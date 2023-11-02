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

// NOTE: The test cases in this file contain tests for implicit VUs that are auto-generated, but
// they deserve their own test cases because these implicit VUs are different in Vulkan SC compared
// to Vulkan.

TEST_F(VkSCPositiveLayerTest, ResetCommandPoolAllowed) {
    TEST_DESCRIPTION("vkResetCommandPool - allowed if VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT is not specified");

    RETURN_IF_SKIP(Init())

    auto create_info = vku::InitStruct<VkCommandPoolCreateInfo>();
    vkt::CommandPool cmd_pool(*m_device, create_info);

    vksc::ResetCommandPool(m_device->handle(), cmd_pool.handle(), 0);
}

TEST_F(VkSCPositiveLayerTest, CreatePipelinesAllowNullStageName) {
    TEST_DESCRIPTION("vkCreate*Pipelines - VkPipelineShaderStageCreateInfo::pName can be NULL in Vulkan SC");

    RETURN_IF_SKIP(Init())

    const vkt::PipelineLayout pipeline_layout(*m_device);
    VkPipeline pipeline = VK_NULL_HANDLE;
    auto offline_info = vksc::GetDefaultPipelineOfflineCreateInfo();

    {
        auto create_info = vku::InitStruct<VkComputePipelineCreateInfo>(&offline_info);
        create_info.stage = vku::InitStruct<VkPipelineShaderStageCreateInfo>();
        create_info.stage.stage = VK_SHADER_STAGE_COMPUTE_BIT;
        create_info.stage.pName = NULL;
        create_info.layout = pipeline_layout.handle();

        vksc::CreateComputePipelines(m_device->handle(), GetDefaultPipelineCache(), 1, &create_info, nullptr, &pipeline);
        vksc::DestroyPipeline(m_device->handle(), pipeline, nullptr);
    }
    {
        VkAttachmentReference attach = {};
        attach.layout = VK_IMAGE_LAYOUT_GENERAL;

        VkSubpassDescription subpass = {};
        subpass.pColorAttachments = &attach;
        subpass.colorAttachmentCount = 1;

        VkAttachmentDescription attach_desc = {};
        attach_desc.format = VK_FORMAT_B8G8R8A8_UNORM;
        attach_desc.samples = VK_SAMPLE_COUNT_1_BIT;
        attach_desc.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        attach_desc.finalLayout = VK_IMAGE_LAYOUT_GENERAL;
        attach_desc.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        attach_desc.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;

        VkRenderPassCreateInfo rpci = vku::InitStructHelper();
        rpci.subpassCount = 1;
        rpci.pSubpasses = &subpass;
        rpci.attachmentCount = 1;
        rpci.pAttachments = &attach_desc;

        const vkt::RenderPass render_pass(*m_device, rpci);

        auto stage_info = vku::InitStruct<VkPipelineShaderStageCreateInfo>();
        stage_info.stage = VK_SHADER_STAGE_VERTEX_BIT;
        stage_info.pName = NULL;

        auto vi_state = vku::InitStruct<VkPipelineVertexInputStateCreateInfo>();
        auto ia_state = vku::InitStruct<VkPipelineInputAssemblyStateCreateInfo>();
        auto rs_state = vku::InitStruct<VkPipelineRasterizationStateCreateInfo>();
        rs_state.rasterizerDiscardEnable = VK_TRUE;
        rs_state.lineWidth = 1.f;

        auto create_info = vku::InitStruct<VkGraphicsPipelineCreateInfo>(&offline_info);
        create_info.stageCount = 1;
        create_info.pStages = &stage_info;
        create_info.pVertexInputState = &vi_state;
        create_info.pInputAssemblyState = &ia_state;
        create_info.pRasterizationState = &rs_state;
        create_info.layout = pipeline_layout.handle();
        create_info.renderPass = render_pass.handle();

        vksc::CreateGraphicsPipelines(m_device->handle(), GetDefaultPipelineCache(), 1, &create_info, nullptr, &pipeline);
        vksc::DestroyPipeline(m_device->handle(), pipeline, nullptr);
    }
}
