// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See layer_chassis_generator.py for modifications

/***************************************************************************
 *
 * Copyright (c) 2015-2026 The Khronos Group Inc.
 * Copyright (c) 2015-2026 Valve Corporation
 * Copyright (c) 2015-2026 LunarG, Inc.
 * Copyright (c) 2015-2024 Google Inc.
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
 ****************************************************************************/

// NOLINTBEGIN

#include "chassis/chassis.h"
#include <array>
#include <cstring>

#include "chassis/dispatch_object.h"
#include "chassis/validation_object.h"
#include "generated/dispatch_vector.h"
#include "utils/vk_layer_extension_utils.h"
#include "layer_options.h"

#include "profiling/profiling.h"

// Extension exposed by the validation layer
static constexpr std::array<VkExtensionProperties, 3> kInstanceExtensions = {
    VkExtensionProperties{VK_EXT_DEBUG_UTILS_EXTENSION_NAME, VK_EXT_DEBUG_UTILS_SPEC_VERSION},
    VkExtensionProperties{VK_EXT_VALIDATION_FEATURES_EXTENSION_NAME, VK_EXT_VALIDATION_FEATURES_SPEC_VERSION},
    VkExtensionProperties{VK_EXT_LAYER_SETTINGS_EXTENSION_NAME, VK_EXT_LAYER_SETTINGS_SPEC_VERSION},
};
static constexpr std::array<VkExtensionProperties, 2> kDeviceExtensions = {
    VkExtensionProperties{VK_EXT_VALIDATION_CACHE_EXTENSION_NAME, VK_EXT_VALIDATION_CACHE_SPEC_VERSION},
    VkExtensionProperties{VK_EXT_TOOLING_INFO_EXTENSION_NAME, VK_EXT_TOOLING_INFO_SPEC_VERSION},
};
namespace vulkan_layer_chassis {
static const VkLayerProperties global_layer = {
    OBJECT_LAYER_NAME,
    VK_HEADER_VERSION_COMPLETE,
    1,
    "LunarG validation Layer",
};

// These functions reference generated data so they cannot be part of chassis_main.cpp
VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceVersion(uint32_t* pApiVersion) {
    if (pApiVersion) {
        *pApiVersion = VK_HEADER_VERSION_COMPLETE;
    }
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceLayerProperties(uint32_t* pCount, VkLayerProperties* pProperties) {
    return util_GetLayerProperties(1, &global_layer, pCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pCount,
                                                              VkLayerProperties* pProperties) {
    return util_GetLayerProperties(1, &global_layer, pCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pCount,
                                                                    VkExtensionProperties* pProperties) {
    if (pLayerName && !strcmp(pLayerName, global_layer.layerName)) {
        return util_GetExtensionProperties(static_cast<uint32_t>(kInstanceExtensions.size()), kInstanceExtensions.data(), pCount,
                                           pProperties);
    }

    return VK_ERROR_LAYER_NOT_PRESENT;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName,
                                                                  uint32_t* pCount, VkExtensionProperties* pProperties) {
    if (pLayerName && !strcmp(pLayerName, global_layer.layerName)) {
        return util_GetExtensionProperties(static_cast<uint32_t>(kDeviceExtensions.size()), kDeviceExtensions.data(), pCount,
                                           pProperties);
    }

    assert(physicalDevice);
    auto layer_data = vvl::dispatch::GetData(physicalDevice);
    return layer_data->instance_dispatch_table.EnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pCount, pProperties);
}
VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount,
                                                        VkPhysicalDevice* pPhysicalDevices) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(instance);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkEnumeratePhysicalDevices, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    {
        VVL_ZoneScopedN("PreCallValidate_vkEnumeratePhysicalDevices");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkEnumeratePhysicalDevices);
    {
        VVL_ZoneScopedN("PreCallRecord_vkEnumeratePhysicalDevices");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkEnumeratePhysicalDevices");
        result = instance_dispatch->EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkEnumeratePhysicalDevices");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceFeatures,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceFeatures");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceFeatures(physicalDevice, pFeatures, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceFeatures);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceFeatures");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceFeatures(physicalDevice, pFeatures, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceFeatures");
        instance_dispatch->GetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceFeatures");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceFeatures(physicalDevice, pFeatures, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                             VkFormatProperties* pFormatProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceFormatProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceFormatProperties");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceFormatProperties);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceFormatProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceFormatProperties");
        instance_dispatch->GetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceFormatProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                      VkImageType type, VkImageTiling tiling,
                                                                      VkImageUsageFlags usage, VkImageCreateFlags flags,
                                                                      VkImageFormatProperties* pImageFormatProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceImageFormatProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceImageFormatProperties");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags,
                                                                              pImageFormatProperties, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceImageFormatProperties);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceImageFormatProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags,
                                                                    pImageFormatProperties, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceImageFormatProperties");
        result = instance_dispatch->GetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags,
                                                                           pImageFormatProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceImageFormatProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags,
                                                                     pImageFormatProperties, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceProperties");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceProperties(physicalDevice, pProperties, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceProperties);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceProperties(physicalDevice, pProperties, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceProperties");
        instance_dispatch->GetPhysicalDeviceProperties(physicalDevice, pProperties);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceProperties(physicalDevice, pProperties, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice,
                                                                  uint32_t* pQueueFamilyPropertyCount,
                                                                  VkQueueFamilyProperties* pQueueFamilyProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceQueueFamilyProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceQueueFamilyProperties");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount,
                                                                              pQueueFamilyProperties, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceQueueFamilyProperties);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceQueueFamilyProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount,
                                                                    pQueueFamilyProperties, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceQueueFamilyProperties");
        instance_dispatch->GetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount,
                                                                  pQueueFamilyProperties);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceQueueFamilyProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount,
                                                                     pQueueFamilyProperties, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice,
                                                             VkPhysicalDeviceMemoryProperties* pMemoryProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceMemoryProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceMemoryProperties");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceMemoryProperties);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceMemoryProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceMemoryProperties");
        instance_dispatch->GetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceMemoryProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceQueue, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDeviceQueue");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetDeviceQueue]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDeviceQueue);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDeviceQueue");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetDeviceQueue]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetDeviceQueue");
        device_dispatch->GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDeviceQueue");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetDeviceQueue]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue, record_obj);
        }
    }
#if defined(VVL_TRACY_GPU)
    TracyVkCollector::Create(device, *pQueue, queueFamilyIndex);
#endif
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(queue);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueSubmit, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    {
        VVL_ZoneScopedN("PreCallValidate_vkQueueSubmit");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateQueueSubmit]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateQueueSubmit(queue, submitCount, pSubmits, fence, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkQueueSubmit);
    {
        VVL_ZoneScopedN("PreCallRecord_vkQueueSubmit");
        VVL_TracyVkNamedZoneStart(GetTracyVkCtx(), queue, "gpu_PreCallRecordvkQueueSubmit", pre_call_record_gpu_zone);

        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordQueueSubmit]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordQueueSubmit(queue, submitCount, pSubmits, fence, record_obj);
        }

        VVL_TracyVkNamedZoneEnd(pre_call_record_gpu_zone, queue);
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkQueueSubmit");

        VVL_TracyVkNamedZoneStart(GetTracyVkCtx(), queue, "gpu_vkQueueSubmit", submit_gpu_zone);
        result = device_dispatch->QueueSubmit(queue, submitCount, pSubmits, fence);

        VVL_TracyVkNamedZoneEnd(submit_gpu_zone, queue);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkQueueSubmit");

        VVL_TracyVkNamedZoneStart(GetTracyVkCtx(), queue, "gpu_PostCallRecordvkQueueSubmit", post_call_record_gpu_zone);

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordQueueSubmit]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordQueueSubmit(queue, submitCount, pSubmits, fence, record_obj);
        }

        VVL_TracyVkNamedZoneEnd(post_call_record_gpu_zone, queue);
    }
#if defined(VVL_TRACY_GPU)
    TracyVkCollector::TrySubmitCollectCb(queue);
