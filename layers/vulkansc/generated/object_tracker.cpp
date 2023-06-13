// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See object_tracker_generator.py for modifications


/***************************************************************************
 *
 * Copyright (c) 2015-2023 The Khronos Group Inc.
 * Copyright (c) 2015-2023 Valve Corporation
 * Copyright (c) 2015-2023 LunarG, Inc.
 * Copyright (c) 2015-2023 Google Inc.
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
 ****************************************************************************/


#include "chassis.h"
#include "object_tracker/object_lifetime_validation.h"

ReadLockGuard ObjectLifetimes::ReadLock() const { return ReadLockGuard(validation_object_mutex, std::defer_lock); }
WriteLockGuard ObjectLifetimes::WriteLock() { return WriteLockGuard(validation_object_mutex, std::defer_lock); }



// ObjectTracker undestroyed objects validation function
bool ObjectLifetimes::ReportUndestroyedInstanceObjects(VkInstance instance) const {
    bool skip = false;
    const std::string error_code = "VUID-vkDestroyInstance-instance-00629";
    skip |= ReportLeakedInstanceObjects(instance, kVulkanObjectTypeSurfaceKHR, error_code);
    // No destroy API -- do not report: skip |= ReportLeakedInstanceObjects(instance, kVulkanObjectTypeDisplayKHR, error_code);
    // No destroy API -- do not report: skip |= ReportLeakedInstanceObjects(instance, kVulkanObjectTypeDisplayModeKHR, error_code);
    skip |= ReportLeakedInstanceObjects(instance, kVulkanObjectTypeDebugReportCallbackEXT, error_code);
    skip |= ReportLeakedInstanceObjects(instance, kVulkanObjectTypeDebugUtilsMessengerEXT, error_code);
    return skip;
}
bool ObjectLifetimes::ReportUndestroyedDeviceObjects(VkDevice device) const {
    bool skip = false;
    const std::string error_code = "VUID-vkDestroyDevice-device-05137";
    // Implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeCommandBuffer, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeBuffer, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeImage, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeSemaphore, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeFence, error_code);
    // Implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeDeviceMemory, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeEvent, error_code);
    // Implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeQueryPool, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeBufferView, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeImageView, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeShaderModule, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypePipelineCache, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypePipelineLayout, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypePipeline, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeRenderPass, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeDescriptorSetLayout, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeSampler, error_code);
    // Implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeDescriptorSet, error_code);
    // Implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeDescriptorPool, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeFramebuffer, error_code);
    // Implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeCommandPool, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeSamplerYcbcrConversion, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeDescriptorUpdateTemplate, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypePrivateDataSlot, error_code);
    // Implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeSwapchainKHR, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeVideoSessionKHR, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeVideoSessionParametersKHR, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeDeferredOperationKHR, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeCuModuleNVX, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeCuFunctionNVX, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeValidationCacheEXT, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeAccelerationStructureNV, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypePerformanceConfigurationINTEL, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeIndirectCommandsLayoutNV, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeAccelerationStructureKHR, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeBufferCollectionFUCHSIA, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeMicromapEXT, error_code);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeOpticalFlowSessionNV, error_code);
    // Implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeSemaphoreSciSyncPoolNV, error_code);
    return skip;
}

void ObjectLifetimes::DestroyLeakedInstanceObjects() {
    DestroyUndestroyedObjects(kVulkanObjectTypeSurfaceKHR);
    DestroyUndestroyedObjects(kVulkanObjectTypeDisplayKHR);
    DestroyUndestroyedObjects(kVulkanObjectTypeDisplayModeKHR);
    DestroyUndestroyedObjects(kVulkanObjectTypeDebugReportCallbackEXT);
    DestroyUndestroyedObjects(kVulkanObjectTypeDebugUtilsMessengerEXT);
}
void ObjectLifetimes::DestroyLeakedDeviceObjects() {
    DestroyUndestroyedObjects(kVulkanObjectTypeCommandBuffer);
    DestroyUndestroyedObjects(kVulkanObjectTypeBuffer);
    DestroyUndestroyedObjects(kVulkanObjectTypeImage);
    DestroyUndestroyedObjects(kVulkanObjectTypeSemaphore);
    DestroyUndestroyedObjects(kVulkanObjectTypeFence);
    DestroyUndestroyedObjects(kVulkanObjectTypeDeviceMemory);
    DestroyUndestroyedObjects(kVulkanObjectTypeEvent);
    DestroyUndestroyedObjects(kVulkanObjectTypeQueryPool);
    DestroyUndestroyedObjects(kVulkanObjectTypeBufferView);
    DestroyUndestroyedObjects(kVulkanObjectTypeImageView);
    DestroyUndestroyedObjects(kVulkanObjectTypeShaderModule);
    DestroyUndestroyedObjects(kVulkanObjectTypePipelineCache);
    DestroyUndestroyedObjects(kVulkanObjectTypePipelineLayout);
    DestroyUndestroyedObjects(kVulkanObjectTypePipeline);
    DestroyUndestroyedObjects(kVulkanObjectTypeRenderPass);
    DestroyUndestroyedObjects(kVulkanObjectTypeDescriptorSetLayout);
    DestroyUndestroyedObjects(kVulkanObjectTypeSampler);
    DestroyUndestroyedObjects(kVulkanObjectTypeDescriptorSet);
    DestroyUndestroyedObjects(kVulkanObjectTypeDescriptorPool);
    DestroyUndestroyedObjects(kVulkanObjectTypeFramebuffer);
    DestroyUndestroyedObjects(kVulkanObjectTypeCommandPool);
    DestroyUndestroyedObjects(kVulkanObjectTypeSamplerYcbcrConversion);
    DestroyUndestroyedObjects(kVulkanObjectTypeDescriptorUpdateTemplate);
    DestroyUndestroyedObjects(kVulkanObjectTypePrivateDataSlot);
    DestroyUndestroyedObjects(kVulkanObjectTypeSwapchainKHR);
    DestroyUndestroyedObjects(kVulkanObjectTypeVideoSessionKHR);
    DestroyUndestroyedObjects(kVulkanObjectTypeVideoSessionParametersKHR);
    DestroyUndestroyedObjects(kVulkanObjectTypeDeferredOperationKHR);
    DestroyUndestroyedObjects(kVulkanObjectTypeCuModuleNVX);
    DestroyUndestroyedObjects(kVulkanObjectTypeCuFunctionNVX);
    DestroyUndestroyedObjects(kVulkanObjectTypeValidationCacheEXT);
    DestroyUndestroyedObjects(kVulkanObjectTypeAccelerationStructureNV);
    DestroyUndestroyedObjects(kVulkanObjectTypePerformanceConfigurationINTEL);
    DestroyUndestroyedObjects(kVulkanObjectTypeIndirectCommandsLayoutNV);
    DestroyUndestroyedObjects(kVulkanObjectTypeAccelerationStructureKHR);
    DestroyUndestroyedObjects(kVulkanObjectTypeBufferCollectionFUCHSIA);
    DestroyUndestroyedObjects(kVulkanObjectTypeMicromapEXT);
    DestroyUndestroyedObjects(kVulkanObjectTypeOpticalFlowSessionNV);
    DestroyUndestroyedObjects(kVulkanObjectTypeSemaphoreSciSyncPoolNV);
}



bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures*                   pFeatures) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceFeatures-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties*                         pFormatProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceFormatProperties-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkImageFormatProperties*                    pImageFormatProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceImageFormatProperties-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties*                 pProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceProperties-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties*           pMemoryProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceMemoryProperties-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetInstanceProcAddr(
    VkInstance                                  instance,
    const char*                                 pName) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, true, "VUID-vkGetInstanceProcAddr-instance-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceProcAddr(
    VkDevice                                    device,
    const char*                                 pName) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetDeviceProcAddr-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateEnumerateDeviceExtensionProperties(
    VkPhysicalDevice                            physicalDevice,
    const char*                                 pLayerName,
    uint32_t*                                   pPropertyCount,
    VkExtensionProperties*                      pProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkEnumerateDeviceExtensionProperties-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateEnumerateDeviceLayerProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkLayerProperties*                          pProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkEnumerateDeviceLayerProperties-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateQueueSubmit(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo*                         pSubmits,
    VkFence                                     fence) const {
    bool skip = false;
    skip |= ValidateObject(queue, kVulkanObjectTypeQueue, false, "VUID-vkQueueSubmit-queue-parameter", "VUID-vkQueueSubmit-commonparent");
    if (pSubmits) {
        for (uint32_t index0 = 0; index0 < submitCount; ++index0) {
            if ((pSubmits[index0].waitSemaphoreCount > 0) && (pSubmits[index0].pWaitSemaphores)) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].waitSemaphoreCount; ++index1) {
                    skip |= ValidateObject(pSubmits[index0].pWaitSemaphores[index1], kVulkanObjectTypeSemaphore, false, "VUID-VkSubmitInfo-pWaitSemaphores-parameter", "VUID-VkSubmitInfo-commonparent");
                }
            }
            if ((pSubmits[index0].commandBufferCount > 0) && (pSubmits[index0].pCommandBuffers)) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].commandBufferCount; ++index1) {
                    skip |= ValidateObject(pSubmits[index0].pCommandBuffers[index1], kVulkanObjectTypeCommandBuffer, false, "VUID-VkSubmitInfo-pCommandBuffers-parameter", "VUID-VkSubmitInfo-commonparent");
                }
            }
            if ((pSubmits[index0].signalSemaphoreCount > 0) && (pSubmits[index0].pSignalSemaphores)) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].signalSemaphoreCount; ++index1) {
                    skip |= ValidateObject(pSubmits[index0].pSignalSemaphores[index1], kVulkanObjectTypeSemaphore, false, "VUID-VkSubmitInfo-pSignalSemaphores-parameter", "VUID-VkSubmitInfo-commonparent");
                }
            }
        }
    }
    skip |= ValidateObject(fence, kVulkanObjectTypeFence, true, "VUID-vkQueueSubmit-fence-parameter", "VUID-vkQueueSubmit-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateQueueWaitIdle(
    VkQueue                                     queue) const {
    bool skip = false;
    skip |= ValidateObject(queue, kVulkanObjectTypeQueue, false, "VUID-vkQueueWaitIdle-queue-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateDeviceWaitIdle(
    VkDevice                                    device) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDeviceWaitIdle-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateAllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDeviceMemory*                             pMemory) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkAllocateMemory-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordAllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDeviceMemory*                             pMemory,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pMemory, kVulkanObjectTypeDeviceMemory, pAllocator);

}

bool ObjectLifetimes::PreCallValidateFreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(memory, kVulkanObjectTypeDeviceMemory, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordFreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(memory, kVulkanObjectTypeDeviceMemory);

}

