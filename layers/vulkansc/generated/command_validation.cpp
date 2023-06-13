// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See command_validation_generator.py for modifications


/***************************************************************************
 *
 * Copyright (c) 2021-2023 The Khronos Group Inc.
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
 ****************************************************************************/

#include "error_message/logging.h"
#include "core_checks/core_validation.h"

static const std::array<const char *, CMD_RANGE_SIZE> kGeneratedMustBeRecordingList = {{
    kVUIDUndefined,
    "UNASSIGNED-vkCmdBeginConditionalRenderingEXT-commandBuffer-recording",
    "VUID-vkCmdBeginDebugUtilsLabelEXT-commandBuffer-recording",
    "VUID-vkCmdBeginQuery-commandBuffer-recording",
    "UNASSIGNED-vkCmdBeginQueryIndexedEXT-commandBuffer-recording",
    "VUID-vkCmdBeginRenderPass-commandBuffer-recording",
    "VUID-vkCmdBeginRenderPass2-commandBuffer-recording",
    "VUID-vkCmdBeginRenderPass2-commandBuffer-recording",
    "UNASSIGNED-vkCmdBeginRendering-commandBuffer-recording",
    "UNASSIGNED-vkCmdBeginRendering-commandBuffer-recording",
    "UNASSIGNED-vkCmdBeginTransformFeedbackEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdBeginVideoCodingKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdBindDescriptorBufferEmbeddedSamplersEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdBindDescriptorBuffersEXT-commandBuffer-recording",
    "VUID-vkCmdBindDescriptorSets-commandBuffer-recording",
    "VUID-vkCmdBindIndexBuffer-commandBuffer-recording",
    "UNASSIGNED-vkCmdBindInvocationMaskHUAWEI-commandBuffer-recording",
    "VUID-vkCmdBindPipeline-commandBuffer-recording",
    "UNASSIGNED-vkCmdBindPipelineShaderGroupNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdBindShadingRateImageNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdBindTransformFeedbackBuffersEXT-commandBuffer-recording",
    "VUID-vkCmdBindVertexBuffers-commandBuffer-recording",
    "VUID-vkCmdBindVertexBuffers2-commandBuffer-recording",
    "VUID-vkCmdBindVertexBuffers2-commandBuffer-recording",
    "VUID-vkCmdBlitImage-commandBuffer-recording",
    "VUID-vkCmdBlitImage2-commandBuffer-recording",
    "VUID-vkCmdBlitImage2-commandBuffer-recording",
    "UNASSIGNED-vkCmdBuildAccelerationStructureNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdBuildAccelerationStructuresIndirectKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdBuildAccelerationStructuresKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdBuildMicromapsEXT-commandBuffer-recording",
    "VUID-vkCmdClearAttachments-commandBuffer-recording",
    "VUID-vkCmdClearColorImage-commandBuffer-recording",
    "VUID-vkCmdClearDepthStencilImage-commandBuffer-recording",
    "UNASSIGNED-vkCmdControlVideoCodingKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdCopyAccelerationStructureKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdCopyAccelerationStructureNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdCopyAccelerationStructureToMemoryKHR-commandBuffer-recording",
    "VUID-vkCmdCopyBuffer-commandBuffer-recording",
    "VUID-vkCmdCopyBuffer2-commandBuffer-recording",
    "VUID-vkCmdCopyBuffer2-commandBuffer-recording",
    "VUID-vkCmdCopyBufferToImage-commandBuffer-recording",
    "VUID-vkCmdCopyBufferToImage2-commandBuffer-recording",
    "VUID-vkCmdCopyBufferToImage2-commandBuffer-recording",
    "VUID-vkCmdCopyImage-commandBuffer-recording",
    "VUID-vkCmdCopyImage2-commandBuffer-recording",
    "VUID-vkCmdCopyImage2-commandBuffer-recording",
    "VUID-vkCmdCopyImageToBuffer-commandBuffer-recording",
    "VUID-vkCmdCopyImageToBuffer2-commandBuffer-recording",
    "VUID-vkCmdCopyImageToBuffer2-commandBuffer-recording",
    "UNASSIGNED-vkCmdCopyMemoryIndirectNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdCopyMemoryToAccelerationStructureKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdCopyMemoryToImageIndirectNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdCopyMemoryToMicromapEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdCopyMicromapEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdCopyMicromapToMemoryEXT-commandBuffer-recording",
    "VUID-vkCmdCopyQueryPoolResults-commandBuffer-recording",
    "UNASSIGNED-vkCmdCuLaunchKernelNVX-commandBuffer-recording",
    "UNASSIGNED-vkCmdDebugMarkerBeginEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdDebugMarkerEndEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdDebugMarkerInsertEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdDecodeVideoKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdDecompressMemoryIndirectCountNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdDecompressMemoryNV-commandBuffer-recording",
    "VUID-vkCmdDispatch-commandBuffer-recording",
    "VUID-vkCmdDispatchBase-commandBuffer-recording",
    "VUID-vkCmdDispatchBase-commandBuffer-recording",
    "VUID-vkCmdDispatchIndirect-commandBuffer-recording",
    "VUID-vkCmdDraw-commandBuffer-recording",
    "UNASSIGNED-vkCmdDrawClusterHUAWEI-commandBuffer-recording",
    "UNASSIGNED-vkCmdDrawClusterIndirectHUAWEI-commandBuffer-recording",
    "VUID-vkCmdDrawIndexed-commandBuffer-recording",
    "VUID-vkCmdDrawIndexedIndirect-commandBuffer-recording",
    "VUID-vkCmdDrawIndexedIndirectCount-commandBuffer-recording",
    "VUID-vkCmdDrawIndexedIndirectCount-commandBuffer-recording",
    "VUID-vkCmdDrawIndexedIndirectCount-commandBuffer-recording",
    "VUID-vkCmdDrawIndirect-commandBuffer-recording",
    "UNASSIGNED-vkCmdDrawIndirectByteCountEXT-commandBuffer-recording",
    "VUID-vkCmdDrawIndirectCount-commandBuffer-recording",
    "VUID-vkCmdDrawIndirectCount-commandBuffer-recording",
    "VUID-vkCmdDrawIndirectCount-commandBuffer-recording",
    "UNASSIGNED-vkCmdDrawMeshTasksEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdDrawMeshTasksIndirectCountEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdDrawMeshTasksIndirectCountNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdDrawMeshTasksIndirectEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdDrawMeshTasksIndirectNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdDrawMeshTasksNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdDrawMultiEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdDrawMultiIndexedEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdEncodeVideoKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdEndConditionalRenderingEXT-commandBuffer-recording",
    "VUID-vkCmdEndDebugUtilsLabelEXT-commandBuffer-recording",
    "VUID-vkCmdEndQuery-commandBuffer-recording",
    "UNASSIGNED-vkCmdEndQueryIndexedEXT-commandBuffer-recording",
    "VUID-vkCmdEndRenderPass-commandBuffer-recording",
    "VUID-vkCmdEndRenderPass2-commandBuffer-recording",
    "VUID-vkCmdEndRenderPass2-commandBuffer-recording",
    "UNASSIGNED-vkCmdEndRendering-commandBuffer-recording",
    "UNASSIGNED-vkCmdEndRendering-commandBuffer-recording",
    "UNASSIGNED-vkCmdEndTransformFeedbackEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdEndVideoCodingKHR-commandBuffer-recording",
    "VUID-vkCmdExecuteCommands-commandBuffer-recording",
    "UNASSIGNED-vkCmdExecuteGeneratedCommandsNV-commandBuffer-recording",
    "VUID-vkCmdFillBuffer-commandBuffer-recording",
    "VUID-vkCmdInsertDebugUtilsLabelEXT-commandBuffer-recording",
    "VUID-vkCmdNextSubpass-commandBuffer-recording",
    "VUID-vkCmdNextSubpass2-commandBuffer-recording",
    "VUID-vkCmdNextSubpass2-commandBuffer-recording",
    "UNASSIGNED-vkCmdOpticalFlowExecuteNV-commandBuffer-recording",
    "VUID-vkCmdPipelineBarrier-commandBuffer-recording",
    "VUID-vkCmdPipelineBarrier2-commandBuffer-recording",
    "VUID-vkCmdPipelineBarrier2-commandBuffer-recording",
    "UNASSIGNED-vkCmdPreprocessGeneratedCommandsNV-commandBuffer-recording",
    "VUID-vkCmdPushConstants-commandBuffer-recording",
    "UNASSIGNED-vkCmdPushDescriptorSetKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdPushDescriptorSetWithTemplateKHR-commandBuffer-recording",
    "VUID-vkCmdRefreshObjectsKHR-commandBuffer-recording",
    "VUID-vkCmdResetEvent-commandBuffer-recording",
    "VUID-vkCmdResetEvent2-commandBuffer-recording",
    "VUID-vkCmdResetEvent2-commandBuffer-recording",
    "VUID-vkCmdResetQueryPool-commandBuffer-recording",
    "VUID-vkCmdResolveImage-commandBuffer-recording",
    "VUID-vkCmdResolveImage2-commandBuffer-recording",
    "VUID-vkCmdResolveImage2-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetAlphaToCoverageEnableEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetAlphaToOneEnableEXT-commandBuffer-recording",
    "VUID-vkCmdSetBlendConstants-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetCheckpointNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetCoarseSampleOrderNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetColorBlendAdvancedEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetColorBlendEnableEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetColorBlendEquationEXT-commandBuffer-recording",
    "VUID-vkCmdSetColorWriteEnableEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetColorWriteMaskEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetConservativeRasterizationModeEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetCoverageModulationModeNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetCoverageModulationTableEnableNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetCoverageModulationTableNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetCoverageReductionModeNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetCoverageToColorEnableNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetCoverageToColorLocationNV-commandBuffer-recording",
    "VUID-vkCmdSetCullMode-commandBuffer-recording",
    "VUID-vkCmdSetCullMode-commandBuffer-recording",
    "VUID-vkCmdSetDepthBias-commandBuffer-recording",
    "VUID-vkCmdSetDepthBiasEnable-commandBuffer-recording",
    "VUID-vkCmdSetDepthBiasEnable-commandBuffer-recording",
    "VUID-vkCmdSetDepthBounds-commandBuffer-recording",
    "VUID-vkCmdSetDepthBoundsTestEnable-commandBuffer-recording",
    "VUID-vkCmdSetDepthBoundsTestEnable-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetDepthClampEnableEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetDepthClipEnableEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetDepthClipNegativeOneToOneEXT-commandBuffer-recording",
    "VUID-vkCmdSetDepthCompareOp-commandBuffer-recording",
    "VUID-vkCmdSetDepthCompareOp-commandBuffer-recording",
    "VUID-vkCmdSetDepthTestEnable-commandBuffer-recording",
    "VUID-vkCmdSetDepthTestEnable-commandBuffer-recording",
    "VUID-vkCmdSetDepthWriteEnable-commandBuffer-recording",
    "VUID-vkCmdSetDepthWriteEnable-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetDescriptorBufferOffsetsEXT-commandBuffer-recording",
    "VUID-vkCmdSetDeviceMask-commandBuffer-recording",
    "VUID-vkCmdSetDeviceMask-commandBuffer-recording",
    "VUID-vkCmdSetDiscardRectangleEXT-commandBuffer-recording",
    "VUID-vkCmdSetDiscardRectangleEnableEXT-commandBuffer-recording",
    "VUID-vkCmdSetDiscardRectangleModeEXT-commandBuffer-recording",
    "VUID-vkCmdSetEvent-commandBuffer-recording",
    "VUID-vkCmdSetEvent2-commandBuffer-recording",
    "VUID-vkCmdSetEvent2-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetExclusiveScissorEnableNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetExclusiveScissorNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetExtraPrimitiveOverestimationSizeEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetFragmentShadingRateEnumNV-commandBuffer-recording",
    "VUID-vkCmdSetFragmentShadingRateKHR-commandBuffer-recording",
    "VUID-vkCmdSetFrontFace-commandBuffer-recording",
    "VUID-vkCmdSetFrontFace-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetLineRasterizationModeEXT-commandBuffer-recording",
    "VUID-vkCmdSetLineStippleEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetLineStippleEnableEXT-commandBuffer-recording",
    "VUID-vkCmdSetLineWidth-commandBuffer-recording",
    "VUID-vkCmdSetLogicOpEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetLogicOpEnableEXT-commandBuffer-recording",
    "VUID-vkCmdSetPatchControlPointsEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetPerformanceMarkerINTEL-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetPerformanceOverrideINTEL-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetPerformanceStreamMarkerINTEL-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetPolygonModeEXT-commandBuffer-recording",
    "VUID-vkCmdSetPrimitiveRestartEnable-commandBuffer-recording",
    "VUID-vkCmdSetPrimitiveRestartEnable-commandBuffer-recording",
    "VUID-vkCmdSetPrimitiveTopology-commandBuffer-recording",
    "VUID-vkCmdSetPrimitiveTopology-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetProvokingVertexModeEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetRasterizationSamplesEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetRasterizationStreamEXT-commandBuffer-recording",
    "VUID-vkCmdSetRasterizerDiscardEnable-commandBuffer-recording",
    "VUID-vkCmdSetRasterizerDiscardEnable-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetRayTracingPipelineStackSizeKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetRepresentativeFragmentTestEnableNV-commandBuffer-recording",
    "VUID-vkCmdSetSampleLocationsEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetSampleLocationsEnableEXT-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetSampleMaskEXT-commandBuffer-recording",
    "VUID-vkCmdSetScissor-commandBuffer-recording",
    "VUID-vkCmdSetScissorWithCount-commandBuffer-recording",
    "VUID-vkCmdSetScissorWithCount-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetShadingRateImageEnableNV-commandBuffer-recording",
    "VUID-vkCmdSetStencilCompareMask-commandBuffer-recording",
    "VUID-vkCmdSetStencilOp-commandBuffer-recording",
    "VUID-vkCmdSetStencilOp-commandBuffer-recording",
    "VUID-vkCmdSetStencilReference-commandBuffer-recording",
    "VUID-vkCmdSetStencilTestEnable-commandBuffer-recording",
    "VUID-vkCmdSetStencilTestEnable-commandBuffer-recording",
    "VUID-vkCmdSetStencilWriteMask-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetTessellationDomainOriginEXT-commandBuffer-recording",
    "VUID-vkCmdSetVertexInputEXT-commandBuffer-recording",
    "VUID-vkCmdSetViewport-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetViewportShadingRatePaletteNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetViewportSwizzleNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetViewportWScalingEnableNV-commandBuffer-recording",
    "UNASSIGNED-vkCmdSetViewportWScalingNV-commandBuffer-recording",
    "VUID-vkCmdSetViewportWithCount-commandBuffer-recording",
    "VUID-vkCmdSetViewportWithCount-commandBuffer-recording",
    "UNASSIGNED-vkCmdSubpassShadingHUAWEI-commandBuffer-recording",
    "UNASSIGNED-vkCmdTraceRaysIndirect2KHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdTraceRaysIndirectKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdTraceRaysKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdTraceRaysNV-commandBuffer-recording",
    "VUID-vkCmdUpdateBuffer-commandBuffer-recording",
    "VUID-vkCmdWaitEvents-commandBuffer-recording",
    "VUID-vkCmdWaitEvents2-commandBuffer-recording",
    "VUID-vkCmdWaitEvents2-commandBuffer-recording",
    "UNASSIGNED-vkCmdWriteAccelerationStructuresPropertiesKHR-commandBuffer-recording",
    "UNASSIGNED-vkCmdWriteAccelerationStructuresPropertiesNV-commandBuffer-recording",
    "VUID-vkCmdWriteBufferMarker2AMD-commandBuffer-recording",
    "UNASSIGNED-vkCmdWriteBufferMarkerAMD-commandBuffer-recording",
    "UNASSIGNED-vkCmdWriteMicromapsPropertiesEXT-commandBuffer-recording",
    "VUID-vkCmdWriteTimestamp-commandBuffer-recording",
    "VUID-vkCmdWriteTimestamp2-commandBuffer-recording",
    "VUID-vkCmdWriteTimestamp2-commandBuffer-recording",
}};

