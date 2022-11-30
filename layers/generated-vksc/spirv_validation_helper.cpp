// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See spirv_validation_generator.py for modifications


/***************************************************************************
 *
 * Copyright (c) 2020-2021 The Khronos Group Inc.
 * Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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
 *
 * Author: Spencer Fricke <s.fricke@samsung.com>
 *
 * This file is related to anything that is found in the Vulkan XML related
 * to SPIR-V. Anything related to the SPIR-V grammar belongs in spirv_grammar_helper
 *
 ****************************************************************************/

#include <string>
#include <functional>
#include <spirv/unified1/spirv.hpp>
#include "vk_extension_helper.h"
#include "shader_module.h"
#include "device_state.h"
#include "core_validation.h"

struct FeaturePointer {
    // Callable object to test if this feature is enabled in the given aggregate feature struct
    const std::function<VkBool32(const DeviceFeatures &)> IsEnabled;

    // Test if feature pointer is populated
    explicit operator bool() const { return static_cast<bool>(IsEnabled); }

    // Default and nullptr constructor to create an empty FeaturePointer
    FeaturePointer() : IsEnabled(nullptr) {}
    FeaturePointer(std::nullptr_t ptr) : IsEnabled(nullptr) {}

    // Constructors to populate FeaturePointer based on given pointer to member
    FeaturePointer(VkBool32 VkPhysicalDeviceFeatures::*ptr)
        : IsEnabled([=](const DeviceFeatures &features) { return features.core.*ptr; }) {}
    FeaturePointer(VkBool32 VkPhysicalDeviceVulkan11Features::*ptr)
        : IsEnabled([=](const DeviceFeatures &features) { return features.core11.*ptr; }) {}
    FeaturePointer(VkBool32 VkPhysicalDeviceVulkan12Features::*ptr)
        : IsEnabled([=](const DeviceFeatures &features) { return features.core12.*ptr; }) {}
    FeaturePointer(VkBool32 VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT::*ptr)
        : IsEnabled([=](const DeviceFeatures &features) { return features.fragment_shader_interlock_features.*ptr; }) {}
    FeaturePointer(VkBool32 VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT::*ptr)
        : IsEnabled([=](const DeviceFeatures &features) { return features.demote_to_helper_invocation_features.*ptr; }) {}
    FeaturePointer(VkBool32 VkPhysicalDeviceFragmentShadingRateFeaturesKHR::*ptr)
        : IsEnabled([=](const DeviceFeatures &features) { return features.fragment_shading_rate_features.*ptr; }) {}
    FeaturePointer(VkBool32 VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::*ptr)
        : IsEnabled([=](const DeviceFeatures &features) { return features.shader_atomic_float_features.*ptr; }) {}
    FeaturePointer(VkBool32 VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT::*ptr)
        : IsEnabled([=](const DeviceFeatures &features) { return features.shader_image_atomic_int64_features.*ptr; }) {}
};

// Each instance of the struct will only have a singel field non-null
struct RequiredSpirvInfo {
    uint32_t version;
    FeaturePointer feature;
    ExtEnabled DeviceExtensions::*extension;
    const char* property; // For human readability and make some capabilities unique
};

