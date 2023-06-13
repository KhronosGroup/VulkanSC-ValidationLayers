/* Copyright (c) 2022-2023 The Khronos Group Inc.
 * Copyright (c) 2022-2023 RasterGrid Kft.
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

#include <assert.h>
#include <vector>

#include "vk_enum_string_helper.h"
#include "chassis.h"
#include "vulkansc/sc_vuid_enums.h"
#include "vulkansc/core_checks/sc_core_validation.h"

template <typename VkHandle>
bool SCCoreChecks::ValidateRemovedCommand(VkHandle handle, const char* cmd) const {
    (void)LogError(handle, kVUID_SC_RemovedCommand, "%s(): command not supported in Vulkan SC", cmd);
    return false;
}

bool SCCoreChecks::PreCallValidateCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) const {
    return ValidateRemovedCommand(device, "vkCreateShaderModule");
}

bool SCCoreChecks::PreCallValidateDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                                      const VkAllocationCallbacks* pAllocator) const {
    return ValidateRemovedCommand(device, "vkDestroyShaderModule");
}

bool SCCoreChecks::PreCallValidateMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount,
                                                      const VkPipelineCache* pSrcCaches) const {
    return ValidateRemovedCommand(device, "vkMergePipelineCaches");
}

bool SCCoreChecks::PreCallValidateGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize,
                                                       void* pData) const {
    return ValidateRemovedCommand(device, "vkGetPipelineCacheData");
}

bool SCCoreChecks::PreCallValidateTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) const {
    return ValidateRemovedCommand(device, "vkTrimCommandPool");
}

bool SCCoreChecks::PreCallValidateTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool,
                                                     VkCommandPoolTrimFlags flags) const {
    return ValidateRemovedCommand(device, "vkTrimCommandPoolKHR");
}

bool SCCoreChecks::PreCallValidateDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                                     const VkAllocationCallbacks* pAllocator) const {
    return ValidateRemovedCommand(device, "vkDestroyCommandPool");
}

bool SCCoreChecks::PreCallValidateDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool,
                                                        const VkAllocationCallbacks* pAllocator) const {
    return ValidateRemovedCommand(device, "vkDestroyDescriptorPool");
}

bool SCCoreChecks::PreCallValidateDestroyQueryPool(VkDevice device, VkQueryPool queryPool,
                                                   const VkAllocationCallbacks* pAllocator) const {
    return ValidateRemovedCommand(device, "vkDestroyQueryPool");
}

bool SCCoreChecks::PreCallValidateDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain,
                                                      const VkAllocationCallbacks* pAllocator) const {
    return ValidateRemovedCommand(device, "vkDestroySwapchainKHR");
}

bool SCCoreChecks::PreCallValidateFreeMemory(VkDevice device, VkDeviceMemory mem, const VkAllocationCallbacks* pAllocator) const {
    return ValidateRemovedCommand(device, "vkFreeMemory");
}

bool SCCoreChecks::PreCallValidateCreateDescriptorUpdateTemplate(VkDevice device,
                                                                 const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                                 const VkAllocationCallbacks* pAllocator,
                                                                 VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) const {
    return ValidateRemovedCommand(device, "vkCreateDescriptorUpdateTemplate");
}

bool SCCoreChecks::PreCallValidateCreateDescriptorUpdateTemplateKHR(VkDevice device,
                                                                    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                                    const VkAllocationCallbacks* pAllocator,
                                                                    VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) const {
    return ValidateRemovedCommand(device, "vkCreateDescriptorUpdateTemplateKHR");
}

bool SCCoreChecks::PreCallValidateDestroyDescriptorUpdateTemplate(VkDevice device,
                                                                  VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                  const VkAllocationCallbacks* pAllocator) const {
    return ValidateRemovedCommand(device, "vkDestroyDescriptorUpdateTemplate");
}

bool SCCoreChecks::PreCallValidateDestroyDescriptorUpdateTemplateKHR(VkDevice device,
                                                                     VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                     const VkAllocationCallbacks* pAllocator) const {
    return ValidateRemovedCommand(device, "vkDestroyDescriptorUpdateTemplateKHR");
}

bool SCCoreChecks::PreCallValidateUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet,
                                                                  VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                  const void* pData) const {
    return ValidateRemovedCommand(device, "vkUpdateDescriptorSetWithTemplate");
}

bool SCCoreChecks::PreCallValidateUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet,
                                                                     VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                     const void* pData) const {
    return ValidateRemovedCommand(device, "vkUpdateDescriptorSetWithTemplateKHR");
}

bool SCCoreChecks::PreCallValidateGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                               VkImageType type, VkSampleCountFlagBits samples,
                                                                               VkImageUsageFlags usage, VkImageTiling tiling,
                                                                               uint32_t* pPropertyCount,
                                                                               VkSparseImageFormatProperties* pProperties) const {
    return ValidateRemovedCommand(device, "vkGetPhysicalDeviceSparseImageFormatProperties");
}

bool SCCoreChecks::PreCallValidateGetPhysicalDeviceSparseImageFormatProperties2(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount,
    VkSparseImageFormatProperties2* pProperties) const {
    return ValidateRemovedCommand(device, "vkGetPhysicalDeviceSparseImageFormatProperties2");
}

bool SCCoreChecks::PreCallValidateGetPhysicalDeviceSparseImageFormatProperties2KHR(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount,
    VkSparseImageFormatProperties2* pProperties) const {
    return ValidateRemovedCommand(device, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
}

bool SCCoreChecks::PreCallValidateGetImageSparseMemoryRequirements(
    VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements* pSparseMemoryRequirements) const {
    return ValidateRemovedCommand(device, "vkGetImageSparseMemoryRequirements");
}

bool SCCoreChecks::PreCallValidateGetImageSparseMemoryRequirements2(
    VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) const {
    return ValidateRemovedCommand(device, "vkGetImageSparseMemoryRequirements2");
}

bool SCCoreChecks::PreCallValidateGetImageSparseMemoryRequirements2KHR(
    VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) const {
    return ValidateRemovedCommand(device, "vkGetImageSparseMemoryRequirements2KHR");
}

bool SCCoreChecks::PreCallValidateQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo,
                                                  VkFence fence) const {
    return ValidateRemovedCommand(device, "vkQueueBindSparse");
}