#endif
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle(VkQueue queue) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(queue);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueWaitIdle, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    {
        VVL_ZoneScopedN("PreCallValidate_vkQueueWaitIdle");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateQueueWaitIdle]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateQueueWaitIdle(queue, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkQueueWaitIdle);
    {
        VVL_ZoneScopedN("PreCallRecord_vkQueueWaitIdle");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordQueueWaitIdle]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordQueueWaitIdle(queue, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkQueueWaitIdle");
        result = device_dispatch->QueueWaitIdle(queue);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkQueueWaitIdle");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordQueueWaitIdle]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordQueueWaitIdle(queue, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle(VkDevice device) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDeviceWaitIdle, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDeviceWaitIdle");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDeviceWaitIdle]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDeviceWaitIdle(device, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkDeviceWaitIdle);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDeviceWaitIdle");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDeviceWaitIdle]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDeviceWaitIdle(device, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkDeviceWaitIdle");
        result = device_dispatch->DeviceWaitIdle(device);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkDeviceWaitIdle");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDeviceWaitIdle]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDeviceWaitIdle(device, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                              const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkAllocateMemory, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkAllocateMemory");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateAllocateMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateAllocateMemory(device, pAllocateInfo, pAllocator, pMemory, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkAllocateMemory);
    {
        VVL_ZoneScopedN("PreCallRecord_vkAllocateMemory");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordAllocateMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordAllocateMemory(device, pAllocateInfo, pAllocator, pMemory, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkAllocateMemory");
        result = device_dispatch->AllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkAllocateMemory");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordAllocateMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordAllocateMemory(device, pAllocateInfo, pAllocator, pMemory, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL MapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size,
                                         VkMemoryMapFlags flags, void** ppData) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkMapMemory, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkMapMemory");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateMapMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateMapMemory(device, memory, offset, size, flags, ppData, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkMapMemory);
    {
        VVL_ZoneScopedN("PreCallRecord_vkMapMemory");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordMapMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordMapMemory(device, memory, offset, size, flags, ppData, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkMapMemory");
        result = device_dispatch->MapMemory(device, memory, offset, size, flags, ppData);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkMapMemory");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordMapMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordMapMemory(device, memory, offset, size, flags, ppData, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL UnmapMemory(VkDevice device, VkDeviceMemory memory) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkUnmapMemory, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkUnmapMemory");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateUnmapMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateUnmapMemory(device, memory, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkUnmapMemory);
    {
        VVL_ZoneScopedN("PreCallRecord_vkUnmapMemory");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordUnmapMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordUnmapMemory(device, memory, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkUnmapMemory");
        device_dispatch->UnmapMemory(device, memory);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkUnmapMemory");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordUnmapMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordUnmapMemory(device, memory, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                       const VkMappedMemoryRange* pMemoryRanges) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkFlushMappedMemoryRanges, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkFlushMappedMemoryRanges");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateFlushMappedMemoryRanges]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkFlushMappedMemoryRanges);
    {
        VVL_ZoneScopedN("PreCallRecord_vkFlushMappedMemoryRanges");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordFlushMappedMemoryRanges]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkFlushMappedMemoryRanges");
        result = device_dispatch->FlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkFlushMappedMemoryRanges");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordFlushMappedMemoryRanges]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                            const VkMappedMemoryRange* pMemoryRanges) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkInvalidateMappedMemoryRanges, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkInvalidateMappedMemoryRanges");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateInvalidateMappedMemoryRanges]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkInvalidateMappedMemoryRanges);
    {
        VVL_ZoneScopedN("PreCallRecord_vkInvalidateMappedMemoryRanges");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordInvalidateMappedMemoryRanges]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkInvalidateMappedMemoryRanges");
        result = device_dispatch->InvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkInvalidateMappedMemoryRanges");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordInvalidateMappedMemoryRanges]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory,
                                                     VkDeviceSize* pCommittedMemoryInBytes) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceMemoryCommitment, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDeviceMemoryCommitment");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetDeviceMemoryCommitment]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDeviceMemoryCommitment);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDeviceMemoryCommitment");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetDeviceMemoryCommitment]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetDeviceMemoryCommitment");
        device_dispatch->GetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDeviceMemoryCommitment");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetDeviceMemoryCommitment]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory,
                                                VkDeviceSize memoryOffset) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkBindBufferMemory, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkBindBufferMemory");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateBindBufferMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateBindBufferMemory(device, buffer, memory, memoryOffset, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkBindBufferMemory);
    {
        VVL_ZoneScopedN("PreCallRecord_vkBindBufferMemory");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordBindBufferMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordBindBufferMemory(device, buffer, memory, memoryOffset, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkBindBufferMemory");
        result = device_dispatch->BindBufferMemory(device, buffer, memory, memoryOffset);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkBindBufferMemory");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordBindBufferMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordBindBufferMemory(device, buffer, memory, memoryOffset, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkBindImageMemory, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkBindImageMemory");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateBindImageMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateBindImageMemory(device, image, memory, memoryOffset, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkBindImageMemory);
    {
        VVL_ZoneScopedN("PreCallRecord_vkBindImageMemory");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordBindImageMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordBindImageMemory(device, image, memory, memoryOffset, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkBindImageMemory");
        result = device_dispatch->BindImageMemory(device, image, memory, memoryOffset);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkBindImageMemory");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordBindImageMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordBindImageMemory(device, image, memory, memoryOffset, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements(VkDevice device, VkBuffer buffer,
                                                       VkMemoryRequirements* pMemoryRequirements) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetBufferMemoryRequirements, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetBufferMemoryRequirements");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetBufferMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetBufferMemoryRequirements(device, buffer, pMemoryRequirements, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetBufferMemoryRequirements);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetBufferMemoryRequirements");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetBufferMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetBufferMemoryRequirements(device, buffer, pMemoryRequirements, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetBufferMemoryRequirements");
        device_dispatch->GetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetBufferMemoryRequirements");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetBufferMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetBufferMemoryRequirements(device, buffer, pMemoryRequirements, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetImageMemoryRequirements, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetImageMemoryRequirements");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetImageMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetImageMemoryRequirements(device, image, pMemoryRequirements, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetImageMemoryRequirements);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetImageMemoryRequirements");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetImageMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetImageMemoryRequirements(device, image, pMemoryRequirements, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetImageMemoryRequirements");
        device_dispatch->GetImageMemoryRequirements(device, image, pMemoryRequirements);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetImageMemoryRequirements");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetImageMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetImageMemoryRequirements(device, image, pMemoryRequirements, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateFence, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateFence");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateFence]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateFence(device, pCreateInfo, pAllocator, pFence, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateFence);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateFence");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateFence]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateFence(device, pCreateInfo, pAllocator, pFence, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateFence");
        result = device_dispatch->CreateFence(device, pCreateInfo, pAllocator, pFence);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateFence");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateFence]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateFence(device, pCreateInfo, pAllocator, pFence, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyFence, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyFence");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyFence]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyFence(device, fence, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyFence);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyFence");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyFence]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyFence(device, fence, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyFence");
        device_dispatch->DestroyFence(device, fence, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyFence");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyFence]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyFence(device, fence, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL ResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkResetFences, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkResetFences");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateResetFences]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateResetFences(device, fenceCount, pFences, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkResetFences);
    {
        VVL_ZoneScopedN("PreCallRecord_vkResetFences");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordResetFences]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordResetFences(device, fenceCount, pFences, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkResetFences");
        result = device_dispatch->ResetFences(device, fenceCount, pFences);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkResetFences");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordResetFences]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordResetFences(device, fenceCount, pFences, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(VkDevice device, VkFence fence) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetFenceStatus, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetFenceStatus");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetFenceStatus]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetFenceStatus(device, fence, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetFenceStatus);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetFenceStatus");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetFenceStatus]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetFenceStatus(device, fence, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetFenceStatus");
        result = device_dispatch->GetFenceStatus(device, fence);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetFenceStatus");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetFenceStatus]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetFenceStatus(device, fence, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll,
                                             uint64_t timeout) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkWaitForFences, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkWaitForFences");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateWaitForFences]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateWaitForFences(device, fenceCount, pFences, waitAll, timeout, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkWaitForFences);
    {
        VVL_ZoneScopedN("PreCallRecord_vkWaitForFences");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordWaitForFences]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordWaitForFences(device, fenceCount, pFences, waitAll, timeout, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkWaitForFences");
        result = device_dispatch->WaitForFences(device, fenceCount, pFences, waitAll, timeout);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkWaitForFences");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordWaitForFences]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordWaitForFences(device, fenceCount, pFences, waitAll, timeout, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateSemaphore, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateSemaphore");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateSemaphore]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateSemaphore);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateSemaphore");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateSemaphore]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateSemaphore");
        result = device_dispatch->CreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateSemaphore");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateSemaphore]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroySemaphore, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroySemaphore");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroySemaphore]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroySemaphore(device, semaphore, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroySemaphore);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroySemaphore");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroySemaphore]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroySemaphore(device, semaphore, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroySemaphore");
        device_dispatch->DestroySemaphore(device, semaphore, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroySemaphore");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroySemaphore]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroySemaphore(device, semaphore, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateQueryPool, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateQueryPool");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateQueryPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateQueryPool);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateQueryPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateQueryPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateQueryPool");
        result = device_dispatch->CreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateQueryPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateQueryPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount,
                                                   size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetQueryPoolResults, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetQueryPoolResults");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetQueryPoolResults]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride,
                                                           flags, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetQueryPoolResults);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetQueryPoolResults");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetQueryPoolResults]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags,
                                                 record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetQueryPoolResults");
        result = device_dispatch->GetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetQueryPoolResults");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetQueryPoolResults]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags,
                                                  record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyBuffer, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyBuffer");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyBuffer(device, buffer, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyBuffer);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyBuffer(device, buffer, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyBuffer");
        device_dispatch->DestroyBuffer(device, buffer, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyBuffer(device, buffer, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator, VkImage* pImage) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateImage, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateImage");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateImage(device, pCreateInfo, pAllocator, pImage, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateImage);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateImage(device, pCreateInfo, pAllocator, pImage, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateImage");
        result = device_dispatch->CreateImage(device, pCreateInfo, pAllocator, pImage);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateImage(device, pCreateInfo, pAllocator, pImage, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyImage, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyImage");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyImage(device, image, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyImage);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyImage(device, image, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyImage");
        device_dispatch->DestroyImage(device, image, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyImage(device, image, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource,
                                                     VkSubresourceLayout* pLayout) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetImageSubresourceLayout, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetImageSubresourceLayout");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetImageSubresourceLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetImageSubresourceLayout(device, image, pSubresource, pLayout, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetImageSubresourceLayout);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetImageSubresourceLayout");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetImageSubresourceLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetImageSubresourceLayout(device, image, pSubresource, pLayout, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetImageSubresourceLayout");
        device_dispatch->GetImageSubresourceLayout(device, image, pSubresource, pLayout);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetImageSubresourceLayout");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetImageSubresourceLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetImageSubresourceLayout(device, image, pSubresource, pLayout, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator, VkImageView* pView) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateImageView, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateImageView");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateImageView]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateImageView(device, pCreateInfo, pAllocator, pView, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateImageView);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateImageView");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateImageView]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateImageView(device, pCreateInfo, pAllocator, pView, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateImageView");
        result = device_dispatch->CreateImageView(device, pCreateInfo, pAllocator, pView);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateImageView");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateImageView]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateImageView(device, pCreateInfo, pAllocator, pView, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyImageView, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyImageView");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyImageView]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyImageView(device, imageView, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyImageView);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyImageView");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyImageView]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyImageView(device, imageView, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyImageView");
        device_dispatch->DestroyImageView(device, imageView, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyImageView");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyImageView]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyImageView(device, imageView, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateCommandPool, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateCommandPool");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateCommandPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateCommandPool);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateCommandPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateCommandPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateCommandPool");
        result = device_dispatch->CreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateCommandPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateCommandPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkResetCommandPool, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkResetCommandPool");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateResetCommandPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateResetCommandPool(device, commandPool, flags, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkResetCommandPool);
    {
        VVL_ZoneScopedN("PreCallRecord_vkResetCommandPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordResetCommandPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordResetCommandPool(device, commandPool, flags, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkResetCommandPool");
        result = device_dispatch->ResetCommandPool(device, commandPool, flags);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkResetCommandPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordResetCommandPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordResetCommandPool(device, commandPool, flags, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                                      VkCommandBuffer* pCommandBuffers) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkAllocateCommandBuffers, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkAllocateCommandBuffers");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateAllocateCommandBuffers]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkAllocateCommandBuffers);
    {
        VVL_ZoneScopedN("PreCallRecord_vkAllocateCommandBuffers");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordAllocateCommandBuffers]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkAllocateCommandBuffers");
        result = device_dispatch->AllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkAllocateCommandBuffers");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordAllocateCommandBuffers]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                              const VkCommandBuffer* pCommandBuffers) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkFreeCommandBuffers, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkFreeCommandBuffers");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateFreeCommandBuffers]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkFreeCommandBuffers);
    {
        VVL_ZoneScopedN("PreCallRecord_vkFreeCommandBuffers");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordFreeCommandBuffers]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkFreeCommandBuffers");
        device_dispatch->FreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkFreeCommandBuffers");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordFreeCommandBuffers]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer(VkCommandBuffer commandBuffer) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkEndCommandBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkEndCommandBuffer");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateEndCommandBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateEndCommandBuffer(commandBuffer, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkEndCommandBuffer);
    {
        VVL_ZoneScopedN("PreCallRecord_vkEndCommandBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordEndCommandBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordEndCommandBuffer(commandBuffer, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkEndCommandBuffer");
        result = device_dispatch->EndCommandBuffer(commandBuffer);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkEndCommandBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordEndCommandBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordEndCommandBuffer(commandBuffer, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkResetCommandBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkResetCommandBuffer");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateResetCommandBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateResetCommandBuffer(commandBuffer, flags, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkResetCommandBuffer);
    {
        VVL_ZoneScopedN("PreCallRecord_vkResetCommandBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordResetCommandBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordResetCommandBuffer(commandBuffer, flags, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkResetCommandBuffer");
        result = device_dispatch->ResetCommandBuffer(commandBuffer, flags);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkResetCommandBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordResetCommandBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordResetCommandBuffer(commandBuffer, flags, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                         uint32_t regionCount, const VkBufferCopy* pRegions) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyBuffer");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyBuffer);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyBuffer");
        device_dispatch->CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                        VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                        const VkImageCopy* pRegions) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyImage, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyImage");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                                    pRegions, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyImage);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions,
                                          record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyImage");
        device_dispatch->CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions,
                                           record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                                VkImageLayout dstImageLayout, uint32_t regionCount,
                                                const VkBufferImageCopy* pRegions) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyBufferToImage, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyBufferToImage");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyBufferToImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount,
                                                            pRegions, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyBufferToImage);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyBufferToImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyBufferToImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions,
                                                  record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyBufferToImage");
        device_dispatch->CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyBufferToImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyBufferToImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions,
                                                   record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                                VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyImageToBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyImageToBuffer");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyImageToBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount,
                                                            pRegions, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyImageToBuffer);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyImageToBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyImageToBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions,
                                                  record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyImageToBuffer");
        device_dispatch->CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyImageToBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyImageToBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions,
                                                   record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                           VkDeviceSize dataSize, const void* pData) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdUpdateBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdUpdateBuffer");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdUpdateBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdUpdateBuffer);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdUpdateBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdUpdateBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdUpdateBuffer");
        device_dispatch->CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdUpdateBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdUpdateBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                         VkDeviceSize size, uint32_t data) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdFillBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdFillBuffer");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdFillBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdFillBuffer);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdFillBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdFillBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdFillBuffer");
        device_dispatch->CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdFillBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdFillBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                              VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                              uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                              uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                              uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdPipelineBarrier, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdPipelineBarrier");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdPipelineBarrier]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdPipelineBarrier(
                commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers,
                bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdPipelineBarrier);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdPipelineBarrier");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdPipelineBarrier]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount,
                                                pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                                imageMemoryBarrierCount, pImageMemoryBarriers, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdPipelineBarrier");
        device_dispatch->CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount,
                                            pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                            imageMemoryBarrierCount, pImageMemoryBarriers);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdPipelineBarrier");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdPipelineBarrier]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount,
                                                 pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                                 imageMemoryBarrierCount, pImageMemoryBarriers, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                         VkQueryControlFlags flags) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBeginQuery, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBeginQuery");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBeginQuery]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBeginQuery(commandBuffer, queryPool, query, flags, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBeginQuery);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBeginQuery");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBeginQuery]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBeginQuery(commandBuffer, queryPool, query, flags, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBeginQuery");
        device_dispatch->CmdBeginQuery(commandBuffer, queryPool, query, flags);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBeginQuery");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBeginQuery]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBeginQuery(commandBuffer, queryPool, query, flags, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdEndQuery, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdEndQuery");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdEndQuery]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdEndQuery(commandBuffer, queryPool, query, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdEndQuery);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdEndQuery");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdEndQuery]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdEndQuery(commandBuffer, queryPool, query, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdEndQuery");
        device_dispatch->CmdEndQuery(commandBuffer, queryPool, query);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdEndQuery");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdEndQuery]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdEndQuery(commandBuffer, queryPool, query, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                             uint32_t queryCount) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResetQueryPool, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdResetQueryPool");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdResetQueryPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdResetQueryPool);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdResetQueryPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdResetQueryPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdResetQueryPool");
        device_dispatch->CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdResetQueryPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdResetQueryPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                             VkQueryPool queryPool, uint32_t query) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWriteTimestamp, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdWriteTimestamp");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdWriteTimestamp]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdWriteTimestamp);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdWriteTimestamp");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdWriteTimestamp]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdWriteTimestamp");
        device_dispatch->CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdWriteTimestamp");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdWriteTimestamp]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                                   uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                   VkDeviceSize stride, VkQueryResultFlags flags) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyQueryPoolResults, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyQueryPoolResults");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyQueryPoolResults]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer,
                                                               dstOffset, stride, flags, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyQueryPoolResults);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyQueryPoolResults");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyQueryPoolResults]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride,
                                                     flags, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyQueryPoolResults");
        device_dispatch->CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride,
                                                 flags);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyQueryPoolResults");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyQueryPoolResults]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset,
                                                      stride, flags, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                              const VkCommandBuffer* pCommandBuffers) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdExecuteCommands, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdExecuteCommands");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdExecuteCommands]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdExecuteCommands);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdExecuteCommands");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdExecuteCommands]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdExecuteCommands");
        device_dispatch->CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdExecuteCommands");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdExecuteCommands]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateEvent, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateEvent");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateEvent(device, pCreateInfo, pAllocator, pEvent, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateEvent);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateEvent");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateEvent(device, pCreateInfo, pAllocator, pEvent, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateEvent");
        result = device_dispatch->CreateEvent(device, pCreateInfo, pAllocator, pEvent);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateEvent");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateEvent(device, pCreateInfo, pAllocator, pEvent, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyEvent, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyEvent");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyEvent(device, event, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyEvent);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyEvent");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyEvent(device, event, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyEvent");
        device_dispatch->DestroyEvent(device, event, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyEvent");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyEvent(device, event, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(VkDevice device, VkEvent event) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetEventStatus, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetEventStatus");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetEventStatus]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetEventStatus(device, event, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetEventStatus);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetEventStatus");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetEventStatus]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetEventStatus(device, event, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetEventStatus");
        result = device_dispatch->GetEventStatus(device, event);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetEventStatus");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetEventStatus]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetEventStatus(device, event, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetEvent(VkDevice device, VkEvent event) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSetEvent, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkSetEvent");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateSetEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateSetEvent(device, event, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkSetEvent);
    {
        VVL_ZoneScopedN("PreCallRecord_vkSetEvent");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordSetEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordSetEvent(device, event, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkSetEvent");
        result = device_dispatch->SetEvent(device, event);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkSetEvent");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordSetEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordSetEvent(device, event, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetEvent(VkDevice device, VkEvent event) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkResetEvent, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkResetEvent");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateResetEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateResetEvent(device, event, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkResetEvent);
    {
        VVL_ZoneScopedN("PreCallRecord_vkResetEvent");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordResetEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordResetEvent(device, event, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkResetEvent");
        result = device_dispatch->ResetEvent(device, event);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkResetEvent");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordResetEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordResetEvent(device, event, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkBufferView* pView) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateBufferView, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateBufferView");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateBufferView]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateBufferView(device, pCreateInfo, pAllocator, pView, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateBufferView);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateBufferView");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateBufferView]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateBufferView(device, pCreateInfo, pAllocator, pView, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateBufferView");
        result = device_dispatch->CreateBufferView(device, pCreateInfo, pAllocator, pView);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateBufferView");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateBufferView]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateBufferView(device, pCreateInfo, pAllocator, pView, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyBufferView, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyBufferView");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyBufferView]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyBufferView(device, bufferView, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyBufferView);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyBufferView");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyBufferView]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyBufferView(device, bufferView, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyBufferView");
        device_dispatch->DestroyBufferView(device, bufferView, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyBufferView");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyBufferView]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyBufferView(device, bufferView, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreatePipelineCache, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreatePipelineCache");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreatePipelineCache]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreatePipelineCache);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreatePipelineCache");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreatePipelineCache]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreatePipelineCache");
        result = device_dispatch->CreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreatePipelineCache");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreatePipelineCache]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache,
                                                const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyPipelineCache, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyPipelineCache");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyPipelineCache]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyPipelineCache(device, pipelineCache, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyPipelineCache);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyPipelineCache");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyPipelineCache]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyPipelineCache(device, pipelineCache, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyPipelineCache");
        device_dispatch->DestroyPipelineCache(device, pipelineCache, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyPipelineCache");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyPipelineCache]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyPipelineCache(device, pipelineCache, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL DestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyPipeline, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyPipeline");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyPipeline]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyPipeline(device, pipeline, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyPipeline);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyPipeline");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyPipeline]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyPipeline(device, pipeline, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyPipeline");
        device_dispatch->DestroyPipeline(device, pipeline, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyPipeline");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyPipeline]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyPipeline(device, pipeline, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout,
                                                 const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyPipelineLayout, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyPipelineLayout");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyPipelineLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyPipelineLayout(device, pipelineLayout, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyPipelineLayout);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyPipelineLayout");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyPipelineLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyPipelineLayout(device, pipelineLayout, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyPipelineLayout");
        device_dispatch->DestroyPipelineLayout(device, pipelineLayout, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyPipelineLayout");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyPipelineLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyPipelineLayout(device, pipelineLayout, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo,
                                             const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateSampler, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateSampler");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateSampler]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateSampler(device, pCreateInfo, pAllocator, pSampler, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateSampler);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateSampler");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateSampler]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateSampler(device, pCreateInfo, pAllocator, pSampler, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateSampler");
        result = device_dispatch->CreateSampler(device, pCreateInfo, pAllocator, pSampler);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateSampler");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateSampler]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateSampler(device, pCreateInfo, pAllocator, pSampler, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroySampler, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroySampler");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroySampler]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroySampler(device, sampler, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroySampler);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroySampler");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroySampler]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroySampler(device, sampler, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroySampler");
        device_dispatch->DestroySampler(device, sampler, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroySampler");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroySampler]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroySampler(device, sampler, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator,
                                                         VkDescriptorSetLayout* pSetLayout) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateDescriptorSetLayout, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateDescriptorSetLayout");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateDescriptorSetLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateDescriptorSetLayout);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateDescriptorSetLayout");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateDescriptorSetLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateDescriptorSetLayout");
        result = device_dispatch->CreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateDescriptorSetLayout");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateDescriptorSetLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout,
                                                      const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyDescriptorSetLayout, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyDescriptorSetLayout");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyDescriptorSetLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyDescriptorSetLayout);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyDescriptorSetLayout");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyDescriptorSetLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyDescriptorSetLayout");
        device_dispatch->DestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyDescriptorSetLayout");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyDescriptorSetLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateDescriptorPool, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateDescriptorPool");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateDescriptorPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateDescriptorPool);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateDescriptorPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateDescriptorPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateDescriptorPool");
        result = device_dispatch->CreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateDescriptorPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateDescriptorPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool,
                                                   VkDescriptorPoolResetFlags flags) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkResetDescriptorPool, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkResetDescriptorPool");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateResetDescriptorPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateResetDescriptorPool(device, descriptorPool, flags, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkResetDescriptorPool);
    {
        VVL_ZoneScopedN("PreCallRecord_vkResetDescriptorPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordResetDescriptorPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordResetDescriptorPool(device, descriptorPool, flags, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkResetDescriptorPool");
        result = device_dispatch->ResetDescriptorPool(device, descriptorPool, flags);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkResetDescriptorPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordResetDescriptorPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordResetDescriptorPool(device, descriptorPool, flags, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount,
                                                  const VkDescriptorSet* pDescriptorSets) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkFreeDescriptorSets, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkFreeDescriptorSets");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateFreeDescriptorSets]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkFreeDescriptorSets);
    {
        VVL_ZoneScopedN("PreCallRecord_vkFreeDescriptorSets");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordFreeDescriptorSets]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkFreeDescriptorSets");
        result = device_dispatch->FreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkFreeDescriptorSets");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordFreeDescriptorSets]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount,
                                                const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount,
                                                const VkCopyDescriptorSet* pDescriptorCopies) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkUpdateDescriptorSets, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkUpdateDescriptorSets");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateUpdateDescriptorSets]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount,
                                                            pDescriptorCopies, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkUpdateDescriptorSets);
    {
        VVL_ZoneScopedN("PreCallRecord_vkUpdateDescriptorSets");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordUpdateDescriptorSets]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount,
                                                  pDescriptorCopies, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkUpdateDescriptorSets");
        device_dispatch->UpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount,
                                              pDescriptorCopies);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkUpdateDescriptorSets");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordUpdateDescriptorSets]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount,
                                                   pDescriptorCopies, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                           VkPipeline pipeline) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindPipeline, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBindPipeline");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBindPipeline]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBindPipeline);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBindPipeline");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBindPipeline]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBindPipeline");
        device_dispatch->CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBindPipeline");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBindPipeline]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                 VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                                 const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                                 const uint32_t* pDynamicOffsets) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindDescriptorSets, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBindDescriptorSets");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBindDescriptorSets]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                                             pDescriptorSets, dynamicOffsetCount, pDynamicOffsets, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBindDescriptorSets);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBindDescriptorSets");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBindDescriptorSets]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                                   pDescriptorSets, dynamicOffsetCount, pDynamicOffsets, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBindDescriptorSets");
        device_dispatch->CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                               pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBindDescriptorSets");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBindDescriptorSets]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                                    pDescriptorSets, dynamicOffsetCount, pDynamicOffsets, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                              const VkClearColorValue* pColor, uint32_t rangeCount,
                                              const VkImageSubresourceRange* pRanges) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdClearColorImage, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdClearColorImage");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdClearColorImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |=
                vo->PreCallValidateCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdClearColorImage);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdClearColorImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdClearColorImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdClearColorImage");
        device_dispatch->CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdClearColorImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdClearColorImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                       uint32_t groupCountZ) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDispatch, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdDispatch");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdDispatch]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdDispatch);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdDispatch");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdDispatch]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdDispatch");
        device_dispatch->CmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdDispatch");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdDispatch]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDispatchIndirect, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdDispatchIndirect");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdDispatchIndirect]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdDispatchIndirect(commandBuffer, buffer, offset, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdDispatchIndirect);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdDispatchIndirect");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdDispatchIndirect]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdDispatchIndirect(commandBuffer, buffer, offset, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdDispatchIndirect");
        device_dispatch->CmdDispatchIndirect(commandBuffer, buffer, offset);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdDispatchIndirect");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdDispatchIndirect]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdDispatchIndirect(commandBuffer, buffer, offset, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetEvent, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetEvent");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetEvent(commandBuffer, event, stageMask, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetEvent);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetEvent");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetEvent(commandBuffer, event, stageMask, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetEvent");
        device_dispatch->CmdSetEvent(commandBuffer, event, stageMask);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetEvent");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetEvent(commandBuffer, event, stageMask, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResetEvent, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdResetEvent");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdResetEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdResetEvent(commandBuffer, event, stageMask, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdResetEvent);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdResetEvent");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdResetEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdResetEvent(commandBuffer, event, stageMask, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdResetEvent");
        device_dispatch->CmdResetEvent(commandBuffer, event, stageMask);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdResetEvent");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdResetEvent]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdResetEvent(commandBuffer, event, stageMask, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                         VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                                         uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                         uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                         uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWaitEvents, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdWaitEvents");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdWaitEvents]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdWaitEvents(
                commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers,
                bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdWaitEvents);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdWaitEvents");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdWaitEvents]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount,
                                           pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                           imageMemoryBarrierCount, pImageMemoryBarriers, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdWaitEvents");
        device_dispatch->CmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount,
                                       pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount,
                                       pImageMemoryBarriers);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdWaitEvents");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdWaitEvents]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount,
                                            pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                            imageMemoryBarrierCount, pImageMemoryBarriers, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                                            uint32_t offset, uint32_t size, const void* pValues) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdPushConstants, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdPushConstants");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdPushConstants]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdPushConstants);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdPushConstants");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdPushConstants]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdPushConstants");
        device_dispatch->CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdPushConstants");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdPushConstants]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateFramebuffer, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateFramebuffer");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateFramebuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateFramebuffer);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateFramebuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateFramebuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateFramebuffer");
        result = device_dispatch->CreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateFramebuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateFramebuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyFramebuffer, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyFramebuffer");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyFramebuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyFramebuffer(device, framebuffer, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyFramebuffer);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyFramebuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyFramebuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyFramebuffer(device, framebuffer, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyFramebuffer");
        device_dispatch->DestroyFramebuffer(device, framebuffer, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyFramebuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyFramebuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyFramebuffer(device, framebuffer, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateRenderPass, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateRenderPass");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateRenderPass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateRenderPass);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateRenderPass");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateRenderPass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateRenderPass");
        result = device_dispatch->CreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateRenderPass");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateRenderPass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyRenderPass, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyRenderPass");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyRenderPass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyRenderPass(device, renderPass, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyRenderPass);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyRenderPass");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyRenderPass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyRenderPass(device, renderPass, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyRenderPass");
        device_dispatch->DestroyRenderPass(device, renderPass, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyRenderPass");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyRenderPass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyRenderPass(device, renderPass, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetRenderAreaGranularity, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetRenderAreaGranularity");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetRenderAreaGranularity]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetRenderAreaGranularity(device, renderPass, pGranularity, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetRenderAreaGranularity);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetRenderAreaGranularity");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetRenderAreaGranularity]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetRenderAreaGranularity(device, renderPass, pGranularity, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetRenderAreaGranularity");
        device_dispatch->GetRenderAreaGranularity(device, renderPass, pGranularity);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetRenderAreaGranularity");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetRenderAreaGranularity]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetRenderAreaGranularity(device, renderPass, pGranularity, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                          const VkViewport* pViewports) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetViewport, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetViewport");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetViewport]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetViewport);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetViewport");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetViewport]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetViewport");
        device_dispatch->CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetViewport");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetViewport]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                         const VkRect2D* pScissors) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetScissor, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetScissor");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetScissor]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetScissor);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetScissor");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetScissor]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetScissor");
        device_dispatch->CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetScissor");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetScissor]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetLineWidth, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetLineWidth");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetLineWidth]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetLineWidth(commandBuffer, lineWidth, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetLineWidth);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetLineWidth");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetLineWidth]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetLineWidth(commandBuffer, lineWidth, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetLineWidth");
        device_dispatch->CmdSetLineWidth(commandBuffer, lineWidth);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetLineWidth");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetLineWidth]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetLineWidth(commandBuffer, lineWidth, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                                           float depthBiasSlopeFactor) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthBias, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDepthBias");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthBias]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor,
                                                       error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDepthBias);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDepthBias");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthBias]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor,
                                             record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDepthBias");
        device_dispatch->CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDepthBias");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthBias]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor,
                                              record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetBlendConstants, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetBlendConstants");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetBlendConstants]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetBlendConstants(commandBuffer, blendConstants, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetBlendConstants);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetBlendConstants");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetBlendConstants]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetBlendConstants(commandBuffer, blendConstants, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetBlendConstants");
        device_dispatch->CmdSetBlendConstants(commandBuffer, blendConstants);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetBlendConstants");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetBlendConstants]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetBlendConstants(commandBuffer, blendConstants, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthBounds, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDepthBounds");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthBounds]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDepthBounds);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDepthBounds");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthBounds]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDepthBounds");
        device_dispatch->CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDepthBounds");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthBounds]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                    uint32_t compareMask) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilCompareMask, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetStencilCompareMask");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilCompareMask]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetStencilCompareMask);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetStencilCompareMask");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilCompareMask]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetStencilCompareMask");
        device_dispatch->CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetStencilCompareMask");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilCompareMask]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilWriteMask, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetStencilWriteMask");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilWriteMask]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetStencilWriteMask);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetStencilWriteMask");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilWriteMask]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetStencilWriteMask");
        device_dispatch->CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetStencilWriteMask");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilWriteMask]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilReference, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetStencilReference");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilReference]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetStencilReference(commandBuffer, faceMask, reference, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetStencilReference);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetStencilReference");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilReference]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetStencilReference(commandBuffer, faceMask, reference, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetStencilReference");
        device_dispatch->CmdSetStencilReference(commandBuffer, faceMask, reference);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetStencilReference");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilReference]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetStencilReference(commandBuffer, faceMask, reference, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                              VkIndexType indexType) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindIndexBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBindIndexBuffer");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBindIndexBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBindIndexBuffer);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBindIndexBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBindIndexBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBindIndexBuffer");
        device_dispatch->CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBindIndexBuffer");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBindIndexBuffer]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                                const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindVertexBuffers, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBindVertexBuffers");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBindVertexBuffers]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |=
                vo->PreCallValidateCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBindVertexBuffers);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBindVertexBuffers");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBindVertexBuffers]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBindVertexBuffers");
        device_dispatch->CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBindVertexBuffers");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBindVertexBuffers]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                                   uint32_t firstVertex, uint32_t firstInstance) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDraw, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdDraw");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdDraw]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdDraw);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdDraw");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdDraw]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdDraw");
        device_dispatch->CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdDraw");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdDraw]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                          uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDrawIndexed, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdDrawIndexed");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdDrawIndexed]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset,
                                                      firstInstance, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdDrawIndexed);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdDrawIndexed");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdDrawIndexed]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance,
                                            record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdDrawIndexed");
        device_dispatch->CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdDrawIndexed");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdDrawIndexed]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance,
                                             record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                                           uint32_t stride) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDrawIndirect, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdDrawIndirect");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdDrawIndirect]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdDrawIndirect);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdDrawIndirect");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdDrawIndirect]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdDrawIndirect");
        device_dispatch->CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdDrawIndirect");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdDrawIndirect]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                  uint32_t drawCount, uint32_t stride) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDrawIndexedIndirect, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdDrawIndexedIndirect");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdDrawIndexedIndirect]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdDrawIndexedIndirect);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdDrawIndexedIndirect");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdDrawIndexedIndirect]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdDrawIndexedIndirect");
        device_dispatch->CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdDrawIndexedIndirect");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdDrawIndexedIndirect]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                        VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                        const VkImageBlit* pRegions, VkFilter filter) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBlitImage, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBlitImage");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBlitImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                                    pRegions, filter, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBlitImage);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBlitImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBlitImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions,
                                          filter, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBlitImage");
        device_dispatch->CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions,
                                      filter);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBlitImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBlitImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions,
                                           filter, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                                     const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                                     const VkImageSubresourceRange* pRanges) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdClearDepthStencilImage, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdClearDepthStencilImage");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdClearDepthStencilImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount,
                                                                 pRanges, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdClearDepthStencilImage);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdClearDepthStencilImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdClearDepthStencilImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges,
                                                       record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdClearDepthStencilImage");
        device_dispatch->CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdClearDepthStencilImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdClearDepthStencilImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges,
                                                        record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                               const VkClearAttachment* pAttachments, uint32_t rectCount,
                                               const VkClearRect* pRects) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdClearAttachments, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdClearAttachments");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdClearAttachments]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |=
                vo->PreCallValidateCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdClearAttachments);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdClearAttachments");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdClearAttachments]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdClearAttachments");
        device_dispatch->CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdClearAttachments");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdClearAttachments]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                           VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                           const VkImageResolve* pRegions) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResolveImage, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdResolveImage");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdResolveImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                                       regionCount, pRegions, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdResolveImage);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdResolveImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdResolveImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                             pRegions, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdResolveImage");
        device_dispatch->CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdResolveImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdResolveImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                              pRegions, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                              VkSubpassContents contents) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBeginRenderPass, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBeginRenderPass");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBeginRenderPass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBeginRenderPass);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBeginRenderPass");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBeginRenderPass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBeginRenderPass");
        device_dispatch->CmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBeginRenderPass");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBeginRenderPass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdNextSubpass, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdNextSubpass");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdNextSubpass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdNextSubpass(commandBuffer, contents, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdNextSubpass);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdNextSubpass");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdNextSubpass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdNextSubpass(commandBuffer, contents, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdNextSubpass");
        device_dispatch->CmdNextSubpass(commandBuffer, contents);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdNextSubpass");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdNextSubpass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdNextSubpass(commandBuffer, contents, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(VkCommandBuffer commandBuffer) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdEndRenderPass, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdEndRenderPass");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdEndRenderPass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdEndRenderPass(commandBuffer, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdEndRenderPass);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdEndRenderPass");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdEndRenderPass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdEndRenderPass(commandBuffer, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdEndRenderPass");
        device_dispatch->CmdEndRenderPass(commandBuffer);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdEndRenderPass");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdEndRenderPass]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdEndRenderPass(commandBuffer, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(VkDevice device, uint32_t bindInfoCount,
                                                 const VkBindBufferMemoryInfo* pBindInfos) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkBindBufferMemory2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkBindBufferMemory2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateBindBufferMemory2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateBindBufferMemory2(device, bindInfoCount, pBindInfos, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkBindBufferMemory2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkBindBufferMemory2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordBindBufferMemory2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordBindBufferMemory2(device, bindInfoCount, pBindInfos, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkBindBufferMemory2");
        result = device_dispatch->BindBufferMemory2(device, bindInfoCount, pBindInfos);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkBindBufferMemory2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordBindBufferMemory2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordBindBufferMemory2(device, bindInfoCount, pBindInfos, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkBindImageMemory2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkBindImageMemory2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateBindImageMemory2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateBindImageMemory2(device, bindInfoCount, pBindInfos, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkBindImageMemory2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkBindImageMemory2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordBindImageMemory2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordBindImageMemory2(device, bindInfoCount, pBindInfos, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkBindImageMemory2");
        result = device_dispatch->BindImageMemory2(device, bindInfoCount, pBindInfos);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkBindImageMemory2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordBindImageMemory2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordBindImageMemory2(device, bindInfoCount, pBindInfos, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                                            uint32_t remoteDeviceIndex,
                                                            VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceGroupPeerMemoryFeatures, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDeviceGroupPeerMemoryFeatures");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetDeviceGroupPeerMemoryFeatures]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex,
                                                                        pPeerMemoryFeatures, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDeviceGroupPeerMemoryFeatures);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDeviceGroupPeerMemoryFeatures");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetDeviceGroupPeerMemoryFeatures]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex,
                                                              pPeerMemoryFeatures, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetDeviceGroupPeerMemoryFeatures");
        device_dispatch->GetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex,
                                                          pPeerMemoryFeatures);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDeviceGroupPeerMemoryFeatures");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetDeviceGroupPeerMemoryFeatures]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex,
                                                               pPeerMemoryFeatures, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDeviceMask, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDeviceMask");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDeviceMask]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDeviceMask(commandBuffer, deviceMask, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDeviceMask);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDeviceMask");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDeviceMask]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDeviceMask(commandBuffer, deviceMask, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDeviceMask");
        device_dispatch->CmdSetDeviceMask(commandBuffer, deviceMask);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDeviceMask");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDeviceMask]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDeviceMask(commandBuffer, deviceMask, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount,
                                                             VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(instance);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkEnumeratePhysicalDeviceGroups, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    {
        VVL_ZoneScopedN("PreCallValidate_vkEnumeratePhysicalDeviceGroups");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount,
                                                                     pPhysicalDeviceGroupProperties, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkEnumeratePhysicalDeviceGroups);
    {
        VVL_ZoneScopedN("PreCallRecord_vkEnumeratePhysicalDeviceGroups");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties,
                                                           record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkEnumeratePhysicalDeviceGroups");
        result =
            instance_dispatch->EnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkEnumeratePhysicalDeviceGroups");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties,
                                                            record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo,
                                                       VkMemoryRequirements2* pMemoryRequirements) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetImageMemoryRequirements2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetImageMemoryRequirements2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetImageMemoryRequirements2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetImageMemoryRequirements2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetImageMemoryRequirements2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetImageMemoryRequirements2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetImageMemoryRequirements2");
        device_dispatch->GetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetImageMemoryRequirements2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetImageMemoryRequirements2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo,
                                                        VkMemoryRequirements2* pMemoryRequirements) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetBufferMemoryRequirements2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetBufferMemoryRequirements2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetBufferMemoryRequirements2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetBufferMemoryRequirements2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetBufferMemoryRequirements2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetBufferMemoryRequirements2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetBufferMemoryRequirements2");
        device_dispatch->GetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetBufferMemoryRequirements2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetBufferMemoryRequirements2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceFeatures2,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceFeatures2");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceFeatures2(physicalDevice, pFeatures, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceFeatures2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceFeatures2");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceFeatures2(physicalDevice, pFeatures, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceFeatures2");
        instance_dispatch->GetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceFeatures2");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceFeatures2(physicalDevice, pFeatures, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceProperties2,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceProperties2");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceProperties2(physicalDevice, pProperties, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceProperties2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceProperties2");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceProperties2(physicalDevice, pProperties, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceProperties2");
        instance_dispatch->GetPhysicalDeviceProperties2(physicalDevice, pProperties);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceProperties2");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceProperties2(physicalDevice, pProperties, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format,
                                                              VkFormatProperties2* pFormatProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceFormatProperties2,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceFormatProperties2");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceFormatProperties2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceFormatProperties2");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceFormatProperties2");
        instance_dispatch->GetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceFormatProperties2");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice,
                                                                       const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
                                                                       VkImageFormatProperties2* pImageFormatProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceImageFormatProperties2,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceImageFormatProperties2");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo,
                                                                               pImageFormatProperties, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceImageFormatProperties2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceImageFormatProperties2");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties,
                                                                     record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceImageFormatProperties2");
        result =
            instance_dispatch->GetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceImageFormatProperties2");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties,
                                                                      record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice,
                                                                   uint32_t* pQueueFamilyPropertyCount,
                                                                   VkQueueFamilyProperties2* pQueueFamilyProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceQueueFamilyProperties2,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceQueueFamilyProperties2");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount,
                                                                               pQueueFamilyProperties, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceQueueFamilyProperties2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceQueueFamilyProperties2");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount,
                                                                     pQueueFamilyProperties, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceQueueFamilyProperties2");
        instance_dispatch->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount,
                                                                   pQueueFamilyProperties);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceQueueFamilyProperties2");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount,
                                                                      pQueueFamilyProperties, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice,
                                                              VkPhysicalDeviceMemoryProperties2* pMemoryProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceMemoryProperties2,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceMemoryProperties2");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceMemoryProperties2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceMemoryProperties2");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceMemoryProperties2");
        instance_dispatch->GetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceMemoryProperties2");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceQueue2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDeviceQueue2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetDeviceQueue2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetDeviceQueue2(device, pQueueInfo, pQueue, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDeviceQueue2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDeviceQueue2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetDeviceQueue2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetDeviceQueue2(device, pQueueInfo, pQueue, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetDeviceQueue2");
        device_dispatch->GetDeviceQueue2(device, pQueueInfo, pQueue);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDeviceQueue2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetDeviceQueue2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetDeviceQueue2(device, pQueueInfo, pQueue, record_obj);
        }
    }
