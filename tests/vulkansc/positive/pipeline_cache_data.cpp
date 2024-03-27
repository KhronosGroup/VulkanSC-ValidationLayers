/*
 * Copyright (c) 2023-2024 The Khronos Group Inc.
 * Copyright (c) 2023-2024 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#include "../framework/vksc_layer_validation_tests.h"

TEST_F(VkSCPositivePipelineCacheData, UnalignedPipelineCacheDataPointer) {
    TEST_DESCRIPTION("Pipeline cache data - test with unaligned pipeline cache data pointer");

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

    // Now test the data with different padding at the beginning that will guarantee misalignment
    std::vector<VkPipelineCacheCreateInfo> create_infos(pipeline_caches.size(), vku::InitStruct<VkPipelineCacheCreateInfo>());
    for (size_t i = 0; i < pipeline_caches.size(); ++i) {
        create_infos[i].flags = VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT | VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT;
        create_infos[i].initialDataSize = pipeline_caches[i].size();
    }
    for (uint32_t padding = 1; padding < 4; ++padding) {
        for (size_t i = 0; i < pipeline_caches.size(); ++i) {
            pipeline_caches[i].insert(pipeline_caches[i].begin(), 0xDD);
            create_infos[i].pInitialData = pipeline_caches[i].data() + padding;
        }
        TestPipelineCacheData(create_infos);
    }
}
