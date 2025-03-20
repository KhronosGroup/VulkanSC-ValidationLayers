/* Copyright (c) 2023-2025 The Khronos Group Inc.
 * Copyright (c) 2023-2025 RasterGrid Kft.
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
 *
 * Author: Daniel Rakos <daniel.rakos@rastergrid.com>
 */
#pragma once

#include "utils/hash_util.h"
#include "state_tracker/pipeline_state.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <json/json.h>

namespace vvl::sc {

class PipelineCacheData {
  public:
    class Entry {
      public:
        class ID {
          public:
            ID(const uint8_t id[VK_UUID_SIZE]) : id_() { std::memcpy(&id_[0], id, VK_UUID_SIZE); }

            std::string toString() const {
                char str[37];
                snprintf(str, sizeof(str), "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x", id_[0], id_[1],
                         id_[2], id_[3], id_[4], id_[5], id_[6], id_[7], id_[8], id_[9], id_[10], id_[11], id_[12], id_[13],
                         id_[14], id_[15]);
                return std::string(str);
            }

            bool operator==(const ID& rhs) const { return memcmp(id_, rhs.id_, VK_UUID_SIZE) == 0; }

            struct hash {
                std::size_t operator()(const ID& id) const {
                    hash_util::HashCombiner hc;
                    for (uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
                        hc << id.id_[i];
                    }
                    return hc.Value();
                }
            };

          private:
            uint8_t id_[VK_UUID_SIZE];
        };

        Entry(const uint8_t* data, const size_t data_size, const std::optional<VkPipelineCacheSafetyCriticalIndexEntry> entry)
            : data_(data), data_size_(data_size), entry_(entry) {}

        ID PipelineID() const { return ID(entry_->pipelineIdentifier); }

        operator bool() const { return entry_.has_value(); }

        const VkPipelineCacheSafetyCriticalIndexEntry* operator->() const { return &entry_.value(); }

        uint64_t JSONDataSize() const { return entry_.has_value() ? entry_->jsonSize : 0; }

        const char* JSONData() const {
            return entry_.has_value() ? reinterpret_cast<const char*>(data_ + entry_->jsonOffset) : nullptr;
        }

        bool HasSPIRVDebugInfo() const { return entry_.has_value() ? entry_->stageIndexCount != 0 : false; }

        uint32_t StageIndexCount() const { return entry_.has_value() ? entry_->stageIndexCount : 0; }

        const std::optional<VkPipelineCacheStageValidationIndexEntry> StageIndexEntry(uint32_t index) const {
            if (index < StageIndexCount()) {
                uint64_t offset = entry_->stageIndexOffset + index * entry_->stageIndexStride;
                return CopyDataFrom<VkPipelineCacheStageValidationIndexEntry>(offset);
            } else {
                return std::optional<VkPipelineCacheStageValidationIndexEntry>();
            }
        }

        std::vector<uint32_t> StageSPIRV(uint32_t index) const {
            auto stage_info = StageIndexEntry(index);
            if (stage_info.has_value()) {
                std::vector<uint32_t> spirv(static_cast<std::size_t>(stage_info->codeSize / sizeof(uint32_t)));
                std::memcpy(spirv.data(), data_ + stage_info->codeOffset, static_cast<std::size_t>(stage_info->codeSize));
                return spirv;
            } else {
                return std::vector<uint32_t>();
            }
        }

      private:
        const uint8_t* data_;
        const size_t data_size_;
        const std::optional<VkPipelineCacheSafetyCriticalIndexEntry> entry_;

        template <typename T>
        std::optional<T> CopyDataFrom(uint64_t offset) const {
            if (offset + sizeof(T) <= data_size_) {
                T data;
                std::memcpy(&data, data_ + offset, sizeof(T));
                return std::optional<T>(std::move(data));
            } else {
                return std::optional<T>();
            }
        }
    };

  public:
    const VkPipelineCacheCreateInfo create_info;
    const std::optional<VkPipelineCacheHeaderVersionSafetyCriticalOne> header;
    const std::vector<uint8_t> original_data;

    PipelineCacheData(const VkPipelineCacheCreateInfo& in_create_info, bool copy_original_data = false)
        : create_info(in_create_info),
          header(CopyDataFrom<VkPipelineCacheHeaderVersionSafetyCriticalOne>(0)),
          original_data(copy_original_data ? CopyOriginalData() : std::vector<uint8_t>{}) {}

    const std::optional<VkPipelineCacheHeaderVersionOne> GetBaseHeader() const {
        return CopyDataFrom<VkPipelineCacheHeaderVersionOne>(0);
    }

    uint32_t PipelineIndexCount() const { return header.has_value() ? header->pipelineIndexCount : 0; }

