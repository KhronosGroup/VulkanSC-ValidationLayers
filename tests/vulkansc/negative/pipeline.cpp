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

TEST_F(VkSCNegativePipeline, CreatePipelinesShaderModuleNotNull) {
    TEST_DESCRIPTION("vkCreate*Pipelines - VkPipelineShaderStageCreateInfo::module must be VK_NULL_HANDLE");

    RETURN_IF_SKIP(Init());
    InitRenderTarget();

    {
        vksc::ComputePipelineBuilder builder(this);
        builder.Init();
        // VkPipelineShaderStageCreateInfo::module must be VK_NULL_HANDLE
        builder.pipeline_ci.stage.module = (VkShaderModule)(size_t)0xBAADF00D;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineShaderStageCreateInfo-module-05026");
        m_errorMonitor->SetAllowedFailureMsg("VUID-VkPipelineShaderStageCreateInfo-module-parameter");
        builder.CreatePipeline(*m_device);
        m_errorMonitor->VerifyFound();
    }
    {
        vksc::GraphicsPipelineBuilder builder(this);
        builder.InitVs();
        // VkPipelineShaderStageCreateInfo::module must be VK_NULL_HANDLE
        builder.stage_ci[0].module = (VkShaderModule)(size_t)0xBAADF00D;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineShaderStageCreateInfo-module-05026");
        m_errorMonitor->SetAllowedFailureMsg("VUID-VkPipelineShaderStageCreateInfo-module-parameter");
        builder.CreatePipeline(*m_device);
        m_errorMonitor->VerifyFound();
    }
}

TEST_F(VkSCNegativePipeline, CreatePipelinesWithBasePipeline) {
    TEST_DESCRIPTION("Test vkCreate*Pipelines usage with a basePipeline");

    RETURN_IF_SKIP(Init());
    InitRenderTarget();

    {
        // vkCreateComputePipelines
        vksc::ComputePipelineBuilder builder(this);
        builder.Init();
        {
            // VkPipelineShaderStageCreateInfo::basePipelineHandle must be VK_NULL_HANDLE
            builder.pipeline_ci.basePipelineHandle = (VkPipeline)(size_t)0xBAADF00D;
            builder.pipeline_ci.basePipelineIndex = 0;

            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkComputePipelineCreateInfo-basePipelineHandle-05024");
            builder.CreatePipeline(*m_device);
            m_errorMonitor->VerifyFound();
        }
        {
            // VkPipelineShaderStageCreateInfo::basePipelineIndex must be 0
            builder.pipeline_ci.basePipelineHandle = VK_NULL_HANDLE;
            builder.pipeline_ci.basePipelineIndex = (int32_t)0xBAADF00D;

            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkComputePipelineCreateInfo-basePipelineIndex-05025");
            builder.CreatePipeline(*m_device);
            m_errorMonitor->VerifyFound();
        }
    }
    {
        // vkCreateGraphicsPipelines
        vksc::GraphicsPipelineBuilder builder(this);
        builder.InitVsFs();
        {
            // VkPipelineShaderStageCreateInfo::basePipelineHandle must be VK_NULL_HANDLE
            builder.pipeline_ci.basePipelineHandle = (VkPipeline)(size_t)0xBAADF00D;
            builder.pipeline_ci.basePipelineIndex = 0;
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkGraphicsPipelineCreateInfo-basePipelineHandle-05024");
            builder.CreatePipeline(*m_device);
            m_errorMonitor->VerifyFound();
        }
        {
            // VkPipelineShaderStageCreateInfo::basePipelineIndex must be 0
            builder.pipeline_ci.basePipelineHandle = VK_NULL_HANDLE;
            builder.pipeline_ci.basePipelineIndex = (int32_t)0xBAADF00D;
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkGraphicsPipelineCreateInfo-basePipelineIndex-05025");
            builder.CreatePipeline(*m_device);
            m_errorMonitor->VerifyFound();
        }
    }
}

