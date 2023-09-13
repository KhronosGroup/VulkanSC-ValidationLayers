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

#include "vksc_test_dispatch_helper.h"
#include "vksc_test_pipeline_cache_helper.h"

#include "../../framework/layer_validation_tests.h"

class VkSCLayerTest : public VkLayerTest {
  public:
    VkSCLayerTest();

    static VkPhysicalDeviceVulkanSC10Features GetVulkanSC10Features(VkPhysicalDevice phys_dev);
    static VkPhysicalDeviceVulkanSC10Properties GetVulkanSC10Properties(VkPhysicalDevice phys_dev);
};

class VkSCPositiveLayerTest : public VkSCLayerTest {};
