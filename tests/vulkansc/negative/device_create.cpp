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

class VkSCDeviceCreateLayerTest : public VkSCLayerTest {
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

TEST_F(VkSCDeviceCreateLayerTest, MissingVulkanSC10Features) {
    TEST_DESCRIPTION("vkCreateDevice with missing VkPhysicalDeviceVulkanSC10Features.");

    RETURN_IF_SKIP(InitFramework());

    auto object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>();

    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "UNASSIGNED-VkDeviceCreateInfo-pNext-VkPhysicalDeviceVulkanSC10Features");
    TestCreateDevice(&object_reservation_info);
}

TEST_F(VkSCDeviceCreateLayerTest, MissingObjectReservationInfo) {
    TEST_DESCRIPTION("vkCreateDevice with missing VkDeviceObjectReservationCreateInfo.");

    RETURN_IF_SKIP(InitFramework());

    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();

    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "UNASSIGNED-VkDeviceCreateInfo-pNext-VkDeviceObjectReservationCreateInfo");
    TestCreateDevice(&sc_10_features);
}

TEST_F(VkSCDeviceCreateLayerTest, MaxMemoryAllocationCountExceeded) {
    TEST_DESCRIPTION("vkCreateDevice - requested memory count exceeds maximum");

    RETURN_IF_SKIP(InitFramework());

    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();

    const uint32_t max_count = 10;
    std::vector<VkDeviceObjectReservationCreateInfo> object_reservation_info(
        max_count, vku::InitStruct<VkDeviceObjectReservationCreateInfo>());
    object_reservation_info[0].pNext = &sc_10_features;
    for (uint32_t i = 1; i < max_count; ++i) {
        object_reservation_info[i].pNext = &object_reservation_info[i - 1];
    }

    for (uint32_t used_count = 1; used_count <= max_count; ++used_count) {
        uint32_t remaining = phys_dev_props.limits.maxMemoryAllocationCount;
        for (uint32_t i = 1; i < used_count; ++i) {
            object_reservation_info[i].deviceMemoryRequestCount = remaining / 2;
            remaining -= object_reservation_info[i].deviceMemoryRequestCount;
        }
        object_reservation_info[0].deviceMemoryRequestCount = remaining;

        void* chain = &object_reservation_info[used_count - 1];

        TestCreateDevice(chain);

        object_reservation_info[used_count / 2].deviceMemoryRequestCount++;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateDevice-deviceMemoryRequestCount-05095");
        TestCreateDevice(chain);
    }
}

TEST_F(VkSCDeviceCreateLayerTest, MaxSamplerAllocationCountExceeded) {
    TEST_DESCRIPTION("vkCreateDevice - requested memory count exceeds maximum");

    RETURN_IF_SKIP(InitFramework());

    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();

    const uint32_t max_count = 10;
    std::vector<VkDeviceObjectReservationCreateInfo> object_reservation_info(
        max_count, vku::InitStruct<VkDeviceObjectReservationCreateInfo>());
    object_reservation_info[0].pNext = &sc_10_features;
    for (uint32_t i = 1; i < max_count; ++i) {
        object_reservation_info[i].pNext = &object_reservation_info[i - 1];
    }

    for (uint32_t used_count = 1; used_count <= max_count; ++used_count) {
        uint32_t remaining = phys_dev_props.limits.maxSamplerAllocationCount;
        for (uint32_t i = 1; i < used_count; ++i) {
            object_reservation_info[i].samplerRequestCount = remaining / 2;
            remaining -= object_reservation_info[i].samplerRequestCount;
        }
        object_reservation_info[0].samplerRequestCount = remaining;

        void* chain = &object_reservation_info[used_count - 1];

        TestCreateDevice(chain);

        object_reservation_info[used_count / 2].samplerRequestCount++;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateDevice-samplerRequestCount-05096");
        TestCreateDevice(chain);
    }
}

