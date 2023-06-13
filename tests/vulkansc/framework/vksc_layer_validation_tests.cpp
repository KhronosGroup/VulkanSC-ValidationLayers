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

#include "vksc_layer_validation_tests.h"

VkPhysicalDeviceVulkanSC10Features VkSCLayerTest::GetVulkanSC10Features(VkPhysicalDevice phys_dev) {
    auto sc_10_features = LvlInitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto features2 = LvlInitStruct<VkPhysicalDeviceFeatures2>(&sc_10_features);
    vksc::GetPhysicalDeviceFeatures2(phys_dev, &features2);
    return sc_10_features;
}

VkPhysicalDeviceVulkanSC10Properties VkSCLayerTest::GetVulkanSC10Properties(VkPhysicalDevice phys_dev) {
    auto sc_10_props = LvlInitStruct<VkPhysicalDeviceVulkanSC10Properties>();
    auto props2 = LvlInitStruct<VkPhysicalDeviceProperties2>(&sc_10_props);
    vksc::GetPhysicalDeviceProperties2(phys_dev, &props2);
    return sc_10_props;
}

VkSCLayerTest::~VkSCLayerTest() {
    if (m_device != nullptr && m_device->handle() != VK_NULL_HANDLE) {
        vksc::DestroyPipelineCache(m_device->handle(), default_pipeline_cache_, nullptr);
    }
}

VkPipelineCache VkSCLayerTest::GetDefaultPipelineCache() {
    if (default_pipeline_cache_ == VK_NULL_HANDLE) {
        vksc::CreatePipelineCache(m_device->handle(), &vksc::GetDefaultPipelineCacheCreateInfo(), nullptr,
                                  &default_pipeline_cache_);
    }
    return default_pipeline_cache_;
}
