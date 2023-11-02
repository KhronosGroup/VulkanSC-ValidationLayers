// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See layer_chassis_generator.py for modifications

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

// NOLINTBEGIN

#include <array>
#include <cstring>
#include <mutex>

#include "chassis.h"
#include "layer_options.h"
#include "layer_chassis_dispatch.h"

thread_local WriteLockGuard* ValidationObject::record_guard{};

small_unordered_map<void*, ValidationObject*, 2> layer_data_map;

// Global unique object identifier.
std::atomic<uint64_t> global_unique_id(1ULL);
// Map uniqueID to actual object handle. Accesses to the map itself are
// internally synchronized.
vl_concurrent_unordered_map<uint64_t, uint64_t, 4, HashedUint64> unique_id_mapping;

bool wrap_handles = true;

#define OBJECT_LAYER_DESCRIPTION "khronos_validation"

// Include layer validation object definitions
#include "thread_tracker/thread_safety_validation.h"
#include "stateless/stateless_validation.h"
#include "object_tracker/object_lifetime_validation.h"
#include "vulkansc/core_checks/sc_core_validation.h"
#include "sync/sync_validation.h"

// This header file must be included after the above validation object class definitions
#include "chassis_dispatch_helper.h"

// Extension exposed by the validation layer
static constexpr std::array kInstanceExtensions = {
    VkExtensionProperties{VK_EXT_DEBUG_UTILS_EXTENSION_NAME, VK_EXT_DEBUG_UTILS_SPEC_VERSION},
    VkExtensionProperties{VK_EXT_VALIDATION_FEATURES_EXTENSION_NAME, VK_EXT_VALIDATION_FEATURES_SPEC_VERSION},
};
static constexpr std::array kDeviceExtensions = {
    VkExtensionProperties{VK_EXT_VALIDATION_CACHE_EXTENSION_NAME, VK_EXT_VALIDATION_CACHE_SPEC_VERSION},
    VkExtensionProperties{VK_EXT_TOOLING_INFO_EXTENSION_NAME, VK_EXT_TOOLING_INFO_SPEC_VERSION},
};

// Layer registration code
static std::vector<ValidationObject*> CreateObjectDispatch(const CHECK_ENABLED& enables, const CHECK_DISABLED& disables) {
    std::vector<ValidationObject*> object_dispatch{};

    // Add VOs to dispatch vector. Order here will be the validation dispatch order!

    if (!disables[thread_safety]) {
        object_dispatch.emplace_back(new ThreadSafety(nullptr));
    }
    if (!disables[stateless_checks]) {
        object_dispatch.emplace_back(new StatelessValidation);
    }
    if (!disables[object_tracking]) {
        object_dispatch.emplace_back(new ObjectLifetimes);
    }
    if (!disables[core_checks]) {
        object_dispatch.emplace_back(new SCCoreChecks);
    }
    if (enables[sync_validation]) {
        object_dispatch.emplace_back(new SyncValidator);
    }
    return object_dispatch;
}

static void InitDeviceObjectDispatch(ValidationObject* instance_interceptor, ValidationObject* device_interceptor) {
    auto disables = instance_interceptor->disabled;
    auto enables = instance_interceptor->enabled;

    // Note that this DEFINES THE ORDER IN WHICH THE LAYER VALIDATION OBJECTS ARE CALLED

    if (!disables[thread_safety]) {
        device_interceptor->object_dispatch.emplace_back(
            new ThreadSafety(instance_interceptor->GetValidationObject<ThreadSafety>()));
    }
    if (!disables[stateless_checks]) {
        device_interceptor->object_dispatch.emplace_back(new StatelessValidation);
    }
    if (!disables[object_tracking]) {
        device_interceptor->object_dispatch.emplace_back(new ObjectLifetimes);
    }
    if (!disables[core_checks]) {
        device_interceptor->object_dispatch.emplace_back(new SCCoreChecks);
    }
    if (enables[sync_validation]) {
        device_interceptor->object_dispatch.emplace_back(new SyncValidator);
    }
}

// Global list of sType,size identifiers
std::vector<std::pair<uint32_t, uint32_t>> custom_stype_info{};

template <typename ValidationObjectType>
ValidationObjectType* ValidationObject::GetValidationObject() const {
    LayerObjectTypeId type_id;
    if constexpr (std::is_same_v<ValidationObjectType, ThreadSafety>) {
        type_id = LayerObjectTypeThreading;
    } else if constexpr (std::is_same_v<ValidationObjectType, StatelessValidation>) {
        type_id = LayerObjectTypeParameterValidation;
    } else if constexpr (std::is_same_v<ValidationObjectType, ObjectLifetimes>) {
        type_id = LayerObjectTypeObjectTracker;
    } else if constexpr (std::is_same_v<ValidationObjectType, CoreChecks>) {
        type_id = LayerObjectTypeCoreValidation;
    } else {
        static_assert(vvl::dependent_false_v<ValidationObjectType>, "unsupported validation object type");
    }
    return static_cast<ValidationObjectType*>(GetValidationObject(type_id));
}

template ThreadSafety* ValidationObject::GetValidationObject<ThreadSafety>() const;
template StatelessValidation* ValidationObject::GetValidationObject<StatelessValidation>() const;
template ObjectLifetimes* ValidationObject::GetValidationObject<ObjectLifetimes>() const;
template CoreChecks* ValidationObject::GetValidationObject<CoreChecks>() const;

namespace vulkan_layer_chassis {

static const VkLayerProperties global_layer = {
    OBJECT_LAYER_NAME,
    VK_LAYER_API_VERSION,
    1,
    "LunarG validation Layer",
};

typedef enum ApiFunctionType { kFuncTypeInst = 0, kFuncTypePdev = 1, kFuncTypeDev = 2 } ApiFunctionType;

typedef struct {
    ApiFunctionType function_type;
    void* funcptr;
} function_data;

extern const vvl::unordered_map<std::string, function_data> name_to_funcptr_map;

// Manually written functions

// Check enabled instance extensions against supported instance extension whitelist
static void InstanceExtensionWhitelist(ValidationObject* layer_data, const VkInstanceCreateInfo* pCreateInfo, VkInstance instance) {
    for (uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; i++) {
        // Check for recognized instance extensions
        if (!white_list(pCreateInfo->ppEnabledExtensionNames[i], kInstanceExtensionNames)) {
            Location loc(vvl::Func::vkCreateInstance);
            layer_data->LogWarning(kVUIDUndefined, layer_data->instance,
                                   loc.dot(vvl::Field::pCreateInfo).dot(vvl::Field::ppEnabledExtensionNames, i),
                                   "%s is not supported by this layer.  Using this extension may adversely affect validation "
                                   "results and/or produce undefined behavior.",
                                   pCreateInfo->ppEnabledExtensionNames[i]);
        }
    }
}

// Check enabled device extensions against supported device extension whitelist
static void DeviceExtensionWhitelist(ValidationObject* layer_data, const VkDeviceCreateInfo* pCreateInfo, VkDevice device) {
    for (uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; i++) {
        // Check for recognized device extensions
        if (!white_list(pCreateInfo->ppEnabledExtensionNames[i], kDeviceExtensionNames)) {
            Location loc(vvl::Func::vkCreateDevice);
            layer_data->LogWarning(kVUIDUndefined, layer_data->device,
                                   loc.dot(vvl::Field::pCreateInfo).dot(vvl::Field::ppEnabledExtensionNames, i),
                                   "%s is not supported by this layer.  Using this extension may adversely affect validation "
                                   "results and/or produce undefined behavior.",
                                   pCreateInfo->ppEnabledExtensionNames[i]);
        }
    }
}

void OutputLayerStatusInfo(ValidationObject* context) {
    std::string list_of_enables;
    std::string list_of_disables;
    for (uint32_t i = 0; i < kMaxEnableFlags; i++) {
        if (context->enabled[i]) {
            if (list_of_enables.size()) list_of_enables.append(", ");
            list_of_enables.append(EnableFlagNameHelper[i]);
        }
    }
    if (list_of_enables.size() == 0) {
        list_of_enables.append("None");
    }
    for (uint32_t i = 0; i < kMaxDisableFlags; i++) {
        if (context->disabled[i]) {
            if (list_of_disables.size()) list_of_disables.append(", ");
            list_of_disables.append(DisableFlagNameHelper[i]);
        }
    }
    if (list_of_disables.size() == 0) {
        list_of_disables.append("None");
    }

    auto settings_info = GetLayerSettingsFileInfo();
    std::string settings_status;
    if (!settings_info->file_found) {
        settings_status = "None. Default location is ";
        settings_status.append(settings_info->location);
        settings_status.append(".");
    } else {
        settings_status = "Found at ";
        settings_status.append(settings_info->location);
        settings_status.append(" specified by ");
        switch (settings_info->source) {
            case kEnvVar:
                settings_status.append("environment variable (VK_LAYER_SETTINGS_PATH).");
                break;
            case kVkConfig:
                settings_status.append("VkConfig application override.");
                break;
            case kLocal:  // Intentionally fall through
            default:
                settings_status.append("default location (current working directory).");
                break;
        }
    }

    Location loc(vvl::Func::vkCreateInstance);
    // Output layer status information message
    context->LogInfo(
        "UNASSIGNED-CreateInstance-status-message", context->instance, loc,
        "Khronos Validation Layer Active:\n    Settings File: %s\n    Current Enables: %s.\n    Current Disables: %s.\n",
        settings_status.c_str(), list_of_enables.c_str(), list_of_disables.c_str());

    // Create warning message if user is running debug layers.
#ifndef NDEBUG
    context->LogPerformanceWarning(
        "UNASSIGNED-CreateInstance-debug-warning", context->instance, loc,
        "VALIDATION LAYERS WARNING: Using debug builds of the validation layers *will* adversely affect performance.");
#endif
    if (!context->fine_grained_locking) {
        context->LogPerformanceWarning(
            "UNASSIGNED-CreateInstance-locking-warning", context->instance, loc,
            "Fine-grained locking is disabled, this will adversely affect performance of multithreaded applications.");
    }
}

// Non-code-generated chassis API functions

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetDeviceProcAddr(VkDevice device, const char* funcName) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    if (!ApiParentExtensionEnabled(funcName, &layer_data->device_extensions)) {
        return nullptr;
    }
    const auto& item = name_to_funcptr_map.find(funcName);
    if (item != name_to_funcptr_map.end()) {
        if (item->second.function_type != kFuncTypeDev) {
            return nullptr;
        } else {
            return reinterpret_cast<PFN_vkVoidFunction>(item->second.funcptr);
        }
    }
    auto& table = layer_data->device_dispatch_table;
    if (!table.GetDeviceProcAddr) return nullptr;
    return table.GetDeviceProcAddr(device, funcName);
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetInstanceProcAddr(VkInstance instance, const char* funcName) {
    const auto& item = name_to_funcptr_map.find(funcName);
    if (item != name_to_funcptr_map.end()) {
        return reinterpret_cast<PFN_vkVoidFunction>(item->second.funcptr);
    }
    auto layer_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    auto& table = layer_data->instance_dispatch_table;
    if (!table.GetInstanceProcAddr) return nullptr;
    return table.GetInstanceProcAddr(instance, funcName);
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetPhysicalDeviceProcAddr(VkInstance instance, const char* funcName) {
    const auto& item = name_to_funcptr_map.find(funcName);
    if (item != name_to_funcptr_map.end()) {
        if (item->second.function_type != kFuncTypePdev) {
            return nullptr;
        } else {
            return reinterpret_cast<PFN_vkVoidFunction>(item->second.funcptr);
        }
    }
    auto layer_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    auto& table = layer_data->instance_dispatch_table;
    if (!table.GetPhysicalDeviceProcAddr) return nullptr;
    return table.GetPhysicalDeviceProcAddr(instance, funcName);
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
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    return layer_data->instance_dispatch_table.EnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                              VkInstance* pInstance) {
    VkLayerInstanceCreateInfo* chain_info = get_chain_info(pCreateInfo, VK_LAYER_LINK_INFO);

    assert(chain_info->u.pLayerInfo);
    PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    PFN_vkCreateInstance fpCreateInstance = (PFN_vkCreateInstance)fpGetInstanceProcAddr(nullptr, "vkCreateInstance");
    if (fpCreateInstance == nullptr) return VK_ERROR_INITIALIZATION_FAILED;
    chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;
    uint32_t specified_version = (pCreateInfo->pApplicationInfo ? pCreateInfo->pApplicationInfo->apiVersion : VK_API_VERSION_1_0);
    APIVersion api_version = VK_MAKE_API_VERSION(VK_API_VERSION_VARIANT(specified_version), VK_API_VERSION_MAJOR(specified_version),
                                                 VK_API_VERSION_MINOR(specified_version), 0);

    auto report_data = new debug_report_data{};
    report_data->instance_pnext_chain = SafePnextCopy(pCreateInfo->pNext);
    ActivateInstanceDebugCallbacks(report_data);

    // Set up enable and disable features flags
    CHECK_ENABLED local_enables{};
    CHECK_DISABLED local_disables{};
    bool lock_setting;
    // select_instrumented_shaders is the only gpu-av setting that is off by default
    GpuAVSettings local_gpuav_settings = {true, true, true, true, true, true, false, 10000};
    ConfigAndEnvSettings config_and_env_settings_data{OBJECT_LAYER_DESCRIPTION,
                                                      pCreateInfo,
                                                      local_enables,
                                                      local_disables,
                                                      report_data->filter_message_ids,
                                                      &report_data->duplicate_message_limit,
                                                      &lock_setting,
                                                      &local_gpuav_settings};
    ProcessConfigAndEnvSettings(&config_and_env_settings_data);
    layer_debug_messenger_actions(report_data, OBJECT_LAYER_DESCRIPTION);

    // Create temporary dispatch vector for pre-calls until instance is created
    std::vector<ValidationObject*> local_object_dispatch = CreateObjectDispatch(local_enables, local_disables);

    // If handle wrapping is disabled via the ValidationFeatures extension, override build flag
    if (local_disables[handle_wrapping]) {
        wrap_handles = false;
    }

    // Initialize the validation objects
    for (auto* intercept : local_object_dispatch) {
        intercept->api_version = api_version;
        intercept->report_data = report_data;
    }

    // Define logic to cleanup everything in case of an error
    auto cleanup_allocations = [report_data, &local_object_dispatch]() {
        DeactivateInstanceDebugCallbacks(report_data);
        FreePnextChain(report_data->instance_pnext_chain);
        LayerDebugUtilsDestroyInstance(report_data);
        for (ValidationObject* object : local_object_dispatch) {
            delete object;
        }
    };

    // Init dispatch array and call registration functions
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateInstance, VulkanTypedHandle());
    for (const ValidationObject* intercept : local_object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateInstance(pCreateInfo, pAllocator, pInstance, error_obj);
        if (skip) {
            cleanup_allocations();
            return VK_ERROR_VALIDATION_FAILED_EXT;
        }
    }
    for (ValidationObject* intercept : local_object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateInstance(pCreateInfo, pAllocator, pInstance);
    }

    VkResult result = fpCreateInstance(pCreateInfo, pAllocator, pInstance);
    if (result != VK_SUCCESS) {
        cleanup_allocations();
        return result;
    }
    auto framework = GetLayerDataPtr(get_dispatch_key(*pInstance), layer_data_map);

    framework->object_dispatch = local_object_dispatch;
    framework->container_type = LayerObjectTypeInstance;
    framework->disabled = local_disables;
    framework->enabled = local_enables;
    framework->fine_grained_locking = lock_setting;
    framework->gpuav_settings = local_gpuav_settings;

    framework->instance = *pInstance;
    layer_init_instance_dispatch_table(*pInstance, &framework->instance_dispatch_table, fpGetInstanceProcAddr);
    framework->report_data = report_data;
    framework->api_version = api_version;
    framework->instance_extensions.InitFromInstanceCreateInfo(specified_version, pCreateInfo);

    // We need to call this to properly check which device extensions have been promoted when validating query functions
    // that take as input a physical device, which can be called before a logical device has been created.
    framework->device_extensions.InitFromDeviceCreateInfo(&framework->instance_extensions, specified_version);

    OutputLayerStatusInfo(framework);

    for (auto* intercept : framework->object_dispatch) {
        intercept->instance_dispatch_table = framework->instance_dispatch_table;
        intercept->enabled = framework->enabled;
        intercept->disabled = framework->disabled;
        intercept->fine_grained_locking = framework->fine_grained_locking;
        intercept->gpuav_settings = framework->gpuav_settings;
        intercept->instance = *pInstance;
    }

    RecordObject record_obj(vvl::Func::vkCreateInstance, result);
    for (ValidationObject* intercept : framework->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateInstance(pCreateInfo, pAllocator, pInstance, record_obj);
    }

    InstanceExtensionWhitelist(framework, pCreateInfo, *pInstance);
    DeactivateInstanceDebugCallbacks(report_data);
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) {
    dispatch_key key = get_dispatch_key(instance);
    auto layer_data = GetLayerDataPtr(key, layer_data_map);
    ActivateInstanceDebugCallbacks(layer_data->report_data);
    ErrorObject error_obj(vvl::Func::vkDestroyInstance, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));

    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        intercept->PreCallValidateDestroyInstance(instance, pAllocator, error_obj);
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyInstance(instance, pAllocator);
    }

    layer_data->instance_dispatch_table.DestroyInstance(instance, pAllocator);

    RecordObject record_obj(vvl::Func::vkDestroyInstance);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyInstance(instance, pAllocator, record_obj);
    }

    DeactivateInstanceDebugCallbacks(layer_data->report_data);
    FreePnextChain(layer_data->report_data->instance_pnext_chain);

    LayerDebugUtilsDestroyInstance(layer_data->report_data);

    for (auto item = layer_data->object_dispatch.begin(); item != layer_data->object_dispatch.end(); item++) {
        delete *item;
    }
    FreeLayerDataPtr(key, layer_data_map);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDevice(VkPhysicalDevice gpu, const VkDeviceCreateInfo* pCreateInfo,
                                            const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) {
    VkLayerDeviceCreateInfo* chain_info = get_chain_info(pCreateInfo, VK_LAYER_LINK_INFO);

    auto instance_interceptor = GetLayerDataPtr(get_dispatch_key(gpu), layer_data_map);

    PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    PFN_vkGetDeviceProcAddr fpGetDeviceProcAddr = chain_info->u.pLayerInfo->pfnNextGetDeviceProcAddr;
    PFN_vkCreateDevice fpCreateDevice = (PFN_vkCreateDevice)fpGetInstanceProcAddr(instance_interceptor->instance, "vkCreateDevice");
    if (fpCreateDevice == nullptr) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }
    chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;

    // Get physical device limits for device
    VkPhysicalDeviceProperties device_properties = {};
    instance_interceptor->instance_dispatch_table.GetPhysicalDeviceProperties(gpu, &device_properties);

    // Setup the validation tables based on the application API version from the instance and the capabilities of the device driver
    auto effective_api_version = std::min(APIVersion(device_properties.apiVersion), instance_interceptor->api_version);

    DeviceExtensions device_extensions = {};
    device_extensions.InitFromDeviceCreateInfo(&instance_interceptor->instance_extensions, effective_api_version, pCreateInfo);
    for (auto item : instance_interceptor->object_dispatch) {
        item->device_extensions = device_extensions;
    }

    safe_VkDeviceCreateInfo modified_create_info(pCreateInfo);

    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateDevice, VulkanTypedHandle(gpu, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : instance_interceptor->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateDevice(gpu, pCreateInfo, pAllocator, pDevice, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : instance_interceptor->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateDevice(gpu, pCreateInfo, pAllocator, pDevice, &modified_create_info);
    }

    VkResult result = fpCreateDevice(gpu, reinterpret_cast<VkDeviceCreateInfo*>(&modified_create_info), pAllocator, pDevice);
    if (result != VK_SUCCESS) {
        return result;
    }

    auto device_interceptor = GetLayerDataPtr(get_dispatch_key(*pDevice), layer_data_map);
    device_interceptor->container_type = LayerObjectTypeDevice;

    // Save local info in device object
    device_interceptor->phys_dev_properties.properties = device_properties;
    device_interceptor->api_version = device_interceptor->device_extensions.InitFromDeviceCreateInfo(
        &instance_interceptor->instance_extensions, effective_api_version, pCreateInfo);
    device_interceptor->device_extensions = device_extensions;

    layer_init_device_dispatch_table(*pDevice, &device_interceptor->device_dispatch_table, fpGetDeviceProcAddr);

    device_interceptor->device = *pDevice;
    device_interceptor->physical_device = gpu;
    device_interceptor->instance = instance_interceptor->instance;
    device_interceptor->report_data = instance_interceptor->report_data;

    instance_interceptor->report_data->device_created++;

    InitDeviceObjectDispatch(instance_interceptor, device_interceptor);

    // Initialize all of the objects with the appropriate data
    for (auto* object : device_interceptor->object_dispatch) {
        object->device = device_interceptor->device;
        object->physical_device = device_interceptor->physical_device;
        object->instance = instance_interceptor->instance;
        object->report_data = instance_interceptor->report_data;
        object->device_dispatch_table = device_interceptor->device_dispatch_table;
        object->api_version = device_interceptor->api_version;
        object->disabled = instance_interceptor->disabled;
        object->enabled = instance_interceptor->enabled;
        object->fine_grained_locking = instance_interceptor->fine_grained_locking;
        object->gpuav_settings = instance_interceptor->gpuav_settings;
        object->instance_dispatch_table = instance_interceptor->instance_dispatch_table;
        object->instance_extensions = instance_interceptor->instance_extensions;
        object->device_extensions = device_interceptor->device_extensions;
    }

    RecordObject record_obj(vvl::Func::vkCreateDevice, result);
    for (ValidationObject* intercept : instance_interceptor->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateDevice(gpu, pCreateInfo, pAllocator, pDevice, record_obj);
    }

    device_interceptor->InitObjectDispatchVectors();

    DeviceExtensionWhitelist(device_interceptor, pCreateInfo, *pDevice);

    return result;
}