TEST_F(VkSCDeviceCreateLayerTest, MaxImageArrayLayersExceeded) {
    TEST_DESCRIPTION("vkCreateDevice - requested max image view array layers exceeds maximum");

    RETURN_IF_SKIP(InitFramework());

    VkPhysicalDeviceProperties pd_props;
    GetPhysicalDeviceProperties(&pd_props);

    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>(&sc_10_features);

    object_reservation_info.maxImageViewArrayLayers = pd_props.limits.maxImageArrayLayers + 1;
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkDeviceObjectReservationCreateInfo-maxImageViewArrayLayers-05014");
    TestCreateDevice(&object_reservation_info);
}

TEST_F(VkSCDeviceCreateLayerTest, MaxMipLevelsExceeded) {
    TEST_DESCRIPTION("vkCreateDevice - requested max image view mip levels exceeds maximum");

    RETURN_IF_SKIP(InitFramework());

    VkPhysicalDeviceProperties pd_props;
    GetPhysicalDeviceProperties(&pd_props);

    uint32_t max_mip_levels =
        1u + static_cast<uint32_t>(log2(std::max({pd_props.limits.maxImageDimension1D, pd_props.limits.maxImageDimension2D,
                                                  pd_props.limits.maxImageDimension3D, pd_props.limits.maxImageDimensionCube})));

    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>(&sc_10_features);

    object_reservation_info.maxImageViewMipLevels = max_mip_levels + 1;
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkDeviceObjectReservationCreateInfo-maxImageViewMipLevels-05015");
    TestCreateDevice(&object_reservation_info);

    object_reservation_info.maxImageViewMipLevels = max_mip_levels;
    object_reservation_info.maxLayeredImageViewMipLevels = max_mip_levels + 1;
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkDeviceObjectReservationCreateInfo-maxLayeredImageViewMipLevels-05016");
    TestCreateDevice(&object_reservation_info);
}

TEST_F(VkSCDeviceCreateLayerTest, MaxTotalSubpassDescriptions) {
    TEST_DESCRIPTION("vkCreateDevice - requested subpass description count exceeds maximum possible");

    RETURN_IF_SKIP(InitFramework());

    auto sc_10_props = GetVulkanSC10Properties(gpu());
    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>(&sc_10_features);

    object_reservation_info.renderPassRequestCount = 42;
    object_reservation_info.subpassDescriptionRequestCount =
        object_reservation_info.renderPassRequestCount * sc_10_props.maxRenderPassSubpasses;
    object_reservation_info.attachmentDescriptionRequestCount =
        object_reservation_info.renderPassRequestCount * sc_10_props.maxFramebufferAttachments;

    object_reservation_info.subpassDescriptionRequestCount++;

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit,
                                         "VUID-VkDeviceObjectReservationCreateInfo-subpassDescriptionRequestCount-05017");
    TestCreateDevice(&object_reservation_info);

    object_reservation_info.subpassDescriptionRequestCount--;
    object_reservation_info.attachmentDescriptionRequestCount++;

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit,
                                         "VUID-VkDeviceObjectReservationCreateInfo-attachmentDescriptionRequestCount-05018");
    TestCreateDevice(&object_reservation_info);
}

TEST_F(VkSCDeviceCreateLayerTest, PipelineCacheCreateMissingRequiredFlags) {
    TEST_DESCRIPTION("vkCreateDevice - VkPipelineCacheCreateInfo is missing required flags");

    RETURN_IF_SKIP(InitFramework());

    VkPipelineCacheCreateInfo create_info{};
    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>(&sc_10_features);
    object_reservation_info.pipelineCacheCreateInfoCount = 1;
    object_reservation_info.pPipelineCacheCreateInfos = &create_info;

    vksc::PipelineCacheDataBuilder builder{};
    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    create_info = builder.MakeCreateInfo(VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT);
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineCacheCreateInfo-flags-05043");
    TestCreateDevice(&object_reservation_info);

    create_info = builder.MakeCreateInfo(VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT);
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineCacheCreateInfo-flags-05044");
    TestCreateDevice(&object_reservation_info);
}