TEST_F(VkSCNegativePipeline, CreatePipelinePoolSize) {
    TEST_DESCRIPTION("Test pipeline pool size related VUs for pipeline create commands");

    RETURN_IF_SKIP(InitFramework());

    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vksc::GetDefaultObjectReservationCreateInfo();
    object_reservation_info.pNext = &sc_10_features;

    VkDeviceSize size1 = 64 * 1024u;
    VkDeviceSize size2 = 128 * 1024u;
    VkDeviceSize invalid_size1 = 32 * 1024u;
    VkDeviceSize invalid_size2 = 48 * 1024u;

    std::vector<VkPipelinePoolSize> pool_sizes{vku::InitStruct<VkPipelinePoolSize>(nullptr, size1, 8u),
                                               vku::InitStruct<VkPipelinePoolSize>(nullptr, size2, 4u)};

    object_reservation_info.pipelinePoolSizeCount = static_cast<uint32_t>(pool_sizes.size());
    object_reservation_info.pPipelinePoolSizes = pool_sizes.data();

    ASSERT_NO_FATAL_FAILURE(InitState(nullptr, &object_reservation_info));

    auto create_pipelines = [this](VkDevice device, VkPipelineLayout pipeline_layout, VkRenderPass render_pass,
                                   std::vector<VkDeviceSize> pool_size,
                                   const std::vector<const char*> vuids = {}) -> std::vector<VkPipeline> {
        std::vector<VkPipeline> pipelines{};

        std::vector<VkPipelineOfflineCreateInfo> offline_info(pool_size.size(), vksc::GetDefaultPipelineOfflineCreateInfo());
        for (size_t i = 0; i < offline_info.size(); ++i) {
            offline_info[i].poolEntrySize = pool_size[i];
        }

        // Test compute pipeline create
        {
            size_t next_pipeline = pipelines.size();
            pipelines.resize(next_pipeline + offline_info.size());

            std::vector<VkComputePipelineCreateInfo> create_info(offline_info.size());
            for (size_t i = 0; i < create_info.size(); ++i) {
                create_info[i] = vku::InitStruct<VkComputePipelineCreateInfo>(&offline_info[i]);
                create_info[i].stage = vku::InitStruct<VkPipelineShaderStageCreateInfo>();
                create_info[i].stage.stage = VK_SHADER_STAGE_COMPUTE_BIT;
                create_info[i].stage.pName = "main";
                create_info[i].layout = pipeline_layout;
            }

            for (const auto vuid : vuids) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, vuid);
            }

            vksc::CreateComputePipelines(device, GetDefaultPipelineCache(), static_cast<uint32_t>(create_info.size()),
                                         create_info.data(), nullptr, &pipelines[next_pipeline]);

            if (vuids.size() > 0) {
                m_errorMonitor->VerifyFound();
            }
        }

        // Test graphics pipeline create
        {
            size_t next_pipeline = pipelines.size();
            pipelines.resize(next_pipeline + offline_info.size());

            auto stage_info = vku::InitStruct<VkPipelineShaderStageCreateInfo>();
            stage_info.stage = VK_SHADER_STAGE_VERTEX_BIT;
            stage_info.pName = "main";

            auto vi_state = vku::InitStruct<VkPipelineVertexInputStateCreateInfo>();
            auto ia_state = vku::InitStruct<VkPipelineInputAssemblyStateCreateInfo>();
            auto rs_state = vku::InitStruct<VkPipelineRasterizationStateCreateInfo>();
            rs_state.rasterizerDiscardEnable = VK_TRUE;
            rs_state.lineWidth = 1.f;

            std::vector<VkGraphicsPipelineCreateInfo> create_info(offline_info.size());
            for (size_t i = 0; i < create_info.size(); ++i) {
                create_info[i] = vku::InitStruct<VkGraphicsPipelineCreateInfo>(&offline_info[i]);
                create_info[i].stageCount = 1;
                create_info[i].pStages = &stage_info;
                create_info[i].pVertexInputState = &vi_state;
                create_info[i].pInputAssemblyState = &ia_state;
                create_info[i].pRasterizationState = &rs_state;
                create_info[i].layout = pipeline_layout;
                create_info[i].renderPass = render_pass;
            }

            for (const auto vuid : vuids) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, vuid);
            }

            vksc::CreateGraphicsPipelines(device, GetDefaultPipelineCache(), static_cast<uint32_t>(create_info.size()),
                                          create_info.data(), nullptr, &pipelines[next_pipeline]);

            if (vuids.size() > 0) {
                m_errorMonitor->VerifyFound();
            }
        }

        return pipelines;
    };

    const char* invalid_size_vuid = "VUID-VkPipelineOfflineCreateInfo-poolEntrySize-05028";

    // Determine which capacity VUID should be triggered based on recyclePipelineMemory support
    const char* capacity_vuid = GetVulkanSC10Properties().recyclePipelineMemory
                                    ? "VUID-VkPipelineOfflineCreateInfo-recyclePipelineMemory-05029"
                                    : "VUID-VkPipelineOfflineCreateInfo-recyclePipelineMemory-05030";

    const vkt::PipelineLayout pipeline_layout(*m_device);
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

    // If recyclePipelineMemory is supported we should be able to do this multiple times
    const uint32_t iter_count = GetVulkanSC10Properties().recyclePipelineMemory ? 3 : 1;
    for (uint32_t iter = 0; iter < iter_count; ++iter) {
        std::vector<VkPipeline> pipelines{};
        std::vector<VkPipeline> created_pipelines{};

        // clang-format off

        // Expect create pipeline to fail if the used pipeline pool size is not one of the requested ones
        created_pipelines = create_pipelines(m_device->handle(), pipeline_layout.handle(), render_pass.handle(),
            {invalid_size1},
            {invalid_size_vuid});
        pipelines.insert(pipelines.end(), created_pipelines.begin(), created_pipelines.end());

        // Expect the same even if multiple pipelines are created and some of them are valid
        created_pipelines = create_pipelines(m_device->handle(), pipeline_layout.handle(), render_pass.handle(),
            {size1, invalid_size1, size1, size2, invalid_size1, size2},
            {invalid_size_vuid});
        pipelines.insert(pipelines.end(), created_pipelines.begin(), created_pipelines.end());

        created_pipelines = create_pipelines(m_device->handle(), pipeline_layout.handle(), render_pass.handle(),
            {size1, invalid_size1, size1, size2, invalid_size2, size2},
            {invalid_size_vuid, invalid_size_vuid});
        pipelines.insert(pipelines.end(), created_pipelines.begin(), created_pipelines.end());

        // Expect to be able to create some pipelines with correct pool sizes (don't use all entries yet)
        created_pipelines = create_pipelines(m_device->handle(), pipeline_layout.handle(), render_pass.handle(),
            {size1, size2, size1});
        pipelines.insert(pipelines.end(), created_pipelines.begin(), created_pipelines.end());

        // Expect to fail to create more pipelines than fit in particular pools but not in others
        created_pipelines = create_pipelines(m_device->handle(), pipeline_layout.handle(), render_pass.handle(),
            {size1, size2, size1, size1, size1, size2, size1, size1},
            {capacity_vuid});
        pipelines.insert(pipelines.end(), created_pipelines.begin(), created_pipelines.end());

        created_pipelines = create_pipelines(m_device->handle(), pipeline_layout.handle(), render_pass.handle(),
            {size1, size2, size2, size1, size2, size2},
            {capacity_vuid});
        pipelines.insert(pipelines.end(), created_pipelines.begin(), created_pipelines.end());

        // Test that multiple errors are generated when appropriate
        created_pipelines = create_pipelines(m_device->handle(), pipeline_layout.handle(), render_pass.handle(),
            {size1, size2, size1, size1, invalid_size1, size1, size1, size1},
            {invalid_size_vuid, capacity_vuid});
        pipelines.insert(pipelines.end(), created_pipelines.begin(), created_pipelines.end());

        created_pipelines = create_pipelines(m_device->handle(), pipeline_layout.handle(), render_pass.handle(),
            {size1, size2, invalid_size1, size2, size2, size2},
            {invalid_size_vuid, capacity_vuid});
        pipelines.insert(pipelines.end(), created_pipelines.begin(), created_pipelines.end());

        // Test that filling up to the limits is still doable
        created_pipelines = create_pipelines(m_device->handle(), pipeline_layout.handle(), render_pass.handle(),
            {size1, size2, size1});
        pipelines.insert(pipelines.end(), created_pipelines.begin(), created_pipelines.end());

        // Then again, we should expect capacity issues with any attempt
        created_pipelines = create_pipelines(m_device->handle(), pipeline_layout.handle(), render_pass.handle(),
            {invalid_size1},
            {invalid_size_vuid});
        pipelines.insert(pipelines.end(), created_pipelines.begin(), created_pipelines.end());

        created_pipelines = create_pipelines(m_device->handle(), pipeline_layout.handle(), render_pass.handle(),
            {size1},
            {capacity_vuid});
        pipelines.insert(pipelines.end(), created_pipelines.begin(), created_pipelines.end());

        created_pipelines = create_pipelines(m_device->handle(), pipeline_layout.handle(), render_pass.handle(),
            {size2},
            {capacity_vuid});
        pipelines.insert(pipelines.end(), created_pipelines.begin(), created_pipelines.end());

        // clang-format on

        // Delete pipelines
        for (auto pipeline : pipelines) {
            vksc::DestroyPipeline(m_device->handle(), pipeline, nullptr);
        }
        pipelines.clear();
    }
}

