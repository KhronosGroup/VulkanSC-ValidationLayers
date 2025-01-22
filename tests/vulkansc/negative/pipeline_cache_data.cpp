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

TEST_F(VkSCNegativePipelineCacheData, HeaderTooSmall) {
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

TEST_F(VkSCNegativePipelineCacheData, InvalidHeaderSize) {
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

TEST_F(VkSCNegativePipelineCacheData, InvalidHeaderVersion) {
    TEST_DESCRIPTION("Pipeline cache data - headerVersion is not VK_PIPELINE_CACHE_HEADER_VERSION_SAFETY_CRITICAL_ONE");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    create_info = builder.MakeCreateInfo();

    header->headerVersionOne.headerVersion = VK_PIPELINE_CACHE_HEADER_VERSION_ONE;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheHeaderVersionOne-headerVersion-05076");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCNegativePipelineCacheData, InvalidValidationVersion) {
    TEST_DESCRIPTION("Pipeline cache data - validationVersion is not VK_PIPELINE_CACHE_VALIDATION_VERSION_SAFETY_CRITICAL_ONE");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    create_info = builder.MakeCreateInfo();

    header->validationVersion = static_cast<VkPipelineCacheValidationVersion>(2);
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheHeaderVersionSafetyCriticalOne-validationVersion-05077");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCNegativePipelineCacheData, InvalidPipelineIndexStride) {
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
    m_errorMonitor->SetAllowedFailureMsg("does not contain SPIR-V module data");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit,
                                         "VUID-VkPipelineCacheHeaderVersionSafetyCriticalOne-pipelineIndexStride-05078");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCNegativePipelineCacheData, PipelineIndexOutOfBounds) {
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

TEST_F(VkSCNegativePipelineCacheData, DuplicatePipelineIdentifier) {
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

TEST_F(VkSCNegativePipelineCacheData, InvalidPipelineIndexEntryValues) {
    TEST_DESCRIPTION("Pipeline cache data - test invalid cases for pipeline index entry values");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    std::vector<vksc::PipelineCacheBuilder::SCIndexEntry<>> entries = {
        builder.AddPipelineEntry(header, "3ddda923-b6fc-433e-803c-822c1bccbc05", 4000),
        builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 6000),
        builder.AddPipelineEntry(header, "b23d0e5c-70a0-4d67-8781-99ec3798ed31", 5000)};

    // jsonOffset must be zero if jsonSize is zero
    entries[1]->jsonOffset = 42;
    m_errorMonitor->SetAllowedFailureMsg("does not contain SPIR-V module data");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-jsonSize-05080");
    TestPipelineCacheData({builder.MakeCreateInfo()});
    entries[1]->jsonOffset = 0;

    // stageIndexCount must be zero if jsonSize is zero (either both JSON and stage data is available or neither)
    entries[2]->stageIndexCount = 1;
    entries[2]->stageIndexStride = 16;
    entries[2]->stageIndexOffset = builder.GetData().size();
    m_errorMonitor->SetAllowedFailureMsg("does not contain SPIR-V module data");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-jsonSize-05081");
    m_errorMonitor->SetAllowedFailureMsg("VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05084");
    TestPipelineCacheData({builder.MakeCreateInfo()});
    entries[2]->stageIndexCount = 0;
    entries[2]->stageIndexStride = 0;
    entries[2]->stageIndexOffset = 0;

    // stageIndexOffset must be zero if stageIndexCount is zero
    entries[0]->stageIndexOffset = 42;
    m_errorMonitor->SetAllowedFailureMsg("does not contain SPIR-V module data");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05082");
    TestPipelineCacheData({builder.MakeCreateInfo()});
    entries[0]->stageIndexOffset = 0;

    // stageIndexStride must be zero if stageIndexCount is zero
    entries[1]->stageIndexStride = 42;
    m_errorMonitor->SetAllowedFailureMsg("does not contain SPIR-V module data");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05082");
    TestPipelineCacheData({builder.MakeCreateInfo()});
    entries[1]->stageIndexStride = 0;
}

TEST_F(VkSCNegativePipelineCacheData, JsonDataOutOfBounds) {
    TEST_DESCRIPTION("Pipeline cache data - JSON data for pipeline out of bounds");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120002", 4000);
    auto entry = builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    builder.AddStageValidation(entry, kSampleGraphicsPipelineJson, SPV_ENV_VULKAN_1_2,
                               {kSampleVertexShaderSpv, kSampleFragmentShaderSpv});

    entry->jsonOffset = builder.GetData().size() - 4;

    m_errorMonitor->SetAllowedFailureMsg("does not contain SPIR-V module data");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-jsonSize-08991");
    TestPipelineCacheData({builder.MakeCreateInfo()});
}

TEST_F(VkSCNegativePipelineCacheData, InvalidStageIndexStride) {
    TEST_DESCRIPTION("Pipeline cache data - stageIndexStride must be at least 16");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120002", 4000);
    auto entry = builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    using PrivData = uint64_t;
    builder.AddStageValidation<PrivData>(entry, kSampleGraphicsPipelineJson, SPV_ENV_VULKAN_1_2,
                                         {kSampleVertexShaderSpv, kSampleFragmentShaderSpv});

    // Should succeed even with a stride larger than 16
    create_info = builder.MakeCreateInfo();
    TestPipelineCacheData({create_info});

    // But fail with a smaller one
    entry->stageIndexStride = 12;
    m_errorMonitor->SetAllowedFailureMsg("does not contain SPIR-V module data");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05083");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCNegativePipelineCacheData, StageIndexOutOfBounds) {
    TEST_DESCRIPTION("Pipeline cache data - stage index entry out of bounds");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120002", 4000);
    auto entry = builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    builder.AddStageValidation(entry, kSampleGraphicsPipelineJson, SPV_ENV_VULKAN_1_2,
                               {kSampleVertexShaderSpv, kSampleFragmentShaderSpv});

    create_info = builder.MakeCreateInfo();
    create_info.initialDataSize = static_cast<size_t>(entry->stageIndexOffset + entry->stageIndexStride + 12);
    m_errorMonitor->SetAllowedFailureMsg("does not contain SPIR-V module data");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05084");
    TestPipelineCacheData({create_info});
}

TEST_F(VkSCNegativePipelineCacheData, InvalidStageIndexEntryValues) {
    TEST_DESCRIPTION("Pipeline cache data - test invalid cases for stage index entry values");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    std::vector<vksc::PipelineCacheBuilder::SCIndexEntry<>> entries = {
        builder.AddPipelineEntry(header, "3ddda923-b6fc-433e-803c-822c1bccbc05", 4000),
        builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 6000),
        builder.AddPipelineEntry(header, "b23d0e5c-70a0-4d67-8781-99ec3798ed31", 5000)};

    builder.AddStageValidation(entries[1], kSampleGraphicsPipelineJson, SPV_ENV_VULKAN_1_2,
                               {kSampleVertexShaderSpv, kSampleFragmentShaderSpv});
    builder.AddStageValidation(entries[2], kSampleComputePipelineJson, SPV_ENV_VULKAN_1_2, {kSampleComputeShaderSpv});

    // codeSize cannot be zero
    auto stage_1_1 = builder.GetStageValidation(entries[1], 1);
    auto orig_code_size_1_1 = stage_1_1->codeSize;
    stage_1_1->codeSize = 0;
    m_errorMonitor->SetAllowedFailureMsg("does not contain SPIR-V module data");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheStageValidationIndexEntry-codeSize-05085");
    TestPipelineCacheData({builder.MakeCreateInfo()});
    stage_1_1->codeSize = orig_code_size_1_1;

    // codeSize must be a multiple of 4
    auto stage_2_0 = builder.GetStageValidation(entries[2], 0);
    auto orig_code_size_2_0 = stage_2_0->codeSize;
    stage_2_0->codeSize -= 1;
    m_errorMonitor->SetAllowedFailureMsg("does not contain SPIR-V module data");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheStageValidationIndexEntry-codeSize-05086");
    TestPipelineCacheData({builder.MakeCreateInfo()});
    stage_2_0->codeSize = orig_code_size_2_0;
}

TEST_F(VkSCNegativePipelineCacheData, StageCodeDataOutOfBounds) {
    TEST_DESCRIPTION("Pipeline cache data - stage code data out of bounds");

    RETURN_IF_SKIP(InitFramework());

    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120002", 4000);
    auto entry = builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    builder.AddStageValidation(entry, kSampleGraphicsPipelineJson, SPV_ENV_VULKAN_1_2,
                               {kSampleVertexShaderSpv, kSampleFragmentShaderSpv});

    builder.GetStageValidation(entry, 1)->codeOffset = builder.GetData().size() - 4;

    m_errorMonitor->SetAllowedFailureMsg("does not contain SPIR-V module data");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheStageValidationIndexEntry-codeOffset-05087");
    TestPipelineCacheData({builder.MakeCreateInfo()});
}

TEST_F(VkSCNegativePipelineCacheData, MultipleProblems) {
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

        builder.AddStageValidation(entry1, kSampleGraphicsPipelineJson, SPV_ENV_VULKAN_1_2,
                                   {kSampleVertexShaderSpv, kSampleFragmentShaderSpv});
        builder.AddStageValidation(entry3, kSampleComputePipelineJson, SPV_ENV_VULKAN_1_2, {kSampleComputeShaderSpv});

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

    m_errorMonitor->SetAllowedFailureMsg("does not contain SPIR-V module data");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit,
                                         "VUID-VkPipelineCacheHeaderVersionSafetyCriticalOne-pipelineIndexOffset-05079");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "VUID-VkPipelineCacheHeaderVersionOne-headerVersion-05076");
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit,
                                         "VUID-VkPipelineCacheHeaderVersionSafetyCriticalOne-pipelineIndexStride-05078");
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineCacheCreateInfo-pInitialData-05139");
    TestPipelineCacheData(create_infos);
}

