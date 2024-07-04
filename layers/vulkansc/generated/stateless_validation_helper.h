// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See stateless_validation_helper_generator.py for modifications

/***************************************************************************
 *
 * Copyright (c) 2015-2024 The Khronos Group Inc.
 * Copyright (c) 2015-2024 Valve Corporation
 * Copyright (c) 2015-2024 LunarG, Inc.
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
 ****************************************************************************/

// NOLINTBEGIN
#pragma once

static inline bool IsDuplicatePnext(VkStructureType input_value) {
    switch (input_value) {
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
        case VK_STRUCTURE_TYPE_DEVICE_OBJECT_RESERVATION_CREATE_INFO:
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_RESERVATION_INFO_KHR:
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
        case VK_STRUCTURE_TYPE_APPLICATION_PARAMETERS_EXT:
        case VK_STRUCTURE_TYPE_DEVICE_SEMAPHORE_SCI_SYNC_POOL_RESERVATION_CREATE_INFO_NV:
            return true;
        default:
            return false;
    }
}

bool PreCallValidateCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                   VkInstance* pInstance, const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateEnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount,
                                             VkPhysicalDevice* pPhysicalDevices, const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures,
                                              const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                      VkFormatProperties* pFormatProperties,
                                                      const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type,
                                                           VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags,
                                                           VkImageFormatProperties* pImageFormatProperties,
                                                           const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties,
                                                const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount,
                                                           VkQueueFamilyProperties* pQueueFamilyProperties,
                                                           const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice,
                                                      VkPhysicalDeviceMemoryProperties* pMemoryProperties,
                                                      const ErrorObject& error_obj) const override;
bool PreCallValidateCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                 const VkAllocationCallbacks* pAllocator, VkDevice* pDevice,
                                 const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator,
                                  const ErrorObject& error_obj) const override;
bool PreCallValidateGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue,
                                   const ErrorObject& error_obj) const override;
bool PreCallValidateQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence,
                                const ErrorObject& error_obj) const override;
bool PreCallValidateQueueWaitIdle(VkQueue queue, const ErrorObject& error_obj) const override;
bool PreCallValidateDeviceWaitIdle(VkDevice device, const ErrorObject& error_obj) const override;
bool PreCallValidateAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                   const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory,
                                   const ErrorObject& error_obj) const override;
bool PreCallValidateMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size,
                              VkMemoryMapFlags flags, void** ppData, const ErrorObject& error_obj) const override;
bool PreCallValidateUnmapMemory(VkDevice device, VkDeviceMemory memory, const ErrorObject& error_obj) const override;
bool PreCallValidateFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges,
                                            const ErrorObject& error_obj) const override;
bool PreCallValidateInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                 const VkMappedMemoryRange* pMemoryRanges,
                                                 const ErrorObject& error_obj) const override;
bool PreCallValidateGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes,
                                              const ErrorObject& error_obj) const override;
bool PreCallValidateBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements,
                                                const ErrorObject& error_obj) const override;
bool PreCallValidateGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements,
                                               const ErrorObject& error_obj) const override;
bool PreCallValidateCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                VkFence* pFence, const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator,
                                 const ErrorObject& error_obj) const override;
bool PreCallValidateResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences,
                                const ErrorObject& error_obj) const override;
bool PreCallValidateGetFenceStatus(VkDevice device, VkFence fence, const ErrorObject& error_obj) const override;
bool PreCallValidateWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout,
                                  const ErrorObject& error_obj) const override;
bool PreCallValidateCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                    const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                VkEvent* pEvent, const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator,
                                 const ErrorObject& error_obj) const override;
bool PreCallValidateGetEventStatus(VkDevice device, VkEvent event, const ErrorObject& error_obj) const override;
bool PreCallValidateSetEvent(VkDevice device, VkEvent event, const ErrorObject& error_obj) const override;
bool PreCallValidateResetEvent(VkDevice device, VkEvent event, const ErrorObject& error_obj) const override;
bool PreCallValidateCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo,
                                    const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount,
                                        size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags,
                                        const ErrorObject& error_obj) const override;
bool PreCallValidateCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                 VkBuffer* pBuffer, const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator,
                                  const ErrorObject& error_obj) const override;
bool PreCallValidateCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                     const VkAllocationCallbacks* pAllocator, VkBufferView* pView,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                VkImage* pImage, const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator,
                                 const ErrorObject& error_obj) const override;