// NOTE: Do _not_ skip the dispatch call when destroying a device. Whether or not there was a validation error,
//       the loader will destroy the device, and know nothing about future references to this device making it
//       impossible for the caller to use this device handle further. IOW, this is our _only_ chance to (potentially)
//       dispatch the driver's DestroyDevice function.
VKAPI_ATTR void VKAPI_CALL DestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
    dispatch_key key = get_dispatch_key(device);
    auto layer_data = GetLayerDataPtr(key, layer_data_map);
    ErrorObject error_obj(vvl::Func::vkCreateDevice, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        intercept->PreCallValidateDestroyDevice(device, pAllocator, error_obj);
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyDevice(device, pAllocator);
    }

    layer_data->device_dispatch_table.DestroyDevice(device, pAllocator);

    RecordObject record_obj(vvl::Func::vkDestroyDevice);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyDevice(device, pAllocator, record_obj);
    }

    auto instance_interceptor = GetLayerDataPtr(get_dispatch_key(layer_data->physical_device), layer_data_map);
    instance_interceptor->report_data->device_created--;

    for (auto item = layer_data->object_dispatch.begin(); item != layer_data->object_dispatch.end(); item++) {
        delete *item;
    }
    FreeLayerDataPtr(key, layer_data_map);
}

// Special-case APIs for which core_validation needs custom parameter lists and/or modifies parameters

VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                                       const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                       const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateGraphicsPipelines, VulkanTypedHandle(device, kVulkanObjectTypeDevice));

    create_graphics_pipeline_api_state cgpl_state[LayerObjectTypeMaxEnum]{};

    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        cgpl_state[intercept->container_type].pCreateInfos = pCreateInfos;
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                                                  pPipelines, error_obj, &(cgpl_state[intercept->container_type]));
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                                        pPipelines, &(cgpl_state[intercept->container_type]));
    }

    auto usepCreateInfos =
        (!cgpl_state[LayerObjectTypeGpuAssisted].pCreateInfos) ? pCreateInfos : cgpl_state[LayerObjectTypeGpuAssisted].pCreateInfos;
    if (cgpl_state[LayerObjectTypeDebugPrintf].pCreateInfos) usepCreateInfos = cgpl_state[LayerObjectTypeDebugPrintf].pCreateInfos;

    VkResult result =
        DispatchCreateGraphicsPipelines(device, pipelineCache, createInfoCount, usepCreateInfos, pAllocator, pPipelines);

    RecordObject record_obj(vvl::Func::vkCreateGraphicsPipelines, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                                         pPipelines, record_obj, &(cgpl_state[intercept->container_type]));
    }
    return result;
}

// This API saves some core_validation pipeline state state on the stack for performance purposes
VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                                      const VkComputePipelineCreateInfo* pCreateInfos,
                                                      const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateComputePipelines, VulkanTypedHandle(device, kVulkanObjectTypeDevice));

    create_compute_pipeline_api_state ccpl_state[LayerObjectTypeMaxEnum]{};

    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        ccpl_state[intercept->container_type].pCreateInfos = pCreateInfos;
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                                                 pPipelines, error_obj, &(ccpl_state[intercept->container_type]));
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines,
                                                       &(ccpl_state[intercept->container_type]));
    }

    auto usepCreateInfos =
        (!ccpl_state[LayerObjectTypeGpuAssisted].pCreateInfos) ? pCreateInfos : ccpl_state[LayerObjectTypeGpuAssisted].pCreateInfos;
    if (ccpl_state[LayerObjectTypeDebugPrintf].pCreateInfos) usepCreateInfos = ccpl_state[LayerObjectTypeDebugPrintf].pCreateInfos;

    VkResult result =
        DispatchCreateComputePipelines(device, pipelineCache, createInfoCount, usepCreateInfos, pAllocator, pPipelines);

    RecordObject record_obj(vvl::Func::vkCreateComputePipelines, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                                        pPipelines, record_obj, &(ccpl_state[intercept->container_type]));
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                                           const VkRayTracingPipelineCreateInfoNV* pCreateInfos,
                                                           const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateRayTracingPipelinesNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));

    create_ray_tracing_pipeline_api_state crtpl_state[LayerObjectTypeMaxEnum]{};

    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        crtpl_state[intercept->container_type].pCreateInfos = pCreateInfos;
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateCreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                                                  pPipelines, error_obj, &(crtpl_state[intercept->container_type]));
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                                            pPipelines, &(crtpl_state[intercept->container_type]));
    }

    VkResult result =
        DispatchCreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    RecordObject record_obj(vvl::Func::vkCreateRayTracingPipelinesNV, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                                             pPipelines, record_obj, &(crtpl_state[intercept->container_type]));
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesKHR(VkDevice device, VkDeferredOperationKHR deferredOperation,
                                                            VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                                            const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
                                                            const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateRayTracingPipelinesKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));

    create_ray_tracing_pipeline_khr_api_state crtpl_state[LayerObjectTypeMaxEnum]{};

    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        crtpl_state[intercept->container_type].pCreateInfos = pCreateInfos;
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount,
                                                                       pCreateInfos, pAllocator, pPipelines, error_obj,
                                                                       &(crtpl_state[intercept->container_type]));
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount,
                                                             pCreateInfos, pAllocator, pPipelines,
                                                             &(crtpl_state[intercept->container_type]));
    }

    auto usepCreateInfos = (!crtpl_state[LayerObjectTypeGpuAssisted].pCreateInfos)
                               ? pCreateInfos
                               : crtpl_state[LayerObjectTypeGpuAssisted].pCreateInfos;
    if (crtpl_state[LayerObjectTypeDebugPrintf].pCreateInfos)
        usepCreateInfos = crtpl_state[LayerObjectTypeDebugPrintf].pCreateInfos;

    VkResult result = DispatchCreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount,
                                                           usepCreateInfos, pAllocator, pPipelines);

    RecordObject record_obj(vvl::Func::vkCreateRayTracingPipelinesKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount,
                                                              pCreateInfos, pAllocator, pPipelines, record_obj,
                                                              &(crtpl_state[intercept->container_type]));
    }
    return result;
}

// This API needs the ability to modify a down-chain parameter
VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreatePipelineLayout, VulkanTypedHandle(device, kVulkanObjectTypeDevice));

    create_pipeline_layout_api_state cpl_state{};
    cpl_state.modified_create_info = *pCreateInfo;

    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout, &cpl_state);
    }
    VkResult result = DispatchCreatePipelineLayout(device, &cpl_state.modified_create_info, pAllocator, pPipelineLayout);
    RecordObject record_obj(vvl::Func::vkCreatePipelineLayout, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout, record_obj);
    }
    return result;
}

// This API needs some local stack data for performance reasons and also may modify a parameter
VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateShaderModule, VulkanTypedHandle(device, kVulkanObjectTypeDevice));

    create_shader_module_api_state csm_state{};
    csm_state.instrumented_create_info = *pCreateInfo;

    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule, &csm_state);
    }

    // Special extra check if SPIR-V itself fails runtime validation in PreCallRecord
    if (!csm_state.valid_spirv) return VK_ERROR_VALIDATION_FAILED_EXT;

    VkResult result = DispatchCreateShaderModule(device, &csm_state.instrumented_create_info, pAllocator, pShaderModule);
    RecordObject record_obj(vvl::Func::vkCreateShaderModule, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule, record_obj, &csm_state);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateShadersEXT(VkDevice device, uint32_t createInfoCount,
                                                const VkShaderCreateInfoEXT* pCreateInfos, const VkAllocationCallbacks* pAllocator,
                                                VkShaderEXT* pShaders) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateShadersEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));

    create_shader_object_api_state csm_state(createInfoCount, pCreateInfos);

    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateShadersEXT(device, createInfoCount, csm_state.instrumented_create_info, pAllocator,
                                                           pShaders, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateShadersEXT(device, createInfoCount, pCreateInfos, pAllocator, pShaders, &csm_state);
    }

    // Special extra check if SPIR-V itself fails runtime validation in PreCallRecord
    if (!csm_state.valid_spirv) return VK_ERROR_VALIDATION_FAILED_EXT;

    VkResult result = DispatchCreateShadersEXT(device, createInfoCount, pCreateInfos, pAllocator, pShaders);
    RecordObject record_obj(vvl::Func::vkCreateShadersEXT, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateShadersEXT(device, createInfoCount, pCreateInfos, pAllocator, pShaders, record_obj,
                                                  &csm_state);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                                      VkDescriptorSet* pDescriptorSets) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkAllocateDescriptorSets, VulkanTypedHandle(device, kVulkanObjectTypeDevice));

    cvdescriptorset::AllocateDescriptorSetsData ads_state[LayerObjectTypeMaxEnum];

    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        ads_state[intercept->container_type].Init(pAllocateInfo->descriptorSetCount);
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets, error_obj,
                                                                 &(ads_state[intercept->container_type]));
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
    }
    VkResult result = DispatchAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
    RecordObject record_obj(vvl::Func::vkAllocateDescriptorSets, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets, record_obj,
                                                        &(ads_state[intercept->container_type]));
    }
    return result;
}

// This API needs the ability to modify a down-chain parameter
VKAPI_ATTR VkResult VKAPI_CALL CreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo,
                                            const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateBuffer, VulkanTypedHandle(device, kVulkanObjectTypeDevice));

    create_buffer_api_state cb_state{};
    cb_state.modified_create_info = *pCreateInfo;

    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateBuffer(device, pCreateInfo, pAllocator, pBuffer, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateBuffer(device, pCreateInfo, pAllocator, pBuffer, &cb_state);
    }
    VkResult result = DispatchCreateBuffer(device, &cb_state.modified_create_info, pAllocator, pBuffer);
    RecordObject record_obj(vvl::Func::vkCreateBuffer, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateBuffer(device, pCreateInfo, pAllocator, pBuffer, record_obj);
    }
    return result;
}

// Handle tooling queries manually as this is a request for layer information

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t* pToolCount,
                                                                  VkPhysicalDeviceToolPropertiesEXT* pToolProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceToolPropertiesEXT,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));

    static const VkPhysicalDeviceToolPropertiesEXT khronos_layer_tool_props = {
        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT,
        nullptr,
        "Khronos Validation Layer",
        STRINGIFY(VK_HEADER_VERSION),
        VK_TOOL_PURPOSE_VALIDATION_BIT_EXT | VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT_EXT | VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT |
            VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT,
        "Khronos Validation Layer",
        OBJECT_LAYER_NAME};

    auto original_pToolProperties = pToolProperties;

    if (pToolProperties != nullptr) {
        *pToolProperties = khronos_layer_tool_props;
        pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
        (*pToolCount)--;
    }

    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateGetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }

    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);
    }

    VkResult result = DispatchGetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);

    if (original_pToolProperties != nullptr) {
        pToolProperties = original_pToolProperties;
    }
    (*pToolCount)++;

    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceToolPropertiesEXT, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties, record_obj);
    }
    return result;
}

// ValidationCache APIs do not dispatch

