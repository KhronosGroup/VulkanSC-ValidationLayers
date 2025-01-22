/*
 * Copyright (c) 2023-2025 The Khronos Group Inc.
 * Copyright (c) 2023-2025 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#include "../framework/vksc_layer_validation_tests.h"
#include "../framework/vksc_test_pipeline_helper.h"

// NOTE: The test cases in this file contain tests for implicit VUs that are auto-generated, but
// they deserve their own test cases because these implicit VUs are different in Vulkan SC compared
// to Vulkan.

TEST_F(VkSCPositiveImplicit, ResetCommandPoolAllowed) {
    TEST_DESCRIPTION("vkResetCommandPool - allowed if VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT is not specified");

    RETURN_IF_SKIP(Init());

    auto create_info = vku::InitStruct<VkCommandPoolCreateInfo>();
    vkt::CommandPool cmd_pool(*m_device, create_info);

    vksc::ResetCommandPool(m_device->handle(), cmd_pool.handle(), 0);
}

TEST_F(VkSCPositiveImplicit, CreatePipelinesAllowNullStageName) {
    TEST_DESCRIPTION("vkCreate*Pipelines - VkPipelineShaderStageCreateInfo::pName can be NULL in Vulkan SC");

    RETURN_IF_SKIP(Init());
    InitRenderTarget();

    {
        vksc::ComputePipelineBuilder builder(this);
        builder.Init(vksc::Shader::Compute().EntryPoint(nullptr));
        builder.CreatePipeline(*m_device);
    }
    {
        vksc::GraphicsPipelineBuilder builder(this);
        builder.InitVsFs(vksc::Shader::Vertex().EntryPoint(nullptr), vksc::Shader::Fragment().EntryPoint(nullptr));
        builder.CreatePipeline(*m_device);
    }
}