bool PreCallValidateGetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource,
                                              VkSubresourceLayout* pLayout, const ErrorObject& error_obj) const override;
bool PreCallValidateCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                    const VkAllocationCallbacks* pAllocator, VkImageView* pView,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache,
                                        const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                            const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                            const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                            const ErrorObject& error_obj) const override;
bool PreCallValidateCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                           const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator,
                                           VkPipeline* pPipelines, const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator,
                                          const ErrorObject& error_obj) const override;
bool PreCallValidateCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                  VkSampler* pSampler, const ErrorObject& error_obj) const override;
bool PreCallValidateDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator,
                                   const ErrorObject& error_obj) const override;
bool PreCallValidateCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout,
                                              const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout,
                                               const VkAllocationCallbacks* pAllocator,
                                               const ErrorObject& error_obj) const override;
bool PreCallValidateCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags,
                                        const ErrorObject& error_obj) const override;
bool PreCallValidateAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                           VkDescriptorSet* pDescriptorSets, const ErrorObject& error_obj) const override;
bool PreCallValidateFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount,
                                       const VkDescriptorSet* pDescriptorSets, const ErrorObject& error_obj) const override;
bool PreCallValidateUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount,
                                         const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount,
                                         const VkCopyDescriptorSet* pDescriptorCopies, const ErrorObject& error_obj) const override;
bool PreCallValidateCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator,
                                       const ErrorObject& error_obj) const override;
bool PreCallValidateCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                     const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity,
                                             const ErrorObject& error_obj) const override;
bool PreCallValidateCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                           VkCommandBuffer* pCommandBuffers, const ErrorObject& error_obj) const override;
bool PreCallValidateFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                       const VkCommandBuffer* pCommandBuffers, const ErrorObject& error_obj) const override;
bool PreCallValidateBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo,
                                       const ErrorObject& error_obj) const override;
bool PreCallValidateEndCommandBuffer(VkCommandBuffer commandBuffer, const ErrorObject& error_obj) const override;
bool PreCallValidateResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags,
                                       const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                   const VkViewport* pViewports, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                  const VkRect2D* pScissors, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                                    float depthBiasSlopeFactor, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4],
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask,
                                             const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask,
                                           const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference,
                                           const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                          VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                          const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                          const uint32_t* pDynamicOffsets, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType,
                                       const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                         const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex,
                            uint32_t firstInstance, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex,
                                   int32_t vertexOffset, uint32_t firstInstance, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                                    uint32_t stride, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                                           uint32_t stride, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ,
                                const ErrorObject& error_obj) const override;
bool PreCallValidateCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount,
                                  const VkBufferCopy* pRegions, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                                 VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions,
                                 const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                                 VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter,
                                 const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                         VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                         VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                    VkDeviceSize dataSize, const void* pData, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size,
                                  uint32_t data, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                       const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges,
                                       const ErrorObject& error_obj) const override;
bool PreCallValidateCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                              const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                              const VkImageSubresourceRange* pRanges, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                        const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects,
                                        const ErrorObject& error_obj) const override;
bool PreCallValidateCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                                    VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask,
                                const ErrorObject& error_obj) const override;
bool PreCallValidateCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask,
                                  const ErrorObject& error_obj) const override;
bool PreCallValidateCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                  VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount,
                                  const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount,
                                  const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount,
                                  const VkImageMemoryBarrier* pImageMemoryBarriers, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                       VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                       uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                       uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                       uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers,
                                       const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags,
                                  const ErrorObject& error_obj) const override;
bool PreCallValidateCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                const ErrorObject& error_obj) const override;
bool PreCallValidateCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                      uint32_t queryCount, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool,
                                      uint32_t query, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                            uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride,
                                            VkQueryResultFlags flags, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                                     uint32_t offset, uint32_t size, const void* pValues,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                       VkSubpassContents contents, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents,
                                   const ErrorObject& error_obj) const override;
bool PreCallValidateCmdEndRenderPass(VkCommandBuffer commandBuffer, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                       const VkCommandBuffer* pCommandBuffers, const ErrorObject& error_obj) const override;
bool PreCallValidateBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                                     uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures,
                                                     const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ,
                                    uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateEnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount,
                                                  VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties,
                                                  const ErrorObject& error_obj) const override;
bool PreCallValidateGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo,
                                                VkMemoryRequirements2* pMemoryRequirements,
                                                const ErrorObject& error_obj) const override;
