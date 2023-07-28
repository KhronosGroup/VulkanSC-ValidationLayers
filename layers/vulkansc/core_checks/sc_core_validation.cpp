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

#include <algorithm>
#include <array>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <string>
#include <valarray>

#include "generated/vk_enum_string_helper.h"
#include "generated/chassis.h"
#include "vulkansc/sc_vuid_enums.h"
#include "vulkansc/core_checks/sc_core_validation.h"
#include "vulkansc/state_tracker/sc_pipeline_state.h"
#include "utils/vk_layer_utils.h"
#include "generated/enum_flag_bits.h"

void SCCoreChecks::PreCallRecordCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                               VkInstance* pInstance) {
    InitFilters();
    BASE::PreCallRecordCreateInstance(pCreateInfo, pAllocator, pInstance);
}

void SCCoreChecks::InitFilters() {
    // Initialize filters for Vulkan SC by filtering out all VUIDs not applicable to Vulkan SC that may otherwise be
    // triggered by the inherited Vulkan validation

    const std::unordered_set<const char*> filtered_vuids = {
        // Filter VUIDs specific to sparse buffer creation which is not supported in Vulkan SC
        "VUID-vkCreateBuffer-flags-00911",
        "VUID-VkBufferCreateInfo-flags-00915",
        "VUID-VkBufferCreateInfo-flags-00916",
        "VUID-VkBufferCreateInfo-flags-00917",
        "VUID-VkBufferCreateInfo-flags-00918",
        "VUID-VkBufferCreateInfo-None-01888",

        // Filter VUIDs specific to sparse image creation which is not supported in Vulkan SC
        "VUID-vkCreateImage-flags-00939",
        "VUID-VkImageCreateInfo-flags-00969",
        "VUID-VkImageCreateInfo-flags-01924",
        "VUID-VkImageCreateInfo-tiling-04121",
        "VUID-VkImageCreateInfo-imageType-00970",
        "VUID-VkImageCreateInfo-imageType-00971",
        "VUID-VkImageCreateInfo-imageType-00972",
        "VUID-VkImageCreateInfo-imageType-00973",
        "VUID-VkImageCreateInfo-imageType-00974",
        "VUID-VkImageCreateInfo-imageType-00975",
        "VUID-VkImageCreateInfo-imageType-00976",
        "VUID-VkImageCreateInfo-flags-00987",
        "VUID-VkImageCreateInfo-None-01925",
        "VUID-VkImageCreateInfo-None-01891",

        // Filter VUIDs specific to split-instance bind regions image creation which is not supported in Vulkan SC
        "VUID-VkImageCreateInfo-physicalDeviceCount-01421",
        "VUID-VkImageCreateInfo-flags-02259",

        // Filter VUIDs requiring images created with split-instance bind regions which is not supported in Vulkan SC
        "VUID-VkBindImageMemoryInfo-pNext-01627",
        "VUID-VkBindImageMemoryInfo-pNext-01628",
        "VUID-VkBindImageMemoryInfo-pNext-01629",
        "VUID-VkBindImageMemoryDeviceGroupInfo-deviceIndexCount-01633",
        "VUID-VkBindImageMemoryDeviceGroupInfo-splitInstanceBindRegionCount-01636",
        "VUID-VkBindImageMemoryDeviceGroupInfo-pSplitInstanceBindRegions-01637",
        "VUID-VkBindImageMemoryDeviceGroupInfo-offset-01638",
        "VUID-VkBindImageMemoryDeviceGroupInfo-offset-01639",
        "VUID-VkBindImageMemoryDeviceGroupInfo-extent-01640",
        "VUID-VkBindImageMemoryDeviceGroupInfo-extent-01641",
    };

    for (const auto& filtered_vuid : filtered_vuids) {
        report_data->filter_message_ids.insert(vvl_vuid_hash(filtered_vuid));
    }
}

bool SCCoreChecks::ValidateObjectRequestCount(VkDevice device, const char* cmd, const char* vuid, const char* object_name_plural,
                                              size_t existing_count, const char* requested_count_name, uint32_t requested_count,
                                              const char* create_count_name, uint32_t create_count) const {
    bool skip = false;
    if (existing_count + create_count > requested_count) {
        skip |= LogError(device, vuid,
                         "%s(): the number of %s currently allocated from the device (%zu) plus %s (%u) is "
                         "greater than the total number of %s requested via VkDeviceObjectReservationCreateInfo::%s (%u).",
                         cmd, object_name_plural, existing_count, create_count_name, create_count, object_name_plural,
                         requested_count_name, requested_count);
    }
    return skip;
}

bool SCCoreChecks::ValidateObjectRequestCount(VkDevice device, const char* cmd, const char* vuid, const char* object_name_plural,
                                              size_t existing_count, const char* requested_count_name, uint32_t requested_count,
                                              uint32_t create_count) const {
    bool skip = false;
    if (existing_count + create_count > requested_count) {
        skip |= LogError(device, vuid,
                         "%s(): the number of %s currently allocated from the device (%zu) plus %u is "
                         "greater than the total number of %s requested via VkDeviceObjectReservationCreateInfo::%s (%u).",
                         cmd, object_name_plural, existing_count, create_count, object_name_plural, requested_count_name,
                         requested_count);
    }
    return skip;
}

bool SCCoreChecks::ValidateCombinedRequestCount(VkDevice device, const char* cmd, const char* vuid, const char* parent_object_name,
                                                const char* object_name_plural, uint32_t existing_count,
                                                const char* requested_count_name, uint32_t requested_count,
                                                const char* create_count_name, uint32_t create_count) const {
    bool skip = false;
    if (existing_count + create_count > requested_count) {
        skip |= LogError(device, vuid,
                         "%s(): the number of %s currently allocated from the device (%u) across all %s objects "
                         "plus %s (%u) is greater than the total number of %s requested via "
                         "VkDeviceObjectReservationCreateInfo::%s (%u).",
                         cmd, object_name_plural, existing_count, parent_object_name, create_count_name, create_count,
                         object_name_plural, requested_count_name, requested_count);
    }
    return skip;
}

template <typename CreateInfo>
bool SCCoreChecks::ValidatePipelinePoolMemory(VkDevice device, const char* cmd, uint32_t create_info_count,
                                              const CreateInfo* create_info) const {
    bool skip = false;

    vvl::unordered_map<VkDeviceSize, uint32_t> reserved_pipeline_pool_entries{};
    for (uint32_t i = 0; i < create_info_count; ++i) {
        auto offline_info = LvlFindInChain<VkPipelineOfflineCreateInfo>(create_info[i].pNext);
        if (offline_info) {
            reserved_pipeline_pool_entries[offline_info->poolEntrySize]++;
        }
    }

    std::unique_lock<std::mutex> lock(sc_used_pipeline_pool_size_map_mutex_);
    for (const auto& it : reserved_pipeline_pool_entries) {
        auto already_used_it = sc_used_pipeline_pool_size_map_.find(it.first);
        auto total_entries_it = sc_pipeline_pool_size_map_.find(it.first);

        if (total_entries_it == sc_pipeline_pool_size_map_.end()) {
            skip |= LogError(device, "VUID-VkPipelineOfflineCreateInfo-poolEntrySize-05028",
                             "%s(): poolEntrySize %" PRIu64 " was not requested at device creation time.", cmd, it.first);
        } else {
            uint32_t newly_reserved = it.second;
            uint32_t already_used = (already_used_it != sc_used_pipeline_pool_size_map_.end()) ? already_used_it->second : 0;
            uint32_t total_entries = total_entries_it->second;

            if (already_used + newly_reserved > total_entries) {
                const char* vuid = phys_dev_props_sc_10_.recyclePipelineMemory
                                       ? "VUID-VkPipelineOfflineCreateInfo-recyclePipelineMemory-05029"
                                       : "VUID-VkPipelineOfflineCreateInfo-recyclePipelineMemory-05030";

                skip |= LogError(device, vuid,
                                 "%s(): the number of currently existing pipelines created with poolEntrySize %" PRIu64
                                 " (%u) plus the number of entries that this command would reserve (%u) "
                                 "is greater than the total number of pool entires (%u) reserved at device "
                                 "creation time.",
                                 cmd, it.first, already_used, newly_reserved, total_entries);
            }
        }
    }

    return skip;
}

