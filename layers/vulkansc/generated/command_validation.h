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

#pragma once
#include <array>
#include <bitset>

// Used as key for maps of all vkCmd* calls
// Does not include vkBeginCommandBuffer/vkEndCommandBuffer
typedef enum CMD_TYPE {
    CMD_NONE = 0,
    CMD_BEGINCONDITIONALRENDERINGEXT = 1,
    CMD_BEGINDEBUGUTILSLABELEXT = 2,
    CMD_BEGINQUERY = 3,
    CMD_BEGINQUERYINDEXEDEXT = 4,
    CMD_BEGINRENDERPASS = 5,
    CMD_BEGINRENDERPASS2 = 6,
    CMD_BEGINRENDERPASS2KHR = 7,
    CMD_BEGINRENDERING = 8,
    CMD_BEGINRENDERINGKHR = 9,
    CMD_BEGINTRANSFORMFEEDBACKEXT = 10,
    CMD_BEGINVIDEOCODINGKHR = 11,
    CMD_BINDDESCRIPTORBUFFEREMBEDDEDSAMPLERSEXT = 12,
    CMD_BINDDESCRIPTORBUFFERSEXT = 13,
    CMD_BINDDESCRIPTORSETS = 14,
    CMD_BINDINDEXBUFFER = 15,
    CMD_BINDINVOCATIONMASKHUAWEI = 16,
    CMD_BINDPIPELINE = 17,
    CMD_BINDPIPELINESHADERGROUPNV = 18,
    CMD_BINDSHADINGRATEIMAGENV = 19,
    CMD_BINDTRANSFORMFEEDBACKBUFFERSEXT = 20,
    CMD_BINDVERTEXBUFFERS = 21,
    CMD_BINDVERTEXBUFFERS2 = 22,
    CMD_BINDVERTEXBUFFERS2EXT = 23,
    CMD_BLITIMAGE = 24,
    CMD_BLITIMAGE2 = 25,
    CMD_BLITIMAGE2KHR = 26,
    CMD_BUILDACCELERATIONSTRUCTURENV = 27,
    CMD_BUILDACCELERATIONSTRUCTURESINDIRECTKHR = 28,
    CMD_BUILDACCELERATIONSTRUCTURESKHR = 29,
    CMD_BUILDMICROMAPSEXT = 30,
    CMD_CLEARATTACHMENTS = 31,
    CMD_CLEARCOLORIMAGE = 32,
    CMD_CLEARDEPTHSTENCILIMAGE = 33,
    CMD_CONTROLVIDEOCODINGKHR = 34,
    CMD_COPYACCELERATIONSTRUCTUREKHR = 35,
    CMD_COPYACCELERATIONSTRUCTURENV = 36,
    CMD_COPYACCELERATIONSTRUCTURETOMEMORYKHR = 37,
    CMD_COPYBUFFER = 38,
    CMD_COPYBUFFER2 = 39,
    CMD_COPYBUFFER2KHR = 40,
    CMD_COPYBUFFERTOIMAGE = 41,
    CMD_COPYBUFFERTOIMAGE2 = 42,
    CMD_COPYBUFFERTOIMAGE2KHR = 43,
    CMD_COPYIMAGE = 44,
    CMD_COPYIMAGE2 = 45,
    CMD_COPYIMAGE2KHR = 46,
    CMD_COPYIMAGETOBUFFER = 47,
    CMD_COPYIMAGETOBUFFER2 = 48,
    CMD_COPYIMAGETOBUFFER2KHR = 49,
    CMD_COPYMEMORYINDIRECTNV = 50,
    CMD_COPYMEMORYTOACCELERATIONSTRUCTUREKHR = 51,
    CMD_COPYMEMORYTOIMAGEINDIRECTNV = 52,
    CMD_COPYMEMORYTOMICROMAPEXT = 53,
    CMD_COPYMICROMAPEXT = 54,
    CMD_COPYMICROMAPTOMEMORYEXT = 55,
    CMD_COPYQUERYPOOLRESULTS = 56,
    CMD_CULAUNCHKERNELNVX = 57,
    CMD_DEBUGMARKERBEGINEXT = 58,
    CMD_DEBUGMARKERENDEXT = 59,
    CMD_DEBUGMARKERINSERTEXT = 60,
    CMD_DECODEVIDEOKHR = 61,
    CMD_DECOMPRESSMEMORYINDIRECTCOUNTNV = 62,
    CMD_DECOMPRESSMEMORYNV = 63,
    CMD_DISPATCH = 64,
    CMD_DISPATCHBASE = 65,
    CMD_DISPATCHBASEKHR = 66,
    CMD_DISPATCHINDIRECT = 67,
    CMD_DRAW = 68,
    CMD_DRAWCLUSTERHUAWEI = 69,
    CMD_DRAWCLUSTERINDIRECTHUAWEI = 70,
    CMD_DRAWINDEXED = 71,
    CMD_DRAWINDEXEDINDIRECT = 72,
    CMD_DRAWINDEXEDINDIRECTCOUNT = 73,
    CMD_DRAWINDEXEDINDIRECTCOUNTAMD = 74,
    CMD_DRAWINDEXEDINDIRECTCOUNTKHR = 75,
    CMD_DRAWINDIRECT = 76,
    CMD_DRAWINDIRECTBYTECOUNTEXT = 77,
    CMD_DRAWINDIRECTCOUNT = 78,
    CMD_DRAWINDIRECTCOUNTAMD = 79,
    CMD_DRAWINDIRECTCOUNTKHR = 80,
    CMD_DRAWMESHTASKSEXT = 81,
    CMD_DRAWMESHTASKSINDIRECTCOUNTEXT = 82,
    CMD_DRAWMESHTASKSINDIRECTCOUNTNV = 83,
    CMD_DRAWMESHTASKSINDIRECTEXT = 84,
    CMD_DRAWMESHTASKSINDIRECTNV = 85,
    CMD_DRAWMESHTASKSNV = 86,
    CMD_DRAWMULTIEXT = 87,
    CMD_DRAWMULTIINDEXEDEXT = 88,
    CMD_ENCODEVIDEOKHR = 89,
    CMD_ENDCONDITIONALRENDERINGEXT = 90,
    CMD_ENDDEBUGUTILSLABELEXT = 91,
    CMD_ENDQUERY = 92,
    CMD_ENDQUERYINDEXEDEXT = 93,
    CMD_ENDRENDERPASS = 94,
    CMD_ENDRENDERPASS2 = 95,
    CMD_ENDRENDERPASS2KHR = 96,
    CMD_ENDRENDERING = 97,
    CMD_ENDRENDERINGKHR = 98,
    CMD_ENDTRANSFORMFEEDBACKEXT = 99,
    CMD_ENDVIDEOCODINGKHR = 100,
    CMD_EXECUTECOMMANDS = 101,
    CMD_EXECUTEGENERATEDCOMMANDSNV = 102,
    CMD_FILLBUFFER = 103,
    CMD_INSERTDEBUGUTILSLABELEXT = 104,
    CMD_NEXTSUBPASS = 105,
    CMD_NEXTSUBPASS2 = 106,
    CMD_NEXTSUBPASS2KHR = 107,
    CMD_OPTICALFLOWEXECUTENV = 108,
    CMD_PIPELINEBARRIER = 109,
    CMD_PIPELINEBARRIER2 = 110,
    CMD_PIPELINEBARRIER2KHR = 111,
    CMD_PREPROCESSGENERATEDCOMMANDSNV = 112,
    CMD_PUSHCONSTANTS = 113,
    CMD_PUSHDESCRIPTORSETKHR = 114,
    CMD_PUSHDESCRIPTORSETWITHTEMPLATEKHR = 115,
    CMD_REFRESHOBJECTSKHR = 116,
    CMD_RESETEVENT = 117,
    CMD_RESETEVENT2 = 118,
    CMD_RESETEVENT2KHR = 119,
    CMD_RESETQUERYPOOL = 120,
    CMD_RESOLVEIMAGE = 121,
    CMD_RESOLVEIMAGE2 = 122,
    CMD_RESOLVEIMAGE2KHR = 123,
    CMD_SETALPHATOCOVERAGEENABLEEXT = 124,
    CMD_SETALPHATOONEENABLEEXT = 125,
    CMD_SETBLENDCONSTANTS = 126,
    CMD_SETCHECKPOINTNV = 127,
    CMD_SETCOARSESAMPLEORDERNV = 128,
    CMD_SETCOLORBLENDADVANCEDEXT = 129,
    CMD_SETCOLORBLENDENABLEEXT = 130,
    CMD_SETCOLORBLENDEQUATIONEXT = 131,
    CMD_SETCOLORWRITEENABLEEXT = 132,
    CMD_SETCOLORWRITEMASKEXT = 133,
    CMD_SETCONSERVATIVERASTERIZATIONMODEEXT = 134,
    CMD_SETCOVERAGEMODULATIONMODENV = 135,
    CMD_SETCOVERAGEMODULATIONTABLEENABLENV = 136,
    CMD_SETCOVERAGEMODULATIONTABLENV = 137,
    CMD_SETCOVERAGEREDUCTIONMODENV = 138,
    CMD_SETCOVERAGETOCOLORENABLENV = 139,
    CMD_SETCOVERAGETOCOLORLOCATIONNV = 140,
    CMD_SETCULLMODE = 141,
    CMD_SETCULLMODEEXT = 142,
    CMD_SETDEPTHBIAS = 143,
    CMD_SETDEPTHBIASENABLE = 144,
    CMD_SETDEPTHBIASENABLEEXT = 145,
    CMD_SETDEPTHBOUNDS = 146,
    CMD_SETDEPTHBOUNDSTESTENABLE = 147,
    CMD_SETDEPTHBOUNDSTESTENABLEEXT = 148,
    CMD_SETDEPTHCLAMPENABLEEXT = 149,
    CMD_SETDEPTHCLIPENABLEEXT = 150,
    CMD_SETDEPTHCLIPNEGATIVEONETOONEEXT = 151,
    CMD_SETDEPTHCOMPAREOP = 152,
    CMD_SETDEPTHCOMPAREOPEXT = 153,
    CMD_SETDEPTHTESTENABLE = 154,
    CMD_SETDEPTHTESTENABLEEXT = 155,
    CMD_SETDEPTHWRITEENABLE = 156,
    CMD_SETDEPTHWRITEENABLEEXT = 157,
    CMD_SETDESCRIPTORBUFFEROFFSETSEXT = 158,
    CMD_SETDEVICEMASK = 159,
    CMD_SETDEVICEMASKKHR = 160,
    CMD_SETDISCARDRECTANGLEEXT = 161,
    CMD_SETDISCARDRECTANGLEENABLEEXT = 162,
    CMD_SETDISCARDRECTANGLEMODEEXT = 163,
    CMD_SETEVENT = 164,
    CMD_SETEVENT2 = 165,
    CMD_SETEVENT2KHR = 166,
    CMD_SETEXCLUSIVESCISSORENABLENV = 167,
    CMD_SETEXCLUSIVESCISSORNV = 168,
    CMD_SETEXTRAPRIMITIVEOVERESTIMATIONSIZEEXT = 169,
    CMD_SETFRAGMENTSHADINGRATEENUMNV = 170,
    CMD_SETFRAGMENTSHADINGRATEKHR = 171,
    CMD_SETFRONTFACE = 172,
    CMD_SETFRONTFACEEXT = 173,
    CMD_SETLINERASTERIZATIONMODEEXT = 174,
    CMD_SETLINESTIPPLEEXT = 175,
    CMD_SETLINESTIPPLEENABLEEXT = 176,
    CMD_SETLINEWIDTH = 177,
    CMD_SETLOGICOPEXT = 178,
    CMD_SETLOGICOPENABLEEXT = 179,
    CMD_SETPATCHCONTROLPOINTSEXT = 180,
    CMD_SETPERFORMANCEMARKERINTEL = 181,
    CMD_SETPERFORMANCEOVERRIDEINTEL = 182,
    CMD_SETPERFORMANCESTREAMMARKERINTEL = 183,
    CMD_SETPOLYGONMODEEXT = 184,
    CMD_SETPRIMITIVERESTARTENABLE = 185,
    CMD_SETPRIMITIVERESTARTENABLEEXT = 186,
    CMD_SETPRIMITIVETOPOLOGY = 187,
    CMD_SETPRIMITIVETOPOLOGYEXT = 188,
    CMD_SETPROVOKINGVERTEXMODEEXT = 189,
    CMD_SETRASTERIZATIONSAMPLESEXT = 190,
    CMD_SETRASTERIZATIONSTREAMEXT = 191,
    CMD_SETRASTERIZERDISCARDENABLE = 192,
    CMD_SETRASTERIZERDISCARDENABLEEXT = 193,
    CMD_SETRAYTRACINGPIPELINESTACKSIZEKHR = 194,
    CMD_SETREPRESENTATIVEFRAGMENTTESTENABLENV = 195,
    CMD_SETSAMPLELOCATIONSEXT = 196,
    CMD_SETSAMPLELOCATIONSENABLEEXT = 197,
    CMD_SETSAMPLEMASKEXT = 198,
    CMD_SETSCISSOR = 199,
    CMD_SETSCISSORWITHCOUNT = 200,
    CMD_SETSCISSORWITHCOUNTEXT = 201,
    CMD_SETSHADINGRATEIMAGEENABLENV = 202,
    CMD_SETSTENCILCOMPAREMASK = 203,
    CMD_SETSTENCILOP = 204,
    CMD_SETSTENCILOPEXT = 205,
    CMD_SETSTENCILREFERENCE = 206,
    CMD_SETSTENCILTESTENABLE = 207,
    CMD_SETSTENCILTESTENABLEEXT = 208,
    CMD_SETSTENCILWRITEMASK = 209,
    CMD_SETTESSELLATIONDOMAINORIGINEXT = 210,
    CMD_SETVERTEXINPUTEXT = 211,
    CMD_SETVIEWPORT = 212,
    CMD_SETVIEWPORTSHADINGRATEPALETTENV = 213,
    CMD_SETVIEWPORTSWIZZLENV = 214,
    CMD_SETVIEWPORTWSCALINGENABLENV = 215,
    CMD_SETVIEWPORTWSCALINGNV = 216,
    CMD_SETVIEWPORTWITHCOUNT = 217,
    CMD_SETVIEWPORTWITHCOUNTEXT = 218,
    CMD_SUBPASSSHADINGHUAWEI = 219,
    CMD_TRACERAYSINDIRECT2KHR = 220,
    CMD_TRACERAYSINDIRECTKHR = 221,
    CMD_TRACERAYSKHR = 222,
    CMD_TRACERAYSNV = 223,
    CMD_UPDATEBUFFER = 224,
    CMD_WAITEVENTS = 225,
    CMD_WAITEVENTS2 = 226,
    CMD_WAITEVENTS2KHR = 227,
    CMD_WRITEACCELERATIONSTRUCTURESPROPERTIESKHR = 228,
    CMD_WRITEACCELERATIONSTRUCTURESPROPERTIESNV = 229,
    CMD_WRITEBUFFERMARKER2AMD = 230,
    CMD_WRITEBUFFERMARKERAMD = 231,
    CMD_WRITEMICROMAPSPROPERTIESEXT = 232,
    CMD_WRITETIMESTAMP = 233,
    CMD_WRITETIMESTAMP2 = 234,
    CMD_WRITETIMESTAMP2KHR = 235,
    CMD_RANGE_SIZE = 236
} CMD_TYPE;