VKAPI_ATTR VkResult VKAPI_CALL CreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator,
                                                        VkValidationCacheEXT* pValidationCache) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    if (auto core_checks = layer_data->GetValidationObject<CoreChecks>()) {
        auto lock = core_checks->WriteLock();
        return core_checks->CoreLayerCreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
    }
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache,
                                                     const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    if (auto core_checks = layer_data->GetValidationObject<CoreChecks>()) {
        auto lock = core_checks->WriteLock();
        core_checks->CoreLayerDestroyValidationCacheEXT(device, validationCache, pAllocator);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL MergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount,
                                                        const VkValidationCacheEXT* pSrcCaches) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    if (auto core_checks = layer_data->GetValidationObject<CoreChecks>()) {
        auto lock = core_checks->WriteLock();
        return core_checks->CoreLayerMergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
    }
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL GetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize,
                                                         void* pData) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    if (auto core_checks = layer_data->GetValidationObject<CoreChecks>()) {
        auto lock = core_checks->WriteLock();
        return core_checks->CoreLayerGetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
    }
    return VK_SUCCESS;
}
VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount,
                                                        VkPhysicalDevice* pPhysicalDevices) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkEnumeratePhysicalDevices, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
    }
    VkResult result = DispatchEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
    RecordObject record_obj(vvl::Func::vkEnumeratePhysicalDevices, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceFeatures,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceFeatures(physicalDevice, pFeatures, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    }
    DispatchGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceFeatures);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceFeatures(physicalDevice, pFeatures, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                             VkFormatProperties* pFormatProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceFormatProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    }
    DispatchGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceFormatProperties);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                      VkImageType type, VkImageTiling tiling,
                                                                      VkImageUsageFlags usage, VkImageCreateFlags flags,
                                                                      VkImageFormatProperties* pImageFormatProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceImageFormatProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags,
                                                                                 pImageFormatProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags,
                                                                       pImageFormatProperties);
    }
    VkResult result =
        DispatchGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceImageFormatProperties, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags,
                                                                        pImageFormatProperties, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceProperties(physicalDevice, pProperties, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceProperties(physicalDevice, pProperties);
    }
    DispatchGetPhysicalDeviceProperties(physicalDevice, pProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceProperties);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceProperties(physicalDevice, pProperties, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice,
                                                                  uint32_t* pQueueFamilyPropertyCount,
                                                                  VkQueueFamilyProperties* pQueueFamilyProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceQueueFamilyProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount,
                                                                                 pQueueFamilyProperties, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount,
                                                                       pQueueFamilyProperties);
    }
    DispatchGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceQueueFamilyProperties);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount,
                                                                        pQueueFamilyProperties, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice,
                                                             VkPhysicalDeviceMemoryProperties* pMemoryProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceMemoryProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    }
    DispatchGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceMemoryProperties);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceQueue, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetDeviceQueue]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetDeviceQueue]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    }
    DispatchGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    RecordObject record_obj(vvl::Func::vkGetDeviceQueue);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetDeviceQueue]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(queue), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueSubmit, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateQueueSubmit]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateQueueSubmit(queue, submitCount, pSubmits, fence, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordQueueSubmit]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordQueueSubmit(queue, submitCount, pSubmits, fence);
    }
    VkResult result = DispatchQueueSubmit(queue, submitCount, pSubmits, fence);
    RecordObject record_obj(vvl::Func::vkQueueSubmit, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordQueueSubmit]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordQueueSubmit(queue, submitCount, pSubmits, fence, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle(VkQueue queue) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(queue), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueWaitIdle, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateQueueWaitIdle]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateQueueWaitIdle(queue, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordQueueWaitIdle]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordQueueWaitIdle(queue);
    }
    VkResult result = DispatchQueueWaitIdle(queue);
    RecordObject record_obj(vvl::Func::vkQueueWaitIdle, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordQueueWaitIdle]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordQueueWaitIdle(queue, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle(VkDevice device) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDeviceWaitIdle, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDeviceWaitIdle]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDeviceWaitIdle(device, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDeviceWaitIdle]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDeviceWaitIdle(device);
    }
    VkResult result = DispatchDeviceWaitIdle(device);
    RecordObject record_obj(vvl::Func::vkDeviceWaitIdle, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDeviceWaitIdle]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDeviceWaitIdle(device, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                              const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkAllocateMemory, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateAllocateMemory]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateAllocateMemory(device, pAllocateInfo, pAllocator, pMemory, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordAllocateMemory]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    }
    VkResult result = DispatchAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    RecordObject record_obj(vvl::Func::vkAllocateMemory, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordAllocateMemory]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordAllocateMemory(device, pAllocateInfo, pAllocator, pMemory, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL MapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size,
                                         VkMemoryMapFlags flags, void** ppData) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkMapMemory, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateMapMemory]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateMapMemory(device, memory, offset, size, flags, ppData, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordMapMemory]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordMapMemory(device, memory, offset, size, flags, ppData);
    }
    VkResult result = DispatchMapMemory(device, memory, offset, size, flags, ppData);
    RecordObject record_obj(vvl::Func::vkMapMemory, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordMapMemory]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordMapMemory(device, memory, offset, size, flags, ppData, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL UnmapMemory(VkDevice device, VkDeviceMemory memory) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkUnmapMemory, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateUnmapMemory]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateUnmapMemory(device, memory, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordUnmapMemory]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordUnmapMemory(device, memory);
    }
    DispatchUnmapMemory(device, memory);
    RecordObject record_obj(vvl::Func::vkUnmapMemory);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordUnmapMemory]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordUnmapMemory(device, memory, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                       const VkMappedMemoryRange* pMemoryRanges) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkFlushMappedMemoryRanges, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateFlushMappedMemoryRanges]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordFlushMappedMemoryRanges]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    }
    VkResult result = DispatchFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    RecordObject record_obj(vvl::Func::vkFlushMappedMemoryRanges, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordFlushMappedMemoryRanges]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                            const VkMappedMemoryRange* pMemoryRanges) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkInvalidateMappedMemoryRanges, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateInvalidateMappedMemoryRanges]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordInvalidateMappedMemoryRanges]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    }
    VkResult result = DispatchInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    RecordObject record_obj(vvl::Func::vkInvalidateMappedMemoryRanges, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordInvalidateMappedMemoryRanges]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory,
                                                     VkDeviceSize* pCommittedMemoryInBytes) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceMemoryCommitment, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetDeviceMemoryCommitment]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetDeviceMemoryCommitment]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    }
    DispatchGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    RecordObject record_obj(vvl::Func::vkGetDeviceMemoryCommitment);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetDeviceMemoryCommitment]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory,
                                                VkDeviceSize memoryOffset) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkBindBufferMemory, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateBindBufferMemory]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateBindBufferMemory(device, buffer, memory, memoryOffset, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordBindBufferMemory]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordBindBufferMemory(device, buffer, memory, memoryOffset);
    }
    VkResult result = DispatchBindBufferMemory(device, buffer, memory, memoryOffset);
    RecordObject record_obj(vvl::Func::vkBindBufferMemory, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordBindBufferMemory]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordBindBufferMemory(device, buffer, memory, memoryOffset, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkBindImageMemory, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateBindImageMemory]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateBindImageMemory(device, image, memory, memoryOffset, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordBindImageMemory]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordBindImageMemory(device, image, memory, memoryOffset);
    }
    VkResult result = DispatchBindImageMemory(device, image, memory, memoryOffset);
    RecordObject record_obj(vvl::Func::vkBindImageMemory, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordBindImageMemory]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordBindImageMemory(device, image, memory, memoryOffset, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements(VkDevice device, VkBuffer buffer,
                                                       VkMemoryRequirements* pMemoryRequirements) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetBufferMemoryRequirements, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetBufferMemoryRequirements]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetBufferMemoryRequirements(device, buffer, pMemoryRequirements, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetBufferMemoryRequirements]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    }
    DispatchGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    RecordObject record_obj(vvl::Func::vkGetBufferMemoryRequirements);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetBufferMemoryRequirements]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetBufferMemoryRequirements(device, buffer, pMemoryRequirements, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetImageMemoryRequirements, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetImageMemoryRequirements]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetImageMemoryRequirements(device, image, pMemoryRequirements, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetImageMemoryRequirements]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetImageMemoryRequirements(device, image, pMemoryRequirements);
    }
    DispatchGetImageMemoryRequirements(device, image, pMemoryRequirements);
    RecordObject record_obj(vvl::Func::vkGetImageMemoryRequirements);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetImageMemoryRequirements]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetImageMemoryRequirements(device, image, pMemoryRequirements, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateFence, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateFence]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateFence(device, pCreateInfo, pAllocator, pFence, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateFence]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateFence(device, pCreateInfo, pAllocator, pFence);
    }
    VkResult result = DispatchCreateFence(device, pCreateInfo, pAllocator, pFence);
    RecordObject record_obj(vvl::Func::vkCreateFence, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateFence]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateFence(device, pCreateInfo, pAllocator, pFence, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyFence, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyFence]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyFence(device, fence, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyFence]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyFence(device, fence, pAllocator);
    }
    DispatchDestroyFence(device, fence, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyFence);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyFence]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyFence(device, fence, pAllocator, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL ResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkResetFences, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateResetFences]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateResetFences(device, fenceCount, pFences, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordResetFences]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordResetFences(device, fenceCount, pFences);
    }
    VkResult result = DispatchResetFences(device, fenceCount, pFences);
    RecordObject record_obj(vvl::Func::vkResetFences, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordResetFences]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordResetFences(device, fenceCount, pFences, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(VkDevice device, VkFence fence) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetFenceStatus, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetFenceStatus]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetFenceStatus(device, fence, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetFenceStatus]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetFenceStatus(device, fence);
    }
    VkResult result = DispatchGetFenceStatus(device, fence);
    RecordObject record_obj(vvl::Func::vkGetFenceStatus, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetFenceStatus]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetFenceStatus(device, fence, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll,
                                             uint64_t timeout) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkWaitForFences, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateWaitForFences]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateWaitForFences(device, fenceCount, pFences, waitAll, timeout, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordWaitForFences]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordWaitForFences(device, fenceCount, pFences, waitAll, timeout);
    }
    VkResult result = DispatchWaitForFences(device, fenceCount, pFences, waitAll, timeout);
    RecordObject record_obj(vvl::Func::vkWaitForFences, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordWaitForFences]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordWaitForFences(device, fenceCount, pFences, waitAll, timeout, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateSemaphore, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateSemaphore]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateSemaphore]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    }
    VkResult result = DispatchCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    RecordObject record_obj(vvl::Func::vkCreateSemaphore, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateSemaphore]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroySemaphore, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroySemaphore]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroySemaphore(device, semaphore, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroySemaphore]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroySemaphore(device, semaphore, pAllocator);
    }
    DispatchDestroySemaphore(device, semaphore, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroySemaphore);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroySemaphore]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroySemaphore(device, semaphore, pAllocator, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateEvent, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateEvent]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateEvent(device, pCreateInfo, pAllocator, pEvent, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateEvent]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateEvent(device, pCreateInfo, pAllocator, pEvent);
    }
    VkResult result = DispatchCreateEvent(device, pCreateInfo, pAllocator, pEvent);
    RecordObject record_obj(vvl::Func::vkCreateEvent, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateEvent]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateEvent(device, pCreateInfo, pAllocator, pEvent, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyEvent, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyEvent]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyEvent(device, event, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyEvent]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyEvent(device, event, pAllocator);
    }
    DispatchDestroyEvent(device, event, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyEvent);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyEvent]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyEvent(device, event, pAllocator, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(VkDevice device, VkEvent event) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetEventStatus, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetEventStatus]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetEventStatus(device, event, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetEventStatus]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetEventStatus(device, event);
    }
    VkResult result = DispatchGetEventStatus(device, event);
    RecordObject record_obj(vvl::Func::vkGetEventStatus, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetEventStatus]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetEventStatus(device, event, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetEvent(VkDevice device, VkEvent event) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSetEvent, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateSetEvent]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateSetEvent(device, event, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordSetEvent]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordSetEvent(device, event);
    }
    VkResult result = DispatchSetEvent(device, event);
    RecordObject record_obj(vvl::Func::vkSetEvent, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordSetEvent]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordSetEvent(device, event, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetEvent(VkDevice device, VkEvent event) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkResetEvent, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateResetEvent]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateResetEvent(device, event, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordResetEvent]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordResetEvent(device, event);
    }
    VkResult result = DispatchResetEvent(device, event);
    RecordObject record_obj(vvl::Func::vkResetEvent, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordResetEvent]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordResetEvent(device, event, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateQueryPool, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateQueryPool]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateQueryPool]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    }
    VkResult result = DispatchCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    RecordObject record_obj(vvl::Func::vkCreateQueryPool, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateQueryPool]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount,
                                                   size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetQueryPoolResults, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetQueryPoolResults]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride,
                                                              flags, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetQueryPoolResults]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    }
    VkResult result = DispatchGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    RecordObject record_obj(vvl::Func::vkGetQueryPoolResults, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetQueryPoolResults]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags,
                                                     record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyBuffer, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyBuffer]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyBuffer(device, buffer, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyBuffer(device, buffer, pAllocator);
    }
    DispatchDestroyBuffer(device, buffer, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyBuffer);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyBuffer(device, buffer, pAllocator, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkBufferView* pView) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateBufferView, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateBufferView]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateBufferView(device, pCreateInfo, pAllocator, pView, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateBufferView]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateBufferView(device, pCreateInfo, pAllocator, pView);
    }
    VkResult result = DispatchCreateBufferView(device, pCreateInfo, pAllocator, pView);
    RecordObject record_obj(vvl::Func::vkCreateBufferView, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateBufferView]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateBufferView(device, pCreateInfo, pAllocator, pView, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyBufferView, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyBufferView]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyBufferView(device, bufferView, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyBufferView]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyBufferView(device, bufferView, pAllocator);
    }
    DispatchDestroyBufferView(device, bufferView, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyBufferView);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyBufferView]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyBufferView(device, bufferView, pAllocator, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo,
                                           const VkAllocationCallbacks* pAllocator, VkImage* pImage) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateImage, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateImage]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateImage(device, pCreateInfo, pAllocator, pImage, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateImage]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateImage(device, pCreateInfo, pAllocator, pImage);
    }
    VkResult result = DispatchCreateImage(device, pCreateInfo, pAllocator, pImage);
    RecordObject record_obj(vvl::Func::vkCreateImage, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateImage]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateImage(device, pCreateInfo, pAllocator, pImage, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyImage, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyImage]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyImage(device, image, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyImage]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyImage(device, image, pAllocator);
    }
    DispatchDestroyImage(device, image, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyImage);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyImage]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyImage(device, image, pAllocator, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource,
                                                     VkSubresourceLayout* pLayout) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetImageSubresourceLayout, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetImageSubresourceLayout]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetImageSubresourceLayout(device, image, pSubresource, pLayout, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetImageSubresourceLayout]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetImageSubresourceLayout(device, image, pSubresource, pLayout);
    }
    DispatchGetImageSubresourceLayout(device, image, pSubresource, pLayout);
    RecordObject record_obj(vvl::Func::vkGetImageSubresourceLayout);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetImageSubresourceLayout]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetImageSubresourceLayout(device, image, pSubresource, pLayout, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator, VkImageView* pView) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateImageView, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateImageView]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateImageView(device, pCreateInfo, pAllocator, pView, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateImageView]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateImageView(device, pCreateInfo, pAllocator, pView);
    }
    VkResult result = DispatchCreateImageView(device, pCreateInfo, pAllocator, pView);
    RecordObject record_obj(vvl::Func::vkCreateImageView, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateImageView]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateImageView(device, pCreateInfo, pAllocator, pView, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyImageView, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyImageView]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyImageView(device, imageView, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyImageView]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyImageView(device, imageView, pAllocator);
    }
    DispatchDestroyImageView(device, imageView, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyImageView);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyImageView]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyImageView(device, imageView, pAllocator, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreatePipelineCache, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreatePipelineCache]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreatePipelineCache]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
    }
    VkResult result = DispatchCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
    RecordObject record_obj(vvl::Func::vkCreatePipelineCache, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreatePipelineCache]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache,
                                                const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyPipelineCache, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyPipelineCache]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyPipelineCache(device, pipelineCache, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyPipelineCache]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyPipelineCache(device, pipelineCache, pAllocator);
    }
    DispatchDestroyPipelineCache(device, pipelineCache, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyPipelineCache);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyPipelineCache]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyPipelineCache(device, pipelineCache, pAllocator, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL DestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyPipeline, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyPipeline]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyPipeline(device, pipeline, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyPipeline]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyPipeline(device, pipeline, pAllocator);
    }
    DispatchDestroyPipeline(device, pipeline, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyPipeline);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyPipeline]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyPipeline(device, pipeline, pAllocator, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout,
                                                 const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyPipelineLayout, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyPipelineLayout]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyPipelineLayout(device, pipelineLayout, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyPipelineLayout]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyPipelineLayout(device, pipelineLayout, pAllocator);
    }
    DispatchDestroyPipelineLayout(device, pipelineLayout, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyPipelineLayout);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyPipelineLayout]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyPipelineLayout(device, pipelineLayout, pAllocator, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo,
                                             const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateSampler, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateSampler]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateSampler(device, pCreateInfo, pAllocator, pSampler, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateSampler]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateSampler(device, pCreateInfo, pAllocator, pSampler);
    }
    VkResult result = DispatchCreateSampler(device, pCreateInfo, pAllocator, pSampler);
    RecordObject record_obj(vvl::Func::vkCreateSampler, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateSampler]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateSampler(device, pCreateInfo, pAllocator, pSampler, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroySampler, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroySampler]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroySampler(device, sampler, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroySampler]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroySampler(device, sampler, pAllocator);
    }
    DispatchDestroySampler(device, sampler, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroySampler);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroySampler]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroySampler(device, sampler, pAllocator, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator,
                                                         VkDescriptorSetLayout* pSetLayout) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateDescriptorSetLayout, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateDescriptorSetLayout]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateDescriptorSetLayout]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    }
    VkResult result = DispatchCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    RecordObject record_obj(vvl::Func::vkCreateDescriptorSetLayout, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateDescriptorSetLayout]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout,
                                                      const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyDescriptorSetLayout, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyDescriptorSetLayout]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyDescriptorSetLayout]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    }
    DispatchDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyDescriptorSetLayout);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyDescriptorSetLayout]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateDescriptorPool, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateDescriptorPool]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateDescriptorPool]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    }
    VkResult result = DispatchCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    RecordObject record_obj(vvl::Func::vkCreateDescriptorPool, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateDescriptorPool]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool,
                                                   VkDescriptorPoolResetFlags flags) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkResetDescriptorPool, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateResetDescriptorPool]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateResetDescriptorPool(device, descriptorPool, flags, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordResetDescriptorPool]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordResetDescriptorPool(device, descriptorPool, flags);
    }
    VkResult result = DispatchResetDescriptorPool(device, descriptorPool, flags);
    RecordObject record_obj(vvl::Func::vkResetDescriptorPool, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordResetDescriptorPool]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordResetDescriptorPool(device, descriptorPool, flags, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount,
                                                  const VkDescriptorSet* pDescriptorSets) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkFreeDescriptorSets, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateFreeDescriptorSets]) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordFreeDescriptorSets]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    }
    VkResult result = DispatchFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    RecordObject record_obj(vvl::Func::vkFreeDescriptorSets, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordFreeDescriptorSets]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount,
                                                const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount,
                                                const VkCopyDescriptorSet* pDescriptorCopies) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkUpdateDescriptorSets, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateUpdateDescriptorSets]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount,
                                                               pDescriptorCopies, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordUpdateDescriptorSets]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount,
                                                     pDescriptorCopies);
    }
    DispatchUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    RecordObject record_obj(vvl::Func::vkUpdateDescriptorSets);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordUpdateDescriptorSets]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount,
                                                      pDescriptorCopies, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateFramebuffer, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateFramebuffer]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateFramebuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    }
    VkResult result = DispatchCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    RecordObject record_obj(vvl::Func::vkCreateFramebuffer, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateFramebuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyFramebuffer, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyFramebuffer]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyFramebuffer(device, framebuffer, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyFramebuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyFramebuffer(device, framebuffer, pAllocator);
    }
    DispatchDestroyFramebuffer(device, framebuffer, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyFramebuffer);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyFramebuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyFramebuffer(device, framebuffer, pAllocator, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateRenderPass, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateRenderPass]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateRenderPass]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    }
    VkResult result = DispatchCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    RecordObject record_obj(vvl::Func::vkCreateRenderPass, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateRenderPass]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyRenderPass, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyRenderPass]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyRenderPass(device, renderPass, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyRenderPass]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyRenderPass(device, renderPass, pAllocator);
    }
    DispatchDestroyRenderPass(device, renderPass, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyRenderPass);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyRenderPass]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyRenderPass(device, renderPass, pAllocator, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetRenderAreaGranularity, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetRenderAreaGranularity]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetRenderAreaGranularity(device, renderPass, pGranularity, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetRenderAreaGranularity]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetRenderAreaGranularity(device, renderPass, pGranularity);
    }
    DispatchGetRenderAreaGranularity(device, renderPass, pGranularity);
    RecordObject record_obj(vvl::Func::vkGetRenderAreaGranularity);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetRenderAreaGranularity]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetRenderAreaGranularity(device, renderPass, pGranularity, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateCommandPool, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateCommandPool]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateCommandPool]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    }
    VkResult result = DispatchCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    RecordObject record_obj(vvl::Func::vkCreateCommandPool, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateCommandPool]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkResetCommandPool, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateResetCommandPool]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateResetCommandPool(device, commandPool, flags, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordResetCommandPool]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordResetCommandPool(device, commandPool, flags);
    }
    VkResult result = DispatchResetCommandPool(device, commandPool, flags);
    RecordObject record_obj(vvl::Func::vkResetCommandPool, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordResetCommandPool]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordResetCommandPool(device, commandPool, flags, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                                      VkCommandBuffer* pCommandBuffers) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkAllocateCommandBuffers, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateAllocateCommandBuffers]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordAllocateCommandBuffers]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
    }
    VkResult result = DispatchAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
    RecordObject record_obj(vvl::Func::vkAllocateCommandBuffers, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordAllocateCommandBuffers]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                              const VkCommandBuffer* pCommandBuffers) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkFreeCommandBuffers, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateFreeCommandBuffers]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordFreeCommandBuffers]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    }
    DispatchFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    RecordObject record_obj(vvl::Func::vkFreeCommandBuffers);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordFreeCommandBuffers]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkBeginCommandBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateBeginCommandBuffer]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateBeginCommandBuffer(commandBuffer, pBeginInfo, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordBeginCommandBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordBeginCommandBuffer(commandBuffer, pBeginInfo);
    }
    VkResult result = DispatchBeginCommandBuffer(commandBuffer, pBeginInfo);
    RecordObject record_obj(vvl::Func::vkBeginCommandBuffer, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordBeginCommandBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordBeginCommandBuffer(commandBuffer, pBeginInfo, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer(VkCommandBuffer commandBuffer) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkEndCommandBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateEndCommandBuffer]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateEndCommandBuffer(commandBuffer, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordEndCommandBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordEndCommandBuffer(commandBuffer);
    }
    VkResult result = DispatchEndCommandBuffer(commandBuffer);
    RecordObject record_obj(vvl::Func::vkEndCommandBuffer, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordEndCommandBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordEndCommandBuffer(commandBuffer, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkResetCommandBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateResetCommandBuffer]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateResetCommandBuffer(commandBuffer, flags, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordResetCommandBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordResetCommandBuffer(commandBuffer, flags);
    }
    VkResult result = DispatchResetCommandBuffer(commandBuffer, flags);
    RecordObject record_obj(vvl::Func::vkResetCommandBuffer, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordResetCommandBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordResetCommandBuffer(commandBuffer, flags, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                           VkPipeline pipeline) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindPipeline, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBindPipeline]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBindPipeline]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    }
    DispatchCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    RecordObject record_obj(vvl::Func::vkCmdBindPipeline);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBindPipeline]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                          const VkViewport* pViewports) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetViewport, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetViewport]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetViewport]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    }
    DispatchCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    RecordObject record_obj(vvl::Func::vkCmdSetViewport);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetViewport]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                         const VkRect2D* pScissors) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetScissor, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetScissor]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetScissor]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    }
    DispatchCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    RecordObject record_obj(vvl::Func::vkCmdSetScissor);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetScissor]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetLineWidth, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetLineWidth]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetLineWidth(commandBuffer, lineWidth, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetLineWidth]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetLineWidth(commandBuffer, lineWidth);
    }
    DispatchCmdSetLineWidth(commandBuffer, lineWidth);
    RecordObject record_obj(vvl::Func::vkCmdSetLineWidth);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetLineWidth]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetLineWidth(commandBuffer, lineWidth, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                                           float depthBiasSlopeFactor) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthBias, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthBias]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp,
                                                          depthBiasSlopeFactor, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthBias]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    }
    DispatchCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    RecordObject record_obj(vvl::Func::vkCmdSetDepthBias);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthBias]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor,
                                                 record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetBlendConstants, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetBlendConstants]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetBlendConstants(commandBuffer, blendConstants, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetBlendConstants]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetBlendConstants(commandBuffer, blendConstants);
    }
    DispatchCmdSetBlendConstants(commandBuffer, blendConstants);
    RecordObject record_obj(vvl::Func::vkCmdSetBlendConstants);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetBlendConstants]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetBlendConstants(commandBuffer, blendConstants, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthBounds, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthBounds]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthBounds]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    }
    DispatchCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    RecordObject record_obj(vvl::Func::vkCmdSetDepthBounds);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthBounds]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                    uint32_t compareMask) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilCompareMask, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilCompareMask]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilCompareMask]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    }
    DispatchCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    RecordObject record_obj(vvl::Func::vkCmdSetStencilCompareMask);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilCompareMask]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilWriteMask, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilWriteMask]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilWriteMask]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    }
    DispatchCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    RecordObject record_obj(vvl::Func::vkCmdSetStencilWriteMask);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilWriteMask]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilReference, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilReference]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetStencilReference(commandBuffer, faceMask, reference, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilReference]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetStencilReference(commandBuffer, faceMask, reference);
    }
    DispatchCmdSetStencilReference(commandBuffer, faceMask, reference);
    RecordObject record_obj(vvl::Func::vkCmdSetStencilReference);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilReference]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetStencilReference(commandBuffer, faceMask, reference, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                 VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                                 const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                                 const uint32_t* pDynamicOffsets) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindDescriptorSets, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBindDescriptorSets]) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                                            pDescriptorSets, dynamicOffsetCount, pDynamicOffsets, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBindDescriptorSets]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                                      pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    }
    DispatchCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets,
                                  dynamicOffsetCount, pDynamicOffsets);
    RecordObject record_obj(vvl::Func::vkCmdBindDescriptorSets);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBindDescriptorSets]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                                       pDescriptorSets, dynamicOffsetCount, pDynamicOffsets, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                              VkIndexType indexType) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindIndexBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBindIndexBuffer]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBindIndexBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    }
    DispatchCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    RecordObject record_obj(vvl::Func::vkCmdBindIndexBuffer);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBindIndexBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                                const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindVertexBuffers, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBindVertexBuffers]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets,
                                                               error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBindVertexBuffers]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    }
    DispatchCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    RecordObject record_obj(vvl::Func::vkCmdBindVertexBuffers);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBindVertexBuffers]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                                   uint32_t firstVertex, uint32_t firstInstance) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDraw, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdDraw]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdDraw]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }
    DispatchCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    RecordObject record_obj(vvl::Func::vkCmdDraw);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdDraw]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                          uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDrawIndexed, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdDrawIndexed]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset,
                                                         firstInstance, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdDrawIndexed]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }
    DispatchCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    RecordObject record_obj(vvl::Func::vkCmdDrawIndexed);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdDrawIndexed]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance,
                                                record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                                           uint32_t stride) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDrawIndirect, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdDrawIndirect]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdDrawIndirect]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }
    DispatchCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    RecordObject record_obj(vvl::Func::vkCmdDrawIndirect);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdDrawIndirect]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                  uint32_t drawCount, uint32_t stride) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDrawIndexedIndirect, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdDrawIndexedIndirect]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdDrawIndexedIndirect]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }
    DispatchCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    RecordObject record_obj(vvl::Func::vkCmdDrawIndexedIndirect);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdDrawIndexedIndirect]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                       uint32_t groupCountZ) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDispatch, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdDispatch]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdDispatch]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }
    DispatchCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    RecordObject record_obj(vvl::Func::vkCmdDispatch);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdDispatch]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDispatchIndirect, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdDispatchIndirect]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdDispatchIndirect(commandBuffer, buffer, offset, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdDispatchIndirect]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdDispatchIndirect(commandBuffer, buffer, offset);
    }
    DispatchCmdDispatchIndirect(commandBuffer, buffer, offset);
    RecordObject record_obj(vvl::Func::vkCmdDispatchIndirect);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdDispatchIndirect]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdDispatchIndirect(commandBuffer, buffer, offset, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                         uint32_t regionCount, const VkBufferCopy* pRegions) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyBuffer]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    }
    DispatchCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    RecordObject record_obj(vvl::Func::vkCmdCopyBuffer);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                        VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                        const VkImageCopy* pRegions) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyImage, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyImage]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                                       regionCount, pRegions, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyImage]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                             pRegions);
    }
    DispatchCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    RecordObject record_obj(vvl::Func::vkCmdCopyImage);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyImage]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                              pRegions, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                        VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                        const VkImageBlit* pRegions, VkFilter filter) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBlitImage, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBlitImage]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                                       regionCount, pRegions, filter, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBlitImage]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                             pRegions, filter);
    }
    DispatchCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    RecordObject record_obj(vvl::Func::vkCmdBlitImage);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBlitImage]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                              pRegions, filter, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                                VkImageLayout dstImageLayout, uint32_t regionCount,
                                                const VkBufferImageCopy* pRegions) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyBufferToImage, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyBufferToImage]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount,
                                                               pRegions, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyBufferToImage]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    }
    DispatchCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    RecordObject record_obj(vvl::Func::vkCmdCopyBufferToImage);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyBufferToImage]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions,
                                                      record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                                VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyImageToBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyImageToBuffer]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount,
                                                               pRegions, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyImageToBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    }
    DispatchCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    RecordObject record_obj(vvl::Func::vkCmdCopyImageToBuffer);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyImageToBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions,
                                                      record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                           VkDeviceSize dataSize, const void* pData) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdUpdateBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdUpdateBuffer]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdUpdateBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    }
    DispatchCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    RecordObject record_obj(vvl::Func::vkCmdUpdateBuffer);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdUpdateBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                         VkDeviceSize size, uint32_t data) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdFillBuffer, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdFillBuffer]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdFillBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    }
    DispatchCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    RecordObject record_obj(vvl::Func::vkCmdFillBuffer);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdFillBuffer]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                              const VkClearColorValue* pColor, uint32_t rangeCount,
                                              const VkImageSubresourceRange* pRanges) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdClearColorImage, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdClearColorImage]) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdClearColorImage]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    }
    DispatchCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    RecordObject record_obj(vvl::Func::vkCmdClearColorImage);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdClearColorImage]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                                     const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                                     const VkImageSubresourceRange* pRanges) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdClearDepthStencilImage, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdClearDepthStencilImage]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount,
                                                                    pRanges, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdClearDepthStencilImage]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    }
    DispatchCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    RecordObject record_obj(vvl::Func::vkCmdClearDepthStencilImage);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdClearDepthStencilImage]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges,
                                                           record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                               const VkClearAttachment* pAttachments, uint32_t rectCount,
                                               const VkClearRect* pRects) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdClearAttachments, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdClearAttachments]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects,
                                                              error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdClearAttachments]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    }
    DispatchCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    RecordObject record_obj(vvl::Func::vkCmdClearAttachments);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdClearAttachments]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                           VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                           const VkImageResolve* pRegions) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResolveImage, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdResolveImage]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                                          regionCount, pRegions, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdResolveImage]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                                pRegions);
    }
    DispatchCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    RecordObject record_obj(vvl::Func::vkCmdResolveImage);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdResolveImage]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                                 pRegions, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetEvent, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetEvent]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetEvent(commandBuffer, event, stageMask, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetEvent]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetEvent(commandBuffer, event, stageMask);
    }
    DispatchCmdSetEvent(commandBuffer, event, stageMask);
    RecordObject record_obj(vvl::Func::vkCmdSetEvent);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetEvent]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetEvent(commandBuffer, event, stageMask, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResetEvent, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdResetEvent]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdResetEvent(commandBuffer, event, stageMask, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdResetEvent]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdResetEvent(commandBuffer, event, stageMask);
    }
    DispatchCmdResetEvent(commandBuffer, event, stageMask);
    RecordObject record_obj(vvl::Func::vkCmdResetEvent);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdResetEvent]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdResetEvent(commandBuffer, event, stageMask, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                         VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                                         uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                         uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                         uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWaitEvents, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdWaitEvents]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdWaitEvents(
            commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers,
            bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdWaitEvents]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount,
                                              pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                              imageMemoryBarrierCount, pImageMemoryBarriers);
    }
    DispatchCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers,
                          bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    RecordObject record_obj(vvl::Func::vkCmdWaitEvents);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdWaitEvents]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount,
                                               pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                               imageMemoryBarrierCount, pImageMemoryBarriers, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                              VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                              uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                              uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                              uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdPipelineBarrier, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdPipelineBarrier]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdPipelineBarrier(
            commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers,
            bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdPipelineBarrier]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount,
                                                   pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                                   imageMemoryBarrierCount, pImageMemoryBarriers);
    }
    DispatchCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers,
                               bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    RecordObject record_obj(vvl::Func::vkCmdPipelineBarrier);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdPipelineBarrier]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount,
                                                    pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                                    imageMemoryBarrierCount, pImageMemoryBarriers, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                         VkQueryControlFlags flags) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBeginQuery, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBeginQuery]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBeginQuery(commandBuffer, queryPool, query, flags, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBeginQuery]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBeginQuery(commandBuffer, queryPool, query, flags);
    }
    DispatchCmdBeginQuery(commandBuffer, queryPool, query, flags);
    RecordObject record_obj(vvl::Func::vkCmdBeginQuery);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBeginQuery]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBeginQuery(commandBuffer, queryPool, query, flags, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdEndQuery, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdEndQuery]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdEndQuery(commandBuffer, queryPool, query, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdEndQuery]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdEndQuery(commandBuffer, queryPool, query);
    }
    DispatchCmdEndQuery(commandBuffer, queryPool, query);
    RecordObject record_obj(vvl::Func::vkCmdEndQuery);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdEndQuery]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdEndQuery(commandBuffer, queryPool, query, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                             uint32_t queryCount) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResetQueryPool, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdResetQueryPool]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdResetQueryPool]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    }
    DispatchCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    RecordObject record_obj(vvl::Func::vkCmdResetQueryPool);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdResetQueryPool]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                             VkQueryPool queryPool, uint32_t query) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWriteTimestamp, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdWriteTimestamp]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdWriteTimestamp]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    }
    DispatchCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    RecordObject record_obj(vvl::Func::vkCmdWriteTimestamp);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdWriteTimestamp]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                                   uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                   VkDeviceSize stride, VkQueryResultFlags flags) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyQueryPoolResults, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyQueryPoolResults]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer,
                                                                  dstOffset, stride, flags, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyQueryPoolResults]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset,
                                                        stride, flags);
    }
    DispatchCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    RecordObject record_obj(vvl::Func::vkCmdCopyQueryPoolResults);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyQueryPoolResults]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset,
                                                         stride, flags, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                                            uint32_t offset, uint32_t size, const void* pValues) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdPushConstants, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdPushConstants]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdPushConstants]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    }
    DispatchCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    RecordObject record_obj(vvl::Func::vkCmdPushConstants);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdPushConstants]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                              VkSubpassContents contents) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBeginRenderPass, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBeginRenderPass]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBeginRenderPass]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    }
    DispatchCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    RecordObject record_obj(vvl::Func::vkCmdBeginRenderPass);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBeginRenderPass]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdNextSubpass, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdNextSubpass]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdNextSubpass(commandBuffer, contents, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdNextSubpass]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdNextSubpass(commandBuffer, contents);
    }
    DispatchCmdNextSubpass(commandBuffer, contents);
    RecordObject record_obj(vvl::Func::vkCmdNextSubpass);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdNextSubpass]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdNextSubpass(commandBuffer, contents, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(VkCommandBuffer commandBuffer) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdEndRenderPass, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdEndRenderPass]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdEndRenderPass(commandBuffer, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdEndRenderPass]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdEndRenderPass(commandBuffer);
    }
    DispatchCmdEndRenderPass(commandBuffer);
    RecordObject record_obj(vvl::Func::vkCmdEndRenderPass);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdEndRenderPass]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdEndRenderPass(commandBuffer, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                              const VkCommandBuffer* pCommandBuffers) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdExecuteCommands, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdExecuteCommands]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdExecuteCommands]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    }
    DispatchCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    RecordObject record_obj(vvl::Func::vkCmdExecuteCommands);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdExecuteCommands]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(VkDevice device, uint32_t bindInfoCount,
                                                 const VkBindBufferMemoryInfo* pBindInfos) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkBindBufferMemory2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateBindBufferMemory2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateBindBufferMemory2(device, bindInfoCount, pBindInfos, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordBindBufferMemory2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordBindBufferMemory2(device, bindInfoCount, pBindInfos);
    }
    VkResult result = DispatchBindBufferMemory2(device, bindInfoCount, pBindInfos);
    RecordObject record_obj(vvl::Func::vkBindBufferMemory2, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordBindBufferMemory2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordBindBufferMemory2(device, bindInfoCount, pBindInfos, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkBindImageMemory2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateBindImageMemory2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateBindImageMemory2(device, bindInfoCount, pBindInfos, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordBindImageMemory2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordBindImageMemory2(device, bindInfoCount, pBindInfos);
    }
    VkResult result = DispatchBindImageMemory2(device, bindInfoCount, pBindInfos);
    RecordObject record_obj(vvl::Func::vkBindImageMemory2, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordBindImageMemory2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordBindImageMemory2(device, bindInfoCount, pBindInfos, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                                            uint32_t remoteDeviceIndex,
                                                            VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceGroupPeerMemoryFeatures, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetDeviceGroupPeerMemoryFeatures]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex,
                                                                           pPeerMemoryFeatures, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetDeviceGroupPeerMemoryFeatures]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex,
                                                                 pPeerMemoryFeatures);
    }
    DispatchGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    RecordObject record_obj(vvl::Func::vkGetDeviceGroupPeerMemoryFeatures);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetDeviceGroupPeerMemoryFeatures]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex,
                                                                  pPeerMemoryFeatures, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDeviceMask, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDeviceMask]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDeviceMask(commandBuffer, deviceMask, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDeviceMask]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDeviceMask(commandBuffer, deviceMask);
    }
    DispatchCmdSetDeviceMask(commandBuffer, deviceMask);
    RecordObject record_obj(vvl::Func::vkCmdSetDeviceMask);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDeviceMask]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDeviceMask(commandBuffer, deviceMask, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                           uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDispatchBase, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdDispatchBase]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX,
                                                          groupCountY, groupCountZ, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdDispatchBase]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                                groupCountZ);
    }
    DispatchCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    RecordObject record_obj(vvl::Func::vkCmdDispatchBase);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdDispatchBase]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                                 groupCountZ, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount,
                                                             VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkEnumeratePhysicalDeviceGroups, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount,
                                                                        pPhysicalDeviceGroupProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    }
    VkResult result = DispatchEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    RecordObject record_obj(vvl::Func::vkEnumeratePhysicalDeviceGroups, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties,
                                                               record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo,
                                                       VkMemoryRequirements2* pMemoryRequirements) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetImageMemoryRequirements2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetImageMemoryRequirements2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetImageMemoryRequirements2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
    }
    DispatchGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
    RecordObject record_obj(vvl::Func::vkGetImageMemoryRequirements2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetImageMemoryRequirements2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo,
                                                        VkMemoryRequirements2* pMemoryRequirements) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetBufferMemoryRequirements2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetBufferMemoryRequirements2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetBufferMemoryRequirements2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    }
    DispatchGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    RecordObject record_obj(vvl::Func::vkGetBufferMemoryRequirements2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetBufferMemoryRequirements2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceFeatures2,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceFeatures2(physicalDevice, pFeatures, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    }
    DispatchGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceFeatures2);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceFeatures2(physicalDevice, pFeatures, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceProperties2,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceProperties2(physicalDevice, pProperties, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceProperties2(physicalDevice, pProperties);
    }
    DispatchGetPhysicalDeviceProperties2(physicalDevice, pProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceProperties2);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceProperties2(physicalDevice, pProperties, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format,
                                                              VkFormatProperties2* pFormatProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceFormatProperties2,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    }
    DispatchGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceFormatProperties2);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice,
                                                                       const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
                                                                       VkImageFormatProperties2* pImageFormatProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceImageFormatProperties2,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo,
                                                                                  pImageFormatProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    }
    VkResult result = DispatchGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceImageFormatProperties2, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties,
                                                                         record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice,
                                                                   uint32_t* pQueueFamilyPropertyCount,
                                                                   VkQueueFamilyProperties2* pQueueFamilyProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceQueueFamilyProperties2,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount,
                                                                                  pQueueFamilyProperties, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount,
                                                                        pQueueFamilyProperties);
    }
    DispatchGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceQueueFamilyProperties2);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount,
                                                                         pQueueFamilyProperties, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice,
                                                              VkPhysicalDeviceMemoryProperties2* pMemoryProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceMemoryProperties2,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
    }
    DispatchGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceMemoryProperties2);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceQueue2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetDeviceQueue2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetDeviceQueue2(device, pQueueInfo, pQueue, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetDeviceQueue2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDeviceQueue2(device, pQueueInfo, pQueue);
    }
    DispatchGetDeviceQueue2(device, pQueueInfo, pQueue);
    RecordObject record_obj(vvl::Func::vkGetDeviceQueue2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetDeviceQueue2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDeviceQueue2(device, pQueueInfo, pQueue, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            VkSamplerYcbcrConversion* pYcbcrConversion) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateSamplerYcbcrConversion, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateCreateSamplerYcbcrConversion]) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateSamplerYcbcrConversion]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
    }
    VkResult result = DispatchCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
    RecordObject record_obj(vvl::Func::vkCreateSamplerYcbcrConversion, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateSamplerYcbcrConversion]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion,
                                                         const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroySamplerYcbcrConversion, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateDestroySamplerYcbcrConversion]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroySamplerYcbcrConversion]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
    }
    DispatchDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroySamplerYcbcrConversion);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroySamplerYcbcrConversion]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice,
                                                                     const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
                                                                     VkExternalBufferProperties* pExternalBufferProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceExternalBufferProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo,
                                                                                    pExternalBufferProperties, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo,
                                                                          pExternalBufferProperties);
    }
    DispatchGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceExternalBufferProperties);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo,
                                                                           pExternalBufferProperties, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice,
                                                                    const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
                                                                    VkExternalFenceProperties* pExternalFenceProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceExternalFenceProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo,
                                                                                   pExternalFenceProperties, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo,
                                                                         pExternalFenceProperties);
    }
    DispatchGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceExternalFenceProperties);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo,
                                                                          pExternalFenceProperties, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceExternalSemaphoreProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo,
                                                                                       pExternalSemaphoreProperties, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo,
                                                                             pExternalSemaphoreProperties);
    }
    DispatchGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceExternalSemaphoreProperties);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo,
                                                                              pExternalSemaphoreProperties, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                         VkDescriptorSetLayoutSupport* pSupport) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDescriptorSetLayoutSupport, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetDescriptorSetLayoutSupport]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetDescriptorSetLayoutSupport]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
    }
    DispatchGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
    RecordObject record_obj(vvl::Func::vkGetDescriptorSetLayoutSupport);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetDescriptorSetLayoutSupport]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                uint32_t stride) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDrawIndirectCount, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdDrawIndirectCount]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                               maxDrawCount, stride, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdDrawIndirectCount]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                                     stride);
    }
    DispatchCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    RecordObject record_obj(vvl::Func::vkCmdDrawIndirectCount);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdDrawIndirectCount]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                                      stride, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                       VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                       uint32_t stride) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdDrawIndexedIndirectCount,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdDrawIndexedIndirectCount]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                                      maxDrawCount, stride, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdDrawIndexedIndirectCount]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                            maxDrawCount, stride);
    }
    DispatchCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    RecordObject record_obj(vvl::Func::vkCmdDrawIndexedIndirectCount);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdDrawIndexedIndirectCount]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                             maxDrawCount, stride, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateRenderPass2, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateRenderPass2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateRenderPass2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    }
    VkResult result = DispatchCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    RecordObject record_obj(vvl::Func::vkCreateRenderPass2, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateRenderPass2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                               const VkSubpassBeginInfo* pSubpassBeginInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBeginRenderPass2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBeginRenderPass2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBeginRenderPass2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }
    DispatchCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    RecordObject record_obj(vvl::Func::vkCmdBeginRenderPass2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBeginRenderPass2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                           const VkSubpassEndInfo* pSubpassEndInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdNextSubpass2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdNextSubpass2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdNextSubpass2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }
    DispatchCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    RecordObject record_obj(vvl::Func::vkCmdNextSubpass2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdNextSubpass2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdEndRenderPass2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdEndRenderPass2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdEndRenderPass2(commandBuffer, pSubpassEndInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdEndRenderPass2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    }
    DispatchCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    RecordObject record_obj(vvl::Func::vkCmdEndRenderPass2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdEndRenderPass2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdEndRenderPass2(commandBuffer, pSubpassEndInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL ResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkResetQueryPool, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateResetQueryPool]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateResetQueryPool(device, queryPool, firstQuery, queryCount, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordResetQueryPool]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordResetQueryPool(device, queryPool, firstQuery, queryCount);
    }
    DispatchResetQueryPool(device, queryPool, firstQuery, queryCount);
    RecordObject record_obj(vvl::Func::vkResetQueryPool);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordResetQueryPool]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordResetQueryPool(device, queryPool, firstQuery, queryCount, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetSemaphoreCounterValue, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetSemaphoreCounterValue]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetSemaphoreCounterValue(device, semaphore, pValue, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetSemaphoreCounterValue]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetSemaphoreCounterValue(device, semaphore, pValue);
    }
    VkResult result = DispatchGetSemaphoreCounterValue(device, semaphore, pValue);
    RecordObject record_obj(vvl::Func::vkGetSemaphoreCounterValue, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetSemaphoreCounterValue]) {
        ValidationObject::BlockingOperationGuard lock(intercept);
        intercept->PostCallRecordGetSemaphoreCounterValue(device, semaphore, pValue, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkWaitSemaphores, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateWaitSemaphores]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateWaitSemaphores(device, pWaitInfo, timeout, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordWaitSemaphores]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordWaitSemaphores(device, pWaitInfo, timeout);
    }
    VkResult result = DispatchWaitSemaphores(device, pWaitInfo, timeout);
    RecordObject record_obj(vvl::Func::vkWaitSemaphores, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordWaitSemaphores]) {
        ValidationObject::BlockingOperationGuard lock(intercept);
        intercept->PostCallRecordWaitSemaphores(device, pWaitInfo, timeout, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSignalSemaphore, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateSignalSemaphore]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateSignalSemaphore(device, pSignalInfo, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordSignalSemaphore]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordSignalSemaphore(device, pSignalInfo);
    }
    VkResult result = DispatchSignalSemaphore(device, pSignalInfo);
    RecordObject record_obj(vvl::Func::vkSignalSemaphore, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordSignalSemaphore]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordSignalSemaphore(device, pSignalInfo, record_obj);
    }
    return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetBufferDeviceAddress, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetBufferDeviceAddress]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetBufferDeviceAddress(device, pInfo, error_obj);
        if (skip) return 0;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetBufferDeviceAddress]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetBufferDeviceAddress(device, pInfo);
    }
    VkDeviceAddress result = DispatchGetBufferDeviceAddress(device, pInfo);
    RecordObject record_obj(vvl::Func::vkGetBufferDeviceAddress, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetBufferDeviceAddress]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetBufferDeviceAddress(device, pInfo, record_obj);
    }
    return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetBufferOpaqueCaptureAddress, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetBufferOpaqueCaptureAddress]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetBufferOpaqueCaptureAddress(device, pInfo, error_obj);
        if (skip) return 0;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetBufferOpaqueCaptureAddress]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetBufferOpaqueCaptureAddress(device, pInfo);
    }
    uint64_t result = DispatchGetBufferOpaqueCaptureAddress(device, pInfo);
    RecordObject record_obj(vvl::Func::vkGetBufferOpaqueCaptureAddress);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetBufferOpaqueCaptureAddress]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetBufferOpaqueCaptureAddress(device, pInfo, record_obj);
    }
    return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress(VkDevice device,
                                                                   const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceMemoryOpaqueCaptureAddress, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetDeviceMemoryOpaqueCaptureAddress]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetDeviceMemoryOpaqueCaptureAddress(device, pInfo, error_obj);
        if (skip) return 0;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetDeviceMemoryOpaqueCaptureAddress]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
    }
    uint64_t result = DispatchGetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
    RecordObject record_obj(vvl::Func::vkGetDeviceMemoryOpaqueCaptureAddress);
    for (ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPostCallRecordGetDeviceMemoryOpaqueCaptureAddress]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDeviceMemoryOpaqueCaptureAddress(device, pInfo, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount,
                                                               VkPhysicalDeviceToolProperties* pToolProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceToolProperties,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties);
    }
    VkResult result = DispatchGetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceToolProperties, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreatePrivateDataSlot, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreatePrivateDataSlot]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreatePrivateDataSlot]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    }
    VkResult result = DispatchCreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    RecordObject record_obj(vvl::Func::vkCreatePrivateDataSlot, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreatePrivateDataSlot]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                  const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyPrivateDataSlot, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDestroyPrivateDataSlot]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyPrivateDataSlot(device, privateDataSlot, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDestroyPrivateDataSlot]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyPrivateDataSlot(device, privateDataSlot, pAllocator);
    }
    DispatchDestroyPrivateDataSlot(device, privateDataSlot, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroyPrivateDataSlot);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDestroyPrivateDataSlot]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyPrivateDataSlot(device, privateDataSlot, pAllocator, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL SetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle,
                                              VkPrivateDataSlot privateDataSlot, uint64_t data) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSetPrivateData, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateSetPrivateData]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateSetPrivateData(device, objectType, objectHandle, privateDataSlot, data, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordSetPrivateData]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordSetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
    }
    VkResult result = DispatchSetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
    RecordObject record_obj(vvl::Func::vkSetPrivateData, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordSetPrivateData]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordSetPrivateData(device, objectType, objectHandle, privateDataSlot, data, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle,
                                          VkPrivateDataSlot privateDataSlot, uint64_t* pData) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPrivateData, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetPrivateData]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPrivateData(device, objectType, objectHandle, privateDataSlot, pData, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetPrivateData]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPrivateData(device, objectType, objectHandle, privateDataSlot, pData);
    }
    DispatchGetPrivateData(device, objectType, objectHandle, privateDataSlot, pData);
    RecordObject record_obj(vvl::Func::vkGetPrivateData);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetPrivateData]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPrivateData(device, objectType, objectHandle, privateDataSlot, pData, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetEvent2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetEvent2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetEvent2(commandBuffer, event, pDependencyInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetEvent2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetEvent2(commandBuffer, event, pDependencyInfo);
    }
    DispatchCmdSetEvent2(commandBuffer, event, pDependencyInfo);
    RecordObject record_obj(vvl::Func::vkCmdSetEvent2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetEvent2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetEvent2(commandBuffer, event, pDependencyInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResetEvent2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdResetEvent2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdResetEvent2(commandBuffer, event, stageMask, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdResetEvent2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdResetEvent2(commandBuffer, event, stageMask);
    }
    DispatchCmdResetEvent2(commandBuffer, event, stageMask);
    RecordObject record_obj(vvl::Func::vkCmdResetEvent2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdResetEvent2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdResetEvent2(commandBuffer, event, stageMask, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                          const VkDependencyInfo* pDependencyInfos) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWaitEvents2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdWaitEvents2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdWaitEvents2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    }
    DispatchCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    RecordObject record_obj(vvl::Func::vkCmdWaitEvents2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdWaitEvents2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdPipelineBarrier2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdPipelineBarrier2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdPipelineBarrier2(commandBuffer, pDependencyInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdPipelineBarrier2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    }
    DispatchCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    RecordObject record_obj(vvl::Func::vkCmdPipelineBarrier2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdPipelineBarrier2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdPipelineBarrier2(commandBuffer, pDependencyInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                              uint32_t query) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWriteTimestamp2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdWriteTimestamp2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdWriteTimestamp2(commandBuffer, stage, queryPool, query, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdWriteTimestamp2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    }
    DispatchCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    RecordObject record_obj(vvl::Func::vkCmdWriteTimestamp2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdWriteTimestamp2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdWriteTimestamp2(commandBuffer, stage, queryPool, query, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(queue), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueSubmit2, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateQueueSubmit2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateQueueSubmit2(queue, submitCount, pSubmits, fence, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordQueueSubmit2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordQueueSubmit2(queue, submitCount, pSubmits, fence);
    }
    VkResult result = DispatchQueueSubmit2(queue, submitCount, pSubmits, fence);
    RecordObject record_obj(vvl::Func::vkQueueSubmit2, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordQueueSubmit2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordQueueSubmit2(queue, submitCount, pSubmits, fence, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyBuffer2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyBuffer2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyBuffer2(commandBuffer, pCopyBufferInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyBuffer2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    }
    DispatchCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    RecordObject record_obj(vvl::Func::vkCmdCopyBuffer2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyBuffer2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyBuffer2(commandBuffer, pCopyBufferInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyImage2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyImage2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyImage2(commandBuffer, pCopyImageInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyImage2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyImage2(commandBuffer, pCopyImageInfo);
    }
    DispatchCmdCopyImage2(commandBuffer, pCopyImageInfo);
    RecordObject record_obj(vvl::Func::vkCmdCopyImage2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyImage2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyImage2(commandBuffer, pCopyImageInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                                 const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyBufferToImage2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyBufferToImage2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyBufferToImage2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    }
    DispatchCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    RecordObject record_obj(vvl::Func::vkCmdCopyBufferToImage2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyBufferToImage2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                                 const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyImageToBuffer2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyImageToBuffer2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyImageToBuffer2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    }
    DispatchCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    RecordObject record_obj(vvl::Func::vkCmdCopyImageToBuffer2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyImageToBuffer2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBlitImage2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBlitImage2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBlitImage2(commandBuffer, pBlitImageInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBlitImage2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBlitImage2(commandBuffer, pBlitImageInfo);
    }
    DispatchCmdBlitImage2(commandBuffer, pBlitImageInfo);
    RecordObject record_obj(vvl::Func::vkCmdBlitImage2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBlitImage2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBlitImage2(commandBuffer, pBlitImageInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResolveImage2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdResolveImage2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdResolveImage2(commandBuffer, pResolveImageInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdResolveImage2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdResolveImage2(commandBuffer, pResolveImageInfo);
    }
    DispatchCmdResolveImage2(commandBuffer, pResolveImageInfo);
    RecordObject record_obj(vvl::Func::vkCmdResolveImage2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdResolveImage2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdResolveImage2(commandBuffer, pResolveImageInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBeginRendering, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBeginRendering]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBeginRendering(commandBuffer, pRenderingInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBeginRendering]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBeginRendering(commandBuffer, pRenderingInfo);
    }
    DispatchCmdBeginRendering(commandBuffer, pRenderingInfo);
    RecordObject record_obj(vvl::Func::vkCmdBeginRendering);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBeginRendering]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBeginRendering(commandBuffer, pRenderingInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndRendering(VkCommandBuffer commandBuffer) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdEndRendering, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdEndRendering]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdEndRendering(commandBuffer, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdEndRendering]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdEndRendering(commandBuffer);
    }
    DispatchCmdEndRendering(commandBuffer);
    RecordObject record_obj(vvl::Func::vkCmdEndRendering);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdEndRendering]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdEndRendering(commandBuffer, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetCullMode, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetCullMode]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetCullMode(commandBuffer, cullMode, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetCullMode]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetCullMode(commandBuffer, cullMode);
    }
    DispatchCmdSetCullMode(commandBuffer, cullMode);
    RecordObject record_obj(vvl::Func::vkCmdSetCullMode);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetCullMode]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetCullMode(commandBuffer, cullMode, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetFrontFace, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetFrontFace]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetFrontFace(commandBuffer, frontFace, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetFrontFace]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetFrontFace(commandBuffer, frontFace);
    }
    DispatchCmdSetFrontFace(commandBuffer, frontFace);
    RecordObject record_obj(vvl::Func::vkCmdSetFrontFace);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetFrontFace]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetFrontFace(commandBuffer, frontFace, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetPrimitiveTopology, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetPrimitiveTopology]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetPrimitiveTopology(commandBuffer, primitiveTopology, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetPrimitiveTopology]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    }
    DispatchCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    RecordObject record_obj(vvl::Func::vkCmdSetPrimitiveTopology);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetPrimitiveTopology]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetPrimitiveTopology(commandBuffer, primitiveTopology, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                   const VkViewport* pViewports) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetViewportWithCount, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetViewportWithCount]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetViewportWithCount]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    }
    DispatchCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    RecordObject record_obj(vvl::Func::vkCmdSetViewportWithCount);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetViewportWithCount]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetScissorWithCount, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetScissorWithCount]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetScissorWithCount]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    }
    DispatchCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    RecordObject record_obj(vvl::Func::vkCmdSetScissorWithCount);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetScissorWithCount]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                                 const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                 const VkDeviceSize* pStrides) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindVertexBuffers2, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBindVertexBuffers2]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets,
                                                                pSizes, pStrides, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBindVertexBuffers2]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                                      pStrides);
    }
    DispatchCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    RecordObject record_obj(vvl::Func::vkCmdBindVertexBuffers2);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBindVertexBuffers2]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                                       pStrides, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthTestEnable, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthTestEnable]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDepthTestEnable(commandBuffer, depthTestEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthTestEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    }
    DispatchCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetDepthTestEnable);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthTestEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDepthTestEnable(commandBuffer, depthTestEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthWriteEnable, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthWriteEnable]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthWriteEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    }
    DispatchCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetDepthWriteEnable);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthWriteEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthCompareOp, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthCompareOp]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDepthCompareOp(commandBuffer, depthCompareOp, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthCompareOp]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    }
    DispatchCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    RecordObject record_obj(vvl::Func::vkCmdSetDepthCompareOp);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthCompareOp]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDepthCompareOp(commandBuffer, depthCompareOp, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthBoundsTestEnable,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthBoundsTestEnable]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthBoundsTestEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    }
    DispatchCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetDepthBoundsTestEnable);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthBoundsTestEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilTestEnable, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilTestEnable]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetStencilTestEnable(commandBuffer, stencilTestEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilTestEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    }
    DispatchCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetStencilTestEnable);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilTestEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetStencilTestEnable(commandBuffer, stencilTestEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                           VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilOp, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilOp]) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilOp]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }
    DispatchCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    RecordObject record_obj(vvl::Func::vkCmdSetStencilOp);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilOp]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetRasterizerDiscardEnable,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetRasterizerDiscardEnable]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetRasterizerDiscardEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    }
    DispatchCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetRasterizerDiscardEnable);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetRasterizerDiscardEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthBiasEnable, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthBiasEnable]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthBiasEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    }
    DispatchCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetDepthBiasEnable);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthBiasEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetPrimitiveRestartEnable,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetPrimitiveRestartEnable]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetPrimitiveRestartEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    }
    DispatchCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetPrimitiveRestartEnable);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetPrimitiveRestartEnable]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo,
                                                             VkMemoryRequirements2* pMemoryRequirements) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceBufferMemoryRequirements, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetDeviceBufferMemoryRequirements]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetDeviceBufferMemoryRequirements]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements);
    }
    DispatchGetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements);
    RecordObject record_obj(vvl::Func::vkGetDeviceBufferMemoryRequirements);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetDeviceBufferMemoryRequirements]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo,
                                                            VkMemoryRequirements2* pMemoryRequirements) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceImageMemoryRequirements, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetDeviceImageMemoryRequirements]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetDeviceImageMemoryRequirements]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements);
    }
    DispatchGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements);
    RecordObject record_obj(vvl::Func::vkGetDeviceImageMemoryRequirements);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetDeviceImageMemoryRequirements]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo,
                                                                  uint32_t* pSparseMemoryRequirementCount,
                                                                  VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceImageSparseMemoryRequirements, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetDeviceImageSparseMemoryRequirements]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount,
                                                                                 pSparseMemoryRequirements, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallRecordGetDeviceImageSparseMemoryRequirements]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount,
                                                                       pSparseMemoryRequirements);
    }
    DispatchGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    RecordObject record_obj(vvl::Func::vkGetDeviceImageSparseMemoryRequirements);
    for (ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPostCallRecordGetDeviceImageSparseMemoryRequirements]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount,
                                                                        pSparseMemoryRequirements, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetCommandPoolMemoryConsumption(VkDevice device, VkCommandPool commandPool,
                                                           VkCommandBuffer commandBuffer,
                                                           VkCommandPoolMemoryConsumption* pConsumption) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetCommandPoolMemoryConsumption, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetCommandPoolMemoryConsumption]) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateGetCommandPoolMemoryConsumption(device, commandPool, commandBuffer, pConsumption, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetCommandPoolMemoryConsumption]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetCommandPoolMemoryConsumption(device, commandPool, commandBuffer, pConsumption);
    }
    DispatchGetCommandPoolMemoryConsumption(device, commandPool, commandBuffer, pConsumption);
    RecordObject record_obj(vvl::Func::vkGetCommandPoolMemoryConsumption);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetCommandPoolMemoryConsumption]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetCommandPoolMemoryConsumption(device, commandPool, commandBuffer, pConsumption, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetFaultData(VkDevice device, VkFaultQueryBehavior faultQueryBehavior, VkBool32* pUnrecordedFaults,
                                            uint32_t* pFaultCount, VkFaultData* pFaults) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetFaultData, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetFaultData]) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateGetFaultData(device, faultQueryBehavior, pUnrecordedFaults, pFaultCount, pFaults, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetFaultData]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetFaultData(device, faultQueryBehavior, pUnrecordedFaults, pFaultCount, pFaults);
    }
    VkResult result = DispatchGetFaultData(device, faultQueryBehavior, pUnrecordedFaults, pFaultCount, pFaults);
    RecordObject record_obj(vvl::Func::vkGetFaultData, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetFaultData]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetFaultData(device, faultQueryBehavior, pUnrecordedFaults, pFaultCount, pFaults, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroySurfaceKHR, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroySurfaceKHR(instance, surface, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroySurfaceKHR(instance, surface, pAllocator);
    }
    DispatchDestroySurfaceKHR(instance, surface, pAllocator);
    RecordObject record_obj(vvl::Func::vkDestroySurfaceKHR);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroySurfaceKHR(instance, surface, pAllocator, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex,
                                                                  VkSurfaceKHR surface, VkBool32* pSupported) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfaceSupportKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported,
                                                                             error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    }
    VkResult result = DispatchGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfaceSupportKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported,
                                                                    record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                       VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfaceCapabilitiesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities,
                                                                                  error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
    }
    VkResult result = DispatchGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfaceCapabilitiesKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                  uint32_t* pSurfaceFormatCount,
                                                                  VkSurfaceFormatKHR* pSurfaceFormats) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfaceFormatsKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount,
                                                                             pSurfaceFormats, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    }
    VkResult result = DispatchGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfaceFormatsKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats,
                                                                    record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                       uint32_t* pPresentModeCount,
                                                                       VkPresentModeKHR* pPresentModes) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfacePresentModesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount,
                                                                                  pPresentModes, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    }
    VkResult result = DispatchGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfacePresentModesKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes,
                                                                         record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateSwapchainKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateSwapchainKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateSwapchainKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    }
    VkResult result = DispatchCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    RecordObject record_obj(vvl::Func::vkCreateSwapchainKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateSwapchainKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount,
                                                     VkImage* pSwapchainImages) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetSwapchainImagesKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetSwapchainImagesKHR]) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetSwapchainImagesKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
    }
    VkResult result = DispatchGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
    RecordObject record_obj(vvl::Func::vkGetSwapchainImagesKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetSwapchainImagesKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout,
                                                   VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkAcquireNextImageKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateAcquireNextImageKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordAcquireNextImageKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    }
    VkResult result = DispatchAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    RecordObject record_obj(vvl::Func::vkAcquireNextImageKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordAcquireNextImageKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(queue), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueuePresentKHR, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateQueuePresentKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateQueuePresentKHR(queue, pPresentInfo, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordQueuePresentKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordQueuePresentKHR(queue, pPresentInfo);
    }
    VkResult result = DispatchQueuePresentKHR(queue, pPresentInfo);
    RecordObject record_obj(vvl::Func::vkQueuePresentKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordQueuePresentKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordQueuePresentKHR(queue, pPresentInfo, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL
GetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceGroupPresentCapabilitiesKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetDeviceGroupPresentCapabilitiesKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallRecordGetDeviceGroupPresentCapabilitiesKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
    }
    VkResult result = DispatchGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
    RecordObject record_obj(vvl::Func::vkGetDeviceGroupPresentCapabilitiesKHR, result);
    for (ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPostCallRecordGetDeviceGroupPresentCapabilitiesKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface,
                                                                    VkDeviceGroupPresentModeFlagsKHR* pModes) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDeviceGroupSurfacePresentModesKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetDeviceGroupSurfacePresentModesKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallRecordGetDeviceGroupSurfacePresentModesKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
    }
    VkResult result = DispatchGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
    RecordObject record_obj(vvl::Func::vkGetDeviceGroupSurfacePresentModesKHR, result);
    for (ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPostCallRecordGetDeviceGroupSurfacePresentModesKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                     uint32_t* pRectCount, VkRect2D* pRects) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDevicePresentRectanglesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
    }
    VkResult result = DispatchGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDevicePresentRectanglesKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo,
                                                    uint32_t* pImageIndex) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkAcquireNextImage2KHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateAcquireNextImage2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordAcquireNextImage2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
    }
    VkResult result = DispatchAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
    RecordObject record_obj(vvl::Func::vkAcquireNextImage2KHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordAcquireNextImage2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                                     VkDisplayPropertiesKHR* pProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceDisplayPropertiesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    }
    VkResult result = DispatchGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceDisplayPropertiesKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                                          VkDisplayPlanePropertiesKHR* pProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceDisplayPlanePropertiesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties,
                                                                                     error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    }
    VkResult result = DispatchGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceDisplayPlanePropertiesKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties,
                                                                            record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex,
                                                                   uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDisplayPlaneSupportedDisplaysKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays,
                                                                              error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
    }
    VkResult result = DispatchGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
    RecordObject record_obj(vvl::Func::vkGetDisplayPlaneSupportedDisplaysKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays,
                                                                     record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                           uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDisplayModePropertiesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
    }
    VkResult result = DispatchGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
    RecordObject record_obj(vvl::Func::vkGetDisplayModePropertiesKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                    const VkDisplayModeCreateInfoKHR* pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateDisplayModeKHR, VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
    }
    VkResult result = DispatchCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
    RecordObject record_obj(vvl::Func::vkCreateDisplayModeKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode,
                                                              uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDisplayPlaneCapabilitiesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
    }
    VkResult result = DispatchGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
    RecordObject record_obj(vvl::Func::vkGetDisplayPlaneCapabilitiesKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateDisplayPlaneSurfaceKHR, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    }
    VkResult result = DispatchCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    RecordObject record_obj(vvl::Func::vkCreateDisplayPlaneSurfaceKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                                         const VkSwapchainCreateInfoKHR* pCreateInfos,
                                                         const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateSharedSwapchainsKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCreateSharedSwapchainsKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains,
                                                                    error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateSharedSwapchainsKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    }
    VkResult result = DispatchCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    RecordObject record_obj(vvl::Func::vkCreateSharedSwapchainsKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateSharedSwapchainsKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains,
                                                           record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetMemoryFdKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetMemoryFdKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetMemoryFdKHR(device, pGetFdInfo, pFd, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetMemoryFdKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetMemoryFdKHR(device, pGetFdInfo, pFd);
    }
    VkResult result = DispatchGetMemoryFdKHR(device, pGetFdInfo, pFd);
    RecordObject record_obj(vvl::Func::vkGetMemoryFdKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetMemoryFdKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetMemoryFdKHR(device, pGetFdInfo, pFd, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd,
                                                        VkMemoryFdPropertiesKHR* pMemoryFdProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetMemoryFdPropertiesKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetMemoryFdPropertiesKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetMemoryFdPropertiesKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
    }
    VkResult result = DispatchGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
    RecordObject record_obj(vvl::Func::vkGetMemoryFdPropertiesKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetMemoryFdPropertiesKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkImportSemaphoreFdKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateImportSemaphoreFdKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordImportSemaphoreFdKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
    }
    VkResult result = DispatchImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
    RecordObject record_obj(vvl::Func::vkImportSemaphoreFdKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordImportSemaphoreFdKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetSemaphoreFdKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetSemaphoreFdKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetSemaphoreFdKHR(device, pGetFdInfo, pFd, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetSemaphoreFdKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetSemaphoreFdKHR(device, pGetFdInfo, pFd);
    }
    VkResult result = DispatchGetSemaphoreFdKHR(device, pGetFdInfo, pFd);
    RecordObject record_obj(vvl::Func::vkGetSemaphoreFdKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetSemaphoreFdKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetSemaphoreFdKHR(device, pGetFdInfo, pFd, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetSwapchainStatusKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetSwapchainStatusKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetSwapchainStatusKHR(device, swapchain, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetSwapchainStatusKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetSwapchainStatusKHR(device, swapchain);
    }
    VkResult result = DispatchGetSwapchainStatusKHR(device, swapchain);
    RecordObject record_obj(vvl::Func::vkGetSwapchainStatusKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetSwapchainStatusKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetSwapchainStatusKHR(device, swapchain, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkImportFenceFdKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateImportFenceFdKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateImportFenceFdKHR(device, pImportFenceFdInfo, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordImportFenceFdKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordImportFenceFdKHR(device, pImportFenceFdInfo);
    }
    VkResult result = DispatchImportFenceFdKHR(device, pImportFenceFdInfo);
    RecordObject record_obj(vvl::Func::vkImportFenceFdKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordImportFenceFdKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordImportFenceFdKHR(device, pImportFenceFdInfo, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetFenceFdKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetFenceFdKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetFenceFdKHR(device, pGetFdInfo, pFd, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetFenceFdKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetFenceFdKHR(device, pGetFdInfo, pFd);
    }
    VkResult result = DispatchGetFenceFdKHR(device, pGetFdInfo, pFd);
    RecordObject record_obj(vvl::Func::vkGetFenceFdKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetFenceFdKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetFenceFdKHR(device, pGetFdInfo, pFd, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters,
    VkPerformanceCounterDescriptionKHR* pCounterDescriptions) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
            physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
            physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    }
    VkResult result = DispatchEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
        physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    RecordObject record_obj(vvl::Func::vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
            physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
            physicalDevice, pPerformanceQueryCreateInfo, pNumPasses, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo,
                                                                                      pNumPasses);
    }
    DispatchGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo,
                                                                                       pNumPasses, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkAcquireProfilingLockKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateAcquireProfilingLockKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateAcquireProfilingLockKHR(device, pInfo, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordAcquireProfilingLockKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordAcquireProfilingLockKHR(device, pInfo);
    }
    VkResult result = DispatchAcquireProfilingLockKHR(device, pInfo);
    RecordObject record_obj(vvl::Func::vkAcquireProfilingLockKHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordAcquireProfilingLockKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordAcquireProfilingLockKHR(device, pInfo, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR(VkDevice device) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkReleaseProfilingLockKHR, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateReleaseProfilingLockKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateReleaseProfilingLockKHR(device, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordReleaseProfilingLockKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordReleaseProfilingLockKHR(device);
    }
    DispatchReleaseProfilingLockKHR(device);
    RecordObject record_obj(vvl::Func::vkReleaseProfilingLockKHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordReleaseProfilingLockKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordReleaseProfilingLockKHR(device, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice,
                                                                        const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                        VkSurfaceCapabilities2KHR* pSurfaceCapabilities) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfaceCapabilities2KHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo,
                                                                                   pSurfaceCapabilities, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    }
    VkResult result = DispatchGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfaceCapabilities2KHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities,
                                                                          record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice,
                                                                   const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                   uint32_t* pSurfaceFormatCount,
                                                                   VkSurfaceFormat2KHR* pSurfaceFormats) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfaceFormats2KHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount,
                                                                              pSurfaceFormats, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount,
                                                                    pSurfaceFormats);
    }
    VkResult result =
        DispatchGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfaceFormats2KHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount,
                                                                     pSurfaceFormats, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                                      VkDisplayProperties2KHR* pProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceDisplayProperties2KHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties,
                                                                                 error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    }
    VkResult result = DispatchGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceDisplayProperties2KHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice,
                                                                           uint32_t* pPropertyCount,
                                                                           VkDisplayPlaneProperties2KHR* pProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceDisplayPlaneProperties2KHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties,
                                                                                      error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    }
    VkResult result = DispatchGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceDisplayPlaneProperties2KHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties,
                                                                             record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                            uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDisplayModeProperties2KHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
    }
    VkResult result = DispatchGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
    RecordObject record_obj(vvl::Func::vkGetDisplayModeProperties2KHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice,
                                                               const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo,
                                                               VkDisplayPlaneCapabilities2KHR* pCapabilities) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetDisplayPlaneCapabilities2KHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
    }
    VkResult result = DispatchGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
    RecordObject record_obj(vvl::Func::vkGetDisplayPlaneCapabilities2KHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL
GetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount,
                                         VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceFragmentShadingRatesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount,
                                                                                   pFragmentShadingRates, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount,
                                                                         pFragmentShadingRates);
    }
    VkResult result =
        DispatchGetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceFragmentShadingRatesKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount,
                                                                          pFragmentShadingRates, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                                        const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetFragmentShadingRateKHR,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetFragmentShadingRateKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetFragmentShadingRateKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
    }
    DispatchCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
    RecordObject record_obj(vvl::Func::vkCmdSetFragmentShadingRateKHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetFragmentShadingRateKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdRefreshObjectsKHR(VkCommandBuffer commandBuffer, const VkRefreshObjectListKHR* pRefreshObjects) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdRefreshObjectsKHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdRefreshObjectsKHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdRefreshObjectsKHR(commandBuffer, pRefreshObjects, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdRefreshObjectsKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdRefreshObjectsKHR(commandBuffer, pRefreshObjects);
    }
    DispatchCmdRefreshObjectsKHR(commandBuffer, pRefreshObjects);
    RecordObject record_obj(vvl::Func::vkCmdRefreshObjectsKHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdRefreshObjectsKHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdRefreshObjectsKHR(commandBuffer, pRefreshObjects, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceRefreshableObjectTypesKHR(VkPhysicalDevice physicalDevice,
                                                                          uint32_t* pRefreshableObjectTypeCount,
                                                                          VkObjectType* pRefreshableObjectTypes) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceRefreshableObjectTypesKHR,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceRefreshableObjectTypesKHR(physicalDevice, pRefreshableObjectTypeCount,
                                                                                     pRefreshableObjectTypes, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceRefreshableObjectTypesKHR(physicalDevice, pRefreshableObjectTypeCount,
                                                                           pRefreshableObjectTypes);
    }
    VkResult result =
        DispatchGetPhysicalDeviceRefreshableObjectTypesKHR(physicalDevice, pRefreshableObjectTypeCount, pRefreshableObjectTypes);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceRefreshableObjectTypesKHR, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceRefreshableObjectTypesKHR(physicalDevice, pRefreshableObjectTypeCount,
                                                                            pRefreshableObjectTypes, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetEvent2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetEvent2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetEvent2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
    }
    DispatchCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
    RecordObject record_obj(vvl::Func::vkCmdSetEvent2KHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetEvent2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResetEvent2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdResetEvent2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdResetEvent2KHR(commandBuffer, event, stageMask, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdResetEvent2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdResetEvent2KHR(commandBuffer, event, stageMask);
    }
    DispatchCmdResetEvent2KHR(commandBuffer, event, stageMask);
    RecordObject record_obj(vvl::Func::vkCmdResetEvent2KHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdResetEvent2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdResetEvent2KHR(commandBuffer, event, stageMask, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                             const VkDependencyInfo* pDependencyInfos) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWaitEvents2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdWaitEvents2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdWaitEvents2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
    }
    DispatchCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
    RecordObject record_obj(vvl::Func::vkCmdWaitEvents2KHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdWaitEvents2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdPipelineBarrier2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdPipelineBarrier2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdPipelineBarrier2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
    }
    DispatchCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
    RecordObject record_obj(vvl::Func::vkCmdPipelineBarrier2KHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdPipelineBarrier2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                                 uint32_t query) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWriteTimestamp2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdWriteTimestamp2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdWriteTimestamp2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
    }
    DispatchCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
    RecordObject record_obj(vvl::Func::vkCmdWriteTimestamp2KHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdWriteTimestamp2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(queue), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueSubmit2KHR, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateQueueSubmit2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateQueueSubmit2KHR(queue, submitCount, pSubmits, fence, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordQueueSubmit2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordQueueSubmit2KHR(queue, submitCount, pSubmits, fence);
    }
    VkResult result = DispatchQueueSubmit2KHR(queue, submitCount, pSubmits, fence);
    RecordObject record_obj(vvl::Func::vkQueueSubmit2KHR, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordQueueSubmit2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordQueueSubmit2KHR(queue, submitCount, pSubmits, fence, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer,
                                                    VkDeviceSize dstOffset, uint32_t marker) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdWriteBufferMarker2AMD, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdWriteBufferMarker2AMD]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdWriteBufferMarker2AMD]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
    }
    DispatchCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
    RecordObject record_obj(vvl::Func::vkCmdWriteBufferMarker2AMD);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdWriteBufferMarker2AMD]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount,
                                                     VkCheckpointData2NV* pCheckpointData) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(queue), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetQueueCheckpointData2NV, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetQueueCheckpointData2NV]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetQueueCheckpointData2NV]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData);
    }
    DispatchGetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData);
    RecordObject record_obj(vvl::Func::vkGetQueueCheckpointData2NV);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetQueueCheckpointData2NV]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyBuffer2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyBuffer2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyBuffer2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
    }
    DispatchCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
    RecordObject record_obj(vvl::Func::vkCmdCopyBuffer2KHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyBuffer2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyImage2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyImage2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyImage2KHR(commandBuffer, pCopyImageInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyImage2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
    }
    DispatchCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
    RecordObject record_obj(vvl::Func::vkCmdCopyImage2KHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyImage2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyImage2KHR(commandBuffer, pCopyImageInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                                    const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyBufferToImage2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyBufferToImage2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyBufferToImage2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
    }
    DispatchCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
    RecordObject record_obj(vvl::Func::vkCmdCopyBufferToImage2KHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyBufferToImage2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                                    const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdCopyImageToBuffer2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdCopyImageToBuffer2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdCopyImageToBuffer2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
    }
    DispatchCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
    RecordObject record_obj(vvl::Func::vkCmdCopyImageToBuffer2KHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdCopyImageToBuffer2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBlitImage2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBlitImage2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBlitImage2KHR(commandBuffer, pBlitImageInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBlitImage2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
    }
    DispatchCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
    RecordObject record_obj(vvl::Func::vkCmdBlitImage2KHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBlitImage2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBlitImage2KHR(commandBuffer, pBlitImageInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdResolveImage2KHR, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdResolveImage2KHR]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdResolveImage2KHR(commandBuffer, pResolveImageInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdResolveImage2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
    }
    DispatchCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
    RecordObject record_obj(vvl::Func::vkCmdResolveImage2KHR);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdResolveImage2KHR]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdResolveImage2KHR(commandBuffer, pResolveImageInfo, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkReleaseDisplayEXT, VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateReleaseDisplayEXT(physicalDevice, display, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordReleaseDisplayEXT(physicalDevice, display);
    }
    VkResult result = DispatchReleaseDisplayEXT(physicalDevice, display);
    RecordObject record_obj(vvl::Func::vkReleaseDisplayEXT, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordReleaseDisplayEXT(physicalDevice, display, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                        VkSurfaceCapabilities2EXT* pSurfaceCapabilities) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSurfaceCapabilities2EXT,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities,
                                                                                   error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
    }
    VkResult result = DispatchGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSurfaceCapabilities2EXT, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities,
                                                                          record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT(VkDevice device, VkDisplayKHR display,
                                                      const VkDisplayPowerInfoEXT* pDisplayPowerInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDisplayPowerControlEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateDisplayPowerControlEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDisplayPowerControlEXT(device, display, pDisplayPowerInfo, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordDisplayPowerControlEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDisplayPowerControlEXT(device, display, pDisplayPowerInfo);
    }
    VkResult result = DispatchDisplayPowerControlEXT(device, display, pDisplayPowerInfo);
    RecordObject record_obj(vvl::Func::vkDisplayPowerControlEXT, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordDisplayPowerControlEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDisplayPowerControlEXT(device, display, pDisplayPowerInfo, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkRegisterDeviceEventEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateRegisterDeviceEventEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordRegisterDeviceEventEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
    }
    VkResult result = DispatchRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
    RecordObject record_obj(vvl::Func::vkRegisterDeviceEventEXT, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordRegisterDeviceEventEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display,
                                                       const VkDisplayEventInfoEXT* pDisplayEventInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkRegisterDisplayEventEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateRegisterDisplayEventEXT]) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordRegisterDisplayEventEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
    }
    VkResult result = DispatchRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
    RecordObject record_obj(vvl::Func::vkRegisterDisplayEventEXT, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordRegisterDisplayEventEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain,
                                                      VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetSwapchainCounterEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetSwapchainCounterEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetSwapchainCounterEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
    }
    VkResult result = DispatchGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
    RecordObject record_obj(vvl::Func::vkGetSwapchainCounterEXT, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetSwapchainCounterEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                                     uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDiscardRectangleEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDiscardRectangleEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                                                    pDiscardRectangles, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDiscardRectangleEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                                          pDiscardRectangles);
    }
    DispatchCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    RecordObject record_obj(vvl::Func::vkCmdSetDiscardRectangleEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDiscardRectangleEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                                           pDiscardRectangles, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDiscardRectangleEnableEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDiscardRectangleEnableEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDiscardRectangleEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
    }
    DispatchCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetDiscardRectangleEnableEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDiscardRectangleEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                                         VkDiscardRectangleModeEXT discardRectangleMode) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDiscardRectangleModeEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDiscardRectangleModeEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDiscardRectangleModeEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
    }
    DispatchCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
    RecordObject record_obj(vvl::Func::vkCmdSetDiscardRectangleModeEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDiscardRectangleModeEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains,
                                             const VkHdrMetadataEXT* pMetadata) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSetHdrMetadataEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateSetHdrMetadataEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordSetHdrMetadataEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
    }
    DispatchSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
    RecordObject record_obj(vvl::Func::vkSetHdrMetadataEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordSetHdrMetadataEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSetDebugUtilsObjectNameEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateSetDebugUtilsObjectNameEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateSetDebugUtilsObjectNameEXT(device, pNameInfo, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordSetDebugUtilsObjectNameEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordSetDebugUtilsObjectNameEXT(device, pNameInfo);
    }
    layer_data->report_data->DebugReportSetUtilsObjectName(pNameInfo);
    VkResult result = DispatchSetDebugUtilsObjectNameEXT(device, pNameInfo);
    RecordObject record_obj(vvl::Func::vkSetDebugUtilsObjectNameEXT, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordSetDebugUtilsObjectNameEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordSetDebugUtilsObjectNameEXT(device, pNameInfo, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSetDebugUtilsObjectTagEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateSetDebugUtilsObjectTagEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateSetDebugUtilsObjectTagEXT(device, pTagInfo, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordSetDebugUtilsObjectTagEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordSetDebugUtilsObjectTagEXT(device, pTagInfo);
    }
    VkResult result = DispatchSetDebugUtilsObjectTagEXT(device, pTagInfo);
    RecordObject record_obj(vvl::Func::vkSetDebugUtilsObjectTagEXT, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordSetDebugUtilsObjectTagEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordSetDebugUtilsObjectTagEXT(device, pTagInfo, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(queue), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueBeginDebugUtilsLabelEXT, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateQueueBeginDebugUtilsLabelEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordQueueBeginDebugUtilsLabelEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    }
    BeginQueueDebugUtilsLabel(layer_data->report_data, queue, pLabelInfo);
    DispatchQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    RecordObject record_obj(vvl::Func::vkQueueBeginDebugUtilsLabelEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordQueueBeginDebugUtilsLabelEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(VkQueue queue) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(queue), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueEndDebugUtilsLabelEXT, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateQueueEndDebugUtilsLabelEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateQueueEndDebugUtilsLabelEXT(queue, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordQueueEndDebugUtilsLabelEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordQueueEndDebugUtilsLabelEXT(queue);
    }
    DispatchQueueEndDebugUtilsLabelEXT(queue);
    EndQueueDebugUtilsLabel(layer_data->report_data, queue);
    RecordObject record_obj(vvl::Func::vkQueueEndDebugUtilsLabelEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordQueueEndDebugUtilsLabelEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordQueueEndDebugUtilsLabelEXT(queue, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(queue), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkQueueInsertDebugUtilsLabelEXT, VulkanTypedHandle(queue, kVulkanObjectTypeQueue));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateQueueInsertDebugUtilsLabelEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordQueueInsertDebugUtilsLabelEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    }
    InsertQueueDebugUtilsLabel(layer_data->report_data, queue, pLabelInfo);
    DispatchQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    RecordObject record_obj(vvl::Func::vkQueueInsertDebugUtilsLabelEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordQueueInsertDebugUtilsLabelEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBeginDebugUtilsLabelEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBeginDebugUtilsLabelEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBeginDebugUtilsLabelEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }
    DispatchCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    RecordObject record_obj(vvl::Func::vkCmdBeginDebugUtilsLabelEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBeginDebugUtilsLabelEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdEndDebugUtilsLabelEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdEndDebugUtilsLabelEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdEndDebugUtilsLabelEXT(commandBuffer, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdEndDebugUtilsLabelEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdEndDebugUtilsLabelEXT(commandBuffer);
    }
    DispatchCmdEndDebugUtilsLabelEXT(commandBuffer);
    RecordObject record_obj(vvl::Func::vkCmdEndDebugUtilsLabelEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdEndDebugUtilsLabelEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdEndDebugUtilsLabelEXT(commandBuffer, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdInsertDebugUtilsLabelEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdInsertDebugUtilsLabelEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdInsertDebugUtilsLabelEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }
    DispatchCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    RecordObject record_obj(vvl::Func::vkCmdInsertDebugUtilsLabelEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdInsertDebugUtilsLabelEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo, record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(VkInstance instance,
                                                            const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            VkDebugUtilsMessengerEXT* pMessenger) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateDebugUtilsMessengerEXT, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
    }
    VkResult result = DispatchCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
    LayerCreateMessengerCallback(layer_data->report_data, false, pCreateInfo, pMessenger);
    RecordObject record_obj(vvl::Func::vkCreateDebugUtilsMessengerEXT, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                                         const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkDestroyDebugUtilsMessengerEXT, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    }
    DispatchDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    LayerDestroyCallback(layer_data->report_data, messenger);
    RecordObject record_obj(vvl::Func::vkDestroyDebugUtilsMessengerEXT);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                      VkDebugUtilsMessageTypeFlagsEXT messageTypes,
                                                      const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkSubmitDebugUtilsMessageEXT, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |=
            intercept->PreCallValidateSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    }
    DispatchSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    RecordObject record_obj(vvl::Func::vkSubmitDebugUtilsMessageEXT);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                                    const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetSampleLocationsEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetSampleLocationsEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetSampleLocationsEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    }
    DispatchCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    RecordObject record_obj(vvl::Func::vkCmdSetSampleLocationsEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetSampleLocationsEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples,
                                                                     VkMultisamplePropertiesEXT* pMultisampleProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceMultisamplePropertiesEXT,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties,
                                                                                    error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
    }
    DispatchGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceMultisamplePropertiesEXT);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties,
                                                                           record_obj);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image,
                                                                      VkImageDrmFormatModifierPropertiesEXT* pProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetImageDrmFormatModifierPropertiesEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetImageDrmFormatModifierPropertiesEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallRecordGetImageDrmFormatModifierPropertiesEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
    }
    VkResult result = DispatchGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
    RecordObject record_obj(vvl::Func::vkGetImageDrmFormatModifierPropertiesEXT, result);
    for (ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPostCallRecordGetImageDrmFormatModifierPropertiesEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties, record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType,
                                                                 const void* pHostPointer,
                                                                 VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetMemoryHostPointerPropertiesEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetMemoryHostPointerPropertiesEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer,
                                                                            pMemoryHostPointerProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetMemoryHostPointerPropertiesEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
    }
    VkResult result = DispatchGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
    RecordObject record_obj(vvl::Func::vkGetMemoryHostPointerPropertiesEXT, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetMemoryHostPointerPropertiesEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties,
                                                                   record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice,
                                                                            uint32_t* pTimeDomainCount,
                                                                            VkTimeDomainEXT* pTimeDomains) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceCalibrateableTimeDomainsEXT,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount,
                                                                                       pTimeDomains, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);
    }
    VkResult result = DispatchGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceCalibrateableTimeDomainsEXT, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains,
                                                                              record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount,
                                                          const VkCalibratedTimestampInfoEXT* pTimestampInfos,
                                                          uint64_t* pTimestamps, uint64_t* pMaxDeviation) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetCalibratedTimestampsEXT, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetCalibratedTimestampsEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps,
                                                                     pMaxDeviation, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetCalibratedTimestampsEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    }
    VkResult result = DispatchGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    RecordObject record_obj(vvl::Func::vkGetCalibratedTimestampsEXT, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetCalibratedTimestampsEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation,
                                                            record_obj);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(instance), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateHeadlessSurfaceEXT, VulkanTypedHandle(instance, kVulkanObjectTypeInstance));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    }
    VkResult result = DispatchCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    RecordObject record_obj(vvl::Func::vkCreateHeadlessSurfaceEXT, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface, record_obj);
    }
    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                uint16_t lineStipplePattern) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetLineStippleEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetLineStippleEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetLineStippleEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    }
    DispatchCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    RecordObject record_obj(vvl::Func::vkCmdSetLineStippleEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetLineStippleEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetCullModeEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetCullModeEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetCullModeEXT(commandBuffer, cullMode, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetCullModeEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetCullModeEXT(commandBuffer, cullMode);
    }
    DispatchCmdSetCullModeEXT(commandBuffer, cullMode);
    RecordObject record_obj(vvl::Func::vkCmdSetCullModeEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetCullModeEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetCullModeEXT(commandBuffer, cullMode, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetFrontFaceEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetFrontFaceEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetFrontFaceEXT(commandBuffer, frontFace, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetFrontFaceEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetFrontFaceEXT(commandBuffer, frontFace);
    }
    DispatchCmdSetFrontFaceEXT(commandBuffer, frontFace);
    RecordObject record_obj(vvl::Func::vkCmdSetFrontFaceEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetFrontFaceEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetFrontFaceEXT(commandBuffer, frontFace, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetPrimitiveTopologyEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetPrimitiveTopologyEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetPrimitiveTopologyEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
    }
    DispatchCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
    RecordObject record_obj(vvl::Func::vkCmdSetPrimitiveTopologyEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetPrimitiveTopologyEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                      const VkViewport* pViewports) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetViewportWithCountEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetViewportWithCountEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetViewportWithCountEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
    }
    DispatchCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
    RecordObject record_obj(vvl::Func::vkCmdSetViewportWithCountEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetViewportWithCountEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                     const VkRect2D* pScissors) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetScissorWithCountEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetScissorWithCountEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetScissorWithCountEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
    }
    DispatchCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
    RecordObject record_obj(vvl::Func::vkCmdSetScissorWithCountEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetScissorWithCountEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                                    const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                                    const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdBindVertexBuffers2EXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdBindVertexBuffers2EXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets,
                                                                   pSizes, pStrides, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdBindVertexBuffers2EXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                                         pStrides);
    }
    DispatchCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    RecordObject record_obj(vvl::Func::vkCmdBindVertexBuffers2EXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdBindVertexBuffers2EXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                                          pStrides, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthTestEnableEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthTestEnableEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthTestEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
    }
    DispatchCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetDepthTestEnableEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthTestEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthWriteEnableEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthWriteEnableEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthWriteEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
    }
    DispatchCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetDepthWriteEnableEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthWriteEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthCompareOpEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthCompareOpEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthCompareOpEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
    }
    DispatchCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
    RecordObject record_obj(vvl::Func::vkCmdSetDepthCompareOpEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthCompareOpEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthBoundsTestEnableEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthBoundsTestEnableEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthBoundsTestEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
    }
    DispatchCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetDepthBoundsTestEnableEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthBoundsTestEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilTestEnableEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilTestEnableEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilTestEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
    }
    DispatchCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetStencilTestEnableEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilTestEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                              VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetStencilOpEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetStencilOpEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp,
                                                             error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetStencilOpEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }
    DispatchCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    RecordObject record_obj(vvl::Func::vkCmdSetStencilOpEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetStencilOpEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                                const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                                uint32_t vertexAttributeDescriptionCount,
                                                const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetVertexInputEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetVertexInputEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount,
                                                               pVertexBindingDescriptions, vertexAttributeDescriptionCount,
                                                               pVertexAttributeDescriptions, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetVertexInputEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                                     vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    }
    DispatchCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                 vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    RecordObject record_obj(vvl::Func::vkCmdSetVertexInputEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetVertexInputEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                                      vertexAttributeDescriptionCount, pVertexAttributeDescriptions, record_obj);
    }
}