struct CommandSupportedQueueType {
    VkQueueFlags flags;
    const char* vuid;
};
static const std::array<CommandSupportedQueueType, CMD_RANGE_SIZE> kGeneratedQueueTypeList = {{
    {VK_QUEUE_FLAG_BITS_MAX_ENUM, kVUIDUndefined},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdBeginConditionalRenderingEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdBeginDebugUtilsLabelEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdBeginQuery-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "UNASSIGNED-vkCmdBeginQueryIndexedEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdBeginRenderPass-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdBeginRenderPass2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdBeginRenderPass2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdBeginRendering-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdBeginRendering-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdBeginTransformFeedbackEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "UNASSIGNED-vkCmdBeginVideoCodingKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdBindDescriptorBufferEmbeddedSamplersEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdBindDescriptorBuffersEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdBindDescriptorSets-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdBindIndexBuffer-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdBindInvocationMaskHUAWEI-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdBindPipeline-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdBindPipelineShaderGroupNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdBindShadingRateImageNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdBindTransformFeedbackBuffersEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdBindVertexBuffers-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdBindVertexBuffers2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdBindVertexBuffers2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdBlitImage-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdBlitImage2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdBlitImage2-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdBuildAccelerationStructureNV-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdBuildAccelerationStructuresIndirectKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdBuildAccelerationStructuresKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdBuildMicromapsEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdClearAttachments-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdClearColorImage-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdClearDepthStencilImage-commandBuffer-cmdpool"},
    {VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "UNASSIGNED-vkCmdControlVideoCodingKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdCopyAccelerationStructureKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdCopyAccelerationStructureNV-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdCopyAccelerationStructureToMemoryKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyBuffer-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyBuffer2-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyBuffer2-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyBufferToImage-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyBufferToImage2-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyBufferToImage2-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyImage-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyImage2-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyImage2-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyImageToBuffer-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyImageToBuffer2-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyImageToBuffer2-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdCopyMemoryIndirectNV-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdCopyMemoryToAccelerationStructureKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdCopyMemoryToImageIndirectNV-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdCopyMemoryToMicromapEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdCopyMicromapEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdCopyMicromapToMemoryEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdCopyQueryPoolResults-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdCuLaunchKernelNVX-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdDebugMarkerBeginEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdDebugMarkerEndEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdDebugMarkerInsertEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_VIDEO_DECODE_BIT_KHR, "UNASSIGNED-vkCmdDecodeVideoKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdDecompressMemoryIndirectCountNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdDecompressMemoryNV-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdDispatch-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdDispatchBase-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdDispatchBase-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdDispatchIndirect-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdDraw-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdDrawClusterHUAWEI-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdDrawClusterIndirectHUAWEI-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdDrawIndexed-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdDrawIndexedIndirect-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdDrawIndexedIndirectCount-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdDrawIndexedIndirectCount-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdDrawIndexedIndirectCount-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdDrawIndirect-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdDrawIndirectByteCountEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdDrawIndirectCount-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdDrawIndirectCount-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdDrawIndirectCount-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdDrawMeshTasksEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdDrawMeshTasksIndirectCountEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdDrawMeshTasksIndirectCountNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdDrawMeshTasksIndirectEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdDrawMeshTasksIndirectNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdDrawMeshTasksNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdDrawMultiEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdDrawMultiIndexedEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "UNASSIGNED-vkCmdEncodeVideoKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdEndConditionalRenderingEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdEndDebugUtilsLabelEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdEndQuery-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "UNASSIGNED-vkCmdEndQueryIndexedEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdEndRenderPass-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdEndRenderPass2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdEndRenderPass2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdEndRendering-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdEndRendering-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdEndTransformFeedbackEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "UNASSIGNED-vkCmdEndVideoCodingKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdExecuteCommands-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdExecuteGeneratedCommandsNV-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdFillBuffer-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdInsertDebugUtilsLabelEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdNextSubpass-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdNextSubpass2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdNextSubpass2-commandBuffer-cmdpool"},
    {VK_QUEUE_OPTICAL_FLOW_BIT_NV, "UNASSIGNED-vkCmdOpticalFlowExecuteNV-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdPipelineBarrier-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdPipelineBarrier2-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdPipelineBarrier2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdPreprocessGeneratedCommandsNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdPushConstants-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdPushDescriptorSetKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdPushDescriptorSetWithTemplateKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, "VUID-vkCmdRefreshObjectsKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdResetEvent-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdResetEvent2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdResetEvent2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR | VK_QUEUE_OPTICAL_FLOW_BIT_NV, "VUID-vkCmdResetQueryPool-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdResolveImage-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdResolveImage2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdResolveImage2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetAlphaToCoverageEnableEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetAlphaToOneEnableEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetBlendConstants-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, "UNASSIGNED-vkCmdSetCheckpointNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetCoarseSampleOrderNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetColorBlendAdvancedEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetColorBlendEnableEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetColorBlendEquationEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetColorWriteEnableEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetColorWriteMaskEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetConservativeRasterizationModeEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetCoverageModulationModeNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetCoverageModulationTableEnableNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetCoverageModulationTableNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetCoverageReductionModeNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetCoverageToColorEnableNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetCoverageToColorLocationNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetCullMode-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetCullMode-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDepthBias-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDepthBiasEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDepthBiasEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDepthBounds-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDepthBoundsTestEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDepthBoundsTestEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetDepthClampEnableEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetDepthClipEnableEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetDepthClipNegativeOneToOneEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDepthCompareOp-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDepthCompareOp-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDepthTestEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDepthTestEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDepthWriteEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDepthWriteEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdSetDescriptorBufferOffsetsEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, "VUID-vkCmdSetDeviceMask-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, "VUID-vkCmdSetDeviceMask-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDiscardRectangleEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDiscardRectangleEnableEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetDiscardRectangleModeEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdSetEvent-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdSetEvent2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdSetEvent2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetExclusiveScissorEnableNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetExclusiveScissorNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetExtraPrimitiveOverestimationSizeEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetFragmentShadingRateEnumNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetFragmentShadingRateKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetFrontFace-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetFrontFace-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetLineRasterizationModeEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetLineStippleEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetLineStippleEnableEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetLineWidth-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetLogicOpEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetLogicOpEnableEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetPatchControlPointsEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, "UNASSIGNED-vkCmdSetPerformanceMarkerINTEL-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, "UNASSIGNED-vkCmdSetPerformanceOverrideINTEL-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, "UNASSIGNED-vkCmdSetPerformanceStreamMarkerINTEL-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetPolygonModeEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetPrimitiveRestartEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetPrimitiveRestartEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetPrimitiveTopology-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetPrimitiveTopology-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetProvokingVertexModeEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetRasterizationSamplesEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetRasterizationStreamEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetRasterizerDiscardEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetRasterizerDiscardEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdSetRayTracingPipelineStackSizeKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetRepresentativeFragmentTestEnableNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetSampleLocationsEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetSampleLocationsEnableEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetSampleMaskEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetScissor-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetScissorWithCount-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetScissorWithCount-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetShadingRateImageEnableNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetStencilCompareMask-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetStencilOp-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetStencilOp-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetStencilReference-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetStencilTestEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetStencilTestEnable-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetStencilWriteMask-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetTessellationDomainOriginEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetVertexInputEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetViewport-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetViewportShadingRatePaletteNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetViewportSwizzleNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetViewportWScalingEnableNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSetViewportWScalingNV-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetViewportWithCount-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "VUID-vkCmdSetViewportWithCount-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT, "UNASSIGNED-vkCmdSubpassShadingHUAWEI-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdTraceRaysIndirect2KHR-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdTraceRaysIndirectKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdTraceRaysKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdTraceRaysNV-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdUpdateBuffer-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdWaitEvents-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdWaitEvents2-commandBuffer-cmdpool"},
    {VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdWaitEvents2-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdWriteAccelerationStructuresPropertiesKHR-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdWriteAccelerationStructuresPropertiesNV-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "VUID-vkCmdWriteBufferMarker2AMD-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdWriteBufferMarkerAMD-commandBuffer-cmdpool"},
    {VK_QUEUE_COMPUTE_BIT, "UNASSIGNED-vkCmdWriteMicromapsPropertiesEXT-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR | VK_QUEUE_OPTICAL_FLOW_BIT_NV, "VUID-vkCmdWriteTimestamp-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdWriteTimestamp2-commandBuffer-cmdpool"},
    {VK_QUEUE_TRANSFER_BIT | VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_VIDEO_DECODE_BIT_KHR | VK_QUEUE_VIDEO_ENCODE_BIT_KHR, "VUID-vkCmdWriteTimestamp2-commandBuffer-cmdpool"},
}};

enum CMD_RENDER_PASS_TYPE {
    CMD_RENDER_PASS_INSIDE,
    CMD_RENDER_PASS_OUTSIDE,
    CMD_RENDER_PASS_BOTH
};
struct CommandSupportedRenderPass {
    CMD_RENDER_PASS_TYPE renderPass;
    const char* vuid;
};
static const std::array<CommandSupportedRenderPass, CMD_RANGE_SIZE> kGeneratedRenderPassList = {{
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined}, // CMD_NONE
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdBeginRenderPass-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdBeginRenderPass2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdBeginRenderPass2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdBeginRendering-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdBeginRendering-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdBeginTransformFeedbackEXT-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdBeginVideoCodingKHR-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdBindInvocationMaskHUAWEI-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdBlitImage-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdBlitImage2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdBlitImage2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdBuildAccelerationStructureNV-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdBuildAccelerationStructuresIndirectKHR-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdBuildAccelerationStructuresKHR-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdBuildMicromapsEXT-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdClearAttachments-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdClearColorImage-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdClearDepthStencilImage-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdControlVideoCodingKHR-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdCopyAccelerationStructureKHR-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdCopyAccelerationStructureNV-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdCopyAccelerationStructureToMemoryKHR-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyBuffer-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyBuffer2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyBuffer2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyBufferToImage-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyBufferToImage2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyBufferToImage2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyImage-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyImage2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyImage2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyImageToBuffer-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyImageToBuffer2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyImageToBuffer2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdCopyMemoryIndirectNV-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdCopyMemoryToAccelerationStructureKHR-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdCopyMemoryToImageIndirectNV-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdCopyMemoryToMicromapEXT-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdCopyMicromapEXT-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdCopyMicromapToMemoryEXT-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdCopyQueryPoolResults-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdDecodeVideoKHR-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdDecompressMemoryIndirectCountNV-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdDecompressMemoryNV-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdDispatch-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdDispatchBase-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdDispatchBase-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdDispatchIndirect-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdDraw-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdDrawClusterHUAWEI-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdDrawClusterIndirectHUAWEI-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdDrawIndexed-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdDrawIndexedIndirect-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdDrawIndexedIndirectCount-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdDrawIndexedIndirectCount-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdDrawIndexedIndirectCount-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdDrawIndirect-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdDrawIndirectByteCountEXT-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdDrawIndirectCount-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdDrawIndirectCount-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdDrawIndirectCount-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdDrawMeshTasksEXT-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdDrawMeshTasksIndirectCountEXT-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdDrawMeshTasksIndirectCountNV-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdDrawMeshTasksIndirectEXT-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdDrawMeshTasksIndirectNV-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdDrawMeshTasksNV-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdDrawMultiEXT-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdDrawMultiIndexedEXT-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdEncodeVideoKHR-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdEndRenderPass-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdEndRenderPass2-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdEndRenderPass2-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdEndRendering-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdEndRendering-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdEndTransformFeedbackEXT-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdEndVideoCodingKHR-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdExecuteGeneratedCommandsNV-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdFillBuffer-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdNextSubpass-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdNextSubpass2-renderpass"},
    {CMD_RENDER_PASS_INSIDE, "VUID-vkCmdNextSubpass2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdOpticalFlowExecuteNV-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdPreprocessGeneratedCommandsNV-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdRefreshObjectsKHR-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdResetEvent-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdResetEvent2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdResetEvent2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdResetQueryPool-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdResolveImage-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdResolveImage2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdResolveImage2-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdSetEvent-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdSetEvent2-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdSetEvent2-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdSetRayTracingPipelineStackSizeKHR-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_INSIDE, "UNASSIGNED-vkCmdSubpassShadingHUAWEI-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdTraceRaysIndirect2KHR-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdTraceRaysIndirectKHR-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdTraceRaysKHR-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdTraceRaysNV-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "VUID-vkCmdUpdateBuffer-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdWriteAccelerationStructuresPropertiesKHR-renderpass"},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdWriteAccelerationStructuresPropertiesNV-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_OUTSIDE, "UNASSIGNED-vkCmdWriteMicromapsPropertiesEXT-renderpass"},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
    {CMD_RENDER_PASS_BOTH, kVUIDUndefined},
}};