TEST_F(VkSCNegativePipelineCacheData, InvalidSpirvHeaderSize) {
    TEST_DESCRIPTION("Test that an error is produced for a SPIR-V module with bad header");

    RETURN_IF_SKIP(InitFramework());

    std::vector<uint32_t> header_too_small = {0x07230203};
    auto header = builder.AddDefaultHeaderVersionSCOne();
    auto entry = builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120001", 4000);
    builder.AddStageValidation(entry, kSampleComputePipelineJson, {header_too_small});

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkShaderModuleCreateInfo-pCode-08736");
    TestPipelineCacheData({builder.MakeCreateInfo()});
}

TEST_F(VkSCNegativePipelineCacheData, InvalidSpirvMagic) {
    TEST_DESCRIPTION("Test that an error is produced for a SPIR-V module with bad header");

    RETURN_IF_SKIP(InitFramework());

    std::vector<uint32_t> header_bad_magic = {0xBAADF00D, 99, 0};
    auto header = builder.AddDefaultHeaderVersionSCOne();
    auto entry = builder.AddPipelineEntry(header, "1de725b8-e36d-11ed-b5ea-0242ac120002", 4000);
    builder.AddStageValidation(entry, kSampleComputePipelineJson, {header_bad_magic});

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkShaderModuleCreateInfo-pCode-08736");
    TestPipelineCacheData({builder.MakeCreateInfo()});
}