static const std::array<const char *, CMD_RANGE_SIZE> kGeneratedCommandNameList = {{
    "Command_Undefined",
    "vkCmdBeginConditionalRenderingEXT",
    "vkCmdBeginDebugUtilsLabelEXT",
    "vkCmdBeginQuery",
    "vkCmdBeginQueryIndexedEXT",
    "vkCmdBeginRenderPass",
    "vkCmdBeginRenderPass2",
    "vkCmdBeginRenderPass2KHR",
    "vkCmdBeginRendering",
    "vkCmdBeginRenderingKHR",
    "vkCmdBeginTransformFeedbackEXT",
    "vkCmdBeginVideoCodingKHR",
    "vkCmdBindDescriptorBufferEmbeddedSamplersEXT",
    "vkCmdBindDescriptorBuffersEXT",
    "vkCmdBindDescriptorSets",
    "vkCmdBindIndexBuffer",
    "vkCmdBindInvocationMaskHUAWEI",
    "vkCmdBindPipeline",
    "vkCmdBindPipelineShaderGroupNV",
    "vkCmdBindShadingRateImageNV",
    "vkCmdBindTransformFeedbackBuffersEXT",
    "vkCmdBindVertexBuffers",
    "vkCmdBindVertexBuffers2",
    "vkCmdBindVertexBuffers2EXT",
    "vkCmdBlitImage",
    "vkCmdBlitImage2",
    "vkCmdBlitImage2KHR",
    "vkCmdBuildAccelerationStructureNV",
    "vkCmdBuildAccelerationStructuresIndirectKHR",
    "vkCmdBuildAccelerationStructuresKHR",
    "vkCmdBuildMicromapsEXT",
    "vkCmdClearAttachments",
    "vkCmdClearColorImage",
    "vkCmdClearDepthStencilImage",
    "vkCmdControlVideoCodingKHR",
    "vkCmdCopyAccelerationStructureKHR",
    "vkCmdCopyAccelerationStructureNV",
    "vkCmdCopyAccelerationStructureToMemoryKHR",
    "vkCmdCopyBuffer",
    "vkCmdCopyBuffer2",
    "vkCmdCopyBuffer2KHR",
    "vkCmdCopyBufferToImage",
    "vkCmdCopyBufferToImage2",
    "vkCmdCopyBufferToImage2KHR",
    "vkCmdCopyImage",
    "vkCmdCopyImage2",
    "vkCmdCopyImage2KHR",
    "vkCmdCopyImageToBuffer",
    "vkCmdCopyImageToBuffer2",
    "vkCmdCopyImageToBuffer2KHR",
    "vkCmdCopyMemoryIndirectNV",
    "vkCmdCopyMemoryToAccelerationStructureKHR",
    "vkCmdCopyMemoryToImageIndirectNV",
    "vkCmdCopyMemoryToMicromapEXT",
    "vkCmdCopyMicromapEXT",
    "vkCmdCopyMicromapToMemoryEXT",
    "vkCmdCopyQueryPoolResults",
    "vkCmdCuLaunchKernelNVX",
    "vkCmdDebugMarkerBeginEXT",
    "vkCmdDebugMarkerEndEXT",
    "vkCmdDebugMarkerInsertEXT",
    "vkCmdDecodeVideoKHR",
    "vkCmdDecompressMemoryIndirectCountNV",
    "vkCmdDecompressMemoryNV",
    "vkCmdDispatch",
    "vkCmdDispatchBase",
    "vkCmdDispatchBaseKHR",
    "vkCmdDispatchIndirect",
    "vkCmdDraw",
    "vkCmdDrawClusterHUAWEI",
    "vkCmdDrawClusterIndirectHUAWEI",
    "vkCmdDrawIndexed",
    "vkCmdDrawIndexedIndirect",
    "vkCmdDrawIndexedIndirectCount",
    "vkCmdDrawIndexedIndirectCountAMD",
    "vkCmdDrawIndexedIndirectCountKHR",
    "vkCmdDrawIndirect",
    "vkCmdDrawIndirectByteCountEXT",
    "vkCmdDrawIndirectCount",
    "vkCmdDrawIndirectCountAMD",
    "vkCmdDrawIndirectCountKHR",
    "vkCmdDrawMeshTasksEXT",
    "vkCmdDrawMeshTasksIndirectCountEXT",
    "vkCmdDrawMeshTasksIndirectCountNV",
    "vkCmdDrawMeshTasksIndirectEXT",
    "vkCmdDrawMeshTasksIndirectNV",
    "vkCmdDrawMeshTasksNV",
    "vkCmdDrawMultiEXT",
    "vkCmdDrawMultiIndexedEXT",
    "vkCmdEncodeVideoKHR",
    "vkCmdEndConditionalRenderingEXT",
    "vkCmdEndDebugUtilsLabelEXT",
    "vkCmdEndQuery",
    "vkCmdEndQueryIndexedEXT",
    "vkCmdEndRenderPass",
    "vkCmdEndRenderPass2",
    "vkCmdEndRenderPass2KHR",
    "vkCmdEndRendering",
    "vkCmdEndRenderingKHR",
    "vkCmdEndTransformFeedbackEXT",
    "vkCmdEndVideoCodingKHR",
    "vkCmdExecuteCommands",
    "vkCmdExecuteGeneratedCommandsNV",
    "vkCmdFillBuffer",
    "vkCmdInsertDebugUtilsLabelEXT",
    "vkCmdNextSubpass",
    "vkCmdNextSubpass2",
    "vkCmdNextSubpass2KHR",
    "vkCmdOpticalFlowExecuteNV",
    "vkCmdPipelineBarrier",
    "vkCmdPipelineBarrier2",
    "vkCmdPipelineBarrier2KHR",
    "vkCmdPreprocessGeneratedCommandsNV",
    "vkCmdPushConstants",
    "vkCmdPushDescriptorSetKHR",
    "vkCmdPushDescriptorSetWithTemplateKHR",
    "vkCmdRefreshObjectsKHR",
    "vkCmdResetEvent",
    "vkCmdResetEvent2",
    "vkCmdResetEvent2KHR",
    "vkCmdResetQueryPool",
    "vkCmdResolveImage",
    "vkCmdResolveImage2",
    "vkCmdResolveImage2KHR",
    "vkCmdSetAlphaToCoverageEnableEXT",
    "vkCmdSetAlphaToOneEnableEXT",
    "vkCmdSetBlendConstants",
    "vkCmdSetCheckpointNV",
    "vkCmdSetCoarseSampleOrderNV",
    "vkCmdSetColorBlendAdvancedEXT",
    "vkCmdSetColorBlendEnableEXT",
    "vkCmdSetColorBlendEquationEXT",
    "vkCmdSetColorWriteEnableEXT",
    "vkCmdSetColorWriteMaskEXT",
    "vkCmdSetConservativeRasterizationModeEXT",
    "vkCmdSetCoverageModulationModeNV",
    "vkCmdSetCoverageModulationTableEnableNV",
    "vkCmdSetCoverageModulationTableNV",
    "vkCmdSetCoverageReductionModeNV",
    "vkCmdSetCoverageToColorEnableNV",
    "vkCmdSetCoverageToColorLocationNV",
    "vkCmdSetCullMode",
    "vkCmdSetCullModeEXT",
    "vkCmdSetDepthBias",
    "vkCmdSetDepthBiasEnable",
    "vkCmdSetDepthBiasEnableEXT",
    "vkCmdSetDepthBounds",
    "vkCmdSetDepthBoundsTestEnable",
    "vkCmdSetDepthBoundsTestEnableEXT",
    "vkCmdSetDepthClampEnableEXT",
    "vkCmdSetDepthClipEnableEXT",
    "vkCmdSetDepthClipNegativeOneToOneEXT",
    "vkCmdSetDepthCompareOp",
    "vkCmdSetDepthCompareOpEXT",
    "vkCmdSetDepthTestEnable",
    "vkCmdSetDepthTestEnableEXT",
    "vkCmdSetDepthWriteEnable",
    "vkCmdSetDepthWriteEnableEXT",
    "vkCmdSetDescriptorBufferOffsetsEXT",
    "vkCmdSetDeviceMask",
    "vkCmdSetDeviceMaskKHR",
    "vkCmdSetDiscardRectangleEXT",
    "vkCmdSetDiscardRectangleEnableEXT",
    "vkCmdSetDiscardRectangleModeEXT",
    "vkCmdSetEvent",
    "vkCmdSetEvent2",
    "vkCmdSetEvent2KHR",
    "vkCmdSetExclusiveScissorEnableNV",
    "vkCmdSetExclusiveScissorNV",
    "vkCmdSetExtraPrimitiveOverestimationSizeEXT",
    "vkCmdSetFragmentShadingRateEnumNV",
    "vkCmdSetFragmentShadingRateKHR",
    "vkCmdSetFrontFace",
    "vkCmdSetFrontFaceEXT",
    "vkCmdSetLineRasterizationModeEXT",
    "vkCmdSetLineStippleEXT",
    "vkCmdSetLineStippleEnableEXT",
    "vkCmdSetLineWidth",
    "vkCmdSetLogicOpEXT",
    "vkCmdSetLogicOpEnableEXT",
    "vkCmdSetPatchControlPointsEXT",
    "vkCmdSetPerformanceMarkerINTEL",
    "vkCmdSetPerformanceOverrideINTEL",
    "vkCmdSetPerformanceStreamMarkerINTEL",
    "vkCmdSetPolygonModeEXT",
    "vkCmdSetPrimitiveRestartEnable",
    "vkCmdSetPrimitiveRestartEnableEXT",
    "vkCmdSetPrimitiveTopology",
    "vkCmdSetPrimitiveTopologyEXT",
    "vkCmdSetProvokingVertexModeEXT",
    "vkCmdSetRasterizationSamplesEXT",
    "vkCmdSetRasterizationStreamEXT",
    "vkCmdSetRasterizerDiscardEnable",
    "vkCmdSetRasterizerDiscardEnableEXT",
    "vkCmdSetRayTracingPipelineStackSizeKHR",
    "vkCmdSetRepresentativeFragmentTestEnableNV",
    "vkCmdSetSampleLocationsEXT",
    "vkCmdSetSampleLocationsEnableEXT",
    "vkCmdSetSampleMaskEXT",
    "vkCmdSetScissor",
    "vkCmdSetScissorWithCount",
    "vkCmdSetScissorWithCountEXT",
    "vkCmdSetShadingRateImageEnableNV",
    "vkCmdSetStencilCompareMask",
    "vkCmdSetStencilOp",
    "vkCmdSetStencilOpEXT",
    "vkCmdSetStencilReference",
    "vkCmdSetStencilTestEnable",
    "vkCmdSetStencilTestEnableEXT",
    "vkCmdSetStencilWriteMask",
    "vkCmdSetTessellationDomainOriginEXT",
    "vkCmdSetVertexInputEXT",
    "vkCmdSetViewport",
    "vkCmdSetViewportShadingRatePaletteNV",
    "vkCmdSetViewportSwizzleNV",
    "vkCmdSetViewportWScalingEnableNV",
    "vkCmdSetViewportWScalingNV",
    "vkCmdSetViewportWithCount",
    "vkCmdSetViewportWithCountEXT",
    "vkCmdSubpassShadingHUAWEI",
    "vkCmdTraceRaysIndirect2KHR",
    "vkCmdTraceRaysIndirectKHR",
    "vkCmdTraceRaysKHR",
    "vkCmdTraceRaysNV",
    "vkCmdUpdateBuffer",
    "vkCmdWaitEvents",
    "vkCmdWaitEvents2",
    "vkCmdWaitEvents2KHR",
    "vkCmdWriteAccelerationStructuresPropertiesKHR",
    "vkCmdWriteAccelerationStructuresPropertiesNV",
    "vkCmdWriteBufferMarker2AMD",
    "vkCmdWriteBufferMarkerAMD",
    "vkCmdWriteMicromapsPropertiesEXT",
    "vkCmdWriteTimestamp",
    "vkCmdWriteTimestamp2",
    "vkCmdWriteTimestamp2KHR",
}};