enum CMD_VIDEO_CODING_TYPE {
    CMD_VIDEO_CODING_INSIDE,
    CMD_VIDEO_CODING_OUTSIDE,
    CMD_VIDEO_CODING_BOTH
};
struct CommandSupportedVideoCoding {
    CMD_VIDEO_CODING_TYPE videoCoding;
    const char* vuid;
};
static const std::array<CommandSupportedVideoCoding, CMD_RANGE_SIZE> kGeneratedVideoCodingList = {{
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined}, // CMD_NONE
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBeginConditionalRenderingEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBeginDebugUtilsLabelEXT-videocoding"},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBeginQueryIndexedEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBeginRenderPass-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBeginRenderPass2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBeginRenderPass2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBeginRendering-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBeginRendering-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBeginTransformFeedbackEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBeginVideoCodingKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBindDescriptorBufferEmbeddedSamplersEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBindDescriptorBuffersEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBindDescriptorSets-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBindIndexBuffer-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBindInvocationMaskHUAWEI-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBindPipeline-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBindPipelineShaderGroupNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBindShadingRateImageNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBindTransformFeedbackBuffersEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBindVertexBuffers-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBindVertexBuffers2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBindVertexBuffers2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBlitImage-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBlitImage2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBlitImage2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBuildAccelerationStructureNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBuildAccelerationStructuresIndirectKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBuildAccelerationStructuresKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdBuildMicromapsEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdClearAttachments-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdClearColorImage-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdClearDepthStencilImage-videocoding"},
    {CMD_VIDEO_CODING_INSIDE, "UNASSIGNED-vkCmdControlVideoCodingKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyAccelerationStructureKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyAccelerationStructureNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyAccelerationStructureToMemoryKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyBuffer-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyBuffer2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyBuffer2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyBufferToImage-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyBufferToImage2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyBufferToImage2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyImage-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyImage2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyImage2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyImageToBuffer-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyImageToBuffer2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyImageToBuffer2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyMemoryIndirectNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyMemoryToAccelerationStructureKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyMemoryToImageIndirectNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyMemoryToMicromapEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyMicromapEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyMicromapToMemoryEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCopyQueryPoolResults-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdCuLaunchKernelNVX-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDebugMarkerBeginEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDebugMarkerEndEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDebugMarkerInsertEXT-videocoding"},
    {CMD_VIDEO_CODING_INSIDE, "UNASSIGNED-vkCmdDecodeVideoKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDecompressMemoryIndirectCountNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDecompressMemoryNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDispatch-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDispatchBase-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDispatchBase-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDispatchIndirect-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDraw-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawClusterHUAWEI-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawClusterIndirectHUAWEI-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawIndexed-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawIndexedIndirect-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawIndexedIndirectCount-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawIndexedIndirectCount-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawIndexedIndirectCount-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawIndirect-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawIndirectByteCountEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawIndirectCount-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawIndirectCount-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawIndirectCount-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawMeshTasksEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawMeshTasksIndirectCountEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawMeshTasksIndirectCountNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawMeshTasksIndirectEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawMeshTasksIndirectNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawMeshTasksNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawMultiEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdDrawMultiIndexedEXT-videocoding"},
    {CMD_VIDEO_CODING_INSIDE, "UNASSIGNED-vkCmdEncodeVideoKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdEndConditionalRenderingEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdEndDebugUtilsLabelEXT-videocoding"},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdEndQueryIndexedEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdEndRenderPass-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdEndRenderPass2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdEndRenderPass2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdEndRendering-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdEndRendering-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdEndTransformFeedbackEXT-videocoding"},
    {CMD_VIDEO_CODING_INSIDE, "UNASSIGNED-vkCmdEndVideoCodingKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdExecuteCommands-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdExecuteGeneratedCommandsNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdFillBuffer-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdInsertDebugUtilsLabelEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdNextSubpass-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdNextSubpass2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdNextSubpass2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdOpticalFlowExecuteNV-videocoding"},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdPreprocessGeneratedCommandsNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdPushConstants-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdPushDescriptorSetKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdPushDescriptorSetWithTemplateKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdRefreshObjectsKHR-videocoding"},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdResetQueryPool-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdResolveImage-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdResolveImage2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdResolveImage2-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetAlphaToCoverageEnableEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetAlphaToOneEnableEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetBlendConstants-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetCheckpointNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetCoarseSampleOrderNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetColorBlendAdvancedEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetColorBlendEnableEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetColorBlendEquationEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetColorWriteEnableEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetColorWriteMaskEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetConservativeRasterizationModeEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetCoverageModulationModeNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetCoverageModulationTableEnableNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetCoverageModulationTableNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetCoverageReductionModeNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetCoverageToColorEnableNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetCoverageToColorLocationNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetCullMode-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetCullMode-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthBias-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthBiasEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthBiasEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthBounds-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthBoundsTestEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthBoundsTestEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthClampEnableEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthClipEnableEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthClipNegativeOneToOneEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthCompareOp-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthCompareOp-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthTestEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthTestEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthWriteEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDepthWriteEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDescriptorBufferOffsetsEXT-videocoding"},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDiscardRectangleEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDiscardRectangleEnableEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetDiscardRectangleModeEXT-videocoding"},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetExclusiveScissorEnableNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetExclusiveScissorNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetExtraPrimitiveOverestimationSizeEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetFragmentShadingRateEnumNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetFragmentShadingRateKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetFrontFace-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetFrontFace-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetLineRasterizationModeEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetLineStippleEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetLineStippleEnableEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetLineWidth-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetLogicOpEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetLogicOpEnableEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetPatchControlPointsEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetPerformanceMarkerINTEL-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetPerformanceOverrideINTEL-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetPerformanceStreamMarkerINTEL-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetPolygonModeEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetPrimitiveRestartEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetPrimitiveRestartEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetPrimitiveTopology-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetPrimitiveTopology-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetProvokingVertexModeEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetRasterizationSamplesEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetRasterizationStreamEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetRasterizerDiscardEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetRasterizerDiscardEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetRayTracingPipelineStackSizeKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetRepresentativeFragmentTestEnableNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetSampleLocationsEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetSampleLocationsEnableEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetSampleMaskEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetScissor-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetScissorWithCount-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetScissorWithCount-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetShadingRateImageEnableNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetStencilCompareMask-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetStencilOp-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetStencilOp-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetStencilReference-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetStencilTestEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetStencilTestEnable-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetStencilWriteMask-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetTessellationDomainOriginEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetVertexInputEXT-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetViewport-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetViewportShadingRatePaletteNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetViewportSwizzleNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetViewportWScalingEnableNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetViewportWScalingNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetViewportWithCount-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSetViewportWithCount-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdSubpassShadingHUAWEI-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdTraceRaysIndirect2KHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdTraceRaysIndirectKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdTraceRaysKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdTraceRaysNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdUpdateBuffer-videocoding"},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdWriteAccelerationStructuresPropertiesKHR-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdWriteAccelerationStructuresPropertiesNV-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdWriteBufferMarker2AMD-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdWriteBufferMarkerAMD-videocoding"},
    {CMD_VIDEO_CODING_OUTSIDE, "UNASSIGNED-vkCmdWriteMicromapsPropertiesEXT-videocoding"},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
    {CMD_VIDEO_CODING_BOTH, kVUIDUndefined},
}};

