// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See valid_enum_values_generator.py for modifications

/***************************************************************************
 *
 * Copyright (c) 2015-2023 The Khronos Group Inc.
 * Copyright (c) 2015-2023 Valve Corporation
 * Copyright (c) 2015-2023 LunarG, Inc.
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

// NOLINTBEGIN

#include "chassis.h"
#include "utils/hash_vk_types.h"

// TODO (ncesario) This is not ideal as we compute the enabled extensions every time this function is called.
//      Ideally "values" would be something like a static variable that is built once and this function returns
//      a span of the container. This does not work for applications which create and destroy many instances and
//      devices over the lifespan of the project (e.g., VLT).

// clang-format off

template<>
std::vector<VkResult> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkResultEnums = {VK_SUCCESS, VK_NOT_READY, VK_TIMEOUT, VK_EVENT_SET, VK_EVENT_RESET, VK_INCOMPLETE, VK_ERROR_OUT_OF_HOST_MEMORY, VK_ERROR_OUT_OF_DEVICE_MEMORY, VK_ERROR_INITIALIZATION_FAILED, VK_ERROR_DEVICE_LOST, VK_ERROR_MEMORY_MAP_FAILED, VK_ERROR_LAYER_NOT_PRESENT, VK_ERROR_EXTENSION_NOT_PRESENT, VK_ERROR_FEATURE_NOT_PRESENT, VK_ERROR_INCOMPATIBLE_DRIVER, VK_ERROR_TOO_MANY_OBJECTS, VK_ERROR_FORMAT_NOT_SUPPORTED, VK_ERROR_FRAGMENTED_POOL, VK_ERROR_UNKNOWN, VK_ERROR_OUT_OF_POOL_MEMORY, VK_ERROR_INVALID_EXTERNAL_HANDLE, VK_ERROR_FRAGMENTATION, VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS, VK_PIPELINE_COMPILE_REQUIRED, VK_ERROR_VALIDATION_FAILED, VK_ERROR_INVALID_PIPELINE_CACHE_DATA, VK_ERROR_NO_PIPELINE_MATCH};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkResult>> ExtendedVkResultEnums = {
        { &DeviceExtensions::vk_khr_surface, { VK_ERROR_SURFACE_LOST_KHR, VK_ERROR_NATIVE_WINDOW_IN_USE_KHR } },
        { &DeviceExtensions::vk_khr_swapchain, { VK_SUBOPTIMAL_KHR, VK_ERROR_OUT_OF_DATE_KHR } },
        { &DeviceExtensions::vk_khr_display_swapchain, { VK_ERROR_INCOMPATIBLE_DISPLAY_KHR } },
        { &DeviceExtensions::vk_ext_image_drm_format_modifier, { VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT } },
    };
    std::vector<VkResult> values(CoreVkResultEnums.cbegin(), CoreVkResultEnums.cend());
    std::set<VkResult> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkResultEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkPipelineCacheHeaderVersion> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkPipelineCacheHeaderVersionEnums = {VK_PIPELINE_CACHE_HEADER_VERSION_ONE, VK_PIPELINE_CACHE_HEADER_VERSION_SAFETY_CRITICAL_ONE};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkPipelineCacheHeaderVersion>> ExtendedVkPipelineCacheHeaderVersionEnums = {
    };
    std::vector<VkPipelineCacheHeaderVersion> values(CoreVkPipelineCacheHeaderVersionEnums.cbegin(), CoreVkPipelineCacheHeaderVersionEnums.cend());
    std::set<VkPipelineCacheHeaderVersion> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkPipelineCacheHeaderVersionEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkImageLayout> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkImageLayoutEnums = {VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_GENERAL, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL, VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_PREINITIALIZED, VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL, VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL, VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL, VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkImageLayout>> ExtendedVkImageLayoutEnums = {
        { &DeviceExtensions::vk_khr_swapchain, { VK_IMAGE_LAYOUT_PRESENT_SRC_KHR } },
        { &DeviceExtensions::vk_khr_shared_presentable_image, { VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR } },
        { &DeviceExtensions::vk_khr_fragment_shading_rate, { VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR } },
        { &DeviceExtensions::vk_khr_synchronization2, { VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL } },
    };
    std::vector<VkImageLayout> values(CoreVkImageLayoutEnums.cbegin(), CoreVkImageLayoutEnums.cend());
    std::set<VkImageLayout> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkImageLayoutEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkObjectType> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkObjectTypeEnums = {VK_OBJECT_TYPE_UNKNOWN, VK_OBJECT_TYPE_INSTANCE, VK_OBJECT_TYPE_PHYSICAL_DEVICE, VK_OBJECT_TYPE_DEVICE, VK_OBJECT_TYPE_QUEUE, VK_OBJECT_TYPE_SEMAPHORE, VK_OBJECT_TYPE_COMMAND_BUFFER, VK_OBJECT_TYPE_FENCE, VK_OBJECT_TYPE_DEVICE_MEMORY, VK_OBJECT_TYPE_BUFFER, VK_OBJECT_TYPE_IMAGE, VK_OBJECT_TYPE_EVENT, VK_OBJECT_TYPE_QUERY_POOL, VK_OBJECT_TYPE_BUFFER_VIEW, VK_OBJECT_TYPE_IMAGE_VIEW, VK_OBJECT_TYPE_SHADER_MODULE, VK_OBJECT_TYPE_PIPELINE_CACHE, VK_OBJECT_TYPE_PIPELINE_LAYOUT, VK_OBJECT_TYPE_RENDER_PASS, VK_OBJECT_TYPE_PIPELINE, VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT, VK_OBJECT_TYPE_SAMPLER, VK_OBJECT_TYPE_DESCRIPTOR_POOL, VK_OBJECT_TYPE_DESCRIPTOR_SET, VK_OBJECT_TYPE_FRAMEBUFFER, VK_OBJECT_TYPE_COMMAND_POOL, VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION, VK_OBJECT_TYPE_PRIVATE_DATA_SLOT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkObjectType>> ExtendedVkObjectTypeEnums = {
        { &DeviceExtensions::vk_khr_surface, { VK_OBJECT_TYPE_SURFACE_KHR } },
        { &DeviceExtensions::vk_khr_swapchain, { VK_OBJECT_TYPE_SWAPCHAIN_KHR } },
        { &DeviceExtensions::vk_khr_display, { VK_OBJECT_TYPE_DISPLAY_KHR, VK_OBJECT_TYPE_DISPLAY_MODE_KHR } },
        { &DeviceExtensions::vk_ext_debug_utils, { VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT } },
        { &DeviceExtensions::vk_nv_external_sci_sync2, { VK_OBJECT_TYPE_SEMAPHORE_SCI_SYNC_POOL_NV } },
    };
    std::vector<VkObjectType> values(CoreVkObjectTypeEnums.cbegin(), CoreVkObjectTypeEnums.cend());
    std::set<VkObjectType> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkObjectTypeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkFormat> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkFormatEnums = {VK_FORMAT_UNDEFINED, VK_FORMAT_R4G4_UNORM_PACK8, VK_FORMAT_R4G4B4A4_UNORM_PACK16, VK_FORMAT_B4G4R4A4_UNORM_PACK16, VK_FORMAT_R5G6B5_UNORM_PACK16, VK_FORMAT_B5G6R5_UNORM_PACK16, VK_FORMAT_R5G5B5A1_UNORM_PACK16, VK_FORMAT_B5G5R5A1_UNORM_PACK16, VK_FORMAT_A1R5G5B5_UNORM_PACK16, VK_FORMAT_R8_UNORM, VK_FORMAT_R8_SNORM, VK_FORMAT_R8_USCALED, VK_FORMAT_R8_SSCALED, VK_FORMAT_R8_UINT, VK_FORMAT_R8_SINT, VK_FORMAT_R8_SRGB, VK_FORMAT_R8G8_UNORM, VK_FORMAT_R8G8_SNORM, VK_FORMAT_R8G8_USCALED, VK_FORMAT_R8G8_SSCALED, VK_FORMAT_R8G8_UINT, VK_FORMAT_R8G8_SINT, VK_FORMAT_R8G8_SRGB, VK_FORMAT_R8G8B8_UNORM, VK_FORMAT_R8G8B8_SNORM, VK_FORMAT_R8G8B8_USCALED, VK_FORMAT_R8G8B8_SSCALED, VK_FORMAT_R8G8B8_UINT, VK_FORMAT_R8G8B8_SINT, VK_FORMAT_R8G8B8_SRGB, VK_FORMAT_B8G8R8_UNORM, VK_FORMAT_B8G8R8_SNORM, VK_FORMAT_B8G8R8_USCALED, VK_FORMAT_B8G8R8_SSCALED, VK_FORMAT_B8G8R8_UINT, VK_FORMAT_B8G8R8_SINT, VK_FORMAT_B8G8R8_SRGB, VK_FORMAT_R8G8B8A8_UNORM, VK_FORMAT_R8G8B8A8_SNORM, VK_FORMAT_R8G8B8A8_USCALED, VK_FORMAT_R8G8B8A8_SSCALED, VK_FORMAT_R8G8B8A8_UINT, VK_FORMAT_R8G8B8A8_SINT, VK_FORMAT_R8G8B8A8_SRGB, VK_FORMAT_B8G8R8A8_UNORM, VK_FORMAT_B8G8R8A8_SNORM, VK_FORMAT_B8G8R8A8_USCALED, VK_FORMAT_B8G8R8A8_SSCALED, VK_FORMAT_B8G8R8A8_UINT, VK_FORMAT_B8G8R8A8_SINT, VK_FORMAT_B8G8R8A8_SRGB, VK_FORMAT_A8B8G8R8_UNORM_PACK32, VK_FORMAT_A8B8G8R8_SNORM_PACK32, VK_FORMAT_A8B8G8R8_USCALED_PACK32, VK_FORMAT_A8B8G8R8_SSCALED_PACK32, VK_FORMAT_A8B8G8R8_UINT_PACK32, VK_FORMAT_A8B8G8R8_SINT_PACK32, VK_FORMAT_A8B8G8R8_SRGB_PACK32, VK_FORMAT_A2R10G10B10_UNORM_PACK32, VK_FORMAT_A2R10G10B10_SNORM_PACK32, VK_FORMAT_A2R10G10B10_USCALED_PACK32, VK_FORMAT_A2R10G10B10_SSCALED_PACK32, VK_FORMAT_A2R10G10B10_UINT_PACK32, VK_FORMAT_A2R10G10B10_SINT_PACK32, VK_FORMAT_A2B10G10R10_UNORM_PACK32, VK_FORMAT_A2B10G10R10_SNORM_PACK32, VK_FORMAT_A2B10G10R10_USCALED_PACK32, VK_FORMAT_A2B10G10R10_SSCALED_PACK32, VK_FORMAT_A2B10G10R10_UINT_PACK32, VK_FORMAT_A2B10G10R10_SINT_PACK32, VK_FORMAT_R16_UNORM, VK_FORMAT_R16_SNORM, VK_FORMAT_R16_USCALED, VK_FORMAT_R16_SSCALED, VK_FORMAT_R16_UINT, VK_FORMAT_R16_SINT, VK_FORMAT_R16_SFLOAT, VK_FORMAT_R16G16_UNORM, VK_FORMAT_R16G16_SNORM, VK_FORMAT_R16G16_USCALED, VK_FORMAT_R16G16_SSCALED, VK_FORMAT_R16G16_UINT, VK_FORMAT_R16G16_SINT, VK_FORMAT_R16G16_SFLOAT, VK_FORMAT_R16G16B16_UNORM, VK_FORMAT_R16G16B16_SNORM, VK_FORMAT_R16G16B16_USCALED, VK_FORMAT_R16G16B16_SSCALED, VK_FORMAT_R16G16B16_UINT, VK_FORMAT_R16G16B16_SINT, VK_FORMAT_R16G16B16_SFLOAT, VK_FORMAT_R16G16B16A16_UNORM, VK_FORMAT_R16G16B16A16_SNORM, VK_FORMAT_R16G16B16A16_USCALED, VK_FORMAT_R16G16B16A16_SSCALED, VK_FORMAT_R16G16B16A16_UINT, VK_FORMAT_R16G16B16A16_SINT, VK_FORMAT_R16G16B16A16_SFLOAT, VK_FORMAT_R32_UINT, VK_FORMAT_R32_SINT, VK_FORMAT_R32_SFLOAT, VK_FORMAT_R32G32_UINT, VK_FORMAT_R32G32_SINT, VK_FORMAT_R32G32_SFLOAT, VK_FORMAT_R32G32B32_UINT, VK_FORMAT_R32G32B32_SINT, VK_FORMAT_R32G32B32_SFLOAT, VK_FORMAT_R32G32B32A32_UINT, VK_FORMAT_R32G32B32A32_SINT, VK_FORMAT_R32G32B32A32_SFLOAT, VK_FORMAT_R64_UINT, VK_FORMAT_R64_SINT, VK_FORMAT_R64_SFLOAT, VK_FORMAT_R64G64_UINT, VK_FORMAT_R64G64_SINT, VK_FORMAT_R64G64_SFLOAT, VK_FORMAT_R64G64B64_UINT, VK_FORMAT_R64G64B64_SINT, VK_FORMAT_R64G64B64_SFLOAT, VK_FORMAT_R64G64B64A64_UINT, VK_FORMAT_R64G64B64A64_SINT, VK_FORMAT_R64G64B64A64_SFLOAT, VK_FORMAT_B10G11R11_UFLOAT_PACK32, VK_FORMAT_E5B9G9R9_UFLOAT_PACK32, VK_FORMAT_D16_UNORM, VK_FORMAT_X8_D24_UNORM_PACK32, VK_FORMAT_D32_SFLOAT, VK_FORMAT_S8_UINT, VK_FORMAT_D16_UNORM_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_BC1_RGB_UNORM_BLOCK, VK_FORMAT_BC1_RGB_SRGB_BLOCK, VK_FORMAT_BC1_RGBA_UNORM_BLOCK, VK_FORMAT_BC1_RGBA_SRGB_BLOCK, VK_FORMAT_BC2_UNORM_BLOCK, VK_FORMAT_BC2_SRGB_BLOCK, VK_FORMAT_BC3_UNORM_BLOCK, VK_FORMAT_BC3_SRGB_BLOCK, VK_FORMAT_BC4_UNORM_BLOCK, VK_FORMAT_BC4_SNORM_BLOCK, VK_FORMAT_BC5_UNORM_BLOCK, VK_FORMAT_BC5_SNORM_BLOCK, VK_FORMAT_BC6H_UFLOAT_BLOCK, VK_FORMAT_BC6H_SFLOAT_BLOCK, VK_FORMAT_BC7_UNORM_BLOCK, VK_FORMAT_BC7_SRGB_BLOCK, VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK, VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK, VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK, VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK, VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK, VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK, VK_FORMAT_EAC_R11_UNORM_BLOCK, VK_FORMAT_EAC_R11_SNORM_BLOCK, VK_FORMAT_EAC_R11G11_UNORM_BLOCK, VK_FORMAT_EAC_R11G11_SNORM_BLOCK, VK_FORMAT_ASTC_4x4_UNORM_BLOCK, VK_FORMAT_ASTC_4x4_SRGB_BLOCK, VK_FORMAT_ASTC_5x4_UNORM_BLOCK, VK_FORMAT_ASTC_5x4_SRGB_BLOCK, VK_FORMAT_ASTC_5x5_UNORM_BLOCK, VK_FORMAT_ASTC_5x5_SRGB_BLOCK, VK_FORMAT_ASTC_6x5_UNORM_BLOCK, VK_FORMAT_ASTC_6x5_SRGB_BLOCK, VK_FORMAT_ASTC_6x6_UNORM_BLOCK, VK_FORMAT_ASTC_6x6_SRGB_BLOCK, VK_FORMAT_ASTC_8x5_UNORM_BLOCK, VK_FORMAT_ASTC_8x5_SRGB_BLOCK, VK_FORMAT_ASTC_8x6_UNORM_BLOCK, VK_FORMAT_ASTC_8x6_SRGB_BLOCK, VK_FORMAT_ASTC_8x8_UNORM_BLOCK, VK_FORMAT_ASTC_8x8_SRGB_BLOCK, VK_FORMAT_ASTC_10x5_UNORM_BLOCK, VK_FORMAT_ASTC_10x5_SRGB_BLOCK, VK_FORMAT_ASTC_10x6_UNORM_BLOCK, VK_FORMAT_ASTC_10x6_SRGB_BLOCK, VK_FORMAT_ASTC_10x8_UNORM_BLOCK, VK_FORMAT_ASTC_10x8_SRGB_BLOCK, VK_FORMAT_ASTC_10x10_UNORM_BLOCK, VK_FORMAT_ASTC_10x10_SRGB_BLOCK, VK_FORMAT_ASTC_12x10_UNORM_BLOCK, VK_FORMAT_ASTC_12x10_SRGB_BLOCK, VK_FORMAT_ASTC_12x12_UNORM_BLOCK, VK_FORMAT_ASTC_12x12_SRGB_BLOCK, VK_FORMAT_G8B8G8R8_422_UNORM, VK_FORMAT_B8G8R8G8_422_UNORM, VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM, VK_FORMAT_G8_B8R8_2PLANE_420_UNORM, VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM, VK_FORMAT_G8_B8R8_2PLANE_422_UNORM, VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM, VK_FORMAT_R10X6_UNORM_PACK16, VK_FORMAT_R10X6G10X6_UNORM_2PACK16, VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16, VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16, VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16, VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16, VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16, VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16, VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16, VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16, VK_FORMAT_R12X4_UNORM_PACK16, VK_FORMAT_R12X4G12X4_UNORM_2PACK16, VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16, VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16, VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16, VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16, VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16, VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16, VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16, VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16, VK_FORMAT_G16B16G16R16_422_UNORM, VK_FORMAT_B16G16R16G16_422_UNORM, VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM, VK_FORMAT_G16_B16R16_2PLANE_420_UNORM, VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM, VK_FORMAT_G16_B16R16_2PLANE_422_UNORM, VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkFormat>> ExtendedVkFormatEnums = {
        { &DeviceExtensions::vk_ext_texture_compression_astc_hdr, { VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK, VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK, VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK, VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK, VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK, VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK, VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK, VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK, VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK, VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK, VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK, VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK, VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK, VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK } },
        { &DeviceExtensions::vk_ext_ycbcr_2plane_444_formats, { VK_FORMAT_G8_B8R8_2PLANE_444_UNORM, VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16, VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16, VK_FORMAT_G16_B16R16_2PLANE_444_UNORM } },
        { &DeviceExtensions::vk_ext_4444_formats, { VK_FORMAT_A4R4G4B4_UNORM_PACK16, VK_FORMAT_A4B4G4R4_UNORM_PACK16 } },
    };
    std::vector<VkFormat> values(CoreVkFormatEnums.cbegin(), CoreVkFormatEnums.cend());
    std::set<VkFormat> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkFormatEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkImageTiling> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkImageTilingEnums = {VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_TILING_LINEAR};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkImageTiling>> ExtendedVkImageTilingEnums = {
        { &DeviceExtensions::vk_ext_image_drm_format_modifier, { VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT } },
    };
    std::vector<VkImageTiling> values(CoreVkImageTilingEnums.cbegin(), CoreVkImageTilingEnums.cend());
    std::set<VkImageTiling> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkImageTilingEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkImageType> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkImageTypeEnums = {VK_IMAGE_TYPE_1D, VK_IMAGE_TYPE_2D, VK_IMAGE_TYPE_3D};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkImageType>> ExtendedVkImageTypeEnums = {
    };
    std::vector<VkImageType> values(CoreVkImageTypeEnums.cbegin(), CoreVkImageTypeEnums.cend());
    std::set<VkImageType> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkImageTypeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkQueryType> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkQueryTypeEnums = {VK_QUERY_TYPE_OCCLUSION, VK_QUERY_TYPE_PIPELINE_STATISTICS, VK_QUERY_TYPE_TIMESTAMP};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkQueryType>> ExtendedVkQueryTypeEnums = {
        { &DeviceExtensions::vk_khr_performance_query, { VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR } },
    };
    std::vector<VkQueryType> values(CoreVkQueryTypeEnums.cbegin(), CoreVkQueryTypeEnums.cend());
    std::set<VkQueryType> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkQueryTypeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkSharingMode> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkSharingModeEnums = {VK_SHARING_MODE_EXCLUSIVE, VK_SHARING_MODE_CONCURRENT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkSharingMode>> ExtendedVkSharingModeEnums = {
    };
    std::vector<VkSharingMode> values(CoreVkSharingModeEnums.cbegin(), CoreVkSharingModeEnums.cend());
    std::set<VkSharingMode> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkSharingModeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkComponentSwizzle> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkComponentSwizzleEnums = {VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_ZERO, VK_COMPONENT_SWIZZLE_ONE, VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G, VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_A};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkComponentSwizzle>> ExtendedVkComponentSwizzleEnums = {
    };
    std::vector<VkComponentSwizzle> values(CoreVkComponentSwizzleEnums.cbegin(), CoreVkComponentSwizzleEnums.cend());
    std::set<VkComponentSwizzle> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkComponentSwizzleEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkImageViewType> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkImageViewTypeEnums = {VK_IMAGE_VIEW_TYPE_1D, VK_IMAGE_VIEW_TYPE_2D, VK_IMAGE_VIEW_TYPE_3D, VK_IMAGE_VIEW_TYPE_CUBE, VK_IMAGE_VIEW_TYPE_1D_ARRAY, VK_IMAGE_VIEW_TYPE_2D_ARRAY, VK_IMAGE_VIEW_TYPE_CUBE_ARRAY};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkImageViewType>> ExtendedVkImageViewTypeEnums = {
    };
    std::vector<VkImageViewType> values(CoreVkImageViewTypeEnums.cbegin(), CoreVkImageViewTypeEnums.cend());
    std::set<VkImageViewType> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkImageViewTypeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkBlendFactor> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkBlendFactorEnums = {VK_BLEND_FACTOR_ZERO, VK_BLEND_FACTOR_ONE, VK_BLEND_FACTOR_SRC_COLOR, VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR, VK_BLEND_FACTOR_DST_COLOR, VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR, VK_BLEND_FACTOR_SRC_ALPHA, VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA, VK_BLEND_FACTOR_DST_ALPHA, VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA, VK_BLEND_FACTOR_CONSTANT_COLOR, VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR, VK_BLEND_FACTOR_CONSTANT_ALPHA, VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA, VK_BLEND_FACTOR_SRC_ALPHA_SATURATE, VK_BLEND_FACTOR_SRC1_COLOR, VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR, VK_BLEND_FACTOR_SRC1_ALPHA, VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkBlendFactor>> ExtendedVkBlendFactorEnums = {
    };
    std::vector<VkBlendFactor> values(CoreVkBlendFactorEnums.cbegin(), CoreVkBlendFactorEnums.cend());
    std::set<VkBlendFactor> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkBlendFactorEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkBlendOp> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkBlendOpEnums = {VK_BLEND_OP_ADD, VK_BLEND_OP_SUBTRACT, VK_BLEND_OP_REVERSE_SUBTRACT, VK_BLEND_OP_MIN, VK_BLEND_OP_MAX};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkBlendOp>> ExtendedVkBlendOpEnums = {
        { &DeviceExtensions::vk_ext_blend_operation_advanced, { VK_BLEND_OP_ZERO_EXT, VK_BLEND_OP_SRC_EXT, VK_BLEND_OP_DST_EXT, VK_BLEND_OP_SRC_OVER_EXT, VK_BLEND_OP_DST_OVER_EXT, VK_BLEND_OP_SRC_IN_EXT, VK_BLEND_OP_DST_IN_EXT, VK_BLEND_OP_SRC_OUT_EXT, VK_BLEND_OP_DST_OUT_EXT, VK_BLEND_OP_SRC_ATOP_EXT, VK_BLEND_OP_DST_ATOP_EXT, VK_BLEND_OP_XOR_EXT, VK_BLEND_OP_MULTIPLY_EXT, VK_BLEND_OP_SCREEN_EXT, VK_BLEND_OP_OVERLAY_EXT, VK_BLEND_OP_DARKEN_EXT, VK_BLEND_OP_LIGHTEN_EXT, VK_BLEND_OP_COLORDODGE_EXT, VK_BLEND_OP_COLORBURN_EXT, VK_BLEND_OP_HARDLIGHT_EXT, VK_BLEND_OP_SOFTLIGHT_EXT, VK_BLEND_OP_DIFFERENCE_EXT, VK_BLEND_OP_EXCLUSION_EXT, VK_BLEND_OP_INVERT_EXT, VK_BLEND_OP_INVERT_RGB_EXT, VK_BLEND_OP_LINEARDODGE_EXT, VK_BLEND_OP_LINEARBURN_EXT, VK_BLEND_OP_VIVIDLIGHT_EXT, VK_BLEND_OP_LINEARLIGHT_EXT, VK_BLEND_OP_PINLIGHT_EXT, VK_BLEND_OP_HARDMIX_EXT, VK_BLEND_OP_HSL_HUE_EXT, VK_BLEND_OP_HSL_SATURATION_EXT, VK_BLEND_OP_HSL_COLOR_EXT, VK_BLEND_OP_HSL_LUMINOSITY_EXT, VK_BLEND_OP_PLUS_EXT, VK_BLEND_OP_PLUS_CLAMPED_EXT, VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT, VK_BLEND_OP_PLUS_DARKER_EXT, VK_BLEND_OP_MINUS_EXT, VK_BLEND_OP_MINUS_CLAMPED_EXT, VK_BLEND_OP_CONTRAST_EXT, VK_BLEND_OP_INVERT_OVG_EXT, VK_BLEND_OP_RED_EXT, VK_BLEND_OP_GREEN_EXT, VK_BLEND_OP_BLUE_EXT } },
    };
    std::vector<VkBlendOp> values(CoreVkBlendOpEnums.cbegin(), CoreVkBlendOpEnums.cend());
    std::set<VkBlendOp> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkBlendOpEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkCompareOp> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkCompareOpEnums = {VK_COMPARE_OP_NEVER, VK_COMPARE_OP_LESS, VK_COMPARE_OP_EQUAL, VK_COMPARE_OP_LESS_OR_EQUAL, VK_COMPARE_OP_GREATER, VK_COMPARE_OP_NOT_EQUAL, VK_COMPARE_OP_GREATER_OR_EQUAL, VK_COMPARE_OP_ALWAYS};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkCompareOp>> ExtendedVkCompareOpEnums = {
    };
    std::vector<VkCompareOp> values(CoreVkCompareOpEnums.cbegin(), CoreVkCompareOpEnums.cend());
    std::set<VkCompareOp> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkCompareOpEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkDynamicState> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkDynamicStateEnums = {VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR, VK_DYNAMIC_STATE_LINE_WIDTH, VK_DYNAMIC_STATE_DEPTH_BIAS, VK_DYNAMIC_STATE_BLEND_CONSTANTS, VK_DYNAMIC_STATE_DEPTH_BOUNDS, VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK, VK_DYNAMIC_STATE_STENCIL_WRITE_MASK, VK_DYNAMIC_STATE_STENCIL_REFERENCE};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkDynamicState>> ExtendedVkDynamicStateEnums = {
        { &DeviceExtensions::vk_khr_fragment_shading_rate, { VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR } },
        { &DeviceExtensions::vk_ext_discard_rectangles, { VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT, VK_DYNAMIC_STATE_DISCARD_RECTANGLE_ENABLE_EXT, VK_DYNAMIC_STATE_DISCARD_RECTANGLE_MODE_EXT } },
        { &DeviceExtensions::vk_ext_sample_locations, { VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT } },
        { &DeviceExtensions::vk_ext_line_rasterization, { VK_DYNAMIC_STATE_LINE_STIPPLE_EXT } },
        { &DeviceExtensions::vk_ext_extended_dynamic_state, { VK_DYNAMIC_STATE_CULL_MODE, VK_DYNAMIC_STATE_FRONT_FACE, VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY, VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT, VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT, VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE, VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE, VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE, VK_DYNAMIC_STATE_DEPTH_COMPARE_OP, VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE, VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE, VK_DYNAMIC_STATE_STENCIL_OP } },
        { &DeviceExtensions::vk_ext_vertex_input_dynamic_state, { VK_DYNAMIC_STATE_VERTEX_INPUT_EXT } },
        { &DeviceExtensions::vk_ext_extended_dynamic_state2, { VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE, VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE, VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE, VK_DYNAMIC_STATE_PATCH_CONTROL_POINTS_EXT, VK_DYNAMIC_STATE_LOGIC_OP_EXT } },
        { &DeviceExtensions::vk_ext_color_write_enable, { VK_DYNAMIC_STATE_COLOR_WRITE_ENABLE_EXT } },
    };
    std::vector<VkDynamicState> values(CoreVkDynamicStateEnums.cbegin(), CoreVkDynamicStateEnums.cend());
    std::set<VkDynamicState> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkDynamicStateEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkFrontFace> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkFrontFaceEnums = {VK_FRONT_FACE_COUNTER_CLOCKWISE, VK_FRONT_FACE_CLOCKWISE};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkFrontFace>> ExtendedVkFrontFaceEnums = {
    };
    std::vector<VkFrontFace> values(CoreVkFrontFaceEnums.cbegin(), CoreVkFrontFaceEnums.cend());
    std::set<VkFrontFace> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkFrontFaceEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkVertexInputRate> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkVertexInputRateEnums = {VK_VERTEX_INPUT_RATE_VERTEX, VK_VERTEX_INPUT_RATE_INSTANCE};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkVertexInputRate>> ExtendedVkVertexInputRateEnums = {
    };
    std::vector<VkVertexInputRate> values(CoreVkVertexInputRateEnums.cbegin(), CoreVkVertexInputRateEnums.cend());
    std::set<VkVertexInputRate> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkVertexInputRateEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkPrimitiveTopology> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkPrimitiveTopologyEnums = {VK_PRIMITIVE_TOPOLOGY_POINT_LIST, VK_PRIMITIVE_TOPOLOGY_LINE_LIST, VK_PRIMITIVE_TOPOLOGY_LINE_STRIP, VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST, VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP, VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN, VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY, VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY, VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY, VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY, VK_PRIMITIVE_TOPOLOGY_PATCH_LIST};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkPrimitiveTopology>> ExtendedVkPrimitiveTopologyEnums = {
    };
    std::vector<VkPrimitiveTopology> values(CoreVkPrimitiveTopologyEnums.cbegin(), CoreVkPrimitiveTopologyEnums.cend());
    std::set<VkPrimitiveTopology> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkPrimitiveTopologyEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkPolygonMode> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkPolygonModeEnums = {VK_POLYGON_MODE_FILL, VK_POLYGON_MODE_LINE, VK_POLYGON_MODE_POINT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkPolygonMode>> ExtendedVkPolygonModeEnums = {
    };
    std::vector<VkPolygonMode> values(CoreVkPolygonModeEnums.cbegin(), CoreVkPolygonModeEnums.cend());
    std::set<VkPolygonMode> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkPolygonModeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkStencilOp> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkStencilOpEnums = {VK_STENCIL_OP_KEEP, VK_STENCIL_OP_ZERO, VK_STENCIL_OP_REPLACE, VK_STENCIL_OP_INCREMENT_AND_CLAMP, VK_STENCIL_OP_DECREMENT_AND_CLAMP, VK_STENCIL_OP_INVERT, VK_STENCIL_OP_INCREMENT_AND_WRAP, VK_STENCIL_OP_DECREMENT_AND_WRAP};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkStencilOp>> ExtendedVkStencilOpEnums = {
    };
    std::vector<VkStencilOp> values(CoreVkStencilOpEnums.cbegin(), CoreVkStencilOpEnums.cend());
    std::set<VkStencilOp> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkStencilOpEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkLogicOp> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkLogicOpEnums = {VK_LOGIC_OP_CLEAR, VK_LOGIC_OP_AND, VK_LOGIC_OP_AND_REVERSE, VK_LOGIC_OP_COPY, VK_LOGIC_OP_AND_INVERTED, VK_LOGIC_OP_NO_OP, VK_LOGIC_OP_XOR, VK_LOGIC_OP_OR, VK_LOGIC_OP_NOR, VK_LOGIC_OP_EQUIVALENT, VK_LOGIC_OP_INVERT, VK_LOGIC_OP_OR_REVERSE, VK_LOGIC_OP_COPY_INVERTED, VK_LOGIC_OP_OR_INVERTED, VK_LOGIC_OP_NAND, VK_LOGIC_OP_SET};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkLogicOp>> ExtendedVkLogicOpEnums = {
    };
    std::vector<VkLogicOp> values(CoreVkLogicOpEnums.cbegin(), CoreVkLogicOpEnums.cend());
    std::set<VkLogicOp> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkLogicOpEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkBorderColor> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkBorderColorEnums = {VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK, VK_BORDER_COLOR_INT_TRANSPARENT_BLACK, VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK, VK_BORDER_COLOR_INT_OPAQUE_BLACK, VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE, VK_BORDER_COLOR_INT_OPAQUE_WHITE};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkBorderColor>> ExtendedVkBorderColorEnums = {
        { &DeviceExtensions::vk_ext_custom_border_color, { VK_BORDER_COLOR_FLOAT_CUSTOM_EXT, VK_BORDER_COLOR_INT_CUSTOM_EXT } },
    };
    std::vector<VkBorderColor> values(CoreVkBorderColorEnums.cbegin(), CoreVkBorderColorEnums.cend());
    std::set<VkBorderColor> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkBorderColorEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkFilter> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkFilterEnums = {VK_FILTER_NEAREST, VK_FILTER_LINEAR};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkFilter>> ExtendedVkFilterEnums = {
        { &DeviceExtensions::vk_ext_filter_cubic, { VK_FILTER_CUBIC_EXT } },
    };
    std::vector<VkFilter> values(CoreVkFilterEnums.cbegin(), CoreVkFilterEnums.cend());
    std::set<VkFilter> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkFilterEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkSamplerAddressMode> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkSamplerAddressModeEnums = {VK_SAMPLER_ADDRESS_MODE_REPEAT, VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT, VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE, VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER, VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkSamplerAddressMode>> ExtendedVkSamplerAddressModeEnums = {
    };
    std::vector<VkSamplerAddressMode> values(CoreVkSamplerAddressModeEnums.cbegin(), CoreVkSamplerAddressModeEnums.cend());
    std::set<VkSamplerAddressMode> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkSamplerAddressModeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkSamplerMipmapMode> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkSamplerMipmapModeEnums = {VK_SAMPLER_MIPMAP_MODE_NEAREST, VK_SAMPLER_MIPMAP_MODE_LINEAR};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkSamplerMipmapMode>> ExtendedVkSamplerMipmapModeEnums = {
    };
    std::vector<VkSamplerMipmapMode> values(CoreVkSamplerMipmapModeEnums.cbegin(), CoreVkSamplerMipmapModeEnums.cend());
    std::set<VkSamplerMipmapMode> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkSamplerMipmapModeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkDescriptorType> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkDescriptorTypeEnums = {VK_DESCRIPTOR_TYPE_SAMPLER, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkDescriptorType>> ExtendedVkDescriptorTypeEnums = {
    };
    std::vector<VkDescriptorType> values(CoreVkDescriptorTypeEnums.cbegin(), CoreVkDescriptorTypeEnums.cend());
    std::set<VkDescriptorType> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkDescriptorTypeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkAttachmentLoadOp> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkAttachmentLoadOpEnums = {VK_ATTACHMENT_LOAD_OP_LOAD, VK_ATTACHMENT_LOAD_OP_CLEAR, VK_ATTACHMENT_LOAD_OP_DONT_CARE};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkAttachmentLoadOp>> ExtendedVkAttachmentLoadOpEnums = {
    };
    std::vector<VkAttachmentLoadOp> values(CoreVkAttachmentLoadOpEnums.cbegin(), CoreVkAttachmentLoadOpEnums.cend());
    std::set<VkAttachmentLoadOp> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkAttachmentLoadOpEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkAttachmentStoreOp> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkAttachmentStoreOpEnums = {VK_ATTACHMENT_STORE_OP_STORE, VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_ATTACHMENT_STORE_OP_NONE};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkAttachmentStoreOp>> ExtendedVkAttachmentStoreOpEnums = {
    };
    std::vector<VkAttachmentStoreOp> values(CoreVkAttachmentStoreOpEnums.cbegin(), CoreVkAttachmentStoreOpEnums.cend());
    std::set<VkAttachmentStoreOp> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkAttachmentStoreOpEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkPipelineBindPoint> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkPipelineBindPointEnums = {VK_PIPELINE_BIND_POINT_GRAPHICS, VK_PIPELINE_BIND_POINT_COMPUTE};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkPipelineBindPoint>> ExtendedVkPipelineBindPointEnums = {
    };
    std::vector<VkPipelineBindPoint> values(CoreVkPipelineBindPointEnums.cbegin(), CoreVkPipelineBindPointEnums.cend());
    std::set<VkPipelineBindPoint> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkPipelineBindPointEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkCommandBufferLevel> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkCommandBufferLevelEnums = {VK_COMMAND_BUFFER_LEVEL_PRIMARY, VK_COMMAND_BUFFER_LEVEL_SECONDARY};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkCommandBufferLevel>> ExtendedVkCommandBufferLevelEnums = {
    };
    std::vector<VkCommandBufferLevel> values(CoreVkCommandBufferLevelEnums.cbegin(), CoreVkCommandBufferLevelEnums.cend());
    std::set<VkCommandBufferLevel> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkCommandBufferLevelEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkIndexType> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkIndexTypeEnums = {VK_INDEX_TYPE_UINT16, VK_INDEX_TYPE_UINT32};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkIndexType>> ExtendedVkIndexTypeEnums = {
        { &DeviceExtensions::vk_ext_index_type_uint8, { VK_INDEX_TYPE_UINT8_EXT } },
    };
    std::vector<VkIndexType> values(CoreVkIndexTypeEnums.cbegin(), CoreVkIndexTypeEnums.cend());
    std::set<VkIndexType> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkIndexTypeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkSubpassContents> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkSubpassContentsEnums = {VK_SUBPASS_CONTENTS_INLINE, VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkSubpassContents>> ExtendedVkSubpassContentsEnums = {
    };
    std::vector<VkSubpassContents> values(CoreVkSubpassContentsEnums.cbegin(), CoreVkSubpassContentsEnums.cend());
    std::set<VkSubpassContents> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkSubpassContentsEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkTessellationDomainOrigin> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkTessellationDomainOriginEnums = {VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT, VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkTessellationDomainOrigin>> ExtendedVkTessellationDomainOriginEnums = {
    };
    std::vector<VkTessellationDomainOrigin> values(CoreVkTessellationDomainOriginEnums.cbegin(), CoreVkTessellationDomainOriginEnums.cend());
    std::set<VkTessellationDomainOrigin> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkTessellationDomainOriginEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkSamplerYcbcrModelConversion> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkSamplerYcbcrModelConversionEnums = {VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY, VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY, VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709, VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601, VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkSamplerYcbcrModelConversion>> ExtendedVkSamplerYcbcrModelConversionEnums = {
    };
    std::vector<VkSamplerYcbcrModelConversion> values(CoreVkSamplerYcbcrModelConversionEnums.cbegin(), CoreVkSamplerYcbcrModelConversionEnums.cend());
    std::set<VkSamplerYcbcrModelConversion> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkSamplerYcbcrModelConversionEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkSamplerYcbcrRange> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkSamplerYcbcrRangeEnums = {VK_SAMPLER_YCBCR_RANGE_ITU_FULL, VK_SAMPLER_YCBCR_RANGE_ITU_NARROW};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkSamplerYcbcrRange>> ExtendedVkSamplerYcbcrRangeEnums = {
    };
    std::vector<VkSamplerYcbcrRange> values(CoreVkSamplerYcbcrRangeEnums.cbegin(), CoreVkSamplerYcbcrRangeEnums.cend());
    std::set<VkSamplerYcbcrRange> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkSamplerYcbcrRangeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkChromaLocation> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkChromaLocationEnums = {VK_CHROMA_LOCATION_COSITED_EVEN, VK_CHROMA_LOCATION_MIDPOINT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkChromaLocation>> ExtendedVkChromaLocationEnums = {
    };
    std::vector<VkChromaLocation> values(CoreVkChromaLocationEnums.cbegin(), CoreVkChromaLocationEnums.cend());
    std::set<VkChromaLocation> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkChromaLocationEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkSamplerReductionMode> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkSamplerReductionModeEnums = {VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE, VK_SAMPLER_REDUCTION_MODE_MIN, VK_SAMPLER_REDUCTION_MODE_MAX};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkSamplerReductionMode>> ExtendedVkSamplerReductionModeEnums = {
    };
    std::vector<VkSamplerReductionMode> values(CoreVkSamplerReductionModeEnums.cbegin(), CoreVkSamplerReductionModeEnums.cend());
    std::set<VkSamplerReductionMode> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkSamplerReductionModeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkSemaphoreType> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkSemaphoreTypeEnums = {VK_SEMAPHORE_TYPE_BINARY, VK_SEMAPHORE_TYPE_TIMELINE};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkSemaphoreType>> ExtendedVkSemaphoreTypeEnums = {
    };
    std::vector<VkSemaphoreType> values(CoreVkSemaphoreTypeEnums.cbegin(), CoreVkSemaphoreTypeEnums.cend());
    std::set<VkSemaphoreType> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkSemaphoreTypeEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkFaultQueryBehavior> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkFaultQueryBehaviorEnums = {VK_FAULT_QUERY_BEHAVIOR_GET_AND_CLEAR_ALL_FAULTS};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkFaultQueryBehavior>> ExtendedVkFaultQueryBehaviorEnums = {
    };
    std::vector<VkFaultQueryBehavior> values(CoreVkFaultQueryBehaviorEnums.cbegin(), CoreVkFaultQueryBehaviorEnums.cend());
    std::set<VkFaultQueryBehavior> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkFaultQueryBehaviorEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkPipelineMatchControl> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkPipelineMatchControlEnums = {VK_PIPELINE_MATCH_CONTROL_APPLICATION_UUID_EXACT_MATCH};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkPipelineMatchControl>> ExtendedVkPipelineMatchControlEnums = {
    };
    std::vector<VkPipelineMatchControl> values(CoreVkPipelineMatchControlEnums.cbegin(), CoreVkPipelineMatchControlEnums.cend());
    std::set<VkPipelineMatchControl> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkPipelineMatchControlEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkPipelineCacheValidationVersion> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkPipelineCacheValidationVersionEnums = {VK_PIPELINE_CACHE_VALIDATION_VERSION_SAFETY_CRITICAL_ONE};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkPipelineCacheValidationVersion>> ExtendedVkPipelineCacheValidationVersionEnums = {
    };
    std::vector<VkPipelineCacheValidationVersion> values(CoreVkPipelineCacheValidationVersionEnums.cbegin(), CoreVkPipelineCacheValidationVersionEnums.cend());
    std::set<VkPipelineCacheValidationVersion> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkPipelineCacheValidationVersionEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkPresentModeKHR> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkPresentModeKHREnums = {VK_PRESENT_MODE_IMMEDIATE_KHR, VK_PRESENT_MODE_MAILBOX_KHR, VK_PRESENT_MODE_FIFO_KHR, VK_PRESENT_MODE_FIFO_RELAXED_KHR};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkPresentModeKHR>> ExtendedVkPresentModeKHREnums = {
        { &DeviceExtensions::vk_khr_shared_presentable_image, { VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR, VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR } },
    };
    std::vector<VkPresentModeKHR> values(CoreVkPresentModeKHREnums.cbegin(), CoreVkPresentModeKHREnums.cend());
    std::set<VkPresentModeKHR> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkPresentModeKHREnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkColorSpaceKHR> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkColorSpaceKHREnums = {VK_COLOR_SPACE_SRGB_NONLINEAR_KHR};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkColorSpaceKHR>> ExtendedVkColorSpaceKHREnums = {
        { &DeviceExtensions::vk_ext_swapchain_colorspace, { VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT, VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT, VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT, VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT, VK_COLOR_SPACE_BT709_LINEAR_EXT, VK_COLOR_SPACE_BT709_NONLINEAR_EXT, VK_COLOR_SPACE_BT2020_LINEAR_EXT, VK_COLOR_SPACE_HDR10_ST2084_EXT, VK_COLOR_SPACE_DOLBYVISION_EXT, VK_COLOR_SPACE_HDR10_HLG_EXT, VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT, VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT, VK_COLOR_SPACE_PASS_THROUGH_EXT, VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT } },
    };
    std::vector<VkColorSpaceKHR> values(CoreVkColorSpaceKHREnums.cbegin(), CoreVkColorSpaceKHREnums.cend());
    std::set<VkColorSpaceKHR> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkColorSpaceKHREnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkFragmentShadingRateCombinerOpKHR> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkFragmentShadingRateCombinerOpKHREnums = {VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR, VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR, VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR, VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR, VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkFragmentShadingRateCombinerOpKHR>> ExtendedVkFragmentShadingRateCombinerOpKHREnums = {
    };
    std::vector<VkFragmentShadingRateCombinerOpKHR> values(CoreVkFragmentShadingRateCombinerOpKHREnums.cbegin(), CoreVkFragmentShadingRateCombinerOpKHREnums.cend());
    std::set<VkFragmentShadingRateCombinerOpKHR> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkFragmentShadingRateCombinerOpKHREnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkDisplayPowerStateEXT> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkDisplayPowerStateEXTEnums = {VK_DISPLAY_POWER_STATE_OFF_EXT, VK_DISPLAY_POWER_STATE_SUSPEND_EXT, VK_DISPLAY_POWER_STATE_ON_EXT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkDisplayPowerStateEXT>> ExtendedVkDisplayPowerStateEXTEnums = {
    };
    std::vector<VkDisplayPowerStateEXT> values(CoreVkDisplayPowerStateEXTEnums.cbegin(), CoreVkDisplayPowerStateEXTEnums.cend());
    std::set<VkDisplayPowerStateEXT> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkDisplayPowerStateEXTEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkDeviceEventTypeEXT> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkDeviceEventTypeEXTEnums = {VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkDeviceEventTypeEXT>> ExtendedVkDeviceEventTypeEXTEnums = {
    };
    std::vector<VkDeviceEventTypeEXT> values(CoreVkDeviceEventTypeEXTEnums.cbegin(), CoreVkDeviceEventTypeEXTEnums.cend());
    std::set<VkDeviceEventTypeEXT> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkDeviceEventTypeEXTEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkDisplayEventTypeEXT> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkDisplayEventTypeEXTEnums = {VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkDisplayEventTypeEXT>> ExtendedVkDisplayEventTypeEXTEnums = {
    };
    std::vector<VkDisplayEventTypeEXT> values(CoreVkDisplayEventTypeEXTEnums.cbegin(), CoreVkDisplayEventTypeEXTEnums.cend());
    std::set<VkDisplayEventTypeEXT> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkDisplayEventTypeEXTEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkDiscardRectangleModeEXT> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkDiscardRectangleModeEXTEnums = {VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT, VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkDiscardRectangleModeEXT>> ExtendedVkDiscardRectangleModeEXTEnums = {
    };
    std::vector<VkDiscardRectangleModeEXT> values(CoreVkDiscardRectangleModeEXTEnums.cbegin(), CoreVkDiscardRectangleModeEXTEnums.cend());
    std::set<VkDiscardRectangleModeEXT> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkDiscardRectangleModeEXTEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkConservativeRasterizationModeEXT> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkConservativeRasterizationModeEXTEnums = {VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT, VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT, VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkConservativeRasterizationModeEXT>> ExtendedVkConservativeRasterizationModeEXTEnums = {
    };
    std::vector<VkConservativeRasterizationModeEXT> values(CoreVkConservativeRasterizationModeEXTEnums.cbegin(), CoreVkConservativeRasterizationModeEXTEnums.cend());
    std::set<VkConservativeRasterizationModeEXT> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkConservativeRasterizationModeEXTEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkBlendOverlapEXT> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkBlendOverlapEXTEnums = {VK_BLEND_OVERLAP_UNCORRELATED_EXT, VK_BLEND_OVERLAP_DISJOINT_EXT, VK_BLEND_OVERLAP_CONJOINT_EXT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkBlendOverlapEXT>> ExtendedVkBlendOverlapEXTEnums = {
    };
    std::vector<VkBlendOverlapEXT> values(CoreVkBlendOverlapEXTEnums.cbegin(), CoreVkBlendOverlapEXTEnums.cend());
    std::set<VkBlendOverlapEXT> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkBlendOverlapEXTEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkQueueGlobalPriorityKHR> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkQueueGlobalPriorityKHREnums = {VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR, VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR, VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR, VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkQueueGlobalPriorityKHR>> ExtendedVkQueueGlobalPriorityKHREnums = {
    };
    std::vector<VkQueueGlobalPriorityKHR> values(CoreVkQueueGlobalPriorityKHREnums.cbegin(), CoreVkQueueGlobalPriorityKHREnums.cend());
    std::set<VkQueueGlobalPriorityKHR> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkQueueGlobalPriorityKHREnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkTimeDomainEXT> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkTimeDomainEXTEnums = {VK_TIME_DOMAIN_DEVICE_EXT, VK_TIME_DOMAIN_CLOCK_MONOTONIC_EXT, VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_EXT, VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_EXT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkTimeDomainEXT>> ExtendedVkTimeDomainEXTEnums = {
    };
    std::vector<VkTimeDomainEXT> values(CoreVkTimeDomainEXTEnums.cbegin(), CoreVkTimeDomainEXTEnums.cend());
    std::set<VkTimeDomainEXT> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkTimeDomainEXTEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkValidationFeatureEnableEXT> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkValidationFeatureEnableEXTEnums = {VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT, VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT, VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT, VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT, VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkValidationFeatureEnableEXT>> ExtendedVkValidationFeatureEnableEXTEnums = {
    };
    std::vector<VkValidationFeatureEnableEXT> values(CoreVkValidationFeatureEnableEXTEnums.cbegin(), CoreVkValidationFeatureEnableEXTEnums.cend());
    std::set<VkValidationFeatureEnableEXT> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkValidationFeatureEnableEXTEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkValidationFeatureDisableEXT> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkValidationFeatureDisableEXTEnums = {VK_VALIDATION_FEATURE_DISABLE_ALL_EXT, VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT, VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT, VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT, VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT, VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT, VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT, VK_VALIDATION_FEATURE_DISABLE_SHADER_VALIDATION_CACHE_EXT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkValidationFeatureDisableEXT>> ExtendedVkValidationFeatureDisableEXTEnums = {
    };
    std::vector<VkValidationFeatureDisableEXT> values(CoreVkValidationFeatureDisableEXTEnums.cbegin(), CoreVkValidationFeatureDisableEXTEnums.cend());
    std::set<VkValidationFeatureDisableEXT> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkValidationFeatureDisableEXTEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkLineRasterizationModeEXT> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkLineRasterizationModeEXTEnums = {VK_LINE_RASTERIZATION_MODE_DEFAULT_EXT, VK_LINE_RASTERIZATION_MODE_RECTANGULAR_EXT, VK_LINE_RASTERIZATION_MODE_BRESENHAM_EXT, VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_EXT};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkLineRasterizationModeEXT>> ExtendedVkLineRasterizationModeEXTEnums = {
    };
    std::vector<VkLineRasterizationModeEXT> values(CoreVkLineRasterizationModeEXTEnums.cbegin(), CoreVkLineRasterizationModeEXTEnums.cend());
    std::set<VkLineRasterizationModeEXT> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkLineRasterizationModeEXTEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

#ifdef VK_USE_PLATFORM_SCI
template<>
std::vector<VkSciSyncClientTypeNV> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkSciSyncClientTypeNVEnums = {VK_SCI_SYNC_CLIENT_TYPE_SIGNALER_NV, VK_SCI_SYNC_CLIENT_TYPE_WAITER_NV, VK_SCI_SYNC_CLIENT_TYPE_SIGNALER_WAITER_NV};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkSciSyncClientTypeNV>> ExtendedVkSciSyncClientTypeNVEnums = {
    };
    std::vector<VkSciSyncClientTypeNV> values(CoreVkSciSyncClientTypeNVEnums.cbegin(), CoreVkSciSyncClientTypeNVEnums.cend());
    std::set<VkSciSyncClientTypeNV> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkSciSyncClientTypeNVEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}

template<>
std::vector<VkSciSyncPrimitiveTypeNV> ValidationObject::ValidParamValues() const {
    constexpr std::array CoreVkSciSyncPrimitiveTypeNVEnums = {VK_SCI_SYNC_PRIMITIVE_TYPE_FENCE_NV, VK_SCI_SYNC_PRIMITIVE_TYPE_SEMAPHORE_NV};
    static const vvl::unordered_map<const ExtEnabled DeviceExtensions::*, std::vector<VkSciSyncPrimitiveTypeNV>> ExtendedVkSciSyncPrimitiveTypeNVEnums = {
    };
    std::vector<VkSciSyncPrimitiveTypeNV> values(CoreVkSciSyncPrimitiveTypeNVEnums.cbegin(), CoreVkSciSyncPrimitiveTypeNVEnums.cend());
    std::set<VkSciSyncPrimitiveTypeNV> unique_exts;
    for (const auto& [extension, enums]: ExtendedVkSciSyncPrimitiveTypeNVEnums) {
        if (IsExtEnabled(device_extensions.*extension)) {
            unique_exts.insert(enums.cbegin(), enums.cend());
        }
    }
    std::copy(unique_exts.cbegin(), unique_exts.cend(), std::back_inserter(values));
    return values;
}
#endif  // VK_USE_PLATFORM_SCI

// clang-format on

// NOLINTEND
