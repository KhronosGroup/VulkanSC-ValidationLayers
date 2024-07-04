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

TEST_F(VkSCNegativeShaderSpirv, ComputeEntryPointNameMismatch) {
    TEST_DESCRIPTION("If entry point name is specified, then it must match the one in the SPIR-V module when available.");

    vksc::ComputePipelineBuilder builder(this);
    builder.Init(vksc::Shader::Compute(kSampleComputeShaderSpv).EntryPoint("WrongEntryPointName"));

    RETURN_IF_SKIP(Init());

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineShaderStageCreateInfo-pName-05027");
    builder.CreatePipeline(*m_device);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeShaderSpirv, GraphicsEntryPointNameMismatch) {
    TEST_DESCRIPTION("If entry point name is specified, then it must match the one in the SPIR-V module when available.");

    vksc::GraphicsPipelineBuilder builder(this);
    builder.InitVsFs(vksc::Shader::Vertex(kSampleVertexShaderSpv), vksc::Shader::Fragment(kSampleFragmentShaderSpv));

    RETURN_IF_SKIP(Init());
    InitRenderTarget();

    const char* wrong_name = "WrongEntryPointName";

    builder.stage_ci[0].pName = "main";
    builder.stage_ci[1].pName = wrong_name;
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineShaderStageCreateInfo-pName-05027");
    builder.CreatePipeline(*m_device);
    m_errorMonitor->VerifyFound();

    builder.stage_ci[0].pName = wrong_name;
    builder.stage_ci[1].pName = "main";
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineShaderStageCreateInfo-pName-05027");
    builder.CreatePipeline(*m_device);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeShaderSpirv, ComputeEntryPointNameNull) {
    TEST_DESCRIPTION("If entry point name is not specified, then SPIR-V dependent validation is disabled.");

    vksc::ComputePipelineBuilder builder(this);
    builder.Init(vksc::Shader::Compute(kSampleComputeShaderSpv).EntryPoint(nullptr));

    RETURN_IF_SKIP(Init());

    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "UNASSIGNED-PipelineCacheData-SpirvDepValMissingInfo");
    builder.CreatePipeline(*m_device);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeShaderSpirv, GraphicsEntryPointNameNull) {
    TEST_DESCRIPTION("If entry point name is not specified, then SPIR-V dependent validation is disabled.");

    vksc::GraphicsPipelineBuilder builder(this);
    builder.InitVsFs(vksc::Shader::Vertex(kSampleVertexShaderSpv), vksc::Shader::Fragment(kSampleFragmentShaderSpv));

    RETURN_IF_SKIP(Init());
    InitRenderTarget();

    builder.stage_ci[0].pName = "main";
    builder.stage_ci[1].pName = nullptr;
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "UNASSIGNED-PipelineCacheData-SpirvDepValMissingInfo");
    builder.CreatePipeline(*m_device);
    m_errorMonitor->VerifyFound();

    builder.stage_ci[0].pName = nullptr;
    builder.stage_ci[1].pName = "main";
    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "UNASSIGNED-PipelineCacheData-SpirvDepValMissingInfo");
    builder.CreatePipeline(*m_device);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeShaderSpirv, MissingSpecializationInfo) {
    TEST_DESCRIPTION("If specialization info is missing, then SPIR-V dependent validation is disabled.");

    vksc::ComputePipelineBuilder builder(this);
    builder.AddBinding(0, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER);
    builder.Init(vksc::Shader::Compute(kComputeShaderWithSpecializationConstantSpv));

    RETURN_IF_SKIP(Init());

    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "UNASSIGNED-PipelineCacheData-SpirvDepValMissingInfo");
    builder.CreatePipeline(*m_device);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeShaderSpirv, InvalidSpirv) {
    TEST_DESCRIPTION("Expect spirv-val reporting an error due to the use of an invalid SPIR-V extension in OpExtension.");

    const char* vertex_source = R"spirv(
               OpCapability Shader
          %1 = OpExtInstImport "GLSL.std.450"
               OpMemoryModel Logical GLSL450
               OpEntryPoint Vertex %4 "main"
               OpSource GLSL 450
               OpExtension "GL_EXT_scalar_block_layout"
               OpName %4 "main"
          %2 = OpTypeVoid
          %3 = OpTypeFunction %2
          %4 = OpFunction %2 None %3
          %5 = OpLabel
               OpReturn
               OpFunctionEnd
        )spirv";

    vksc::GraphicsPipelineBuilder builder(this);
    builder.InitVsFs(vksc::Shader::Vertex(vertex_source), vksc::Shader::Fragment(kSampleFragmentShaderSpv));

    RETURN_IF_SKIP(Init());

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkShaderModuleCreateInfo-pCode-08737");
    builder.CreatePipelineCache(*m_device);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeShaderSpirv, MissingShaderCapability) {
    TEST_DESCRIPTION("Missing Shader capability in the SPIR-V code.");

    const char* vertex_source = R"spirv(
            OpMemoryModel Logical GLSL450
            OpEntryPoint Vertex %main "main"
            OpSource GLSL 450
    %void = OpTypeVoid
       %3 = OpTypeFunction %void
    %main = OpFunction %void None %3
       %5 = OpLabel
            OpReturn
            OpFunctionEnd
        )spirv";

    vksc::GraphicsPipelineBuilder builder(this);
    builder.InitVsFs(vksc::Shader::Vertex(vertex_source), vksc::Shader::Fragment(kSampleFragmentShaderSpv));

    RETURN_IF_SKIP(Init());

    // TODO: Vulkan SC - this should be triggering VUID 08738, but actually triggers 08737
    // because VVL does not check for 08738 and relies on spirv-val to detect the error
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkShaderModuleCreateInfo-pCode-08737");
    builder.CreatePipelineCache(*m_device);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeShaderSpirv, CapabilityNotSupported) {
    TEST_DESCRIPTION("SPIR-V capability is used that is not supported by the API.");

    const char* source = R"spirv(
            OpCapability Shader
            OpCapability Linkage
       %1 = OpExtInstImport "GLSL.std.450"
            OpMemoryModel Logical GLSL450
            OpEntryPoint GLCompute %main "main"
            OpExecutionMode %main LocalSize 2 1 1
            OpSource GLSL 450
    %void = OpTypeVoid
       %3 = OpTypeFunction %void
    %main = OpFunction %void None %3
       %5 = OpLabel
            OpReturn
            OpFunctionEnd
        )spirv";

    vksc::ComputePipelineBuilder builder(this);
    builder.Init(vksc::Shader::Compute(source));

    RETURN_IF_SKIP(Init());

    m_errorMonitor->SetAllowedFailureMsg("VUID-VkShaderModuleCreateInfo-pCode-08737");
    builder.CreatePipelineCache(*m_device);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeShaderSpirv, CapabilityRequirementNotMet) {
    TEST_DESCRIPTION("SPIR-V capability is used without meeting its prerequisites.");

    const char* source = R"spirv(
            OpCapability Shader
            OpCapability SparseResidency
       %1 = OpExtInstImport "GLSL.std.450"
            OpMemoryModel Logical GLSL450
            OpEntryPoint GLCompute %main "main"
            OpExecutionMode %main LocalSize 2 1 1
            OpSource GLSL 450
    %void = OpTypeVoid
       %3 = OpTypeFunction %void
    %main = OpFunction %void None %3
       %5 = OpLabel
            OpReturn
            OpFunctionEnd
        )spirv";

    vksc::ComputePipelineBuilder builder(this);
    builder.Init(vksc::Shader::Compute(source));

    RETURN_IF_SKIP(Init());

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkShaderModuleCreateInfo-pCode-08740");
    builder.CreatePipelineCache(*m_device);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeShaderSpirv, ExtensionNotSupported) {
    TEST_DESCRIPTION("SPIR-V extension is used that is not supported by the API.");

    const char* source = R"spirv(
            OpCapability Shader
            OpExtension "GL_EXT_scalar_block_layout"
       %1 = OpExtInstImport "GLSL.std.450"
            OpMemoryModel Logical GLSL450
            OpEntryPoint GLCompute %main "main"
            OpExecutionMode %main LocalSize 2 1 1
            OpSource GLSL 450
    %void = OpTypeVoid
       %3 = OpTypeFunction %void
    %main = OpFunction %void None %3
       %5 = OpLabel
            OpReturn
            OpFunctionEnd
        )spirv";

    vksc::ComputePipelineBuilder builder(this);
    builder.Init(vksc::Shader::Compute(source));

    RETURN_IF_SKIP(Init());

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkShaderModuleCreateInfo-pCode-08741");
    builder.CreatePipelineCache(*m_device);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeShaderSpirv, ExtensionRequirementNotMet) {
    TEST_DESCRIPTION("SPIR-V extension is used without meeting its prerequisites.");

    const char* source = R"spirv(
            OpCapability Shader
            OpExtension "SPV_EXT_shader_stencil_export"
       %1 = OpExtInstImport "GLSL.std.450"
            OpMemoryModel Logical GLSL450
            OpEntryPoint GLCompute %main "main"
            OpExecutionMode %main LocalSize 2 1 1
            OpSource GLSL 450
    %void = OpTypeVoid
       %3 = OpTypeFunction %void
    %main = OpFunction %void None %3
       %5 = OpLabel
            OpReturn
            OpFunctionEnd
        )spirv";

    vksc::ComputePipelineBuilder builder(this);
    builder.Init(vksc::Shader::Compute(source));

    RETURN_IF_SKIP(Init());

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkShaderModuleCreateInfo-pCode-08742");
    builder.CreatePipelineCache(*m_device);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeShaderSpirv, Atomics) {
    TEST_DESCRIPTION("SPIR-V extension uses atomic instructions without enabling shaderAtomicInstructions.");

    vksc::ComputePipelineBuilder builder(this);
    builder.AddBinding(0, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER);
    builder.Init(vksc::Shader::Compute(kComputeShaderAtomicInstructionsSpv));

    AddDisabledFeature(vkt::Feature::shaderAtomicInstructions);
    RETURN_IF_SKIP(Init());

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-RuntimeSpirv-OpAtomic-05091");
    builder.CreatePipeline(*m_device);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeShaderSpirv, LayoutCrossValidation) {
    TEST_DESCRIPTION("Smoke test for cross-validation of SPIR-V code with pipeline layout.");

    vksc::ComputePipelineBuilder builder(this);
    builder.Init(vksc::Shader::Compute(kComputeShaderAtomicInstructionsSpv));

    AddRequiredFeature(vkt::Feature::shaderAtomicInstructions);
    RETURN_IF_SKIP(Init());

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkComputePipelineCreateInfo-layout-07988");
    builder.CreatePipeline(*m_device);
    m_errorMonitor->VerifyFound();
}
