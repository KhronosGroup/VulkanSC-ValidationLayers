/*
 * Copyright (c) 2023-2024 The Khronos Group Inc.
 * Copyright (c) 2023-2024 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <vulkan/utility/vk_struct_helper.hpp>
#include "spirv-tools/libspirv.h"
#include "../../framework/binding.h"

#include <assert.h>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <string.h>

namespace vksc {

void InitDefaultPipelineCacheData();
const std::vector<uint8_t>& GetDefaultPipelineCacheData();
const VkPipelinePoolSize& GetDefaultPipelinePoolSize();
const VkPipelineCacheCreateInfo& GetDefaultPipelineCacheCreateInfo();
const VkPipelineOfflineCreateInfo& GetDefaultPipelineOfflineCreateInfo();
std::vector<uint32_t> CompileSPV(const spv_target_env target_env, const char* spv);

void ParseUUID(const char* str, uint8_t* uuid);

class PipelineCache : public vkt::PipelineCache {
  public:
    PipelineCache() = default;
    PipelineCache(VkDevice device, VkPipelineCache handle) { NonDispHandle::init(device, handle); }
};

// Helper class for building pipeline cache data
class PipelineCacheBuilder {
  public:
    template <typename T>
    static size_t AlignedSize() {
        return (sizeof(T) + std::alignment_of_v<T> - 1) & ~(std::alignment_of_v<T> - 1);
    }

    template <typename T>
    static size_t AlignedOffset(size_t offset) {
        return (offset + std::alignment_of_v<T> - 1) & ~(std::alignment_of_v<T> - 1);
    }

    template <typename BaseData, typename PrivateData>
    class Block {
      public:
        Block(std::vector<uint8_t>& data, size_t offset) : data_(data), offset_(offset) {}

        static size_t Alignment() {
            return static_cast<uint64_t>(std::max(std::alignment_of_v<BaseData>, std::alignment_of_v<PrivateData>));
        }

        static size_t Size() { return AlignedOffset<PrivateData>(AlignedSize<BaseData>()) + AlignedSize<PrivateData>(); }

        static size_t Stride() { return AlignedOffset<BaseData>(Size()); }

        size_t Offset() const { return offset_; }

        BaseData* operator->() { return reinterpret_cast<BaseData*>(data_.data() + offset_); }
        PrivateData* PrivData() {
            return reinterpret_cast<PrivateData*>(data_.data() + AlignedOffset<PrivateData>(offset_ + AlignedSize<BaseData>()));
        }

      private:
        std::vector<uint8_t>& data_;
        const size_t offset_;
    };

    template <typename BaseData>
    class Block<BaseData, void> {
      public:
        Block(std::vector<uint8_t>& data, size_t offset) : data_(data), offset_(offset) {
            // We currently always build aligned pipeline cache data
            assert(reinterpret_cast<uintptr_t>(data_.data() + offset_) % alignof(BaseData) == 0);
        }

        static size_t Alignment() { return std::alignment_of_v<BaseData>; }

        static size_t Size() { return AlignedSize<BaseData>(); }

        static size_t Stride() { return Size(); }

        size_t Offset() const { return offset_; }

        BaseData* operator->() { return reinterpret_cast<BaseData*>(data_.data() + offset_); }
        void* PrivData() { return nullptr; }

      private:
        std::vector<uint8_t>& data_;
        const size_t offset_;
    };

    template <typename PrivateData = void>
    using HeaderVersionOne = Block<VkPipelineCacheHeaderVersionOne, PrivateData>;
    template <typename PrivateData = void>
    using HeaderVersionSCOne = Block<VkPipelineCacheHeaderVersionSafetyCriticalOne, PrivateData>;
    template <typename PrivateData = void>
    using SCIndexEntry = Block<VkPipelineCacheSafetyCriticalIndexEntry, PrivateData>;
    template <typename PrivateData = void>
    using StageValIndexEntry = Block<VkPipelineCacheStageValidationIndexEntry, PrivateData>;

    size_t AddBlob(size_t size, size_t alignment = 1) {
        size_t offset = (data_.size() + alignment - 1) & ~(alignment - 1);
        data_.resize(static_cast<std::size_t>(offset + size));
        return offset;
    }

    template <typename T>
    T AddBlock() {
        size_t alignment = T::Alignment();
        size_t size = T::Size();
        size_t offset = (data_.size() + alignment - 1) & ~(alignment - 1);
        data_.resize(offset + size);
        return T(data_, offset);
    }

    template <typename PrivateData = void>
    HeaderVersionSCOne<PrivateData> AddDefaultHeaderVersionSCOne() {
        auto header = AddBlock<HeaderVersionSCOne<PrivateData>>();
        header->headerVersionOne.headerSize = sizeof(VkPipelineCacheHeaderVersionSafetyCriticalOne);
        header->headerVersionOne.headerVersion = VK_PIPELINE_CACHE_HEADER_VERSION_SAFETY_CRITICAL_ONE;
        ParseUUID("47d2b326-e366-11ed-b5ea-0242ac120002", &header->headerVersionOne.pipelineCacheUUID[0]);
        header->validationVersion = VK_PIPELINE_CACHE_VALIDATION_VERSION_SAFETY_CRITICAL_ONE;
        return header;
    }

    template <typename PrivateData = void, typename HeaderPrivateData = void>
    SCIndexEntry<PrivateData> AddPipelineEntry(HeaderVersionSCOne<HeaderPrivateData>& header, const char* uuid,
                                               uint64_t pipeline_memory_size) {
        auto entry = AddBlock<SCIndexEntry<PrivateData>>();
        ParseUUID(uuid, &entry->pipelineIdentifier[0]);
        entry->pipelineMemorySize = pipeline_memory_size;
        if (header->pipelineIndexStride == 0) {
            header->pipelineIndexStride = static_cast<uint32_t>(SCIndexEntry<PrivateData>::Stride());
        } else {
            assert(header->pipelineIndexStride == SCIndexEntry<PrivateData>::Stride());
        }
        if (header->pipelineIndexCount == 0) {
            header->pipelineIndexOffset = entry.Offset();
        } else {
            assert(entry.Offset() == header->pipelineIndexOffset + header->pipelineIndexCount * header->pipelineIndexStride);
        }
        header->pipelineIndexCount++;
        return entry;
    }

    template <typename PrivateData = void, typename PipelinePrivateData = void>
    StageValIndexEntry<PrivateData> GetStageValidation(SCIndexEntry<PipelinePrivateData>& pipeline, uint32_t index) {
        assert(index < pipeline->stageIndexCount);
        return StageValIndexEntry<PrivateData>(
            data_, static_cast<size_t>(pipeline->stageIndexOffset) + index * pipeline->stageIndexStride);
    }
    template <typename PrivateData = void, typename PipelinePrivateData = void>
    void AddStageValidation(SCIndexEntry<PipelinePrivateData>& pipeline, const char* json,
                            const std::vector<std::vector<uint32_t>> stage_spv) {
        if (json != nullptr && *json != '\0') {
            pipeline->jsonSize = strlen(json);
            pipeline->jsonOffset = AddBlob(static_cast<size_t>(pipeline->jsonSize));
            strncpy(reinterpret_cast<char*>(&data_[static_cast<size_t>(pipeline->jsonOffset)]), json,
                    static_cast<size_t>(pipeline->jsonSize));
        } else {
            pipeline->jsonSize = 0;
            pipeline->jsonOffset = 0;
        }

        for (std::size_t i = 0; i < stage_spv.size(); ++i) {
            auto block = AddBlock<StageValIndexEntry<PrivateData>>();
            if (pipeline->stageIndexOffset == 0) {
                pipeline->stageIndexOffset = block.Offset();
                pipeline->stageIndexStride = static_cast<uint32_t>(block.Stride());
            } else {
                assert(pipeline->stageIndexStride == block.Stride());
            }
            pipeline->stageIndexCount++;
        }

        for (std::size_t i = 0; i < stage_spv.size(); ++i) {
            auto& spv = stage_spv[i];
            assert(spv.size() != 0);
            size_t size = spv.size() * 4;
            size_t offset = AddBlob(size, 4);
            memcpy(&data_[offset], spv.data(), size);
            auto entry = GetStageValidation(pipeline, i);
            entry->codeOffset = offset;
            entry->codeSize = size;
        }
    }

    template <typename PrivateData = void, typename PipelinePrivateData = void>
    void AddStageValidation(SCIndexEntry<PipelinePrivateData>& pipeline, const char* json, const spv_target_env target_env,
                            const std::vector<const char*> stage_spv) {
        std::vector<std::vector<uint32_t>> compiled_spv;
        for (std::size_t i = 0; i < stage_spv.size(); ++i) {
            compiled_spv.emplace_back(CompileSPV(target_env, stage_spv[i]));
        }
        AddStageValidation(pipeline, json, compiled_spv);
    }

    VkPipelineCacheCreateInfo MakeCreateInfo(
        VkPipelineCacheCreateFlags create_flags = VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT |
                                                  VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT) const {
        auto create_info = vku::InitStruct<VkPipelineCacheCreateInfo>();
        create_info.flags = create_flags;
        create_info.initialDataSize = data_.size();
        create_info.pInitialData = data_.data();
        return create_info;
    }

    vkt::PipelineCache CreatePipelineCache(const vkt::Device& device) const { return vkt::PipelineCache(device, MakeCreateInfo()); }

    const std::vector<uint8_t>& GetData() const { return data_; }
    void Clear() { data_.clear(); }

  private:
    std::vector<uint8_t> data_{};
};

}  // namespace vksc