class VkSCPipelineCacheDataLayerTest : public VkSCDeviceCreateLayerTest {
  public:
    VkPipelineCacheCreateInfo create_info{};

    void TestPipelineCacheData(const std::vector<VkPipelineCacheCreateInfo> create_infos) {
        auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
        auto object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>(&sc_10_features);
        object_reservation_info.pipelineCacheCreateInfoCount = static_cast<uint32_t>(create_infos.size());
        object_reservation_info.pPipelineCacheCreateInfos = create_infos.data();

        TestCreateDevice(&object_reservation_info);
    }

    vksc::PipelineCacheDataBuilder builder{};
};

TEST_F(VkSCPipelineCacheDataLayerTest, HeaderTooSmall) {
    TEST_DESCRIPTION("Test when pipeline cache data smaller than expected");

    RETURN_IF_SKIP(InitFramework());

    builder.AddBlob(4);

    create_info = builder.MakeCreateInfo();
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "UNASSIGNED-SC-PipelineCacheData-tooSmall");
    TestPipelineCacheData({create_info});

    builder.Clear();
    builder.AddDefaultHeaderVersionSCOne();
    create_info = builder.MakeCreateInfo();
    create_info.initialDataSize = 52;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "UNASSIGNED-SC-PipelineCacheData-tooSmall");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCPipelineCacheDataLayerTest, InvalidHeaderSize) {
    TEST_DESCRIPTION("Pipeline cache data - headerSize is not 56");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    create_info = builder.MakeCreateInfo();

    header->headerVersionOne.headerSize = 52;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheHeaderVersionOne-headerSize-05075");
    TestPipelineCacheData({create_info});

    header->headerVersionOne.headerSize = 60;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheHeaderVersionOne-headerSize-05075");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCPipelineCacheDataLayerTest, InvalidHeaderVersion) {
    TEST_DESCRIPTION("Pipeline cache data - headerVersion is not VK_PIPELINE_CACHE_HEADER_VERSION_SAFETY_CRITICAL_ONE");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    create_info = builder.MakeCreateInfo();

    header->headerVersionOne.headerVersion = VK_PIPELINE_CACHE_HEADER_VERSION_ONE;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheHeaderVersionOne-headerVersion-05076");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCPipelineCacheDataLayerTest, InvalidValidationVersion) {
    TEST_DESCRIPTION("Pipeline cache data - validationVersion is not VK_PIPELINE_CACHE_VALIDATION_VERSION_SAFETY_CRITICAL_ONE");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    create_info = builder.MakeCreateInfo();

    header->validationVersion = static_cast<VkPipelineCacheValidationVersion>(2);
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheHeaderVersionSafetyCriticalOne-validationVersion-05077");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCPipelineCacheDataLayerTest, InvalidPipelineIndexStride) {
    TEST_DESCRIPTION("Pipeline cache data - pipelineIndexStride must be at least 56");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    using PrivData = uint64_t;
    builder.AddPipelineEntry<PrivData>(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    // Should succeed even with a stride larger than 56
    create_info = builder.MakeCreateInfo();
    TestPipelineCacheData({create_info});

    // But fail with a smaller one
    header->pipelineIndexStride = 52;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit,
                                         "VUID-VkPipelineCacheHeaderVersionSafetyCriticalOne-pipelineIndexStride-05078");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCPipelineCacheDataLayerTest, PipelineIndexOutOfBounds) {
    TEST_DESCRIPTION("Pipeline cache data - pipeline index entry out of bounds");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);
    builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120002", 4000);

    create_info = builder.MakeCreateInfo();
    create_info.initialDataSize -= 4;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit,
                                         "VUID-VkPipelineCacheHeaderVersionSafetyCriticalOne-pipelineIndexOffset-05079");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCPipelineCacheDataLayerTest, DuplicatePipelineIdentifier) {
    TEST_DESCRIPTION("Pipeline cache data - duplicate pipeline identifier");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "3ddda923-b6fc-433e-803c-822c1bccbc05", 4000);
    builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 6000);  // duplicate
    builder.AddPipelineEntry(header, "b23d0e5c-70a0-4d67-8781-99ec3798ed31", 5000);
    builder.AddPipelineEntry(header, "19cce681-1612-4b3e-97fc-166624627579", 4000);
    builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 8000);  // duplicate
    builder.AddPipelineEntry(header, "73ada7f2-9cc6-48ed-a193-24d0091f4f95", 4000);

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineCacheCreateInfo-pInitialData-05139");
    TestPipelineCacheData({builder.MakeCreateInfo()});
}