#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL GetFenceSciSyncFenceNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo,
                                                      void* pHandle) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetFenceSciSyncFenceNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetFenceSciSyncFenceNV]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetFenceSciSyncFenceNV(device, pGetSciSyncHandleInfo, pHandle, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetFenceSciSyncFenceNV]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetFenceSciSyncFenceNV(device, pGetSciSyncHandleInfo, pHandle);
    }
    VkResult result = DispatchGetFenceSciSyncFenceNV(device, pGetSciSyncHandleInfo, pHandle);
    RecordObject record_obj(vvl::Func::vkGetFenceSciSyncFenceNV, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetFenceSciSyncFenceNV]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetFenceSciSyncFenceNV(device, pGetSciSyncHandleInfo, pHandle, record_obj);
    }
    return result;
}

#endif
#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL GetFenceSciSyncObjNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo,
                                                    void* pHandle) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetFenceSciSyncObjNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetFenceSciSyncObjNV]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetFenceSciSyncObjNV(device, pGetSciSyncHandleInfo, pHandle, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetFenceSciSyncObjNV]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetFenceSciSyncObjNV(device, pGetSciSyncHandleInfo, pHandle);
    }
    VkResult result = DispatchGetFenceSciSyncObjNV(device, pGetSciSyncHandleInfo, pHandle);
    RecordObject record_obj(vvl::Func::vkGetFenceSciSyncObjNV, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetFenceSciSyncObjNV]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetFenceSciSyncObjNV(device, pGetSciSyncHandleInfo, pHandle, record_obj);
    }
    return result;
}

