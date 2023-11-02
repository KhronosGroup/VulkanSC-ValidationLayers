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

TEST_F(VkSCLayerTest, ResetCommandPoolReleaseResourcesNotAllowed) {
    TEST_DESCRIPTION("vkResetCommandPool - VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT not allowed");

    RETURN_IF_SKIP(Init())

    auto create_info = vku::InitStruct<VkCommandPoolCreateInfo>();
    vkt::CommandPool cmd_pool(*m_device, create_info);

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkResetCommandPool-flags-zerobitmask");
    vksc::ResetCommandPool(m_device->handle(), cmd_pool.handle(), VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCLayerTest, CreatePipelinesDerivativeBitNotAllowed) {
    TEST_DESCRIPTION("vkCreate*Pipelines - Vk*PipelineCreateInfo::flags must not contain VK_PIPELINE_CREATE_DERIVATIVE_BIT");
    // NOTE: This test case implicitly tests the removed VUIDs:
    // 00695, 00696, 07984, 07985, 07986 for createComputePipeline
    // 00720, 00721, 07984, 07985, 07986 for createGraphicsPipeline

    RETURN_IF_SKIP(Init())

    const vkt::PipelineLayout pipeline_layout(*m_device);
    VkPipeline pipeline = VK_NULL_HANDLE;
    auto offline_info = vksc::GetDefaultPipelineOfflineCreateInfo();

    {
        auto create_info = vku::InitStruct<VkComputePipelineCreateInfo>(&offline_info);
        create_info.stage = vku::InitStruct<VkPipelineShaderStageCreateInfo>();
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
        stage_info.module = VK_NULL_HANDLE;
        stage_info.pName = "main";

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

    RETURN_IF_SKIP(Init())

    const vkt::PipelineLayout pipeline_layout(*m_device);
    VkPipeline pipeline = VK_NULL_HANDLE;
    auto offline_info = vksc::GetDefaultPipelineOfflineCreateInfo();

    {
        auto create_info = vku::InitStruct<VkComputePipelineCreateInfo>(&offline_info);
        create_info.stage = vku::InitStruct<VkPipelineShaderStageCreateInfo>();
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
        stage_info.module = VK_NULL_HANDLE;
        stage_info.pName = "main";

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

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "UNASSIGNED-GeneralParameterError-RequiredParameter");
        // pipelineCache must not be VK_NULL_HANDLE
        vksc::CreateGraphicsPipelines(m_device->handle(), VK_NULL_HANDLE, 1, &create_info, nullptr, &pipeline);
        m_errorMonitor->VerifyFound();
    }
}

TEST_F(VkSCLayerTest, PipelineCacheInitialDataSizeNotZero) {
    TEST_DESCRIPTION("VkPipelineCacheCreateInfo::initialDataSize must not be 0");

    auto create_info = vku::InitStruct<VkPipelineCacheCreateInfo>();
    create_info.flags = VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT | VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT;
    create_info.initialDataSize = 0;

    RETURN_IF_SKIP(InitFramework());

    // Test that error is generated by vkCreateDevice
    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>(&sc_10_features);
    object_reservation_info.pipelineCacheCreateInfoCount = 1;
    object_reservation_info.pPipelineCacheCreateInfos = &create_info;

    float queue_priority = 1.f;
    auto queue_info = vku::InitStruct<VkDeviceQueueCreateInfo>();
    queue_info.queueCount = 1;
    queue_info.pQueuePriorities = &queue_priority;

    auto device_ci = vku::InitStruct<VkDeviceCreateInfo>(&object_reservation_info);
    device_ci.queueCreateInfoCount = 1;
    device_ci.pQueueCreateInfos = &queue_info;

    VkDevice device = VK_NULL_HANDLE;

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineCacheCreateInfo-initialDataSize-arraylength");
    vksc::CreateDevice(gpu(), &device_ci, nullptr, &device);
    m_errorMonitor->VerifyFound();

    RETURN_IF_SKIP(InitState())

    // Test that error is generated by vkCreatePipelineCache
    VkPipelineCache pipeline_cache = VK_NULL_HANDLE;

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineCacheCreateInfo-initialDataSize-arraylength");
    vksc::CreatePipelineCache(m_device->handle(), &create_info, nullptr, &pipeline_cache);
    m_errorMonitor->VerifyFound();
}
