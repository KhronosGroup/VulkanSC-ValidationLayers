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
#include <cmath>

#include "generated/vk_enum_string_helper.h"
#include "generated/vk_format_utils.h"
#include "generated/vk_typemap_helper.h"
#include "utils/vk_layer_utils.h"

#include "generated/chassis.h"
#include "vulkansc/state_tracker/sc_state_tracker.h"
#include "core_checks/core_validation.h"

template class SCValidationStateTracker<CoreChecks>;

template <typename BASE>
template <typename CreateInfo>
void SCValidationStateTracker<BASE>::ReservePipelinePoolEntries(uint32_t create_info_count, const CreateInfo *create_info) {
    vvl::unordered_map<VkDeviceSize, uint32_t> reserved_pipeline_pool_entries{};
    for (uint32_t i = 0; i < create_info_count; ++i) {
        auto offline_info = LvlFindInChain<VkPipelineOfflineCreateInfo>(create_info[i].pNext);
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
void SCValidationStateTracker<BASE>::RecyclePipelinePoolEntry(const VkPipelineOfflineCreateInfo *offline_info) {
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
void SCValidationStateTracker<BASE>::CreateDevice(const VkDeviceCreateInfo *pCreateInfo) {
    BASE::CreateDevice(pCreateInfo);

    const auto *sc_10_features = LvlFindInChain<VkPhysicalDeviceVulkanSC10Features>(pCreateInfo->pNext);
    if (sc_10_features != nullptr) {
        enabled_sc_features_.core = *sc_10_features;
    }

    const auto *object_reservation_info = LvlFindInChain<VkDeviceObjectReservationCreateInfo>(pCreateInfo->pNext);
    while (object_reservation_info != nullptr) {
        for (uint32_t i = 0; i < object_reservation_info->pipelineCacheCreateInfoCount; ++i) {
            const auto &create_info = object_reservation_info->pPipelineCacheCreateInfos[i];
            sc_pipeline_cache_map_.emplace(
                std::make_pair(create_info.pInitialData, std::make_unique<SCPipelineCacheData>(create_info)));
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

        object_reservation_info = LvlFindInChain<VkDeviceObjectReservationCreateInfo>(object_reservation_info->pNext);
    }

    const auto *private_data_slot_reservation_info = LvlFindInChain<VkDevicePrivateDataCreateInfoEXT>(pCreateInfo->pNext);
    while (private_data_slot_reservation_info != nullptr) {
        sc_private_data_slot_limits_.privateDataSlotRequestCount += private_data_slot_reservation_info->privateDataSlotRequestCount;

        private_data_slot_reservation_info =
            LvlFindInChain<VkDevicePrivateDataCreateInfoEXT>(private_data_slot_reservation_info->pNext);
    }

    const auto *perf_query_reservation_info = LvlFindInChain<VkPerformanceQueryReservationInfoKHR>(pCreateInfo->pNext);
    while (perf_query_reservation_info != nullptr) {
        sc_perf_query_limits_.maxPerformanceQueriesPerPool =
            std::max(sc_perf_query_limits_.maxPerformanceQueriesPerPool, perf_query_reservation_info->maxPerformanceQueriesPerPool);

        perf_query_reservation_info = LvlFindInChain<VkPerformanceQueryReservationInfoKHR>(perf_query_reservation_info->pNext);
    }

    phys_dev_props_sc_10_ = LvlInitStruct<VkPhysicalDeviceVulkanSC10Properties>();
    auto props = LvlInitStruct<VkPhysicalDeviceProperties2>(&phys_dev_props_sc_10_);
    DispatchGetPhysicalDeviceProperties2(BASE::physical_device, &props);
}

template <typename BASE>
std::shared_ptr<COMMAND_POOL_STATE> SCValidationStateTracker<BASE>::CreateCommandPoolState(
    VkCommandPool command_pool, const VkCommandPoolCreateInfo *pCreateInfo) {
    auto queue_flags = BASE::physical_device_state->queue_family_properties[pCreateInfo->queueFamilyIndex].queueFlags;
    return std::make_shared<SC_COMMAND_POOL_STATE>(this, command_pool, pCreateInfo, queue_flags);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo *pCreateInfo,
                                                                     const VkAllocationCallbacks *pAllocator,
                                                                     VkCommandPool *pCommandPool, VkResult result) {
    BASE::PostCallRecordCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool, result);
    if (result != VK_SUCCESS) return;

    const auto *mem_reservation_info = LvlFindInChain<VkCommandPoolMemoryReservationCreateInfo>(pCreateInfo->pNext);
    if (mem_reservation_info) {
        sc_reserved_objects_.command_buffers.fetch_add(mem_reservation_info->commandPoolMaxCommandBuffers);
    }
}

template <typename BASE>
std::shared_ptr<PIPELINE_CACHE_STATE> SCValidationStateTracker<BASE>::CreatePipelineCacheState(
    VkPipelineCache pipeline_cache, const VkPipelineCacheCreateInfo *pCreateInfo) const {
    auto it = sc_pipeline_cache_map_.find(pCreateInfo->pInitialData);
    auto data = (it != sc_pipeline_cache_map_.end()) ? it->second.get() : nullptr;
    return std::static_pointer_cast<PIPELINE_CACHE_STATE>(
        std::make_shared<SC_PIPELINE_CACHE_STATE>(pipeline_cache, pCreateInfo, data));
}

template <typename BASE>
std::shared_ptr<PIPELINE_STATE> SCValidationStateTracker<BASE>::CreateGraphicsPipelineState(
    const VkGraphicsPipelineCreateInfo *pCreateInfo, uint32_t create_index, std::shared_ptr<const RENDER_PASS_STATE> &&render_pass,
    std::shared_ptr<const PIPELINE_LAYOUT_STATE> &&layout, CreateShaderModuleStates *csm_states) const {
    return std::static_pointer_cast<PIPELINE_STATE>(std::make_shared<SC_PIPELINE_STATE>(
        this, pCreateInfo, create_index, std::move(render_pass), std::move(layout), csm_states));
}

template <typename BASE>
std::shared_ptr<PIPELINE_STATE> SCValidationStateTracker<BASE>::CreateComputePipelineState(
    const VkComputePipelineCreateInfo *pCreateInfo, uint32_t create_index,
    std::shared_ptr<const PIPELINE_LAYOUT_STATE> &&layout) const {
    return std::static_pointer_cast<PIPELINE_STATE>(
        std::make_shared<SC_PIPELINE_STATE>(this, pCreateInfo, create_index, std::move(layout)));
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreateGraphicsPipelines(
    VkDevice device, VkPipelineCache pipelineCache, uint32_t count, const VkGraphicsPipelineCreateInfo *pCreateInfos,
    const VkAllocationCallbacks *pAllocator, VkPipeline *pPipelines, VkResult result, void *cgpl_state_data) {
    BASE::PostCallRecordCreateGraphicsPipelines(device, pipelineCache, count, pCreateInfos, pAllocator, pPipelines, result,
                                                cgpl_state_data);

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
void SCValidationStateTracker<BASE>::PostCallRecordCreateComputePipelines(
    VkDevice device, VkPipelineCache pipelineCache, uint32_t count, const VkComputePipelineCreateInfo *pCreateInfos,
    const VkAllocationCallbacks *pAllocator, VkPipeline *pPipelines, VkResult result, void *ccpl_state_data) {
    BASE::PostCallRecordCreateComputePipelines(device, pipelineCache, count, pCreateInfos, pAllocator, pPipelines, result,
                                               ccpl_state_data);

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
void SCValidationStateTracker<BASE>::PreCallRecordDestroyPipeline(VkDevice device, VkPipeline pipeline,
                                                                  const VkAllocationCallbacks *pAllocator) {
    auto pipeline_state = Get<SC_PIPELINE_STATE>(pipeline);
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

    BASE::PreCallRecordDestroyPipeline(device, pipeline, pAllocator);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreateImageView(VkDevice device, const VkImageViewCreateInfo *pCreateInfo,
                                                                   const VkAllocationCallbacks *pAllocator, VkImageView *pView,
                                                                   VkResult result) {
    BASE::PostCallRecordCreateImageView(device, pCreateInfo, pAllocator, pView, result);
    if (result != VK_SUCCESS) return;

    if (pCreateInfo->subresourceRange.layerCount > 1) {
        sc_reserved_objects_.layered_image_views++;
    }
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PreCallRecordDestroyImageView(VkDevice device, VkImageView imageView,
                                                                   const VkAllocationCallbacks *pAllocator) {
    auto image_view_state = Get<IMAGE_VIEW_STATE>(imageView);
    if (image_view_state) {
        if (image_view_state->create_info.subresourceRange.layerCount > 1) {
            sc_reserved_objects_.layered_image_views--;
        }
    }

    BASE::PreCallRecordDestroyImageView(device, imageView, pAllocator);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreateDescriptorSetLayout(VkDevice device,
                                                                             const VkDescriptorSetLayoutCreateInfo *pCreateInfo,
                                                                             const VkAllocationCallbacks *pAllocator,
                                                                             VkDescriptorSetLayout *pSetLayout, VkResult result) {
    BASE::PostCallRecordCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout, result);
    if (result != VK_SUCCESS) return;

    sc_reserved_objects_.descriptor_set_layout_bindings.fetch_add(pCreateInfo->bindingCount);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PreCallRecordDestroyDescriptorSetLayout(VkDevice device,
                                                                             VkDescriptorSetLayout descriptorSetLayout,
                                                                             const VkAllocationCallbacks *pAllocator) {
    auto set_layout_state = Get<cvdescriptorset::DescriptorSetLayout>(descriptorSetLayout);
    if (set_layout_state) {
        sc_reserved_objects_.descriptor_set_layout_bindings.fetch_sub(set_layout_state->GetBindingCount());
    }

    BASE::PreCallRecordDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo *pCreateInfo,
                                                                    const VkAllocationCallbacks *pAllocator,
                                                                    VkRenderPass *pRenderPass, VkResult result) {
    BASE::PostCallRecordCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass, result);
    if (result != VK_SUCCESS) return;

    sc_reserved_objects_.subpass_descriptions.fetch_add(pCreateInfo->subpassCount);
    sc_reserved_objects_.attachment_descriptions.fetch_add(pCreateInfo->attachmentCount);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2 *pCreateInfo,
                                                                     const VkAllocationCallbacks *pAllocator,
                                                                     VkRenderPass *pRenderPass, VkResult result) {
    BASE::PostCallRecordCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass, result);
    if (result != VK_SUCCESS) return;

    sc_reserved_objects_.subpass_descriptions.fetch_add(pCreateInfo->subpassCount);
    sc_reserved_objects_.attachment_descriptions.fetch_add(pCreateInfo->attachmentCount);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PreCallRecordDestroyRenderPass(VkDevice device, VkRenderPass renderPass,
                                                                    const VkAllocationCallbacks *pAllocator) {
    auto rp_state = Get<RENDER_PASS_STATE>(renderPass);
    if (rp_state) {
        sc_reserved_objects_.subpass_descriptions.fetch_sub(rp_state->createInfo.subpassCount);
        sc_reserved_objects_.attachment_descriptions.fetch_sub(rp_state->createInfo.attachmentCount);
    }

    BASE::PreCallRecordDestroyRenderPass(device, renderPass, pAllocator);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreatePrivateDataSlotEXT(VkDevice device,
                                                                            const VkPrivateDataSlotCreateInfo *pCreateInfo,
                                                                            const VkAllocationCallbacks *pAllocator,
                                                                            VkPrivateDataSlot *pPrivateDataSlot, VkResult result) {
    BASE::PostCallRecordCreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot, result);
    if (result != VK_SUCCESS) return;

    sc_reserved_objects_.private_data_slots++;
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PreCallRecordDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                                            const VkAllocationCallbacks *pAllocator) {
    if (privateDataSlot != VK_NULL_HANDLE) {
        sc_reserved_objects_.private_data_slots--;
    }

    BASE::PreCallRecordDestroyPrivateDataSlotEXT(device, privateDataSlot, pAllocator);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordBeginCommandBuffer(VkCommandBuffer commandBuffer,
                                                                      const VkCommandBufferBeginInfo *pBeginInfo, VkResult result) {
    BASE::PostCallRecordBeginCommandBuffer(commandBuffer, pBeginInfo, result);
    if (result != VK_SUCCESS) return;

    auto cb_state = Get<CMD_BUFFER_STATE>(commandBuffer);
    if (cb_state) {
        auto cp_state = Get<SC_COMMAND_POOL_STATE>(cb_state->command_pool->commandPool());
        cp_state->command_buffers_recording++;
    }
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PreCallRecordEndCommandBuffer(VkCommandBuffer commandBuffer) {
    auto cb_state = Get<CMD_BUFFER_STATE>(commandBuffer);
    if (cb_state) {
        auto cp_state = Get<SC_COMMAND_POOL_STATE>(cb_state->command_pool->commandPool());
        cp_state->command_buffers_recording--;
    }

    BASE::PreCallRecordEndCommandBuffer(commandBuffer);
}
