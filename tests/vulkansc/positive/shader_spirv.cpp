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
#include "../framework/vksc_test_pipeline_helper.h"

TEST_F(VkSCPositiveShaderSpirvTest, Atomics) {
    TEST_DESCRIPTION("SPIR-V extension uses atomic instructions with shaderAtomicInstructions enabled.");

    RETURN_IF_SKIP(InitFramework());

    vksc::ComputePipelineBuilder builder(this);
    builder.AddBinding(0, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER);
    builder.Init(vksc::Shader::Compute(kComputeShaderAtomicInstructionsSpv));

    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
    sc_10_features.shaderAtomicInstructions = VK_TRUE;

    RETURN_IF_SKIP(InitState(nullptr, &sc_10_features));

    builder.CreatePipeline(*m_device);
}