bool PreCallValidateGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo,
                                                 VkMemoryRequirements2* pMemoryRequirements,
                                                 const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures,
                                               const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties,
                                                 const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format,
                                                       VkFormatProperties2* pFormatProperties,
                                                       const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice,
                                                            const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
                                                            VkImageFormatProperties2* pImageFormatProperties,
                                                            const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount,
                                                            VkQueueFamilyProperties2* pQueueFamilyProperties,
                                                            const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice,
                                                       VkPhysicalDeviceMemoryProperties2* pMemoryProperties,
                                                       const ErrorObject& error_obj) const override;
bool PreCallValidateGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator,
                                                 VkSamplerYcbcrConversion* pYcbcrConversion,
                                                 const ErrorObject& error_obj) const override;
bool PreCallValidateDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion,
                                                  const VkAllocationCallbacks* pAllocator,
                                                  const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice,
                                                              const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
                                                              VkExternalBufferProperties* pExternalBufferProperties,
                                                              const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice,
                                                             const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
                                                             VkExternalFenceProperties* pExternalFenceProperties,
                                                             const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties* pExternalSemaphoreProperties, const ErrorObject& error_obj) const override;
bool PreCallValidateGetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                  VkDescriptorSetLayoutSupport* pSupport,
                                                  const ErrorObject& error_obj) const override;
bool PreCallValidateCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer,
                                         VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                uint32_t stride, const ErrorObject& error_obj) const override;
bool PreCallValidateCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                        const VkSubpassBeginInfo* pSubpassBeginInfo, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                    const VkSubpassEndInfo* pSubpassEndInfo, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount,
                                   const ErrorObject& error_obj) const override;
bool PreCallValidateGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue,
                                             const ErrorObject& error_obj) const override;
bool PreCallValidateWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout,
                                   const ErrorObject& error_obj) const override;
bool PreCallValidateSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo,
                                           const ErrorObject& error_obj) const override;
bool PreCallValidateGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo,
                                                  const ErrorObject& error_obj) const override;
bool PreCallValidateGetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo,
                                                        const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount,
                                                    VkPhysicalDeviceToolProperties* pToolProperties,
                                                    const ErrorObject& error_obj) const override;
bool PreCallValidateCreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo,
                                          const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot,
                                          const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                           const VkAllocationCallbacks* pAllocator, const ErrorObject& error_obj) const override;
bool PreCallValidateSetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle,
                                   VkPrivateDataSlot privateDataSlot, uint64_t data, const ErrorObject& error_obj) const override;
bool PreCallValidateGetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle,
                                   VkPrivateDataSlot privateDataSlot, uint64_t* pData, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo,
                                 const ErrorObject& error_obj) const override;
bool PreCallValidateCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask,
                                   const ErrorObject& error_obj) const override;
bool PreCallValidateCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                   const VkDependencyInfo* pDependencyInfos, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo,
                                        const ErrorObject& error_obj) const override;
bool PreCallValidateCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                       uint32_t query, const ErrorObject& error_obj) const override;
bool PreCallValidateQueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence,
                                 const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo,
                                   const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo,
                                  const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo,
                                          const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo,
                                          const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo,
                                  const ErrorObject& error_obj) const override;
bool PreCallValidateCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateCmdEndRendering(VkCommandBuffer commandBuffer, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode,
                                   const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology,
                                            const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports,
                                            const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors,
                                           const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                          const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                          const VkDeviceSize* pStrides, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable,
                                          const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable,
                                           const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable,
                                                const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable,
                                            const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                    VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable,
                                                  const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable,
                                          const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable,
                                                 const ErrorObject& error_obj) const override;
bool PreCallValidateGetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo,
                                                      VkMemoryRequirements2* pMemoryRequirements,
                                                      const ErrorObject& error_obj) const override;
bool PreCallValidateGetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo,
                                                     VkMemoryRequirements2* pMemoryRequirements,
                                                     const ErrorObject& error_obj) const override;
bool PreCallValidateGetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo,
                                                           uint32_t* pSparseMemoryRequirementCount,
                                                           VkSparseImageMemoryRequirements2* pSparseMemoryRequirements,
                                                           const ErrorObject& error_obj) const override;