TEST_F(VkSCNegativePipelineCacheData, AllPipelinesMissingSpirvDebugInfo) {
    TEST_DESCRIPTION("A warning is issued if all pipelines in the pipeline cache data are missing SPIR-V debug info.");

    RETURN_IF_SKIP(InitFramework());
    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "3ddda923-b6fc-433e-803c-822c1bccbc05", 4000);
    builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);
    builder.AddPipelineEntry(header, "73ada7f2-9cc6-48ed-a193-24d0091f4f95", 4000);

    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "does not contain SPIR-V module data for any pipelines");
    TestPipelineCacheData({builder.MakeCreateInfo()});
}

TEST_F(VkSCNegativePipelineCacheData, SomePipelinesMissingSpirvDebugInfo) {
    TEST_DESCRIPTION("A warning is issued if some pipelines in the pipeline cache data are missing SPIR-V debug info.");

    RETURN_IF_SKIP(InitFramework());
    auto header = builder.AddDefaultHeaderVersionSCOne();
    std::vector<vksc::PipelineCacheBuilder::SCIndexEntry<>> entries = {
        builder.AddPipelineEntry(header, "3ddda923-b6fc-433e-803c-822c1bccbc05", 4000),
        builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000),
        builder.AddPipelineEntry(header, "73ada7f2-9cc6-48ed-a193-24d0091f4f95", 4000)};
    builder.AddStageValidation(entries[0], kSampleComputePipelineJson, SPV_ENV_VULKAN_1_2, {kSampleComputeShaderSpv});
    builder.AddStageValidation(entries[2], kSampleComputePipelineJson, SPV_ENV_VULKAN_1_2, {kSampleComputeShaderSpv});

    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "does not contain SPIR-V module data for some pipelines");
    TestPipelineCacheData({builder.MakeCreateInfo()});
}