TEST_F(VkSCNegativePipeline, CreatePipelineCacheInvalidFlags) {
    TEST_DESCRIPTION("vkCreatePipelineCache - missing required flags");
    // NOTE: This test case implicitly tests the removed VUIDs: 00768, 00769

    RETURN_IF_SKIP(Init());

    VkPipelineCache pipeline_cache = VK_NULL_HANDLE;
    auto create_info = vksc::GetDefaultPipelineCacheCreateInfo();

    create_info.flags = VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT;
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineCacheCreateInfo-flags-05043");
    m_errorMonitor->SetAllowedFailureMsg("VUID-vkCreatePipelineCache-pCreateInfo-05045");
    vksc::CreatePipelineCache(m_device->handle(), &create_info, nullptr, &pipeline_cache);
    m_errorMonitor->VerifyFound();

    create_info.flags = VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT;
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineCacheCreateInfo-flags-05044");
    m_errorMonitor->SetAllowedFailureMsg("VUID-vkCreatePipelineCache-pCreateInfo-05045");
    vksc::CreatePipelineCache(m_device->handle(), &create_info, nullptr, &pipeline_cache);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativePipeline, CreatePipelineCacheNoMatch) {
    TEST_DESCRIPTION(
        "vkCreatePipelineCache - pipeline cache create info does not match any of the "
        "pipeline cache create infos specified at device create time");

    auto object_reservation_info = vksc::GetDefaultObjectReservationCreateInfo();
    auto pipeline_cache_data = vksc::GetDefaultPipelineCacheData();
    auto create_info = vksc::GetDefaultPipelineCacheCreateInfo();

    create_info.pInitialData = pipeline_cache_data.data();
    object_reservation_info.pipelineCacheCreateInfoCount = 1;
    object_reservation_info.pPipelineCacheCreateInfos = &create_info;

    RETURN_IF_SKIP(InitFramework());
    ASSERT_NO_FATAL_FAILURE(InitState(nullptr, &object_reservation_info));

    VkPipelineCache pipeline_cache = VK_NULL_HANDLE;

    // Mismatch in initialDataSize
    create_info.initialDataSize += 8;
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreatePipelineCache-pCreateInfo-05045");
    vksc::CreatePipelineCache(m_device->handle(), &create_info, nullptr, &pipeline_cache);
    m_errorMonitor->VerifyFound();
    create_info.initialDataSize -= 8;

    // Mismatch in pInitialData pointer (content is otherwise the same)
    auto pipeline_cache_data_copy = pipeline_cache_data;
    create_info.pInitialData = pipeline_cache_data_copy.data();
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreatePipelineCache-pCreateInfo-05045");
    vksc::CreatePipelineCache(m_device->handle(), &create_info, nullptr, &pipeline_cache);
    m_errorMonitor->VerifyFound();
    create_info.pInitialData = pipeline_cache_data.data();

    // Mismatch in pInitialData contents (pointer is the same)
    pipeline_cache_data[sizeof(VkPipelineCacheHeaderVersionSafetyCriticalOne)] ^= 1;
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreatePipelineCache-pCreateInfo-05045");
    vksc::CreatePipelineCache(m_device->handle(), &create_info, nullptr, &pipeline_cache);
    m_errorMonitor->VerifyFound();
    pipeline_cache_data[sizeof(VkPipelineCacheHeaderVersionSafetyCriticalOne)] ^= 1;
}
