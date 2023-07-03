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

TEST_F(VkSCLayerTest, CreateComputePipelinesShaderModuleNotNull) {
    TEST_DESCRIPTION("vkCreateComputePipelines - VkPipelineShaderStageCreateInfo::module must be VK_NULL_HANDLE");

    ASSERT_NO_FATAL_FAILURE(InitFramework());
    ASSERT_NO_FATAL_FAILURE(InitState());

    VkPipelineLayoutObj pipeline_layout(m_device);
    VkPipeline pipeline = VK_NULL_HANDLE;

    auto offline_info = vksc::GetDefaultPipelineOfflineCreateInfo();
    auto create_info = LvlInitStruct<VkComputePipelineCreateInfo>(&offline_info);
    create_info.stage = LvlInitStruct<VkPipelineShaderStageCreateInfo>();
    create_info.stage.stage = VK_SHADER_STAGE_COMPUTE_BIT;
    create_info.stage.module = (VkShaderModule)(size_t)0xBAADF00D;
    create_info.stage.pName = "main";
    create_info.layout = pipeline_layout.handle();

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineShaderStageCreateInfo-module-05026");
    m_errorMonitor->SetAllowedFailureMsg("VUID-VkPipelineShaderStageCreateInfo-module-parameter");
    vksc::CreateComputePipelines(m_device->handle(), GetDefaultPipelineCache(), 1, &create_info, nullptr, &pipeline);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCLayerTest, CreateGraphicsPipelinesShaderModuleNotNull) {
    TEST_DESCRIPTION("vkCreateGraphicsPipelines - VkPipelineShaderStageCreateInfo::module must be VK_NULL_HANDLE");

    ASSERT_NO_FATAL_FAILURE(InitFramework());
    ASSERT_NO_FATAL_FAILURE(InitState());

    VkPipelineLayoutObj pipeline_layout(m_device);
    VkRenderpassObj render_pass(m_device);
    VkPipeline pipeline = VK_NULL_HANDLE;

    auto stage_info = LvlInitStruct<VkPipelineShaderStageCreateInfo>();
    stage_info.stage = VK_SHADER_STAGE_VERTEX_BIT;
    stage_info.module = (VkShaderModule)(size_t)0xBAADF00D;
    stage_info.pName = "main";

    auto vi_state = LvlInitStruct<VkPipelineVertexInputStateCreateInfo>();
    auto ia_state = LvlInitStruct<VkPipelineInputAssemblyStateCreateInfo>();
    auto rs_state = LvlInitStruct<VkPipelineRasterizationStateCreateInfo>();
    rs_state.rasterizerDiscardEnable = VK_TRUE;
    rs_state.lineWidth = 1.f;

    auto offline_info = vksc::GetDefaultPipelineOfflineCreateInfo();
    auto create_info = LvlInitStruct<VkGraphicsPipelineCreateInfo>(&offline_info);
    create_info.stageCount = 1;
    create_info.pStages = &stage_info;
    create_info.pVertexInputState = &vi_state;
    create_info.pInputAssemblyState = &ia_state;
    create_info.pRasterizationState = &rs_state;
    create_info.layout = pipeline_layout.handle();
    create_info.renderPass = render_pass.handle();

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineShaderStageCreateInfo-module-05026");
    m_errorMonitor->SetAllowedFailureMsg("VUID-VkPipelineShaderStageCreateInfo-module-parameter");
    vksc::CreateGraphicsPipelines(m_device->handle(), GetDefaultPipelineCache(), 1, &create_info, nullptr, &pipeline);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCLayerTest, CreatePipelinePoolSize) {
    TEST_DESCRIPTION("Test pipeline pool size related VUs for pipeline create commands");

    ASSERT_NO_FATAL_FAILURE(InitFramework());

    auto sc_10_features = LvlInitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vksc::GetDefaultObjectReservationCreateInfo();
    object_reservation_info.pNext = &sc_10_features;

    VkDeviceSize size1 = 64 * 1024u;
    VkDeviceSize size2 = 128 * 1024u;
    VkDeviceSize invalid_size1 = 32 * 1024u;
    VkDeviceSize invalid_size2 = 48 * 1024u;

    std::vector<VkPipelinePoolSize> pool_sizes{LvlInitStruct<VkPipelinePoolSize>(nullptr, size1, 8u),
                                               LvlInitStruct<VkPipelinePoolSize>(nullptr, size2, 4u)};

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
                create_info[i] = LvlInitStruct<VkComputePipelineCreateInfo>(&offline_info[i]);
                create_info[i].stage = LvlInitStruct<VkPipelineShaderStageCreateInfo>();
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

            auto stage_info = LvlInitStruct<VkPipelineShaderStageCreateInfo>();
            stage_info.stage = VK_SHADER_STAGE_VERTEX_BIT;
            stage_info.pName = "main";

            auto vi_state = LvlInitStruct<VkPipelineVertexInputStateCreateInfo>();
            auto ia_state = LvlInitStruct<VkPipelineInputAssemblyStateCreateInfo>();
            auto rs_state = LvlInitStruct<VkPipelineRasterizationStateCreateInfo>();
            rs_state.rasterizerDiscardEnable = VK_TRUE;
            rs_state.lineWidth = 1.f;

            std::vector<VkGraphicsPipelineCreateInfo> create_info(offline_info.size());
            for (size_t i = 0; i < create_info.size(); ++i) {
                create_info[i] = LvlInitStruct<VkGraphicsPipelineCreateInfo>(&offline_info[i]);
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
    const char* capacity_vuid = GetVulkanSC10Properties(gpu()).recyclePipelineMemory
                                    ? "VUID-VkPipelineOfflineCreateInfo-recyclePipelineMemory-05029"
                                    : "VUID-VkPipelineOfflineCreateInfo-recyclePipelineMemory-05030";

    VkPipelineLayoutObj pipeline_layout(m_device);
    VkRenderpassObj render_pass(m_device);

    // If recyclePipelineMemory is supported we should be able to do this multiple times
    const uint32_t iter_count = GetVulkanSC10Properties(gpu()).recyclePipelineMemory ? 3 : 1;
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

TEST_F(VkSCLayerTest, CreatePipelineCacheInvalidFlags) {
    TEST_DESCRIPTION("vkCreatePipelineCache - missing required flags");

    ASSERT_NO_FATAL_FAILURE(InitFramework());
    ASSERT_NO_FATAL_FAILURE(InitState());

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

TEST_F(VkSCLayerTest, CreatePipelineCacheNoMatch) {
    TEST_DESCRIPTION(
        "vkCreatePipelineCache - pipeline cache create info does not match any of the "
        "pipeline cache create infos specified at device create time");

    auto object_reservation_info = vksc::GetDefaultObjectReservationCreateInfo();
    auto pipeline_cache_data = vksc::GetDefaultPipelineCacheData();
    auto create_info = vksc::GetDefaultPipelineCacheCreateInfo();

    create_info.pInitialData = pipeline_cache_data.data();
    object_reservation_info.pipelineCacheCreateInfoCount = 1;
    object_reservation_info.pPipelineCacheCreateInfos = &create_info;

    ASSERT_NO_FATAL_FAILURE(InitFramework());
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