bool PreCallValidateGetCommandPoolMemoryConsumption(VkDevice device, VkCommandPool commandPool, VkCommandBuffer commandBuffer,
                                                    VkCommandPoolMemoryConsumption* pConsumption,
                                                    const ErrorObject& error_obj) const override;
bool PreCallValidateGetFaultData(VkDevice device, VkFaultQueryBehavior faultQueryBehavior, VkBool32* pUnrecordedFaults,
                                 uint32_t* pFaultCount, VkFaultData* pFaults, const ErrorObject& error_obj) const override;
bool PreCallValidateDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex,
                                                       VkSurfaceKHR surface, VkBool32* pSupported,
                                                       const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                            VkSurfaceCapabilitiesKHR* pSurfaceCapabilities,
                                                            const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                       uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats,
                                                       const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                            uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes,
                                                            const ErrorObject& error_obj) const override;
bool PreCallValidateCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain,
                                       const ErrorObject& error_obj) const override;
bool PreCallValidateGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount,
                                          VkImage* pSwapchainImages, const ErrorObject& error_obj) const override;
bool PreCallValidateAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore,
                                        VkFence fence, uint32_t* pImageIndex, const ErrorObject& error_obj) const override;
bool PreCallValidateQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateGetDeviceGroupPresentCapabilitiesKHR(VkDevice device,
                                                         VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities,
                                                         const ErrorObject& error_obj) const override;
bool PreCallValidateGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface,
                                                         VkDeviceGroupPresentModeFlagsKHR* pModes,
                                                         const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                          uint32_t* pRectCount, VkRect2D* pRects,
                                                          const ErrorObject& error_obj) const override;
bool PreCallValidateAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                          VkDisplayPropertiesKHR* pProperties,
                                                          const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                               VkDisplayPlanePropertiesKHR* pProperties,
                                                               const ErrorObject& error_obj) const override;
bool PreCallValidateGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex,
                                                        uint32_t* pDisplayCount, VkDisplayKHR* pDisplays,
                                                        const ErrorObject& error_obj) const override;
bool PreCallValidateGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount,
                                                VkDisplayModePropertiesKHR* pProperties,
                                                const ErrorObject& error_obj) const override;
bool PreCallValidateCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                         const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                         VkDisplayModeKHR* pMode, const ErrorObject& error_obj) const override;
bool PreCallValidateGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex,
                                                   VkDisplayPlaneCapabilitiesKHR* pCapabilities,
                                                   const ErrorObject& error_obj) const override;
bool PreCallValidateCreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                 const ErrorObject& error_obj) const override;
bool PreCallValidateCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                              const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator,
                                              VkSwapchainKHR* pSwapchains, const ErrorObject& error_obj) const override;
bool PreCallValidateGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd,
                                   const ErrorObject& error_obj) const override;
bool PreCallValidateGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd,
                                             VkMemoryFdPropertiesKHR* pMemoryFdProperties,
                                             const ErrorObject& error_obj) const override;
bool PreCallValidateImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain, const ErrorObject& error_obj) const override;
bool PreCallValidateImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd,
                                  const ErrorObject& error_obj) const override;
bool PreCallValidateEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters,
    VkPerformanceCounterDescriptionKHR* pCounterDescriptions, const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses,
    const ErrorObject& error_obj) const override;
bool PreCallValidateAcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo,
                                            const ErrorObject& error_obj) const override;
bool PreCallValidateReleaseProfilingLockKHR(VkDevice device, const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice,
                                                             const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                             VkSurfaceCapabilities2KHR* pSurfaceCapabilities,
                                                             const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice,
                                                        const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                        uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats,
                                                        const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                           VkDisplayProperties2KHR* pProperties,
                                                           const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                                VkDisplayPlaneProperties2KHR* pProperties,
                                                                const ErrorObject& error_obj) const override;
bool PreCallValidateGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount,
                                                 VkDisplayModeProperties2KHR* pProperties,
                                                 const ErrorObject& error_obj) const override;
bool PreCallValidateGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice,
                                                    const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo,
                                                    VkDisplayPlaneCapabilities2KHR* pCapabilities,
                                                    const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount,
                                                             VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates,
                                                             const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                                 const VkFragmentShadingRateCombinerOpKHR combinerOps[2],
                                                 const ErrorObject& error_obj) const override;
