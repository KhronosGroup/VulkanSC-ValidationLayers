/*
 * Copyright (c) 2023-2023 The Khronos Group Inc.
 * Copyright (c) 2023-2023 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#include "vksc_render_framework.h"
#include "vksc_test_pipeline_cache_helper.h"

VkSCRenderFramework::~VkSCRenderFramework() {
    if (m_device != nullptr && m_device->handle() != VK_NULL_HANDLE) {
        vksc::DestroyPipelineCache(m_device->handle(), default_pipeline_cache_, nullptr);
    }
}

void VkSCRenderFramework::InitFramework(void *instance_pnext) {
    if (InstanceLayerSupported("VK_LAYER_KHRONOS_device_simulation") && getenv("VKSC_DEVSIM_PROFILE_FILE")) {
        instance_layers_.push_back("VK_LAYER_KHRONOS_device_simulation");
    }

    VkRenderFramework::InitFramework(instance_pnext);
}

void VkSCRenderFramework::InitState(VkPhysicalDeviceFeatures *features, void *create_device_pnext,
                                    const VkCommandPoolCreateFlags flags) {
    VkRenderFramework::InitState(features, create_device_pnext, flags);
}

VkPipelineCache VkSCRenderFramework::GetDefaultPipelineCache() {
    if (default_pipeline_cache_ == VK_NULL_HANDLE) {
        vksc::CreatePipelineCache(m_device->handle(), &vksc::GetDefaultPipelineCacheCreateInfo(), nullptr,
                                  &default_pipeline_cache_);
    }
    return default_pipeline_cache_;
}

VkPhysicalDeviceVulkanSC10Features VkSCRenderFramework::GetVulkanSC10Features(VkPhysicalDevice phys_dev) {
    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto features2 = vku::InitStruct<VkPhysicalDeviceFeatures2>(&sc_10_features);
    vksc::GetPhysicalDeviceFeatures2(phys_dev, &features2);
    return sc_10_features;
}

VkPhysicalDeviceVulkanSC10Properties VkSCRenderFramework::GetVulkanSC10Properties(VkPhysicalDevice phys_dev) {
    auto sc_10_props = vku::InitStruct<VkPhysicalDeviceVulkanSC10Properties>();
    auto props2 = vku::InitStruct<VkPhysicalDeviceProperties2>(&sc_10_props);
    vksc::GetPhysicalDeviceProperties2(phys_dev, &props2);
    return sc_10_props;
}

bool VkSCRenderFramework::GLSLtoSPV(VkPhysicalDeviceLimits const *const device_limits, const VkShaderStageFlagBits shader_type,
                                        const char *pshader, std::vector<uint32_t> &spv, bool debug, const spv_target_env spv_env) {
    // Vulkan SC tests should never call this
    assert(false);
    return false;
}

bool VkSCRenderFramework::ASMtoSPV(const spv_target_env target_env, const uint32_t options, const char *pasm,
                                   std::vector<uint32_t> &spv) {
    // Vulkan SC tests should never call this
    assert(false);
    return false;
}

VkSCCompatibilityRenderFramework::VkSCCompatibilityRenderFramework() : VkSCRenderFramework(), dispatch_helper_(this) {
    assert(s_instance == nullptr);
    s_instance = this;
}

VkSCCompatibilityRenderFramework::~VkSCCompatibilityRenderFramework() {
    assert(s_instance == this);
    s_instance = nullptr;
}

void VkSCCompatibilityRenderFramework::InitFramework(void *instance_pnext) { VkSCRenderFramework::InitFramework(instance_pnext); }

void VkSCCompatibilityRenderFramework::InitState(VkPhysicalDeviceFeatures *features, void *create_device_pnext,
                                                 const VkCommandPoolCreateFlags flags) {
    VkSCRenderFramework::InitState(features, create_device_pnext, flags);
}

bool VkSCCompatibilityRenderFramework::GLSLtoSPV(VkPhysicalDeviceLimits const *const device_limits,
                                                 const VkShaderStageFlagBits shader_type, const char *pshader,
                                                 std::vector<uint32_t> &spv, bool debug, const spv_target_env spv_env) {
    if (IsPlatformMockICD()) {
        // For mock ICD runs we simply skip shader compilation as it won't affect test execution
        return true;
    } else {
        // We don't currently support shader-based test cases on real Vulkan SC drivers
        assert(false);
        return false;
    }
}

bool VkSCCompatibilityRenderFramework::ASMtoSPV(const spv_target_env target_env, const uint32_t options, const char *pasm,
                                                std::vector<uint32_t> &spv) {
    if (IsPlatformMockICD()) {
        // For mock ICD runs we simply skip shader compilation as it won't affect test execution
        return true;
    } else {
        // We don't currently support shader-based test cases on real Vulkan SC drivers
        assert(false);
        return false;
    }
}