TEST_F(VkSCPipelineCacheDataLayerTest, InvalidPipelineIndexEntryValues) {
    TEST_DESCRIPTION("Pipeline cache data - test invalid cases for pipeline index entry values");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    std::vector<vksc::PipelineCacheDataBuilder::SCIndexEntry<>> entries = {
        builder.AddPipelineEntry(header, "3ddda923-b6fc-433e-803c-822c1bccbc05", 4000),
        builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 6000),
        builder.AddPipelineEntry(header, "b23d0e5c-70a0-4d67-8781-99ec3798ed31", 5000)};

    // jsonOffset must be zero if jsonSize is zero
    entries[1]->jsonOffset = 42;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-jsonSize-05080");
    TestPipelineCacheData({builder.MakeCreateInfo()});
    entries[1]->jsonOffset = 0;

    // stageIndexCount must be zero if jsonSize is zero (either both JSON and stage data is available or neither)
    entries[2]->stageIndexCount = 1;
    entries[2]->stageIndexStride = 16;
    entries[2]->stageIndexOffset = builder.GetData().size();
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-jsonSize-05081");
    m_errorMonitor->SetAllowedFailureMsg("VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05084");
    TestPipelineCacheData({builder.MakeCreateInfo()});
    entries[2]->stageIndexCount = 0;
    entries[2]->stageIndexStride = 0;
    entries[2]->stageIndexOffset = 0;

    // stageIndexOffset must be zero if stageIndexCount is zero
    entries[0]->stageIndexOffset = 42;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05082");
    TestPipelineCacheData({builder.MakeCreateInfo()});
    entries[0]->stageIndexOffset = 0;

    // stageIndexStride must be zero if stageIndexCount is zero
    entries[1]->stageIndexStride = 42;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05082");
    TestPipelineCacheData({builder.MakeCreateInfo()});
    entries[1]->stageIndexStride = 0;
}

TEST_F(VkSCPipelineCacheDataLayerTest, JsonDataOutOfBounds) {
    TEST_DESCRIPTION("Pipeline cache data - JSON data for pipeline out of bounds");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120002", 4000);
    auto entry = builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    builder.AddStageValidation(entry, builder.sample_graphics_pipeline_json, SPV_ENV_VULKAN_1_2,
                               {builder.sample_vertex_shader_spv, builder.sample_fragment_shader_spv});

    entry->jsonOffset = builder.GetData().size() - 4;

    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-jsonSize-08991");
    TestPipelineCacheData({builder.MakeCreateInfo()});
}