    Entry PipelineIndexEntry(uint32_t index) const {
        if (index < PipelineIndexCount()) {
            uint64_t offset = header->pipelineIndexOffset + index * header->pipelineIndexStride;
            return Entry(Data(), DataSize(), CopyDataFrom<VkPipelineCacheSafetyCriticalIndexEntry>(offset));
        } else {
            return Entry(Data(), DataSize(), std::optional<VkPipelineCacheSafetyCriticalIndexEntry>());
        }
    }

  private:
    const uint8_t* Data() const { return reinterpret_cast<const uint8_t*>(create_info.pInitialData); }
    size_t DataSize() const { return create_info.initialDataSize; }

    template <typename T>
    std::optional<T> CopyDataFrom(uint64_t offset) const {
        if (offset + sizeof(T) <= DataSize()) {
            T data;
            std::memcpy(&data, Data() + offset, sizeof(T));
            return std::optional<T>(std::move(data));
        } else {
            return std::optional<T>();
        }
    }

    const std::vector<uint8_t> CopyOriginalData() const {
        std::vector<uint8_t> data{};
        data.assign(Data(), Data() + DataSize());
        return data;
    }
};

class PipelineCache : public vvl::PipelineCache {
  public:
    class Entry {
      public:
        using ID = PipelineCacheData::Entry::ID;
        using StageModules = std::vector<std::shared_ptr<vvl::ShaderModule>>;

        Entry(const Device& state_data, const PipelineCacheData::Entry& cache_entry)
            : id_(cache_entry.PipelineID()),
              shader_modules_(InitShaderModules(state_data, cache_entry)),
              json_data_(ParseJsonData(cache_entry)) {}

        ID PipelineID() const { return id_; }

        std::shared_ptr<vvl::ShaderModule> GetShaderModule(size_t stage_index) const {
            if (stage_index < shader_modules_.size()) {
                return shader_modules_[stage_index];
            } else {
                return nullptr;
            }
        }

        const char* GetJsonEntryPointName(size_t stage_index) const {
            if (stage_index < json_data_.entrypoint_name.size() && json_data_.entrypoint_name[stage_index].size() > 0) {
                return json_data_.entrypoint_name[stage_index].c_str();
            } else {
                return nullptr;
            }
        }

        const VkSpecializationInfo* GetJsonSpecializationInfo(size_t stage_index) const {
            if (stage_index < json_data_.specialization_info.size()) {
                return json_data_.specialization_info[stage_index]->ptr();
            } else {
                return nullptr;
            }
        }

      private:
        struct JsonData {
            Json::Value json{};
            std::vector<std::string> entrypoint_name{};
            std::vector<std::unique_ptr<vku::safe_VkSpecializationInfo>> specialization_info{};
        };

        StageModules InitShaderModules(const Device& state_data, const PipelineCacheData::Entry& cache_entry);
        JsonData ParseJsonData(const PipelineCacheData::Entry& cache_entry);

        ID id_;
        const StageModules shader_modules_;
        JsonData json_data_;
    };

    PipelineCache(const Device& state_data, VkPipelineCache pipeline_cache, const VkPipelineCacheCreateInfo* pCreateInfo);

    const Entry* GetPipeline(const VkPipelineOfflineCreateInfo* offline_info) const {
        if (offline_info) {
            auto it = pipelines_.find(Entry::ID(offline_info->pipelineIdentifier));
            if (it != pipelines_.end()) {
                return &it->second;
            }
        }
        return nullptr;
    }

    std::shared_ptr<const vvl::ShaderModule> GetStageModule(const vvl::Pipeline& pipe_state, size_t stage_index) const override {
        // If the application did not specify the SPIR-V module entry point,
        // then we cannot use the SPIR-V module for validation
        if (pipe_state.shader_stages_ci[stage_index].pName == nullptr) {
            return nullptr;
        }

        auto offline_info = vku::FindStructInPNextChain<VkPipelineOfflineCreateInfo>(pipe_state.GetCreateInfoPNext());
        auto pipeline_entry = GetPipeline(offline_info);
        if (pipeline_entry) {
            return pipeline_entry->GetShaderModule(stage_index);
        } else {
            return nullptr;
        }
    }

  private:
    vvl::unordered_map<Entry::ID, Entry, Entry::ID::hash> pipelines_;
};

class Pipeline : public vvl::Pipeline {
  public:
    const VkPipelineOfflineCreateInfo *offline_info;

    template <typename CreateInfo, typename... Args>
    Pipeline(const Device& state_data, const CreateInfo* pCreateInfo, Args&&... args)
        : vvl::Pipeline(state_data, pCreateInfo, std::forward<Args>(args)...), offline_info(FindOfflineCreateInfo()) {}

  private:
    const VkPipelineOfflineCreateInfo* FindOfflineCreateInfo() const {
        return vku::FindStructInPNextChain<VkPipelineOfflineCreateInfo>(GetCreateInfoPNext());
    }
};

}  // namespace vvl::sc
