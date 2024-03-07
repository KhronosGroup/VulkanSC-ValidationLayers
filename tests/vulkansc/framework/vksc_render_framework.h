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
                           const char *pshader, std::vector<uint32_t> &spv, const spv_target_env spv_env = SPV_ENV_VULKAN_1_0) override;
    virtual bool ASMtoSPV(const spv_target_env target_env, const uint32_t options, const char *pasm,
                          std::vector<uint32_t> &spv) override;

    virtual ~VkSCRenderFramework() override;

    void InitFramework(void *instance_pnext = NULL);
    void InitState(VkPhysicalDeviceFeatures *features = nullptr, void *create_device_pnext = nullptr,
                   const VkCommandPoolCreateFlags flags = 0);

    VkPipelineCache GetDefaultPipelineCache();

    static VkPhysicalDeviceVulkanSC10Features GetVulkanSC10Features(VkPhysicalDevice phys_dev);
    static VkPhysicalDeviceVulkanSC10Properties GetVulkanSC10Properties(VkPhysicalDevice phys_dev);

    template <typename T>
    T GetVulkanFeatures() const {
        auto features = vku::InitStruct<T>();
        auto features2 = vku::InitStruct<VkPhysicalDeviceFeatures2>(&features);
        vksc::GetPhysicalDeviceFeatures2(gpu(), &features2);
        return features;
    }

    template <typename T>
    T GetVulkanProperties() const {
        auto props = vku::InitStruct<T>();
        auto props2 = vku::InitStruct<VkPhysicalDeviceProperties2>(&props);
        vksc::GetPhysicalDeviceProperties2(gpu(), &props2);
        return props;
    }

  private:
    VkPipelineCache default_pipeline_cache_{VK_NULL_HANDLE};
};

// Render framework used by compatible Vulkan tests
class VkSCCompatibilityRenderFramework : public VkSCRenderFramework {
  public:
    virtual bool GLSLtoSPV(VkPhysicalDeviceLimits const *const device_limits, const VkShaderStageFlagBits shader_type,
                           const char *pshader, std::vector<uint32_t> &spv, const spv_target_env spv_env = SPV_ENV_VULKAN_1_0) override;
    virtual bool ASMtoSPV(const spv_target_env target_env, const uint32_t options, const char *pasm,
                          std::vector<uint32_t> &spv) override;

    VkSCCompatibilityRenderFramework();
    virtual ~VkSCCompatibilityRenderFramework() override;

    void InitFramework(void *instance_pnext = NULL);
    void InitState(VkPhysicalDeviceFeatures *features = nullptr, void *create_device_pnext = nullptr,
                   const VkCommandPoolCreateFlags flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);

    static VkSCCompatibilityRenderFramework &RenderFrameworkInstance() {
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
