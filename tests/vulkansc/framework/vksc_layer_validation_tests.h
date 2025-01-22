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
#pragma once

#include "vksc_test_dispatch_helper.h"
#include "vksc_test_pipeline_cache_helper.h"
#include "vksc_shader_templates.h"
#include "vksc_pipeline_templates.h"

#include "../../framework/layer_validation_tests.h"

class VkSCLayerTest : public VkLayerTest {
  public:
    VkSCLayerTest();
};

class VkSCPositiveLayerTest : public VkSCLayerTest {};

class VkSCDeviceCreateTest : public VkSCLayerTest {
  public:
    VkPhysicalDeviceProperties phys_dev_props;

    void InitFramework() {
        VkSCLayerTest::InitFramework();

        vksc::GetPhysicalDeviceProperties(gpu(), &phys_dev_props);
    }

    void TestCreateDevice(void* pNext) {
        float queue_priority = 1.f;
        auto queue_info = vku::InitStruct<VkDeviceQueueCreateInfo>();
        queue_info.queueCount = 1;
        queue_info.pQueuePriorities = &queue_priority;

        auto create_info = vku::InitStruct<VkDeviceCreateInfo>(pNext);
        create_info.queueCreateInfoCount = 1;
        create_info.pQueueCreateInfos = &queue_info;

        VkDevice device = VK_NULL_HANDLE;

        vksc::CreateDevice(gpu(), &create_info, nullptr, &device);
        m_errorMonitor->VerifyFound();

        vksc::DestroyDevice(device, nullptr);
    }
};

class VkSCPipelineCacheDataTest : public VkSCDeviceCreateTest {
  public:
    VkPipelineCacheCreateInfo create_info{};

    void TestPipelineCacheData(const std::vector<VkPipelineCacheCreateInfo> create_infos) {
        auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
        auto object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>(&sc_10_features);
        object_reservation_info.pipelineCacheCreateInfoCount = static_cast<uint32_t>(create_infos.size());
        object_reservation_info.pPipelineCacheCreateInfos = create_infos.data();

        TestCreateDevice(&object_reservation_info);
    }

    void InitStateWithPipelineCacheData(const std::vector<VkPipelineCacheCreateInfo> create_infos, const void* pNext = nullptr) {
        auto object_reservation_info = vksc::GetDefaultObjectReservationCreateInfo();
        object_reservation_info.pipelineCacheCreateInfoCount = static_cast<uint32_t>(create_infos.size());
        object_reservation_info.pPipelineCacheCreateInfos = create_infos.data();
        object_reservation_info.pNext = pNext;

        InitState(nullptr, &object_reservation_info);
    }

    vksc::PipelineCacheBuilder builder{};
};

class VkSCNegativeDeviceCreate : public VkSCDeviceCreateTest {};

class VkSCNegativePipelineCacheData : public VkSCPipelineCacheDataTest {};
class VkSCPositivePipelineCacheData : public VkSCPipelineCacheDataTest {};

class VkSCNegativeShaderSpirv : public VkSCLayerTest {};
class VkSCPositiveShaderSpirv : public VkSCLayerTest {};

class VkSCPositiveRemoved : public VkSCLayerTest {};

class VkSCNegativeImplicit : public VkSCLayerTest {};
class VkSCPositiveImplicit : public VkSCLayerTest {};

class VkSCNegativeCommand : public VkSCLayerTest {};

class VkSCPositiveInstance : public VkSCLayerTest {};

class VkSCNegativePipeline : public VkSCLayerTest {};
class VkSCPositivePipeline : public VkSCLayerTest {};

class VkSCNegativeRenderPass : public VkSCLayerTest {};
