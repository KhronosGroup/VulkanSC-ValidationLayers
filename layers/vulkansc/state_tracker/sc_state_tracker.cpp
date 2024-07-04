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
#include <cmath>

#include "vulkan/vk_enum_string_helper.h"
#include "vulkan/utility/vk_format_utils.h"
#include "utils/vk_layer_utils.h"

#include "generated/chassis.h"
#include "state_tracker/device_state.h"
#include "state_tracker/image_state.h"
#include "state_tracker/descriptor_sets.h"
#include "state_tracker/render_pass_state.h"
#include "vulkansc/state_tracker/sc_state_tracker.h"
#include "core_checks/core_validation.h"
#include "sync/sync_validation.h"

template class SCValidationStateTracker<CoreChecks>;
template class SCValidationStateTracker<SyncValidator>;

template <typename BASE>
template <typename CreateInfo>
void SCValidationStateTracker<BASE>::ReservePipelinePoolEntries(uint32_t create_info_count, const CreateInfo *create_info) {
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
void SCValidationStateTracker<BASE>::CreateDevice(const VkDeviceCreateInfo *pCreateInfo, const Location& loc) {
    BASE::CreateDevice(pCreateInfo, loc);

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
                std::make_pair(create_info.pInitialData, std::make_unique<vvl::sc::PipelineCacheData>(create_info, copy_data)));
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
    DispatchGetPhysicalDeviceProperties2(BASE::physical_device, &props);
}

template <typename BASE>
std::shared_ptr<vvl::CommandPool> SCValidationStateTracker<BASE>::CreateCommandPoolState(
    VkCommandPool command_pool, const VkCommandPoolCreateInfo *pCreateInfo) {
    auto queue_flags = BASE::physical_device_state->queue_family_properties[pCreateInfo->queueFamilyIndex].queueFlags;
    return std::make_shared<vvl::sc::CommandPool>(*this, command_pool, pCreateInfo, queue_flags);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo *pCreateInfo,
                                                                     const VkAllocationCallbacks *pAllocator,
                                                                     VkCommandPool *pCommandPool, const RecordObject &record_obj) {
    BASE::PostCallRecordCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    const auto *mem_reservation_info = vku::FindStructInPNextChain<VkCommandPoolMemoryReservationCreateInfo>(pCreateInfo->pNext);
    if (mem_reservation_info) {
        sc_reserved_objects_.command_buffers.fetch_add(mem_reservation_info->commandPoolMaxCommandBuffers);
    }
}

template <typename BASE>
std::shared_ptr<vvl::PipelineCache> SCValidationStateTracker<BASE>::CreatePipelineCacheState(
    VkPipelineCache pipeline_cache, const VkPipelineCacheCreateInfo *pCreateInfo) const {
    return std::static_pointer_cast<vvl::PipelineCache>(
        std::make_shared<vvl::sc::PipelineCache>(*this, pipeline_cache, pCreateInfo));
}

template <typename BASE>
std::shared_ptr<vvl::Pipeline> SCValidationStateTracker<BASE>::CreateGraphicsPipelineState(
    const VkGraphicsPipelineCreateInfo *pCreateInfo, std::shared_ptr<const vvl::PipelineCache> pipeline_cache,
    std::shared_ptr<const vvl::RenderPass> &&render_pass, std::shared_ptr<const vvl::PipelineLayout> &&layout,
    ShaderModuleUniqueIds *shader_unique_id_map) const {
    // If any of the VkPipelineShaderStageCreateInfo entries are missing:
    //  * the entry point name (pName == NULL)
    //  * specialization info (pSpecializationInfo == NULL), if necessary
    // Then if those are available in the pipeline JSON debug information, we should patch the info passed
    // to the pipeline state object in order for those to be available for SPIR-V dependent validation.
    bool patch_with_pipeline_json_data = false;
    auto offline_info = vku::FindStructInPNextChain<VkPipelineOfflineCreateInfo>(pCreateInfo->pNext);
    auto pipeline_entry = std::static_pointer_cast<const vvl::sc::PipelineCache>(pipeline_cache)->GetPipeline(offline_info);
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

    return std::static_pointer_cast<vvl::Pipeline>(std::make_shared<vvl::sc::Pipeline>(
        *this, pCreateInfo, std::move(pipeline_cache), std::move(render_pass), std::move(layout), shader_unique_id_map));
}

