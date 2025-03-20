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

#include <algorithm>
#include <cmath>

#include "vulkan/vk_enum_string_helper.h"
#include "vulkan/utility/vk_format_utils.h"
#include "utils/vk_layer_utils.h"

#include "state_tracker/device_state.h"
#include "state_tracker/image_state.h"
#include "state_tracker/descriptor_sets.h"
#include "state_tracker/render_pass_state.h"
#include "vulkansc/state_tracker/sc_state_tracker.h"
#include "core_checks/core_validation.h"
#include "sync/sync_validation.h"

namespace vvl::sc {

template class Instance<core::Instance>;
template class Device<CoreChecks>;

template class Instance<syncval::Instance>;
template class Device<SyncValidator>;

template <typename BASE>
template <typename CreateInfo>
void Device<BASE>::ReservePipelinePoolEntries(uint32_t create_info_count, const CreateInfo* create_info) {
    vvl::unordered_map<VkDeviceSize, uint32_t> reserved_pipeline_pool_entries{};
    for (uint32_t i = 0; i < create_info_count; ++i) {
        auto offline_info = vku::FindStructInPNextChain<VkPipelineOfflineCreateInfo>(create_info[i].pNext);
        if (offline_info) {
            reserved_pipeline_pool_entries[offline_info->poolEntrySize]++;
        } else {
            // We should never hit this as implementations are supposed to return VK_ERROR_NO_PIPELINE_MATCH
            // if no VkPipelineOfflineCreateInfo structure was included in the create info pNext chain
            assert(offline_info != nullptr);
        }
    }

    std::unique_lock<std::mutex> lock(sc_used_pipeline_pool_size_map_mutex_);
    for (const auto &it : reserved_pipeline_pool_entries) {
        sc_used_pipeline_pool_size_map_[it.first] += it.second;
    }
}

template <typename BASE>
void Device<BASE>::RecyclePipelinePoolEntry(const VkPipelineOfflineCreateInfo* offline_info) {
    if (phys_dev_props_sc_10_.recyclePipelineMemory) {
        if (offline_info) {
            std::unique_lock<std::mutex> lock(sc_used_pipeline_pool_size_map_mutex_);
            sc_used_pipeline_pool_size_map_[offline_info->poolEntrySize]--;
        } else {
            // We should never hit this as implementations are supposed to return VK_ERROR_NO_PIPELINE_MATCH
            // if no VkPipelineOfflineCreateInfo structure was included in the create info pNext chain
            assert(offline_info != nullptr);
        }
    }
}

template <typename BASE>
void Device<BASE>::FinishDeviceSetup(const VkDeviceCreateInfo* pCreateInfo, const Location& loc) {
    BaseClass::FinishDeviceSetup(pCreateInfo, loc);

    const auto *sc_10_features = vku::FindStructInPNextChain<VkPhysicalDeviceVulkanSC10Features>(pCreateInfo->pNext);
    if (sc_10_features != nullptr) {
        enabled_sc_features_.core = *sc_10_features;
    }

    const auto *object_reservation_info = vku::FindStructInPNextChain<VkDeviceObjectReservationCreateInfo>(pCreateInfo->pNext);
    while (object_reservation_info != nullptr) {
        for (uint32_t i = 0; i < object_reservation_info->pipelineCacheCreateInfoCount; ++i) {
            const auto &create_info = object_reservation_info->pPipelineCacheCreateInfos[i];
            const bool copy_data = true;  // Copy pipeline cache data to be able to verify contents later
            sc_pipeline_cache_map_.emplace(
                std::make_pair(create_info.pInitialData, std::make_unique<PipelineCacheData>(create_info, copy_data)));
        }

        for (uint32_t i = 0; i < object_reservation_info->pipelinePoolSizeCount; ++i) {
            const auto &pool_size = object_reservation_info->pPipelinePoolSizes[i];
            sc_pipeline_pool_size_map_[pool_size.poolEntrySize] += pool_size.poolEntryCount;
        }

        sc_object_limits_.semaphoreRequestCount += object_reservation_info->semaphoreRequestCount;
        sc_object_limits_.commandBufferRequestCount += object_reservation_info->commandBufferRequestCount;
        sc_object_limits_.fenceRequestCount += object_reservation_info->fenceRequestCount;
        sc_object_limits_.deviceMemoryRequestCount += object_reservation_info->deviceMemoryRequestCount;
        sc_object_limits_.bufferRequestCount += object_reservation_info->bufferRequestCount;
        sc_object_limits_.imageRequestCount += object_reservation_info->imageRequestCount;
        sc_object_limits_.eventRequestCount += object_reservation_info->eventRequestCount;
        sc_object_limits_.queryPoolRequestCount += object_reservation_info->queryPoolRequestCount;
        sc_object_limits_.bufferViewRequestCount += object_reservation_info->bufferViewRequestCount;
        sc_object_limits_.imageViewRequestCount += object_reservation_info->imageViewRequestCount;
        sc_object_limits_.layeredImageViewRequestCount += object_reservation_info->layeredImageViewRequestCount;
        sc_object_limits_.pipelineCacheRequestCount += object_reservation_info->pipelineCacheRequestCount;
        sc_object_limits_.pipelineLayoutRequestCount += object_reservation_info->pipelineLayoutRequestCount;
        sc_object_limits_.renderPassRequestCount += object_reservation_info->renderPassRequestCount;
        sc_object_limits_.graphicsPipelineRequestCount += object_reservation_info->graphicsPipelineRequestCount;
        sc_object_limits_.computePipelineRequestCount += object_reservation_info->computePipelineRequestCount;
        sc_object_limits_.descriptorSetLayoutRequestCount += object_reservation_info->descriptorSetLayoutRequestCount;
        sc_object_limits_.samplerRequestCount += object_reservation_info->samplerRequestCount;
        sc_object_limits_.descriptorPoolRequestCount += object_reservation_info->descriptorPoolRequestCount;
        sc_object_limits_.descriptorSetRequestCount += object_reservation_info->descriptorSetRequestCount;
        sc_object_limits_.framebufferRequestCount += object_reservation_info->framebufferRequestCount;
        sc_object_limits_.commandPoolRequestCount += object_reservation_info->commandPoolRequestCount;
        sc_object_limits_.samplerYcbcrConversionRequestCount += object_reservation_info->samplerYcbcrConversionRequestCount;
        sc_object_limits_.swapchainRequestCount += object_reservation_info->swapchainRequestCount;
        sc_object_limits_.subpassDescriptionRequestCount += object_reservation_info->subpassDescriptionRequestCount;
        sc_object_limits_.attachmentDescriptionRequestCount += object_reservation_info->attachmentDescriptionRequestCount;
        sc_object_limits_.descriptorSetLayoutBindingRequestCount += object_reservation_info->descriptorSetLayoutBindingRequestCount;

        sc_object_limits_.descriptorSetLayoutBindingLimit =
            std::max(sc_object_limits_.descriptorSetLayoutBindingLimit, object_reservation_info->descriptorSetLayoutBindingLimit);
        sc_object_limits_.maxImageViewMipLevels =
            std::max(sc_object_limits_.maxImageViewMipLevels, object_reservation_info->maxImageViewMipLevels);
        sc_object_limits_.maxImageViewArrayLayers =
            std::max(sc_object_limits_.maxImageViewArrayLayers, object_reservation_info->maxImageViewArrayLayers);
        sc_object_limits_.maxLayeredImageViewMipLevels =
            std::max(sc_object_limits_.maxLayeredImageViewMipLevels, object_reservation_info->maxLayeredImageViewMipLevels);
        sc_object_limits_.maxOcclusionQueriesPerPool =
            std::max(sc_object_limits_.maxOcclusionQueriesPerPool, object_reservation_info->maxOcclusionQueriesPerPool);
        sc_object_limits_.maxPipelineStatisticsQueriesPerPool = std::max(
            sc_object_limits_.maxPipelineStatisticsQueriesPerPool, object_reservation_info->maxPipelineStatisticsQueriesPerPool);
        sc_object_limits_.maxTimestampQueriesPerPool =
            std::max(sc_object_limits_.maxTimestampQueriesPerPool, object_reservation_info->maxTimestampQueriesPerPool);
        sc_object_limits_.maxImmutableSamplersPerDescriptorSetLayout =
            std::max(sc_object_limits_.maxImmutableSamplersPerDescriptorSetLayout,
                     object_reservation_info->maxImmutableSamplersPerDescriptorSetLayout);

        object_reservation_info = vku::FindStructInPNextChain<VkDeviceObjectReservationCreateInfo>(object_reservation_info->pNext);
    }

    const auto *private_data_slot_reservation_info =
        vku::FindStructInPNextChain<VkDevicePrivateDataCreateInfoEXT>(pCreateInfo->pNext);
    while (private_data_slot_reservation_info != nullptr) {
        sc_private_data_slot_limits_.privateDataSlotRequestCount += private_data_slot_reservation_info->privateDataSlotRequestCount;

        private_data_slot_reservation_info =
            vku::FindStructInPNextChain<VkDevicePrivateDataCreateInfoEXT>(private_data_slot_reservation_info->pNext);
    }

    const auto *perf_query_reservation_info = vku::FindStructInPNextChain<VkPerformanceQueryReservationInfoKHR>(pCreateInfo->pNext);
    while (perf_query_reservation_info != nullptr) {
        sc_perf_query_limits_.maxPerformanceQueriesPerPool =
            std::max(sc_perf_query_limits_.maxPerformanceQueriesPerPool, perf_query_reservation_info->maxPerformanceQueriesPerPool);

        perf_query_reservation_info =
            vku::FindStructInPNextChain<VkPerformanceQueryReservationInfoKHR>(perf_query_reservation_info->pNext);
    }

    phys_dev_props_sc_10_ = vku::InitStruct<VkPhysicalDeviceVulkanSC10Properties>();
    auto props = vku::InitStruct<VkPhysicalDeviceProperties2>(&phys_dev_props_sc_10_);
    DispatchGetPhysicalDeviceProperties2Helper(BaseClass::api_version, BaseClass::physical_device, &props);
}

template <typename BASE>
std::shared_ptr<vvl::CommandPool> Device<BASE>::CreateCommandPoolState(VkCommandPool command_pool,
                                                                       const VkCommandPoolCreateInfo* pCreateInfo) {
    auto queue_flags = BaseClass::physical_device_state->queue_family_properties[pCreateInfo->queueFamilyIndex].queueFlags;
    return std::make_shared<CommandPool>(*this, command_pool, pCreateInfo, queue_flags);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool,
                                                   const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    const auto *mem_reservation_info = vku::FindStructInPNextChain<VkCommandPoolMemoryReservationCreateInfo>(pCreateInfo->pNext);
    if (mem_reservation_info) {
        sc_reserved_objects_.command_buffers.fetch_add(mem_reservation_info->commandPoolMaxCommandBuffers);
    }

    sc_reserved_objects_.command_pools++;
}

template <typename BASE>
void Device<BASE>::PostCallRecordAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory,
                                                const RecordObject& record_obj) {
    BaseClass::PostCallRecordAllocateMemory(device, pAllocateInfo, pAllocator, pMemory, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.device_memories++;
}

template <typename BASE>
std::shared_ptr<vvl::PipelineCache> Device<BASE>::CreatePipelineCacheState(VkPipelineCache pipeline_cache,
                                                                           const VkPipelineCacheCreateInfo* pCreateInfo) const {
    return std::static_pointer_cast<vvl::PipelineCache>(std::make_shared<PipelineCache>(*this, pipeline_cache, pCreateInfo));
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache,
                                                     const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.pipeline_caches++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache,
                                                     const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    auto pipeline_cache_state = Get<vvl::PipelineCache>(pipelineCache);
    if (pipeline_cache_state) {
        sc_reserved_objects_.pipeline_caches--;
    }

    BaseClass::PreCallRecordDestroyPipelineCache(device, pipelineCache, pAllocator, record_obj);
}

template <typename BASE>
std::shared_ptr<vvl::Pipeline> Device<BASE>::CreateGraphicsPipelineState(
    const VkGraphicsPipelineCreateInfo* pCreateInfo, std::shared_ptr<const vvl::PipelineCache> pipeline_cache,
    std::shared_ptr<const vvl::RenderPass>&& render_pass, std::shared_ptr<const vvl::PipelineLayout>&& layout,
    spirv::StatelessData stateless_data[kCommonMaxGraphicsShaderStages]) const {
    // If any of the VkPipelineShaderStageCreateInfo entries are missing:
    //  * the entry point name (pName == NULL)
    //  * specialization info (pSpecializationInfo == NULL), if necessary
    // Then if those are available in the pipeline JSON debug information, we should patch the info passed
    // to the pipeline state object in order for those to be available for SPIR-V dependent validation.
    bool patch_with_pipeline_json_data = false;
    auto offline_info = vku::FindStructInPNextChain<VkPipelineOfflineCreateInfo>(pCreateInfo->pNext);
    auto pipeline_entry = std::static_pointer_cast<const PipelineCache>(pipeline_cache)->GetPipeline(offline_info);
    if (pipeline_entry) {
        for (uint32_t stage_index = 0; stage_index < pCreateInfo->stageCount; ++stage_index) {
            // Only consider stages that actually have SPIR-V debug information
            if (pipeline_entry->GetShaderModule(stage_index) != nullptr) {
                if (pCreateInfo->pStages[stage_index].pName == nullptr &&
                    pipeline_entry->GetJsonEntryPointName(stage_index) != nullptr) {
                    // We can patch missing entry point name
                    patch_with_pipeline_json_data = true;
                }
                if (pCreateInfo->pStages[stage_index].pSpecializationInfo == nullptr &&
                    pipeline_entry->GetJsonSpecializationInfo(stage_index) != nullptr) {
                    // We can patch missing specialization info
                    patch_with_pipeline_json_data = true;
                }
            }
        }
    }
    VkGraphicsPipelineCreateInfo create_info{};
    std::vector<VkPipelineShaderStageCreateInfo> stages_ci{};
    if (patch_with_pipeline_json_data) {
        stages_ci.resize(pCreateInfo->stageCount);
        for (uint32_t stage_index = 0; stage_index < pCreateInfo->stageCount; ++stage_index) {
            stages_ci[stage_index] = pCreateInfo->pStages[stage_index];
            stages_ci[stage_index].pName = pipeline_entry->GetJsonEntryPointName(stage_index);
            stages_ci[stage_index].pSpecializationInfo = pipeline_entry->GetJsonSpecializationInfo(stage_index);
        }
        create_info = *pCreateInfo;
        create_info.pStages = stages_ci.data();
        pCreateInfo = &create_info;
    }

    return std::static_pointer_cast<vvl::Pipeline>(std::make_shared<Pipeline>(
        *this, pCreateInfo, std::move(pipeline_cache), std::move(render_pass), std::move(layout), stateless_data));
}

template <typename BASE>
std::shared_ptr<vvl::Pipeline> Device<BASE>::CreateComputePipelineState(const VkComputePipelineCreateInfo* pCreateInfo,
                                                                        std::shared_ptr<const vvl::PipelineCache> pipeline_cache,
                                                                        std::shared_ptr<const vvl::PipelineLayout>&& layout,
                                                                        spirv::StatelessData* stateless_data) const {
    // If the VkPipelineShaderStageCreateInfo entries is missing:
    //  * the entry point name (pName == NULL)
    //  * specialization info (pSpecializationInfo == NULL), if necessary
    // Then if those are available in the pipeline JSON debug information, we should patch the info passed
    // to the pipeline state object in order for those to be available for SPIR-V dependent validation.
    bool patch_with_pipeline_json_data = false;
    auto offline_info = vku::FindStructInPNextChain<VkPipelineOfflineCreateInfo>(pCreateInfo->pNext);
    auto pipeline_entry = std::static_pointer_cast<const PipelineCache>(pipeline_cache)->GetPipeline(offline_info);
    if (pipeline_entry) {
        // Only consider if stage has SPIR-V debug information
        if (pipeline_entry->GetShaderModule(0) != nullptr) {
            if (pCreateInfo->stage.pName == nullptr && pipeline_entry->GetJsonEntryPointName(0) != nullptr) {
                // We can patch missing entry point name
                patch_with_pipeline_json_data = true;
            }
            if (pCreateInfo->stage.pSpecializationInfo == nullptr && pipeline_entry->GetJsonSpecializationInfo(0) != nullptr) {
                // We can patch missing specialization info
                patch_with_pipeline_json_data = true;
            }
        }
    }
    VkComputePipelineCreateInfo create_info{};
    if (patch_with_pipeline_json_data) {
        create_info = *pCreateInfo;
        create_info.stage.pName = pipeline_entry->GetJsonEntryPointName(0);
        create_info.stage.pSpecializationInfo = pipeline_entry->GetJsonSpecializationInfo(0);
        pCreateInfo = &create_info;
    }

    return std::static_pointer_cast<vvl::Pipeline>(
        std::make_shared<Pipeline>(*this, pCreateInfo, std::move(pipeline_cache), std::move(layout), stateless_data));
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t count,
                                                         const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                         const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                         const RecordObject& record_obj, PipelineStates& pipeline_states,
                                                         chassis::CreateGraphicsPipelines& chassis_state) {
    BaseClass::PostCallRecordCreateGraphicsPipelines(device, pipelineCache, count, pCreateInfos, pAllocator, pPipelines, record_obj,
                                                     pipeline_states, chassis_state);
    if (VK_SUCCESS != record_obj.result) return;

    ReservePipelinePoolEntries(count, pCreateInfos);

    // This API may create pipelines regardless of the return value
    uint32_t created_count = 0;
    for (uint32_t i = 0; i < count; i++) {
        if (pPipelines[i] != VK_NULL_HANDLE) {
            ++created_count;
        }
    }
    sc_reserved_objects_.graphics_pipelines.fetch_add(created_count);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t count,
                                                        const VkComputePipelineCreateInfo* pCreateInfos,
                                                        const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                        const RecordObject& record_obj, PipelineStates& pipeline_states,
                                                        chassis::CreateComputePipelines& chassis_state) {
    BaseClass::PostCallRecordCreateComputePipelines(device, pipelineCache, count, pCreateInfos, pAllocator, pPipelines, record_obj,
                                                    pipeline_states, chassis_state);
    if (VK_SUCCESS != record_obj.result) return;

    ReservePipelinePoolEntries(count, pCreateInfos);

    // This API may create pipelines regardless of the return value
    uint32_t created_count = 0;
    for (uint32_t i = 0; i < count; i++) {
        if (pPipelines[i] != VK_NULL_HANDLE) {
            ++created_count;
        }
    }
    sc_reserved_objects_.compute_pipelines.fetch_add(created_count);
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator,
                                                const RecordObject& record_obj) {
    auto pipeline_state = Get<Pipeline>(pipeline);
    if (pipeline_state) {
        switch (pipeline_state->pipeline_type) {
            case VK_PIPELINE_BIND_POINT_GRAPHICS:
                sc_reserved_objects_.graphics_pipelines--;
                break;

            case VK_PIPELINE_BIND_POINT_COMPUTE:
                sc_reserved_objects_.compute_pipelines--;
                break;

            default:
                // Unsupported pipeline type for Vulkan SC
                assert(false);
                break;
        }

        RecyclePipelinePoolEntry(pipeline_state->offline_info);
    }

    BaseClass::PreCallRecordDestroyPipeline(device, pipeline, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer,
                                              const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateBuffer(device, pCreateInfo, pAllocator, pBuffer, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.buffers++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator,
                                              const RecordObject& record_obj) {
    auto buffer_state = Get<vvl::Buffer>(buffer);
    if (buffer_state) {
        sc_reserved_objects_.buffers--;
    }

    BaseClass::PreCallRecordDestroyBuffer(device, buffer, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkBufferView* pView,
                                                  const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateBufferView(device, pCreateInfo, pAllocator, pView, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.buffer_views++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator,
                                                  const RecordObject& record_obj) {
    auto buffer_view_state = Get<vvl::BufferView>(bufferView);
    if (buffer_view_state) {
        sc_reserved_objects_.buffer_views--;
    }

    BaseClass::PreCallRecordDestroyBufferView(device, bufferView, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo,
                                             const VkAllocationCallbacks* pAllocator, VkImage* pImage,
                                             const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateImage(device, pCreateInfo, pAllocator, pImage, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.images++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator,
                                             const RecordObject& record_obj) {
    auto image_state = Get<vvl::Image>(image);
    if (image_state) {
        sc_reserved_objects_.images--;
    }

    BaseClass::PreCallRecordDestroyImage(device, image, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkImageView* pView,
                                                 const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateImageView(device, pCreateInfo, pAllocator, pView, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.image_views++;

    if (pCreateInfo->subresourceRange.layerCount > 1) {
        sc_reserved_objects_.layered_image_views++;
    }
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator,
                                                 const RecordObject& record_obj) {
    auto image_view_state = Get<vvl::ImageView>(imageView);
    if (image_view_state) {
        if (image_view_state->create_info.subresourceRange.layerCount > 1) {
            sc_reserved_objects_.layered_image_views--;
        }
        sc_reserved_objects_.image_views--;
    }

    BaseClass::PreCallRecordDestroyImageView(device, imageView, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator, VkSampler* pSampler,
                                               const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateSampler(device, pCreateInfo, pAllocator, pSampler, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.samplers++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator,
                                               const RecordObject& record_obj) {
    auto sampler_state = Get<vvl::Sampler>(sampler);
    if (sampler_state) {
        sc_reserved_objects_.samplers--;
    }

    BaseClass::PreCallRecordDestroySampler(device, sampler, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateSamplerYcbcrConversion(VkDevice device,
                                                              const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                              const VkAllocationCallbacks* pAllocator,
                                                              VkSamplerYcbcrConversion* pYcbcrConversion,
                                                              const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.sampler_ycbcr_conversions++;
}

template <typename BASE>
void Device<BASE>::PostCallRecordDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               const RecordObject& record_obj) {
    auto conversion_state = Get<vvl::SamplerYcbcrConversion>(ycbcrConversion);
    if (conversion_state) {
        sc_reserved_objects_.sampler_ycbcr_conversions--;
    }

    BaseClass::PostCallRecordDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout,
                                                      const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.pipeline_layouts++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout,
                                                      const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    auto pipeline_layout_state = Get<vvl::PipelineLayout>(pipelineLayout);
    if (pipeline_layout_state) {
        sc_reserved_objects_.pipeline_layouts--;
    }

    BaseClass::PreCallRecordDestroyPipelineLayout(device, pipelineLayout, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           VkDescriptorSetLayout* pSetLayout, const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.descriptor_set_layout_bindings.fetch_add(pCreateInfo->bindingCount);
    sc_reserved_objects_.descriptor_set_layouts++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           const RecordObject& record_obj) {
    auto set_layout_state = Get<vvl::DescriptorSetLayout>(descriptorSetLayout);
    if (set_layout_state) {
        sc_reserved_objects_.descriptor_set_layouts--;
        sc_reserved_objects_.descriptor_set_layout_bindings.fetch_sub(set_layout_state->GetBindingCount());
    }

    BaseClass::PreCallRecordDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator, record_obj);
}

template <typename BASE>
std::shared_ptr<vvl::DescriptorPool> Device<BASE>::CreateDescriptorPoolState(VkDescriptorPool handle,
                                                                             const VkDescriptorPoolCreateInfo* create_info) {
    return std::make_shared<DescriptorPool>(*this, handle, create_info);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool,
                                                      const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.descriptor_pools++;
}

template <typename BASE>
void Device<BASE>::PostCallRecordResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool,
                                                     VkDescriptorPoolResetFlags flags, const RecordObject& record_obj) {
    auto pool_state = Get<DescriptorPool>(descriptorPool);
    if (pool_state) {
        uint32_t allocated_sets = pool_state->allocated_descriptor_sets.exchange(0);
        sc_reserved_objects_.descriptor_sets.fetch_sub(allocated_sets);
    }

    BaseClass::PostCallRecordResetDescriptorPool(device, descriptorPool, flags, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                                        VkDescriptorSet* pDescriptorSets, const RecordObject& record_obj,
                                                        vvl::AllocateDescriptorSetsData& ads_state) {
    BaseClass::PostCallRecordAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets, record_obj, ads_state);
    if (VK_SUCCESS != record_obj.result) return;

    auto pool_state = Get<DescriptorPool>(pAllocateInfo->descriptorPool);
    if (pool_state) {
        sc_reserved_objects_.descriptor_sets.fetch_add(pAllocateInfo->descriptorSetCount);
        pool_state->allocated_descriptor_sets.fetch_add(pAllocateInfo->descriptorSetCount);
    }
}

template <typename BASE>
void Device<BASE>::PreCallRecordFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t count,
                                                   const VkDescriptorSet* pDescriptorSets, const RecordObject& record_obj) {
    auto pool_state = Get<DescriptorPool>(descriptorPool);
    if (pool_state) {
        uint32_t actual_free_count = 0;
        for (uint32_t i = 0; i < count; ++i) {
            auto set_state = Get<vvl::DescriptorSet>(pDescriptorSets[i]);
            if (set_state) {
                actual_free_count++;
            }
        }
        pool_state->allocated_descriptor_sets.fetch_sub(actual_free_count);
        sc_reserved_objects_.descriptor_sets.fetch_sub(actual_free_count);
    }

    BaseClass::PreCallRecordFreeDescriptorSets(device, descriptorPool, count, pDescriptorSets, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                                  const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.subpass_descriptions.fetch_add(pCreateInfo->subpassCount);
    sc_reserved_objects_.attachment_descriptions.fetch_add(pCreateInfo->attachmentCount);
    sc_reserved_objects_.render_passes++;
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                                   const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.subpass_descriptions.fetch_add(pCreateInfo->subpassCount);
    sc_reserved_objects_.attachment_descriptions.fetch_add(pCreateInfo->attachmentCount);
    sc_reserved_objects_.render_passes++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator,
                                                  const RecordObject& record_obj) {
    auto rp_state = Get<vvl::RenderPass>(renderPass);
    if (rp_state) {
        sc_reserved_objects_.render_passes--;
        sc_reserved_objects_.subpass_descriptions.fetch_sub(rp_state->create_info.subpassCount);
        sc_reserved_objects_.attachment_descriptions.fetch_sub(rp_state->create_info.attachmentCount);
    }

    BaseClass::PreCallRecordDestroyRenderPass(device, renderPass, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer,
                                                   const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.framebuffers++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer,
                                                   const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    auto fb_state = Get<vvl::Framebuffer>(framebuffer);
    if (fb_state) {
        sc_reserved_objects_.framebuffers--;
    }

    BaseClass::PreCallRecordDestroyFramebuffer(device, framebuffer, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo,
                                             const VkAllocationCallbacks* pAllocator, VkFence* pFence,
                                             const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateFence(device, pCreateInfo, pAllocator, pFence, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.fences++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator,
                                             const RecordObject& record_obj) {
    auto fence_state = Get<vvl::Fence>(fence);
    if (fence_state) {
        sc_reserved_objects_.fences--;
    }

    BaseClass::PreCallRecordDestroyFence(device, fence, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore,
                                                 const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.semaphores++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator,
                                                 const RecordObject& record_obj) {
    auto semaphore_state = Get<vvl::Semaphore>(semaphore);
    if (semaphore_state) {
        sc_reserved_objects_.semaphores--;
    }

    BaseClass::PreCallRecordDestroySemaphore(device, semaphore, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo,
                                             const VkAllocationCallbacks* pAllocator, VkEvent* pEvent,
                                             const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateEvent(device, pCreateInfo, pAllocator, pEvent, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.events++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator,
                                             const RecordObject& record_obj) {
    auto event_state = Get<vvl::Event>(event);
    if (event_state) {
        sc_reserved_objects_.events--;
    }

    BaseClass::PreCallRecordDestroyEvent(device, event, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool,
                                                 const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.query_pools++;
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator,
                                                          VkPrivateDataSlot* pPrivateDataSlot, const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.private_data_slots++;
}

template <typename BASE>
void Device<BASE>::PreCallRecordDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                          const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    if (privateDataSlot != VK_NULL_HANDLE) {
        sc_reserved_objects_.private_data_slots--;
    }

    BaseClass::PreCallRecordDestroyPrivateDataSlotEXT(device, privateDataSlot, pAllocator, record_obj);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                                           const VkSwapchainCreateInfoKHR* pCreateInfos,
                                                           const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains,
                                                           const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.swapchains.fetch_add(swapchainCount);
}

template <typename BASE>
void Device<BASE>::PostCallRecordCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain,
                                                    const RecordObject& record_obj) {
    BaseClass::PostCallRecordCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.swapchains++;
}

template <typename BASE>
void Device<BASE>::PostCallRecordBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo,
                                                    const RecordObject& record_obj) {
    BaseClass::PostCallRecordBeginCommandBuffer(commandBuffer, pBeginInfo, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    auto cb_state = Get<vvl::CommandBuffer>(commandBuffer);
    if (cb_state) {
        auto cp_state = Get<CommandPool>(cb_state->command_pool->VkHandle());
        cp_state->command_buffers_recording++;
    }
}

template <typename BASE>
void Device<BASE>::PreCallRecordEndCommandBuffer(VkCommandBuffer commandBuffer, const RecordObject& record_obj) {
    auto cb_state = Get<vvl::CommandBuffer>(commandBuffer);
    if (cb_state) {
        auto cp_state = Get<CommandPool>(cb_state->command_pool->VkHandle());
        cp_state->command_buffers_recording--;
    }

    BaseClass::PreCallRecordEndCommandBuffer(commandBuffer, record_obj);
}

}  // namespace vvl::sc