TEST_F(VkSCPipelineCacheDataLayerTest, InvalidStageIndexStride) {
    TEST_DESCRIPTION("Pipeline cache data - stageIndexStride must be at least 16");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120002", 4000);
    auto entry = builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    using PrivData = uint64_t;
    builder.AddStageValidation<PrivData>(entry, builder.sample_graphics_pipeline_json, SPV_ENV_VULKAN_1_2,
                                         {builder.sample_vertex_shader_spv, builder.sample_fragment_shader_spv});

    // Should succeed even with a stride larger than 16
    create_info = builder.MakeCreateInfo();
    TestPipelineCacheData({create_info});

    // But fail with a smaller one
    entry->stageIndexStride = 12;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05083");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCPipelineCacheDataLayerTest, StageIndexOutOfBounds) {
    TEST_DESCRIPTION("Pipeline cache data - stage index entry out of bounds");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120002", 4000);
    auto entry = builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    builder.AddStageValidation(entry, builder.sample_graphics_pipeline_json, SPV_ENV_VULKAN_1_2,
                               {builder.sample_vertex_shader_spv, builder.sample_fragment_shader_spv});

    create_info = builder.MakeCreateInfo();
    create_info.initialDataSize = static_cast<size_t>(entry->stageIndexOffset + entry->stageIndexStride + 12);
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05084");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCPipelineCacheDataLayerTest, InvalidStageIndexEntryValues) {
    TEST_DESCRIPTION("Pipeline cache data - test invalid cases for stage index entry values");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    std::vector<vksc::PipelineCacheDataBuilder::SCIndexEntry<>> entries = {
        builder.AddPipelineEntry(header, "3ddda923-b6fc-433e-803c-822c1bccbc05", 4000),
        builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 6000),
        builder.AddPipelineEntry(header, "b23d0e5c-70a0-4d67-8781-99ec3798ed31", 5000)};

    builder.AddStageValidation(entries[1], builder.sample_graphics_pipeline_json, SPV_ENV_VULKAN_1_2,
                               {builder.sample_vertex_shader_spv, builder.sample_fragment_shader_spv});
    builder.AddStageValidation(entries[2], builder.sample_compute_pipeline_json, SPV_ENV_VULKAN_1_2,
                               {builder.sample_compute_shader_spv});

    // codeSize cannot be zero
    auto stage_1_1 = builder.GetStageValidation(entries[1], 1);
    auto orig_code_size_1_1 = stage_1_1->codeSize;
    stage_1_1->codeSize = 0;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheStageValidationIndexEntry-codeSize-05085");
    TestPipelineCacheData({builder.MakeCreateInfo()});
    stage_1_1->codeSize = orig_code_size_1_1;

    // codeSize must be a multiple of 4
    auto stage_2_0 = builder.GetStageValidation(entries[2], 0);
    auto orig_code_size_2_0 = stage_2_0->codeSize;
    stage_2_0->codeSize -= 1;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheStageValidationIndexEntry-codeSize-05086");
    TestPipelineCacheData({builder.MakeCreateInfo()});
    stage_2_0->codeSize = orig_code_size_2_0;
}

TEST_F(VkSCPipelineCacheDataLayerTest, StageCodeDataOutOfBounds) {
    TEST_DESCRIPTION("Pipeline cache data - stage code data out of bounds");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120002", 4000);
    auto entry = builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    builder.AddStageValidation(entry, builder.sample_graphics_pipeline_json, SPV_ENV_VULKAN_1_2,
                               {builder.sample_vertex_shader_spv, builder.sample_fragment_shader_spv});

    builder.GetStageValidation(entry, 1)->codeOffset = builder.GetData().size() - 4;

    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheStageValidationIndexEntry-codeOffset-05087");
    TestPipelineCacheData({builder.MakeCreateInfo()});
}