template <typename BASE>
std::shared_ptr<vvl::Pipeline> SCValidationStateTracker<BASE>::CreateComputePipelineState(
    const VkComputePipelineCreateInfo *pCreateInfo, std::shared_ptr<const vvl::PipelineCache> pipeline_cache,
    std::shared_ptr<const vvl::PipelineLayout> &&layout) const {
    // If the VkPipelineShaderStageCreateInfo entries is missing:
    //  * the entry point name (pName == NULL)
    //  * specialization info (pSpecializationInfo == NULL), if necessary
    // Then if those are available in the pipeline JSON debug information, we should patch the info passed
    // to the pipeline state object in order for those to be available for SPIR-V dependent validation.
    bool patch_with_pipeline_json_data = false;
    auto offline_info = vku::FindStructInPNextChain<VkPipelineOfflineCreateInfo>(pCreateInfo->pNext);
    auto pipeline_entry = std::static_pointer_cast<const vvl::sc::PipelineCache>(pipeline_cache)->GetPipeline(offline_info);
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
        std::make_shared<vvl::sc::Pipeline>(*this, pCreateInfo, std::move(pipeline_cache), std::move(layout)));
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreateGraphicsPipelines(
    VkDevice device, VkPipelineCache pipelineCache, uint32_t count, const VkGraphicsPipelineCreateInfo *pCreateInfos,
    const VkAllocationCallbacks *pAllocator, VkPipeline *pPipelines, const RecordObject &record_obj, PipelineStates& pipeline_states,
                                               chassis::CreateGraphicsPipelines& chassis_state) {
    BASE::PostCallRecordCreateGraphicsPipelines(device, pipelineCache, count, pCreateInfos, pAllocator, pPipelines, record_obj,
                                                pipeline_states, chassis_state);

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
    const VkAllocationCallbacks *pAllocator, VkPipeline *pPipelines, const RecordObject &record_obj, PipelineStates& pipeline_states,
                                               chassis::CreateComputePipelines& chassis_state) {
    BASE::PostCallRecordCreateComputePipelines(device, pipelineCache, count, pCreateInfos, pAllocator, pPipelines, record_obj,
                                               pipeline_states, chassis_state);

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
                                                                  const VkAllocationCallbacks *pAllocator,
                                                                  const RecordObject &record_obj) {
    auto pipeline_state = Get<vvl::sc::Pipeline>(pipeline);
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

    BASE::PreCallRecordDestroyPipeline(device, pipeline, pAllocator, record_obj);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreateImageView(VkDevice device, const VkImageViewCreateInfo *pCreateInfo,
                                                                   const VkAllocationCallbacks *pAllocator, VkImageView *pView,
                                                                   const RecordObject &record_obj) {
    BASE::PostCallRecordCreateImageView(device, pCreateInfo, pAllocator, pView, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    if (pCreateInfo->subresourceRange.layerCount > 1) {
        sc_reserved_objects_.layered_image_views++;
    }
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PreCallRecordDestroyImageView(VkDevice device, VkImageView imageView,
                                                                   const VkAllocationCallbacks *pAllocator,
                                                                   const RecordObject &record_obj) {
    auto image_view_state = Get<vvl::ImageView>(imageView);
    if (image_view_state) {
        if (image_view_state->create_info.subresourceRange.layerCount > 1) {
            sc_reserved_objects_.layered_image_views--;
        }
    }

    BASE::PreCallRecordDestroyImageView(device, imageView, pAllocator, record_obj);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreateDescriptorSetLayout(VkDevice device,
                                                                             const VkDescriptorSetLayoutCreateInfo *pCreateInfo,
                                                                             const VkAllocationCallbacks *pAllocator,
                                                                             VkDescriptorSetLayout *pSetLayout,
                                                                             const RecordObject &record_obj) {
    BASE::PostCallRecordCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.descriptor_set_layout_bindings.fetch_add(pCreateInfo->bindingCount);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PreCallRecordDestroyDescriptorSetLayout(VkDevice device,
                                                                             VkDescriptorSetLayout descriptorSetLayout,
                                                                             const VkAllocationCallbacks *pAllocator,
                                                                             const RecordObject &record_obj) {
    auto set_layout_state = Get<vvl::DescriptorSetLayout>(descriptorSetLayout);
    if (set_layout_state) {
        sc_reserved_objects_.descriptor_set_layout_bindings.fetch_sub(set_layout_state->GetBindingCount());
    }

    BASE::PreCallRecordDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator, record_obj);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo *pCreateInfo,
                                                                    const VkAllocationCallbacks *pAllocator,
                                                                    VkRenderPass *pRenderPass, const RecordObject &record_obj) {
    BASE::PostCallRecordCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.subpass_descriptions.fetch_add(pCreateInfo->subpassCount);
    sc_reserved_objects_.attachment_descriptions.fetch_add(pCreateInfo->attachmentCount);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2 *pCreateInfo,
                                                                     const VkAllocationCallbacks *pAllocator,
                                                                     VkRenderPass *pRenderPass, const RecordObject &record_obj) {
    BASE::PostCallRecordCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.subpass_descriptions.fetch_add(pCreateInfo->subpassCount);
    sc_reserved_objects_.attachment_descriptions.fetch_add(pCreateInfo->attachmentCount);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PreCallRecordDestroyRenderPass(VkDevice device, VkRenderPass renderPass,
                                                                    const VkAllocationCallbacks *pAllocator,
                                                                    const RecordObject &record_obj) {
    auto rp_state = Get<vvl::RenderPass>(renderPass);
    if (rp_state) {
        sc_reserved_objects_.subpass_descriptions.fetch_sub(rp_state->create_info.subpassCount);
        sc_reserved_objects_.attachment_descriptions.fetch_sub(rp_state->create_info.attachmentCount);
    }

    BASE::PreCallRecordDestroyRenderPass(device, renderPass, pAllocator, record_obj);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordCreatePrivateDataSlotEXT(VkDevice device,
                                                                            const VkPrivateDataSlotCreateInfo *pCreateInfo,
                                                                            const VkAllocationCallbacks *pAllocator,
                                                                            VkPrivateDataSlot *pPrivateDataSlot,
                                                                            const RecordObject &record_obj) {
    BASE::PostCallRecordCreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    sc_reserved_objects_.private_data_slots++;
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PreCallRecordDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                                            const VkAllocationCallbacks *pAllocator,
                                                                            const RecordObject &record_obj) {
    if (privateDataSlot != VK_NULL_HANDLE) {
        sc_reserved_objects_.private_data_slots--;
    }

    BASE::PreCallRecordDestroyPrivateDataSlotEXT(device, privateDataSlot, pAllocator, record_obj);
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PostCallRecordBeginCommandBuffer(VkCommandBuffer commandBuffer,
                                                                      const VkCommandBufferBeginInfo *pBeginInfo,
                                                                      const RecordObject &record_obj) {
    BASE::PostCallRecordBeginCommandBuffer(commandBuffer, pBeginInfo, record_obj);
    if (VK_SUCCESS != record_obj.result) return;

    auto cb_state = Get<vvl::CommandBuffer>(commandBuffer);
    if (cb_state) {
        auto cp_state = Get<vvl::sc::CommandPool>(cb_state->command_pool->VkHandle());
        cp_state->command_buffers_recording++;
    }
}

template <typename BASE>
void SCValidationStateTracker<BASE>::PreCallRecordEndCommandBuffer(VkCommandBuffer commandBuffer, const RecordObject &record_obj) {
    auto cb_state = Get<vvl::CommandBuffer>(commandBuffer);
    if (cb_state) {
        auto cp_state = Get<vvl::sc::CommandPool>(cb_state->command_pool->VkHandle());
        cp_state->command_buffers_recording--;
    }

    BASE::PreCallRecordEndCommandBuffer(commandBuffer, record_obj);
}
