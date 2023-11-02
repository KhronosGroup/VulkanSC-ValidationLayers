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

VkSCLayerTest::VkSCLayerTest() : VkLayerTest() { app_info_.apiVersion = VKSC_API_VERSION_1_0; }

VkPhysicalDeviceVulkanSC10Features VkSCLayerTest::GetVulkanSC10Features(VkPhysicalDevice phys_dev) {
    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto features2 = vku::InitStruct<VkPhysicalDeviceFeatures2>(&sc_10_features);
    vksc::GetPhysicalDeviceFeatures2(phys_dev, &features2);
    return sc_10_features;
}

VkPhysicalDeviceVulkanSC10Properties VkSCLayerTest::GetVulkanSC10Properties(VkPhysicalDevice phys_dev) {
    auto sc_10_props = vku::InitStruct<VkPhysicalDeviceVulkanSC10Properties>();
    auto props2 = vku::InitStruct<VkPhysicalDeviceProperties2>(&sc_10_props);
    vksc::GetPhysicalDeviceProperties2(phys_dev, &props2);
    return sc_10_props;
}
