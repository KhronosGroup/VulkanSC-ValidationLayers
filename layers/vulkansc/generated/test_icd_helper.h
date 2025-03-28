// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See test_icd_generator.py for modifications

/***************************************************************************
 *
 * Copyright (c) 2024-2025 LunarG, Inc.
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

#include <stdint.h>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vulkan/vulkan.h>

namespace icd {

// Map of instance extension name to version
static const std::unordered_map<std::string, uint32_t> instance_extension_map = {
    {VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_SURFACE_SPEC_VERSION},
    {VK_KHR_DISPLAY_EXTENSION_NAME, VK_KHR_DISPLAY_SPEC_VERSION},
    {VK_KHR_GET_SURFACE_CAPABILITIES_2_EXTENSION_NAME, VK_KHR_GET_SURFACE_CAPABILITIES_2_SPEC_VERSION},
    {VK_KHR_GET_DISPLAY_PROPERTIES_2_EXTENSION_NAME, VK_KHR_GET_DISPLAY_PROPERTIES_2_SPEC_VERSION},
    {VK_EXT_DIRECT_MODE_DISPLAY_EXTENSION_NAME, VK_EXT_DIRECT_MODE_DISPLAY_SPEC_VERSION},
    {VK_EXT_DISPLAY_SURFACE_COUNTER_EXTENSION_NAME, VK_EXT_DISPLAY_SURFACE_COUNTER_SPEC_VERSION},
    {VK_EXT_SWAPCHAIN_COLOR_SPACE_EXTENSION_NAME, VK_EXT_SWAPCHAIN_COLOR_SPACE_SPEC_VERSION},
    {VK_EXT_DEBUG_UTILS_EXTENSION_NAME, VK_EXT_DEBUG_UTILS_SPEC_VERSION},
    {VK_EXT_VALIDATION_FEATURES_EXTENSION_NAME, VK_EXT_VALIDATION_FEATURES_SPEC_VERSION},
    {VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME, VK_EXT_HEADLESS_SURFACE_SPEC_VERSION},
    {VK_EXT_APPLICATION_PARAMETERS_EXTENSION_NAME, VK_EXT_APPLICATION_PARAMETERS_SPEC_VERSION},
    {VK_EXT_LAYER_SETTINGS_EXTENSION_NAME, VK_EXT_LAYER_SETTINGS_SPEC_VERSION},
};

// Map of device extension name to version
static const std::unordered_map<std::string, uint32_t> device_extension_map = {
    {VK_KHR_SWAPCHAIN_EXTENSION_NAME, VK_KHR_SWAPCHAIN_SPEC_VERSION},
    {VK_KHR_DISPLAY_SWAPCHAIN_EXTENSION_NAME, VK_KHR_DISPLAY_SWAPCHAIN_SPEC_VERSION},
    {VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME, VK_KHR_EXTERNAL_MEMORY_FD_SPEC_VERSION},
    {VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME, VK_KHR_EXTERNAL_SEMAPHORE_FD_SPEC_VERSION},
    {VK_KHR_INCREMENTAL_PRESENT_EXTENSION_NAME, VK_KHR_INCREMENTAL_PRESENT_SPEC_VERSION},
    {VK_KHR_SHARED_PRESENTABLE_IMAGE_EXTENSION_NAME, VK_KHR_SHARED_PRESENTABLE_IMAGE_SPEC_VERSION},
    {VK_KHR_EXTERNAL_FENCE_FD_EXTENSION_NAME, VK_KHR_EXTERNAL_FENCE_FD_SPEC_VERSION},
    {VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME, VK_KHR_PERFORMANCE_QUERY_SPEC_VERSION},
    {VK_KHR_SHADER_CLOCK_EXTENSION_NAME, VK_KHR_SHADER_CLOCK_SPEC_VERSION},
    {VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME, VK_KHR_GLOBAL_PRIORITY_SPEC_VERSION},
    {VK_KHR_SWAPCHAIN_MUTABLE_FORMAT_EXTENSION_NAME, VK_KHR_SWAPCHAIN_MUTABLE_FORMAT_SPEC_VERSION},
    {VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME, VK_KHR_SHADER_TERMINATE_INVOCATION_SPEC_VERSION},
    {VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME, VK_KHR_FRAGMENT_SHADING_RATE_SPEC_VERSION},
    {VK_KHR_OBJECT_REFRESH_EXTENSION_NAME, VK_KHR_OBJECT_REFRESH_SPEC_VERSION},
    {VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME, VK_KHR_SYNCHRONIZATION_2_SPEC_VERSION},
    {VK_KHR_COPY_COMMANDS_2_EXTENSION_NAME, VK_KHR_COPY_COMMANDS_2_SPEC_VERSION},
    {VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME, VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION},
    {VK_KHR_INDEX_TYPE_UINT8_EXTENSION_NAME, VK_KHR_INDEX_TYPE_UINT8_SPEC_VERSION},
    {VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, VK_KHR_LINE_RASTERIZATION_SPEC_VERSION},
    {VK_KHR_CALIBRATED_TIMESTAMPS_EXTENSION_NAME, VK_KHR_CALIBRATED_TIMESTAMPS_SPEC_VERSION},
    {VK_EXT_DEPTH_RANGE_UNRESTRICTED_EXTENSION_NAME, VK_EXT_DEPTH_RANGE_UNRESTRICTED_SPEC_VERSION},
    {VK_NV_PRIVATE_VENDOR_INFO_EXTENSION_NAME, VK_NV_PRIVATE_VENDOR_INFO_SPEC_VERSION},
    {VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME, VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_SPEC_VERSION},
    {VK_EXT_ASTC_DECODE_MODE_EXTENSION_NAME, VK_EXT_ASTC_DECODE_MODE_SPEC_VERSION},
    {VK_EXT_DISPLAY_CONTROL_EXTENSION_NAME, VK_EXT_DISPLAY_CONTROL_SPEC_VERSION},
    {VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME, VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION},
    {VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME, VK_EXT_CONSERVATIVE_RASTERIZATION_SPEC_VERSION},
    {VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME, VK_EXT_DEPTH_CLIP_ENABLE_SPEC_VERSION},
    {VK_EXT_HDR_METADATA_EXTENSION_NAME, VK_EXT_HDR_METADATA_SPEC_VERSION},
    {VK_EXT_EXTERNAL_MEMORY_DMA_BUF_EXTENSION_NAME, VK_EXT_EXTERNAL_MEMORY_DMA_BUF_SPEC_VERSION},
    {VK_EXT_QUEUE_FAMILY_FOREIGN_EXTENSION_NAME, VK_EXT_QUEUE_FAMILY_FOREIGN_SPEC_VERSION},
    {VK_EXT_SHADER_STENCIL_EXPORT_EXTENSION_NAME, VK_EXT_SHADER_STENCIL_EXPORT_SPEC_VERSION},
    {VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME, VK_EXT_SAMPLE_LOCATIONS_SPEC_VERSION},
    {VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME, VK_EXT_BLEND_OPERATION_ADVANCED_SPEC_VERSION},
    {VK_EXT_POST_DEPTH_COVERAGE_EXTENSION_NAME, VK_EXT_POST_DEPTH_COVERAGE_SPEC_VERSION},
    {VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME, VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_SPEC_VERSION},
    {VK_EXT_FILTER_CUBIC_EXTENSION_NAME, VK_EXT_FILTER_CUBIC_SPEC_VERSION},
    {VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME, VK_EXT_EXTERNAL_MEMORY_HOST_SPEC_VERSION},
    {VK_EXT_PCI_BUS_INFO_EXTENSION_NAME, VK_EXT_PCI_BUS_INFO_SPEC_VERSION},
    {VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME, VK_EXT_SUBGROUP_SIZE_CONTROL_SPEC_VERSION},
    {VK_EXT_SHADER_IMAGE_ATOMIC_INT64_EXTENSION_NAME, VK_EXT_SHADER_IMAGE_ATOMIC_INT64_SPEC_VERSION},
    {VK_EXT_MEMORY_BUDGET_EXTENSION_NAME, VK_EXT_MEMORY_BUDGET_SPEC_VERSION},
    {VK_EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME, VK_EXT_FRAGMENT_SHADER_INTERLOCK_SPEC_VERSION},
    {VK_EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME, VK_EXT_YCBCR_IMAGE_ARRAYS_SPEC_VERSION},
    {VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME, VK_EXT_LINE_RASTERIZATION_SPEC_VERSION},
    {VK_EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME, VK_EXT_SHADER_ATOMIC_FLOAT_SPEC_VERSION},
    {VK_EXT_INDEX_TYPE_UINT8_EXTENSION_NAME, VK_EXT_INDEX_TYPE_UINT8_SPEC_VERSION},
    {VK_EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME, VK_EXT_EXTENDED_DYNAMIC_STATE_SPEC_VERSION},
    {VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME, VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_SPEC_VERSION},
    {VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME, VK_EXT_TEXEL_BUFFER_ALIGNMENT_SPEC_VERSION},
    {VK_EXT_ROBUSTNESS_2_EXTENSION_NAME, VK_EXT_ROBUSTNESS_2_SPEC_VERSION},
    {VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME, VK_EXT_CUSTOM_BORDER_COLOR_SPEC_VERSION},
    {VK_EXT_YCBCR_2PLANE_444_FORMATS_EXTENSION_NAME, VK_EXT_YCBCR_2PLANE_444_FORMATS_SPEC_VERSION},
    {VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME, VK_EXT_IMAGE_ROBUSTNESS_SPEC_VERSION},
    {VK_EXT_4444_FORMATS_EXTENSION_NAME, VK_EXT_4444_FORMATS_SPEC_VERSION},
#ifdef VK_USE_PLATFORM_WIN32_KHR
    {VK_NV_ACQUIRE_WINRT_DISPLAY_EXTENSION_NAME, VK_NV_ACQUIRE_WINRT_DISPLAY_SPEC_VERSION},
#endif  // VK_USE_PLATFORM_WIN32_KHR
    {VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME, VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_SPEC_VERSION},
#ifdef VK_USE_PLATFORM_SCI
    {VK_NV_EXTERNAL_SCI_SYNC_EXTENSION_NAME, VK_NV_EXTERNAL_SCI_SYNC_SPEC_VERSION},
    {VK_NV_EXTERNAL_MEMORY_SCI_BUF_EXTENSION_NAME, VK_NV_EXTERNAL_MEMORY_SCI_BUF_SPEC_VERSION},
#endif  // VK_USE_PLATFORM_SCI
    {VK_EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME, VK_EXT_EXTENDED_DYNAMIC_STATE_2_SPEC_VERSION},
    {VK_EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME, VK_EXT_COLOR_WRITE_ENABLE_SPEC_VERSION},
#ifdef VK_USE_PLATFORM_SCI
    {VK_NV_EXTERNAL_SCI_SYNC_2_EXTENSION_NAME, VK_NV_EXTERNAL_SCI_SYNC_2_SPEC_VERSION},
#endif  // VK_USE_PLATFORM_SCI
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    {VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_EXTENSION_NAME, VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_SPEC_VERSION},
#endif  // VK_USE_PLATFORM_SCREEN_QNX
};
static VKAPI_ATTR VkResult VKAPI_CALL CreateInstance(const VkInstanceCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
static VKAPI_ATTR void VKAPI_CALL DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount,
                                                               VkPhysicalDevice* pPhysicalDevices);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                    VkFormatProperties* pFormatProperties);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                             VkImageType type, VkImageTiling tiling,
                                                                             VkImageUsageFlags usage, VkImageCreateFlags flags,
                                                                             VkImageFormatProperties* pImageFormatProperties);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice,
                                                              VkPhysicalDeviceProperties* pProperties);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice,
                                                                         uint32_t* pQueueFamilyPropertyCount,
                                                                         VkQueueFamilyProperties* pQueueFamilyProperties);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice,
                                                                    VkPhysicalDeviceMemoryProperties* pMemoryProperties);
static VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetInstanceProcAddr(VkInstance instance, const char* pName);
static VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetDeviceProcAddr(VkDevice device, const char* pName);
static VKAPI_ATTR VkResult VKAPI_CALL CreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkDevice* pDevice);
static VKAPI_ATTR void VKAPI_CALL DestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount,
                                                                           VkExtensionProperties* pProperties);
static VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName,
                                                                         uint32_t* pPropertyCount,
                                                                         VkExtensionProperties* pProperties);
static VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
static VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                                     VkLayerProperties* pProperties);
static VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
static VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
static VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle(VkQueue queue);
static VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle(VkDevice device);
static VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
static VKAPI_ATTR VkResult VKAPI_CALL MapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size,
                                                VkMemoryMapFlags flags, void** ppData);
static VKAPI_ATTR void VKAPI_CALL UnmapMemory(VkDevice device, VkDeviceMemory memory);
static VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                              const VkMappedMemoryRange* pMemoryRanges);
static VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                                   const VkMappedMemoryRange* pMemoryRanges);
static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory,
                                                            VkDeviceSize* pCommittedMemoryInBytes);
static VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory,
                                                       VkDeviceSize memoryOffset);
static VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory,
                                                      VkDeviceSize memoryOffset);
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements(VkDevice device, VkBuffer buffer,
                                                              VkMemoryRequirements* pMemoryRequirements);
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements(VkDevice device, VkImage image,
                                                             VkMemoryRequirements* pMemoryRequirements);
static VKAPI_ATTR VkResult VKAPI_CALL CreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkFence* pFence);
static VKAPI_ATTR void VKAPI_CALL DestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL ResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences);
static VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(VkDevice device, VkFence fence);
static VKAPI_ATTR VkResult VKAPI_CALL WaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll,
                                                    uint64_t timeout);
static VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
static VKAPI_ATTR void VKAPI_CALL DestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkEvent* pEvent);
static VKAPI_ATTR void VKAPI_CALL DestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(VkDevice device, VkEvent event);
static VKAPI_ATTR VkResult VKAPI_CALL SetEvent(VkDevice device, VkEvent event);
static VKAPI_ATTR VkResult VKAPI_CALL ResetEvent(VkDevice device, VkEvent event);
static VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);
static VKAPI_ATTR VkResult VKAPI_CALL GetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                                          uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride,
                                                          VkQueryResultFlags flags);
static VKAPI_ATTR VkResult VKAPI_CALL CreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
static VKAPI_ATTR void VKAPI_CALL DestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkBufferView* pView);
static VKAPI_ATTR void VKAPI_CALL DestroyBufferView(VkDevice device, VkBufferView bufferView,
                                                    const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL CreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkImage* pImage);
static VKAPI_ATTR void VKAPI_CALL DestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource,
                                                            VkSubresourceLayout* pLayout);
static VKAPI_ATTR VkResult VKAPI_CALL CreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkImageView* pView);
static VKAPI_ATTR void VKAPI_CALL DestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);
static VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache,
                                                       const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                              uint32_t createInfoCount,
                                                              const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                              const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
static VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                             uint32_t createInfoCount,
                                                             const VkComputePipelineCreateInfo* pCreateInfos,
                                                             const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
static VKAPI_ATTR void VKAPI_CALL DestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           VkPipelineLayout* pPipelineLayout);
static VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout,
                                                        const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkSampler* pSampler);
static VKAPI_ATTR void VKAPI_CALL DestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                                const VkAllocationCallbacks* pAllocator,
                                                                VkDescriptorSetLayout* pSetLayout);
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout,
                                                             const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           VkDescriptorPool* pDescriptorPool);
static VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool,
                                                          VkDescriptorPoolResetFlags flags);
static VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                                             VkDescriptorSet* pDescriptorSets);
static VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool,
                                                         uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);
static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount,
                                                       const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount,
                                                       const VkCopyDescriptorSet* pDescriptorCopies);
static VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
static VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer,
                                                     const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
static VKAPI_ATTR void VKAPI_CALL DestroyRenderPass(VkDevice device, VkRenderPass renderPass,
                                                    const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity);
static VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
static VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags);
static VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                                             VkCommandBuffer* pCommandBuffers);
static VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                                     const VkCommandBuffer* pCommandBuffers);
static VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
static VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer(VkCommandBuffer commandBuffer);
static VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);
static VKAPI_ATTR void VKAPI_CALL CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                  VkPipeline pipeline);
static VKAPI_ATTR void VKAPI_CALL CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                                 const VkViewport* pViewports);
static VKAPI_ATTR void VKAPI_CALL CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                                const VkRect2D* pScissors);
static VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth);
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor,
                                                  float depthBiasClamp, float depthBiasSlopeFactor);
static VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]);
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                           uint32_t compareMask);
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                         uint32_t writeMask);
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                         uint32_t reference);
static VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                        VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                                        const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                                        const uint32_t* pDynamicOffsets);
static VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                     VkIndexType indexType);
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                                       const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);
static VKAPI_ATTR void VKAPI_CALL CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                                          uint32_t firstVertex, uint32_t firstInstance);
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                                 uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                  uint32_t drawCount, uint32_t stride);
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                         uint32_t drawCount, uint32_t stride);
static VKAPI_ATTR void VKAPI_CALL CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                              uint32_t groupCountZ);
static VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                                uint32_t regionCount, const VkBufferCopy* pRegions);
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                               VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                               const VkImageCopy* pRegions);
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                               VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                               const VkImageBlit* pRegions, VkFilter filter);
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                                       VkImageLayout dstImageLayout, uint32_t regionCount,
                                                       const VkBufferImageCopy* pRegions);
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                       VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount,
                                                       const VkBufferImageCopy* pRegions);
static VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                  VkDeviceSize dataSize, const void* pData);
static VKAPI_ATTR void VKAPI_CALL CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                VkDeviceSize size, uint32_t data);
static VKAPI_ATTR void VKAPI_CALL CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                                     const VkClearColorValue* pColor, uint32_t rangeCount,
                                                     const VkImageSubresourceRange* pRanges);
static VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                                            const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                                            const VkImageSubresourceRange* pRanges);
static VKAPI_ATTR void VKAPI_CALL CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                      const VkClearAttachment* pAttachments, uint32_t rectCount,
                                                      const VkClearRect* pRects);
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                                  VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                                  const VkImageResolve* pRegions);
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                                VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                                                uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                                uint32_t bufferMemoryBarrierCount,
                                                const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                                uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                                     VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                                     uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                                     uint32_t bufferMemoryBarrierCount,
                                                     const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                                     uint32_t imageMemoryBarrierCount,
                                                     const VkImageMemoryBarrier* pImageMemoryBarriers);
static VKAPI_ATTR void VKAPI_CALL CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                                VkQueryControlFlags flags);
static VKAPI_ATTR void VKAPI_CALL CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);
static VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                                    uint32_t queryCount);
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                                    VkQueryPool queryPool, uint32_t query);
static VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                                          uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                          VkDeviceSize stride, VkQueryResultFlags flags);
static VKAPI_ATTR void VKAPI_CALL CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                                   VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                                   const void* pValues);
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                                     VkSubpassContents contents);
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents);
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(VkCommandBuffer commandBuffer);
static VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                                     const VkCommandBuffer* pCommandBuffers);
static VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceVersion(uint32_t* pApiVersion);
static VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(VkDevice device, uint32_t bindInfoCount,
                                                        const VkBindBufferMemoryInfo* pBindInfos);
static VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2(VkDevice device, uint32_t bindInfoCount,
                                                       const VkBindImageMemoryInfo* pBindInfos);
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                                                   uint32_t remoteDeviceIndex,
                                                                   VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
static VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask);
static VKAPI_ATTR void VKAPI_CALL CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                                  uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                                  uint32_t groupCountZ);
static VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(
    VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo,
                                                              VkMemoryRequirements2* pMemoryRequirements);
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo,
                                                               VkMemoryRequirements2* pMemoryRequirements);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice,
                                                               VkPhysicalDeviceProperties2* pProperties);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                     VkFormatProperties2* pFormatProperties);
static VKAPI_ATTR VkResult VKAPI_CALL
GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
                                        VkImageFormatProperties2* pImageFormatProperties);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice,
                                                                          uint32_t* pQueueFamilyPropertyCount,
                                                                          VkQueueFamilyProperties2* pQueueFamilyProperties);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice,
                                                                     VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
static VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue);
static VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion(VkDevice device,
                                                                   const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   VkSamplerYcbcrConversion* pYcbcrConversion);
static VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion,
                                                                const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
    VkExternalBufferProperties* pExternalBufferProperties);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
    VkExternalFenceProperties* pExternalFenceProperties);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties* pExternalSemaphoreProperties);
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                                VkDescriptorSetLayoutSupport* pSupport);
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                       VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                       uint32_t stride);
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                              VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                              uint32_t maxDrawCount, uint32_t stride);
static VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                                      const VkSubpassBeginInfo* pSubpassBeginInfo);
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                                  const VkSubpassEndInfo* pSubpassEndInfo);
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
static VKAPI_ATTR void VKAPI_CALL ResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue);
static VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);
static VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
static VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
static VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress(VkDevice device,
                                                                          const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount,
                                                                      VkPhysicalDeviceToolProperties* pToolProperties);
static VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            VkPrivateDataSlot* pPrivateDataSlot);
static VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                         const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL SetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle,
                                                     VkPrivateDataSlot privateDataSlot, uint64_t data);
static VKAPI_ATTR void VKAPI_CALL GetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle,
                                                 VkPrivateDataSlot privateDataSlot, uint64_t* pData);
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                               const VkDependencyInfo* pDependencyInfo);
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                                 const VkDependencyInfo* pDependencyInfos);
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                     VkQueryPool queryPool, uint32_t query);
static VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits,
                                                   VkFence fence);
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                                        const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                                        const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
static VKAPI_ATTR void VKAPI_CALL CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
static VKAPI_ATTR void VKAPI_CALL CmdEndRendering(VkCommandBuffer commandBuffer);
static VKAPI_ATTR void VKAPI_CALL CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace);
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                          const VkViewport* pViewports);
static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                         const VkRect2D* pScissors);
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                                        const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                                        const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                                  VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
static VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo,
                                                                    VkMemoryRequirements2* pMemoryRequirements);
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo,
                                                                   VkMemoryRequirements2* pMemoryRequirements);
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements(
    VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStipple(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                    uint16_t lineStipplePattern);
static VKAPI_ATTR VkResult VKAPI_CALL MapMemory2(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData);
static VKAPI_ATTR VkResult VKAPI_CALL UnmapMemory2(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo);
static VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer2(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                      VkDeviceSize size, VkIndexType indexType);
static VKAPI_ATTR void VKAPI_CALL GetRenderingAreaGranularity(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo,
                                                              VkExtent2D* pGranularity);
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSubresourceLayout(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo,
                                                                  VkSubresourceLayout2* pLayout);
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2(VkDevice device, VkImage image,
                                                             const VkImageSubresource2* pSubresource,
                                                             VkSubresourceLayout2* pLayout);
static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSet(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                       VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                                       const VkWriteDescriptorSet* pDescriptorWrites);
static VKAPI_ATTR void VKAPI_CALL CmdSetRenderingAttachmentLocations(VkCommandBuffer commandBuffer,
                                                                     const VkRenderingAttachmentLocationInfo* pLocationInfo);
static VKAPI_ATTR void VKAPI_CALL CmdSetRenderingInputAttachmentIndices(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo);
static VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets2(VkCommandBuffer commandBuffer,
                                                         const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo);
static VKAPI_ATTR void VKAPI_CALL CmdPushConstants2(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo);
static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSet2(VkCommandBuffer commandBuffer,
                                                        const VkPushDescriptorSetInfo* pPushDescriptorSetInfo);
static VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToImage(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo);
static VKAPI_ATTR VkResult VKAPI_CALL CopyImageToMemory(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo);
static VKAPI_ATTR VkResult VKAPI_CALL CopyImageToImage(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo);
static VKAPI_ATTR VkResult VKAPI_CALL TransitionImageLayout(VkDevice device, uint32_t transitionCount,
                                                            const VkHostImageLayoutTransitionInfo* pTransitions);
static VKAPI_ATTR void VKAPI_CALL GetCommandPoolMemoryConsumption(VkDevice device, VkCommandPool commandPool,
                                                                  VkCommandBuffer commandBuffer,
                                                                  VkCommandPoolMemoryConsumption* pConsumption);
static VKAPI_ATTR VkResult VKAPI_CALL GetFaultData(VkDevice device, VkFaultQueryBehavior faultQueryBehavior,
                                                   VkBool32* pUnrecordedFaults, uint32_t* pFaultCount, VkFaultData* pFaults);
static VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface,
                                                    const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex,
                                                                         VkSurfaceKHR surface, VkBool32* pSupported);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                              VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                         uint32_t* pSurfaceFormatCount,
                                                                         VkSurfaceFormatKHR* pSurfaceFormats);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                              uint32_t* pPresentModeCount,
                                                                              VkPresentModeKHR* pPresentModes);
static VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
static VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain,
                                                            uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
static VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout,
                                                          VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
static VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo);
static VKAPI_ATTR VkResult VKAPI_CALL
GetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities);
static VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface,
                                                                           VkDeviceGroupPresentModeFlagsKHR* pModes);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                            uint32_t* pRectCount, VkRect2D* pRects);
static VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo,
                                                           uint32_t* pImageIndex);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice,
                                                                            uint32_t* pPropertyCount,
                                                                            VkDisplayPropertiesKHR* pProperties);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice,
                                                                                 uint32_t* pPropertyCount,
                                                                                 VkDisplayPlanePropertiesKHR* pProperties);
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex,
                                                                          uint32_t* pDisplayCount, VkDisplayKHR* pDisplays);
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                                  uint32_t* pPropertyCount,
                                                                  VkDisplayModePropertiesKHR* pProperties);
static VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                           const VkDisplayModeCreateInfoKHR* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode);
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode,
                                                                     uint32_t planeIndex,
                                                                     VkDisplayPlaneCapabilitiesKHR* pCapabilities);
static VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR(VkInstance instance,
                                                                   const VkDisplaySurfaceCreateInfoKHR* pCreateInfo,
                                                                   const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
static VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                                                const VkSwapchainCreateInfoKHR* pCreateInfos,
                                                                const VkAllocationCallbacks* pAllocator,
                                                                VkSwapchainKHR* pSwapchains);
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd);
static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType,
                                                               int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties);
static VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR(VkDevice device,
                                                           const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo);
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd);
static VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain);
static VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo);
static VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd);
static VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters,
    VkPerformanceCounterDescriptionKHR* pCounterDescriptions);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses);
static VKAPI_ATTR VkResult VKAPI_CALL AcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo);
static VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR(VkDevice device);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice,
                                                                               const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                               VkSurfaceCapabilities2KHR* pSurfaceCapabilities);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice,
                                                                          const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                          uint32_t* pSurfaceFormatCount,
                                                                          VkSurfaceFormat2KHR* pSurfaceFormats);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice,
                                                                             uint32_t* pPropertyCount,
                                                                             VkDisplayProperties2KHR* pProperties);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice,
                                                                                  uint32_t* pPropertyCount,
                                                                                  VkDisplayPlaneProperties2KHR* pProperties);
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                                   uint32_t* pPropertyCount,
                                                                   VkDisplayModeProperties2KHR* pProperties);
static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice,
                                                                      const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo,
                                                                      VkDisplayPlaneCapabilities2KHR* pCapabilities);
static VKAPI_ATTR VkResult VKAPI_CALL
GetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount,
                                         VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates);
static VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                                               const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);
static VKAPI_ATTR void VKAPI_CALL CmdRefreshObjectsKHR(VkCommandBuffer commandBuffer,
                                                       const VkRefreshObjectListKHR* pRefreshObjects);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceRefreshableObjectTypesKHR(VkPhysicalDevice physicalDevice,
                                                                                 uint32_t* pRefreshableObjectTypeCount,
                                                                                 VkObjectType* pRefreshableObjectTypes);
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                                  const VkDependencyInfo* pDependencyInfo);
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                                    const VkDependencyInfo* pDependencyInfos);
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                        VkQueryPool queryPool, uint32_t query);
static VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits,
                                                      VkFence fence);
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                                           const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                                           const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                       uint16_t lineStipplePattern);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice physicalDevice,
                                                                                   uint32_t* pTimeDomainCount,
                                                                                   VkTimeDomainKHR* pTimeDomains);
static VKAPI_ATTR VkResult VKAPI_CALL GetCalibratedTimestampsKHR(VkDevice device, uint32_t timestampCount,
                                                                 const VkCalibratedTimestampInfoKHR* pTimestampInfos,
                                                                 uint64_t* pTimestamps, uint64_t* pMaxDeviation);
static VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice,
                                                                               VkSurfaceKHR surface,
                                                                               VkSurfaceCapabilities2EXT* pSurfaceCapabilities);
static VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT(VkDevice device, VkDisplayKHR display,
                                                             const VkDisplayPowerInfoEXT* pDisplayPowerInfo);
static VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo,
                                                             const VkAllocationCallbacks* pAllocator, VkFence* pFence);
static VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display,
                                                              const VkDisplayEventInfoEXT* pDisplayEventInfo,
                                                              const VkAllocationCallbacks* pAllocator, VkFence* pFence);
static VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain,
                                                             VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue);
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                                            uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles);
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                                                VkDiscardRectangleModeEXT discardRectangleMode);
static VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains,
                                                    const VkHdrMetadataEXT* pMetadata);
static VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo);
static VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo);
static VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
static VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(VkQueue queue);
static VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
static VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
static VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer);
static VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                              const VkDebugUtilsLabelEXT* pLabelInfo);
static VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(VkInstance instance,
                                                                   const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   VkDebugUtilsMessengerEXT* pMessenger);
static VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                                                const VkAllocationCallbacks* pAllocator);
static VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT(VkInstance instance,
                                                             VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                             VkDebugUtilsMessageTypeFlagsEXT messageTypes,
                                                             const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData);
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                                           const VkSampleLocationsInfoEXT* pSampleLocationsInfo);
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice,
                                                                            VkSampleCountFlagBits samples,
                                                                            VkMultisamplePropertiesEXT* pMultisampleProperties);
static VKAPI_ATTR VkResult VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image,
                                                                             VkImageDrmFormatModifierPropertiesEXT* pProperties);
static VKAPI_ATTR VkResult VKAPI_CALL
GetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer,
                                  VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties);
static VKAPI_ATTR VkResult VKAPI_CALL CreateHeadlessSurfaceEXT(VkInstance instance,
                                                               const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo,
                                                               const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                       uint16_t lineStipplePattern);
static VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace);
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                             const VkViewport* pViewports);
static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                            const VkRect2D* pScissors);
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                           uint32_t bindingCount, const VkBuffer* pBuffers,
                                                           const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                           const VkDeviceSize* pStrides);
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                                     VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL AcquireWinrtDisplayNV(VkPhysicalDevice physicalDevice, VkDisplayKHR display);
static VKAPI_ATTR VkResult VKAPI_CALL GetWinrtDisplayNV(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId,
                                                        VkDisplayKHR* pDisplay);
#endif  // VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                                       const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                                       uint32_t vertexAttributeDescriptionCount,
                                                       const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);
#ifdef VK_USE_PLATFORM_SCI
static VKAPI_ATTR VkResult VKAPI_CALL GetFenceSciSyncFenceNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo,
                                                             void* pHandle);
static VKAPI_ATTR VkResult VKAPI_CALL GetFenceSciSyncObjNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo,
                                                           void* pHandle);
static VKAPI_ATTR VkResult VKAPI_CALL ImportFenceSciSyncFenceNV(VkDevice device,
                                                                const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo);
static VKAPI_ATTR VkResult VKAPI_CALL ImportFenceSciSyncObjNV(VkDevice device,
                                                              const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSciSyncAttributesNV(VkPhysicalDevice physicalDevice,
                                                                           const VkSciSyncAttributesInfoNV* pSciSyncAttributesInfo,
                                                                           NvSciSyncAttrList pAttributes);
static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreSciSyncObjNV(VkDevice device, const VkSemaphoreGetSciSyncInfoNV* pGetSciSyncInfo,
                                                               void* pHandle);
static VKAPI_ATTR VkResult VKAPI_CALL
ImportSemaphoreSciSyncObjNV(VkDevice device, const VkImportSemaphoreSciSyncInfoNV* pImportSemaphoreSciSyncInfo);
static VKAPI_ATTR VkResult VKAPI_CALL GetMemorySciBufNV(VkDevice device, const VkMemoryGetSciBufInfoNV* pGetSciBufInfo,
                                                        NvSciBufObj* pHandle);
static VKAPI_ATTR VkResult VKAPI_CALL
GetPhysicalDeviceExternalMemorySciBufPropertiesNV(VkPhysicalDevice physicalDevice, VkExternalMemoryHandleTypeFlagBits handleType,
                                                  NvSciBufObj handle, VkMemorySciBufPropertiesNV* pMemorySciBufProperties);
static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSciBufAttributesNV(VkPhysicalDevice physicalDevice,
                                                                          NvSciBufAttrList pAttributes);
#endif  // VK_USE_PLATFORM_SCI
static VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints);
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp);
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
static VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                            const VkBool32* pColorWriteEnables);
#ifdef VK_USE_PLATFORM_SCI
static VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphoreSciSyncPoolNV(VkDevice device,
                                                                   const VkSemaphoreSciSyncPoolCreateInfoNV* pCreateInfo,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   VkSemaphoreSciSyncPoolNV* pSemaphorePool);
#endif  // VK_USE_PLATFORM_SCI
#ifdef VK_USE_PLATFORM_SCREEN_QNX
static VKAPI_ATTR VkResult VKAPI_CALL GetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer,
                                                                   VkScreenBufferPropertiesQNX* pProperties);
#endif  // VK_USE_PLATFORM_SCREEN_QNX

// Map of all APIs to be intercepted by this layer
static const std::unordered_map<std::string, void*> name_to_func_ptr_map = {
    {"vkCreateInstance", (void*)CreateInstance},
    {"vkDestroyInstance", (void*)DestroyInstance},
    {"vkEnumeratePhysicalDevices", (void*)EnumeratePhysicalDevices},
    {"vkGetPhysicalDeviceFeatures", (void*)GetPhysicalDeviceFeatures},
    {"vkGetPhysicalDeviceFormatProperties", (void*)GetPhysicalDeviceFormatProperties},
    {"vkGetPhysicalDeviceImageFormatProperties", (void*)GetPhysicalDeviceImageFormatProperties},
    {"vkGetPhysicalDeviceProperties", (void*)GetPhysicalDeviceProperties},
    {"vkGetPhysicalDeviceQueueFamilyProperties", (void*)GetPhysicalDeviceQueueFamilyProperties},
    {"vkGetPhysicalDeviceMemoryProperties", (void*)GetPhysicalDeviceMemoryProperties},
    {"vkGetInstanceProcAddr", (void*)GetInstanceProcAddr},
    {"vkGetDeviceProcAddr", (void*)GetDeviceProcAddr},
    {"vkCreateDevice", (void*)CreateDevice},
    {"vkDestroyDevice", (void*)DestroyDevice},
    {"vkEnumerateInstanceExtensionProperties", (void*)EnumerateInstanceExtensionProperties},
    {"vkEnumerateDeviceExtensionProperties", (void*)EnumerateDeviceExtensionProperties},
    {"vkEnumerateInstanceLayerProperties", (void*)EnumerateInstanceLayerProperties},
    {"vkEnumerateDeviceLayerProperties", (void*)EnumerateDeviceLayerProperties},
    {"vkGetDeviceQueue", (void*)GetDeviceQueue},
    {"vkQueueSubmit", (void*)QueueSubmit},
    {"vkQueueWaitIdle", (void*)QueueWaitIdle},
    {"vkDeviceWaitIdle", (void*)DeviceWaitIdle},
    {"vkAllocateMemory", (void*)AllocateMemory},
    {"vkMapMemory", (void*)MapMemory},
    {"vkUnmapMemory", (void*)UnmapMemory},
    {"vkFlushMappedMemoryRanges", (void*)FlushMappedMemoryRanges},
    {"vkInvalidateMappedMemoryRanges", (void*)InvalidateMappedMemoryRanges},
    {"vkGetDeviceMemoryCommitment", (void*)GetDeviceMemoryCommitment},
    {"vkBindBufferMemory", (void*)BindBufferMemory},
    {"vkBindImageMemory", (void*)BindImageMemory},
    {"vkGetBufferMemoryRequirements", (void*)GetBufferMemoryRequirements},
    {"vkGetImageMemoryRequirements", (void*)GetImageMemoryRequirements},
    {"vkCreateFence", (void*)CreateFence},
    {"vkDestroyFence", (void*)DestroyFence},
    {"vkResetFences", (void*)ResetFences},
    {"vkGetFenceStatus", (void*)GetFenceStatus},
    {"vkWaitForFences", (void*)WaitForFences},
    {"vkCreateSemaphore", (void*)CreateSemaphore},
    {"vkDestroySemaphore", (void*)DestroySemaphore},
    {"vkCreateEvent", (void*)CreateEvent},
    {"vkDestroyEvent", (void*)DestroyEvent},
    {"vkGetEventStatus", (void*)GetEventStatus},
    {"vkSetEvent", (void*)SetEvent},
    {"vkResetEvent", (void*)ResetEvent},
    {"vkCreateQueryPool", (void*)CreateQueryPool},
    {"vkGetQueryPoolResults", (void*)GetQueryPoolResults},
    {"vkCreateBuffer", (void*)CreateBuffer},
    {"vkDestroyBuffer", (void*)DestroyBuffer},
    {"vkCreateBufferView", (void*)CreateBufferView},
    {"vkDestroyBufferView", (void*)DestroyBufferView},
    {"vkCreateImage", (void*)CreateImage},
    {"vkDestroyImage", (void*)DestroyImage},
    {"vkGetImageSubresourceLayout", (void*)GetImageSubresourceLayout},
    {"vkCreateImageView", (void*)CreateImageView},
    {"vkDestroyImageView", (void*)DestroyImageView},
    {"vkCreatePipelineCache", (void*)CreatePipelineCache},
    {"vkDestroyPipelineCache", (void*)DestroyPipelineCache},
    {"vkCreateGraphicsPipelines", (void*)CreateGraphicsPipelines},
    {"vkCreateComputePipelines", (void*)CreateComputePipelines},
    {"vkDestroyPipeline", (void*)DestroyPipeline},
    {"vkCreatePipelineLayout", (void*)CreatePipelineLayout},
    {"vkDestroyPipelineLayout", (void*)DestroyPipelineLayout},
    {"vkCreateSampler", (void*)CreateSampler},
    {"vkDestroySampler", (void*)DestroySampler},
    {"vkCreateDescriptorSetLayout", (void*)CreateDescriptorSetLayout},
    {"vkDestroyDescriptorSetLayout", (void*)DestroyDescriptorSetLayout},
    {"vkCreateDescriptorPool", (void*)CreateDescriptorPool},
    {"vkResetDescriptorPool", (void*)ResetDescriptorPool},
    {"vkAllocateDescriptorSets", (void*)AllocateDescriptorSets},
    {"vkFreeDescriptorSets", (void*)FreeDescriptorSets},
    {"vkUpdateDescriptorSets", (void*)UpdateDescriptorSets},
    {"vkCreateFramebuffer", (void*)CreateFramebuffer},
    {"vkDestroyFramebuffer", (void*)DestroyFramebuffer},
    {"vkCreateRenderPass", (void*)CreateRenderPass},
    {"vkDestroyRenderPass", (void*)DestroyRenderPass},
    {"vkGetRenderAreaGranularity", (void*)GetRenderAreaGranularity},
    {"vkCreateCommandPool", (void*)CreateCommandPool},
    {"vkResetCommandPool", (void*)ResetCommandPool},
    {"vkAllocateCommandBuffers", (void*)AllocateCommandBuffers},
    {"vkFreeCommandBuffers", (void*)FreeCommandBuffers},
    {"vkBeginCommandBuffer", (void*)BeginCommandBuffer},
    {"vkEndCommandBuffer", (void*)EndCommandBuffer},
    {"vkResetCommandBuffer", (void*)ResetCommandBuffer},
    {"vkCmdBindPipeline", (void*)CmdBindPipeline},
    {"vkCmdSetViewport", (void*)CmdSetViewport},
    {"vkCmdSetScissor", (void*)CmdSetScissor},
    {"vkCmdSetLineWidth", (void*)CmdSetLineWidth},
    {"vkCmdSetDepthBias", (void*)CmdSetDepthBias},
    {"vkCmdSetBlendConstants", (void*)CmdSetBlendConstants},
    {"vkCmdSetDepthBounds", (void*)CmdSetDepthBounds},
    {"vkCmdSetStencilCompareMask", (void*)CmdSetStencilCompareMask},
    {"vkCmdSetStencilWriteMask", (void*)CmdSetStencilWriteMask},
    {"vkCmdSetStencilReference", (void*)CmdSetStencilReference},
    {"vkCmdBindDescriptorSets", (void*)CmdBindDescriptorSets},
    {"vkCmdBindIndexBuffer", (void*)CmdBindIndexBuffer},
    {"vkCmdBindVertexBuffers", (void*)CmdBindVertexBuffers},
    {"vkCmdDraw", (void*)CmdDraw},
    {"vkCmdDrawIndexed", (void*)CmdDrawIndexed},
    {"vkCmdDrawIndirect", (void*)CmdDrawIndirect},
    {"vkCmdDrawIndexedIndirect", (void*)CmdDrawIndexedIndirect},
    {"vkCmdDispatch", (void*)CmdDispatch},
    {"vkCmdDispatchIndirect", (void*)CmdDispatchIndirect},
    {"vkCmdCopyBuffer", (void*)CmdCopyBuffer},
    {"vkCmdCopyImage", (void*)CmdCopyImage},
    {"vkCmdBlitImage", (void*)CmdBlitImage},
    {"vkCmdCopyBufferToImage", (void*)CmdCopyBufferToImage},
    {"vkCmdCopyImageToBuffer", (void*)CmdCopyImageToBuffer},
    {"vkCmdUpdateBuffer", (void*)CmdUpdateBuffer},
    {"vkCmdFillBuffer", (void*)CmdFillBuffer},
    {"vkCmdClearColorImage", (void*)CmdClearColorImage},
    {"vkCmdClearDepthStencilImage", (void*)CmdClearDepthStencilImage},
    {"vkCmdClearAttachments", (void*)CmdClearAttachments},
    {"vkCmdResolveImage", (void*)CmdResolveImage},
    {"vkCmdSetEvent", (void*)CmdSetEvent},
    {"vkCmdResetEvent", (void*)CmdResetEvent},
    {"vkCmdWaitEvents", (void*)CmdWaitEvents},
    {"vkCmdPipelineBarrier", (void*)CmdPipelineBarrier},
    {"vkCmdBeginQuery", (void*)CmdBeginQuery},
    {"vkCmdEndQuery", (void*)CmdEndQuery},
    {"vkCmdResetQueryPool", (void*)CmdResetQueryPool},
    {"vkCmdWriteTimestamp", (void*)CmdWriteTimestamp},
    {"vkCmdCopyQueryPoolResults", (void*)CmdCopyQueryPoolResults},
    {"vkCmdPushConstants", (void*)CmdPushConstants},
    {"vkCmdBeginRenderPass", (void*)CmdBeginRenderPass},
    {"vkCmdNextSubpass", (void*)CmdNextSubpass},
    {"vkCmdEndRenderPass", (void*)CmdEndRenderPass},
    {"vkCmdExecuteCommands", (void*)CmdExecuteCommands},
    {"vkEnumerateInstanceVersion", (void*)EnumerateInstanceVersion},
    {"vkBindBufferMemory2", (void*)BindBufferMemory2},
    {"vkBindImageMemory2", (void*)BindImageMemory2},
    {"vkGetDeviceGroupPeerMemoryFeatures", (void*)GetDeviceGroupPeerMemoryFeatures},
    {"vkCmdSetDeviceMask", (void*)CmdSetDeviceMask},
    {"vkCmdDispatchBase", (void*)CmdDispatchBase},
    {"vkEnumeratePhysicalDeviceGroups", (void*)EnumeratePhysicalDeviceGroups},
    {"vkGetImageMemoryRequirements2", (void*)GetImageMemoryRequirements2},
    {"vkGetBufferMemoryRequirements2", (void*)GetBufferMemoryRequirements2},
    {"vkGetPhysicalDeviceFeatures2", (void*)GetPhysicalDeviceFeatures2},
    {"vkGetPhysicalDeviceProperties2", (void*)GetPhysicalDeviceProperties2},
    {"vkGetPhysicalDeviceFormatProperties2", (void*)GetPhysicalDeviceFormatProperties2},
    {"vkGetPhysicalDeviceImageFormatProperties2", (void*)GetPhysicalDeviceImageFormatProperties2},
    {"vkGetPhysicalDeviceQueueFamilyProperties2", (void*)GetPhysicalDeviceQueueFamilyProperties2},
    {"vkGetPhysicalDeviceMemoryProperties2", (void*)GetPhysicalDeviceMemoryProperties2},
    {"vkGetDeviceQueue2", (void*)GetDeviceQueue2},
    {"vkCreateSamplerYcbcrConversion", (void*)CreateSamplerYcbcrConversion},
    {"vkDestroySamplerYcbcrConversion", (void*)DestroySamplerYcbcrConversion},
    {"vkGetPhysicalDeviceExternalBufferProperties", (void*)GetPhysicalDeviceExternalBufferProperties},
    {"vkGetPhysicalDeviceExternalFenceProperties", (void*)GetPhysicalDeviceExternalFenceProperties},
    {"vkGetPhysicalDeviceExternalSemaphoreProperties", (void*)GetPhysicalDeviceExternalSemaphoreProperties},
    {"vkGetDescriptorSetLayoutSupport", (void*)GetDescriptorSetLayoutSupport},
    {"vkCmdDrawIndirectCount", (void*)CmdDrawIndirectCount},
    {"vkCmdDrawIndexedIndirectCount", (void*)CmdDrawIndexedIndirectCount},
    {"vkCreateRenderPass2", (void*)CreateRenderPass2},
    {"vkCmdBeginRenderPass2", (void*)CmdBeginRenderPass2},
    {"vkCmdNextSubpass2", (void*)CmdNextSubpass2},
    {"vkCmdEndRenderPass2", (void*)CmdEndRenderPass2},
    {"vkResetQueryPool", (void*)ResetQueryPool},
    {"vkGetSemaphoreCounterValue", (void*)GetSemaphoreCounterValue},
    {"vkWaitSemaphores", (void*)WaitSemaphores},
    {"vkSignalSemaphore", (void*)SignalSemaphore},
    {"vkGetBufferDeviceAddress", (void*)GetBufferDeviceAddress},
    {"vkGetBufferOpaqueCaptureAddress", (void*)GetBufferOpaqueCaptureAddress},
    {"vkGetDeviceMemoryOpaqueCaptureAddress", (void*)GetDeviceMemoryOpaqueCaptureAddress},
    {"vkGetPhysicalDeviceToolProperties", (void*)GetPhysicalDeviceToolProperties},
    {"vkCreatePrivateDataSlot", (void*)CreatePrivateDataSlot},
    {"vkDestroyPrivateDataSlot", (void*)DestroyPrivateDataSlot},
    {"vkSetPrivateData", (void*)SetPrivateData},
    {"vkGetPrivateData", (void*)GetPrivateData},
    {"vkCmdSetEvent2", (void*)CmdSetEvent2},
    {"vkCmdResetEvent2", (void*)CmdResetEvent2},
    {"vkCmdWaitEvents2", (void*)CmdWaitEvents2},
    {"vkCmdPipelineBarrier2", (void*)CmdPipelineBarrier2},
    {"vkCmdWriteTimestamp2", (void*)CmdWriteTimestamp2},
    {"vkQueueSubmit2", (void*)QueueSubmit2},
    {"vkCmdCopyBuffer2", (void*)CmdCopyBuffer2},
    {"vkCmdCopyImage2", (void*)CmdCopyImage2},
    {"vkCmdCopyBufferToImage2", (void*)CmdCopyBufferToImage2},
    {"vkCmdCopyImageToBuffer2", (void*)CmdCopyImageToBuffer2},
    {"vkCmdBlitImage2", (void*)CmdBlitImage2},
    {"vkCmdResolveImage2", (void*)CmdResolveImage2},
    {"vkCmdBeginRendering", (void*)CmdBeginRendering},
    {"vkCmdEndRendering", (void*)CmdEndRendering},
    {"vkCmdSetCullMode", (void*)CmdSetCullMode},
    {"vkCmdSetFrontFace", (void*)CmdSetFrontFace},
    {"vkCmdSetPrimitiveTopology", (void*)CmdSetPrimitiveTopology},
    {"vkCmdSetViewportWithCount", (void*)CmdSetViewportWithCount},
    {"vkCmdSetScissorWithCount", (void*)CmdSetScissorWithCount},
    {"vkCmdBindVertexBuffers2", (void*)CmdBindVertexBuffers2},
    {"vkCmdSetDepthTestEnable", (void*)CmdSetDepthTestEnable},
    {"vkCmdSetDepthWriteEnable", (void*)CmdSetDepthWriteEnable},
    {"vkCmdSetDepthCompareOp", (void*)CmdSetDepthCompareOp},
    {"vkCmdSetDepthBoundsTestEnable", (void*)CmdSetDepthBoundsTestEnable},
    {"vkCmdSetStencilTestEnable", (void*)CmdSetStencilTestEnable},
    {"vkCmdSetStencilOp", (void*)CmdSetStencilOp},
    {"vkCmdSetRasterizerDiscardEnable", (void*)CmdSetRasterizerDiscardEnable},
    {"vkCmdSetDepthBiasEnable", (void*)CmdSetDepthBiasEnable},
    {"vkCmdSetPrimitiveRestartEnable", (void*)CmdSetPrimitiveRestartEnable},
    {"vkGetDeviceBufferMemoryRequirements", (void*)GetDeviceBufferMemoryRequirements},
    {"vkGetDeviceImageMemoryRequirements", (void*)GetDeviceImageMemoryRequirements},
    {"vkGetDeviceImageSparseMemoryRequirements", (void*)GetDeviceImageSparseMemoryRequirements},
    {"vkCmdSetLineStipple", (void*)CmdSetLineStipple},
    {"vkMapMemory2", (void*)MapMemory2},
    {"vkUnmapMemory2", (void*)UnmapMemory2},
    {"vkCmdBindIndexBuffer2", (void*)CmdBindIndexBuffer2},
    {"vkGetRenderingAreaGranularity", (void*)GetRenderingAreaGranularity},
    {"vkGetDeviceImageSubresourceLayout", (void*)GetDeviceImageSubresourceLayout},
    {"vkGetImageSubresourceLayout2", (void*)GetImageSubresourceLayout2},
    {"vkCmdPushDescriptorSet", (void*)CmdPushDescriptorSet},
    {"vkCmdSetRenderingAttachmentLocations", (void*)CmdSetRenderingAttachmentLocations},
    {"vkCmdSetRenderingInputAttachmentIndices", (void*)CmdSetRenderingInputAttachmentIndices},
    {"vkCmdBindDescriptorSets2", (void*)CmdBindDescriptorSets2},
    {"vkCmdPushConstants2", (void*)CmdPushConstants2},
    {"vkCmdPushDescriptorSet2", (void*)CmdPushDescriptorSet2},
    {"vkCopyMemoryToImage", (void*)CopyMemoryToImage},
    {"vkCopyImageToMemory", (void*)CopyImageToMemory},
    {"vkCopyImageToImage", (void*)CopyImageToImage},
    {"vkTransitionImageLayout", (void*)TransitionImageLayout},
    {"vkGetCommandPoolMemoryConsumption", (void*)GetCommandPoolMemoryConsumption},
    {"vkGetFaultData", (void*)GetFaultData},
    {"vkDestroySurfaceKHR", (void*)DestroySurfaceKHR},
    {"vkGetPhysicalDeviceSurfaceSupportKHR", (void*)GetPhysicalDeviceSurfaceSupportKHR},
    {"vkGetPhysicalDeviceSurfaceCapabilitiesKHR", (void*)GetPhysicalDeviceSurfaceCapabilitiesKHR},
    {"vkGetPhysicalDeviceSurfaceFormatsKHR", (void*)GetPhysicalDeviceSurfaceFormatsKHR},
    {"vkGetPhysicalDeviceSurfacePresentModesKHR", (void*)GetPhysicalDeviceSurfacePresentModesKHR},
    {"vkCreateSwapchainKHR", (void*)CreateSwapchainKHR},
    {"vkGetSwapchainImagesKHR", (void*)GetSwapchainImagesKHR},
    {"vkAcquireNextImageKHR", (void*)AcquireNextImageKHR},
    {"vkQueuePresentKHR", (void*)QueuePresentKHR},
    {"vkGetDeviceGroupPresentCapabilitiesKHR", (void*)GetDeviceGroupPresentCapabilitiesKHR},
    {"vkGetDeviceGroupSurfacePresentModesKHR", (void*)GetDeviceGroupSurfacePresentModesKHR},
    {"vkGetPhysicalDevicePresentRectanglesKHR", (void*)GetPhysicalDevicePresentRectanglesKHR},
    {"vkAcquireNextImage2KHR", (void*)AcquireNextImage2KHR},
    {"vkGetPhysicalDeviceDisplayPropertiesKHR", (void*)GetPhysicalDeviceDisplayPropertiesKHR},
    {"vkGetPhysicalDeviceDisplayPlanePropertiesKHR", (void*)GetPhysicalDeviceDisplayPlanePropertiesKHR},
    {"vkGetDisplayPlaneSupportedDisplaysKHR", (void*)GetDisplayPlaneSupportedDisplaysKHR},
    {"vkGetDisplayModePropertiesKHR", (void*)GetDisplayModePropertiesKHR},
    {"vkCreateDisplayModeKHR", (void*)CreateDisplayModeKHR},
    {"vkGetDisplayPlaneCapabilitiesKHR", (void*)GetDisplayPlaneCapabilitiesKHR},
    {"vkCreateDisplayPlaneSurfaceKHR", (void*)CreateDisplayPlaneSurfaceKHR},
    {"vkCreateSharedSwapchainsKHR", (void*)CreateSharedSwapchainsKHR},
    {"vkGetMemoryFdKHR", (void*)GetMemoryFdKHR},
    {"vkGetMemoryFdPropertiesKHR", (void*)GetMemoryFdPropertiesKHR},
    {"vkImportSemaphoreFdKHR", (void*)ImportSemaphoreFdKHR},
    {"vkGetSemaphoreFdKHR", (void*)GetSemaphoreFdKHR},
    {"vkGetSwapchainStatusKHR", (void*)GetSwapchainStatusKHR},
    {"vkImportFenceFdKHR", (void*)ImportFenceFdKHR},
    {"vkGetFenceFdKHR", (void*)GetFenceFdKHR},
    {"vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR",
     (void*)EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR},
    {"vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", (void*)GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR},
    {"vkAcquireProfilingLockKHR", (void*)AcquireProfilingLockKHR},
    {"vkReleaseProfilingLockKHR", (void*)ReleaseProfilingLockKHR},
    {"vkGetPhysicalDeviceSurfaceCapabilities2KHR", (void*)GetPhysicalDeviceSurfaceCapabilities2KHR},
    {"vkGetPhysicalDeviceSurfaceFormats2KHR", (void*)GetPhysicalDeviceSurfaceFormats2KHR},
    {"vkGetPhysicalDeviceDisplayProperties2KHR", (void*)GetPhysicalDeviceDisplayProperties2KHR},
    {"vkGetPhysicalDeviceDisplayPlaneProperties2KHR", (void*)GetPhysicalDeviceDisplayPlaneProperties2KHR},
    {"vkGetDisplayModeProperties2KHR", (void*)GetDisplayModeProperties2KHR},
    {"vkGetDisplayPlaneCapabilities2KHR", (void*)GetDisplayPlaneCapabilities2KHR},
    {"vkGetPhysicalDeviceFragmentShadingRatesKHR", (void*)GetPhysicalDeviceFragmentShadingRatesKHR},
    {"vkCmdSetFragmentShadingRateKHR", (void*)CmdSetFragmentShadingRateKHR},
    {"vkCmdRefreshObjectsKHR", (void*)CmdRefreshObjectsKHR},
    {"vkGetPhysicalDeviceRefreshableObjectTypesKHR", (void*)GetPhysicalDeviceRefreshableObjectTypesKHR},
    {"vkCmdSetEvent2KHR", (void*)CmdSetEvent2KHR},
    {"vkCmdResetEvent2KHR", (void*)CmdResetEvent2KHR},
    {"vkCmdWaitEvents2KHR", (void*)CmdWaitEvents2KHR},
    {"vkCmdPipelineBarrier2KHR", (void*)CmdPipelineBarrier2KHR},
    {"vkCmdWriteTimestamp2KHR", (void*)CmdWriteTimestamp2KHR},
    {"vkQueueSubmit2KHR", (void*)QueueSubmit2KHR},
    {"vkCmdCopyBuffer2KHR", (void*)CmdCopyBuffer2KHR},
    {"vkCmdCopyImage2KHR", (void*)CmdCopyImage2KHR},
    {"vkCmdCopyBufferToImage2KHR", (void*)CmdCopyBufferToImage2KHR},
    {"vkCmdCopyImageToBuffer2KHR", (void*)CmdCopyImageToBuffer2KHR},
    {"vkCmdBlitImage2KHR", (void*)CmdBlitImage2KHR},
    {"vkCmdResolveImage2KHR", (void*)CmdResolveImage2KHR},
    {"vkCmdSetLineStippleKHR", (void*)CmdSetLineStippleKHR},
    {"vkGetPhysicalDeviceCalibrateableTimeDomainsKHR", (void*)GetPhysicalDeviceCalibrateableTimeDomainsKHR},
    {"vkGetCalibratedTimestampsKHR", (void*)GetCalibratedTimestampsKHR},
    {"vkReleaseDisplayEXT", (void*)ReleaseDisplayEXT},
    {"vkGetPhysicalDeviceSurfaceCapabilities2EXT", (void*)GetPhysicalDeviceSurfaceCapabilities2EXT},
    {"vkDisplayPowerControlEXT", (void*)DisplayPowerControlEXT},
    {"vkRegisterDeviceEventEXT", (void*)RegisterDeviceEventEXT},
    {"vkRegisterDisplayEventEXT", (void*)RegisterDisplayEventEXT},
    {"vkGetSwapchainCounterEXT", (void*)GetSwapchainCounterEXT},
    {"vkCmdSetDiscardRectangleEXT", (void*)CmdSetDiscardRectangleEXT},
    {"vkCmdSetDiscardRectangleEnableEXT", (void*)CmdSetDiscardRectangleEnableEXT},
    {"vkCmdSetDiscardRectangleModeEXT", (void*)CmdSetDiscardRectangleModeEXT},
    {"vkSetHdrMetadataEXT", (void*)SetHdrMetadataEXT},
    {"vkSetDebugUtilsObjectNameEXT", (void*)SetDebugUtilsObjectNameEXT},
    {"vkSetDebugUtilsObjectTagEXT", (void*)SetDebugUtilsObjectTagEXT},
    {"vkQueueBeginDebugUtilsLabelEXT", (void*)QueueBeginDebugUtilsLabelEXT},
    {"vkQueueEndDebugUtilsLabelEXT", (void*)QueueEndDebugUtilsLabelEXT},
    {"vkQueueInsertDebugUtilsLabelEXT", (void*)QueueInsertDebugUtilsLabelEXT},
    {"vkCmdBeginDebugUtilsLabelEXT", (void*)CmdBeginDebugUtilsLabelEXT},
    {"vkCmdEndDebugUtilsLabelEXT", (void*)CmdEndDebugUtilsLabelEXT},
    {"vkCmdInsertDebugUtilsLabelEXT", (void*)CmdInsertDebugUtilsLabelEXT},
    {"vkCreateDebugUtilsMessengerEXT", (void*)CreateDebugUtilsMessengerEXT},
    {"vkDestroyDebugUtilsMessengerEXT", (void*)DestroyDebugUtilsMessengerEXT},
    {"vkSubmitDebugUtilsMessageEXT", (void*)SubmitDebugUtilsMessageEXT},
    {"vkCmdSetSampleLocationsEXT", (void*)CmdSetSampleLocationsEXT},
    {"vkGetPhysicalDeviceMultisamplePropertiesEXT", (void*)GetPhysicalDeviceMultisamplePropertiesEXT},
    {"vkGetImageDrmFormatModifierPropertiesEXT", (void*)GetImageDrmFormatModifierPropertiesEXT},
    {"vkGetMemoryHostPointerPropertiesEXT", (void*)GetMemoryHostPointerPropertiesEXT},
    {"vkCreateHeadlessSurfaceEXT", (void*)CreateHeadlessSurfaceEXT},
    {"vkCmdSetLineStippleEXT", (void*)CmdSetLineStippleEXT},
    {"vkCmdSetCullModeEXT", (void*)CmdSetCullModeEXT},
    {"vkCmdSetFrontFaceEXT", (void*)CmdSetFrontFaceEXT},
    {"vkCmdSetPrimitiveTopologyEXT", (void*)CmdSetPrimitiveTopologyEXT},
    {"vkCmdSetViewportWithCountEXT", (void*)CmdSetViewportWithCountEXT},
    {"vkCmdSetScissorWithCountEXT", (void*)CmdSetScissorWithCountEXT},
    {"vkCmdBindVertexBuffers2EXT", (void*)CmdBindVertexBuffers2EXT},
    {"vkCmdSetDepthTestEnableEXT", (void*)CmdSetDepthTestEnableEXT},
    {"vkCmdSetDepthWriteEnableEXT", (void*)CmdSetDepthWriteEnableEXT},
    {"vkCmdSetDepthCompareOpEXT", (void*)CmdSetDepthCompareOpEXT},
    {"vkCmdSetDepthBoundsTestEnableEXT", (void*)CmdSetDepthBoundsTestEnableEXT},
    {"vkCmdSetStencilTestEnableEXT", (void*)CmdSetStencilTestEnableEXT},
    {"vkCmdSetStencilOpEXT", (void*)CmdSetStencilOpEXT},
#ifdef VK_USE_PLATFORM_WIN32_KHR
    {"vkAcquireWinrtDisplayNV", (void*)AcquireWinrtDisplayNV},
    {"vkGetWinrtDisplayNV", (void*)GetWinrtDisplayNV},
#endif  // VK_USE_PLATFORM_WIN32_KHR
    {"vkCmdSetVertexInputEXT", (void*)CmdSetVertexInputEXT},
#ifdef VK_USE_PLATFORM_SCI
    {"vkGetFenceSciSyncFenceNV", (void*)GetFenceSciSyncFenceNV},
    {"vkGetFenceSciSyncObjNV", (void*)GetFenceSciSyncObjNV},
    {"vkImportFenceSciSyncFenceNV", (void*)ImportFenceSciSyncFenceNV},
    {"vkImportFenceSciSyncObjNV", (void*)ImportFenceSciSyncObjNV},
    {"vkGetPhysicalDeviceSciSyncAttributesNV", (void*)GetPhysicalDeviceSciSyncAttributesNV},
    {"vkGetSemaphoreSciSyncObjNV", (void*)GetSemaphoreSciSyncObjNV},
    {"vkImportSemaphoreSciSyncObjNV", (void*)ImportSemaphoreSciSyncObjNV},
    {"vkGetMemorySciBufNV", (void*)GetMemorySciBufNV},
    {"vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV", (void*)GetPhysicalDeviceExternalMemorySciBufPropertiesNV},
    {"vkGetPhysicalDeviceSciBufAttributesNV", (void*)GetPhysicalDeviceSciBufAttributesNV},
#endif  // VK_USE_PLATFORM_SCI
    {"vkCmdSetPatchControlPointsEXT", (void*)CmdSetPatchControlPointsEXT},
    {"vkCmdSetRasterizerDiscardEnableEXT", (void*)CmdSetRasterizerDiscardEnableEXT},
    {"vkCmdSetDepthBiasEnableEXT", (void*)CmdSetDepthBiasEnableEXT},
    {"vkCmdSetLogicOpEXT", (void*)CmdSetLogicOpEXT},
    {"vkCmdSetPrimitiveRestartEnableEXT", (void*)CmdSetPrimitiveRestartEnableEXT},
    {"vkCmdSetColorWriteEnableEXT", (void*)CmdSetColorWriteEnableEXT},
#ifdef VK_USE_PLATFORM_SCI
    {"vkCreateSemaphoreSciSyncPoolNV", (void*)CreateSemaphoreSciSyncPoolNV},
#endif  // VK_USE_PLATFORM_SCI
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    {"vkGetScreenBufferPropertiesQNX", (void*)GetScreenBufferPropertiesQNX},
#endif  // VK_USE_PLATFORM_SCREEN_QNX
};
static VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle(VkQueue queue) { return VK_SUCCESS; }

static VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle(VkDevice device) { return VK_SUCCESS; }

static VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                              const VkMappedMemoryRange* pMemoryRanges) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                                   const VkMappedMemoryRange* pMemoryRanges) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory,
                                                            VkDeviceSize* pCommittedMemoryInBytes) {}

static VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory,
                                                       VkDeviceSize memoryOffset) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory,
                                                      VkDeviceSize memoryOffset) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    unique_lock_t lock(global_lock);
    *pFence = (VkFence)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL ResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(VkDevice device, VkFence fence) { return VK_SUCCESS; }

static VKAPI_ATTR VkResult VKAPI_CALL WaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll,
                                                    uint64_t timeout) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) {
    unique_lock_t lock(global_lock);
    *pSemaphore = (VkSemaphore)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroySemaphore(VkDevice device, VkSemaphore semaphore,
                                                   const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) {
    unique_lock_t lock(global_lock);
    *pEvent = (VkEvent)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(VkDevice device, VkEvent event) { return VK_SUCCESS; }

static VKAPI_ATTR VkResult VKAPI_CALL SetEvent(VkDevice device, VkEvent event) { return VK_SUCCESS; }

static VKAPI_ATTR VkResult VKAPI_CALL ResetEvent(VkDevice device, VkEvent event) { return VK_SUCCESS; }

static VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) {
    unique_lock_t lock(global_lock);
    *pQueryPool = (VkQueryPool)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                                          uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride,
                                                          VkQueryResultFlags flags) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkBufferView* pView) {
    unique_lock_t lock(global_lock);
    *pView = (VkBufferView)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyBufferView(VkDevice device, VkBufferView bufferView,
                                                    const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkImageView* pView) {
    unique_lock_t lock(global_lock);
    *pView = (VkImageView)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyImageView(VkDevice device, VkImageView imageView,
                                                   const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator,
                                                          VkPipelineCache* pPipelineCache) {
    unique_lock_t lock(global_lock);
    *pPipelineCache = (VkPipelineCache)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache,
                                                       const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                              uint32_t createInfoCount,
                                                              const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                              const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    unique_lock_t lock(global_lock);
    for (uint32_t i = 0; i < createInfoCount; ++i) {
        pPipelines[i] = (VkPipeline)global_unique_handle++;
    }
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                             uint32_t createInfoCount,
                                                             const VkComputePipelineCreateInfo* pCreateInfos,
                                                             const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    unique_lock_t lock(global_lock);
    for (uint32_t i = 0; i < createInfoCount; ++i) {
        pPipelines[i] = (VkPipeline)global_unique_handle++;
    }
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           VkPipelineLayout* pPipelineLayout) {
    unique_lock_t lock(global_lock);
    *pPipelineLayout = (VkPipelineLayout)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout,
                                                        const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) {
    unique_lock_t lock(global_lock);
    *pSampler = (VkSampler)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                                const VkAllocationCallbacks* pAllocator,
                                                                VkDescriptorSetLayout* pSetLayout) {
    unique_lock_t lock(global_lock);
    *pSetLayout = (VkDescriptorSetLayout)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout,
                                                             const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           VkDescriptorPool* pDescriptorPool) {
    unique_lock_t lock(global_lock);
    *pDescriptorPool = (VkDescriptorPool)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool,
                                                          VkDescriptorPoolResetFlags flags) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                                             VkDescriptorSet* pDescriptorSets) {
    unique_lock_t lock(global_lock);
    for (uint32_t i = 0; i < pAllocateInfo->descriptorSetCount; ++i) {
        pDescriptorSets[i] = (VkDescriptorSet)global_unique_handle++;
    }
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool,
                                                         uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount,
                                                       const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount,
                                                       const VkCopyDescriptorSet* pDescriptorCopies) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) {
    unique_lock_t lock(global_lock);
    *pFramebuffer = (VkFramebuffer)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer,
                                                     const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    unique_lock_t lock(global_lock);
    *pRenderPass = (VkRenderPass)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyRenderPass(VkDevice device, VkRenderPass renderPass,
                                                    const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(VkCommandBuffer commandBuffer,
                                                         const VkCommandBufferBeginInfo* pBeginInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer(VkCommandBuffer commandBuffer) { return VK_SUCCESS; }

static VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                  VkPipeline pipeline) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                                 const VkViewport* pViewports) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                                const VkRect2D* pScissors) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor,
                                                  float depthBiasClamp, float depthBiasSlopeFactor) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                           uint32_t compareMask) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                         uint32_t writeMask) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                         uint32_t reference) {}

static VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                        VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                                        const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                                        const uint32_t* pDynamicOffsets) {}

static VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                     VkIndexType indexType) {}

static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                                       const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {}

static VKAPI_ATTR void VKAPI_CALL CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                                          uint32_t firstVertex, uint32_t firstInstance) {}

static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                                 uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {}

static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                  uint32_t drawCount, uint32_t stride) {}

static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                         uint32_t drawCount, uint32_t stride) {}

static VKAPI_ATTR void VKAPI_CALL CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                              uint32_t groupCountZ) {}

static VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {}

static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                                uint32_t regionCount, const VkBufferCopy* pRegions) {}

static VKAPI_ATTR void VKAPI_CALL CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                               VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                               const VkImageCopy* pRegions) {}

static VKAPI_ATTR void VKAPI_CALL CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                               VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                               const VkImageBlit* pRegions, VkFilter filter) {}

static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                                       VkImageLayout dstImageLayout, uint32_t regionCount,
                                                       const VkBufferImageCopy* pRegions) {}

static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                       VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount,
                                                       const VkBufferImageCopy* pRegions) {}

static VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                  VkDeviceSize dataSize, const void* pData) {}

static VKAPI_ATTR void VKAPI_CALL CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                VkDeviceSize size, uint32_t data) {}

static VKAPI_ATTR void VKAPI_CALL CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                                     const VkClearColorValue* pColor, uint32_t rangeCount,
                                                     const VkImageSubresourceRange* pRanges) {}

static VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                                            const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                                            const VkImageSubresourceRange* pRanges) {}

static VKAPI_ATTR void VKAPI_CALL CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                      const VkClearAttachment* pAttachments, uint32_t rectCount,
                                                      const VkClearRect* pRects) {}

static VKAPI_ATTR void VKAPI_CALL CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                                  VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                                  const VkImageResolve* pRegions) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {}

static VKAPI_ATTR void VKAPI_CALL CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {}

static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                                VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                                                uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                                uint32_t bufferMemoryBarrierCount,
                                                const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                                uint32_t imageMemoryBarrierCount,
                                                const VkImageMemoryBarrier* pImageMemoryBarriers) {}

static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                                     VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                                     uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                                     uint32_t bufferMemoryBarrierCount,
                                                     const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                                     uint32_t imageMemoryBarrierCount,
                                                     const VkImageMemoryBarrier* pImageMemoryBarriers) {}

static VKAPI_ATTR void VKAPI_CALL CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                                VkQueryControlFlags flags) {}

static VKAPI_ATTR void VKAPI_CALL CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {}

static VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                                    uint32_t queryCount) {}

static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                                    VkQueryPool queryPool, uint32_t query) {}

static VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                                          uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                          VkDeviceSize stride, VkQueryResultFlags flags) {}

static VKAPI_ATTR void VKAPI_CALL CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                                   VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                                   const void* pValues) {}

static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                                     VkSubpassContents contents) {}

static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {}

static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(VkCommandBuffer commandBuffer) {}

static VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                                     const VkCommandBuffer* pCommandBuffers) {}

static VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(VkDevice device, uint32_t bindInfoCount,
                                                        const VkBindBufferMemoryInfo* pBindInfos) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2(VkDevice device, uint32_t bindInfoCount,
                                                       const VkBindImageMemoryInfo* pBindInfos) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                                                   uint32_t remoteDeviceIndex,
                                                                   VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {}

static VKAPI_ATTR void VKAPI_CALL CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                                  uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                                  uint32_t groupCountZ) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion(VkDevice device,
                                                                   const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   VkSamplerYcbcrConversion* pYcbcrConversion) {
    unique_lock_t lock(global_lock);
    *pYcbcrConversion = (VkSamplerYcbcrConversion)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion,
                                                                const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                       VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                       uint32_t stride) {}

static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                              VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                              uint32_t maxDrawCount, uint32_t stride) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    unique_lock_t lock(global_lock);
    *pRenderPass = (VkRenderPass)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                                      const VkSubpassBeginInfo* pSubpassBeginInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                                  const VkSubpassEndInfo* pSubpassEndInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {}

static VKAPI_ATTR void VKAPI_CALL ResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
}

static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress(VkDevice device,
                                                                          const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount,
                                                                      VkPhysicalDeviceToolProperties* pToolProperties) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            VkPrivateDataSlot* pPrivateDataSlot) {
    unique_lock_t lock(global_lock);
    *pPrivateDataSlot = (VkPrivateDataSlot)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                         const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL SetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle,
                                                     VkPrivateDataSlot privateDataSlot, uint64_t data) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL GetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle,
                                                 VkPrivateDataSlot privateDataSlot, uint64_t* pData) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                               const VkDependencyInfo* pDependencyInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {}

static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                                 const VkDependencyInfo* pDependencyInfos) {}

static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                     VkQueryPool queryPool, uint32_t query) {}

static VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits,
                                                   VkFence fence) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                                        const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                                        const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdEndRendering(VkCommandBuffer commandBuffer) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                          const VkViewport* pViewports) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                         const VkRect2D* pScissors) {}

static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                                        const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                                        const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                                  VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {}

static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements(
    VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetLineStipple(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                    uint16_t lineStipplePattern) {}

static VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer2(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                      VkDeviceSize size, VkIndexType indexType) {}

static VKAPI_ATTR void VKAPI_CALL GetRenderingAreaGranularity(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo,
                                                              VkExtent2D* pGranularity) {}

static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSubresourceLayout(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo,
                                                                  VkSubresourceLayout2* pLayout) {}

static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2(VkDevice device, VkImage image,
                                                             const VkImageSubresource2* pSubresource,
                                                             VkSubresourceLayout2* pLayout) {}

static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSet(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                       VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                                       const VkWriteDescriptorSet* pDescriptorWrites) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetRenderingAttachmentLocations(VkCommandBuffer commandBuffer,
                                                                     const VkRenderingAttachmentLocationInfo* pLocationInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetRenderingInputAttachmentIndices(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets2(VkCommandBuffer commandBuffer,
                                                         const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdPushConstants2(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSet2(VkCommandBuffer commandBuffer,
                                                        const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) {}

static VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToImage(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL CopyImageToMemory(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL CopyImageToImage(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL TransitionImageLayout(VkDevice device, uint32_t transitionCount,
                                                            const VkHostImageLayoutTransitionInfo* pTransitions) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL GetCommandPoolMemoryConsumption(VkDevice device, VkCommandPool commandPool,
                                                                  VkCommandBuffer commandBuffer,
                                                                  VkCommandPoolMemoryConsumption* pConsumption) {}

static VKAPI_ATTR VkResult VKAPI_CALL GetFaultData(VkDevice device, VkFaultQueryBehavior faultQueryBehavior,
                                                   VkBool32* pUnrecordedFaults, uint32_t* pFaultCount, VkFaultData* pFaults) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface,
                                                    const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) { return VK_SUCCESS; }

static VKAPI_ATTR VkResult VKAPI_CALL
GetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface,
                                                                           VkDeviceGroupPresentModeFlagsKHR* pModes) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                            uint32_t* pRectCount, VkRect2D* pRects) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice,
                                                                                 uint32_t* pPropertyCount,
                                                                                 VkDisplayPlanePropertiesKHR* pProperties) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex,
                                                                          uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                                  uint32_t* pPropertyCount,
                                                                  VkDisplayModePropertiesKHR* pProperties) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                           const VkDisplayModeCreateInfoKHR* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) {
    unique_lock_t lock(global_lock);
    *pMode = (VkDisplayModeKHR)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode,
                                                                     uint32_t planeIndex,
                                                                     VkDisplayPlaneCapabilitiesKHR* pCapabilities) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR(VkInstance instance,
                                                                   const VkDisplaySurfaceCreateInfoKHR* pCreateInfo,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   VkSurfaceKHR* pSurface) {
    unique_lock_t lock(global_lock);
    *pSurface = (VkSurfaceKHR)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                                                const VkSwapchainCreateInfoKHR* pCreateInfos,
                                                                const VkAllocationCallbacks* pAllocator,
                                                                VkSwapchainKHR* pSwapchains) {
    unique_lock_t lock(global_lock);
    for (uint32_t i = 0; i < swapchainCount; ++i) {
        pSwapchains[i] = (VkSwapchainKHR)global_unique_handle++;
    }
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType,
                                                               int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR(VkDevice device,
                                                           const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) { return VK_SUCCESS; }

static VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL AcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR(VkDevice device) {}

static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice,
                                                                             uint32_t* pPropertyCount,
                                                                             VkDisplayProperties2KHR* pProperties) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice,
                                                                                  uint32_t* pPropertyCount,
                                                                                  VkDisplayPlaneProperties2KHR* pProperties) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                                   uint32_t* pPropertyCount,
                                                                   VkDisplayModeProperties2KHR* pProperties) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice,
                                                                      const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo,
                                                                      VkDisplayPlaneCapabilities2KHR* pCapabilities) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                                               const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {}

static VKAPI_ATTR void VKAPI_CALL CmdRefreshObjectsKHR(VkCommandBuffer commandBuffer,
                                                       const VkRefreshObjectListKHR* pRefreshObjects) {}

static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceRefreshableObjectTypesKHR(VkPhysicalDevice physicalDevice,
                                                                                 uint32_t* pRefreshableObjectTypeCount,
                                                                                 VkObjectType* pRefreshableObjectTypes) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                                  const VkDependencyInfo* pDependencyInfo) {
    CmdSetEvent2(commandBuffer, event, pDependencyInfo);
}

static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    CmdResetEvent2(commandBuffer, event, stageMask);
}

static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                                    const VkDependencyInfo* pDependencyInfos) {
    CmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    CmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}

static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                        VkQueryPool queryPool, uint32_t query) {
    CmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}

static VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits,
                                                      VkFence fence) {
    return QueueSubmit2(queue, submitCount, pSubmits, fence);
}

static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    CmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}

static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    CmdCopyImage2(commandBuffer, pCopyImageInfo);
}

static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                                           const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    CmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}

static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                                           const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    CmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}

static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    CmdBlitImage2(commandBuffer, pBlitImageInfo);
}

static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    CmdResolveImage2(commandBuffer, pResolveImageInfo);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                       uint16_t lineStipplePattern) {
    CmdSetLineStipple(commandBuffer, lineStippleFactor, lineStipplePattern);
}

static VKAPI_ATTR VkResult VKAPI_CALL GetCalibratedTimestampsKHR(VkDevice device, uint32_t timestampCount,
                                                                 const VkCalibratedTimestampInfoKHR* pTimestampInfos,
                                                                 uint64_t* pTimestamps, uint64_t* pMaxDeviation) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT(VkDevice device, VkDisplayKHR display,
                                                             const VkDisplayPowerInfoEXT* pDisplayPowerInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo,
                                                             const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain,
                                                             VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                                            uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                                                VkDiscardRectangleModeEXT discardRectangleMode) {}

static VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains,
                                                    const VkHdrMetadataEXT* pMetadata) {}

static VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {}

static VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(VkQueue queue) {}

static VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                             const VkDebugUtilsLabelEXT* pLabelInfo) {}

static VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {}

static VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                              const VkDebugUtilsLabelEXT* pLabelInfo) {}

static VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(VkInstance instance,
                                                                   const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   VkDebugUtilsMessengerEXT* pMessenger) {
    unique_lock_t lock(global_lock);
    *pMessenger = (VkDebugUtilsMessengerEXT)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                                                const VkAllocationCallbacks* pAllocator) {}

static VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT(VkInstance instance,
                                                             VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                             VkDebugUtilsMessageTypeFlagsEXT messageTypes,
                                                             const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                                           const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {}

static VKAPI_ATTR VkResult VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image,
                                                                             VkImageDrmFormatModifierPropertiesEXT* pProperties) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateHeadlessSurfaceEXT(VkInstance instance,
                                                               const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo,
                                                               const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    unique_lock_t lock(global_lock);
    *pSurface = (VkSurfaceKHR)global_unique_handle++;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                       uint16_t lineStipplePattern) {
    CmdSetLineStipple(commandBuffer, lineStippleFactor, lineStipplePattern);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    CmdSetCullMode(commandBuffer, cullMode);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    CmdSetFrontFace(commandBuffer, frontFace);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    CmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                             const VkViewport* pViewports) {
    CmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                            const VkRect2D* pScissors) {
    CmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}

static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                           uint32_t bindingCount, const VkBuffer* pBuffers,
                                                           const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                           const VkDeviceSize* pStrides) {
    CmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    CmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    CmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    CmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    CmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    CmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                                     VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    CmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL AcquireWinrtDisplayNV(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetWinrtDisplayNV(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId,
                                                        VkDisplayKHR* pDisplay) {
    return VK_SUCCESS;
}

#endif  // VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                                       const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                                       uint32_t vertexAttributeDescriptionCount,
                                                       const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {}

#ifdef VK_USE_PLATFORM_SCI
static VKAPI_ATTR VkResult VKAPI_CALL GetFenceSciSyncFenceNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo,
                                                             void* pHandle) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetFenceSciSyncObjNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo,
                                                           void* pHandle) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL ImportFenceSciSyncFenceNV(VkDevice device,
                                                                const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL ImportFenceSciSyncObjNV(VkDevice device,
                                                              const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSciSyncAttributesNV(VkPhysicalDevice physicalDevice,
                                                                           const VkSciSyncAttributesInfoNV* pSciSyncAttributesInfo,
                                                                           NvSciSyncAttrList pAttributes) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreSciSyncObjNV(VkDevice device, const VkSemaphoreGetSciSyncInfoNV* pGetSciSyncInfo,
                                                               void* pHandle) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL
ImportSemaphoreSciSyncObjNV(VkDevice device, const VkImportSemaphoreSciSyncInfoNV* pImportSemaphoreSciSyncInfo) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetMemorySciBufNV(VkDevice device, const VkMemoryGetSciBufInfoNV* pGetSciBufInfo,
                                                        NvSciBufObj* pHandle) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL
GetPhysicalDeviceExternalMemorySciBufPropertiesNV(VkPhysicalDevice physicalDevice, VkExternalMemoryHandleTypeFlagBits handleType,
                                                  NvSciBufObj handle, VkMemorySciBufPropertiesNV* pMemorySciBufProperties) {
    return VK_SUCCESS;
}

static VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSciBufAttributesNV(VkPhysicalDevice physicalDevice,
                                                                          NvSciBufAttrList pAttributes) {
    return VK_SUCCESS;
}

#endif  // VK_USE_PLATFORM_SCI
static VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer,
                                                                   VkBool32 rasterizerDiscardEnable) {
    CmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    CmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {}

static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    CmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}

static VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                            const VkBool32* pColorWriteEnables) {}

#ifdef VK_USE_PLATFORM_SCI
static VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphoreSciSyncPoolNV(VkDevice device,
                                                                   const VkSemaphoreSciSyncPoolCreateInfoNV* pCreateInfo,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   VkSemaphoreSciSyncPoolNV* pSemaphorePool) {
    unique_lock_t lock(global_lock);
    *pSemaphorePool = (VkSemaphoreSciSyncPoolNV)global_unique_handle++;
    return VK_SUCCESS;
}

#endif  // VK_USE_PLATFORM_SCI
#ifdef VK_USE_PLATFORM_SCREEN_QNX
static VKAPI_ATTR VkResult VKAPI_CALL GetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer,
                                                                   VkScreenBufferPropertiesQNX* pProperties) {
    return VK_SUCCESS;
}

#endif  // VK_USE_PLATFORM_SCREEN_QNX

}  // namespace icd
// NOLINTEND
