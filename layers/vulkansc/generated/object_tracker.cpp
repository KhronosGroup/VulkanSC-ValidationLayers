// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See object_tracker_generator.py for modifications

/***************************************************************************
 *
 * Copyright (c) 2015-2024 The Khronos Group Inc.
 * Copyright (c) 2015-2024 Valve Corporation
 * Copyright (c) 2015-2024 LunarG, Inc.
 * Copyright (c) 2015-2024 Google Inc.
 * Copyright (c) 2015-2024 RasterGrid Kft.
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
// clang-format off
#include "chassis.h"
#include "object_tracker/object_lifetime_validation.h"
ReadLockGuard ObjectLifetimes::ReadLock() const { return ReadLockGuard(validation_object_mutex, std::defer_lock); }
WriteLockGuard ObjectLifetimes::WriteLock() { return WriteLockGuard(validation_object_mutex, std::defer_lock); }

// ObjectTracker undestroyed objects validation function
bool ObjectLifetimes::ReportUndestroyedInstanceObjects(VkInstance instance, const Location& loc) const {
    bool skip = false;
    const std::string error_code = "VUID-vkDestroyInstance-instance-00629";
    skip |= ReportLeakedInstanceObjects(instance, kVulkanObjectTypeSurfaceKHR, error_code, loc);
    // No destroy API or implicitly freed/destroyed -- do not report: skip |= ReportLeakedInstanceObjects(instance, kVulkanObjectTypeDisplayKHR, error_code, loc);
    // No destroy API or implicitly freed/destroyed -- do not report: skip |= ReportLeakedInstanceObjects(instance, kVulkanObjectTypeDisplayModeKHR, error_code, loc);
    skip |= ReportLeakedInstanceObjects(instance, kVulkanObjectTypeDebugReportCallbackEXT, error_code, loc);
    skip |= ReportLeakedInstanceObjects(instance, kVulkanObjectTypeDebugUtilsMessengerEXT, error_code, loc);
    return skip;
}

bool ObjectLifetimes::ReportUndestroyedDeviceObjects(VkDevice device, const Location& loc) const {
    bool skip = false;
    const std::string error_code = "VUID-vkDestroyDevice-device-05137";
    // No destroy API or implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeCommandBuffer, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeBuffer, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeImage, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeSemaphore, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeFence, error_code, loc);
    // No destroy API or implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeDeviceMemory, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeEvent, error_code, loc);
    // No destroy API or implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeQueryPool, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeBufferView, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeImageView, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeShaderModule, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypePipelineCache, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypePipelineLayout, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypePipeline, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeRenderPass, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeDescriptorSetLayout, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeSampler, error_code, loc);
    // No destroy API or implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeDescriptorSet, error_code, loc);
    // No destroy API or implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeDescriptorPool, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeFramebuffer, error_code, loc);
    // No destroy API or implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeCommandPool, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeSamplerYcbcrConversion, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeDescriptorUpdateTemplate, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypePrivateDataSlot, error_code, loc);
    // No destroy API or implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeSwapchainKHR, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeVideoSessionKHR, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeVideoSessionParametersKHR, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeDeferredOperationKHR, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeCuModuleNVX, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeCuFunctionNVX, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeValidationCacheEXT, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeAccelerationStructureNV, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypePerformanceConfigurationINTEL, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeIndirectCommandsLayoutNV, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeCudaModuleNV, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeCudaFunctionNV, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeAccelerationStructureKHR, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeBufferCollectionFUCHSIA, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeMicromapEXT, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeOpticalFlowSessionNV, error_code, loc);
    skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeShaderEXT, error_code, loc);
    // No destroy API or implicitly freed/destroyed -- do not report: skip |= ReportLeakedDeviceObjects(device, kVulkanObjectTypeSemaphoreSciSyncPoolNV, error_code, loc);
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
    DestroyUndestroyedObjects(kVulkanObjectTypeCudaModuleNV);
    DestroyUndestroyedObjects(kVulkanObjectTypeCudaFunctionNV);
    DestroyUndestroyedObjects(kVulkanObjectTypeAccelerationStructureKHR);
    DestroyUndestroyedObjects(kVulkanObjectTypeBufferCollectionFUCHSIA);
    DestroyUndestroyedObjects(kVulkanObjectTypeMicromapEXT);
    DestroyUndestroyedObjects(kVulkanObjectTypeOpticalFlowSessionNV);
    DestroyUndestroyedObjects(kVulkanObjectTypeShaderEXT);
    DestroyUndestroyedObjects(kVulkanObjectTypeSemaphoreSciSyncPoolNV);
}
// clang-format on
// vkGetPhysicalDeviceFeatures:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceFeatures-physicalDevice-parameter"

// vkGetPhysicalDeviceFormatProperties:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceFormatProperties-physicalDevice-parameter"

// vkGetPhysicalDeviceImageFormatProperties:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceImageFormatProperties-physicalDevice-parameter"

// vkGetPhysicalDeviceProperties:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceProperties-physicalDevice-parameter"

// vkGetPhysicalDeviceMemoryProperties:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceMemoryProperties-physicalDevice-parameter"

// vkGetInstanceProcAddr:
// Checked by chassis: instance: "VUID-vkGetInstanceProcAddr-instance-parameter"

// vkGetDeviceProcAddr:
// Checked by chassis: device: "VUID-vkGetDeviceProcAddr-device-parameter"

// vkEnumerateDeviceExtensionProperties:
// Checked by chassis: physicalDevice: "VUID-vkEnumerateDeviceExtensionProperties-physicalDevice-parameter"

// vkEnumerateDeviceLayerProperties:
// Checked by chassis: physicalDevice: "VUID-vkEnumerateDeviceLayerProperties-physicalDevice-parameter"

bool ObjectLifetimes::PreCallValidateQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence,
                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: queue: "VUID-vkQueueSubmit-queue-parameter"
    // Checked by chassis: queue: "VUID-vkQueueSubmit-commonparent"
    if (pSubmits) {
        for (uint32_t index0 = 0; index0 < submitCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pSubmits, index0);

            if ((pSubmits[index0].waitSemaphoreCount > 0) && (pSubmits[index0].pWaitSemaphores)) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].waitSemaphoreCount; ++index1) {
                    skip |= ValidateObject(pSubmits[index0].pWaitSemaphores[index1], kVulkanObjectTypeSemaphore, false,
                                           "VUID-VkSubmitInfo-pWaitSemaphores-parameter", "VUID-VkSubmitInfo-commonparent",
                                           index0_loc.dot(Field::pWaitSemaphores, index1));
                }
            }

            if ((pSubmits[index0].commandBufferCount > 0) && (pSubmits[index0].pCommandBuffers)) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].commandBufferCount; ++index1) {
                    skip |= ValidateObject(pSubmits[index0].pCommandBuffers[index1], kVulkanObjectTypeCommandBuffer, false,
                                           "VUID-VkSubmitInfo-pCommandBuffers-parameter", "VUID-VkSubmitInfo-commonparent",
                                           index0_loc.dot(Field::pCommandBuffers, index1));
                }
            }

            if ((pSubmits[index0].signalSemaphoreCount > 0) && (pSubmits[index0].pSignalSemaphores)) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].signalSemaphoreCount; ++index1) {
                    skip |= ValidateObject(pSubmits[index0].pSignalSemaphores[index1], kVulkanObjectTypeSemaphore, false,
                                           "VUID-VkSubmitInfo-pSignalSemaphores-parameter", "VUID-VkSubmitInfo-commonparent",
                                           index0_loc.dot(Field::pSignalSemaphores, index1));
                }
            }
            if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkFrameBoundaryEXT>(pSubmits[index0].pNext)) {
                [[maybe_unused]] const Location pNext_loc = index0_loc.pNext(Struct::VkFrameBoundaryEXT);

                if ((pNext->imageCount > 0) && (pNext->pImages)) {
                    for (uint32_t index2 = 0; index2 < pNext->imageCount; ++index2) {
                        skip |= ValidateObject(pNext->pImages[index2], kVulkanObjectTypeImage, false, kVUIDUndefined,
                                               "UNASSIGNED-VkFrameBoundaryEXT-commonparent", pNext_loc.dot(Field::pImages, index2));
                    }
                }

                if ((pNext->bufferCount > 0) && (pNext->pBuffers)) {
                    for (uint32_t index2 = 0; index2 < pNext->bufferCount; ++index2) {
                        skip |=
                            ValidateObject(pNext->pBuffers[index2], kVulkanObjectTypeBuffer, false, kVUIDUndefined,
                                           "UNASSIGNED-VkFrameBoundaryEXT-commonparent", pNext_loc.dot(Field::pBuffers, index2));
                    }
                }
            }
#ifdef VK_USE_PLATFORM_WIN32_KHR
            if ([[maybe_unused]] auto pNext =
                    vku::FindStructInPNextChain<VkWin32KeyedMutexAcquireReleaseInfoKHR>(pSubmits[index0].pNext)) {
                [[maybe_unused]] const Location pNext_loc = index0_loc.pNext(Struct::VkWin32KeyedMutexAcquireReleaseInfoKHR);

                if ((pNext->acquireCount > 0) && (pNext->pAcquireSyncs)) {
                    for (uint32_t index2 = 0; index2 < pNext->acquireCount; ++index2) {
                        skip |= ValidateObject(pNext->pAcquireSyncs[index2], kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined,
                                               "UNASSIGNED-VkWin32KeyedMutexAcquireReleaseInfoKHR-commonparent",
                                               pNext_loc.dot(Field::pAcquireSyncs, index2));
                    }
                }

                if ((pNext->releaseCount > 0) && (pNext->pReleaseSyncs)) {
                    for (uint32_t index2 = 0; index2 < pNext->releaseCount; ++index2) {
                        skip |= ValidateObject(pNext->pReleaseSyncs[index2], kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined,
                                               "UNASSIGNED-VkWin32KeyedMutexAcquireReleaseInfoKHR-commonparent",
                                               pNext_loc.dot(Field::pReleaseSyncs, index2));
                    }
                }
            }
            if ([[maybe_unused]] auto pNext =
                    vku::FindStructInPNextChain<VkWin32KeyedMutexAcquireReleaseInfoNV>(pSubmits[index0].pNext)) {
                [[maybe_unused]] const Location pNext_loc = index0_loc.pNext(Struct::VkWin32KeyedMutexAcquireReleaseInfoNV);

                if ((pNext->acquireCount > 0) && (pNext->pAcquireSyncs)) {
                    for (uint32_t index2 = 0; index2 < pNext->acquireCount; ++index2) {
                        skip |= ValidateObject(pNext->pAcquireSyncs[index2], kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined,
                                               "UNASSIGNED-VkWin32KeyedMutexAcquireReleaseInfoNV-commonparent",
                                               pNext_loc.dot(Field::pAcquireSyncs, index2));
                    }
                }

                if ((pNext->releaseCount > 0) && (pNext->pReleaseSyncs)) {
                    for (uint32_t index2 = 0; index2 < pNext->releaseCount; ++index2) {
                        skip |= ValidateObject(pNext->pReleaseSyncs[index2], kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined,
                                               "UNASSIGNED-VkWin32KeyedMutexAcquireReleaseInfoNV-commonparent",
                                               pNext_loc.dot(Field::pReleaseSyncs, index2));
                    }
                }
            }
#endif  // VK_USE_PLATFORM_WIN32_KHR
        }
    }
    skip |= ValidateObject(fence, kVulkanObjectTypeFence, true, "VUID-vkQueueSubmit-fence-parameter",
                           "VUID-vkQueueSubmit-commonparent", error_obj.location.dot(Field::fence));

    return skip;
}

// vkQueueWaitIdle:
// Checked by chassis: queue: "VUID-vkQueueWaitIdle-queue-parameter"

// vkDeviceWaitIdle:
// Checked by chassis: device: "VUID-vkDeviceWaitIdle-device-parameter"

bool ObjectLifetimes::PreCallValidateAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory,
                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkAllocateMemory-device-parameter"
    if (pAllocateInfo) {
        [[maybe_unused]] const Location pAllocateInfo_loc = error_obj.location.dot(Field::pAllocateInfo);
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkDedicatedAllocationMemoryAllocateInfoNV>(pAllocateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pAllocateInfo_loc.pNext(Struct::VkDedicatedAllocationMemoryAllocateInfoNV);
        }
#ifdef VK_USE_PLATFORM_FUCHSIA
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkImportMemoryBufferCollectionFUCHSIA>(pAllocateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pAllocateInfo_loc.pNext(Struct::VkImportMemoryBufferCollectionFUCHSIA);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pNext->collection, kVulkanObjectTypeBufferCollectionFUCHSIA, false, kVUIDUndefined,
                                   kVUIDUndefined, pNext_loc.dot(Field::collection));
        }
#endif  // VK_USE_PLATFORM_FUCHSIA
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkMemoryDedicatedAllocateInfo>(pAllocateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pAllocateInfo_loc.pNext(Struct::VkMemoryDedicatedAllocateInfo);
            skip |= ValidateObject(pNext->image, kVulkanObjectTypeImage, true, "VUID-VkMemoryDedicatedAllocateInfo-image-parameter",
                                   "VUID-VkMemoryDedicatedAllocateInfo-commonparent", pNext_loc.dot(Field::image));
            skip |=
                ValidateObject(pNext->buffer, kVulkanObjectTypeBuffer, true, "VUID-VkMemoryDedicatedAllocateInfo-buffer-parameter",
                               "VUID-VkMemoryDedicatedAllocateInfo-commonparent", pNext_loc.dot(Field::buffer));
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory,
                                                   const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pMemory, kVulkanObjectTypeDeviceMemory, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator,
                                                const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(memory, kVulkanObjectTypeDeviceMemory, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator,
                                              const RecordObject& record_obj) {
    RecordDestroyObject(memory, kVulkanObjectTypeDeviceMemory);
}

bool ObjectLifetimes::PreCallValidateMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size,
                                               VkMemoryMapFlags flags, void** ppData, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkMapMemory-device-parameter"
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, false, "VUID-vkMapMemory-memory-parameter",
                           "VUID-vkMapMemory-memory-parent", error_obj.location.dot(Field::memory));

    return skip;
}

bool ObjectLifetimes::PreCallValidateUnmapMemory(VkDevice device, VkDeviceMemory memory, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkUnmapMemory-device-parameter"
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, false, "VUID-vkUnmapMemory-memory-parameter",
                           "VUID-vkUnmapMemory-memory-parent", error_obj.location.dot(Field::memory));

    return skip;
}

bool ObjectLifetimes::PreCallValidateFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                             const VkMappedMemoryRange* pMemoryRanges,
                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkFlushMappedMemoryRanges-device-parameter"
    if (pMemoryRanges) {
        for (uint32_t index0 = 0; index0 < memoryRangeCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pMemoryRanges, index0);
            skip |= ValidateObject(pMemoryRanges[index0].memory, kVulkanObjectTypeDeviceMemory, false,
                                   "VUID-VkMappedMemoryRange-memory-parameter", kVUIDUndefined, index0_loc.dot(Field::memory));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                                  const VkMappedMemoryRange* pMemoryRanges,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkInvalidateMappedMemoryRanges-device-parameter"
    if (pMemoryRanges) {
        for (uint32_t index0 = 0; index0 < memoryRangeCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pMemoryRanges, index0);
            skip |= ValidateObject(pMemoryRanges[index0].memory, kVulkanObjectTypeDeviceMemory, false,
                                   "VUID-VkMappedMemoryRange-memory-parameter", kVUIDUndefined, index0_loc.dot(Field::memory));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory,
                                                               VkDeviceSize* pCommittedMemoryInBytes,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetDeviceMemoryCommitment-device-parameter"
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, false, "VUID-vkGetDeviceMemoryCommitment-memory-parameter",
                           "VUID-vkGetDeviceMemoryCommitment-memory-parent", error_obj.location.dot(Field::memory));

    return skip;
}

bool ObjectLifetimes::PreCallValidateBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory,
                                                      VkDeviceSize memoryOffset, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkBindBufferMemory-device-parameter"
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkBindBufferMemory-buffer-parameter",
                           "VUID-vkBindBufferMemory-buffer-parent", error_obj.location.dot(Field::buffer));
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, false, "VUID-vkBindBufferMemory-memory-parameter",
                           "VUID-vkBindBufferMemory-memory-parent", error_obj.location.dot(Field::memory));

    return skip;
}

bool ObjectLifetimes::PreCallValidateBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory,
                                                     VkDeviceSize memoryOffset, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkBindImageMemory-device-parameter"
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, "VUID-vkBindImageMemory-image-parameter",
                           "VUID-vkBindImageMemory-image-parent", error_obj.location.dot(Field::image));
    skip |= ValidateObject(memory, kVulkanObjectTypeDeviceMemory, false, "VUID-vkBindImageMemory-memory-parameter",
                           "VUID-vkBindImageMemory-memory-parent", error_obj.location.dot(Field::memory));

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer,
                                                                 VkMemoryRequirements* pMemoryRequirements,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetBufferMemoryRequirements-device-parameter"
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkGetBufferMemoryRequirements-buffer-parameter",
                           "VUID-vkGetBufferMemoryRequirements-buffer-parent", error_obj.location.dot(Field::buffer));

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageMemoryRequirements(VkDevice device, VkImage image,
                                                                VkMemoryRequirements* pMemoryRequirements,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetImageMemoryRequirements-device-parameter"
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, "VUID-vkGetImageMemoryRequirements-image-parameter",
                           "VUID-vkGetImageMemoryRequirements-image-parent", error_obj.location.dot(Field::image));

    return skip;
}

// vkGetImageSparseMemoryRequirements:
// Checked by chassis: device: kVUIDUndefined

// vkGetPhysicalDeviceSparseImageFormatProperties:
// Checked by chassis: physicalDevice: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo,
                                                     VkFence fence, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: queue: kVUIDUndefined
    // Checked by chassis: queue: "UNASSIGNED-vkQueueBindSparse-commonparent"
    if (pBindInfo) {
        for (uint32_t index0 = 0; index0 < bindInfoCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pBindInfo, index0);

            if ((pBindInfo[index0].waitSemaphoreCount > 0) && (pBindInfo[index0].pWaitSemaphores)) {
                for (uint32_t index1 = 0; index1 < pBindInfo[index0].waitSemaphoreCount; ++index1) {
                    skip |=
                        ValidateObject(pBindInfo[index0].pWaitSemaphores[index1], kVulkanObjectTypeSemaphore, false, kVUIDUndefined,
                                       "UNASSIGNED-VkBindSparseInfo-commonparent", index0_loc.dot(Field::pWaitSemaphores, index1));
                }
            }
            if (pBindInfo[index0].pBufferBinds) {
                for (uint32_t index1 = 0; index1 < pBindInfo[index0].bufferBindCount; ++index1) {
                    [[maybe_unused]] const Location index1_loc = index0_loc.dot(Field::pBufferBinds, index1);
                    // There should be an explicit VU (if not that is a spec bug)
                    skip |= ValidateObject(pBindInfo[index0].pBufferBinds[index1].buffer, kVulkanObjectTypeBuffer, false,
                                           kVUIDUndefined, kVUIDUndefined, index1_loc.dot(Field::buffer));
                    if (pBindInfo[index0].pBufferBinds[index1].pBinds) {
                        for (uint32_t index2 = 0; index2 < pBindInfo[index0].pBufferBinds[index1].bindCount; ++index2) {
                            [[maybe_unused]] const Location index2_loc = index1_loc.dot(Field::pBinds, index2);
                            // There should be an explicit VU (if not that is a spec bug)
                            skip |= ValidateObject(pBindInfo[index0].pBufferBinds[index1].pBinds[index2].memory,
                                                   kVulkanObjectTypeDeviceMemory, true, kVUIDUndefined, kVUIDUndefined,
                                                   index2_loc.dot(Field::memory));
                        }
                    }
                }
            }
            if (pBindInfo[index0].pImageOpaqueBinds) {
                for (uint32_t index1 = 0; index1 < pBindInfo[index0].imageOpaqueBindCount; ++index1) {
                    [[maybe_unused]] const Location index1_loc = index0_loc.dot(Field::pImageOpaqueBinds, index1);
                    // There should be an explicit VU (if not that is a spec bug)
                    skip |= ValidateObject(pBindInfo[index0].pImageOpaqueBinds[index1].image, kVulkanObjectTypeImage, false,
                                           kVUIDUndefined, kVUIDUndefined, index1_loc.dot(Field::image));
                    if (pBindInfo[index0].pImageOpaqueBinds[index1].pBinds) {
                        for (uint32_t index2 = 0; index2 < pBindInfo[index0].pImageOpaqueBinds[index1].bindCount; ++index2) {
                            [[maybe_unused]] const Location index2_loc = index1_loc.dot(Field::pBinds, index2);
                            // There should be an explicit VU (if not that is a spec bug)
                            skip |= ValidateObject(pBindInfo[index0].pImageOpaqueBinds[index1].pBinds[index2].memory,
                                                   kVulkanObjectTypeDeviceMemory, true, kVUIDUndefined, kVUIDUndefined,
                                                   index2_loc.dot(Field::memory));
                        }
                    }
                }
            }
            if (pBindInfo[index0].pImageBinds) {
                for (uint32_t index1 = 0; index1 < pBindInfo[index0].imageBindCount; ++index1) {
                    [[maybe_unused]] const Location index1_loc = index0_loc.dot(Field::pImageBinds, index1);
                    // There should be an explicit VU (if not that is a spec bug)
                    skip |= ValidateObject(pBindInfo[index0].pImageBinds[index1].image, kVulkanObjectTypeImage, false,
                                           kVUIDUndefined, kVUIDUndefined, index1_loc.dot(Field::image));
                    if (pBindInfo[index0].pImageBinds[index1].pBinds) {
                        for (uint32_t index2 = 0; index2 < pBindInfo[index0].pImageBinds[index1].bindCount; ++index2) {
                            [[maybe_unused]] const Location index2_loc = index1_loc.dot(Field::pBinds, index2);
                            // There should be an explicit VU (if not that is a spec bug)
                            skip |= ValidateObject(pBindInfo[index0].pImageBinds[index1].pBinds[index2].memory,
                                                   kVulkanObjectTypeDeviceMemory, true, kVUIDUndefined, kVUIDUndefined,
                                                   index2_loc.dot(Field::memory));
                        }
                    }
                }
            }

            if ((pBindInfo[index0].signalSemaphoreCount > 0) && (pBindInfo[index0].pSignalSemaphores)) {
                for (uint32_t index1 = 0; index1 < pBindInfo[index0].signalSemaphoreCount; ++index1) {
                    skip |= ValidateObject(pBindInfo[index0].pSignalSemaphores[index1], kVulkanObjectTypeSemaphore, false,
                                           kVUIDUndefined, "UNASSIGNED-VkBindSparseInfo-commonparent",
                                           index0_loc.dot(Field::pSignalSemaphores, index1));
                }
            }
            if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkFrameBoundaryEXT>(pBindInfo[index0].pNext)) {
                [[maybe_unused]] const Location pNext_loc = index0_loc.pNext(Struct::VkFrameBoundaryEXT);

                if ((pNext->imageCount > 0) && (pNext->pImages)) {
                    for (uint32_t index2 = 0; index2 < pNext->imageCount; ++index2) {
                        skip |= ValidateObject(pNext->pImages[index2], kVulkanObjectTypeImage, false, kVUIDUndefined,
                                               "UNASSIGNED-VkFrameBoundaryEXT-commonparent", pNext_loc.dot(Field::pImages, index2));
                    }
                }

                if ((pNext->bufferCount > 0) && (pNext->pBuffers)) {
                    for (uint32_t index2 = 0; index2 < pNext->bufferCount; ++index2) {
                        skip |=
                            ValidateObject(pNext->pBuffers[index2], kVulkanObjectTypeBuffer, false, kVUIDUndefined,
                                           "UNASSIGNED-VkFrameBoundaryEXT-commonparent", pNext_loc.dot(Field::pBuffers, index2));
                    }
                }
            }
        }
    }

    return skip;
}

// vkCreateFence:
// Checked by chassis: device: "VUID-vkCreateFence-device-parameter"

void ObjectLifetimes::PostCallRecordCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkFence* pFence,
                                                const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pFence, kVulkanObjectTypeFence, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator,
                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroyFence-device-parameter"
    skip |= ValidateObject(fence, kVulkanObjectTypeFence, true, "VUID-vkDestroyFence-fence-parameter",
                           "VUID-vkDestroyFence-fence-parent", error_obj.location.dot(Field::fence));
    skip |= ValidateDestroyObject(fence, kVulkanObjectTypeFence, pAllocator, kVUIDUndefined, kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator,
                                                const RecordObject& record_obj) {
    RecordDestroyObject(fence, kVulkanObjectTypeFence);
}

bool ObjectLifetimes::PreCallValidateResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences,
                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkResetFences-device-parameter"

    if ((fenceCount > 0) && (pFences)) {
        for (uint32_t index0 = 0; index0 < fenceCount; ++index0) {
            skip |= ValidateObject(pFences[index0], kVulkanObjectTypeFence, false, "VUID-vkResetFences-pFences-parameter",
                                   "VUID-vkResetFences-pFences-parent", error_obj.location.dot(Field::pFences, index0));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetFenceStatus(VkDevice device, VkFence fence, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetFenceStatus-device-parameter"
    skip |= ValidateObject(fence, kVulkanObjectTypeFence, false, "VUID-vkGetFenceStatus-fence-parameter",
                           "VUID-vkGetFenceStatus-fence-parent", error_obj.location.dot(Field::fence));

    return skip;
}

bool ObjectLifetimes::PreCallValidateWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll,
                                                   uint64_t timeout, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkWaitForFences-device-parameter"

    if ((fenceCount > 0) && (pFences)) {
        for (uint32_t index0 = 0; index0 < fenceCount; ++index0) {
            skip |= ValidateObject(pFences[index0], kVulkanObjectTypeFence, false, "VUID-vkWaitForFences-pFences-parameter",
                                   "VUID-vkWaitForFences-pFences-parent", error_obj.location.dot(Field::pFences, index0));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore,
                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkCreateSemaphore-device-parameter"
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
#ifdef VK_USE_PLATFORM_SCI
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkSemaphoreSciSyncCreateInfoNV>(pCreateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pCreateInfo_loc.pNext(Struct::VkSemaphoreSciSyncCreateInfoNV);
            skip |= ValidateObject(pNext->semaphorePool, kVulkanObjectTypeSemaphoreSciSyncPoolNV, false,
                                   "VUID-VkSemaphoreSciSyncCreateInfoNV-semaphorePool-parameter",
                                   "UNASSIGNED-VkSemaphoreSciSyncCreateInfoNV-semaphorePool-parent",
                                   pNext_loc.dot(Field::semaphorePool));
        }
#endif  // VK_USE_PLATFORM_SCI
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore,
                                                    const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSemaphore, kVulkanObjectTypeSemaphore, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroySemaphore(VkDevice device, VkSemaphore semaphore,
                                                      const VkAllocationCallbacks* pAllocator, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroySemaphore-device-parameter"
    skip |= ValidateObject(semaphore, kVulkanObjectTypeSemaphore, true, "VUID-vkDestroySemaphore-semaphore-parameter",
                           "VUID-vkDestroySemaphore-semaphore-parent", error_obj.location.dot(Field::semaphore));
    skip |= ValidateDestroyObject(semaphore, kVulkanObjectTypeSemaphore, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator,
                                                    const RecordObject& record_obj) {
    RecordDestroyObject(semaphore, kVulkanObjectTypeSemaphore);
}

// vkCreateEvent:
// Checked by chassis: device: "VUID-vkCreateEvent-device-parameter"

void ObjectLifetimes::PostCallRecordCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkEvent* pEvent,
                                                const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pEvent, kVulkanObjectTypeEvent, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator,
                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroyEvent-device-parameter"
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, true, "VUID-vkDestroyEvent-event-parameter",
                           "VUID-vkDestroyEvent-event-parent", error_obj.location.dot(Field::event));
    skip |= ValidateDestroyObject(event, kVulkanObjectTypeEvent, pAllocator, kVUIDUndefined, kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator,
                                                const RecordObject& record_obj) {
    RecordDestroyObject(event, kVulkanObjectTypeEvent);
}

bool ObjectLifetimes::PreCallValidateGetEventStatus(VkDevice device, VkEvent event, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetEventStatus-device-parameter"
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkGetEventStatus-event-parameter",
                           "VUID-vkGetEventStatus-event-parent", error_obj.location.dot(Field::event));

    return skip;
}

bool ObjectLifetimes::PreCallValidateSetEvent(VkDevice device, VkEvent event, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkSetEvent-device-parameter"
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkSetEvent-event-parameter", "VUID-vkSetEvent-event-parent",
                           error_obj.location.dot(Field::event));

    return skip;
}

bool ObjectLifetimes::PreCallValidateResetEvent(VkDevice device, VkEvent event, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkResetEvent-device-parameter"
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkResetEvent-event-parameter",
                           "VUID-vkResetEvent-event-parent", error_obj.location.dot(Field::event));

    return skip;
}

// vkCreateQueryPool:
// Checked by chassis: device: "VUID-vkCreateQueryPool-device-parameter"

void ObjectLifetimes::PostCallRecordCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool,
                                                    const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pQueryPool, kVulkanObjectTypeQueryPool, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyQueryPool(VkDevice device, VkQueryPool queryPool,
                                                      const VkAllocationCallbacks* pAllocator, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(queryPool, kVulkanObjectTypeQueryPool, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator,
                                                    const RecordObject& record_obj) {
    RecordDestroyObject(queryPool, kVulkanObjectTypeQueryPool);
}

bool ObjectLifetimes::PreCallValidateGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                                         uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride,
                                                         VkQueryResultFlags flags, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetQueryPoolResults-device-parameter"
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkGetQueryPoolResults-queryPool-parameter",
                           "VUID-vkGetQueryPoolResults-queryPool-parent", error_obj.location.dot(Field::queryPool));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer,
                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkCreateBuffer-device-parameter"
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
#ifdef VK_USE_PLATFORM_FUCHSIA
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkBufferCollectionBufferCreateInfoFUCHSIA>(pCreateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pCreateInfo_loc.pNext(Struct::VkBufferCollectionBufferCreateInfoFUCHSIA);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pNext->collection, kVulkanObjectTypeBufferCollectionFUCHSIA, false, kVUIDUndefined,
                                   kVUIDUndefined, pNext_loc.dot(Field::collection));
        }
#endif  // VK_USE_PLATFORM_FUCHSIA
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer,
                                                 const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pBuffer, kVulkanObjectTypeBuffer, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator,
                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroyBuffer-device-parameter"
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, true, "VUID-vkDestroyBuffer-buffer-parameter",
                           "VUID-vkDestroyBuffer-buffer-parent", error_obj.location.dot(Field::buffer));
    skip |= ValidateDestroyObject(buffer, kVulkanObjectTypeBuffer, pAllocator, kVUIDUndefined, kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator,
                                                 const RecordObject& record_obj) {
    RecordDestroyObject(buffer, kVulkanObjectTypeBuffer);
}

bool ObjectLifetimes::PreCallValidateCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkBufferView* pView,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkCreateBufferView-device-parameter"
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        skip |= ValidateObject(pCreateInfo->buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferViewCreateInfo-buffer-parameter",
                               kVUIDUndefined, pCreateInfo_loc.dot(Field::buffer));
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkBufferView* pView,
                                                     const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pView, kVulkanObjectTypeBufferView, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyBufferView(VkDevice device, VkBufferView bufferView,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroyBufferView-device-parameter"
    skip |= ValidateObject(bufferView, kVulkanObjectTypeBufferView, true, "VUID-vkDestroyBufferView-bufferView-parameter",
                           "VUID-vkDestroyBufferView-bufferView-parent", error_obj.location.dot(Field::bufferView));
    skip |= ValidateDestroyObject(bufferView, kVulkanObjectTypeBufferView, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyBufferView(VkDevice device, VkBufferView bufferView,
                                                     const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(bufferView, kVulkanObjectTypeBufferView);
}

bool ObjectLifetimes::PreCallValidateCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkImage* pImage,
                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkCreateImage-device-parameter"
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
#ifdef VK_USE_PLATFORM_FUCHSIA
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkBufferCollectionImageCreateInfoFUCHSIA>(pCreateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pCreateInfo_loc.pNext(Struct::VkBufferCollectionImageCreateInfoFUCHSIA);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pNext->collection, kVulkanObjectTypeBufferCollectionFUCHSIA, false, kVUIDUndefined,
                                   kVUIDUndefined, pNext_loc.dot(Field::collection));
        }
#endif  // VK_USE_PLATFORM_FUCHSIA
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkImageSwapchainCreateInfoKHR>(pCreateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pCreateInfo_loc.pNext(Struct::VkImageSwapchainCreateInfoKHR);
            skip |= ValidateObject(pNext->swapchain, kVulkanObjectTypeSwapchainKHR, true,
                                   "VUID-VkImageSwapchainCreateInfoKHR-swapchain-parameter", kVUIDUndefined,
                                   pNext_loc.dot(Field::swapchain));
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkImage* pImage,
                                                const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pImage, kVulkanObjectTypeImage, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator,
                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroyImage-device-parameter"
    skip |= ValidateObject(image, kVulkanObjectTypeImage, true, "VUID-vkDestroyImage-image-parameter",
                           "VUID-vkDestroyImage-image-parent", error_obj.location.dot(Field::image));
    skip |= ValidateDestroyObject(image, kVulkanObjectTypeImage, pAllocator, kVUIDUndefined, kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator,
                                                const RecordObject& record_obj) {
    RecordDestroyObject(image, kVulkanObjectTypeImage);
}

bool ObjectLifetimes::PreCallValidateGetImageSubresourceLayout(VkDevice device, VkImage image,
                                                               const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetImageSubresourceLayout-device-parameter"
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, "VUID-vkGetImageSubresourceLayout-image-parameter",
                           "VUID-vkGetImageSubresourceLayout-image-parent", error_obj.location.dot(Field::image));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkImageView* pView,
                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkCreateImageView-device-parameter"
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        skip |= ValidateObject(pCreateInfo->image, kVulkanObjectTypeImage, false, "VUID-VkImageViewCreateInfo-image-parameter",
                               "VUID-vkCreateImageView-image-09179", pCreateInfo_loc.dot(Field::image));
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkSamplerYcbcrConversionInfo>(pCreateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pCreateInfo_loc.pNext(Struct::VkSamplerYcbcrConversionInfo);
            skip |= ValidateObject(pNext->conversion, kVulkanObjectTypeSamplerYcbcrConversion, false,
                                   "VUID-VkSamplerYcbcrConversionInfo-conversion-parameter", kVUIDUndefined,
                                   pNext_loc.dot(Field::conversion));
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkImageView* pView,
                                                    const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pView, kVulkanObjectTypeImageView, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyImageView(VkDevice device, VkImageView imageView,
                                                      const VkAllocationCallbacks* pAllocator, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroyImageView-device-parameter"
    skip |= ValidateObject(imageView, kVulkanObjectTypeImageView, true, "VUID-vkDestroyImageView-imageView-parameter",
                           "VUID-vkDestroyImageView-imageView-parent", error_obj.location.dot(Field::imageView));
    skip |= ValidateDestroyObject(imageView, kVulkanObjectTypeImageView, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator,
                                                    const RecordObject& record_obj) {
    RecordDestroyObject(imageView, kVulkanObjectTypeImageView);
}

bool ObjectLifetimes::PreCallValidateCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkShaderModuleValidationCacheCreateInfoEXT>(pCreateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pCreateInfo_loc.pNext(Struct::VkShaderModuleValidationCacheCreateInfoEXT);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pNext->validationCache, kVulkanObjectTypeValidationCacheEXT, false, kVUIDUndefined,
                                   kVUIDUndefined, pNext_loc.dot(Field::validationCache));
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule,
                                                       const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pShaderModule, kVulkanObjectTypeShaderModule, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                                         const VkAllocationCallbacks* pAllocator,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(shaderModule, kVulkanObjectTypeShaderModule, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                                       const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(shaderModule, kVulkanObjectTypeShaderModule);
}

// vkCreatePipelineCache:
// Checked by chassis: device: "VUID-vkCreatePipelineCache-device-parameter"

void ObjectLifetimes::PostCallRecordCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache,
                                                        const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pPipelineCache, kVulkanObjectTypePipelineCache, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache,
                                                          const VkAllocationCallbacks* pAllocator,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroyPipelineCache-device-parameter"
    skip |=
        ValidateObject(pipelineCache, kVulkanObjectTypePipelineCache, true, "VUID-vkDestroyPipelineCache-pipelineCache-parameter",
                       "VUID-vkDestroyPipelineCache-pipelineCache-parent", error_obj.location.dot(Field::pipelineCache));
    skip |= ValidateDestroyObject(pipelineCache, kVulkanObjectTypePipelineCache, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache,
                                                        const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(pipelineCache, kVulkanObjectTypePipelineCache);
}

// vkGetPipelineCacheData:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount,
                                                         const VkPipelineCache* pSrcCaches, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined

    if ((srcCacheCount > 0) && (pSrcCaches)) {
        for (uint32_t index0 = 0; index0 < srcCacheCount; ++index0) {
            skip |= ValidateObject(pSrcCaches[index0], kVulkanObjectTypePipelineCache, false, kVUIDUndefined,
                                   "UNASSIGNED-vkMergePipelineCaches-pSrcCaches-parent",
                                   error_obj.location.dot(Field::pSrcCaches, index0));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                             uint32_t createInfoCount,
                                                             const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                             const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkCreateGraphicsPipelines-device-parameter"
    skip |= ValidateObject(pipelineCache, kVulkanObjectTypePipelineCache, false,
                           "VUID-vkCreateGraphicsPipelines-pipelineCache-parameter",
                           "VUID-vkCreateGraphicsPipelines-pipelineCache-parent", error_obj.location.dot(Field::pipelineCache));
    if (pCreateInfos) {
        for (uint32_t index0 = 0; index0 < createInfoCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pCreateInfos, index0);
            if (pCreateInfos[index0].pStages) {
                for (uint32_t index1 = 0; index1 < pCreateInfos[index0].stageCount; ++index1) {
                    [[maybe_unused]] const Location index1_loc = index0_loc.dot(Field::pStages, index1);
                    skip |= ValidateObject(pCreateInfos[index0].pStages[index1].module, kVulkanObjectTypeShaderModule, true,
                                           "VUID-VkPipelineShaderStageCreateInfo-module-parameter", kVUIDUndefined,
                                           index1_loc.dot(Field::module));
                    if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkShaderModuleValidationCacheCreateInfoEXT>(
                            pCreateInfos[index0].pStages[index1].pNext)) {
                        [[maybe_unused]] const Location pNext_loc =
                            index1_loc.pNext(Struct::VkShaderModuleValidationCacheCreateInfoEXT);
                        // There should be an explicit VU (if not that is a spec bug)
                        skip |= ValidateObject(pNext->validationCache, kVulkanObjectTypeValidationCacheEXT, false, kVUIDUndefined,
                                               kVUIDUndefined, pNext_loc.dot(Field::validationCache));
                    }
                }
            }
            if ((pCreateInfos[index0].flags & VK_PIPELINE_CREATE_DERIVATIVE_BIT) && (pCreateInfos[index0].basePipelineIndex == -1))
                skip |= ValidateObject(pCreateInfos[index0].basePipelineHandle, kVulkanObjectTypePipeline, false,
                                       "VUID-VkGraphicsPipelineCreateInfo-flags-07984",
                                       "VUID-VkGraphicsPipelineCreateInfo-commonparent", error_obj.location);
            if ([[maybe_unused]] auto pNext =
                    vku::FindStructInPNextChain<VkGraphicsPipelineShaderGroupsCreateInfoNV>(pCreateInfos[index0].pNext)) {
                [[maybe_unused]] const Location pNext_loc = index0_loc.pNext(Struct::VkGraphicsPipelineShaderGroupsCreateInfoNV);

                if ((pNext->pipelineCount > 0) && (pNext->pPipelines)) {
                    for (uint32_t index2 = 0; index2 < pNext->pipelineCount; ++index2) {
                        skip |= ValidateObject(pNext->pPipelines[index2], kVulkanObjectTypePipeline, false, kVUIDUndefined,
                                               kVUIDUndefined, pNext_loc.dot(Field::pPipelines, index2));
                    }
                }
            }
            if ([[maybe_unused]] auto pNext =
                    vku::FindStructInPNextChain<VkPipelineLibraryCreateInfoKHR>(pCreateInfos[index0].pNext)) {
                [[maybe_unused]] const Location pNext_loc = index0_loc.pNext(Struct::VkPipelineLibraryCreateInfoKHR);

                if ((pNext->libraryCount > 0) && (pNext->pLibraries)) {
                    for (uint32_t index2 = 0; index2 < pNext->libraryCount; ++index2) {
                        skip |= ValidateObject(pNext->pLibraries[index2], kVulkanObjectTypePipeline, false, kVUIDUndefined,
                                               kVUIDUndefined, pNext_loc.dot(Field::pLibraries, index2));
                    }
                }
            }
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                            uint32_t createInfoCount,
                                                            const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                            const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                            const RecordObject& record_obj) {
    if (VK_ERROR_VALIDATION_FAILED_EXT == record_obj.result) return;
    if (pPipelines) {
        for (uint32_t index = 0; index < createInfoCount; index++) {
            if (!pPipelines[index]) continue;
            CreateObject(pPipelines[index], kVulkanObjectTypePipeline, pAllocator,
                         record_obj.location.dot(Field::pPipelines, index));
        }
    }
}

bool ObjectLifetimes::PreCallValidateCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                            uint32_t createInfoCount,
                                                            const VkComputePipelineCreateInfo* pCreateInfos,
                                                            const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkCreateComputePipelines-device-parameter"
    skip |= ValidateObject(pipelineCache, kVulkanObjectTypePipelineCache, false,
                           "VUID-vkCreateComputePipelines-pipelineCache-parameter",
                           "VUID-vkCreateComputePipelines-pipelineCache-parent", error_obj.location.dot(Field::pipelineCache));
    if (pCreateInfos) {
        for (uint32_t index0 = 0; index0 < createInfoCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pCreateInfos, index0);
            [[maybe_unused]] const Location stage_loc = index0_loc.dot(Field::stage);
            skip |= ValidateObject(pCreateInfos[index0].stage.module, kVulkanObjectTypeShaderModule, true,
                                   "VUID-VkPipelineShaderStageCreateInfo-module-parameter", kVUIDUndefined,
                                   stage_loc.dot(Field::module));
            if ([[maybe_unused]] auto pNext =
                    vku::FindStructInPNextChain<VkShaderModuleValidationCacheCreateInfoEXT>(pCreateInfos[index0].stage.pNext)) {
                [[maybe_unused]] const Location pNext_loc = stage_loc.pNext(Struct::VkShaderModuleValidationCacheCreateInfoEXT);
                // There should be an explicit VU (if not that is a spec bug)
                skip |= ValidateObject(pNext->validationCache, kVulkanObjectTypeValidationCacheEXT, false, kVUIDUndefined,
                                       kVUIDUndefined, pNext_loc.dot(Field::validationCache));
            }
            skip |= ValidateObject(pCreateInfos[index0].layout, kVulkanObjectTypePipelineLayout, false,
                                   "VUID-VkComputePipelineCreateInfo-layout-parameter",
                                   "VUID-VkComputePipelineCreateInfo-commonparent", index0_loc.dot(Field::layout));
            if ((pCreateInfos[index0].flags & VK_PIPELINE_CREATE_DERIVATIVE_BIT) && (pCreateInfos[index0].basePipelineIndex == -1))
                skip |= ValidateObject(pCreateInfos[index0].basePipelineHandle, kVulkanObjectTypePipeline, false,
                                       "VUID-VkComputePipelineCreateInfo-flags-07984",
                                       "VUID-VkComputePipelineCreateInfo-commonparent", error_obj.location);
            if ([[maybe_unused]] auto pNext =
                    vku::FindStructInPNextChain<VkSubpassShadingPipelineCreateInfoHUAWEI>(pCreateInfos[index0].pNext)) {
                [[maybe_unused]] const Location pNext_loc = index0_loc.pNext(Struct::VkSubpassShadingPipelineCreateInfoHUAWEI);
                // There should be an explicit VU (if not that is a spec bug)
                skip |= ValidateObject(pNext->renderPass, kVulkanObjectTypeRenderPass, false, kVUIDUndefined, kVUIDUndefined,
                                       pNext_loc.dot(Field::renderPass));
            }
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                                           const VkComputePipelineCreateInfo* pCreateInfos,
                                                           const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                           const RecordObject& record_obj) {
    if (VK_ERROR_VALIDATION_FAILED_EXT == record_obj.result) return;
    if (pPipelines) {
        for (uint32_t index = 0; index < createInfoCount; index++) {
            if (!pPipelines[index]) continue;
            CreateObject(pPipelines[index], kVulkanObjectTypePipeline, pAllocator,
                         record_obj.location.dot(Field::pPipelines, index));
        }
    }
}

bool ObjectLifetimes::PreCallValidateDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator,
                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroyPipeline-device-parameter"
    skip |= ValidateObject(pipeline, kVulkanObjectTypePipeline, true, "VUID-vkDestroyPipeline-pipeline-parameter",
                           "VUID-vkDestroyPipeline-pipeline-parent", error_obj.location.dot(Field::pipeline));
    skip |=
        ValidateDestroyObject(pipeline, kVulkanObjectTypePipeline, pAllocator, kVUIDUndefined, kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator,
                                                   const RecordObject& record_obj) {
    RecordDestroyObject(pipeline, kVulkanObjectTypePipeline);
}

bool ObjectLifetimes::PreCallValidateCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator,
                                                          VkPipelineLayout* pPipelineLayout, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkCreatePipelineLayout-device-parameter"
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);

        if ((pCreateInfo->setLayoutCount > 0) && (pCreateInfo->pSetLayouts)) {
            for (uint32_t index1 = 0; index1 < pCreateInfo->setLayoutCount; ++index1) {
                skip |= ValidateObject(pCreateInfo->pSetLayouts[index1], kVulkanObjectTypeDescriptorSetLayout, true,
                                       "VUID-VkPipelineLayoutCreateInfo-pSetLayouts-parameter", kVUIDUndefined,
                                       pCreateInfo_loc.dot(Field::pSetLayouts, index1));
            }
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout,
                                                         const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pPipelineLayout, kVulkanObjectTypePipelineLayout, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroyPipelineLayout-device-parameter"
    skip |= ValidateObject(pipelineLayout, kVulkanObjectTypePipelineLayout, true,
                           "VUID-vkDestroyPipelineLayout-pipelineLayout-parameter",
                           "VUID-vkDestroyPipelineLayout-pipelineLayout-parent", error_obj.location.dot(Field::pipelineLayout));
    skip |= ValidateDestroyObject(pipelineLayout, kVulkanObjectTypePipelineLayout, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout,
                                                         const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(pipelineLayout, kVulkanObjectTypePipelineLayout);
}

bool ObjectLifetimes::PreCallValidateCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkSampler* pSampler,
                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkCreateSampler-device-parameter"
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkSamplerYcbcrConversionInfo>(pCreateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pCreateInfo_loc.pNext(Struct::VkSamplerYcbcrConversionInfo);
            skip |= ValidateObject(pNext->conversion, kVulkanObjectTypeSamplerYcbcrConversion, false,
                                   "VUID-VkSamplerYcbcrConversionInfo-conversion-parameter", kVUIDUndefined,
                                   pNext_loc.dot(Field::conversion));
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkSampler* pSampler,
                                                  const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSampler, kVulkanObjectTypeSampler, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator,
                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroySampler-device-parameter"
    skip |= ValidateObject(sampler, kVulkanObjectTypeSampler, true, "VUID-vkDestroySampler-sampler-parameter",
                           "VUID-vkDestroySampler-sampler-parent", error_obj.location.dot(Field::sampler));
    skip |=
        ValidateDestroyObject(sampler, kVulkanObjectTypeSampler, pAllocator, kVUIDUndefined, kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator,
                                                  const RecordObject& record_obj) {
    RecordDestroyObject(sampler, kVulkanObjectTypeSampler);
}

bool ObjectLifetimes::PreCallValidateDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout,
                                                                const VkAllocationCallbacks* pAllocator,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroyDescriptorSetLayout-device-parameter"
    skip |= ValidateObject(descriptorSetLayout, kVulkanObjectTypeDescriptorSetLayout, true,
                           "VUID-vkDestroyDescriptorSetLayout-descriptorSetLayout-parameter",
                           "VUID-vkDestroyDescriptorSetLayout-descriptorSetLayout-parent",
                           error_obj.location.dot(Field::descriptorSetLayout));
    skip |= ValidateDestroyObject(descriptorSetLayout, kVulkanObjectTypeDescriptorSetLayout, pAllocator, kVUIDUndefined,
                                  kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout,
                                                              const VkAllocationCallbacks* pAllocator,
                                                              const RecordObject& record_obj) {
    RecordDestroyObject(descriptorSetLayout, kVulkanObjectTypeDescriptorSetLayout);
}

// vkCreateDescriptorPool:
// Checked by chassis: device: "VUID-vkCreateDescriptorPool-device-parameter"

void ObjectLifetimes::PostCallRecordCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool,
                                                         const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pDescriptorPool, kVulkanObjectTypeDescriptorPool, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer,
                                                        const VkAllocationCallbacks* pAllocator,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroyFramebuffer-device-parameter"
    skip |= ValidateObject(framebuffer, kVulkanObjectTypeFramebuffer, true, "VUID-vkDestroyFramebuffer-framebuffer-parameter",
                           "VUID-vkDestroyFramebuffer-framebuffer-parent", error_obj.location.dot(Field::framebuffer));
    skip |= ValidateDestroyObject(framebuffer, kVulkanObjectTypeFramebuffer, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer,
                                                      const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(framebuffer, kVulkanObjectTypeFramebuffer);
}

// vkCreateRenderPass:
// Checked by chassis: device: "VUID-vkCreateRenderPass-device-parameter"

void ObjectLifetimes::PostCallRecordCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                                     const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pRenderPass, kVulkanObjectTypeRenderPass, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyRenderPass(VkDevice device, VkRenderPass renderPass,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroyRenderPass-device-parameter"
    skip |= ValidateObject(renderPass, kVulkanObjectTypeRenderPass, true, "VUID-vkDestroyRenderPass-renderPass-parameter",
                           "VUID-vkDestroyRenderPass-renderPass-parent", error_obj.location.dot(Field::renderPass));
    skip |= ValidateDestroyObject(renderPass, kVulkanObjectTypeRenderPass, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyRenderPass(VkDevice device, VkRenderPass renderPass,
                                                     const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(renderPass, kVulkanObjectTypeRenderPass);
}

bool ObjectLifetimes::PreCallValidateGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetRenderAreaGranularity-device-parameter"
    skip |= ValidateObject(renderPass, kVulkanObjectTypeRenderPass, false, "VUID-vkGetRenderAreaGranularity-renderPass-parameter",
                           "VUID-vkGetRenderAreaGranularity-renderPass-parent", error_obj.location.dot(Field::renderPass));

    return skip;
}

// vkCreateCommandPool:
// Checked by chassis: device: "VUID-vkCreateCommandPool-device-parameter"

void ObjectLifetimes::PostCallRecordCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool,
                                                      const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pCommandPool, kVulkanObjectTypeCommandPool, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkResetCommandPool-device-parameter"
    skip |= ValidateObject(commandPool, kVulkanObjectTypeCommandPool, false, "VUID-vkResetCommandPool-commandPool-parameter",
                           "VUID-vkResetCommandPool-commandPool-parent", error_obj.location.dot(Field::commandPool));

    return skip;
}

// vkEndCommandBuffer:
// Checked by chassis: commandBuffer: "VUID-vkEndCommandBuffer-commandBuffer-parameter"

// vkResetCommandBuffer:
// Checked by chassis: commandBuffer: "VUID-vkResetCommandBuffer-commandBuffer-parameter"

bool ObjectLifetimes::PreCallValidateCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                     VkPipeline pipeline, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdBindPipeline-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdBindPipeline-commonparent"
    skip |= ValidateObject(pipeline, kVulkanObjectTypePipeline, false, "VUID-vkCmdBindPipeline-pipeline-parameter",
                           "VUID-vkCmdBindPipeline-commonparent", error_obj.location.dot(Field::pipeline));

    return skip;
}

// vkCmdSetViewport:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetViewport-commandBuffer-parameter"

// vkCmdSetScissor:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetScissor-commandBuffer-parameter"

// vkCmdSetLineWidth:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetLineWidth-commandBuffer-parameter"

// vkCmdSetDepthBias:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDepthBias-commandBuffer-parameter"

// vkCmdSetBlendConstants:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetBlendConstants-commandBuffer-parameter"

// vkCmdSetDepthBounds:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDepthBounds-commandBuffer-parameter"

// vkCmdSetStencilCompareMask:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetStencilCompareMask-commandBuffer-parameter"

// vkCmdSetStencilWriteMask:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetStencilWriteMask-commandBuffer-parameter"

// vkCmdSetStencilReference:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetStencilReference-commandBuffer-parameter"

bool ObjectLifetimes::PreCallValidateCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                           VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                                           const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                                           const uint32_t* pDynamicOffsets, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdBindDescriptorSets-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdBindDescriptorSets-commonparent"
    skip |= ValidateObject(layout, kVulkanObjectTypePipelineLayout, false, "VUID-vkCmdBindDescriptorSets-layout-parameter",
                           "VUID-vkCmdBindDescriptorSets-commonparent", error_obj.location.dot(Field::layout));

    if ((descriptorSetCount > 0) && (pDescriptorSets)) {
        for (uint32_t index0 = 0; index0 < descriptorSetCount; ++index0) {
            skip |=
                ValidateObject(pDescriptorSets[index0], kVulkanObjectTypeDescriptorSet, true,
                               "VUID-vkCmdBindDescriptorSets-pDescriptorSets-parameter",
                               "VUID-vkCmdBindDescriptorSets-commonparent", error_obj.location.dot(Field::pDescriptorSets, index0));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                        VkIndexType indexType, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdBindIndexBuffer-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdBindIndexBuffer-commonparent"
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, true, "VUID-vkCmdBindIndexBuffer-buffer-parameter",
                           "VUID-vkCmdBindIndexBuffer-commonparent", error_obj.location.dot(Field::buffer));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                          uint32_t bindingCount, const VkBuffer* pBuffers,
                                                          const VkDeviceSize* pOffsets, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdBindVertexBuffers-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdBindVertexBuffers-commonparent"

    if ((bindingCount > 0) && (pBuffers)) {
        for (uint32_t index0 = 0; index0 < bindingCount; ++index0) {
            skip |=
                ValidateObject(pBuffers[index0], kVulkanObjectTypeBuffer, true, "VUID-vkCmdBindVertexBuffers-pBuffers-parameter",
                               "VUID-vkCmdBindVertexBuffers-commonparent", error_obj.location.dot(Field::pBuffers, index0));
        }
    }

    return skip;
}

// vkCmdDraw:
// Checked by chassis: commandBuffer: "VUID-vkCmdDraw-commandBuffer-parameter"

// vkCmdDrawIndexed:
// Checked by chassis: commandBuffer: "VUID-vkCmdDrawIndexed-commandBuffer-parameter"

bool ObjectLifetimes::PreCallValidateCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                     uint32_t drawCount, uint32_t stride, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdDrawIndirect-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdDrawIndirect-commonparent"
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndirect-buffer-parameter",
                           "VUID-vkCmdDrawIndirect-commonparent", error_obj.location.dot(Field::buffer));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                            uint32_t drawCount, uint32_t stride,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdDrawIndexedIndirect-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdDrawIndexedIndirect-commonparent"
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndexedIndirect-buffer-parameter",
                           "VUID-vkCmdDrawIndexedIndirect-commonparent", error_obj.location.dot(Field::buffer));

    return skip;
}

// vkCmdDispatch:
// Checked by chassis: commandBuffer: "VUID-vkCmdDispatch-commandBuffer-parameter"

bool ObjectLifetimes::PreCallValidateCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdDispatchIndirect-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdDispatchIndirect-commonparent"
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDispatchIndirect-buffer-parameter",
                           "VUID-vkCmdDispatchIndirect-commonparent", error_obj.location.dot(Field::buffer));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                                   uint32_t regionCount, const VkBufferCopy* pRegions,
                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyBuffer-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyBuffer-commonparent"
    skip |= ValidateObject(srcBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdCopyBuffer-srcBuffer-parameter",
                           "VUID-vkCmdCopyBuffer-commonparent", error_obj.location.dot(Field::srcBuffer));
    skip |= ValidateObject(dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdCopyBuffer-dstBuffer-parameter",
                           "VUID-vkCmdCopyBuffer-commonparent", error_obj.location.dot(Field::dstBuffer));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                                  VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                                  const VkImageCopy* pRegions, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyImage-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyImage-commonparent"
    skip |= ValidateObject(srcImage, kVulkanObjectTypeImage, false, "VUID-vkCmdCopyImage-srcImage-parameter",
                           "VUID-vkCmdCopyImage-commonparent", error_obj.location.dot(Field::srcImage));
    skip |= ValidateObject(dstImage, kVulkanObjectTypeImage, false, "VUID-vkCmdCopyImage-dstImage-parameter",
                           "VUID-vkCmdCopyImage-commonparent", error_obj.location.dot(Field::dstImage));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                                  VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                                  const VkImageBlit* pRegions, VkFilter filter,
                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdBlitImage-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdBlitImage-commonparent"
    skip |= ValidateObject(srcImage, kVulkanObjectTypeImage, false, "VUID-vkCmdBlitImage-srcImage-parameter",
                           "VUID-vkCmdBlitImage-commonparent", error_obj.location.dot(Field::srcImage));
    skip |= ValidateObject(dstImage, kVulkanObjectTypeImage, false, "VUID-vkCmdBlitImage-dstImage-parameter",
                           "VUID-vkCmdBlitImage-commonparent", error_obj.location.dot(Field::dstImage));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                                          VkImageLayout dstImageLayout, uint32_t regionCount,
                                                          const VkBufferImageCopy* pRegions, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyBufferToImage-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyBufferToImage-commonparent"
    skip |= ValidateObject(srcBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdCopyBufferToImage-srcBuffer-parameter",
                           "VUID-vkCmdCopyBufferToImage-commonparent", error_obj.location.dot(Field::srcBuffer));
    skip |= ValidateObject(dstImage, kVulkanObjectTypeImage, false, "VUID-vkCmdCopyBufferToImage-dstImage-parameter",
                           "VUID-vkCmdCopyBufferToImage-commonparent", error_obj.location.dot(Field::dstImage));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                          VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount,
                                                          const VkBufferImageCopy* pRegions, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyImageToBuffer-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyImageToBuffer-commonparent"
    skip |= ValidateObject(srcImage, kVulkanObjectTypeImage, false, "VUID-vkCmdCopyImageToBuffer-srcImage-parameter",
                           "VUID-vkCmdCopyImageToBuffer-commonparent", error_obj.location.dot(Field::srcImage));
    skip |= ValidateObject(dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdCopyImageToBuffer-dstBuffer-parameter",
                           "VUID-vkCmdCopyImageToBuffer-commonparent", error_obj.location.dot(Field::dstBuffer));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                     VkDeviceSize dataSize, const void* pData, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdUpdateBuffer-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdUpdateBuffer-commonparent"
    skip |= ValidateObject(dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdUpdateBuffer-dstBuffer-parameter",
                           "VUID-vkCmdUpdateBuffer-commonparent", error_obj.location.dot(Field::dstBuffer));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                   VkDeviceSize size, uint32_t data, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdFillBuffer-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdFillBuffer-commonparent"
    skip |= ValidateObject(dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdFillBuffer-dstBuffer-parameter",
                           "VUID-vkCmdFillBuffer-commonparent", error_obj.location.dot(Field::dstBuffer));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                                        const VkClearColorValue* pColor, uint32_t rangeCount,
                                                        const VkImageSubresourceRange* pRanges,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdClearColorImage-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdClearColorImage-commonparent"
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, "VUID-vkCmdClearColorImage-image-parameter",
                           "VUID-vkCmdClearColorImage-commonparent", error_obj.location.dot(Field::image));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image,
                                                               VkImageLayout imageLayout,
                                                               const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                                               const VkImageSubresourceRange* pRanges,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdClearDepthStencilImage-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdClearDepthStencilImage-commonparent"
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, "VUID-vkCmdClearDepthStencilImage-image-parameter",
                           "VUID-vkCmdClearDepthStencilImage-commonparent", error_obj.location.dot(Field::image));

    return skip;
}

// vkCmdClearAttachments:
// Checked by chassis: commandBuffer: "VUID-vkCmdClearAttachments-commandBuffer-parameter"

bool ObjectLifetimes::PreCallValidateCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                                     VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                                     const VkImageResolve* pRegions, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdResolveImage-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdResolveImage-commonparent"
    skip |= ValidateObject(srcImage, kVulkanObjectTypeImage, false, "VUID-vkCmdResolveImage-srcImage-parameter",
                           "VUID-vkCmdResolveImage-commonparent", error_obj.location.dot(Field::srcImage));
    skip |= ValidateObject(dstImage, kVulkanObjectTypeImage, false, "VUID-vkCmdResolveImage-dstImage-parameter",
                           "VUID-vkCmdResolveImage-commonparent", error_obj.location.dot(Field::dstImage));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask,
                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdSetEvent-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdSetEvent-commonparent"
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkCmdSetEvent-event-parameter",
                           "VUID-vkCmdSetEvent-commonparent", error_obj.location.dot(Field::event));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask,
                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdResetEvent-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdResetEvent-commonparent"
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkCmdResetEvent-event-parameter",
                           "VUID-vkCmdResetEvent-commonparent", error_obj.location.dot(Field::event));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWaitEvents(
    VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask,
    VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
    uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount,
    const VkImageMemoryBarrier* pImageMemoryBarriers, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdWaitEvents-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdWaitEvents-commonparent"

    if ((eventCount > 0) && (pEvents)) {
        for (uint32_t index0 = 0; index0 < eventCount; ++index0) {
            skip |= ValidateObject(pEvents[index0], kVulkanObjectTypeEvent, false, "VUID-vkCmdWaitEvents-pEvents-parameter",
                                   "VUID-vkCmdWaitEvents-commonparent", error_obj.location.dot(Field::pEvents, index0));
        }
    }
    if (pBufferMemoryBarriers) {
        for (uint32_t index0 = 0; index0 < bufferMemoryBarrierCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pBufferMemoryBarriers, index0);
            skip |= ValidateObject(pBufferMemoryBarriers[index0].buffer, kVulkanObjectTypeBuffer, false,
                                   "VUID-VkBufferMemoryBarrier-buffer-parameter", kVUIDUndefined, index0_loc.dot(Field::buffer));
        }
    }
    if (pImageMemoryBarriers) {
        for (uint32_t index0 = 0; index0 < imageMemoryBarrierCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pImageMemoryBarriers, index0);
            skip |= ValidateObject(pImageMemoryBarriers[index0].image, kVulkanObjectTypeImage, false,
                                   "VUID-VkImageMemoryBarrier-image-parameter", kVUIDUndefined, index0_loc.dot(Field::image));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdPipelineBarrier(
    VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
    VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
    uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount,
    const VkImageMemoryBarrier* pImageMemoryBarriers, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdPipelineBarrier-commandBuffer-parameter"
    if (pBufferMemoryBarriers) {
        for (uint32_t index0 = 0; index0 < bufferMemoryBarrierCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pBufferMemoryBarriers, index0);
            skip |= ValidateObject(pBufferMemoryBarriers[index0].buffer, kVulkanObjectTypeBuffer, false,
                                   "VUID-VkBufferMemoryBarrier-buffer-parameter", kVUIDUndefined, index0_loc.dot(Field::buffer));
        }
    }
    if (pImageMemoryBarriers) {
        for (uint32_t index0 = 0; index0 < imageMemoryBarrierCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pImageMemoryBarriers, index0);
            skip |= ValidateObject(pImageMemoryBarriers[index0].image, kVulkanObjectTypeImage, false,
                                   "VUID-VkImageMemoryBarrier-image-parameter", kVUIDUndefined, index0_loc.dot(Field::image));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                                   VkQueryControlFlags flags, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdBeginQuery-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdBeginQuery-commonparent"
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdBeginQuery-queryPool-parameter",
                           "VUID-vkCmdBeginQuery-commonparent", error_obj.location.dot(Field::queryPool));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdEndQuery-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdEndQuery-commonparent"
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdEndQuery-queryPool-parameter",
                           "VUID-vkCmdEndQuery-commonparent", error_obj.location.dot(Field::queryPool));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                                       uint32_t queryCount, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdResetQueryPool-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdResetQueryPool-commonparent"
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdResetQueryPool-queryPool-parameter",
                           "VUID-vkCmdResetQueryPool-commonparent", error_obj.location.dot(Field::queryPool));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                                       VkQueryPool queryPool, uint32_t query, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdWriteTimestamp-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdWriteTimestamp-commonparent"
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdWriteTimestamp-queryPool-parameter",
                           "VUID-vkCmdWriteTimestamp-commonparent", error_obj.location.dot(Field::queryPool));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                             uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer,
                                                             VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags,
                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyQueryPoolResults-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyQueryPoolResults-commonparent"
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdCopyQueryPoolResults-queryPool-parameter",
                           "VUID-vkCmdCopyQueryPoolResults-commonparent", error_obj.location.dot(Field::queryPool));
    skip |= ValidateObject(dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdCopyQueryPoolResults-dstBuffer-parameter",
                           "VUID-vkCmdCopyQueryPoolResults-commonparent", error_obj.location.dot(Field::dstBuffer));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                                      VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                                      const void* pValues, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdPushConstants-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdPushConstants-commonparent"
    skip |= ValidateObject(layout, kVulkanObjectTypePipelineLayout, false, "VUID-vkCmdPushConstants-layout-parameter",
                           "VUID-vkCmdPushConstants-commonparent", error_obj.location.dot(Field::layout));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBeginRenderPass(VkCommandBuffer commandBuffer,
                                                        const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdBeginRenderPass-commandBuffer-parameter"
    if (pRenderPassBegin) {
        [[maybe_unused]] const Location pRenderPassBegin_loc = error_obj.location.dot(Field::pRenderPassBegin);
        skip |= ValidateObject(pRenderPassBegin->renderPass, kVulkanObjectTypeRenderPass, false,
                               "VUID-VkRenderPassBeginInfo-renderPass-parameter", "VUID-VkRenderPassBeginInfo-commonparent",
                               pRenderPassBegin_loc.dot(Field::renderPass));
        skip |= ValidateObject(pRenderPassBegin->framebuffer, kVulkanObjectTypeFramebuffer, false,
                               "VUID-VkRenderPassBeginInfo-framebuffer-parameter", "VUID-VkRenderPassBeginInfo-commonparent",
                               pRenderPassBegin_loc.dot(Field::framebuffer));
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkRenderPassAttachmentBeginInfo>(pRenderPassBegin->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pRenderPassBegin_loc.pNext(Struct::VkRenderPassAttachmentBeginInfo);

            if ((pNext->attachmentCount > 0) && (pNext->pAttachments)) {
                for (uint32_t index2 = 0; index2 < pNext->attachmentCount; ++index2) {
                    skip |=
                        ValidateObject(pNext->pAttachments[index2], kVulkanObjectTypeImageView, false,
                                       "VUID-VkRenderPassAttachmentBeginInfo-pAttachments-parameter",
                                       "VUID-VkRenderPassBeginInfo-framebuffer-02780", pNext_loc.dot(Field::pAttachments, index2));
                }
            }
        }
    }

    return skip;
}

// vkCmdNextSubpass:
// Checked by chassis: commandBuffer: "VUID-vkCmdNextSubpass-commandBuffer-parameter"

// vkCmdEndRenderPass:
// Checked by chassis: commandBuffer: "VUID-vkCmdEndRenderPass-commandBuffer-parameter"

bool ObjectLifetimes::PreCallValidateCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                                        const VkCommandBuffer* pCommandBuffers,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdExecuteCommands-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdExecuteCommands-commonparent"

    if ((commandBufferCount > 0) && (pCommandBuffers)) {
        for (uint32_t index0 = 0; index0 < commandBufferCount; ++index0) {
            skip |= ValidateObject(pCommandBuffers[index0], kVulkanObjectTypeCommandBuffer, false,
                                   "VUID-vkCmdExecuteCommands-pCommandBuffers-parameter", "VUID-vkCmdExecuteCommands-commonparent",
                                   error_obj.location.dot(Field::pCommandBuffers, index0));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateBindBufferMemory2(VkDevice device, uint32_t bindInfoCount,
                                                       const VkBindBufferMemoryInfo* pBindInfos,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkBindBufferMemory2-device-parameter"
    if (pBindInfos) {
        for (uint32_t index0 = 0; index0 < bindInfoCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pBindInfos, index0);
            skip |= ValidateObject(pBindInfos[index0].buffer, kVulkanObjectTypeBuffer, false,
                                   "VUID-VkBindBufferMemoryInfo-buffer-parameter", "VUID-VkBindBufferMemoryInfo-commonparent",
                                   index0_loc.dot(Field::buffer));
            skip |= ValidateObject(pBindInfos[index0].memory, kVulkanObjectTypeDeviceMemory, false,
                                   "VUID-VkBindBufferMemoryInfo-memory-parameter", "VUID-VkBindBufferMemoryInfo-commonparent",
                                   index0_loc.dot(Field::memory));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateBindImageMemory2(VkDevice device, uint32_t bindInfoCount,
                                                      const VkBindImageMemoryInfo* pBindInfos, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkBindImageMemory2-device-parameter"
    if (pBindInfos) {
        for (uint32_t index0 = 0; index0 < bindInfoCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pBindInfos, index0);
            skip |= ValidateObject(pBindInfos[index0].image, kVulkanObjectTypeImage, false,
                                   "VUID-VkBindImageMemoryInfo-image-parameter", "VUID-VkBindImageMemoryInfo-commonparent",
                                   index0_loc.dot(Field::image));
            if ([[maybe_unused]] auto pNext =
                    vku::FindStructInPNextChain<VkBindImageMemorySwapchainInfoKHR>(pBindInfos[index0].pNext)) {
                [[maybe_unused]] const Location pNext_loc = index0_loc.pNext(Struct::VkBindImageMemorySwapchainInfoKHR);
                skip |= ValidateObject(pNext->swapchain, kVulkanObjectTypeSwapchainKHR, false,
                                       "VUID-VkBindImageMemorySwapchainInfoKHR-swapchain-parameter", kVUIDUndefined,
                                       pNext_loc.dot(Field::swapchain));
            }
        }
    }

    return skip;
}

// vkGetDeviceGroupPeerMemoryFeatures:
// Checked by chassis: device: "VUID-vkGetDeviceGroupPeerMemoryFeatures-device-parameter"

// vkCmdSetDeviceMask:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDeviceMask-commandBuffer-parameter"

// vkCmdDispatchBase:
// Checked by chassis: commandBuffer: "VUID-vkCmdDispatchBase-commandBuffer-parameter"

// vkEnumeratePhysicalDeviceGroups:
// Checked by chassis: instance: "VUID-vkEnumeratePhysicalDeviceGroups-instance-parameter"

void ObjectLifetimes::PostCallRecordEnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount,
                                                                  VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties,
                                                                  const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS && record_obj.result != VK_INCOMPLETE) return;

    if (pPhysicalDeviceGroupProperties) {
        const RecordObject record_obj(vvl::Func::vkEnumeratePhysicalDevices, VK_SUCCESS);
        for (uint32_t device_group_index = 0; device_group_index < *pPhysicalDeviceGroupCount; device_group_index++) {
            PostCallRecordEnumeratePhysicalDevices(instance,
                                                   &pPhysicalDeviceGroupProperties[device_group_index].physicalDeviceCount,
                                                   pPhysicalDeviceGroupProperties[device_group_index].physicalDevices, record_obj);
        }
    }
}

bool ObjectLifetimes::PreCallValidateGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo,
                                                                 VkMemoryRequirements2* pMemoryRequirements,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetImageMemoryRequirements2-device-parameter"
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        skip |= ValidateObject(pInfo->image, kVulkanObjectTypeImage, false, "VUID-VkImageMemoryRequirementsInfo2-image-parameter",
                               kVUIDUndefined, pInfo_loc.dot(Field::image));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo,
                                                                  VkMemoryRequirements2* pMemoryRequirements,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetBufferMemoryRequirements2-device-parameter"
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        skip |=
            ValidateObject(pInfo->buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferMemoryRequirementsInfo2-buffer-parameter",
                           kVUIDUndefined, pInfo_loc.dot(Field::buffer));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageSparseMemoryRequirements2(VkDevice device,
                                                                       const VkImageSparseMemoryRequirementsInfo2* pInfo,
                                                                       uint32_t* pSparseMemoryRequirementCount,
                                                                       VkSparseImageMemoryRequirements2* pSparseMemoryRequirements,
                                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->image, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::image));
    }

    return skip;
}

// vkGetPhysicalDeviceFeatures2:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceFeatures2-physicalDevice-parameter"

// vkGetPhysicalDeviceProperties2:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceProperties2-physicalDevice-parameter"

// vkGetPhysicalDeviceFormatProperties2:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceFormatProperties2-physicalDevice-parameter"

// vkGetPhysicalDeviceImageFormatProperties2:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceImageFormatProperties2-physicalDevice-parameter"

// vkGetPhysicalDeviceMemoryProperties2:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceMemoryProperties2-physicalDevice-parameter"

// vkGetPhysicalDeviceSparseImageFormatProperties2:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkTrimCommandPool:
// Checked by chassis: device: kVUIDUndefined

// vkCreateSamplerYcbcrConversion:
// Checked by chassis: device: "VUID-vkCreateSamplerYcbcrConversion-device-parameter"

void ObjectLifetimes::PostCallRecordCreateSamplerYcbcrConversion(VkDevice device,
                                                                 const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                                 const VkAllocationCallbacks* pAllocator,
                                                                 VkSamplerYcbcrConversion* pYcbcrConversion,
                                                                 const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pYcbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDestroySamplerYcbcrConversion-device-parameter"
    skip |= ValidateObject(ycbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion, true,
                           "VUID-vkDestroySamplerYcbcrConversion-ycbcrConversion-parameter",
                           "VUID-vkDestroySamplerYcbcrConversion-ycbcrConversion-parent",
                           error_obj.location.dot(Field::ycbcrConversion));
    skip |= ValidateDestroyObject(ycbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion, pAllocator, kVUIDUndefined,
                                  kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion,
                                                                 const VkAllocationCallbacks* pAllocator,
                                                                 const RecordObject& record_obj) {
    RecordDestroyObject(ycbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion);
}

bool ObjectLifetimes::PreCallValidateDestroyDescriptorUpdateTemplate(VkDevice device,
                                                                     VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                     const VkAllocationCallbacks* pAllocator,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(descriptorUpdateTemplate, kVulkanObjectTypeDescriptorUpdateTemplate, pAllocator, kVUIDUndefined,
                                  kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyDescriptorUpdateTemplate(VkDevice device,
                                                                   VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   const RecordObject& record_obj) {
    RecordDestroyObject(descriptorUpdateTemplate, kVulkanObjectTypeDescriptorUpdateTemplate);
}

// vkUpdateDescriptorSetWithTemplate:
// Checked by chassis: device: kVUIDUndefined

// vkGetPhysicalDeviceExternalBufferProperties:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceExternalBufferProperties-physicalDevice-parameter"

// vkGetPhysicalDeviceExternalFenceProperties:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceExternalFenceProperties-physicalDevice-parameter"

// vkGetPhysicalDeviceExternalSemaphoreProperties:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceExternalSemaphoreProperties-physicalDevice-parameter"

bool ObjectLifetimes::PreCallValidateCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                          VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                          uint32_t maxDrawCount, uint32_t stride,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdDrawIndirectCount-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdDrawIndirectCount-commonparent"
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndirectCount-buffer-parameter",
                           "VUID-vkCmdDrawIndirectCount-commonparent", error_obj.location.dot(Field::buffer));
    skip |= ValidateObject(countBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndirectCount-countBuffer-parameter",
                           "VUID-vkCmdDrawIndirectCount-commonparent", error_obj.location.dot(Field::countBuffer));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                 VkDeviceSize offset, VkBuffer countBuffer,
                                                                 VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                                 uint32_t stride, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdDrawIndexedIndirectCount-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdDrawIndexedIndirectCount-commonparent"
    skip |= ValidateObject(buffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndexedIndirectCount-buffer-parameter",
                           "VUID-vkCmdDrawIndexedIndirectCount-commonparent", error_obj.location.dot(Field::buffer));
    skip |= ValidateObject(countBuffer, kVulkanObjectTypeBuffer, false, "VUID-vkCmdDrawIndexedIndirectCount-countBuffer-parameter",
                           "VUID-vkCmdDrawIndexedIndirectCount-commonparent", error_obj.location.dot(Field::countBuffer));

    return skip;
}

// vkCreateRenderPass2:
// Checked by chassis: device: "VUID-vkCreateRenderPass2-device-parameter"

void ObjectLifetimes::PostCallRecordCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                                      const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pRenderPass, kVulkanObjectTypeRenderPass, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateCmdBeginRenderPass2(VkCommandBuffer commandBuffer,
                                                         const VkRenderPassBeginInfo* pRenderPassBegin,
                                                         const VkSubpassBeginInfo* pSubpassBeginInfo,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdBeginRenderPass2-commandBuffer-parameter"
    if (pRenderPassBegin) {
        [[maybe_unused]] const Location pRenderPassBegin_loc = error_obj.location.dot(Field::pRenderPassBegin);
        skip |= ValidateObject(pRenderPassBegin->renderPass, kVulkanObjectTypeRenderPass, false,
                               "VUID-VkRenderPassBeginInfo-renderPass-parameter", "VUID-VkRenderPassBeginInfo-commonparent",
                               pRenderPassBegin_loc.dot(Field::renderPass));
        skip |= ValidateObject(pRenderPassBegin->framebuffer, kVulkanObjectTypeFramebuffer, false,
                               "VUID-VkRenderPassBeginInfo-framebuffer-parameter", "VUID-VkRenderPassBeginInfo-commonparent",
                               pRenderPassBegin_loc.dot(Field::framebuffer));
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkRenderPassAttachmentBeginInfo>(pRenderPassBegin->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pRenderPassBegin_loc.pNext(Struct::VkRenderPassAttachmentBeginInfo);

            if ((pNext->attachmentCount > 0) && (pNext->pAttachments)) {
                for (uint32_t index2 = 0; index2 < pNext->attachmentCount; ++index2) {
                    skip |=
                        ValidateObject(pNext->pAttachments[index2], kVulkanObjectTypeImageView, false,
                                       "VUID-VkRenderPassAttachmentBeginInfo-pAttachments-parameter",
                                       "VUID-VkRenderPassBeginInfo-framebuffer-02780", pNext_loc.dot(Field::pAttachments, index2));
                }
            }
        }
    }

    return skip;
}

// vkCmdNextSubpass2:
// Checked by chassis: commandBuffer: "VUID-vkCmdNextSubpass2-commandBuffer-parameter"

// vkCmdEndRenderPass2:
// Checked by chassis: commandBuffer: "VUID-vkCmdEndRenderPass2-commandBuffer-parameter"

bool ObjectLifetimes::PreCallValidateResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                                    uint32_t queryCount, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkResetQueryPool-device-parameter"
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkResetQueryPool-queryPool-parameter",
                           "VUID-vkResetQueryPool-queryPool-parent", error_obj.location.dot(Field::queryPool));

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetSemaphoreCounterValue-device-parameter"
    skip |= ValidateObject(semaphore, kVulkanObjectTypeSemaphore, false, "VUID-vkGetSemaphoreCounterValue-semaphore-parameter",
                           "VUID-vkGetSemaphoreCounterValue-semaphore-parent", error_obj.location.dot(Field::semaphore));

    return skip;
}

bool ObjectLifetimes::PreCallValidateWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout,
                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkWaitSemaphores-device-parameter"
    if (pWaitInfo) {
        [[maybe_unused]] const Location pWaitInfo_loc = error_obj.location.dot(Field::pWaitInfo);

        if ((pWaitInfo->semaphoreCount > 0) && (pWaitInfo->pSemaphores)) {
            for (uint32_t index1 = 0; index1 < pWaitInfo->semaphoreCount; ++index1) {
                skip |= ValidateObject(pWaitInfo->pSemaphores[index1], kVulkanObjectTypeSemaphore, false,
                                       "VUID-VkSemaphoreWaitInfo-pSemaphores-parameter", kVUIDUndefined,
                                       pWaitInfo_loc.dot(Field::pSemaphores, index1));
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo,
                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkSignalSemaphore-device-parameter"
    if (pSignalInfo) {
        [[maybe_unused]] const Location pSignalInfo_loc = error_obj.location.dot(Field::pSignalInfo);
        skip |=
            ValidateObject(pSignalInfo->semaphore, kVulkanObjectTypeSemaphore, false,
                           "VUID-VkSemaphoreSignalInfo-semaphore-parameter", kVUIDUndefined, pSignalInfo_loc.dot(Field::semaphore));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetBufferDeviceAddress-device-parameter"
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        skip |= ValidateObject(pInfo->buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferDeviceAddressInfo-buffer-parameter",
                               kVUIDUndefined, pInfo_loc.dot(Field::buffer));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetBufferOpaqueCaptureAddress-device-parameter"
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        skip |= ValidateObject(pInfo->buffer, kVulkanObjectTypeBuffer, false, "VUID-VkBufferDeviceAddressInfo-buffer-parameter",
                               kVUIDUndefined, pInfo_loc.dot(Field::buffer));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceMemoryOpaqueCaptureAddress(VkDevice device,
                                                                         const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo,
                                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetDeviceMemoryOpaqueCaptureAddress-device-parameter"
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        skip |= ValidateObject(pInfo->memory, kVulkanObjectTypeDeviceMemory, false,
                               "VUID-VkDeviceMemoryOpaqueCaptureAddressInfo-memory-parameter", kVUIDUndefined,
                               pInfo_loc.dot(Field::memory));
    }

    return skip;
}

// vkGetPhysicalDeviceToolProperties:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkCreatePrivateDataSlot:
// Checked by chassis: device: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator,
                                                          VkPrivateDataSlot* pPrivateDataSlot, const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pPrivateDataSlot, kVulkanObjectTypePrivateDataSlot, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                          const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot);
}

bool ObjectLifetimes::PreCallValidateCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                                  const VkDependencyInfo* pDependencyInfo, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdSetEvent2-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdSetEvent2-commonparent"
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkCmdSetEvent2-event-parameter",
                           "VUID-vkCmdSetEvent2-commonparent", error_obj.location.dot(Field::event));
    if (pDependencyInfo) {
        [[maybe_unused]] const Location pDependencyInfo_loc = error_obj.location.dot(Field::pDependencyInfo);
        if (pDependencyInfo->pBufferMemoryBarriers) {
            for (uint32_t index1 = 0; index1 < pDependencyInfo->bufferMemoryBarrierCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pDependencyInfo_loc.dot(Field::pBufferMemoryBarriers, index1);
                skip |=
                    ValidateObject(pDependencyInfo->pBufferMemoryBarriers[index1].buffer, kVulkanObjectTypeBuffer, false,
                                   "VUID-VkBufferMemoryBarrier2-buffer-parameter", kVUIDUndefined, index1_loc.dot(Field::buffer));
            }
        }
        if (pDependencyInfo->pImageMemoryBarriers) {
            for (uint32_t index1 = 0; index1 < pDependencyInfo->imageMemoryBarrierCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pDependencyInfo_loc.dot(Field::pImageMemoryBarriers, index1);
                skip |= ValidateObject(pDependencyInfo->pImageMemoryBarriers[index1].image, kVulkanObjectTypeImage, false,
                                       "VUID-VkImageMemoryBarrier2-image-parameter", kVUIDUndefined, index1_loc.dot(Field::image));
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask,
                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdResetEvent2-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdResetEvent2-commonparent"
    skip |= ValidateObject(event, kVulkanObjectTypeEvent, false, "VUID-vkCmdResetEvent2-event-parameter",
                           "VUID-vkCmdResetEvent2-commonparent", error_obj.location.dot(Field::event));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                                    const VkDependencyInfo* pDependencyInfos, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdWaitEvents2-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdWaitEvents2-commonparent"

    if ((eventCount > 0) && (pEvents)) {
        for (uint32_t index0 = 0; index0 < eventCount; ++index0) {
            skip |= ValidateObject(pEvents[index0], kVulkanObjectTypeEvent, false, "VUID-vkCmdWaitEvents2-pEvents-parameter",
                                   "VUID-vkCmdWaitEvents2-commonparent", error_obj.location.dot(Field::pEvents, index0));
        }
    }
    if (pDependencyInfos) {
        for (uint32_t index0 = 0; index0 < eventCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pDependencyInfos, index0);
            if (pDependencyInfos[index0].pBufferMemoryBarriers) {
                for (uint32_t index1 = 0; index1 < pDependencyInfos[index0].bufferMemoryBarrierCount; ++index1) {
                    [[maybe_unused]] const Location index1_loc = index0_loc.dot(Field::pBufferMemoryBarriers, index1);
                    skip |= ValidateObject(pDependencyInfos[index0].pBufferMemoryBarriers[index1].buffer, kVulkanObjectTypeBuffer,
                                           false, "VUID-VkBufferMemoryBarrier2-buffer-parameter", kVUIDUndefined,
                                           index1_loc.dot(Field::buffer));
                }
            }
            if (pDependencyInfos[index0].pImageMemoryBarriers) {
                for (uint32_t index1 = 0; index1 < pDependencyInfos[index0].imageMemoryBarrierCount; ++index1) {
                    [[maybe_unused]] const Location index1_loc = index0_loc.dot(Field::pImageMemoryBarriers, index1);
                    skip |=
                        ValidateObject(pDependencyInfos[index0].pImageMemoryBarriers[index1].image, kVulkanObjectTypeImage, false,
                                       "VUID-VkImageMemoryBarrier2-image-parameter", kVUIDUndefined, index1_loc.dot(Field::image));
                }
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdPipelineBarrier2-commandBuffer-parameter"
    if (pDependencyInfo) {
        [[maybe_unused]] const Location pDependencyInfo_loc = error_obj.location.dot(Field::pDependencyInfo);
        if (pDependencyInfo->pBufferMemoryBarriers) {
            for (uint32_t index1 = 0; index1 < pDependencyInfo->bufferMemoryBarrierCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pDependencyInfo_loc.dot(Field::pBufferMemoryBarriers, index1);
                skip |=
                    ValidateObject(pDependencyInfo->pBufferMemoryBarriers[index1].buffer, kVulkanObjectTypeBuffer, false,
                                   "VUID-VkBufferMemoryBarrier2-buffer-parameter", kVUIDUndefined, index1_loc.dot(Field::buffer));
            }
        }
        if (pDependencyInfo->pImageMemoryBarriers) {
            for (uint32_t index1 = 0; index1 < pDependencyInfo->imageMemoryBarrierCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pDependencyInfo_loc.dot(Field::pImageMemoryBarriers, index1);
                skip |= ValidateObject(pDependencyInfo->pImageMemoryBarriers[index1].image, kVulkanObjectTypeImage, false,
                                       "VUID-VkImageMemoryBarrier2-image-parameter", kVUIDUndefined, index1_loc.dot(Field::image));
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                        VkQueryPool queryPool, uint32_t query, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdWriteTimestamp2-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdWriteTimestamp2-commonparent"
    skip |= ValidateObject(queryPool, kVulkanObjectTypeQueryPool, false, "VUID-vkCmdWriteTimestamp2-queryPool-parameter",
                           "VUID-vkCmdWriteTimestamp2-commonparent", error_obj.location.dot(Field::queryPool));

    return skip;
}

bool ObjectLifetimes::PreCallValidateQueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence,
                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: queue: "VUID-vkQueueSubmit2-queue-parameter"
    // Checked by chassis: queue: "VUID-vkQueueSubmit2-commonparent"
    if (pSubmits) {
        for (uint32_t index0 = 0; index0 < submitCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pSubmits, index0);
            if (pSubmits[index0].pWaitSemaphoreInfos) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].waitSemaphoreInfoCount; ++index1) {
                    [[maybe_unused]] const Location index1_loc = index0_loc.dot(Field::pWaitSemaphoreInfos, index1);
                    skip |= ValidateObject(pSubmits[index0].pWaitSemaphoreInfos[index1].semaphore, kVulkanObjectTypeSemaphore,
                                           false, "VUID-VkSemaphoreSubmitInfo-semaphore-parameter", kVUIDUndefined,
                                           index1_loc.dot(Field::semaphore));
                }
            }
            if (pSubmits[index0].pCommandBufferInfos) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].commandBufferInfoCount; ++index1) {
                    [[maybe_unused]] const Location index1_loc = index0_loc.dot(Field::pCommandBufferInfos, index1);
                    skip |=
                        ValidateObject(pSubmits[index0].pCommandBufferInfos[index1].commandBuffer, kVulkanObjectTypeCommandBuffer,
                                       false, "VUID-VkCommandBufferSubmitInfo-commandBuffer-parameter", kVUIDUndefined,
                                       index1_loc.dot(Field::commandBuffer));
                }
            }
            if (pSubmits[index0].pSignalSemaphoreInfos) {
                for (uint32_t index1 = 0; index1 < pSubmits[index0].signalSemaphoreInfoCount; ++index1) {
                    [[maybe_unused]] const Location index1_loc = index0_loc.dot(Field::pSignalSemaphoreInfos, index1);
                    skip |= ValidateObject(pSubmits[index0].pSignalSemaphoreInfos[index1].semaphore, kVulkanObjectTypeSemaphore,
                                           false, "VUID-VkSemaphoreSubmitInfo-semaphore-parameter", kVUIDUndefined,
                                           index1_loc.dot(Field::semaphore));
                }
            }
            if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkFrameBoundaryEXT>(pSubmits[index0].pNext)) {
                [[maybe_unused]] const Location pNext_loc = index0_loc.pNext(Struct::VkFrameBoundaryEXT);

                if ((pNext->imageCount > 0) && (pNext->pImages)) {
                    for (uint32_t index2 = 0; index2 < pNext->imageCount; ++index2) {
                        skip |= ValidateObject(pNext->pImages[index2], kVulkanObjectTypeImage, false, kVUIDUndefined,
                                               "UNASSIGNED-VkFrameBoundaryEXT-commonparent", pNext_loc.dot(Field::pImages, index2));
                    }
                }

                if ((pNext->bufferCount > 0) && (pNext->pBuffers)) {
                    for (uint32_t index2 = 0; index2 < pNext->bufferCount; ++index2) {
                        skip |=
                            ValidateObject(pNext->pBuffers[index2], kVulkanObjectTypeBuffer, false, kVUIDUndefined,
                                           "UNASSIGNED-VkFrameBoundaryEXT-commonparent", pNext_loc.dot(Field::pBuffers, index2));
                    }
                }
            }
#ifdef VK_USE_PLATFORM_WIN32_KHR
            if ([[maybe_unused]] auto pNext =
                    vku::FindStructInPNextChain<VkWin32KeyedMutexAcquireReleaseInfoKHR>(pSubmits[index0].pNext)) {
                [[maybe_unused]] const Location pNext_loc = index0_loc.pNext(Struct::VkWin32KeyedMutexAcquireReleaseInfoKHR);

                if ((pNext->acquireCount > 0) && (pNext->pAcquireSyncs)) {
                    for (uint32_t index2 = 0; index2 < pNext->acquireCount; ++index2) {
                        skip |= ValidateObject(pNext->pAcquireSyncs[index2], kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined,
                                               "UNASSIGNED-VkWin32KeyedMutexAcquireReleaseInfoKHR-commonparent",
                                               pNext_loc.dot(Field::pAcquireSyncs, index2));
                    }
                }

                if ((pNext->releaseCount > 0) && (pNext->pReleaseSyncs)) {
                    for (uint32_t index2 = 0; index2 < pNext->releaseCount; ++index2) {
                        skip |= ValidateObject(pNext->pReleaseSyncs[index2], kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined,
                                               "UNASSIGNED-VkWin32KeyedMutexAcquireReleaseInfoKHR-commonparent",
                                               pNext_loc.dot(Field::pReleaseSyncs, index2));
                    }
                }
            }
            if ([[maybe_unused]] auto pNext =
                    vku::FindStructInPNextChain<VkWin32KeyedMutexAcquireReleaseInfoNV>(pSubmits[index0].pNext)) {
                [[maybe_unused]] const Location pNext_loc = index0_loc.pNext(Struct::VkWin32KeyedMutexAcquireReleaseInfoNV);

                if ((pNext->acquireCount > 0) && (pNext->pAcquireSyncs)) {
                    for (uint32_t index2 = 0; index2 < pNext->acquireCount; ++index2) {
                        skip |= ValidateObject(pNext->pAcquireSyncs[index2], kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined,
                                               "UNASSIGNED-VkWin32KeyedMutexAcquireReleaseInfoNV-commonparent",
                                               pNext_loc.dot(Field::pAcquireSyncs, index2));
                    }
                }

                if ((pNext->releaseCount > 0) && (pNext->pReleaseSyncs)) {
                    for (uint32_t index2 = 0; index2 < pNext->releaseCount; ++index2) {
                        skip |= ValidateObject(pNext->pReleaseSyncs[index2], kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined,
                                               "UNASSIGNED-VkWin32KeyedMutexAcquireReleaseInfoNV-commonparent",
                                               pNext_loc.dot(Field::pReleaseSyncs, index2));
                    }
                }
            }
#endif  // VK_USE_PLATFORM_WIN32_KHR
        }
    }
    skip |= ValidateObject(fence, kVulkanObjectTypeFence, true, "VUID-vkQueueSubmit2-fence-parameter",
                           "VUID-vkQueueSubmit2-commonparent", error_obj.location.dot(Field::fence));

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo,
                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyBuffer2-commandBuffer-parameter"
    if (pCopyBufferInfo) {
        [[maybe_unused]] const Location pCopyBufferInfo_loc = error_obj.location.dot(Field::pCopyBufferInfo);
        skip |=
            ValidateObject(pCopyBufferInfo->srcBuffer, kVulkanObjectTypeBuffer, false, "VUID-VkCopyBufferInfo2-srcBuffer-parameter",
                           "VUID-VkCopyBufferInfo2-commonparent", pCopyBufferInfo_loc.dot(Field::srcBuffer));
        skip |=
            ValidateObject(pCopyBufferInfo->dstBuffer, kVulkanObjectTypeBuffer, false, "VUID-VkCopyBufferInfo2-dstBuffer-parameter",
                           "VUID-VkCopyBufferInfo2-commonparent", pCopyBufferInfo_loc.dot(Field::dstBuffer));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo,
                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyImage2-commandBuffer-parameter"
    if (pCopyImageInfo) {
        [[maybe_unused]] const Location pCopyImageInfo_loc = error_obj.location.dot(Field::pCopyImageInfo);
        skip |= ValidateObject(pCopyImageInfo->srcImage, kVulkanObjectTypeImage, false, "VUID-VkCopyImageInfo2-srcImage-parameter",
                               "VUID-VkCopyImageInfo2-commonparent", pCopyImageInfo_loc.dot(Field::srcImage));
        skip |= ValidateObject(pCopyImageInfo->dstImage, kVulkanObjectTypeImage, false, "VUID-VkCopyImageInfo2-dstImage-parameter",
                               "VUID-VkCopyImageInfo2-commonparent", pCopyImageInfo_loc.dot(Field::dstImage));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                                           const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyBufferToImage2-commandBuffer-parameter"
    if (pCopyBufferToImageInfo) {
        [[maybe_unused]] const Location pCopyBufferToImageInfo_loc = error_obj.location.dot(Field::pCopyBufferToImageInfo);
        skip |= ValidateObject(pCopyBufferToImageInfo->srcBuffer, kVulkanObjectTypeBuffer, false,
                               "VUID-VkCopyBufferToImageInfo2-srcBuffer-parameter", "VUID-VkCopyBufferToImageInfo2-commonparent",
                               pCopyBufferToImageInfo_loc.dot(Field::srcBuffer));
        skip |= ValidateObject(pCopyBufferToImageInfo->dstImage, kVulkanObjectTypeImage, false,
                               "VUID-VkCopyBufferToImageInfo2-dstImage-parameter", "VUID-VkCopyBufferToImageInfo2-commonparent",
                               pCopyBufferToImageInfo_loc.dot(Field::dstImage));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                                           const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdCopyImageToBuffer2-commandBuffer-parameter"
    if (pCopyImageToBufferInfo) {
        [[maybe_unused]] const Location pCopyImageToBufferInfo_loc = error_obj.location.dot(Field::pCopyImageToBufferInfo);
        skip |= ValidateObject(pCopyImageToBufferInfo->srcImage, kVulkanObjectTypeImage, false,
                               "VUID-VkCopyImageToBufferInfo2-srcImage-parameter", "VUID-VkCopyImageToBufferInfo2-commonparent",
                               pCopyImageToBufferInfo_loc.dot(Field::srcImage));
        skip |= ValidateObject(pCopyImageToBufferInfo->dstBuffer, kVulkanObjectTypeBuffer, false,
                               "VUID-VkCopyImageToBufferInfo2-dstBuffer-parameter", "VUID-VkCopyImageToBufferInfo2-commonparent",
                               pCopyImageToBufferInfo_loc.dot(Field::dstBuffer));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo,
                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdBlitImage2-commandBuffer-parameter"
    if (pBlitImageInfo) {
        [[maybe_unused]] const Location pBlitImageInfo_loc = error_obj.location.dot(Field::pBlitImageInfo);
        skip |= ValidateObject(pBlitImageInfo->srcImage, kVulkanObjectTypeImage, false, "VUID-VkBlitImageInfo2-srcImage-parameter",
                               "VUID-VkBlitImageInfo2-commonparent", pBlitImageInfo_loc.dot(Field::srcImage));
        skip |= ValidateObject(pBlitImageInfo->dstImage, kVulkanObjectTypeImage, false, "VUID-VkBlitImageInfo2-dstImage-parameter",
                               "VUID-VkBlitImageInfo2-commonparent", pBlitImageInfo_loc.dot(Field::dstImage));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdResolveImage2-commandBuffer-parameter"
    if (pResolveImageInfo) {
        [[maybe_unused]] const Location pResolveImageInfo_loc = error_obj.location.dot(Field::pResolveImageInfo);
        skip |= ValidateObject(pResolveImageInfo->srcImage, kVulkanObjectTypeImage, false,
                               "VUID-VkResolveImageInfo2-srcImage-parameter", "VUID-VkResolveImageInfo2-commonparent",
                               pResolveImageInfo_loc.dot(Field::srcImage));
        skip |= ValidateObject(pResolveImageInfo->dstImage, kVulkanObjectTypeImage, false,
                               "VUID-VkResolveImageInfo2-dstImage-parameter", "VUID-VkResolveImageInfo2-commonparent",
                               pResolveImageInfo_loc.dot(Field::dstImage));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pRenderingInfo) {
        [[maybe_unused]] const Location pRenderingInfo_loc = error_obj.location.dot(Field::pRenderingInfo);
        if (pRenderingInfo->pColorAttachments) {
            for (uint32_t index1 = 0; index1 < pRenderingInfo->colorAttachmentCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pRenderingInfo_loc.dot(Field::pColorAttachments, index1);
            }
        }
        if (pRenderingInfo->pDepthAttachment) {
            [[maybe_unused]] const Location pDepthAttachment_loc = pRenderingInfo_loc.dot(Field::pDepthAttachment);
        }
        if (pRenderingInfo->pStencilAttachment) {
            [[maybe_unused]] const Location pStencilAttachment_loc = pRenderingInfo_loc.dot(Field::pStencilAttachment);
        }
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkRenderingFragmentDensityMapAttachmentInfoEXT>(pRenderingInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc =
                pRenderingInfo_loc.pNext(Struct::VkRenderingFragmentDensityMapAttachmentInfoEXT);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pNext->imageView, kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined,
                                   pNext_loc.dot(Field::imageView));
        }
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkRenderingFragmentShadingRateAttachmentInfoKHR>(pRenderingInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc =
                pRenderingInfo_loc.pNext(Struct::VkRenderingFragmentShadingRateAttachmentInfoKHR);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pNext->imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined,
                                   pNext_loc.dot(Field::imageView));
        }
    }

    return skip;
}

// vkCmdEndRendering:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetCullMode:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetCullMode-commandBuffer-parameter"

// vkCmdSetFrontFace:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetFrontFace-commandBuffer-parameter"

// vkCmdSetPrimitiveTopology:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetPrimitiveTopology-commandBuffer-parameter"

// vkCmdSetViewportWithCount:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetViewportWithCount-commandBuffer-parameter"

// vkCmdSetScissorWithCount:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetScissorWithCount-commandBuffer-parameter"

bool ObjectLifetimes::PreCallValidateCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                           uint32_t bindingCount, const VkBuffer* pBuffers,
                                                           const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                           const VkDeviceSize* pStrides, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: "VUID-vkCmdBindVertexBuffers2-commandBuffer-parameter"
    // Checked by chassis: commandBuffer: "VUID-vkCmdBindVertexBuffers2-commonparent"

    if ((bindingCount > 0) && (pBuffers)) {
        for (uint32_t index0 = 0; index0 < bindingCount; ++index0) {
            skip |=
                ValidateObject(pBuffers[index0], kVulkanObjectTypeBuffer, true, "VUID-vkCmdBindVertexBuffers2-pBuffers-parameter",
                               "VUID-vkCmdBindVertexBuffers2-commonparent", error_obj.location.dot(Field::pBuffers, index0));
        }
    }

    return skip;
}

// vkCmdSetDepthTestEnable:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDepthTestEnable-commandBuffer-parameter"

// vkCmdSetDepthWriteEnable:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDepthWriteEnable-commandBuffer-parameter"

// vkCmdSetDepthCompareOp:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDepthCompareOp-commandBuffer-parameter"

// vkCmdSetDepthBoundsTestEnable:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDepthBoundsTestEnable-commandBuffer-parameter"

// vkCmdSetStencilTestEnable:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetStencilTestEnable-commandBuffer-parameter"

// vkCmdSetStencilOp:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetStencilOp-commandBuffer-parameter"

// vkCmdSetRasterizerDiscardEnable:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetRasterizerDiscardEnable-commandBuffer-parameter"

// vkCmdSetDepthBiasEnable:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDepthBiasEnable-commandBuffer-parameter"

// vkCmdSetPrimitiveRestartEnable:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetPrimitiveRestartEnable-commandBuffer-parameter"

// vkGetDeviceBufferMemoryRequirements:
// Checked by chassis: device: kVUIDUndefined

// vkGetDeviceImageMemoryRequirements:
// Checked by chassis: device: kVUIDUndefined

// vkGetDeviceImageSparseMemoryRequirements:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateGetCommandPoolMemoryConsumption(VkDevice device, VkCommandPool commandPool,
                                                                     VkCommandBuffer commandBuffer,
                                                                     VkCommandPoolMemoryConsumption* pConsumption,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetCommandPoolMemoryConsumption-device-parameter"
    skip |= ValidateObject(commandPool, kVulkanObjectTypeCommandPool, false,
                           "VUID-vkGetCommandPoolMemoryConsumption-commandPool-parameter",
                           "UNASSIGNED-vkGetCommandPoolMemoryConsumption-commonparent", error_obj.location.dot(Field::commandPool));
    skip |= ValidateObject(
        commandBuffer, kVulkanObjectTypeCommandBuffer, true, "VUID-vkGetCommandPoolMemoryConsumption-commandBuffer-parameter",
        "UNASSIGNED-vkGetCommandPoolMemoryConsumption-commonparent", error_obj.location.dot(Field::commandBuffer));

    return skip;
}

// vkGetFaultData:
// Checked by chassis: device: "VUID-vkGetFaultData-device-parameter"

bool ObjectLifetimes::PreCallValidateDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: instance: "VUID-vkDestroySurfaceKHR-instance-parameter"
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, true, "VUID-vkDestroySurfaceKHR-surface-parameter",
                           "VUID-vkDestroySurfaceKHR-surface-parent", error_obj.location.dot(Field::surface),
                           kVulkanObjectTypeInstance);
    skip |=
        ValidateDestroyObject(surface, kVulkanObjectTypeSurfaceKHR, pAllocator, kVUIDUndefined, kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface,
                                                     const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(surface, kVulkanObjectTypeSurfaceKHR);
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex,
                                                                        VkSurfaceKHR surface, VkBool32* pSupported,
                                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSurfaceSupportKHR-physicalDevice-parameter"
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSurfaceSupportKHR-commonparent"
    skip |=
        ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, false, "VUID-vkGetPhysicalDeviceSurfaceSupportKHR-surface-parameter",
                       "VUID-vkGetPhysicalDeviceSurfaceSupportKHR-commonparent", error_obj.location.dot(Field::surface),
                       kVulkanObjectTypeInstance);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                             VkSurfaceCapabilitiesKHR* pSurfaceCapabilities,
                                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSurfaceCapabilitiesKHR-physicalDevice-parameter"
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSurfaceCapabilitiesKHR-commonparent"
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, false,
                           "VUID-vkGetPhysicalDeviceSurfaceCapabilitiesKHR-surface-parameter",
                           "VUID-vkGetPhysicalDeviceSurfaceCapabilitiesKHR-commonparent", error_obj.location.dot(Field::surface),
                           kVulkanObjectTypeInstance);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                        uint32_t* pSurfaceFormatCount,
                                                                        VkSurfaceFormatKHR* pSurfaceFormats,
                                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSurfaceFormatsKHR-physicalDevice-parameter"
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSurfaceFormatsKHR-commonparent"
    skip |=
        ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, true, "VUID-vkGetPhysicalDeviceSurfaceFormatsKHR-surface-parameter",
                       "VUID-vkGetPhysicalDeviceSurfaceFormatsKHR-commonparent", error_obj.location.dot(Field::surface),
                       kVulkanObjectTypeInstance);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                             uint32_t* pPresentModeCount,
                                                                             VkPresentModeKHR* pPresentModes,
                                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSurfacePresentModesKHR-physicalDevice-parameter"
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSurfacePresentModesKHR-commonparent"
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, true,
                           "VUID-vkGetPhysicalDeviceSurfacePresentModesKHR-surface-parameter",
                           "VUID-vkGetPhysicalDeviceSurfacePresentModesKHR-commonparent", error_obj.location.dot(Field::surface),
                           kVulkanObjectTypeInstance);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkCreateSwapchainKHR-device-parameter"
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        auto instance_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
        auto instance_object_lifetimes = instance_data->GetValidationObject<ObjectLifetimes>();
        skip |= instance_object_lifetimes->ValidateObject(
            pCreateInfo->surface, kVulkanObjectTypeSurfaceKHR, false, "VUID-VkSwapchainCreateInfoKHR-surface-parameter",
            "VUID-VkSwapchainCreateInfoKHR-commonparent", pCreateInfo_loc.dot(Field::surface), kVulkanObjectTypeInstance);
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain,
                                                       const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSwapchain, kVulkanObjectTypeSwapchainKHR, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout,
                                                         VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkAcquireNextImageKHR-device-parameter"
    skip |= ValidateObject(swapchain, kVulkanObjectTypeSwapchainKHR, false, "VUID-vkAcquireNextImageKHR-swapchain-parameter",
                           "VUID-vkAcquireNextImageKHR-swapchain-parent", error_obj.location.dot(Field::swapchain));
    skip |= ValidateObject(semaphore, kVulkanObjectTypeSemaphore, true, "VUID-vkAcquireNextImageKHR-semaphore-parameter",
                           "VUID-vkAcquireNextImageKHR-semaphore-parent", error_obj.location.dot(Field::semaphore));
    skip |= ValidateObject(fence, kVulkanObjectTypeFence, true, "VUID-vkAcquireNextImageKHR-fence-parameter",
                           "VUID-vkAcquireNextImageKHR-fence-parent", error_obj.location.dot(Field::fence));

    return skip;
}

bool ObjectLifetimes::PreCallValidateQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo,
                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: queue: "VUID-vkQueuePresentKHR-queue-parameter"
    if (pPresentInfo) {
        [[maybe_unused]] const Location pPresentInfo_loc = error_obj.location.dot(Field::pPresentInfo);

        if ((pPresentInfo->waitSemaphoreCount > 0) && (pPresentInfo->pWaitSemaphores)) {
            for (uint32_t index1 = 0; index1 < pPresentInfo->waitSemaphoreCount; ++index1) {
                skip |= ValidateObject(pPresentInfo->pWaitSemaphores[index1], kVulkanObjectTypeSemaphore, false,
                                       "VUID-VkPresentInfoKHR-pWaitSemaphores-parameter", "VUID-VkPresentInfoKHR-commonparent",
                                       pPresentInfo_loc.dot(Field::pWaitSemaphores, index1));
            }
        }

        if ((pPresentInfo->swapchainCount > 0) && (pPresentInfo->pSwapchains)) {
            for (uint32_t index1 = 0; index1 < pPresentInfo->swapchainCount; ++index1) {
                skip |= ValidateObject(pPresentInfo->pSwapchains[index1], kVulkanObjectTypeSwapchainKHR, false,
                                       "VUID-VkPresentInfoKHR-pSwapchains-parameter", "VUID-VkPresentInfoKHR-commonparent",
                                       pPresentInfo_loc.dot(Field::pSwapchains, index1));
            }
        }
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkFrameBoundaryEXT>(pPresentInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pPresentInfo_loc.pNext(Struct::VkFrameBoundaryEXT);

            if ((pNext->imageCount > 0) && (pNext->pImages)) {
                for (uint32_t index2 = 0; index2 < pNext->imageCount; ++index2) {
                    skip |= ValidateObject(pNext->pImages[index2], kVulkanObjectTypeImage, false, kVUIDUndefined,
                                           "UNASSIGNED-VkFrameBoundaryEXT-commonparent", pNext_loc.dot(Field::pImages, index2));
                }
            }

            if ((pNext->bufferCount > 0) && (pNext->pBuffers)) {
                for (uint32_t index2 = 0; index2 < pNext->bufferCount; ++index2) {
                    skip |= ValidateObject(pNext->pBuffers[index2], kVulkanObjectTypeBuffer, false, kVUIDUndefined,
                                           "UNASSIGNED-VkFrameBoundaryEXT-commonparent", pNext_loc.dot(Field::pBuffers, index2));
                }
            }
        }
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkSwapchainPresentFenceInfoEXT>(pPresentInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pPresentInfo_loc.pNext(Struct::VkSwapchainPresentFenceInfoEXT);

            if ((pNext->swapchainCount > 0) && (pNext->pFences)) {
                for (uint32_t index2 = 0; index2 < pNext->swapchainCount; ++index2) {
                    skip |= ValidateObject(pNext->pFences[index2], kVulkanObjectTypeFence, false, kVUIDUndefined, kVUIDUndefined,
                                           pNext_loc.dot(Field::pFences, index2));
                }
            }
        }
    }

    return skip;
}

// vkGetDeviceGroupPresentCapabilitiesKHR:
// Checked by chassis: device: "VUID-vkGetDeviceGroupPresentCapabilitiesKHR-device-parameter"

bool ObjectLifetimes::PreCallValidateGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface,
                                                                          VkDeviceGroupPresentModeFlagsKHR* pModes,
                                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetDeviceGroupSurfacePresentModesKHR-device-parameter"
    // Checked by chassis: device: "VUID-vkGetDeviceGroupSurfacePresentModesKHR-commonparent"
    auto instance_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    auto instance_object_lifetimes = instance_data->GetValidationObject<ObjectLifetimes>();
    skip |= instance_object_lifetimes->ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, false,
                                                      "VUID-vkGetDeviceGroupSurfacePresentModesKHR-surface-parameter",
                                                      "VUID-vkGetDeviceGroupSurfacePresentModesKHR-commonparent",
                                                      error_obj.location.dot(Field::surface), kVulkanObjectTypeInstance);

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                           uint32_t* pRectCount, VkRect2D* pRects,
                                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDevicePresentRectanglesKHR-physicalDevice-parameter"
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDevicePresentRectanglesKHR-commonparent"
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, false,
                           "VUID-vkGetPhysicalDevicePresentRectanglesKHR-surface-parameter",
                           "VUID-vkGetPhysicalDevicePresentRectanglesKHR-commonparent", error_obj.location.dot(Field::surface),
                           kVulkanObjectTypeInstance);

    return skip;
}

bool ObjectLifetimes::PreCallValidateAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo,
                                                          uint32_t* pImageIndex, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkAcquireNextImage2KHR-device-parameter"
    if (pAcquireInfo) {
        [[maybe_unused]] const Location pAcquireInfo_loc = error_obj.location.dot(Field::pAcquireInfo);
        skip |= ValidateObject(pAcquireInfo->swapchain, kVulkanObjectTypeSwapchainKHR, false,
                               "VUID-VkAcquireNextImageInfoKHR-swapchain-parameter", "VUID-VkAcquireNextImageInfoKHR-commonparent",
                               pAcquireInfo_loc.dot(Field::swapchain));
        skip |= ValidateObject(pAcquireInfo->semaphore, kVulkanObjectTypeSemaphore, true,
                               "VUID-VkAcquireNextImageInfoKHR-semaphore-parameter", "VUID-VkAcquireNextImageInfoKHR-commonparent",
                               pAcquireInfo_loc.dot(Field::semaphore));
        skip |= ValidateObject(pAcquireInfo->fence, kVulkanObjectTypeFence, true, "VUID-VkAcquireNextImageInfoKHR-fence-parameter",
                               "VUID-VkAcquireNextImageInfoKHR-commonparent", pAcquireInfo_loc.dot(Field::fence));
    }

    return skip;
}

// vkGetPhysicalDeviceDisplayPlanePropertiesKHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceDisplayPlanePropertiesKHR-physicalDevice-parameter"

// vkGetDisplayPlaneSupportedDisplaysKHR:
// Checked by chassis: physicalDevice: "VUID-vkGetDisplayPlaneSupportedDisplaysKHR-physicalDevice-parameter"

void ObjectLifetimes::PostCallRecordGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex,
                                                                        uint32_t* pDisplayCount, VkDisplayKHR* pDisplays,
                                                                        const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    if (pDisplays) {
        for (uint32_t index = 0; index < *pDisplayCount; index++) {
            CreateObject(pDisplays[index], kVulkanObjectTypeDisplayKHR, nullptr, record_obj.location.dot(Field::pDisplays, index));
        }
    }
}

bool ObjectLifetimes::PreCallValidateCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                          const VkDisplayModeCreateInfoKHR* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: "VUID-vkCreateDisplayModeKHR-physicalDevice-parameter"
    skip |= ValidateObject(display, kVulkanObjectTypeDisplayKHR, false, "VUID-vkCreateDisplayModeKHR-display-parameter",
                           "VUID-vkCreateDisplayModeKHR-display-parent", error_obj.location.dot(Field::display),
                           kVulkanObjectTypePhysicalDevice);

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                         const VkDisplayModeCreateInfoKHR* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode,
                                                         const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pMode, kVulkanObjectTypeDisplayModeKHR, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode,
                                                                    uint32_t planeIndex,
                                                                    VkDisplayPlaneCapabilitiesKHR* pCapabilities,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: "VUID-vkGetDisplayPlaneCapabilitiesKHR-physicalDevice-parameter"
    skip |= ValidateObject(mode, kVulkanObjectTypeDisplayModeKHR, false, "VUID-vkGetDisplayPlaneCapabilitiesKHR-mode-parameter",
                           "VUID-vkGetDisplayPlaneCapabilitiesKHR-mode-parent", error_obj.location.dot(Field::mode),
                           kVulkanObjectTypePhysicalDevice);

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateDisplayPlaneSurfaceKHR(VkInstance instance,
                                                                  const VkDisplaySurfaceCreateInfoKHR* pCreateInfo,
                                                                  const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: instance: "VUID-vkCreateDisplayPlaneSurfaceKHR-instance-parameter"
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        skip |= ValidateObject(pCreateInfo->displayMode, kVulkanObjectTypeDisplayModeKHR, false,
                               "VUID-VkDisplaySurfaceCreateInfoKHR-displayMode-parameter", kVUIDUndefined,
                               pCreateInfo_loc.dot(Field::displayMode));
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateDisplayPlaneSurfaceKHR(VkInstance instance,
                                                                 const VkDisplaySurfaceCreateInfoKHR* pCreateInfo,
                                                                 const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                                 const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                                               const VkSwapchainCreateInfoKHR* pCreateInfos,
                                                               const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkCreateSharedSwapchainsKHR-device-parameter"
    if (pCreateInfos) {
        for (uint32_t index0 = 0; index0 < swapchainCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pCreateInfos, index0);
            auto instance_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
            auto instance_object_lifetimes = instance_data->GetValidationObject<ObjectLifetimes>();
            skip |= instance_object_lifetimes->ValidateObject(
                pCreateInfos[index0].surface, kVulkanObjectTypeSurfaceKHR, false, "VUID-VkSwapchainCreateInfoKHR-surface-parameter",
                "VUID-VkSwapchainCreateInfoKHR-commonparent", index0_loc.dot(Field::surface), kVulkanObjectTypeInstance);
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                                              const VkSwapchainCreateInfoKHR* pCreateInfos,
                                                              const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains,
                                                              const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    if (pSwapchains) {
        for (uint32_t index = 0; index < swapchainCount; index++) {
            CreateObject(pSwapchains[index], kVulkanObjectTypeSwapchainKHR, pAllocator,
                         record_obj.location.dot(Field::pSwapchains, index));
        }
    }
}
#ifdef VK_USE_PLATFORM_XLIB_KHR

// vkCreateXlibSurfaceKHR:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                         const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}

// vkGetPhysicalDeviceXlibPresentationSupportKHR:
// Checked by chassis: physicalDevice: kVUIDUndefined

#endif  // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR

// vkCreateXcbSurfaceKHR:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                        const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}

// vkGetPhysicalDeviceXcbPresentationSupportKHR:
// Checked by chassis: physicalDevice: kVUIDUndefined

#endif  // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR

// vkCreateWaylandSurfaceKHR:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateWaylandSurfaceKHR(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                            const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}

// vkGetPhysicalDeviceWaylandPresentationSupportKHR:
// Checked by chassis: physicalDevice: kVUIDUndefined

#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR

// vkCreateAndroidSurfaceKHR:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateAndroidSurfaceKHR(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                            const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR

// vkCreateWin32SurfaceKHR:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                          const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}

// vkGetPhysicalDeviceWin32PresentationSupportKHR:
// Checked by chassis: physicalDevice: kVUIDUndefined

#endif  // VK_USE_PLATFORM_WIN32_KHR

// vkGetPhysicalDeviceVideoCapabilitiesKHR:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkGetPhysicalDeviceVideoFormatPropertiesKHR:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkCreateVideoSessionKHR:
// Checked by chassis: device: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateVideoSessionKHR(VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession,
                                                          const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pVideoSession, kVulkanObjectTypeVideoSessionKHR, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyVideoSessionKHR(VkDevice device, VkVideoSessionKHR videoSession,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(videoSession, kVulkanObjectTypeVideoSessionKHR, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyVideoSessionKHR(VkDevice device, VkVideoSessionKHR videoSession,
                                                          const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(videoSession, kVulkanObjectTypeVideoSessionKHR);
}

// vkGetVideoSessionMemoryRequirementsKHR:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateBindVideoSessionMemoryKHR(VkDevice device, VkVideoSessionKHR videoSession,
                                                               uint32_t bindSessionMemoryInfoCount,
                                                               const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pBindSessionMemoryInfos) {
        for (uint32_t index0 = 0; index0 < bindSessionMemoryInfoCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pBindSessionMemoryInfos, index0);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pBindSessionMemoryInfos[index0].memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined,
                                   kVUIDUndefined, index0_loc.dot(Field::memory));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCreateVideoSessionParametersKHR(VkDevice device,
                                                                     const VkVideoSessionParametersCreateInfoKHR* pCreateInfo,
                                                                     const VkAllocationCallbacks* pAllocator,
                                                                     VkVideoSessionParametersKHR* pVideoSessionParameters,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateVideoSessionParametersKHR(VkDevice device,
                                                                    const VkVideoSessionParametersCreateInfoKHR* pCreateInfo,
                                                                    const VkAllocationCallbacks* pAllocator,
                                                                    VkVideoSessionParametersKHR* pVideoSessionParameters,
                                                                    const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pVideoSessionParameters, kVulkanObjectTypeVideoSessionParametersKHR, pAllocator, record_obj.location);
}

// vkUpdateVideoSessionParametersKHR:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateDestroyVideoSessionParametersKHR(VkDevice device,
                                                                      VkVideoSessionParametersKHR videoSessionParameters,
                                                                      const VkAllocationCallbacks* pAllocator,
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(videoSessionParameters, kVulkanObjectTypeVideoSessionParametersKHR, pAllocator, kVUIDUndefined,
                                  kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyVideoSessionParametersKHR(VkDevice device,
                                                                    VkVideoSessionParametersKHR videoSessionParameters,
                                                                    const VkAllocationCallbacks* pAllocator,
                                                                    const RecordObject& record_obj) {
    RecordDestroyObject(videoSessionParameters, kVulkanObjectTypeVideoSessionParametersKHR);
}

bool ObjectLifetimes::PreCallValidateCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                            const VkVideoBeginCodingInfoKHR* pBeginInfo,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pBeginInfo) {
        [[maybe_unused]] const Location pBeginInfo_loc = error_obj.location.dot(Field::pBeginInfo);
        if (pBeginInfo->pReferenceSlots) {
            for (uint32_t index1 = 0; index1 < pBeginInfo->referenceSlotCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pBeginInfo_loc.dot(Field::pReferenceSlots, index1);
                if (pBeginInfo->pReferenceSlots[index1].pPictureResource) {
                    [[maybe_unused]] const Location pPictureResource_loc = index1_loc.dot(Field::pPictureResource);
                    // There should be an explicit VU (if not that is a spec bug)
                    skip |= ValidateObject(pBeginInfo->pReferenceSlots[index1].pPictureResource->imageViewBinding,
                                           kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined,
                                           pPictureResource_loc.dot(Field::imageViewBinding));
                }
            }
        }
    }

    return skip;
}

// vkCmdEndVideoCodingKHR:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdControlVideoCodingKHR:
// Checked by chassis: commandBuffer: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pDecodeInfo) {
        [[maybe_unused]] const Location pDecodeInfo_loc = error_obj.location.dot(Field::pDecodeInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pDecodeInfo->srcBuffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined,
                               pDecodeInfo_loc.dot(Field::srcBuffer));
        [[maybe_unused]] const Location dstPictureResource_loc = pDecodeInfo_loc.dot(Field::dstPictureResource);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pDecodeInfo->dstPictureResource.imageViewBinding, kVulkanObjectTypeImageView, false, kVUIDUndefined,
                               kVUIDUndefined, dstPictureResource_loc.dot(Field::imageViewBinding));
        if (pDecodeInfo->pSetupReferenceSlot) {
            [[maybe_unused]] const Location pSetupReferenceSlot_loc = pDecodeInfo_loc.dot(Field::pSetupReferenceSlot);
            if (pDecodeInfo->pSetupReferenceSlot->pPictureResource) {
                [[maybe_unused]] const Location pPictureResource_loc = pSetupReferenceSlot_loc.dot(Field::pPictureResource);
                // There should be an explicit VU (if not that is a spec bug)
                skip |=
                    ValidateObject(pDecodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding, kVulkanObjectTypeImageView,
                                   false, kVUIDUndefined, kVUIDUndefined, pPictureResource_loc.dot(Field::imageViewBinding));
            }
        }
        if (pDecodeInfo->pReferenceSlots) {
            for (uint32_t index1 = 0; index1 < pDecodeInfo->referenceSlotCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pDecodeInfo_loc.dot(Field::pReferenceSlots, index1);
                if (pDecodeInfo->pReferenceSlots[index1].pPictureResource) {
                    [[maybe_unused]] const Location pPictureResource_loc = index1_loc.dot(Field::pPictureResource);
                    // There should be an explicit VU (if not that is a spec bug)
                    skip |= ValidateObject(pDecodeInfo->pReferenceSlots[index1].pPictureResource->imageViewBinding,
                                           kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined,
                                           pPictureResource_loc.dot(Field::imageViewBinding));
                }
            }
        }
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkVideoInlineQueryInfoKHR>(pDecodeInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pDecodeInfo_loc.pNext(Struct::VkVideoInlineQueryInfoKHR);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo,
                                                          const ErrorObject& error_obj) const {
    return PreCallValidateCmdBeginRendering(commandBuffer, pRenderingInfo, error_obj);
}

// vkCmdEndRenderingKHR:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkGetPhysicalDeviceFeatures2KHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceFeatures2-physicalDevice-parameter"

// vkGetPhysicalDeviceProperties2KHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceProperties2-physicalDevice-parameter"

// vkGetPhysicalDeviceFormatProperties2KHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceFormatProperties2-physicalDevice-parameter"

// vkGetPhysicalDeviceImageFormatProperties2KHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceImageFormatProperties2-physicalDevice-parameter"

// vkGetPhysicalDeviceMemoryProperties2KHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceMemoryProperties2-physicalDevice-parameter"

// vkGetPhysicalDeviceSparseImageFormatProperties2KHR:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkGetDeviceGroupPeerMemoryFeaturesKHR:
// Checked by chassis: device: "VUID-vkGetDeviceGroupPeerMemoryFeatures-device-parameter"

// vkCmdSetDeviceMaskKHR:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDeviceMask-commandBuffer-parameter"

// vkCmdDispatchBaseKHR:
// Checked by chassis: commandBuffer: "VUID-vkCmdDispatchBase-commandBuffer-parameter"

// vkTrimCommandPoolKHR:
// Checked by chassis: device: kVUIDUndefined

// vkEnumeratePhysicalDeviceGroupsKHR:
// Checked by chassis: instance: "VUID-vkEnumeratePhysicalDeviceGroups-instance-parameter"

void ObjectLifetimes::PostCallRecordEnumeratePhysicalDeviceGroupsKHR(
    VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties,
    const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS && record_obj.result != VK_INCOMPLETE) return;

    if (pPhysicalDeviceGroupProperties) {
        const RecordObject record_obj(vvl::Func::vkEnumeratePhysicalDevices, VK_SUCCESS);
        for (uint32_t device_group_index = 0; device_group_index < *pPhysicalDeviceGroupCount; device_group_index++) {
            PostCallRecordEnumeratePhysicalDevices(instance,
                                                   &pPhysicalDeviceGroupProperties[device_group_index].physicalDeviceCount,
                                                   pPhysicalDeviceGroupProperties[device_group_index].physicalDevices, record_obj);
        }
    }
}

// vkGetPhysicalDeviceExternalBufferPropertiesKHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceExternalBufferProperties-physicalDevice-parameter"

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetMemoryWin32HandleKHR(VkDevice device,
                                                             const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                                             HANDLE* pHandle, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pGetWin32HandleInfo) {
        [[maybe_unused]] const Location pGetWin32HandleInfo_loc = error_obj.location.dot(Field::pGetWin32HandleInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pGetWin32HandleInfo->memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined,
                               pGetWin32HandleInfo_loc.dot(Field::memory));
    }

    return skip;
}

// vkGetMemoryWin32HandlePropertiesKHR:
// Checked by chassis: device: kVUIDUndefined

#endif  // VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd,
                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetMemoryFdKHR-device-parameter"
    if (pGetFdInfo) {
        [[maybe_unused]] const Location pGetFdInfo_loc = error_obj.location.dot(Field::pGetFdInfo);
        skip |= ValidateObject(pGetFdInfo->memory, kVulkanObjectTypeDeviceMemory, false,
                               "VUID-VkMemoryGetFdInfoKHR-memory-parameter", kVUIDUndefined, pGetFdInfo_loc.dot(Field::memory));
    }

    return skip;
}

// vkGetMemoryFdPropertiesKHR:
// Checked by chassis: device: "VUID-vkGetMemoryFdPropertiesKHR-device-parameter"

// vkGetPhysicalDeviceExternalSemaphorePropertiesKHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceExternalSemaphoreProperties-physicalDevice-parameter"

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateImportSemaphoreWin32HandleKHR(
    VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo,
    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pImportSemaphoreWin32HandleInfo) {
        [[maybe_unused]] const Location pImportSemaphoreWin32HandleInfo_loc =
            error_obj.location.dot(Field::pImportSemaphoreWin32HandleInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pImportSemaphoreWin32HandleInfo->semaphore, kVulkanObjectTypeSemaphore, false, kVUIDUndefined,
                               kVUIDUndefined, pImportSemaphoreWin32HandleInfo_loc.dot(Field::semaphore));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetSemaphoreWin32HandleKHR(VkDevice device,
                                                                const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                                                HANDLE* pHandle, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pGetWin32HandleInfo) {
        [[maybe_unused]] const Location pGetWin32HandleInfo_loc = error_obj.location.dot(Field::pGetWin32HandleInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pGetWin32HandleInfo->semaphore, kVulkanObjectTypeSemaphore, false, kVUIDUndefined, kVUIDUndefined,
                               pGetWin32HandleInfo_loc.dot(Field::semaphore));
    }

    return skip;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkImportSemaphoreFdKHR-device-parameter"
    if (pImportSemaphoreFdInfo) {
        [[maybe_unused]] const Location pImportSemaphoreFdInfo_loc = error_obj.location.dot(Field::pImportSemaphoreFdInfo);
        skip |= ValidateObject(pImportSemaphoreFdInfo->semaphore, kVulkanObjectTypeSemaphore, false,
                               "VUID-VkImportSemaphoreFdInfoKHR-semaphore-parameter", kVUIDUndefined,
                               pImportSemaphoreFdInfo_loc.dot(Field::semaphore));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetSemaphoreFdKHR-device-parameter"
    if (pGetFdInfo) {
        [[maybe_unused]] const Location pGetFdInfo_loc = error_obj.location.dot(Field::pGetFdInfo);
        skip |= ValidateObject(pGetFdInfo->semaphore, kVulkanObjectTypeSemaphore, false,
                               "VUID-VkSemaphoreGetFdInfoKHR-semaphore-parameter", kVUIDUndefined,
                               pGetFdInfo_loc.dot(Field::semaphore));
    }

    return skip;
}

// vkCmdPushDescriptorSetWithTemplateKHR:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdPushDescriptorSetWithTemplateKHR-commonparent"

bool ObjectLifetimes::PreCallValidateDestroyDescriptorUpdateTemplateKHR(VkDevice device,
                                                                        VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                        const VkAllocationCallbacks* pAllocator,
                                                                        const ErrorObject& error_obj) const {
    return PreCallValidateDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator, error_obj);
}

void ObjectLifetimes::PreCallRecordDestroyDescriptorUpdateTemplateKHR(VkDevice device,
                                                                      VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                      const VkAllocationCallbacks* pAllocator,
                                                                      const RecordObject& record_obj) {
    RecordDestroyObject(descriptorUpdateTemplate, kVulkanObjectTypeDescriptorUpdateTemplate);
}

// vkUpdateDescriptorSetWithTemplateKHR:
// Checked by chassis: device: kVUIDUndefined

// vkCreateRenderPass2KHR:
// Checked by chassis: device: "VUID-vkCreateRenderPass2-device-parameter"

void ObjectLifetimes::PostCallRecordCreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                                         const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pRenderPass, kVulkanObjectTypeRenderPass, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer,
                                                            const VkRenderPassBeginInfo* pRenderPassBegin,
                                                            const VkSubpassBeginInfo* pSubpassBeginInfo,
                                                            const ErrorObject& error_obj) const {
    return PreCallValidateCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo, error_obj);
}

// vkCmdNextSubpass2KHR:
// Checked by chassis: commandBuffer: "VUID-vkCmdNextSubpass2-commandBuffer-parameter"

// vkCmdEndRenderPass2KHR:
// Checked by chassis: commandBuffer: "VUID-vkCmdEndRenderPass2-commandBuffer-parameter"

bool ObjectLifetimes::PreCallValidateGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetSwapchainStatusKHR-device-parameter"
    skip |= ValidateObject(swapchain, kVulkanObjectTypeSwapchainKHR, false, "VUID-vkGetSwapchainStatusKHR-swapchain-parameter",
                           "VUID-vkGetSwapchainStatusKHR-swapchain-parent", error_obj.location.dot(Field::swapchain));

    return skip;
}

// vkGetPhysicalDeviceExternalFencePropertiesKHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceExternalFenceProperties-physicalDevice-parameter"

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateImportFenceWin32HandleKHR(VkDevice device,
                                                               const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pImportFenceWin32HandleInfo) {
        [[maybe_unused]] const Location pImportFenceWin32HandleInfo_loc =
            error_obj.location.dot(Field::pImportFenceWin32HandleInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pImportFenceWin32HandleInfo->fence, kVulkanObjectTypeFence, false, kVUIDUndefined, kVUIDUndefined,
                               pImportFenceWin32HandleInfo_loc.dot(Field::fence));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetFenceWin32HandleKHR(VkDevice device,
                                                            const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                                            HANDLE* pHandle, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pGetWin32HandleInfo) {
        [[maybe_unused]] const Location pGetWin32HandleInfo_loc = error_obj.location.dot(Field::pGetWin32HandleInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pGetWin32HandleInfo->fence, kVulkanObjectTypeFence, false, kVUIDUndefined, kVUIDUndefined,
                               pGetWin32HandleInfo_loc.dot(Field::fence));
    }

    return skip;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkImportFenceFdKHR-device-parameter"
    if (pImportFenceFdInfo) {
        [[maybe_unused]] const Location pImportFenceFdInfo_loc = error_obj.location.dot(Field::pImportFenceFdInfo);
        skip |=
            ValidateObject(pImportFenceFdInfo->fence, kVulkanObjectTypeFence, false, "VUID-VkImportFenceFdInfoKHR-fence-parameter",
                           kVUIDUndefined, pImportFenceFdInfo_loc.dot(Field::fence));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd,
                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetFenceFdKHR-device-parameter"
    if (pGetFdInfo) {
        [[maybe_unused]] const Location pGetFdInfo_loc = error_obj.location.dot(Field::pGetFdInfo);
        skip |= ValidateObject(pGetFdInfo->fence, kVulkanObjectTypeFence, false, "VUID-VkFenceGetFdInfoKHR-fence-parameter",
                               kVUIDUndefined, pGetFdInfo_loc.dot(Field::fence));
    }

    return skip;
}

// vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR:
// Checked by chassis: physicalDevice:
// "VUID-vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR-physicalDevice-parameter"

// vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR-physicalDevice-parameter"

// vkAcquireProfilingLockKHR:
// Checked by chassis: device: "VUID-vkAcquireProfilingLockKHR-device-parameter"

// vkReleaseProfilingLockKHR:
// Checked by chassis: device: "VUID-vkReleaseProfilingLockKHR-device-parameter"

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice,
                                                                              const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                              VkSurfaceCapabilities2KHR* pSurfaceCapabilities,
                                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSurfaceCapabilities2KHR-physicalDevice-parameter"
    if (pSurfaceInfo) {
        [[maybe_unused]] const Location pSurfaceInfo_loc = error_obj.location.dot(Field::pSurfaceInfo);
        skip |= ValidateObject(pSurfaceInfo->surface, kVulkanObjectTypeSurfaceKHR, true,
                               "VUID-VkPhysicalDeviceSurfaceInfo2KHR-surface-parameter", kVUIDUndefined,
                               pSurfaceInfo_loc.dot(Field::surface));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice,
                                                                         const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                         uint32_t* pSurfaceFormatCount,
                                                                         VkSurfaceFormat2KHR* pSurfaceFormats,
                                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSurfaceFormats2KHR-physicalDevice-parameter"
    if (pSurfaceInfo) {
        [[maybe_unused]] const Location pSurfaceInfo_loc = error_obj.location.dot(Field::pSurfaceInfo);
        skip |= ValidateObject(pSurfaceInfo->surface, kVulkanObjectTypeSurfaceKHR, true,
                               "VUID-VkPhysicalDeviceSurfaceInfo2KHR-surface-parameter", kVUIDUndefined,
                               pSurfaceInfo_loc.dot(Field::surface));
    }

    return skip;
}

// vkGetPhysicalDeviceDisplayPlaneProperties2KHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceDisplayPlaneProperties2KHR-physicalDevice-parameter"

bool ObjectLifetimes::PreCallValidateGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice,
                                                                     const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo,
                                                                     VkDisplayPlaneCapabilities2KHR* pCapabilities,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: "VUID-vkGetDisplayPlaneCapabilities2KHR-physicalDevice-parameter"
    if (pDisplayPlaneInfo) {
        [[maybe_unused]] const Location pDisplayPlaneInfo_loc = error_obj.location.dot(Field::pDisplayPlaneInfo);
        skip |=
            ValidateObject(pDisplayPlaneInfo->mode, kVulkanObjectTypeDisplayModeKHR, false,
                           "VUID-VkDisplayPlaneInfo2KHR-mode-parameter", kVUIDUndefined, pDisplayPlaneInfo_loc.dot(Field::mode));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo,
                                                                    VkMemoryRequirements2* pMemoryRequirements,
                                                                    const ErrorObject& error_obj) const {
    return PreCallValidateGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements, error_obj);
}

bool ObjectLifetimes::PreCallValidateGetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo,
                                                                     VkMemoryRequirements2* pMemoryRequirements,
                                                                     const ErrorObject& error_obj) const {
    return PreCallValidateGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements, error_obj);
}

bool ObjectLifetimes::PreCallValidateGetImageSparseMemoryRequirements2KHR(
    VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2* pSparseMemoryRequirements, const ErrorObject& error_obj) const {
    return PreCallValidateGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements,
                                                            error_obj);
}

// vkCreateSamplerYcbcrConversionKHR:
// Checked by chassis: device: "VUID-vkCreateSamplerYcbcrConversion-device-parameter"

void ObjectLifetimes::PostCallRecordCreateSamplerYcbcrConversionKHR(VkDevice device,
                                                                    const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                                    const VkAllocationCallbacks* pAllocator,
                                                                    VkSamplerYcbcrConversion* pYcbcrConversion,
                                                                    const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pYcbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion,
                                                                      const VkAllocationCallbacks* pAllocator,
                                                                      const ErrorObject& error_obj) const {
    return PreCallValidateDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator, error_obj);
}

void ObjectLifetimes::PreCallRecordDestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion,
                                                                    const VkAllocationCallbacks* pAllocator,
                                                                    const RecordObject& record_obj) {
    RecordDestroyObject(ycbcrConversion, kVulkanObjectTypeSamplerYcbcrConversion);
}

bool ObjectLifetimes::PreCallValidateBindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount,
                                                          const VkBindBufferMemoryInfo* pBindInfos,
                                                          const ErrorObject& error_obj) const {
    return PreCallValidateBindBufferMemory2(device, bindInfoCount, pBindInfos, error_obj);
}

bool ObjectLifetimes::PreCallValidateBindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount,
                                                         const VkBindImageMemoryInfo* pBindInfos,
                                                         const ErrorObject& error_obj) const {
    return PreCallValidateBindImageMemory2(device, bindInfoCount, pBindInfos, error_obj);
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                             VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                             uint32_t maxDrawCount, uint32_t stride,
                                                             const ErrorObject& error_obj) const {
    return PreCallValidateCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride,
                                               error_obj);
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                    VkDeviceSize offset, VkBuffer countBuffer,
                                                                    VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                                    uint32_t stride, const ErrorObject& error_obj) const {
    return PreCallValidateCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                                      stride, error_obj);
}

bool ObjectLifetimes::PreCallValidateGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue,
                                                                 const ErrorObject& error_obj) const {
    return PreCallValidateGetSemaphoreCounterValue(device, semaphore, pValue, error_obj);
}

bool ObjectLifetimes::PreCallValidateWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout,
                                                       const ErrorObject& error_obj) const {
    return PreCallValidateWaitSemaphores(device, pWaitInfo, timeout, error_obj);
}

bool ObjectLifetimes::PreCallValidateSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo,
                                                        const ErrorObject& error_obj) const {
    return PreCallValidateSignalSemaphore(device, pSignalInfo, error_obj);
}

// vkGetPhysicalDeviceFragmentShadingRatesKHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceFragmentShadingRatesKHR-physicalDevice-parameter"

// vkCmdSetFragmentShadingRateKHR:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetFragmentShadingRateKHR-commandBuffer-parameter"

// vkCmdSetRenderingAttachmentLocationsKHR:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetRenderingInputAttachmentIndicesKHR:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkWaitForPresentKHR:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateGetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo,
                                                               const ErrorObject& error_obj) const {
    return PreCallValidateGetBufferDeviceAddress(device, pInfo, error_obj);
}

bool ObjectLifetimes::PreCallValidateGetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo,
                                                                      const ErrorObject& error_obj) const {
    return PreCallValidateGetBufferOpaqueCaptureAddress(device, pInfo, error_obj);
}

bool ObjectLifetimes::PreCallValidateGetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device,
                                                                            const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo,
                                                                            const ErrorObject& error_obj) const {
    return PreCallValidateGetDeviceMemoryOpaqueCaptureAddress(device, pInfo, error_obj);
}

// vkCreateDeferredOperationKHR:
// Checked by chassis: device: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks* pAllocator,
                                                               VkDeferredOperationKHR* pDeferredOperation,
                                                               const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pDeferredOperation, kVulkanObjectTypeDeferredOperationKHR, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation,
                                                                 const VkAllocationCallbacks* pAllocator,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(operation, kVulkanObjectTypeDeferredOperationKHR, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               const RecordObject& record_obj) {
    RecordDestroyObject(operation, kVulkanObjectTypeDeferredOperationKHR);
}

// vkGetDeferredOperationMaxConcurrencyKHR:
// Checked by chassis: device: kVUIDUndefined

// vkGetDeferredOperationResultKHR:
// Checked by chassis: device: kVUIDUndefined

// vkDeferredOperationJoinKHR:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateGetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR* pPipelineInfo,
                                                                        uint32_t* pExecutableCount,
                                                                        VkPipelineExecutablePropertiesKHR* pProperties,
                                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pPipelineInfo) {
        [[maybe_unused]] const Location pPipelineInfo_loc = error_obj.location.dot(Field::pPipelineInfo);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPipelineExecutableStatisticsKHR(VkDevice device,
                                                                        const VkPipelineExecutableInfoKHR* pExecutableInfo,
                                                                        uint32_t* pStatisticCount,
                                                                        VkPipelineExecutableStatisticKHR* pStatistics,
                                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pExecutableInfo) {
        [[maybe_unused]] const Location pExecutableInfo_loc = error_obj.location.dot(Field::pExecutableInfo);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetPipelineExecutableInternalRepresentationsKHR(
    VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount,
    VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pExecutableInfo) {
        [[maybe_unused]] const Location pExecutableInfo_loc = error_obj.location.dot(Field::pExecutableInfo);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateMapMemory2KHR(VkDevice device, const VkMemoryMapInfoKHR* pMemoryMapInfo, void** ppData,
                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pMemoryMapInfo) {
        [[maybe_unused]] const Location pMemoryMapInfo_loc = error_obj.location.dot(Field::pMemoryMapInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pMemoryMapInfo->memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined,
                               pMemoryMapInfo_loc.dot(Field::memory));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateUnmapMemory2KHR(VkDevice device, const VkMemoryUnmapInfoKHR* pMemoryUnmapInfo,
                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pMemoryUnmapInfo) {
        [[maybe_unused]] const Location pMemoryUnmapInfo_loc = error_obj.location.dot(Field::pMemoryUnmapInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pMemoryUnmapInfo->memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined,
                               pMemoryUnmapInfo_loc.dot(Field::memory));
    }

    return skip;
}

// vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR:
// Checked by chassis: physicalDevice: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateGetEncodedVideoSessionParametersKHR(
    VkDevice device, const VkVideoEncodeSessionParametersGetInfoKHR* pVideoSessionParametersInfo,
    VkVideoEncodeSessionParametersFeedbackInfoKHR* pFeedbackInfo, size_t* pDataSize, void* pData,
    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pVideoSessionParametersInfo) {
        [[maybe_unused]] const Location pVideoSessionParametersInfo_loc =
            error_obj.location.dot(Field::pVideoSessionParametersInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |=
            ValidateObject(pVideoSessionParametersInfo->videoSessionParameters, kVulkanObjectTypeVideoSessionParametersKHR, false,
                           kVUIDUndefined, kVUIDUndefined, pVideoSessionParametersInfo_loc.dot(Field::videoSessionParameters));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pEncodeInfo) {
        [[maybe_unused]] const Location pEncodeInfo_loc = error_obj.location.dot(Field::pEncodeInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pEncodeInfo->dstBuffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined,
                               pEncodeInfo_loc.dot(Field::dstBuffer));
        [[maybe_unused]] const Location srcPictureResource_loc = pEncodeInfo_loc.dot(Field::srcPictureResource);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pEncodeInfo->srcPictureResource.imageViewBinding, kVulkanObjectTypeImageView, false, kVUIDUndefined,
                               kVUIDUndefined, srcPictureResource_loc.dot(Field::imageViewBinding));
        if (pEncodeInfo->pSetupReferenceSlot) {
            [[maybe_unused]] const Location pSetupReferenceSlot_loc = pEncodeInfo_loc.dot(Field::pSetupReferenceSlot);
            if (pEncodeInfo->pSetupReferenceSlot->pPictureResource) {
                [[maybe_unused]] const Location pPictureResource_loc = pSetupReferenceSlot_loc.dot(Field::pPictureResource);
                // There should be an explicit VU (if not that is a spec bug)
                skip |=
                    ValidateObject(pEncodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding, kVulkanObjectTypeImageView,
                                   false, kVUIDUndefined, kVUIDUndefined, pPictureResource_loc.dot(Field::imageViewBinding));
            }
        }
        if (pEncodeInfo->pReferenceSlots) {
            for (uint32_t index1 = 0; index1 < pEncodeInfo->referenceSlotCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pEncodeInfo_loc.dot(Field::pReferenceSlots, index1);
                if (pEncodeInfo->pReferenceSlots[index1].pPictureResource) {
                    [[maybe_unused]] const Location pPictureResource_loc = index1_loc.dot(Field::pPictureResource);
                    // There should be an explicit VU (if not that is a spec bug)
                    skip |= ValidateObject(pEncodeInfo->pReferenceSlots[index1].pPictureResource->imageViewBinding,
                                           kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined,
                                           pPictureResource_loc.dot(Field::imageViewBinding));
                }
            }
        }
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkVideoInlineQueryInfoKHR>(pEncodeInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pEncodeInfo_loc.pNext(Struct::VkVideoInlineQueryInfoKHR);
        }
    }

    return skip;
}

// vkCmdRefreshObjectsKHR:
// Checked by chassis: commandBuffer: "VUID-vkCmdRefreshObjectsKHR-commandBuffer-parameter"

// vkGetPhysicalDeviceRefreshableObjectTypesKHR:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceRefreshableObjectTypesKHR-physicalDevice-parameter"

bool ObjectLifetimes::PreCallValidateCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                                     const VkDependencyInfo* pDependencyInfo, const ErrorObject& error_obj) const {
    return PreCallValidateCmdSetEvent2(commandBuffer, event, pDependencyInfo, error_obj);
}

bool ObjectLifetimes::PreCallValidateCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                                       VkPipelineStageFlags2 stageMask, const ErrorObject& error_obj) const {
    return PreCallValidateCmdResetEvent2(commandBuffer, event, stageMask, error_obj);
}

bool ObjectLifetimes::PreCallValidateCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                                       const VkDependencyInfo* pDependencyInfos,
                                                       const ErrorObject& error_obj) const {
    return PreCallValidateCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos, error_obj);
}

bool ObjectLifetimes::PreCallValidateCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo,
                                                            const ErrorObject& error_obj) const {
    return PreCallValidateCmdPipelineBarrier2(commandBuffer, pDependencyInfo, error_obj);
}

bool ObjectLifetimes::PreCallValidateCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                           VkQueryPool queryPool, uint32_t query,
                                                           const ErrorObject& error_obj) const {
    return PreCallValidateCmdWriteTimestamp2(commandBuffer, stage, queryPool, query, error_obj);
}

bool ObjectLifetimes::PreCallValidateQueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits,
                                                     VkFence fence, const ErrorObject& error_obj) const {
    return PreCallValidateQueueSubmit2(queue, submitCount, pSubmits, fence, error_obj);
}

// vkCmdWriteBufferMarker2AMD:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdWriteBufferMarker2AMD-commonparent"

// vkGetQueueCheckpointData2NV:
// Checked by chassis: queue: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo,
                                                       const ErrorObject& error_obj) const {
    return PreCallValidateCmdCopyBuffer2(commandBuffer, pCopyBufferInfo, error_obj);
}

bool ObjectLifetimes::PreCallValidateCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo,
                                                      const ErrorObject& error_obj) const {
    return PreCallValidateCmdCopyImage2(commandBuffer, pCopyImageInfo, error_obj);
}

bool ObjectLifetimes::PreCallValidateCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                                              const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo,
                                                              const ErrorObject& error_obj) const {
    return PreCallValidateCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo, error_obj);
}

bool ObjectLifetimes::PreCallValidateCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                                              const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo,
                                                              const ErrorObject& error_obj) const {
    return PreCallValidateCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo, error_obj);
}

bool ObjectLifetimes::PreCallValidateCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo,
                                                      const ErrorObject& error_obj) const {
    return PreCallValidateCmdBlitImage2(commandBuffer, pBlitImageInfo, error_obj);
}

bool ObjectLifetimes::PreCallValidateCmdResolveImage2KHR(VkCommandBuffer commandBuffer,
                                                         const VkResolveImageInfo2* pResolveImageInfo,
                                                         const ErrorObject& error_obj) const {
    return PreCallValidateCmdResolveImage2(commandBuffer, pResolveImageInfo, error_obj);
}

// vkCmdTraceRaysIndirect2KHR:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkGetDeviceBufferMemoryRequirementsKHR:
// Checked by chassis: device: kVUIDUndefined

// vkGetDeviceImageMemoryRequirementsKHR:
// Checked by chassis: device: kVUIDUndefined

// vkGetDeviceImageSparseMemoryRequirementsKHR:
// Checked by chassis: device: kVUIDUndefined

// vkCmdBindIndexBuffer2KHR:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdBindIndexBuffer2KHR-commonparent"

// vkGetRenderingAreaGranularityKHR:
// Checked by chassis: device: kVUIDUndefined

// vkGetDeviceImageSubresourceLayoutKHR:
// Checked by chassis: device: kVUIDUndefined

// vkGetImageSubresourceLayout2KHR:
// Checked by chassis: device: kVUIDUndefined

// vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkCmdSetLineStippleKHR:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkGetPhysicalDeviceCalibrateableTimeDomainsKHR:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkGetCalibratedTimestampsKHR:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                                               const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pBindDescriptorSetsInfo) {
        [[maybe_unused]] const Location pBindDescriptorSetsInfo_loc = error_obj.location.dot(Field::pBindDescriptorSetsInfo);

        if ((pBindDescriptorSetsInfo->descriptorSetCount > 0) && (pBindDescriptorSetsInfo->pDescriptorSets)) {
            for (uint32_t index1 = 0; index1 < pBindDescriptorSetsInfo->descriptorSetCount; ++index1) {
                skip |= ValidateObject(pBindDescriptorSetsInfo->pDescriptorSets[index1], kVulkanObjectTypeDescriptorSet, false,
                                       kVUIDUndefined, "UNASSIGNED-VkBindDescriptorSetsInfoKHR-commonparent",
                                       pBindDescriptorSetsInfo_loc.dot(Field::pDescriptorSets, index1));
            }
        }
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkPipelineLayoutCreateInfo>(pBindDescriptorSetsInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pBindDescriptorSetsInfo_loc.pNext(Struct::VkPipelineLayoutCreateInfo);

            if ((pNext->setLayoutCount > 0) && (pNext->pSetLayouts)) {
                for (uint32_t index2 = 0; index2 < pNext->setLayoutCount; ++index2) {
                    skip |= ValidateObject(pNext->pSetLayouts[index2], kVulkanObjectTypeDescriptorSetLayout, true,
                                           "VUID-VkPipelineLayoutCreateInfo-pSetLayouts-parameter", kVUIDUndefined,
                                           pNext_loc.dot(Field::pSetLayouts, index2));
                }
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdPushConstants2KHR(VkCommandBuffer commandBuffer,
                                                          const VkPushConstantsInfoKHR* pPushConstantsInfo,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pPushConstantsInfo) {
        [[maybe_unused]] const Location pPushConstantsInfo_loc = error_obj.location.dot(Field::pPushConstantsInfo);
        if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkPipelineLayoutCreateInfo>(pPushConstantsInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pPushConstantsInfo_loc.pNext(Struct::VkPipelineLayoutCreateInfo);

            if ((pNext->setLayoutCount > 0) && (pNext->pSetLayouts)) {
                for (uint32_t index2 = 0; index2 < pNext->setLayoutCount; ++index2) {
                    skip |= ValidateObject(pNext->pSetLayouts[index2], kVulkanObjectTypeDescriptorSetLayout, true,
                                           "VUID-VkPipelineLayoutCreateInfo-pSetLayouts-parameter", kVUIDUndefined,
                                           pNext_loc.dot(Field::pSetLayouts, index2));
                }
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo,
    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pPushDescriptorSetWithTemplateInfo) {
        [[maybe_unused]] const Location pPushDescriptorSetWithTemplateInfo_loc =
            error_obj.location.dot(Field::pPushDescriptorSetWithTemplateInfo);
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkPipelineLayoutCreateInfo>(pPushDescriptorSetWithTemplateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc =
                pPushDescriptorSetWithTemplateInfo_loc.pNext(Struct::VkPipelineLayoutCreateInfo);

            if ((pNext->setLayoutCount > 0) && (pNext->pSetLayouts)) {
                for (uint32_t index2 = 0; index2 < pNext->setLayoutCount; ++index2) {
                    skip |= ValidateObject(pNext->pSetLayouts[index2], kVulkanObjectTypeDescriptorSetLayout, true,
                                           "VUID-VkPipelineLayoutCreateInfo-pSetLayouts-parameter", kVUIDUndefined,
                                           pNext_loc.dot(Field::pSetLayouts, index2));
                }
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo,
    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pSetDescriptorBufferOffsetsInfo) {
        [[maybe_unused]] const Location pSetDescriptorBufferOffsetsInfo_loc =
            error_obj.location.dot(Field::pSetDescriptorBufferOffsetsInfo);
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkPipelineLayoutCreateInfo>(pSetDescriptorBufferOffsetsInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc =
                pSetDescriptorBufferOffsetsInfo_loc.pNext(Struct::VkPipelineLayoutCreateInfo);

            if ((pNext->setLayoutCount > 0) && (pNext->pSetLayouts)) {
                for (uint32_t index2 = 0; index2 < pNext->setLayoutCount; ++index2) {
                    skip |= ValidateObject(pNext->pSetLayouts[index2], kVulkanObjectTypeDescriptorSetLayout, true,
                                           "VUID-VkPipelineLayoutCreateInfo-pSetLayouts-parameter", kVUIDUndefined,
                                           pNext_loc.dot(Field::pSetLayouts, index2));
                }
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo,
    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pBindDescriptorBufferEmbeddedSamplersInfo) {
        [[maybe_unused]] const Location pBindDescriptorBufferEmbeddedSamplersInfo_loc =
            error_obj.location.dot(Field::pBindDescriptorBufferEmbeddedSamplersInfo);
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkPipelineLayoutCreateInfo>(pBindDescriptorBufferEmbeddedSamplersInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc =
                pBindDescriptorBufferEmbeddedSamplersInfo_loc.pNext(Struct::VkPipelineLayoutCreateInfo);

            if ((pNext->setLayoutCount > 0) && (pNext->pSetLayouts)) {
                for (uint32_t index2 = 0; index2 < pNext->setLayoutCount; ++index2) {
                    skip |= ValidateObject(pNext->pSetLayouts[index2], kVulkanObjectTypeDescriptorSetLayout, true,
                                           "VUID-VkPipelineLayoutCreateInfo-pSetLayouts-parameter", kVUIDUndefined,
                                           pNext_loc.dot(Field::pSetLayouts, index2));
                }
            }
        }
    }

    return skip;
}

// vkCreateDebugReportCallbackEXT:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateDebugReportCallbackEXT(VkInstance instance,
                                                                 const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
                                                                 const VkAllocationCallbacks* pAllocator,
                                                                 VkDebugReportCallbackEXT* pCallback,
                                                                 const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pCallback, kVulkanObjectTypeDebugReportCallbackEXT, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: instance: kVUIDUndefined
    skip |= ValidateDestroyObject(callback, kVulkanObjectTypeDebugReportCallbackEXT, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback,
                                                                 const VkAllocationCallbacks* pAllocator,
                                                                 const RecordObject& record_obj) {
    RecordDestroyObject(callback, kVulkanObjectTypeDebugReportCallbackEXT);
}

// vkDebugReportMessageEXT:
// Checked by chassis: instance: kVUIDUndefined

// vkCmdDebugMarkerBeginEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdDebugMarkerEndEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdDebugMarkerInsertEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                                        uint32_t bindingCount, const VkBuffer* pBuffers,
                                                                        const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    // Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdBindTransformFeedbackBuffersEXT-commonparent"

    if ((bindingCount > 0) && (pBuffers)) {
        for (uint32_t index0 = 0; index0 < bindingCount; ++index0) {
            skip |= ValidateObject(pBuffers[index0], kVulkanObjectTypeBuffer, false, kVUIDUndefined,
                                   "UNASSIGNED-vkCmdBindTransformFeedbackBuffersEXT-commonparent",
                                   error_obj.location.dot(Field::pBuffers, index0));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                                  uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                                                  const VkDeviceSize* pCounterBufferOffsets,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    // Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdBeginTransformFeedbackEXT-commonparent"

    if ((counterBufferCount > 0) && (pCounterBuffers)) {
        for (uint32_t index0 = 0; index0 < counterBufferCount; ++index0) {
            skip |= ValidateObject(pCounterBuffers[index0], kVulkanObjectTypeBuffer, true,
                                   "VUID-vkCmdBeginTransformFeedbackEXT-counterBufferCount-02607",
                                   "UNASSIGNED-vkCmdBeginTransformFeedbackEXT-commonparent",
                                   error_obj.location.dot(Field::pCounterBuffers, index0));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                                uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                                                const VkDeviceSize* pCounterBufferOffsets,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    // Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdEndTransformFeedbackEXT-commonparent"

    if ((counterBufferCount > 0) && (pCounterBuffers)) {
        for (uint32_t index0 = 0; index0 < counterBufferCount; ++index0) {
            skip |= ValidateObject(pCounterBuffers[index0], kVulkanObjectTypeBuffer, true,
                                   "VUID-vkCmdEndTransformFeedbackEXT-counterBufferCount-02608",
                                   "UNASSIGNED-vkCmdEndTransformFeedbackEXT-commonparent",
                                   error_obj.location.dot(Field::pCounterBuffers, index0));
        }
    }

    return skip;
}

// vkCmdBeginQueryIndexedEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdBeginQueryIndexedEXT-commonparent"

// vkCmdEndQueryIndexedEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdEndQueryIndexedEXT-commonparent"

// vkCmdDrawIndirectByteCountEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdDrawIndirectByteCountEXT-commonparent"

// vkCreateCuModuleNVX:
// Checked by chassis: device: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateCuModuleNVX(VkDevice device, const VkCuModuleCreateInfoNVX* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkCuModuleNVX* pModule,
                                                      const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pModule, kVulkanObjectTypeCuModuleNVX, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateCreateCuFunctionNVX(VkDevice device, const VkCuFunctionCreateInfoNVX* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator, VkCuFunctionNVX* pFunction,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pCreateInfo->module, kVulkanObjectTypeCuModuleNVX, false, kVUIDUndefined, kVUIDUndefined,
                               pCreateInfo_loc.dot(Field::module));
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateCuFunctionNVX(VkDevice device, const VkCuFunctionCreateInfoNVX* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkCuFunctionNVX* pFunction,
                                                        const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pFunction, kVulkanObjectTypeCuFunctionNVX, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyCuModuleNVX(VkDevice device, VkCuModuleNVX module,
                                                        const VkAllocationCallbacks* pAllocator,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |=
        ValidateDestroyObject(module, kVulkanObjectTypeCuModuleNVX, pAllocator, kVUIDUndefined, kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyCuModuleNVX(VkDevice device, VkCuModuleNVX module,
                                                      const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(module, kVulkanObjectTypeCuModuleNVX);
}

bool ObjectLifetimes::PreCallValidateDestroyCuFunctionNVX(VkDevice device, VkCuFunctionNVX function,
                                                          const VkAllocationCallbacks* pAllocator,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(function, kVulkanObjectTypeCuFunctionNVX, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyCuFunctionNVX(VkDevice device, VkCuFunctionNVX function,
                                                        const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(function, kVulkanObjectTypeCuFunctionNVX);
}

bool ObjectLifetimes::PreCallValidateCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pLaunchInfo) {
        [[maybe_unused]] const Location pLaunchInfo_loc = error_obj.location.dot(Field::pLaunchInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pLaunchInfo->function, kVulkanObjectTypeCuFunctionNVX, false, kVUIDUndefined, kVUIDUndefined,
                               pLaunchInfo_loc.dot(Field::function));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
    }

    return skip;
}

// vkGetImageViewAddressNVX:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                             VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                             uint32_t maxDrawCount, uint32_t stride,
                                                             const ErrorObject& error_obj) const {
    return PreCallValidateCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride,
                                               error_obj);
}

bool ObjectLifetimes::PreCallValidateCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                    VkDeviceSize offset, VkBuffer countBuffer,
                                                                    VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                                    uint32_t stride, const ErrorObject& error_obj) const {
    return PreCallValidateCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                                      stride, error_obj);
}

// vkGetShaderInfoAMD:
// Checked by chassis: device: kVUIDUndefined

#ifdef VK_USE_PLATFORM_GGP

// vkCreateStreamDescriptorSurfaceGGP:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateStreamDescriptorSurfaceGGP(VkInstance instance,
                                                                     const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo,
                                                                     const VkAllocationCallbacks* pAllocator,
                                                                     VkSurfaceKHR* pSurface, const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}
#endif  // VK_USE_PLATFORM_GGP

// vkGetPhysicalDeviceExternalImageFormatPropertiesNV:
// Checked by chassis: physicalDevice: kVUIDUndefined

#ifdef VK_USE_PLATFORM_WIN32_KHR

// vkGetMemoryWin32HandleNV:
// Checked by chassis: device: kVUIDUndefined

#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_VI_NN

// vkCreateViSurfaceNN:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateViSurfaceNN(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                      const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}
#endif  // VK_USE_PLATFORM_VI_NN

bool ObjectLifetimes::PreCallValidateCmdBeginConditionalRenderingEXT(
    VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin,
    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pConditionalRenderingBegin) {
        [[maybe_unused]] const Location pConditionalRenderingBegin_loc = error_obj.location.dot(Field::pConditionalRenderingBegin);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pConditionalRenderingBegin->buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined,
                               pConditionalRenderingBegin_loc.dot(Field::buffer));
    }

    return skip;
}

// vkCmdEndConditionalRenderingEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetViewportWScalingNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: "VUID-vkReleaseDisplayEXT-physicalDevice-parameter"
    skip |= ValidateObject(display, kVulkanObjectTypeDisplayKHR, false, "VUID-vkReleaseDisplayEXT-display-parameter",
                           "VUID-vkReleaseDisplayEXT-display-parent", error_obj.location.dot(Field::display),
                           kVulkanObjectTypePhysicalDevice);

    return skip;
}
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT

// vkAcquireXlibDisplayEXT:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkGetRandROutputDisplayEXT:
// Checked by chassis: physicalDevice: kVUIDUndefined

void ObjectLifetimes::PostCallRecordGetRandROutputDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput,
                                                             VkDisplayKHR* pDisplay, const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pDisplay, kVulkanObjectTypeDisplayKHR, nullptr, record_obj.location);
}
#endif  // VK_USE_PLATFORM_XLIB_XRANDR_EXT

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                              VkSurfaceCapabilities2EXT* pSurfaceCapabilities,
                                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSurfaceCapabilities2EXT-physicalDevice-parameter"
    // Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSurfaceCapabilities2EXT-commonparent"
    skip |= ValidateObject(surface, kVulkanObjectTypeSurfaceKHR, false,
                           "VUID-vkGetPhysicalDeviceSurfaceCapabilities2EXT-surface-parameter",
                           "VUID-vkGetPhysicalDeviceSurfaceCapabilities2EXT-commonparent", error_obj.location.dot(Field::surface),
                           kVulkanObjectTypeInstance);

    return skip;
}

bool ObjectLifetimes::PreCallValidateDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display,
                                                            const VkDisplayPowerInfoEXT* pDisplayPowerInfo,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkDisplayPowerControlEXT-device-parameter"
    // Checked by chassis: device: "VUID-vkDisplayPowerControlEXT-commonparent"
    auto instance_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    auto instance_object_lifetimes = instance_data->GetValidationObject<ObjectLifetimes>();
    skip |= instance_object_lifetimes->ValidateObject(
        display, kVulkanObjectTypeDisplayKHR, false, "VUID-vkDisplayPowerControlEXT-display-parameter",
        "VUID-vkDisplayPowerControlEXT-commonparent", error_obj.location.dot(Field::display), kVulkanObjectTypePhysicalDevice);

    return skip;
}

// vkRegisterDeviceEventEXT:
// Checked by chassis: device: "VUID-vkRegisterDeviceEventEXT-device-parameter"

void ObjectLifetimes::PostCallRecordRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo,
                                                           const VkAllocationCallbacks* pAllocator, VkFence* pFence,
                                                           const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pFence, kVulkanObjectTypeFence, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display,
                                                             const VkDisplayEventInfoEXT* pDisplayEventInfo,
                                                             const VkAllocationCallbacks* pAllocator, VkFence* pFence,
                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkRegisterDisplayEventEXT-device-parameter"
    // Checked by chassis: device: "VUID-vkRegisterDisplayEventEXT-commonparent"
    auto instance_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    auto instance_object_lifetimes = instance_data->GetValidationObject<ObjectLifetimes>();
    skip |= instance_object_lifetimes->ValidateObject(
        display, kVulkanObjectTypeDisplayKHR, false, "VUID-vkRegisterDisplayEventEXT-display-parameter",
        "VUID-vkRegisterDisplayEventEXT-commonparent", error_obj.location.dot(Field::display), kVulkanObjectTypePhysicalDevice);

    return skip;
}

void ObjectLifetimes::PostCallRecordRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display,
                                                            const VkDisplayEventInfoEXT* pDisplayEventInfo,
                                                            const VkAllocationCallbacks* pAllocator, VkFence* pFence,
                                                            const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pFence, kVulkanObjectTypeFence, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain,
                                                            VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetSwapchainCounterEXT-device-parameter"
    skip |= ValidateObject(swapchain, kVulkanObjectTypeSwapchainKHR, false, "VUID-vkGetSwapchainCounterEXT-swapchain-parameter",
                           "VUID-vkGetSwapchainCounterEXT-swapchain-parent", error_obj.location.dot(Field::swapchain));

    return skip;
}

// vkGetRefreshCycleDurationGOOGLE:
// Checked by chassis: device: kVUIDUndefined

// vkGetPastPresentationTimingGOOGLE:
// Checked by chassis: device: kVUIDUndefined

// vkCmdSetDiscardRectangleEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDiscardRectangleEXT-commandBuffer-parameter"

// vkCmdSetDiscardRectangleEnableEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDiscardRectangleEnableEXT-commandBuffer-parameter"

// vkCmdSetDiscardRectangleModeEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDiscardRectangleModeEXT-commandBuffer-parameter"

bool ObjectLifetimes::PreCallValidateSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains,
                                                       const VkHdrMetadataEXT* pMetadata, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkSetHdrMetadataEXT-device-parameter"

    if ((swapchainCount > 0) && (pSwapchains)) {
        for (uint32_t index0 = 0; index0 < swapchainCount; ++index0) {
            skip |= ValidateObject(pSwapchains[index0], kVulkanObjectTypeSwapchainKHR, false,
                                   "VUID-vkSetHdrMetadataEXT-pSwapchains-parameter", "VUID-vkSetHdrMetadataEXT-pSwapchains-parent",
                                   error_obj.location.dot(Field::pSwapchains, index0));
        }
    }

    return skip;
}
#ifdef VK_USE_PLATFORM_IOS_MVK

// vkCreateIOSSurfaceMVK:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateIOSSurfaceMVK(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                        const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}
#endif  // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK

// vkCreateMacOSSurfaceMVK:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateMacOSSurfaceMVK(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                          const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}
#endif  // VK_USE_PLATFORM_MACOS_MVK

// vkQueueBeginDebugUtilsLabelEXT:
// Checked by chassis: queue: "VUID-vkQueueBeginDebugUtilsLabelEXT-queue-parameter"

// vkQueueEndDebugUtilsLabelEXT:
// Checked by chassis: queue: "VUID-vkQueueEndDebugUtilsLabelEXT-queue-parameter"

// vkQueueInsertDebugUtilsLabelEXT:
// Checked by chassis: queue: "VUID-vkQueueInsertDebugUtilsLabelEXT-queue-parameter"

// vkCmdBeginDebugUtilsLabelEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdBeginDebugUtilsLabelEXT-commandBuffer-parameter"

// vkCmdEndDebugUtilsLabelEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdEndDebugUtilsLabelEXT-commandBuffer-parameter"

// vkCmdInsertDebugUtilsLabelEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdInsertDebugUtilsLabelEXT-commandBuffer-parameter"

// vkCreateDebugUtilsMessengerEXT:
// Checked by chassis: instance: "VUID-vkCreateDebugUtilsMessengerEXT-instance-parameter"

void ObjectLifetimes::PostCallRecordCreateDebugUtilsMessengerEXT(VkInstance instance,
                                                                 const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                                 const VkAllocationCallbacks* pAllocator,
                                                                 VkDebugUtilsMessengerEXT* pMessenger,
                                                                 const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pMessenger, kVulkanObjectTypeDebugUtilsMessengerEXT, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: instance: "VUID-vkDestroyDebugUtilsMessengerEXT-instance-parameter"
    skip |= ValidateObject(messenger, kVulkanObjectTypeDebugUtilsMessengerEXT, true,
                           "VUID-vkDestroyDebugUtilsMessengerEXT-messenger-parameter",
                           "VUID-vkDestroyDebugUtilsMessengerEXT-messenger-parent", error_obj.location.dot(Field::messenger),
                           kVulkanObjectTypeInstance);
    skip |= ValidateDestroyObject(messenger, kVulkanObjectTypeDebugUtilsMessengerEXT, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                                                 const VkAllocationCallbacks* pAllocator,
                                                                 const RecordObject& record_obj) {
    RecordDestroyObject(messenger, kVulkanObjectTypeDebugUtilsMessengerEXT);
}

// vkSubmitDebugUtilsMessageEXT:
// Checked by chassis: instance: "VUID-vkSubmitDebugUtilsMessageEXT-instance-parameter"

#ifdef VK_USE_PLATFORM_ANDROID_KHR

// vkGetAndroidHardwareBufferPropertiesANDROID:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateGetMemoryAndroidHardwareBufferANDROID(VkDevice device,
                                                                           const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo,
                                                                           struct AHardwareBuffer** pBuffer,
                                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::memory));
    }

    return skip;
}
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_ENABLE_BETA_EXTENSIONS

bool ObjectLifetimes::PreCallValidateCreateExecutionGraphPipelinesAMDX(VkDevice device, VkPipelineCache pipelineCache,
                                                                       uint32_t createInfoCount,
                                                                       const VkExecutionGraphPipelineCreateInfoAMDX* pCreateInfos,
                                                                       const VkAllocationCallbacks* pAllocator,
                                                                       VkPipeline* pPipelines, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfos) {
        for (uint32_t index0 = 0; index0 < createInfoCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pCreateInfos, index0);
            if (pCreateInfos[index0].pStages) {
                for (uint32_t index1 = 0; index1 < pCreateInfos[index0].stageCount; ++index1) {
                    [[maybe_unused]] const Location index1_loc = index0_loc.dot(Field::pStages, index1);
                    skip |= ValidateObject(pCreateInfos[index0].pStages[index1].module, kVulkanObjectTypeShaderModule, true,
                                           "VUID-VkPipelineShaderStageCreateInfo-module-parameter", kVUIDUndefined,
                                           index1_loc.dot(Field::module));
                    if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkShaderModuleValidationCacheCreateInfoEXT>(
                            pCreateInfos[index0].pStages[index1].pNext)) {
                        [[maybe_unused]] const Location pNext_loc =
                            index1_loc.pNext(Struct::VkShaderModuleValidationCacheCreateInfoEXT);
                        // There should be an explicit VU (if not that is a spec bug)
                        skip |= ValidateObject(pNext->validationCache, kVulkanObjectTypeValidationCacheEXT, false, kVUIDUndefined,
                                               kVUIDUndefined, pNext_loc.dot(Field::validationCache));
                    }
                }
            }
            if (pCreateInfos[index0].pLibraryInfo) {
                [[maybe_unused]] const Location pLibraryInfo_loc = index0_loc.dot(Field::pLibraryInfo);

                if ((pCreateInfos[index0].pLibraryInfo->libraryCount > 0) && (pCreateInfos[index0].pLibraryInfo->pLibraries)) {
                    for (uint32_t index2 = 0; index2 < pCreateInfos[index0].pLibraryInfo->libraryCount; ++index2) {
                        skip |=
                            ValidateObject(pCreateInfos[index0].pLibraryInfo->pLibraries[index2], kVulkanObjectTypePipeline, false,
                                           kVUIDUndefined, kVUIDUndefined, pLibraryInfo_loc.dot(Field::pLibraries, index2));
                    }
                }
            }
            if ((pCreateInfos[index0].flags & VK_PIPELINE_CREATE_DERIVATIVE_BIT) && (pCreateInfos[index0].basePipelineIndex == -1))
                skip |= ValidateObject(pCreateInfos[index0].basePipelineHandle, kVulkanObjectTypePipeline, false, kVUIDUndefined,
                                       "UNASSIGNED-VkExecutionGraphPipelineCreateInfoAMDX-commonparent", error_obj.location);
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateExecutionGraphPipelinesAMDX(VkDevice device, VkPipelineCache pipelineCache,
                                                                      uint32_t createInfoCount,
                                                                      const VkExecutionGraphPipelineCreateInfoAMDX* pCreateInfos,
                                                                      const VkAllocationCallbacks* pAllocator,
                                                                      VkPipeline* pPipelines, const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    if (pPipelines) {
        for (uint32_t index = 0; index < createInfoCount; index++) {
            CreateObject(pPipelines[index], kVulkanObjectTypePipeline, pAllocator,
                         record_obj.location.dot(Field::pPipelines, index));
        }
    }
}

// vkGetExecutionGraphPipelineScratchSizeAMDX:
// Checked by chassis: device: kVUIDUndefined

// vkGetExecutionGraphPipelineNodeIndexAMDX:
// Checked by chassis: device: kVUIDUndefined

// vkCmdInitializeGraphScratchMemoryAMDX:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdDispatchGraphAMDX:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdDispatchGraphIndirectAMDX:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdDispatchGraphIndirectCountAMDX:
// Checked by chassis: commandBuffer: kVUIDUndefined

#endif  // VK_ENABLE_BETA_EXTENSIONS

// vkCmdSetSampleLocationsEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetSampleLocationsEXT-commandBuffer-parameter"

// vkGetPhysicalDeviceMultisamplePropertiesEXT:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceMultisamplePropertiesEXT-physicalDevice-parameter"

bool ObjectLifetimes::PreCallValidateGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image,
                                                                            VkImageDrmFormatModifierPropertiesEXT* pProperties,
                                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetImageDrmFormatModifierPropertiesEXT-device-parameter"
    skip |= ValidateObject(image, kVulkanObjectTypeImage, false, "VUID-vkGetImageDrmFormatModifierPropertiesEXT-image-parameter",
                           "VUID-vkGetImageDrmFormatModifierPropertiesEXT-image-parent", error_obj.location.dot(Field::image));

    return skip;
}

// vkCreateValidationCacheEXT:
// Checked by chassis: device: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo,
                                                             const VkAllocationCallbacks* pAllocator,
                                                             VkValidationCacheEXT* pValidationCache,
                                                             const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pValidationCache, kVulkanObjectTypeValidationCacheEXT, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(validationCache, kVulkanObjectTypeValidationCacheEXT, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache,
                                                             const VkAllocationCallbacks* pAllocator,
                                                             const RecordObject& record_obj) {
    RecordDestroyObject(validationCache, kVulkanObjectTypeValidationCacheEXT);
}

bool ObjectLifetimes::PreCallValidateMergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache,
                                                              uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined

    if ((srcCacheCount > 0) && (pSrcCaches)) {
        for (uint32_t index0 = 0; index0 < srcCacheCount; ++index0) {
            skip |= ValidateObject(pSrcCaches[index0], kVulkanObjectTypeValidationCacheEXT, false, kVUIDUndefined,
                                   "UNASSIGNED-vkMergeValidationCachesEXT-pSrcCaches-parent",
                                   error_obj.location.dot(Field::pSrcCaches, index0));
        }
    }

    return skip;
}

// vkGetValidationCacheDataEXT:
// Checked by chassis: device: kVUIDUndefined

// vkCmdBindShadingRateImageNV:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdBindShadingRateImageNV-commonparent"

// vkCmdSetViewportShadingRatePaletteNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetCoarseSampleOrderNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateCreateAccelerationStructureNV(VkDevice device,
                                                                   const VkAccelerationStructureCreateInfoNV* pCreateInfo,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   VkAccelerationStructureNV* pAccelerationStructure,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        [[maybe_unused]] const Location info_loc = pCreateInfo_loc.dot(Field::info);
        if (pCreateInfo->info.pGeometries) {
            for (uint32_t index2 = 0; index2 < pCreateInfo->info.geometryCount; ++index2) {
                [[maybe_unused]] const Location index2_loc = info_loc.dot(Field::pGeometries, index2);
                [[maybe_unused]] const Location geometry_loc = index2_loc.dot(Field::geometry);
                [[maybe_unused]] const Location triangles_loc = geometry_loc.dot(Field::triangles);
                [[maybe_unused]] const Location aabbs_loc = geometry_loc.dot(Field::aabbs);
                // There should be an explicit VU (if not that is a spec bug)
                skip |= ValidateObject(pCreateInfo->info.pGeometries[index2].geometry.aabbs.aabbData, kVulkanObjectTypeBuffer, true,
                                       kVUIDUndefined, kVUIDUndefined, aabbs_loc.dot(Field::aabbData));
            }
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateAccelerationStructureNV(VkDevice device,
                                                                  const VkAccelerationStructureCreateInfoNV* pCreateInfo,
                                                                  const VkAllocationCallbacks* pAllocator,
                                                                  VkAccelerationStructureNV* pAccelerationStructure,
                                                                  const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pAccelerationStructure, kVulkanObjectTypeAccelerationStructureNV, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyAccelerationStructureNV(VkDevice device,
                                                                    VkAccelerationStructureNV accelerationStructure,
                                                                    const VkAllocationCallbacks* pAllocator,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(accelerationStructure, kVulkanObjectTypeAccelerationStructureNV, pAllocator, kVUIDUndefined,
                                  kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure,
                                                                  const VkAllocationCallbacks* pAllocator,
                                                                  const RecordObject& record_obj) {
    RecordDestroyObject(accelerationStructure, kVulkanObjectTypeAccelerationStructureNV);
}

bool ObjectLifetimes::PreCallValidateGetAccelerationStructureMemoryRequirementsNV(
    VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements,
    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->accelerationStructure, kVulkanObjectTypeAccelerationStructureNV, false, kVUIDUndefined,
                               kVUIDUndefined, pInfo_loc.dot(Field::accelerationStructure));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateBindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount,
                                                                       const VkBindAccelerationStructureMemoryInfoNV* pBindInfos,
                                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pBindInfos) {
        for (uint32_t index0 = 0; index0 < bindInfoCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pBindInfos, index0);
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdBuildAccelerationStructureNV(
    VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset,
    VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset,
    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    // Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdBuildAccelerationStructureNV-commonparent"
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        if (pInfo->pGeometries) {
            for (uint32_t index1 = 0; index1 < pInfo->geometryCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pInfo_loc.dot(Field::pGeometries, index1);
                [[maybe_unused]] const Location geometry_loc = index1_loc.dot(Field::geometry);
                [[maybe_unused]] const Location triangles_loc = geometry_loc.dot(Field::triangles);
                [[maybe_unused]] const Location aabbs_loc = geometry_loc.dot(Field::aabbs);
                // There should be an explicit VU (if not that is a spec bug)
                skip |= ValidateObject(pInfo->pGeometries[index1].geometry.aabbs.aabbData, kVulkanObjectTypeBuffer, true,
                                       kVUIDUndefined, kVUIDUndefined, aabbs_loc.dot(Field::aabbData));
            }
        }
    }

    return skip;
}

// vkCmdCopyAccelerationStructureNV:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdCopyAccelerationStructureNV-commonparent"

// vkCmdTraceRaysNV:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdTraceRaysNV-commonparent"

bool ObjectLifetimes::PreCallValidateCreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache,
                                                                 uint32_t createInfoCount,
                                                                 const VkRayTracingPipelineCreateInfoNV* pCreateInfos,
                                                                 const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfos) {
        for (uint32_t index0 = 0; index0 < createInfoCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pCreateInfos, index0);
            if (pCreateInfos[index0].pStages) {
                for (uint32_t index1 = 0; index1 < pCreateInfos[index0].stageCount; ++index1) {
                    [[maybe_unused]] const Location index1_loc = index0_loc.dot(Field::pStages, index1);
                    skip |= ValidateObject(pCreateInfos[index0].pStages[index1].module, kVulkanObjectTypeShaderModule, true,
                                           "VUID-VkPipelineShaderStageCreateInfo-module-parameter", kVUIDUndefined,
                                           index1_loc.dot(Field::module));
                    if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkShaderModuleValidationCacheCreateInfoEXT>(
                            pCreateInfos[index0].pStages[index1].pNext)) {
                        [[maybe_unused]] const Location pNext_loc =
                            index1_loc.pNext(Struct::VkShaderModuleValidationCacheCreateInfoEXT);
                        // There should be an explicit VU (if not that is a spec bug)
                        skip |= ValidateObject(pNext->validationCache, kVulkanObjectTypeValidationCacheEXT, false, kVUIDUndefined,
                                               kVUIDUndefined, pNext_loc.dot(Field::validationCache));
                    }
                }
            }
            if ((pCreateInfos[index0].flags & VK_PIPELINE_CREATE_DERIVATIVE_BIT) && (pCreateInfos[index0].basePipelineIndex == -1))
                skip |= ValidateObject(pCreateInfos[index0].basePipelineHandle, kVulkanObjectTypePipeline, false,
                                       "VUID-VkRayTracingPipelineCreateInfoNV-flags-07984",
                                       "UNASSIGNED-VkRayTracingPipelineCreateInfoNV-commonparent", error_obj.location);
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache,
                                                                uint32_t createInfoCount,
                                                                const VkRayTracingPipelineCreateInfoNV* pCreateInfos,
                                                                const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                                const RecordObject& record_obj) {
    if (VK_ERROR_VALIDATION_FAILED_EXT == record_obj.result) return;
    if (pPipelines) {
        for (uint32_t index = 0; index < createInfoCount; index++) {
            if (!pPipelines[index]) continue;
            CreateObject(pPipelines[index], kVulkanObjectTypePipeline, pAllocator,
                         record_obj.location.dot(Field::pPipelines, index));
        }
    }
}

// vkGetRayTracingShaderGroupHandlesKHR:
// Checked by chassis: device: kVUIDUndefined

// vkGetRayTracingShaderGroupHandlesNV:
// Checked by chassis: device: kVUIDUndefined

// vkGetAccelerationStructureHandleNV:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures,
    VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    // Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdWriteAccelerationStructuresPropertiesNV-commonparent"

    if ((accelerationStructureCount > 0) && (pAccelerationStructures)) {
        for (uint32_t index0 = 0; index0 < accelerationStructureCount; ++index0) {
            skip |= ValidateObject(pAccelerationStructures[index0], kVulkanObjectTypeAccelerationStructureNV, false, kVUIDUndefined,
                                   "UNASSIGNED-vkCmdWriteAccelerationStructuresPropertiesNV-commonparent",
                                   error_obj.location.dot(Field::pAccelerationStructures, index0));
        }
    }

    return skip;
}

// vkCompileDeferredNV:
// Checked by chassis: device: kVUIDUndefined

// vkGetMemoryHostPointerPropertiesEXT:
// Checked by chassis: device: "VUID-vkGetMemoryHostPointerPropertiesEXT-device-parameter"

// vkCmdWriteBufferMarkerAMD:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdWriteBufferMarkerAMD-commonparent"

// vkGetPhysicalDeviceCalibrateableTimeDomainsEXT:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkGetCalibratedTimestampsEXT:
// Checked by chassis: device: kVUIDUndefined

// vkCmdDrawMeshTasksNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdDrawMeshTasksIndirectNV:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdDrawMeshTasksIndirectNV-commonparent"

// vkCmdDrawMeshTasksIndirectCountNV:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdDrawMeshTasksIndirectCountNV-commonparent"

// vkCmdSetExclusiveScissorEnableNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetExclusiveScissorNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetCheckpointNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkGetQueueCheckpointDataNV:
// Checked by chassis: queue: kVUIDUndefined

// vkInitializePerformanceApiINTEL:
// Checked by chassis: device: kVUIDUndefined

// vkUninitializePerformanceApiINTEL:
// Checked by chassis: device: kVUIDUndefined

// vkCmdSetPerformanceMarkerINTEL:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetPerformanceStreamMarkerINTEL:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetPerformanceOverrideINTEL:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkAcquirePerformanceConfigurationINTEL:
// Checked by chassis: device: kVUIDUndefined

void ObjectLifetimes::PostCallRecordAcquirePerformanceConfigurationINTEL(
    VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo,
    VkPerformanceConfigurationINTEL* pConfiguration, const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pConfiguration, kVulkanObjectTypePerformanceConfigurationINTEL, nullptr, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateReleasePerformanceConfigurationINTEL(VkDevice device,
                                                                          VkPerformanceConfigurationINTEL configuration,
                                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(configuration, kVulkanObjectTypePerformanceConfigurationINTEL, nullptr, kVUIDUndefined,
                                  kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordReleasePerformanceConfigurationINTEL(VkDevice device,
                                                                        VkPerformanceConfigurationINTEL configuration,
                                                                        const RecordObject& record_obj) {
    RecordDestroyObject(configuration, kVulkanObjectTypePerformanceConfigurationINTEL);
}

// vkQueueSetPerformanceConfigurationINTEL:
// Checked by chassis: queue: kVUIDUndefined
// Checked by chassis: queue: "UNASSIGNED-vkQueueSetPerformanceConfigurationINTEL-commonparent"

// vkGetPerformanceParameterINTEL:
// Checked by chassis: device: kVUIDUndefined

// vkSetLocalDimmingAMD:
// Checked by chassis: device: kVUIDUndefined

#ifdef VK_USE_PLATFORM_FUCHSIA

// vkCreateImagePipeSurfaceFUCHSIA:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateImagePipeSurfaceFUCHSIA(VkInstance instance,
                                                                  const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo,
                                                                  const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                                  const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_METAL_EXT

// vkCreateMetalSurfaceEXT:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                          const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}
#endif  // VK_USE_PLATFORM_METAL_EXT

bool ObjectLifetimes::PreCallValidateGetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo* pInfo,
                                                               const ErrorObject& error_obj) const {
    return PreCallValidateGetBufferDeviceAddress(device, pInfo, error_obj);
}

// vkGetPhysicalDeviceToolPropertiesEXT:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkGetPhysicalDeviceCooperativeMatrixPropertiesNV:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV:
// Checked by chassis: physicalDevice: kVUIDUndefined

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ObjectLifetimes::PreCallValidateGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice,
                                                                              const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                              uint32_t* pPresentModeCount,
                                                                              VkPresentModeKHR* pPresentModes,
                                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: physicalDevice: kVUIDUndefined
    if (pSurfaceInfo) {
        [[maybe_unused]] const Location pSurfaceInfo_loc = error_obj.location.dot(Field::pSurfaceInfo);
        skip |= ValidateObject(pSurfaceInfo->surface, kVulkanObjectTypeSurfaceKHR, true,
                               "VUID-VkPhysicalDeviceSurfaceInfo2KHR-surface-parameter", kVUIDUndefined,
                               pSurfaceInfo_loc.dot(Field::surface));
    }

    return skip;
}

// vkAcquireFullScreenExclusiveModeEXT:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain,
                                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    // There should be an explicit VU (if not that is a spec bug)
    skip |= ValidateObject(swapchain, kVulkanObjectTypeSwapchainKHR, false, kVUIDUndefined, kVUIDUndefined,
                           error_obj.location.dot(Field::swapchain));

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetDeviceGroupSurfacePresentModes2EXT(VkDevice device,
                                                                           const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                           VkDeviceGroupPresentModeFlagsKHR* pModes,
                                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pSurfaceInfo) {
        [[maybe_unused]] const Location pSurfaceInfo_loc = error_obj.location.dot(Field::pSurfaceInfo);
        auto instance_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
        auto instance_object_lifetimes = instance_data->GetValidationObject<ObjectLifetimes>();
        skip |= instance_object_lifetimes->ValidateObject(pSurfaceInfo->surface, kVulkanObjectTypeSurfaceKHR, true,
                                                          "VUID-VkPhysicalDeviceSurfaceInfo2KHR-surface-parameter", kVUIDUndefined,
                                                          pSurfaceInfo_loc.dot(Field::surface));
    }

    return skip;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR

// vkCreateHeadlessSurfaceEXT:
// Checked by chassis: instance: "VUID-vkCreateHeadlessSurfaceEXT-instance-parameter"

void ObjectLifetimes::PostCallRecordCreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo,
                                                             const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                             const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}

// vkCmdSetLineStippleEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                                       uint32_t queryCount, const ErrorObject& error_obj) const {
    return PreCallValidateResetQueryPool(device, queryPool, firstQuery, queryCount, error_obj);
}

// vkCmdSetCullModeEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetCullMode-commandBuffer-parameter"

// vkCmdSetFrontFaceEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetFrontFace-commandBuffer-parameter"

// vkCmdSetPrimitiveTopologyEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetPrimitiveTopology-commandBuffer-parameter"

// vkCmdSetViewportWithCountEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetViewportWithCount-commandBuffer-parameter"

// vkCmdSetScissorWithCountEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetScissorWithCount-commandBuffer-parameter"

bool ObjectLifetimes::PreCallValidateCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                              uint32_t bindingCount, const VkBuffer* pBuffers,
                                                              const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                              const VkDeviceSize* pStrides, const ErrorObject& error_obj) const {
    return PreCallValidateCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides,
                                                error_obj);
}

// vkCmdSetDepthTestEnableEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDepthTestEnable-commandBuffer-parameter"

// vkCmdSetDepthWriteEnableEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDepthWriteEnable-commandBuffer-parameter"

// vkCmdSetDepthCompareOpEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDepthCompareOp-commandBuffer-parameter"

// vkCmdSetDepthBoundsTestEnableEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDepthBoundsTestEnable-commandBuffer-parameter"

// vkCmdSetStencilTestEnableEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetStencilTestEnable-commandBuffer-parameter"

// vkCmdSetStencilOpEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetStencilOp-commandBuffer-parameter"

bool ObjectLifetimes::PreCallValidateCopyMemoryToImageEXT(VkDevice device, const VkCopyMemoryToImageInfoEXT* pCopyMemoryToImageInfo,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCopyMemoryToImageInfo) {
        [[maybe_unused]] const Location pCopyMemoryToImageInfo_loc = error_obj.location.dot(Field::pCopyMemoryToImageInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pCopyMemoryToImageInfo->dstImage, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined,
                               pCopyMemoryToImageInfo_loc.dot(Field::dstImage));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCopyImageToMemoryEXT(VkDevice device, const VkCopyImageToMemoryInfoEXT* pCopyImageToMemoryInfo,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCopyImageToMemoryInfo) {
        [[maybe_unused]] const Location pCopyImageToMemoryInfo_loc = error_obj.location.dot(Field::pCopyImageToMemoryInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pCopyImageToMemoryInfo->srcImage, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined,
                               pCopyImageToMemoryInfo_loc.dot(Field::srcImage));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCopyImageToImageEXT(VkDevice device, const VkCopyImageToImageInfoEXT* pCopyImageToImageInfo,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCopyImageToImageInfo) {
        [[maybe_unused]] const Location pCopyImageToImageInfo_loc = error_obj.location.dot(Field::pCopyImageToImageInfo);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateTransitionImageLayoutEXT(VkDevice device, uint32_t transitionCount,
                                                              const VkHostImageLayoutTransitionInfoEXT* pTransitions,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pTransitions) {
        for (uint32_t index0 = 0; index0 < transitionCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pTransitions, index0);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pTransitions[index0].image, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined,
                                   index0_loc.dot(Field::image));
        }
    }

    return skip;
}

// vkGetImageSubresourceLayout2EXT:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateReleaseSwapchainImagesEXT(VkDevice device, const VkReleaseSwapchainImagesInfoEXT* pReleaseInfo,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pReleaseInfo) {
        [[maybe_unused]] const Location pReleaseInfo_loc = error_obj.location.dot(Field::pReleaseInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pReleaseInfo->swapchain, kVulkanObjectTypeSwapchainKHR, false, kVUIDUndefined, kVUIDUndefined,
                               pReleaseInfo_loc.dot(Field::swapchain));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetGeneratedCommandsMemoryRequirementsNV(
    VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements,
    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                                                      const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo,
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pGeneratedCommandsInfo) {
        [[maybe_unused]] const Location pGeneratedCommandsInfo_loc = error_obj.location.dot(Field::pGeneratedCommandsInfo);
        if (pGeneratedCommandsInfo->pStreams) {
            for (uint32_t index1 = 0; index1 < pGeneratedCommandsInfo->streamCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pGeneratedCommandsInfo_loc.dot(Field::pStreams, index1);
                // There should be an explicit VU (if not that is a spec bug)
                skip |= ValidateObject(pGeneratedCommandsInfo->pStreams[index1].buffer, kVulkanObjectTypeBuffer, false,
                                       kVUIDUndefined, kVUIDUndefined, index1_loc.dot(Field::buffer));
            }
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                                   const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pGeneratedCommandsInfo) {
        [[maybe_unused]] const Location pGeneratedCommandsInfo_loc = error_obj.location.dot(Field::pGeneratedCommandsInfo);
        if (pGeneratedCommandsInfo->pStreams) {
            for (uint32_t index1 = 0; index1 < pGeneratedCommandsInfo->streamCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pGeneratedCommandsInfo_loc.dot(Field::pStreams, index1);
                // There should be an explicit VU (if not that is a spec bug)
                skip |= ValidateObject(pGeneratedCommandsInfo->pStreams[index1].buffer, kVulkanObjectTypeBuffer, false,
                                       kVUIDUndefined, kVUIDUndefined, index1_loc.dot(Field::buffer));
            }
        }
    }

    return skip;
}

// vkCmdBindPipelineShaderGroupNV:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdBindPipelineShaderGroupNV-commonparent"

bool ObjectLifetimes::PreCallValidateCreateIndirectCommandsLayoutNV(VkDevice device,
                                                                    const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo,
                                                                    const VkAllocationCallbacks* pAllocator,
                                                                    VkIndirectCommandsLayoutNV* pIndirectCommandsLayout,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        if (pCreateInfo->pTokens) {
            for (uint32_t index1 = 0; index1 < pCreateInfo->tokenCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pCreateInfo_loc.dot(Field::pTokens, index1);
                // There should be an explicit VU (if not that is a spec bug)
                skip |= ValidateObject(pCreateInfo->pTokens[index1].pushconstantPipelineLayout, kVulkanObjectTypePipelineLayout,
                                       true, kVUIDUndefined, kVUIDUndefined, index1_loc.dot(Field::pushconstantPipelineLayout));
            }
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateIndirectCommandsLayoutNV(VkDevice device,
                                                                   const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   VkIndirectCommandsLayoutNV* pIndirectCommandsLayout,
                                                                   const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pIndirectCommandsLayout, kVulkanObjectTypeIndirectCommandsLayoutNV, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyIndirectCommandsLayoutNV(VkDevice device,
                                                                     VkIndirectCommandsLayoutNV indirectCommandsLayout,
                                                                     const VkAllocationCallbacks* pAllocator,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(indirectCommandsLayout, kVulkanObjectTypeIndirectCommandsLayoutNV, pAllocator, kVUIDUndefined,
                                  kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyIndirectCommandsLayoutNV(VkDevice device,
                                                                   VkIndirectCommandsLayoutNV indirectCommandsLayout,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   const RecordObject& record_obj) {
    RecordDestroyObject(indirectCommandsLayout, kVulkanObjectTypeIndirectCommandsLayoutNV);
}

// vkCmdSetDepthBias2EXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkAcquireDrmDisplayEXT:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkGetDrmDisplayEXT:
// Checked by chassis: physicalDevice: kVUIDUndefined

void ObjectLifetimes::PostCallRecordGetDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId,
                                                     VkDisplayKHR* display, const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*display, kVulkanObjectTypeDisplayKHR, nullptr, record_obj.location);
}

// vkCreatePrivateDataSlotEXT:
// Checked by chassis: device: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo,
                                                             const VkAllocationCallbacks* pAllocator,
                                                             VkPrivateDataSlot* pPrivateDataSlot, const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pPrivateDataSlot, kVulkanObjectTypePrivateDataSlot, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               const ErrorObject& error_obj) const {
    return PreCallValidateDestroyPrivateDataSlot(device, privateDataSlot, pAllocator, error_obj);
}

void ObjectLifetimes::PreCallRecordDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                             const VkAllocationCallbacks* pAllocator,
                                                             const RecordObject& record_obj) {
    RecordDestroyObject(privateDataSlot, kVulkanObjectTypePrivateDataSlot);
}

// vkSetPrivateDataEXT:
// Checked by chassis: device: kVUIDUndefined

// vkGetPrivateDataEXT:
// Checked by chassis: device: kVUIDUndefined

// vkCreateCudaModuleNV:
// Checked by chassis: device: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateCudaModuleNV(VkDevice device, const VkCudaModuleCreateInfoNV* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkCudaModuleNV* pModule,
                                                       const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pModule, kVulkanObjectTypeCudaModuleNV, pAllocator, record_obj.location);
}

// vkGetCudaModuleCacheNV:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateCreateCudaFunctionNV(VkDevice device, const VkCudaFunctionCreateInfoNV* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator, VkCudaFunctionNV* pFunction,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateCudaFunctionNV(VkDevice device, const VkCudaFunctionCreateInfoNV* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator, VkCudaFunctionNV* pFunction,
                                                         const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pFunction, kVulkanObjectTypeCudaFunctionNV, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyCudaModuleNV(VkDevice device, VkCudaModuleNV module,
                                                         const VkAllocationCallbacks* pAllocator,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(module, kVulkanObjectTypeCudaModuleNV, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyCudaModuleNV(VkDevice device, VkCudaModuleNV module,
                                                       const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(module, kVulkanObjectTypeCudaModuleNV);
}

bool ObjectLifetimes::PreCallValidateDestroyCudaFunctionNV(VkDevice device, VkCudaFunctionNV function,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(function, kVulkanObjectTypeCudaFunctionNV, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyCudaFunctionNV(VkDevice device, VkCudaFunctionNV function,
                                                         const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(function, kVulkanObjectTypeCudaFunctionNV);
}

bool ObjectLifetimes::PreCallValidateCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pLaunchInfo) {
        [[maybe_unused]] const Location pLaunchInfo_loc = error_obj.location.dot(Field::pLaunchInfo);
    }

    return skip;
}

// vkGetDescriptorSetLayoutSizeEXT:
// Checked by chassis: device: kVUIDUndefined

// vkGetDescriptorSetLayoutBindingOffsetEXT:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                                                 const VkDescriptorBufferBindingInfoEXT* pBindingInfos,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pBindingInfos) {
        for (uint32_t index0 = 0; index0 < bufferCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pBindingInfos, index0);
            if ([[maybe_unused]] auto pNext = vku::FindStructInPNextChain<VkDescriptorBufferBindingPushDescriptorBufferHandleEXT>(
                    pBindingInfos[index0].pNext)) {
                [[maybe_unused]] const Location pNext_loc =
                    index0_loc.pNext(Struct::VkDescriptorBufferBindingPushDescriptorBufferHandleEXT);
                // There should be an explicit VU (if not that is a spec bug)
                skip |= ValidateObject(pNext->buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined,
                                       pNext_loc.dot(Field::buffer));
            }
        }
    }

    return skip;
}

// vkCmdSetDescriptorBufferOffsetsEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdSetDescriptorBufferOffsetsEXT-commonparent"

// vkCmdBindDescriptorBufferEmbeddedSamplersEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdBindDescriptorBufferEmbeddedSamplersEXT-commonparent"

bool ObjectLifetimes::PreCallValidateGetBufferOpaqueCaptureDescriptorDataEXT(VkDevice device,
                                                                             const VkBufferCaptureDescriptorDataInfoEXT* pInfo,
                                                                             void* pData, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::buffer));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageOpaqueCaptureDescriptorDataEXT(VkDevice device,
                                                                            const VkImageCaptureDescriptorDataInfoEXT* pInfo,
                                                                            void* pData, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->image, kVulkanObjectTypeImage, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::image));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetImageViewOpaqueCaptureDescriptorDataEXT(
    VkDevice device, const VkImageViewCaptureDescriptorDataInfoEXT* pInfo, void* pData, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->imageView, kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::imageView));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetSamplerOpaqueCaptureDescriptorDataEXT(VkDevice device,
                                                                              const VkSamplerCaptureDescriptorDataInfoEXT* pInfo,
                                                                              void* pData, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->sampler, kVulkanObjectTypeSampler, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::sampler));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(
    VkDevice device, const VkAccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData,
    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
    }

    return skip;
}

// vkCmdSetFragmentShadingRateEnumNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkGetDeviceFaultInfoEXT:
// Checked by chassis: device: kVUIDUndefined

#ifdef VK_USE_PLATFORM_WIN32_KHR

// vkAcquireWinrtDisplayNV:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkGetWinrtDisplayNV:
// Checked by chassis: physicalDevice: kVUIDUndefined

void ObjectLifetimes::PostCallRecordGetWinrtDisplayNV(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId,
                                                      VkDisplayKHR* pDisplay, const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pDisplay, kVulkanObjectTypeDisplayKHR, nullptr, record_obj.location);
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT

// vkCreateDirectFBSurfaceEXT:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateDirectFBSurfaceEXT(VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo,
                                                             const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                             const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}

// vkGetPhysicalDeviceDirectFBPresentationSupportEXT:
// Checked by chassis: physicalDevice: kVUIDUndefined

#endif  // VK_USE_PLATFORM_DIRECTFB_EXT

// vkCmdSetVertexInputEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetVertexInputEXT-commandBuffer-parameter"

#ifdef VK_USE_PLATFORM_FUCHSIA

bool ObjectLifetimes::PreCallValidateGetMemoryZirconHandleFUCHSIA(VkDevice device,
                                                                  const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo,
                                                                  zx_handle_t* pZirconHandle, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pGetZirconHandleInfo) {
        [[maybe_unused]] const Location pGetZirconHandleInfo_loc = error_obj.location.dot(Field::pGetZirconHandleInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pGetZirconHandleInfo->memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined, kVUIDUndefined,
                               pGetZirconHandleInfo_loc.dot(Field::memory));
    }

    return skip;
}

// vkGetMemoryZirconHandlePropertiesFUCHSIA:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateImportSemaphoreZirconHandleFUCHSIA(
    VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo,
    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pImportSemaphoreZirconHandleInfo) {
        [[maybe_unused]] const Location pImportSemaphoreZirconHandleInfo_loc =
            error_obj.location.dot(Field::pImportSemaphoreZirconHandleInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pImportSemaphoreZirconHandleInfo->semaphore, kVulkanObjectTypeSemaphore, false, kVUIDUndefined,
                               kVUIDUndefined, pImportSemaphoreZirconHandleInfo_loc.dot(Field::semaphore));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetSemaphoreZirconHandleFUCHSIA(
    VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle,
    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pGetZirconHandleInfo) {
        [[maybe_unused]] const Location pGetZirconHandleInfo_loc = error_obj.location.dot(Field::pGetZirconHandleInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pGetZirconHandleInfo->semaphore, kVulkanObjectTypeSemaphore, false, kVUIDUndefined, kVUIDUndefined,
                               pGetZirconHandleInfo_loc.dot(Field::semaphore));
    }

    return skip;
}

// vkCreateBufferCollectionFUCHSIA:
// Checked by chassis: device: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateBufferCollectionFUCHSIA(VkDevice device,
                                                                  const VkBufferCollectionCreateInfoFUCHSIA* pCreateInfo,
                                                                  const VkAllocationCallbacks* pAllocator,
                                                                  VkBufferCollectionFUCHSIA* pCollection,
                                                                  const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pCollection, kVulkanObjectTypeBufferCollectionFUCHSIA, pAllocator, record_obj.location);
}

// vkSetBufferCollectionImageConstraintsFUCHSIA:
// Checked by chassis: device: kVUIDUndefined

// vkSetBufferCollectionBufferConstraintsFUCHSIA:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateDestroyBufferCollectionFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection,
                                                                    const VkAllocationCallbacks* pAllocator,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(collection, kVulkanObjectTypeBufferCollectionFUCHSIA, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyBufferCollectionFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection,
                                                                  const VkAllocationCallbacks* pAllocator,
                                                                  const RecordObject& record_obj) {
    RecordDestroyObject(collection, kVulkanObjectTypeBufferCollectionFUCHSIA);
}

// vkGetBufferCollectionPropertiesFUCHSIA:
// Checked by chassis: device: kVUIDUndefined

#endif  // VK_USE_PLATFORM_FUCHSIA

// vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI:
// Checked by chassis: device: kVUIDUndefined

// vkCmdSubpassShadingHUAWEI:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdBindInvocationMaskHUAWEI:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdBindInvocationMaskHUAWEI-commonparent"

bool ObjectLifetimes::PreCallValidateGetMemoryRemoteAddressNV(VkDevice device,
                                                              const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo,
                                                              VkRemoteAddressNV* pAddress, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pMemoryGetRemoteAddressInfo) {
        [[maybe_unused]] const Location pMemoryGetRemoteAddressInfo_loc =
            error_obj.location.dot(Field::pMemoryGetRemoteAddressInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pMemoryGetRemoteAddressInfo->memory, kVulkanObjectTypeDeviceMemory, false, kVUIDUndefined,
                               kVUIDUndefined, pMemoryGetRemoteAddressInfo_loc.dot(Field::memory));
    }

    return skip;
}

// vkGetPipelinePropertiesEXT:
// Checked by chassis: device: kVUIDUndefined

#ifdef VK_USE_PLATFORM_SCI

bool ObjectLifetimes::PreCallValidateGetFenceSciSyncFenceNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo,
                                                            void* pHandle, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetFenceSciSyncFenceNV-device-parameter"
    if (pGetSciSyncHandleInfo) {
        [[maybe_unused]] const Location pGetSciSyncHandleInfo_loc = error_obj.location.dot(Field::pGetSciSyncHandleInfo);
        skip |= ValidateObject(pGetSciSyncHandleInfo->fence, kVulkanObjectTypeFence, false,
                               "VUID-VkFenceGetSciSyncInfoNV-fence-parameter", "UNASSIGNED-VkFenceGetSciSyncInfoNV-fence-parent",
                               pGetSciSyncHandleInfo_loc.dot(Field::fence));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetFenceSciSyncObjNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo,
                                                          void* pHandle, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetFenceSciSyncObjNV-device-parameter"
    if (pGetSciSyncHandleInfo) {
        [[maybe_unused]] const Location pGetSciSyncHandleInfo_loc = error_obj.location.dot(Field::pGetSciSyncHandleInfo);
        skip |= ValidateObject(pGetSciSyncHandleInfo->fence, kVulkanObjectTypeFence, false,
                               "VUID-VkFenceGetSciSyncInfoNV-fence-parameter", "UNASSIGNED-VkFenceGetSciSyncInfoNV-fence-parent",
                               pGetSciSyncHandleInfo_loc.dot(Field::fence));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateImportFenceSciSyncFenceNV(VkDevice device,
                                                               const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkImportFenceSciSyncFenceNV-device-parameter"
    if (pImportFenceSciSyncInfo) {
        [[maybe_unused]] const Location pImportFenceSciSyncInfo_loc = error_obj.location.dot(Field::pImportFenceSciSyncInfo);
        skip |= ValidateObject(pImportFenceSciSyncInfo->fence, kVulkanObjectTypeFence, false,
                               "VUID-VkImportFenceSciSyncInfoNV-fence-parameter",
                               "UNASSIGNED-VkImportFenceSciSyncInfoNV-fence-parent", pImportFenceSciSyncInfo_loc.dot(Field::fence));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateImportFenceSciSyncObjNV(VkDevice device,
                                                             const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo,
                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkImportFenceSciSyncObjNV-device-parameter"
    if (pImportFenceSciSyncInfo) {
        [[maybe_unused]] const Location pImportFenceSciSyncInfo_loc = error_obj.location.dot(Field::pImportFenceSciSyncInfo);
        skip |= ValidateObject(pImportFenceSciSyncInfo->fence, kVulkanObjectTypeFence, false,
                               "VUID-VkImportFenceSciSyncInfoNV-fence-parameter",
                               "UNASSIGNED-VkImportFenceSciSyncInfoNV-fence-parent", pImportFenceSciSyncInfo_loc.dot(Field::fence));
    }

    return skip;
}

// vkGetPhysicalDeviceSciSyncAttributesNV:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSciSyncAttributesNV-physicalDevice-parameter"

bool ObjectLifetimes::PreCallValidateGetSemaphoreSciSyncObjNV(VkDevice device, const VkSemaphoreGetSciSyncInfoNV* pGetSciSyncInfo,
                                                              void* pHandle, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetSemaphoreSciSyncObjNV-device-parameter"
    if (pGetSciSyncInfo) {
        [[maybe_unused]] const Location pGetSciSyncInfo_loc = error_obj.location.dot(Field::pGetSciSyncInfo);
        skip |= ValidateObject(
            pGetSciSyncInfo->semaphore, kVulkanObjectTypeSemaphore, false, "VUID-VkSemaphoreGetSciSyncInfoNV-semaphore-parameter",
            "UNASSIGNED-VkSemaphoreGetSciSyncInfoNV-semaphore-parent", pGetSciSyncInfo_loc.dot(Field::semaphore));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateImportSemaphoreSciSyncObjNV(VkDevice device,
                                                                 const VkImportSemaphoreSciSyncInfoNV* pImportSemaphoreSciSyncInfo,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkImportSemaphoreSciSyncObjNV-device-parameter"
    if (pImportSemaphoreSciSyncInfo) {
        [[maybe_unused]] const Location pImportSemaphoreSciSyncInfo_loc =
            error_obj.location.dot(Field::pImportSemaphoreSciSyncInfo);
        skip |= ValidateObject(pImportSemaphoreSciSyncInfo->semaphore, kVulkanObjectTypeSemaphore, false,
                               "VUID-VkImportSemaphoreSciSyncInfoNV-semaphore-parameter",
                               "UNASSIGNED-VkImportSemaphoreSciSyncInfoNV-semaphore-parent",
                               pImportSemaphoreSciSyncInfo_loc.dot(Field::semaphore));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetMemorySciBufNV(VkDevice device, const VkMemoryGetSciBufInfoNV* pGetSciBufInfo,
                                                       NvSciBufObj* pHandle, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: "VUID-vkGetMemorySciBufNV-device-parameter"
    if (pGetSciBufInfo) {
        [[maybe_unused]] const Location pGetSciBufInfo_loc = error_obj.location.dot(Field::pGetSciBufInfo);
        skip |= ValidateObject(pGetSciBufInfo->memory, kVulkanObjectTypeDeviceMemory, false,
                               "VUID-VkMemoryGetSciBufInfoNV-memory-parameter", "UNASSIGNED-VkMemoryGetSciBufInfoNV-memory-parent",
                               pGetSciBufInfo_loc.dot(Field::memory));
    }

    return skip;
}

// vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV-physicalDevice-parameter"

// vkGetPhysicalDeviceSciBufAttributesNV:
// Checked by chassis: physicalDevice: "VUID-vkGetPhysicalDeviceSciBufAttributesNV-physicalDevice-parameter"

#endif  // VK_USE_PLATFORM_SCI

// vkCmdSetPatchControlPointsEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetPatchControlPointsEXT-commandBuffer-parameter"

// vkCmdSetRasterizerDiscardEnableEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetRasterizerDiscardEnable-commandBuffer-parameter"

// vkCmdSetDepthBiasEnableEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetDepthBiasEnable-commandBuffer-parameter"

// vkCmdSetLogicOpEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetLogicOpEXT-commandBuffer-parameter"

// vkCmdSetPrimitiveRestartEnableEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetPrimitiveRestartEnable-commandBuffer-parameter"

#ifdef VK_USE_PLATFORM_SCREEN_QNX

// vkCreateScreenSurfaceQNX:
// Checked by chassis: instance: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateScreenSurfaceQNX(VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                           const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSurface, kVulkanObjectTypeSurfaceKHR, pAllocator, record_obj.location);
}

// vkGetPhysicalDeviceScreenPresentationSupportQNX:
// Checked by chassis: physicalDevice: kVUIDUndefined

#endif  // VK_USE_PLATFORM_SCREEN_QNX

// vkCmdSetColorWriteEnableEXT:
// Checked by chassis: commandBuffer: "VUID-vkCmdSetColorWriteEnableEXT-commandBuffer-parameter"

// vkCmdDrawMultiEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdDrawMultiIndexedEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateCreateMicromapEXT(VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pCreateInfo->buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined,
                               pCreateInfo_loc.dot(Field::buffer));
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateMicromapEXT(VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap,
                                                      const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pMicromap, kVulkanObjectTypeMicromapEXT, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyMicromapEXT(VkDevice device, VkMicromapEXT micromap,
                                                        const VkAllocationCallbacks* pAllocator,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(micromap, kVulkanObjectTypeMicromapEXT, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyMicromapEXT(VkDevice device, VkMicromapEXT micromap,
                                                      const VkAllocationCallbacks* pAllocator, const RecordObject& record_obj) {
    RecordDestroyObject(micromap, kVulkanObjectTypeMicromapEXT);
}

bool ObjectLifetimes::PreCallValidateCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                          const VkMicromapBuildInfoEXT* pInfos,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pInfos) {
        for (uint32_t index0 = 0; index0 < infoCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pInfos, index0);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pInfos[index0].dstMicromap, kVulkanObjectTypeMicromapEXT, true, kVUIDUndefined, kVUIDUndefined,
                                   index0_loc.dot(Field::dstMicromap));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateBuildMicromapsEXT(VkDevice device, VkDeferredOperationKHR deferredOperation,
                                                       uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfos) {
        for (uint32_t index0 = 0; index0 < infoCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pInfos, index0);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pInfos[index0].dstMicromap, kVulkanObjectTypeMicromapEXT, true, kVUIDUndefined, kVUIDUndefined,
                                   index0_loc.dot(Field::dstMicromap));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCopyMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation,
                                                     const VkCopyMicromapInfoEXT* pInfo, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCopyMicromapToMemoryEXT(VkDevice device, VkDeferredOperationKHR deferredOperation,
                                                             const VkCopyMicromapToMemoryInfoEXT* pInfo,
                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->src, kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::src));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCopyMemoryToMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation,
                                                             const VkCopyMemoryToMicromapInfoEXT* pInfo,
                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->dst, kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::dst));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateWriteMicromapsPropertiesEXT(VkDevice device, uint32_t micromapCount,
                                                                 const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                                                 size_t dataSize, void* pData, size_t stride,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined

    if ((micromapCount > 0) && (pMicromaps)) {
        for (uint32_t index0 = 0; index0 < micromapCount; ++index0) {
            skip |= ValidateObject(pMicromaps[index0], kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined,
                                   "UNASSIGNED-vkWriteMicromapsPropertiesEXT-pMicromaps-parent",
                                   error_obj.location.dot(Field::pMicromaps, index0));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer,
                                                                const VkCopyMicromapToMemoryInfoEXT* pInfo,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->src, kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::src));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer,
                                                                const VkCopyMemoryToMicromapInfoEXT* pInfo,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->dst, kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::dst));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                                                    const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                                                    VkQueryPool queryPool, uint32_t firstQuery,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    // Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdWriteMicromapsPropertiesEXT-commonparent"

    if ((micromapCount > 0) && (pMicromaps)) {
        for (uint32_t index0 = 0; index0 < micromapCount; ++index0) {
            skip |= ValidateObject(pMicromaps[index0], kVulkanObjectTypeMicromapEXT, false, kVUIDUndefined,
                                   "UNASSIGNED-vkCmdWriteMicromapsPropertiesEXT-commonparent",
                                   error_obj.location.dot(Field::pMicromaps, index0));
        }
    }

    return skip;
}

// vkGetDeviceMicromapCompatibilityEXT:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateGetMicromapBuildSizesEXT(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType,
                                                              const VkMicromapBuildInfoEXT* pBuildInfo,
                                                              VkMicromapBuildSizesInfoEXT* pSizeInfo,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pBuildInfo) {
        [[maybe_unused]] const Location pBuildInfo_loc = error_obj.location.dot(Field::pBuildInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pBuildInfo->dstMicromap, kVulkanObjectTypeMicromapEXT, true, kVUIDUndefined, kVUIDUndefined,
                               pBuildInfo_loc.dot(Field::dstMicromap));
    }

    return skip;
}

// vkCmdDrawClusterHUAWEI:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdDrawClusterIndirectHUAWEI:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdDrawClusterIndirectHUAWEI-commonparent"

// vkSetDeviceMemoryPriorityEXT:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateGetDescriptorSetLayoutHostMappingInfoVALVE(
    VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference,
    VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pBindingReference) {
        [[maybe_unused]] const Location pBindingReference_loc = error_obj.location.dot(Field::pBindingReference);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pBindingReference->descriptorSetLayout, kVulkanObjectTypeDescriptorSetLayout, false, kVUIDUndefined,
                               kVUIDUndefined, pBindingReference_loc.dot(Field::descriptorSetLayout));
    }

    return skip;
}

// vkGetDescriptorSetHostMappingVALVE:
// Checked by chassis: device: kVUIDUndefined

// vkCmdCopyMemoryIndirectNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdCopyMemoryToImageIndirectNV:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdCopyMemoryToImageIndirectNV-commonparent"

// vkCmdDecompressMemoryNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdDecompressMemoryIndirectCountNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateGetPipelineIndirectMemoryRequirementsNV(VkDevice device,
                                                                             const VkComputePipelineCreateInfo* pCreateInfo,
                                                                             VkMemoryRequirements2* pMemoryRequirements,
                                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        [[maybe_unused]] const Location stage_loc = pCreateInfo_loc.dot(Field::stage);
        skip |=
            ValidateObject(pCreateInfo->stage.module, kVulkanObjectTypeShaderModule, true,
                           "VUID-VkPipelineShaderStageCreateInfo-module-parameter", kVUIDUndefined, stage_loc.dot(Field::module));
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkShaderModuleValidationCacheCreateInfoEXT>(pCreateInfo->stage.pNext)) {
            [[maybe_unused]] const Location pNext_loc = stage_loc.pNext(Struct::VkShaderModuleValidationCacheCreateInfoEXT);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pNext->validationCache, kVulkanObjectTypeValidationCacheEXT, false, kVUIDUndefined,
                                   kVUIDUndefined, pNext_loc.dot(Field::validationCache));
        }
        skip |= ValidateObject(pCreateInfo->layout, kVulkanObjectTypePipelineLayout, false,
                               "VUID-VkComputePipelineCreateInfo-layout-parameter", "VUID-VkComputePipelineCreateInfo-commonparent",
                               pCreateInfo_loc.dot(Field::layout));
        if ((pCreateInfo->flags & VK_PIPELINE_CREATE_DERIVATIVE_BIT) && (pCreateInfo->basePipelineIndex == -1))
            skip |= ValidateObject(pCreateInfo->basePipelineHandle, kVulkanObjectTypePipeline, false,
                                   "VUID-VkComputePipelineCreateInfo-flags-07984", "VUID-VkComputePipelineCreateInfo-commonparent",
                                   error_obj.location);
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkSubpassShadingPipelineCreateInfoHUAWEI>(pCreateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pCreateInfo_loc.pNext(Struct::VkSubpassShadingPipelineCreateInfoHUAWEI);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pNext->renderPass, kVulkanObjectTypeRenderPass, false, kVUIDUndefined, kVUIDUndefined,
                                   pNext_loc.dot(Field::renderPass));
        }
    }

    return skip;
}

// vkCmdUpdatePipelineIndirectBufferNV:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdUpdatePipelineIndirectBufferNV-commonparent"

bool ObjectLifetimes::PreCallValidateGetPipelineIndirectDeviceAddressNV(VkDevice device,
                                                                        const VkPipelineIndirectDeviceAddressInfoNV* pInfo,
                                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->pipeline, kVulkanObjectTypePipeline, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::pipeline));
    }

    return skip;
}

// vkCmdSetDepthClampEnableEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetPolygonModeEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetRasterizationSamplesEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetSampleMaskEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetAlphaToCoverageEnableEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetAlphaToOneEnableEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetLogicOpEnableEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetColorBlendEnableEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetColorBlendEquationEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetColorWriteMaskEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetTessellationDomainOriginEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetRasterizationStreamEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetConservativeRasterizationModeEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetExtraPrimitiveOverestimationSizeEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetDepthClipEnableEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetSampleLocationsEnableEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetColorBlendAdvancedEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetProvokingVertexModeEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetLineRasterizationModeEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetLineStippleEnableEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetDepthClipNegativeOneToOneEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetViewportWScalingEnableNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetViewportSwizzleNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetCoverageToColorEnableNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetCoverageToColorLocationNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetCoverageModulationModeNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetCoverageModulationTableEnableNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetCoverageModulationTableNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetShadingRateImageEnableNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetRepresentativeFragmentTestEnableNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdSetCoverageReductionModeNV:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkGetShaderModuleIdentifierEXT:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateGetShaderModuleCreateInfoIdentifierEXT(VkDevice device,
                                                                            const VkShaderModuleCreateInfo* pCreateInfo,
                                                                            VkShaderModuleIdentifierEXT* pIdentifier,
                                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkShaderModuleValidationCacheCreateInfoEXT>(pCreateInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc = pCreateInfo_loc.pNext(Struct::VkShaderModuleValidationCacheCreateInfoEXT);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pNext->validationCache, kVulkanObjectTypeValidationCacheEXT, false, kVUIDUndefined,
                                   kVUIDUndefined, pNext_loc.dot(Field::validationCache));
        }
    }

    return skip;
}

// vkGetPhysicalDeviceOpticalFlowImageFormatsNV:
// Checked by chassis: physicalDevice: kVUIDUndefined

// vkCreateOpticalFlowSessionNV:
// Checked by chassis: device: kVUIDUndefined

void ObjectLifetimes::PostCallRecordCreateOpticalFlowSessionNV(VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               VkOpticalFlowSessionNV* pSession, const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSession, kVulkanObjectTypeOpticalFlowSessionNV, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyOpticalFlowSessionNV(VkDevice device, VkOpticalFlowSessionNV session,
                                                                 const VkAllocationCallbacks* pAllocator,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(session, kVulkanObjectTypeOpticalFlowSessionNV, pAllocator, kVUIDUndefined, kVUIDUndefined,
                                  error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyOpticalFlowSessionNV(VkDevice device, VkOpticalFlowSessionNV session,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               const RecordObject& record_obj) {
    RecordDestroyObject(session, kVulkanObjectTypeOpticalFlowSessionNV);
}

// vkBindOpticalFlowSessionImageNV:
// Checked by chassis: device: kVUIDUndefined

// vkCmdOpticalFlowExecuteNV:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdOpticalFlowExecuteNV-commonparent"

bool ObjectLifetimes::PreCallValidateCreateShadersEXT(VkDevice device, uint32_t createInfoCount,
                                                      const VkShaderCreateInfoEXT* pCreateInfos,
                                                      const VkAllocationCallbacks* pAllocator, VkShaderEXT* pShaders,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfos) {
        for (uint32_t index0 = 0; index0 < createInfoCount; ++index0) {
            [[maybe_unused]] const Location index0_loc = error_obj.location.dot(Field::pCreateInfos, index0);

            if ((pCreateInfos[index0].setLayoutCount > 0) && (pCreateInfos[index0].pSetLayouts)) {
                for (uint32_t index1 = 0; index1 < pCreateInfos[index0].setLayoutCount; ++index1) {
                    skip |= ValidateObject(pCreateInfos[index0].pSetLayouts[index1], kVulkanObjectTypeDescriptorSetLayout, false,
                                           kVUIDUndefined, kVUIDUndefined, index0_loc.dot(Field::pSetLayouts, index1));
                }
            }
        }
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateShadersEXT(VkDevice device, uint32_t createInfoCount,
                                                     const VkShaderCreateInfoEXT* pCreateInfos,
                                                     const VkAllocationCallbacks* pAllocator, VkShaderEXT* pShaders,
                                                     const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS && record_obj.result != VK_ERROR_INCOMPATIBLE_SHADER_BINARY_EXT) return;
    if (pShaders) {
        for (uint32_t index = 0; index < createInfoCount; index++) {
            if (!pShaders[index]) break;
            CreateObject(pShaders[index], kVulkanObjectTypeShaderEXT, pAllocator, record_obj.location.dot(Field::pShaders, index));
        }
    }
}

bool ObjectLifetimes::PreCallValidateDestroyShaderEXT(VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks* pAllocator,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |=
        ValidateDestroyObject(shader, kVulkanObjectTypeShaderEXT, pAllocator, kVUIDUndefined, kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyShaderEXT(VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks* pAllocator,
                                                    const RecordObject& record_obj) {
    RecordDestroyObject(shader, kVulkanObjectTypeShaderEXT);
}

// vkGetShaderBinaryDataEXT:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                                       const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    // Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdBindShadersEXT-commonparent"

    if ((stageCount > 0) && (pShaders)) {
        for (uint32_t index0 = 0; index0 < stageCount; ++index0) {
            skip |= ValidateObject(pShaders[index0], kVulkanObjectTypeShaderEXT, true, kVUIDUndefined,
                                   "UNASSIGNED-vkCmdBindShadersEXT-commonparent", error_obj.location.dot(Field::pShaders, index0));
        }
    }

    return skip;
}

// vkGetFramebufferTilePropertiesQCOM:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateGetDynamicRenderingTilePropertiesQCOM(VkDevice device, const VkRenderingInfo* pRenderingInfo,
                                                                           VkTilePropertiesQCOM* pProperties,
                                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pRenderingInfo) {
        [[maybe_unused]] const Location pRenderingInfo_loc = error_obj.location.dot(Field::pRenderingInfo);
        if (pRenderingInfo->pColorAttachments) {
            for (uint32_t index1 = 0; index1 < pRenderingInfo->colorAttachmentCount; ++index1) {
                [[maybe_unused]] const Location index1_loc = pRenderingInfo_loc.dot(Field::pColorAttachments, index1);
            }
        }
        if (pRenderingInfo->pDepthAttachment) {
            [[maybe_unused]] const Location pDepthAttachment_loc = pRenderingInfo_loc.dot(Field::pDepthAttachment);
        }
        if (pRenderingInfo->pStencilAttachment) {
            [[maybe_unused]] const Location pStencilAttachment_loc = pRenderingInfo_loc.dot(Field::pStencilAttachment);
        }
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkRenderingFragmentDensityMapAttachmentInfoEXT>(pRenderingInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc =
                pRenderingInfo_loc.pNext(Struct::VkRenderingFragmentDensityMapAttachmentInfoEXT);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pNext->imageView, kVulkanObjectTypeImageView, false, kVUIDUndefined, kVUIDUndefined,
                                   pNext_loc.dot(Field::imageView));
        }
        if ([[maybe_unused]] auto pNext =
                vku::FindStructInPNextChain<VkRenderingFragmentShadingRateAttachmentInfoKHR>(pRenderingInfo->pNext)) {
            [[maybe_unused]] const Location pNext_loc =
                pRenderingInfo_loc.pNext(Struct::VkRenderingFragmentShadingRateAttachmentInfoKHR);
            // There should be an explicit VU (if not that is a spec bug)
            skip |= ValidateObject(pNext->imageView, kVulkanObjectTypeImageView, true, kVUIDUndefined, kVUIDUndefined,
                                   pNext_loc.dot(Field::imageView));
        }
    }

    return skip;
}
#ifdef VK_USE_PLATFORM_SCI

// vkCreateSemaphoreSciSyncPoolNV:
// Checked by chassis: device: "VUID-vkCreateSemaphoreSciSyncPoolNV-device-parameter"

void ObjectLifetimes::PostCallRecordCreateSemaphoreSciSyncPoolNV(VkDevice device,
                                                                 const VkSemaphoreSciSyncPoolCreateInfoNV* pCreateInfo,
                                                                 const VkAllocationCallbacks* pAllocator,
                                                                 VkSemaphoreSciSyncPoolNV* pSemaphorePool,
                                                                 const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pSemaphorePool, kVulkanObjectTypeSemaphoreSciSyncPoolNV, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroySemaphoreSciSyncPoolNV(VkDevice device, VkSemaphoreSciSyncPoolNV semaphorePool,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(semaphorePool, kVulkanObjectTypeSemaphoreSciSyncPoolNV, pAllocator, kVUIDUndefined,
                                  kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroySemaphoreSciSyncPoolNV(VkDevice device, VkSemaphoreSciSyncPoolNV semaphorePool,
                                                                 const VkAllocationCallbacks* pAllocator,
                                                                 const RecordObject& record_obj) {
    RecordDestroyObject(semaphorePool, kVulkanObjectTypeSemaphoreSciSyncPoolNV);
}
#endif  // VK_USE_PLATFORM_SCI

// vkSetLatencySleepModeNV:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateLatencySleepNV(VkDevice device, VkSwapchainKHR swapchain,
                                                    const VkLatencySleepInfoNV* pSleepInfo, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pSleepInfo) {
        [[maybe_unused]] const Location pSleepInfo_loc = error_obj.location.dot(Field::pSleepInfo);
    }

    return skip;
}

// vkSetLatencyMarkerNV:
// Checked by chassis: device: kVUIDUndefined

// vkGetLatencyTimingsNV:
// Checked by chassis: device: kVUIDUndefined

// vkQueueNotifyOutOfBandNV:
// Checked by chassis: queue: kVUIDUndefined

// vkCmdSetAttachmentFeedbackLoopEnableEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

#ifdef VK_USE_PLATFORM_SCREEN_QNX

// vkGetScreenBufferPropertiesQNX:
// Checked by chassis: device: "VUID-vkGetScreenBufferPropertiesQNX-device-parameter"

#endif  // VK_USE_PLATFORM_SCREEN_QNX

bool ObjectLifetimes::PreCallValidateCreateAccelerationStructureKHR(VkDevice device,
                                                                    const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
                                                                    const VkAllocationCallbacks* pAllocator,
                                                                    VkAccelerationStructureKHR* pAccelerationStructure,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pCreateInfo) {
        [[maybe_unused]] const Location pCreateInfo_loc = error_obj.location.dot(Field::pCreateInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pCreateInfo->buffer, kVulkanObjectTypeBuffer, false, kVUIDUndefined, kVUIDUndefined,
                               pCreateInfo_loc.dot(Field::buffer));
    }

    return skip;
}

void ObjectLifetimes::PostCallRecordCreateAccelerationStructureKHR(VkDevice device,
                                                                   const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   VkAccelerationStructureKHR* pAccelerationStructure,
                                                                   const RecordObject& record_obj) {
    if (record_obj.result != VK_SUCCESS) return;
    CreateObject(*pAccelerationStructure, kVulkanObjectTypeAccelerationStructureKHR, pAllocator, record_obj.location);
}

bool ObjectLifetimes::PreCallValidateDestroyAccelerationStructureKHR(VkDevice device,
                                                                     VkAccelerationStructureKHR accelerationStructure,
                                                                     const VkAllocationCallbacks* pAllocator,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    skip |= ValidateDestroyObject(accelerationStructure, kVulkanObjectTypeAccelerationStructureKHR, pAllocator, kVUIDUndefined,
                                  kVUIDUndefined, error_obj.location);

    return skip;
}

void ObjectLifetimes::PreCallRecordDestroyAccelerationStructureKHR(VkDevice device,
                                                                   VkAccelerationStructureKHR accelerationStructure,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   const RecordObject& record_obj) {
    RecordDestroyObject(accelerationStructure, kVulkanObjectTypeAccelerationStructureKHR);
}

bool ObjectLifetimes::PreCallValidateCopyAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation,
                                                                  const VkCopyAccelerationStructureInfoKHR* pInfo,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCopyAccelerationStructureToMemoryKHR(VkDevice device, VkDeferredOperationKHR deferredOperation,
                                                                          const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo,
                                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->src, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::src));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCopyMemoryToAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation,
                                                                          const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo,
                                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->dst, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::dst));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateWriteAccelerationStructuresPropertiesKHR(
    VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures,
    VkQueryType queryType, size_t dataSize, void* pData, size_t stride, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined

    if ((accelerationStructureCount > 0) && (pAccelerationStructures)) {
        for (uint32_t index0 = 0; index0 < accelerationStructureCount; ++index0) {
            skip |=
                ValidateObject(pAccelerationStructures[index0], kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined,
                               "UNASSIGNED-vkWriteAccelerationStructuresPropertiesKHR-pAccelerationStructures-parent",
                               error_obj.location.dot(Field::pAccelerationStructures, index0));
        }
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                                     const VkCopyAccelerationStructureInfoKHR* pInfo,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->src, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::src));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->dst, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined, kVUIDUndefined,
                               pInfo_loc.dot(Field::dst));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateGetAccelerationStructureDeviceAddressKHR(
    VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pInfo) {
        [[maybe_unused]] const Location pInfo_loc = error_obj.location.dot(Field::pInfo);
        // There should be an explicit VU (if not that is a spec bug)
        skip |= ValidateObject(pInfo->accelerationStructure, kVulkanObjectTypeAccelerationStructureKHR, false, kVUIDUndefined,
                               kVUIDUndefined, pInfo_loc.dot(Field::accelerationStructure));
    }

    return skip;
}

bool ObjectLifetimes::PreCallValidateCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures,
    VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: commandBuffer: kVUIDUndefined
    // Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdWriteAccelerationStructuresPropertiesKHR-commonparent"

    if ((accelerationStructureCount > 0) && (pAccelerationStructures)) {
        for (uint32_t index0 = 0; index0 < accelerationStructureCount; ++index0) {
            skip |= ValidateObject(pAccelerationStructures[index0], kVulkanObjectTypeAccelerationStructureKHR, false,
                                   kVUIDUndefined, "UNASSIGNED-vkCmdWriteAccelerationStructuresPropertiesKHR-commonparent",
                                   error_obj.location.dot(Field::pAccelerationStructures, index0));
        }
    }

    return skip;
}

// vkGetDeviceAccelerationStructureCompatibilityKHR:
// Checked by chassis: device: kVUIDUndefined

bool ObjectLifetimes::PreCallValidateGetAccelerationStructureBuildSizesKHR(
    VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo,
    const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo, const ErrorObject& error_obj) const {
    bool skip = false;
    // Checked by chassis: device: kVUIDUndefined
    if (pBuildInfo) {
        [[maybe_unused]] const Location pBuildInfo_loc = error_obj.location.dot(Field::pBuildInfo);
    }

    return skip;
}

// vkCmdTraceRaysKHR:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkGetRayTracingCaptureReplayShaderGroupHandlesKHR:
// Checked by chassis: device: kVUIDUndefined

// vkCmdTraceRaysIndirectKHR:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkGetRayTracingShaderGroupStackSizeKHR:
// Checked by chassis: device: kVUIDUndefined

// vkCmdSetRayTracingPipelineStackSizeKHR:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdDrawMeshTasksEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined

// vkCmdDrawMeshTasksIndirectEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdDrawMeshTasksIndirectEXT-commonparent"

// vkCmdDrawMeshTasksIndirectCountEXT:
// Checked by chassis: commandBuffer: kVUIDUndefined
// Checked by chassis: commandBuffer: "UNASSIGNED-vkCmdDrawMeshTasksIndirectCountEXT-commonparent"

// NOLINTEND