TEST_F(VkSCPipelineCacheDataLayerTest, MultipleProblems) {
    TEST_DESCRIPTION("Pipeline cache data - test multiple problems with the pipeline cache data");

    RETURN_IF_SKIP(InitFramework());

    std::vector<std::vector<uint8_t>> pipeline_caches{};

    // Create a valid pipeline cache without debug info
    {
        auto header = builder.AddDefaultHeaderVersionSCOne();
        builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120002", 4000);
        builder.AddPipelineEntry(header, "4af1b9ff-a76a-436e-9e7c-7965c06bd7e3", 6000);
        builder.AddPipelineEntry(header, "9fb88f4b-fd08-42f3-ae6c-78e16109d030", 8000);
        pipeline_caches.push_back(builder.GetData());
        builder.Clear();
    }

    // Create an pipeline cache with out-of-bounds pipeline index entry data
    {
        auto header = builder.AddDefaultHeaderVersionSCOne();
        builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120002", 4000);
        builder.AddPipelineEntry(header, "4af1b9ff-a76a-436e-9e7c-7965c06bd7e3", 6000);
        pipeline_caches.push_back(builder.GetData());
        pipeline_caches.back().resize(pipeline_caches.back().size() - 4);
        builder.Clear();
    }

    // Create a pipeline cache with incorrect pipeline header version
    {
        auto header = builder.AddDefaultHeaderVersionSCOne();
        header->headerVersionOne.headerVersion = VK_PIPELINE_CACHE_HEADER_VERSION_ONE;
        builder.AddPipelineEntry(header, "21b63c03-7484-4a69-b420-cda943cb5008", 4000);
        pipeline_caches.push_back(builder.GetData());
        builder.Clear();
    }

    // Create a valid pipeline cache with some debug info
    {
        auto header = builder.AddDefaultHeaderVersionSCOne();

        auto entry1 = builder.AddPipelineEntry(header, "4af1b9ff-a76a-436e-9e7c-7965c06bd7e3", 6000);
        builder.AddPipelineEntry(header, "81101016-a2e3-482c-98c4-5b8de6296538", 8000);
        auto entry3 = builder.AddPipelineEntry(header, "1b7fd11d-f4f8-406e-b58b-871918d4b2e3", 8000);

        builder.AddStageValidation(entry1, builder.sample_graphics_pipeline_json, SPV_ENV_VULKAN_1_2,
                                   {builder.sample_vertex_shader_spv, builder.sample_fragment_shader_spv});
        builder.AddStageValidation(entry3, builder.sample_compute_pipeline_json, SPV_ENV_VULKAN_1_2,
                                   {builder.sample_compute_shader_spv});

        pipeline_caches.push_back(builder.GetData());
        builder.Clear();
    }

    // Create a pipeline cache with invalid pipeline index stride
    {
        auto header = builder.AddDefaultHeaderVersionSCOne();
        builder.AddPipelineEntry(header, "21b63c03-7484-4a69-b420-cda943cb5008", 4000);
        header->pipelineIndexStride = 32;
        pipeline_caches.push_back(builder.GetData());
        builder.Clear();
    }

    // Create a pipeline cache with duplicate pipeline identifiers
    {
        auto header = builder.AddDefaultHeaderVersionSCOne();
        builder.AddPipelineEntry(header, "3ddda923-b6fc-433e-803c-822c1bccbc05", 4000);
        builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 6000);  // duplicate
        builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 8000);  // duplicate
        builder.AddPipelineEntry(header, "73ada7f2-9cc6-48ed-a193-24d0091f4f95", 4000);
        pipeline_caches.push_back(builder.GetData());
        builder.Clear();
    }

    std::vector<VkPipelineCacheCreateInfo> create_infos(pipeline_caches.size(), vku::InitStruct<VkPipelineCacheCreateInfo>());
    for (size_t i = 0; i < pipeline_caches.size(); ++i) {
        create_infos[i].flags = VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT | VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT;
        create_infos[i].initialDataSize = pipeline_caches[i].size();
        create_infos[i].pInitialData = pipeline_caches[i].data();
    }

    m_errorMonitor->SetDesiredFailureMsg(kWarningBit,
                                         "VUID-VkPipelineCacheHeaderVersionSafetyCriticalOne-pipelineIndexOffset-05079");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheHeaderVersionOne-headerVersion-05076");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit,
                                         "VUID-VkPipelineCacheHeaderVersionSafetyCriticalOne-pipelineIndexStride-05078");
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineCacheCreateInfo-pInitialData-05139");
    TestPipelineCacheData(create_infos);
    m_errorMonitor->VerifyFound();
}
