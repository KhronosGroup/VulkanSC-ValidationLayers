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
#include "generated/chassis.h"
#include "error_message/validation_error_enums.h"
#include "state_tracker/state_tracker.h"
#include "vulkansc/state_tracker/sc_device_state.h"
#include "vulkansc/state_tracker/sc_pipeline_state.h"
#include "vulkansc/state_tracker/sc_cmd_buffer_state.h"
#include "generated/layer_chassis_dispatch.h"
#include "error_message/logging.h"
#include "vulkan/vk_layer.h"

#include <atomic>

VALSTATETRACK_DERIVED_STATE_OBJECT(VkPipelineCache, vvl::sc::PipelineCache, vvl::PipelineCache);
VALSTATETRACK_DERIVED_STATE_OBJECT(VkPipeline, vvl::sc::Pipeline, vvl::Pipeline);
VALSTATETRACK_DERIVED_STATE_OBJECT(VkCommandPool, vvl::sc::CommandPool, vvl::CommandPool);

template <typename BASE>
class SCValidationStateTracker : public BASE {
  public:
    template <typename State, typename HandleType = typename state_object::Traits<State>::HandleType>
    void Add(std::shared_ptr<State>&& state_object) {
        BASE::template Add<State, HandleType>(std::move(state_object));
    }

    template <typename State, typename Traits = typename state_object::Traits<State>>
    void Destroy(typename Traits::HandleType handle) {
        BASE::template Destroy<State, Traits>(handle);
    }

    template <typename State, typename Traits = typename state_object::Traits<State>>
    typename Traits::SharedType Get(typename Traits::HandleType handle) {
        return BASE::template Get<State, Traits>(handle);
    }

    template <typename State, typename Traits = typename state_object::Traits<State>>
    typename Traits::ConstSharedType Get(typename Traits::HandleType handle) const {
        return BASE::template Get<State, Traits>(handle);
    }

    template <typename State, typename Traits = typename state_object::Traits<State>,
              typename ReadLockedType = typename Traits::ReadLockedType>
    ReadLockedType GetRead(typename Traits::HandleType handle) const {
        return BASE::template GetRead<State, Traits, ReadLockedType>(handle);
    }

    template <typename State, typename Traits = state_object::Traits<State>,
              typename WriteLockedType = typename Traits::WriteLockedType>
    WriteLockedType GetWrite(typename Traits::HandleType handle) {
        return BASE::template GetWrite<State, Traits, WriteLockedType>(handle);
    }

    template <typename CreateInfo>
    void ReservePipelinePoolEntries(uint32_t create_info_count, const CreateInfo* create_info);
    void RecyclePipelinePoolEntry(const VkPipelineOfflineCreateInfo* offline_info);

    // Functions requiring additional/modified state tracking for Vulkan SC
    void CreateDevice(const VkDeviceCreateInfo* pCreateInfo) override;
    virtual std::shared_ptr<vvl::CommandPool> CreateCommandPoolState(VkCommandPool command_pool,
                                                                     const VkCommandPoolCreateInfo* pCreateInfo) override;
    void PostCallRecordCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool,
                                         const RecordObject& record_obj) override;
    std::shared_ptr<vvl::PipelineCache> CreatePipelineCacheState(VkPipelineCache pipeline_cache,
                                                                 const VkPipelineCacheCreateInfo* pCreateInfo) const override;

    std::shared_ptr<vvl::Pipeline> CreateGraphicsPipelineState(const VkGraphicsPipelineCreateInfo* pCreateInfo,
                                                               std::shared_ptr<const vvl::RenderPass>&& render_pass,
                                                               std::shared_ptr<const vvl::PipelineLayout>&& layout,
                                                               CreateShaderModuleStates* csm_states) const override;
    std::shared_ptr<vvl::Pipeline> CreateComputePipelineState(const VkComputePipelineCreateInfo* pCreateInfo,
                                                              std::shared_ptr<const vvl::PipelineLayout>&& layout) const override;
    void PostCallRecordCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t count,
                                               const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                               const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                               const RecordObject& record_obj, void* cgpl_state) override;
    void PostCallRecordCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t count,
                                              const VkComputePipelineCreateInfo* pCreateInfos,
                                              const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                              const RecordObject& record_obj, void* pipe_state) override;
    void PreCallRecordDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator,
                                      const RecordObject& record_obj) override;
    void PostCallRecordCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator, VkImageView* pView,
                                       const RecordObject& record_obj) override;
    void PreCallRecordDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator,
                                       const RecordObject& record_obj) override;
    void PostCallRecordCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout,
                                                 const RecordObject& record_obj) override;
    void PreCallRecordDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout,
                                                 const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) override;
    void PostCallRecordCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                        const RecordObject& record_obj) override;
    void PostCallRecordCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                         const RecordObject& record_obj) override;
    void PreCallRecordDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator,
                                        const RecordObject& record_obj) override;
    void PostCallRecordCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot,
                                                const RecordObject& record_obj) override;
    void PreCallRecordDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) override;
    void PostCallRecordBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo,
                                          const RecordObject& record_obj) override;
    void PreCallRecordEndCommandBuffer(VkCommandBuffer commandBuffer, const RecordObject& record_obj) override;

  protected:
    // SC-specific features and properties
    SCDeviceFeatures enabled_sc_features_ = {};
    VkPhysicalDeviceVulkanSC10Properties phys_dev_props_sc_10_ = {};

    // Object reservation limits
    VkDeviceObjectReservationCreateInfo sc_object_limits_ = {};
    VkDevicePrivateDataCreateInfoEXT sc_private_data_slot_limits_ = {};
    VkPerformanceQueryReservationInfoKHR sc_perf_query_limits_ = {};

    // Pipeline cache and pool related states
    vvl::unordered_map<const void*, std::unique_ptr<vvl::sc::PipelineCacheData>> sc_pipeline_cache_map_ = {};
    vvl::unordered_map<VkDeviceSize, uint32_t> sc_pipeline_pool_size_map_ = {};
    mutable std::mutex sc_used_pipeline_pool_size_map_mutex_{};
    vvl::unordered_map<VkDeviceSize, uint32_t> sc_used_pipeline_pool_size_map_ = {};

    // Object / sub-object count tracking
    struct {
        std::atomic_uint32_t command_buffers{0};
        std::atomic_uint32_t graphics_pipelines{0};
        std::atomic_uint32_t compute_pipelines{0};
        std::atomic_uint32_t layered_image_views{0};
        std::atomic_uint32_t subpass_descriptions{0};
        std::atomic_uint32_t attachment_descriptions{0};
        std::atomic_uint32_t descriptor_set_layout_bindings{0};
        std::atomic_uint32_t private_data_slots{0};
    } sc_reserved_objects_{};
};
