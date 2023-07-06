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

TEST_F(VkSCLayerTest, ResetCommandPoolReleaseResourcesNotAllowed) {
    TEST_DESCRIPTION("vkResetCommandPool - VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT not allowed");

    ASSERT_NO_FATAL_FAILURE(Init());

    auto create_info = LvlInitStruct<VkCommandPoolCreateInfo>();
    vk_testing::CommandPool cmd_pool(*m_device, create_info);

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkResetCommandPool-flags-zerobitmask");
    vksc::ResetCommandPool(m_device->handle(), cmd_pool.handle(), VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCLayerTest, CreatePipelinesDerivativeBitNotAllowed) {
    TEST_DESCRIPTION("vkCreate*Pipelines - Vk*PipelineCreateInfo::flags must not contain VK_PIPELINE_CREATE_DERIVATIVE_BIT");
    // NOTE: This test case implicitly tests the removed VUIDs:
    // 00695, 00696, 07984, 07985, 07986 for createComputePipeline
    // 00720, 00721, 07984, 07985, 07986 for createGraphicsPipeline

    ASSERT_NO_FATAL_FAILURE(InitFramework());
    ASSERT_NO_FATAL_FAILURE(InitState());

    VkPipelineLayoutObj pipeline_layout(m_device);
    VkPipeline pipeline = VK_NULL_HANDLE;
    auto offline_info = vksc::GetDefaultPipelineOfflineCreateInfo();

    {
        auto create_info = LvlInitStruct<VkComputePipelineCreateInfo>(&offline_info);
        create_info.stage = LvlInitStruct<VkPipelineShaderStageCreateInfo>();
        create_info.stage.stage = VK_SHADER_STAGE_COMPUTE_BIT;
        create_info.stage.module = VK_NULL_HANDLE;
        create_info.stage.pName = "main";
        create_info.layout = pipeline_layout.handle();
        // VkComputePipelineCreateInfo::flags must not contain VK_PIPELINE_CREATE_DERIVATIVE_BIT
        create_info.flags = VK_PIPELINE_CREATE_DERIVATIVE_BIT;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkComputePipelineCreateInfo-flags-parameter");
        vksc::CreateComputePipelines(m_device->handle(), GetDefaultPipelineCache(), 1, &create_info, nullptr, &pipeline);
        m_errorMonitor->VerifyFound();
    }
    {
        VkRenderpassObj render_pass(m_device);

        auto stage_info = LvlInitStruct<VkPipelineShaderStageCreateInfo>();
        stage_info.stage = VK_SHADER_STAGE_VERTEX_BIT;
        stage_info.module = VK_NULL_HANDLE;
        stage_info.pName = "main";

        auto vi_state = LvlInitStruct<VkPipelineVertexInputStateCreateInfo>();
        auto ia_state = LvlInitStruct<VkPipelineInputAssemblyStateCreateInfo>();
        auto rs_state = LvlInitStruct<VkPipelineRasterizationStateCreateInfo>();
        rs_state.rasterizerDiscardEnable = VK_TRUE;
        rs_state.lineWidth = 1.f;

        auto create_info = LvlInitStruct<VkGraphicsPipelineCreateInfo>(&offline_info);
        create_info.stageCount = 1;
        create_info.pStages = &stage_info;
        create_info.pVertexInputState = &vi_state;
        create_info.pInputAssemblyState = &ia_state;
        create_info.pRasterizationState = &rs_state;
        create_info.layout = pipeline_layout.handle();
        create_info.renderPass = render_pass.handle();
        // VkGraphicsPipelineCreateInfo::flags must not contain VK_PIPELINE_CREATE_DERIVATIVE_BIT
        create_info.flags = VK_PIPELINE_CREATE_DERIVATIVE_BIT;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkGraphicsPipelineCreateInfo-flags-parameter");
        vksc::CreateGraphicsPipelines(m_device->handle(), GetDefaultPipelineCache(), 1, &create_info, nullptr, &pipeline);
        m_errorMonitor->VerifyFound();
        create_info.flags = 0;
    }
}

TEST_F(VkSCLayerTest, CreatePipelinesMissingPipelineCache) {
    TEST_DESCRIPTION("vkCreate*Pipelines - pipelineCache must not be VK_NULL_HANDLE");

    ASSERT_NO_FATAL_FAILURE(InitFramework());
    ASSERT_NO_FATAL_FAILURE(InitState());

    VkPipelineLayoutObj pipeline_layout(m_device);
    VkPipeline pipeline = VK_NULL_HANDLE;
    auto offline_info = vksc::GetDefaultPipelineOfflineCreateInfo();

    {
        auto create_info = LvlInitStruct<VkComputePipelineCreateInfo>(&offline_info);
        create_info.stage = LvlInitStruct<VkPipelineShaderStageCreateInfo>();
        create_info.stage.stage = VK_SHADER_STAGE_COMPUTE_BIT;
        create_info.stage.module = VK_NULL_HANDLE;
        create_info.stage.pName = "main";
        create_info.layout = pipeline_layout.handle();

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "UNASSIGNED-GeneralParameterError-RequiredParameter");
        // pipelineCache must not be VK_NULL_HANDLE
        vksc::CreateComputePipelines(m_device->handle(), VK_NULL_HANDLE, 1, &create_info, nullptr, &pipeline);
        m_errorMonitor->VerifyFound();
    }
    {
        VkRenderpassObj render_pass(m_device);

        auto stage_info = LvlInitStruct<VkPipelineShaderStageCreateInfo>();
        stage_info.stage = VK_SHADER_STAGE_VERTEX_BIT;
        stage_info.module = VK_NULL_HANDLE;
        stage_info.pName = "main";

        auto vi_state = LvlInitStruct<VkPipelineVertexInputStateCreateInfo>();
        auto ia_state = LvlInitStruct<VkPipelineInputAssemblyStateCreateInfo>();
        auto rs_state = LvlInitStruct<VkPipelineRasterizationStateCreateInfo>();
        rs_state.rasterizerDiscardEnable = VK_TRUE;
        rs_state.lineWidth = 1.f;

        auto create_info = LvlInitStruct<VkGraphicsPipelineCreateInfo>(&offline_info);
        create_info.stageCount = 1;
        create_info.pStages = &stage_info;
        create_info.pVertexInputState = &vi_state;
        create_info.pInputAssemblyState = &ia_state;
        create_info.pRasterizationState = &rs_state;
        create_info.layout = pipeline_layout.handle();
        create_info.renderPass = render_pass.handle();

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "UNASSIGNED-GeneralParameterError-RequiredParameter");
        // pipelineCache must not be VK_NULL_HANDLE
        vksc::CreateGraphicsPipelines(m_device->handle(), VK_NULL_HANDLE, 1, &create_info, nullptr, &pipeline);
        m_errorMonitor->VerifyFound();
    }
}