#endif
#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL ImportFenceSciSyncFenceNV(VkDevice device,
                                                         const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkImportFenceSciSyncFenceNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateImportFenceSciSyncFenceNV]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateImportFenceSciSyncFenceNV(device, pImportFenceSciSyncInfo, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordImportFenceSciSyncFenceNV]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordImportFenceSciSyncFenceNV(device, pImportFenceSciSyncInfo);
    }
    VkResult result = DispatchImportFenceSciSyncFenceNV(device, pImportFenceSciSyncInfo);
    RecordObject record_obj(vvl::Func::vkImportFenceSciSyncFenceNV, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordImportFenceSciSyncFenceNV]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordImportFenceSciSyncFenceNV(device, pImportFenceSciSyncInfo, record_obj);
    }
    return result;
}

#endif
#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL ImportFenceSciSyncObjNV(VkDevice device, const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkImportFenceSciSyncObjNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateImportFenceSciSyncObjNV]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateImportFenceSciSyncObjNV(device, pImportFenceSciSyncInfo, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordImportFenceSciSyncObjNV]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordImportFenceSciSyncObjNV(device, pImportFenceSciSyncInfo);
    }
    VkResult result = DispatchImportFenceSciSyncObjNV(device, pImportFenceSciSyncInfo);
    RecordObject record_obj(vvl::Func::vkImportFenceSciSyncObjNV, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordImportFenceSciSyncObjNV]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordImportFenceSciSyncObjNV(device, pImportFenceSciSyncInfo, record_obj);
    }
    return result;
}

