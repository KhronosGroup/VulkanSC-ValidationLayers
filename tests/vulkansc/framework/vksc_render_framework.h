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
#pragma once

#include "../../framework/render.h"
#include "vksc_test_dispatch_helper.h"

// Render framework used by Vulkan SC tests
class VkSCRenderFramework : public VkRenderFramework {
  public:
    virtual bool GLSLtoSPV(VkPhysicalDeviceLimits const *const device_limits, const VkShaderStageFlagBits shader_type,
                           const char *pshader, std::vector<uint32_t> &spv, bool debug = false,
                           const spv_target_env spv_env = SPV_ENV_VULKAN_1_0) override;
    virtual bool ASMtoSPV(const spv_target_env target_env, const uint32_t options, const char *pasm,
                          std::vector<uint32_t> &spv) override;

    virtual ~VkSCRenderFramework() override;

    void InitFramework(void * /*unused compatibility parameter*/ = NULL, void *instance_pnext = NULL);

    VkPipelineCache GetDefaultPipelineCache();

  private:
    VkPipelineCache default_pipeline_cache_{VK_NULL_HANDLE};
};

// Render framework used by compatible Vulkan tests
class VkSCCompatibilityRenderFramework : public VkSCRenderFramework {
  public:
    virtual bool GLSLtoSPV(VkPhysicalDeviceLimits const *const device_limits, const VkShaderStageFlagBits shader_type,
                           const char *pshader, std::vector<uint32_t> &spv, bool debug = false,
                           const spv_target_env spv_env = SPV_ENV_VULKAN_1_0) override;
    virtual bool ASMtoSPV(const spv_target_env target_env, const uint32_t options, const char *pasm,
                          std::vector<uint32_t> &spv) override;

    VkSCCompatibilityRenderFramework();
    virtual ~VkSCCompatibilityRenderFramework() override;

    void InitFramework(void * /*unused compatibility parameter*/ = NULL, void *instance_pnext = NULL);
    void InitState(VkPhysicalDeviceFeatures *features = nullptr, void *create_device_pnext = nullptr,
                   const VkCommandPoolCreateFlags flags = 0);

    static VkSCCompatibilityRenderFramework &Instance() {
        assert(s_instance != nullptr);
        return *s_instance;
    }

    static vksc::TestDispatchHelper *DispatchHelper() {
        if (s_instance != nullptr) {
            return &s_instance->dispatch_helper_;
        } else {
            return nullptr;
        }
    }

  private:
    vksc::TestDispatchHelper dispatch_helper_;

    inline static VkSCCompatibilityRenderFramework *s_instance{nullptr};
};