typedef enum CBDynamicStatus {
    CB_DYNAMIC_VIEWPORT_SET = 1,
    CB_DYNAMIC_SCISSOR_SET = 2,
    CB_DYNAMIC_LINE_WIDTH_SET = 3,
    CB_DYNAMIC_DEPTH_BIAS_SET = 4,
    CB_DYNAMIC_BLEND_CONSTANTS_SET = 5,
    CB_DYNAMIC_DEPTH_BOUNDS_SET = 6,
    CB_DYNAMIC_STENCIL_COMPARE_MASK_SET = 7,
    CB_DYNAMIC_STENCIL_WRITE_MASK_SET = 8,
    CB_DYNAMIC_STENCIL_REFERENCE_SET = 9,
    CB_DYNAMIC_CULL_MODE_SET = 10,
    CB_DYNAMIC_FRONT_FACE_SET = 11,
    CB_DYNAMIC_PRIMITIVE_TOPOLOGY_SET = 12,
    CB_DYNAMIC_VIEWPORT_WITH_COUNT_SET = 13,
    CB_DYNAMIC_SCISSOR_WITH_COUNT_SET = 14,
    CB_DYNAMIC_VERTEX_INPUT_BINDING_STRIDE_SET = 15,
    CB_DYNAMIC_DEPTH_TEST_ENABLE_SET = 16,
    CB_DYNAMIC_DEPTH_WRITE_ENABLE_SET = 17,
    CB_DYNAMIC_DEPTH_COMPARE_OP_SET = 18,
    CB_DYNAMIC_DEPTH_BOUNDS_TEST_ENABLE_SET = 19,
    CB_DYNAMIC_STENCIL_TEST_ENABLE_SET = 20,
    CB_DYNAMIC_STENCIL_OP_SET = 21,
    CB_DYNAMIC_RASTERIZER_DISCARD_ENABLE_SET = 22,
    CB_DYNAMIC_DEPTH_BIAS_ENABLE_SET = 23,
    CB_DYNAMIC_PRIMITIVE_RESTART_ENABLE_SET = 24,
    CB_DYNAMIC_VIEWPORT_W_SCALING_NV_SET = 25,
    CB_DYNAMIC_DISCARD_RECTANGLE_EXT_SET = 26,
    CB_DYNAMIC_DISCARD_RECTANGLE_ENABLE_EXT_SET = 27,
    CB_DYNAMIC_DISCARD_RECTANGLE_MODE_EXT_SET = 28,
    CB_DYNAMIC_SAMPLE_LOCATIONS_EXT_SET = 29,
    CB_DYNAMIC_RAY_TRACING_PIPELINE_STACK_SIZE_KHR_SET = 30,
    CB_DYNAMIC_VIEWPORT_SHADING_RATE_PALETTE_NV_SET = 31,
    CB_DYNAMIC_VIEWPORT_COARSE_SAMPLE_ORDER_NV_SET = 32,
    CB_DYNAMIC_EXCLUSIVE_SCISSOR_ENABLE_NV_SET = 33,
    CB_DYNAMIC_EXCLUSIVE_SCISSOR_NV_SET = 34,
    CB_DYNAMIC_FRAGMENT_SHADING_RATE_KHR_SET = 35,
    CB_DYNAMIC_LINE_STIPPLE_EXT_SET = 36,
    CB_DYNAMIC_VERTEX_INPUT_EXT_SET = 37,
    CB_DYNAMIC_PATCH_CONTROL_POINTS_EXT_SET = 38,
    CB_DYNAMIC_LOGIC_OP_EXT_SET = 39,
    CB_DYNAMIC_COLOR_WRITE_ENABLE_EXT_SET = 40,
    CB_DYNAMIC_TESSELLATION_DOMAIN_ORIGIN_EXT_SET = 41,
    CB_DYNAMIC_DEPTH_CLAMP_ENABLE_EXT_SET = 42,
    CB_DYNAMIC_POLYGON_MODE_EXT_SET = 43,
    CB_DYNAMIC_RASTERIZATION_SAMPLES_EXT_SET = 44,
    CB_DYNAMIC_SAMPLE_MASK_EXT_SET = 45,
    CB_DYNAMIC_ALPHA_TO_COVERAGE_ENABLE_EXT_SET = 46,
    CB_DYNAMIC_ALPHA_TO_ONE_ENABLE_EXT_SET = 47,
    CB_DYNAMIC_LOGIC_OP_ENABLE_EXT_SET = 48,
    CB_DYNAMIC_COLOR_BLEND_ENABLE_EXT_SET = 49,
    CB_DYNAMIC_COLOR_BLEND_EQUATION_EXT_SET = 50,
    CB_DYNAMIC_COLOR_WRITE_MASK_EXT_SET = 51,
    CB_DYNAMIC_RASTERIZATION_STREAM_EXT_SET = 52,
    CB_DYNAMIC_CONSERVATIVE_RASTERIZATION_MODE_EXT_SET = 53,
    CB_DYNAMIC_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT_SET = 54,
    CB_DYNAMIC_DEPTH_CLIP_ENABLE_EXT_SET = 55,
    CB_DYNAMIC_SAMPLE_LOCATIONS_ENABLE_EXT_SET = 56,
    CB_DYNAMIC_COLOR_BLEND_ADVANCED_EXT_SET = 57,
    CB_DYNAMIC_PROVOKING_VERTEX_MODE_EXT_SET = 58,
    CB_DYNAMIC_LINE_RASTERIZATION_MODE_EXT_SET = 59,
    CB_DYNAMIC_LINE_STIPPLE_ENABLE_EXT_SET = 60,
    CB_DYNAMIC_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT_SET = 61,
    CB_DYNAMIC_VIEWPORT_W_SCALING_ENABLE_NV_SET = 62,
    CB_DYNAMIC_VIEWPORT_SWIZZLE_NV_SET = 63,
    CB_DYNAMIC_COVERAGE_TO_COLOR_ENABLE_NV_SET = 64,
    CB_DYNAMIC_COVERAGE_TO_COLOR_LOCATION_NV_SET = 65,
    CB_DYNAMIC_COVERAGE_MODULATION_MODE_NV_SET = 66,
    CB_DYNAMIC_COVERAGE_MODULATION_TABLE_ENABLE_NV_SET = 67,
    CB_DYNAMIC_COVERAGE_MODULATION_TABLE_NV_SET = 68,
    CB_DYNAMIC_SHADING_RATE_IMAGE_ENABLE_NV_SET = 69,
    CB_DYNAMIC_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV_SET = 70,
    CB_DYNAMIC_COVERAGE_REDUCTION_MODE_NV_SET = 71,
    CB_DYNAMIC_STATUS_NUM = 72
} CBDynamicStatus;

using CBDynamicFlags = std::bitset<CB_DYNAMIC_STATUS_NUM>;
const char* DynamicStateToString(CBDynamicStatus status);
std::string DynamicStatesToString(CBDynamicFlags const &dynamic_state);
struct VkPipelineDynamicStateCreateInfo;
CBDynamicFlags MakeStaticStateMask(VkPipelineDynamicStateCreateInfo const *info);