static const std::array<const char *, CMD_RANGE_SIZE> kGeneratedBufferLevelList = {{
    kVUIDUndefined, // CMD_NONE
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    "VUID-vkCmdBeginRenderPass-bufferlevel",
    "VUID-vkCmdBeginRenderPass2-bufferlevel",
    "VUID-vkCmdBeginRenderPass2-bufferlevel",
    nullptr,
    nullptr,
    nullptr,
    "UNASSIGNED-vkCmdBeginVideoCodingKHR-bufferlevel",
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    "UNASSIGNED-vkCmdControlVideoCodingKHR-bufferlevel",
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    "UNASSIGNED-vkCmdDecodeVideoKHR-bufferlevel",
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    "UNASSIGNED-vkCmdEncodeVideoKHR-bufferlevel",
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    "VUID-vkCmdEndRenderPass-bufferlevel",
    "VUID-vkCmdEndRenderPass2-bufferlevel",
    "VUID-vkCmdEndRenderPass2-bufferlevel",
    nullptr,
    nullptr,
    nullptr,
    "UNASSIGNED-vkCmdEndVideoCodingKHR-bufferlevel",
    "VUID-vkCmdExecuteCommands-bufferlevel",
    nullptr,
    nullptr,
    nullptr,
    "VUID-vkCmdNextSubpass-bufferlevel",
    "VUID-vkCmdNextSubpass2-bufferlevel",
    "VUID-vkCmdNextSubpass2-bufferlevel",
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
}};

