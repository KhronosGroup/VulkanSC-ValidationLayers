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

VkSCRenderFramework::VkSCRenderFramework() : dispatch_helper_(this) {
    assert(s_instance == nullptr);
    s_instance = this;
}

VkSCRenderFramework::~VkSCRenderFramework() {
    if (m_device != nullptr && m_device->handle() != VK_NULL_HANDLE) {
        vksc::DestroyPipelineCache(m_device->handle(), default_pipeline_cache_, nullptr);
    }

    assert(s_instance == this);
    s_instance = nullptr;
}

VkPipelineCache VkSCRenderFramework::GetDefaultPipelineCache() {
    if (default_pipeline_cache_ == VK_NULL_HANDLE) {
        vksc::CreatePipelineCache(m_device->handle(), &vksc::GetDefaultPipelineCacheCreateInfo(), nullptr,
                                  &default_pipeline_cache_);
    }
    return default_pipeline_cache_;
}

bool VkSCRenderFramework::GLSLtoSPV(VkPhysicalDeviceLimits const *const device_limits, const VkShaderStageFlagBits shader_type,
                                        const char *pshader, std::vector<uint32_t> &spv, bool debug, const spv_target_env spv_env) {
    if (IsPlatform(kMockICD)) {
        // For mock ICD runs we simply skip shader compilation as it won't affect test execution
        return true;
    } else {
        // We don't currently support shader-based test cases on real Vulkan SC drivers
        assert(false);
        return false;
    }
}

bool VkSCRenderFramework::ASMtoSPV(const spv_target_env target_env, const uint32_t options, const char *pasm,
                                       std::vector<uint32_t> &spv) {
    if (IsPlatform(kMockICD)) {
        // For mock ICD runs we simply skip shader compilation as it won't affect test execution
        return true;
    } else {
        // We don't currently support shader-based test cases on real Vulkan SC drivers
        assert(false);
        return false;
    }
}