template <typename VkHandle>
bool SCCoreChecks::ValidatePipelineCacheCreateInfo(VkHandle handle, const char* cmd,
                                                   const VkPipelineCacheCreateInfo& create_info) const {
    bool skip = false;

    const char* missing_flags_msg = "%s(): VkPipelineCacheCreateInfo::flags (%s) is missing %s.";

    if ((create_info.flags & VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT) == 0) {
        skip |= LogError(handle, "VUID-VkPipelineCacheCreateInfo-flags-05043", missing_flags_msg, cmd,
                         string_VkPipelineCacheCreateFlags(create_info.flags).c_str(), "VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT");
    }

    if ((create_info.flags & VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT) == 0) {
        skip |= LogError(handle, "VUID-VkPipelineCacheCreateInfo-flags-05044", missing_flags_msg, cmd,
                         string_VkPipelineCacheCreateFlags(create_info.flags).c_str(),
                         "VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT");
    }

    return skip;
}

bool SCCoreChecks::ValidatePipelineCacheData(VkPhysicalDevice physicalDevice, const VkPipelineCacheCreateInfo& create_info,
                                             uint32_t index) const {
    bool skip = false;
    bool header_valid = true;

    if (create_info.pInitialData == nullptr) {
        // No data to validate, should be already caught as a validation error by parameter validation
        return false;
    }

    if (create_info.initialDataSize < sizeof(uint32_t) + sizeof(VkPipelineCacheHeaderVersion)) {
        skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_TooSmall,
                           "vkCreateDevice(): the pipeline cache data size specified in "
                           "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].initialDataSize "
                           "is too small (%zu bytes) to verify header.",
                           index, create_info.initialDataSize);
        // Return early here as we cannot validate anything else if the header is too small.
        return skip;
    }

    const uint32_t sc_header_size = sizeof(VkPipelineCacheHeaderVersionSafetyCriticalOne);
    auto header = reinterpret_cast<const VkPipelineCacheHeaderVersionSafetyCriticalOne*>(create_info.pInitialData);
    if (header->headerVersionOne.headerSize != sc_header_size) {
        skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_InvalidHeaderSize,
                           "vkCreateDevice(): the pipeline cache data specified in "
                           "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData "
                           "has an invalid headerSize (%u) that does not match the header size of a Vulkan "
                           "SC pipeline cache VkPipelineCacheHeaderVersionSafetyCriticalOne (%u bytes).",
                           index, header->headerVersionOne.headerSize, sc_header_size);
        header_valid = false;
    }

    if (header->headerVersionOne.headerVersion != VK_PIPELINE_CACHE_HEADER_VERSION_SAFETY_CRITICAL_ONE) {
        skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_UnrecognizedHeaderVersion,
                           "vkCreateDevice(): the pipeline cache data specified in "
                           "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData "
                           "has an invalid headerVersion %s (%u) that does not match the header version of "
                           "a Vulkan SC pipeline cache (VK_PIPELINE_CACHE_HEADER_VERSION_SAFETY_CRITICAL_ONE).",
                           index, string_VkPipelineCacheHeaderVersion(header->headerVersionOne.headerVersion),
                           header->headerVersionOne.headerVersion);
        header_valid = false;
    }

    if (create_info.initialDataSize < sc_header_size) {
        skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_TooSmall,
                           "vkCreateDevice(): the pipeline cache data size specified in "
                           "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].initialDataSize "
                           "is too small (%zu bytes) to contain a VkPipelineCacheHeaderVersionSafetyCriticalOne "
                           "(%u bytes) header.",
                           index, create_info.initialDataSize, sc_header_size);
        // Return early here as we cannot validate anything else if the header is too small.
        return skip;
    }

    if (header->validationVersion != VK_PIPELINE_CACHE_VALIDATION_VERSION_SAFETY_CRITICAL_ONE) {
        skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_UnrecognizedValidationVersion,
                           "vkCreateDevice(): the pipeline cache data specified in "
                           "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData "
                           "has an invalid validationVersion %s (%u) that does not match the validation version of "
                           "a Vulkan SC pipeline cache (VK_PIPELINE_CACHE_VALIDATION_VERSION_SAFETY_CRITICAL_ONE).",
                           index, string_VkPipelineCacheValidationVersion(header->validationVersion), header->validationVersion);
        header_valid = false;
    }

    const uint32_t sc_index_entry_size = sizeof(VkPipelineCacheSafetyCriticalIndexEntry);
    assert(sc_index_entry_size == 56);
    if (header->pipelineIndexStride < sc_index_entry_size) {
        skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_PipelineIndexStrideTooSmall,
                           "vkCreateDevice(): the pipeline cache data specified in "
                           "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData "
                           "has an invalid pipelineIndexStride (%u) which needs to be at least %u.",
                           index, header->pipelineIndexStride, sc_index_entry_size);
        header_valid = false;
    }

    if (header->pipelineIndexOffset + header->pipelineIndexCount * header->pipelineIndexStride > create_info.initialDataSize) {
        skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_PipelineIndexOutOfBounds,
                           "vkCreateDevice(): the pipeline cache data specified in "
                           "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData "
                           "is too small (%zu bytes) to fit pipelineIndexCount (%u) pipelines stored with "
                           "pipelineIndexStride (%u) starting from pipelineIndexOffset (%" PRIu64 ").",
                           index, create_info.initialDataSize, header->pipelineIndexCount, header->pipelineIndexStride,
                           header->pipelineIndexOffset);
        header_valid = false;
    }

    if (!header_valid) {
        // Should not validate any other data if the header is invalid.
        return skip;
    }

    SCPipelineCacheData data(create_info);
    vvl::unordered_set<SCPipelineCacheData::Entry::ID, SCPipelineCacheData::Entry::ID::hash> pipeline_ids{};
    for (uint32_t pipeline_index = 0; pipeline_index < data.PipelineIndexCount(); ++pipeline_index) {
        bool stage_info_valid = true;
        auto entry = data.PipelineIndexEntry(pipeline_index);
        if (!entry) continue;

        auto id = entry.PipelineID();
        if (!pipeline_ids.emplace(id).second) {
            skip |= LogError(physicalDevice, "VUID-VkPipelineCacheCreateInfo-pInitialData-05139",
                             "vkCreateDevice(): the pipeline cache data specified in "
                             "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData "
                             "contains duplicate pipeline identifier {%s}.",
                             index, id.toString().c_str());
        }

        if (entry->jsonSize == 0 && entry->jsonOffset != 0) {
            skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_JsonOffsetAndSizeInconsistent,
                               "vkCreateDevice(): jsonSize for pipeline identifier {%s} in the pipeline cache data specified "
                               "in VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData is zero, "
                               "but jsonOffset is not zero (%" PRIu64 ").",
                               id.toString().c_str(), index, entry->jsonOffset);
        }

        if (entry->jsonSize != 0 && entry->jsonOffset + entry->jsonSize > create_info.initialDataSize) {
            skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_JsonDataOutOfBounds,
                               "vkCreateDevice(): the pipeline cache data specified in "
                               "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData "
                               "is too small (%zu bytes) to fit the JSON data for pipeline identifier {%s} stored with "
                               "jsonSize (%" PRIu64 ") starting from jsonOffset (%" PRIu64 ").",
                               index, create_info.initialDataSize, id.toString().c_str(), entry->jsonSize, entry->jsonOffset);
        }

        if (entry->jsonSize == 0 && entry->stageIndexCount != 0) {
            skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_JsonSizeStageIndexCountInconsistent,
                               "vkCreateDevice(): jsonSize for pipeline identifier {%s} in the pipeline cache data specified "
                               "in VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData is zero, "
                               "but stageIndexCount is not zero (%u).",
                               id.toString().c_str(), index, entry->stageIndexCount);
        }

        if (entry->stageIndexCount == 0 && entry->stageIndexOffset != 0) {
            skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_StageIndexOffsetStrideCountInconsistent,
                               "vkCreateDevice(): stageIndexCount for pipeline identifier {%s} in the pipeline cache data "
                               "specified in VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData "
                               "is zero, but stageIndexOffset is not zero (%" PRIu64 ").",
                               id.toString().c_str(), index, entry->stageIndexOffset);
        }

        if (entry->stageIndexCount == 0 && entry->stageIndexStride != 0) {
            skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_StageIndexOffsetStrideCountInconsistent,
                               "vkCreateDevice(): stageIndexCount for pipeline identifier {%s} in the pipeline cache data "
                               "specified in VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData "
                               "is zero, but stageIndexStride is not zero (%u).",
                               id.toString().c_str(), index, entry->stageIndexStride);
        }

        const uint32_t sc_stage_val_entry_size = sizeof(VkPipelineCacheStageValidationIndexEntry);
        assert(sc_stage_val_entry_size == 16);
        if (entry->stageIndexCount != 0 && entry->stageIndexStride < sc_stage_val_entry_size) {
            skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_StageIndexStrideTooSmall,
                               "vkCreateDevice(): stageIndexCount for pipeline identifier {%s} in the pipeline cache data "
                               "specified in VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData "
                               "is not zero, but stageIndexStride is too small (%u bytes) for the stage entries to contain a "
                               "VkPipelineCacheStageValidationIndexEntry structure (%u bytes).",
                               id.toString().c_str(), index, entry->stageIndexStride, sc_stage_val_entry_size);
            stage_info_valid = false;
        }

        if (entry->stageIndexCount != 0 &&
            entry->stageIndexOffset + entry->stageIndexCount * entry->stageIndexStride > create_info.initialDataSize) {
            skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_StageIndexOutOfBounds,
                               "vkCreateDevice(): the pipeline cache data specified in "
                               "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData "
                               "is too small (%zu bytes) to fit stageIndexCount (%u) stage validation entries for "
                               "pipeline identifier {%s} stored with stageIndexStride (%u) starting from "
                               "stageIndexOffset (%" PRIu64 ").",
                               index, create_info.initialDataSize, entry->stageIndexCount, id.toString().c_str(),
                               entry->stageIndexStride, entry->stageIndexOffset);
            stage_info_valid = false;
        }

        if (stage_info_valid) {
            for (uint32_t stage_index = 0; stage_index < entry.StageIndexCount(); ++stage_index) {
                auto stage_info = entry.StageIndexEntry(stage_index);
                if (!stage_info) continue;

                if (stage_info->codeSize == 0) {
                    skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_CodeSizeZero,
                                       "vkCreateDevice(): codeSize for stage index entry #%u for pipeline identifier {%s} "
                                       "in the pipeline cache data specified in VkDeviceObjectReservationCreateInfo::"
                                       "pPipelineCacheCreateInfos[%u].pInitialData is zero.",
                                       stage_index, id.toString().c_str(), index);
                }

                if (stage_info->codeSize % 4 != 0) {
                    skip |= LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_CodeSizeNotMultipleOfFour,
                                       "vkCreateDevice(): codeSize (%" PRIu64
                                       ") for stage index entry #%u for pipeline identifier {%s} in the pipeline "
                                       "cache data specified in VkDeviceObjectReservationCreateInfo::"
                                       "pPipelineCacheCreateInfos[%u].pInitialData is not a multiple of 4.",
                                       stage_info->codeSize, stage_index, id.toString().c_str(), index);
                }

                if (stage_info->codeOffset + stage_info->codeSize > create_info.initialDataSize) {
                    skip |=
                        LogWarning(physicalDevice, kVUID_SC_PipelineCacheData_CodeDataOutOfBounds,
                                   "vkCreateDevice(): the pipeline cache data specified in "
                                   "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos[%u].pInitialData "
                                   "is too small (%zu bytes) to fit the SPIR-V module data for stage index entry #%u "
                                   "for pipeline identifier {%s} stored at codeOffset (%" PRIu64 ") with codeSize (%" PRIu64 ").",
                                   index, create_info.initialDataSize, stage_index, id.toString().c_str(), stage_info->codeOffset,
                                   stage_info->codeSize);
                }
            }
        }
    }

    return skip;
}

