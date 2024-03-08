/* Copyright (c) 2023-2024 The Khronos Group Inc.
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

#include "vulkan/vk_enum_string_helper.h"
#include "state_tracker/image_state.h"
#include "generated/chassis.h"
#include "vulkansc/sc_vuid_enums.h"
#include "vulkansc/core_checks/sc_core_validation.h"
#include "vulkansc/state_tracker/sc_pipeline_state.h"
#include "utils/vk_layer_utils.h"
#include "generated/enum_flag_bits.h"

void SCCoreChecks::PreCallRecordCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                               VkInstance* pInstance, const RecordObject& record_obj) {
    InitFilters();
    BASE::PreCallRecordCreateInstance(pCreateInfo, pAllocator, pInstance, record_obj);
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

        // Filter VUIDs related to split-instance bind regions which is not supported in Vulkan SC
        "VUID-VkImageCreateInfo-physicalDeviceCount-01421",
        "VUID-VkImageCreateInfo-flags-02259",
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
        "VUID-VkSwapchainCreateInfoKHR-physicalDeviceCount-01429",

        // Filter VUIDs replaced by Vulkan SC specific ones
        "VUID-VkPipelineShaderStageCreateInfo-pName-00707",
        "VUID-VkCommandBufferBeginInfo-flags-00055",
        "VUID-VkSwapchainCreateInfoKHR-oldSwapchain-01933",

        // Filter other VUIDs that are not applicable to Vulkan SC
        "VUID-vkDestroySurfaceKHR-surface-01266",
    };

    for (const auto& filtered_vuid : filtered_vuids) {
        report_data->filter_message_ids.insert(hash_util::VuidHash(filtered_vuid));
    }
}

bool SCCoreChecks::ValidateObjectRequestCount(VkDevice device, const Location& loc, const char* vuid, const char* object_name_plural,
                                              size_t existing_count, const char* requested_count_name, uint32_t requested_count,
                                              const char* create_count_name, uint32_t create_count) const {
    bool skip = false;
    if (existing_count + create_count > requested_count) {
        skip |= LogError(vuid, device, loc,
                         "the number of %s currently allocated from the device (%zu) plus %s (%u) is "
                         "greater than the total number of %s requested via VkDeviceObjectReservationCreateInfo::%s (%u).",
                         object_name_plural, existing_count, create_count_name, create_count, object_name_plural,
                         requested_count_name, requested_count);
    }
    return skip;
}

bool SCCoreChecks::ValidateObjectRequestCount(VkDevice device, const Location& loc, const char* vuid, const char* object_name_plural,
                                              size_t existing_count, const char* requested_count_name, uint32_t requested_count,
                                              uint32_t create_count) const {
    bool skip = false;
    if (existing_count + create_count > requested_count) {
        skip |= LogError(vuid, device, loc,
                         "the number of %s currently allocated from the device (%zu) plus %u is "
                         "greater than the total number of %s requested via VkDeviceObjectReservationCreateInfo::%s (%u).",
                         object_name_plural, existing_count, create_count, object_name_plural, requested_count_name,
                         requested_count);
    }
    return skip;
}

bool SCCoreChecks::ValidateCombinedRequestCount(VkDevice device, const Location& loc, const char* vuid, const char* parent_object_name,
                                                const char* object_name_plural, uint32_t existing_count,
                                                const char* requested_count_name, uint32_t requested_count,
                                                const char* create_count_name, uint32_t create_count) const {
    bool skip = false;
    if (existing_count + create_count > requested_count) {
        skip |= LogError(vuid, device, loc,
                         "the number of %s currently allocated from the device (%u) across all %s objects "
                         "plus %s (%u) is greater than the total number of %s requested via "
                         "VkDeviceObjectReservationCreateInfo::%s (%u).",
                         object_name_plural, existing_count, parent_object_name, create_count_name, create_count,
                         object_name_plural, requested_count_name, requested_count);
    }
    return skip;
}

template <typename CreateInfo>
bool SCCoreChecks::ValidatePipelinePoolMemory(VkDevice device, const Location& loc, uint32_t create_info_count,
                                              const CreateInfo* create_info) const {
    bool skip = false;

    vvl::unordered_map<VkDeviceSize, uint32_t> reserved_pipeline_pool_entries{};
    for (uint32_t i = 0; i < create_info_count; ++i) {
        auto offline_info = vku::FindStructInPNextChain<VkPipelineOfflineCreateInfo>(create_info[i].pNext);
        if (offline_info) {
            reserved_pipeline_pool_entries[offline_info->poolEntrySize]++;
        }
    }

    std::unique_lock<std::mutex> lock(sc_used_pipeline_pool_size_map_mutex_);
    for (const auto& it : reserved_pipeline_pool_entries) {
        auto already_used_it = sc_used_pipeline_pool_size_map_.find(it.first);
        auto total_entries_it = sc_pipeline_pool_size_map_.find(it.first);

        if (total_entries_it == sc_pipeline_pool_size_map_.end()) {
            skip |= LogError("VUID-VkPipelineOfflineCreateInfo-poolEntrySize-05028", device, loc,
                             "poolEntrySize %" PRIu64 " was not requested at device creation time.", it.first);
        } else {
            uint32_t newly_reserved = it.second;
            uint32_t already_used = (already_used_it != sc_used_pipeline_pool_size_map_.end()) ? already_used_it->second : 0;
            uint32_t total_entries = total_entries_it->second;

            if (already_used + newly_reserved > total_entries) {
                const char* vuid = phys_dev_props_sc_10_.recyclePipelineMemory
                                       ? "VUID-VkPipelineOfflineCreateInfo-recyclePipelineMemory-05029"
                                       : "VUID-VkPipelineOfflineCreateInfo-recyclePipelineMemory-05030";

                skip |= LogError(vuid, device, loc,
                                 "the number of currently existing pipelines created with poolEntrySize %" PRIu64
                                 " (%u) plus the number of entries that this command would reserve (%u) "
                                 "is greater than the total number of pool entires (%u) reserved at device "
                                 "creation time.",
                                 it.first, already_used, newly_reserved, total_entries);
            }
        }
    }

    return skip;
}

template <typename VkHandle>
bool SCCoreChecks::ValidatePipelineCacheCreateInfo(VkHandle handle, const Location& loc,
                                                   const VkPipelineCacheCreateInfo& create_info) const {
    bool skip = false;

    const char* missing_flags_msg = "(%s) is missing %s.";

    if ((create_info.flags & VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT) == 0) {
        skip |= LogError("VUID-VkPipelineCacheCreateInfo-flags-05043", handle, loc.dot(Field::flags), missing_flags_msg,
                         string_VkPipelineCacheCreateFlags(create_info.flags).c_str(), "VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT");
    }

    if ((create_info.flags & VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT) == 0) {
        skip |= LogError("VUID-VkPipelineCacheCreateInfo-flags-05044", handle, loc.dot(Field::flags), missing_flags_msg,
                         string_VkPipelineCacheCreateFlags(create_info.flags).c_str(),
                         "VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT");
    }

    return skip;
}

bool SCCoreChecks::ValidatePipelineCacheData(VkPhysicalDevice physicalDevice, const VkPipelineCacheCreateInfo& create_info,
                                             const Location& loc) const {
    bool skip = false;
    bool header_valid = true;

    if (create_info.pInitialData == nullptr) {
        // No data to validate, should be already caught as a validation error by parameter validation
        return false;
    }

    if (create_info.initialDataSize < sizeof(VkPipelineCacheHeaderVersionOne)) {
        skip |= LogWarning(kVUID_SC_PipelineCacheData_TooSmall, physicalDevice, loc.dot(Field::initialDataSize),
                           "(%zu) is too small to verify pipeline cache header.", create_info.initialDataSize);
        // Return early here as we cannot validate anything else if the header is too small.
        return skip;
    }

    const uint32_t sc_header_size = sizeof(VkPipelineCacheHeaderVersionSafetyCriticalOne);

    vvl::sc::PipelineCacheData data(create_info);
    auto baseHeader = data.GetBaseHeader();
    assert(baseHeader.has_value());

    if (baseHeader->headerSize != sc_header_size) {
        skip |= LogWarning(kVUID_SC_PipelineCacheData_InvalidHeaderSize, physicalDevice, loc.dot(Field::pInitialData),
                           "has an invalid headerSize (%u) that does not match the header size of a Vulkan "
                           "SC pipeline cache VkPipelineCacheHeaderVersionSafetyCriticalOne (%u bytes).",
                           baseHeader->headerSize, sc_header_size);
        header_valid = false;
    }

    if (baseHeader->headerVersion != VK_PIPELINE_CACHE_HEADER_VERSION_SAFETY_CRITICAL_ONE) {
        skip |= LogWarning(kVUID_SC_PipelineCacheData_UnrecognizedHeaderVersion, physicalDevice, loc.dot(Field::pInitialData),
                           "has an invalid headerVersion %s (%u) that does not match the header version of "
                           "a Vulkan SC pipeline cache (VK_PIPELINE_CACHE_HEADER_VERSION_SAFETY_CRITICAL_ONE).",
                           string_VkPipelineCacheHeaderVersion(baseHeader->headerVersion), baseHeader->headerVersion);
        header_valid = false;
    }

    if (create_info.initialDataSize < sc_header_size) {
        skip |= LogWarning(kVUID_SC_PipelineCacheData_TooSmall, physicalDevice, loc.dot(Field::initialDataSize),
                           "is too small (%zu bytes) to contain a VkPipelineCacheHeaderVersionSafetyCriticalOne "
                           "(%u bytes) header.",
                           create_info.initialDataSize, sc_header_size);
        // Return early here as we cannot validate anything else if the header is too small.
        return skip;
    }

    if (data.header->validationVersion != VK_PIPELINE_CACHE_VALIDATION_VERSION_SAFETY_CRITICAL_ONE) {
        skip |= LogWarning(kVUID_SC_PipelineCacheData_UnrecognizedValidationVersion, physicalDevice, loc.dot(Field::pInitialData),
                           "has an invalid validationVersion %s (%u) that does not match the validation version of "
                           "a Vulkan SC pipeline cache (VK_PIPELINE_CACHE_VALIDATION_VERSION_SAFETY_CRITICAL_ONE).",
                           string_VkPipelineCacheValidationVersion(data.header->validationVersion), data.header->validationVersion);
        header_valid = false;
    }

    const uint32_t sc_index_entry_size = sizeof(VkPipelineCacheSafetyCriticalIndexEntry);
    assert(sc_index_entry_size == 56);
    if (data.header->pipelineIndexStride < sc_index_entry_size) {
        skip |= LogWarning(kVUID_SC_PipelineCacheData_PipelineIndexStrideTooSmall, physicalDevice, loc.dot(Field::pInitialData),
                           "has an invalid pipelineIndexStride (%u) which needs to be at least %u.",
                           data.header->pipelineIndexStride, sc_index_entry_size);
        header_valid = false;
    }

    if (data.header->pipelineIndexOffset + data.header->pipelineIndexCount * data.header->pipelineIndexStride >
        create_info.initialDataSize) {
        skip |= LogWarning(kVUID_SC_PipelineCacheData_PipelineIndexOutOfBounds, physicalDevice, loc.dot(Field::initialDataSize),
                           "is too small (%zu bytes) to fit pipelineIndexCount (%u) pipelines stored with "
                           "pipelineIndexStride (%u) starting from pipelineIndexOffset (%" PRIu64 ").",
                           create_info.initialDataSize, data.header->pipelineIndexCount, data.header->pipelineIndexStride,
                           data.header->pipelineIndexOffset);
        header_valid = false;
    }

    if (!header_valid) {
        // Should not validate any other data if the header is invalid.
        return skip;
    }

    vvl::unordered_set<vvl::sc::PipelineCacheData::Entry::ID, vvl::sc::PipelineCacheData::Entry::ID::hash> pipeline_ids{};
    for (uint32_t pipeline_index = 0; pipeline_index < data.PipelineIndexCount(); ++pipeline_index) {
        bool stage_info_valid = true;
        auto entry = data.PipelineIndexEntry(pipeline_index);
        if (!entry) continue;

        auto id = entry.PipelineID();
        if (!pipeline_ids.emplace(id).second) {
            skip |= LogError("VUID-VkPipelineCacheCreateInfo-pInitialData-05139", physicalDevice, loc.dot(Field::pInitialData),
                             "contains duplicate pipeline identifier {%s}.", id.toString().c_str());
        }

        if (entry->jsonSize == 0 && entry->jsonOffset != 0) {
            skip |=
                LogWarning(kVUID_SC_PipelineCacheData_JsonOffsetAndSizeInconsistent, physicalDevice, loc.dot(Field::pInitialData),
                           "contains pipeline identifier {%s} for which jsonSize is zero "
                           "but jsonOffset is not zero (%" PRIu64 ").",
                           id.toString().c_str(), entry->jsonOffset);
        }

        if (entry->jsonSize != 0 && entry->jsonOffset + entry->jsonSize > create_info.initialDataSize) {
            skip |= LogWarning(kVUID_SC_PipelineCacheData_JsonDataOutOfBounds, physicalDevice, loc.dot(Field::initialDataSize),
                               "is too small (%zu bytes) to fit the JSON data for pipeline identifier {%s} stored with "
                               "jsonSize (%" PRIu64 ") starting from jsonOffset (%" PRIu64 ").",
                               create_info.initialDataSize, id.toString().c_str(), entry->jsonSize, entry->jsonOffset);
        }

        if (entry->jsonSize == 0 && entry->stageIndexCount != 0) {
            skip |= LogWarning(kVUID_SC_PipelineCacheData_JsonSizeStageIndexCountInconsistent, physicalDevice,
                               loc.dot(Field::pInitialData),
                               "contains pipeline identifier {%s} for which jsonSize is zero "
                               "but stageIndexCount is not zero (%u).",
                               id.toString().c_str(), entry->stageIndexCount);
        }

        if (entry->stageIndexCount == 0 && entry->stageIndexOffset != 0) {
            skip |= LogWarning(kVUID_SC_PipelineCacheData_StageIndexOffsetStrideCountInconsistent, physicalDevice,
                               loc.dot(Field::pInitialData),
                               "contains pipeline identifier {%s} for which stageIndexCount is zero "
                               "but stageIndexOffset is not zero (%" PRIu64 ").",
                               id.toString().c_str(), entry->stageIndexOffset);
        }

        if (entry->stageIndexCount == 0 && entry->stageIndexStride != 0) {
            skip |= LogWarning(kVUID_SC_PipelineCacheData_StageIndexOffsetStrideCountInconsistent, physicalDevice,
                               loc.dot(Field::pInitialData),
                               "contains pipeline identifier {%s} for which stageIndexCount is zero "
                               "but stageIndexStride is not zero (%u).",
                               id.toString().c_str(), entry->stageIndexStride);
        }

        const uint32_t sc_stage_val_entry_size = sizeof(VkPipelineCacheStageValidationIndexEntry);
        assert(sc_stage_val_entry_size == 16);
        if (entry->stageIndexCount != 0 && entry->stageIndexStride < sc_stage_val_entry_size) {
            skip |= LogWarning(kVUID_SC_PipelineCacheData_StageIndexStrideTooSmall, physicalDevice, loc.dot(Field::pInitialData),
                               "contains pipeline identifier {%s} for which stageIndexCount is not zero "
                               "but stageIndexStride is too small (%u bytes) for the stage entries to contain a "
                               "VkPipelineCacheStageValidationIndexEntry structure (%u bytes).",
                               id.toString().c_str(), entry->stageIndexStride, sc_stage_val_entry_size);
            stage_info_valid = false;
        }

        if (entry->stageIndexCount != 0 &&
            entry->stageIndexOffset + entry->stageIndexCount * entry->stageIndexStride > create_info.initialDataSize) {
            skip |= LogWarning(kVUID_SC_PipelineCacheData_StageIndexOutOfBounds, physicalDevice, loc.dot(Field::initialDataSize),
                               "is too small (%zu bytes) to fit stageIndexCount (%u) stage validation entries for "
                               "pipeline identifier {%s} stored with stageIndexStride (%u) starting from "
                               "stageIndexOffset (%" PRIu64 ").",
                               create_info.initialDataSize, entry->stageIndexCount, id.toString().c_str(), entry->stageIndexStride,
                               entry->stageIndexOffset);
            stage_info_valid = false;
        }

        if (stage_info_valid) {
            for (uint32_t stage_index = 0; stage_index < entry.StageIndexCount(); ++stage_index) {
                auto stage_info = entry.StageIndexEntry(stage_index);
                if (!stage_info) continue;

                skip |= ValidatePipelineCacheSpirv(physicalDevice, data, pipeline_index, stage_index, loc);
                // SPIR-V validation, if used, will already report errors for the warnings below
                if (skip) continue;

                if (stage_info->codeSize == 0) {
                    skip |= LogWarning(kVUID_SC_PipelineCacheData_CodeSizeZero, physicalDevice, loc.dot(Field::pInitialData),
                                       "contains pipeline identifier {%s} for which codeSize "
                                       "for stage index entry #%u is zero.",
                                       id.toString().c_str(), stage_index);
                }

                if (stage_info->codeSize % 4 != 0) {
                    skip |= LogWarning(kVUID_SC_PipelineCacheData_CodeSizeNotMultipleOfFour, physicalDevice,
                                       loc.dot(Field::pInitialData),
                                       "contains pipeline identifier {%s} for which codeSize (%" PRIu64
                                       ") for stage index entry #%u is not a multiple of 4.",
                                       id.toString().c_str(), stage_info->codeSize, stage_index);
                }

                if (stage_info->codeOffset + stage_info->codeSize > create_info.initialDataSize) {
                    skip |=
                        LogWarning(kVUID_SC_PipelineCacheData_CodeDataOutOfBounds, physicalDevice, loc.dot(Field::initialDataSize),
                                   "is too small (%zu bytes) to fit the SPIR-V module data for "
                                   "stage index entry #%u for pipeline identifier {%s} stored at "
                                   "codeOffset (%" PRIu64 ") with codeSize (%" PRIu64 ").",
                                   create_info.initialDataSize, stage_index, id.toString().c_str(), stage_info->codeOffset,
                                   stage_info->codeSize);
                }
            }
        }
    }

    return skip;
}

bool SCCoreChecks::ValidateSwapchainCreateInfo(VkDevice device, const VkSwapchainCreateInfoKHR& create_info, const Location& loc) const {
    bool skip = false;

    if (create_info.flags & VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR) {
        skip |= LogError("VUID-VkSwapchainCreateInfoKHR-flags-05072", device, loc.dot(Field::flags),
                         "(%s) contains unsupported flag VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR.",
                         string_VkSwapchainCreateFlagsKHR(create_info.flags).c_str());
    }

    if (create_info.oldSwapchain != VK_NULL_HANDLE) {
        skip |= LogError("VUID-VkSwapchainCreateInfoKHR-oldSwapchain-05073", device, loc.dot(Field::oldSwapchain),
                         "is not VK_NULL_HANDLE.");
    }

    return skip;
}

bool SCCoreChecks::ValidateShaderModuleId(const vvl::Pipeline& pipeline, const Location& loc) const {
    bool skip = false;

    for (const auto& stage_ci : pipeline.shader_stages_ci) {
        if (stage_ci.module != VK_NULL_HANDLE) {
            skip |= LogError("VUID-VkPipelineShaderStageCreateInfo-module-05026", device, loc,
                             "module in VkPipelineShaderStageCreateInfo (stage %s) is not VK_NULL_HANDLE.",
                             string_VkShaderStageFlagBits(stage_ci.stage));
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                                 VkInstance* pInstance, const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateInstance(pCreateInfo, pAllocator, pInstance, error_obj);

    if (pCreateInfo && pCreateInfo->pApplicationInfo) {
        uint32_t api_version = pCreateInfo->pApplicationInfo->apiVersion;

        if (api_version != 0 && VK_API_VERSION_VARIANT(api_version) == VKSC_API_VARIANT && api_version < VKSC_API_VERSION_1_0) {
            skip |= LogError("VUID-VkApplicationInfo-apiVersion-05021", instance,
                             error_obj.location.dot(Field::pCreateInfo).dot(Field::pApplicationInfo).dot(Field::apiVersion),
                             "(0x%08x) is invalid.", api_version);
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator, VkDevice* pDevice,
                                               const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice, error_obj);
    auto pd_state = Get<vvl::PhysicalDevice>(physicalDevice);

    if (pd_state) {
        const Location create_info_loc = error_obj.location.dot(Field::pCreateInfo);
        const char* missing_pnext_msg = "does not contain a %s structure.";

        auto sc_10_props = vku::InitStruct<VkPhysicalDeviceVulkanSC10Properties>();
        auto pd_props = vku::InitStruct<VkPhysicalDeviceProperties2>(&sc_10_props);
        const auto& device_limits = pd_props.properties.limits;
        DispatchGetPhysicalDeviceProperties2(physicalDevice, &pd_props);

        uint32_t max_mip_levels =
            1u + static_cast<uint32_t>(log2(std::max({device_limits.maxImageDimension1D, device_limits.maxImageDimension2D,
                                                      device_limits.maxImageDimension3D, device_limits.maxImageDimensionCube})));

        const auto* sc_10_features = vku::FindStructInPNextChain<VkPhysicalDeviceVulkanSC10Features>(pCreateInfo->pNext);
        if (sc_10_features == nullptr) {
            skip |= LogWarning(kVUID_SC_CreateDevice_MissingVulkanSC10Features, physicalDevice,
                               create_info_loc.dot(Field::pNext), missing_pnext_msg,
                               "VkPhysicalDeviceVulkanSC10Features");
        }

        const auto* object_reservation_info = vku::FindStructInPNextChain<VkDeviceObjectReservationCreateInfo>(pCreateInfo->pNext);
        if (object_reservation_info == nullptr) {
            skip |= LogWarning(kVUID_SC_CreateDevice_MissingObjectReservationInfo, physicalDevice,
                               create_info_loc.dot(Field::pNext), missing_pnext_msg,
                               "VkDeviceObjectReservationCreateInfo");
        }

        const auto* fault_callback_info = vku::FindStructInPNextChain<VkFaultCallbackInfo>(pCreateInfo->pNext);
        if (fault_callback_info != nullptr && fault_callback_info->faultCount != 0 &&
            fault_callback_info->faultCount != phys_dev_props_sc_10_.maxCallbackFaultCount) {
            skip |= LogError("VUID-VkFaultCallbackInfo-faultCount-05138", device,
                             create_info_loc.pNext(Struct::VkFaultCallbackInfo, Field::faultCount),
                             "(%u) does not equal zero or VkPhysicalDeviceVulkanSC10Properties::maxCallbackFaultCount (%u).",
                             fault_callback_info->faultCount, phys_dev_props_sc_10_.maxCallbackFaultCount);
        }

        uint32_t total_device_memory_request_count = 0;
        uint32_t total_sampler_request_count = 0;

        while (object_reservation_info != nullptr) {
            const Location object_reservation_info_loc = create_info_loc.pNext(Struct::VkDeviceObjectReservationCreateInfo);
            for (uint32_t i = 0; i < object_reservation_info->pipelineCacheCreateInfoCount; ++i) {
                const auto& create_info = object_reservation_info->pPipelineCacheCreateInfos[i];
                const Location cache_create_info_loc = object_reservation_info_loc.dot(Field::pPipelineCacheCreateInfos, i);
                skip |= ValidatePipelineCacheCreateInfo(physicalDevice, cache_create_info_loc, create_info);
                skip |= ValidatePipelineCacheData(physicalDevice, create_info, cache_create_info_loc);
            }

            if (object_reservation_info->maxImageViewArrayLayers > device_limits.maxImageArrayLayers) {
                skip |= LogError("VUID-VkDeviceObjectReservationCreateInfo-maxImageViewArrayLayers-05014", physicalDevice,
                                 object_reservation_info_loc.dot(Field::maxImageViewArrayLayers),
                                 "(%u) exceeds device limit maxImageArrayLayers (%u).",
                                 object_reservation_info->maxImageViewArrayLayers, device_limits.maxImageArrayLayers);
            }

            if (object_reservation_info->maxImageViewMipLevels > max_mip_levels) {
                skip |= LogError("VUID-VkDeviceObjectReservationCreateInfo-maxImageViewMipLevels-05015", physicalDevice,
                                 object_reservation_info_loc.dot(Field::maxImageViewMipLevels),
                                 "(%u) exceeds the maximum number of mipmap levels (%u) in a complete mipmap chain based "
                                 "on the maximum of the device limits maxImageDimension1D (%u), maxImageDimension2D (%u), "
                                 "maxImageDimension3D (%u), and maxImageDimensionCube (%u).",
                                 object_reservation_info->maxImageViewMipLevels, max_mip_levels, device_limits.maxImageDimension1D,
                                 device_limits.maxImageDimension2D, device_limits.maxImageDimension3D,
                                 device_limits.maxImageDimensionCube);
            }

            if (object_reservation_info->maxLayeredImageViewMipLevels > max_mip_levels) {
                skip |= LogError("VUID-VkDeviceObjectReservationCreateInfo-maxLayeredImageViewMipLevels-05016", physicalDevice,
                                 object_reservation_info_loc.dot(Field::maxLayeredImageViewMipLevels),
                                 "(%u) exceeds the maximum number of mipmap levels (%u) in a complete mipmap chain based "
                                 "on the maximum of the device limits maxImageDimension1D (%u), maxImageDimension2D (%u), "
                                 "maxImageDimension3D (%u), and maxImageDimensionCube (%u).",
                                 object_reservation_info->maxLayeredImageViewMipLevels, max_mip_levels,
                                 device_limits.maxImageDimension1D, device_limits.maxImageDimension2D,
                                 device_limits.maxImageDimension3D, device_limits.maxImageDimensionCube);
            }

            uint32_t max_subpass_descriptions =
                object_reservation_info->renderPassRequestCount * sc_10_props.maxRenderPassSubpasses;
            if (object_reservation_info->subpassDescriptionRequestCount > max_subpass_descriptions) {
                skip |= LogError("VUID-VkDeviceObjectReservationCreateInfo-subpassDescriptionRequestCount-05017", physicalDevice,
                                 object_reservation_info_loc.dot(Field::subpassDescriptionRequestCount),
                                 "(%u) exceeds the maximum number of subpass descriptions (%u) that can be used, determined by "
                                 "multiplying VkDeviceObjectReservationCreateInfo::renderPassRequestCount (%u) by "
                                 "VkPhysicalDeviceVulkanSC10Properties::maxRenderPassSubpasses (%u).",
                                 object_reservation_info->subpassDescriptionRequestCount, max_subpass_descriptions,
                                 object_reservation_info->renderPassRequestCount, sc_10_props.maxRenderPassSubpasses);
            }

            uint32_t max_attachment_descriptions =
                object_reservation_info->renderPassRequestCount * sc_10_props.maxFramebufferAttachments;
            if (object_reservation_info->attachmentDescriptionRequestCount > max_attachment_descriptions) {
                skip |= LogError("VUID-VkDeviceObjectReservationCreateInfo-attachmentDescriptionRequestCount-05018", physicalDevice,
                                 object_reservation_info_loc.dot(Field::attachmentDescriptionRequestCount),
                                 "(%u) exceeds the maximum number of subpass descriptions (%u) that can be used, determined by "
                                 "multiplying VkDeviceObjectReservationCreateInfo::renderPassRequestCount (%u) by "
                                 "VkPhysicalDeviceVulkanSC10Properties::maxFramebufferAttachments (%u).",
                                 object_reservation_info->attachmentDescriptionRequestCount, max_attachment_descriptions,
                                 object_reservation_info->renderPassRequestCount, sc_10_props.maxFramebufferAttachments);
            }

            total_device_memory_request_count += object_reservation_info->deviceMemoryRequestCount;
            total_sampler_request_count += object_reservation_info->samplerRequestCount;
            object_reservation_info =
                vku::FindStructInPNextChain<VkDeviceObjectReservationCreateInfo>(object_reservation_info->pNext);
        }

        if (total_device_memory_request_count > device_limits.maxMemoryAllocationCount) {
            skip |= LogError("VUID-vkCreateDevice-deviceMemoryRequestCount-05095", physicalDevice, error_obj.location,
                             "the sum of deviceMemoryRequestCount over all "
                             "VkDeviceObjectReservationCreateInfo structures (%u) exceed the "
                             "device limit maxMemoryAllocationCount (%u).",
                             total_device_memory_request_count, device_limits.maxMemoryAllocationCount);
        }

        if (total_sampler_request_count > device_limits.maxSamplerAllocationCount) {
            skip |= LogError("VUID-vkCreateDevice-samplerRequestCount-05096", physicalDevice, error_obj.location,
                             "the sum of samplerRequestCount over all "
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
                                                    const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool,
                                                    const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateCommandPool-device-05068", "command pools",
                                       Count<vvl::CommandPool>(), "commandPoolRequestCount",
                                       sc_object_limits_.commandPoolRequestCount, 1);

    const Location create_info_loc = error_obj.location.dot(Field::pCreateInfo);
    const auto* mem_reservation_info = vku::FindStructInPNextChain<VkCommandPoolMemoryReservationCreateInfo>(pCreateInfo->pNext);
    if (mem_reservation_info) {
        const Location mem_reservation_info_loc = create_info_loc.pNext(Struct::VkCommandPoolMemoryReservationCreateInfo);
        if (mem_reservation_info->commandPoolReservedSize == 0) {
            skip |= LogError("VUID-VkCommandPoolMemoryReservationCreateInfo-commandPoolReservedSize-05003", device,
                             mem_reservation_info_loc.dot(Field::commandPoolReservedSize), "is zero.");
        }
        if (mem_reservation_info->commandPoolMaxCommandBuffers == 0) {
            skip |=
                LogError("VUID-VkCommandPoolMemoryReservationCreateInfo-commandPoolMaxCommandBuffers-05004", device,
                         mem_reservation_info_loc.dot(Field::commandPoolMaxCommandBuffers), "is zero.");
        } else if (mem_reservation_info->commandPoolMaxCommandBuffers > phys_dev_props_sc_10_.maxCommandPoolCommandBuffers) {
            skip |=
                LogError("VUID-VkCommandPoolMemoryReservationCreateInfo-commandPoolMaxCommandBuffers-05090", device,
                         mem_reservation_info_loc.dot(Field::commandPoolMaxCommandBuffers),
                         "(%u) is greater than VkPhysicalDeviceVulkanSC10Properties::maxCommandPoolCommandBuffers (%u).",
                         mem_reservation_info->commandPoolMaxCommandBuffers, phys_dev_props_sc_10_.maxCommandPoolCommandBuffers);
        }
        uint32_t reserved_command_buffers = sc_reserved_objects_.command_buffers.load();
        if (reserved_command_buffers + mem_reservation_info->commandPoolMaxCommandBuffers >
            sc_object_limits_.commandBufferRequestCount) {
            skip |= LogError("VUID-VkCommandPoolMemoryReservationCreateInfo-commandPoolMaxCommandBuffers-05074", device,
                             mem_reservation_info_loc.dot(Field::commandPoolMaxCommandBuffers),
                             "(%u) plus the number of already reserved command buffers (%u) is greater than the total "
                             "number of command buffers requested (%u).",
                             mem_reservation_info->commandPoolMaxCommandBuffers, reserved_command_buffers,
                             sc_object_limits_.commandBufferRequestCount);
        }
    } else {
        skip |=
            LogError("VUID-VkCommandPoolCreateInfo-pNext-05002", device,
                     create_info_loc.dot(Field::pNext),
                     "chain does not contain a VkCommandPoolMemoryReservationCreateInfo structure.");
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            VkDescriptorSetLayout* pSetLayout, const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateDescriptorSetLayout-device-05068",
                                       "descriptor set layouts", Count<vvl::DescriptorSetLayout>(), "descriptorSetLayout",
                                       sc_object_limits_.descriptorSetLayoutRequestCount, 1);

    if (pCreateInfo) {
        const Location create_info_loc = error_obj.location.dot(Field::pCreateInfo);

        if (pCreateInfo->bindingCount > phys_dev_props_sc_10_.maxDescriptorSetLayoutBindings) {
            skip |= LogError("VUID-VkDescriptorSetLayoutCreateInfo-bindingCount-05011", device,
                             create_info_loc.dot(Field::bindCount), "(%u) exceeds the device limit "
                             "VkPhysicalDeviceVulkanSC10Properties::maxDescriptorSetLayoutBindings (%u).",
                             pCreateInfo->bindingCount, phys_dev_props_sc_10_.maxDescriptorSetLayoutBindings);
        }

        skip |= ValidateCombinedRequestCount(
            device, error_obj.location, "VUID-vkCreateDescriptorSetLayout-layoutbindings-device-05089",
            "VkDescriptorSetLayout", "descriptor set layout bindings", sc_reserved_objects_.descriptor_set_layout_bindings.load(),
            "descriptorSetLayoutBinding", sc_object_limits_.descriptorSetLayoutBindingRequestCount, "pCreateInfo->bindingCount",
            pCreateInfo->bindingCount);

        uint32_t requested_immutable_samplers = 0;
        for (uint32_t i = 0; i < pCreateInfo->bindingCount; ++i) {
            const auto& binding = pCreateInfo->pBindings[i];
            if (binding.binding >= sc_object_limits_.descriptorSetLayoutBindingLimit) {
                skip |= LogError("VUID-VkDescriptorSetLayoutBinding-binding-05012", device,
                                 create_info_loc.dot(Field::pBindings, i).dot(Field::binding),
                                 "(%u) exceeds the limit requested in "
                                 "VkDeviceObjectReservationCreateInfo::descriptorSetLayoutBindingLimit (%u).",
                                 binding.binding, sc_object_limits_.descriptorSetLayoutBindingLimit);
            }

            if ((binding.descriptorType == VK_DESCRIPTOR_TYPE_SAMPLER ||
                 binding.descriptorType == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) &&
                binding.pImmutableSamplers != nullptr) {
                requested_immutable_samplers += binding.descriptorCount;
            }
        }

        if (requested_immutable_samplers > sc_object_limits_.maxImmutableSamplersPerDescriptorSetLayout) {
            skip |= LogError("VUID-VkDescriptorSetLayoutCreateInfo-descriptorCount-05071", device, error_obj.location,
                             "the total immutable samplers (%u) across the specified bindings exceeds the limit requested "
                             "in VkDeviceObjectReservationCreateInfo::maxImmutableSamplersPerDescriptorSetLayout (%u).",
                             requested_immutable_samplers, sc_object_limits_.maxImmutableSamplersPerDescriptorSetLayout);
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout,
                                                       const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout, error_obj);

    skip |=
        ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreatePipelineLayout-device-05068", "pipeline layouts",
                                   Count<vvl::PipelineLayout>(), "pipelineLayout", sc_object_limits_.pipelineLayoutRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool,
                                                       const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool, error_obj);

    skip |=
        ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateDescriptorPool-device-05068", "descriptor pool",
                                   Count<vvl::DescriptorPool>(), "descriptorPool", sc_object_limits_.descriptorPoolRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                                         VkCommandBuffer* pCommandBuffers, const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers, error_obj);

    auto cp_state = Get<vvl::sc::CommandPool>(pAllocateInfo->commandPool);
    if (!cp_state) return false;

    if (cp_state->commandBuffers.size() + pAllocateInfo->commandBufferCount > cp_state->max_command_buffers) {
        skip |= LogError("VUID-VkCommandBufferAllocateInfo-commandPool-05006", device,
                         error_obj.location.dot(Field::pAllocateInfo).dot(Field::commandBufferCount),
                         "(%u) plus the number of command buffers currently allocated from %s (%zu) is greater than the "
                         "VkCommandPoolMemoryReservationCreateInfo::commandPoolMaxCommandBuffers (%u) "
                         "the command pool was created with.",
                         pAllocateInfo->commandBufferCount, report_data->FormatHandle(pAllocateInfo->commandPool).c_str(),
                         cp_state->commandBuffers.size(), cp_state->max_command_buffers);
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                                         VkDescriptorSet* pDescriptorSets, const ErrorObject& error_obj,
                                                         void* ads_state_data) const {
    bool skip = BASE::PreCallValidateAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets, error_obj, ads_state_data);

    if (pAllocateInfo) {
        skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkAllocateDescriptorSets-device-05068",
                                           "descriptor sets", Count<vvl::DescriptorSet>(), "descriptorSet",
                                           sc_object_limits_.descriptorSetRequestCount, "pAllocateInfo->descriptorSetCount",
                                           pAllocateInfo->descriptorSetCount);
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory,
                                                 const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateAllocateMemory(device, pAllocateInfo, pAllocator, pMemory, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkAllocateMemory-device-05068", "device memory objects",
                                       Count<vvl::DeviceMemory>(), "deviceMemory", sc_object_limits_.deviceMemoryRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t count,
                                                         const VkComputePipelineCreateInfo* pCreateInfos,
                                                         const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                         const ErrorObject& error_obj, void* ccpl_state_data) const {
    bool skip = BASE::PreCallValidateCreateComputePipelines(device, pipelineCache, count, pCreateInfos, pAllocator, pPipelines,
                                                            error_obj, ccpl_state_data);

    auto pipeline_cache_state = Get<vvl::sc::PipelineCache>(pipelineCache);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateComputePipelines-device-05068",
                                       "compute pipelines", sc_reserved_objects_.compute_pipelines.load(), "computePipeline",
                                       sc_object_limits_.computePipelineRequestCount, "createInfoCount", count);

    skip |= ValidatePipelinePoolMemory(device, error_obj.location, count, pCreateInfos);

    if (pCreateInfos != nullptr) {
        for (uint32_t i = 0; i < count; i++) {
            const Location create_info_loc = error_obj.location.dot(Field::pCreateInfos, i);

            if (pCreateInfos[i].basePipelineHandle != VK_NULL_HANDLE) {
                skip |= LogError("VUID-VkComputePipelineCreateInfo-basePipelineHandle-05024", device,
                                 create_info_loc.dot(Field::basePipelineHandle), "is not VK_NULL_HANDLE.");
            }
            if (pCreateInfos[i].basePipelineIndex != 0) {
                skip |= LogError("VUID-VkComputePipelineCreateInfo-basePipelineIndex-05025", device,
                                 create_info_loc.dot(Field::basePipelineIndex), "(%u) is not zero.",
                                 pCreateInfos[i].basePipelineIndex);
            }

            auto offline_create_info = vku::FindStructInPNextChain<VkPipelineOfflineCreateInfo>(pCreateInfos[i].pNext);
            skip |= ValidatePipelineStageInfo(0, pCreateInfos[i].stage, pipeline_cache_state.get(), offline_create_info,
                                              error_obj.location.dot(Field::pCreateInfos, i).dot(Field::stage));
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t count,
                                                          const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                          const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                          const ErrorObject& error_obj, void* cgpl_state_data) const {
    bool skip = BASE::PreCallValidateCreateGraphicsPipelines(device, pipelineCache, count, pCreateInfos, pAllocator, pPipelines,
                                                             error_obj, cgpl_state_data);

    auto pipeline_cache_state = Get<vvl::sc::PipelineCache>(pipelineCache);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateGraphicsPipelines-device-05068",
                                       "graphics pipelines", sc_reserved_objects_.graphics_pipelines.load(), "graphicsPipeline",
                                       sc_object_limits_.graphicsPipelineRequestCount, "createInfoCount", count);

    skip |= ValidatePipelinePoolMemory(device, error_obj.location, count, pCreateInfos);

    if (pCreateInfos != nullptr) {
        for (uint32_t i = 0; i < count; i++) {
            const Location create_info_loc = error_obj.location.dot(Field::pCreateInfos, i);

            if (pCreateInfos[i].basePipelineHandle != VK_NULL_HANDLE) {
                skip |= LogError("VUID-VkGraphicsPipelineCreateInfo-basePipelineHandle-05024", device,
                                 create_info_loc.dot(Field::basePipelineHandle), "is not VK_NULL_HANDLE.");
            }
            if (pCreateInfos[i].basePipelineIndex != 0) {
                skip |= LogError("VUID-VkGraphicsPipelineCreateInfo-basePipelineIndex-05025", device,
                                 create_info_loc.dot(Field::basePipelineIndex), "(%u) is not zero.",
                                 pCreateInfos[i].basePipelineIndex);
            }

            auto offline_create_info = vku::FindStructInPNextChain<VkPipelineOfflineCreateInfo>(pCreateInfos[i].pNext);
            for (uint32_t stage_index = 0; stage_index < pCreateInfos[i].stageCount; ++stage_index) {
                skip |= ValidatePipelineStageInfo(stage_index, pCreateInfos[i].pStages[stage_index], pipeline_cache_state.get(),
                                                  offline_create_info,
                                                  error_obj.location.dot(Field::pCreateInfos, i).dot(Field::pStages, stage_index));
            }
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache,
                                                      const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache, error_obj);

    skip |=
        ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreatePipelineCache-device-05068", "pipeline caches",
                                   Count<vvl::PipelineCache>(), "pipelineCache", sc_object_limits_.pipelineCacheRequestCount, 1);

    if (pCreateInfo) {
        const Location create_info_loc = error_obj.location.dot(Field::pCreateInfo);

        skip |= ValidatePipelineCacheCreateInfo(device, create_info_loc, *pCreateInfo);

        // By default we do not re-validate the pipeline cache data as it was already validated at device creation time,
        // but we do so if the passed pipeline cache create information is one that was not specified at that time.
        bool validate_pipeline_cache_data = false;
        auto it = sc_pipeline_cache_map_.find(pCreateInfo->pInitialData);
        if (it == sc_pipeline_cache_map_.end() || it->second->create_info.flags != pCreateInfo->flags ||
            it->second->create_info.initialDataSize != pCreateInfo->initialDataSize) {
            skip |= LogError("VUID-vkCreatePipelineCache-pCreateInfo-05045", device, create_info_loc,
                             "does not match any of the VkPipelineCacheCreateInfo structures specified in "
                             "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos at device creation time.");
            validate_pipeline_cache_data = true;
        } else if (memcmp(it->second->original_data.data(), pCreateInfo->pInitialData, pCreateInfo->initialDataSize) != 0) {
            skip |= LogError("VUID-vkCreatePipelineCache-pCreateInfo-05045", device, create_info_loc,
                             "the data pointed to by pCreateInfo->pInitialData does not match the data specified in "
                             "VkDeviceObjectReservationCreateInfo::pPipelineCacheCreateInfos at device creation time.");
            validate_pipeline_cache_data = true;
        }
        if (validate_pipeline_cache_data) {
            skip |= ValidatePipelineCacheData(physical_device, *pCreateInfo, error_obj.location.dot(Field::pCreateInfo));
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool,
                                                  const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateQueryPool-device-05068", "query pools",
                                       Count<vvl::QueryPool>(), "queryPool", sc_object_limits_.queryPoolRequestCount, 1);

    if (pCreateInfo) {
        const Location create_info_loc = error_obj.location.dot(Field::pCreateInfo);

        if (pCreateInfo->queryType == VK_QUERY_TYPE_OCCLUSION &&
            pCreateInfo->queryCount > sc_object_limits_.maxOcclusionQueriesPerPool) {
            skip |= LogError("VUID-VkQueryPoolCreateInfo-queryType-05046", device,
                             create_info_loc.dot(Field::queryCount),
                             "(%u) exceeds the limit requested in "
                             "VkDeviceObjectReservationCreateInfo::maxOcclusionQueriesPerPool (%u).",
                             pCreateInfo->queryCount, sc_object_limits_.maxOcclusionQueriesPerPool);
        }

        if (pCreateInfo->queryType == VK_QUERY_TYPE_PIPELINE_STATISTICS &&
            pCreateInfo->queryCount > sc_object_limits_.maxPipelineStatisticsQueriesPerPool) {
            skip |= LogError("VUID-VkQueryPoolCreateInfo-queryType-05047", device,
                             create_info_loc.dot(Field::queryCount),
                             "(%u) exceeds the limit requested in "
                             "VkDeviceObjectReservationCreateInfo::maxPipelineStatisticsQueriesPerPool (%u).",
                             pCreateInfo->queryCount, sc_object_limits_.maxPipelineStatisticsQueriesPerPool);
        }

        if (pCreateInfo->queryType == VK_QUERY_TYPE_TIMESTAMP &&
            pCreateInfo->queryCount > sc_object_limits_.maxTimestampQueriesPerPool) {
            skip |= LogError("VUID-VkQueryPoolCreateInfo-queryType-05048", device,
                             create_info_loc.dot(Field::queryCount),
                             "(%u) exceeds the limit requested in "
                             "VkDeviceObjectReservationCreateInfo::maxTimestampQueriesPerPool (%u).",
                             pCreateInfo->queryCount, sc_object_limits_.maxTimestampQueriesPerPool);
        }

        if (pCreateInfo->queryType == VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR &&
            pCreateInfo->queryCount > sc_perf_query_limits_.maxPerformanceQueriesPerPool) {
            skip |= LogError("VUID-VkQueryPoolCreateInfo-queryType-05049", device,
                             create_info_loc.dot(Field::queryCount),
                             "(%u) exceeds the limit requested in "
                             "VkPerformanceQueryReservationInfoKHR::maxPerformanceQueriesPerPool (%u).",
                             pCreateInfo->queryCount, sc_perf_query_limits_.maxPerformanceQueriesPerPool);
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                                   const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateRenderPass-device-05068", "render passes",
                                       Count<vvl::RenderPass>(), "renderPass", sc_object_limits_.renderPassRequestCount, 1);

    if (pCreateInfo) {
        const Location create_info_loc = error_obj.location.dot(Field::pCreateInfo);

        skip |= ValidateCombinedRequestCount(device, error_obj.location, "VUID-vkCreateRenderPass-subpasses-device-05089",
                                             "VkRenderPass", "subpasses", sc_reserved_objects_.subpass_descriptions.load(),
                                             "subpassDescription", sc_object_limits_.subpassDescriptionRequestCount,
                                             "pCreateInfo->subpassCount", pCreateInfo->subpassCount);
        skip |= ValidateCombinedRequestCount(device, error_obj.location, "VUID-vkCreateRenderPass-attachments-device-05089",
                                             "VkRenderPass", "attachments", sc_reserved_objects_.attachment_descriptions.load(),
                                             "attachmentDescription", sc_object_limits_.attachmentDescriptionRequestCount,
                                             "pCreateInfo->attachmentCount", pCreateInfo->attachmentCount);

        if (pCreateInfo->subpassCount > phys_dev_props_sc_10_.maxRenderPassSubpasses) {
            skip |= LogError("VUID-VkRenderPassCreateInfo-subpassCount-05050", device,
                             create_info_loc.dot(Field::subpassCount),
                             "(%u) exceeds the device limit VkPhysicalDeviceVulkanSC10Properties::maxRenderPassSubpasses (%u).",
                             pCreateInfo->subpassCount, phys_dev_props_sc_10_.maxRenderPassSubpasses);
        }
        if (pCreateInfo->dependencyCount > phys_dev_props_sc_10_.maxRenderPassDependencies) {
            skip |= LogError("VUID-VkRenderPassCreateInfo-dependencyCount-05051", device,
                             create_info_loc.dot(Field::dependencyCount),
                             "(%u) exceeds the device limit VkPhysicalDeviceVulkanSC10Properties::maxRenderPassDependencies (%u).",
                             pCreateInfo->dependencyCount, phys_dev_props_sc_10_.maxRenderPassDependencies);
        }
        if (pCreateInfo->attachmentCount > phys_dev_props_sc_10_.maxFramebufferAttachments) {
            skip |= LogError("VUID-VkRenderPassCreateInfo-attachmentCount-05052", device,
                             create_info_loc.dot(Field::attachmentCount),
                             "(%u) exceeds the device limit VkPhysicalDeviceVulkanSC10Properties::maxFramebufferAttachments (%u).",
                             pCreateInfo->attachmentCount, phys_dev_props_sc_10_.maxFramebufferAttachments);
        }
        for (uint32_t subpass_idx = 0; subpass_idx < pCreateInfo->subpassCount; ++subpass_idx) {
            const auto& subpass = pCreateInfo->pSubpasses[subpass_idx];
            const Location subpass_loc = create_info_loc.dot(Field::pSubpasses, subpass_idx);

            if (subpass.inputAttachmentCount > phys_dev_props_sc_10_.maxSubpassInputAttachments) {
                skip |= LogError("VUID-VkSubpassDescription-inputAttachmentCount-05053", device,
                                 subpass_loc.dot(Field::inputAttachmentCount),
                                 "(%u) exceeds the device limit VkPhysicalDeviceVulkanSC10Properties::maxSubpassInputAttachments (%u).",
                                 subpass.inputAttachmentCount, phys_dev_props_sc_10_.maxSubpassInputAttachments);
            }
            if (subpass.preserveAttachmentCount > phys_dev_props_sc_10_.maxSubpassPreserveAttachments) {
                skip |=
                    LogError("VUID-VkSubpassDescription-preserveAttachmentCount-05054", device,
                             subpass_loc.dot(Field::preserveAttachmentCount),
                             "(%u) exceeds the device limit VkPhysicalDeviceVulkanSC10Properties::maxSubpassPreserveAttachments (%u).",
                             subpass.preserveAttachmentCount, phys_dev_props_sc_10_.maxSubpassPreserveAttachments);
            }
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                                    const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateRenderPass2-device-05068", "render passes",
                                       Count<vvl::RenderPass>(), "renderPass", sc_object_limits_.renderPassRequestCount, 1);

    if (pCreateInfo) {
        const Location create_info_loc = error_obj.location.dot(Field::pCreateInfo);

        skip |= ValidateCombinedRequestCount(device, error_obj.location, "VUID-vkCreateRenderPass2-subpasses-device-05089",
                                             "VkRenderPass", "subpasses", sc_reserved_objects_.subpass_descriptions.load(),
                                             "subpassDescription", sc_object_limits_.subpassDescriptionRequestCount,
                                             "pCreateInfo->subpassCount", pCreateInfo->subpassCount);
        skip |= ValidateCombinedRequestCount(device, error_obj.location, "VUID-vkCreateRenderPass2-attachments-device-05089",
                                             "VkRenderPass", "attachments", sc_reserved_objects_.attachment_descriptions.load(),
                                             "attachmentDescription", sc_object_limits_.attachmentDescriptionRequestCount,
                                             "pCreateInfo->attachmentCount", pCreateInfo->attachmentCount);

        if (pCreateInfo->subpassCount > phys_dev_props_sc_10_.maxRenderPassSubpasses) {
            skip |= LogError("VUID-VkRenderPassCreateInfo2-subpassCount-05055", device,
                             create_info_loc.dot(Field::subpassCount),
                             "(%u) exceeds the device limit VkPhysicalDeviceVulkanSC10Properties::maxRenderPassSubpasses (%u).",
                             pCreateInfo->subpassCount, phys_dev_props_sc_10_.maxRenderPassSubpasses);
        }
        if (pCreateInfo->dependencyCount > phys_dev_props_sc_10_.maxRenderPassDependencies) {
            skip |= LogError("VUID-VkRenderPassCreateInfo2-dependencyCount-05056", device,
                             create_info_loc.dot(Field::dependencyCount),
                             "(%u) exceeds the device limit VkPhysicalDeviceVulkanSC10Properties::maxRenderPassDependencies (%u).",
                             pCreateInfo->dependencyCount, phys_dev_props_sc_10_.maxRenderPassDependencies);
        }
        if (pCreateInfo->attachmentCount > phys_dev_props_sc_10_.maxFramebufferAttachments) {
            skip |= LogError("VUID-VkRenderPassCreateInfo2-attachmentCount-05057", device,
                             create_info_loc.dot(Field::attachmentCount),
                             "(%u) exceeds the device limit VkPhysicalDeviceVulkanSC10Properties::maxFramebufferAttachments (%u).",
                             pCreateInfo->attachmentCount, phys_dev_props_sc_10_.maxFramebufferAttachments);
        }
        for (uint32_t subpass_idx = 0; subpass_idx < pCreateInfo->subpassCount; ++subpass_idx) {
            const auto& subpass = pCreateInfo->pSubpasses[subpass_idx];
            const Location subpass_loc = create_info_loc.dot(Field::pSubpasses, subpass_idx);

            if (subpass.inputAttachmentCount > phys_dev_props_sc_10_.maxSubpassInputAttachments) {
                skip |= LogError("VUID-VkSubpassDescription2-inputAttachmentCount-05058", device,
                                 subpass_loc.dot(Field::inputAttachmentCount),
                                 "(%u) exceeds the device limit VkPhysicalDeviceVulkanSC10Properties::maxSubpassInputAttachments (%u).",
                                 subpass.inputAttachmentCount, phys_dev_props_sc_10_.maxSubpassInputAttachments);
            }
            if (subpass.preserveAttachmentCount > phys_dev_props_sc_10_.maxSubpassPreserveAttachments) {
                skip |=
                    LogError("VUID-VkSubpassDescription2-preserveAttachmentCount-05059", device,
                             subpass_loc.dot(Field::preserveAttachmentCount),
                             "(%u) exceeds the device limit VkPhysicalDeviceVulkanSC10Properties::maxSubpassPreserveAttachments (%u).",
                             subpass.preserveAttachmentCount, phys_dev_props_sc_10_.maxSubpassPreserveAttachments);
            }
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer,
                                                    const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateFramebuffer-device-05068", "framebuffers",
                                       Count<vvl::Framebuffer>(), "framebuffer", sc_object_limits_.framebufferRequestCount, 1);

    if (pCreateInfo) {
        const Location create_info_loc = error_obj.location.dot(Field::pCreateInfo);

        if (pCreateInfo->attachmentCount > phys_dev_props_sc_10_.maxFramebufferAttachments) {
            skip |= LogError("VUID-VkFramebufferCreateInfo-attachmentCount-05060", device,
                             create_info_loc.dot(Field::attachmentCount),
                             "(%u) exceeds the device limit VkPhysicalDeviceVulkanSC10Properties::maxFramebufferAttachments (%u).",
                             pCreateInfo->attachmentCount, phys_dev_props_sc_10_.maxFramebufferAttachments);
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer,
                                               const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateBuffer(device, pCreateInfo, pAllocator, pBuffer, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateBuffer-device-05068", "buffers",
                                       Count<vvl::Buffer>(), "buffer", sc_object_limits_.bufferRequestCount, 1);

    if (pCreateInfo) {
        const Location create_info_loc = error_obj.location.dot(Field::pCreateInfo);

        VkBufferCreateFlags unsupported_flags =
            pCreateInfo->flags &
            (VK_BUFFER_CREATE_SPARSE_BINDING_BIT | VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT | VK_BUFFER_CREATE_SPARSE_ALIASED_BIT);
        if (unsupported_flags != 0) {
            skip |= LogError("VUID-VkBufferCreateInfo-flags-05061", device,
                             create_info_loc.dot(Field::flags), "contains unsupported flag(s) %s.",
                             string_VkBufferCreateFlags(unsupported_flags).c_str());
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkBufferView* pView,
                                                   const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateBufferView(device, pCreateInfo, pAllocator, pView, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateBufferView-device-05068", "buffer views",
                                       Count<vvl::BufferView>(), "bufferView", sc_object_limits_.bufferViewRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator, VkImage* pImage,
                                              const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateImage(device, pCreateInfo, pAllocator, pImage, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateImage-device-05068", "images", Count<vvl::Image>(),
                                       "image", sc_object_limits_.imageRequestCount, 1);

    if (pCreateInfo) {
        const Location create_info_loc = error_obj.location.dot(Field::pCreateInfo);

        VkImageCreateFlags unsupported_flags =
            pCreateInfo->flags & (VK_IMAGE_CREATE_SPARSE_BINDING_BIT | VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT |
                                  VK_IMAGE_CREATE_SPARSE_ALIASED_BIT | VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT);
        if (unsupported_flags != 0) {
            skip |= LogError("VUID-VkImageCreateInfo-flags-05062", device,
                             create_info_loc.dot(Field::flags), "contains unsupported flag(s) %s.",
                             string_VkImageCreateFlags(unsupported_flags).c_str());
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkImageView* pView,
                                                  const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateImageView(device, pCreateInfo, pAllocator, pView, error_obj);
    auto image_state = Get<vvl::Image>(pCreateInfo->image);
    if (!image_state) {
        return skip;
    }

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateImageView-device-05068", "image views",
                                       Count<vvl::ImageView>(), "imageView", sc_object_limits_.imageViewRequestCount, 1);

    if (pCreateInfo) {
        const uint32_t effective_mip_levels = ResolveRemainingLevels(image_state->createInfo, pCreateInfo->subresourceRange);
        const uint32_t effective_array_layers = ResolveRemainingLayers(image_state->createInfo, pCreateInfo->subresourceRange);

        if (effective_mip_levels > sc_object_limits_.maxImageViewMipLevels) {
            const char* vuid = pCreateInfo->subresourceRange.levelCount == VK_REMAINING_MIP_LEVELS
                                   ? "VUID-VkImageViewCreateInfo-subresourceRange-05200"
                                   : "VUID-VkImageViewCreateInfo-subresourceRange-05064";
            skip |= LogError(vuid, device, error_obj.location,
                             "the requested mip level count (%u) exceeds the limit requested in "
                             "VkDeviceObjectReservationCreateInfo::maxImageViewMipLevels (%u).",
                             effective_mip_levels, sc_object_limits_.maxImageViewMipLevels);
        }

        if (effective_array_layers > sc_object_limits_.maxImageViewArrayLayers) {
            const char* vuid = pCreateInfo->subresourceRange.layerCount == VK_REMAINING_ARRAY_LAYERS
                                   ? "VUID-VkImageViewCreateInfo-subresourceRange-05201"
                                   : "VUID-VkImageViewCreateInfo-subresourceRange-05065";
            skip |= LogError(vuid, device, error_obj.location,
                             "the requested array layer count (%u) exceeds the limit requested in "
                             "VkDeviceObjectReservationCreateInfo::maxImageViewArrayLayers (%u).",
                             effective_array_layers, sc_object_limits_.maxImageViewArrayLayers);
        }

        if (effective_array_layers > 1) {
            uint32_t reserved_layered_image_views = sc_reserved_objects_.layered_image_views.load();
            if (reserved_layered_image_views >= sc_object_limits_.layeredImageViewRequestCount) {
                skip |= LogError("VUID-vkCreateImageView-subresourceRange-05063", device, error_obj.location,
                                 "the number of image views with more than one array layer currently allocated from the "
                                 "device (%u) plus 1 is greater than the total number of layered image views requested via "
                                 "VkDeviceObjectReservationCreateInfo::layeredImageViewRequestCount (%u).",
                                 reserved_layered_image_views, sc_object_limits_.layeredImageViewRequestCount);
            }

            if (effective_mip_levels > sc_object_limits_.maxLayeredImageViewMipLevels) {
                const char* vuid = pCreateInfo->subresourceRange.levelCount == VK_REMAINING_MIP_LEVELS
                                       ? "VUID-VkImageViewCreateInfo-subresourceRange-05202"
                                       : "VUID-VkImageViewCreateInfo-subresourceRange-05066";
                skip |= LogError(vuid, device, error_obj.location,
                                 "the requested mip level count (%u) exceeds the limit requested in "
                                 "VkDeviceObjectReservationCreateInfo::maxLayeredImageViewMipLevels (%u).",
                                 effective_mip_levels, sc_object_limits_.maxLayeredImageViewMipLevels);
            }
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkSampler* pSampler,
                                                const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateSampler(device, pCreateInfo, pAllocator, pSampler, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateSampler-device-05068", "samplers",
                                       Count<vvl::Sampler>(), "sampler", sc_object_limits_.samplerRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateSamplerYcbcrConversion(VkDevice device,
                                                               const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               VkSamplerYcbcrConversion* pYcbcrConversion,
                                                               const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateSamplerYcbcrConversion-device-05068",
                                       "sampler conversions", Count<vvl::SamplerYcbcrConversion>(), "samplerYcbcrConversion",
                                       sc_object_limits_.samplerYcbcrConversionRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator, VkFence* pFence,
                                              const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateFence(device, pCreateInfo, pAllocator, pFence, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateFence-device-05068", "fences", Count<vvl::Fence>(),
                                       "fence", sc_object_limits_.fenceRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore,
                                                  const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateSemaphore-device-05068", "semaphores",
                                       Count<vvl::Semaphore>(), "semaphore", sc_object_limits_.semaphoreRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator, VkEvent* pEvent,
                                              const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateEvent(device, pCreateInfo, pAllocator, pEvent, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateEvent-device-05068", "events", Count<vvl::Event>(),
                                       "event", sc_object_limits_.eventRequestCount, 1);

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain,
                                                     const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateSwapchainKHR-device-05068", "swapchains",
                                       Count<vvl::Swapchain>(), "swapchain", sc_object_limits_.swapchainRequestCount, 1);

    skip |= ValidateSwapchainCreateInfo(device, *pCreateInfo, error_obj.location.dot(Field::pCreateInfo));

    return skip;
}

bool SCCoreChecks::PreCallValidateCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                                            const VkSwapchainCreateInfoKHR* pCreateInfos,
                                                            const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains,
                                                            const ErrorObject& error_obj) const {
    bool skip =
        BASE::PreCallValidateCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains, error_obj);

    skip |= ValidateObjectRequestCount(device, error_obj.location, "VUID-vkCreateSharedSwapchainsKHR-device-05068",
                                       "swapchains", Count<vvl::Swapchain>(), "swapchain", sc_object_limits_.swapchainRequestCount,
                                       "swapchainCount", swapchainCount);

    for (uint32_t i = 0; i < swapchainCount; i++) {
        skip |= ValidateSwapchainCreateInfo(device, pCreateInfos[i], error_obj.location.dot(Field::pCreateInfos, i));
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfoEXT* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           VkPrivateDataSlotEXT* pPrivateDataSlot,
                                                           const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateCreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot, error_obj);

    uint32_t reserved_private_data_slots = sc_reserved_objects_.private_data_slots.load();
    if (reserved_private_data_slots >= sc_private_data_slot_limits_.privateDataSlotRequestCount) {
        skip |= LogError("VUID-vkCreatePrivateDataSlotEXT-device-05000", device, error_obj.location,
                         "the number of private data slots currently allocated from the device (%u) plus one "
                         "is greater than the total number of private data slots requested "
                         "via VkDevicePrivateDataCreateInfoEXT::privateDataSlotRequestCount (%u).",
                         reserved_private_data_slots, sc_private_data_slot_limits_.privateDataSlotRequestCount);
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos,
                                                   const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateBindImageMemory2(device, bindInfoCount, pBindInfos, error_obj);

    for (uint32_t i = 0; i < bindInfoCount; ++i) {
        const Location bind_info_loc = error_obj.location.dot(Field::pBindInfos, i);

        auto device_group_info = vku::FindStructInPNextChain<VkBindImageMemoryDeviceGroupInfo>(pBindInfos[i].pNext);
        const Location device_group_info_loc = bind_info_loc.pNext(Struct::VkBindImageMemoryDeviceGroupInfo);

        if (device_group_info && device_group_info->splitInstanceBindRegionCount != 0) {
            skip |= LogError("VUID-VkBindImageMemoryDeviceGroupInfo-splitInstanceBindRegionCount-05067", device,
                             device_group_info_loc.dot(Field::splitInstanceBindRegionCount),
                             "(%u) is not zero.", device_group_info->splitInstanceBindRegionCount);
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo,
                                                     const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateBeginCommandBuffer(commandBuffer, pBeginInfo, error_obj);

    auto cb_state = GetRead<vvl::CommandBuffer>(commandBuffer);
    if (!cb_state) return false;

    auto cp_state = Get<vvl::sc::CommandPool>(cb_state->command_pool->VkHandle());

    const Location begin_info_loc = error_obj.location.dot(Field::pBeginInfo);

    if (cb_state->state != CbState::New && !phys_dev_props_sc_10_.commandPoolResetCommandBuffer) {
        skip |= LogError("VUID-vkBeginCommandBuffer-commandPoolResetCommandBuffer-05136", commandBuffer, error_obj.location,
                         "call attempts to implicitly reset %s but "
                         "VkPhysicalDeviceVulkanSC10Properties::commandPoolResetCommandBuffer is not supported.",
                         report_data->FormatHandle(commandBuffer).c_str());
    }

    if (cp_state->command_buffers_recording.load() > 0 && !phys_dev_props_sc_10_.commandPoolMultipleCommandBuffersRecording) {
        skip |= LogError("VUID-vkBeginCommandBuffer-commandPoolMultipleCommandBuffersRecording-05007", commandBuffer,
                         error_obj.location,
                         "%s %s was allocated from is already recording another command buffer but "
                         "VkPhysicalDeviceVulkanSC10Properties::commandPoolMultipleCommandBuffersRecording is not supported.",
                         report_data->FormatHandle(cp_state->Handle()).c_str(), report_data->FormatHandle(commandBuffer).c_str());
    }

    if ((pBeginInfo->flags & VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT) && !phys_dev_props_sc_10_.commandBufferSimultaneousUse) {
        skip |= LogError("VUID-vkBeginCommandBuffer-commandBufferSimultaneousUse-05008", commandBuffer,
                         begin_info_loc.dot(Field::flags),
                         "(%s) includes VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT but "
                         "VkPhysicalDeviceVulkanSC10Properties::commandBufferSimultaneousUse is not supported.",
                         string_VkCommandBufferUsageFlags(pBeginInfo->flags).c_str());
    }

    if (pBeginInfo->pInheritanceInfo != nullptr && pBeginInfo->flags & VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT) {
        auto framebuffer = Get<vvl::Framebuffer>(pBeginInfo->pInheritanceInfo->framebuffer);
        if (framebuffer) {
            if (framebuffer->createInfo.renderPass != pBeginInfo->pInheritanceInfo->renderPass) {
                const char* vuid = phys_dev_props_sc_10_.secondaryCommandBufferNullOrImagelessFramebuffer
                                       ? "VUID-VkCommandBufferBeginInfo-flags-05009"
                                       : "VUID-VkCommandBufferBeginInfo-flags-05010";

                if ((framebuffer->createInfo.flags & VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT) != 0 &&
                    !phys_dev_props_sc_10_.secondaryCommandBufferNullOrImagelessFramebuffer) {
                    skip |= LogError("VUID-VkCommandBufferBeginInfo-flags-05010", commandBuffer,
                                     begin_info_loc.dot(Field::flags),
                                     "has VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT set and "
                                     "pBeginInfo->pInheritanceInfo->framebuffer (%s) was created "
                                     "with VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT but "
                                     "VkPhysicalDeviceVulkanSC10Properties::secondaryCommandBufferNullOrImagelessFramebuffer "
                                     "is not supported.",
                                     report_data->FormatHandle(framebuffer->Handle()).c_str());
                } else {
                    auto render_pass = Get<vvl::RenderPass>(pBeginInfo->pInheritanceInfo->renderPass);
                    // renderPass that framebuffer was created with must be compatible with local renderPass
                    skip |= ValidateRenderPassCompatibility(framebuffer->Handle(), *framebuffer->rp_state.get(),
                        cb_state->Handle(), *render_pass.get(),
                        error_obj.location.dot(Field::pBeginInfo).dot(Field::pInheritanceInfo), vuid);
                }
            }
        } else if (!phys_dev_props_sc_10_.secondaryCommandBufferNullOrImagelessFramebuffer) {
            skip |= LogError("VUID-VkCommandBufferBeginInfo-flags-05010", commandBuffer,
                             begin_info_loc.dot(Field::flags),
                             "has VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT set and "
                             "pBeginInfo->pInheritanceInfo->framebuffer is VK_NULL_HANDLE but "
                             "VkPhysicalDeviceVulkanSC10Properties::secondaryCommandBufferNullOrImagelessFramebuffer "
                             "is not supported.");
        }
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags,
                                                     const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateResetCommandBuffer(commandBuffer, flags, error_obj);

    if (!phys_dev_props_sc_10_.commandPoolResetCommandBuffer) {
        skip |= LogError("VUID-vkResetCommandBuffer-commandPoolResetCommandBuffer-05135", commandBuffer, error_obj.location,
                         "VkPhysicalDeviceVulkanSC10Properties::commandPoolResetCommandBuffer is not supported.");
    }

    return skip;
}

bool SCCoreChecks::PreCallValidateGetFaultData(VkDevice device, VkFaultQueryBehavior faultQueryBehavior,
                                               VkBool32* pUnrecordedFaults, uint32_t* pFaultCount, VkFaultData* pFaults,
                                               const ErrorObject& error_obj) const {
    bool skip = BASE::PreCallValidateGetFaultData(device, faultQueryBehavior, pUnrecordedFaults, pFaultCount, pFaults, error_obj);

    if (*pFaultCount > phys_dev_props_sc_10_.maxQueryFaultCount) {
        skip |= LogError("VUID-vkGetFaultData-pFaultCount-05020", device, error_obj.location.dot(Field::pFaultCount),
                         "(%u) exceeds the device limit VkPhysicalDeviceVulkanSC10Properties::maxQueryFaultCount (%u).",
                         *pFaultCount, phys_dev_props_sc_10_.maxQueryFaultCount);
    }

    return skip;
}
