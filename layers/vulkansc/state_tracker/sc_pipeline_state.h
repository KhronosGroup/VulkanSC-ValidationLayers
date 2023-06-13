/* Copyright (c) 2023-2023 The Khronos Group Inc.
 * Copyright (c) 2023-2023 RasterGrid Kft.
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
#include "layer_chassis_dispatch.h"
#include <vector>
#include <unordered_map>

class SCPipelineCacheData {
  public:
    class Entry {
      public:
        class ID {
          public:
            ID(const uint8_t* id) : id_(id) {}

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
            const uint8_t* id_;
        };

        Entry(const std::vector<uint8_t>& pipeline_cache_data, const VkPipelineCacheSafetyCriticalIndexEntry* entry)
            : pipeline_cache_data_(pipeline_cache_data), entry_(entry) {}

        ID PipelineID() const { return ID(entry_->pipelineIdentifier); }

        operator bool() const { return entry_ != nullptr; }

        const VkPipelineCacheSafetyCriticalIndexEntry* operator->() const { return entry_; }

        uint64_t JSONDataSize() const { return (entry_ != nullptr) ? entry_->jsonSize : 0; }

        const char* JSONData() const { return (entry_ != nullptr) ? DataAt<char>(entry_->jsonOffset) : nullptr; }

        bool HasSPIRVDebugInfo() const { return (entry_ != nullptr) ? entry_->stageIndexCount != 0 : false; }

        uint32_t StageIndexCount() const { return (entry_ != nullptr) ? entry_->stageIndexCount : 0; }

        const VkPipelineCacheStageValidationIndexEntry* StageIndexEntry(uint32_t index) const {
            if (index < StageIndexCount()) {
                uint64_t offset = entry_->stageIndexOffset + index * entry_->stageIndexStride;
                return DataAt<VkPipelineCacheStageValidationIndexEntry>(offset);
            } else {
                return nullptr;
            }
        }

        vvl::span<const uint32_t> StageSPIRV(uint32_t index) const {
            auto stage_info = StageIndexEntry(index);
            if (stage_info != nullptr) {
                return vvl::span<const uint32_t>(DataAt<uint32_t>(stage_info->codeOffset),
                                                 static_cast<size_t>(stage_info->codeSize / sizeof(uint32_t)));
            } else {
                return vvl::span<const uint32_t>();
            }
        }

      private:
        const std::vector<uint8_t>& pipeline_cache_data_;
        const VkPipelineCacheSafetyCriticalIndexEntry* entry_;

        template <typename T>
        const T* DataAt(uint64_t offset) const {
            if (offset + sizeof(T) <= pipeline_cache_data_.size()) {
                return reinterpret_cast<const T*>(pipeline_cache_data_.data() + offset);
            } else {
                return nullptr;
            }
        }
    };

    using EntryMap = vvl::unordered_map<Entry::ID, Entry, Entry::ID::hash>;

    const VkPipelineCacheCreateInfo create_info;
    const std::vector<uint8_t> raw_data;
    const EntryMap entries;

    SCPipelineCacheData(const VkPipelineCacheCreateInfo& in_create_info)
        : create_info(in_create_info), raw_data(GetRawData()), entries(ParseEntries()) {
        ParseEntries();
    }

    const VkPipelineCacheHeaderVersionOne* HeaderBase() const { return DataAt<VkPipelineCacheHeaderVersionOne>(0); }

    const VkPipelineCacheHeaderVersionSafetyCriticalOne* Header() const {
        return DataAt<VkPipelineCacheHeaderVersionSafetyCriticalOne>(0);
    }

    uint32_t PipelineIndexCount() const { return (Header() != nullptr) ? Header()->pipelineIndexCount : 0; }

    Entry PipelineIndexEntry(uint32_t index) const {
        if (index < PipelineIndexCount()) {
            uint64_t offset = Header()->pipelineIndexOffset + index * Header()->pipelineIndexStride;
            return Entry(raw_data, DataAt<VkPipelineCacheSafetyCriticalIndexEntry>(offset));
        } else {
            return Entry(raw_data, nullptr);
        }
    }

  private:
    template <typename T>
    const T* DataAt(uint64_t offset) const {
        if (offset + sizeof(T) <= raw_data.size()) {
            return reinterpret_cast<const T*>(raw_data.data() + offset);
        } else {
            return nullptr;
        }
    }

    std::vector<uint8_t> GetRawData() const {
        std::vector<uint8_t> raw_data{};
        auto* data_ptr = reinterpret_cast<const uint8_t*>(create_info.pInitialData);
        size_t data_size = create_info.initialDataSize;
        raw_data.assign(data_ptr, data_ptr + data_size);
        return raw_data;
    }

    EntryMap ParseEntries() const {
        EntryMap entries;
        for (uint32_t i = 0; i < PipelineIndexCount(); ++i) {
            auto entry = PipelineIndexEntry(i);
            if (entry) {
                entries.emplace(std::make_pair(entry.PipelineID(), entry));
            }
        }
        return entries;
    }
};

class SC_PIPELINE_CACHE_STATE : public PIPELINE_CACHE_STATE {
  public:
    const SCPipelineCacheData* contents;

    SC_PIPELINE_CACHE_STATE(VkPipelineCache pipeline_cache, const VkPipelineCacheCreateInfo* pCreateInfo,
                            const SCPipelineCacheData* cache_data)
        : PIPELINE_CACHE_STATE(pipeline_cache, pCreateInfo), contents(cache_data) {}
};

class SC_PIPELINE_STATE : public PIPELINE_STATE {
  public:
    const VkPipelineOfflineCreateInfo *offline_info;

    template <typename CreateInfo, typename... Args>
    SC_PIPELINE_STATE(const ValidationStateTracker *state_data, const CreateInfo *pCreateInfo, Args &&...args)
        : PIPELINE_STATE(state_data, pCreateInfo, std::forward<Args>(args)...),
          offline_info(LvlFindInChain<VkPipelineOfflineCreateInfo>(pCreateInfo->pNext)) {}
};