// Used to handle all the implicit VUs that are autogenerated from the registry
bool CoreChecks::ValidateCmd(const CMD_BUFFER_STATE &cb_state, const CMD_TYPE cmd) const {
    bool skip = false;
    const char *caller_name = CommandTypeString(cmd);

    // Validate the given command being added to the specified cmd buffer,
    // flagging errors if CB is not in the recording state or if there's an issue with the Cmd ordering
    switch (cb_state.state) {
        case CB_RECORDING:
            skip |= ValidateCmdSubpassState(cb_state, cmd);
            break;

        case CB_INVALID_COMPLETE:
        case CB_INVALID_INCOMPLETE:
            skip |= ReportInvalidCommandBuffer(cb_state, caller_name);
            break;

        default:
            assert(cmd != CMD_NONE);
            const auto error = kGeneratedMustBeRecordingList[cmd];
            skip |= LogError(cb_state.commandBuffer(), error, "You must call vkBeginCommandBuffer() before this call to %s.",
                            caller_name);
    }

    // Validate the command pool from which the command buffer is from that the command is allowed for queue type
    const auto supportedQueueType = kGeneratedQueueTypeList[cmd];
    skip |= ValidateCmdQueueFlags(cb_state, caller_name, supportedQueueType.flags, supportedQueueType.vuid);

    // Validate if command is inside or outside a render pass if applicable
    const auto supportedRenderPass = kGeneratedRenderPassList[cmd];
    if (supportedRenderPass.renderPass == CMD_RENDER_PASS_INSIDE) {
        skip |= OutsideRenderPass(cb_state, caller_name, supportedRenderPass.vuid);
    } else if (supportedRenderPass.renderPass == CMD_RENDER_PASS_OUTSIDE) {
        skip |= InsideRenderPass(cb_state, caller_name, supportedRenderPass.vuid);
    }

    // Validate if command is inside or outside a video coding scope if applicable
    const auto supportedVideoCoding = kGeneratedVideoCodingList[cmd];
    if (supportedVideoCoding.videoCoding == CMD_VIDEO_CODING_INSIDE) {
        skip |= OutsideVideoCodingScope(cb_state, caller_name, supportedVideoCoding.vuid);
    } else if (supportedVideoCoding.videoCoding == CMD_VIDEO_CODING_OUTSIDE) {
        skip |= InsideVideoCodingScope(cb_state, caller_name, supportedVideoCoding.vuid);
    }

    // Validate if command has to be recorded in a primary command buffer
    const auto supportedBufferLevel = kGeneratedBufferLevelList[cmd];
    if (supportedBufferLevel != nullptr) {
        skip |= ValidatePrimaryCommandBuffer(cb_state, caller_name, supportedBufferLevel);
    }

    return skip;
}