bool PreCallValidateCmdRefreshObjectsKHR(VkCommandBuffer commandBuffer, const VkRefreshObjectListKHR* pRefreshObjects,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceRefreshableObjectTypesKHR(VkPhysicalDevice physicalDevice,
                                                               uint32_t* pRefreshableObjectTypeCount,
                                                               VkObjectType* pRefreshableObjectTypes,
                                                               const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                      const VkDependencyInfo* pDependencyInfos, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo,
                                           const ErrorObject& error_obj) const override;
bool PreCallValidateCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                          uint32_t query, const ErrorObject& error_obj) const override;
bool PreCallValidateQueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence,
                                    const ErrorObject& error_obj) const override;
bool PreCallValidateCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer,
                                             VkDeviceSize dstOffset, uint32_t marker, const ErrorObject& error_obj) const override;
bool PreCallValidateGetQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData,
                                              const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo,
                                             const ErrorObject& error_obj) const override;
bool PreCallValidateCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo,
                                             const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo,
                                     const ErrorObject& error_obj) const override;
bool PreCallValidateCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo,
                                        const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount,
                                                                 VkTimeDomainKHR* pTimeDomains,
                                                                 const ErrorObject& error_obj) const override;
bool PreCallValidateGetCalibratedTimestampsKHR(VkDevice device, uint32_t timestampCount,
                                               const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps,
                                               uint64_t* pMaxDeviation, const ErrorObject& error_obj) const override;
bool PreCallValidateReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                             VkSurfaceCapabilities2EXT* pSurfaceCapabilities,
                                                             const ErrorObject& error_obj) const override;
bool PreCallValidateDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo,
                                           const ErrorObject& error_obj) const override;
bool PreCallValidateRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo,
                                           const VkAllocationCallbacks* pAllocator, VkFence* pFence,
                                           const ErrorObject& error_obj) const override;
bool PreCallValidateRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo,
                                            const VkAllocationCallbacks* pAllocator, VkFence* pFence,
                                            const ErrorObject& error_obj) const override;
bool PreCallValidateGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter,
                                           uint64_t* pCounterValue, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                              uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles,
                                              const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable,
                                                    const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode,
                                                  const ErrorObject& error_obj) const override;
bool PreCallValidateSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains,
                                      const VkHdrMetadataEXT* pMetadata, const ErrorObject& error_obj) const override;
bool PreCallValidateSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo,
                                               const ErrorObject& error_obj) const override;
bool PreCallValidateSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo,
                                              const ErrorObject& error_obj) const override;
bool PreCallValidateQueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo,
                                                 const ErrorObject& error_obj) const override;
bool PreCallValidateQueueEndDebugUtilsLabelEXT(VkQueue queue, const ErrorObject& error_obj) const override;
bool PreCallValidateQueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo,
                                                  const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo,
                                               const ErrorObject& error_obj) const override;
bool PreCallValidateCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo,
                                                const ErrorObject& error_obj) const override;
bool PreCallValidateCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger,
                                                 const ErrorObject& error_obj) const override;
bool PreCallValidateDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                                  const VkAllocationCallbacks* pAllocator,
                                                  const ErrorObject& error_obj) const override;
bool PreCallValidateSubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                               VkDebugUtilsMessageTypeFlagsEXT messageTypes,
                                               const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                               const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo,
                                             const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples,
                                                              VkMultisamplePropertiesEXT* pMultisampleProperties,
                                                              const ErrorObject& error_obj) const override;
bool PreCallValidateGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image,
                                                           VkImageDrmFormatModifierPropertiesEXT* pProperties,
                                                           const ErrorObject& error_obj) const override;
bool PreCallValidateGetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType,
                                                      const void* pHostPointer,
                                                      VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties,
                                                      const ErrorObject& error_obj) const override;
bool PreCallValidateCreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo,
                                             const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                             const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace,
                                       const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology,
                                               const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports,
                                               const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors,
                                              const ErrorObject& error_obj) const override;
bool PreCallValidateCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                             const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                             const VkDeviceSize* pStrides, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable,
                                             const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable,
                                              const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp,
                                            const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable,
                                                   const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable,
                                               const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                       VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp,
                                       const ErrorObject& error_obj) const override;
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool PreCallValidateAcquireWinrtDisplayNV(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                          const ErrorObject& error_obj) const override;
bool PreCallValidateGetWinrtDisplayNV(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay,
                                      const ErrorObject& error_obj) const override;
#endif  // VK_USE_PLATFORM_WIN32_KHR
bool PreCallValidateCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                         const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                         uint32_t vertexAttributeDescriptionCount,
                                         const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions,
                                         const ErrorObject& error_obj) const override;