#endif
#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSciSyncAttributesNV(VkPhysicalDevice physicalDevice,
                                                                    const VkSciSyncAttributesInfoNV* pSciSyncAttributesInfo,
                                                                    NvSciSyncAttrList pAttributes) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSciSyncAttributesNV,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceSciSyncAttributesNV(physicalDevice, pSciSyncAttributesInfo, pAttributes,
                                                                               error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceSciSyncAttributesNV(physicalDevice, pSciSyncAttributesInfo, pAttributes);
    }
    VkResult result = DispatchGetPhysicalDeviceSciSyncAttributesNV(physicalDevice, pSciSyncAttributesInfo, pAttributes);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSciSyncAttributesNV, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceSciSyncAttributesNV(physicalDevice, pSciSyncAttributesInfo, pAttributes,
                                                                      record_obj);
    }
    return result;
}

#endif
#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreSciSyncObjNV(VkDevice device, const VkSemaphoreGetSciSyncInfoNV* pGetSciSyncInfo,
                                                        void* pHandle) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetSemaphoreSciSyncObjNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetSemaphoreSciSyncObjNV]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetSemaphoreSciSyncObjNV(device, pGetSciSyncInfo, pHandle, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetSemaphoreSciSyncObjNV]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetSemaphoreSciSyncObjNV(device, pGetSciSyncInfo, pHandle);
    }
    VkResult result = DispatchGetSemaphoreSciSyncObjNV(device, pGetSciSyncInfo, pHandle);
    RecordObject record_obj(vvl::Func::vkGetSemaphoreSciSyncObjNV, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetSemaphoreSciSyncObjNV]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetSemaphoreSciSyncObjNV(device, pGetSciSyncInfo, pHandle, record_obj);
    }
    return result;
}

