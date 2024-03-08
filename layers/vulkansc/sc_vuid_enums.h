/* Copyright (c) 2023-2024 The Khronos Group Inc.
 * Copyright (c) 2023-2024 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

// clang-format off

[[maybe_unused]] static const char *kVUID_SC_RemovedCommand = "UNASSIGNED-VulkanSC-removed-command";

// Pipeline cache data related warnings
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_TooSmall =
    "UNASSIGNED-SC-PipelineCacheData-tooSmall";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_InvalidHeaderSize =
    "VUID-VkPipelineCacheHeaderVersionOne-headerSize-05075";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_UnrecognizedHeaderVersion =
    "VUID-VkPipelineCacheHeaderVersionOne-headerVersion-05076";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_UnrecognizedValidationVersion =
    "VUID-VkPipelineCacheHeaderVersionSafetyCriticalOne-validationVersion-05077";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_PipelineIndexStrideTooSmall =
    "VUID-VkPipelineCacheHeaderVersionSafetyCriticalOne-pipelineIndexStride-05078";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_PipelineIndexOutOfBounds =
    "VUID-VkPipelineCacheHeaderVersionSafetyCriticalOne-pipelineIndexOffset-05079";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_JsonOffsetAndSizeInconsistent =
    "VUID-VkPipelineCacheSafetyCriticalIndexEntry-jsonSize-05080";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_JsonDataOutOfBounds =
    "VUID-VkPipelineCacheSafetyCriticalIndexEntry-jsonSize-08991";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_JsonSizeStageIndexCountInconsistent =
    "VUID-VkPipelineCacheSafetyCriticalIndexEntry-jsonSize-05081";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_StageIndexOffsetStrideCountInconsistent =
    "VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05082";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_StageIndexStrideTooSmall =
    "VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05083";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_StageIndexOutOfBounds =
    "VUID-VkPipelineCacheSafetyCriticalIndexEntry-stageIndexCount-05084";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_CodeSizeZero =
    "VUID-VkPipelineCacheStageValidationIndexEntry-codeSize-05085";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_CodeSizeNotMultipleOfFour =
    "VUID-VkPipelineCacheStageValidationIndexEntry-codeSize-05086";
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_CodeDataOutOfBounds =
    "VUID-VkPipelineCacheStageValidationIndexEntry-codeOffset-05087";

// Other device create time warnings
[[maybe_unused]] static const char *kVUID_SC_CreateDevice_MissingVulkanSC10Features =
    "UNASSIGNED-VkDeviceCreateInfo-pNext-VkPhysicalDeviceVulkanSC10Features";
[[maybe_unused]] static const char *kVUID_SC_CreateDevice_MissingObjectReservationInfo =
    "UNASSIGNED-VkDeviceCreateInfo-pNext-VkDeviceObjectReservationCreateInfo";

// SPIR-V related validation errors/warnings for cases
// where the Vulkan SC spec does not have explicit VUs
[[maybe_unused]] static const char *kVUID_SC_PipelineCacheData_SpirvDepValMissingInfo =
    "UNASSIGNED-VkPipelineShaderStageCreateInfo-pName-SpirvDepValMissingInfo";

// clang-format on
