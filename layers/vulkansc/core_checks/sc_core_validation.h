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

#include "core_checks/core_validation.h"
#include "vulkansc/state_tracker/sc_state_tracker.h"

class SCCoreChecks : public SCValidationStateTracker<CoreChecks> {
  protected:
    using BASE = SCValidationStateTracker<CoreChecks>;

    void InitFilters();

  public:
    using StateTracker = SCValidationStateTracker<CoreChecks>;

    SCCoreChecks() {}

    bool ValidateObjectRequestCount(VkDevice device, const char* cmd, const char* vuid, const char* object_name_plural,
                                    size_t existing_count, const char* requested_count_name, uint32_t requested_count,
                                    const char* create_count_name, uint32_t create_count) const;
    bool ValidateObjectRequestCount(VkDevice device, const char* cmd, const char* vuid, const char* object_name_plural,
                                    size_t existing_count, const char* requested_count_name, uint32_t requested_count,
                                    uint32_t create_count) const;
    bool ValidateCombinedRequestCount(VkDevice device, const char* cmd, const char* vuid, const char* parent_object_name,
                                      const char* object_name_plural, uint32_t existing_count, const char* requested_count_name,
                                      uint32_t requested_count, const char* create_count_name, uint32_t create_count) const;

    template <typename CreateInfo>
    bool ValidatePipelinePoolMemory(VkDevice device, const char* cmd, uint32_t create_info_count,
                                    const CreateInfo* create_info) const;

    template <typename VkHandle>
    bool ValidatePipelineCacheCreateInfo(VkHandle handle, const char* cmd, const VkPipelineCacheCreateInfo& create_info) const;
    bool ValidatePipelineCacheData(VkPhysicalDevice physicalDevice, const VkPipelineCacheCreateInfo& create_info,
                                   uint32_t index) const;

    // Functions removed in Vulkan SC
    template <typename VkHandle>
    bool ValidateRemovedCommand(VkHandle handle, const char* cmd) const;
    bool PreCallValidateCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) const override;
    bool PreCallValidateDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                            const VkAllocationCallbacks* pAllocator) const override;
    bool PreCallValidateMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount,
                                            const VkPipelineCache* pSrcCaches) const override;
    bool PreCallValidateGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize,
                                             void* pData) const override;
    bool PreCallValidateTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) const override;
    bool PreCallValidateTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) const override;
    bool PreCallValidateDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                           const VkAllocationCallbacks* pAllocator) const override;
    bool PreCallValidateDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool,
                                              const VkAllocationCallbacks* pAllocator) const override;
    bool PreCallValidateDestroyQueryPool(VkDevice device, VkQueryPool queryPool,
                                         const VkAllocationCallbacks* pAllocator) const override;
    bool PreCallValidateDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain,
                                            const VkAllocationCallbacks* pAllocator) const override;
    bool PreCallValidateFreeMemory(VkDevice device, VkDeviceMemory mem, const VkAllocationCallbacks* pAllocator) const override;
    bool PreCallValidateCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) const override;
    bool PreCallValidateCreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator,
                                                          VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) const override;
    bool PreCallValidateDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                        const VkAllocationCallbacks* pAllocator) const override;
    bool PreCallValidateDestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                           const VkAllocationCallbacks* pAllocator) const override;
    bool PreCallValidateUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet,
                                                        VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                        const void* pData) const override;
    bool PreCallValidateUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet,
                                                           VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                           const void* pData) const override;
    bool PreCallValidateGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                     VkImageType type, VkSampleCountFlagBits samples,
                                                                     VkImageUsageFlags usage, VkImageTiling tiling,
                                                                     uint32_t* pPropertyCount,
                                                                     VkSparseImageFormatProperties* pProperties) const override;
    bool PreCallValidateGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice,
                                                                      const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
                                                                      uint32_t* pPropertyCount,
                                                                      VkSparseImageFormatProperties2* pProperties) const override;
    bool PreCallValidateGetPhysicalDeviceSparseImageFormatProperties2KHR(
        VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount,
        VkSparseImageFormatProperties2* pProperties) const override;
    bool PreCallValidateGetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount,
                                                         VkSparseImageMemoryRequirements* pSparseMemoryRequirements) const override;
    bool PreCallValidateGetImageSparseMemoryRequirements2(
        VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) const override;
    bool PreCallValidateGetImageSparseMemoryRequirements2KHR(
        VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) const override;
    bool PreCallValidateQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo,
                                        VkFence fence) const override;

    // Validation utility functions overridden for Vulkan SC
    bool ValidateShaderModuleId(const PIPELINE_STATE& pipeline) const override;
    bool ValidatePipelineShaderStage(const PIPELINE_STATE& pipeline, const PipelineStageState& stage_state) const override;

    // Intercept instance creation to set up VUID filters
    void PreCallRecordCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                     VkInstance* pInstance) override;

    // Functions requiring additional/modified validation for Vulkan SC
    bool PreCallValidateCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                       VkInstance* pInstance) const override;
    bool PreCallValidateCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                     const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) const override;
    void CreateDevice(const VkDeviceCreateInfo* pCreateInfo) override;

    bool PreCallValidateCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                          const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) const override;
    bool PreCallValidateAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                               VkCommandBuffer* pCommandBuffers) const override;
    bool PreCallValidateCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator,
                                                  VkDescriptorSetLayout* pSetLayout) const override;
    bool PreCallValidateCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo,
                                             const VkAllocationCallbacks* pAllocator,
                                             VkPipelineLayout* pPipelineLayout) const override;
    bool PreCallValidateCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo,
                                             const VkAllocationCallbacks* pAllocator,
                                             VkDescriptorPool* pDescriptorPool) const override;
    bool PreCallValidateAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                               VkDescriptorSet* pDescriptorSets, void* ads_state) const override;
    bool PreCallValidateAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                       const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) const override;
    bool PreCallValidateCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t count,
                                               const VkComputePipelineCreateInfo* pCreateInfos,
                                               const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                               void* pipe_state) const override;
    bool PreCallValidateCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t count,
                                                const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                void* cgpl_state) const override;
    bool PreCallValidateCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                            const VkAllocationCallbacks* pAllocator,
                                            VkPipelineCache* pPipelineCache) const override;
    bool PreCallValidateCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) const override;
    bool PreCallValidateCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) const override;
    bool PreCallValidateCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                          const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) const override;
    bool PreCallValidateCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo,
                                          const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) const override;
    bool PreCallValidateCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo,
                                     const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) const override;
    bool PreCallValidateCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator, VkBufferView* pView) const override;
    bool PreCallValidateCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                    VkImage* pImage) const override;
    bool PreCallValidateCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator, VkImageView* pView) const override;
    bool PreCallValidateCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) const override;
    bool PreCallValidateCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator,
                                                     VkSamplerYcbcrConversion* pYcbcrConversion) const override;
    bool PreCallValidateCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                    VkFence* pFence) const override;
    bool PreCallValidateCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) const override;
    bool PreCallValidateCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                    VkEvent* pEvent) const override;
    bool PreCallValidateCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) const override;
    bool PreCallValidateCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                                  const VkSwapchainCreateInfoKHR* pCreateInfos,
                                                  const VkAllocationCallbacks* pAllocator,
                                                  VkSwapchainKHR* pSwapchains) const override;
    bool PreCallValidateBindImageMemory2(VkDevice device, uint32_t bindInfoCount,
                                         const VkBindImageMemoryInfo* pBindInfos) const override;

};  // Class SCCoreChecks
