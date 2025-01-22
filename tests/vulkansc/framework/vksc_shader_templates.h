/*
 * Copyright (c) 2024-2025 The Khronos Group Inc.
 * Copyright (c) 2024-2025 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */
#pragma once

[[maybe_unused]] static char const kSampleComputeShaderSpv[] = R"spirv(
            OpCapability Shader
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

[[maybe_unused]] static char const kSampleVertexShaderSpv[] = R"spirv(
            OpCapability Shader
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

[[maybe_unused]] static char const kSampleFragmentShaderSpv[] = R"spirv(
            OpCapability Shader
            OpCapability ImageBuffer
            OpMemoryModel Logical GLSL450
            OpEntryPoint Fragment %main "main"
            OpExecutionMode %main OriginUpperLeft
    %void = OpTypeVoid
       %3 = OpTypeFunction %void
    %main = OpFunction %void None %3
       %5 = OpLabel
            OpReturn
            OpFunctionEnd
)spirv";

[[maybe_unused]] static char const kComputeShaderAtomicInstructionsSpv[] = R"spirv(
               OpCapability Shader
          %1 = OpExtInstImport "GLSL.std.450"
               OpMemoryModel Logical GLSL450
               OpEntryPoint GLCompute %main "main" %_
               OpExecutionMode %main LocalSize 1 1 1
               OpSource GLSL 450
               OpName %main "main"
               OpName %Test "Test"
               OpMemberName %Test 0 "value"
               OpName %_ ""
               OpMemberDecorate %Test 0 Offset 0
               OpDecorate %Test Block
               OpDecorate %_ DescriptorSet 0
               OpDecorate %_ Binding 0
       %void = OpTypeVoid
          %3 = OpTypeFunction %void
       %uint = OpTypeInt 32 0
       %Test = OpTypeStruct %uint
%_ptr_StorageBuffer_Test = OpTypePointer StorageBuffer %Test
          %_ = OpVariable %_ptr_StorageBuffer_Test StorageBuffer
        %int = OpTypeInt 32 1
      %int_0 = OpConstant %int 0
%_ptr_StorageBuffer_uint = OpTypePointer StorageBuffer %uint
     %uint_1 = OpConstant %uint 1
     %uint_0 = OpConstant %uint 0
       %main = OpFunction %void None %3
          %5 = OpLabel
         %13 = OpAccessChain %_ptr_StorageBuffer_uint %_ %int_0
         %16 = OpAtomicIAdd %uint %13 %uint_1 %uint_0 %uint_1
               OpReturn
               OpFunctionEnd
        )spirv";

[[maybe_unused]] static char const kComputeShaderWithSpecializationConstantSpv[] = R"spirv(
               OpCapability Shader
          %1 = OpExtInstImport "GLSL.std.450"
               OpMemoryModel Logical GLSL450
               OpEntryPoint GLCompute %main "main" %_
               OpExecutionMode %main LocalSize 1 1 1
               OpSource GLSL 450
               OpName %main "main"
               OpName %Test "Test"
               OpMemberName %Test 0 "value"
               OpName %_ ""
               OpName %constValue "constValue"
               OpMemberDecorate %Test 0 Offset 0
               OpDecorate %Test Block
               OpDecorate %_ DescriptorSet 0
               OpDecorate %_ Binding 0
               OpDecorate %constValue SpecId 0
       %void = OpTypeVoid
          %3 = OpTypeFunction %void
       %uint = OpTypeInt 32 0
       %Test = OpTypeStruct %uint
%_ptr_StorageBuffer_Test = OpTypePointer StorageBuffer %Test
          %_ = OpVariable %_ptr_StorageBuffer_Test StorageBuffer
        %int = OpTypeInt 32 1
      %int_0 = OpConstant %int 0
 %constValue = OpSpecConstant %uint 0
%_ptr_StorageBuffer_uint = OpTypePointer StorageBuffer %uint
       %main = OpFunction %void None %3
          %5 = OpLabel
         %14 = OpAccessChain %_ptr_StorageBuffer_uint %_ %int_0
               OpStore %14 %constValue
               OpReturn
               OpFunctionEnd
        )spirv";