bool SCCoreChecks::ValidateShaderModuleId(const PIPELINE_STATE& pipeline) const {
    bool skip = false;

    for (const auto& stage_ci : pipeline.shader_stages_ci) {
        if (stage_ci.module != VK_NULL_HANDLE) {
            skip |= LogError(device, "VUID-VkPipelineShaderStageCreateInfo-module-05026",
                             "module in VkPipelineShaderStageCreateInfo (stage %s) is not VK_NULL_HANDLE.",
                             string_VkShaderStageFlagBits(stage_ci.stage));
        }
    }

    return skip;
}

bool SCCoreChecks::ValidatePipelineShaderStage(const PIPELINE_STATE& pipeline, const PipelineStageState& stage_state) const {
    bool skip = false;
    const auto* create_info = stage_state.create_info;
    const SHADER_MODULE_STATE& module_state = *stage_state.module_state.get();

    // TODO: Vulkan SC - Recent refactoring upstream caused validation that does not depend on SPIR-V data
    // to now require SPIR-V data for being executed. This is a regression that makes us lose some
    // coverage of non-SPIR-V depended VUs, so for now we simply replicate the checks done by
    // ValidateSpecialization and ValidateShaderSubgroupSizeControl until the regression is fixed upstream.

    // skip |= ValidateSpecializations(module_state, create_info->pSpecializationInfo, pipeline);
    {
        auto spec = create_info->pSpecializationInfo;
        if (spec) {
            for (auto i = 0u; i < spec->mapEntryCount; i++) {
                if (spec->pMapEntries[i].offset >= spec->dataSize) {
                    skip |=
                        LogError(module_state.Handle(), "VUID-VkSpecializationInfo-offset-00773",
                                 "%s(): pCreateInfos[%" PRIu32
                                 "] Specialization entry %u (for constant id %u) references memory outside provided specialization "
                                 "data (bytes %u..%zu; %zu bytes provided).",
                                 pipeline.GetCreateFunctionName(), pipeline.create_index, i, spec->pMapEntries[i].constantID,
                                 spec->pMapEntries[i].offset, spec->pMapEntries[i].offset + spec->dataSize - 1, spec->dataSize);

                    continue;
                }
                if (spec->pMapEntries[i].offset + spec->pMapEntries[i].size > spec->dataSize) {
                    skip |= LogError(
                        module_state.Handle(), "VUID-VkSpecializationInfo-pMapEntries-00774",
                        "%s(): pCreateInfos[%" PRIu32
                        "] Specialization entry %u (for constant id %u) references memory outside provided specialization "
                        "data (bytes %u..%zu; %zu bytes provided).",
                        pipeline.GetCreateFunctionName(), pipeline.create_index, i, spec->pMapEntries[i].constantID,
                        spec->pMapEntries[i].offset, spec->pMapEntries[i].offset + spec->pMapEntries[i].size - 1, spec->dataSize);
                }
                for (uint32_t j = i + 1; j < spec->mapEntryCount; ++j) {
                    if (spec->pMapEntries[i].constantID == spec->pMapEntries[j].constantID) {
                        skip |= LogError(module_state.Handle(), "VUID-VkSpecializationInfo-constantID-04911",
                                         "%s(): pCreateInfos[%" PRIu32 "] Specialization entry %" PRIu32 " and %" PRIu32
                                         " have the same constantID (%" PRIu32 ").",
                                         pipeline.GetCreateFunctionName(), pipeline.create_index, i, j,
                                         spec->pMapEntries[i].constantID);
                    }
                }
            }
        }
    }

    if (IsExtEnabled(device_extensions.vk_ext_subgroup_size_control)) {
        // skip |= ValidateShaderSubgroupSizeControl(module_state, create_info->stage, create_info->flags);
        auto stage = create_info->stage;
        auto flags = create_info->flags;

        if ((flags & VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT) != 0 &&
            !enabled_features.core13.subgroupSizeControl) {
            skip |= LogError(module_state.Handle(), "VUID-VkPipelineShaderStageCreateInfo-flags-02784",
                             "VkPipelineShaderStageCreateInfo flags contain "
                             "VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT, "
                             "but the VkPhysicalDeviceSubgroupSizeControlFeaturesEXT::subgroupSizeControl feature is not enabled.");
        }

        if ((flags & VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT) != 0) {
            if (!enabled_features.core13.computeFullSubgroups) {
                skip |= LogError(module_state.Handle(), "VUID-VkPipelineShaderStageCreateInfo-flags-02785",
                                 "VkPipelineShaderStageCreateInfo flags contain "
                                 "VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT, but the "
                                 "VkPhysicalDeviceSubgroupSizeControlFeaturesEXT::computeFullSubgroups feature is not enabled");
            } else if ((stage & (VK_SHADER_STAGE_MESH_BIT_EXT | VK_SHADER_STAGE_TASK_BIT_EXT | VK_SHADER_STAGE_COMPUTE_BIT)) == 0) {
                skip |= LogError(module_state.Handle(), "VUID-VkPipelineShaderStageCreateInfo-flags-08988",
                                 "VkPipelineShaderStageCreateInfo flags contain "
                                 "VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT, but the stage is %s.",
                                 string_VkShaderStageFlagBits(stage));
            }
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                                 VkInstance* pInstance) const {
    bool skip = BASE::PreCallValidateCreateInstance(pCreateInfo, pAllocator, pInstance);

    if (pCreateInfo && pCreateInfo->pApplicationInfo) {
        uint32_t api_version = pCreateInfo->pApplicationInfo->apiVersion;

        if (api_version != 0 && VK_API_VERSION_VARIANT(api_version) == VKSC_API_VARIANT && api_version < VKSC_API_VERSION_1_0) {
            skip |= LogError(instance, "VUID-VkApplicationInfo-apiVersion-05021",
                             "vkCreateInstance(): pCreateInfo->pApplicationInfo->apiVersion (0x%08x) is invalid.", api_version);
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) const {
    bool skip = BASE::PreCallValidateCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    auto pd_state = Get<PHYSICAL_DEVICE_STATE>(physicalDevice);

    if (pd_state) {
        const char* missing_pnext_msg = "vkCreateDevice(): missing %s from the pNext chain of pCreateInfo";

        auto sc_10_props = LvlInitStruct<VkPhysicalDeviceVulkanSC10Properties>();
        auto pd_props = LvlInitStruct<VkPhysicalDeviceProperties2>(&sc_10_props);
        const auto& device_limits = pd_props.properties.limits;
        DispatchGetPhysicalDeviceProperties2(physicalDevice, &pd_props);

        uint32_t max_mip_levels =
            1u + static_cast<uint32_t>(log2(std::max({device_limits.maxImageDimension1D, device_limits.maxImageDimension2D,
                                                      device_limits.maxImageDimension3D, device_limits.maxImageDimensionCube})));

        const auto* sc_10_features = LvlFindInChain<VkPhysicalDeviceVulkanSC10Features>(pCreateInfo->pNext);
        if (sc_10_features == nullptr) {
            skip |= LogWarning(physicalDevice, kVUID_SC_CreateDevice_MissingVulkanSC10Features, missing_pnext_msg,
                               "VkPhysicalDeviceVulkanSC10Features");
        }

        const auto* object_reservation_info = LvlFindInChain<VkDeviceObjectReservationCreateInfo>(pCreateInfo->pNext);
        if (object_reservation_info == nullptr) {
            skip |= LogWarning(physicalDevice, kVUID_SC_CreateDevice_MissingObjectReservationInfo, missing_pnext_msg,
                               "VkDeviceObjectReservationCreateInfo");
        }

        uint32_t total_device_memory_request_count = 0;
        uint32_t total_sampler_request_count = 0;

        while (object_reservation_info != nullptr) {
            for (uint32_t i = 0; i < object_reservation_info->pipelineCacheCreateInfoCount; ++i) {
                const auto& create_info = object_reservation_info->pPipelineCacheCreateInfos[i];
                skip |= ValidatePipelineCacheCreateInfo(physicalDevice, "vkCreateDevice", create_info);
                skip |= ValidatePipelineCacheData(physicalDevice, create_info, i);
            }

            if (object_reservation_info->maxImageViewArrayLayers > device_limits.maxImageArrayLayers) {
                skip |= LogError(physicalDevice, "VUID-VkDeviceObjectReservationCreateInfo-maxImageViewArrayLayers-05014",
                                 "vkCreateDevice(): VkDeviceObjectReservationCreateInfo::maxImageViewArrayLayers (%u) "
                                 "exceeds device limit maxImageArrayLayers (%u).",
                                 object_reservation_info->maxImageViewArrayLayers, device_limits.maxImageArrayLayers);
            }

            if (object_reservation_info->maxImageViewMipLevels > max_mip_levels) {
                skip |= LogError(physicalDevice, "VUID-VkDeviceObjectReservationCreateInfo-maxImageViewMipLevels-05015",
                                 "vkCreateDevice(): VkDeviceObjectReservationCreateInfo::maxImageViewMipLevels (%u) "
                                 "exceeds the maximum number of mipmap levels (%u) in a complete mipmap chain based "
                                 "on the maximum of the device limits maxImageDimension1D (%u), maxImageDimension2D (%u), "
                                 "maxImageDimension3D (%u), and maxImageDimensionCube (%u).",
                                 object_reservation_info->maxImageViewMipLevels, max_mip_levels, device_limits.maxImageDimension1D,
                                 device_limits.maxImageDimension2D, device_limits.maxImageDimension3D,
                                 device_limits.maxImageDimensionCube);
            }

            if (object_reservation_info->maxLayeredImageViewMipLevels > max_mip_levels) {
                skip |= LogError(physicalDevice, "VUID-VkDeviceObjectReservationCreateInfo-maxLayeredImageViewMipLevels-05016",
                                 "vkCreateDevice(): VkDeviceObjectReservationCreateInfo::maxLayeredImageViewMipLevels (%u) "
                                 "exceeds the maximum number of mipmap levels (%u) in a complete mipmap chain based "
                                 "on the maximum of the device limits maxImageDimension1D (%u), maxImageDimension2D (%u), "
                                 "maxImageDimension3D (%u), and maxImageDimensionCube (%u).",
                                 object_reservation_info->maxLayeredImageViewMipLevels, max_mip_levels,
                                 device_limits.maxImageDimension1D, device_limits.maxImageDimension2D,
                                 device_limits.maxImageDimension3D, device_limits.maxImageDimensionCube);
            }

            uint32_t max_subpass_descriptions =
                object_reservation_info->renderPassRequestCount * sc_10_props.maxRenderPassSubpasses;
            if (object_reservation_info->subpassDescriptionRequestCount > max_subpass_descriptions) {
                skip |= LogError(physicalDevice, "VUID-VkDeviceObjectReservationCreateInfo-subpassDescriptionRequestCount-05017",
                                 "vkCreateDevice(): VkDeviceObjectReservationCreateInfo::subpassDescriptionRequestCount (%u) "
                                 "exceeds the maximum number of subpass descriptions (%u) that can be used, determined by "
                                 "multiplying VkDeviceObjectReservationCreateInfo::renderPassRequestCount (%u) by "
                                 "VkPhysicalDeviceVulkanSC10Properties::maxRenderPassSubpasses (%u).",
                                 object_reservation_info->subpassDescriptionRequestCount, max_subpass_descriptions,
                                 object_reservation_info->renderPassRequestCount, sc_10_props.maxRenderPassSubpasses);
            }

            uint32_t max_attachment_descriptions =
                object_reservation_info->renderPassRequestCount * sc_10_props.maxFramebufferAttachments;
            if (object_reservation_info->attachmentDescriptionRequestCount > max_attachment_descriptions) {
                skip |= LogError(physicalDevice, "VUID-VkDeviceObjectReservationCreateInfo-attachmentDescriptionRequestCount-05018",
                                 "vkCreateDevice(): VkDeviceObjectReservationCreateInfo::attachmentDescriptionRequestCount (%u) "
                                 "exceeds the maximum number of subpass descriptions (%u) that can be used, determined by "
                                 "multiplying VkDeviceObjectReservationCreateInfo::renderPassRequestCount (%u) by "
                                 "VkPhysicalDeviceVulkanSC10Properties::maxFramebufferAttachments (%u).",
                                 object_reservation_info->attachmentDescriptionRequestCount, max_attachment_descriptions,
                                 object_reservation_info->renderPassRequestCount, sc_10_props.maxFramebufferAttachments);
            }

            total_device_memory_request_count += object_reservation_info->deviceMemoryRequestCount;
            total_sampler_request_count += object_reservation_info->samplerRequestCount;
            object_reservation_info = LvlFindInChain<VkDeviceObjectReservationCreateInfo>(object_reservation_info->pNext);
        }

        if (total_device_memory_request_count > device_limits.maxMemoryAllocationCount) {
            skip |= LogError(physicalDevice, "VUID-vkCreateDevice-deviceMemoryRequestCount-05095",
                             "vkCreateDevice(): the sum of deviceMemoryRequestCount over all "
                             "VkDeviceObjectReservationCreateInfo structures (%u) exceed the "
                             "device limit maxMemoryAllocationCount (%u).",
                             total_device_memory_request_count, device_limits.maxMemoryAllocationCount);
        }

        if (total_sampler_request_count > device_limits.maxSamplerAllocationCount) {
            skip |= LogError(physicalDevice, "VUID-vkCreateDevice-samplerRequestCount-05096",
                             "vkCreateDevice(): the sum of samplerRequestCount over all "
                             "VkDeviceObjectReservationCreateInfo structures (%u) exceeds the "
                             "device limit maxSamplerAllocationCount (%u).",
                             total_device_memory_request_count, device_limits.maxMemoryAllocationCount);
        }
    }

    return skip;
}

void SCCoreChecks::CreateDevice(const VkDeviceCreateInfo* pCreateInfo) {
    // The state tracker sets up the device state
    BASE::CreateDevice(pCreateInfo);
}

bool SCCoreChecks::PreCallValidateCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) const {
    bool skip = BASE::PreCallValidateCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);

    skip |= ValidateObjectRequestCount(device, "vkCreateCommandPool", "VUID-vkCreateCommandPool-device-05068", "command pools",
                                       Count<COMMAND_POOL_STATE>(), "commandPoolRequestCount",
                                       sc_object_limits_.commandPoolRequestCount, 1);

    const auto* mem_reservation_info = LvlFindInChain<VkCommandPoolMemoryReservationCreateInfo>(pCreateInfo->pNext);
    if (mem_reservation_info) {
        if (mem_reservation_info->commandPoolReservedSize == 0) {
            skip |= LogError(device, "VUID-VkCommandPoolMemoryReservationCreateInfo-commandPoolReservedSize-05003",
                             "vkCreateCommandPool(): VkCommandPoolMemoryReservationCreateInfo::commandPoolReservedSize is zero.");
        }
        if (mem_reservation_info->commandPoolMaxCommandBuffers == 0) {
            skip |=
                LogError(device, "VUID-VkCommandPoolMemoryReservationCreateInfo-commandPoolMaxCommandBuffers-05004",
                         "vkCreateCommandPool(): VkCommandPoolMemoryReservationCreateInfo::commandPoolMaxCommandBuffers is zero.");
        } else if (mem_reservation_info->commandPoolMaxCommandBuffers > phys_dev_props_sc_10_.maxCommandPoolCommandBuffers) {
            skip |=
                LogError(device, "VUID-VkCommandPoolMemoryReservationCreateInfo-commandPoolMaxCommandBuffers-05090",
                         "vkCreateCommandPool(): VkCommandPoolMemoryReservationCreateInfo::commandPoolMaxCommandBuffers (%u) is "
                         "greater than VkPhysicalDeviceVulkanSC10Properties::maxCommandPoolCommandBuffers (%u).",
                         mem_reservation_info->commandPoolMaxCommandBuffers, phys_dev_props_sc_10_.maxCommandPoolCommandBuffers);
        }
        uint32_t reserved_command_buffers = sc_reserved_objects_.command_buffers.load();
        if (reserved_command_buffers + mem_reservation_info->commandPoolMaxCommandBuffers >
            sc_object_limits_.commandBufferRequestCount) {
            skip |= LogError(device, "VUID-VkCommandPoolMemoryReservationCreateInfo-commandPoolMaxCommandBuffers-05074",
                             "vkCreateCommandPool(): VkCommandPoolMemoryReservationCreateInfo::commandPoolMaxCommandBuffers (%u) "
                             "plus the number of already reserved command buffers (%u) is greater than the total number of "
                             "command buffers requested (%u).",
                             mem_reservation_info->commandPoolMaxCommandBuffers, reserved_command_buffers,
                             sc_object_limits_.commandBufferRequestCount);
        }
    } else {
        skip |=
            LogError(device, "VUID-VkCommandPoolCreateInfo-pNext-05002",
                     "vkCreateCommandPool(): missing VkCommandPoolMemoryReservationCreateInfo from the pNext chain of pCreateInfo");
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            VkDescriptorSetLayout* pSetLayout) const {
    bool skip = BASE::PreCallValidateCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);

    skip |= ValidateObjectRequestCount(device, "vkCreateDescriptorSetLayout", "VUID-vkCreateDescriptorSetLayout-device-05068",
                                       "descriptor set layouts", Count<cvdescriptorset::DescriptorSetLayout>(),
                                       "descriptorSetLayout", sc_object_limits_.descriptorSetLayoutRequestCount, 1);

    if (pCreateInfo) {
        if (pCreateInfo->bindingCount > phys_dev_props_sc_10_.maxDescriptorSetLayoutBindings) {
            skip |= LogError(device, "VUID-VkDescriptorSetLayoutCreateInfo-bindingCount-05011",
                             "vkCreateDescriptorSetLayout(): pCreateInfo->bindingCount (%u) exceeds the device limit "
                             "VkPhysicalDeviceVulkanSC10Properties::maxDescriptorSetLayoutBindings (%u).",
                             pCreateInfo->bindingCount, phys_dev_props_sc_10_.maxDescriptorSetLayoutBindings);
        }

        skip |= ValidateCombinedRequestCount(
            device, "vkCreateDescriptorSetLayout", "VUID-vkCreateDescriptorSetLayout-layoutbindings-device-05089",
            "VkDescriptorSetLayout", "descriptor set layout bindings", sc_reserved_objects_.descriptor_set_layout_bindings.load(),
            "descriptorSetLayoutBinding", sc_object_limits_.descriptorSetLayoutBindingRequestCount, "pCreateInfo->bindingCount",
            pCreateInfo->bindingCount);

        uint32_t requested_immutable_samplers = 0;
        for (uint32_t i = 0; i < pCreateInfo->bindingCount; ++i) {
            const auto& binding = pCreateInfo->pBindings[i];
            if (binding.binding >= sc_object_limits_.descriptorSetLayoutBindingLimit) {
                skip |= LogError(device, "VUID-VkDescriptorSetLayoutBinding-binding-05012",
                                 "vkCreateDescriptorSetLayout(): pCreateInfo->pBindings[%u].binding (%u) exceeds the limit "
                                 "requested in VkDeviceObjectReservationCreateInfo::descriptorSetLayoutBindingLimit (%u).",
                                 i, binding.binding, sc_object_limits_.descriptorSetLayoutBindingLimit);
            }

            if ((binding.descriptorType == VK_DESCRIPTOR_TYPE_SAMPLER ||
                 binding.descriptorType == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) &&
                binding.pImmutableSamplers != nullptr) {
                requested_immutable_samplers += binding.descriptorCount;
            }
        }

        if (requested_immutable_samplers > sc_object_limits_.maxImmutableSamplersPerDescriptorSetLayout) {
            skip |= LogError(device, "VUID-VkDescriptorSetLayoutCreateInfo-descriptorCount-05071",
                             "vkCreateDescriptorSetLayout(): the total immutable samplers (%u) across the specified "
                             "bindings exceeds the limit requested in VkDeviceObjectReservationCreateInfo::"
                             "maxImmutableSamplersPerDescriptorSetLayout (%u).",
                             requested_immutable_samplers, sc_object_limits_.maxImmutableSamplersPerDescriptorSetLayout);
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       VkPipelineLayout* pPipelineLayout) const {
    bool skip = BASE::PreCallValidateCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);

    skip |= ValidateObjectRequestCount(device, "vkCreatePipelineLayout", "VUID-vkCreatePipelineLayout-device-05068",
                                       "pipeline layouts", Count<PIPELINE_LAYOUT_STATE>(), "pipelineLayout",
                                       sc_object_limits_.pipelineLayoutRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       VkDescriptorPool* pDescriptorPool) const {
    bool skip = BASE::PreCallValidateCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);

    skip |= ValidateObjectRequestCount(device, "vkCreateDescriptorPool", "VUID-vkCreateDescriptorPool-device-05068",
                                       "descriptor pool", Count<DESCRIPTOR_POOL_STATE>(), "descriptorPool",
                                       sc_object_limits_.descriptorPoolRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                                         VkCommandBuffer* pCommandBuffers) const {
    bool skip = false;

    auto cp_state = Get<SC_COMMAND_POOL_STATE>(pAllocateInfo->commandPool);
    if (!cp_state) return false;

    if (cp_state->commandBuffers.size() + pAllocateInfo->commandBufferCount > cp_state->max_command_buffers) {
        skip |= LogError(device, "VUID-VkCommandBufferAllocateInfo-commandPool-05006",
                         "vkAllocateCommandBuffers(): the number of command buffers currently allocated from %s (%zu) plus "
                         "pAllocateInfo->commandBufferCount (%u) is greater than the "
                         "VkCommandPoolMemoryReservationCreateInfo::commandPoolMaxCommandBuffers (%u) "
                         "the command pool was created with.",
                         report_data->FormatHandle(pAllocateInfo->commandPool).c_str(), cp_state->commandBuffers.size(),
                         pAllocateInfo->commandBufferCount, cp_state->max_command_buffers);
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                                         VkDescriptorSet* pDescriptorSets, void* ads_state_data) const {
    bool skip = BASE::PreCallValidateAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets, ads_state_data);

    if (pAllocateInfo) {
        skip |= ValidateObjectRequestCount(device, "vkAllocateDescriptorSets", "VUID-vkAllocateDescriptorSets-device-05068",
                                           "descriptor sets", Count<cvdescriptorset::DescriptorSet>(), "descriptorSet",
                                           sc_object_limits_.descriptorSetRequestCount, "pAllocateInfo->descriptorSetCount",
                                           pAllocateInfo->descriptorSetCount);
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) const {
    bool skip = BASE::PreCallValidateAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);

    skip |= ValidateObjectRequestCount(device, "vkAllocateMemory", "VUID-vkAllocateMemory-device-05068", "device memory objects",
                                       Count<DEVICE_MEMORY_STATE>(), "deviceMemory", sc_object_limits_.deviceMemoryRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t count,
                                                         const VkComputePipelineCreateInfo* pCreateInfos,
                                                         const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                         void* ccpl_state_data) const {
    bool skip = BASE::PreCallValidateCreateComputePipelines(device, pipelineCache, count, pCreateInfos, pAllocator, pPipelines,
                                                            ccpl_state_data);

    skip |= ValidateObjectRequestCount(device, "vkCreateComputePipelines", "VUID-vkCreateComputePipelines-device-05068",
                                       "compute pipelines", sc_reserved_objects_.compute_pipelines.load(), "computePipeline",
                                       sc_object_limits_.computePipelineRequestCount, "createInfoCount", count);

    skip |= ValidatePipelinePoolMemory(device, "vkCreateComputePipelines", count, pCreateInfos);

    if (pCreateInfos != nullptr) {
        for (uint32_t i = 0; i < count; i++) {
            if (pCreateInfos[i].basePipelineHandle != VK_NULL_HANDLE) {
                skip |= LogError(device, "VUID-VkComputePipelineCreateInfo-basePipelineHandle-05024",
                                 "vkCreateComputePipelines(): pCreateInfo[%u].basePipelineHandle is not VK_NULL_HANDLE.", i);
            }
            if (pCreateInfos[i].basePipelineIndex != 0) {
                skip |= LogError(device, "VUID-VkComputePipelineCreateInfo-basePipelineIndex-05025",
                                 "vkCreateComputePipelines(): pCreateInfo[%u].basePipelineIndex (%u) is not 0.", i,
                                 pCreateInfos[i].basePipelineIndex);
            }
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t count,
                                                          const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                          const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                          void* cgpl_state_data) const {
    bool skip = BASE::PreCallValidateCreateGraphicsPipelines(device, pipelineCache, count, pCreateInfos, pAllocator, pPipelines,
                                                             cgpl_state_data);

    skip |= ValidateObjectRequestCount(device, "vkCreateGraphicsPipelines", "VUID-vkCreateGraphicsPipelines-device-05068",
                                       "graphics pipelines", sc_reserved_objects_.graphics_pipelines.load(), "graphicsPipeline",
                                       sc_object_limits_.graphicsPipelineRequestCount, "createInfoCount", count);

    skip |= ValidatePipelinePoolMemory(device, "vkCreateGraphicsPipelines", count, pCreateInfos);

    if (pCreateInfos != nullptr) {
        for (uint32_t i = 0; i < count; i++) {
            if (pCreateInfos[i].basePipelineHandle != VK_NULL_HANDLE) {
                skip |= LogError(device, "VUID-VkGraphicsPipelineCreateInfo-basePipelineHandle-05024",
                                 "vkCreateGraphicsPipelines(): pCreateInfo[%u].basePipelineHandle is not VK_NULL_HANDLE.", i);
            }
            if (pCreateInfos[i].basePipelineIndex != 0) {
                skip |= LogError(device, "VUID-VkGraphicsPipelineCreateInfo-basePipelineIndex-05025",
                                 "vkCreateGraphicsPipelines(): pCreateInfo[%u].basePipelineIndex (%u) is not 0.", i,
                                 pCreateInfos[i].basePipelineIndex);
            }
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator,
                                                      VkPipelineCache* pPipelineCache) const {
    bool skip = BASE::PreCallValidateCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);

    skip |= ValidateObjectRequestCount(device, "vkCreatePipelineCache", "VUID-vkCreatePipelineCache-device-05068",
                                       "pipeline caches", Count<SC_PIPELINE_CACHE_STATE>(), "pipelineCache",
                                       sc_object_limits_.pipelineCacheRequestCount, 1);

    if (pCreateInfo) {
        skip |= ValidatePipelineCacheCreateInfo(device, "vkCreatePipelineCache", *pCreateInfo);

        auto it = sc_pipeline_cache_map_.find(pCreateInfo->pInitialData);
        if (it == sc_pipeline_cache_map_.end() || it->second->create_info.flags != pCreateInfo->flags ||
            it->second->create_info.initialDataSize != pCreateInfo->initialDataSize) {
            skip |= LogError(device, "VUID-vkCreatePipelineCache-pCreateInfo-05045",
                             "vkCreatePipelineCache(): pCreateInfo does not match any of the VkPipelineCacheCreateInfo "
                             "structures specified in VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos "
                             "at device creation time.");
        } else if (memcmp(it->second->raw_data.data(), pCreateInfo->pInitialData, pCreateInfo->initialDataSize) != 0) {
            skip |= LogError(device, "VUID-vkCreatePipelineCache-pCreateInfo-05045",
                             "vkCreatePipelineCache(): the data pointed to by pCreateInfo->pInitialData does not match "
                             "the data specified in VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos "
                             "at device creation time.");
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) const {
    bool skip = BASE::PreCallValidateCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);

    skip |= ValidateObjectRequestCount(device, "vkCreateQueryPool", "VUID-vkCreateQueryPool-device-05068", "query pools",
                                       Count<QUERY_POOL_STATE>(), "queryPool", sc_object_limits_.queryPoolRequestCount, 1);

    if (pCreateInfo) {
        if (pCreateInfo->queryType == VK_QUERY_TYPE_OCCLUSION &&
            pCreateInfo->queryCount > sc_object_limits_.maxOcclusionQueriesPerPool) {
            skip |= LogError(device, "VUID-VkQueryPoolCreateInfo-queryType-05046",
                             "vkCreateQueryPool(): pCreateInfo->queryCount (%u) exceeds the limit requested in "
                             "VkDeviceObjectReservationCreateInfo::maxOcclusionQueriesPerPool (%u).",
                             pCreateInfo->queryCount, sc_object_limits_.maxOcclusionQueriesPerPool);
        }

        if (pCreateInfo->queryType == VK_QUERY_TYPE_PIPELINE_STATISTICS &&
            pCreateInfo->queryCount > sc_object_limits_.maxPipelineStatisticsQueriesPerPool) {
            skip |= LogError(device, "VUID-VkQueryPoolCreateInfo-queryType-05047",
                             "vkCreateQueryPool(): pCreateInfo->queryCount (%u) exceeds the limit requested in "
                             "VkDeviceObjectReservationCreateInfo::maxPipelineStatisticsQueriesPerPool (%u).",
                             pCreateInfo->queryCount, sc_object_limits_.maxPipelineStatisticsQueriesPerPool);
        }

        if (pCreateInfo->queryType == VK_QUERY_TYPE_TIMESTAMP &&
            pCreateInfo->queryCount > sc_object_limits_.maxTimestampQueriesPerPool) {
            skip |= LogError(device, "VUID-VkQueryPoolCreateInfo-queryType-05048",
                             "vkCreateQueryPool(): pCreateInfo->queryCount (%u) exceeds the limit requested in "
                             "VkDeviceObjectReservationCreateInfo::maxTimestampQueriesPerPool (%u).",
                             pCreateInfo->queryCount, sc_object_limits_.maxTimestampQueriesPerPool);
        }

        if (pCreateInfo->queryType == VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR &&
            pCreateInfo->queryCount > sc_perf_query_limits_.maxPerformanceQueriesPerPool) {
            skip |= LogError(device, "VUID-VkQueryPoolCreateInfo-queryType-05049",
                             "vkCreateQueryPool(): pCreateInfo->queryCount (%u) exceeds the limit requested in "
                             "VkPerformanceQueryReservationInfoKHR::maxPerformanceQueriesPerPool (%u).",
                             pCreateInfo->queryCount, sc_perf_query_limits_.maxPerformanceQueriesPerPool);
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) const {
    bool skip = BASE::PreCallValidateCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);

    skip |= ValidateObjectRequestCount(device, "vkCreateRenderPass", "VUID-vkCreateRenderPass-device-05068", "render passes",
                                       Count<RENDER_PASS_STATE>(), "renderPass", sc_object_limits_.renderPassRequestCount, 1);

    if (pCreateInfo) {
        skip |= ValidateCombinedRequestCount(device, "vkCreateRenderPass", "VUID-vkCreateRenderPass-subpasses-device-05089",
                                             "VkRenderPass", "subpasses", sc_reserved_objects_.subpass_descriptions.load(),
                                             "subpassDescription", sc_object_limits_.subpassDescriptionRequestCount,
                                             "pCreateInfo->subpassCount", pCreateInfo->subpassCount);
        skip |= ValidateCombinedRequestCount(device, "vkCreateRenderPass", "VUID-vkCreateRenderPass-attachments-device-05089",
                                             "VkRenderPass", "attachments", sc_reserved_objects_.attachment_descriptions.load(),
                                             "attachmentDescription", sc_object_limits_.attachmentDescriptionRequestCount,
                                             "pCreateInfo->attachmentCount", pCreateInfo->attachmentCount);

        if (pCreateInfo->subpassCount > phys_dev_props_sc_10_.maxRenderPassSubpasses) {
            skip |= LogError(device, "VUID-VkRenderPassCreateInfo-subpassCount-05050",
                             "vkCreateRenderPass(): pCreateInfo->subpassCount (%u) exceeds the device limit "
                             "VkPhysicalDeviceVulkanSC10Properties::maxRenderPassSubpasses (%u).",
                             pCreateInfo->subpassCount, phys_dev_props_sc_10_.maxRenderPassSubpasses);
        }
        if (pCreateInfo->dependencyCount > phys_dev_props_sc_10_.maxRenderPassDependencies) {
            skip |= LogError(device, "VUID-VkRenderPassCreateInfo-dependencyCount-05051",
                             "vkCreateRenderPass(): pCreateInfo->dependencyCount (%u) exceeds the device limit "
                             "VkPhysicalDeviceVulkanSC10Properties::maxRenderPassDependencies (%u).",
                             pCreateInfo->dependencyCount, phys_dev_props_sc_10_.maxRenderPassDependencies);
        }
        if (pCreateInfo->attachmentCount > phys_dev_props_sc_10_.maxFramebufferAttachments) {
            skip |= LogError(device, "VUID-VkRenderPassCreateInfo-attachmentCount-05052",
                             "vkCreateRenderPass(): pCreateInfo->attachmentCount (%u) exceeds the device limit "
                             "VkPhysicalDeviceVulkanSC10Properties::maxFramebufferAttachments (%u).",
                             pCreateInfo->attachmentCount, phys_dev_props_sc_10_.maxFramebufferAttachments);
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) const {
    bool skip = BASE::PreCallValidateCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);

    skip |= ValidateObjectRequestCount(device, "vkCreateRenderPass2", "VUID-vkCreateRenderPass2-device-05068", "render passes",
                                       Count<RENDER_PASS_STATE>(), "renderPass", sc_object_limits_.renderPassRequestCount, 1);

    if (pCreateInfo) {
        skip |= ValidateCombinedRequestCount(device, "vkCreateRenderPass", "VUID-vkCreateRenderPass2-subpasses-device-05089",
                                             "VkRenderPass", "subpasses", sc_reserved_objects_.subpass_descriptions.load(),
                                             "subpassDescription", sc_object_limits_.subpassDescriptionRequestCount,
                                             "pCreateInfo->subpassCount", pCreateInfo->subpassCount);
        skip |= ValidateCombinedRequestCount(device, "vkCreateRenderPass", "VUID-vkCreateRenderPass2-attachments-device-05089",
                                             "VkRenderPass", "attachments", sc_reserved_objects_.attachment_descriptions.load(),
                                             "attachmentDescription", sc_object_limits_.attachmentDescriptionRequestCount,
                                             "pCreateInfo->attachmentCount", pCreateInfo->attachmentCount);

        if (pCreateInfo->subpassCount > phys_dev_props_sc_10_.maxRenderPassSubpasses) {
            skip |= LogError(device, "VUID-VkRenderPassCreateInfo2-subpassCount-05055",
                             "vkCreateRenderPass2(): pCreateInfo->subpassCount (%u) exceeds the device limit "
                             "VkPhysicalDeviceVulkanSC10Properties::maxRenderPassSubpasses (%u).",
                             pCreateInfo->subpassCount, phys_dev_props_sc_10_.maxRenderPassSubpasses);
        }
        if (pCreateInfo->dependencyCount > phys_dev_props_sc_10_.maxRenderPassDependencies) {
            skip |= LogError(device, "VUID-VkRenderPassCreateInfo2-dependencyCount-05056",
                             "vkCreateRenderPass2(): pCreateInfo->dependencyCount (%u) exceeds the device limit "
                             "VkPhysicalDeviceVulkanSC10Properties::maxRenderPassDependencies (%u).",
                             pCreateInfo->dependencyCount, phys_dev_props_sc_10_.maxRenderPassDependencies);
        }
        if (pCreateInfo->attachmentCount > phys_dev_props_sc_10_.maxFramebufferAttachments) {
            skip |= LogError(device, "VUID-VkRenderPassCreateInfo2-attachmentCount-05057",
                             "vkCreateRenderPass2(): pCreateInfo->attachmentCount (%u) exceeds the device limit "
                             "VkPhysicalDeviceVulkanSC10Properties::maxFramebufferAttachments (%u).",
                             pCreateInfo->attachmentCount, phys_dev_props_sc_10_.maxFramebufferAttachments);
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) const {
    bool skip = BASE::PreCallValidateCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);

    skip |= ValidateObjectRequestCount(device, "vkCreateFramebuffer", "VUID-vkCreateFramebuffer-device-05068", "framebuffers",
                                       Count<FRAMEBUFFER_STATE>(), "framebuffer", sc_object_limits_.framebufferRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) const {
    bool skip = BASE::PreCallValidateCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);

    skip |= ValidateObjectRequestCount(device, "vkCreateBuffer", "VUID-vkCreateBuffer-device-05068", "buffers",
                                       Count<BUFFER_STATE>(), "buffer", sc_object_limits_.bufferRequestCount, 1);

    if (pCreateInfo) {
        VkBufferCreateFlags unsupported_flags =
            pCreateInfo->flags &
            (VK_BUFFER_CREATE_SPARSE_BINDING_BIT | VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT | VK_BUFFER_CREATE_SPARSE_ALIASED_BIT);
        if (unsupported_flags != 0) {
            skip |= LogError(device, "VUID-VkBufferCreateInfo-flags-05061",
                             "vkCreateBuffer(): pCreateInfo->flags contains unsupported flag(s) %s.",
                             string_VkBufferCreateFlags(unsupported_flags).c_str());
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkBufferView* pView) const {
    bool skip = BASE::PreCallValidateCreateBufferView(device, pCreateInfo, pAllocator, pView);

    skip |= ValidateObjectRequestCount(device, "vkCreateBufferView", "VUID-vkCreateBufferView-device-05068", "buffer views",
                                       Count<BUFFER_VIEW_STATE>(), "bufferView", sc_object_limits_.bufferViewRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator, VkImage* pImage) const {
    bool skip = BASE::PreCallValidateCreateImage(device, pCreateInfo, pAllocator, pImage);

    skip |= ValidateObjectRequestCount(device, "vkCreateImage", "VUID-vkCreateImage-device-05068", "images", Count<IMAGE_STATE>(),
                                       "image", sc_object_limits_.imageRequestCount, 1);

    if (pCreateInfo) {
        VkImageCreateFlags unsupported_flags =
            pCreateInfo->flags & (VK_IMAGE_CREATE_SPARSE_BINDING_BIT | VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT |
                                  VK_IMAGE_CREATE_SPARSE_ALIASED_BIT | VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT);
        if (unsupported_flags != 0) {
            skip |= LogError(device, "VUID-VkImageCreateInfo-flags-05062",
                             "vkCreateImage(): pCreateInfo->flags contains unsupported flag(s) %s.",
                             string_VkImageCreateFlags(unsupported_flags).c_str());
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkImageView* pView) const {
    bool skip = BASE::PreCallValidateCreateImageView(device, pCreateInfo, pAllocator, pView);
    auto image_state = Get<IMAGE_STATE>(pCreateInfo->image);
    if (!image_state) {
        return skip;
    }

    skip |= ValidateObjectRequestCount(device, "vkCreateImageView", "VUID-vkCreateImageView-device-05068", "image views",
                                       Count<IMAGE_VIEW_STATE>(), "imageView", sc_object_limits_.imageViewRequestCount, 1);

    if (pCreateInfo) {
        const uint32_t effective_mip_levels = ResolveRemainingLevels(image_state->createInfo, pCreateInfo->subresourceRange);
        const uint32_t effective_array_layers = ResolveRemainingLayers(image_state->createInfo, pCreateInfo->subresourceRange);

        if (effective_mip_levels > sc_object_limits_.maxImageViewMipLevels) {
            skip |= LogError(device, "VUID-VkImageViewCreateInfo-subresourceRange-05064",
                             "vkCreateImageView(): the requested mip level count (%u) exceeds the limit "
                             "requested in VkDeviceObjectReservationCreateInfo::maxImageViewMipLevels (%u).",
                             effective_mip_levels, sc_object_limits_.maxImageViewMipLevels);
        }

        if (effective_array_layers > sc_object_limits_.maxImageViewArrayLayers) {
            skip |= LogError(device, "VUID-VkImageViewCreateInfo-subresourceRange-05065",
                             "vkCreateImageView(): the requested array layer count (%u) exceeds the limit "
                             "requested in VkDeviceObjectReservationCreateInfo::maxImageViewArrayLayers (%u).",
                             effective_array_layers, sc_object_limits_.maxImageViewArrayLayers);
        }

        if (effective_array_layers > 1) {
            uint32_t reserved_layered_image_views = sc_reserved_objects_.layered_image_views.load();
            if (reserved_layered_image_views >= sc_object_limits_.layeredImageViewRequestCount) {
                skip |= LogError(device, "VUID-vkCreateImageView-subresourceRange-05063",
                                 "vkCreateImageView(): the number of image views with more than one "
                                 "array layer currently allocated from the device (%u) plus 1 is "
                                 "greater than the total number of layered image views requested via "
                                 "VkDeviceObjectReservationCreateInfo::layeredImageViewRequestCount (%u)",
                                 reserved_layered_image_views, sc_object_limits_.layeredImageViewRequestCount);
            }

            if (effective_mip_levels > sc_object_limits_.maxLayeredImageViewMipLevels) {
                skip |= LogError(device, "VUID-VkImageViewCreateInfo-subresourceRange-05066",
                                 "vkCreateImageView(): the requested mip level count (%u) exceeds the limit "
                                 "requested in VkDeviceObjectReservationCreateInfo::maxLayeredImageViewMipLevels (%u).",
                                 effective_mip_levels, sc_object_limits_.maxLayeredImageViewMipLevels);
            }
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) const {
    bool skip = BASE::PreCallValidateCreateSampler(device, pCreateInfo, pAllocator, pSampler);

    skip |= ValidateObjectRequestCount(device, "vkCreateSampler", "VUID-vkCreateSampler-device-05068", "samplers",
                                       Count<SAMPLER_STATE>(), "sampler", sc_object_limits_.samplerRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateSamplerYcbcrConversion(VkDevice device,
                                                               const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               VkSamplerYcbcrConversion* pYcbcrConversion) const {
    bool skip = BASE::PreCallValidateCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);

    skip |= ValidateObjectRequestCount(device, "vkCreateSamplerYcbcrConversion", "VUID-vkCreateSamplerYcbcrConversion-device-05068",
                                       "sampler conversions", Count<SAMPLER_YCBCR_CONVERSION_STATE>(), "samplerYcbcrConversion",
                                       sc_object_limits_.samplerYcbcrConversionRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator, VkFence* pFence) const {
    bool skip = BASE::PreCallValidateCreateFence(device, pCreateInfo, pAllocator, pFence);

    skip |= ValidateObjectRequestCount(device, "vkCreateFence", "VUID-vkCreateFence-device-05068", "fences", Count<FENCE_STATE>(),
                                       "fence", sc_object_limits_.fenceRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) const {
    bool skip = BASE::PreCallValidateCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);

    skip |= ValidateObjectRequestCount(device, "vkCreateSemaphore", "VUID-vkCreateSemaphore-device-05068", "semaphores",
                                       Count<SEMAPHORE_STATE>(), "semaphore", sc_object_limits_.semaphoreRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) const {
    bool skip = BASE::PreCallValidateCreateEvent(device, pCreateInfo, pAllocator, pEvent);

    skip |= ValidateObjectRequestCount(device, "vkCreateEvent", "VUID-vkCreateEvent-device-05068", "events", Count<EVENT_STATE>(),
                                       "event", sc_object_limits_.eventRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) const {
    bool skip = BASE::PreCallValidateCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);

    skip |= ValidateObjectRequestCount(device, "vkCreateSwapchainKHR", "VUID-vkCreateSwapchainKHR-device-05068", "swapchains",
                                       Count<SWAPCHAIN_NODE>(), "swapchain", sc_object_limits_.swapchainRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                                            const VkSwapchainCreateInfoKHR* pCreateInfos,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            VkSwapchainKHR* pSwapchains) const {
    bool skip = BASE::PreCallValidateCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    skip |= ValidateObjectRequestCount(device, "vkCreateSharedSwapchainsKHR", "VUID-vkCreateSharedSwapchainsKHR-device-05068",
                                       "swapchains", Count<SWAPCHAIN_NODE>(), "swapchain", sc_object_limits_.swapchainRequestCount,
                                       "swapchainCount", swapchainCount);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfoEXT* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           VkPrivateDataSlotEXT* pPrivateDataSlot) const {
    bool skip = BASE::PreCallValidateCreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot);

    uint32_t reserved_private_data_slots = sc_reserved_objects_.private_data_slots.load();
    if (reserved_private_data_slots >= sc_private_data_slot_limits_.privateDataSlotRequestCount) {
        skip |= LogError(device, "VUID-vkCreatePrivateDataSlotEXT-device-05000",
                         "vkCreatePrivateDataSlotEXT(): the number of private data slots currently allocated from "
                         "the device (%u) plus one is greater than the total number of private data slots requested "
                         "via VkDevicePrivateDataCreateInfoEXT::privateDataSlotRequestCount (%u).",
                         reserved_private_data_slots, sc_private_data_slot_limits_.privateDataSlotRequestCount);
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateBindImageMemory2(VkDevice device, uint32_t bindInfoCount,
                                                   const VkBindImageMemoryInfo* pBindInfos) const {
    bool skip = BASE::PreCallValidateBindImageMemory2(device, bindInfoCount, pBindInfos);

    for (uint32_t i = 0; i < bindInfoCount; ++i) {
        auto device_group_info = LvlFindInChain<VkBindImageMemoryDeviceGroupInfo>(pBindInfos[i].pNext);
        if (device_group_info && device_group_info->splitInstanceBindRegionCount != 0) {
            skip |= LogError(device, "VUID-VkBindImageMemoryDeviceGroupInfo-splitInstanceBindRegionCount-05067",
                             "vkBindImageMemory2(): VkBindImageMemoryDeviceGroupInfo::splitInstanceBindRegionCount "
                             "(%u) in the pNext chain of pBindInfos[%u] is not zero.",
                             device_group_info->splitInstanceBindRegionCount, i);
        }
    }

    return skip;
}
