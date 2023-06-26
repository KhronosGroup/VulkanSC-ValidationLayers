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

#include "../framework/vksc_layer_validation_tests.h"

#include <malloc.h>
#include <cstdlib>

// NOTE: The test cases in this file contain tests for implicit VUs that are auto-generated, but
// they deserve their own test cases because these implicit VUs are different in Vulkan SC compared
// to Vulkan.

TEST_F(VkSCPositiveLayerTest, ResetCommandPoolAllowed) {
    TEST_DESCRIPTION("vkResetCommandPool - allowed if VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT is not specified");

    ASSERT_NO_FATAL_FAILURE(Init());

    auto create_info = LvlInitStruct<VkCommandPoolCreateInfo>();
    vk_testing::CommandPool cmd_pool(*m_device, create_info);

    vksc::ResetCommandPool(m_device->handle(), cmd_pool.handle(), 0);
}
