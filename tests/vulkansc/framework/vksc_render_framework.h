/*
 * Copyright (c) 2023-2024 The Khronos Group Inc.
 * Copyright (c) 2023-2024 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */
#pragma once

#include "../../framework/render.h"
#include "vksc_test_environment.h"
#include "vksc_test_dispatch_helper.h"
#include "vksc_test_pipeline_cache_helper.h"

namespace vksc {
class PipelineCache;
}  // namespace vksc

// Render framework used by Vulkan SC tests
class VkSCRenderFramework : public VkRenderFramework {
  public:
    VkSCRenderFramework() : VkRenderFramework(), object_reservation_info_(vksc::GetDefaultObjectReservationCreateInfo()) {}
    virtual ~VkSCRenderFramework() override;

    void InitFramework(void *instance_pnext = NULL);
    void InitState(VkPhysicalDeviceFeatures *features = nullptr, void *create_device_pnext = nullptr,
                   const VkCommandPoolCreateFlags flags = 0);

    VkPipelineCache GetDefaultPipelineCache();

    VkPhysicalDeviceVulkanSC10Features GetVulkanSC10Features() const {
        auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
        auto features2 = vku::InitStruct<VkPhysicalDeviceFeatures2>(&sc_10_features);
        vksc::GetPhysicalDeviceFeatures2(gpu(), &features2);
        return sc_10_features;
    }

    VkPhysicalDeviceVulkanSC10Properties GetVulkanSC10Properties() const {
        auto sc_10_props = vku::InitStruct<VkPhysicalDeviceVulkanSC10Properties>();
        auto props2 = vku::InitStruct<VkPhysicalDeviceProperties2>(&sc_10_props);
        vksc::GetPhysicalDeviceProperties2(gpu(), &props2);
        return sc_10_props;
    }

    VkPhysicalDeviceFeatures GetVulkanFeatures() const {
        VkPhysicalDeviceFeatures features;
        vksc::GetPhysicalDeviceFeatures(gpu(), &features);
        return features;
    }

    VkPhysicalDeviceProperties GetVulkanProperties() const {
        VkPhysicalDeviceProperties props;
        vksc::GetPhysicalDeviceProperties(gpu(), &props);
        return props;
    }

    template <typename T>
    T GetFeatures() const {
        auto features = vku::InitStruct<T>();
        auto features2 = vku::InitStruct<VkPhysicalDeviceFeatures2>(&features);
        vksc::GetPhysicalDeviceFeatures2(gpu(), &features2);
        return features;
    }

    template <typename T>
    T GetProperties() const {
        auto props = vku::InitStruct<T>();
        auto props2 = vku::InitStruct<VkPhysicalDeviceProperties2>(&props);
        vksc::GetPhysicalDeviceProperties2(gpu(), &props2);
        return props;
    }

    vksc::PipelineCacheBuilder *AddPipelineCacheBuilder() {
        pipeline_cache_builders_.emplace_back(vksc::PipelineCacheBuilder());
        return &pipeline_cache_builders_.back();
    }

    VkDeviceObjectReservationCreateInfo &ObjectReservation() { return object_reservation_info_; }

  private:
    VkPipelineCache default_pipeline_cache_{VK_NULL_HANDLE};
    std::vector<vksc::PipelineCacheBuilder> pipeline_cache_builders_{};
    VkDeviceObjectReservationCreateInfo object_reservation_info_;
};

// Render framework used by compatible Vulkan tests
class VkSCCompatibilityRenderFramework : public VkSCRenderFramework {
  public:
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

    // Create fake shader module object to store SPIR-V data in
    VkShaderModule CreateShaderModuleData(const VkShaderModuleCreateInfo &create_info) {
        std::vector<uint32_t> spirv;
        spirv.assign(create_info.pCode, create_info.pCode + create_info.codeSize / sizeof(uint32_t));
        auto handle = reinterpret_cast<VkShaderModule>(spirv.data());
        shader_modules_.emplace(handle, std::move(spirv));
        return handle;
    }

    // Get SPIR-V data from fake shader module object
    const std::vector<uint32_t> *GetShaderModuleData(VkShaderModule handle) {
        auto it = shader_modules_.find(handle);
        if (it != shader_modules_.end()) {
            return &it->second;
        } else {
            return nullptr;
        }
    }

    // Destroy fake shader module object
    void DestroyShaderModuleData(VkShaderModule handle) { shader_modules_.erase(handle); }

    // Create on-demand pipeline cache in response to Vulkan pipeline creation
    std::shared_ptr<vksc::PipelineCache> CreateOnDemandPipelineCache(VkDevice device, const VkPipelineCacheCreateInfo &create_info);

    // Register created pipeline with an on-demand pipeline cache
    void RegisterPipelineWithOnDemandCache(VkPipeline pipeline, const std::shared_ptr<vksc::PipelineCache> &cache) {
        on_demand_pipeline_caches_.emplace(pipeline, cache);
    }

    // Unregister destroyed pipeline with an on-demand pipeline cache
    void UnregisterPipelineWithOnDemandCache(VkPipeline pipeline) { on_demand_pipeline_caches_.erase(pipeline); }

    // Skip on QNX
    void SkipOnQNX() {
#if defined(__QNX__)
        dispatch_helper_.SkipUnsupportedTest("Test case not compatible with QNX");
#endif
    }

    // Skip if SPIR-V debug information is not enabled
    void RequiresSpvDebugInfo() {
        if (!VkSCTestEnvironment::IsSpvDebugInfoEnabled()) {
            dispatch_helper_.SkipUnsupportedTest("Test case requires SPIR-V debug information");
        }
    }

  private:
    vksc::TestDispatchHelper dispatch_helper_;

    // Shader module SPIR-V data map to store emulated shader module data
    vvl::unordered_map<VkShaderModule, std::vector<uint32_t>> shader_modules_;

    // On-demand pipeline cache map to store references to the pipeline caches created on demand
    // in response to pipeline creation commands using shader module SPIR-V data
    vvl::unordered_map<VkPipeline, std::shared_ptr<vksc::PipelineCache>> on_demand_pipeline_caches_;

    inline static VkSCCompatibilityRenderFramework *s_instance{nullptr};
};
