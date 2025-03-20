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

#include "vulkan/vk_enum_string_helper.h"
#include "vulkansc/sc_vuid_enums.h"
#include "vulkansc/core_checks/sc_core_validation.h"

namespace core::sc {

template <typename VkHandleType>
bool Instance::ValidateRemovedCommand(VkHandleType handle, const Location& loc) const {
    (void)LogError(kVUID_SC_RemovedCommand, handle, loc, "command not supported in Vulkan SC");
    return false;
}

bool Device::PreCallValidateCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule,
                                               const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                                const VkAllocationCallbacks* pAllocator, const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount,
                                                const VkPipelineCache* pSrcCaches, const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData,
                                                 const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags,
                                            const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags,
                                               const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator,
                                               const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool,
                                                  const VkAllocationCallbacks* pAllocator, const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator,
                                             const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator,
                                                const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateFreeMemory(VkDevice device, VkDeviceMemory mem, const VkAllocationCallbacks* pAllocator,
                                       const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate,
                                                           const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateCreateDescriptorUpdateTemplateKHR(VkDevice device,
                                                              const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                              const VkAllocationCallbacks* pAllocator,
                                                              VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate,
                                                              const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateDestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet,
                                                            VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData,
                                                            const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet,
                                                               VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                               const void* pData, const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Instance::PreCallValidateGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                           VkImageType type, VkSampleCountFlagBits samples,
                                                                           VkImageUsageFlags usage, VkImageTiling tiling,
                                                                           uint32_t* pPropertyCount,
                                                                           VkSparseImageFormatProperties* pProperties,
                                                                           const ErrorObject& error_obj) const {
    return ValidateRemovedCommand(physicalDevice, error_obj.location);
}

bool Instance::PreCallValidateGetPhysicalDeviceSparseImageFormatProperties2(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount,
    VkSparseImageFormatProperties2* pProperties, const ErrorObject& error_obj) const {
    return ValidateRemovedCommand(physicalDevice, error_obj.location);
}

bool Instance::PreCallValidateGetPhysicalDeviceSparseImageFormatProperties2KHR(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount,
    VkSparseImageFormatProperties2* pProperties, const ErrorObject& error_obj) const {
    return ValidateRemovedCommand(physicalDevice, error_obj.location);
}

bool Device::PreCallValidateGetImageSparseMemoryRequirements(VkDevice device, VkImage image,
                                                             uint32_t* pSparseMemoryRequirementCount,
                                                             VkSparseImageMemoryRequirements* pSparseMemoryRequirements,
                                                             const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateGetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo,
                                                              uint32_t* pSparseMemoryRequirementCount,
                                                              VkSparseImageMemoryRequirements2* pSparseMemoryRequirements,
                                                              const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateGetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo,
                                                                 uint32_t* pSparseMemoryRequirementCount,
                                                                 VkSparseImageMemoryRequirements2* pSparseMemoryRequirements,
                                                                 const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

bool Device::PreCallValidateQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence,
                                            const ErrorObject& error_obj) const {
    return instance_vo_->ValidateRemovedCommand(device, error_obj.location);
}

}  // namespace core::sc