bool ObjectLifetimes::PreCallValidateMapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    void**                                      ppData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkMapMemory-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, false, "VUID-vkMapMemory-memory-parameter", "VUID-vkMapMemory-memory-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateUnmapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkUnmapMemory-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, false, "VUID-vkUnmapMemory-memory-parameter", "VUID-vkUnmapMemory-memory-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateFlushMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkFlushMappedMemoryRanges-device-parameter", kVUIDUndefined);
    if (pMemoryRanges) {
        for (uint32_t index0 = 0; index0 < memoryRangeCount; ++index0) {
            skip |= ValidateObject(pMemoryRanges[index0].memory, kVulkanObjectTypeDeviceMemory, false, "VUID-VkMappedMemoryRange-memory-parameter", kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateInvalidateMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkInvalidateMappedMemoryRanges-device-parameter", kVUIDUndefined);
    if (pMemoryRanges) {
        for (uint32_t index0 = 0; index0 < memoryRangeCount; ++index0) {
            skip |= ValidateObject(pMemoryRanges[index0].memory, kVulkanObjectTypeDeviceMemory, false, "VUID-VkMappedMemoryRange-memory-parameter", kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceMemoryCommitment(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize*                               pCommittedMemoryInBytes) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetDeviceMemoryCommitment-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, false, "VUID-vkGetDeviceMemoryCommitment-memory-parameter", "VUID-vkGetDeviceMemoryCommitment-memory-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateBindBufferMemory(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkBindBufferMemory-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkBindBufferMemory-buffer-parameter", "VUID-vkBindBufferMemory-buffer-parent");
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, false, "VUID-vkBindBufferMemory-memory-parameter", "VUID-vkBindBufferMemory-memory-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateBindImageMemory(
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkBindImageMemory-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, "VUID-vkBindImageMemory-image-parameter", "VUID-vkBindImageMemory-image-parent");
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, false, "VUID-vkBindImageMemory-memory-parameter", "VUID-vkBindImageMemory-memory-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetBufferMemoryRequirements(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkMemoryRequirements*                       pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetBufferMemoryRequirements-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkGetBufferMemoryRequirements-buffer-parameter", "VUID-vkGetBufferMemoryRequirements-buffer-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    VkMemoryRequirements*                       pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetImageMemoryRequirements-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, "VUID-vkGetImageMemoryRequirements-image-parameter", "VUID-vkGetImageMemoryRequirements-image-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageSparseMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements*            pSparseMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSparseImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties*              pProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateQueueBindSparse(
    VkQueue                                     queue,
    uint32_t                                    bindInfoCount,
    const VkBindSparseInfo*                     pBindInfo,
    VkFence                                     fence) const {
    bool skip = false;
    skip |= ValidateObject(queue, kVulkanObjectTypeQueue, false, kVUIDUndefined, kVUIDUndefined);
    if (pBindInfo) {
        for (uint32_t index0 = 0; index0 < bindInfoCount; ++index0) {
            if ((pBindInfo[index0].waitSemaphoreCount > 0) && (pBindInfo[index0].pWaitSemaphores)) {
                for (uint32_t index1 = 0; index1 < pBindInfo[index0].waitSemaphoreCount; ++index1) {
                    skip |= ValidateObject(pBindInfo[index0].pWaitSemaphores[index1], kVulkanObjectTypeSemaphore, false, kVUIDUndefined, kVUIDUndefined);
                }
            }
            if (pBindInfo[index0].pBufferBinds) {
                for (uint32_t index1 = 0; index1 < pBindInfo[index0].bufferBindCount; ++index1) {
                    skip |= ValidateObject(pBindInfo[index0].pBufferBinds[index1].buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
                    if (pBindInfo[index0].pBufferBinds[index1].pBinds) {
                        for (uint32_t index2 = 0; index2 < pBindInfo[index0].pBufferBinds[index1].bindCount; ++index2) {
                            skip |= ValidateObject(pBindInfo[index0].pBufferBinds[index1].pBinds[index2].memory, kVulkanObjectTypeDeviceMemory, true, kVUIDUndefined, kVUIDUndefined);
                        }
                    }
                }
            }
            if (pBindInfo[index0].pImageOpaqueBinds) {
                for (uint32_t index1 = 0; index1 < pBindInfo[index0].imageOpaqueBindCount; ++index1) {
                    skip |= ValidateObject(pBindInfo[index0].pImageOpaqueBinds[index1].image, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined);
                    if (pBindInfo[index0].pImageOpaqueBinds[index1].pBinds) {
                        for (uint32_t index2 = 0; index2 < pBindInfo[index0].pImageOpaqueBinds[index1].bindCount; ++index2) {
                            skip |= ValidateObject(pBindInfo[index0].pImageOpaqueBinds[index1].pBinds[index2].memory, kVulkanObjectTypeDeviceMemory, true, kVUIDUndefined, kVUIDUndefined);
                        }
                    }
                }
            }
            if (pBindInfo[index0].pImageBinds) {
                for (uint32_t index1 = 0; index1 < pBindInfo[index0].imageBindCount; ++index1) {
                    skip |= ValidateObject(pBindInfo[index0].pImageBinds[index1].image, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined);
                    if (pBindInfo[index0].pImageBinds[index1].pBinds) {
                        for (uint32_t index2 = 0; index2 < pBindInfo[index0].pImageBinds[index1].bindCount; ++index2) {
                            skip |= ValidateObject(pBindInfo[index0].pImageBinds[index1].pBinds[index2].memory, kVulkanObjectTypeDeviceMemory, true, kVUIDUndefined, kVUIDUndefined);
                        }
                    }
                }
            }
            if ((pBindInfo[index0].signalSemaphoreCount > 0) && (pBindInfo[index0].pSignalSemaphores)) {
                for (uint32_t index1 = 0; index1 < pBindInfo[index0].signalSemaphoreCount; ++index1) {
                    skip |= ValidateObject(pBindInfo[index0].pSignalSemaphores[index1], kVulkanObjectTypeSemaphore, false, kVUIDUndefined, kVUIDUndefined);
                }
            }
        }
    }
    skip |= ValidateObject(fence, kVulkanObjectTypeFence, true, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateFence-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pFence, kVulkanObjectTypeFence, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyFence(
    VkDevice                                    device,
    VkFence                                     fence,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroyFence-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(fence, kVulkanObjectTypeFence, true, "VUID-vkDestroyFence-fence-parameter", "VUID-vkDestroyFence-fence-parent");
    skip |= ValidateDestroyObject(fence, kVulkanObjectTypeFence, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyFence(
    VkDevice                                    device,
    VkFence                                     fence,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(fence, kVulkanObjectTypeFence);

}

bool ObjectLifetimes::PreCallValidateResetFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkResetFences-device-parameter", kVUIDUndefined);
    if ((fenceCount > 0) && (pFences)) {
        for (uint32_t index0 = 0; index0 < fenceCount; ++index0) {
            skip |= ValidateObject(pFences[index0], kVulkanObjectTypeFence, false, "VUID-vkResetFences-pFences-parameter", "VUID-vkResetFences-pFences-parent");
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetFenceStatus(
    VkDevice                                    device,
    VkFence                                     fence) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetFenceStatus-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(fence, kVulkanObjectTypeFence, false, "VUID-vkGetFenceStatus-fence-parameter", "VUID-vkGetFenceStatus-fence-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateWaitForFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkWaitForFences-device-parameter", kVUIDUndefined);
    if ((fenceCount > 0) && (pFences)) {
        for (uint32_t index0 = 0; index0 < fenceCount; ++index0) {
            skip |= ValidateObject(pFences[index0], kVulkanObjectTypeFence, false, "VUID-vkWaitForFences-pFences-parameter", "VUID-vkWaitForFences-pFences-parent");
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphore*                                pSemaphore) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateSemaphore-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphore*                                pSemaphore,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSemaphore, kVulkanObjectTypeSemaphore, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroySemaphore-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(semaphore, kVulkanObjectTypeSemaphore, true, "VUID-vkDestroySemaphore-semaphore-parameter", "VUID-vkDestroySemaphore-semaphore-parent");
    skip |= ValidateDestroyObject(semaphore, kVulkanObjectTypeSemaphore, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(semaphore, kVulkanObjectTypeSemaphore);

}

bool ObjectLifetimes::PreCallValidateCreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkEvent*                                    pEvent) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateEvent-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkEvent*                                    pEvent,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pEvent, kVulkanObjectTypeEvent, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroyEvent-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, true, "VUID-vkDestroyEvent-event-parameter", "VUID-vkDestroyEvent-event-parent");
    skip |= ValidateDestroyObject(event, kVulkanObjectTypeEvent, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(event, kVulkanObjectTypeEvent);

}

bool ObjectLifetimes::PreCallValidateGetEventStatus(
    VkDevice                                    device,
    VkEvent                                     event) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetEventStatus-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkGetEventStatus-event-parameter", "VUID-vkGetEventStatus-event-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateSetEvent(
    VkDevice                                    device,
    VkEvent                                     event) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkSetEvent-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkSetEvent-event-parameter", "VUID-vkSetEvent-event-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateResetEvent(
    VkDevice                                    device,
    VkEvent                                     event) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkResetEvent-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkResetEvent-event-parameter", "VUID-vkResetEvent-event-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkQueryPool*                                pQueryPool) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateQueryPool-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkQueryPool*                                pQueryPool,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pQueryPool, kVulkanObjectTypeQueryPool, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(queryPool, kVulkanObjectTypeQueryPool, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(queryPool, kVulkanObjectTypeQueryPool);

}

bool ObjectLifetimes::PreCallValidateGetQueryPoolResults(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    void*                                       pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetQueryPoolResults-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkGetQueryPoolResults-queryPool-parameter", "VUID-vkGetQueryPoolResults-queryPool-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBuffer*                                   pBuffer) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateBuffer-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBuffer*                                   pBuffer,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pBuffer, kVulkanObjectTypeBuffer, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroyBuffer-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, true, "VUID-vkDestroyBuffer-buffer-parameter", "VUID-vkDestroyBuffer-buffer-parent");
    skip |= ValidateDestroyObject(buffer, kVulkanObjectTypeBuffer, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(buffer, kVulkanObjectTypeBuffer);

}

bool ObjectLifetimes::PreCallValidateCreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferView*                               pView) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateBufferView-device-parameter", kVUIDUndefined);
    if (pCreateInfo) {
        skip |= ValidateObject(pCreateInfo->buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferViewCreateInfo-buffer-parameter", kVUIDUndefined);
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferView*                               pView,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pView, kVulkanObjectTypeBufferView, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroyBufferView-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(bufferView, kVulkanObjectTypeBufferView, true, "VUID-vkDestroyBufferView-bufferView-parameter", "VUID-vkDestroyBufferView-bufferView-parent");
    skip |= ValidateDestroyObject(bufferView, kVulkanObjectTypeBufferView, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(bufferView, kVulkanObjectTypeBufferView);

}

bool ObjectLifetimes::PreCallValidateCreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImage*                                    pImage) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateImage-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImage*                                    pImage,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pImage, kVulkanObjectTypeImage, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyImage(
    VkDevice                                    device,
    VkImage                                     image,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroyImage-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(image, kVulkanObjectTypeImage, true, "VUID-vkDestroyImage-image-parameter", "VUID-vkDestroyImage-image-parent");
    skip |= ValidateDestroyObject(image, kVulkanObjectTypeImage, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyImage(
    VkDevice                                    device,
    VkImage                                     image,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(image, kVulkanObjectTypeImage);

}

bool ObjectLifetimes::PreCallValidateGetImageSubresourceLayout(
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource*                   pSubresource,
    VkSubresourceLayout*                        pLayout) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetImageSubresourceLayout-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, "VUID-vkGetImageSubresourceLayout-image-parameter", "VUID-vkGetImageSubresourceLayout-image-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImageView*                                pView) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateImageView-device-parameter", kVUIDUndefined);
    if (pCreateInfo) {
        skip |= ValidateObject(pCreateInfo->image, kVulkanObjectTypeImage, false, "VUID-VkImageViewCreateInfo-image-parameter", kVUIDUndefined);
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImageView*                                pView,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pView, kVulkanObjectTypeImageView, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroyImageView-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(imageView, kVulkanObjectTypeImageView, true, "VUID-vkDestroyImageView-imageView-parameter", "VUID-vkDestroyImageView-imageView-parent");
    skip |= ValidateDestroyObject(imageView, kVulkanObjectTypeImageView, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(imageView, kVulkanObjectTypeImageView);

}

bool ObjectLifetimes::PreCallValidateCreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkShaderModule*                             pShaderModule) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkShaderModule*                             pShaderModule,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pShaderModule, kVulkanObjectTypeShaderModule, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(shaderModule, kVulkanObjectTypeShaderModule, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(shaderModule, kVulkanObjectTypeShaderModule, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(shaderModule, kVulkanObjectTypeShaderModule);

}

bool ObjectLifetimes::PreCallValidateCreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineCache*                            pPipelineCache) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreatePipelineCache-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineCache*                            pPipelineCache,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pPipelineCache, kVulkanObjectTypePipelineCache, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroyPipelineCache-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(pipelineCache, kVulkanObjectTypePipelineCache, true, "VUID-vkDestroyPipelineCache-pipelineCache-parameter", "VUID-vkDestroyPipelineCache-pipelineCache-parent");
    skip |= ValidateDestroyObject(pipelineCache, kVulkanObjectTypePipelineCache, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(pipelineCache, kVulkanObjectTypePipelineCache);

}

bool ObjectLifetimes::PreCallValidateGetPipelineCacheData(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    size_t*                                     pDataSize,
    void*                                       pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(pipelineCache, kVulkanObjectTypePipelineCache, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateMergePipelineCaches(
    VkDevice                                    device,
    VkPipelineCache                             dstCache,
    uint32_t                                    srcCacheCount,
    const VkPipelineCache*                      pSrcCaches) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(dstCache, kVulkanObjectTypePipelineCache, false, kVUIDUndefined, kVUIDUndefined);
    if ((srcCacheCount > 0) && (pSrcCaches)) {
        for (uint32_t index0 = 0; index0 < srcCacheCount; ++index0) {
            skip |= ValidateObject(pSrcCaches[index0], kVulkanObjectTypePipelineCache, false, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateGraphicsPipelines-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(pipelineCache, kVulkanObjectTypePipelineCache, false, "VUID-vkCreateGraphicsPipelines-pipelineCache-parameter", "VUID-vkCreateGraphicsPipelines-pipelineCache-parent");
    if (pCreateInfos) {
        for (uint32_t index0 = 0; index0 < createInfoCount; ++index0) {
            if (pCreateInfos[index0].pStages) {
                for (uint32_t index1 = 0; index1 < pCreateInfos[index0].stageCount; ++index1) {
                    skip |= ValidateObject(pCreateInfos[index0].pStages[index1].module, kVulkanObjectTypeShaderModule, true, "VUID-VkPipelineShaderStageCreateInfo-module-parameter", kVUIDUndefined);
                }
            }
            skip |= ValidateObject(pCreateInfos[index0].layout, kVulkanObjectTypePipelineLayout, true, kVUIDUndefined, "VUID-VkGraphicsPipelineCreateInfo-commonparent");
            skip |= ValidateObject(pCreateInfos[index0].renderPass, kVulkanObjectTypeRenderPass, true, kVUIDUndefined, "VUID-VkGraphicsPipelineCreateInfo-commonparent");
            if ((pCreateInfos[index0].flags & VK_PIPELINE_CREATE_DERIVATIVE_BIT) && (pCreateInfos[index0].basePipelineIndex == -1))
                skip |= ValidateObject(pCreateInfos[index0].basePipelineHandle, kVulkanObjectTypePipeline, false, "VUID-VkGraphicsPipelineCreateInfo-flags-07984", "VUID-VkGraphicsPipelineCreateInfo-commonparent");
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines,
    VkResult                                    result) {
    if (VK_ERROR_VALIDATION_FAILED_EXT == result) return;
    if (pPipelines) {
        for (uint32_t index = 0; index < createInfoCount; index++) {
            if (!pPipelines[index]) continue;
            CreateObject(pPipelines[index], kVulkanObjectTypePipeline, pAllocator);
        }
    }

}

bool ObjectLifetimes::PreCallValidateCreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateComputePipelines-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(pipelineCache, kVulkanObjectTypePipelineCache, false, "VUID-vkCreateComputePipelines-pipelineCache-parameter", "VUID-vkCreateComputePipelines-pipelineCache-parent");
    if (pCreateInfos) {
        for (uint32_t index0 = 0; index0 < createInfoCount; ++index0) {
            skip |= ValidateObject(pCreateInfos[index0].stage.module, kVulkanObjectTypeShaderModule, true, "VUID-VkPipelineShaderStageCreateInfo-module-parameter", kVUIDUndefined);
            skip |= ValidateObject(pCreateInfos[index0].layout, kVulkanObjectTypePipelineLayout, false, "VUID-VkComputePipelineCreateInfo-layout-parameter", "VUID-VkComputePipelineCreateInfo-commonparent");
            if ((pCreateInfos[index0].flags & VK_PIPELINE_CREATE_DERIVATIVE_BIT) && (pCreateInfos[index0].basePipelineIndex == -1))
                skip |= ValidateObject(pCreateInfos[index0].basePipelineHandle, kVulkanObjectTypePipeline, false, "VUID-VkComputePipelineCreateInfo-flags-07984", "VUID-VkComputePipelineCreateInfo-commonparent");
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines,
    VkResult                                    result) {
    if (VK_ERROR_VALIDATION_FAILED_EXT == result) return;
    if (pPipelines) {
        for (uint32_t index = 0; index < createInfoCount; index++) {
            if (!pPipelines[index]) continue;
            CreateObject(pPipelines[index], kVulkanObjectTypePipeline, pAllocator);
        }
    }

}

bool ObjectLifetimes::PreCallValidateDestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroyPipeline-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(pipeline, kVulkanObjectTypePipeline, true, "VUID-vkDestroyPipeline-pipeline-parameter", "VUID-vkDestroyPipeline-pipeline-parent");
    skip |= ValidateDestroyObject(pipeline, kVulkanObjectTypePipeline, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(pipeline, kVulkanObjectTypePipeline);

}

bool ObjectLifetimes::PreCallValidateCreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineLayout*                           pPipelineLayout) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreatePipelineLayout-device-parameter", kVUIDUndefined);
    if (pCreateInfo) {
        if ((pCreateInfo->setLayoutCount > 0) && (pCreateInfo->pSetLayouts)) {
            for (uint32_t index1 = 0; index1 < pCreateInfo->setLayoutCount; ++index1) {
                skip |= ValidateObject(pCreateInfo->pSetLayouts[index1], kVulkanObjectTypeDescriptorSetLayout, true, "VUID-VkPipelineLayoutCreateInfo-pSetLayouts-parameter", kVUIDUndefined);
            }
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineLayout*                           pPipelineLayout,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pPipelineLayout, kVulkanObjectTypePipelineLayout, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroyPipelineLayout-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(pipelineLayout, kVulkanObjectTypePipelineLayout, true, "VUID-vkDestroyPipelineLayout-pipelineLayout-parameter", "VUID-vkDestroyPipelineLayout-pipelineLayout-parent");
    skip |= ValidateDestroyObject(pipelineLayout, kVulkanObjectTypePipelineLayout, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(pipelineLayout, kVulkanObjectTypePipelineLayout);

}

bool ObjectLifetimes::PreCallValidateCreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSampler*                                  pSampler) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateSampler-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSampler*                                  pSampler,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSampler, kVulkanObjectTypeSampler, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroySampler-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(sampler, kVulkanObjectTypeSampler, true, "VUID-vkDestroySampler-sampler-parameter", "VUID-vkDestroySampler-sampler-parent");
    skip |= ValidateDestroyObject(sampler, kVulkanObjectTypeSampler, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(sampler, kVulkanObjectTypeSampler);

}

bool ObjectLifetimes::PreCallValidateDestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroyDescriptorSetLayout-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(descriptorSetLayout, kVulkanObjectTypeDescriptorSetLayout, true, "VUID-vkDestroyDescriptorSetLayout-descriptorSetLayout-parameter", "VUID-vkDestroyDescriptorSetLayout-descriptorSetLayout-parent");
    skip |= ValidateDestroyObject(descriptorSetLayout, kVulkanObjectTypeDescriptorSetLayout, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(descriptorSetLayout, kVulkanObjectTypeDescriptorSetLayout);

}

bool ObjectLifetimes::PreCallValidateCreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorPool*                           pDescriptorPool) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateDescriptorPool-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorPool*                           pDescriptorPool,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pDescriptorPool, kVulkanObjectTypeDescriptorPool, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroyFramebuffer-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(framebuffer, kVulkanObjectTypeFramebuffer, true, "VUID-vkDestroyFramebuffer-framebuffer-parameter", "VUID-vkDestroyFramebuffer-framebuffer-parent");
    skip |= ValidateDestroyObject(framebuffer, kVulkanObjectTypeFramebuffer, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(framebuffer, kVulkanObjectTypeFramebuffer);

}

bool ObjectLifetimes::PreCallValidateCreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateRenderPass-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pRenderPass, kVulkanObjectTypeRenderPass, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroyRenderPass-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(renderPass, kVulkanObjectTypeRenderPass, true, "VUID-vkDestroyRenderPass-renderPass-parameter", "VUID-vkDestroyRenderPass-renderPass-parent");
    skip |= ValidateDestroyObject(renderPass, kVulkanObjectTypeRenderPass, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(renderPass, kVulkanObjectTypeRenderPass);

}

bool ObjectLifetimes::PreCallValidateGetRenderAreaGranularity(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    VkExtent2D*                                 pGranularity) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetRenderAreaGranularity-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(renderPass, kVulkanObjectTypeRenderPass, false, "VUID-vkGetRenderAreaGranularity-renderPass-parameter", "VUID-vkGetRenderAreaGranularity-renderPass-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCommandPool*                              pCommandPool) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateCommandPool-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCommandPool*                              pCommandPool,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pCommandPool, kVulkanObjectTypeCommandPool, pAllocator);

}

bool ObjectLifetimes::PreCallValidateResetCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkResetCommandPool-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(commandPool, kVulkanObjectTypeCommandPool, false, "VUID-vkResetCommandPool-commandPool-parameter", "VUID-vkResetCommandPool-commandPool-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateEndCommandBuffer(
    VkCommandBuffer                             commandBuffer) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkEndCommandBuffer-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateResetCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkResetCommandBuffer-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBindPipeline-commandBuffer-parameter", "VUID-vkCmdBindPipeline-commonparent");
    skip |= ValidateObject(pipeline, kVulkanObjectTypePipeline, false, "VUID-vkCmdBindPipeline-pipeline-parameter", "VUID-vkCmdBindPipeline-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetViewport-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetScissor-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetLineWidth-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDepthBias-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4]) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetBlendConstants-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDepthBounds-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetStencilCompareMask-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetStencilWriteMask-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetStencilReference-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBindDescriptorSets-commandBuffer-parameter", "VUID-vkCmdBindDescriptorSets-commonparent");
    skip |= ValidateObject(layout, kVulkanObjectTypePipelineLayout, false, "VUID-vkCmdBindDescriptorSets-layout-parameter", "VUID-vkCmdBindDescriptorSets-commonparent");
    if ((descriptorSetCount > 0) && (pDescriptorSets)) {
        for (uint32_t index0 = 0; index0 < descriptorSetCount; ++index0) {
            skip |= ValidateObject(pDescriptorSets[index0], kVulkanObjectTypeDescriptorSet, true, "VUID-vkCmdBindDescriptorSets-pDescriptorSets-parameter", "VUID-vkCmdBindDescriptorSets-commonparent");
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBindIndexBuffer-commandBuffer-parameter", "VUID-vkCmdBindIndexBuffer-commonparent");
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdBindIndexBuffer-buffer-parameter", "VUID-vkCmdBindIndexBuffer-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBindVertexBuffers-commandBuffer-parameter", "VUID-vkCmdBindVertexBuffers-commonparent");
    if ((bindingCount > 0) && (pBuffers)) {
        for (uint32_t index0 = 0; index0 < bindingCount; ++index0) {
            skip |= ValidateObject(pBuffers[index0], kVulkanObjectTypeBuffer, true, "VUID-vkCmdBindVertexBuffers-pBuffers-parameter", "VUID-vkCmdBindVertexBuffers-commonparent");
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDraw-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDrawIndexed-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDrawIndirect-commandBuffer-parameter", "VUID-vkCmdDrawIndirect-commonparent");
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndirect-buffer-parameter", "VUID-vkCmdDrawIndirect-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDrawIndexedIndirect-commandBuffer-parameter", "VUID-vkCmdDrawIndexedIndirect-commonparent");
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndexedIndirect-buffer-parameter", "VUID-vkCmdDrawIndexedIndirect-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDispatch-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDispatchIndirect-commandBuffer-parameter", "VUID-vkCmdDispatchIndirect-commonparent");
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDispatchIndirect-buffer-parameter", "VUID-vkCmdDispatchIndirect-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyBuffer-commandBuffer-parameter", "VUID-vkCmdCopyBuffer-commonparent");
    skip |= ValidateObject(srcBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdCopyBuffer-srcBuffer-parameter", "VUID-vkCmdCopyBuffer-commonparent");
    skip |= ValidateObject(dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdCopyBuffer-dstBuffer-parameter", "VUID-vkCmdCopyBuffer-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyImage-commandBuffer-parameter", "VUID-vkCmdCopyImage-commonparent");
    skip |= ValidateObject(srcImage, kVulkanObjectTypeImage, false, "VUID-vkCmdCopyImage-srcImage-parameter", "VUID-vkCmdCopyImage-commonparent");
    skip |= ValidateObject(dstImage, kVulkanObjectTypeImage, false, "VUID-vkCmdCopyImage-dstImage-parameter", "VUID-vkCmdCopyImage-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBlitImage-commandBuffer-parameter", "VUID-vkCmdBlitImage-commonparent");
    skip |= ValidateObject(srcImage, kVulkanObjectTypeImage, false, "VUID-vkCmdBlitImage-srcImage-parameter", "VUID-vkCmdBlitImage-commonparent");
    skip |= ValidateObject(dstImage, kVulkanObjectTypeImage, false, "VUID-vkCmdBlitImage-dstImage-parameter", "VUID-vkCmdBlitImage-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyBufferToImage-commandBuffer-parameter", "VUID-vkCmdCopyBufferToImage-commonparent");
    skip |= ValidateObject(srcBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdCopyBufferToImage-srcBuffer-parameter", "VUID-vkCmdCopyBufferToImage-commonparent");
    skip |= ValidateObject(dstImage, kVulkanObjectTypeImage, false, "VUID-vkCmdCopyBufferToImage-dstImage-parameter", "VUID-vkCmdCopyBufferToImage-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyImageToBuffer-commandBuffer-parameter", "VUID-vkCmdCopyImageToBuffer-commonparent");
    skip |= ValidateObject(srcImage, kVulkanObjectTypeImage, false, "VUID-vkCmdCopyImageToBuffer-srcImage-parameter", "VUID-vkCmdCopyImageToBuffer-commonparent");
    skip |= ValidateObject(dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdCopyImageToBuffer-dstBuffer-parameter", "VUID-vkCmdCopyImageToBuffer-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdUpdateBuffer-commandBuffer-parameter", "VUID-vkCmdUpdateBuffer-commonparent");
    skip |= ValidateObject(dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdUpdateBuffer-dstBuffer-parameter", "VUID-vkCmdUpdateBuffer-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdFillBuffer-commandBuffer-parameter", "VUID-vkCmdFillBuffer-commonparent");
    skip |= ValidateObject(dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdFillBuffer-dstBuffer-parameter", "VUID-vkCmdFillBuffer-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdClearColorImage-commandBuffer-parameter", "VUID-vkCmdClearColorImage-commonparent");
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, "VUID-vkCmdClearColorImage-image-parameter", "VUID-vkCmdClearColorImage-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdClearDepthStencilImage-commandBuffer-parameter", "VUID-vkCmdClearDepthStencilImage-commonparent");
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, "VUID-vkCmdClearDepthStencilImage-image-parameter", "VUID-vkCmdClearDepthStencilImage-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdClearAttachments-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdResolveImage-commandBuffer-parameter", "VUID-vkCmdResolveImage-commonparent");
    skip |= ValidateObject(srcImage, kVulkanObjectTypeImage, false, "VUID-vkCmdResolveImage-srcImage-parameter", "VUID-vkCmdResolveImage-commonparent");
    skip |= ValidateObject(dstImage, kVulkanObjectTypeImage, false, "VUID-vkCmdResolveImage-dstImage-parameter", "VUID-vkCmdResolveImage-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetEvent-commandBuffer-parameter", "VUID-vkCmdSetEvent-commonparent");
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkCmdSetEvent-event-parameter", "VUID-vkCmdSetEvent-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdResetEvent-commandBuffer-parameter", "VUID-vkCmdResetEvent-commonparent");
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkCmdResetEvent-event-parameter", "VUID-vkCmdResetEvent-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWaitEvents(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdWaitEvents-commandBuffer-parameter", "VUID-vkCmdWaitEvents-commonparent");
    if ((eventCount > 0) && (pEvents)) {
        for (uint32_t index0 = 0; index0 < eventCount; ++index0) {
            skip |= ValidateObject(pEvents[index0], kVulkanObjectTypeEvent, false, "VUID-vkCmdWaitEvents-pEvents-parameter", "VUID-vkCmdWaitEvents-commonparent");
        }
    }
    if (pBufferMemoryBarriers) {
        for (uint32_t index0 = 0; index0 < bufferMemoryBarrierCount; ++index0) {
            skip |= ValidateObject(pBufferMemoryBarriers[index0].buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferMemoryBarrier-buffer-parameter", kVUIDUndefined);
        }
    }
    if (pImageMemoryBarriers) {
        for (uint32_t index0 = 0; index0 < imageMemoryBarrierCount; ++index0) {
            skip |= ValidateObject(pImageMemoryBarriers[index0].image, kVulkanObjectTypeImage, false, "VUID-VkImageMemoryBarrier-image-parameter", kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdPipelineBarrier-commandBuffer-parameter", kVUIDUndefined);
    if (pBufferMemoryBarriers) {
        for (uint32_t index0 = 0; index0 < bufferMemoryBarrierCount; ++index0) {
            skip |= ValidateObject(pBufferMemoryBarriers[index0].buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferMemoryBarrier-buffer-parameter", kVUIDUndefined);
        }
    }
    if (pImageMemoryBarriers) {
        for (uint32_t index0 = 0; index0 < imageMemoryBarrierCount; ++index0) {
            skip |= ValidateObject(pImageMemoryBarriers[index0].image, kVulkanObjectTypeImage, false, "VUID-VkImageMemoryBarrier-image-parameter", kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBeginQuery-commandBuffer-parameter", "VUID-vkCmdBeginQuery-commonparent");
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdBeginQuery-queryPool-parameter", "VUID-vkCmdBeginQuery-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdEndQuery-commandBuffer-parameter", "VUID-vkCmdEndQuery-commonparent");
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdEndQuery-queryPool-parameter", "VUID-vkCmdEndQuery-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdResetQueryPool-commandBuffer-parameter", "VUID-vkCmdResetQueryPool-commonparent");
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdResetQueryPool-queryPool-parameter", "VUID-vkCmdResetQueryPool-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdWriteTimestamp-commandBuffer-parameter", "VUID-vkCmdWriteTimestamp-commonparent");
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdWriteTimestamp-queryPool-parameter", "VUID-vkCmdWriteTimestamp-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyQueryPoolResults-commandBuffer-parameter", "VUID-vkCmdCopyQueryPoolResults-commonparent");
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdCopyQueryPoolResults-queryPool-parameter", "VUID-vkCmdCopyQueryPoolResults-commonparent");
    skip |= ValidateObject(dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdCopyQueryPoolResults-dstBuffer-parameter", "VUID-vkCmdCopyQueryPoolResults-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdPushConstants-commandBuffer-parameter", "VUID-vkCmdPushConstants-commonparent");
    skip |= ValidateObject(layout, kVulkanObjectTypePipelineLayout, false, "VUID-vkCmdPushConstants-layout-parameter", "VUID-vkCmdPushConstants-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBeginRenderPass-commandBuffer-parameter", kVUIDUndefined);
    if (pRenderPassBegin) {
        skip |= ValidateObject(pRenderPassBegin->renderPass, kVulkanObjectTypeRenderPass, false, "VUID-VkRenderPassBeginInfo-renderPass-parameter", "VUID-VkRenderPassBeginInfo-commonparent");
        skip |= ValidateObject(pRenderPassBegin->framebuffer, kVulkanObjectTypeFramebuffer, false, "VUID-VkRenderPassBeginInfo-framebuffer-parameter", "VUID-VkRenderPassBeginInfo-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdNextSubpass-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndRenderPass(
    VkCommandBuffer                             commandBuffer) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdEndRenderPass-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdExecuteCommands-commandBuffer-parameter", "VUID-vkCmdExecuteCommands-commonparent");
    if ((commandBufferCount > 0) && (pCommandBuffers)) {
        for (uint32_t index0 = 0; index0 < commandBufferCount; ++index0) {
            skip |= ValidateObject(pCommandBuffers[index0], kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdExecuteCommands-pCommandBuffers-parameter", "VUID-vkCmdExecuteCommands-commonparent");
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateBindBufferMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkBindBufferMemory2-device-parameter", kVUIDUndefined);
    if (pBindInfos) {
        for (uint32_t index0 = 0; index0 < bindInfoCount; ++index0) {
            skip |= ValidateObject(pBindInfos[index0].buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBindBufferMemoryInfo-buffer-parameter", "VUID-VkBindBufferMemoryInfo-commonparent");
            skip |= ValidateObject(pBindInfos[index0].memory, kVulkanObjectTypeDeviceMemory, false, "VUID-VkBindBufferMemoryInfo-memory-parameter", "VUID-VkBindBufferMemoryInfo-commonparent");
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateBindImageMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkBindImageMemory2-device-parameter", kVUIDUndefined);
    if (pBindInfos) {
        for (uint32_t index0 = 0; index0 < bindInfoCount; ++index0) {
            skip |= ValidateObject(pBindInfos[index0].image, kVulkanObjectTypeImage, false, "VUID-VkBindImageMemoryInfo-image-parameter", "VUID-VkBindImageMemoryInfo-commonparent");
            skip |= ValidateObject(pBindInfos[index0].memory, kVulkanObjectTypeDeviceMemory, true, kVUIDUndefined, "VUID-VkBindImageMemoryInfo-commonparent");
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceGroupPeerMemoryFeatures(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetDeviceGroupPeerMemoryFeatures-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDeviceMask-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDispatchBase-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateEnumeratePhysicalDeviceGroups(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, "VUID-vkEnumeratePhysicalDeviceGroups-instance-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordEnumeratePhysicalDeviceGroups(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties,
    VkResult                                    result) {
    if (result != VK_SUCCESS && result != VK_INCOMPLETE) return;
    if (pPhysicalDeviceGroupProperties) {
        for (uint32_t device_group_index = 0; device_group_index < *pPhysicalDeviceGroupCount; device_group_index++) {
            PostCallRecordEnumeratePhysicalDevices(instance, &pPhysicalDeviceGroupProperties[device_group_index].physicalDeviceCount, pPhysicalDeviceGroupProperties[device_group_index].physicalDevices, VK_SUCCESS);
        }
    }

}

bool ObjectLifetimes::PreCallValidateGetImageMemoryRequirements2(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetImageMemoryRequirements2-device-parameter", kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->image, kVulkanObjectTypeImage, false, "VUID-VkImageMemoryRequirementsInfo2-image-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetBufferMemoryRequirements2(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetBufferMemoryRequirements2-device-parameter", kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferMemoryRequirementsInfo2-buffer-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageSparseMemoryRequirements2(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->image, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceFeatures2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceFeatures2-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceProperties2-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceFormatProperties2-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceImageFormatProperties2-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceMemoryProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceMemoryProperties2-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSparseImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateTrimCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(commandPool, kVulkanObjectTypeCommandPool, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateSamplerYcbcrConversion(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateSamplerYcbcrConversion-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateSamplerYcbcrConversion(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pYcbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroySamplerYcbcrConversion(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroySamplerYcbcrConversion-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(ycbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion, true, "VUID-vkDestroySamplerYcbcrConversion-ycbcrConversion-parameter", "VUID-vkDestroySamplerYcbcrConversion-ycbcrConversion-parent");
    skip |= ValidateDestroyObject(ycbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroySamplerYcbcrConversion(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(ycbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion);

}

bool ObjectLifetimes::PreCallValidateDestroyDescriptorUpdateTemplate(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(descriptorUpdateTemplate, kVulkanObjectTypeDescriptorUpdateTemplate, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(descriptorUpdateTemplate, kVulkanObjectTypeDescriptorUpdateTemplate, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyDescriptorUpdateTemplate(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(descriptorUpdateTemplate, kVulkanObjectTypeDescriptorUpdateTemplate);

}

bool ObjectLifetimes::PreCallValidateUpdateDescriptorSetWithTemplate(
    VkDevice                                    device,
    VkDescriptorSet                             descriptorSet,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const void*                                 pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(descriptorSet, kVulkanObjectTypeDescriptorSet, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(descriptorUpdateTemplate, kVulkanObjectTypeDescriptorUpdateTemplate, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceExternalBufferProperties-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceExternalFenceProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceExternalFenceProperties-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceExternalSemaphoreProperties-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDrawIndirectCount-commandBuffer-parameter", "VUID-vkCmdDrawIndirectCount-commonparent");
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndirectCount-buffer-parameter", "VUID-vkCmdDrawIndirectCount-commonparent");
    skip |= ValidateObject(countBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndirectCount-countBuffer-parameter", "VUID-vkCmdDrawIndirectCount-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndexedIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDrawIndexedIndirectCount-commandBuffer-parameter", "VUID-vkCmdDrawIndexedIndirectCount-commonparent");
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndexedIndirectCount-buffer-parameter", "VUID-vkCmdDrawIndexedIndirectCount-commonparent");
    skip |= ValidateObject(countBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndexedIndirectCount-countBuffer-parameter", "VUID-vkCmdDrawIndexedIndirectCount-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateRenderPass2(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateRenderPass2-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateRenderPass2(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pRenderPass, kVulkanObjectTypeRenderPass, pAllocator);

}

bool ObjectLifetimes::PreCallValidateCmdBeginRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBeginRenderPass2-commandBuffer-parameter", kVUIDUndefined);
    if (pRenderPassBegin) {
        skip |= ValidateObject(pRenderPassBegin->renderPass, kVulkanObjectTypeRenderPass, false, "VUID-VkRenderPassBeginInfo-renderPass-parameter", "VUID-VkRenderPassBeginInfo-commonparent");
        skip |= ValidateObject(pRenderPassBegin->framebuffer, kVulkanObjectTypeFramebuffer, false, "VUID-VkRenderPassBeginInfo-framebuffer-parameter", "VUID-VkRenderPassBeginInfo-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdNextSubpass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdNextSubpass2-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdEndRenderPass2-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateResetQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkResetQueryPool-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkResetQueryPool-queryPool-parameter", "VUID-vkResetQueryPool-queryPool-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetSemaphoreCounterValue(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    uint64_t*                                   pValue) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetSemaphoreCounterValue-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(semaphore, kVulkanObjectTypeSemaphore, false, "VUID-vkGetSemaphoreCounterValue-semaphore-parameter", "VUID-vkGetSemaphoreCounterValue-semaphore-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateWaitSemaphores(
    VkDevice                                    device,
    const VkSemaphoreWaitInfo*                  pWaitInfo,
    uint64_t                                    timeout) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkWaitSemaphores-device-parameter", kVUIDUndefined);
    if (pWaitInfo) {
        if ((pWaitInfo->semaphoreCount > 0) && (pWaitInfo->pSemaphores)) {
            for (uint32_t index1 = 0; index1 < pWaitInfo->semaphoreCount; ++index1) {
                skip |= ValidateObject(pWaitInfo->pSemaphores[index1], kVulkanObjectTypeSemaphore, false, "VUID-VkSemaphoreWaitInfo-pSemaphores-parameter", kVUIDUndefined);
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateSignalSemaphore(
    VkDevice                                    device,
    const VkSemaphoreSignalInfo*                pSignalInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkSignalSemaphore-device-parameter", kVUIDUndefined);
    if (pSignalInfo) {
        skip |= ValidateObject(pSignalInfo->semaphore, kVulkanObjectTypeSemaphore, false, "VUID-VkSemaphoreSignalInfo-semaphore-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetBufferDeviceAddress(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetBufferDeviceAddress-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetBufferOpaqueCaptureAddress(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetBufferOpaqueCaptureAddress-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceMemoryOpaqueCaptureAddress(
    VkDevice                                    device,
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetDeviceMemoryOpaqueCaptureAddress-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceToolProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pToolCount,
    VkPhysicalDeviceToolProperties*             pToolProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreatePrivateDataSlot(
    VkDevice                                    device,
    const VkPrivateDataSlotCreateInfo*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPrivateDataSlot*                          pPrivateDataSlot) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreatePrivateDataSlot(
    VkDevice                                    device,
    const VkPrivateDataSlotCreateInfo*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPrivateDataSlot*                          pPrivateDataSlot,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pPrivateDataSlot, kVulkanObjectTypePrivateDataSlot, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyPrivateDataSlot(
    VkDevice                                    device,
    VkPrivateDataSlot                           privateDataSlot,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyPrivateDataSlot(
    VkDevice                                    device,
    VkPrivateDataSlot                           privateDataSlot,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot);

}

bool ObjectLifetimes::PreCallValidateSetPrivateData(
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t                                    data) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPrivateData(
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t*                                   pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetEvent2-commandBuffer-parameter", "VUID-vkCmdSetEvent2-commonparent");
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkCmdSetEvent2-event-parameter", "VUID-vkCmdSetEvent2-commonparent");
    if (pDependencyInfo) {
        if (pDependencyInfo->pBufferMemoryBarriers) {
            for (uint32_t index1 = 0; index1 < pDependencyInfo->bufferMemoryBarrierCount; ++index1) {
                skip |= ValidateObject(pDependencyInfo->pBufferMemoryBarriers[index1].buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferMemoryBarrier2-buffer-parameter", kVUIDUndefined);
            }
        }
        if (pDependencyInfo->pImageMemoryBarriers) {
            for (uint32_t index1 = 0; index1 < pDependencyInfo->imageMemoryBarrierCount; ++index1) {
                skip |= ValidateObject(pDependencyInfo->pImageMemoryBarriers[index1].image, kVulkanObjectTypeImage, false, "VUID-VkImageMemoryBarrier2-image-parameter", kVUIDUndefined);
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdResetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdResetEvent2-commandBuffer-parameter", "VUID-vkCmdResetEvent2-commonparent");
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkCmdResetEvent2-event-parameter", "VUID-vkCmdResetEvent2-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWaitEvents2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdWaitEvents2-commandBuffer-parameter", "VUID-vkCmdWaitEvents2-commonparent");
    if ((eventCount > 0) && (pEvents)) {
        for (uint32_t index0 = 0; index0 < eventCount; ++index0) {
            skip |= ValidateObject(pEvents[index0], kVulkanObjectTypeEvent, false, "VUID-vkCmdWaitEvents2-pEvents-parameter", "VUID-vkCmdWaitEvents2-commonparent");
        }
    }
    if (pDependencyInfos) {
        for (uint32_t index0 = 0; index0 < eventCount; ++index0) {
            if (pDependencyInfos[index0].pBufferMemoryBarriers) {
                for (uint32_t index1 = 0; index1 < pDependencyInfos[index0].bufferMemoryBarrierCount; ++index1) {
                    skip |= ValidateObject(pDependencyInfos[index0].pBufferMemoryBarriers[index1].buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferMemoryBarrier2-buffer-parameter", kVUIDUndefined);
                }
            }
            if (pDependencyInfos[index0].pImageMemoryBarriers) {
                for (uint32_t index1 = 0; index1 < pDependencyInfos[index0].imageMemoryBarrierCount; ++index1) {
                    skip |= ValidateObject(pDependencyInfos[index0].pImageMemoryBarriers[index1].image, kVulkanObjectTypeImage, false, "VUID-VkImageMemoryBarrier2-image-parameter", kVUIDUndefined);
                }
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdPipelineBarrier2(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdPipelineBarrier2-commandBuffer-parameter", kVUIDUndefined);
    if (pDependencyInfo) {
        if (pDependencyInfo->pBufferMemoryBarriers) {
            for (uint32_t index1 = 0; index1 < pDependencyInfo->bufferMemoryBarrierCount; ++index1) {
                skip |= ValidateObject(pDependencyInfo->pBufferMemoryBarriers[index1].buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferMemoryBarrier2-buffer-parameter", kVUIDUndefined);
            }
        }
        if (pDependencyInfo->pImageMemoryBarriers) {
            for (uint32_t index1 = 0; index1 < pDependencyInfo->imageMemoryBarrierCount; ++index1) {
                skip |= ValidateObject(pDependencyInfo->pImageMemoryBarriers[index1].image, kVulkanObjectTypeImage, false, "VUID-VkImageMemoryBarrier2-image-parameter", kVUIDUndefined);
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWriteTimestamp2(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdWriteTimestamp2-commandBuffer-parameter", "VUID-vkCmdWriteTimestamp2-commonparent");
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdWriteTimestamp2-queryPool-parameter", "VUID-vkCmdWriteTimestamp2-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateQueueSubmit2(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo2*                        pSubmits,
    VkFence                                     fence) const {
    bool skip = false;
    skip |= ValidateObject(queue, kVulkanObjectTypeQueue, false, "VUID-vkQueueSubmit2-queue-parameter", "VUID-vkQueueSubmit2-commonparent");
    if (pSubmits) {
        for (uint32_t index0 = 0; index0 < submitCount; ++index0) {
            if (pSubmits[index0].pWaitSemaphoreInfos) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].waitSemaphoreInfoCount; ++index1) {
                    skip |= ValidateObject(pSubmits[index0].pWaitSemaphoreInfos[index1].semaphore, kVulkanObjectTypeSemaphore, false, "VUID-VkSemaphoreSubmitInfo-semaphore-parameter", kVUIDUndefined);
                }
            }
            if (pSubmits[index0].pCommandBufferInfos) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].commandBufferInfoCount; ++index1) {
                    skip |= ValidateObject(pSubmits[index0].pCommandBufferInfos[index1].commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-VkCommandBufferSubmitInfo-commandBuffer-parameter", kVUIDUndefined);
                }
            }
            if (pSubmits[index0].pSignalSemaphoreInfos) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].signalSemaphoreInfoCount; ++index1) {
                    skip |= ValidateObject(pSubmits[index0].pSignalSemaphoreInfos[index1].semaphore, kVulkanObjectTypeSemaphore, false, "VUID-VkSemaphoreSubmitInfo-semaphore-parameter", kVUIDUndefined);
                }
            }
        }
    }
    skip |= ValidateObject(fence, kVulkanObjectTypeFence, true, "VUID-vkQueueSubmit2-fence-parameter", "VUID-vkQueueSubmit2-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyBuffer2-commandBuffer-parameter", kVUIDUndefined);
    if (pCopyBufferInfo) {
        skip |= ValidateObject(pCopyBufferInfo->srcBuffer, kVulkanObjectTypeBuffer, false, "VUID-VkCopyBufferInfo2-srcBuffer-parameter", "VUID-VkCopyBufferInfo2-commonparent");
        skip |= ValidateObject(pCopyBufferInfo->dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-VkCopyBufferInfo2-dstBuffer-parameter", "VUID-VkCopyBufferInfo2-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyImage2-commandBuffer-parameter", kVUIDUndefined);
    if (pCopyImageInfo) {
        skip |= ValidateObject(pCopyImageInfo->srcImage, kVulkanObjectTypeImage, false, "VUID-VkCopyImageInfo2-srcImage-parameter", "VUID-VkCopyImageInfo2-commonparent");
        skip |= ValidateObject(pCopyImageInfo->dstImage, kVulkanObjectTypeImage, false, "VUID-VkCopyImageInfo2-dstImage-parameter", "VUID-VkCopyImageInfo2-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyBufferToImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyBufferToImage2-commandBuffer-parameter", kVUIDUndefined);
    if (pCopyBufferToImageInfo) {
        skip |= ValidateObject(pCopyBufferToImageInfo->srcBuffer, kVulkanObjectTypeBuffer, false, "VUID-VkCopyBufferToImageInfo2-srcBuffer-parameter", "VUID-VkCopyBufferToImageInfo2-commonparent");
        skip |= ValidateObject(pCopyBufferToImageInfo->dstImage, kVulkanObjectTypeImage, false, "VUID-VkCopyBufferToImageInfo2-dstImage-parameter", "VUID-VkCopyBufferToImageInfo2-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyImageToBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyImageToBuffer2-commandBuffer-parameter", kVUIDUndefined);
    if (pCopyImageToBufferInfo) {
        skip |= ValidateObject(pCopyImageToBufferInfo->srcImage, kVulkanObjectTypeImage, false, "VUID-VkCopyImageToBufferInfo2-srcImage-parameter", "VUID-VkCopyImageToBufferInfo2-commonparent");
        skip |= ValidateObject(pCopyImageToBufferInfo->dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-VkCopyImageToBufferInfo2-dstBuffer-parameter", "VUID-VkCopyImageToBufferInfo2-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBlitImage2(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBlitImage2-commandBuffer-parameter", kVUIDUndefined);
    if (pBlitImageInfo) {
        skip |= ValidateObject(pBlitImageInfo->srcImage, kVulkanObjectTypeImage, false, "VUID-VkBlitImageInfo2-srcImage-parameter", "VUID-VkBlitImageInfo2-commonparent");
        skip |= ValidateObject(pBlitImageInfo->dstImage, kVulkanObjectTypeImage, false, "VUID-VkBlitImageInfo2-dstImage-parameter", "VUID-VkBlitImageInfo2-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdResolveImage2(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdResolveImage2-commandBuffer-parameter", kVUIDUndefined);
    if (pResolveImageInfo) {
        skip |= ValidateObject(pResolveImageInfo->srcImage, kVulkanObjectTypeImage, false, "VUID-VkResolveImageInfo2-srcImage-parameter", "VUID-VkResolveImageInfo2-commonparent");
        skip |= ValidateObject(pResolveImageInfo->dstImage, kVulkanObjectTypeImage, false, "VUID-VkResolveImageInfo2-dstImage-parameter", "VUID-VkResolveImageInfo2-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBeginRendering(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pRenderingInfo) {
        if (pRenderingInfo->pColorAttachments) {
            for (uint32_t index1 = 0; index1 < pRenderingInfo->colorAttachmentCount; ++index1) {
                skip |= ValidateObject(pRenderingInfo->pColorAttachments[index1].imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
                skip |= ValidateObject(pRenderingInfo->pColorAttachments[index1].resolveImageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
            }
        }
        if (pRenderingInfo->pDepthAttachment) {
            skip |= ValidateObject(pRenderingInfo->pDepthAttachment->imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
            skip |= ValidateObject(pRenderingInfo->pDepthAttachment->resolveImageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
        }
        if (pRenderingInfo->pStencilAttachment) {
            skip |= ValidateObject(pRenderingInfo->pStencilAttachment->imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
            skip |= ValidateObject(pRenderingInfo->pStencilAttachment->resolveImageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndRendering(
    VkCommandBuffer                             commandBuffer) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetCullMode(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetCullMode-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetFrontFace(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetFrontFace-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetPrimitiveTopology(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetPrimitiveTopology-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetViewportWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetViewportWithCount-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetScissorWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetScissorWithCount-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindVertexBuffers2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBindVertexBuffers2-commandBuffer-parameter", "VUID-vkCmdBindVertexBuffers2-commonparent");
    if ((bindingCount > 0) && (pBuffers)) {
        for (uint32_t index0 = 0; index0 < bindingCount; ++index0) {
            skip |= ValidateObject(pBuffers[index0], kVulkanObjectTypeBuffer, true, "VUID-vkCmdBindVertexBuffers2-pBuffers-parameter", "VUID-vkCmdBindVertexBuffers2-commonparent");
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDepthTestEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthWriteEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDepthWriteEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthCompareOp(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDepthCompareOp-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthBoundsTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDepthBoundsTestEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetStencilTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetStencilTestEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetStencilOp(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetStencilOp-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetRasterizerDiscardEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetRasterizerDiscardEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthBiasEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDepthBiasEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetPrimitiveRestartEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetPrimitiveRestartEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceBufferMemoryRequirements(
    VkDevice                                    device,
    const VkDeviceBufferMemoryRequirements*     pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceImageMemoryRequirements(
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceImageSparseMemoryRequirements(
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetCommandPoolMemoryConsumption(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandBuffer                             commandBuffer,
    VkCommandPoolMemoryConsumption*             pConsumption) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetCommandPoolMemoryConsumption-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(commandPool, kVulkanObjectTypeCommandPool, false, "VUID-vkGetCommandPoolMemoryConsumption-commandPool-parameter", "VUID-vkGetCommandPoolMemoryConsumption-commandPool-parent");
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, true, "VUID-vkGetCommandPoolMemoryConsumption-commandBuffer-parameter", "VUID-vkGetCommandPoolMemoryConsumption-commandBuffer-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetFaultData(
    VkDevice                                    device,
    VkFaultQueryBehavior                        faultQueryBehavior,
    VkBool32*                                   pUnrecordedFaults,
    uint32_t*                                   pFaultCount,
    VkFaultData*                                pFaults) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetFaultData-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateDestroySurfaceKHR(
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, "VUID-vkDestroySurfaceKHR-instance-parameter", kVUIDUndefined);
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, true, "VUID-vkDestroySurfaceKHR-surface-parameter", kVUIDUndefined);
    skip |= ValidateDestroyObject(surface, kVulkanObjectTypeSurfaceKHR, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroySurfaceKHR(
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(surface, kVulkanObjectTypeSurfaceKHR);

}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfaceSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    VkBool32*                                   pSupported) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceSurfaceSupportKHR-physicalDevice-parameter", kVUIDUndefined);
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, false, "VUID-vkGetPhysicalDeviceSurfaceSupportKHR-surface-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilitiesKHR*                   pSurfaceCapabilities) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceSurfaceCapabilitiesKHR-physicalDevice-parameter", kVUIDUndefined);
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, false, "VUID-vkGetPhysicalDeviceSurfaceCapabilitiesKHR-surface-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfaceFormatsKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormatKHR*                         pSurfaceFormats) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceSurfaceFormatsKHR-physicalDevice-parameter", kVUIDUndefined);
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, true, "VUID-vkGetPhysicalDeviceSurfaceFormatsKHR-surface-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfacePresentModesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceSurfacePresentModesKHR-physicalDevice-parameter", kVUIDUndefined);
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, true, "VUID-vkGetPhysicalDeviceSurfacePresentModesKHR-surface-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateSwapchainKHR(
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchain) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateSwapchainKHR-device-parameter", kVUIDUndefined);
    if (pCreateInfo) {
        skip |= ValidateObject(pCreateInfo->surface, kVulkanObjectTypeSurfaceKHR, false, "VUID-VkSwapchainCreateInfoKHR-surface-parameter", kVUIDUndefined);
        skip |= ValidateObject(pCreateInfo->oldSwapchain, kVulkanObjectTypeSwapchainKHR, true, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateSwapchainKHR(
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchain,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSwapchain, kVulkanObjectTypeSwapchainKHR, pAllocator);

}

bool ObjectLifetimes::PreCallValidateAcquireNextImageKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    timeout,
    VkSemaphore                                 semaphore,
    VkFence                                     fence,
    uint32_t*                                   pImageIndex) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkAcquireNextImageKHR-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(swapchain, kVulkanObjectTypeSwapchainKHR, false, "VUID-vkAcquireNextImageKHR-swapchain-parameter", kVUIDUndefined);
    skip |= ValidateObject(semaphore, kVulkanObjectTypeSemaphore, true, "VUID-vkAcquireNextImageKHR-semaphore-parameter", "VUID-vkAcquireNextImageKHR-semaphore-parent");
    skip |= ValidateObject(fence, kVulkanObjectTypeFence, true, "VUID-vkAcquireNextImageKHR-fence-parameter", "VUID-vkAcquireNextImageKHR-fence-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateQueuePresentKHR(
    VkQueue                                     queue,
    const VkPresentInfoKHR*                     pPresentInfo) const {
    bool skip = false;
    skip |= ValidateObject(queue, kVulkanObjectTypeQueue, false, "VUID-vkQueuePresentKHR-queue-parameter", kVUIDUndefined);
    if (pPresentInfo) {
        if ((pPresentInfo->waitSemaphoreCount > 0) && (pPresentInfo->pWaitSemaphores)) {
            for (uint32_t index1 = 0; index1 < pPresentInfo->waitSemaphoreCount; ++index1) {
                skip |= ValidateObject(pPresentInfo->pWaitSemaphores[index1], kVulkanObjectTypeSemaphore, false, "VUID-VkPresentInfoKHR-pWaitSemaphores-parameter", "VUID-VkPresentInfoKHR-commonparent");
            }
        }
        if ((pPresentInfo->swapchainCount > 0) && (pPresentInfo->pSwapchains)) {
            for (uint32_t index1 = 0; index1 < pPresentInfo->swapchainCount; ++index1) {
                skip |= ValidateObject(pPresentInfo->pSwapchains[index1], kVulkanObjectTypeSwapchainKHR, false, "VUID-VkPresentInfoKHR-pSwapchains-parameter", kVUIDUndefined);
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceGroupPresentCapabilitiesKHR(
    VkDevice                                    device,
    VkDeviceGroupPresentCapabilitiesKHR*        pDeviceGroupPresentCapabilities) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetDeviceGroupPresentCapabilitiesKHR-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceGroupSurfacePresentModesKHR(
    VkDevice                                    device,
    VkSurfaceKHR                                surface,
    VkDeviceGroupPresentModeFlagsKHR*           pModes) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetDeviceGroupSurfacePresentModesKHR-device-parameter", "VUID-vkGetDeviceGroupSurfacePresentModesKHR-commonparent");
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, false, "VUID-vkGetDeviceGroupSurfacePresentModesKHR-surface-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDevicePresentRectanglesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pRectCount,
    VkRect2D*                                   pRects) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDevicePresentRectanglesKHR-physicalDevice-parameter", kVUIDUndefined);
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, false, "VUID-vkGetPhysicalDevicePresentRectanglesKHR-surface-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateAcquireNextImage2KHR(
    VkDevice                                    device,
    const VkAcquireNextImageInfoKHR*            pAcquireInfo,
    uint32_t*                                   pImageIndex) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkAcquireNextImage2KHR-device-parameter", kVUIDUndefined);
    if (pAcquireInfo) {
        skip |= ValidateObject(pAcquireInfo->swapchain, kVulkanObjectTypeSwapchainKHR, false, "VUID-VkAcquireNextImageInfoKHR-swapchain-parameter", kVUIDUndefined);
        skip |= ValidateObject(pAcquireInfo->semaphore, kVulkanObjectTypeSemaphore, true, "VUID-VkAcquireNextImageInfoKHR-semaphore-parameter", "VUID-VkAcquireNextImageInfoKHR-commonparent");
        skip |= ValidateObject(pAcquireInfo->fence, kVulkanObjectTypeFence, true, "VUID-VkAcquireNextImageInfoKHR-fence-parameter", "VUID-VkAcquireNextImageInfoKHR-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlanePropertiesKHR*                pProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceDisplayPlanePropertiesKHR-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDisplayPlaneSupportedDisplaysKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    uint32_t*                                   pDisplayCount,
    VkDisplayKHR*                               pDisplays) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetDisplayPlaneSupportedDisplaysKHR-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordGetDisplayPlaneSupportedDisplaysKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    uint32_t*                                   pDisplayCount,
    VkDisplayKHR*                               pDisplays,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    if (pDisplays) {
        for (uint32_t index = 0; index < *pDisplayCount; index++) {
            CreateObject(pDisplays[index], kVulkanObjectTypeDisplayKHR, nullptr);
        }
    }

}

bool ObjectLifetimes::PreCallValidateCreateDisplayModeKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const VkDisplayModeCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDisplayModeKHR*                           pMode) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkCreateDisplayModeKHR-physicalDevice-parameter", kVUIDUndefined);
    skip |= ValidateObject(display, kVulkanObjectTypeDisplayKHR, false, "VUID-vkCreateDisplayModeKHR-display-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateDisplayModeKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const VkDisplayModeCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDisplayModeKHR*                           pMode,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pMode, kVulkanObjectTypeDisplayModeKHR, pAllocator);

}

bool ObjectLifetimes::PreCallValidateGetDisplayPlaneCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayModeKHR                            mode,
    uint32_t                                    planeIndex,
    VkDisplayPlaneCapabilitiesKHR*              pCapabilities) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetDisplayPlaneCapabilitiesKHR-physicalDevice-parameter", kVUIDUndefined);
    skip |= ValidateObject(mode, kVulkanObjectTypeDisplayModeKHR, false, "VUID-vkGetDisplayPlaneCapabilitiesKHR-mode-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateDisplayPlaneSurfaceKHR(
    VkInstance                                  instance,
    const VkDisplaySurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, "VUID-vkCreateDisplayPlaneSurfaceKHR-instance-parameter", kVUIDUndefined);
    if (pCreateInfo) {
        skip |= ValidateObject(pCreateInfo->displayMode, kVulkanObjectTypeDisplayModeKHR, false, "VUID-VkDisplaySurfaceCreateInfoKHR-displayMode-parameter", kVUIDUndefined);
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateDisplayPlaneSurfaceKHR(
    VkInstance                                  instance,
    const VkDisplaySurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}

bool ObjectLifetimes::PreCallValidateCreateSharedSwapchainsKHR(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainCreateInfoKHR*             pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchains) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateSharedSwapchainsKHR-device-parameter", kVUIDUndefined);
    if (pCreateInfos) {
        for (uint32_t index0 = 0; index0 < swapchainCount; ++index0) {
            skip |= ValidateObject(pCreateInfos[index0].surface, kVulkanObjectTypeSurfaceKHR, false, "VUID-VkSwapchainCreateInfoKHR-surface-parameter", kVUIDUndefined);
            skip |= ValidateObject(pCreateInfos[index0].oldSwapchain, kVulkanObjectTypeSwapchainKHR, true, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateSharedSwapchainsKHR(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainCreateInfoKHR*             pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchains,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    if (pSwapchains) {
        for (uint32_t index = 0; index < swapchainCount; index++) {
            CreateObject(pSwapchains[index], kVulkanObjectTypeSwapchainKHR, pAllocator);
        }
    }

}

#ifdef VK_USE_PLATFORM_XLIB_KHR

bool ObjectLifetimes::PreCallValidateCreateXlibSurfaceKHR(
    VkInstance                                  instance,
    const VkXlibSurfaceCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateXlibSurfaceKHR(
    VkInstance                                  instance,
    const VkXlibSurfaceCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_XLIB_KHR

#ifdef VK_USE_PLATFORM_XLIB_KHR

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceXlibPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    Display*                                    dpy,
    VisualID                                    visualID) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_XLIB_KHR

#ifdef VK_USE_PLATFORM_XCB_KHR

bool ObjectLifetimes::PreCallValidateCreateXcbSurfaceKHR(
    VkInstance                                  instance,
    const VkXcbSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateXcbSurfaceKHR(
    VkInstance                                  instance,
    const VkXcbSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_XCB_KHR

#ifdef VK_USE_PLATFORM_XCB_KHR

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceXcbPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    xcb_connection_t*                           connection,
    xcb_visualid_t                              visual_id) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_XCB_KHR

#ifdef VK_USE_PLATFORM_WAYLAND_KHR

bool ObjectLifetimes::PreCallValidateCreateWaylandSurfaceKHR(
    VkInstance                                  instance,
    const VkWaylandSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateWaylandSurfaceKHR(
    VkInstance                                  instance,
    const VkWaylandSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_WAYLAND_KHR

#ifdef VK_USE_PLATFORM_WAYLAND_KHR

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceWaylandPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct wl_display*                          display) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_WAYLAND_KHR

#ifdef VK_USE_PLATFORM_ANDROID_KHR

bool ObjectLifetimes::PreCallValidateCreateAndroidSurfaceKHR(
    VkInstance                                  instance,
    const VkAndroidSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateAndroidSurfaceKHR(
    VkInstance                                  instance,
    const VkAndroidSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateCreateWin32SurfaceKHR(
    VkInstance                                  instance,
    const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateWin32SurfaceKHR(
    VkInstance                                  instance,
    const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceWin32PresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceVideoCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkVideoProfileInfoKHR*                pVideoProfile,
    VkVideoCapabilitiesKHR*                     pCapabilities) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceVideoFormatPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceVideoFormatInfoKHR*   pVideoFormatInfo,
    uint32_t*                                   pVideoFormatPropertyCount,
    VkVideoFormatPropertiesKHR*                 pVideoFormatProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateVideoSessionKHR(
    VkDevice                                    device,
    const VkVideoSessionCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkVideoSessionKHR*                          pVideoSession) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateVideoSessionKHR(
    VkDevice                                    device,
    const VkVideoSessionCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkVideoSessionKHR*                          pVideoSession,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pVideoSession, kVulkanObjectTypeVideoSessionKHR, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyVideoSessionKHR(
    VkDevice                                    device,
    VkVideoSessionKHR                           videoSession,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(videoSession, kVulkanObjectTypeVideoSessionKHR, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(videoSession, kVulkanObjectTypeVideoSessionKHR, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyVideoSessionKHR(
    VkDevice                                    device,
    VkVideoSessionKHR                           videoSession,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(videoSession, kVulkanObjectTypeVideoSessionKHR);

}

bool ObjectLifetimes::PreCallValidateGetVideoSessionMemoryRequirementsKHR(
    VkDevice                                    device,
    VkVideoSessionKHR                           videoSession,
    uint32_t*                                   pMemoryRequirementsCount,
    VkVideoSessionMemoryRequirementsKHR*        pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(videoSession, kVulkanObjectTypeVideoSessionKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateBindVideoSessionMemoryKHR(
    VkDevice                                    device,
    VkVideoSessionKHR                           videoSession,
    uint32_t                                    bindSessionMemoryInfoCount,
    const VkBindVideoSessionMemoryInfoKHR*      pBindSessionMemoryInfos) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(videoSession, kVulkanObjectTypeVideoSessionKHR, false, kVUIDUndefined, kVUIDUndefined);
    if (pBindSessionMemoryInfos) {
        for (uint32_t index0 = 0; index0 < bindSessionMemoryInfoCount; ++index0) {
            skip |= ValidateObject(pBindSessionMemoryInfos[index0].memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateVideoSessionParametersKHR(
    VkDevice                                    device,
    const VkVideoSessionParametersCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkVideoSessionParametersKHR*                pVideoSessionParameters) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pCreateInfo) {
        skip |= ValidateObject(pCreateInfo->videoSessionParametersTemplate, kVulkanObjectTypeVideoSessionParametersKHR, true, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pCreateInfo->videoSession, kVulkanObjectTypeVideoSessionKHR, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateVideoSessionParametersKHR(
    VkDevice                                    device,
    const VkVideoSessionParametersCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkVideoSessionParametersKHR*                pVideoSessionParameters,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pVideoSessionParameters, kVulkanObjectTypeVideoSessionParametersKHR, pAllocator);

}

bool ObjectLifetimes::PreCallValidateUpdateVideoSessionParametersKHR(
    VkDevice                                    device,
    VkVideoSessionParametersKHR                 videoSessionParameters,
    const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(videoSessionParameters, kVulkanObjectTypeVideoSessionParametersKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateDestroyVideoSessionParametersKHR(
    VkDevice                                    device,
    VkVideoSessionParametersKHR                 videoSessionParameters,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(videoSessionParameters, kVulkanObjectTypeVideoSessionParametersKHR, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(videoSessionParameters, kVulkanObjectTypeVideoSessionParametersKHR, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyVideoSessionParametersKHR(
    VkDevice                                    device,
    VkVideoSessionParametersKHR                 videoSessionParameters,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(videoSessionParameters, kVulkanObjectTypeVideoSessionParametersKHR);

}

bool ObjectLifetimes::PreCallValidateCmdBeginVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoBeginCodingInfoKHR*            pBeginInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pBeginInfo) {
        skip |= ValidateObject(pBeginInfo->videoSession, kVulkanObjectTypeVideoSessionKHR, false, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pBeginInfo->videoSessionParameters, kVulkanObjectTypeVideoSessionParametersKHR, true, kVUIDUndefined, kVUIDUndefined);
        if (pBeginInfo->pReferenceSlots) {
            for (uint32_t index1 = 0; index1 < pBeginInfo->referenceSlotCount; ++index1) {
                if (pBeginInfo->pReferenceSlots[index1].pPictureResource) {
                    skip |= ValidateObject(pBeginInfo->pReferenceSlots[index1].pPictureResource->imageViewBinding, kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined);
                }
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEndCodingInfoKHR*              pEndCodingInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdControlVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoCodingControlInfoKHR*          pCodingControlInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDecodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoDecodeInfoKHR*                 pDecodeInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pDecodeInfo) {
        skip |= ValidateObject(pDecodeInfo->srcBuffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pDecodeInfo->dstPictureResource.imageViewBinding, kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined);
        if (pDecodeInfo->pSetupReferenceSlot) {
            if (pDecodeInfo->pSetupReferenceSlot->pPictureResource) {
                skip |= ValidateObject(pDecodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding, kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined);
            }
        }
        if (pDecodeInfo->pReferenceSlots) {
            for (uint32_t index1 = 0; index1 < pDecodeInfo->referenceSlotCount; ++index1) {
                if (pDecodeInfo->pReferenceSlots[index1].pPictureResource) {
                    skip |= ValidateObject(pDecodeInfo->pReferenceSlots[index1].pPictureResource->imageViewBinding, kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined);
                }
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBeginRenderingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pRenderingInfo) {
        if (pRenderingInfo->pColorAttachments) {
            for (uint32_t index1 = 0; index1 < pRenderingInfo->colorAttachmentCount; ++index1) {
                skip |= ValidateObject(pRenderingInfo->pColorAttachments[index1].imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
                skip |= ValidateObject(pRenderingInfo->pColorAttachments[index1].resolveImageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
            }
        }
        if (pRenderingInfo->pDepthAttachment) {
            skip |= ValidateObject(pRenderingInfo->pDepthAttachment->imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
            skip |= ValidateObject(pRenderingInfo->pDepthAttachment->resolveImageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
        }
        if (pRenderingInfo->pStencilAttachment) {
            skip |= ValidateObject(pRenderingInfo->pStencilAttachment->imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
            skip |= ValidateObject(pRenderingInfo->pStencilAttachment->resolveImageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndRenderingKHR(
    VkCommandBuffer                             commandBuffer) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceFeatures2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceFeatures2-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceProperties2-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceFormatProperties2-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceImageFormatProperties2-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceMemoryProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceMemoryProperties2-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSparseImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceGroupPeerMemoryFeaturesKHR(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetDeviceGroupPeerMemoryFeatures-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDeviceMask-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDispatchBaseKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDispatchBase-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateTrimCommandPoolKHR(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(commandPool, kVulkanObjectTypeCommandPool, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateEnumeratePhysicalDeviceGroupsKHR(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, "VUID-vkEnumeratePhysicalDeviceGroups-instance-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordEnumeratePhysicalDeviceGroupsKHR(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties,
    VkResult                                    result) {
    if (result != VK_SUCCESS && result != VK_INCOMPLETE) return;
    if (pPhysicalDeviceGroupProperties) {
        for (uint32_t device_group_index = 0; device_group_index < *pPhysicalDeviceGroupCount; device_group_index++) {
            PostCallRecordEnumeratePhysicalDevices(instance, &pPhysicalDeviceGroupProperties[device_group_index].physicalDeviceCount, pPhysicalDeviceGroupProperties[device_group_index].physicalDevices, VK_SUCCESS);
        }
    }

}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceExternalBufferPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceExternalBufferProperties-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetMemoryWin32HandleKHR(
    VkDevice                                    device,
    const VkMemoryGetWin32HandleInfoKHR*        pGetWin32HandleInfo,
    HANDLE*                                     pHandle) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pGetWin32HandleInfo) {
        skip |= ValidateObject(pGetWin32HandleInfo->memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetMemoryWin32HandlePropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    HANDLE                                      handle,
    VkMemoryWin32HandlePropertiesKHR*           pMemoryWin32HandleProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetMemoryFdKHR(
    VkDevice                                    device,
    const VkMemoryGetFdInfoKHR*                 pGetFdInfo,
    int*                                        pFd) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetMemoryFdKHR-device-parameter", kVUIDUndefined);
    if (pGetFdInfo) {
        skip |= ValidateObject(pGetFdInfo->memory, kVulkanObjectTypeDeviceMemory, false, "VUID-VkMemoryGetFdInfoKHR-memory-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetMemoryFdPropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    VkMemoryFdPropertiesKHR*                    pMemoryFdProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetMemoryFdPropertiesKHR-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceExternalSemaphoreProperties-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateImportSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkImportSemaphoreWin32HandleInfoKHR*  pImportSemaphoreWin32HandleInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pImportSemaphoreWin32HandleInfo) {
        skip |= ValidateObject(pImportSemaphoreWin32HandleInfo->semaphore, kVulkanObjectTypeSemaphore, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkSemaphoreGetWin32HandleInfoKHR*     pGetWin32HandleInfo,
    HANDLE*                                     pHandle) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pGetWin32HandleInfo) {
        skip |= ValidateObject(pGetWin32HandleInfo->semaphore, kVulkanObjectTypeSemaphore, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateImportSemaphoreFdKHR(
    VkDevice                                    device,
    const VkImportSemaphoreFdInfoKHR*           pImportSemaphoreFdInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkImportSemaphoreFdKHR-device-parameter", kVUIDUndefined);
    if (pImportSemaphoreFdInfo) {
        skip |= ValidateObject(pImportSemaphoreFdInfo->semaphore, kVulkanObjectTypeSemaphore, false, "VUID-VkImportSemaphoreFdInfoKHR-semaphore-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetSemaphoreFdKHR(
    VkDevice                                    device,
    const VkSemaphoreGetFdInfoKHR*              pGetFdInfo,
    int*                                        pFd) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetSemaphoreFdKHR-device-parameter", kVUIDUndefined);
    if (pGetFdInfo) {
        skip |= ValidateObject(pGetFdInfo->semaphore, kVulkanObjectTypeSemaphore, false, "VUID-VkSemaphoreGetFdInfoKHR-semaphore-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdPushDescriptorSetWithTemplateKHR(
    VkCommandBuffer                             commandBuffer,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    const void*                                 pData) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(descriptorUpdateTemplate, kVulkanObjectTypeDescriptorUpdateTemplate, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(layout, kVulkanObjectTypePipelineLayout, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateDestroyDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(descriptorUpdateTemplate, kVulkanObjectTypeDescriptorUpdateTemplate, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(descriptorUpdateTemplate, kVulkanObjectTypeDescriptorUpdateTemplate, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(descriptorUpdateTemplate, kVulkanObjectTypeDescriptorUpdateTemplate);

}

bool ObjectLifetimes::PreCallValidateUpdateDescriptorSetWithTemplateKHR(
    VkDevice                                    device,
    VkDescriptorSet                             descriptorSet,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const void*                                 pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(descriptorSet, kVulkanObjectTypeDescriptorSet, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(descriptorUpdateTemplate, kVulkanObjectTypeDescriptorUpdateTemplate, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateRenderPass2KHR(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateRenderPass2-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateRenderPass2KHR(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pRenderPass, kVulkanObjectTypeRenderPass, pAllocator);

}

bool ObjectLifetimes::PreCallValidateCmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBeginRenderPass2-commandBuffer-parameter", kVUIDUndefined);
    if (pRenderPassBegin) {
        skip |= ValidateObject(pRenderPassBegin->renderPass, kVulkanObjectTypeRenderPass, false, "VUID-VkRenderPassBeginInfo-renderPass-parameter", "VUID-VkRenderPassBeginInfo-commonparent");
        skip |= ValidateObject(pRenderPassBegin->framebuffer, kVulkanObjectTypeFramebuffer, false, "VUID-VkRenderPassBeginInfo-framebuffer-parameter", "VUID-VkRenderPassBeginInfo-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdNextSubpass2-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdEndRenderPass2-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetSwapchainStatusKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetSwapchainStatusKHR-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(swapchain, kVulkanObjectTypeSwapchainKHR, false, "VUID-vkGetSwapchainStatusKHR-swapchain-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceExternalFencePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceExternalFenceProperties-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateImportFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkImportFenceWin32HandleInfoKHR*      pImportFenceWin32HandleInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pImportFenceWin32HandleInfo) {
        skip |= ValidateObject(pImportFenceWin32HandleInfo->fence, kVulkanObjectTypeFence, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkFenceGetWin32HandleInfoKHR*         pGetWin32HandleInfo,
    HANDLE*                                     pHandle) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pGetWin32HandleInfo) {
        skip |= ValidateObject(pGetWin32HandleInfo->fence, kVulkanObjectTypeFence, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateImportFenceFdKHR(
    VkDevice                                    device,
    const VkImportFenceFdInfoKHR*               pImportFenceFdInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkImportFenceFdKHR-device-parameter", kVUIDUndefined);
    if (pImportFenceFdInfo) {
        skip |= ValidateObject(pImportFenceFdInfo->fence, kVulkanObjectTypeFence, false, "VUID-VkImportFenceFdInfoKHR-fence-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetFenceFdKHR(
    VkDevice                                    device,
    const VkFenceGetFdInfoKHR*                  pGetFdInfo,
    int*                                        pFd) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetFenceFdKHR-device-parameter", kVUIDUndefined);
    if (pGetFdInfo) {
        skip |= ValidateObject(pGetFdInfo->fence, kVulkanObjectTypeFence, false, "VUID-VkFenceGetFdInfoKHR-fence-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint32_t*                                   pCounterCount,
    VkPerformanceCounterKHR*                    pCounters,
    VkPerformanceCounterDescriptionKHR*         pCounterDescriptions) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkQueryPoolPerformanceCreateInfoKHR*  pPerformanceQueryCreateInfo,
    uint32_t*                                   pNumPasses) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateAcquireProfilingLockKHR(
    VkDevice                                    device,
    const VkAcquireProfilingLockInfoKHR*        pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkAcquireProfilingLockKHR-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateReleaseProfilingLockKHR(
    VkDevice                                    device) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkReleaseProfilingLockKHR-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfaceCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkSurfaceCapabilities2KHR*                  pSurfaceCapabilities) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceSurfaceCapabilities2KHR-physicalDevice-parameter", kVUIDUndefined);
    if (pSurfaceInfo) {
        skip |= ValidateObject(pSurfaceInfo->surface, kVulkanObjectTypeSurfaceKHR, true, "VUID-VkPhysicalDeviceSurfaceInfo2KHR-surface-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfaceFormats2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormat2KHR*                        pSurfaceFormats) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceSurfaceFormats2KHR-physicalDevice-parameter", kVUIDUndefined);
    if (pSurfaceInfo) {
        skip |= ValidateObject(pSurfaceInfo->surface, kVulkanObjectTypeSurfaceKHR, true, "VUID-VkPhysicalDeviceSurfaceInfo2KHR-surface-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlaneProperties2KHR*               pProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceDisplayPlaneProperties2KHR-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDisplayPlaneCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkDisplayPlaneInfo2KHR*               pDisplayPlaneInfo,
    VkDisplayPlaneCapabilities2KHR*             pCapabilities) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetDisplayPlaneCapabilities2KHR-physicalDevice-parameter", kVUIDUndefined);
    if (pDisplayPlaneInfo) {
        skip |= ValidateObject(pDisplayPlaneInfo->mode, kVulkanObjectTypeDisplayModeKHR, false, "VUID-VkDisplayPlaneInfo2KHR-mode-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetImageMemoryRequirements2-device-parameter", kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->image, kVulkanObjectTypeImage, false, "VUID-VkImageMemoryRequirementsInfo2-image-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetBufferMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetBufferMemoryRequirements2-device-parameter", kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferMemoryRequirementsInfo2-buffer-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageSparseMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->image, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateSamplerYcbcrConversionKHR(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateSamplerYcbcrConversion-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateSamplerYcbcrConversionKHR(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pYcbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroySamplerYcbcrConversionKHR(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDestroySamplerYcbcrConversion-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(ycbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion, true, "VUID-vkDestroySamplerYcbcrConversion-ycbcrConversion-parameter", "VUID-vkDestroySamplerYcbcrConversion-ycbcrConversion-parent");
    skip |= ValidateDestroyObject(ycbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroySamplerYcbcrConversionKHR(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(ycbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion);

}

bool ObjectLifetimes::PreCallValidateBindBufferMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkBindBufferMemory2-device-parameter", kVUIDUndefined);
    if (pBindInfos) {
        for (uint32_t index0 = 0; index0 < bindInfoCount; ++index0) {
            skip |= ValidateObject(pBindInfos[index0].buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBindBufferMemoryInfo-buffer-parameter", "VUID-VkBindBufferMemoryInfo-commonparent");
            skip |= ValidateObject(pBindInfos[index0].memory, kVulkanObjectTypeDeviceMemory, false, "VUID-VkBindBufferMemoryInfo-memory-parameter", "VUID-VkBindBufferMemoryInfo-commonparent");
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateBindImageMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkBindImageMemory2-device-parameter", kVUIDUndefined);
    if (pBindInfos) {
        for (uint32_t index0 = 0; index0 < bindInfoCount; ++index0) {
            skip |= ValidateObject(pBindInfos[index0].image, kVulkanObjectTypeImage, false, "VUID-VkBindImageMemoryInfo-image-parameter", "VUID-VkBindImageMemoryInfo-commonparent");
            skip |= ValidateObject(pBindInfos[index0].memory, kVulkanObjectTypeDeviceMemory, true, kVUIDUndefined, "VUID-VkBindImageMemoryInfo-commonparent");
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDrawIndirectCount-commandBuffer-parameter", "VUID-vkCmdDrawIndirectCount-commonparent");
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndirectCount-buffer-parameter", "VUID-vkCmdDrawIndirectCount-commonparent");
    skip |= ValidateObject(countBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndirectCount-countBuffer-parameter", "VUID-vkCmdDrawIndirectCount-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDrawIndexedIndirectCount-commandBuffer-parameter", "VUID-vkCmdDrawIndexedIndirectCount-commonparent");
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndexedIndirectCount-buffer-parameter", "VUID-vkCmdDrawIndexedIndirectCount-commonparent");
    skip |= ValidateObject(countBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndexedIndirectCount-countBuffer-parameter", "VUID-vkCmdDrawIndexedIndirectCount-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetSemaphoreCounterValueKHR(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    uint64_t*                                   pValue) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetSemaphoreCounterValue-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(semaphore, kVulkanObjectTypeSemaphore, false, "VUID-vkGetSemaphoreCounterValue-semaphore-parameter", "VUID-vkGetSemaphoreCounterValue-semaphore-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateWaitSemaphoresKHR(
    VkDevice                                    device,
    const VkSemaphoreWaitInfo*                  pWaitInfo,
    uint64_t                                    timeout) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkWaitSemaphores-device-parameter", kVUIDUndefined);
    if (pWaitInfo) {
        if ((pWaitInfo->semaphoreCount > 0) && (pWaitInfo->pSemaphores)) {
            for (uint32_t index1 = 0; index1 < pWaitInfo->semaphoreCount; ++index1) {
                skip |= ValidateObject(pWaitInfo->pSemaphores[index1], kVulkanObjectTypeSemaphore, false, "VUID-VkSemaphoreWaitInfo-pSemaphores-parameter", kVUIDUndefined);
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateSignalSemaphoreKHR(
    VkDevice                                    device,
    const VkSemaphoreSignalInfo*                pSignalInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkSignalSemaphore-device-parameter", kVUIDUndefined);
    if (pSignalInfo) {
        skip |= ValidateObject(pSignalInfo->semaphore, kVulkanObjectTypeSemaphore, false, "VUID-VkSemaphoreSignalInfo-semaphore-parameter", kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceFragmentShadingRatesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pFragmentShadingRateCount,
    VkPhysicalDeviceFragmentShadingRateKHR*     pFragmentShadingRates) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceFragmentShadingRatesKHR-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetFragmentShadingRateKHR(
    VkCommandBuffer                             commandBuffer,
    const VkExtent2D*                           pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetFragmentShadingRateKHR-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateWaitForPresentKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    presentId,
    uint64_t                                    timeout) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(swapchain, kVulkanObjectTypeSwapchainKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetBufferDeviceAddressKHR(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetBufferDeviceAddress-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetBufferOpaqueCaptureAddressKHR(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetBufferOpaqueCaptureAddress-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceMemoryOpaqueCaptureAddressKHR(
    VkDevice                                    device,
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetDeviceMemoryOpaqueCaptureAddress-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateDeferredOperationKHR(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator,
    VkDeferredOperationKHR*                     pDeferredOperation) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateDeferredOperationKHR(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator,
    VkDeferredOperationKHR*                     pDeferredOperation,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pDeferredOperation, kVulkanObjectTypeDeferredOperationKHR, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyDeferredOperationKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(operation, kVulkanObjectTypeDeferredOperationKHR, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(operation, kVulkanObjectTypeDeferredOperationKHR, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyDeferredOperationKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(operation, kVulkanObjectTypeDeferredOperationKHR);

}

bool ObjectLifetimes::PreCallValidateGetDeferredOperationMaxConcurrencyKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(operation, kVulkanObjectTypeDeferredOperationKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeferredOperationResultKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(operation, kVulkanObjectTypeDeferredOperationKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateDeferredOperationJoinKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(operation, kVulkanObjectTypeDeferredOperationKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPipelineExecutablePropertiesKHR(
    VkDevice                                    device,
    const VkPipelineInfoKHR*                    pPipelineInfo,
    uint32_t*                                   pExecutableCount,
    VkPipelineExecutablePropertiesKHR*          pProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pPipelineInfo) {
        skip |= ValidateObject(pPipelineInfo->pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPipelineExecutableStatisticsKHR(
    VkDevice                                    device,
    const VkPipelineExecutableInfoKHR*          pExecutableInfo,
    uint32_t*                                   pStatisticCount,
    VkPipelineExecutableStatisticKHR*           pStatistics) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pExecutableInfo) {
        skip |= ValidateObject(pExecutableInfo->pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPipelineExecutableInternalRepresentationsKHR(
    VkDevice                                    device,
    const VkPipelineExecutableInfoKHR*          pExecutableInfo,
    uint32_t*                                   pInternalRepresentationCount,
    VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pExecutableInfo) {
        skip |= ValidateObject(pExecutableInfo->pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateMapMemory2KHR(
    VkDevice                                    device,
    const VkMemoryMapInfoKHR*                   pMemoryMapInfo,
    void**                                      ppData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pMemoryMapInfo) {
        skip |= ValidateObject(pMemoryMapInfo->memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateUnmapMemory2KHR(
    VkDevice                                    device,
    const VkMemoryUnmapInfoKHR*                 pMemoryUnmapInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pMemoryUnmapInfo) {
        skip |= ValidateObject(pMemoryUnmapInfo->memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

#ifdef VK_ENABLE_BETA_EXTENSIONS

bool ObjectLifetimes::PreCallValidateCmdEncodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEncodeInfoKHR*                 pEncodeInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pEncodeInfo) {
        skip |= ValidateObject(pEncodeInfo->dstBuffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pEncodeInfo->srcPictureResource.imageViewBinding, kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined);
        if (pEncodeInfo->pSetupReferenceSlot) {
            if (pEncodeInfo->pSetupReferenceSlot->pPictureResource) {
                skip |= ValidateObject(pEncodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding, kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined);
            }
        }
        if (pEncodeInfo->pReferenceSlots) {
            for (uint32_t index1 = 0; index1 < pEncodeInfo->referenceSlotCount; ++index1) {
                if (pEncodeInfo->pReferenceSlots[index1].pPictureResource) {
                    skip |= ValidateObject(pEncodeInfo->pReferenceSlots[index1].pPictureResource->imageViewBinding, kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined);
                }
            }
        }
    }

    return skip;
}
#endif // VK_ENABLE_BETA_EXTENSIONS

bool ObjectLifetimes::PreCallValidateCmdRefreshObjectsKHR(
    VkCommandBuffer                             commandBuffer,
    const VkRefreshObjectListKHR*               pRefreshObjects) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdRefreshObjectsKHR-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceRefreshableObjectTypesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pRefreshableObjectTypeCount,
    VkObjectType*                               pRefreshableObjectTypes) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceRefreshableObjectTypesKHR-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetEvent2-commandBuffer-parameter", "VUID-vkCmdSetEvent2-commonparent");
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkCmdSetEvent2-event-parameter", "VUID-vkCmdSetEvent2-commonparent");
    if (pDependencyInfo) {
        if (pDependencyInfo->pBufferMemoryBarriers) {
            for (uint32_t index1 = 0; index1 < pDependencyInfo->bufferMemoryBarrierCount; ++index1) {
                skip |= ValidateObject(pDependencyInfo->pBufferMemoryBarriers[index1].buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferMemoryBarrier2-buffer-parameter", kVUIDUndefined);
            }
        }
        if (pDependencyInfo->pImageMemoryBarriers) {
            for (uint32_t index1 = 0; index1 < pDependencyInfo->imageMemoryBarrierCount; ++index1) {
                skip |= ValidateObject(pDependencyInfo->pImageMemoryBarriers[index1].image, kVulkanObjectTypeImage, false, "VUID-VkImageMemoryBarrier2-image-parameter", kVUIDUndefined);
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdResetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdResetEvent2-commandBuffer-parameter", "VUID-vkCmdResetEvent2-commonparent");
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkCmdResetEvent2-event-parameter", "VUID-vkCmdResetEvent2-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWaitEvents2KHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdWaitEvents2-commandBuffer-parameter", "VUID-vkCmdWaitEvents2-commonparent");
    if ((eventCount > 0) && (pEvents)) {
        for (uint32_t index0 = 0; index0 < eventCount; ++index0) {
            skip |= ValidateObject(pEvents[index0], kVulkanObjectTypeEvent, false, "VUID-vkCmdWaitEvents2-pEvents-parameter", "VUID-vkCmdWaitEvents2-commonparent");
        }
    }
    if (pDependencyInfos) {
        for (uint32_t index0 = 0; index0 < eventCount; ++index0) {
            if (pDependencyInfos[index0].pBufferMemoryBarriers) {
                for (uint32_t index1 = 0; index1 < pDependencyInfos[index0].bufferMemoryBarrierCount; ++index1) {
                    skip |= ValidateObject(pDependencyInfos[index0].pBufferMemoryBarriers[index1].buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferMemoryBarrier2-buffer-parameter", kVUIDUndefined);
                }
            }
            if (pDependencyInfos[index0].pImageMemoryBarriers) {
                for (uint32_t index1 = 0; index1 < pDependencyInfos[index0].imageMemoryBarrierCount; ++index1) {
                    skip |= ValidateObject(pDependencyInfos[index0].pImageMemoryBarriers[index1].image, kVulkanObjectTypeImage, false, "VUID-VkImageMemoryBarrier2-image-parameter", kVUIDUndefined);
                }
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdPipelineBarrier2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdPipelineBarrier2-commandBuffer-parameter", kVUIDUndefined);
    if (pDependencyInfo) {
        if (pDependencyInfo->pBufferMemoryBarriers) {
            for (uint32_t index1 = 0; index1 < pDependencyInfo->bufferMemoryBarrierCount; ++index1) {
                skip |= ValidateObject(pDependencyInfo->pBufferMemoryBarriers[index1].buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferMemoryBarrier2-buffer-parameter", kVUIDUndefined);
            }
        }
        if (pDependencyInfo->pImageMemoryBarriers) {
            for (uint32_t index1 = 0; index1 < pDependencyInfo->imageMemoryBarrierCount; ++index1) {
                skip |= ValidateObject(pDependencyInfo->pImageMemoryBarriers[index1].image, kVulkanObjectTypeImage, false, "VUID-VkImageMemoryBarrier2-image-parameter", kVUIDUndefined);
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWriteTimestamp2KHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdWriteTimestamp2-commandBuffer-parameter", "VUID-vkCmdWriteTimestamp2-commonparent");
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdWriteTimestamp2-queryPool-parameter", "VUID-vkCmdWriteTimestamp2-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateQueueSubmit2KHR(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo2*                        pSubmits,
    VkFence                                     fence) const {
    bool skip = false;
    skip |= ValidateObject(queue, kVulkanObjectTypeQueue, false, "VUID-vkQueueSubmit2-queue-parameter", "VUID-vkQueueSubmit2-commonparent");
    if (pSubmits) {
        for (uint32_t index0 = 0; index0 < submitCount; ++index0) {
            if (pSubmits[index0].pWaitSemaphoreInfos) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].waitSemaphoreInfoCount; ++index1) {
                    skip |= ValidateObject(pSubmits[index0].pWaitSemaphoreInfos[index1].semaphore, kVulkanObjectTypeSemaphore, false, "VUID-VkSemaphoreSubmitInfo-semaphore-parameter", kVUIDUndefined);
                }
            }
            if (pSubmits[index0].pCommandBufferInfos) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].commandBufferInfoCount; ++index1) {
                    skip |= ValidateObject(pSubmits[index0].pCommandBufferInfos[index1].commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-VkCommandBufferSubmitInfo-commandBuffer-parameter", kVUIDUndefined);
                }
            }
            if (pSubmits[index0].pSignalSemaphoreInfos) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].signalSemaphoreInfoCount; ++index1) {
                    skip |= ValidateObject(pSubmits[index0].pSignalSemaphoreInfos[index1].semaphore, kVulkanObjectTypeSemaphore, false, "VUID-VkSemaphoreSubmitInfo-semaphore-parameter", kVUIDUndefined);
                }
            }
        }
    }
    skip |= ValidateObject(fence, kVulkanObjectTypeFence, true, "VUID-vkQueueSubmit2-fence-parameter", "VUID-vkQueueSubmit2-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWriteBufferMarker2AMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdWriteBufferMarker2AMD-commandBuffer-parameter", "VUID-vkCmdWriteBufferMarker2AMD-commonparent");
    skip |= ValidateObject(dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdWriteBufferMarker2AMD-dstBuffer-parameter", "VUID-vkCmdWriteBufferMarker2AMD-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetQueueCheckpointData2NV(
    VkQueue                                     queue,
    uint32_t*                                   pCheckpointDataCount,
    VkCheckpointData2NV*                        pCheckpointData) const {
    bool skip = false;
    skip |= ValidateObject(queue, kVulkanObjectTypeQueue, false, "VUID-vkGetQueueCheckpointData2NV-queue-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyBuffer2-commandBuffer-parameter", kVUIDUndefined);
    if (pCopyBufferInfo) {
        skip |= ValidateObject(pCopyBufferInfo->srcBuffer, kVulkanObjectTypeBuffer, false, "VUID-VkCopyBufferInfo2-srcBuffer-parameter", "VUID-VkCopyBufferInfo2-commonparent");
        skip |= ValidateObject(pCopyBufferInfo->dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-VkCopyBufferInfo2-dstBuffer-parameter", "VUID-VkCopyBufferInfo2-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyImage2-commandBuffer-parameter", kVUIDUndefined);
    if (pCopyImageInfo) {
        skip |= ValidateObject(pCopyImageInfo->srcImage, kVulkanObjectTypeImage, false, "VUID-VkCopyImageInfo2-srcImage-parameter", "VUID-VkCopyImageInfo2-commonparent");
        skip |= ValidateObject(pCopyImageInfo->dstImage, kVulkanObjectTypeImage, false, "VUID-VkCopyImageInfo2-dstImage-parameter", "VUID-VkCopyImageInfo2-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyBufferToImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyBufferToImage2-commandBuffer-parameter", kVUIDUndefined);
    if (pCopyBufferToImageInfo) {
        skip |= ValidateObject(pCopyBufferToImageInfo->srcBuffer, kVulkanObjectTypeBuffer, false, "VUID-VkCopyBufferToImageInfo2-srcBuffer-parameter", "VUID-VkCopyBufferToImageInfo2-commonparent");
        skip |= ValidateObject(pCopyBufferToImageInfo->dstImage, kVulkanObjectTypeImage, false, "VUID-VkCopyBufferToImageInfo2-dstImage-parameter", "VUID-VkCopyBufferToImageInfo2-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyImageToBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdCopyImageToBuffer2-commandBuffer-parameter", kVUIDUndefined);
    if (pCopyImageToBufferInfo) {
        skip |= ValidateObject(pCopyImageToBufferInfo->srcImage, kVulkanObjectTypeImage, false, "VUID-VkCopyImageToBufferInfo2-srcImage-parameter", "VUID-VkCopyImageToBufferInfo2-commonparent");
        skip |= ValidateObject(pCopyImageToBufferInfo->dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-VkCopyImageToBufferInfo2-dstBuffer-parameter", "VUID-VkCopyImageToBufferInfo2-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBlitImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBlitImage2-commandBuffer-parameter", kVUIDUndefined);
    if (pBlitImageInfo) {
        skip |= ValidateObject(pBlitImageInfo->srcImage, kVulkanObjectTypeImage, false, "VUID-VkBlitImageInfo2-srcImage-parameter", "VUID-VkBlitImageInfo2-commonparent");
        skip |= ValidateObject(pBlitImageInfo->dstImage, kVulkanObjectTypeImage, false, "VUID-VkBlitImageInfo2-dstImage-parameter", "VUID-VkBlitImageInfo2-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdResolveImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdResolveImage2-commandBuffer-parameter", kVUIDUndefined);
    if (pResolveImageInfo) {
        skip |= ValidateObject(pResolveImageInfo->srcImage, kVulkanObjectTypeImage, false, "VUID-VkResolveImageInfo2-srcImage-parameter", "VUID-VkResolveImageInfo2-commonparent");
        skip |= ValidateObject(pResolveImageInfo->dstImage, kVulkanObjectTypeImage, false, "VUID-VkResolveImageInfo2-dstImage-parameter", "VUID-VkResolveImageInfo2-commonparent");
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdTraceRaysIndirect2KHR(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceBufferMemoryRequirementsKHR(
    VkDevice                                    device,
    const VkDeviceBufferMemoryRequirements*     pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceImageMemoryRequirementsKHR(
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceImageSparseMemoryRequirementsKHR(
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateDebugReportCallbackEXT(
    VkInstance                                  instance,
    const VkDebugReportCallbackCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugReportCallbackEXT*                   pCallback) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateDebugReportCallbackEXT(
    VkInstance                                  instance,
    const VkDebugReportCallbackCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugReportCallbackEXT*                   pCallback,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pCallback, kVulkanObjectTypeDebugReportCallbackEXT, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyDebugReportCallbackEXT(
    VkInstance                                  instance,
    VkDebugReportCallbackEXT                    callback,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(callback, kVulkanObjectTypeDebugReportCallbackEXT, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(callback, kVulkanObjectTypeDebugReportCallbackEXT, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyDebugReportCallbackEXT(
    VkInstance                                  instance,
    VkDebugReportCallbackEXT                    callback,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(callback, kVulkanObjectTypeDebugReportCallbackEXT);

}

bool ObjectLifetimes::PreCallValidateDebugReportMessageEXT(
    VkInstance                                  instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    const char*                                 pLayerPrefix,
    const char*                                 pMessage) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateDebugMarkerSetObjectTagEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectTagInfoEXT*        pTagInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateDebugMarkerSetObjectNameEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectNameInfoEXT*       pNameInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindTransformFeedbackBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if ((bindingCount > 0) && (pBuffers)) {
        for (uint32_t index0 = 0; index0 < bindingCount; ++index0) {
            skip |= ValidateObject(pBuffers[index0], kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBeginTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if ((counterBufferCount > 0) && (pCounterBuffers)) {
        for (uint32_t index0 = 0; index0 < counterBufferCount; ++index0) {
            skip |= ValidateObject(pCounterBuffers[index0], kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if ((counterBufferCount > 0) && (pCounterBuffers)) {
        for (uint32_t index0 = 0; index0 < counterBufferCount; ++index0) {
            skip |= ValidateObject(pCounterBuffers[index0], kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBeginQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    uint32_t                                    index) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndirectByteCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    VkBuffer                                    counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(counterBuffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateCuModuleNVX(
    VkDevice                                    device,
    const VkCuModuleCreateInfoNVX*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCuModuleNVX*                              pModule) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateCuModuleNVX(
    VkDevice                                    device,
    const VkCuModuleCreateInfoNVX*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCuModuleNVX*                              pModule,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pModule, kVulkanObjectTypeCuModuleNVX, pAllocator);

}

bool ObjectLifetimes::PreCallValidateCreateCuFunctionNVX(
    VkDevice                                    device,
    const VkCuFunctionCreateInfoNVX*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCuFunctionNVX*                            pFunction) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pCreateInfo) {
        skip |= ValidateObject(pCreateInfo->module, kVulkanObjectTypeCuModuleNVX, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateCuFunctionNVX(
    VkDevice                                    device,
    const VkCuFunctionCreateInfoNVX*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCuFunctionNVX*                            pFunction,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pFunction, kVulkanObjectTypeCuFunctionNVX, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyCuModuleNVX(
    VkDevice                                    device,
    VkCuModuleNVX                               module,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(module, kVulkanObjectTypeCuModuleNVX, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(module, kVulkanObjectTypeCuModuleNVX, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyCuModuleNVX(
    VkDevice                                    device,
    VkCuModuleNVX                               module,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(module, kVulkanObjectTypeCuModuleNVX);

}

bool ObjectLifetimes::PreCallValidateDestroyCuFunctionNVX(
    VkDevice                                    device,
    VkCuFunctionNVX                             function,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(function, kVulkanObjectTypeCuFunctionNVX, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(function, kVulkanObjectTypeCuFunctionNVX, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyCuFunctionNVX(
    VkDevice                                    device,
    VkCuFunctionNVX                             function,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(function, kVulkanObjectTypeCuFunctionNVX);

}

bool ObjectLifetimes::PreCallValidateCmdCuLaunchKernelNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCuLaunchInfoNVX*                    pLaunchInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pLaunchInfo) {
        skip |= ValidateObject(pLaunchInfo->function, kVulkanObjectTypeCuFunctionNVX, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageViewHandleNVX(
    VkDevice                                    device,
    const VkImageViewHandleInfoNVX*             pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageViewAddressNVX(
    VkDevice                                    device,
    VkImageView                                 imageView,
    VkImageViewAddressPropertiesNVX*            pProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(imageView, kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDrawIndirectCount-commandBuffer-parameter", "VUID-vkCmdDrawIndirectCount-commonparent");
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndirectCount-buffer-parameter", "VUID-vkCmdDrawIndirectCount-commonparent");
    skip |= ValidateObject(countBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndirectCount-countBuffer-parameter", "VUID-vkCmdDrawIndirectCount-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdDrawIndexedIndirectCount-commandBuffer-parameter", "VUID-vkCmdDrawIndexedIndirectCount-commonparent");
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndexedIndirectCount-buffer-parameter", "VUID-vkCmdDrawIndexedIndirectCount-commonparent");
    skip |= ValidateObject(countBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndexedIndirectCount-countBuffer-parameter", "VUID-vkCmdDrawIndexedIndirectCount-commonparent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetShaderInfoAMD(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    size_t*                                     pInfoSize,
    void*                                       pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_GGP

bool ObjectLifetimes::PreCallValidateCreateStreamDescriptorSurfaceGGP(
    VkInstance                                  instance,
    const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateStreamDescriptorSurfaceGGP(
    VkInstance                                  instance,
    const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_GGP

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceExternalImageFormatPropertiesNV(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
    VkExternalImageFormatPropertiesNV*          pExternalImageFormatProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetMemoryWin32HandleNV(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    HANDLE*                                     pHandle) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_VI_NN

bool ObjectLifetimes::PreCallValidateCreateViSurfaceNN(
    VkInstance                                  instance,
    const VkViSurfaceCreateInfoNN*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateViSurfaceNN(
    VkInstance                                  instance,
    const VkViSurfaceCreateInfoNN*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_VI_NN

bool ObjectLifetimes::PreCallValidateCmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pConditionalRenderingBegin) {
        skip |= ValidateObject(pConditionalRenderingBegin->buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateReleaseDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkReleaseDisplayEXT-physicalDevice-parameter", kVUIDUndefined);
    skip |= ValidateObject(display, kVulkanObjectTypeDisplayKHR, false, "VUID-vkReleaseDisplayEXT-display-parameter", kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT

bool ObjectLifetimes::PreCallValidateAcquireXlibDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    VkDisplayKHR                                display) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(display, kVulkanObjectTypeDisplayKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT

bool ObjectLifetimes::PreCallValidateGetRandROutputDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    RROutput                                    rrOutput,
    VkDisplayKHR*                               pDisplay) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordGetRandROutputDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    RROutput                                    rrOutput,
    VkDisplayKHR*                               pDisplay,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pDisplay, kVulkanObjectTypeDisplayKHR, nullptr);

}
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfaceCapabilities2EXT(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilities2EXT*                  pSurfaceCapabilities) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceSurfaceCapabilities2EXT-physicalDevice-parameter", kVUIDUndefined);
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, false, "VUID-vkGetPhysicalDeviceSurfaceCapabilities2EXT-surface-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateDisplayPowerControlEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayPowerInfoEXT*                pDisplayPowerInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkDisplayPowerControlEXT-device-parameter", "VUID-vkDisplayPowerControlEXT-commonparent");
    skip |= ValidateObject(display, kVulkanObjectTypeDisplayKHR, false, "VUID-vkDisplayPowerControlEXT-display-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateRegisterDeviceEventEXT(
    VkDevice                                    device,
    const VkDeviceEventInfoEXT*                 pDeviceEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkRegisterDeviceEventEXT-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordRegisterDeviceEventEXT(
    VkDevice                                    device,
    const VkDeviceEventInfoEXT*                 pDeviceEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pFence, kVulkanObjectTypeFence, pAllocator);

}

bool ObjectLifetimes::PreCallValidateRegisterDisplayEventEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayEventInfoEXT*                pDisplayEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkRegisterDisplayEventEXT-device-parameter", "VUID-vkRegisterDisplayEventEXT-commonparent");
    skip |= ValidateObject(display, kVulkanObjectTypeDisplayKHR, false, "VUID-vkRegisterDisplayEventEXT-display-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordRegisterDisplayEventEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayEventInfoEXT*                pDisplayEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pFence, kVulkanObjectTypeFence, pAllocator);

}

bool ObjectLifetimes::PreCallValidateGetSwapchainCounterEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    uint64_t*                                   pCounterValue) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetSwapchainCounterEXT-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(swapchain, kVulkanObjectTypeSwapchainKHR, false, "VUID-vkGetSwapchainCounterEXT-swapchain-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetRefreshCycleDurationGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkRefreshCycleDurationGOOGLE*               pDisplayTimingProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(swapchain, kVulkanObjectTypeSwapchainKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPastPresentationTimingGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pPresentationTimingCount,
    VkPastPresentationTimingGOOGLE*             pPresentationTimings) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(swapchain, kVulkanObjectTypeSwapchainKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDiscardRectangleEXT-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDiscardRectangleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    discardRectangleEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDiscardRectangleEnableEXT-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDiscardRectangleModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDiscardRectangleModeEXT-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateSetHdrMetadataEXT(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainKHR*                       pSwapchains,
    const VkHdrMetadataEXT*                     pMetadata) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkSetHdrMetadataEXT-device-parameter", kVUIDUndefined);
    if ((swapchainCount > 0) && (pSwapchains)) {
        for (uint32_t index0 = 0; index0 < swapchainCount; ++index0) {
            skip |= ValidateObject(pSwapchains[index0], kVulkanObjectTypeSwapchainKHR, false, "VUID-vkSetHdrMetadataEXT-pSwapchains-parameter", kVUIDUndefined);
        }
    }

    return skip;
}

#ifdef VK_USE_PLATFORM_IOS_MVK

bool ObjectLifetimes::PreCallValidateCreateIOSSurfaceMVK(
    VkInstance                                  instance,
    const VkIOSSurfaceCreateInfoMVK*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateIOSSurfaceMVK(
    VkInstance                                  instance,
    const VkIOSSurfaceCreateInfoMVK*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_IOS_MVK

#ifdef VK_USE_PLATFORM_MACOS_MVK

bool ObjectLifetimes::PreCallValidateCreateMacOSSurfaceMVK(
    VkInstance                                  instance,
    const VkMacOSSurfaceCreateInfoMVK*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateMacOSSurfaceMVK(
    VkInstance                                  instance,
    const VkMacOSSurfaceCreateInfoMVK*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_MACOS_MVK

bool ObjectLifetimes::PreCallValidateQueueBeginDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) const {
    bool skip = false;
    skip |= ValidateObject(queue, kVulkanObjectTypeQueue, false, "VUID-vkQueueBeginDebugUtilsLabelEXT-queue-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateQueueEndDebugUtilsLabelEXT(
    VkQueue                                     queue) const {
    bool skip = false;
    skip |= ValidateObject(queue, kVulkanObjectTypeQueue, false, "VUID-vkQueueEndDebugUtilsLabelEXT-queue-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateQueueInsertDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) const {
    bool skip = false;
    skip |= ValidateObject(queue, kVulkanObjectTypeQueue, false, "VUID-vkQueueInsertDebugUtilsLabelEXT-queue-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBeginDebugUtilsLabelEXT-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdEndDebugUtilsLabelEXT-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdInsertDebugUtilsLabelEXT-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    const VkDebugUtilsMessengerCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugUtilsMessengerEXT*                   pMessenger) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, "VUID-vkCreateDebugUtilsMessengerEXT-instance-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    const VkDebugUtilsMessengerCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugUtilsMessengerEXT*                   pMessenger,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pMessenger, kVulkanObjectTypeDebugUtilsMessengerEXT, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessengerEXT                    messenger,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, "VUID-vkDestroyDebugUtilsMessengerEXT-instance-parameter", kVUIDUndefined);
    skip |= ValidateObject(messenger, kVulkanObjectTypeDebugUtilsMessengerEXT, true, "VUID-vkDestroyDebugUtilsMessengerEXT-messenger-parameter", kVUIDUndefined);
    skip |= ValidateDestroyObject(messenger, kVulkanObjectTypeDebugUtilsMessengerEXT, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessengerEXT                    messenger,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(messenger, kVulkanObjectTypeDebugUtilsMessengerEXT);

}

bool ObjectLifetimes::PreCallValidateSubmitDebugUtilsMessageEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, "VUID-vkSubmitDebugUtilsMessageEXT-instance-parameter", kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR

bool ObjectLifetimes::PreCallValidateGetAndroidHardwareBufferPropertiesANDROID(
    VkDevice                                    device,
    const struct AHardwareBuffer*               buffer,
    VkAndroidHardwareBufferPropertiesANDROID*   pProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_ANDROID_KHR

bool ObjectLifetimes::PreCallValidateGetMemoryAndroidHardwareBufferANDROID(
    VkDevice                                    device,
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo,
    struct AHardwareBuffer**                    pBuffer) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_ANDROID_KHR

bool ObjectLifetimes::PreCallValidateCmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetSampleLocationsEXT-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceMultisamplePropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    VkMultisamplePropertiesEXT*                 pMultisampleProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceMultisamplePropertiesEXT-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageDrmFormatModifierPropertiesEXT(
    VkDevice                                    device,
    VkImage                                     image,
    VkImageDrmFormatModifierPropertiesEXT*      pProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetImageDrmFormatModifierPropertiesEXT-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, "VUID-vkGetImageDrmFormatModifierPropertiesEXT-image-parameter", "VUID-vkGetImageDrmFormatModifierPropertiesEXT-image-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateValidationCacheEXT(
    VkDevice                                    device,
    const VkValidationCacheCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkValidationCacheEXT*                       pValidationCache) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateValidationCacheEXT(
    VkDevice                                    device,
    const VkValidationCacheCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkValidationCacheEXT*                       pValidationCache,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pValidationCache, kVulkanObjectTypeValidationCacheEXT, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyValidationCacheEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(validationCache, kVulkanObjectTypeValidationCacheEXT, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(validationCache, kVulkanObjectTypeValidationCacheEXT, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyValidationCacheEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(validationCache, kVulkanObjectTypeValidationCacheEXT);

}

bool ObjectLifetimes::PreCallValidateMergeValidationCachesEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        dstCache,
    uint32_t                                    srcCacheCount,
    const VkValidationCacheEXT*                 pSrcCaches) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(dstCache, kVulkanObjectTypeValidationCacheEXT, false, kVUIDUndefined, kVUIDUndefined);
    if ((srcCacheCount > 0) && (pSrcCaches)) {
        for (uint32_t index0 = 0; index0 < srcCacheCount; ++index0) {
            skip |= ValidateObject(pSrcCaches[index0], kVulkanObjectTypeValidationCacheEXT, false, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetValidationCacheDataEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    size_t*                                     pDataSize,
    void*                                       pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(validationCache, kVulkanObjectTypeValidationCacheEXT, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindShadingRateImageNV(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetViewportShadingRatePaletteNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetCoarseSampleOrderNV(
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateAccelerationStructureNV(
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoNV*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureNV*                  pAccelerationStructure) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pCreateInfo) {
        if (pCreateInfo->info.pGeometries) {
            for (uint32_t index2 = 0; index2 < pCreateInfo->info.geometryCount; ++index2) {
                skip |= ValidateObject(pCreateInfo->info.pGeometries[index2].geometry.triangles.vertexData, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
                skip |= ValidateObject(pCreateInfo->info.pGeometries[index2].geometry.triangles.indexData, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
                skip |= ValidateObject(pCreateInfo->info.pGeometries[index2].geometry.triangles.transformData, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
                skip |= ValidateObject(pCreateInfo->info.pGeometries[index2].geometry.aabbs.aabbData, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
            }
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateAccelerationStructureNV(
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoNV*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureNV*                  pAccelerationStructure,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pAccelerationStructure, kVulkanObjectTypeAccelerationStructureNV, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyAccelerationStructureNV(
    VkDevice                                    device,
    VkAccelerationStructureNV                   accelerationStructure,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(accelerationStructure, kVulkanObjectTypeAccelerationStructureNV, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(accelerationStructure, kVulkanObjectTypeAccelerationStructureNV, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyAccelerationStructureNV(
    VkDevice                                    device,
    VkAccelerationStructureNV                   accelerationStructure,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(accelerationStructure, kVulkanObjectTypeAccelerationStructureNV);

}

bool ObjectLifetimes::PreCallValidateGetAccelerationStructureMemoryRequirementsNV(
    VkDevice                                    device,
    const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo,
    VkMemoryRequirements2KHR*                   pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->accelerationStructure, kVulkanObjectTypeAccelerationStructureNV, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateBindAccelerationStructureMemoryNV(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pBindInfos) {
        for (uint32_t index0 = 0; index0 < bindInfoCount; ++index0) {
            skip |= ValidateObject(pBindInfos[index0].accelerationStructure, kVulkanObjectTypeAccelerationStructureNV, false, kVUIDUndefined, kVUIDUndefined);
            skip |= ValidateObject(pBindInfos[index0].memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBuildAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureInfoNV*        pInfo,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        if (pInfo->pGeometries) {
            for (uint32_t index1 = 0; index1 < pInfo->geometryCount; ++index1) {
                skip |= ValidateObject(pInfo->pGeometries[index1].geometry.triangles.vertexData, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
                skip |= ValidateObject(pInfo->pGeometries[index1].geometry.triangles.indexData, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
                skip |= ValidateObject(pInfo->pGeometries[index1].geometry.triangles.transformData, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
                skip |= ValidateObject(pInfo->pGeometries[index1].geometry.aabbs.aabbData, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
            }
        }
    }
    skip |= ValidateObject(instanceData, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(dst, kVulkanObjectTypeAccelerationStructureNV, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(src, kVulkanObjectTypeAccelerationStructureNV, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(scratch, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeKHR          mode) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(dst, kVulkanObjectTypeAccelerationStructureNV, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(src, kVulkanObjectTypeAccelerationStructureNV, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdTraceRaysNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    raygenShaderBindingTableBuffer,
    VkDeviceSize                                raygenShaderBindingOffset,
    VkBuffer                                    missShaderBindingTableBuffer,
    VkDeviceSize                                missShaderBindingOffset,
    VkDeviceSize                                missShaderBindingStride,
    VkBuffer                                    hitShaderBindingTableBuffer,
    VkDeviceSize                                hitShaderBindingOffset,
    VkDeviceSize                                hitShaderBindingStride,
    VkBuffer                                    callableShaderBindingTableBuffer,
    VkDeviceSize                                callableShaderBindingOffset,
    VkDeviceSize                                callableShaderBindingStride,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(raygenShaderBindingTableBuffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(missShaderBindingTableBuffer, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(hitShaderBindingTableBuffer, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(callableShaderBindingTableBuffer, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateRayTracingPipelinesNV(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkRayTracingPipelineCreateInfoNV*     pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(pipelineCache, kVulkanObjectTypePipelineCache, false, kVUIDUndefined, kVUIDUndefined);
    if (pCreateInfos) {
        for (uint32_t index0 = 0; index0 < createInfoCount; ++index0) {
            if (pCreateInfos[index0].pStages) {
                for (uint32_t index1 = 0; index1 < pCreateInfos[index0].stageCount; ++index1) {
                    skip |= ValidateObject(pCreateInfos[index0].pStages[index1].module, kVulkanObjectTypeShaderModule, true, "VUID-VkPipelineShaderStageCreateInfo-module-parameter", kVUIDUndefined);
                }
            }
            skip |= ValidateObject(pCreateInfos[index0].layout, kVulkanObjectTypePipelineLayout, false, kVUIDUndefined, kVUIDUndefined);
            if ((pCreateInfos[index0].flags & VK_PIPELINE_CREATE_DERIVATIVE_BIT) && (pCreateInfos[index0].basePipelineIndex == -1))
                skip |= ValidateObject(pCreateInfos[index0].basePipelineHandle, kVulkanObjectTypePipeline, false, "VUID-VkRayTracingPipelineCreateInfoNV-flags-07984", kVUIDUndefined);
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateRayTracingPipelinesNV(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkRayTracingPipelineCreateInfoNV*     pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines,
    VkResult                                    result) {
    if (VK_ERROR_VALIDATION_FAILED_EXT == result) return;
    if (pPipelines) {
        for (uint32_t index = 0; index < createInfoCount; index++) {
            if (!pPipelines[index]) continue;
            CreateObject(pPipelines[index], kVulkanObjectTypePipeline, pAllocator);
        }
    }

}

bool ObjectLifetimes::PreCallValidateGetRayTracingShaderGroupHandlesKHR(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    void*                                       pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetRayTracingShaderGroupHandlesNV(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    void*                                       pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetAccelerationStructureHandleNV(
    VkDevice                                    device,
    VkAccelerationStructureNV                   accelerationStructure,
    size_t                                      dataSize,
    void*                                       pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(accelerationStructure, kVulkanObjectTypeAccelerationStructureNV, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureNV*            pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if ((accelerationStructureCount > 0) && (pAccelerationStructures)) {
        for (uint32_t index0 = 0; index0 < accelerationStructureCount; ++index0) {
            skip |= ValidateObject(pAccelerationStructures[index0], kVulkanObjectTypeAccelerationStructureNV, false, kVUIDUndefined, kVUIDUndefined);
        }
    }
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCompileDeferredNV(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    shader) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetMemoryHostPointerPropertiesEXT(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    const void*                                 pHostPointer,
    VkMemoryHostPointerPropertiesEXT*           pMemoryHostPointerProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetMemoryHostPointerPropertiesEXT-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(dstBuffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pTimeDomainCount,
    VkTimeDomainEXT*                            pTimeDomains) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceCalibrateableTimeDomainsEXT-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetCalibratedTimestampsEXT(
    VkDevice                                    device,
    uint32_t                                    timestampCount,
    const VkCalibratedTimestampInfoEXT*         pTimestampInfos,
    uint64_t*                                   pTimestamps,
    uint64_t*                                   pMaxDeviation) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetCalibratedTimestampsEXT-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawMeshTasksNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawMeshTasksIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawMeshTasksIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(countBuffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetExclusiveScissorEnableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkBool32*                             pExclusiveScissorEnables) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetExclusiveScissorNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetCheckpointNV(
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetQueueCheckpointDataNV(
    VkQueue                                     queue,
    uint32_t*                                   pCheckpointDataCount,
    VkCheckpointDataNV*                         pCheckpointData) const {
    bool skip = false;
    skip |= ValidateObject(queue, kVulkanObjectTypeQueue, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateInitializePerformanceApiINTEL(
    VkDevice                                    device,
    const VkInitializePerformanceApiInfoINTEL*  pInitializeInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateUninitializePerformanceApiINTEL(
    VkDevice                                    device) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetPerformanceMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceMarkerInfoINTEL*         pMarkerInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetPerformanceStreamMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetPerformanceOverrideINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceOverrideInfoINTEL*       pOverrideInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateAcquirePerformanceConfigurationINTEL(
    VkDevice                                    device,
    const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo,
    VkPerformanceConfigurationINTEL*            pConfiguration) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordAcquirePerformanceConfigurationINTEL(
    VkDevice                                    device,
    const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo,
    VkPerformanceConfigurationINTEL*            pConfiguration,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pConfiguration, kVulkanObjectTypePerformanceConfigurationINTEL, nullptr);

}

bool ObjectLifetimes::PreCallValidateReleasePerformanceConfigurationINTEL(
    VkDevice                                    device,
    VkPerformanceConfigurationINTEL             configuration) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(configuration, kVulkanObjectTypePerformanceConfigurationINTEL, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(configuration, kVulkanObjectTypePerformanceConfigurationINTEL, nullptr, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordReleasePerformanceConfigurationINTEL(
    VkDevice                                    device,
    VkPerformanceConfigurationINTEL             configuration) {
    RecordDestroyObject(configuration, kVulkanObjectTypePerformanceConfigurationINTEL);

}

bool ObjectLifetimes::PreCallValidateQueueSetPerformanceConfigurationINTEL(
    VkQueue                                     queue,
    VkPerformanceConfigurationINTEL             configuration) const {
    bool skip = false;
    skip |= ValidateObject(queue, kVulkanObjectTypeQueue, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(configuration, kVulkanObjectTypePerformanceConfigurationINTEL, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPerformanceParameterINTEL(
    VkDevice                                    device,
    VkPerformanceParameterTypeINTEL             parameter,
    VkPerformanceValueINTEL*                    pValue) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateSetLocalDimmingAMD(
    VkDevice                                    device,
    VkSwapchainKHR                              swapChain,
    VkBool32                                    localDimmingEnable) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(swapChain, kVulkanObjectTypeSwapchainKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_FUCHSIA

bool ObjectLifetimes::PreCallValidateCreateImagePipeSurfaceFUCHSIA(
    VkInstance                                  instance,
    const VkImagePipeSurfaceCreateInfoFUCHSIA*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateImagePipeSurfaceFUCHSIA(
    VkInstance                                  instance,
    const VkImagePipeSurfaceCreateInfoFUCHSIA*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_FUCHSIA

#ifdef VK_USE_PLATFORM_METAL_EXT

bool ObjectLifetimes::PreCallValidateCreateMetalSurfaceEXT(
    VkInstance                                  instance,
    const VkMetalSurfaceCreateInfoEXT*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateMetalSurfaceEXT(
    VkInstance                                  instance,
    const VkMetalSurfaceCreateInfoEXT*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_METAL_EXT

bool ObjectLifetimes::PreCallValidateGetBufferDeviceAddressEXT(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetBufferDeviceAddress-device-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceToolPropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pToolCount,
    VkPhysicalDeviceToolProperties*             pToolProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkCooperativeMatrixPropertiesNV*            pProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pCombinationCount,
    VkFramebufferMixedSamplesCombinationNV*     pCombinations) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfacePresentModes2EXT(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pSurfaceInfo) {
        skip |= ValidateObject(pSurfaceInfo->surface, kVulkanObjectTypeSurfaceKHR, true, "VUID-VkPhysicalDeviceSurfaceInfo2KHR-surface-parameter", kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateAcquireFullScreenExclusiveModeEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(swapchain, kVulkanObjectTypeSwapchainKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateReleaseFullScreenExclusiveModeEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(swapchain, kVulkanObjectTypeSwapchainKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetDeviceGroupSurfacePresentModes2EXT(
    VkDevice                                    device,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkDeviceGroupPresentModeFlagsKHR*           pModes) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pSurfaceInfo) {
        skip |= ValidateObject(pSurfaceInfo->surface, kVulkanObjectTypeSurfaceKHR, true, "VUID-VkPhysicalDeviceSurfaceInfo2KHR-surface-parameter", kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateCreateHeadlessSurfaceEXT(
    VkInstance                                  instance,
    const VkHeadlessSurfaceCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, "VUID-vkCreateHeadlessSurfaceEXT-instance-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateHeadlessSurfaceEXT(
    VkInstance                                  instance,
    const VkHeadlessSurfaceCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}

bool ObjectLifetimes::PreCallValidateCmdSetLineStippleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetLineStippleEXT-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateResetQueryPoolEXT(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkResetQueryPool-device-parameter", kVUIDUndefined);
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkResetQueryPool-queryPool-parameter", "VUID-vkResetQueryPool-queryPool-parent");

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetCullModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetCullMode-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetFrontFaceEXT(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetFrontFace-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetPrimitiveTopologyEXT(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetPrimitiveTopology-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetViewportWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetViewportWithCount-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetScissorWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetScissorWithCount-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindVertexBuffers2EXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdBindVertexBuffers2-commandBuffer-parameter", "VUID-vkCmdBindVertexBuffers2-commonparent");
    if ((bindingCount > 0) && (pBuffers)) {
        for (uint32_t index0 = 0; index0 < bindingCount; ++index0) {
            skip |= ValidateObject(pBuffers[index0], kVulkanObjectTypeBuffer, true, "VUID-vkCmdBindVertexBuffers2-pBuffers-parameter", "VUID-vkCmdBindVertexBuffers2-commonparent");
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDepthTestEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDepthWriteEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthCompareOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDepthCompareOp-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthBoundsTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDepthBoundsTestEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetStencilTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetStencilTestEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetStencilOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetStencilOp-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateReleaseSwapchainImagesEXT(
    VkDevice                                    device,
    const VkReleaseSwapchainImagesInfoEXT*      pReleaseInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pReleaseInfo) {
        skip |= ValidateObject(pReleaseInfo->swapchain, kVulkanObjectTypeSwapchainKHR, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetGeneratedCommandsMemoryRequirementsNV(
    VkDevice                                    device,
    const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pInfo->indirectCommandsLayout, kVulkanObjectTypeIndirectCommandsLayoutNV, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdPreprocessGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pGeneratedCommandsInfo) {
        skip |= ValidateObject(pGeneratedCommandsInfo->pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pGeneratedCommandsInfo->indirectCommandsLayout, kVulkanObjectTypeIndirectCommandsLayoutNV, false, kVUIDUndefined, kVUIDUndefined);
        if (pGeneratedCommandsInfo->pStreams) {
            for (uint32_t index1 = 0; index1 < pGeneratedCommandsInfo->streamCount; ++index1) {
                skip |= ValidateObject(pGeneratedCommandsInfo->pStreams[index1].buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
            }
        }
        skip |= ValidateObject(pGeneratedCommandsInfo->preprocessBuffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pGeneratedCommandsInfo->sequencesCountBuffer, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pGeneratedCommandsInfo->sequencesIndexBuffer, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdExecuteGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pGeneratedCommandsInfo) {
        skip |= ValidateObject(pGeneratedCommandsInfo->pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pGeneratedCommandsInfo->indirectCommandsLayout, kVulkanObjectTypeIndirectCommandsLayoutNV, false, kVUIDUndefined, kVUIDUndefined);
        if (pGeneratedCommandsInfo->pStreams) {
            for (uint32_t index1 = 0; index1 < pGeneratedCommandsInfo->streamCount; ++index1) {
                skip |= ValidateObject(pGeneratedCommandsInfo->pStreams[index1].buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
            }
        }
        skip |= ValidateObject(pGeneratedCommandsInfo->preprocessBuffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pGeneratedCommandsInfo->sequencesCountBuffer, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pGeneratedCommandsInfo->sequencesIndexBuffer, kVulkanObjectTypeBuffer, true, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindPipelineShaderGroupNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline,
    uint32_t                                    groupIndex) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateIndirectCommandsLayoutNV(
    VkDevice                                    device,
    const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkIndirectCommandsLayoutNV*                 pIndirectCommandsLayout) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pCreateInfo) {
        if (pCreateInfo->pTokens) {
            for (uint32_t index1 = 0; index1 < pCreateInfo->tokenCount; ++index1) {
                skip |= ValidateObject(pCreateInfo->pTokens[index1].pushconstantPipelineLayout, kVulkanObjectTypePipelineLayout, true, kVUIDUndefined, kVUIDUndefined);
            }
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateIndirectCommandsLayoutNV(
    VkDevice                                    device,
    const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkIndirectCommandsLayoutNV*                 pIndirectCommandsLayout,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pIndirectCommandsLayout, kVulkanObjectTypeIndirectCommandsLayoutNV, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyIndirectCommandsLayoutNV(
    VkDevice                                    device,
    VkIndirectCommandsLayoutNV                  indirectCommandsLayout,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(indirectCommandsLayout, kVulkanObjectTypeIndirectCommandsLayoutNV, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(indirectCommandsLayout, kVulkanObjectTypeIndirectCommandsLayoutNV, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyIndirectCommandsLayoutNV(
    VkDevice                                    device,
    VkIndirectCommandsLayoutNV                  indirectCommandsLayout,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(indirectCommandsLayout, kVulkanObjectTypeIndirectCommandsLayoutNV);

}

bool ObjectLifetimes::PreCallValidateAcquireDrmDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    int32_t                                     drmFd,
    VkDisplayKHR                                display) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(display, kVulkanObjectTypeDisplayKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDrmDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    int32_t                                     drmFd,
    uint32_t                                    connectorId,
    VkDisplayKHR*                               display) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordGetDrmDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    int32_t                                     drmFd,
    uint32_t                                    connectorId,
    VkDisplayKHR*                               display,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*display, kVulkanObjectTypeDisplayKHR, nullptr);

}

bool ObjectLifetimes::PreCallValidateCreatePrivateDataSlotEXT(
    VkDevice                                    device,
    const VkPrivateDataSlotCreateInfo*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPrivateDataSlot*                          pPrivateDataSlot) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreatePrivateDataSlotEXT(
    VkDevice                                    device,
    const VkPrivateDataSlotCreateInfo*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPrivateDataSlot*                          pPrivateDataSlot,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pPrivateDataSlot, kVulkanObjectTypePrivateDataSlot, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyPrivateDataSlotEXT(
    VkDevice                                    device,
    VkPrivateDataSlot                           privateDataSlot,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyPrivateDataSlotEXT(
    VkDevice                                    device,
    VkPrivateDataSlot                           privateDataSlot,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot);

}

bool ObjectLifetimes::PreCallValidateSetPrivateDataEXT(
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t                                    data) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPrivateDataEXT(
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t*                                   pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDescriptorSetLayoutSizeEXT(
    VkDevice                                    device,
    VkDescriptorSetLayout                       layout,
    VkDeviceSize*                               pLayoutSizeInBytes) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(layout, kVulkanObjectTypeDescriptorSetLayout, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDescriptorSetLayoutBindingOffsetEXT(
    VkDevice                                    device,
    VkDescriptorSetLayout                       layout,
    uint32_t                                    binding,
    VkDeviceSize*                               pOffset) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(layout, kVulkanObjectTypeDescriptorSetLayout, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindDescriptorBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    bufferCount,
    const VkDescriptorBufferBindingInfoEXT*     pBindingInfos) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDescriptorBufferOffsetsEXT(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    setCount,
    const uint32_t*                             pBufferIndices,
    const VkDeviceSize*                         pOffsets) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(layout, kVulkanObjectTypePipelineLayout, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindDescriptorBufferEmbeddedSamplersEXT(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(layout, kVulkanObjectTypePipelineLayout, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetBufferOpaqueCaptureDescriptorDataEXT(
    VkDevice                                    device,
    const VkBufferCaptureDescriptorDataInfoEXT* pInfo,
    void*                                       pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageOpaqueCaptureDescriptorDataEXT(
    VkDevice                                    device,
    const VkImageCaptureDescriptorDataInfoEXT*  pInfo,
    void*                                       pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->image, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageViewOpaqueCaptureDescriptorDataEXT(
    VkDevice                                    device,
    const VkImageViewCaptureDescriptorDataInfoEXT* pInfo,
    void*                                       pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->imageView, kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetSamplerOpaqueCaptureDescriptorDataEXT(
    VkDevice                                    device,
    const VkSamplerCaptureDescriptorDataInfoEXT* pInfo,
    void*                                       pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->sampler, kVulkanObjectTypeSampler, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(
    VkDevice                                    device,
    const VkAccelerationStructureCaptureDescriptorDataInfoEXT* pInfo,
    void*                                       pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->accelerationStructure, kVulkanObjectTypeAccelerationStructureKHR, true, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pInfo->accelerationStructureNV, kVulkanObjectTypeAccelerationStructureNV, true, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetFragmentShadingRateEnumNV(
    VkCommandBuffer                             commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageSubresourceLayout2EXT(
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource2EXT*               pSubresource,
    VkSubresourceLayout2EXT*                    pLayout) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceFaultInfoEXT(
    VkDevice                                    device,
    VkDeviceFaultCountsEXT*                     pFaultCounts,
    VkDeviceFaultInfoEXT*                       pFaultInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateAcquireWinrtDisplayNV(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(display, kVulkanObjectTypeDisplayKHR, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetWinrtDisplayNV(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    VkDisplayKHR*                               pDisplay) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordGetWinrtDisplayNV(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    VkDisplayKHR*                               pDisplay,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pDisplay, kVulkanObjectTypeDisplayKHR, nullptr);

}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_DIRECTFB_EXT

bool ObjectLifetimes::PreCallValidateCreateDirectFBSurfaceEXT(
    VkInstance                                  instance,
    const VkDirectFBSurfaceCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateDirectFBSurfaceEXT(
    VkInstance                                  instance,
    const VkDirectFBSurfaceCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_DIRECTFB_EXT

#ifdef VK_USE_PLATFORM_DIRECTFB_EXT

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceDirectFBPresentationSupportEXT(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    IDirectFB*                                  dfb) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_DIRECTFB_EXT

bool ObjectLifetimes::PreCallValidateCmdSetVertexInputEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT*  pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetVertexInputEXT-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_FUCHSIA

bool ObjectLifetimes::PreCallValidateGetMemoryZirconHandleFUCHSIA(
    VkDevice                                    device,
    const VkMemoryGetZirconHandleInfoFUCHSIA*   pGetZirconHandleInfo,
    zx_handle_t*                                pZirconHandle) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pGetZirconHandleInfo) {
        skip |= ValidateObject(pGetZirconHandleInfo->memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_FUCHSIA

#ifdef VK_USE_PLATFORM_FUCHSIA

bool ObjectLifetimes::PreCallValidateGetMemoryZirconHandlePropertiesFUCHSIA(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    zx_handle_t                                 zirconHandle,
    VkMemoryZirconHandlePropertiesFUCHSIA*      pMemoryZirconHandleProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_FUCHSIA

#ifdef VK_USE_PLATFORM_FUCHSIA

bool ObjectLifetimes::PreCallValidateImportSemaphoreZirconHandleFUCHSIA(
    VkDevice                                    device,
    const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pImportSemaphoreZirconHandleInfo) {
        skip |= ValidateObject(pImportSemaphoreZirconHandleInfo->semaphore, kVulkanObjectTypeSemaphore, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_FUCHSIA

#ifdef VK_USE_PLATFORM_FUCHSIA

bool ObjectLifetimes::PreCallValidateGetSemaphoreZirconHandleFUCHSIA(
    VkDevice                                    device,
    const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo,
    zx_handle_t*                                pZirconHandle) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pGetZirconHandleInfo) {
        skip |= ValidateObject(pGetZirconHandleInfo->semaphore, kVulkanObjectTypeSemaphore, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_FUCHSIA

#ifdef VK_USE_PLATFORM_FUCHSIA

bool ObjectLifetimes::PreCallValidateCreateBufferCollectionFUCHSIA(
    VkDevice                                    device,
    const VkBufferCollectionCreateInfoFUCHSIA*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferCollectionFUCHSIA*                  pCollection) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateBufferCollectionFUCHSIA(
    VkDevice                                    device,
    const VkBufferCollectionCreateInfoFUCHSIA*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferCollectionFUCHSIA*                  pCollection,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pCollection, kVulkanObjectTypeBufferCollectionFUCHSIA, pAllocator);

}
#endif // VK_USE_PLATFORM_FUCHSIA

#ifdef VK_USE_PLATFORM_FUCHSIA

bool ObjectLifetimes::PreCallValidateSetBufferCollectionImageConstraintsFUCHSIA(
    VkDevice                                    device,
    VkBufferCollectionFUCHSIA                   collection,
    const VkImageConstraintsInfoFUCHSIA*        pImageConstraintsInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(collection, kVulkanObjectTypeBufferCollectionFUCHSIA, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_FUCHSIA

#ifdef VK_USE_PLATFORM_FUCHSIA

bool ObjectLifetimes::PreCallValidateSetBufferCollectionBufferConstraintsFUCHSIA(
    VkDevice                                    device,
    VkBufferCollectionFUCHSIA                   collection,
    const VkBufferConstraintsInfoFUCHSIA*       pBufferConstraintsInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(collection, kVulkanObjectTypeBufferCollectionFUCHSIA, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_FUCHSIA

#ifdef VK_USE_PLATFORM_FUCHSIA

bool ObjectLifetimes::PreCallValidateDestroyBufferCollectionFUCHSIA(
    VkDevice                                    device,
    VkBufferCollectionFUCHSIA                   collection,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(collection, kVulkanObjectTypeBufferCollectionFUCHSIA, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(collection, kVulkanObjectTypeBufferCollectionFUCHSIA, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyBufferCollectionFUCHSIA(
    VkDevice                                    device,
    VkBufferCollectionFUCHSIA                   collection,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(collection, kVulkanObjectTypeBufferCollectionFUCHSIA);

}
#endif // VK_USE_PLATFORM_FUCHSIA

#ifdef VK_USE_PLATFORM_FUCHSIA

bool ObjectLifetimes::PreCallValidateGetBufferCollectionPropertiesFUCHSIA(
    VkDevice                                    device,
    VkBufferCollectionFUCHSIA                   collection,
    VkBufferCollectionPropertiesFUCHSIA*        pProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(collection, kVulkanObjectTypeBufferCollectionFUCHSIA, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_FUCHSIA

bool ObjectLifetimes::PreCallValidateGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(
    VkDevice                                    device,
    VkRenderPass                                renderpass,
    VkExtent2D*                                 pMaxWorkgroupSize) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(renderpass, kVulkanObjectTypeRenderPass, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSubpassShadingHUAWEI(
    VkCommandBuffer                             commandBuffer) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindInvocationMaskHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetMemoryRemoteAddressNV(
    VkDevice                                    device,
    const VkMemoryGetRemoteAddressInfoNV*       pMemoryGetRemoteAddressInfo,
    VkRemoteAddressNV*                          pAddress) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pMemoryGetRemoteAddressInfo) {
        skip |= ValidateObject(pMemoryGetRemoteAddressInfo->memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPipelinePropertiesEXT(
    VkDevice                                    device,
    const VkPipelineInfoEXT*                    pPipelineInfo,
    VkBaseOutStructure*                         pPipelineProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateGetFenceSciSyncFenceNV(
    VkDevice                                    device,
    const VkFenceGetSciSyncInfoNV*              pGetSciSyncHandleInfo,
    void*                                       pHandle) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetFenceSciSyncFenceNV-device-parameter", kVUIDUndefined);
    if (pGetSciSyncHandleInfo) {
        skip |= ValidateObject(pGetSciSyncHandleInfo->fence, kVulkanObjectTypeFence, false, "VUID-VkFenceGetSciSyncInfoNV-fence-parameter", kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateGetFenceSciSyncObjNV(
    VkDevice                                    device,
    const VkFenceGetSciSyncInfoNV*              pGetSciSyncHandleInfo,
    void*                                       pHandle) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetFenceSciSyncObjNV-device-parameter", kVUIDUndefined);
    if (pGetSciSyncHandleInfo) {
        skip |= ValidateObject(pGetSciSyncHandleInfo->fence, kVulkanObjectTypeFence, false, "VUID-VkFenceGetSciSyncInfoNV-fence-parameter", kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateImportFenceSciSyncFenceNV(
    VkDevice                                    device,
    const VkImportFenceSciSyncInfoNV*           pImportFenceSciSyncInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkImportFenceSciSyncFenceNV-device-parameter", kVUIDUndefined);
    if (pImportFenceSciSyncInfo) {
        skip |= ValidateObject(pImportFenceSciSyncInfo->fence, kVulkanObjectTypeFence, false, "VUID-VkImportFenceSciSyncInfoNV-fence-parameter", kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateImportFenceSciSyncObjNV(
    VkDevice                                    device,
    const VkImportFenceSciSyncInfoNV*           pImportFenceSciSyncInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkImportFenceSciSyncObjNV-device-parameter", kVUIDUndefined);
    if (pImportFenceSciSyncInfo) {
        skip |= ValidateObject(pImportFenceSciSyncInfo->fence, kVulkanObjectTypeFence, false, "VUID-VkImportFenceSciSyncInfoNV-fence-parameter", kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSciSyncAttributesNV(
    VkPhysicalDevice                            physicalDevice,
    const VkSciSyncAttributesInfoNV*            pSciSyncAttributesInfo,
    NvSciSyncAttrList                           pAttributes) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceSciSyncAttributesNV-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateGetSemaphoreSciSyncObjNV(
    VkDevice                                    device,
    const VkSemaphoreGetSciSyncInfoNV*          pGetSciSyncInfo,
    void*                                       pHandle) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetSemaphoreSciSyncObjNV-device-parameter", kVUIDUndefined);
    if (pGetSciSyncInfo) {
        skip |= ValidateObject(pGetSciSyncInfo->semaphore, kVulkanObjectTypeSemaphore, false, "VUID-VkSemaphoreGetSciSyncInfoNV-semaphore-parameter", kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateImportSemaphoreSciSyncObjNV(
    VkDevice                                    device,
    const VkImportSemaphoreSciSyncInfoNV*       pImportSemaphoreSciSyncInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkImportSemaphoreSciSyncObjNV-device-parameter", kVUIDUndefined);
    if (pImportSemaphoreSciSyncInfo) {
        skip |= ValidateObject(pImportSemaphoreSciSyncInfo->semaphore, kVulkanObjectTypeSemaphore, false, "VUID-VkImportSemaphoreSciSyncInfoNV-semaphore-parameter", kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateGetMemorySciBufNV(
    VkDevice                                    device,
    const VkMemoryGetSciBufInfoNV*              pGetSciBufInfo,
    NvSciBufObj*                                pHandle) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkGetMemorySciBufNV-device-parameter", kVUIDUndefined);
    if (pGetSciBufInfo) {
        skip |= ValidateObject(pGetSciBufInfo->memory, kVulkanObjectTypeDeviceMemory, false, "VUID-VkMemoryGetSciBufInfoNV-memory-parameter", kVUIDUndefined);
    }

    return skip;
}
#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceExternalMemorySciBufPropertiesNV(
    VkPhysicalDevice                            physicalDevice,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    NvSciBufObj                                 handle,
    VkMemorySciBufPropertiesNV*                 pMemorySciBufProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSciBufAttributesNV(
    VkPhysicalDevice                            physicalDevice,
    NvSciBufAttrList                            pAttributes) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, "VUID-vkGetPhysicalDeviceSciBufAttributesNV-physicalDevice-parameter", kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateCmdSetPatchControlPointsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    patchControlPoints) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetPatchControlPointsEXT-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetRasterizerDiscardEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetRasterizerDiscardEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthBiasEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetDepthBiasEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetLogicOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkLogicOp                                   logicOp) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetLogicOpEXT-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetPrimitiveRestartEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetPrimitiveRestartEnable-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

#ifdef VK_USE_PLATFORM_SCREEN_QNX

bool ObjectLifetimes::PreCallValidateCreateScreenSurfaceQNX(
    VkInstance                                  instance,
    const VkScreenSurfaceCreateInfoQNX*         pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    skip |= ValidateObject(instance, kVulkanObjectTypeInstance, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateScreenSurfaceQNX(
    VkInstance                                  instance,
    const VkScreenSurfaceCreateInfoQNX*         pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator);

}
#endif // VK_USE_PLATFORM_SCREEN_QNX

#ifdef VK_USE_PLATFORM_SCREEN_QNX

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceScreenPresentationSupportQNX(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct _screen_window*                      window) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}
#endif // VK_USE_PLATFORM_SCREEN_QNX

bool ObjectLifetimes::PreCallValidateCmdSetColorWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorWriteEnables) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, "VUID-vkCmdSetColorWriteEnableEXT-commandBuffer-parameter", kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawMultiEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawInfoEXT*                   pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawMultiIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawIndexedInfoEXT*            pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    const int32_t*                              pVertexOffset) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateMicromapEXT(
    VkDevice                                    device,
    const VkMicromapCreateInfoEXT*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkMicromapEXT*                              pMicromap) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pCreateInfo) {
        skip |= ValidateObject(pCreateInfo->buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateMicromapEXT(
    VkDevice                                    device,
    const VkMicromapCreateInfoEXT*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkMicromapEXT*                              pMicromap,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pMicromap, kVulkanObjectTypeMicromapEXT, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyMicromapEXT(
    VkDevice                                    device,
    VkMicromapEXT                               micromap,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(micromap, kVulkanObjectTypeMicromapEXT, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(micromap, kVulkanObjectTypeMicromapEXT, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyMicromapEXT(
    VkDevice                                    device,
    VkMicromapEXT                               micromap,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(micromap, kVulkanObjectTypeMicromapEXT);

}

bool ObjectLifetimes::PreCallValidateCmdBuildMicromapsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfos) {
        for (uint32_t index0 = 0; index0 < infoCount; ++index0) {
            skip |= ValidateObject(pInfos[index0].dstMicromap, kVulkanObjectTypeMicromapEXT, true, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateBuildMicromapsEXT(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(deferredOperation, kVulkanObjectTypeDeferredOperationKHR, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfos) {
        for (uint32_t index0 = 0; index0 < infoCount; ++index0) {
            skip |= ValidateObject(pInfos[index0].dstMicromap, kVulkanObjectTypeMicromapEXT, true, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCopyMicromapEXT(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyMicromapInfoEXT*                pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(deferredOperation, kVulkanObjectTypeDeferredOperationKHR, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->src, kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pInfo->dst, kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCopyMicromapToMemoryEXT(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(deferredOperation, kVulkanObjectTypeDeferredOperationKHR, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->src, kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCopyMemoryToMicromapEXT(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(deferredOperation, kVulkanObjectTypeDeferredOperationKHR, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->dst, kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateWriteMicromapsPropertiesEXT(
    VkDevice                                    device,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    void*                                       pData,
    size_t                                      stride) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if ((micromapCount > 0) && (pMicromaps)) {
        for (uint32_t index0 = 0; index0 < micromapCount; ++index0) {
            skip |= ValidateObject(pMicromaps[index0], kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapInfoEXT*                pInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->src, kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pInfo->dst, kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyMicromapToMemoryEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->src, kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyMemoryToMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->dst, kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWriteMicromapsPropertiesEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if ((micromapCount > 0) && (pMicromaps)) {
        for (uint32_t index0 = 0; index0 < micromapCount; ++index0) {
            skip |= ValidateObject(pMicromaps[index0], kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined);
        }
    }
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceMicromapCompatibilityEXT(
    VkDevice                                    device,
    const VkMicromapVersionInfoEXT*             pVersionInfo,
    VkAccelerationStructureCompatibilityKHR*    pCompatibility) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetMicromapBuildSizesEXT(
    VkDevice                                    device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    const VkMicromapBuildInfoEXT*               pBuildInfo,
    VkMicromapBuildSizesInfoEXT*                pSizeInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pBuildInfo) {
        skip |= ValidateObject(pBuildInfo->dstMicromap, kVulkanObjectTypeMicromapEXT, true, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawClusterHUAWEI(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawClusterIndirectHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateSetDeviceMemoryPriorityEXT(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    float                                       priority) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDescriptorSetLayoutHostMappingInfoVALVE(
    VkDevice                                    device,
    const VkDescriptorSetBindingReferenceVALVE* pBindingReference,
    VkDescriptorSetLayoutHostMappingInfoVALVE*  pHostMapping) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pBindingReference) {
        skip |= ValidateObject(pBindingReference->descriptorSetLayout, kVulkanObjectTypeDescriptorSetLayout, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDescriptorSetHostMappingVALVE(
    VkDevice                                    device,
    VkDescriptorSet                             descriptorSet,
    void**                                      ppData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(descriptorSet, kVulkanObjectTypeDescriptorSet, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyMemoryIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             copyBufferAddress,
    uint32_t                                    copyCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyMemoryToImageIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             copyBufferAddress,
    uint32_t                                    copyCount,
    uint32_t                                    stride,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkImageSubresourceLayers*             pImageSubresources) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(dstImage, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDecompressMemoryNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    decompressRegionCount,
    const VkDecompressMemoryRegionNV*           pDecompressMemoryRegions) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDecompressMemoryIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectCommandsAddress,
    VkDeviceAddress                             indirectCommandsCountAddress,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetTessellationDomainOriginEXT(
    VkCommandBuffer                             commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthClampEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClampEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetPolygonModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkPolygonMode                               polygonMode) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetRasterizationSamplesEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetSampleMaskEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       samples,
    const VkSampleMask*                         pSampleMask) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetAlphaToCoverageEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToCoverageEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetAlphaToOneEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToOneEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetLogicOpEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    logicOpEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetColorBlendEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorBlendEnables) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetColorBlendEquationEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendEquationEXT*              pColorBlendEquations) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetColorWriteMaskEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorComponentFlags*                pColorWriteMasks) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetRasterizationStreamEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    rasterizationStream) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetExtraPrimitiveOverestimationSizeEXT(
    VkCommandBuffer                             commandBuffer,
    float                                       extraPrimitiveOverestimationSize) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthClipEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClipEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetSampleLocationsEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    sampleLocationsEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetColorBlendAdvancedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendAdvancedEXT*              pColorBlendAdvanced) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetProvokingVertexModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetLineRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetLineStippleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stippledLineEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDepthClipNegativeOneToOneEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    negativeOneToOne) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetViewportWScalingEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    viewportWScalingEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetViewportSwizzleNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportSwizzleNV*                  pViewportSwizzles) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetCoverageToColorEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageToColorEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetCoverageToColorLocationNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageToColorLocation) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetCoverageModulationModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetCoverageModulationTableEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageModulationTableEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetCoverageModulationTableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    const float*                                pCoverageModulationTable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetShadingRateImageEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    shadingRateImageEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetRepresentativeFragmentTestEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    representativeFragmentTestEnable) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetCoverageReductionModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetShaderModuleIdentifierEXT(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    VkShaderModuleIdentifierEXT*                pIdentifier) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(shaderModule, kVulkanObjectTypeShaderModule, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetShaderModuleCreateInfoIdentifierEXT(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    VkShaderModuleIdentifierEXT*                pIdentifier) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceOpticalFlowImageFormatsNV(
    VkPhysicalDevice                            physicalDevice,
    const VkOpticalFlowImageFormatInfoNV*       pOpticalFlowImageFormatInfo,
    uint32_t*                                   pFormatCount,
    VkOpticalFlowImageFormatPropertiesNV*       pImageFormatProperties) const {
    bool skip = false;
    skip |= ValidateObject(physicalDevice, kVulkanObjectTypePhysicalDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateOpticalFlowSessionNV(
    VkDevice                                    device,
    const VkOpticalFlowSessionCreateInfoNV*     pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkOpticalFlowSessionNV*                     pSession) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateOpticalFlowSessionNV(
    VkDevice                                    device,
    const VkOpticalFlowSessionCreateInfoNV*     pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkOpticalFlowSessionNV*                     pSession,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSession, kVulkanObjectTypeOpticalFlowSessionNV, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyOpticalFlowSessionNV(
    VkDevice                                    device,
    VkOpticalFlowSessionNV                      session,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(session, kVulkanObjectTypeOpticalFlowSessionNV, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(session, kVulkanObjectTypeOpticalFlowSessionNV, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyOpticalFlowSessionNV(
    VkDevice                                    device,
    VkOpticalFlowSessionNV                      session,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(session, kVulkanObjectTypeOpticalFlowSessionNV);

}

bool ObjectLifetimes::PreCallValidateBindOpticalFlowSessionImageNV(
    VkDevice                                    device,
    VkOpticalFlowSessionNV                      session,
    VkOpticalFlowSessionBindingPointNV          bindingPoint,
    VkImageView                                 view,
    VkImageLayout                               layout) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(session, kVulkanObjectTypeOpticalFlowSessionNV, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(view, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdOpticalFlowExecuteNV(
    VkCommandBuffer                             commandBuffer,
    VkOpticalFlowSessionNV                      session,
    const VkOpticalFlowExecuteInfoNV*           pExecuteInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(session, kVulkanObjectTypeOpticalFlowSessionNV, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetFramebufferTilePropertiesQCOM(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    uint32_t*                                   pPropertiesCount,
    VkTilePropertiesQCOM*                       pProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(framebuffer, kVulkanObjectTypeFramebuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDynamicRenderingTilePropertiesQCOM(
    VkDevice                                    device,
    const VkRenderingInfo*                      pRenderingInfo,
    VkTilePropertiesQCOM*                       pProperties) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pRenderingInfo) {
        if (pRenderingInfo->pColorAttachments) {
            for (uint32_t index1 = 0; index1 < pRenderingInfo->colorAttachmentCount; ++index1) {
                skip |= ValidateObject(pRenderingInfo->pColorAttachments[index1].imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
                skip |= ValidateObject(pRenderingInfo->pColorAttachments[index1].resolveImageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
            }
        }
        if (pRenderingInfo->pDepthAttachment) {
            skip |= ValidateObject(pRenderingInfo->pDepthAttachment->imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
            skip |= ValidateObject(pRenderingInfo->pDepthAttachment->resolveImageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
        }
        if (pRenderingInfo->pStencilAttachment) {
            skip |= ValidateObject(pRenderingInfo->pStencilAttachment->imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
            skip |= ValidateObject(pRenderingInfo->pStencilAttachment->resolveImageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateCreateSemaphoreSciSyncPoolNV(
    VkDevice                                    device,
    const VkSemaphoreSciSyncPoolCreateInfoNV*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphoreSciSyncPoolNV*                   pSemaphorePool) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, "VUID-vkCreateSemaphoreSciSyncPoolNV-device-parameter", kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateSemaphoreSciSyncPoolNV(
    VkDevice                                    device,
    const VkSemaphoreSciSyncPoolCreateInfoNV*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphoreSciSyncPoolNV*                   pSemaphorePool,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pSemaphorePool, kVulkanObjectTypeSemaphoreSciSyncPoolNV, pAllocator);

}
#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateDestroySemaphoreSciSyncPoolNV(
    VkDevice                                    device,
    VkSemaphoreSciSyncPoolNV                    semaphorePool,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(semaphorePool, kVulkanObjectTypeSemaphoreSciSyncPoolNV, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(semaphorePool, kVulkanObjectTypeSemaphoreSciSyncPoolNV, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroySemaphoreSciSyncPoolNV(
    VkDevice                                    device,
    VkSemaphoreSciSyncPoolNV                    semaphorePool,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(semaphorePool, kVulkanObjectTypeSemaphoreSciSyncPoolNV);

}
#endif // VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateCreateAccelerationStructureKHR(
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureKHR*                 pAccelerationStructure) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pCreateInfo) {
        skip |= ValidateObject(pCreateInfo->buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateAccelerationStructureKHR(
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureKHR*                 pAccelerationStructure,
    VkResult                                    result) {
    if (result != VK_SUCCESS) return;
    CreateObject(*pAccelerationStructure, kVulkanObjectTypeAccelerationStructureKHR, pAllocator);

}

bool ObjectLifetimes::PreCallValidateDestroyAccelerationStructureKHR(
    VkDevice                                    device,
    VkAccelerationStructureKHR                  accelerationStructure,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(accelerationStructure, kVulkanObjectTypeAccelerationStructureKHR, true, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateDestroyObject(accelerationStructure, kVulkanObjectTypeAccelerationStructureKHR, pAllocator, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyAccelerationStructureKHR(
    VkDevice                                    device,
    VkAccelerationStructureKHR                  accelerationStructure,
    const VkAllocationCallbacks*                pAllocator) {
    RecordDestroyObject(accelerationStructure, kVulkanObjectTypeAccelerationStructureKHR);

}

bool ObjectLifetimes::PreCallValidateCopyAccelerationStructureKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyAccelerationStructureInfoKHR*   pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(deferredOperation, kVulkanObjectTypeDeferredOperationKHR, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->src, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pInfo->dst, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCopyAccelerationStructureToMemoryKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(deferredOperation, kVulkanObjectTypeDeferredOperationKHR, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->src, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCopyMemoryToAccelerationStructureKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(deferredOperation, kVulkanObjectTypeDeferredOperationKHR, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->dst, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateWriteAccelerationStructuresPropertiesKHR(
    VkDevice                                    device,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    void*                                       pData,
    size_t                                      stride) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if ((accelerationStructureCount > 0) && (pAccelerationStructures)) {
        for (uint32_t index0 = 0; index0 < accelerationStructureCount; ++index0) {
            skip |= ValidateObject(pAccelerationStructures[index0], kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureInfoKHR*   pInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->src, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pInfo->dst, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->src, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if (pInfo) {
        skip |= ValidateObject(pInfo->dst, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetAccelerationStructureDeviceAddressKHR(
    VkDevice                                    device,
    const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    if ((accelerationStructureCount > 0) && (pAccelerationStructures)) {
        for (uint32_t index0 = 0; index0 < accelerationStructureCount; ++index0) {
            skip |= ValidateObject(pAccelerationStructures[index0], kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined);
        }
    }
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceAccelerationStructureCompatibilityKHR(
    VkDevice                                    device,
    const VkAccelerationStructureVersionInfoKHR* pVersionInfo,
    VkAccelerationStructureCompatibilityKHR*    pCompatibility) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetAccelerationStructureBuildSizesKHR(
    VkDevice                                    device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo,
    const uint32_t*                             pMaxPrimitiveCounts,
    VkAccelerationStructureBuildSizesInfoKHR*   pSizeInfo) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    if (pBuildInfo) {
        skip |= ValidateObject(pBuildInfo->srcAccelerationStructure, kVulkanObjectTypeAccelerationStructureKHR, true, kVUIDUndefined, kVUIDUndefined);
        skip |= ValidateObject(pBuildInfo->dstAccelerationStructure, kVulkanObjectTypeAccelerationStructureKHR, true, kVUIDUndefined, kVUIDUndefined);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdTraceRaysKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    void*                                       pData) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdTraceRaysIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetRayTracingShaderGroupStackSizeKHR(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    group,
    VkShaderGroupShaderKHR                      groupShader) const {
    bool skip = false;
    skip |= ValidateObject(device, kVulkanObjectTypeDevice, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetRayTracingPipelineStackSizeKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    pipelineStackSize) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawMeshTasksEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawMeshTasksIndirectEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawMeshTasksIndirectCountEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateObject(commandBuffer, kVulkanObjectTypeCommandBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);
    skip |= ValidateObject(countBuffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined);

    return skip;
}


