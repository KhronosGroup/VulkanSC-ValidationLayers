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
#include "generated/chassis.h"
#include "state_tracker/state_tracker.h"
#include "vulkansc/state_tracker/sc_device_state.h"
#include "vulkansc/state_tracker/sc_pipeline_state.h"
#include "vulkansc/state_tracker/sc_cmd_buffer_state.h"
#include "vulkansc/state_tracker/sc_descriptor_sets.h"
#include "generated/layer_chassis_dispatch.h"
#include "error_message/logging.h"
#include "vulkan/vk_layer.h"

#include <atomic>

VALSTATETRACK_DERIVED_STATE_OBJECT(VkPipelineCache, vvl::sc::PipelineCache, vvl::PipelineCache);
VALSTATETRACK_DERIVED_STATE_OBJECT(VkPipeline, vvl::sc::Pipeline, vvl::Pipeline);
VALSTATETRACK_DERIVED_STATE_OBJECT(VkCommandPool, vvl::sc::CommandPool, vvl::CommandPool);
VALSTATETRACK_DERIVED_STATE_OBJECT(VkDescriptorPool, vvl::sc::DescriptorPool, vvl::DescriptorPool);

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
    void PostCreateDevice(const VkDeviceCreateInfo* pCreateInfo, const Location& loc) override;
    virtual std::shared_ptr<vvl::CommandPool> CreateCommandPoolState(VkCommandPool command_pool,
                                                                     const VkCommandPoolCreateInfo* pCreateInfo) override;
    void PostCallRecordCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool,
                                         const RecordObject& record_obj) override;
    void PostCallRecordAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                      const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory,
                                      const RecordObject& record_obj) override;
    std::shared_ptr<vvl::PipelineCache> CreatePipelineCacheState(VkPipelineCache pipeline_cache,
                                                                 const VkPipelineCacheCreateInfo* pCreateInfo) const override;
    void PostCallRecordCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache,
                                           const RecordObject& record_obj) override;
    void PreCallRecordDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator,
                                           const RecordObject& record_obj) override;
    std::shared_ptr<vvl::Pipeline> CreateGraphicsPipelineState(
        const VkGraphicsPipelineCreateInfo* create_info, std::shared_ptr<const vvl::PipelineCache> pipeline_cache,
        std::shared_ptr<const vvl::RenderPass>&& render_pass, std::shared_ptr<const vvl::PipelineLayout>&& layout,
        spirv::StatelessData stateless_data[kCommonMaxGraphicsShaderStages]) const override;
    std::shared_ptr<vvl::Pipeline> CreateComputePipelineState(const VkComputePipelineCreateInfo* create_info,
                                                              std::shared_ptr<const vvl::PipelineCache> pipeline_cache,
                                                              std::shared_ptr<const vvl::PipelineLayout>&& layout,
                                                              spirv::StatelessData* stateless_data) const override;
    void PostCallRecordCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t count,
                                               const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                               const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                               const RecordObject& record_obj, PipelineStates& pipeline_states,
                                               chassis::CreateGraphicsPipelines& chassis_state) override;
    void PostCallRecordCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t count,
                                              const VkComputePipelineCreateInfo* pCreateInfos,
                                              const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                              const RecordObject& record_obj, PipelineStates& pipeline_states,
                                              chassis::CreateComputePipelines& chassis_state) override;
    void PreCallRecordDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator,
                                      const RecordObject& record_obj) override;
    void PostCallRecordCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                    VkBuffer* pBuffer, const RecordObject& record_obj) override;
    void PreCallRecordDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator,
                                    const RecordObject& record_obj) override;
    void PostCallRecordCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator, VkBufferView* pView,
                                        const RecordObject& record_obj) override;
    void PreCallRecordDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator,
                                        const RecordObject& record_obj) override;
    void PostCallRecordCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                   VkImage* pImage, const RecordObject& record_obj) override;
    void PreCallRecordDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator,
                                   const RecordObject& record_obj) override;
    void PostCallRecordCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator, VkImageView* pView,
                                       const RecordObject& record_obj) override;
    void PreCallRecordDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator,
                                       const RecordObject& record_obj) override;
    void PostCallRecordCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo,
                                     const VkAllocationCallbacks* pAllocator, VkSampler* pSampler,
                                     const RecordObject& record_obj) override;
    void PreCallRecordDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator,
                                     const RecordObject& record_obj) override;
    void PostCallRecordCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator,
                                                    VkSamplerYcbcrConversion* pYcbcrConversion,
                                                    const RecordObject& record_obj) override;
    void PostCallRecordDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion,
                                                     const VkAllocationCallbacks* pAllocator,
                                                     const RecordObject& record_obj) override;
    void PostCallRecordCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo,
                                            const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout,
                                            const RecordObject& record_obj) override;
    void PreCallRecordDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout,
                                            const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) override;
    void PostCallRecordCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout,
                                                 const RecordObject& record_obj) override;
    void PreCallRecordDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout,
                                                 const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) override;
    std::shared_ptr<vvl::DescriptorPool> CreateDescriptorPoolState(VkDescriptorPool handle,
                                                                   const VkDescriptorPoolCreateInfo* create_info) override;
    void PostCallRecordCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo,
                                            const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool,
                                            const RecordObject& record_obj) override;
    void PostCallRecordResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags,
                                           const RecordObject& record_obj) override;
    void PostCallRecordAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                              VkDescriptorSet* pDescriptorSets, const RecordObject& record_obj,
                                              vvl::AllocateDescriptorSetsData& ads_state) override;
    void PreCallRecordFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t count,
                                         const VkDescriptorSet* pDescriptorSets, const RecordObject& record_obj) override;
    void PostCallRecordCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                        const RecordObject& record_obj) override;
    void PostCallRecordCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                         const RecordObject& record_obj) override;
    void PreCallRecordDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator,
                                        const RecordObject& record_obj) override;
    void PostCallRecordCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer,
                                         const RecordObject& record_obj) override;
    void PreCallRecordDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator,
                                         const RecordObject& record_obj) override;
    void PostCallRecordCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                   VkFence* pFence, const RecordObject& record_obj) override;
    void PreCallRecordDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator,
                                   const RecordObject& record_obj) override;
    void PostCallRecordCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore,
                                       const RecordObject& record_obj) override;
    void PreCallRecordDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator,
                                       const RecordObject& record_obj) override;
    void PostCallRecordCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                   VkEvent* pEvent, const RecordObject& record_obj) override;
    void PreCallRecordDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator,
                                   const RecordObject& record_obj) override;
    void PostCallRecordCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool,
                                       const RecordObject& record_obj) override;
    void PostCallRecordCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot,
                                                const RecordObject& record_obj) override;
    void PreCallRecordDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) override;
    void PostCallRecordCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                                 const VkSwapchainCreateInfoKHR* pCreateInfos,
                                                 const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains,
                                                 const RecordObject& record_obj) override;
    void PostCallRecordCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo,
                                          const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain,
                                          const RecordObject& record_obj) override;
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
        std::atomic_uint32_t semaphores{0};
        std::atomic_uint32_t command_buffers{0};
        std::atomic_uint32_t fences{0};
        std::atomic_uint32_t device_memories{0};
        std::atomic_uint32_t buffers{0};
        std::atomic_uint32_t images{0};
        std::atomic_uint32_t events{0};
        std::atomic_uint32_t query_pools{0};
        std::atomic_uint32_t buffer_views{0};
        std::atomic_uint32_t image_views{0};
        std::atomic_uint32_t layered_image_views{0};
        std::atomic_uint32_t pipeline_caches{0};
        std::atomic_uint32_t pipeline_layouts{0};
        std::atomic_uint32_t render_passes{0};
        std::atomic_uint32_t graphics_pipelines{0};
        std::atomic_uint32_t compute_pipelines{0};
        std::atomic_uint32_t descriptor_set_layouts{0};
        std::atomic_uint32_t samplers{0};
        std::atomic_uint32_t descriptor_pools{0};
        std::atomic_uint32_t descriptor_sets{0};
        std::atomic_uint32_t framebuffers{0};
        std::atomic_uint32_t command_pools{0};
        std::atomic_uint32_t sampler_ycbcr_conversions{0};
        std::atomic_uint32_t swapchains{0};
        std::atomic_uint32_t subpass_descriptions{0};
        std::atomic_uint32_t attachment_descriptions{0};
        std::atomic_uint32_t descriptor_set_layout_bindings{0};
        std::atomic_uint32_t private_data_slots{0};
    } sc_reserved_objects_{};
};