// clang-format off
static const std::unordered_multimap<uint32_t, RequiredSpirvInfo> spirvCapabilities = {
#if defined(VK_EXT_shader_atomic_float2)
    {spv::CapabilityAtomicFloat16AddEXT, {0, &VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderBufferFloat16AtomicAdd, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float2)
    {spv::CapabilityAtomicFloat16AddEXT, {0, &VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderSharedFloat16AtomicAdd, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float2)
    {spv::CapabilityAtomicFloat16MinMaxEXT, {0, &VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderBufferFloat16AtomicMinMax, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float2)
    {spv::CapabilityAtomicFloat16MinMaxEXT, {0, &VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderSharedFloat16AtomicMinMax, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float)
    {spv::CapabilityAtomicFloat32AddEXT, {0, &VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderBufferFloat32AtomicAdd, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float)
    {spv::CapabilityAtomicFloat32AddEXT, {0, &VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderSharedFloat32AtomicAdd, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float)
    {spv::CapabilityAtomicFloat32AddEXT, {0, &VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderImageFloat32AtomicAdd, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float2)
    {spv::CapabilityAtomicFloat32MinMaxEXT, {0, &VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderBufferFloat32AtomicMinMax, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float2)
    {spv::CapabilityAtomicFloat32MinMaxEXT, {0, &VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderSharedFloat32AtomicMinMax, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float2)
    {spv::CapabilityAtomicFloat32MinMaxEXT, {0, &VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderImageFloat32AtomicMinMax, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float)
    {spv::CapabilityAtomicFloat64AddEXT, {0, &VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderBufferFloat64AtomicAdd, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float)
    {spv::CapabilityAtomicFloat64AddEXT, {0, &VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderSharedFloat64AtomicAdd, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float2)
    {spv::CapabilityAtomicFloat64MinMaxEXT, {0, &VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderBufferFloat64AtomicMinMax, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float2)
    {spv::CapabilityAtomicFloat64MinMaxEXT, {0, &VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderSharedFloat64AtomicMinMax, nullptr, ""}},
#endif
    {spv::CapabilityClipDistance, {0, &VkPhysicalDeviceFeatures::shaderClipDistance, nullptr, ""}},
#if defined(VK_NV_compute_shader_derivatives)
    {spv::CapabilityComputeDerivativeGroupLinearNV, {0, &VkPhysicalDeviceComputeShaderDerivativesFeaturesNV::computeDerivativeGroupLinear, nullptr, ""}},
#endif
#if defined(VK_NV_compute_shader_derivatives)
    {spv::CapabilityComputeDerivativeGroupQuadsNV, {0, &VkPhysicalDeviceComputeShaderDerivativesFeaturesNV::computeDerivativeGroupQuads, nullptr, ""}},
#endif
#if defined(VK_NV_cooperative_matrix)
    {spv::CapabilityCooperativeMatrixNV, {0, &VkPhysicalDeviceCooperativeMatrixFeaturesNV::cooperativeMatrix, nullptr, ""}},
#endif
    {spv::CapabilityCullDistance, {0, &VkPhysicalDeviceFeatures::shaderCullDistance, nullptr, ""}},
#if defined(VK_EXT_shader_demote_to_helper_invocation)
    {spv::CapabilityDemoteToHelperInvocationEXT, {0, &VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT::shaderDemoteToHelperInvocation, nullptr, ""}},
#endif
    {spv::CapabilityDenormFlushToZero, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderDenormFlushToZeroFloat16 & VK_TRUE) != 0"}},
    {spv::CapabilityDenormFlushToZero, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderDenormFlushToZeroFloat32 & VK_TRUE) != 0"}},
    {spv::CapabilityDenormFlushToZero, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderDenormFlushToZeroFloat64 & VK_TRUE) != 0"}},
    {spv::CapabilityDenormPreserve, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderDenormPreserveFloat16 & VK_TRUE) != 0"}},
    {spv::CapabilityDenormPreserve, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderDenormPreserveFloat32 & VK_TRUE) != 0"}},
    {spv::CapabilityDenormPreserve, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderDenormPreserveFloat64 & VK_TRUE) != 0"}},
    {spv::CapabilityDerivativeControl, {VK_API_VERSION_1_0, nullptr, nullptr, ""}},
    {spv::CapabilityDeviceGroup, {VK_API_VERSION_1_1, nullptr, nullptr, ""}},
#if defined(VK_KHR_device_group)
    {spv::CapabilityDeviceGroup, {0, nullptr, &DeviceExtensions::vk_khr_device_group, ""}},
#endif
#if defined(VK_KHR_shader_integer_dot_product)
    {spv::CapabilityDotProductInput4x8BitKHR, {0, &VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR::shaderIntegerDotProduct, nullptr, ""}},
#endif
#if defined(VK_KHR_shader_integer_dot_product)
    {spv::CapabilityDotProductInput4x8BitPackedKHR, {0, &VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR::shaderIntegerDotProduct, nullptr, ""}},
#endif
#if defined(VK_KHR_shader_integer_dot_product)
    {spv::CapabilityDotProductInputAllKHR, {0, &VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR::shaderIntegerDotProduct, nullptr, ""}},
#endif
#if defined(VK_KHR_shader_integer_dot_product)
    {spv::CapabilityDotProductKHR, {0, &VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR::shaderIntegerDotProduct, nullptr, ""}},
#endif
    {spv::CapabilityDrawParameters, {0, &VkPhysicalDeviceVulkan11Features::shaderDrawParameters, nullptr, ""}},
#if defined(VK_KHR_shader_draw_parameters)
    {spv::CapabilityDrawParameters, {0, nullptr, &DeviceExtensions::vk_khr_shader_draw_parameters, ""}},
#endif
    {spv::CapabilityFloat16, {0, &VkPhysicalDeviceVulkan12Features::shaderFloat16, nullptr, ""}},
#if defined(VK_AMD_gpu_shader_half_float)
    {spv::CapabilityFloat16, {0, nullptr, &DeviceExtensions::vk_amd_gpu_shader_half_float, ""}},
#endif
    {spv::CapabilityFloat64, {0, &VkPhysicalDeviceFeatures::shaderFloat64, nullptr, ""}},
#if defined(VK_NV_fragment_shader_barycentric)
    {spv::CapabilityFragmentBarycentricNV, {0, &VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV::fragmentShaderBarycentric, nullptr, ""}},
#endif
#if defined(VK_EXT_fragment_density_map)
    {spv::CapabilityFragmentDensityEXT, {0, &VkPhysicalDeviceFragmentDensityMapFeaturesEXT::fragmentDensityMap, nullptr, ""}},
#endif
#if defined(VK_AMD_shader_fragment_mask)
    {spv::CapabilityFragmentMaskAMD, {0, nullptr, &DeviceExtensions::vk_amd_shader_fragment_mask, ""}},
#endif
#if defined(VK_EXT_fragment_shader_interlock)
    {spv::CapabilityFragmentShaderPixelInterlockEXT, {0, &VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT::fragmentShaderPixelInterlock, nullptr, ""}},
#endif
#if defined(VK_EXT_fragment_shader_interlock)
    {spv::CapabilityFragmentShaderSampleInterlockEXT, {0, &VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT::fragmentShaderSampleInterlock, nullptr, ""}},
#endif
#if defined(VK_EXT_fragment_shader_interlock)
    {spv::CapabilityFragmentShaderShadingRateInterlockEXT, {0, &VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT::fragmentShaderShadingRateInterlock, nullptr, ""}},
#endif
#if defined(VK_NV_shading_rate_image)
    {spv::CapabilityFragmentShaderShadingRateInterlockEXT, {0, &VkPhysicalDeviceShadingRateImageFeaturesNV::shadingRateImage, nullptr, ""}},
#endif
#if defined(VK_KHR_fragment_shading_rate)
    {spv::CapabilityFragmentShadingRateKHR, {0, &VkPhysicalDeviceFragmentShadingRateFeaturesKHR::pipelineFragmentShadingRate, nullptr, ""}},
#endif
#if defined(VK_KHR_fragment_shading_rate)
    {spv::CapabilityFragmentShadingRateKHR, {0, &VkPhysicalDeviceFragmentShadingRateFeaturesKHR::primitiveFragmentShadingRate, nullptr, ""}},
#endif
#if defined(VK_KHR_fragment_shading_rate)
    {spv::CapabilityFragmentShadingRateKHR, {0, &VkPhysicalDeviceFragmentShadingRateFeaturesKHR::attachmentFragmentShadingRate, nullptr, ""}},
#endif
    {spv::CapabilityGeometry, {0, &VkPhysicalDeviceFeatures::geometryShader, nullptr, ""}},
    {spv::CapabilityGeometryPointSize, {0, &VkPhysicalDeviceFeatures::shaderTessellationAndGeometryPointSize, nullptr, ""}},
#if defined(VK_NV_geometry_shader_passthrough)
    {spv::CapabilityGeometryShaderPassthroughNV, {0, nullptr, &DeviceExtensions::vk_nv_geometry_shader_passthrough, ""}},
#endif
#if defined(VK_EXT_transform_feedback)
    {spv::CapabilityGeometryStreams, {0, &VkPhysicalDeviceTransformFeedbackFeaturesEXT::geometryStreams, nullptr, ""}},
#endif
    {spv::CapabilityGroupNonUniform, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan11Properties::subgroupSupportedOperations & VK_SUBGROUP_FEATURE_BASIC_BIT) != 0"}},
    {spv::CapabilityGroupNonUniformArithmetic, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan11Properties::subgroupSupportedOperations & VK_SUBGROUP_FEATURE_ARITHMETIC_BIT) != 0"}},
    {spv::CapabilityGroupNonUniformBallot, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan11Properties::subgroupSupportedOperations & VK_SUBGROUP_FEATURE_BALLOT_BIT) != 0"}},
    {spv::CapabilityGroupNonUniformClustered, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan11Properties::subgroupSupportedOperations & VK_SUBGROUP_FEATURE_CLUSTERED_BIT) != 0"}},
    {spv::CapabilityGroupNonUniformPartitionedNV, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan11Properties::subgroupSupportedOperations & VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV) != 0"}},
    {spv::CapabilityGroupNonUniformQuad, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan11Properties::subgroupSupportedOperations & VK_SUBGROUP_FEATURE_QUAD_BIT) != 0"}},
    {spv::CapabilityGroupNonUniformShuffle, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan11Properties::subgroupSupportedOperations & VK_SUBGROUP_FEATURE_SHUFFLE_BIT) != 0"}},
    {spv::CapabilityGroupNonUniformShuffleRelative, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan11Properties::subgroupSupportedOperations & VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT) != 0"}},
    {spv::CapabilityGroupNonUniformVote, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan11Properties::subgroupSupportedOperations & VK_SUBGROUP_FEATURE_VOTE_BIT) != 0"}},
    {spv::CapabilityImage1D, {VK_API_VERSION_1_0, nullptr, nullptr, ""}},
    {spv::CapabilityImageBuffer, {VK_API_VERSION_1_0, nullptr, nullptr, ""}},
    {spv::CapabilityImageCubeArray, {0, &VkPhysicalDeviceFeatures::imageCubeArray, nullptr, ""}},
#if defined(VK_NV_shader_image_footprint)
    {spv::CapabilityImageFootprintNV, {0, &VkPhysicalDeviceShaderImageFootprintFeaturesNV::imageFootprint, nullptr, ""}},
#endif
#if defined(VK_AMD_texture_gather_bias_lod)
    {spv::CapabilityImageGatherBiasLodAMD, {0, nullptr, &DeviceExtensions::vk_amd_texture_gather_bias_lod, ""}},
#endif
    {spv::CapabilityImageGatherExtended, {0, &VkPhysicalDeviceFeatures::shaderImageGatherExtended, nullptr, ""}},
    {spv::CapabilityImageMSArray, {0, &VkPhysicalDeviceFeatures::shaderStorageImageMultisample, nullptr, ""}},
    {spv::CapabilityImageQuery, {VK_API_VERSION_1_0, nullptr, nullptr, ""}},
#if defined(VK_AMD_shader_image_load_store_lod)
    {spv::CapabilityImageReadWriteLodAMD, {0, nullptr, &DeviceExtensions::vk_amd_shader_image_load_store_lod, ""}},
#endif
    {spv::CapabilityInputAttachment, {VK_API_VERSION_1_0, nullptr, nullptr, ""}},
    {spv::CapabilityInputAttachmentArrayDynamicIndexing, {0, &VkPhysicalDeviceVulkan12Features::shaderInputAttachmentArrayDynamicIndexing, nullptr, ""}},
    {spv::CapabilityInputAttachmentArrayNonUniformIndexing, {0, &VkPhysicalDeviceVulkan12Features::shaderInputAttachmentArrayNonUniformIndexing, nullptr, ""}},
    {spv::CapabilityInt16, {0, &VkPhysicalDeviceFeatures::shaderInt16, nullptr, ""}},
    {spv::CapabilityInt64, {0, &VkPhysicalDeviceFeatures::shaderInt64, nullptr, ""}},
    {spv::CapabilityInt64Atomics, {0, &VkPhysicalDeviceVulkan12Features::shaderBufferInt64Atomics, nullptr, ""}},
    {spv::CapabilityInt64Atomics, {0, &VkPhysicalDeviceVulkan12Features::shaderSharedInt64Atomics, nullptr, ""}},
#if defined(VK_EXT_shader_image_atomic_int64)
    {spv::CapabilityInt64Atomics, {0, &VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT::shaderImageInt64Atomics, nullptr, ""}},
#endif
#if defined(VK_EXT_shader_image_atomic_int64)
    {spv::CapabilityInt64ImageEXT, {0, &VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT::shaderImageInt64Atomics, nullptr, ""}},
#endif
    {spv::CapabilityInt8, {0, &VkPhysicalDeviceVulkan12Features::shaderInt8, nullptr, ""}},
#if defined(VK_INTEL_shader_integer_functions2)
    {spv::CapabilityIntegerFunctions2INTEL, {0, &VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL::shaderIntegerFunctions2, nullptr, ""}},
#endif
    {spv::CapabilityInterpolationFunction, {0, &VkPhysicalDeviceFeatures::sampleRateShading, nullptr, ""}},
    {spv::CapabilityMatrix, {VK_API_VERSION_1_0, nullptr, nullptr, ""}},
#if defined(VK_NV_mesh_shader)
    {spv::CapabilityMeshShadingNV, {0, nullptr, &DeviceExtensions::vk_nv_mesh_shader, ""}},
#endif
    {spv::CapabilityMinLod, {0, &VkPhysicalDeviceFeatures::shaderResourceMinLod, nullptr, ""}},
    {spv::CapabilityMultiView, {0, &VkPhysicalDeviceVulkan11Features::multiview, nullptr, ""}},
    {spv::CapabilityMultiViewport, {0, &VkPhysicalDeviceFeatures::multiViewport, nullptr, ""}},
#if defined(VK_NVX_multiview_per_view_attributes)
    {spv::CapabilityPerViewAttributesNV, {0, nullptr, &DeviceExtensions::vk_nvx_multiview_per_view_attributes, ""}},
#endif
    {spv::CapabilityPhysicalStorageBufferAddresses, {0, &VkPhysicalDeviceVulkan12Features::bufferDeviceAddress, nullptr, ""}},
#if defined(VK_EXT_buffer_device_address)
    {spv::CapabilityPhysicalStorageBufferAddresses, {0, &VkPhysicalDeviceBufferDeviceAddressFeaturesEXT::bufferDeviceAddress, nullptr, ""}},
#endif
#if defined(VK_KHR_ray_query)
    {spv::CapabilityRayQueryKHR, {0, &VkPhysicalDeviceRayQueryFeaturesKHR::rayQuery, nullptr, ""}},
#endif
#if defined(VK_KHR_ray_tracing_pipeline)
    {spv::CapabilityRayTracingKHR, {0, &VkPhysicalDeviceRayTracingPipelineFeaturesKHR::rayTracingPipeline, nullptr, ""}},
#endif
#if defined(VK_NV_ray_tracing_motion_blur)
    {spv::CapabilityRayTracingMotionBlurNV, {0, &VkPhysicalDeviceRayTracingMotionBlurFeaturesNV::rayTracingMotionBlur, nullptr, ""}},
#endif
#if defined(VK_NV_ray_tracing)
    {spv::CapabilityRayTracingNV, {0, nullptr, &DeviceExtensions::vk_nv_ray_tracing, ""}},
#endif
#if defined(VK_KHR_ray_tracing_pipeline)
    {spv::CapabilityRayTraversalPrimitiveCullingKHR, {0, &VkPhysicalDeviceRayTracingPipelineFeaturesKHR::rayTraversalPrimitiveCulling, nullptr, ""}},
#endif
    {spv::CapabilityRoundingModeRTE, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderRoundingModeRTEFloat16 & VK_TRUE) != 0"}},
    {spv::CapabilityRoundingModeRTE, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderRoundingModeRTEFloat32 & VK_TRUE) != 0"}},
    {spv::CapabilityRoundingModeRTE, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderRoundingModeRTEFloat64 & VK_TRUE) != 0"}},
    {spv::CapabilityRoundingModeRTZ, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderRoundingModeRTZFloat16 & VK_TRUE) != 0"}},
    {spv::CapabilityRoundingModeRTZ, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderRoundingModeRTZFloat32 & VK_TRUE) != 0"}},
    {spv::CapabilityRoundingModeRTZ, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderRoundingModeRTZFloat64 & VK_TRUE) != 0"}},
    {spv::CapabilityRuntimeDescriptorArray, {0, &VkPhysicalDeviceVulkan12Features::runtimeDescriptorArray, nullptr, ""}},
#if defined(VK_NV_sample_mask_override_coverage)
    {spv::CapabilitySampleMaskOverrideCoverageNV, {0, nullptr, &DeviceExtensions::vk_nv_sample_mask_override_coverage, ""}},
#endif
#if defined(VK_EXT_post_depth_coverage)
    {spv::CapabilitySampleMaskPostDepthCoverage, {0, nullptr, &DeviceExtensions::vk_ext_post_depth_coverage, ""}},
#endif
    {spv::CapabilitySampleRateShading, {0, &VkPhysicalDeviceFeatures::sampleRateShading, nullptr, ""}},
    {spv::CapabilitySampled1D, {VK_API_VERSION_1_0, nullptr, nullptr, ""}},
    {spv::CapabilitySampledBuffer, {VK_API_VERSION_1_0, nullptr, nullptr, ""}},
    {spv::CapabilitySampledCubeArray, {0, &VkPhysicalDeviceFeatures::imageCubeArray, nullptr, ""}},
    {spv::CapabilitySampledImageArrayDynamicIndexing, {0, &VkPhysicalDeviceFeatures::shaderSampledImageArrayDynamicIndexing, nullptr, ""}},
    {spv::CapabilitySampledImageArrayNonUniformIndexing, {0, &VkPhysicalDeviceVulkan12Features::shaderSampledImageArrayNonUniformIndexing, nullptr, ""}},
    {spv::CapabilityShader, {VK_API_VERSION_1_0, nullptr, nullptr, ""}},
#if defined(VK_KHR_shader_clock)
    {spv::CapabilityShaderClockKHR, {0, nullptr, &DeviceExtensions::vk_khr_shader_clock, ""}},
#endif
    {spv::CapabilityShaderLayer, {0, &VkPhysicalDeviceVulkan12Features::shaderOutputLayer, nullptr, ""}},
    {spv::CapabilityShaderNonUniform, {VK_API_VERSION_1_2, nullptr, nullptr, ""}},
#if defined(VK_EXT_descriptor_indexing)
    {spv::CapabilityShaderNonUniform, {0, nullptr, &DeviceExtensions::vk_ext_descriptor_indexing, ""}},
#endif
#if defined(VK_NV_shader_sm_builtins)
    {spv::CapabilityShaderSMBuiltinsNV, {0, &VkPhysicalDeviceShaderSMBuiltinsFeaturesNV::shaderSMBuiltins, nullptr, ""}},
#endif
    {spv::CapabilityShaderViewportIndex, {0, &VkPhysicalDeviceVulkan12Features::shaderOutputViewportIndex, nullptr, ""}},
#if defined(VK_EXT_shader_viewport_index_layer)
    {spv::CapabilityShaderViewportIndexLayerEXT, {0, nullptr, &DeviceExtensions::vk_ext_shader_viewport_index_layer, ""}},
#endif
#if defined(VK_NV_viewport_array2)
    {spv::CapabilityShaderViewportIndexLayerNV, {0, nullptr, &DeviceExtensions::vk_nv_viewport_array2, ""}},
#endif
#if defined(VK_NV_viewport_array2)
    {spv::CapabilityShaderViewportMaskNV, {0, nullptr, &DeviceExtensions::vk_nv_viewport_array2, ""}},
#endif
#if defined(VK_NV_shading_rate_image)
    {spv::CapabilityShadingRateNV, {0, &VkPhysicalDeviceShadingRateImageFeaturesNV::shadingRateImage, nullptr, ""}},
#endif
    {spv::CapabilitySignedZeroInfNanPreserve, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderSignedZeroInfNanPreserveFloat16 & VK_TRUE) != 0"}},
    {spv::CapabilitySignedZeroInfNanPreserve, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderSignedZeroInfNanPreserveFloat32 & VK_TRUE) != 0"}},
    {spv::CapabilitySignedZeroInfNanPreserve, {0, nullptr, nullptr, "(VkPhysicalDeviceVulkan12Properties::shaderSignedZeroInfNanPreserveFloat64 & VK_TRUE) != 0"}},
    {spv::CapabilitySparseResidency, {0, &VkPhysicalDeviceFeatures::shaderResourceResidency, nullptr, ""}},
#if defined(VK_EXT_shader_stencil_export)
    {spv::CapabilityStencilExportEXT, {0, nullptr, &DeviceExtensions::vk_ext_shader_stencil_export, ""}},
#endif
    {spv::CapabilityStorageBuffer16BitAccess, {0, &VkPhysicalDeviceVulkan11Features::storageBuffer16BitAccess, nullptr, ""}},
    {spv::CapabilityStorageBuffer8BitAccess, {0, &VkPhysicalDeviceVulkan12Features::storageBuffer8BitAccess, nullptr, ""}},
    {spv::CapabilityStorageBufferArrayDynamicIndexing, {0, &VkPhysicalDeviceFeatures::shaderStorageBufferArrayDynamicIndexing, nullptr, ""}},
    {spv::CapabilityStorageBufferArrayNonUniformIndexing, {0, &VkPhysicalDeviceVulkan12Features::shaderStorageBufferArrayNonUniformIndexing, nullptr, ""}},
    {spv::CapabilityStorageImageArrayDynamicIndexing, {0, &VkPhysicalDeviceFeatures::shaderStorageImageArrayDynamicIndexing, nullptr, ""}},
    {spv::CapabilityStorageImageArrayNonUniformIndexing, {0, &VkPhysicalDeviceVulkan12Features::shaderStorageImageArrayNonUniformIndexing, nullptr, ""}},
    {spv::CapabilityStorageImageExtendedFormats, {VK_API_VERSION_1_0, nullptr, nullptr, ""}},
    {spv::CapabilityStorageImageMultisample, {0, &VkPhysicalDeviceFeatures::shaderStorageImageMultisample, nullptr, ""}},
    {spv::CapabilityStorageImageReadWithoutFormat, {0, &VkPhysicalDeviceFeatures::shaderStorageImageReadWithoutFormat, nullptr, ""}},
#if defined(VK_KHR_format_feature_flags2)
    {spv::CapabilityStorageImageReadWithoutFormat, {0, nullptr, &DeviceExtensions::vk_khr_format_feature_flags2, ""}},
#endif
    {spv::CapabilityStorageImageWriteWithoutFormat, {0, &VkPhysicalDeviceFeatures::shaderStorageImageWriteWithoutFormat, nullptr, ""}},
#if defined(VK_KHR_format_feature_flags2)
    {spv::CapabilityStorageImageWriteWithoutFormat, {0, nullptr, &DeviceExtensions::vk_khr_format_feature_flags2, ""}},
#endif
    {spv::CapabilityStorageInputOutput16, {0, &VkPhysicalDeviceVulkan11Features::storageInputOutput16, nullptr, ""}},
    {spv::CapabilityStoragePushConstant16, {0, &VkPhysicalDeviceVulkan11Features::storagePushConstant16, nullptr, ""}},
    {spv::CapabilityStoragePushConstant8, {0, &VkPhysicalDeviceVulkan12Features::storagePushConstant8, nullptr, ""}},
    {spv::CapabilityStorageTexelBufferArrayDynamicIndexing, {0, &VkPhysicalDeviceVulkan12Features::shaderStorageTexelBufferArrayDynamicIndexing, nullptr, ""}},
    {spv::CapabilityStorageTexelBufferArrayNonUniformIndexing, {0, &VkPhysicalDeviceVulkan12Features::shaderStorageTexelBufferArrayNonUniformIndexing, nullptr, ""}},
#if defined(VK_EXT_shader_subgroup_ballot)
    {spv::CapabilitySubgroupBallotKHR, {0, nullptr, &DeviceExtensions::vk_ext_shader_subgroup_ballot, ""}},
#endif
#if defined(VK_EXT_shader_subgroup_vote)
    {spv::CapabilitySubgroupVoteKHR, {0, nullptr, &DeviceExtensions::vk_ext_shader_subgroup_vote, ""}},
#endif
    {spv::CapabilityTessellation, {0, &VkPhysicalDeviceFeatures::tessellationShader, nullptr, ""}},
    {spv::CapabilityTessellationPointSize, {0, &VkPhysicalDeviceFeatures::shaderTessellationAndGeometryPointSize, nullptr, ""}},
#if defined(VK_EXT_transform_feedback)
    {spv::CapabilityTransformFeedback, {0, &VkPhysicalDeviceTransformFeedbackFeaturesEXT::transformFeedback, nullptr, ""}},
#endif
    {spv::CapabilityUniformAndStorageBuffer16BitAccess, {0, &VkPhysicalDeviceVulkan11Features::uniformAndStorageBuffer16BitAccess, nullptr, ""}},
    {spv::CapabilityUniformAndStorageBuffer8BitAccess, {0, &VkPhysicalDeviceVulkan12Features::uniformAndStorageBuffer8BitAccess, nullptr, ""}},
    {spv::CapabilityUniformBufferArrayDynamicIndexing, {0, &VkPhysicalDeviceFeatures::shaderUniformBufferArrayDynamicIndexing, nullptr, ""}},
    {spv::CapabilityUniformBufferArrayNonUniformIndexing, {0, &VkPhysicalDeviceVulkan12Features::shaderUniformBufferArrayNonUniformIndexing, nullptr, ""}},
    {spv::CapabilityUniformTexelBufferArrayDynamicIndexing, {0, &VkPhysicalDeviceVulkan12Features::shaderUniformTexelBufferArrayDynamicIndexing, nullptr, ""}},
    {spv::CapabilityUniformTexelBufferArrayNonUniformIndexing, {0, &VkPhysicalDeviceVulkan12Features::shaderUniformTexelBufferArrayNonUniformIndexing, nullptr, ""}},
    {spv::CapabilityVariablePointers, {0, &VkPhysicalDeviceVulkan11Features::variablePointers, nullptr, ""}},
    {spv::CapabilityVariablePointersStorageBuffer, {0, &VkPhysicalDeviceVulkan11Features::variablePointersStorageBuffer, nullptr, ""}},
    {spv::CapabilityVulkanMemoryModel, {0, &VkPhysicalDeviceVulkan12Features::vulkanMemoryModel, nullptr, ""}},
    {spv::CapabilityVulkanMemoryModelDeviceScope, {0, &VkPhysicalDeviceVulkan12Features::vulkanMemoryModelDeviceScope, nullptr, ""}},
#if defined(VK_KHR_workgroup_memory_explicit_layout)
    {spv::CapabilityWorkgroupMemoryExplicitLayout16BitAccessKHR, {0, &VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR::workgroupMemoryExplicitLayout16BitAccess, nullptr, ""}},
#endif
#if defined(VK_KHR_workgroup_memory_explicit_layout)
    {spv::CapabilityWorkgroupMemoryExplicitLayout8BitAccessKHR, {0, &VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR::workgroupMemoryExplicitLayout8BitAccess, nullptr, ""}},
#endif
#if defined(VK_KHR_workgroup_memory_explicit_layout)
    {spv::CapabilityWorkgroupMemoryExplicitLayoutKHR, {0, &VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR::workgroupMemoryExplicitLayout, nullptr, ""}},
#endif
};
// clang-format on

// clang-format off
static const std::unordered_multimap<std::string, RequiredSpirvInfo> spirvExtensions = {
#if defined(VK_AMD_gcn_shader)
    {"SPV_AMD_gcn_shader", {0, nullptr, &DeviceExtensions::vk_amd_gcn_shader, ""}},
#endif
#if defined(VK_AMD_gpu_shader_half_float)
    {"SPV_AMD_gpu_shader_half_float", {0, nullptr, &DeviceExtensions::vk_amd_gpu_shader_half_float, ""}},
#endif
#if defined(VK_AMD_gpu_shader_int16)
    {"SPV_AMD_gpu_shader_int16", {0, nullptr, &DeviceExtensions::vk_amd_gpu_shader_int16, ""}},
#endif
#if defined(VK_AMD_shader_ballot)
    {"SPV_AMD_shader_ballot", {0, nullptr, &DeviceExtensions::vk_amd_shader_ballot, ""}},
#endif
#if defined(VK_AMD_shader_explicit_vertex_parameter)
    {"SPV_AMD_shader_explicit_vertex_parameter", {0, nullptr, &DeviceExtensions::vk_amd_shader_explicit_vertex_parameter, ""}},
#endif
#if defined(VK_AMD_shader_fragment_mask)
    {"SPV_AMD_shader_fragment_mask", {0, nullptr, &DeviceExtensions::vk_amd_shader_fragment_mask, ""}},
#endif
#if defined(VK_AMD_shader_image_load_store_lod)
    {"SPV_AMD_shader_image_load_store_lod", {0, nullptr, &DeviceExtensions::vk_amd_shader_image_load_store_lod, ""}},
#endif
#if defined(VK_AMD_shader_trinary_minmax)
    {"SPV_AMD_shader_trinary_minmax", {0, nullptr, &DeviceExtensions::vk_amd_shader_trinary_minmax, ""}},
#endif
#if defined(VK_AMD_texture_gather_bias_lod)
    {"SPV_AMD_texture_gather_bias_lod", {0, nullptr, &DeviceExtensions::vk_amd_texture_gather_bias_lod, ""}},
#endif
#if defined(VK_EXT_shader_demote_to_helper_invocation)
    {"SPV_EXT_demote_to_helper_invocation", {0, nullptr, &DeviceExtensions::vk_ext_shader_demote_to_helper_invocation, ""}},
#endif
    {"SPV_EXT_descriptor_indexing", {VK_API_VERSION_1_2, nullptr, nullptr, ""}},
#if defined(VK_EXT_descriptor_indexing)
    {"SPV_EXT_descriptor_indexing", {0, nullptr, &DeviceExtensions::vk_ext_descriptor_indexing, ""}},
#endif
#if defined(VK_EXT_fragment_density_map)
    {"SPV_EXT_fragment_invocation_density", {0, nullptr, &DeviceExtensions::vk_ext_fragment_density_map, ""}},
#endif
#if defined(VK_EXT_fragment_shader_interlock)
    {"SPV_EXT_fragment_shader_interlock", {0, nullptr, &DeviceExtensions::vk_ext_fragment_shader_interlock, ""}},
#endif
#if defined(VK_EXT_buffer_device_address)
    {"SPV_EXT_physical_storage_buffer", {0, nullptr, &DeviceExtensions::vk_ext_buffer_device_address, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float2)
    {"SPV_EXT_shader_atomic_float16_add", {0, nullptr, &DeviceExtensions::vk_ext_shader_atomic_float2, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float)
    {"SPV_EXT_shader_atomic_float_add", {0, nullptr, &DeviceExtensions::vk_ext_shader_atomic_float, ""}},
#endif
#if defined(VK_EXT_shader_atomic_float2)
    {"SPV_EXT_shader_atomic_float_min_max", {0, nullptr, &DeviceExtensions::vk_ext_shader_atomic_float2, ""}},
#endif
#if defined(VK_EXT_shader_image_atomic_int64)
    {"SPV_EXT_shader_image_int64", {0, nullptr, &DeviceExtensions::vk_ext_shader_image_atomic_int64, ""}},
#endif
#if defined(VK_EXT_shader_stencil_export)
    {"SPV_EXT_shader_stencil_export", {0, nullptr, &DeviceExtensions::vk_ext_shader_stencil_export, ""}},
#endif
    {"SPV_EXT_shader_viewport_index_layer", {VK_API_VERSION_1_2, nullptr, nullptr, ""}},
#if defined(VK_EXT_shader_viewport_index_layer)
    {"SPV_EXT_shader_viewport_index_layer", {0, nullptr, &DeviceExtensions::vk_ext_shader_viewport_index_layer, ""}},
#endif
#if defined(VK_GOOGLE_decorate_string)
    {"SPV_GOOGLE_decorate_string", {0, nullptr, &DeviceExtensions::vk_google_decorate_string, ""}},
#endif
#if defined(VK_GOOGLE_hlsl_functionality1)
    {"SPV_GOOGLE_hlsl_functionality1", {0, nullptr, &DeviceExtensions::vk_google_hlsl_functionality1, ""}},
#endif
#if defined(VK_GOOGLE_user_type)
    {"SPV_GOOGLE_user_type", {0, nullptr, &DeviceExtensions::vk_google_user_type, ""}},
#endif
    {"SPV_KHR_16bit_storage", {VK_API_VERSION_1_1, nullptr, nullptr, ""}},
#if defined(VK_KHR_16bit_storage)
    {"SPV_KHR_16bit_storage", {0, nullptr, &DeviceExtensions::vk_khr_16bit_storage, ""}},
#endif
    {"SPV_KHR_8bit_storage", {VK_API_VERSION_1_2, nullptr, nullptr, ""}},
#if defined(VK_KHR_8bit_storage)
    {"SPV_KHR_8bit_storage", {0, nullptr, &DeviceExtensions::vk_khr_8bit_storage, ""}},
#endif
    {"SPV_KHR_float_controls", {VK_API_VERSION_1_2, nullptr, nullptr, ""}},
#if defined(VK_KHR_shader_float_controls)
    {"SPV_KHR_float_controls", {0, nullptr, &DeviceExtensions::vk_khr_shader_float_controls, ""}},
#endif
#if defined(VK_KHR_fragment_shading_rate)
    {"SPV_KHR_fragment_shading_rate", {0, nullptr, &DeviceExtensions::vk_khr_fragment_shading_rate, ""}},
#endif
#if defined(VK_KHR_shader_integer_dot_product)
    {"SPV_KHR_integer_dot_product", {0, nullptr, &DeviceExtensions::vk_khr_shader_integer_dot_product, ""}},
#endif
    {"SPV_KHR_multiview", {VK_API_VERSION_1_1, nullptr, nullptr, ""}},
#if defined(VK_KHR_multiview)
    {"SPV_KHR_multiview", {0, nullptr, &DeviceExtensions::vk_khr_multiview, ""}},
#endif
#if defined(VK_KHR_shader_non_semantic_info)
    {"SPV_KHR_non_semantic_info", {0, nullptr, &DeviceExtensions::vk_khr_shader_non_semantic_info, ""}},
#endif
    {"SPV_KHR_physical_storage_buffer", {VK_API_VERSION_1_2, nullptr, nullptr, ""}},
#if defined(VK_KHR_buffer_device_address)
    {"SPV_KHR_physical_storage_buffer", {0, nullptr, &DeviceExtensions::vk_khr_buffer_device_address, ""}},
#endif
#if defined(VK_EXT_post_depth_coverage)
    {"SPV_KHR_post_depth_coverage", {0, nullptr, &DeviceExtensions::vk_ext_post_depth_coverage, ""}},
#endif
#if defined(VK_KHR_ray_query)
    {"SPV_KHR_ray_query", {0, nullptr, &DeviceExtensions::vk_khr_ray_query, ""}},
#endif
#if defined(VK_KHR_ray_tracing_pipeline)
    {"SPV_KHR_ray_tracing", {0, nullptr, &DeviceExtensions::vk_khr_ray_tracing_pipeline, ""}},
#endif
#if defined(VK_EXT_shader_subgroup_ballot)
    {"SPV_KHR_shader_ballot", {0, nullptr, &DeviceExtensions::vk_ext_shader_subgroup_ballot, ""}},
#endif
#if defined(VK_KHR_shader_clock)
    {"SPV_KHR_shader_clock", {0, nullptr, &DeviceExtensions::vk_khr_shader_clock, ""}},
#endif
    {"SPV_KHR_shader_draw_parameters", {VK_API_VERSION_1_1, nullptr, nullptr, ""}},
#if defined(VK_KHR_shader_draw_parameters)
    {"SPV_KHR_shader_draw_parameters", {0, nullptr, &DeviceExtensions::vk_khr_shader_draw_parameters, ""}},
#endif
    {"SPV_KHR_storage_buffer_storage_class", {VK_API_VERSION_1_1, nullptr, nullptr, ""}},
#if defined(VK_KHR_storage_buffer_storage_class)
    {"SPV_KHR_storage_buffer_storage_class", {0, nullptr, &DeviceExtensions::vk_khr_storage_buffer_storage_class, ""}},
#endif
#if defined(VK_KHR_shader_subgroup_uniform_control_flow)
    {"SPV_KHR_subgroup_uniform_control_flow", {0, nullptr, &DeviceExtensions::vk_khr_shader_subgroup_uniform_control_flow, ""}},
#endif
#if defined(VK_EXT_shader_subgroup_vote)
    {"SPV_KHR_subgroup_vote", {0, nullptr, &DeviceExtensions::vk_ext_shader_subgroup_vote, ""}},
#endif
#if defined(VK_KHR_shader_terminate_invocation)
    {"SPV_KHR_terminate_invocation", {0, nullptr, &DeviceExtensions::vk_khr_shader_terminate_invocation, ""}},
#endif
    {"SPV_KHR_variable_pointers", {VK_API_VERSION_1_1, nullptr, nullptr, ""}},
#if defined(VK_KHR_variable_pointers)
    {"SPV_KHR_variable_pointers", {0, nullptr, &DeviceExtensions::vk_khr_variable_pointers, ""}},
#endif
    {"SPV_KHR_vulkan_memory_model", {VK_API_VERSION_1_2, nullptr, nullptr, ""}},
#if defined(VK_KHR_vulkan_memory_model)
    {"SPV_KHR_vulkan_memory_model", {0, nullptr, &DeviceExtensions::vk_khr_vulkan_memory_model, ""}},
#endif
#if defined(VK_KHR_workgroup_memory_explicit_layout)
    {"SPV_KHR_workgroup_memory_explicit_layout", {0, nullptr, &DeviceExtensions::vk_khr_workgroup_memory_explicit_layout, ""}},
#endif
#if defined(VK_NVX_multiview_per_view_attributes)
    {"SPV_NVX_multiview_per_view_attributes", {0, nullptr, &DeviceExtensions::vk_nvx_multiview_per_view_attributes, ""}},
#endif
#if defined(VK_NV_compute_shader_derivatives)
    {"SPV_NV_compute_shader_derivatives", {0, nullptr, &DeviceExtensions::vk_nv_compute_shader_derivatives, ""}},
#endif
#if defined(VK_NV_cooperative_matrix)
    {"SPV_NV_cooperative_matrix", {0, nullptr, &DeviceExtensions::vk_nv_cooperative_matrix, ""}},
#endif
#if defined(VK_NV_fragment_shader_barycentric)
    {"SPV_NV_fragment_shader_barycentric", {0, nullptr, &DeviceExtensions::vk_nv_fragment_shader_barycentric, ""}},
#endif
#if defined(VK_NV_geometry_shader_passthrough)
    {"SPV_NV_geometry_shader_passthrough", {0, nullptr, &DeviceExtensions::vk_nv_geometry_shader_passthrough, ""}},
#endif
#if defined(VK_NV_mesh_shader)
    {"SPV_NV_mesh_shader", {0, nullptr, &DeviceExtensions::vk_nv_mesh_shader, ""}},
#endif
#if defined(VK_NV_ray_tracing)
    {"SPV_NV_ray_tracing", {0, nullptr, &DeviceExtensions::vk_nv_ray_tracing, ""}},
#endif
#if defined(VK_NV_sample_mask_override_coverage)
    {"SPV_NV_sample_mask_override_coverage", {0, nullptr, &DeviceExtensions::vk_nv_sample_mask_override_coverage, ""}},
#endif
#if defined(VK_NV_shader_image_footprint)
    {"SPV_NV_shader_image_footprint", {0, nullptr, &DeviceExtensions::vk_nv_shader_image_footprint, ""}},
#endif
#if defined(VK_NV_shader_sm_builtins)
    {"SPV_NV_shader_sm_builtins", {0, nullptr, &DeviceExtensions::vk_nv_shader_sm_builtins, ""}},
#endif
#if defined(VK_NV_shader_subgroup_partitioned)
    {"SPV_NV_shader_subgroup_partitioned", {0, nullptr, &DeviceExtensions::vk_nv_shader_subgroup_partitioned, ""}},
#endif
#if defined(VK_NV_shading_rate_image)
    {"SPV_NV_shading_rate", {0, nullptr, &DeviceExtensions::vk_nv_shading_rate_image, ""}},
#endif
#if defined(VK_NV_viewport_array2)
    {"SPV_NV_viewport_array2", {0, nullptr, &DeviceExtensions::vk_nv_viewport_array2, ""}},
#endif
};
// clang-format on

static inline const char* string_SpvCapability(uint32_t input_value) {
    switch ((spv::Capability)input_value) {
         case spv::CapabilityAtomicFloat16AddEXT:
            return "AtomicFloat16AddEXT";
         case spv::CapabilityAtomicFloat16MinMaxEXT:
            return "AtomicFloat16MinMaxEXT";
         case spv::CapabilityAtomicFloat32AddEXT:
            return "AtomicFloat32AddEXT";
         case spv::CapabilityAtomicFloat32MinMaxEXT:
            return "AtomicFloat32MinMaxEXT";
         case spv::CapabilityAtomicFloat64AddEXT:
            return "AtomicFloat64AddEXT";
         case spv::CapabilityAtomicFloat64MinMaxEXT:
            return "AtomicFloat64MinMaxEXT";
         case spv::CapabilityClipDistance:
            return "ClipDistance";
         case spv::CapabilityComputeDerivativeGroupLinearNV:
            return "ComputeDerivativeGroupLinearNV";
         case spv::CapabilityComputeDerivativeGroupQuadsNV:
            return "ComputeDerivativeGroupQuadsNV";
         case spv::CapabilityCooperativeMatrixNV:
            return "CooperativeMatrixNV";
         case spv::CapabilityCullDistance:
            return "CullDistance";
         case spv::CapabilityDemoteToHelperInvocationEXT:
            return "DemoteToHelperInvocationEXT";
         case spv::CapabilityDenormFlushToZero:
            return "DenormFlushToZero";
         case spv::CapabilityDenormPreserve:
            return "DenormPreserve";
         case spv::CapabilityDerivativeControl:
            return "DerivativeControl";
         case spv::CapabilityDeviceGroup:
            return "DeviceGroup";
         case spv::CapabilityDotProductInput4x8BitKHR:
            return "DotProductInput4x8BitKHR";
         case spv::CapabilityDotProductInput4x8BitPackedKHR:
            return "DotProductInput4x8BitPackedKHR";
         case spv::CapabilityDotProductInputAllKHR:
            return "DotProductInputAllKHR";
         case spv::CapabilityDotProductKHR:
            return "DotProductKHR";
         case spv::CapabilityDrawParameters:
            return "DrawParameters";
         case spv::CapabilityFloat16:
            return "Float16";
         case spv::CapabilityFloat64:
            return "Float64";
         case spv::CapabilityFragmentBarycentricNV:
            return "FragmentBarycentricNV";
         case spv::CapabilityFragmentDensityEXT:
            return "FragmentDensityEXT";
         case spv::CapabilityFragmentMaskAMD:
            return "FragmentMaskAMD";
         case spv::CapabilityFragmentShaderPixelInterlockEXT:
            return "FragmentShaderPixelInterlockEXT";
         case spv::CapabilityFragmentShaderSampleInterlockEXT:
            return "FragmentShaderSampleInterlockEXT";
         case spv::CapabilityFragmentShaderShadingRateInterlockEXT:
            return "FragmentShaderShadingRateInterlockEXT";
         case spv::CapabilityFragmentShadingRateKHR:
            return "FragmentShadingRateKHR";
         case spv::CapabilityGeometry:
            return "Geometry";
         case spv::CapabilityGeometryPointSize:
            return "GeometryPointSize";
         case spv::CapabilityGeometryShaderPassthroughNV:
            return "GeometryShaderPassthroughNV";
         case spv::CapabilityGeometryStreams:
            return "GeometryStreams";
         case spv::CapabilityGroupNonUniform:
            return "GroupNonUniform";
         case spv::CapabilityGroupNonUniformArithmetic:
            return "GroupNonUniformArithmetic";
         case spv::CapabilityGroupNonUniformBallot:
            return "GroupNonUniformBallot";
         case spv::CapabilityGroupNonUniformClustered:
            return "GroupNonUniformClustered";
         case spv::CapabilityGroupNonUniformPartitionedNV:
            return "GroupNonUniformPartitionedNV";
         case spv::CapabilityGroupNonUniformQuad:
            return "GroupNonUniformQuad";
         case spv::CapabilityGroupNonUniformShuffle:
            return "GroupNonUniformShuffle";
         case spv::CapabilityGroupNonUniformShuffleRelative:
            return "GroupNonUniformShuffleRelative";
         case spv::CapabilityGroupNonUniformVote:
            return "GroupNonUniformVote";
         case spv::CapabilityImage1D:
            return "Image1D";
         case spv::CapabilityImageBuffer:
            return "ImageBuffer";
         case spv::CapabilityImageCubeArray:
            return "ImageCubeArray";
         case spv::CapabilityImageFootprintNV:
            return "ImageFootprintNV";
         case spv::CapabilityImageGatherBiasLodAMD:
            return "ImageGatherBiasLodAMD";
         case spv::CapabilityImageGatherExtended:
            return "ImageGatherExtended";
         case spv::CapabilityImageMSArray:
            return "ImageMSArray";
         case spv::CapabilityImageQuery:
            return "ImageQuery";
         case spv::CapabilityImageReadWriteLodAMD:
            return "ImageReadWriteLodAMD";
         case spv::CapabilityInputAttachment:
            return "InputAttachment";
         case spv::CapabilityInputAttachmentArrayDynamicIndexing:
            return "InputAttachmentArrayDynamicIndexing";
         case spv::CapabilityInputAttachmentArrayNonUniformIndexing:
            return "InputAttachmentArrayNonUniformIndexing";
         case spv::CapabilityInt16:
            return "Int16";
         case spv::CapabilityInt64:
            return "Int64";
         case spv::CapabilityInt64Atomics:
            return "Int64Atomics";
         case spv::CapabilityInt64ImageEXT:
            return "Int64ImageEXT";
         case spv::CapabilityInt8:
            return "Int8";
         case spv::CapabilityIntegerFunctions2INTEL:
            return "IntegerFunctions2INTEL";
         case spv::CapabilityInterpolationFunction:
            return "InterpolationFunction";
         case spv::CapabilityMatrix:
            return "Matrix";
         case spv::CapabilityMeshShadingNV:
            return "MeshShadingNV";
         case spv::CapabilityMinLod:
            return "MinLod";
         case spv::CapabilityMultiView:
            return "MultiView";
         case spv::CapabilityMultiViewport:
            return "MultiViewport";
         case spv::CapabilityPerViewAttributesNV:
            return "PerViewAttributesNV";
         case spv::CapabilityPhysicalStorageBufferAddresses:
            return "PhysicalStorageBufferAddresses";
         case spv::CapabilityRayQueryKHR:
            return "RayQueryKHR";
         case spv::CapabilityRayTracingKHR:
            return "RayTracingKHR";
         case spv::CapabilityRayTracingMotionBlurNV:
            return "RayTracingMotionBlurNV";
         case spv::CapabilityRayTracingNV:
            return "RayTracingNV";
         case spv::CapabilityRayTraversalPrimitiveCullingKHR:
            return "RayTraversalPrimitiveCullingKHR";
         case spv::CapabilityRoundingModeRTE:
            return "RoundingModeRTE";
         case spv::CapabilityRoundingModeRTZ:
            return "RoundingModeRTZ";
         case spv::CapabilityRuntimeDescriptorArray:
            return "RuntimeDescriptorArray";
         case spv::CapabilitySampleMaskOverrideCoverageNV:
            return "SampleMaskOverrideCoverageNV";
         case spv::CapabilitySampleMaskPostDepthCoverage:
            return "SampleMaskPostDepthCoverage";
         case spv::CapabilitySampleRateShading:
            return "SampleRateShading";
         case spv::CapabilitySampled1D:
            return "Sampled1D";
         case spv::CapabilitySampledBuffer:
            return "SampledBuffer";
         case spv::CapabilitySampledCubeArray:
            return "SampledCubeArray";
         case spv::CapabilitySampledImageArrayDynamicIndexing:
            return "SampledImageArrayDynamicIndexing";
         case spv::CapabilitySampledImageArrayNonUniformIndexing:
            return "SampledImageArrayNonUniformIndexing";
         case spv::CapabilityShader:
            return "Shader";
         case spv::CapabilityShaderClockKHR:
            return "ShaderClockKHR";
         case spv::CapabilityShaderLayer:
            return "ShaderLayer";
         case spv::CapabilityShaderNonUniform:
            return "ShaderNonUniform";
         case spv::CapabilityShaderSMBuiltinsNV:
            return "ShaderSMBuiltinsNV";
         case spv::CapabilityShaderViewportIndex:
            return "ShaderViewportIndex";
         case spv::CapabilityShaderViewportIndexLayerEXT:
            return "ShaderViewportIndexLayerEXT";
         case spv::CapabilityShaderViewportMaskNV:
            return "ShaderViewportMaskNV";
         case spv::CapabilitySignedZeroInfNanPreserve:
            return "SignedZeroInfNanPreserve";
         case spv::CapabilitySparseResidency:
            return "SparseResidency";
         case spv::CapabilityStencilExportEXT:
            return "StencilExportEXT";
         case spv::CapabilityStorageBuffer16BitAccess:
            return "StorageBuffer16BitAccess";
         case spv::CapabilityStorageBuffer8BitAccess:
            return "StorageBuffer8BitAccess";
         case spv::CapabilityStorageBufferArrayDynamicIndexing:
            return "StorageBufferArrayDynamicIndexing";
         case spv::CapabilityStorageBufferArrayNonUniformIndexing:
            return "StorageBufferArrayNonUniformIndexing";
         case spv::CapabilityStorageImageArrayDynamicIndexing:
            return "StorageImageArrayDynamicIndexing";
         case spv::CapabilityStorageImageArrayNonUniformIndexing:
            return "StorageImageArrayNonUniformIndexing";
         case spv::CapabilityStorageImageExtendedFormats:
            return "StorageImageExtendedFormats";
         case spv::CapabilityStorageImageMultisample:
            return "StorageImageMultisample";
         case spv::CapabilityStorageImageReadWithoutFormat:
            return "StorageImageReadWithoutFormat";
         case spv::CapabilityStorageImageWriteWithoutFormat:
            return "StorageImageWriteWithoutFormat";
         case spv::CapabilityStorageInputOutput16:
            return "StorageInputOutput16";
         case spv::CapabilityStoragePushConstant16:
            return "StoragePushConstant16";
         case spv::CapabilityStoragePushConstant8:
            return "StoragePushConstant8";
         case spv::CapabilityStorageTexelBufferArrayDynamicIndexing:
            return "StorageTexelBufferArrayDynamicIndexing";
         case spv::CapabilityStorageTexelBufferArrayNonUniformIndexing:
            return "StorageTexelBufferArrayNonUniformIndexing";
         case spv::CapabilitySubgroupBallotKHR:
            return "SubgroupBallotKHR";
         case spv::CapabilitySubgroupVoteKHR:
            return "SubgroupVoteKHR";
         case spv::CapabilityTessellation:
            return "Tessellation";
         case spv::CapabilityTessellationPointSize:
            return "TessellationPointSize";
         case spv::CapabilityTransformFeedback:
            return "TransformFeedback";
         case spv::CapabilityUniformAndStorageBuffer16BitAccess:
            return "UniformAndStorageBuffer16BitAccess";
         case spv::CapabilityUniformAndStorageBuffer8BitAccess:
            return "UniformAndStorageBuffer8BitAccess";
         case spv::CapabilityUniformBufferArrayDynamicIndexing:
            return "UniformBufferArrayDynamicIndexing";
         case spv::CapabilityUniformBufferArrayNonUniformIndexing:
            return "UniformBufferArrayNonUniformIndexing";
         case spv::CapabilityUniformTexelBufferArrayDynamicIndexing:
            return "UniformTexelBufferArrayDynamicIndexing";
         case spv::CapabilityUniformTexelBufferArrayNonUniformIndexing:
            return "UniformTexelBufferArrayNonUniformIndexing";
         case spv::CapabilityVariablePointers:
            return "VariablePointers";
         case spv::CapabilityVariablePointersStorageBuffer:
            return "VariablePointersStorageBuffer";
         case spv::CapabilityVulkanMemoryModel:
            return "VulkanMemoryModel";
         case spv::CapabilityVulkanMemoryModelDeviceScope:
            return "VulkanMemoryModelDeviceScope";
         case spv::CapabilityWorkgroupMemoryExplicitLayout16BitAccessKHR:
            return "WorkgroupMemoryExplicitLayout16BitAccessKHR";
         case spv::CapabilityWorkgroupMemoryExplicitLayout8BitAccessKHR:
            return "WorkgroupMemoryExplicitLayout8BitAccessKHR";
         case spv::CapabilityWorkgroupMemoryExplicitLayoutKHR:
            return "WorkgroupMemoryExplicitLayoutKHR";
        default:
            return "Unhandled OpCapability";
    };
};

bool CoreChecks::ValidateShaderCapabilitiesAndExtensions(SHADER_MODULE_STATE const *src, spirv_inst_iter& insn) const {
    bool skip = false;

    if (insn.opcode() == spv::OpCapability) {
        // All capabilities are generated so if it is not in the list it is not supported by Vulkan
        if (spirvCapabilities.count(insn.word(1)) == 0) {
            skip |= LogError(device, "VUID-VkShaderModuleCreateInfo-pCode-01090",
                "vkCreateShaderModule(): A SPIR-V Capability (%s) was declared that is not supported by Vulkan.", string_SpvCapability(insn.word(1)));
            return skip; // no known capability to validate
        }

        // Each capability has one or more requirements to check
        // Only one item has to be satisfied and an error only occurs
        // when all are not satisfied
        auto caps = spirvCapabilities.equal_range(insn.word(1));
        bool has_support = false;
        for (auto it = caps.first; (it != caps.second) && (has_support == false); ++it) {
            if (it->second.version) {
                if (api_version >= it->second.version) {
                    has_support = true;
                }
            } else if (it->second.feature) {
                if (it->second.feature.IsEnabled(enabled_features)) {
                    has_support = true;
                }
            } else if (it->second.extension) {
                // kEnabledByApiLevel is not valid as some extension are promoted with feature bits to be used.
                // If the new Api Level gives support, it will be caught in the "it->second.version" check instead.
                if (IsExtEnabledByCreateinfo(device_extensions.*(it->second.extension))) {
                    has_support = true;
                }
            } else if (it->second.property) {
                // support is or'ed as only one has to be supported (if applicable)
                switch (insn.word(1)) {
#if defined(VK_VERSION_1_2) && defined(VK_KHR_shader_float_controls)
                    case spv::CapabilityDenormFlushToZero:
                        has_support |= ((phys_dev_props_core12.shaderDenormFlushToZeroFloat16 & VK_TRUE) != 0);
                        has_support |= ((phys_dev_props_core12.shaderDenormFlushToZeroFloat32 & VK_TRUE) != 0);
                        has_support |= ((phys_dev_props_core12.shaderDenormFlushToZeroFloat64 & VK_TRUE) != 0);
                        break;
#endif
#if defined(VK_VERSION_1_2) && defined(VK_KHR_shader_float_controls)
                    case spv::CapabilityDenormPreserve:
                        has_support |= ((phys_dev_props_core12.shaderDenormPreserveFloat16 & VK_TRUE) != 0);
                        has_support |= ((phys_dev_props_core12.shaderDenormPreserveFloat32 & VK_TRUE) != 0);
                        has_support |= ((phys_dev_props_core12.shaderDenormPreserveFloat64 & VK_TRUE) != 0);
                        break;
#endif
#if defined(VK_VERSION_1_1)
                    case spv::CapabilityGroupNonUniform:
                        has_support |= ((phys_dev_props_core11.subgroupSupportedOperations & VK_SUBGROUP_FEATURE_BASIC_BIT) != 0);
                        break;
#endif
#if defined(VK_VERSION_1_1)
                    case spv::CapabilityGroupNonUniformArithmetic:
                        has_support |= ((phys_dev_props_core11.subgroupSupportedOperations & VK_SUBGROUP_FEATURE_ARITHMETIC_BIT) != 0);
                        break;
#endif
#if defined(VK_VERSION_1_1)
                    case spv::CapabilityGroupNonUniformBallot:
                        has_support |= ((phys_dev_props_core11.subgroupSupportedOperations & VK_SUBGROUP_FEATURE_BALLOT_BIT) != 0);
                        break;
#endif
#if defined(VK_VERSION_1_1)
                    case spv::CapabilityGroupNonUniformClustered:
                        has_support |= ((phys_dev_props_core11.subgroupSupportedOperations & VK_SUBGROUP_FEATURE_CLUSTERED_BIT) != 0);
                        break;
#endif
#if defined(VK_NV_shader_subgroup_partitioned)
                    case spv::CapabilityGroupNonUniformPartitionedNV:
                        has_support |= ((phys_dev_props_core11.subgroupSupportedOperations & VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV) != 0);
                        break;
#endif
#if defined(VK_VERSION_1_1)
                    case spv::CapabilityGroupNonUniformQuad:
                        has_support |= ((phys_dev_props_core11.subgroupSupportedOperations & VK_SUBGROUP_FEATURE_QUAD_BIT) != 0);
                        break;
#endif
#if defined(VK_VERSION_1_1)
                    case spv::CapabilityGroupNonUniformShuffle:
                        has_support |= ((phys_dev_props_core11.subgroupSupportedOperations & VK_SUBGROUP_FEATURE_SHUFFLE_BIT) != 0);
                        break;
#endif
#if defined(VK_VERSION_1_1)
                    case spv::CapabilityGroupNonUniformShuffleRelative:
                        has_support |= ((phys_dev_props_core11.subgroupSupportedOperations & VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT) != 0);
                        break;
#endif
#if defined(VK_VERSION_1_1)
                    case spv::CapabilityGroupNonUniformVote:
                        has_support |= ((phys_dev_props_core11.subgroupSupportedOperations & VK_SUBGROUP_FEATURE_VOTE_BIT) != 0);
                        break;
#endif
#if defined(VK_VERSION_1_2) && defined(VK_KHR_shader_float_controls)
                    case spv::CapabilityRoundingModeRTE:
                        has_support |= ((phys_dev_props_core12.shaderRoundingModeRTEFloat16 & VK_TRUE) != 0);
                        has_support |= ((phys_dev_props_core12.shaderRoundingModeRTEFloat32 & VK_TRUE) != 0);
                        has_support |= ((phys_dev_props_core12.shaderRoundingModeRTEFloat64 & VK_TRUE) != 0);
                        break;
#endif
#if defined(VK_VERSION_1_2) && defined(VK_KHR_shader_float_controls)
                    case spv::CapabilityRoundingModeRTZ:
                        has_support |= ((phys_dev_props_core12.shaderRoundingModeRTZFloat16 & VK_TRUE) != 0);
                        has_support |= ((phys_dev_props_core12.shaderRoundingModeRTZFloat32 & VK_TRUE) != 0);
                        has_support |= ((phys_dev_props_core12.shaderRoundingModeRTZFloat64 & VK_TRUE) != 0);
                        break;
#endif
#if defined(VK_VERSION_1_2) && defined(VK_KHR_shader_float_controls)
                    case spv::CapabilitySignedZeroInfNanPreserve:
                        has_support |= ((phys_dev_props_core12.shaderSignedZeroInfNanPreserveFloat16 & VK_TRUE) != 0);
                        has_support |= ((phys_dev_props_core12.shaderSignedZeroInfNanPreserveFloat32 & VK_TRUE) != 0);
                        has_support |= ((phys_dev_props_core12.shaderSignedZeroInfNanPreserveFloat64 & VK_TRUE) != 0);
                        break;
#endif

                    default:
                        break;
                }
            }
        }

        if (has_support == false) {
            skip |= LogError(device, "VUID-VkShaderModuleCreateInfo-pCode-01091",
                "vkCreateShaderModule(): The SPIR-V Capability (%s) was declared, but none of the requirements were met to use it.", string_SpvCapability(insn.word(1)));
        }

        // Portability checks
#if defined(VK_KHR_portability_subset)
        if (IsExtEnabled(device_extensions.vk_khr_portability_subset)) {
            if ((VK_FALSE == enabled_features.portability_subset_features.shaderSampleRateInterpolationFunctions) &&
                (spv::CapabilityInterpolationFunction == insn.word(1))) {
                skip |= LogError(device, "VUID-RuntimeSpirv-shaderSampleRateInterpolationFunctions-06325",
                                    "Invalid shader capability (portability error): interpolation functions are not supported "
                                    "by this platform");
            }
        }
#endif
    } else if (insn.opcode() == spv::OpExtension) {
        static const std::string spv_prefix = "SPV_";
        std::string extension_name = (char const *)&insn.word(1);

        if (0 == extension_name.compare(0, spv_prefix.size(), spv_prefix)) {
            if (spirvExtensions.count(extension_name) == 0) {
                skip |= LogError(device, "VUID-VkShaderModuleCreateInfo-pCode-04146",
                    "vkCreateShaderModule(): A SPIR-V Extension (%s) was declared that is not supported by Vulkan.", extension_name.c_str());
                return skip; // no known extension to validate
            }
        } else {
            skip |= LogError(device, kVUID_Core_Shader_InvalidExtension,
                "vkCreateShaderModule(): The SPIR-V code uses the '%s' extension which is not a SPIR-V extension. Please use a SPIR-V"
                " extension (https://github.com/KhronosGroup/SPIRV-Registry) for OpExtension instructions. Non-SPIR-V extensions can be"
                " recorded in SPIR-V using the OpSourceExtension instruction.", extension_name.c_str());
            return skip; // no known extension to validate
        }

        // Each SPIR-V Extension has one or more requirements to check
        // Only one item has to be satisfied and an error only occurs
        // when all are not satisfied
        auto ext = spirvExtensions.equal_range(extension_name);
        bool has_support = false;
        for (auto it = ext.first; (it != ext.second) && (has_support == false); ++it) {
            if (it->second.version) {
                if (api_version >= it->second.version) {
                    has_support = true;
                }
            } else if (it->second.feature) {
                if (it->second.feature.IsEnabled(enabled_features)) {
                    has_support = true;
                }
            } else if (it->second.extension) {
                if (IsExtEnabled(device_extensions.*(it->second.extension))) {
                    has_support = true;
                }
            } else if (it->second.property) {
                // support is or'ed as only one has to be supported (if applicable)
                switch (insn.word(1)) {
                    default:
                        break;
                }
            }
        }

        if (has_support == false) {
            skip |= LogError(device, "VUID-VkShaderModuleCreateInfo-pCode-04147",
                "vkCreateShaderModule(): The SPIR-V Extension (%s) was declared, but none of the requirements were met to use it.", extension_name.c_str());
        }
    } //spv::OpExtension
    return skip;
}