#endif
#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreSciSyncObjNV(VkDevice device,
                                                           const VkImportSemaphoreSciSyncInfoNV* pImportSemaphoreSciSyncInfo) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkImportSemaphoreSciSyncObjNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateImportSemaphoreSciSyncObjNV]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateImportSemaphoreSciSyncObjNV(device, pImportSemaphoreSciSyncInfo, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordImportSemaphoreSciSyncObjNV]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordImportSemaphoreSciSyncObjNV(device, pImportSemaphoreSciSyncInfo);
    }
    VkResult result = DispatchImportSemaphoreSciSyncObjNV(device, pImportSemaphoreSciSyncInfo);
    RecordObject record_obj(vvl::Func::vkImportSemaphoreSciSyncObjNV, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordImportSemaphoreSciSyncObjNV]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordImportSemaphoreSciSyncObjNV(device, pImportSemaphoreSciSyncInfo, record_obj);
    }
    return result;
}

#endif
#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL GetMemorySciBufNV(VkDevice device, const VkMemoryGetSciBufInfoNV* pGetSciBufInfo,
                                                 NvSciBufObj* pHandle) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetMemorySciBufNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateGetMemorySciBufNV]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetMemorySciBufNV(device, pGetSciBufInfo, pHandle, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetMemorySciBufNV]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetMemorySciBufNV(device, pGetSciBufInfo, pHandle);
    }
    VkResult result = DispatchGetMemorySciBufNV(device, pGetSciBufInfo, pHandle);
    RecordObject record_obj(vvl::Func::vkGetMemorySciBufNV, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetMemorySciBufNV]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetMemorySciBufNV(device, pGetSciBufInfo, pHandle, record_obj);
    }
    return result;
}

#endif
#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL
GetPhysicalDeviceExternalMemorySciBufPropertiesNV(VkPhysicalDevice physicalDevice, VkExternalMemoryHandleTypeFlagBits handleType,
                                                  NvSciBufObj handle, VkMemorySciBufPropertiesNV* pMemorySciBufProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceExternalMemorySciBufPropertiesNV(physicalDevice, handleType, handle,
                                                                                            pMemorySciBufProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceExternalMemorySciBufPropertiesNV(physicalDevice, handleType, handle,
                                                                                  pMemorySciBufProperties);
    }
    VkResult result =
        DispatchGetPhysicalDeviceExternalMemorySciBufPropertiesNV(physicalDevice, handleType, handle, pMemorySciBufProperties);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceExternalMemorySciBufPropertiesNV(physicalDevice, handleType, handle,
                                                                                   pMemorySciBufProperties, record_obj);
    }
    return result;
}

#endif
#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSciBufAttributesNV(VkPhysicalDevice physicalDevice, NvSciBufAttrList pAttributes) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(physicalDevice), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetPhysicalDeviceSciBufAttributesNV,
                          VulkanTypedHandle(physicalDevice, kVulkanObjectTypePhysicalDevice));
    for (const ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetPhysicalDeviceSciBufAttributesNV(physicalDevice, pAttributes, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetPhysicalDeviceSciBufAttributesNV(physicalDevice, pAttributes);
    }
    VkResult result = DispatchGetPhysicalDeviceSciBufAttributesNV(physicalDevice, pAttributes);
    RecordObject record_obj(vvl::Func::vkGetPhysicalDeviceSciBufAttributesNV, result);
    for (ValidationObject* intercept : layer_data->object_dispatch) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetPhysicalDeviceSciBufAttributesNV(physicalDevice, pAttributes, record_obj);
    }
    return result;
}

#endif
VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetPatchControlPointsEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetPatchControlPointsEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetPatchControlPointsEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
    }
    DispatchCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
    RecordObject record_obj(vvl::Func::vkCmdSetPatchControlPointsEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetPatchControlPointsEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetRasterizerDiscardEnableEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetRasterizerDiscardEnableEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetRasterizerDiscardEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
    }
    DispatchCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetRasterizerDiscardEnableEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetRasterizerDiscardEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetDepthBiasEnableEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetDepthBiasEnableEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetDepthBiasEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
    }
    DispatchCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetDepthBiasEnableEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetDepthBiasEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetLogicOpEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetLogicOpEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetLogicOpEXT(commandBuffer, logicOp, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetLogicOpEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetLogicOpEXT(commandBuffer, logicOp);
    }
    DispatchCmdSetLogicOpEXT(commandBuffer, logicOp);
    RecordObject record_obj(vvl::Func::vkCmdSetLogicOpEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetLogicOpEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetLogicOpEXT(commandBuffer, logicOp, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetPrimitiveRestartEnableEXT,
                          VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetPrimitiveRestartEnableEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetPrimitiveRestartEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
    }
    DispatchCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
    RecordObject record_obj(vvl::Func::vkCmdSetPrimitiveRestartEnableEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetPrimitiveRestartEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable, record_obj);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                     const VkBool32* pColorWriteEnables) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(commandBuffer), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCmdSetColorWriteEnableEXT, VulkanTypedHandle(commandBuffer, kVulkanObjectTypeCommandBuffer));
    for (const ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallValidateCmdSetColorWriteEnableEXT]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables, error_obj);
        if (skip) return;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCmdSetColorWriteEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
    }
    DispatchCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
    RecordObject record_obj(vvl::Func::vkCmdSetColorWriteEnableEXT);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCmdSetColorWriteEnableEXT]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables, record_obj);
    }
}

#ifdef VK_USE_PLATFORM_SCI
VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphoreSciSyncPoolNV(VkDevice device, const VkSemaphoreSciSyncPoolCreateInfoNV* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            VkSemaphoreSciSyncPoolNV* pSemaphorePool) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkCreateSemaphoreSciSyncPoolNV, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateCreateSemaphoreSciSyncPoolNV]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateCreateSemaphoreSciSyncPoolNV(device, pCreateInfo, pAllocator, pSemaphorePool, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordCreateSemaphoreSciSyncPoolNV]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordCreateSemaphoreSciSyncPoolNV(device, pCreateInfo, pAllocator, pSemaphorePool);
    }
    VkResult result = DispatchCreateSemaphoreSciSyncPoolNV(device, pCreateInfo, pAllocator, pSemaphorePool);
    RecordObject record_obj(vvl::Func::vkCreateSemaphoreSciSyncPoolNV, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordCreateSemaphoreSciSyncPoolNV]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordCreateSemaphoreSciSyncPoolNV(device, pCreateInfo, pAllocator, pSemaphorePool, record_obj);
    }
    return result;
}

