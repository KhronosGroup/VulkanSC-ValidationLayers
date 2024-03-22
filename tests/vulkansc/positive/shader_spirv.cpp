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

TEST_F(VkSCPositiveShaderSpirvTest, ComputeEntryPointNameNull) {
    TEST_DESCRIPTION(
        "If entry point name is not specified, but pipeline JSON data has entry point name info,"
        " then SPIR-V dependent validation is not disabled.");

    vksc::ComputePipelineBuilder builder(this);
    builder.SetPipelineJsonData(kSampleComputePipelineJson);
    builder.Init(vksc::Shader::Compute(kSampleComputeShaderSpv).EntryPoint(nullptr));

    RETURN_IF_SKIP(Init());

    m_errorMonitor->ExpectSuccess(kErrorBit | kWarningBit);
    builder.CreatePipeline(*m_device);
}

TEST_F(VkSCPositiveShaderSpirvTest, GraphicsEntryPointNameNull) {
    TEST_DESCRIPTION(
        "If entry point name is not specified, but pipeline JSON data has entry point name info,"
        " then SPIR-V dependent validation is not disabled.");

    vksc::GraphicsPipelineBuilder builder(this);
    builder.SetPipelineJsonData(kSampleGraphicsPipelineJson);
    builder.InitVsFs(vksc::Shader::Vertex(kSampleVertexShaderSpv), vksc::Shader::Fragment(kSampleFragmentShaderSpv));

    RETURN_IF_SKIP(Init());
    InitRenderTarget();

    builder.stage_ci[0].pName = "main";
    builder.stage_ci[1].pName = nullptr;
    builder.CreatePipeline(*m_device);

    builder.stage_ci[0].pName = nullptr;
    builder.stage_ci[1].pName = "main";
    m_errorMonitor->ExpectSuccess(kErrorBit | kWarningBit);
    builder.CreatePipeline(*m_device);
}

TEST_F(VkSCPositiveShaderSpirvTest, MissingSpecializationInfo) {
    TEST_DESCRIPTION(
        "If specialization info is missing, but pipeline JSON data has specialization info,"
        " then SPIR-V dependent validation is not disabled.");

    vksc::ComputePipelineBuilder builder(this);
    builder.AddBinding(0, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER);
    builder.SetPipelineJsonData(kSampleComputePipelineWithSpecializationConstantJson);
    builder.Init(vksc::Shader::Compute(kComputeShaderWithSpecializationConstantSpv));

    RETURN_IF_SKIP(Init());

    m_errorMonitor->ExpectSuccess(kErrorBit | kWarningBit);
    builder.CreatePipeline(*m_device);
}
