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
};

class VkSCPositiveLayerTest : public VkSCLayerTest {};