#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
VKAPI_ATTR VkResult VKAPI_CALL GetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer,
                                                            VkScreenBufferPropertiesQNX* pProperties) {
    auto layer_data = GetLayerDataPtr(get_dispatch_key(device), layer_data_map);
    bool skip = false;
    ErrorObject error_obj(vvl::Func::vkGetScreenBufferPropertiesQNX, VulkanTypedHandle(device, kVulkanObjectTypeDevice));
    for (const ValidationObject* intercept :
         layer_data->intercept_vectors[InterceptIdPreCallValidateGetScreenBufferPropertiesQNX]) {
        auto lock = intercept->ReadLock();
        skip |= intercept->PreCallValidateGetScreenBufferPropertiesQNX(device, buffer, pProperties, error_obj);
        if (skip) return VK_ERROR_VALIDATION_FAILED_EXT;
    }
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPreCallRecordGetScreenBufferPropertiesQNX]) {
        auto lock = intercept->WriteLock();
        intercept->PreCallRecordGetScreenBufferPropertiesQNX(device, buffer, pProperties);
    }
    VkResult result = DispatchGetScreenBufferPropertiesQNX(device, buffer, pProperties);
    RecordObject record_obj(vvl::Func::vkGetScreenBufferPropertiesQNX, result);
    for (ValidationObject* intercept : layer_data->intercept_vectors[InterceptIdPostCallRecordGetScreenBufferPropertiesQNX]) {
        auto lock = intercept->WriteLock();
        intercept->PostCallRecordGetScreenBufferPropertiesQNX(device, buffer, pProperties, record_obj);
    }
    return result;
}

#endif

// Map of intercepted ApiName to its associated function data
#ifdef _MSC_VER
#pragma warning(suppress : 6262)  // VS analysis: this uses more than 16 kiB, which is fine here at global scope
#endif
// clang-format off
const vvl::unordered_map<std::string, function_data> name_to_funcptr_map = {
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
    {"vkCreateEvent", {kFuncTypeDev, (void*)CreateEvent}},
    {"vkDestroyEvent", {kFuncTypeDev, (void*)DestroyEvent}},
    {"vkGetEventStatus", {kFuncTypeDev, (void*)GetEventStatus}},
    {"vkSetEvent", {kFuncTypeDev, (void*)SetEvent}},
    {"vkResetEvent", {kFuncTypeDev, (void*)ResetEvent}},
    {"vkCreateQueryPool", {kFuncTypeDev, (void*)CreateQueryPool}},
    {"vkGetQueryPoolResults", {kFuncTypeDev, (void*)GetQueryPoolResults}},
    {"vkCreateBuffer", {kFuncTypeDev, (void*)CreateBuffer}},
    {"vkDestroyBuffer", {kFuncTypeDev, (void*)DestroyBuffer}},
    {"vkCreateBufferView", {kFuncTypeDev, (void*)CreateBufferView}},
    {"vkDestroyBufferView", {kFuncTypeDev, (void*)DestroyBufferView}},
    {"vkCreateImage", {kFuncTypeDev, (void*)CreateImage}},
    {"vkDestroyImage", {kFuncTypeDev, (void*)DestroyImage}},
    {"vkGetImageSubresourceLayout", {kFuncTypeDev, (void*)GetImageSubresourceLayout}},
    {"vkCreateImageView", {kFuncTypeDev, (void*)CreateImageView}},
    {"vkDestroyImageView", {kFuncTypeDev, (void*)DestroyImageView}},
    {"vkCreatePipelineCache", {kFuncTypeDev, (void*)CreatePipelineCache}},
    {"vkDestroyPipelineCache", {kFuncTypeDev, (void*)DestroyPipelineCache}},
    {"vkCreateGraphicsPipelines", {kFuncTypeDev, (void*)CreateGraphicsPipelines}},
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
    {"vkCreateFramebuffer", {kFuncTypeDev, (void*)CreateFramebuffer}},
    {"vkDestroyFramebuffer", {kFuncTypeDev, (void*)DestroyFramebuffer}},
    {"vkCreateRenderPass", {kFuncTypeDev, (void*)CreateRenderPass}},
    {"vkDestroyRenderPass", {kFuncTypeDev, (void*)DestroyRenderPass}},
    {"vkGetRenderAreaGranularity", {kFuncTypeDev, (void*)GetRenderAreaGranularity}},
    {"vkCreateCommandPool", {kFuncTypeDev, (void*)CreateCommandPool}},
    {"vkResetCommandPool", {kFuncTypeDev, (void*)ResetCommandPool}},
    {"vkAllocateCommandBuffers", {kFuncTypeDev, (void*)AllocateCommandBuffers}},
    {"vkFreeCommandBuffers", {kFuncTypeDev, (void*)FreeCommandBuffers}},
    {"vkBeginCommandBuffer", {kFuncTypeDev, (void*)BeginCommandBuffer}},
    {"vkEndCommandBuffer", {kFuncTypeDev, (void*)EndCommandBuffer}},
    {"vkResetCommandBuffer", {kFuncTypeDev, (void*)ResetCommandBuffer}},
    {"vkCmdBindPipeline", {kFuncTypeDev, (void*)CmdBindPipeline}},
    {"vkCmdSetViewport", {kFuncTypeDev, (void*)CmdSetViewport}},
    {"vkCmdSetScissor", {kFuncTypeDev, (void*)CmdSetScissor}},
    {"vkCmdSetLineWidth", {kFuncTypeDev, (void*)CmdSetLineWidth}},
    {"vkCmdSetDepthBias", {kFuncTypeDev, (void*)CmdSetDepthBias}},
    {"vkCmdSetBlendConstants", {kFuncTypeDev, (void*)CmdSetBlendConstants}},
    {"vkCmdSetDepthBounds", {kFuncTypeDev, (void*)CmdSetDepthBounds}},
    {"vkCmdSetStencilCompareMask", {kFuncTypeDev, (void*)CmdSetStencilCompareMask}},
    {"vkCmdSetStencilWriteMask", {kFuncTypeDev, (void*)CmdSetStencilWriteMask}},
    {"vkCmdSetStencilReference", {kFuncTypeDev, (void*)CmdSetStencilReference}},
    {"vkCmdBindDescriptorSets", {kFuncTypeDev, (void*)CmdBindDescriptorSets}},
    {"vkCmdBindIndexBuffer", {kFuncTypeDev, (void*)CmdBindIndexBuffer}},
    {"vkCmdBindVertexBuffers", {kFuncTypeDev, (void*)CmdBindVertexBuffers}},
    {"vkCmdDraw", {kFuncTypeDev, (void*)CmdDraw}},
    {"vkCmdDrawIndexed", {kFuncTypeDev, (void*)CmdDrawIndexed}},
    {"vkCmdDrawIndirect", {kFuncTypeDev, (void*)CmdDrawIndirect}},
    {"vkCmdDrawIndexedIndirect", {kFuncTypeDev, (void*)CmdDrawIndexedIndirect}},
    {"vkCmdDispatch", {kFuncTypeDev, (void*)CmdDispatch}},
    {"vkCmdDispatchIndirect", {kFuncTypeDev, (void*)CmdDispatchIndirect}},
    {"vkCmdCopyBuffer", {kFuncTypeDev, (void*)CmdCopyBuffer}},
    {"vkCmdCopyImage", {kFuncTypeDev, (void*)CmdCopyImage}},
    {"vkCmdBlitImage", {kFuncTypeDev, (void*)CmdBlitImage}},
    {"vkCmdCopyBufferToImage", {kFuncTypeDev, (void*)CmdCopyBufferToImage}},
    {"vkCmdCopyImageToBuffer", {kFuncTypeDev, (void*)CmdCopyImageToBuffer}},
    {"vkCmdUpdateBuffer", {kFuncTypeDev, (void*)CmdUpdateBuffer}},
    {"vkCmdFillBuffer", {kFuncTypeDev, (void*)CmdFillBuffer}},
    {"vkCmdClearColorImage", {kFuncTypeDev, (void*)CmdClearColorImage}},
    {"vkCmdClearDepthStencilImage", {kFuncTypeDev, (void*)CmdClearDepthStencilImage}},
    {"vkCmdClearAttachments", {kFuncTypeDev, (void*)CmdClearAttachments}},
    {"vkCmdResolveImage", {kFuncTypeDev, (void*)CmdResolveImage}},
    {"vkCmdSetEvent", {kFuncTypeDev, (void*)CmdSetEvent}},
    {"vkCmdResetEvent", {kFuncTypeDev, (void*)CmdResetEvent}},
    {"vkCmdWaitEvents", {kFuncTypeDev, (void*)CmdWaitEvents}},
    {"vkCmdPipelineBarrier", {kFuncTypeDev, (void*)CmdPipelineBarrier}},
    {"vkCmdBeginQuery", {kFuncTypeDev, (void*)CmdBeginQuery}},
    {"vkCmdEndQuery", {kFuncTypeDev, (void*)CmdEndQuery}},
    {"vkCmdResetQueryPool", {kFuncTypeDev, (void*)CmdResetQueryPool}},
    {"vkCmdWriteTimestamp", {kFuncTypeDev, (void*)CmdWriteTimestamp}},
    {"vkCmdCopyQueryPoolResults", {kFuncTypeDev, (void*)CmdCopyQueryPoolResults}},
    {"vkCmdPushConstants", {kFuncTypeDev, (void*)CmdPushConstants}},
    {"vkCmdBeginRenderPass", {kFuncTypeDev, (void*)CmdBeginRenderPass}},
    {"vkCmdNextSubpass", {kFuncTypeDev, (void*)CmdNextSubpass}},
    {"vkCmdEndRenderPass", {kFuncTypeDev, (void*)CmdEndRenderPass}},
    {"vkCmdExecuteCommands", {kFuncTypeDev, (void*)CmdExecuteCommands}},
    {"vkBindBufferMemory2", {kFuncTypeDev, (void*)BindBufferMemory2}},
    {"vkBindImageMemory2", {kFuncTypeDev, (void*)BindImageMemory2}},
    {"vkGetDeviceGroupPeerMemoryFeatures", {kFuncTypeDev, (void*)GetDeviceGroupPeerMemoryFeatures}},
    {"vkCmdSetDeviceMask", {kFuncTypeDev, (void*)CmdSetDeviceMask}},
    {"vkCmdDispatchBase", {kFuncTypeDev, (void*)CmdDispatchBase}},
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
    {"vkCreateSamplerYcbcrConversion", {kFuncTypeDev, (void*)CreateSamplerYcbcrConversion}},
    {"vkDestroySamplerYcbcrConversion", {kFuncTypeDev, (void*)DestroySamplerYcbcrConversion}},
    {"vkGetPhysicalDeviceExternalBufferProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceExternalBufferProperties}},
    {"vkGetPhysicalDeviceExternalFenceProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceExternalFenceProperties}},
    {"vkGetPhysicalDeviceExternalSemaphoreProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceExternalSemaphoreProperties}},
    {"vkGetDescriptorSetLayoutSupport", {kFuncTypeDev, (void*)GetDescriptorSetLayoutSupport}},
    {"vkCmdDrawIndirectCount", {kFuncTypeDev, (void*)CmdDrawIndirectCount}},
    {"vkCmdDrawIndexedIndirectCount", {kFuncTypeDev, (void*)CmdDrawIndexedIndirectCount}},
    {"vkCreateRenderPass2", {kFuncTypeDev, (void*)CreateRenderPass2}},
    {"vkCmdBeginRenderPass2", {kFuncTypeDev, (void*)CmdBeginRenderPass2}},
    {"vkCmdNextSubpass2", {kFuncTypeDev, (void*)CmdNextSubpass2}},
    {"vkCmdEndRenderPass2", {kFuncTypeDev, (void*)CmdEndRenderPass2}},
    {"vkResetQueryPool", {kFuncTypeDev, (void*)ResetQueryPool}},
    {"vkGetSemaphoreCounterValue", {kFuncTypeDev, (void*)GetSemaphoreCounterValue}},
    {"vkWaitSemaphores", {kFuncTypeDev, (void*)WaitSemaphores}},
    {"vkSignalSemaphore", {kFuncTypeDev, (void*)SignalSemaphore}},
    {"vkGetBufferDeviceAddress", {kFuncTypeDev, (void*)GetBufferDeviceAddress}},
    {"vkGetBufferOpaqueCaptureAddress", {kFuncTypeDev, (void*)GetBufferOpaqueCaptureAddress}},
    {"vkGetDeviceMemoryOpaqueCaptureAddress", {kFuncTypeDev, (void*)GetDeviceMemoryOpaqueCaptureAddress}},
    {"vkGetPhysicalDeviceToolProperties", {kFuncTypePdev, (void*)GetPhysicalDeviceToolProperties}},
    {"vkCreatePrivateDataSlot", {kFuncTypeDev, (void*)CreatePrivateDataSlot}},
    {"vkDestroyPrivateDataSlot", {kFuncTypeDev, (void*)DestroyPrivateDataSlot}},
    {"vkSetPrivateData", {kFuncTypeDev, (void*)SetPrivateData}},
    {"vkGetPrivateData", {kFuncTypeDev, (void*)GetPrivateData}},
    {"vkCmdSetEvent2", {kFuncTypeDev, (void*)CmdSetEvent2}},
    {"vkCmdResetEvent2", {kFuncTypeDev, (void*)CmdResetEvent2}},
    {"vkCmdWaitEvents2", {kFuncTypeDev, (void*)CmdWaitEvents2}},
    {"vkCmdPipelineBarrier2", {kFuncTypeDev, (void*)CmdPipelineBarrier2}},
    {"vkCmdWriteTimestamp2", {kFuncTypeDev, (void*)CmdWriteTimestamp2}},
    {"vkQueueSubmit2", {kFuncTypeDev, (void*)QueueSubmit2}},
    {"vkCmdCopyBuffer2", {kFuncTypeDev, (void*)CmdCopyBuffer2}},
    {"vkCmdCopyImage2", {kFuncTypeDev, (void*)CmdCopyImage2}},
    {"vkCmdCopyBufferToImage2", {kFuncTypeDev, (void*)CmdCopyBufferToImage2}},
    {"vkCmdCopyImageToBuffer2", {kFuncTypeDev, (void*)CmdCopyImageToBuffer2}},
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
    {"vkGetDeviceBufferMemoryRequirements", {kFuncTypeDev, (void*)GetDeviceBufferMemoryRequirements}},
    {"vkGetDeviceImageMemoryRequirements", {kFuncTypeDev, (void*)GetDeviceImageMemoryRequirements}},
    {"vkGetDeviceImageSparseMemoryRequirements", {kFuncTypeDev, (void*)GetDeviceImageSparseMemoryRequirements}},
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
    {"vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", {kFuncTypePdev, (void*)EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR}},
    {"vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", {kFuncTypePdev, (void*)GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR}},
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
    {"vkCmdWriteBufferMarker2AMD", {kFuncTypeDev, (void*)CmdWriteBufferMarker2AMD}},
    {"vkGetQueueCheckpointData2NV", {kFuncTypeDev, (void*)GetQueueCheckpointData2NV}},
    {"vkCmdCopyBuffer2KHR", {kFuncTypeDev, (void*)CmdCopyBuffer2KHR}},
    {"vkCmdCopyImage2KHR", {kFuncTypeDev, (void*)CmdCopyImage2KHR}},
    {"vkCmdCopyBufferToImage2KHR", {kFuncTypeDev, (void*)CmdCopyBufferToImage2KHR}},
    {"vkCmdCopyImageToBuffer2KHR", {kFuncTypeDev, (void*)CmdCopyImageToBuffer2KHR}},
    {"vkCmdBlitImage2KHR", {kFuncTypeDev, (void*)CmdBlitImage2KHR}},
    {"vkCmdResolveImage2KHR", {kFuncTypeDev, (void*)CmdResolveImage2KHR}},
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
    {"vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", {kFuncTypePdev, (void*)GetPhysicalDeviceCalibrateableTimeDomainsEXT}},
    {"vkGetCalibratedTimestampsEXT", {kFuncTypeDev, (void*)GetCalibratedTimestampsEXT}},
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
    {"vkCmdSetVertexInputEXT", {kFuncTypeDev, (void*)CmdSetVertexInputEXT}},
#ifdef VK_USE_PLATFORM_SCI
    {"vkGetFenceSciSyncFenceNV", {kFuncTypeDev, (void*)GetFenceSciSyncFenceNV}},
#endif
#ifdef VK_USE_PLATFORM_SCI
    {"vkGetFenceSciSyncObjNV", {kFuncTypeDev, (void*)GetFenceSciSyncObjNV}},
#endif
#ifdef VK_USE_PLATFORM_SCI
    {"vkImportFenceSciSyncFenceNV", {kFuncTypeDev, (void*)ImportFenceSciSyncFenceNV}},
#endif
#ifdef VK_USE_PLATFORM_SCI
    {"vkImportFenceSciSyncObjNV", {kFuncTypeDev, (void*)ImportFenceSciSyncObjNV}},
#endif
#ifdef VK_USE_PLATFORM_SCI
    {"vkGetPhysicalDeviceSciSyncAttributesNV", {kFuncTypePdev, (void*)GetPhysicalDeviceSciSyncAttributesNV}},
#endif
#ifdef VK_USE_PLATFORM_SCI
    {"vkGetSemaphoreSciSyncObjNV", {kFuncTypeDev, (void*)GetSemaphoreSciSyncObjNV}},
#endif
#ifdef VK_USE_PLATFORM_SCI
    {"vkImportSemaphoreSciSyncObjNV", {kFuncTypeDev, (void*)ImportSemaphoreSciSyncObjNV}},
#endif
#ifdef VK_USE_PLATFORM_SCI
    {"vkGetMemorySciBufNV", {kFuncTypeDev, (void*)GetMemorySciBufNV}},
#endif
#ifdef VK_USE_PLATFORM_SCI
    {"vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV", {kFuncTypePdev, (void*)GetPhysicalDeviceExternalMemorySciBufPropertiesNV}},
#endif
#ifdef VK_USE_PLATFORM_SCI
    {"vkGetPhysicalDeviceSciBufAttributesNV", {kFuncTypePdev, (void*)GetPhysicalDeviceSciBufAttributesNV}},
#endif
    {"vkCmdSetPatchControlPointsEXT", {kFuncTypeDev, (void*)CmdSetPatchControlPointsEXT}},
    {"vkCmdSetRasterizerDiscardEnableEXT", {kFuncTypeDev, (void*)CmdSetRasterizerDiscardEnableEXT}},
    {"vkCmdSetDepthBiasEnableEXT", {kFuncTypeDev, (void*)CmdSetDepthBiasEnableEXT}},
    {"vkCmdSetLogicOpEXT", {kFuncTypeDev, (void*)CmdSetLogicOpEXT}},
    {"vkCmdSetPrimitiveRestartEnableEXT", {kFuncTypeDev, (void*)CmdSetPrimitiveRestartEnableEXT}},
    {"vkCmdSetColorWriteEnableEXT", {kFuncTypeDev, (void*)CmdSetColorWriteEnableEXT}},
#ifdef VK_USE_PLATFORM_SCI
    {"vkCreateSemaphoreSciSyncPoolNV", {kFuncTypeDev, (void*)CreateSemaphoreSciSyncPoolNV}},
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    {"vkGetScreenBufferPropertiesQNX", {kFuncTypeDev, (void*)GetScreenBufferPropertiesQNX}},
#endif
};
} // namespace vulkan_layer_chassis
// clang-format on

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
        pVersionStruct->pfnGetInstanceProcAddr = vkGetInstanceProcAddr;
        pVersionStruct->pfnGetDeviceProcAddr = vkGetDeviceProcAddr;
        pVersionStruct->pfnGetPhysicalDeviceProcAddr = vk_layerGetPhysicalDeviceProcAddr;
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