static VkDynamicState ConvertToDynamicState(CBDynamicStatus flag) {
    switch (flag) {
        case CB_DYNAMIC_VIEWPORT_SET:
            return VK_DYNAMIC_STATE_VIEWPORT;
        case CB_DYNAMIC_SCISSOR_SET:
            return VK_DYNAMIC_STATE_SCISSOR;
        case CB_DYNAMIC_LINE_WIDTH_SET:
            return VK_DYNAMIC_STATE_LINE_WIDTH;
        case CB_DYNAMIC_DEPTH_BIAS_SET:
            return VK_DYNAMIC_STATE_DEPTH_BIAS;
        case CB_DYNAMIC_BLEND_CONSTANTS_SET:
            return VK_DYNAMIC_STATE_BLEND_CONSTANTS;
        case CB_DYNAMIC_DEPTH_BOUNDS_SET:
            return VK_DYNAMIC_STATE_DEPTH_BOUNDS;
        case CB_DYNAMIC_STENCIL_COMPARE_MASK_SET:
            return VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK;
        case CB_DYNAMIC_STENCIL_WRITE_MASK_SET:
            return VK_DYNAMIC_STATE_STENCIL_WRITE_MASK;
        case CB_DYNAMIC_STENCIL_REFERENCE_SET:
            return VK_DYNAMIC_STATE_STENCIL_REFERENCE;
        case CB_DYNAMIC_CULL_MODE_SET:
            return VK_DYNAMIC_STATE_CULL_MODE;
        case CB_DYNAMIC_FRONT_FACE_SET:
            return VK_DYNAMIC_STATE_FRONT_FACE;
        case CB_DYNAMIC_PRIMITIVE_TOPOLOGY_SET:
            return VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY;
        case CB_DYNAMIC_VIEWPORT_WITH_COUNT_SET:
            return VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT;
        case CB_DYNAMIC_SCISSOR_WITH_COUNT_SET:
            return VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT;
        case CB_DYNAMIC_VERTEX_INPUT_BINDING_STRIDE_SET:
            return VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE;
        case CB_DYNAMIC_DEPTH_TEST_ENABLE_SET:
            return VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE;
        case CB_DYNAMIC_DEPTH_WRITE_ENABLE_SET:
            return VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE;
        case CB_DYNAMIC_DEPTH_COMPARE_OP_SET:
            return VK_DYNAMIC_STATE_DEPTH_COMPARE_OP;
        case CB_DYNAMIC_DEPTH_BOUNDS_TEST_ENABLE_SET:
            return VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE;
        case CB_DYNAMIC_STENCIL_TEST_ENABLE_SET:
            return VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE;
        case CB_DYNAMIC_STENCIL_OP_SET:
            return VK_DYNAMIC_STATE_STENCIL_OP;
        case CB_DYNAMIC_RASTERIZER_DISCARD_ENABLE_SET:
            return VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE;
        case CB_DYNAMIC_DEPTH_BIAS_ENABLE_SET:
            return VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE;
        case CB_DYNAMIC_PRIMITIVE_RESTART_ENABLE_SET:
            return VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE;
        case CB_DYNAMIC_VIEWPORT_W_SCALING_NV_SET:
            return VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV;
        case CB_DYNAMIC_DISCARD_RECTANGLE_EXT_SET:
            return VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT;
        case CB_DYNAMIC_DISCARD_RECTANGLE_ENABLE_EXT_SET:
            return VK_DYNAMIC_STATE_DISCARD_RECTANGLE_ENABLE_EXT;
        case CB_DYNAMIC_DISCARD_RECTANGLE_MODE_EXT_SET:
            return VK_DYNAMIC_STATE_DISCARD_RECTANGLE_MODE_EXT;
        case CB_DYNAMIC_SAMPLE_LOCATIONS_EXT_SET:
            return VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT;
        case CB_DYNAMIC_RAY_TRACING_PIPELINE_STACK_SIZE_KHR_SET:
            return VK_DYNAMIC_STATE_RAY_TRACING_PIPELINE_STACK_SIZE_KHR;
        case CB_DYNAMIC_VIEWPORT_SHADING_RATE_PALETTE_NV_SET:
            return VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV;
        case CB_DYNAMIC_VIEWPORT_COARSE_SAMPLE_ORDER_NV_SET:
            return VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV;
        case CB_DYNAMIC_EXCLUSIVE_SCISSOR_ENABLE_NV_SET:
            return VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_ENABLE_NV;
        case CB_DYNAMIC_EXCLUSIVE_SCISSOR_NV_SET:
            return VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV;
        case CB_DYNAMIC_FRAGMENT_SHADING_RATE_KHR_SET:
            return VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR;
        case CB_DYNAMIC_LINE_STIPPLE_EXT_SET:
            return VK_DYNAMIC_STATE_LINE_STIPPLE_EXT;
        case CB_DYNAMIC_VERTEX_INPUT_EXT_SET:
            return VK_DYNAMIC_STATE_VERTEX_INPUT_EXT;
        case CB_DYNAMIC_PATCH_CONTROL_POINTS_EXT_SET:
            return VK_DYNAMIC_STATE_PATCH_CONTROL_POINTS_EXT;
        case CB_DYNAMIC_LOGIC_OP_EXT_SET:
            return VK_DYNAMIC_STATE_LOGIC_OP_EXT;
        case CB_DYNAMIC_COLOR_WRITE_ENABLE_EXT_SET:
            return VK_DYNAMIC_STATE_COLOR_WRITE_ENABLE_EXT;
        case CB_DYNAMIC_TESSELLATION_DOMAIN_ORIGIN_EXT_SET:
            return VK_DYNAMIC_STATE_TESSELLATION_DOMAIN_ORIGIN_EXT;
        case CB_DYNAMIC_DEPTH_CLAMP_ENABLE_EXT_SET:
            return VK_DYNAMIC_STATE_DEPTH_CLAMP_ENABLE_EXT;
        case CB_DYNAMIC_POLYGON_MODE_EXT_SET:
            return VK_DYNAMIC_STATE_POLYGON_MODE_EXT;
        case CB_DYNAMIC_RASTERIZATION_SAMPLES_EXT_SET:
            return VK_DYNAMIC_STATE_RASTERIZATION_SAMPLES_EXT;
        case CB_DYNAMIC_SAMPLE_MASK_EXT_SET:
            return VK_DYNAMIC_STATE_SAMPLE_MASK_EXT;
        case CB_DYNAMIC_ALPHA_TO_COVERAGE_ENABLE_EXT_SET:
            return VK_DYNAMIC_STATE_ALPHA_TO_COVERAGE_ENABLE_EXT;
        case CB_DYNAMIC_ALPHA_TO_ONE_ENABLE_EXT_SET:
            return VK_DYNAMIC_STATE_ALPHA_TO_ONE_ENABLE_EXT;
        case CB_DYNAMIC_LOGIC_OP_ENABLE_EXT_SET:
            return VK_DYNAMIC_STATE_LOGIC_OP_ENABLE_EXT;
        case CB_DYNAMIC_COLOR_BLEND_ENABLE_EXT_SET:
            return VK_DYNAMIC_STATE_COLOR_BLEND_ENABLE_EXT;
        case CB_DYNAMIC_COLOR_BLEND_EQUATION_EXT_SET:
            return VK_DYNAMIC_STATE_COLOR_BLEND_EQUATION_EXT;
        case CB_DYNAMIC_COLOR_WRITE_MASK_EXT_SET:
            return VK_DYNAMIC_STATE_COLOR_WRITE_MASK_EXT;
        case CB_DYNAMIC_RASTERIZATION_STREAM_EXT_SET:
            return VK_DYNAMIC_STATE_RASTERIZATION_STREAM_EXT;
        case CB_DYNAMIC_CONSERVATIVE_RASTERIZATION_MODE_EXT_SET:
            return VK_DYNAMIC_STATE_CONSERVATIVE_RASTERIZATION_MODE_EXT;
        case CB_DYNAMIC_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT_SET:
            return VK_DYNAMIC_STATE_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT;
        case CB_DYNAMIC_DEPTH_CLIP_ENABLE_EXT_SET:
            return VK_DYNAMIC_STATE_DEPTH_CLIP_ENABLE_EXT;
        case CB_DYNAMIC_SAMPLE_LOCATIONS_ENABLE_EXT_SET:
            return VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_ENABLE_EXT;
        case CB_DYNAMIC_COLOR_BLEND_ADVANCED_EXT_SET:
            return VK_DYNAMIC_STATE_COLOR_BLEND_ADVANCED_EXT;
        case CB_DYNAMIC_PROVOKING_VERTEX_MODE_EXT_SET:
            return VK_DYNAMIC_STATE_PROVOKING_VERTEX_MODE_EXT;
        case CB_DYNAMIC_LINE_RASTERIZATION_MODE_EXT_SET:
            return VK_DYNAMIC_STATE_LINE_RASTERIZATION_MODE_EXT;
        case CB_DYNAMIC_LINE_STIPPLE_ENABLE_EXT_SET:
            return VK_DYNAMIC_STATE_LINE_STIPPLE_ENABLE_EXT;
        case CB_DYNAMIC_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT_SET:
            return VK_DYNAMIC_STATE_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT;
        case CB_DYNAMIC_VIEWPORT_W_SCALING_ENABLE_NV_SET:
            return VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_ENABLE_NV;
        case CB_DYNAMIC_VIEWPORT_SWIZZLE_NV_SET:
            return VK_DYNAMIC_STATE_VIEWPORT_SWIZZLE_NV;
        case CB_DYNAMIC_COVERAGE_TO_COLOR_ENABLE_NV_SET:
            return VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_ENABLE_NV;
        case CB_DYNAMIC_COVERAGE_TO_COLOR_LOCATION_NV_SET:
            return VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_LOCATION_NV;
        case CB_DYNAMIC_COVERAGE_MODULATION_MODE_NV_SET:
            return VK_DYNAMIC_STATE_COVERAGE_MODULATION_MODE_NV;
        case CB_DYNAMIC_COVERAGE_MODULATION_TABLE_ENABLE_NV_SET:
            return VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_ENABLE_NV;
        case CB_DYNAMIC_COVERAGE_MODULATION_TABLE_NV_SET:
            return VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_NV;
        case CB_DYNAMIC_SHADING_RATE_IMAGE_ENABLE_NV_SET:
            return VK_DYNAMIC_STATE_SHADING_RATE_IMAGE_ENABLE_NV;
        case CB_DYNAMIC_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV_SET:
            return VK_DYNAMIC_STATE_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV;
        case CB_DYNAMIC_COVERAGE_REDUCTION_MODE_NV_SET:
            return VK_DYNAMIC_STATE_COVERAGE_REDUCTION_MODE_NV;
        default:
            return VK_DYNAMIC_STATE_MAX_ENUM;
    }
}