#if defined(VVL_TRACY_GPU)
    TracyVkCollector::Create(device, *pQueue, pQueueInfo->queueFamilyIndex);
#endif
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice,
                                                                     const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
                                                                     VkExternalBufferProperties* pExternalBufferProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceExternalBufferProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceExternalBufferProperties");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo,
                                                                                 pExternalBufferProperties, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceExternalBufferProperties);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceExternalBufferProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo,
                                                                       pExternalBufferProperties, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceExternalBufferProperties");
        instance_dispatch->GetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo,
                                                                     pExternalBufferProperties);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceExternalBufferProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo,
                                                                        pExternalBufferProperties, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice,
                                                                    const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
                                                                    VkExternalFenceProperties* pExternalFenceProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceExternalFenceProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceExternalFenceProperties");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo,
                                                                                pExternalFenceProperties, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceExternalFenceProperties);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceExternalFenceProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties,
                                                                      record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceExternalFenceProperties");
        instance_dispatch->GetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceExternalFenceProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties,
                                                                       record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceExternalSemaphoreProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceExternalSemaphoreProperties");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo,
                                                                                    pExternalSemaphoreProperties, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceExternalSemaphoreProperties);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceExternalSemaphoreProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo,
                                                                          pExternalSemaphoreProperties, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceExternalSemaphoreProperties");
        instance_dispatch->GetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo,
                                                                        pExternalSemaphoreProperties);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceExternalSemaphoreProperties");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo,
                                                                           pExternalSemaphoreProperties, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                           uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDispatchBase, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdDispatchBase");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdDispatchBase]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                                       groupCountZ, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdDispatchBase);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdDispatchBase");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdDispatchBase]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                             groupCountZ, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdDispatchBase");
        device_dispatch->CmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdDispatchBase");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdDispatchBase]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                              groupCountZ, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                         VkDescriptorSetLayoutSupport* pSupport) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDescriptorSetLayoutSupport, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDescriptorSetLayoutSupport");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetDescriptorSetLayoutSupport]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDescriptorSetLayoutSupport);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDescriptorSetLayoutSupport");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetDescriptorSetLayoutSupport]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetDescriptorSetLayoutSupport");
        device_dispatch->GetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDescriptorSetLayoutSupport");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetDescriptorSetLayoutSupport]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            VkSamplerYcbcrConversion* pYcbcrConversion) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateSamplerYcbcrConversion, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateSamplerYcbcrConversion");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateSamplerYcbcrConversion]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateSamplerYcbcrConversion);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateSamplerYcbcrConversion");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateSamplerYcbcrConversion]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateSamplerYcbcrConversion");
        result = device_dispatch->CreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateSamplerYcbcrConversion");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateSamplerYcbcrConversion]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion,
                                                         const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroySamplerYcbcrConversion, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroySamplerYcbcrConversion");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroySamplerYcbcrConversion]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroySamplerYcbcrConversion);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroySamplerYcbcrConversion");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroySamplerYcbcrConversion]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroySamplerYcbcrConversion");
        device_dispatch->DestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroySamplerYcbcrConversion");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroySamplerYcbcrConversion]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL ResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkResetQueryPool, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkResetQueryPool");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateResetQueryPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateResetQueryPool(device, queryPool, firstQuery, queryCount, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkResetQueryPool);
    {
        VVL_ZoneScopedN("PreCallRecord_vkResetQueryPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordResetQueryPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordResetQueryPool(device, queryPool, firstQuery, queryCount, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkResetQueryPool");
        device_dispatch->ResetQueryPool(device, queryPool, firstQuery, queryCount);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkResetQueryPool");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordResetQueryPool]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordResetQueryPool(device, queryPool, firstQuery, queryCount, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetSemaphoreCounterValue, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetSemaphoreCounterValue");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetSemaphoreCounterValue]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetSemaphoreCounterValue(device, semaphore, pValue, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetSemaphoreCounterValue);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetSemaphoreCounterValue");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetSemaphoreCounterValue]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetSemaphoreCounterValue(device, semaphore, pValue, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetSemaphoreCounterValue");
        result = device_dispatch->GetSemaphoreCounterValue(device, semaphore, pValue);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetSemaphoreCounterValue");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetSemaphoreCounterValue]) {
            if (!vo) {
                continue;
            }
            vvl::base::Device::BlockingOperationGuard lock(vo);
            vo->PostCallRecordGetSemaphoreCounterValue(device, semaphore, pValue, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkWaitSemaphores, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkWaitSemaphores");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateWaitSemaphores]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateWaitSemaphores(device, pWaitInfo, timeout, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkWaitSemaphores);
    {
        VVL_ZoneScopedN("PreCallRecord_vkWaitSemaphores");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordWaitSemaphores]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordWaitSemaphores(device, pWaitInfo, timeout, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkWaitSemaphores");
        result = device_dispatch->WaitSemaphores(device, pWaitInfo, timeout);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkWaitSemaphores");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordWaitSemaphores]) {
            if (!vo) {
                continue;
            }
            vvl::base::Device::BlockingOperationGuard lock(vo);
            vo->PostCallRecordWaitSemaphores(device, pWaitInfo, timeout, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSignalSemaphore, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkSignalSemaphore");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateSignalSemaphore]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateSignalSemaphore(device, pSignalInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkSignalSemaphore);
    {
        VVL_ZoneScopedN("PreCallRecord_vkSignalSemaphore");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordSignalSemaphore]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordSignalSemaphore(device, pSignalInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkSignalSemaphore");
        result = device_dispatch->SignalSemaphore(device, pSignalInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkSignalSemaphore");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordSignalSemaphore]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordSignalSemaphore(device, pSignalInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetBufferDeviceAddress, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetBufferDeviceAddress");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetBufferDeviceAddress]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetBufferDeviceAddress(device, pInfo, error_obj);
            if (skip) return 0;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetBufferDeviceAddress);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetBufferDeviceAddress");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetBufferDeviceAddress]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetBufferDeviceAddress(device, pInfo, record_obj);
        }
    }
    VkDeviceAddress result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetBufferDeviceAddress");
        result = device_dispatch->GetBufferDeviceAddress(device, pInfo);
    }
    record_obj.device_address = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetBufferDeviceAddress");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetBufferDeviceAddress]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetBufferDeviceAddress(device, pInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetBufferOpaqueCaptureAddress, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetBufferOpaqueCaptureAddress");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetBufferOpaqueCaptureAddress]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetBufferOpaqueCaptureAddress(device, pInfo, error_obj);
            if (skip) return 0;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetBufferOpaqueCaptureAddress);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetBufferOpaqueCaptureAddress");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetBufferOpaqueCaptureAddress]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetBufferOpaqueCaptureAddress(device, pInfo, record_obj);
        }
    }
    uint64_t result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetBufferOpaqueCaptureAddress");
        result = device_dispatch->GetBufferOpaqueCaptureAddress(device, pInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetBufferOpaqueCaptureAddress");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetBufferOpaqueCaptureAddress]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetBufferOpaqueCaptureAddress(device, pInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress(VkDevice device,
                                                                   const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceMemoryOpaqueCaptureAddress, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDeviceMemoryOpaqueCaptureAddress");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetDeviceMemoryOpaqueCaptureAddress]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetDeviceMemoryOpaqueCaptureAddress(device, pInfo, error_obj);
            if (skip) return 0;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDeviceMemoryOpaqueCaptureAddress);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDeviceMemoryOpaqueCaptureAddress");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetDeviceMemoryOpaqueCaptureAddress]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetDeviceMemoryOpaqueCaptureAddress(device, pInfo, record_obj);
        }
    }
    uint64_t result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetDeviceMemoryOpaqueCaptureAddress");
        result = device_dispatch->GetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDeviceMemoryOpaqueCaptureAddress");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetDeviceMemoryOpaqueCaptureAddress]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetDeviceMemoryOpaqueCaptureAddress(device, pInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                uint32_t stride) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDrawIndirectCount, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdDrawIndirectCount");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdDrawIndirectCount]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                            maxDrawCount, stride, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdDrawIndirectCount);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdDrawIndirectCount");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdDrawIndirectCount]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                                  stride, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdDrawIndirectCount");
        device_dispatch->CmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdDrawIndirectCount");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdDrawIndirectCount]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                                   stride, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                       VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                       uint32_t stride) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDrawIndexedIndirectCount,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdDrawIndexedIndirectCount");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdDrawIndexedIndirectCount]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                                   maxDrawCount, stride, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdDrawIndexedIndirectCount);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdDrawIndexedIndirectCount");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdDrawIndexedIndirectCount]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                         maxDrawCount, stride, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdDrawIndexedIndirectCount");
        device_dispatch->CmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                                     stride);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdDrawIndexedIndirectCount");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdDrawIndexedIndirectCount]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                          maxDrawCount, stride, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateRenderPass2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateRenderPass2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateRenderPass2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateRenderPass2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateRenderPass2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateRenderPass2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateRenderPass2");
        result = device_dispatch->CreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateRenderPass2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateRenderPass2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                               const VkSubpassBeginInfo* pSubpassBeginInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBeginRenderPass2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBeginRenderPass2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBeginRenderPass2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBeginRenderPass2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBeginRenderPass2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBeginRenderPass2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBeginRenderPass2");
        device_dispatch->CmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBeginRenderPass2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBeginRenderPass2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                           const VkSubpassEndInfo* pSubpassEndInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdNextSubpass2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdNextSubpass2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdNextSubpass2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdNextSubpass2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdNextSubpass2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdNextSubpass2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdNextSubpass2");
        device_dispatch->CmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdNextSubpass2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdNextSubpass2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdEndRenderPass2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdEndRenderPass2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdEndRenderPass2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdEndRenderPass2(commandBuffer, pSubpassEndInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdEndRenderPass2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdEndRenderPass2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdEndRenderPass2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdEndRenderPass2(commandBuffer, pSubpassEndInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdEndRenderPass2");
        device_dispatch->CmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdEndRenderPass2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdEndRenderPass2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdEndRenderPass2(commandBuffer, pSubpassEndInfo, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreatePrivateDataSlot, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreatePrivateDataSlot");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreatePrivateDataSlot]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreatePrivateDataSlot);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreatePrivateDataSlot");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreatePrivateDataSlot]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreatePrivateDataSlot");
        result = device_dispatch->CreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreatePrivateDataSlot");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreatePrivateDataSlot]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                  const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyPrivateDataSlot, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyPrivateDataSlot");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDestroyPrivateDataSlot]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDestroyPrivateDataSlot(device, privateDataSlot, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyPrivateDataSlot);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyPrivateDataSlot");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDestroyPrivateDataSlot]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDestroyPrivateDataSlot(device, privateDataSlot, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyPrivateDataSlot");
        device_dispatch->DestroyPrivateDataSlot(device, privateDataSlot, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyPrivateDataSlot");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDestroyPrivateDataSlot]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDestroyPrivateDataSlot(device, privateDataSlot, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL SetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle,
                                              VkPrivateDataSlot privateDataSlot, uint64_t data) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSetPrivateData, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkSetPrivateData");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateSetPrivateData]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateSetPrivateData(device, objectType, objectHandle, privateDataSlot, data, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkSetPrivateData);
    {
        VVL_ZoneScopedN("PreCallRecord_vkSetPrivateData");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordSetPrivateData]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordSetPrivateData(device, objectType, objectHandle, privateDataSlot, data, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkSetPrivateData");
        result = device_dispatch->SetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkSetPrivateData");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordSetPrivateData]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordSetPrivateData(device, objectType, objectHandle, privateDataSlot, data, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle,
                                          VkPrivateDataSlot privateDataSlot, uint64_t* pData) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPrivateData, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPrivateData");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetPrivateData]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetPrivateData(device, objectType, objectHandle, privateDataSlot, pData, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPrivateData);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPrivateData");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetPrivateData]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetPrivateData(device, objectType, objectHandle, privateDataSlot, pData, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPrivateData");
        device_dispatch->GetPrivateData(device, objectType, objectHandle, privateDataSlot, pData);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPrivateData");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetPrivateData]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetPrivateData(device, objectType, objectHandle, privateDataSlot, pData, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdPipelineBarrier2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdPipelineBarrier2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdPipelineBarrier2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdPipelineBarrier2(commandBuffer, pDependencyInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdPipelineBarrier2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdPipelineBarrier2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdPipelineBarrier2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdPipelineBarrier2(commandBuffer, pDependencyInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdPipelineBarrier2");
        device_dispatch->CmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdPipelineBarrier2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdPipelineBarrier2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdPipelineBarrier2(commandBuffer, pDependencyInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                              uint32_t query) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWriteTimestamp2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdWriteTimestamp2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdWriteTimestamp2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdWriteTimestamp2(commandBuffer, stage, queryPool, query, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdWriteTimestamp2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdWriteTimestamp2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdWriteTimestamp2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdWriteTimestamp2(commandBuffer, stage, queryPool, query, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdWriteTimestamp2");
        device_dispatch->CmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdWriteTimestamp2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdWriteTimestamp2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdWriteTimestamp2(commandBuffer, stage, queryPool, query, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(queue);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueSubmit2, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    {
        VVL_ZoneScopedN("PreCallValidate_vkQueueSubmit2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateQueueSubmit2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateQueueSubmit2(queue, submitCount, pSubmits, fence, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkQueueSubmit2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkQueueSubmit2");
        VVL_TracyVkNamedZoneStart(GetTracyVkCtx(), queue, "gpu_PreCallRecordvkQueueSubmit2", pre_call_record_gpu_zone);

        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordQueueSubmit2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordQueueSubmit2(queue, submitCount, pSubmits, fence, record_obj);
        }

        VVL_TracyVkNamedZoneEnd(pre_call_record_gpu_zone, queue);
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkQueueSubmit2");

        VVL_TracyVkNamedZoneStart(GetTracyVkCtx(), queue, "gpu_vkQueueSubmit2", submit_gpu_zone);
        result = device_dispatch->QueueSubmit2(queue, submitCount, pSubmits, fence);

        VVL_TracyVkNamedZoneEnd(submit_gpu_zone, queue);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkQueueSubmit2");

        VVL_TracyVkNamedZoneStart(GetTracyVkCtx(), queue, "gpu_PostCallRecordvkQueueSubmit2", post_call_record_gpu_zone);

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordQueueSubmit2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordQueueSubmit2(queue, submitCount, pSubmits, fence, record_obj);
        }

        VVL_TracyVkNamedZoneEnd(post_call_record_gpu_zone, queue);
    }
#if defined(VVL_TRACY_GPU)
    TracyVkCollector::TrySubmitCollectCb(queue);
#endif
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyBuffer2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyBuffer2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyBuffer2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyBuffer2(commandBuffer, pCopyBufferInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyBuffer2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyBuffer2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyBuffer2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyBuffer2(commandBuffer, pCopyBufferInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyBuffer2");
        device_dispatch->CmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyBuffer2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyBuffer2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyBuffer2(commandBuffer, pCopyBufferInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyImage2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyImage2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyImage2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyImage2(commandBuffer, pCopyImageInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyImage2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyImage2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyImage2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyImage2(commandBuffer, pCopyImageInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyImage2");
        device_dispatch->CmdCopyImage2(commandBuffer, pCopyImageInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyImage2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyImage2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyImage2(commandBuffer, pCopyImageInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                                 const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyBufferToImage2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyBufferToImage2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyBufferToImage2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyBufferToImage2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyBufferToImage2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyBufferToImage2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyBufferToImage2");
        device_dispatch->CmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyBufferToImage2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyBufferToImage2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                                 const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyImageToBuffer2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyImageToBuffer2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyImageToBuffer2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyImageToBuffer2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyImageToBuffer2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyImageToBuffer2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyImageToBuffer2");
        device_dispatch->CmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyImageToBuffer2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyImageToBuffer2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo,
                                                             VkMemoryRequirements2* pMemoryRequirements) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceBufferMemoryRequirements, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDeviceBufferMemoryRequirements");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetDeviceBufferMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDeviceBufferMemoryRequirements);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDeviceBufferMemoryRequirements");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetDeviceBufferMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetDeviceBufferMemoryRequirements");
        device_dispatch->GetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDeviceBufferMemoryRequirements");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetDeviceBufferMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo,
                                                            VkMemoryRequirements2* pMemoryRequirements) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceImageMemoryRequirements, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDeviceImageMemoryRequirements");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetDeviceImageMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDeviceImageMemoryRequirements);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDeviceImageMemoryRequirements");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetDeviceImageMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetDeviceImageMemoryRequirements");
        device_dispatch->GetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDeviceImageMemoryRequirements");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetDeviceImageMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo,
                                                                  uint32_t* pSparseMemoryRequirementCount,
                                                                  VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceImageSparseMemoryRequirements, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDeviceImageSparseMemoryRequirements");
        for (const auto& vo :
             device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetDeviceImageSparseMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount,
                                                                              pSparseMemoryRequirements, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDeviceImageSparseMemoryRequirements);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDeviceImageSparseMemoryRequirements");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetDeviceImageSparseMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount,
                                                                    pSparseMemoryRequirements, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetDeviceImageSparseMemoryRequirements");
        device_dispatch->GetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount,
                                                                pSparseMemoryRequirements);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDeviceImageSparseMemoryRequirements");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetDeviceImageSparseMemoryRequirements]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount,
                                                                     pSparseMemoryRequirements, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetEvent2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetEvent2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetEvent2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetEvent2(commandBuffer, event, pDependencyInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetEvent2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetEvent2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetEvent2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetEvent2(commandBuffer, event, pDependencyInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetEvent2");
        device_dispatch->CmdSetEvent2(commandBuffer, event, pDependencyInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetEvent2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetEvent2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetEvent2(commandBuffer, event, pDependencyInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResetEvent2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdResetEvent2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdResetEvent2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdResetEvent2(commandBuffer, event, stageMask, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdResetEvent2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdResetEvent2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdResetEvent2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdResetEvent2(commandBuffer, event, stageMask, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdResetEvent2");
        device_dispatch->CmdResetEvent2(commandBuffer, event, stageMask);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdResetEvent2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdResetEvent2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdResetEvent2(commandBuffer, event, stageMask, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                          const VkDependencyInfo* pDependencyInfos) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWaitEvents2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdWaitEvents2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdWaitEvents2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdWaitEvents2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdWaitEvents2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdWaitEvents2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdWaitEvents2");
        device_dispatch->CmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdWaitEvents2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdWaitEvents2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBlitImage2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBlitImage2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBlitImage2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBlitImage2(commandBuffer, pBlitImageInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBlitImage2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBlitImage2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBlitImage2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBlitImage2(commandBuffer, pBlitImageInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBlitImage2");
        device_dispatch->CmdBlitImage2(commandBuffer, pBlitImageInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBlitImage2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBlitImage2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBlitImage2(commandBuffer, pBlitImageInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResolveImage2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdResolveImage2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdResolveImage2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdResolveImage2(commandBuffer, pResolveImageInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdResolveImage2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdResolveImage2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdResolveImage2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdResolveImage2(commandBuffer, pResolveImageInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdResolveImage2");
        device_dispatch->CmdResolveImage2(commandBuffer, pResolveImageInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdResolveImage2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdResolveImage2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdResolveImage2(commandBuffer, pResolveImageInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBeginRendering, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBeginRendering");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBeginRendering]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBeginRendering(commandBuffer, pRenderingInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBeginRendering);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBeginRendering");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBeginRendering]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBeginRendering(commandBuffer, pRenderingInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBeginRendering");
        device_dispatch->CmdBeginRendering(commandBuffer, pRenderingInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBeginRendering");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBeginRendering]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBeginRendering(commandBuffer, pRenderingInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndRendering(VkCommandBuffer commandBuffer) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdEndRendering, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdEndRendering");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdEndRendering]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdEndRendering(commandBuffer, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdEndRendering);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdEndRendering");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdEndRendering]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdEndRendering(commandBuffer, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdEndRendering");
        device_dispatch->CmdEndRendering(commandBuffer);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdEndRendering");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdEndRendering]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdEndRendering(commandBuffer, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetCullMode, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetCullMode");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetCullMode]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetCullMode(commandBuffer, cullMode, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetCullMode);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetCullMode");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetCullMode]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetCullMode(commandBuffer, cullMode, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetCullMode");
        device_dispatch->CmdSetCullMode(commandBuffer, cullMode);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetCullMode");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetCullMode]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetCullMode(commandBuffer, cullMode, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetFrontFace, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetFrontFace");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetFrontFace]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetFrontFace(commandBuffer, frontFace, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetFrontFace);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetFrontFace");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetFrontFace]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetFrontFace(commandBuffer, frontFace, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetFrontFace");
        device_dispatch->CmdSetFrontFace(commandBuffer, frontFace);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetFrontFace");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetFrontFace]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetFrontFace(commandBuffer, frontFace, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetPrimitiveTopology, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetPrimitiveTopology");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetPrimitiveTopology]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetPrimitiveTopology(commandBuffer, primitiveTopology, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetPrimitiveTopology);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetPrimitiveTopology");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetPrimitiveTopology]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetPrimitiveTopology(commandBuffer, primitiveTopology, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetPrimitiveTopology");
        device_dispatch->CmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetPrimitiveTopology");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetPrimitiveTopology]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetPrimitiveTopology(commandBuffer, primitiveTopology, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                   const VkViewport* pViewports) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetViewportWithCount, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetViewportWithCount");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetViewportWithCount]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetViewportWithCount);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetViewportWithCount");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetViewportWithCount]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetViewportWithCount");
        device_dispatch->CmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetViewportWithCount");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetViewportWithCount]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetScissorWithCount, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetScissorWithCount");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetScissorWithCount]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetScissorWithCount);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetScissorWithCount");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetScissorWithCount]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetScissorWithCount");
        device_dispatch->CmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetScissorWithCount");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetScissorWithCount]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                                 const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                 const VkDeviceSize* pStrides) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindVertexBuffers2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBindVertexBuffers2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBindVertexBuffers2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                                             pStrides, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBindVertexBuffers2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBindVertexBuffers2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBindVertexBuffers2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides,
                                                   record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBindVertexBuffers2");
        device_dispatch->CmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBindVertexBuffers2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBindVertexBuffers2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides,
                                                    record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthTestEnable, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDepthTestEnable");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthTestEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDepthTestEnable(commandBuffer, depthTestEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDepthTestEnable);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDepthTestEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthTestEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDepthTestEnable(commandBuffer, depthTestEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDepthTestEnable");
        device_dispatch->CmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDepthTestEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthTestEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDepthTestEnable(commandBuffer, depthTestEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthWriteEnable, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDepthWriteEnable");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthWriteEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDepthWriteEnable);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDepthWriteEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthWriteEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDepthWriteEnable");
        device_dispatch->CmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDepthWriteEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthWriteEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthCompareOp, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDepthCompareOp");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthCompareOp]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDepthCompareOp(commandBuffer, depthCompareOp, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDepthCompareOp);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDepthCompareOp");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthCompareOp]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDepthCompareOp(commandBuffer, depthCompareOp, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDepthCompareOp");
        device_dispatch->CmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDepthCompareOp");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthCompareOp]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDepthCompareOp(commandBuffer, depthCompareOp, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthBoundsTestEnable,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDepthBoundsTestEnable");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthBoundsTestEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDepthBoundsTestEnable);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDepthBoundsTestEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthBoundsTestEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDepthBoundsTestEnable");
        device_dispatch->CmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDepthBoundsTestEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthBoundsTestEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilTestEnable, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetStencilTestEnable");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilTestEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetStencilTestEnable(commandBuffer, stencilTestEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetStencilTestEnable);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetStencilTestEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilTestEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetStencilTestEnable(commandBuffer, stencilTestEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetStencilTestEnable");
        device_dispatch->CmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetStencilTestEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilTestEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetStencilTestEnable(commandBuffer, stencilTestEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                           VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilOp, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetStencilOp");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilOp]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetStencilOp);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetStencilOp");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilOp]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetStencilOp");
        device_dispatch->CmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetStencilOp");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilOp]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetRasterizerDiscardEnable,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetRasterizerDiscardEnable");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetRasterizerDiscardEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetRasterizerDiscardEnable);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetRasterizerDiscardEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetRasterizerDiscardEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetRasterizerDiscardEnable");
        device_dispatch->CmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetRasterizerDiscardEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetRasterizerDiscardEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthBiasEnable, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDepthBiasEnable");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthBiasEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDepthBiasEnable);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDepthBiasEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthBiasEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDepthBiasEnable");
        device_dispatch->CmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDepthBiasEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthBiasEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetPrimitiveRestartEnable,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetPrimitiveRestartEnable");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetPrimitiveRestartEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetPrimitiveRestartEnable);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetPrimitiveRestartEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetPrimitiveRestartEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetPrimitiveRestartEnable");
        device_dispatch->CmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetPrimitiveRestartEnable");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetPrimitiveRestartEnable]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL MapMemory2(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkMapMemory2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkMapMemory2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateMapMemory2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateMapMemory2(device, pMemoryMapInfo, ppData, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkMapMemory2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkMapMemory2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordMapMemory2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordMapMemory2(device, pMemoryMapInfo, ppData, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkMapMemory2");
        result = device_dispatch->MapMemory2(device, pMemoryMapInfo, ppData);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkMapMemory2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordMapMemory2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordMapMemory2(device, pMemoryMapInfo, ppData, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL UnmapMemory2(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkUnmapMemory2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkUnmapMemory2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateUnmapMemory2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateUnmapMemory2(device, pMemoryUnmapInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkUnmapMemory2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkUnmapMemory2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordUnmapMemory2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordUnmapMemory2(device, pMemoryUnmapInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkUnmapMemory2");
        result = device_dispatch->UnmapMemory2(device, pMemoryUnmapInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkUnmapMemory2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordUnmapMemory2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordUnmapMemory2(device, pMemoryUnmapInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSubresourceLayout(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo,
                                                           VkSubresourceLayout2* pLayout) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceImageSubresourceLayout, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDeviceImageSubresourceLayout");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetDeviceImageSubresourceLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetDeviceImageSubresourceLayout(device, pInfo, pLayout, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDeviceImageSubresourceLayout);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDeviceImageSubresourceLayout");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetDeviceImageSubresourceLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetDeviceImageSubresourceLayout(device, pInfo, pLayout, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetDeviceImageSubresourceLayout");
        device_dispatch->GetDeviceImageSubresourceLayout(device, pInfo, pLayout);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDeviceImageSubresourceLayout");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetDeviceImageSubresourceLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetDeviceImageSubresourceLayout(device, pInfo, pLayout, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource,
                                                      VkSubresourceLayout2* pLayout) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetImageSubresourceLayout2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetImageSubresourceLayout2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetImageSubresourceLayout2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetImageSubresourceLayout2(device, image, pSubresource, pLayout, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetImageSubresourceLayout2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetImageSubresourceLayout2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetImageSubresourceLayout2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetImageSubresourceLayout2(device, image, pSubresource, pLayout, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetImageSubresourceLayout2");
        device_dispatch->GetImageSubresourceLayout2(device, image, pSubresource, pLayout);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetImageSubresourceLayout2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetImageSubresourceLayout2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetImageSubresourceLayout2(device, image, pSubresource, pLayout, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToImage(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCopyMemoryToImage, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCopyMemoryToImage");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCopyMemoryToImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCopyMemoryToImage(device, pCopyMemoryToImageInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCopyMemoryToImage);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCopyMemoryToImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCopyMemoryToImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCopyMemoryToImage(device, pCopyMemoryToImageInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCopyMemoryToImage");
        result = device_dispatch->CopyMemoryToImage(device, pCopyMemoryToImageInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCopyMemoryToImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCopyMemoryToImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCopyMemoryToImage(device, pCopyMemoryToImageInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CopyImageToMemory(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCopyImageToMemory, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCopyImageToMemory");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCopyImageToMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCopyImageToMemory(device, pCopyImageToMemoryInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCopyImageToMemory);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCopyImageToMemory");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCopyImageToMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCopyImageToMemory(device, pCopyImageToMemoryInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCopyImageToMemory");
        result = device_dispatch->CopyImageToMemory(device, pCopyImageToMemoryInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCopyImageToMemory");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCopyImageToMemory]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCopyImageToMemory(device, pCopyImageToMemoryInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CopyImageToImage(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCopyImageToImage, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCopyImageToImage");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCopyImageToImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCopyImageToImage(device, pCopyImageToImageInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCopyImageToImage);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCopyImageToImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCopyImageToImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCopyImageToImage(device, pCopyImageToImageInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCopyImageToImage");
        result = device_dispatch->CopyImageToImage(device, pCopyImageToImageInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCopyImageToImage");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCopyImageToImage]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCopyImageToImage(device, pCopyImageToImageInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL TransitionImageLayout(VkDevice device, uint32_t transitionCount,
                                                     const VkHostImageLayoutTransitionInfo* pTransitions) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkTransitionImageLayout, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkTransitionImageLayout");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateTransitionImageLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateTransitionImageLayout(device, transitionCount, pTransitions, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkTransitionImageLayout);
    {
        VVL_ZoneScopedN("PreCallRecord_vkTransitionImageLayout");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordTransitionImageLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordTransitionImageLayout(device, transitionCount, pTransitions, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkTransitionImageLayout");
        result = device_dispatch->TransitionImageLayout(device, transitionCount, pTransitions);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkTransitionImageLayout");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordTransitionImageLayout]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordTransitionImageLayout(device, transitionCount, pTransitions, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSet(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                                const VkWriteDescriptorSet* pDescriptorWrites) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdPushDescriptorSet, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdPushDescriptorSet");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdPushDescriptorSet]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdPushDescriptorSet(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount,
                                                            pDescriptorWrites, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdPushDescriptorSet);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdPushDescriptorSet");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdPushDescriptorSet]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdPushDescriptorSet(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount,
                                                  pDescriptorWrites, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdPushDescriptorSet");
        device_dispatch->CmdPushDescriptorSet(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount,
                                              pDescriptorWrites);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdPushDescriptorSet");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdPushDescriptorSet]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdPushDescriptorSet(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount,
                                                   pDescriptorWrites, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets2(VkCommandBuffer commandBuffer,
                                                  const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindDescriptorSets2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBindDescriptorSets2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBindDescriptorSets2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBindDescriptorSets2(commandBuffer, pBindDescriptorSetsInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBindDescriptorSets2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBindDescriptorSets2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBindDescriptorSets2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBindDescriptorSets2(commandBuffer, pBindDescriptorSetsInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBindDescriptorSets2");
        device_dispatch->CmdBindDescriptorSets2(commandBuffer, pBindDescriptorSetsInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBindDescriptorSets2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBindDescriptorSets2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBindDescriptorSets2(commandBuffer, pBindDescriptorSetsInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPushConstants2(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdPushConstants2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdPushConstants2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdPushConstants2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdPushConstants2(commandBuffer, pPushConstantsInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdPushConstants2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdPushConstants2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdPushConstants2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdPushConstants2(commandBuffer, pPushConstantsInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdPushConstants2");
        device_dispatch->CmdPushConstants2(commandBuffer, pPushConstantsInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdPushConstants2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdPushConstants2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdPushConstants2(commandBuffer, pPushConstantsInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSet2(VkCommandBuffer commandBuffer,
                                                 const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdPushDescriptorSet2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdPushDescriptorSet2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdPushDescriptorSet2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdPushDescriptorSet2(commandBuffer, pPushDescriptorSetInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdPushDescriptorSet2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdPushDescriptorSet2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdPushDescriptorSet2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdPushDescriptorSet2(commandBuffer, pPushDescriptorSetInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdPushDescriptorSet2");
        device_dispatch->CmdPushDescriptorSet2(commandBuffer, pPushDescriptorSetInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdPushDescriptorSet2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdPushDescriptorSet2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdPushDescriptorSet2(commandBuffer, pPushDescriptorSetInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineStipple(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                             uint16_t lineStipplePattern) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetLineStipple, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetLineStipple");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetLineStipple]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetLineStipple(commandBuffer, lineStippleFactor, lineStipplePattern, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetLineStipple);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetLineStipple");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetLineStipple]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetLineStipple(commandBuffer, lineStippleFactor, lineStipplePattern, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetLineStipple");
        device_dispatch->CmdSetLineStipple(commandBuffer, lineStippleFactor, lineStipplePattern);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetLineStipple");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetLineStipple]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetLineStipple(commandBuffer, lineStippleFactor, lineStipplePattern, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer2(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               VkDeviceSize size, VkIndexType indexType) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindIndexBuffer2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBindIndexBuffer2");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBindIndexBuffer2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBindIndexBuffer2(commandBuffer, buffer, offset, size, indexType, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBindIndexBuffer2);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBindIndexBuffer2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBindIndexBuffer2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBindIndexBuffer2(commandBuffer, buffer, offset, size, indexType, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBindIndexBuffer2");
        device_dispatch->CmdBindIndexBuffer2(commandBuffer, buffer, offset, size, indexType);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBindIndexBuffer2");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBindIndexBuffer2]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBindIndexBuffer2(commandBuffer, buffer, offset, size, indexType, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetRenderingAreaGranularity(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo,
                                                       VkExtent2D* pGranularity) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetRenderingAreaGranularity, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetRenderingAreaGranularity");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetRenderingAreaGranularity]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetRenderingAreaGranularity(device, pRenderingAreaInfo, pGranularity, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetRenderingAreaGranularity);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetRenderingAreaGranularity");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetRenderingAreaGranularity]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetRenderingAreaGranularity(device, pRenderingAreaInfo, pGranularity, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetRenderingAreaGranularity");
        device_dispatch->GetRenderingAreaGranularity(device, pRenderingAreaInfo, pGranularity);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetRenderingAreaGranularity");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetRenderingAreaGranularity]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetRenderingAreaGranularity(device, pRenderingAreaInfo, pGranularity, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetRenderingAttachmentLocations(VkCommandBuffer commandBuffer,
                                                              const VkRenderingAttachmentLocationInfo* pLocationInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetRenderingAttachmentLocations,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetRenderingAttachmentLocations");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetRenderingAttachmentLocations]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetRenderingAttachmentLocations(commandBuffer, pLocationInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetRenderingAttachmentLocations);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetRenderingAttachmentLocations");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetRenderingAttachmentLocations]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetRenderingAttachmentLocations(commandBuffer, pLocationInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetRenderingAttachmentLocations");
        device_dispatch->CmdSetRenderingAttachmentLocations(commandBuffer, pLocationInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetRenderingAttachmentLocations");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetRenderingAttachmentLocations]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetRenderingAttachmentLocations(commandBuffer, pLocationInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetRenderingInputAttachmentIndices(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetRenderingInputAttachmentIndices,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetRenderingInputAttachmentIndices");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetRenderingInputAttachmentIndices]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetRenderingInputAttachmentIndices(commandBuffer, pInputAttachmentIndexInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetRenderingInputAttachmentIndices);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetRenderingInputAttachmentIndices");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetRenderingInputAttachmentIndices]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetRenderingInputAttachmentIndices(commandBuffer, pInputAttachmentIndexInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetRenderingInputAttachmentIndices");
        device_dispatch->CmdSetRenderingInputAttachmentIndices(commandBuffer, pInputAttachmentIndexInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetRenderingInputAttachmentIndices");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetRenderingInputAttachmentIndices]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetRenderingInputAttachmentIndices(commandBuffer, pInputAttachmentIndexInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetCommandPoolMemoryConsumption(VkDevice device, VkCommandPool commandPool,
                                                           VkCommandBuffer commandBuffer,
                                                           VkCommandPoolMemoryConsumption* pConsumption) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetCommandPoolMemoryConsumption, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetCommandPoolMemoryConsumption");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetCommandPoolMemoryConsumption]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetCommandPoolMemoryConsumption(device, commandPool, commandBuffer, pConsumption, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetCommandPoolMemoryConsumption);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetCommandPoolMemoryConsumption");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetCommandPoolMemoryConsumption]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetCommandPoolMemoryConsumption(device, commandPool, commandBuffer, pConsumption, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetCommandPoolMemoryConsumption");
        device_dispatch->GetCommandPoolMemoryConsumption(device, commandPool, commandBuffer, pConsumption);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetCommandPoolMemoryConsumption");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetCommandPoolMemoryConsumption]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetCommandPoolMemoryConsumption(device, commandPool, commandBuffer, pConsumption, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetFaultData(VkDevice device, VkFaultQueryBehavior faultQueryBehavior, VkBool32* pUnrecordedFaults,
                                            uint32_t* pFaultCount, VkFaultData* pFaults) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetFaultData, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetFaultData");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetFaultData]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetFaultData(device, faultQueryBehavior, pUnrecordedFaults, pFaultCount, pFaults, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetFaultData);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetFaultData");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetFaultData]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetFaultData(device, faultQueryBehavior, pUnrecordedFaults, pFaultCount, pFaults, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetFaultData");
        result = device_dispatch->GetFaultData(device, faultQueryBehavior, pUnrecordedFaults, pFaultCount, pFaults);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetFaultData");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetFaultData]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetFaultData(device, faultQueryBehavior, pUnrecordedFaults, pFaultCount, pFaults, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(instance);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroySurfaceKHR, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroySurfaceKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateDestroySurfaceKHR(instance, surface, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroySurfaceKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroySurfaceKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordDestroySurfaceKHR(instance, surface, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroySurfaceKHR");
        instance_dispatch->DestroySurfaceKHR(instance, surface, pAllocator);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroySurfaceKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordDestroySurfaceKHR(instance, surface, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex,
                                                                  VkSurfaceKHR surface, VkBool32* pSupported) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfaceSupportKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceSurfaceSupportKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported,
                                                                          error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfaceSupportKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceSurfaceSupportKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceSurfaceSupportKHR");
        result = instance_dispatch->GetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceSurfaceSupportKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                       VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfaceCapabilitiesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities,
                                                                               error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
        result = instance_dispatch->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                  uint32_t* pSurfaceFormatCount,
                                                                  VkSurfaceFormatKHR* pSurfaceFormats) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfaceFormatsKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceSurfaceFormatsKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount,
                                                                          pSurfaceFormats, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfaceFormatsKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceSurfaceFormatsKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats,
                                                                record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceSurfaceFormatsKHR");
        result =
            instance_dispatch->GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceSurfaceFormatsKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats,
                                                                 record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                       uint32_t* pPresentModeCount,
                                                                       VkPresentModeKHR* pPresentModes) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfacePresentModesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceSurfacePresentModesKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount,
                                                                               pPresentModes, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfacePresentModesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceSurfacePresentModesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes,
                                                                     record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceSurfacePresentModesKHR");
        result =
            instance_dispatch->GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceSurfacePresentModesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes,
                                                                      record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateSwapchainKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateSwapchainKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateSwapchainKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateSwapchainKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateSwapchainKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateSwapchainKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateSwapchainKHR");
        result = device_dispatch->CreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateSwapchainKHR");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateSwapchainKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount,
                                                     VkImage* pSwapchainImages) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetSwapchainImagesKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetSwapchainImagesKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetSwapchainImagesKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetSwapchainImagesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetSwapchainImagesKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetSwapchainImagesKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetSwapchainImagesKHR");
        result = device_dispatch->GetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetSwapchainImagesKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetSwapchainImagesKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout,
                                                   VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkAcquireNextImageKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkAcquireNextImageKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateAcquireNextImageKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkAcquireNextImageKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkAcquireNextImageKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordAcquireNextImageKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkAcquireNextImageKHR");
        result = device_dispatch->AcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkAcquireNextImageKHR");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordAcquireNextImageKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL
GetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceGroupPresentCapabilitiesKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDeviceGroupPresentCapabilitiesKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetDeviceGroupPresentCapabilitiesKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDeviceGroupPresentCapabilitiesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDeviceGroupPresentCapabilitiesKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetDeviceGroupPresentCapabilitiesKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetDeviceGroupPresentCapabilitiesKHR");
        result = device_dispatch->GetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDeviceGroupPresentCapabilitiesKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetDeviceGroupPresentCapabilitiesKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface,
                                                                    VkDeviceGroupPresentModeFlagsKHR* pModes) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceGroupSurfacePresentModesKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDeviceGroupSurfacePresentModesKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetDeviceGroupSurfacePresentModesKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDeviceGroupSurfacePresentModesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDeviceGroupSurfacePresentModesKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetDeviceGroupSurfacePresentModesKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetDeviceGroupSurfacePresentModesKHR");
        result = device_dispatch->GetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDeviceGroupSurfacePresentModesKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetDeviceGroupSurfacePresentModesKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                     uint32_t* pRectCount, VkRect2D* pRects) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDevicePresentRectanglesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDevicePresentRectanglesKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |=
                vo->PreCallValidateGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDevicePresentRectanglesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDevicePresentRectanglesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDevicePresentRectanglesKHR");
        result = instance_dispatch->GetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDevicePresentRectanglesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo,
                                                    uint32_t* pImageIndex) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkAcquireNextImage2KHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkAcquireNextImage2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateAcquireNextImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkAcquireNextImage2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkAcquireNextImage2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordAcquireNextImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkAcquireNextImage2KHR");
        result = device_dispatch->AcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkAcquireNextImage2KHR");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordAcquireNextImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                                     VkDisplayPropertiesKHR* pProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceDisplayPropertiesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceDisplayPropertiesKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |=
                vo->PreCallValidateGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceDisplayPropertiesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceDisplayPropertiesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceDisplayPropertiesKHR");
        result = instance_dispatch->GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceDisplayPropertiesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                                          VkDisplayPlanePropertiesKHR* pProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceDisplayPlanePropertiesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties,
                                                                                  error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
        result = instance_dispatch->GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex,
                                                                   uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDisplayPlaneSupportedDisplaysKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDisplayPlaneSupportedDisplaysKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays,
                                                                           error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDisplayPlaneSupportedDisplaysKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDisplayPlaneSupportedDisplaysKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetDisplayPlaneSupportedDisplaysKHR");
        result = instance_dispatch->GetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDisplayPlaneSupportedDisplaysKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                           uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDisplayModePropertiesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDisplayModePropertiesKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDisplayModePropertiesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDisplayModePropertiesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetDisplayModePropertiesKHR");
        result = instance_dispatch->GetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDisplayModePropertiesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                    const VkDisplayModeCreateInfoKHR* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateDisplayModeKHR, VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateDisplayModeKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateDisplayModeKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateDisplayModeKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateDisplayModeKHR");
        result = instance_dispatch->CreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateDisplayModeKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode,
                                                              uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDisplayPlaneCapabilitiesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDisplayPlaneCapabilitiesKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDisplayPlaneCapabilitiesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDisplayPlaneCapabilitiesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetDisplayPlaneCapabilitiesKHR");
        result = instance_dispatch->GetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDisplayPlaneCapabilitiesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(instance);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateDisplayPlaneSurfaceKHR, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateDisplayPlaneSurfaceKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateDisplayPlaneSurfaceKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateDisplayPlaneSurfaceKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateDisplayPlaneSurfaceKHR");
        result = instance_dispatch->CreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateDisplayPlaneSurfaceKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                                         const VkSwapchainCreateInfoKHR* pCreateInfos,
                                                         const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateSharedSwapchainsKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateSharedSwapchainsKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateSharedSwapchainsKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains,
                                                                 error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateSharedSwapchainsKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateSharedSwapchainsKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateSharedSwapchainsKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateSharedSwapchainsKHR");
        result = device_dispatch->CreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateSharedSwapchainsKHR");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateSharedSwapchainsKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetMemoryFdKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetMemoryFdKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetMemoryFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetMemoryFdKHR(device, pGetFdInfo, pFd, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetMemoryFdKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetMemoryFdKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetMemoryFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetMemoryFdKHR(device, pGetFdInfo, pFd, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetMemoryFdKHR");
        result = device_dispatch->GetMemoryFdKHR(device, pGetFdInfo, pFd);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetMemoryFdKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetMemoryFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetMemoryFdKHR(device, pGetFdInfo, pFd, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd,
                                                        VkMemoryFdPropertiesKHR* pMemoryFdProperties) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetMemoryFdPropertiesKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetMemoryFdPropertiesKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetMemoryFdPropertiesKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetMemoryFdPropertiesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetMemoryFdPropertiesKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetMemoryFdPropertiesKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetMemoryFdPropertiesKHR");
        result = device_dispatch->GetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetMemoryFdPropertiesKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetMemoryFdPropertiesKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkImportSemaphoreFdKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkImportSemaphoreFdKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateImportSemaphoreFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkImportSemaphoreFdKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkImportSemaphoreFdKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordImportSemaphoreFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkImportSemaphoreFdKHR");
        result = device_dispatch->ImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkImportSemaphoreFdKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordImportSemaphoreFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetSemaphoreFdKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetSemaphoreFdKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetSemaphoreFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetSemaphoreFdKHR(device, pGetFdInfo, pFd, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetSemaphoreFdKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetSemaphoreFdKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetSemaphoreFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetSemaphoreFdKHR(device, pGetFdInfo, pFd, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetSemaphoreFdKHR");
        result = device_dispatch->GetSemaphoreFdKHR(device, pGetFdInfo, pFd);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetSemaphoreFdKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetSemaphoreFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetSemaphoreFdKHR(device, pGetFdInfo, pFd, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetSwapchainStatusKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetSwapchainStatusKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetSwapchainStatusKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetSwapchainStatusKHR(device, swapchain, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetSwapchainStatusKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetSwapchainStatusKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetSwapchainStatusKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetSwapchainStatusKHR(device, swapchain, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetSwapchainStatusKHR");
        result = device_dispatch->GetSwapchainStatusKHR(device, swapchain);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetSwapchainStatusKHR");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetSwapchainStatusKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetSwapchainStatusKHR(device, swapchain, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkImportFenceFdKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkImportFenceFdKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateImportFenceFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateImportFenceFdKHR(device, pImportFenceFdInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkImportFenceFdKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkImportFenceFdKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordImportFenceFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordImportFenceFdKHR(device, pImportFenceFdInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkImportFenceFdKHR");
        result = device_dispatch->ImportFenceFdKHR(device, pImportFenceFdInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkImportFenceFdKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordImportFenceFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordImportFenceFdKHR(device, pImportFenceFdInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetFenceFdKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetFenceFdKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetFenceFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetFenceFdKHR(device, pGetFdInfo, pFd, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetFenceFdKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetFenceFdKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetFenceFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetFenceFdKHR(device, pGetFdInfo, pFd, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetFenceFdKHR");
        result = device_dispatch->GetFenceFdKHR(device, pGetFdInfo, pFd);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetFenceFdKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetFenceFdKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetFenceFdKHR(device, pGetFdInfo, pFd, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters,
    VkPerformanceCounterDescriptionKHR* pCounterDescriptions) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
                physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
                physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
        result = instance_dispatch->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
            physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
                physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
                physicalDevice, pPerformanceQueryCreateInfo, pNumPasses, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo,
                                                                                   pNumPasses, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
        instance_dispatch->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo,
                                                                                 pNumPasses);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo,
                                                                                    pNumPasses, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkAcquireProfilingLockKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkAcquireProfilingLockKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateAcquireProfilingLockKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateAcquireProfilingLockKHR(device, pInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkAcquireProfilingLockKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkAcquireProfilingLockKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordAcquireProfilingLockKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordAcquireProfilingLockKHR(device, pInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkAcquireProfilingLockKHR");
        result = device_dispatch->AcquireProfilingLockKHR(device, pInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkAcquireProfilingLockKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordAcquireProfilingLockKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordAcquireProfilingLockKHR(device, pInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR(VkDevice device) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkReleaseProfilingLockKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkReleaseProfilingLockKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateReleaseProfilingLockKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateReleaseProfilingLockKHR(device, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkReleaseProfilingLockKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkReleaseProfilingLockKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordReleaseProfilingLockKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordReleaseProfilingLockKHR(device, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkReleaseProfilingLockKHR");
        device_dispatch->ReleaseProfilingLockKHR(device);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkReleaseProfilingLockKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordReleaseProfilingLockKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordReleaseProfilingLockKHR(device, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice,
                                                                        const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                        VkSurfaceCapabilities2KHR* pSurfaceCapabilities) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfaceCapabilities2KHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceSurfaceCapabilities2KHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities,
                                                                                error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfaceCapabilities2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceSurfaceCapabilities2KHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities,
                                                                      record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceSurfaceCapabilities2KHR");
        result = instance_dispatch->GetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceSurfaceCapabilities2KHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities,
                                                                       record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice,
                                                                   const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                   uint32_t* pSurfaceFormatCount,
                                                                   VkSurfaceFormat2KHR* pSurfaceFormats) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfaceFormats2KHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceSurfaceFormats2KHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount,
                                                                           pSurfaceFormats, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfaceFormats2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceSurfaceFormats2KHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats,
                                                                 record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceSurfaceFormats2KHR");
        result = instance_dispatch->GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount,
                                                                        pSurfaceFormats);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceSurfaceFormats2KHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount,
                                                                  pSurfaceFormats, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                                      VkDisplayProperties2KHR* pProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceDisplayProperties2KHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceDisplayProperties2KHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |=
                vo->PreCallValidateGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceDisplayProperties2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceDisplayProperties2KHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceDisplayProperties2KHR");
        result = instance_dispatch->GetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceDisplayProperties2KHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice,
                                                                           uint32_t* pPropertyCount,
                                                                           VkDisplayPlaneProperties2KHR* pProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceDisplayPlaneProperties2KHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties,
                                                                                   error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
        result = instance_dispatch->GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                            uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDisplayModeProperties2KHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDisplayModeProperties2KHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |=
                vo->PreCallValidateGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDisplayModeProperties2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDisplayModeProperties2KHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetDisplayModeProperties2KHR");
        result = instance_dispatch->GetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDisplayModeProperties2KHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice,
                                                               const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo,
                                                               VkDisplayPlaneCapabilities2KHR* pCapabilities) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDisplayPlaneCapabilities2KHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetDisplayPlaneCapabilities2KHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetDisplayPlaneCapabilities2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetDisplayPlaneCapabilities2KHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetDisplayPlaneCapabilities2KHR");
        result = instance_dispatch->GetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetDisplayPlaneCapabilities2KHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL
GetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount,
                                         VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceFragmentShadingRatesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceFragmentShadingRatesKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount,
                                                                                pFragmentShadingRates, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceFragmentShadingRatesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceFragmentShadingRatesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount,
                                                                      pFragmentShadingRates, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceFragmentShadingRatesKHR");
        result = instance_dispatch->GetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount,
                                                                             pFragmentShadingRates);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceFragmentShadingRatesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount,
                                                                       pFragmentShadingRates, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                                        const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetFragmentShadingRateKHR,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetFragmentShadingRateKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetFragmentShadingRateKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetFragmentShadingRateKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetFragmentShadingRateKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetFragmentShadingRateKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetFragmentShadingRateKHR");
        device_dispatch->CmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetFragmentShadingRateKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetFragmentShadingRateKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdRefreshObjectsKHR(VkCommandBuffer commandBuffer, const VkRefreshObjectListKHR* pRefreshObjects) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdRefreshObjectsKHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdRefreshObjectsKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdRefreshObjectsKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdRefreshObjectsKHR(commandBuffer, pRefreshObjects, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdRefreshObjectsKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdRefreshObjectsKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdRefreshObjectsKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdRefreshObjectsKHR(commandBuffer, pRefreshObjects, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdRefreshObjectsKHR");
        device_dispatch->CmdRefreshObjectsKHR(commandBuffer, pRefreshObjects);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdRefreshObjectsKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdRefreshObjectsKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdRefreshObjectsKHR(commandBuffer, pRefreshObjects, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceRefreshableObjectTypesKHR(VkPhysicalDevice physicalDevice,
                                                                          uint32_t* pRefreshableObjectTypeCount,
                                                                          VkObjectType* pRefreshableObjectTypes) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceRefreshableObjectTypesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceRefreshableObjectTypesKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceRefreshableObjectTypesKHR(physicalDevice, pRefreshableObjectTypeCount,
                                                                                  pRefreshableObjectTypes, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceRefreshableObjectTypesKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceRefreshableObjectTypesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceRefreshableObjectTypesKHR(physicalDevice, pRefreshableObjectTypeCount,
                                                                        pRefreshableObjectTypes, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceRefreshableObjectTypesKHR");
        result = instance_dispatch->GetPhysicalDeviceRefreshableObjectTypesKHR(physicalDevice, pRefreshableObjectTypeCount,
                                                                               pRefreshableObjectTypes);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceRefreshableObjectTypesKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceRefreshableObjectTypesKHR(physicalDevice, pRefreshableObjectTypeCount,
                                                                         pRefreshableObjectTypes, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetEvent2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetEvent2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetEvent2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetEvent2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetEvent2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetEvent2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetEvent2KHR");
        device_dispatch->CmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetEvent2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetEvent2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResetEvent2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdResetEvent2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdResetEvent2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdResetEvent2KHR(commandBuffer, event, stageMask, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdResetEvent2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdResetEvent2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdResetEvent2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdResetEvent2KHR(commandBuffer, event, stageMask, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdResetEvent2KHR");
        device_dispatch->CmdResetEvent2KHR(commandBuffer, event, stageMask);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdResetEvent2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdResetEvent2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdResetEvent2KHR(commandBuffer, event, stageMask, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                             const VkDependencyInfo* pDependencyInfos) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWaitEvents2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdWaitEvents2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdWaitEvents2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdWaitEvents2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdWaitEvents2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdWaitEvents2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdWaitEvents2KHR");
        device_dispatch->CmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdWaitEvents2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdWaitEvents2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdPipelineBarrier2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdPipelineBarrier2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdPipelineBarrier2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdPipelineBarrier2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdPipelineBarrier2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdPipelineBarrier2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdPipelineBarrier2KHR");
        device_dispatch->CmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdPipelineBarrier2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdPipelineBarrier2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                                 uint32_t query) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWriteTimestamp2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdWriteTimestamp2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdWriteTimestamp2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdWriteTimestamp2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdWriteTimestamp2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdWriteTimestamp2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdWriteTimestamp2KHR");
        device_dispatch->CmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdWriteTimestamp2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdWriteTimestamp2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(queue);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueSubmit2KHR, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    {
        VVL_ZoneScopedN("PreCallValidate_vkQueueSubmit2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateQueueSubmit2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateQueueSubmit2KHR(queue, submitCount, pSubmits, fence, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkQueueSubmit2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkQueueSubmit2KHR");
        VVL_TracyVkNamedZoneStart(GetTracyVkCtx(), queue, "gpu_PreCallRecordvkQueueSubmit2KHR", pre_call_record_gpu_zone);

        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordQueueSubmit2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordQueueSubmit2KHR(queue, submitCount, pSubmits, fence, record_obj);
        }

        VVL_TracyVkNamedZoneEnd(pre_call_record_gpu_zone, queue);
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkQueueSubmit2KHR");

        VVL_TracyVkNamedZoneStart(GetTracyVkCtx(), queue, "gpu_vkQueueSubmit2KHR", submit_gpu_zone);
        result = device_dispatch->QueueSubmit2KHR(queue, submitCount, pSubmits, fence);

        VVL_TracyVkNamedZoneEnd(submit_gpu_zone, queue);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkQueueSubmit2KHR");

        VVL_TracyVkNamedZoneStart(GetTracyVkCtx(), queue, "gpu_PostCallRecordvkQueueSubmit2KHR", post_call_record_gpu_zone);

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordQueueSubmit2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordQueueSubmit2KHR(queue, submitCount, pSubmits, fence, record_obj);
        }

        VVL_TracyVkNamedZoneEnd(post_call_record_gpu_zone, queue);
    }
#if defined(VVL_TRACY_GPU)
    TracyVkCollector::TrySubmitCollectCb(queue);
#endif
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyBuffer2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyBuffer2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyBuffer2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyBuffer2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyBuffer2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyBuffer2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyBuffer2KHR");
        device_dispatch->CmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyBuffer2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyBuffer2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyImage2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyImage2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyImage2KHR(commandBuffer, pCopyImageInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyImage2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyImage2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyImage2KHR(commandBuffer, pCopyImageInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyImage2KHR");
        device_dispatch->CmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyImage2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyImage2KHR(commandBuffer, pCopyImageInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                                    const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyBufferToImage2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyBufferToImage2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyBufferToImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyBufferToImage2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyBufferToImage2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyBufferToImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyBufferToImage2KHR");
        device_dispatch->CmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyBufferToImage2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyBufferToImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                                    const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyImageToBuffer2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdCopyImageToBuffer2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdCopyImageToBuffer2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdCopyImageToBuffer2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdCopyImageToBuffer2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdCopyImageToBuffer2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdCopyImageToBuffer2KHR");
        device_dispatch->CmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdCopyImageToBuffer2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdCopyImageToBuffer2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBlitImage2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBlitImage2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBlitImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBlitImage2KHR(commandBuffer, pBlitImageInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBlitImage2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBlitImage2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBlitImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBlitImage2KHR(commandBuffer, pBlitImageInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBlitImage2KHR");
        device_dispatch->CmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBlitImage2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBlitImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBlitImage2KHR(commandBuffer, pBlitImageInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResolveImage2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdResolveImage2KHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdResolveImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdResolveImage2KHR(commandBuffer, pResolveImageInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdResolveImage2KHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdResolveImage2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdResolveImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdResolveImage2KHR(commandBuffer, pResolveImageInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdResolveImage2KHR");
        device_dispatch->CmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdResolveImage2KHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdResolveImage2KHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdResolveImage2KHR(commandBuffer, pResolveImageInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                uint16_t lineStipplePattern) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetLineStippleKHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetLineStippleKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetLineStippleKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetLineStippleKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetLineStippleKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetLineStippleKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetLineStippleKHR");
        device_dispatch->CmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetLineStippleKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetLineStippleKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice physicalDevice,
                                                                            uint32_t* pTimeDomainCount,
                                                                            VkTimeDomainKHR* pTimeDomains) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceCalibrateableTimeDomainsKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceCalibrateableTimeDomainsKHR(physicalDevice, pTimeDomainCount, pTimeDomains,
                                                                                    error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceCalibrateableTimeDomainsKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceCalibrateableTimeDomainsKHR(physicalDevice, pTimeDomainCount, pTimeDomains,
                                                                          record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
        result = instance_dispatch->GetPhysicalDeviceCalibrateableTimeDomainsKHR(physicalDevice, pTimeDomainCount, pTimeDomains);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceCalibrateableTimeDomainsKHR(physicalDevice, pTimeDomainCount, pTimeDomains,
                                                                           record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetCalibratedTimestampsKHR(VkDevice device, uint32_t timestampCount,
                                                          const VkCalibratedTimestampInfoKHR* pTimestampInfos,
                                                          uint64_t* pTimestamps, uint64_t* pMaxDeviation) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetCalibratedTimestampsKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetCalibratedTimestampsKHR");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetCalibratedTimestampsKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetCalibratedTimestampsKHR(device, timestampCount, pTimestampInfos, pTimestamps,
                                                                  pMaxDeviation, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetCalibratedTimestampsKHR);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetCalibratedTimestampsKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetCalibratedTimestampsKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetCalibratedTimestampsKHR(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation,
                                                        record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetCalibratedTimestampsKHR");
        result = device_dispatch->GetCalibratedTimestampsKHR(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetCalibratedTimestampsKHR");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetCalibratedTimestampsKHR]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetCalibratedTimestampsKHR(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation,
                                                         record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkReleaseDisplayEXT, VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkReleaseDisplayEXT");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateReleaseDisplayEXT(physicalDevice, display, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkReleaseDisplayEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkReleaseDisplayEXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordReleaseDisplayEXT(physicalDevice, display, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkReleaseDisplayEXT");
        result = instance_dispatch->ReleaseDisplayEXT(physicalDevice, display);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkReleaseDisplayEXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordReleaseDisplayEXT(physicalDevice, display, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                        VkSurfaceCapabilities2EXT* pSurfaceCapabilities) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfaceCapabilities2EXT,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceSurfaceCapabilities2EXT");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities,
                                                                                error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfaceCapabilities2EXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceSurfaceCapabilities2EXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceSurfaceCapabilities2EXT");
        result = instance_dispatch->GetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceSurfaceCapabilities2EXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT(VkDevice device, VkDisplayKHR display,
                                                      const VkDisplayPowerInfoEXT* pDisplayPowerInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDisplayPowerControlEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDisplayPowerControlEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateDisplayPowerControlEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateDisplayPowerControlEXT(device, display, pDisplayPowerInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkDisplayPowerControlEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDisplayPowerControlEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordDisplayPowerControlEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordDisplayPowerControlEXT(device, display, pDisplayPowerInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkDisplayPowerControlEXT");
        result = device_dispatch->DisplayPowerControlEXT(device, display, pDisplayPowerInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkDisplayPowerControlEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordDisplayPowerControlEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordDisplayPowerControlEXT(device, display, pDisplayPowerInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkRegisterDeviceEventEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkRegisterDeviceEventEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateRegisterDeviceEventEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkRegisterDeviceEventEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkRegisterDeviceEventEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordRegisterDeviceEventEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkRegisterDeviceEventEXT");
        result = device_dispatch->RegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkRegisterDeviceEventEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordRegisterDeviceEventEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display,
                                                       const VkDisplayEventInfoEXT* pDisplayEventInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkRegisterDisplayEventEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkRegisterDisplayEventEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateRegisterDisplayEventEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkRegisterDisplayEventEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkRegisterDisplayEventEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordRegisterDisplayEventEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkRegisterDisplayEventEXT");
        result = device_dispatch->RegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkRegisterDisplayEventEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordRegisterDisplayEventEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain,
                                                      VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetSwapchainCounterEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetSwapchainCounterEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetSwapchainCounterEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetSwapchainCounterEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetSwapchainCounterEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetSwapchainCounterEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetSwapchainCounterEXT");
        result = device_dispatch->GetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetSwapchainCounterEXT");

        if (result == VK_ERROR_DEVICE_LOST) {
            for (auto& vo : device_dispatch->object_dispatch) {
                vo->is_device_lost = true;
            }
        }
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetSwapchainCounterEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                                     uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDiscardRectangleEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDiscardRectangleEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDiscardRectangleEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                                                 pDiscardRectangles, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDiscardRectangleEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDiscardRectangleEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDiscardRectangleEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                                       pDiscardRectangles, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDiscardRectangleEXT");
        device_dispatch->CmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDiscardRectangleEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDiscardRectangleEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                                        pDiscardRectangles, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDiscardRectangleEnableEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDiscardRectangleEnableEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDiscardRectangleEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDiscardRectangleEnableEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDiscardRectangleEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDiscardRectangleEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDiscardRectangleEnableEXT");
        device_dispatch->CmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDiscardRectangleEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDiscardRectangleEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                                         VkDiscardRectangleModeEXT discardRectangleMode) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDiscardRectangleModeEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDiscardRectangleModeEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDiscardRectangleModeEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDiscardRectangleModeEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDiscardRectangleModeEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDiscardRectangleModeEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDiscardRectangleModeEXT");
        device_dispatch->CmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDiscardRectangleModeEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDiscardRectangleModeEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains,
                                             const VkHdrMetadataEXT* pMetadata) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSetHdrMetadataEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkSetHdrMetadataEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateSetHdrMetadataEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkSetHdrMetadataEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkSetHdrMetadataEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordSetHdrMetadataEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkSetHdrMetadataEXT");
        device_dispatch->SetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkSetHdrMetadataEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordSetHdrMetadataEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSetDebugUtilsObjectNameEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkSetDebugUtilsObjectNameEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateSetDebugUtilsObjectNameEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateSetDebugUtilsObjectNameEXT(device, pNameInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkSetDebugUtilsObjectNameEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkSetDebugUtilsObjectNameEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordSetDebugUtilsObjectNameEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordSetDebugUtilsObjectNameEXT(device, pNameInfo, record_obj);
        }
    }
    device_dispatch->debug_report->SetUtilsObjectName(pNameInfo);
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkSetDebugUtilsObjectNameEXT");
        result = device_dispatch->SetDebugUtilsObjectNameEXT(device, pNameInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkSetDebugUtilsObjectNameEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordSetDebugUtilsObjectNameEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordSetDebugUtilsObjectNameEXT(device, pNameInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSetDebugUtilsObjectTagEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkSetDebugUtilsObjectTagEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateSetDebugUtilsObjectTagEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateSetDebugUtilsObjectTagEXT(device, pTagInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkSetDebugUtilsObjectTagEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkSetDebugUtilsObjectTagEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordSetDebugUtilsObjectTagEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordSetDebugUtilsObjectTagEXT(device, pTagInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkSetDebugUtilsObjectTagEXT");
        result = device_dispatch->SetDebugUtilsObjectTagEXT(device, pTagInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkSetDebugUtilsObjectTagEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordSetDebugUtilsObjectTagEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordSetDebugUtilsObjectTagEXT(device, pTagInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(queue);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueBeginDebugUtilsLabelEXT, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    {
        VVL_ZoneScopedN("PreCallValidate_vkQueueBeginDebugUtilsLabelEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateQueueBeginDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkQueueBeginDebugUtilsLabelEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkQueueBeginDebugUtilsLabelEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordQueueBeginDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo, record_obj);
        }
    }
    device_dispatch->debug_report->BeginQueueDebugUtilsLabel(queue, pLabelInfo);
    {
        VVL_ZoneScopedN("Dispatch_vkQueueBeginDebugUtilsLabelEXT");
        device_dispatch->QueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkQueueBeginDebugUtilsLabelEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordQueueBeginDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(VkQueue queue) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(queue);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueEndDebugUtilsLabelEXT, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    {
        VVL_ZoneScopedN("PreCallValidate_vkQueueEndDebugUtilsLabelEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateQueueEndDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateQueueEndDebugUtilsLabelEXT(queue, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkQueueEndDebugUtilsLabelEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkQueueEndDebugUtilsLabelEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordQueueEndDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordQueueEndDebugUtilsLabelEXT(queue, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkQueueEndDebugUtilsLabelEXT");
        device_dispatch->QueueEndDebugUtilsLabelEXT(queue);
    }
    device_dispatch->debug_report->EndQueueDebugUtilsLabel(queue);
    {
        VVL_ZoneScopedN("PostCallRecord_vkQueueEndDebugUtilsLabelEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordQueueEndDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordQueueEndDebugUtilsLabelEXT(queue, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(queue);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueInsertDebugUtilsLabelEXT, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    {
        VVL_ZoneScopedN("PreCallValidate_vkQueueInsertDebugUtilsLabelEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateQueueInsertDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkQueueInsertDebugUtilsLabelEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkQueueInsertDebugUtilsLabelEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordQueueInsertDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo, record_obj);
        }
    }
    device_dispatch->debug_report->InsertQueueDebugUtilsLabel(queue, pLabelInfo);
    {
        VVL_ZoneScopedN("Dispatch_vkQueueInsertDebugUtilsLabelEXT");
        device_dispatch->QueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkQueueInsertDebugUtilsLabelEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordQueueInsertDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBeginDebugUtilsLabelEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBeginDebugUtilsLabelEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBeginDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBeginDebugUtilsLabelEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBeginDebugUtilsLabelEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBeginDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBeginDebugUtilsLabelEXT");
        device_dispatch->CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBeginDebugUtilsLabelEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBeginDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdEndDebugUtilsLabelEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdEndDebugUtilsLabelEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdEndDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdEndDebugUtilsLabelEXT(commandBuffer, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdEndDebugUtilsLabelEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdEndDebugUtilsLabelEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdEndDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdEndDebugUtilsLabelEXT(commandBuffer, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdEndDebugUtilsLabelEXT");
        device_dispatch->CmdEndDebugUtilsLabelEXT(commandBuffer);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdEndDebugUtilsLabelEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdEndDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdEndDebugUtilsLabelEXT(commandBuffer, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdInsertDebugUtilsLabelEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdInsertDebugUtilsLabelEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdInsertDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdInsertDebugUtilsLabelEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdInsertDebugUtilsLabelEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdInsertDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdInsertDebugUtilsLabelEXT");
        device_dispatch->CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdInsertDebugUtilsLabelEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdInsertDebugUtilsLabelEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo, record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(VkInstance instance,
                                                            const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            VkDebugUtilsMessengerEXT* pMessenger) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(instance);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateDebugUtilsMessengerEXT, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateDebugUtilsMessengerEXT");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateDebugUtilsMessengerEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateDebugUtilsMessengerEXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateDebugUtilsMessengerEXT");
        result = instance_dispatch->CreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
    }
    LayerCreateMessengerCallback(instance_dispatch->debug_report, false, pCreateInfo, pMessenger);
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateDebugUtilsMessengerEXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                                         const VkAllocationCallbacks* pAllocator) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(instance);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyDebugUtilsMessengerEXT, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    {
        VVL_ZoneScopedN("PreCallValidate_vkDestroyDebugUtilsMessengerEXT");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkDestroyDebugUtilsMessengerEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkDestroyDebugUtilsMessengerEXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkDestroyDebugUtilsMessengerEXT");
        instance_dispatch->DestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    }
    LayerDestroyCallback(instance_dispatch->debug_report, messenger);
    {
        VVL_ZoneScopedN("PostCallRecord_vkDestroyDebugUtilsMessengerEXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                      VkDebugUtilsMessageTypeFlagsEXT messageTypes,
                                                      const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(instance);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSubmitDebugUtilsMessageEXT, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    {
        VVL_ZoneScopedN("PreCallValidate_vkSubmitDebugUtilsMessageEXT");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |=
                vo->PreCallValidateSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkSubmitDebugUtilsMessageEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkSubmitDebugUtilsMessageEXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkSubmitDebugUtilsMessageEXT");
        instance_dispatch->SubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkSubmitDebugUtilsMessageEXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                                    const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetSampleLocationsEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetSampleLocationsEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetSampleLocationsEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetSampleLocationsEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetSampleLocationsEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetSampleLocationsEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetSampleLocationsEXT");
        device_dispatch->CmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetSampleLocationsEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetSampleLocationsEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples,
                                                                     VkMultisamplePropertiesEXT* pMultisampleProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceMultisamplePropertiesEXT,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceMultisamplePropertiesEXT");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties,
                                                                                 error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceMultisamplePropertiesEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceMultisamplePropertiesEXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceMultisamplePropertiesEXT");
        instance_dispatch->GetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceMultisamplePropertiesEXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties,
                                                                        record_obj);
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image,
                                                                      VkImageDrmFormatModifierPropertiesEXT* pProperties) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetImageDrmFormatModifierPropertiesEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetImageDrmFormatModifierPropertiesEXT");
        for (const auto& vo :
             device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetImageDrmFormatModifierPropertiesEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetImageDrmFormatModifierPropertiesEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetImageDrmFormatModifierPropertiesEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetImageDrmFormatModifierPropertiesEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetImageDrmFormatModifierPropertiesEXT");
        result = device_dispatch->GetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetImageDrmFormatModifierPropertiesEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetImageDrmFormatModifierPropertiesEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType,
                                                                 const void* pHostPointer,
                                                                 VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetMemoryHostPointerPropertiesEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetMemoryHostPointerPropertiesEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetMemoryHostPointerPropertiesEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer,
                                                                         pMemoryHostPointerProperties, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetMemoryHostPointerPropertiesEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetMemoryHostPointerPropertiesEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetMemoryHostPointerPropertiesEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties,
                                                               record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetMemoryHostPointerPropertiesEXT");
        result = device_dispatch->GetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetMemoryHostPointerPropertiesEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetMemoryHostPointerPropertiesEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties,
                                                                record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(instance);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateHeadlessSurfaceEXT, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateHeadlessSurfaceEXT");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateHeadlessSurfaceEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateHeadlessSurfaceEXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateHeadlessSurfaceEXT");
        result = instance_dispatch->CreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateHeadlessSurfaceEXT");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                uint16_t lineStipplePattern) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetLineStippleEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetLineStippleEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetLineStippleEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetLineStippleEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetLineStippleEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetLineStippleEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetLineStippleEXT");
        device_dispatch->CmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetLineStippleEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetLineStippleEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetCullModeEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetCullModeEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetCullModeEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetCullModeEXT(commandBuffer, cullMode, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetCullModeEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetCullModeEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetCullModeEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetCullModeEXT(commandBuffer, cullMode, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetCullModeEXT");
        device_dispatch->CmdSetCullModeEXT(commandBuffer, cullMode);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetCullModeEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetCullModeEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetCullModeEXT(commandBuffer, cullMode, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetFrontFaceEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetFrontFaceEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetFrontFaceEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetFrontFaceEXT(commandBuffer, frontFace, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetFrontFaceEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetFrontFaceEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetFrontFaceEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetFrontFaceEXT(commandBuffer, frontFace, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetFrontFaceEXT");
        device_dispatch->CmdSetFrontFaceEXT(commandBuffer, frontFace);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetFrontFaceEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetFrontFaceEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetFrontFaceEXT(commandBuffer, frontFace, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetPrimitiveTopologyEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetPrimitiveTopologyEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetPrimitiveTopologyEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetPrimitiveTopologyEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetPrimitiveTopologyEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetPrimitiveTopologyEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetPrimitiveTopologyEXT");
        device_dispatch->CmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetPrimitiveTopologyEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetPrimitiveTopologyEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                      const VkViewport* pViewports) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetViewportWithCountEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetViewportWithCountEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetViewportWithCountEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetViewportWithCountEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetViewportWithCountEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetViewportWithCountEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetViewportWithCountEXT");
        device_dispatch->CmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetViewportWithCountEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetViewportWithCountEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                     const VkRect2D* pScissors) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetScissorWithCountEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetScissorWithCountEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetScissorWithCountEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetScissorWithCountEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetScissorWithCountEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetScissorWithCountEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetScissorWithCountEXT");
        device_dispatch->CmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetScissorWithCountEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetScissorWithCountEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                                    const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                                    const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindVertexBuffers2EXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdBindVertexBuffers2EXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdBindVertexBuffers2EXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets,
                                                                pSizes, pStrides, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdBindVertexBuffers2EXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdBindVertexBuffers2EXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdBindVertexBuffers2EXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                                      pStrides, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdBindVertexBuffers2EXT");
        device_dispatch->CmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdBindVertexBuffers2EXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdBindVertexBuffers2EXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                                       pStrides, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthTestEnableEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDepthTestEnableEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthTestEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDepthTestEnableEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDepthTestEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthTestEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDepthTestEnableEXT");
        device_dispatch->CmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDepthTestEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthTestEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthWriteEnableEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDepthWriteEnableEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthWriteEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDepthWriteEnableEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDepthWriteEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthWriteEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDepthWriteEnableEXT");
        device_dispatch->CmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDepthWriteEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthWriteEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthCompareOpEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDepthCompareOpEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthCompareOpEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDepthCompareOpEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDepthCompareOpEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthCompareOpEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDepthCompareOpEXT");
        device_dispatch->CmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDepthCompareOpEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthCompareOpEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthBoundsTestEnableEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDepthBoundsTestEnableEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthBoundsTestEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDepthBoundsTestEnableEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDepthBoundsTestEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthBoundsTestEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDepthBoundsTestEnableEXT");
        device_dispatch->CmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDepthBoundsTestEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthBoundsTestEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilTestEnableEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetStencilTestEnableEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilTestEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetStencilTestEnableEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetStencilTestEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilTestEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetStencilTestEnableEXT");
        device_dispatch->CmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetStencilTestEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilTestEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                              VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilOpEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetStencilOpEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilOpEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |=
                vo->PreCallValidateCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetStencilOpEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetStencilOpEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilOpEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetStencilOpEXT");
        device_dispatch->CmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetStencilOpEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilOpEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp, record_obj);
        }
    }
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL AcquireWinrtDisplayNV(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkAcquireWinrtDisplayNV, VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkAcquireWinrtDisplayNV");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateAcquireWinrtDisplayNV(physicalDevice, display, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkAcquireWinrtDisplayNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkAcquireWinrtDisplayNV");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordAcquireWinrtDisplayNV(physicalDevice, display, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkAcquireWinrtDisplayNV");
        result = instance_dispatch->AcquireWinrtDisplayNV(physicalDevice, display);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkAcquireWinrtDisplayNV");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordAcquireWinrtDisplayNV(physicalDevice, display, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetWinrtDisplayNV(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId,
                                                 VkDisplayKHR* pDisplay) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetWinrtDisplayNV, VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetWinrtDisplayNV");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetWinrtDisplayNV(physicalDevice, deviceRelativeId, pDisplay, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetWinrtDisplayNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetWinrtDisplayNV");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetWinrtDisplayNV(physicalDevice, deviceRelativeId, pDisplay, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetWinrtDisplayNV");
        result = instance_dispatch->GetWinrtDisplayNV(physicalDevice, deviceRelativeId, pDisplay);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetWinrtDisplayNV");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetWinrtDisplayNV(physicalDevice, deviceRelativeId, pDisplay, record_obj);
        }
    }
    return result;
}

#endif  // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                                const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                                uint32_t vertexAttributeDescriptionCount,
                                                const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetVertexInputEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetVertexInputEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetVertexInputEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |=
                vo->PreCallValidateCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                                        vertexAttributeDescriptionCount, pVertexAttributeDescriptions, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetVertexInputEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetVertexInputEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetVertexInputEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                                  vertexAttributeDescriptionCount, pVertexAttributeDescriptions, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetVertexInputEXT");
        device_dispatch->CmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                              vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetVertexInputEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetVertexInputEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                                   vertexAttributeDescriptionCount, pVertexAttributeDescriptions, record_obj);
        }
    }
}

#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL GetFenceSciSyncFenceNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo,
                                                      void* pHandle) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetFenceSciSyncFenceNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetFenceSciSyncFenceNV");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetFenceSciSyncFenceNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetFenceSciSyncFenceNV(device, pGetSciSyncHandleInfo, pHandle, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetFenceSciSyncFenceNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetFenceSciSyncFenceNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetFenceSciSyncFenceNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetFenceSciSyncFenceNV(device, pGetSciSyncHandleInfo, pHandle, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetFenceSciSyncFenceNV");
        result = device_dispatch->GetFenceSciSyncFenceNV(device, pGetSciSyncHandleInfo, pHandle);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetFenceSciSyncFenceNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetFenceSciSyncFenceNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetFenceSciSyncFenceNV(device, pGetSciSyncHandleInfo, pHandle, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceSciSyncObjNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo,
                                                    void* pHandle) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetFenceSciSyncObjNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetFenceSciSyncObjNV");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetFenceSciSyncObjNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetFenceSciSyncObjNV(device, pGetSciSyncHandleInfo, pHandle, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetFenceSciSyncObjNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetFenceSciSyncObjNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetFenceSciSyncObjNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetFenceSciSyncObjNV(device, pGetSciSyncHandleInfo, pHandle, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetFenceSciSyncObjNV");
        result = device_dispatch->GetFenceSciSyncObjNV(device, pGetSciSyncHandleInfo, pHandle);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetFenceSciSyncObjNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetFenceSciSyncObjNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetFenceSciSyncObjNV(device, pGetSciSyncHandleInfo, pHandle, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceSciSyncFenceNV(VkDevice device,
                                                         const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkImportFenceSciSyncFenceNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkImportFenceSciSyncFenceNV");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateImportFenceSciSyncFenceNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateImportFenceSciSyncFenceNV(device, pImportFenceSciSyncInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkImportFenceSciSyncFenceNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkImportFenceSciSyncFenceNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordImportFenceSciSyncFenceNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordImportFenceSciSyncFenceNV(device, pImportFenceSciSyncInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkImportFenceSciSyncFenceNV");
        result = device_dispatch->ImportFenceSciSyncFenceNV(device, pImportFenceSciSyncInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkImportFenceSciSyncFenceNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordImportFenceSciSyncFenceNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordImportFenceSciSyncFenceNV(device, pImportFenceSciSyncInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceSciSyncObjNV(VkDevice device, const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkImportFenceSciSyncObjNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkImportFenceSciSyncObjNV");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateImportFenceSciSyncObjNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateImportFenceSciSyncObjNV(device, pImportFenceSciSyncInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkImportFenceSciSyncObjNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkImportFenceSciSyncObjNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordImportFenceSciSyncObjNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordImportFenceSciSyncObjNV(device, pImportFenceSciSyncInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkImportFenceSciSyncObjNV");
        result = device_dispatch->ImportFenceSciSyncObjNV(device, pImportFenceSciSyncInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkImportFenceSciSyncObjNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordImportFenceSciSyncObjNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordImportFenceSciSyncObjNV(device, pImportFenceSciSyncInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSciSyncAttributesNV(VkPhysicalDevice physicalDevice,
                                                                    const VkSciSyncAttributesInfoNV* pSciSyncAttributesInfo,
                                                                    NvSciSyncAttrList pAttributes) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSciSyncAttributesNV,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceSciSyncAttributesNV");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceSciSyncAttributesNV(physicalDevice, pSciSyncAttributesInfo, pAttributes,
                                                                            error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSciSyncAttributesNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceSciSyncAttributesNV");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceSciSyncAttributesNV(physicalDevice, pSciSyncAttributesInfo, pAttributes, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceSciSyncAttributesNV");
        result = instance_dispatch->GetPhysicalDeviceSciSyncAttributesNV(physicalDevice, pSciSyncAttributesInfo, pAttributes);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceSciSyncAttributesNV");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceSciSyncAttributesNV(physicalDevice, pSciSyncAttributesInfo, pAttributes, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreSciSyncObjNV(VkDevice device, const VkSemaphoreGetSciSyncInfoNV* pGetSciSyncInfo,
                                                        void* pHandle) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetSemaphoreSciSyncObjNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetSemaphoreSciSyncObjNV");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetSemaphoreSciSyncObjNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetSemaphoreSciSyncObjNV(device, pGetSciSyncInfo, pHandle, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetSemaphoreSciSyncObjNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetSemaphoreSciSyncObjNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetSemaphoreSciSyncObjNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetSemaphoreSciSyncObjNV(device, pGetSciSyncInfo, pHandle, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetSemaphoreSciSyncObjNV");
        result = device_dispatch->GetSemaphoreSciSyncObjNV(device, pGetSciSyncInfo, pHandle);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetSemaphoreSciSyncObjNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetSemaphoreSciSyncObjNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetSemaphoreSciSyncObjNV(device, pGetSciSyncInfo, pHandle, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreSciSyncObjNV(VkDevice device,
                                                           const VkImportSemaphoreSciSyncInfoNV* pImportSemaphoreSciSyncInfo) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkImportSemaphoreSciSyncObjNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkImportSemaphoreSciSyncObjNV");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateImportSemaphoreSciSyncObjNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateImportSemaphoreSciSyncObjNV(device, pImportSemaphoreSciSyncInfo, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkImportSemaphoreSciSyncObjNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkImportSemaphoreSciSyncObjNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordImportSemaphoreSciSyncObjNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordImportSemaphoreSciSyncObjNV(device, pImportSemaphoreSciSyncInfo, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkImportSemaphoreSciSyncObjNV");
        result = device_dispatch->ImportSemaphoreSciSyncObjNV(device, pImportSemaphoreSciSyncInfo);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkImportSemaphoreSciSyncObjNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordImportSemaphoreSciSyncObjNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordImportSemaphoreSciSyncObjNV(device, pImportSemaphoreSciSyncInfo, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemorySciBufNV(VkDevice device, const VkMemoryGetSciBufInfoNV* pGetSciBufInfo,
                                                 NvSciBufObj* pHandle) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetMemorySciBufNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetMemorySciBufNV");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetMemorySciBufNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetMemorySciBufNV(device, pGetSciBufInfo, pHandle, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetMemorySciBufNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetMemorySciBufNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetMemorySciBufNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetMemorySciBufNV(device, pGetSciBufInfo, pHandle, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetMemorySciBufNV");
        result = device_dispatch->GetMemorySciBufNV(device, pGetSciBufInfo, pHandle);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetMemorySciBufNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetMemorySciBufNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetMemorySciBufNV(device, pGetSciBufInfo, pHandle, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL
GetPhysicalDeviceExternalMemorySciBufPropertiesNV(VkPhysicalDevice physicalDevice, VkExternalMemoryHandleTypeFlagBits handleType,
                                                  NvSciBufObj handle, VkMemorySciBufPropertiesNV* pMemorySciBufProperties) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceExternalMemorySciBufPropertiesNV(physicalDevice, handleType, handle,
                                                                                         pMemorySciBufProperties, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceExternalMemorySciBufPropertiesNV(physicalDevice, handleType, handle,
                                                                               pMemorySciBufProperties, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV");
        result = instance_dispatch->GetPhysicalDeviceExternalMemorySciBufPropertiesNV(physicalDevice, handleType, handle,
                                                                                      pMemorySciBufProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceExternalMemorySciBufPropertiesNV(physicalDevice, handleType, handle,
                                                                                pMemorySciBufProperties, record_obj);
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSciBufAttributesNV(VkPhysicalDevice physicalDevice, NvSciBufAttrList pAttributes) {
    VVL_ZoneScoped;

    auto instance_dispatch = vvl::dispatch::GetData(physicalDevice);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSciBufAttributesNV,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetPhysicalDeviceSciBufAttributesNV");
        for (const auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            skip |= vo->PreCallValidateGetPhysicalDeviceSciBufAttributesNV(physicalDevice, pAttributes, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSciBufAttributesNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetPhysicalDeviceSciBufAttributesNV");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PreCallRecordGetPhysicalDeviceSciBufAttributesNV(physicalDevice, pAttributes, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetPhysicalDeviceSciBufAttributesNV");
        result = instance_dispatch->GetPhysicalDeviceSciBufAttributesNV(physicalDevice, pAttributes);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetPhysicalDeviceSciBufAttributesNV");
        for (auto& vo : instance_dispatch->object_dispatch) {
            if (!vo) {
                continue;
            }
            vo->PostCallRecordGetPhysicalDeviceSciBufAttributesNV(physicalDevice, pAttributes, record_obj);
        }
    }
    return result;
}

#endif  // VK_USE_PLATFORM_SCI
VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetPatchControlPointsEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetPatchControlPointsEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetPatchControlPointsEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetPatchControlPointsEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetPatchControlPointsEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetPatchControlPointsEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetPatchControlPointsEXT");
        device_dispatch->CmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetPatchControlPointsEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetPatchControlPointsEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetRasterizerDiscardEnableEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetRasterizerDiscardEnableEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetRasterizerDiscardEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetRasterizerDiscardEnableEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetRasterizerDiscardEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetRasterizerDiscardEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetRasterizerDiscardEnableEXT");
        device_dispatch->CmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetRasterizerDiscardEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetRasterizerDiscardEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthBiasEnableEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetDepthBiasEnableEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthBiasEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetDepthBiasEnableEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetDepthBiasEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthBiasEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetDepthBiasEnableEXT");
        device_dispatch->CmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetDepthBiasEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthBiasEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetLogicOpEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetLogicOpEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetLogicOpEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetLogicOpEXT(commandBuffer, logicOp, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetLogicOpEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetLogicOpEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetLogicOpEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetLogicOpEXT(commandBuffer, logicOp, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetLogicOpEXT");
        device_dispatch->CmdSetLogicOpEXT(commandBuffer, logicOp);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetLogicOpEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetLogicOpEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetLogicOpEXT(commandBuffer, logicOp, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetPrimitiveRestartEnableEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetPrimitiveRestartEnableEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetPrimitiveRestartEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetPrimitiveRestartEnableEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetPrimitiveRestartEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetPrimitiveRestartEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetPrimitiveRestartEnableEXT");
        device_dispatch->CmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetPrimitiveRestartEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetPrimitiveRestartEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable, record_obj);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                     const VkBool32* pColorWriteEnables) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(commandBuffer);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetColorWriteEnableEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCmdSetColorWriteEnableEXT");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCmdSetColorWriteEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables, error_obj);
            if (skip) return;
        }
    }
    RecordObject record_obj(vvl::Func::vkCmdSetColorWriteEnableEXT);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCmdSetColorWriteEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCmdSetColorWriteEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables, record_obj);
        }
    }
    {
        VVL_ZoneScopedN("Dispatch_vkCmdSetColorWriteEnableEXT");
        device_dispatch->CmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
    }
    {
        VVL_ZoneScopedN("PostCallRecord_vkCmdSetColorWriteEnableEXT");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCmdSetColorWriteEnableEXT]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables, record_obj);
        }
    }
}

#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphoreSciSyncPoolNV(VkDevice device, const VkSemaphoreSciSyncPoolCreateInfoNV* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            VkSemaphoreSciSyncPoolNV* pSemaphorePool) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateSemaphoreSciSyncPoolNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkCreateSemaphoreSciSyncPoolNV");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateCreateSemaphoreSciSyncPoolNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateCreateSemaphoreSciSyncPoolNV(device, pCreateInfo, pAllocator, pSemaphorePool, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkCreateSemaphoreSciSyncPoolNV);
    {
        VVL_ZoneScopedN("PreCallRecord_vkCreateSemaphoreSciSyncPoolNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordCreateSemaphoreSciSyncPoolNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordCreateSemaphoreSciSyncPoolNV(device, pCreateInfo, pAllocator, pSemaphorePool, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkCreateSemaphoreSciSyncPoolNV");
        result = device_dispatch->CreateSemaphoreSciSyncPoolNV(device, pCreateInfo, pAllocator, pSemaphorePool);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkCreateSemaphoreSciSyncPoolNV");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordCreateSemaphoreSciSyncPoolNV]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordCreateSemaphoreSciSyncPoolNV(device, pCreateInfo, pAllocator, pSemaphorePool, record_obj);
        }
    }
    return result;
}

#endif  // VK_USE_PLATFORM_SCI
#ifdef VK_USE_PLATFORM_SCREEN_QNX
VKAPI_ATTR VkResult VKAPI_CALL GetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer,
                                                            VkScreenBufferPropertiesQNX* pProperties) {
    VVL_ZoneScoped;

    auto device_dispatch = vvl::dispatch::GetData(device);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetScreenBufferPropertiesQNX, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    {
        VVL_ZoneScopedN("PreCallValidate_vkGetScreenBufferPropertiesQNX");
        for (const auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallValidateGetScreenBufferPropertiesQNX]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->ReadLock();
            skip |= vo->PreCallValidateGetScreenBufferPropertiesQNX(device, buffer, pProperties, error_obj);
            if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    RecordObject record_obj(vvl::Func::vkGetScreenBufferPropertiesQNX);
    {
        VVL_ZoneScopedN("PreCallRecord_vkGetScreenBufferPropertiesQNX");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPreCallRecordGetScreenBufferPropertiesQNX]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PreCallRecordGetScreenBufferPropertiesQNX(device, buffer, pProperties, record_obj);
        }
    }
    VkResult result;
    {
        VVL_ZoneScopedN("Dispatch_vkGetScreenBufferPropertiesQNX");
        result = device_dispatch->GetScreenBufferPropertiesQNX(device, buffer, pProperties);
    }
    record_obj.result = result;
    {
        VVL_ZoneScopedN("PostCallRecord_vkGetScreenBufferPropertiesQNX");
        for (auto& vo : device_dispatch->intercept_vectors[InterceptIdPostCallRecordGetScreenBufferPropertiesQNX]) {
            if (!vo) {
                continue;
            }
            auto lock = vo->WriteLock();
            vo->PostCallRecordGetScreenBufferPropertiesQNX(device, buffer, pProperties, record_obj);
        }
    }
    return result;
}

#endif  // VK_USE_PLATFORM_SCREEN_QNX

// Map of intercepted ApiName to its associated function data
#ifdef _MSC_VER
#pragma warning(suppress : 6262)  // VS analysis: this uses more than 16 kiB, which is fine here at global scope
#endif

const vvl::unordered_map<std::string, function_data>& GetNameToFuncPtrMap() {
    static const vvl::unordered_map<std::string, function_data> name_to_func_ptr_map = {
        {"vk_layerGetPhysicalDeviceProcAddr", {kFuncTypeInst, (void*)GetPhysicalDeviceProcAddr}},
        {"vkCreateInstance", {kFuncTypeInst, (void*)CreateInstance}},
        {"vkDestroyInstance", {kFuncTypeInst, (void*)DestroyInstance}},
        {"vkEnumeratePhysicalDevices", {kFuncTypeInst, (void*)EnumeratePhysicalDevices}},
        {"vkGetPhysicalDeviceFeatures", {kFuncTypePdev, (void*)GetPhysicalDeviceFeatures}},
        {"vkGetPhysicalDeviceFormatProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceFormatProperties}},
        {"vkGetPhysicalDeviceImageFormatProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceImageFormatProperties}},
        {"vkGetPhysicalDeviceProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceProperties}},
        {"vkGetPhysicalDeviceQueueFamilyProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceQueueFamilyProperties}},
        {"vkGetPhysicalDeviceMemoryProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceMemoryProperties}},
        {"vkGetInstanceProcAddr", {kFuncTypeInst, (void*)GetInstanceProcAddr}},
        {"vkGetDeviceProcAddr", {kFuncTypeDev, (void*)GetDeviceProcAddr}},
        {"vkCreateDevice", {kFuncTypePdev, (void*)CreateDevice}},
        {"vkDestroyDevice", {kFuncTypeDev, (void*)DestroyDevice}},
        {"vkEnumerateInstanceExtensionProperties", {kFuncTypeInst, (void*)EnumerateInstanceExtensionProperties}},
        {"vkEnumerateDeviceExtensionProperties", {kFuncTypePdev, (void*)EnumerateDeviceExtensionProperties}},
        {"vkEnumerateInstanceLayerProperties", {kFuncTypeInst, (void*)EnumerateInstanceLayerProperties}},
        {"vkEnumerateDeviceLayerProperties", {kFuncTypePdev, (void*)EnumerateDeviceLayerProperties}},
        {"vkGetDeviceQueue", {kFuncTypeDev, (void*)GetDeviceQueue}},
        {"vkQueueSubmit", {kFuncTypeDev, (void*)QueueSubmit}},
        {"vkQueueWaitIdle", {kFuncTypeDev, (void*)QueueWaitIdle}},
        {"vkDeviceWaitIdle", {kFuncTypeDev, (void*)DeviceWaitIdle}},
        {"vkAllocateMemory", {kFuncTypeDev, (void*)AllocateMemory}},
        {"vkMapMemory", {kFuncTypeDev, (void*)MapMemory}},
        {"vkUnmapMemory", {kFuncTypeDev, (void*)UnmapMemory}},
        {"vkFlushMappedMemoryRanges", {kFuncTypeDev, (void*)FlushMappedMemoryRanges}},
        {"vkInvalidateMappedMemoryRanges", {kFuncTypeDev, (void*)InvalidateMappedMemoryRanges}},
        {"vkGetDeviceMemoryCommitment", {kFuncTypeDev, (void*)GetDeviceMemoryCommitment}},
        {"vkBindBufferMemory", {kFuncTypeDev, (void*)BindBufferMemory}},
        {"vkBindImageMemory", {kFuncTypeDev, (void*)BindImageMemory}},
        {"vkGetBufferMemoryRequirements", {kFuncTypeDev, (void*)GetBufferMemoryRequirements}},
        {"vkGetImageMemoryRequirements", {kFuncTypeDev, (void*)GetImageMemoryRequirements}},
        {"vkCreateFence", {kFuncTypeDev, (void*)CreateFence}},
        {"vkDestroyFence", {kFuncTypeDev, (void*)DestroyFence}},
        {"vkResetFences", {kFuncTypeDev, (void*)ResetFences}},
        {"vkGetFenceStatus", {kFuncTypeDev, (void*)GetFenceStatus}},
        {"vkWaitForFences", {kFuncTypeDev, (void*)WaitForFences}},
        {"vkCreateSemaphore", {kFuncTypeDev, (void*)CreateSemaphore}},
        {"vkDestroySemaphore", {kFuncTypeDev, (void*)DestroySemaphore}},
        {"vkCreateQueryPool", {kFuncTypeDev, (void*)CreateQueryPool}},
        {"vkGetQueryPoolResults", {kFuncTypeDev, (void*)GetQueryPoolResults}},
        {"vkCreateBuffer", {kFuncTypeDev, (void*)CreateBuffer}},
        {"vkDestroyBuffer", {kFuncTypeDev, (void*)DestroyBuffer}},
        {"vkCreateImage", {kFuncTypeDev, (void*)CreateImage}},
        {"vkDestroyImage", {kFuncTypeDev, (void*)DestroyImage}},
        {"vkGetImageSubresourceLayout", {kFuncTypeDev, (void*)GetImageSubresourceLayout}},
        {"vkCreateImageView", {kFuncTypeDev, (void*)CreateImageView}},
        {"vkDestroyImageView", {kFuncTypeDev, (void*)DestroyImageView}},
        {"vkCreateCommandPool", {kFuncTypeDev, (void*)CreateCommandPool}},
        {"vkResetCommandPool", {kFuncTypeDev, (void*)ResetCommandPool}},
        {"vkAllocateCommandBuffers", {kFuncTypeDev, (void*)AllocateCommandBuffers}},
        {"vkFreeCommandBuffers", {kFuncTypeDev, (void*)FreeCommandBuffers}},
        {"vkBeginCommandBuffer", {kFuncTypeDev, (void*)BeginCommandBuffer}},
        {"vkEndCommandBuffer", {kFuncTypeDev, (void*)EndCommandBuffer}},
        {"vkResetCommandBuffer", {kFuncTypeDev, (void*)ResetCommandBuffer}},
        {"vkCmdCopyBuffer", {kFuncTypeDev, (void*)CmdCopyBuffer}},
        {"vkCmdCopyImage", {kFuncTypeDev, (void*)CmdCopyImage}},
        {"vkCmdCopyBufferToImage", {kFuncTypeDev, (void*)CmdCopyBufferToImage}},
        {"vkCmdCopyImageToBuffer", {kFuncTypeDev, (void*)CmdCopyImageToBuffer}},
        {"vkCmdUpdateBuffer", {kFuncTypeDev, (void*)CmdUpdateBuffer}},
        {"vkCmdFillBuffer", {kFuncTypeDev, (void*)CmdFillBuffer}},
        {"vkCmdPipelineBarrier", {kFuncTypeDev, (void*)CmdPipelineBarrier}},
        {"vkCmdBeginQuery", {kFuncTypeDev, (void*)CmdBeginQuery}},
        {"vkCmdEndQuery", {kFuncTypeDev, (void*)CmdEndQuery}},
        {"vkCmdResetQueryPool", {kFuncTypeDev, (void*)CmdResetQueryPool}},
        {"vkCmdWriteTimestamp", {kFuncTypeDev, (void*)CmdWriteTimestamp}},
        {"vkCmdCopyQueryPoolResults", {kFuncTypeDev, (void*)CmdCopyQueryPoolResults}},
        {"vkCmdExecuteCommands", {kFuncTypeDev, (void*)CmdExecuteCommands}},
        {"vkCreateEvent", {kFuncTypeDev, (void*)CreateEvent}},
        {"vkDestroyEvent", {kFuncTypeDev, (void*)DestroyEvent}},
        {"vkGetEventStatus", {kFuncTypeDev, (void*)GetEventStatus}},
        {"vkSetEvent", {kFuncTypeDev, (void*)SetEvent}},
        {"vkResetEvent", {kFuncTypeDev, (void*)ResetEvent}},
        {"vkCreateBufferView", {kFuncTypeDev, (void*)CreateBufferView}},
        {"vkDestroyBufferView", {kFuncTypeDev, (void*)DestroyBufferView}},
        {"vkCreatePipelineCache", {kFuncTypeDev, (void*)CreatePipelineCache}},
        {"vkDestroyPipelineCache", {kFuncTypeDev, (void*)DestroyPipelineCache}},
        {"vkCreateComputePipelines", {kFuncTypeDev, (void*)CreateComputePipelines}},
        {"vkDestroyPipeline", {kFuncTypeDev, (void*)DestroyPipeline}},
        {"vkCreatePipelineLayout", {kFuncTypeDev, (void*)CreatePipelineLayout}},
        {"vkDestroyPipelineLayout", {kFuncTypeDev, (void*)DestroyPipelineLayout}},
        {"vkCreateSampler", {kFuncTypeDev, (void*)CreateSampler}},
        {"vkDestroySampler", {kFuncTypeDev, (void*)DestroySampler}},
        {"vkCreateDescriptorSetLayout", {kFuncTypeDev, (void*)CreateDescriptorSetLayout}},
        {"vkDestroyDescriptorSetLayout", {kFuncTypeDev, (void*)DestroyDescriptorSetLayout}},
        {"vkCreateDescriptorPool", {kFuncTypeDev, (void*)CreateDescriptorPool}},
        {"vkResetDescriptorPool", {kFuncTypeDev, (void*)ResetDescriptorPool}},
        {"vkAllocateDescriptorSets", {kFuncTypeDev, (void*)AllocateDescriptorSets}},
        {"vkFreeDescriptorSets", {kFuncTypeDev, (void*)FreeDescriptorSets}},
        {"vkUpdateDescriptorSets", {kFuncTypeDev, (void*)UpdateDescriptorSets}},
        {"vkCmdBindPipeline", {kFuncTypeDev, (void*)CmdBindPipeline}},
        {"vkCmdBindDescriptorSets", {kFuncTypeDev, (void*)CmdBindDescriptorSets}},
        {"vkCmdClearColorImage", {kFuncTypeDev, (void*)CmdClearColorImage}},
        {"vkCmdDispatch", {kFuncTypeDev, (void*)CmdDispatch}},
        {"vkCmdDispatchIndirect", {kFuncTypeDev, (void*)CmdDispatchIndirect}},
        {"vkCmdSetEvent", {kFuncTypeDev, (void*)CmdSetEvent}},
        {"vkCmdResetEvent", {kFuncTypeDev, (void*)CmdResetEvent}},
        {"vkCmdWaitEvents", {kFuncTypeDev, (void*)CmdWaitEvents}},
        {"vkCmdPushConstants", {kFuncTypeDev, (void*)CmdPushConstants}},
        {"vkCreateGraphicsPipelines", {kFuncTypeDev, (void*)CreateGraphicsPipelines}},
        {"vkCreateFramebuffer", {kFuncTypeDev, (void*)CreateFramebuffer}},
        {"vkDestroyFramebuffer", {kFuncTypeDev, (void*)DestroyFramebuffer}},
        {"vkCreateRenderPass", {kFuncTypeDev, (void*)CreateRenderPass}},
        {"vkDestroyRenderPass", {kFuncTypeDev, (void*)DestroyRenderPass}},
        {"vkGetRenderAreaGranularity", {kFuncTypeDev, (void*)GetRenderAreaGranularity}},
        {"vkCmdSetViewport", {kFuncTypeDev, (void*)CmdSetViewport}},
        {"vkCmdSetScissor", {kFuncTypeDev, (void*)CmdSetScissor}},
        {"vkCmdSetLineWidth", {kFuncTypeDev, (void*)CmdSetLineWidth}},
        {"vkCmdSetDepthBias", {kFuncTypeDev, (void*)CmdSetDepthBias}},
        {"vkCmdSetBlendConstants", {kFuncTypeDev, (void*)CmdSetBlendConstants}},
        {"vkCmdSetDepthBounds", {kFuncTypeDev, (void*)CmdSetDepthBounds}},
        {"vkCmdSetStencilCompareMask", {kFuncTypeDev, (void*)CmdSetStencilCompareMask}},
        {"vkCmdSetStencilWriteMask", {kFuncTypeDev, (void*)CmdSetStencilWriteMask}},
        {"vkCmdSetStencilReference", {kFuncTypeDev, (void*)CmdSetStencilReference}},
        {"vkCmdBindIndexBuffer", {kFuncTypeDev, (void*)CmdBindIndexBuffer}},
        {"vkCmdBindVertexBuffers", {kFuncTypeDev, (void*)CmdBindVertexBuffers}},
        {"vkCmdDraw", {kFuncTypeDev, (void*)CmdDraw}},
        {"vkCmdDrawIndexed", {kFuncTypeDev, (void*)CmdDrawIndexed}},
        {"vkCmdDrawIndirect", {kFuncTypeDev, (void*)CmdDrawIndirect}},
        {"vkCmdDrawIndexedIndirect", {kFuncTypeDev, (void*)CmdDrawIndexedIndirect}},
        {"vkCmdBlitImage", {kFuncTypeDev, (void*)CmdBlitImage}},
        {"vkCmdClearDepthStencilImage", {kFuncTypeDev, (void*)CmdClearDepthStencilImage}},
        {"vkCmdClearAttachments", {kFuncTypeDev, (void*)CmdClearAttachments}},
        {"vkCmdResolveImage", {kFuncTypeDev, (void*)CmdResolveImage}},
        {"vkCmdBeginRenderPass", {kFuncTypeDev, (void*)CmdBeginRenderPass}},
        {"vkCmdNextSubpass", {kFuncTypeDev, (void*)CmdNextSubpass}},
        {"vkCmdEndRenderPass", {kFuncTypeDev, (void*)CmdEndRenderPass}},
        {"vkEnumerateInstanceVersion", {kFuncTypeInst, (void*)EnumerateInstanceVersion}},
        {"vkBindBufferMemory2", {kFuncTypeDev, (void*)BindBufferMemory2}},
        {"vkBindImageMemory2", {kFuncTypeDev, (void*)BindImageMemory2}},
        {"vkGetDeviceGroupPeerMemoryFeatures", {kFuncTypeDev, (void*)GetDeviceGroupPeerMemoryFeatures}},
        {"vkCmdSetDeviceMask", {kFuncTypeDev, (void*)CmdSetDeviceMask}},
        {"vkEnumeratePhysicalDeviceGroups", {kFuncTypeInst, (void*)EnumeratePhysicalDeviceGroups}},
        {"vkGetImageMemoryRequirements2", {kFuncTypeDev, (void*)GetImageMemoryRequirements2}},
        {"vkGetBufferMemoryRequirements2", {kFuncTypeDev, (void*)GetBufferMemoryRequirements2}},
        {"vkGetPhysicalDeviceFeatures2", {kFuncTypePdev, (void*)GetPhysicalDeviceFeatures2}},
        {"vkGetPhysicalDeviceProperties2", {kFuncTypePdev, (void*)GetPhysicalDeviceProperties2}},
        {"vkGetPhysicalDeviceFormatProperties2", {kFuncTypePdev, (void*)GetPhysicalDeviceFormatProperties2}},
        {"vkGetPhysicalDeviceImageFormatProperties2", {kFuncTypePdev, (void*)GetPhysicalDeviceImageFormatProperties2}},
        {"vkGetPhysicalDeviceQueueFamilyProperties2", {kFuncTypePdev, (void*)GetPhysicalDeviceQueueFamilyProperties2}},
        {"vkGetPhysicalDeviceMemoryProperties2", {kFuncTypePdev, (void*)GetPhysicalDeviceMemoryProperties2}},
        {"vkGetDeviceQueue2", {kFuncTypeDev, (void*)GetDeviceQueue2}},
        {"vkGetPhysicalDeviceExternalBufferProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceExternalBufferProperties}},
        {"vkGetPhysicalDeviceExternalFenceProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceExternalFenceProperties}},
        {"vkGetPhysicalDeviceExternalSemaphoreProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceExternalSemaphoreProperties}},
        {"vkCmdDispatchBase", {kFuncTypeDev, (void*)CmdDispatchBase}},
        {"vkGetDescriptorSetLayoutSupport", {kFuncTypeDev, (void*)GetDescriptorSetLayoutSupport}},
        {"vkCreateSamplerYcbcrConversion", {kFuncTypeDev, (void*)CreateSamplerYcbcrConversion}},
        {"vkDestroySamplerYcbcrConversion", {kFuncTypeDev, (void*)DestroySamplerYcbcrConversion}},
        {"vkResetQueryPool", {kFuncTypeDev, (void*)ResetQueryPool}},
        {"vkGetSemaphoreCounterValue", {kFuncTypeDev, (void*)GetSemaphoreCounterValue}},
        {"vkWaitSemaphores", {kFuncTypeDev, (void*)WaitSemaphores}},
        {"vkSignalSemaphore", {kFuncTypeDev, (void*)SignalSemaphore}},
        {"vkGetBufferDeviceAddress", {kFuncTypeDev, (void*)GetBufferDeviceAddress}},
        {"vkGetBufferOpaqueCaptureAddress", {kFuncTypeDev, (void*)GetBufferOpaqueCaptureAddress}},
        {"vkGetDeviceMemoryOpaqueCaptureAddress", {kFuncTypeDev, (void*)GetDeviceMemoryOpaqueCaptureAddress}},
        {"vkCmdDrawIndirectCount", {kFuncTypeDev, (void*)CmdDrawIndirectCount}},
        {"vkCmdDrawIndexedIndirectCount", {kFuncTypeDev, (void*)CmdDrawIndexedIndirectCount}},
        {"vkCreateRenderPass2", {kFuncTypeDev, (void*)CreateRenderPass2}},
        {"vkCmdBeginRenderPass2", {kFuncTypeDev, (void*)CmdBeginRenderPass2}},
        {"vkCmdNextSubpass2", {kFuncTypeDev, (void*)CmdNextSubpass2}},
        {"vkCmdEndRenderPass2", {kFuncTypeDev, (void*)CmdEndRenderPass2}},
        {"vkGetPhysicalDeviceToolProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceToolProperties}},
        {"vkCreatePrivateDataSlot", {kFuncTypeDev, (void*)CreatePrivateDataSlot}},
        {"vkDestroyPrivateDataSlot", {kFuncTypeDev, (void*)DestroyPrivateDataSlot}},
        {"vkSetPrivateData", {kFuncTypeDev, (void*)SetPrivateData}},
        {"vkGetPrivateData", {kFuncTypeDev, (void*)GetPrivateData}},
        {"vkCmdPipelineBarrier2", {kFuncTypeDev, (void*)CmdPipelineBarrier2}},
        {"vkCmdWriteTimestamp2", {kFuncTypeDev, (void*)CmdWriteTimestamp2}},
        {"vkQueueSubmit2", {kFuncTypeDev, (void*)QueueSubmit2}},
        {"vkCmdCopyBuffer2", {kFuncTypeDev, (void*)CmdCopyBuffer2}},
        {"vkCmdCopyImage2", {kFuncTypeDev, (void*)CmdCopyImage2}},
        {"vkCmdCopyBufferToImage2", {kFuncTypeDev, (void*)CmdCopyBufferToImage2}},
        {"vkCmdCopyImageToBuffer2", {kFuncTypeDev, (void*)CmdCopyImageToBuffer2}},
        {"vkGetDeviceBufferMemoryRequirements", {kFuncTypeDev, (void*)GetDeviceBufferMemoryRequirements}},
        {"vkGetDeviceImageMemoryRequirements", {kFuncTypeDev, (void*)GetDeviceImageMemoryRequirements}},
        {"vkGetDeviceImageSparseMemoryRequirements", {kFuncTypeDev, (void*)GetDeviceImageSparseMemoryRequirements}},
        {"vkCmdSetEvent2", {kFuncTypeDev, (void*)CmdSetEvent2}},
        {"vkCmdResetEvent2", {kFuncTypeDev, (void*)CmdResetEvent2}},
        {"vkCmdWaitEvents2", {kFuncTypeDev, (void*)CmdWaitEvents2}},
        {"vkCmdBlitImage2", {kFuncTypeDev, (void*)CmdBlitImage2}},
        {"vkCmdResolveImage2", {kFuncTypeDev, (void*)CmdResolveImage2}},
        {"vkCmdBeginRendering", {kFuncTypeDev, (void*)CmdBeginRendering}},
        {"vkCmdEndRendering", {kFuncTypeDev, (void*)CmdEndRendering}},
        {"vkCmdSetCullMode", {kFuncTypeDev, (void*)CmdSetCullMode}},
        {"vkCmdSetFrontFace", {kFuncTypeDev, (void*)CmdSetFrontFace}},
        {"vkCmdSetPrimitiveTopology", {kFuncTypeDev, (void*)CmdSetPrimitiveTopology}},
        {"vkCmdSetViewportWithCount", {kFuncTypeDev, (void*)CmdSetViewportWithCount}},
        {"vkCmdSetScissorWithCount", {kFuncTypeDev, (void*)CmdSetScissorWithCount}},
        {"vkCmdBindVertexBuffers2", {kFuncTypeDev, (void*)CmdBindVertexBuffers2}},
        {"vkCmdSetDepthTestEnable", {kFuncTypeDev, (void*)CmdSetDepthTestEnable}},
        {"vkCmdSetDepthWriteEnable", {kFuncTypeDev, (void*)CmdSetDepthWriteEnable}},
        {"vkCmdSetDepthCompareOp", {kFuncTypeDev, (void*)CmdSetDepthCompareOp}},
        {"vkCmdSetDepthBoundsTestEnable", {kFuncTypeDev, (void*)CmdSetDepthBoundsTestEnable}},
        {"vkCmdSetStencilTestEnable", {kFuncTypeDev, (void*)CmdSetStencilTestEnable}},
        {"vkCmdSetStencilOp", {kFuncTypeDev, (void*)CmdSetStencilOp}},
        {"vkCmdSetRasterizerDiscardEnable", {kFuncTypeDev, (void*)CmdSetRasterizerDiscardEnable}},
        {"vkCmdSetDepthBiasEnable", {kFuncTypeDev, (void*)CmdSetDepthBiasEnable}},
        {"vkCmdSetPrimitiveRestartEnable", {kFuncTypeDev, (void*)CmdSetPrimitiveRestartEnable}},
        {"vkMapMemory2", {kFuncTypeDev, (void*)MapMemory2}},
        {"vkUnmapMemory2", {kFuncTypeDev, (void*)UnmapMemory2}},
        {"vkGetDeviceImageSubresourceLayout", {kFuncTypeDev, (void*)GetDeviceImageSubresourceLayout}},
        {"vkGetImageSubresourceLayout2", {kFuncTypeDev, (void*)GetImageSubresourceLayout2}},
        {"vkCopyMemoryToImage", {kFuncTypeDev, (void*)CopyMemoryToImage}},
        {"vkCopyImageToMemory", {kFuncTypeDev, (void*)CopyImageToMemory}},
        {"vkCopyImageToImage", {kFuncTypeDev, (void*)CopyImageToImage}},
        {"vkTransitionImageLayout", {kFuncTypeDev, (void*)TransitionImageLayout}},
        {"vkCmdPushDescriptorSet", {kFuncTypeDev, (void*)CmdPushDescriptorSet}},
        {"vkCmdBindDescriptorSets2", {kFuncTypeDev, (void*)CmdBindDescriptorSets2}},
        {"vkCmdPushConstants2", {kFuncTypeDev, (void*)CmdPushConstants2}},
        {"vkCmdPushDescriptorSet2", {kFuncTypeDev, (void*)CmdPushDescriptorSet2}},
        {"vkCmdSetLineStipple", {kFuncTypeDev, (void*)CmdSetLineStipple}},
        {"vkCmdBindIndexBuffer2", {kFuncTypeDev, (void*)CmdBindIndexBuffer2}},
        {"vkGetRenderingAreaGranularity", {kFuncTypeDev, (void*)GetRenderingAreaGranularity}},
        {"vkCmdSetRenderingAttachmentLocations", {kFuncTypeDev, (void*)CmdSetRenderingAttachmentLocations}},
        {"vkCmdSetRenderingInputAttachmentIndices", {kFuncTypeDev, (void*)CmdSetRenderingInputAttachmentIndices}},
        {"vkGetCommandPoolMemoryConsumption", {kFuncTypeDev, (void*)GetCommandPoolMemoryConsumption}},
        {"vkGetFaultData", {kFuncTypeDev, (void*)GetFaultData}},
        {"vkDestroySurfaceKHR", {kFuncTypeInst, (void*)DestroySurfaceKHR}},
        {"vkGetPhysicalDeviceSurfaceSupportKHR", {kFuncTypePdev, (void*)GetPhysicalDeviceSurfaceSupportKHR}},
        {"vkGetPhysicalDeviceSurfaceCapabilitiesKHR", {kFuncTypePdev, (void*)GetPhysicalDeviceSurfaceCapabilitiesKHR}},
        {"vkGetPhysicalDeviceSurfaceFormatsKHR", {kFuncTypePdev, (void*)GetPhysicalDeviceSurfaceFormatsKHR}},
        {"vkGetPhysicalDeviceSurfacePresentModesKHR", {kFuncTypePdev, (void*)GetPhysicalDeviceSurfacePresentModesKHR}},
        {"vkCreateSwapchainKHR", {kFuncTypeDev, (void*)CreateSwapchainKHR}},
        {"vkGetSwapchainImagesKHR", {kFuncTypeDev, (void*)GetSwapchainImagesKHR}},
        {"vkAcquireNextImageKHR", {kFuncTypeDev, (void*)AcquireNextImageKHR}},
        {"vkQueuePresentKHR", {kFuncTypeDev, (void*)QueuePresentKHR}},
        {"vkGetDeviceGroupPresentCapabilitiesKHR", {kFuncTypeDev, (void*)GetDeviceGroupPresentCapabilitiesKHR}},
        {"vkGetDeviceGroupSurfacePresentModesKHR", {kFuncTypeDev, (void*)GetDeviceGroupSurfacePresentModesKHR}},
        {"vkGetPhysicalDevicePresentRectanglesKHR", {kFuncTypePdev, (void*)GetPhysicalDevicePresentRectanglesKHR}},
        {"vkAcquireNextImage2KHR", {kFuncTypeDev, (void*)AcquireNextImage2KHR}},
        {"vkGetPhysicalDeviceDisplayPropertiesKHR", {kFuncTypePdev, (void*)GetPhysicalDeviceDisplayPropertiesKHR}},
        {"vkGetPhysicalDeviceDisplayPlanePropertiesKHR", {kFuncTypePdev, (void*)GetPhysicalDeviceDisplayPlanePropertiesKHR}},
        {"vkGetDisplayPlaneSupportedDisplaysKHR", {kFuncTypePdev, (void*)GetDisplayPlaneSupportedDisplaysKHR}},
        {"vkGetDisplayModePropertiesKHR", {kFuncTypePdev, (void*)GetDisplayModePropertiesKHR}},
        {"vkCreateDisplayModeKHR", {kFuncTypePdev, (void*)CreateDisplayModeKHR}},
        {"vkGetDisplayPlaneCapabilitiesKHR", {kFuncTypePdev, (void*)GetDisplayPlaneCapabilitiesKHR}},
        {"vkCreateDisplayPlaneSurfaceKHR", {kFuncTypeInst, (void*)CreateDisplayPlaneSurfaceKHR}},
        {"vkCreateSharedSwapchainsKHR", {kFuncTypeDev, (void*)CreateSharedSwapchainsKHR}},
        {"vkGetMemoryFdKHR", {kFuncTypeDev, (void*)GetMemoryFdKHR}},
        {"vkGetMemoryFdPropertiesKHR", {kFuncTypeDev, (void*)GetMemoryFdPropertiesKHR}},
        {"vkImportSemaphoreFdKHR", {kFuncTypeDev, (void*)ImportSemaphoreFdKHR}},
        {"vkGetSemaphoreFdKHR", {kFuncTypeDev, (void*)GetSemaphoreFdKHR}},
        {"vkGetSwapchainStatusKHR", {kFuncTypeDev, (void*)GetSwapchainStatusKHR}},
        {"vkImportFenceFdKHR", {kFuncTypeDev, (void*)ImportFenceFdKHR}},
        {"vkGetFenceFdKHR", {kFuncTypeDev, (void*)GetFenceFdKHR}},
        {"vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR",
         {kFuncTypePdev, (void*)EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR}},
        {"vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR",
         {kFuncTypePdev, (void*)GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR}},
        {"vkAcquireProfilingLockKHR", {kFuncTypeDev, (void*)AcquireProfilingLockKHR}},
        {"vkReleaseProfilingLockKHR", {kFuncTypeDev, (void*)ReleaseProfilingLockKHR}},
        {"vkGetPhysicalDeviceSurfaceCapabilities2KHR", {kFuncTypePdev, (void*)GetPhysicalDeviceSurfaceCapabilities2KHR}},
        {"vkGetPhysicalDeviceSurfaceFormats2KHR", {kFuncTypePdev, (void*)GetPhysicalDeviceSurfaceFormats2KHR}},
        {"vkGetPhysicalDeviceDisplayProperties2KHR", {kFuncTypePdev, (void*)GetPhysicalDeviceDisplayProperties2KHR}},
        {"vkGetPhysicalDeviceDisplayPlaneProperties2KHR", {kFuncTypePdev, (void*)GetPhysicalDeviceDisplayPlaneProperties2KHR}},
        {"vkGetDisplayModeProperties2KHR", {kFuncTypePdev, (void*)GetDisplayModeProperties2KHR}},
        {"vkGetDisplayPlaneCapabilities2KHR", {kFuncTypePdev, (void*)GetDisplayPlaneCapabilities2KHR}},
        {"vkGetPhysicalDeviceFragmentShadingRatesKHR", {kFuncTypePdev, (void*)GetPhysicalDeviceFragmentShadingRatesKHR}},
        {"vkCmdSetFragmentShadingRateKHR", {kFuncTypeDev, (void*)CmdSetFragmentShadingRateKHR}},
        {"vkCmdRefreshObjectsKHR", {kFuncTypeDev, (void*)CmdRefreshObjectsKHR}},
        {"vkGetPhysicalDeviceRefreshableObjectTypesKHR", {kFuncTypePdev, (void*)GetPhysicalDeviceRefreshableObjectTypesKHR}},
        {"vkCmdSetEvent2KHR", {kFuncTypeDev, (void*)CmdSetEvent2KHR}},
        {"vkCmdResetEvent2KHR", {kFuncTypeDev, (void*)CmdResetEvent2KHR}},
        {"vkCmdWaitEvents2KHR", {kFuncTypeDev, (void*)CmdWaitEvents2KHR}},
        {"vkCmdPipelineBarrier2KHR", {kFuncTypeDev, (void*)CmdPipelineBarrier2KHR}},
        {"vkCmdWriteTimestamp2KHR", {kFuncTypeDev, (void*)CmdWriteTimestamp2KHR}},
        {"vkQueueSubmit2KHR", {kFuncTypeDev, (void*)QueueSubmit2KHR}},
        {"vkCmdCopyBuffer2KHR", {kFuncTypeDev, (void*)CmdCopyBuffer2KHR}},
        {"vkCmdCopyImage2KHR", {kFuncTypeDev, (void*)CmdCopyImage2KHR}},
        {"vkCmdCopyBufferToImage2KHR", {kFuncTypeDev, (void*)CmdCopyBufferToImage2KHR}},
        {"vkCmdCopyImageToBuffer2KHR", {kFuncTypeDev, (void*)CmdCopyImageToBuffer2KHR}},
        {"vkCmdBlitImage2KHR", {kFuncTypeDev, (void*)CmdBlitImage2KHR}},
        {"vkCmdResolveImage2KHR", {kFuncTypeDev, (void*)CmdResolveImage2KHR}},
        {"vkCmdSetLineStippleKHR", {kFuncTypeDev, (void*)CmdSetLineStippleKHR}},
        {"vkGetPhysicalDeviceCalibrateableTimeDomainsKHR", {kFuncTypePdev, (void*)GetPhysicalDeviceCalibrateableTimeDomainsKHR}},
        {"vkGetCalibratedTimestampsKHR", {kFuncTypeDev, (void*)GetCalibratedTimestampsKHR}},
        {"vkReleaseDisplayEXT", {kFuncTypePdev, (void*)ReleaseDisplayEXT}},
        {"vkGetPhysicalDeviceSurfaceCapabilities2EXT", {kFuncTypePdev, (void*)GetPhysicalDeviceSurfaceCapabilities2EXT}},
        {"vkDisplayPowerControlEXT", {kFuncTypeDev, (void*)DisplayPowerControlEXT}},
        {"vkRegisterDeviceEventEXT", {kFuncTypeDev, (void*)RegisterDeviceEventEXT}},
        {"vkRegisterDisplayEventEXT", {kFuncTypeDev, (void*)RegisterDisplayEventEXT}},
        {"vkGetSwapchainCounterEXT", {kFuncTypeDev, (void*)GetSwapchainCounterEXT}},
        {"vkCmdSetDiscardRectangleEXT", {kFuncTypeDev, (void*)CmdSetDiscardRectangleEXT}},
        {"vkCmdSetDiscardRectangleEnableEXT", {kFuncTypeDev, (void*)CmdSetDiscardRectangleEnableEXT}},
        {"vkCmdSetDiscardRectangleModeEXT", {kFuncTypeDev, (void*)CmdSetDiscardRectangleModeEXT}},
        {"vkSetHdrMetadataEXT", {kFuncTypeDev, (void*)SetHdrMetadataEXT}},
        {"vkSetDebugUtilsObjectNameEXT", {kFuncTypeDev, (void*)SetDebugUtilsObjectNameEXT}},
        {"vkSetDebugUtilsObjectTagEXT", {kFuncTypeDev, (void*)SetDebugUtilsObjectTagEXT}},
        {"vkQueueBeginDebugUtilsLabelEXT", {kFuncTypeDev, (void*)QueueBeginDebugUtilsLabelEXT}},
        {"vkQueueEndDebugUtilsLabelEXT", {kFuncTypeDev, (void*)QueueEndDebugUtilsLabelEXT}},
        {"vkQueueInsertDebugUtilsLabelEXT", {kFuncTypeDev, (void*)QueueInsertDebugUtilsLabelEXT}},
        {"vkCmdBeginDebugUtilsLabelEXT", {kFuncTypeDev, (void*)CmdBeginDebugUtilsLabelEXT}},
        {"vkCmdEndDebugUtilsLabelEXT", {kFuncTypeDev, (void*)CmdEndDebugUtilsLabelEXT}},
        {"vkCmdInsertDebugUtilsLabelEXT", {kFuncTypeDev, (void*)CmdInsertDebugUtilsLabelEXT}},
        {"vkCreateDebugUtilsMessengerEXT", {kFuncTypeInst, (void*)CreateDebugUtilsMessengerEXT}},
        {"vkDestroyDebugUtilsMessengerEXT", {kFuncTypeInst, (void*)DestroyDebugUtilsMessengerEXT}},
        {"vkSubmitDebugUtilsMessageEXT", {kFuncTypeInst, (void*)SubmitDebugUtilsMessageEXT}},
        {"vkCmdSetSampleLocationsEXT", {kFuncTypeDev, (void*)CmdSetSampleLocationsEXT}},
        {"vkGetPhysicalDeviceMultisamplePropertiesEXT", {kFuncTypePdev, (void*)GetPhysicalDeviceMultisamplePropertiesEXT}},
        {"vkGetImageDrmFormatModifierPropertiesEXT", {kFuncTypeDev, (void*)GetImageDrmFormatModifierPropertiesEXT}},
        {"vkGetMemoryHostPointerPropertiesEXT", {kFuncTypeDev, (void*)GetMemoryHostPointerPropertiesEXT}},
        {"vkCreateHeadlessSurfaceEXT", {kFuncTypeInst, (void*)CreateHeadlessSurfaceEXT}},
        {"vkCmdSetLineStippleEXT", {kFuncTypeDev, (void*)CmdSetLineStippleEXT}},
        {"vkCmdSetCullModeEXT", {kFuncTypeDev, (void*)CmdSetCullModeEXT}},
        {"vkCmdSetFrontFaceEXT", {kFuncTypeDev, (void*)CmdSetFrontFaceEXT}},
        {"vkCmdSetPrimitiveTopologyEXT", {kFuncTypeDev, (void*)CmdSetPrimitiveTopologyEXT}},
        {"vkCmdSetViewportWithCountEXT", {kFuncTypeDev, (void*)CmdSetViewportWithCountEXT}},
        {"vkCmdSetScissorWithCountEXT", {kFuncTypeDev, (void*)CmdSetScissorWithCountEXT}},
        {"vkCmdBindVertexBuffers2EXT", {kFuncTypeDev, (void*)CmdBindVertexBuffers2EXT}},
        {"vkCmdSetDepthTestEnableEXT", {kFuncTypeDev, (void*)CmdSetDepthTestEnableEXT}},
        {"vkCmdSetDepthWriteEnableEXT", {kFuncTypeDev, (void*)CmdSetDepthWriteEnableEXT}},
        {"vkCmdSetDepthCompareOpEXT", {kFuncTypeDev, (void*)CmdSetDepthCompareOpEXT}},
        {"vkCmdSetDepthBoundsTestEnableEXT", {kFuncTypeDev, (void*)CmdSetDepthBoundsTestEnableEXT}},
        {"vkCmdSetStencilTestEnableEXT", {kFuncTypeDev, (void*)CmdSetStencilTestEnableEXT}},
        {"vkCmdSetStencilOpEXT", {kFuncTypeDev, (void*)CmdSetStencilOpEXT}},
#ifdef VK_USE_PLATFORM_WIN32_KHR
        {"vkAcquireWinrtDisplayNV", {kFuncTypePdev, (void*)AcquireWinrtDisplayNV}},
        {"vkGetWinrtDisplayNV", {kFuncTypePdev, (void*)GetWinrtDisplayNV}},
#endif  // VK_USE_PLATFORM_WIN32_KHR
        {"vkCmdSetVertexInputEXT", {kFuncTypeDev, (void*)CmdSetVertexInputEXT}},
#ifdef VK_USE_PLATFORM_SCI
        {"vkGetFenceSciSyncFenceNV", {kFuncTypeDev, (void*)GetFenceSciSyncFenceNV}},
        {"vkGetFenceSciSyncObjNV", {kFuncTypeDev, (void*)GetFenceSciSyncObjNV}},
        {"vkImportFenceSciSyncFenceNV", {kFuncTypeDev, (void*)ImportFenceSciSyncFenceNV}},
        {"vkImportFenceSciSyncObjNV", {kFuncTypeDev, (void*)ImportFenceSciSyncObjNV}},
        {"vkGetPhysicalDeviceSciSyncAttributesNV", {kFuncTypePdev, (void*)GetPhysicalDeviceSciSyncAttributesNV}},
        {"vkGetSemaphoreSciSyncObjNV", {kFuncTypeDev, (void*)GetSemaphoreSciSyncObjNV}},
        {"vkImportSemaphoreSciSyncObjNV", {kFuncTypeDev, (void*)ImportSemaphoreSciSyncObjNV}},
        {"vkGetMemorySciBufNV", {kFuncTypeDev, (void*)GetMemorySciBufNV}},
        {"vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV",
         {kFuncTypePdev, (void*)GetPhysicalDeviceExternalMemorySciBufPropertiesNV}},
        {"vkGetPhysicalDeviceSciBufAttributesNV", {kFuncTypePdev, (void*)GetPhysicalDeviceSciBufAttributesNV}},
#endif  // VK_USE_PLATFORM_SCI
        {"vkCmdSetPatchControlPointsEXT", {kFuncTypeDev, (void*)CmdSetPatchControlPointsEXT}},
        {"vkCmdSetRasterizerDiscardEnableEXT", {kFuncTypeDev, (void*)CmdSetRasterizerDiscardEnableEXT}},
        {"vkCmdSetDepthBiasEnableEXT", {kFuncTypeDev, (void*)CmdSetDepthBiasEnableEXT}},
        {"vkCmdSetLogicOpEXT", {kFuncTypeDev, (void*)CmdSetLogicOpEXT}},
        {"vkCmdSetPrimitiveRestartEnableEXT", {kFuncTypeDev, (void*)CmdSetPrimitiveRestartEnableEXT}},
        {"vkCmdSetColorWriteEnableEXT", {kFuncTypeDev, (void*)CmdSetColorWriteEnableEXT}},
#ifdef VK_USE_PLATFORM_SCI
        {"vkCreateSemaphoreSciSyncPoolNV", {kFuncTypeDev, (void*)CreateSemaphoreSciSyncPoolNV}},
#endif  // VK_USE_PLATFORM_SCI
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        {"vkGetScreenBufferPropertiesQNX", {kFuncTypeDev, (void*)GetScreenBufferPropertiesQNX}},
#endif  // VK_USE_PLATFORM_SCREEN_QNX
    };
    return name_to_func_ptr_map;
}
}  // namespace vulkan_layer_chassis

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vk_layerGetPhysicalDeviceProcAddr(VkInstance instance, const char* funcName) {
    return vulkan_layer_chassis::GetPhysicalDeviceProcAddr(instance, funcName);
}

#if defined(__GNUC__) && __GNUC__ >= 4
#define VVL_EXPORT __attribute__((visibility("default")))
#else
#define VVL_EXPORT
#endif

// The following functions need to match the `/DEF` and `--version-script` files
// for consistency across platforms that don't accept those linker options.
extern "C" {

VVL_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance instance, const char* funcName) {
    return vulkan_layer_chassis::GetInstanceProcAddr(instance, funcName);
}

VVL_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(VkDevice dev, const char* funcName) {
    return vulkan_layer_chassis::GetDeviceProcAddr(dev, funcName);
}

VVL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(uint32_t* pCount, VkLayerProperties* pProperties) {
    return vulkan_layer_chassis::EnumerateInstanceLayerProperties(pCount, pProperties);
}

VVL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pCount,
                                                                                 VkExtensionProperties* pProperties) {
    return vulkan_layer_chassis::EnumerateInstanceExtensionProperties(pLayerName, pCount, pProperties);
}

VVL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkNegotiateLoaderLayerInterfaceVersion(VkNegotiateLayerInterface* pVersionStruct) {
    assert(pVersionStruct != nullptr);
    assert(pVersionStruct->sType == LAYER_NEGOTIATE_INTERFACE_STRUCT);

    // Fill in the function pointers if our version is at least capable of having the structure contain them.
    if (pVersionStruct->loaderLayerInterfaceVersion >= 2) {
        pVersionStruct->pfnGetInstanceProcAddr = vulkan_layer_chassis::GetInstanceProcAddr;
        pVersionStruct->pfnGetDeviceProcAddr = vulkan_layer_chassis::GetDeviceProcAddr;
        pVersionStruct->pfnGetPhysicalDeviceProcAddr = vulkan_layer_chassis::GetPhysicalDeviceProcAddr;
    }

    return VK_SUCCESS;
}

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
VVL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pCount,
                                                                           VkLayerProperties* pProperties) {
    // the layer command handles VK_NULL_HANDLE just fine internally
    assert(physicalDevice == VK_NULL_HANDLE);
    return vulkan_layer_chassis::EnumerateDeviceLayerProperties(VK_NULL_HANDLE, pCount, pProperties);
}

VVL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice,
                                                                               const char* pLayerName, uint32_t* pCount,
                                                                               VkExtensionProperties* pProperties) {
    // the layer command handles VK_NULL_HANDLE just fine internally
    assert(physicalDevice == VK_NULL_HANDLE);
    return vulkan_layer_chassis::EnumerateDeviceExtensionProperties(VK_NULL_HANDLE, pLayerName, pCount, pProperties);
}
#endif

}  // extern "C"

// NOLINTEND