#ifdef VK_USE_PLATFORM_SCI
bool PreCallValidateGetFenceSciSyncFenceNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo, void* pHandle,
                                           const ErrorObject& error_obj) const override;
bool PreCallValidateGetFenceSciSyncObjNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo, void* pHandle,
                                         const ErrorObject& error_obj) const override;
bool PreCallValidateImportFenceSciSyncFenceNV(VkDevice device, const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo,
                                              const ErrorObject& error_obj) const override;
bool PreCallValidateImportFenceSciSyncObjNV(VkDevice device, const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo,
                                            const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceSciSyncAttributesNV(VkPhysicalDevice physicalDevice,
                                                         const VkSciSyncAttributesInfoNV* pSciSyncAttributesInfo,
                                                         NvSciSyncAttrList pAttributes,
                                                         const ErrorObject& error_obj) const override;
bool PreCallValidateGetSemaphoreSciSyncObjNV(VkDevice device, const VkSemaphoreGetSciSyncInfoNV* pGetSciSyncInfo, void* pHandle,
                                             const ErrorObject& error_obj) const override;
bool PreCallValidateImportSemaphoreSciSyncObjNV(VkDevice device, const VkImportSemaphoreSciSyncInfoNV* pImportSemaphoreSciSyncInfo,
                                                const ErrorObject& error_obj) const override;
bool PreCallValidateGetMemorySciBufNV(VkDevice device, const VkMemoryGetSciBufInfoNV* pGetSciBufInfo, NvSciBufObj* pHandle,
                                      const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceExternalMemorySciBufPropertiesNV(VkPhysicalDevice physicalDevice,
                                                                      VkExternalMemoryHandleTypeFlagBits handleType,
                                                                      NvSciBufObj handle,
                                                                      VkMemorySciBufPropertiesNV* pMemorySciBufProperties,
                                                                      const ErrorObject& error_obj) const override;
bool PreCallValidateGetPhysicalDeviceSciBufAttributesNV(VkPhysicalDevice physicalDevice, NvSciBufAttrList pAttributes,
                                                        const ErrorObject& error_obj) const override;
#endif  // VK_USE_PLATFORM_SCI
bool PreCallValidateCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints,
                                                const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable,
                                                     const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable,
                                             const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp, const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable,
                                                    const ErrorObject& error_obj) const override;
bool PreCallValidateCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                              const VkBool32* pColorWriteEnables, const ErrorObject& error_obj) const override;
#ifdef VK_USE_PLATFORM_SCI
bool PreCallValidateCreateSemaphoreSciSyncPoolNV(VkDevice device, const VkSemaphoreSciSyncPoolCreateInfoNV* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkSemaphoreSciSyncPoolNV* pSemaphorePool,
                                                 const ErrorObject& error_obj) const override;
#endif  // VK_USE_PLATFORM_SCI
#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool PreCallValidateGetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer,
                                                 VkScreenBufferPropertiesQNX* pProperties,
                                                 const ErrorObject& error_obj) const override;
#endif  // VK_USE_PLATFORM_SCREEN_QNX
bool ValidatePipelineViewportStateCreateInfo(const VkPipelineViewportStateCreateInfo& info, const Location& loc) const;
bool ValidatePipelineTessellationStateCreateInfo(const VkPipelineTessellationStateCreateInfo& info, const Location& loc) const;
bool ValidatePipelineVertexInputStateCreateInfo(const VkPipelineVertexInputStateCreateInfo& info, const Location& loc) const;
bool ValidatePipelineMultisampleStateCreateInfo(const VkPipelineMultisampleStateCreateInfo& info, const Location& loc) const;
bool ValidatePipelineColorBlendStateCreateInfo(const VkPipelineColorBlendStateCreateInfo& info, const Location& loc) const;
bool ValidatePipelineDepthStencilStateCreateInfo(const VkPipelineDepthStencilStateCreateInfo& info, const Location& loc) const;
bool ValidatePipelineInputAssemblyStateCreateInfo(const VkPipelineInputAssemblyStateCreateInfo& info, const Location& loc) const;
bool ValidatePipelineRasterizationStateCreateInfo(const VkPipelineRasterizationStateCreateInfo& info, const Location& loc) const;
bool ValidateDescriptorAddressInfoEXT(const VkDescriptorAddressInfoEXT& info, const Location& loc) const;
// NOLINTEND