static CBDynamicStatus ConvertToCBDynamicStatus(VkDynamicState state) {
    switch (state) {
        case VK_DYNAMIC_STATE_VIEWPORT:
            return CB_DYNAMIC_VIEWPORT_SET;
        case VK_DYNAMIC_STATE_SCISSOR:
            return CB_DYNAMIC_SCISSOR_SET;
        case VK_DYNAMIC_STATE_LINE_WIDTH:
            return CB_DYNAMIC_LINE_WIDTH_SET;
        case VK_DYNAMIC_STATE_DEPTH_BIAS:
            return CB_DYNAMIC_DEPTH_BIAS_SET;
        case VK_DYNAMIC_STATE_BLEND_CONSTANTS:
            return CB_DYNAMIC_BLEND_CONSTANTS_SET;
        case VK_DYNAMIC_STATE_DEPTH_BOUNDS:
            return CB_DYNAMIC_DEPTH_BOUNDS_SET;
        case VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK:
            return CB_DYNAMIC_STENCIL_COMPARE_MASK_SET;
        case VK_DYNAMIC_STATE_STENCIL_WRITE_MASK:
            return CB_DYNAMIC_STENCIL_WRITE_MASK_SET;
        case VK_DYNAMIC_STATE_STENCIL_REFERENCE:
            return CB_DYNAMIC_STENCIL_REFERENCE_SET;
        case VK_DYNAMIC_STATE_CULL_MODE:
            return CB_DYNAMIC_CULL_MODE_SET;
        case VK_DYNAMIC_STATE_FRONT_FACE:
            return CB_DYNAMIC_FRONT_FACE_SET;
        case VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY:
            return CB_DYNAMIC_PRIMITIVE_TOPOLOGY_SET;
        case VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT:
            return CB_DYNAMIC_VIEWPORT_WITH_COUNT_SET;
        case VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT:
            return CB_DYNAMIC_SCISSOR_WITH_COUNT_SET;
        case VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE:
            return CB_DYNAMIC_VERTEX_INPUT_BINDING_STRIDE_SET;
        case VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE:
            return CB_DYNAMIC_DEPTH_TEST_ENABLE_SET;
        case VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE:
            return CB_DYNAMIC_DEPTH_WRITE_ENABLE_SET;
        case VK_DYNAMIC_STATE_DEPTH_COMPARE_OP:
            return CB_DYNAMIC_DEPTH_COMPARE_OP_SET;
        case VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE:
            return CB_DYNAMIC_DEPTH_BOUNDS_TEST_ENABLE_SET;
        case VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE:
            return CB_DYNAMIC_STENCIL_TEST_ENABLE_SET;
        case VK_DYNAMIC_STATE_STENCIL_OP:
            return CB_DYNAMIC_STENCIL_OP_SET;
        case VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE:
            return CB_DYNAMIC_RASTERIZER_DISCARD_ENABLE_SET;
        case VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE:
            return CB_DYNAMIC_DEPTH_BIAS_ENABLE_SET;
        case VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE:
            return CB_DYNAMIC_PRIMITIVE_RESTART_ENABLE_SET;
        case VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV:
            return CB_DYNAMIC_VIEWPORT_W_SCALING_NV_SET;
        case VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT:
            return CB_DYNAMIC_DISCARD_RECTANGLE_EXT_SET;
        case VK_DYNAMIC_STATE_DISCARD_RECTANGLE_ENABLE_EXT:
            return CB_DYNAMIC_DISCARD_RECTANGLE_ENABLE_EXT_SET;
        case VK_DYNAMIC_STATE_DISCARD_RECTANGLE_MODE_EXT:
            return CB_DYNAMIC_DISCARD_RECTANGLE_MODE_EXT_SET;
        case VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT:
            return CB_DYNAMIC_SAMPLE_LOCATIONS_EXT_SET;
        case VK_DYNAMIC_STATE_RAY_TRACING_PIPELINE_STACK_SIZE_KHR:
            return CB_DYNAMIC_RAY_TRACING_PIPELINE_STACK_SIZE_KHR_SET;
        case VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV:
            return CB_DYNAMIC_VIEWPORT_SHADING_RATE_PALETTE_NV_SET;
        case VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV:
            return CB_DYNAMIC_VIEWPORT_COARSE_SAMPLE_ORDER_NV_SET;
        case VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_ENABLE_NV:
            return CB_DYNAMIC_EXCLUSIVE_SCISSOR_ENABLE_NV_SET;
        case VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV:
            return CB_DYNAMIC_EXCLUSIVE_SCISSOR_NV_SET;
        case VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR:
            return CB_DYNAMIC_FRAGMENT_SHADING_RATE_KHR_SET;
        case VK_DYNAMIC_STATE_LINE_STIPPLE_EXT:
            return CB_DYNAMIC_LINE_STIPPLE_EXT_SET;
        case VK_DYNAMIC_STATE_VERTEX_INPUT_EXT:
            return CB_DYNAMIC_VERTEX_INPUT_EXT_SET;
        case VK_DYNAMIC_STATE_PATCH_CONTROL_POINTS_EXT:
            return CB_DYNAMIC_PATCH_CONTROL_POINTS_EXT_SET;
        case VK_DYNAMIC_STATE_LOGIC_OP_EXT:
            return CB_DYNAMIC_LOGIC_OP_EXT_SET;
        case VK_DYNAMIC_STATE_COLOR_WRITE_ENABLE_EXT:
            return CB_DYNAMIC_COLOR_WRITE_ENABLE_EXT_SET;
        case VK_DYNAMIC_STATE_TESSELLATION_DOMAIN_ORIGIN_EXT:
            return CB_DYNAMIC_TESSELLATION_DOMAIN_ORIGIN_EXT_SET;
        case VK_DYNAMIC_STATE_DEPTH_CLAMP_ENABLE_EXT:
            return CB_DYNAMIC_DEPTH_CLAMP_ENABLE_EXT_SET;
        case VK_DYNAMIC_STATE_POLYGON_MODE_EXT:
            return CB_DYNAMIC_POLYGON_MODE_EXT_SET;
        case VK_DYNAMIC_STATE_RASTERIZATION_SAMPLES_EXT:
            return CB_DYNAMIC_RASTERIZATION_SAMPLES_EXT_SET;
        case VK_DYNAMIC_STATE_SAMPLE_MASK_EXT:
            return CB_DYNAMIC_SAMPLE_MASK_EXT_SET;
        case VK_DYNAMIC_STATE_ALPHA_TO_COVERAGE_ENABLE_EXT:
            return CB_DYNAMIC_ALPHA_TO_COVERAGE_ENABLE_EXT_SET;
        case VK_DYNAMIC_STATE_ALPHA_TO_ONE_ENABLE_EXT:
            return CB_DYNAMIC_ALPHA_TO_ONE_ENABLE_EXT_SET;
        case VK_DYNAMIC_STATE_LOGIC_OP_ENABLE_EXT:
            return CB_DYNAMIC_LOGIC_OP_ENABLE_EXT_SET;
        case VK_DYNAMIC_STATE_COLOR_BLEND_ENABLE_EXT:
            return CB_DYNAMIC_COLOR_BLEND_ENABLE_EXT_SET;
        case VK_DYNAMIC_STATE_COLOR_BLEND_EQUATION_EXT:
            return CB_DYNAMIC_COLOR_BLEND_EQUATION_EXT_SET;
        case VK_DYNAMIC_STATE_COLOR_WRITE_MASK_EXT:
            return CB_DYNAMIC_COLOR_WRITE_MASK_EXT_SET;
        case VK_DYNAMIC_STATE_RASTERIZATION_STREAM_EXT:
            return CB_DYNAMIC_RASTERIZATION_STREAM_EXT_SET;
        case VK_DYNAMIC_STATE_CONSERVATIVE_RASTERIZATION_MODE_EXT:
            return CB_DYNAMIC_CONSERVATIVE_RASTERIZATION_MODE_EXT_SET;
        case VK_DYNAMIC_STATE_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT:
            return CB_DYNAMIC_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT_SET;
        case VK_DYNAMIC_STATE_DEPTH_CLIP_ENABLE_EXT:
            return CB_DYNAMIC_DEPTH_CLIP_ENABLE_EXT_SET;
        case VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_ENABLE_EXT:
            return CB_DYNAMIC_SAMPLE_LOCATIONS_ENABLE_EXT_SET;
        case VK_DYNAMIC_STATE_COLOR_BLEND_ADVANCED_EXT:
            return CB_DYNAMIC_COLOR_BLEND_ADVANCED_EXT_SET;
        case VK_DYNAMIC_STATE_PROVOKING_VERTEX_MODE_EXT:
            return CB_DYNAMIC_PROVOKING_VERTEX_MODE_EXT_SET;
        case VK_DYNAMIC_STATE_LINE_RASTERIZATION_MODE_EXT:
            return CB_DYNAMIC_LINE_RASTERIZATION_MODE_EXT_SET;
        case VK_DYNAMIC_STATE_LINE_STIPPLE_ENABLE_EXT:
            return CB_DYNAMIC_LINE_STIPPLE_ENABLE_EXT_SET;
        case VK_DYNAMIC_STATE_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT:
            return CB_DYNAMIC_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT_SET;
        case VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_ENABLE_NV:
            return CB_DYNAMIC_VIEWPORT_W_SCALING_ENABLE_NV_SET;
        case VK_DYNAMIC_STATE_VIEWPORT_SWIZZLE_NV:
            return CB_DYNAMIC_VIEWPORT_SWIZZLE_NV_SET;
        case VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_ENABLE_NV:
            return CB_DYNAMIC_COVERAGE_TO_COLOR_ENABLE_NV_SET;
        case VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_LOCATION_NV:
            return CB_DYNAMIC_COVERAGE_TO_COLOR_LOCATION_NV_SET;
        case VK_DYNAMIC_STATE_COVERAGE_MODULATION_MODE_NV:
            return CB_DYNAMIC_COVERAGE_MODULATION_MODE_NV_SET;
        case VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_ENABLE_NV:
            return CB_DYNAMIC_COVERAGE_MODULATION_TABLE_ENABLE_NV_SET;
        case VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_NV:
            return CB_DYNAMIC_COVERAGE_MODULATION_TABLE_NV_SET;
        case VK_DYNAMIC_STATE_SHADING_RATE_IMAGE_ENABLE_NV:
            return CB_DYNAMIC_SHADING_RATE_IMAGE_ENABLE_NV_SET;
        case VK_DYNAMIC_STATE_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV:
            return CB_DYNAMIC_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV_SET;
        case VK_DYNAMIC_STATE_COVERAGE_REDUCTION_MODE_NV:
            return CB_DYNAMIC_COVERAGE_REDUCTION_MODE_NV_SET;
        default:
            return CB_DYNAMIC_STATUS_NUM;
    }
}

const char* DynamicStateToString(CBDynamicStatus status) {
    return string_VkDynamicState(ConvertToDynamicState(status));
}

std::string DynamicStatesToString(CBDynamicFlags const &dynamic_state) {
    std::string ret;
    // enum is not zero based
    for (int index = 1; index < CB_DYNAMIC_STATUS_NUM; ++index) {
        CBDynamicStatus status = static_cast<CBDynamicStatus>(index);
        if (dynamic_state[status]) {
            if (!ret.empty()) ret.append("|");
            ret.append(string_VkDynamicState(ConvertToDynamicState(status)));
        }
    }
    if (ret.empty()) ret.append(string_VkDynamicState(ConvertToDynamicState(CB_DYNAMIC_STATUS_NUM)));
    return ret;
}

CBDynamicFlags MakeStaticStateMask(VkPipelineDynamicStateCreateInfo const *info) {
    // initially assume everything is static state
    CBDynamicFlags flags(~CBDynamicFlags(0));

    if (info) {
        for (uint32_t i = 0; i < info->dynamicStateCount; i++) {
            flags.reset(ConvertToCBDynamicStatus(info->pDynamicStates[i]));
        }
    }
    return flags;
}

