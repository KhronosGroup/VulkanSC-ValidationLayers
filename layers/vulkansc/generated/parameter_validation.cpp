/* *** THIS FILE IS GENERATED - DO NOT EDIT! ***
 * See parameter_validation_generator.py for modifications
 *
 * Copyright (c) 2015-2023 The Khronos Group Inc.
 * Copyright (c) 2015-2023 LunarG, Inc.
 * Copyright (C) 2015-2023 Google Inc.
 * Copyright (c) 2015-2023 Valve Corporation
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


#include "chassis.h"

#include "stateless/stateless_validation.h"
#include "enum_flag_bits.h"

bool StatelessValidation::CheckPromotedApiAgainstVulkanVersion(VkInstance instance, const char *api_name, const uint32_t promoted_version) const {
    bool skip = false;
    if (api_version < promoted_version) {
        skip = LogError(instance,
                        kVUID_PVError_ApiVersionViolation, "Attempted to call %s() with an effective API version of %s"
                        "but this API was not promoted until version %s.", api_name, StringAPIVersion(api_version).c_str(),
                        StringAPIVersion(promoted_version).c_str());
    }
    return skip;
}

bool StatelessValidation::CheckPromotedApiAgainstVulkanVersion(VkPhysicalDevice pdev, const char *api_name, const uint32_t promoted_version) const {
    bool skip = false;
    const auto &target_pdev = physical_device_properties_map.find(pdev);
    if (target_pdev != physical_device_properties_map.end()) {
        auto effective_api_version = std::min(APIVersion(target_pdev->second->apiVersion), api_version);
        if (effective_api_version < promoted_version) {
            skip = LogError(instance,
                            kVUID_PVError_ApiVersionViolation, "Attempted to call %s() with an effective API version of %s, "
                            "which is the minimum of version requested in pApplicationInfo (%s) and supported by this physical device (%s), "
                            "but this API was not promoted until version %s.", api_name, StringAPIVersion(effective_api_version).c_str(),
                            StringAPIVersion(api_version).c_str(), StringAPIVersion(target_pdev->second->apiVersion).c_str(),
                            StringAPIVersion(promoted_version).c_str());
        }
    }
    return skip;
}

bool StatelessValidation::ValidatePnextStructContents(const char *api_name, const ParameterName &parameter_name,
                                                      const VkBaseOutStructure* header, const char *pnext_vuid, bool is_physdev_api, bool is_const_param) const {
    bool skip = false;
    switch(header->sType) {

        // Validation code for VkPhysicalDeviceSubgroupProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES: { // Covers VUID-VkPhysicalDeviceSubgroupProperties-sType-sType
            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES) which was added in VK_API_VERSION_1_1 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceProtectedMemoryFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES: { // Covers VUID-VkPhysicalDeviceProtectedMemoryFeatures-sType-sType
            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES) which was added in VK_API_VERSION_1_1 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                VkPhysicalDeviceProtectedMemoryFeatures *structure = (VkPhysicalDeviceProtectedMemoryFeatures *) header;
                skip |= ValidateBool32("VkPhysicalDeviceProtectedMemoryFeatures", "protectedMemory", structure->protectedMemory);
            }
        } break;

        // Validation code for VkPhysicalDeviceProtectedMemoryProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES: { // Covers VUID-VkPhysicalDeviceProtectedMemoryProperties-sType-sType
            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES) which was added in VK_API_VERSION_1_1 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkProtectedSubmitInfo structure members
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO: { // Covers VUID-VkProtectedSubmitInfo-sType-sType
            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO) which was added in VK_API_VERSION_1_1 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                VkProtectedSubmitInfo *structure = (VkProtectedSubmitInfo *) header;
                skip |= ValidateBool32("VkProtectedSubmitInfo", "protectedSubmit", structure->protectedSubmit);
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderDrawParametersFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES: { // Covers VUID-VkPhysicalDeviceShaderDrawParametersFeatures-sType-sType
            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES) which was added in VK_API_VERSION_1_1 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                VkPhysicalDeviceShaderDrawParametersFeatures *structure = (VkPhysicalDeviceShaderDrawParametersFeatures *) header;
                skip |= ValidateBool32("VkPhysicalDeviceShaderDrawParametersFeatures", "shaderDrawParameters", structure->shaderDrawParameters);
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkan11Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: { // Covers VUID-VkPhysicalDeviceVulkan11Features-sType-sType
            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES) which was added in VK_API_VERSION_1_2 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                VkPhysicalDeviceVulkan11Features *structure = (VkPhysicalDeviceVulkan11Features *) header;
                skip |= ValidateBool32("VkPhysicalDeviceVulkan11Features", "storageBuffer16BitAccess", structure->storageBuffer16BitAccess);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan11Features", "uniformAndStorageBuffer16BitAccess", structure->uniformAndStorageBuffer16BitAccess);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan11Features", "storagePushConstant16", structure->storagePushConstant16);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan11Features", "storageInputOutput16", structure->storageInputOutput16);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan11Features", "multiview", structure->multiview);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan11Features", "multiviewGeometryShader", structure->multiviewGeometryShader);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan11Features", "multiviewTessellationShader", structure->multiviewTessellationShader);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan11Features", "variablePointersStorageBuffer", structure->variablePointersStorageBuffer);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan11Features", "variablePointers", structure->variablePointers);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan11Features", "protectedMemory", structure->protectedMemory);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan11Features", "samplerYcbcrConversion", structure->samplerYcbcrConversion);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan11Features", "shaderDrawParameters", structure->shaderDrawParameters);
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkan11Properties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: { // Covers VUID-VkPhysicalDeviceVulkan11Properties-sType-sType
            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES) which was added in VK_API_VERSION_1_2 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkan12Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: { // Covers VUID-VkPhysicalDeviceVulkan12Features-sType-sType
            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES) which was added in VK_API_VERSION_1_2 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                VkPhysicalDeviceVulkan12Features *structure = (VkPhysicalDeviceVulkan12Features *) header;
                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "samplerMirrorClampToEdge", structure->samplerMirrorClampToEdge);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "drawIndirectCount", structure->drawIndirectCount);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "storageBuffer8BitAccess", structure->storageBuffer8BitAccess);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "uniformAndStorageBuffer8BitAccess", structure->uniformAndStorageBuffer8BitAccess);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "storagePushConstant8", structure->storagePushConstant8);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderBufferInt64Atomics", structure->shaderBufferInt64Atomics);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderSharedInt64Atomics", structure->shaderSharedInt64Atomics);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderFloat16", structure->shaderFloat16);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderInt8", structure->shaderInt8);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "descriptorIndexing", structure->descriptorIndexing);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderInputAttachmentArrayDynamicIndexing", structure->shaderInputAttachmentArrayDynamicIndexing);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderUniformTexelBufferArrayDynamicIndexing", structure->shaderUniformTexelBufferArrayDynamicIndexing);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderStorageTexelBufferArrayDynamicIndexing", structure->shaderStorageTexelBufferArrayDynamicIndexing);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderUniformBufferArrayNonUniformIndexing", structure->shaderUniformBufferArrayNonUniformIndexing);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderSampledImageArrayNonUniformIndexing", structure->shaderSampledImageArrayNonUniformIndexing);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderStorageBufferArrayNonUniformIndexing", structure->shaderStorageBufferArrayNonUniformIndexing);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderStorageImageArrayNonUniformIndexing", structure->shaderStorageImageArrayNonUniformIndexing);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderInputAttachmentArrayNonUniformIndexing", structure->shaderInputAttachmentArrayNonUniformIndexing);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderUniformTexelBufferArrayNonUniformIndexing", structure->shaderUniformTexelBufferArrayNonUniformIndexing);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderStorageTexelBufferArrayNonUniformIndexing", structure->shaderStorageTexelBufferArrayNonUniformIndexing);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "descriptorBindingUniformBufferUpdateAfterBind", structure->descriptorBindingUniformBufferUpdateAfterBind);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "descriptorBindingSampledImageUpdateAfterBind", structure->descriptorBindingSampledImageUpdateAfterBind);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "descriptorBindingStorageImageUpdateAfterBind", structure->descriptorBindingStorageImageUpdateAfterBind);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "descriptorBindingStorageBufferUpdateAfterBind", structure->descriptorBindingStorageBufferUpdateAfterBind);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "descriptorBindingUniformTexelBufferUpdateAfterBind", structure->descriptorBindingUniformTexelBufferUpdateAfterBind);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "descriptorBindingStorageTexelBufferUpdateAfterBind", structure->descriptorBindingStorageTexelBufferUpdateAfterBind);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "descriptorBindingUpdateUnusedWhilePending", structure->descriptorBindingUpdateUnusedWhilePending);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "descriptorBindingPartiallyBound", structure->descriptorBindingPartiallyBound);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "descriptorBindingVariableDescriptorCount", structure->descriptorBindingVariableDescriptorCount);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "runtimeDescriptorArray", structure->runtimeDescriptorArray);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "samplerFilterMinmax", structure->samplerFilterMinmax);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "scalarBlockLayout", structure->scalarBlockLayout);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "imagelessFramebuffer", structure->imagelessFramebuffer);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "uniformBufferStandardLayout", structure->uniformBufferStandardLayout);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderSubgroupExtendedTypes", structure->shaderSubgroupExtendedTypes);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "separateDepthStencilLayouts", structure->separateDepthStencilLayouts);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "hostQueryReset", structure->hostQueryReset);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "timelineSemaphore", structure->timelineSemaphore);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "bufferDeviceAddress", structure->bufferDeviceAddress);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "bufferDeviceAddressCaptureReplay", structure->bufferDeviceAddressCaptureReplay);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "bufferDeviceAddressMultiDevice", structure->bufferDeviceAddressMultiDevice);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "vulkanMemoryModel", structure->vulkanMemoryModel);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "vulkanMemoryModelDeviceScope", structure->vulkanMemoryModelDeviceScope);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "vulkanMemoryModelAvailabilityVisibilityChains", structure->vulkanMemoryModelAvailabilityVisibilityChains);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderOutputViewportIndex", structure->shaderOutputViewportIndex);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "shaderOutputLayer", structure->shaderOutputLayer);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan12Features", "subgroupBroadcastDynamicId", structure->subgroupBroadcastDynamicId);
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkan12Properties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: { // Covers VUID-VkPhysicalDeviceVulkan12Properties-sType-sType
            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES) which was added in VK_API_VERSION_1_2 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkan13Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: { // Covers VUID-VkPhysicalDeviceVulkan13Features-sType-sType
            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES) which was added in VK_API_VERSION_1_3 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                VkPhysicalDeviceVulkan13Features *structure = (VkPhysicalDeviceVulkan13Features *) header;
                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "robustImageAccess", structure->robustImageAccess);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "inlineUniformBlock", structure->inlineUniformBlock);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "descriptorBindingInlineUniformBlockUpdateAfterBind", structure->descriptorBindingInlineUniformBlockUpdateAfterBind);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "pipelineCreationCacheControl", structure->pipelineCreationCacheControl);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "privateData", structure->privateData);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "shaderDemoteToHelperInvocation", structure->shaderDemoteToHelperInvocation);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "shaderTerminateInvocation", structure->shaderTerminateInvocation);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "subgroupSizeControl", structure->subgroupSizeControl);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "computeFullSubgroups", structure->computeFullSubgroups);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "synchronization2", structure->synchronization2);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "textureCompressionASTC_HDR", structure->textureCompressionASTC_HDR);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "shaderZeroInitializeWorkgroupMemory", structure->shaderZeroInitializeWorkgroupMemory);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "dynamicRendering", structure->dynamicRendering);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "shaderIntegerDotProduct", structure->shaderIntegerDotProduct);

                skip |= ValidateBool32("VkPhysicalDeviceVulkan13Features", "maintenance4", structure->maintenance4);
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkan13Properties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES: { // Covers VUID-VkPhysicalDeviceVulkan13Properties-sType-sType
            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES) which was added in VK_API_VERSION_1_3 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderTerminateInvocationFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES: { // Covers VUID-VkPhysicalDeviceShaderTerminateInvocationFeatures-sType-sType
            if (is_const_param) {
                if ((is_physdev_api && !SupportedByPdev(physical_device, VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME)) || (!is_physdev_api && !IsExtEnabled(device_extensions.vk_khr_shader_terminate_invocation))) {
                        skip |= LogError(
                               instance, pnext_vuid,
                               "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES), but its parent extension "
                               "VK_KHR_shader_terminate_invocation has not been enabled.",
                               api_name, parameter_name.get_name().c_str());
                }
            }

            if (is_const_param) {
                VkPhysicalDeviceShaderTerminateInvocationFeatures *structure = (VkPhysicalDeviceShaderTerminateInvocationFeatures *) header;
                skip |= ValidateBool32("VkPhysicalDeviceShaderTerminateInvocationFeatures", "shaderTerminateInvocation", structure->shaderTerminateInvocation);
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES: { // Covers VUID-VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures-sType-sType
            if (is_const_param) {
                if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME)) || (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_shader_demote_to_helper_invocation))) {
                        skip |= LogError(
                               instance, pnext_vuid,
                               "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES), but its parent extension "
                               "VK_EXT_shader_demote_to_helper_invocation has not been enabled.",
                               api_name, parameter_name.get_name().c_str());
                }
            }

            if (is_const_param) {
                VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures *structure = (VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures *) header;
                skip |= ValidateBool32("VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures", "shaderDemoteToHelperInvocation", structure->shaderDemoteToHelperInvocation);
            }
        } break;

        // Validation code for VkMemoryBarrier2 structure members
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2: { // Covers VUID-VkMemoryBarrier2-sType-sType
            if (is_const_param) {
                if ((is_physdev_api && !SupportedByPdev(physical_device, VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME)) || (!is_physdev_api && !IsExtEnabled(device_extensions.vk_khr_synchronization2))) {
                        skip |= LogError(
                               instance, pnext_vuid,
                               "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_MEMORY_BARRIER_2), but its parent extension "
                               "VK_KHR_synchronization2 has not been enabled.",
                               api_name, parameter_name.get_name().c_str());
                }
            }

            if (is_const_param) {
                VkMemoryBarrier2 *structure = (VkMemoryBarrier2 *) header;
                skip |= ValidateFlags("VkMemoryBarrier2", "srcStageMask", "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, structure->srcStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("VkMemoryBarrier2", "srcAccessMask", "VkAccessFlagBits2", AllVkAccessFlagBits2, structure->srcAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("VkMemoryBarrier2", "dstStageMask", "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, structure->dstStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("VkMemoryBarrier2", "dstAccessMask", "VkAccessFlagBits2", AllVkAccessFlagBits2, structure->dstAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstAccessMask-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceSynchronization2Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES: { // Covers VUID-VkPhysicalDeviceSynchronization2Features-sType-sType
            if (is_const_param) {
                if ((is_physdev_api && !SupportedByPdev(physical_device, VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME)) || (!is_physdev_api && !IsExtEnabled(device_extensions.vk_khr_synchronization2))) {
                        skip |= LogError(
                               instance, pnext_vuid,
                               "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES), but its parent extension "
                               "VK_KHR_synchronization2 has not been enabled.",
                               api_name, parameter_name.get_name().c_str());
                }
            }

            if (is_const_param) {
                VkPhysicalDeviceSynchronization2Features *structure = (VkPhysicalDeviceSynchronization2Features *) header;
                skip |= ValidateBool32("VkPhysicalDeviceSynchronization2Features", "synchronization2", structure->synchronization2);
            }
        } break;

        // Validation code for VkPhysicalDeviceImageRobustnessFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES: { // Covers VUID-VkPhysicalDeviceImageRobustnessFeatures-sType-sType
            if (is_const_param) {
                if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME)) || (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_image_robustness))) {
                        skip |= LogError(
                               instance, pnext_vuid,
                               "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES), but its parent extension "
                               "VK_EXT_image_robustness has not been enabled.",
                               api_name, parameter_name.get_name().c_str());
                }
            }

            if (is_const_param) {
                VkPhysicalDeviceImageRobustnessFeatures *structure = (VkPhysicalDeviceImageRobustnessFeatures *) header;
                skip |= ValidateBool32("VkPhysicalDeviceImageRobustnessFeatures", "robustImageAccess", structure->robustImageAccess);
            }
        } break;

        // Validation code for VkPhysicalDeviceSubgroupSizeControlFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES: { // Covers VUID-VkPhysicalDeviceSubgroupSizeControlFeatures-sType-sType
            if (is_const_param) {
                if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME)) || (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_subgroup_size_control))) {
                        skip |= LogError(
                               instance, pnext_vuid,
                               "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES), but its parent extension "
                               "VK_EXT_subgroup_size_control has not been enabled.",
                               api_name, parameter_name.get_name().c_str());
                }
            }

            if (is_const_param) {
                VkPhysicalDeviceSubgroupSizeControlFeatures *structure = (VkPhysicalDeviceSubgroupSizeControlFeatures *) header;
                skip |= ValidateBool32("VkPhysicalDeviceSubgroupSizeControlFeatures", "subgroupSizeControl", structure->subgroupSizeControl);

                skip |= ValidateBool32("VkPhysicalDeviceSubgroupSizeControlFeatures", "computeFullSubgroups", structure->computeFullSubgroups);
            }
        } break;

        // Validation code for VkPhysicalDeviceSubgroupSizeControlProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES: { // Covers VUID-VkPhysicalDeviceSubgroupSizeControlProperties-sType-sType
            if (is_const_param) {
                if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME)) || (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_subgroup_size_control))) {
                        skip |= LogError(
                               instance, pnext_vuid,
                               "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES), but its parent extension "
                               "VK_EXT_subgroup_size_control has not been enabled.",
                               api_name, parameter_name.get_name().c_str());
                }
            }

        } break;

        // Validation code for VkPipelineShaderStageRequiredSubgroupSizeCreateInfo structure members
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO: { // Covers VUID-VkPipelineShaderStageRequiredSubgroupSizeCreateInfo-sType-sType
            if (is_const_param) {
                if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME)) || (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_subgroup_size_control))) {
                        skip |= LogError(
                               instance, pnext_vuid,
                               "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO), but its parent extension "
                               "VK_EXT_subgroup_size_control has not been enabled.",
                               api_name, parameter_name.get_name().c_str());
                }
            }

        } break;

        // Validation code for VkPhysicalDeviceTextureCompressionASTCHDRFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES: { // Covers VUID-VkPhysicalDeviceTextureCompressionASTCHDRFeatures-sType-sType
            if (is_const_param) {
                if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME)) || (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_texture_compression_astc_hdr))) {
                        skip |= LogError(
                               instance, pnext_vuid,
                               "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES), but its parent extension "
                               "VK_EXT_texture_compression_astc_hdr has not been enabled.",
                               api_name, parameter_name.get_name().c_str());
                }
            }

            if (is_const_param) {
                VkPhysicalDeviceTextureCompressionASTCHDRFeatures *structure = (VkPhysicalDeviceTextureCompressionASTCHDRFeatures *) header;
                skip |= ValidateBool32("VkPhysicalDeviceTextureCompressionASTCHDRFeatures", "textureCompressionASTC_HDR", structure->textureCompressionASTC_HDR);
            }
        } break;

        // Validation code for VkPhysicalDeviceTexelBufferAlignmentProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES: { // Covers VUID-VkPhysicalDeviceTexelBufferAlignmentProperties-sType-sType
            if (is_const_param) {
                if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME)) || (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_texel_buffer_alignment))) {
                        skip |= LogError(
                               instance, pnext_vuid,
                               "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES), but its parent extension "
                               "VK_EXT_texel_buffer_alignment has not been enabled.",
                               api_name, parameter_name.get_name().c_str());
                }
            }

        } break;

        // Validation code for VkPhysicalDeviceVulkanSC10Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES: { // Covers VUID-VkPhysicalDeviceVulkanSC10Features-sType-sType
            if (api_version < VKSC_API_VERSION_1_0) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES) which was added in VKSC_API_VERSION_1_0 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                VkPhysicalDeviceVulkanSC10Features *structure = (VkPhysicalDeviceVulkanSC10Features *) header;
                skip |= ValidateBool32("VkPhysicalDeviceVulkanSC10Features", "shaderAtomicInstructions", structure->shaderAtomicInstructions);
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkanSC10Properties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES: { // Covers VUID-VkPhysicalDeviceVulkanSC10Properties-sType-sType
            if (api_version < VKSC_API_VERSION_1_0) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES) which was added in VKSC_API_VERSION_1_0 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkDeviceObjectReservationCreateInfo structure members
        case VK_STRUCTURE_TYPE_DEVICE_OBJECT_RESERVATION_CREATE_INFO: { // Covers VUID-VkDeviceObjectReservationCreateInfo-sType-sType
            if (api_version < VKSC_API_VERSION_1_0) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_DEVICE_OBJECT_RESERVATION_CREATE_INFO) which was added in VKSC_API_VERSION_1_0 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                VkDeviceObjectReservationCreateInfo *structure = (VkDeviceObjectReservationCreateInfo *) header;
                skip |= ValidateStructTypeArray("VkDeviceObjectReservationCreateInfo", "pipelineCacheCreateInfoCount", "pPipelineCacheCreateInfos", "VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO", structure->pipelineCacheCreateInfoCount, structure->pPipelineCacheCreateInfos, VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO, false, true, "VUID-VkPipelineCacheCreateInfo-sType-sType", "VUID-VkDeviceObjectReservationCreateInfo-pPipelineCacheCreateInfos-parameter", kVUIDUndefined);

                if (structure->pPipelineCacheCreateInfos != nullptr)
                {
                    for (uint32_t pipelineCacheCreateInfoIndex = 0; pipelineCacheCreateInfoIndex < structure->pipelineCacheCreateInfoCount; ++pipelineCacheCreateInfoIndex)
                    {
                        skip |= ValidateFlags("VkDeviceObjectReservationCreateInfo", ParameterName("pPipelineCacheCreateInfos[%i].flags", ParameterName::IndexVector{ pipelineCacheCreateInfoIndex }), "VkPipelineCacheCreateFlagBits", AllVkPipelineCacheCreateFlagBits, structure->pPipelineCacheCreateInfos[pipelineCacheCreateInfoIndex].flags, kOptionalFlags, "VUID-VkPipelineCacheCreateInfo-flags-parameter");

                        skip |= ValidateArray("VkDeviceObjectReservationCreateInfo", ParameterName("pPipelineCacheCreateInfos[%i].initialDataSize", ParameterName::IndexVector{ pipelineCacheCreateInfoIndex }), ParameterName("pPipelineCacheCreateInfos[%i].pInitialData", ParameterName::IndexVector{ pipelineCacheCreateInfoIndex }), structure->pPipelineCacheCreateInfos[pipelineCacheCreateInfoIndex].initialDataSize, &structure->pPipelineCacheCreateInfos[pipelineCacheCreateInfoIndex].pInitialData, true, true, "VUID-VkPipelineCacheCreateInfo-initialDataSize-arraylength", "VUID-VkPipelineCacheCreateInfo-pInitialData-parameter");
                    }
                }

                skip |= ValidateStructTypeArray("VkDeviceObjectReservationCreateInfo", "pipelinePoolSizeCount", "pPipelinePoolSizes", "VK_STRUCTURE_TYPE_PIPELINE_POOL_SIZE", structure->pipelinePoolSizeCount, structure->pPipelinePoolSizes, VK_STRUCTURE_TYPE_PIPELINE_POOL_SIZE, false, true, "VUID-VkPipelinePoolSize-sType-sType", "VUID-VkDeviceObjectReservationCreateInfo-pPipelinePoolSizes-parameter", kVUIDUndefined);

                if (structure->pPipelinePoolSizes != nullptr)
                {
                    for (uint32_t pipelinePoolSizeIndex = 0; pipelinePoolSizeIndex < structure->pipelinePoolSizeCount; ++pipelinePoolSizeIndex)
                    {
                    }
                }
            }
        } break;

        // Validation code for VkCommandPoolMemoryReservationCreateInfo structure members
        case VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_RESERVATION_CREATE_INFO: { // Covers VUID-VkCommandPoolMemoryReservationCreateInfo-sType-sType
            if (api_version < VKSC_API_VERSION_1_0) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_RESERVATION_CREATE_INFO) which was added in VKSC_API_VERSION_1_0 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkFaultCallbackInfo structure members
        case VK_STRUCTURE_TYPE_FAULT_CALLBACK_INFO: { // Covers VUID-VkFaultCallbackInfo-sType-sType
            if (api_version < VKSC_API_VERSION_1_0) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_FAULT_CALLBACK_INFO) which was added in VKSC_API_VERSION_1_0 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                VkFaultCallbackInfo *structure = (VkFaultCallbackInfo *) header;
                skip |= ValidateStructTypeArray("VkFaultCallbackInfo", "faultCount", "pFaults", "VK_STRUCTURE_TYPE_FAULT_DATA", structure->faultCount, structure->pFaults, VK_STRUCTURE_TYPE_FAULT_DATA, false, false, "VUID-VkFaultData-sType-sType", "VUID-VkFaultCallbackInfo-pFaults-parameter", kVUIDUndefined);

                if (structure->pFaults != nullptr)
                {
                    for (uint32_t faultIndex = 0; faultIndex < structure->faultCount; ++faultIndex)
                    {
                    }
                }

                skip |= ValidateRequiredPointer("VkFaultCallbackInfo", "pfnFaultCallback", reinterpret_cast<const void*>(structure->pfnFaultCallback), "VUID-VkFaultCallbackInfo-pfnFaultCallback-parameter");
            }
        } break;

        // Validation code for VkPipelineOfflineCreateInfo structure members
        case VK_STRUCTURE_TYPE_PIPELINE_OFFLINE_CREATE_INFO: { // Covers VUID-VkPipelineOfflineCreateInfo-sType-sType
            if (api_version < VKSC_API_VERSION_1_0) {
                skip |= LogError(
                           instance, pnext_vuid,
                           "%s: Includes a pNext pointer (%s) to a VkStructureType (VK_STRUCTURE_TYPE_PIPELINE_OFFLINE_CREATE_INFO) which was added in VKSC_API_VERSION_1_0 but the "
                           "current effective API version is %s.",
                           api_name, parameter_name.get_name().c_str(), StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                VkPipelineOfflineCreateInfo *structure = (VkPipelineOfflineCreateInfo *) header;
                skip |= ValidateRangedEnum("VkPipelineOfflineCreateInfo", "matchControl", "VkPipelineMatchControl", structure->matchControl, "VUID-VkPipelineOfflineCreateInfo-matchControl-parameter");
            }
        } break;

        // No Validation code for VkImageSwapchainCreateInfoKHR structure members  -- Covers VUID-VkImageSwapchainCreateInfoKHR-sType-sType

        // Validation code for VkBindImageMemorySwapchainInfoKHR structure members
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR: { // Covers VUID-VkBindImageMemorySwapchainInfoKHR-sType-sType
            if (is_const_param) {
                VkBindImageMemorySwapchainInfoKHR *structure = (VkBindImageMemorySwapchainInfoKHR *) header;
                skip |= ValidateRequiredHandle("VkBindImageMemorySwapchainInfoKHR", "swapchain", structure->swapchain);
            }
        } break;

        // Validation code for VkDeviceGroupPresentInfoKHR structure members
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR: { // Covers VUID-VkDeviceGroupPresentInfoKHR-sType-sType
            if (is_const_param) {
                VkDeviceGroupPresentInfoKHR *structure = (VkDeviceGroupPresentInfoKHR *) header;
                skip |= ValidateArray("VkDeviceGroupPresentInfoKHR", "swapchainCount", "pDeviceMasks", structure->swapchainCount, &structure->pDeviceMasks, false, true, kVUIDUndefined, "VUID-VkDeviceGroupPresentInfoKHR-pDeviceMasks-parameter");

                skip |= ValidateFlags("VkDeviceGroupPresentInfoKHR", "mode", "VkDeviceGroupPresentModeFlagBitsKHR", AllVkDeviceGroupPresentModeFlagBitsKHR, structure->mode, kRequiredSingleBit, "VUID-VkDeviceGroupPresentInfoKHR-mode-parameter", "VUID-VkDeviceGroupPresentInfoKHR-mode-parameter");
            }
        } break;

        // Validation code for VkDeviceGroupSwapchainCreateInfoKHR structure members
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR: { // Covers VUID-VkDeviceGroupSwapchainCreateInfoKHR-sType-sType
            if (is_const_param) {
                VkDeviceGroupSwapchainCreateInfoKHR *structure = (VkDeviceGroupSwapchainCreateInfoKHR *) header;
                skip |= ValidateFlags("VkDeviceGroupSwapchainCreateInfoKHR", "modes", "VkDeviceGroupPresentModeFlagBitsKHR", AllVkDeviceGroupPresentModeFlagBitsKHR, structure->modes, kRequiredFlags, "VUID-VkDeviceGroupSwapchainCreateInfoKHR-modes-parameter", "VUID-VkDeviceGroupSwapchainCreateInfoKHR-modes-requiredbitmask");
            }
        } break;

        // Validation code for VkDisplayPresentInfoKHR structure members
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR: { // Covers VUID-VkDisplayPresentInfoKHR-sType-sType
            if (is_const_param) {
                VkDisplayPresentInfoKHR *structure = (VkDisplayPresentInfoKHR *) header;
                skip |= ValidateBool32("VkDisplayPresentInfoKHR", "persistent", structure->persistent);
            }
        } break;

        // Validation code for VkImportMemoryFdInfoKHR structure members
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR: { // Covers VUID-VkImportMemoryFdInfoKHR-sType-sType
            if (is_const_param) {
                VkImportMemoryFdInfoKHR *structure = (VkImportMemoryFdInfoKHR *) header;
                skip |= ValidateFlags("VkImportMemoryFdInfoKHR", "handleType", "VkExternalMemoryHandleTypeFlagBits", AllVkExternalMemoryHandleTypeFlagBits, structure->handleType, kOptionalSingleBit, "VUID-VkImportMemoryFdInfoKHR-handleType-parameter");
            }
        } break;

        // Validation code for VkPresentRegionsKHR structure members
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR: { // Covers VUID-VkPresentRegionsKHR-sType-sType
            if (is_const_param) {
                VkPresentRegionsKHR *structure = (VkPresentRegionsKHR *) header;
                skip |= ValidateArray("VkPresentRegionsKHR", "swapchainCount", "pRegions", structure->swapchainCount, &structure->pRegions, true, false, "VUID-VkPresentRegionsKHR-swapchainCount-arraylength", "VUID-VkPresentRegionsKHR-pRegions-parameter");

                if (structure->pRegions != nullptr)
                {
                    for (uint32_t swapchainIndex = 0; swapchainIndex < structure->swapchainCount; ++swapchainIndex)
                    {
                        if (structure->pRegions[swapchainIndex].pRectangles != nullptr)
                        {
                            for (uint32_t rectangleIndex = 0; rectangleIndex < structure->pRegions[swapchainIndex].rectangleCount; ++rectangleIndex)
                            {
                            }
                        }
                    }
                }
            }
        } break;

        // No Validation code for VkSharedPresentSurfaceCapabilitiesKHR structure members  -- Covers VUID-VkSharedPresentSurfaceCapabilitiesKHR-sType-sType

        // Validation code for VkPhysicalDevicePerformanceQueryFeaturesKHR structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR: { // Covers VUID-VkPhysicalDevicePerformanceQueryFeaturesKHR-sType-sType
            if (is_const_param) {
                VkPhysicalDevicePerformanceQueryFeaturesKHR *structure = (VkPhysicalDevicePerformanceQueryFeaturesKHR *) header;
                skip |= ValidateBool32("VkPhysicalDevicePerformanceQueryFeaturesKHR", "performanceCounterQueryPools", structure->performanceCounterQueryPools);

                skip |= ValidateBool32("VkPhysicalDevicePerformanceQueryFeaturesKHR", "performanceCounterMultipleQueryPools", structure->performanceCounterMultipleQueryPools);
            }
        } break;

        // No Validation code for VkPhysicalDevicePerformanceQueryPropertiesKHR structure members  -- Covers VUID-VkPhysicalDevicePerformanceQueryPropertiesKHR-sType-sType

        // Validation code for VkQueryPoolPerformanceCreateInfoKHR structure members
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR: { // Covers VUID-VkQueryPoolPerformanceCreateInfoKHR-sType-sType
            if (is_const_param) {
                VkQueryPoolPerformanceCreateInfoKHR *structure = (VkQueryPoolPerformanceCreateInfoKHR *) header;
                skip |= ValidateArray("VkQueryPoolPerformanceCreateInfoKHR", "counterIndexCount", "pCounterIndices", structure->counterIndexCount, &structure->pCounterIndices, true, true, "VUID-VkQueryPoolPerformanceCreateInfoKHR-counterIndexCount-arraylength", "VUID-VkQueryPoolPerformanceCreateInfoKHR-pCounterIndices-parameter");
            }
        } break;

        // No Validation code for VkPerformanceQuerySubmitInfoKHR structure members  -- Covers VUID-VkPerformanceQuerySubmitInfoKHR-sType-sType

        // No Validation code for VkPerformanceQueryReservationInfoKHR structure members  -- Covers VUID-VkPerformanceQueryReservationInfoKHR-sType-sType

        // Validation code for VkPhysicalDeviceShaderClockFeaturesKHR structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR: { // Covers VUID-VkPhysicalDeviceShaderClockFeaturesKHR-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceShaderClockFeaturesKHR *structure = (VkPhysicalDeviceShaderClockFeaturesKHR *) header;
                skip |= ValidateBool32("VkPhysicalDeviceShaderClockFeaturesKHR", "shaderSubgroupClock", structure->shaderSubgroupClock);

                skip |= ValidateBool32("VkPhysicalDeviceShaderClockFeaturesKHR", "shaderDeviceClock", structure->shaderDeviceClock);
            }
        } break;

        // Validation code for VkFragmentShadingRateAttachmentInfoKHR structure members
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: { // Covers VUID-VkFragmentShadingRateAttachmentInfoKHR-sType-sType
            if (is_const_param) {
                VkFragmentShadingRateAttachmentInfoKHR *structure = (VkFragmentShadingRateAttachmentInfoKHR *) header;
                skip |= ValidateStructType("VkFragmentShadingRateAttachmentInfoKHR", "pFragmentShadingRateAttachment", "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2", structure->pFragmentShadingRateAttachment, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2, false, "VUID-VkFragmentShadingRateAttachmentInfoKHR-pFragmentShadingRateAttachment-parameter", "VUID-VkAttachmentReference2-sType-sType");

                if (structure->pFragmentShadingRateAttachment != nullptr)
                {
                    skip |= ValidateRangedEnum("VkFragmentShadingRateAttachmentInfoKHR", "pFragmentShadingRateAttachment->layout", "VkImageLayout", structure->pFragmentShadingRateAttachment->layout, "VUID-VkAttachmentReference2-layout-parameter");
                }

            }
        } break;

        // No Validation code for VkPipelineFragmentShadingRateStateCreateInfoKHR structure members  -- Covers VUID-VkPipelineFragmentShadingRateStateCreateInfoKHR-sType-sType

        // Validation code for VkPhysicalDeviceFragmentShadingRateFeaturesKHR structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR: { // Covers VUID-VkPhysicalDeviceFragmentShadingRateFeaturesKHR-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceFragmentShadingRateFeaturesKHR *structure = (VkPhysicalDeviceFragmentShadingRateFeaturesKHR *) header;
                skip |= ValidateBool32("VkPhysicalDeviceFragmentShadingRateFeaturesKHR", "pipelineFragmentShadingRate", structure->pipelineFragmentShadingRate);

                skip |= ValidateBool32("VkPhysicalDeviceFragmentShadingRateFeaturesKHR", "primitiveFragmentShadingRate", structure->primitiveFragmentShadingRate);

                skip |= ValidateBool32("VkPhysicalDeviceFragmentShadingRateFeaturesKHR", "attachmentFragmentShadingRate", structure->attachmentFragmentShadingRate);
            }
        } break;

        // No Validation code for VkPhysicalDeviceFragmentShadingRatePropertiesKHR structure members  -- Covers VUID-VkPhysicalDeviceFragmentShadingRatePropertiesKHR-sType-sType

        // No Validation code for VkQueueFamilyCheckpointProperties2NV structure members  -- Covers VUID-VkQueueFamilyCheckpointProperties2NV-sType-sType

        // Validation code for VkImageViewASTCDecodeModeEXT structure members
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT: { // Covers VUID-VkImageViewASTCDecodeModeEXT-sType-sType
            if (is_const_param) {
                VkImageViewASTCDecodeModeEXT *structure = (VkImageViewASTCDecodeModeEXT *) header;
                skip |= ValidateRangedEnum("VkImageViewASTCDecodeModeEXT", "decodeMode", "VkFormat", structure->decodeMode, "VUID-VkImageViewASTCDecodeModeEXT-decodeMode-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceASTCDecodeFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceASTCDecodeFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceASTCDecodeFeaturesEXT *structure = (VkPhysicalDeviceASTCDecodeFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceASTCDecodeFeaturesEXT", "decodeModeSharedExponent", structure->decodeModeSharedExponent);
            }
        } break;

        // Validation code for VkSwapchainCounterCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT: { // Covers VUID-VkSwapchainCounterCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkSwapchainCounterCreateInfoEXT *structure = (VkSwapchainCounterCreateInfoEXT *) header;
                skip |= ValidateFlags("VkSwapchainCounterCreateInfoEXT", "surfaceCounters", "VkSurfaceCounterFlagBitsEXT", AllVkSurfaceCounterFlagBitsEXT, structure->surfaceCounters, kOptionalFlags, "VUID-VkSwapchainCounterCreateInfoEXT-surfaceCounters-parameter");
            }
        } break;

        // No Validation code for VkPhysicalDeviceDiscardRectanglePropertiesEXT structure members  -- Covers VUID-VkPhysicalDeviceDiscardRectanglePropertiesEXT-sType-sType

        // Validation code for VkPipelineDiscardRectangleStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT: { // Covers VUID-VkPipelineDiscardRectangleStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkPipelineDiscardRectangleStateCreateInfoEXT *structure = (VkPipelineDiscardRectangleStateCreateInfoEXT *) header;
                skip |= ValidateReservedFlags("VkPipelineDiscardRectangleStateCreateInfoEXT", "flags", structure->flags, "VUID-VkPipelineDiscardRectangleStateCreateInfoEXT-flags-zerobitmask");

                skip |= ValidateRangedEnum("VkPipelineDiscardRectangleStateCreateInfoEXT", "discardRectangleMode", "VkDiscardRectangleModeEXT", structure->discardRectangleMode, "VUID-VkPipelineDiscardRectangleStateCreateInfoEXT-discardRectangleMode-parameter");
            }
        } break;

        // No Validation code for VkPhysicalDeviceConservativeRasterizationPropertiesEXT structure members  -- Covers VUID-VkPhysicalDeviceConservativeRasterizationPropertiesEXT-sType-sType

        // Validation code for VkPipelineRasterizationConservativeStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT: { // Covers VUID-VkPipelineRasterizationConservativeStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkPipelineRasterizationConservativeStateCreateInfoEXT *structure = (VkPipelineRasterizationConservativeStateCreateInfoEXT *) header;
                skip |= ValidateReservedFlags("VkPipelineRasterizationConservativeStateCreateInfoEXT", "flags", structure->flags, "VUID-VkPipelineRasterizationConservativeStateCreateInfoEXT-flags-zerobitmask");

                skip |= ValidateRangedEnum("VkPipelineRasterizationConservativeStateCreateInfoEXT", "conservativeRasterizationMode", "VkConservativeRasterizationModeEXT", structure->conservativeRasterizationMode, "VUID-VkPipelineRasterizationConservativeStateCreateInfoEXT-conservativeRasterizationMode-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceDepthClipEnableFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceDepthClipEnableFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceDepthClipEnableFeaturesEXT *structure = (VkPhysicalDeviceDepthClipEnableFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceDepthClipEnableFeaturesEXT", "depthClipEnable", structure->depthClipEnable);
            }
        } break;

        // Validation code for VkPipelineRasterizationDepthClipStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT: { // Covers VUID-VkPipelineRasterizationDepthClipStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkPipelineRasterizationDepthClipStateCreateInfoEXT *structure = (VkPipelineRasterizationDepthClipStateCreateInfoEXT *) header;
                skip |= ValidateReservedFlags("VkPipelineRasterizationDepthClipStateCreateInfoEXT", "flags", structure->flags, "VUID-VkPipelineRasterizationDepthClipStateCreateInfoEXT-flags-zerobitmask");

                skip |= ValidateBool32("VkPipelineRasterizationDepthClipStateCreateInfoEXT", "depthClipEnable", structure->depthClipEnable);
            }
        } break;

        // Validation code for VkDebugUtilsObjectNameInfoEXT structure members
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT: { // Covers VUID-VkDebugUtilsObjectNameInfoEXT-sType-sType
            if (is_const_param) {
                VkDebugUtilsObjectNameInfoEXT *structure = (VkDebugUtilsObjectNameInfoEXT *) header;
                skip |= ValidateRangedEnum("VkDebugUtilsObjectNameInfoEXT", "objectType", "VkObjectType", structure->objectType, "VUID-VkDebugUtilsObjectNameInfoEXT-objectType-parameter");
            }
        } break;

        // Validation code for VkDebugUtilsMessengerCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT: { // Covers VUID-VkDebugUtilsMessengerCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkDebugUtilsMessengerCreateInfoEXT *structure = (VkDebugUtilsMessengerCreateInfoEXT *) header;
                skip |= ValidateReservedFlags("VkDebugUtilsMessengerCreateInfoEXT", "flags", structure->flags, "VUID-VkDebugUtilsMessengerCreateInfoEXT-flags-zerobitmask");

                skip |= ValidateFlags("VkDebugUtilsMessengerCreateInfoEXT", "messageSeverity", "VkDebugUtilsMessageSeverityFlagBitsEXT", AllVkDebugUtilsMessageSeverityFlagBitsEXT, structure->messageSeverity, kRequiredFlags, "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageSeverity-parameter", "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageSeverity-requiredbitmask");

                skip |= ValidateFlags("VkDebugUtilsMessengerCreateInfoEXT", "messageType", "VkDebugUtilsMessageTypeFlagBitsEXT", AllVkDebugUtilsMessageTypeFlagBitsEXT, structure->messageType, kRequiredFlags, "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageType-parameter", "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageType-requiredbitmask");

                skip |= ValidateRequiredPointer("VkDebugUtilsMessengerCreateInfoEXT", "pfnUserCallback", reinterpret_cast<const void*>(structure->pfnUserCallback), "VUID-VkDebugUtilsMessengerCreateInfoEXT-pfnUserCallback-parameter");
            }
        } break;

        // Validation code for VkSampleLocationsInfoEXT structure members
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: { // Covers VUID-VkSampleLocationsInfoEXT-sType-sType
            if (is_const_param) {
                VkSampleLocationsInfoEXT *structure = (VkSampleLocationsInfoEXT *) header;
                skip |= ValidateArray("VkSampleLocationsInfoEXT", "sampleLocationsCount", "pSampleLocations", structure->sampleLocationsCount, &structure->pSampleLocations, false, true, kVUIDUndefined, "VUID-VkSampleLocationsInfoEXT-pSampleLocations-parameter");

                if (structure->pSampleLocations != nullptr)
                {
                    for (uint32_t sampleLocationsIndex = 0; sampleLocationsIndex < structure->sampleLocationsCount; ++sampleLocationsIndex)
                    {
                    }
                }
            }
        } break;

        // Validation code for VkRenderPassSampleLocationsBeginInfoEXT structure members
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT: { // Covers VUID-VkRenderPassSampleLocationsBeginInfoEXT-sType-sType
            if (is_const_param) {
                VkRenderPassSampleLocationsBeginInfoEXT *structure = (VkRenderPassSampleLocationsBeginInfoEXT *) header;
                skip |= ValidateArray("VkRenderPassSampleLocationsBeginInfoEXT", "attachmentInitialSampleLocationsCount", "pAttachmentInitialSampleLocations", structure->attachmentInitialSampleLocationsCount, &structure->pAttachmentInitialSampleLocations, false, true, kVUIDUndefined, "VUID-VkRenderPassSampleLocationsBeginInfoEXT-pAttachmentInitialSampleLocations-parameter");

                if (structure->pAttachmentInitialSampleLocations != nullptr)
                {
                    for (uint32_t attachmentInitialSampleLocationsIndex = 0; attachmentInitialSampleLocationsIndex < structure->attachmentInitialSampleLocationsCount; ++attachmentInitialSampleLocationsIndex)
                    {
                        skip |= ValidateStructType("VkRenderPassSampleLocationsBeginInfoEXT", ParameterName("pAttachmentInitialSampleLocations[%i].sampleLocationsInfo", ParameterName::IndexVector{ attachmentInitialSampleLocationsIndex }), "VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT", &(structure->pAttachmentInitialSampleLocations[attachmentInitialSampleLocationsIndex].sampleLocationsInfo), VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT, false, kVUIDUndefined, "VUID-VkSampleLocationsInfoEXT-sType-sType");

                        skip |= ValidateArray("VkRenderPassSampleLocationsBeginInfoEXT", ParameterName("pAttachmentInitialSampleLocations[%i].sampleLocationsInfo.sampleLocationsCount", ParameterName::IndexVector{ attachmentInitialSampleLocationsIndex }), ParameterName("pAttachmentInitialSampleLocations[%i].sampleLocationsInfo.pSampleLocations", ParameterName::IndexVector{ attachmentInitialSampleLocationsIndex }), structure->pAttachmentInitialSampleLocations[attachmentInitialSampleLocationsIndex].sampleLocationsInfo.sampleLocationsCount, &structure->pAttachmentInitialSampleLocations[attachmentInitialSampleLocationsIndex].sampleLocationsInfo.pSampleLocations, false, true, kVUIDUndefined, "VUID-VkSampleLocationsInfoEXT-pSampleLocations-parameter");

                        if (structure->pAttachmentInitialSampleLocations[attachmentInitialSampleLocationsIndex].sampleLocationsInfo.pSampleLocations != nullptr)
                        {
                            for (uint32_t sampleLocationsIndex = 0; sampleLocationsIndex < structure->pAttachmentInitialSampleLocations[attachmentInitialSampleLocationsIndex].sampleLocationsInfo.sampleLocationsCount; ++sampleLocationsIndex)
                            {
                            }
                        }
                    }
                }

                skip |= ValidateArray("VkRenderPassSampleLocationsBeginInfoEXT", "postSubpassSampleLocationsCount", "pPostSubpassSampleLocations", structure->postSubpassSampleLocationsCount, &structure->pPostSubpassSampleLocations, false, true, kVUIDUndefined, "VUID-VkRenderPassSampleLocationsBeginInfoEXT-pPostSubpassSampleLocations-parameter");

                if (structure->pPostSubpassSampleLocations != nullptr)
                {
                    for (uint32_t postSubpassSampleLocationsIndex = 0; postSubpassSampleLocationsIndex < structure->postSubpassSampleLocationsCount; ++postSubpassSampleLocationsIndex)
                    {
                        skip |= ValidateStructType("VkRenderPassSampleLocationsBeginInfoEXT", ParameterName("pPostSubpassSampleLocations[%i].sampleLocationsInfo", ParameterName::IndexVector{ postSubpassSampleLocationsIndex }), "VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT", &(structure->pPostSubpassSampleLocations[postSubpassSampleLocationsIndex].sampleLocationsInfo), VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT, false, kVUIDUndefined, "VUID-VkSampleLocationsInfoEXT-sType-sType");

                        skip |= ValidateArray("VkRenderPassSampleLocationsBeginInfoEXT", ParameterName("pPostSubpassSampleLocations[%i].sampleLocationsInfo.sampleLocationsCount", ParameterName::IndexVector{ postSubpassSampleLocationsIndex }), ParameterName("pPostSubpassSampleLocations[%i].sampleLocationsInfo.pSampleLocations", ParameterName::IndexVector{ postSubpassSampleLocationsIndex }), structure->pPostSubpassSampleLocations[postSubpassSampleLocationsIndex].sampleLocationsInfo.sampleLocationsCount, &structure->pPostSubpassSampleLocations[postSubpassSampleLocationsIndex].sampleLocationsInfo.pSampleLocations, false, true, kVUIDUndefined, "VUID-VkSampleLocationsInfoEXT-pSampleLocations-parameter");

                        if (structure->pPostSubpassSampleLocations[postSubpassSampleLocationsIndex].sampleLocationsInfo.pSampleLocations != nullptr)
                        {
                            for (uint32_t sampleLocationsIndex = 0; sampleLocationsIndex < structure->pPostSubpassSampleLocations[postSubpassSampleLocationsIndex].sampleLocationsInfo.sampleLocationsCount; ++sampleLocationsIndex)
                            {
                            }
                        }
                    }
                }
            }
        } break;

        // Validation code for VkPipelineSampleLocationsStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT: { // Covers VUID-VkPipelineSampleLocationsStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkPipelineSampleLocationsStateCreateInfoEXT *structure = (VkPipelineSampleLocationsStateCreateInfoEXT *) header;
                skip |= ValidateBool32("VkPipelineSampleLocationsStateCreateInfoEXT", "sampleLocationsEnable", structure->sampleLocationsEnable);

                skip |= ValidateStructType("VkPipelineSampleLocationsStateCreateInfoEXT", "sampleLocationsInfo", "VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT", &(structure->sampleLocationsInfo), VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT, false, kVUIDUndefined, "VUID-VkSampleLocationsInfoEXT-sType-sType");

                skip |= ValidateArray("VkPipelineSampleLocationsStateCreateInfoEXT", "sampleLocationsInfo.sampleLocationsCount", "sampleLocationsInfo.pSampleLocations", structure->sampleLocationsInfo.sampleLocationsCount, &structure->sampleLocationsInfo.pSampleLocations, false, true, kVUIDUndefined, "VUID-VkSampleLocationsInfoEXT-pSampleLocations-parameter");

                if (structure->sampleLocationsInfo.pSampleLocations != nullptr)
                {
                    for (uint32_t sampleLocationsIndex = 0; sampleLocationsIndex < structure->sampleLocationsInfo.sampleLocationsCount; ++sampleLocationsIndex)
                    {
                    }
                }
            }
        } break;

        // No Validation code for VkPhysicalDeviceSampleLocationsPropertiesEXT structure members  -- Covers VUID-VkPhysicalDeviceSampleLocationsPropertiesEXT-sType-sType

        // Validation code for VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT *structure = (VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT", "advancedBlendCoherentOperations", structure->advancedBlendCoherentOperations);
            }
        } break;

        // No Validation code for VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT structure members  -- Covers VUID-VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT-sType-sType

        // Validation code for VkPipelineColorBlendAdvancedStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT: { // Covers VUID-VkPipelineColorBlendAdvancedStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkPipelineColorBlendAdvancedStateCreateInfoEXT *structure = (VkPipelineColorBlendAdvancedStateCreateInfoEXT *) header;
                skip |= ValidateBool32("VkPipelineColorBlendAdvancedStateCreateInfoEXT", "srcPremultiplied", structure->srcPremultiplied);

                skip |= ValidateBool32("VkPipelineColorBlendAdvancedStateCreateInfoEXT", "dstPremultiplied", structure->dstPremultiplied);

                skip |= ValidateRangedEnum("VkPipelineColorBlendAdvancedStateCreateInfoEXT", "blendOverlap", "VkBlendOverlapEXT", structure->blendOverlap, "VUID-VkPipelineColorBlendAdvancedStateCreateInfoEXT-blendOverlap-parameter");
            }
        } break;

        // No Validation code for VkDrmFormatModifierPropertiesListEXT structure members  -- Covers VUID-VkDrmFormatModifierPropertiesListEXT-sType-sType

        // Validation code for VkPhysicalDeviceImageDrmFormatModifierInfoEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT: { // Covers VUID-VkPhysicalDeviceImageDrmFormatModifierInfoEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceImageDrmFormatModifierInfoEXT *structure = (VkPhysicalDeviceImageDrmFormatModifierInfoEXT *) header;
                skip |= ValidateRangedEnum("VkPhysicalDeviceImageDrmFormatModifierInfoEXT", "sharingMode", "VkSharingMode", structure->sharingMode, "VUID-VkPhysicalDeviceImageDrmFormatModifierInfoEXT-sharingMode-parameter");
            }
        } break;

        // Validation code for VkImageDrmFormatModifierListCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT: { // Covers VUID-VkImageDrmFormatModifierListCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkImageDrmFormatModifierListCreateInfoEXT *structure = (VkImageDrmFormatModifierListCreateInfoEXT *) header;
                skip |= ValidateArray("VkImageDrmFormatModifierListCreateInfoEXT", "drmFormatModifierCount", "pDrmFormatModifiers", structure->drmFormatModifierCount, &structure->pDrmFormatModifiers, true, true, "VUID-VkImageDrmFormatModifierListCreateInfoEXT-drmFormatModifierCount-arraylength", "VUID-VkImageDrmFormatModifierListCreateInfoEXT-pDrmFormatModifiers-parameter");
            }
        } break;

        // Validation code for VkImageDrmFormatModifierExplicitCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT: { // Covers VUID-VkImageDrmFormatModifierExplicitCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkImageDrmFormatModifierExplicitCreateInfoEXT *structure = (VkImageDrmFormatModifierExplicitCreateInfoEXT *) header;
                skip |= ValidateArray("VkImageDrmFormatModifierExplicitCreateInfoEXT", "drmFormatModifierPlaneCount", "pPlaneLayouts", structure->drmFormatModifierPlaneCount, &structure->pPlaneLayouts, true, true, kVUIDUndefined, "VUID-VkImageDrmFormatModifierExplicitCreateInfoEXT-pPlaneLayouts-parameter");

                if (structure->pPlaneLayouts != nullptr)
                {
                    for (uint32_t drmFormatModifierPlaneIndex = 0; drmFormatModifierPlaneIndex < structure->drmFormatModifierPlaneCount; ++drmFormatModifierPlaneIndex)
                    {
                    }
                }
            }
        } break;

        // No Validation code for VkDrmFormatModifierPropertiesList2EXT structure members  -- Covers VUID-VkDrmFormatModifierPropertiesList2EXT-sType-sType

        // Validation code for VkPhysicalDeviceImageViewImageFormatInfoEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT: { // Covers VUID-VkPhysicalDeviceImageViewImageFormatInfoEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceImageViewImageFormatInfoEXT *structure = (VkPhysicalDeviceImageViewImageFormatInfoEXT *) header;
                skip |= ValidateRangedEnum("VkPhysicalDeviceImageViewImageFormatInfoEXT", "imageViewType", "VkImageViewType", structure->imageViewType, "VUID-VkPhysicalDeviceImageViewImageFormatInfoEXT-imageViewType-parameter");
            }
        } break;

        // No Validation code for VkFilterCubicImageViewImageFormatPropertiesEXT structure members  -- Covers VUID-VkFilterCubicImageViewImageFormatPropertiesEXT-sType-sType

        // Validation code for VkDeviceQueueGlobalPriorityCreateInfoKHR structure members
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR: { // Covers VUID-VkDeviceQueueGlobalPriorityCreateInfoKHR-sType-sType
            if (is_const_param) {
                VkDeviceQueueGlobalPriorityCreateInfoKHR *structure = (VkDeviceQueueGlobalPriorityCreateInfoKHR *) header;
                skip |= ValidateRangedEnum("VkDeviceQueueGlobalPriorityCreateInfoKHR", "globalPriority", "VkQueueGlobalPriorityKHR", structure->globalPriority, "VUID-VkDeviceQueueGlobalPriorityCreateInfoKHR-globalPriority-parameter");
            }
        } break;

        // Validation code for VkImportMemoryHostPointerInfoEXT structure members
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT: { // Covers VUID-VkImportMemoryHostPointerInfoEXT-sType-sType
            if (is_const_param) {
                VkImportMemoryHostPointerInfoEXT *structure = (VkImportMemoryHostPointerInfoEXT *) header;
                skip |= ValidateFlags("VkImportMemoryHostPointerInfoEXT", "handleType", "VkExternalMemoryHandleTypeFlagBits", AllVkExternalMemoryHandleTypeFlagBits, structure->handleType, kRequiredSingleBit, "VUID-VkImportMemoryHostPointerInfoEXT-handleType-parameter", "VUID-VkImportMemoryHostPointerInfoEXT-handleType-parameter");

                skip |= ValidateRequiredPointer("VkImportMemoryHostPointerInfoEXT", "pHostPointer", structure->pHostPointer, kVUIDUndefined);
            }
        } break;

        // No Validation code for VkPhysicalDeviceExternalMemoryHostPropertiesEXT structure members  -- Covers VUID-VkPhysicalDeviceExternalMemoryHostPropertiesEXT-sType-sType

        // No Validation code for VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT structure members  -- Covers VUID-VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT-sType-sType

        // Validation code for VkPipelineVertexInputDivisorStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT: { // Covers VUID-VkPipelineVertexInputDivisorStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkPipelineVertexInputDivisorStateCreateInfoEXT *structure = (VkPipelineVertexInputDivisorStateCreateInfoEXT *) header;
                skip |= ValidateArray("VkPipelineVertexInputDivisorStateCreateInfoEXT", "vertexBindingDivisorCount", "pVertexBindingDivisors", structure->vertexBindingDivisorCount, &structure->pVertexBindingDivisors, true, true, "VUID-VkPipelineVertexInputDivisorStateCreateInfoEXT-vertexBindingDivisorCount-arraylength", "VUID-VkPipelineVertexInputDivisorStateCreateInfoEXT-pVertexBindingDivisors-parameter");

                if (structure->pVertexBindingDivisors != nullptr)
                {
                    for (uint32_t vertexBindingDivisorIndex = 0; vertexBindingDivisorIndex < structure->vertexBindingDivisorCount; ++vertexBindingDivisorIndex)
                    {
                    }
                }
            }
        } break;

        // Validation code for VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT *structure = (VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT", "vertexAttributeInstanceRateDivisor", structure->vertexAttributeInstanceRateDivisor);

                skip |= ValidateBool32("VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT", "vertexAttributeInstanceRateZeroDivisor", structure->vertexAttributeInstanceRateZeroDivisor);
            }
        } break;

        // No Validation code for VkPhysicalDevicePCIBusInfoPropertiesEXT structure members  -- Covers VUID-VkPhysicalDevicePCIBusInfoPropertiesEXT-sType-sType

        // Validation code for VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT *structure = (VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT", "shaderImageInt64Atomics", structure->shaderImageInt64Atomics);

                skip |= ValidateBool32("VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT", "sparseImageInt64Atomics", structure->sparseImageInt64Atomics);
            }
        } break;

        // No Validation code for VkPhysicalDeviceMemoryBudgetPropertiesEXT structure members  -- Covers VUID-VkPhysicalDeviceMemoryBudgetPropertiesEXT-sType-sType

        // Validation code for VkValidationFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT: { // Covers VUID-VkValidationFeaturesEXT-sType-sType
            if (is_const_param) {
                VkValidationFeaturesEXT *structure = (VkValidationFeaturesEXT *) header;
                skip |= ValidateRangedEnumArray("VkValidationFeaturesEXT", "enabledValidationFeatureCount", "pEnabledValidationFeatures", "VkValidationFeatureEnableEXT", structure->enabledValidationFeatureCount, structure->pEnabledValidationFeatures, false, true);

                skip |= ValidateRangedEnumArray("VkValidationFeaturesEXT", "disabledValidationFeatureCount", "pDisabledValidationFeatures", "VkValidationFeatureDisableEXT", structure->disabledValidationFeatureCount, structure->pDisabledValidationFeatures, false, true);
            }
        } break;

        // Validation code for VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT *structure = (VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT", "fragmentShaderSampleInterlock", structure->fragmentShaderSampleInterlock);

                skip |= ValidateBool32("VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT", "fragmentShaderPixelInterlock", structure->fragmentShaderPixelInterlock);

                skip |= ValidateBool32("VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT", "fragmentShaderShadingRateInterlock", structure->fragmentShaderShadingRateInterlock);
            }
        } break;

        // Validation code for VkPhysicalDeviceYcbcrImageArraysFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceYcbcrImageArraysFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceYcbcrImageArraysFeaturesEXT *structure = (VkPhysicalDeviceYcbcrImageArraysFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceYcbcrImageArraysFeaturesEXT", "ycbcrImageArrays", structure->ycbcrImageArrays);
            }
        } break;

        // Validation code for VkPhysicalDeviceLineRasterizationFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceLineRasterizationFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceLineRasterizationFeaturesEXT *structure = (VkPhysicalDeviceLineRasterizationFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceLineRasterizationFeaturesEXT", "rectangularLines", structure->rectangularLines);

                skip |= ValidateBool32("VkPhysicalDeviceLineRasterizationFeaturesEXT", "bresenhamLines", structure->bresenhamLines);

                skip |= ValidateBool32("VkPhysicalDeviceLineRasterizationFeaturesEXT", "smoothLines", structure->smoothLines);

                skip |= ValidateBool32("VkPhysicalDeviceLineRasterizationFeaturesEXT", "stippledRectangularLines", structure->stippledRectangularLines);

                skip |= ValidateBool32("VkPhysicalDeviceLineRasterizationFeaturesEXT", "stippledBresenhamLines", structure->stippledBresenhamLines);

                skip |= ValidateBool32("VkPhysicalDeviceLineRasterizationFeaturesEXT", "stippledSmoothLines", structure->stippledSmoothLines);
            }
        } break;

        // No Validation code for VkPhysicalDeviceLineRasterizationPropertiesEXT structure members  -- Covers VUID-VkPhysicalDeviceLineRasterizationPropertiesEXT-sType-sType

        // Validation code for VkPipelineRasterizationLineStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT: { // Covers VUID-VkPipelineRasterizationLineStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkPipelineRasterizationLineStateCreateInfoEXT *structure = (VkPipelineRasterizationLineStateCreateInfoEXT *) header;
                skip |= ValidateRangedEnum("VkPipelineRasterizationLineStateCreateInfoEXT", "lineRasterizationMode", "VkLineRasterizationModeEXT", structure->lineRasterizationMode, "VUID-VkPipelineRasterizationLineStateCreateInfoEXT-lineRasterizationMode-parameter");

                skip |= ValidateBool32("VkPipelineRasterizationLineStateCreateInfoEXT", "stippledLineEnable", structure->stippledLineEnable);
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderAtomicFloatFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceShaderAtomicFloatFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceShaderAtomicFloatFeaturesEXT *structure = (VkPhysicalDeviceShaderAtomicFloatFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", "shaderBufferFloat32Atomics", structure->shaderBufferFloat32Atomics);

                skip |= ValidateBool32("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", "shaderBufferFloat32AtomicAdd", structure->shaderBufferFloat32AtomicAdd);

                skip |= ValidateBool32("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", "shaderBufferFloat64Atomics", structure->shaderBufferFloat64Atomics);

                skip |= ValidateBool32("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", "shaderBufferFloat64AtomicAdd", structure->shaderBufferFloat64AtomicAdd);

                skip |= ValidateBool32("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", "shaderSharedFloat32Atomics", structure->shaderSharedFloat32Atomics);

                skip |= ValidateBool32("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", "shaderSharedFloat32AtomicAdd", structure->shaderSharedFloat32AtomicAdd);

                skip |= ValidateBool32("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", "shaderSharedFloat64Atomics", structure->shaderSharedFloat64Atomics);

                skip |= ValidateBool32("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", "shaderSharedFloat64AtomicAdd", structure->shaderSharedFloat64AtomicAdd);

                skip |= ValidateBool32("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", "shaderImageFloat32Atomics", structure->shaderImageFloat32Atomics);

                skip |= ValidateBool32("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", "shaderImageFloat32AtomicAdd", structure->shaderImageFloat32AtomicAdd);

                skip |= ValidateBool32("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", "sparseImageFloat32Atomics", structure->sparseImageFloat32Atomics);

                skip |= ValidateBool32("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", "sparseImageFloat32AtomicAdd", structure->sparseImageFloat32AtomicAdd);
            }
        } break;

        // Validation code for VkPhysicalDeviceIndexTypeUint8FeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceIndexTypeUint8FeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceIndexTypeUint8FeaturesEXT *structure = (VkPhysicalDeviceIndexTypeUint8FeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceIndexTypeUint8FeaturesEXT", "indexTypeUint8", structure->indexTypeUint8);
            }
        } break;

        // Validation code for VkPhysicalDeviceExtendedDynamicStateFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceExtendedDynamicStateFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceExtendedDynamicStateFeaturesEXT *structure = (VkPhysicalDeviceExtendedDynamicStateFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceExtendedDynamicStateFeaturesEXT", "extendedDynamicState", structure->extendedDynamicState);
            }
        } break;

        // Validation code for VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT *structure = (VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT", "texelBufferAlignment", structure->texelBufferAlignment);
            }
        } break;

        // Validation code for VkPhysicalDeviceRobustness2FeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceRobustness2FeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceRobustness2FeaturesEXT *structure = (VkPhysicalDeviceRobustness2FeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceRobustness2FeaturesEXT", "robustBufferAccess2", structure->robustBufferAccess2);

                skip |= ValidateBool32("VkPhysicalDeviceRobustness2FeaturesEXT", "robustImageAccess2", structure->robustImageAccess2);

                skip |= ValidateBool32("VkPhysicalDeviceRobustness2FeaturesEXT", "nullDescriptor", structure->nullDescriptor);
            }
        } break;

        // No Validation code for VkPhysicalDeviceRobustness2PropertiesEXT structure members  -- Covers VUID-VkPhysicalDeviceRobustness2PropertiesEXT-sType-sType

        // Validation code for VkSamplerCustomBorderColorCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT: { // Covers VUID-VkSamplerCustomBorderColorCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkSamplerCustomBorderColorCreateInfoEXT *structure = (VkSamplerCustomBorderColorCreateInfoEXT *) header;
                skip |= ValidateRangedEnum("VkSamplerCustomBorderColorCreateInfoEXT", "format", "VkFormat", structure->format, "VUID-VkSamplerCustomBorderColorCreateInfoEXT-format-parameter");
            }
        } break;

        // No Validation code for VkPhysicalDeviceCustomBorderColorPropertiesEXT structure members  -- Covers VUID-VkPhysicalDeviceCustomBorderColorPropertiesEXT-sType-sType

        // Validation code for VkPhysicalDeviceCustomBorderColorFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceCustomBorderColorFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceCustomBorderColorFeaturesEXT *structure = (VkPhysicalDeviceCustomBorderColorFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceCustomBorderColorFeaturesEXT", "customBorderColors", structure->customBorderColors);

                skip |= ValidateBool32("VkPhysicalDeviceCustomBorderColorFeaturesEXT", "customBorderColorWithoutFormat", structure->customBorderColorWithoutFormat);
            }
        } break;

        // Validation code for VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT *structure = (VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT", "ycbcr2plane444Formats", structure->ycbcr2plane444Formats);
            }
        } break;

        // Validation code for VkPhysicalDevice4444FormatsFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT: { // Covers VUID-VkPhysicalDevice4444FormatsFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDevice4444FormatsFeaturesEXT *structure = (VkPhysicalDevice4444FormatsFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDevice4444FormatsFeaturesEXT", "formatA4R4G4B4", structure->formatA4R4G4B4);

                skip |= ValidateBool32("VkPhysicalDevice4444FormatsFeaturesEXT", "formatA4B4G4R4", structure->formatA4B4G4R4);
            }
        } break;

        // Validation code for VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT *structure = (VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT", "vertexInputDynamicState", structure->vertexInputDynamicState);
            }
        } break;

        // No Validation code for VkExportFenceSciSyncInfoNV structure members  -- Covers VUID-VkExportFenceSciSyncInfoNV-sType-sType

        // No Validation code for VkExportSemaphoreSciSyncInfoNV structure members  -- Covers VUID-VkExportSemaphoreSciSyncInfoNV-sType-sType

#ifdef VK_USE_PLATFORM_SCI
        // Validation code for VkPhysicalDeviceExternalSciSyncFeaturesNV structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_FEATURES_NV: { // Covers VUID-VkPhysicalDeviceExternalSciSyncFeaturesNV-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceExternalSciSyncFeaturesNV *structure = (VkPhysicalDeviceExternalSciSyncFeaturesNV *) header;
                skip |= ValidateBool32("VkPhysicalDeviceExternalSciSyncFeaturesNV", "sciSyncFence", structure->sciSyncFence);

                skip |= ValidateBool32("VkPhysicalDeviceExternalSciSyncFeaturesNV", "sciSyncSemaphore", structure->sciSyncSemaphore);

                skip |= ValidateBool32("VkPhysicalDeviceExternalSciSyncFeaturesNV", "sciSyncImport", structure->sciSyncImport);

                skip |= ValidateBool32("VkPhysicalDeviceExternalSciSyncFeaturesNV", "sciSyncExport", structure->sciSyncExport);
            }
        } break;
#endif // VK_USE_PLATFORM_SCI

        // No Validation code for VkExportMemorySciBufInfoNV structure members  -- Covers VUID-VkExportMemorySciBufInfoNV-sType-sType

#ifdef VK_USE_PLATFORM_SCI
        // Validation code for VkImportMemorySciBufInfoNV structure members
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_SCI_BUF_INFO_NV: { // Covers VUID-VkImportMemorySciBufInfoNV-sType-sType
            if (is_const_param) {
                VkImportMemorySciBufInfoNV *structure = (VkImportMemorySciBufInfoNV *) header;
                skip |= ValidateFlags("VkImportMemorySciBufInfoNV", "handleType", "VkExternalMemoryHandleTypeFlagBits", AllVkExternalMemoryHandleTypeFlagBits, structure->handleType, kRequiredSingleBit, "VUID-VkImportMemorySciBufInfoNV-handleType-parameter", "VUID-VkImportMemorySciBufInfoNV-handleType-parameter");
            }
        } break;
#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI
        // Validation code for VkPhysicalDeviceExternalMemorySciBufFeaturesNV structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCI_BUF_FEATURES_NV: { // Covers VUID-VkPhysicalDeviceExternalMemorySciBufFeaturesNV-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceExternalMemorySciBufFeaturesNV *structure = (VkPhysicalDeviceExternalMemorySciBufFeaturesNV *) header;
                skip |= ValidateBool32("VkPhysicalDeviceExternalMemorySciBufFeaturesNV", "sciBufImport", structure->sciBufImport);

                skip |= ValidateBool32("VkPhysicalDeviceExternalMemorySciBufFeaturesNV", "sciBufExport", structure->sciBufExport);
            }
        } break;
#endif // VK_USE_PLATFORM_SCI

        // Validation code for VkPhysicalDeviceExtendedDynamicState2FeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceExtendedDynamicState2FeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceExtendedDynamicState2FeaturesEXT *structure = (VkPhysicalDeviceExtendedDynamicState2FeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceExtendedDynamicState2FeaturesEXT", "extendedDynamicState2", structure->extendedDynamicState2);

                skip |= ValidateBool32("VkPhysicalDeviceExtendedDynamicState2FeaturesEXT", "extendedDynamicState2LogicOp", structure->extendedDynamicState2LogicOp);

                skip |= ValidateBool32("VkPhysicalDeviceExtendedDynamicState2FeaturesEXT", "extendedDynamicState2PatchControlPoints", structure->extendedDynamicState2PatchControlPoints);
            }
        } break;

        // Validation code for VkPhysicalDeviceColorWriteEnableFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT: { // Covers VUID-VkPhysicalDeviceColorWriteEnableFeaturesEXT-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceColorWriteEnableFeaturesEXT *structure = (VkPhysicalDeviceColorWriteEnableFeaturesEXT *) header;
                skip |= ValidateBool32("VkPhysicalDeviceColorWriteEnableFeaturesEXT", "colorWriteEnable", structure->colorWriteEnable);
            }
        } break;

        // Validation code for VkPipelineColorWriteCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT: { // Covers VUID-VkPipelineColorWriteCreateInfoEXT-sType-sType
            if (is_const_param) {
                VkPipelineColorWriteCreateInfoEXT *structure = (VkPipelineColorWriteCreateInfoEXT *) header;
                skip |= ValidateBool32Array("VkPipelineColorWriteCreateInfoEXT", "attachmentCount", "pColorWriteEnables", structure->attachmentCount, structure->pColorWriteEnables, false, true);
            }
        } break;

        // No Validation code for VkApplicationParametersEXT structure members  -- Covers VUID-VkApplicationParametersEXT-sType-sType

#ifdef VK_USE_PLATFORM_SCI
        // Validation code for VkPhysicalDeviceExternalSciSync2FeaturesNV structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_2_FEATURES_NV: { // Covers VUID-VkPhysicalDeviceExternalSciSync2FeaturesNV-sType-sType
            if (is_const_param) {
                VkPhysicalDeviceExternalSciSync2FeaturesNV *structure = (VkPhysicalDeviceExternalSciSync2FeaturesNV *) header;
                skip |= ValidateBool32("VkPhysicalDeviceExternalSciSync2FeaturesNV", "sciSyncFence", structure->sciSyncFence);

                skip |= ValidateBool32("VkPhysicalDeviceExternalSciSync2FeaturesNV", "sciSyncSemaphore2", structure->sciSyncSemaphore2);

                skip |= ValidateBool32("VkPhysicalDeviceExternalSciSync2FeaturesNV", "sciSyncImport", structure->sciSyncImport);

                skip |= ValidateBool32("VkPhysicalDeviceExternalSciSync2FeaturesNV", "sciSyncExport", structure->sciSyncExport);
            }
        } break;
#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI
        // Validation code for VkSemaphoreSciSyncCreateInfoNV structure members
        case VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_CREATE_INFO_NV: { // Covers VUID-VkSemaphoreSciSyncCreateInfoNV-sType-sType
            if (is_const_param) {
                VkSemaphoreSciSyncCreateInfoNV *structure = (VkSemaphoreSciSyncCreateInfoNV *) header;
                skip |= ValidateRequiredHandle("VkSemaphoreSciSyncCreateInfoNV", "semaphorePool", structure->semaphorePool);

                skip |= ValidateRequiredPointer("VkSemaphoreSciSyncCreateInfoNV", "pFence", structure->pFence, "VUID-VkSemaphoreSciSyncCreateInfoNV-pFence-parameter");
            }
        } break;
#endif // VK_USE_PLATFORM_SCI

        // No Validation code for VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV structure members  -- Covers VUID-VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV-sType-sType
        default:
            skip = false;
    }
    return skip;
}


bool StatelessValidation::OutputExtensionError(const std::string &api_name, const std::string &extension_name) const {
    return LogError(instance,
                    kVUID_PVError_ExtensionNotEnabled, "Attempted to call %s() but its required extension %s has not been enabled\n",
                    api_name.c_str(), extension_name.c_str());
}


bool StatelessValidation::PreCallValidateCreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateInstance", "pCreateInfo", "VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO, true, "VUID-vkCreateInstance-pCreateInfo-parameter", "VUID-VkInstanceCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkInstanceCreateInfo = { VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT, VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT, VK_STRUCTURE_TYPE_INSTANCE_LAYER_SETTINGS_EXT };

        skip |= ValidateStructPnext("vkCreateInstance", "pCreateInfo->pNext", "VkDebugUtilsMessengerCreateInfoEXT, VkValidationFeaturesEXT, VkInstanceLayerSettingsEXT", pCreateInfo->pNext, allowed_structs_VkInstanceCreateInfo.size(), allowed_structs_VkInstanceCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkInstanceCreateInfo-pNext-pNext", "VUID-VkInstanceCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags("vkCreateInstance", "pCreateInfo->flags", "VkInstanceCreateFlagBits", AllVkInstanceCreateFlagBits, pCreateInfo->flags, kOptionalFlags, kVUIDUndefined);

        skip |= ValidateStructType("vkCreateInstance", "pCreateInfo->pApplicationInfo", "VK_STRUCTURE_TYPE_APPLICATION_INFO", pCreateInfo->pApplicationInfo, VK_STRUCTURE_TYPE_APPLICATION_INFO, false, "VUID-VkInstanceCreateInfo-pApplicationInfo-parameter", "VUID-VkApplicationInfo-sType-sType");

        if (pCreateInfo->pApplicationInfo != nullptr)
        {
            constexpr std::array allowed_structs_VkApplicationInfo = { VK_STRUCTURE_TYPE_APPLICATION_PARAMETERS_EXT };

            skip |= ValidateStructPnext("vkCreateInstance", "pCreateInfo->pApplicationInfo->pNext", "VkApplicationParametersEXT", pCreateInfo->pApplicationInfo->pNext, allowed_structs_VkApplicationInfo.size(), allowed_structs_VkApplicationInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkApplicationInfo-pNext-pNext", "VUID-VkApplicationInfo-sType-unique", false, true);
        }

        skip |= ValidateStringArray("vkCreateInstance", "pCreateInfo->enabledLayerCount", "pCreateInfo->ppEnabledLayerNames", pCreateInfo->enabledLayerCount, pCreateInfo->ppEnabledLayerNames, false, true, kVUIDUndefined, "VUID-VkInstanceCreateInfo-ppEnabledLayerNames-parameter");

        skip |= ValidateStringArray("vkCreateInstance", "pCreateInfo->enabledExtensionCount", "pCreateInfo->ppEnabledExtensionNames", pCreateInfo->enabledExtensionCount, pCreateInfo->ppEnabledExtensionNames, false, true, kVUIDUndefined, "VUID-VkInstanceCreateInfo-ppEnabledExtensionNames-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateInstance-pAllocator-null", "vkCreateInstance(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateInstance", "pInstance", pInstance, "VUID-vkCreateInstance-pInstance-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateInstance(pCreateInfo, pAllocator, pInstance);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyInstance(
    VkInstance                                  instance,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyInstance-pAllocator-null", "vkDestroyInstance(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateEnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices) const {
    bool skip = false;
    skip |= ValidateArray("vkEnumeratePhysicalDevices", "pPhysicalDeviceCount", "pPhysicalDevices", pPhysicalDeviceCount, &pPhysicalDevices, true, false, false, kVUIDUndefined, "VUID-vkEnumeratePhysicalDevices-pPhysicalDevices-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures*                   pFeatures) const {
    bool skip = false;
    skip |= ValidateRequiredPointer("vkGetPhysicalDeviceFeatures", "pFeatures", pFeatures, "VUID-vkGetPhysicalDeviceFeatures-pFeatures-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties*                         pFormatProperties) const {
    bool skip = false;
    skip |= ValidateRangedEnum("vkGetPhysicalDeviceFormatProperties", "format", "VkFormat", format, "VUID-vkGetPhysicalDeviceFormatProperties-format-parameter");
    skip |= ValidateRequiredPointer("vkGetPhysicalDeviceFormatProperties", "pFormatProperties", pFormatProperties, "VUID-vkGetPhysicalDeviceFormatProperties-pFormatProperties-parameter");
    if (pFormatProperties != nullptr)
    {
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkImageFormatProperties*                    pImageFormatProperties) const {
    bool skip = false;
    skip |= ValidateRangedEnum("vkGetPhysicalDeviceImageFormatProperties", "format", "VkFormat", format, "VUID-vkGetPhysicalDeviceImageFormatProperties-format-parameter");
    skip |= ValidateRangedEnum("vkGetPhysicalDeviceImageFormatProperties", "type", "VkImageType", type, "VUID-vkGetPhysicalDeviceImageFormatProperties-type-parameter");
    skip |= ValidateRangedEnum("vkGetPhysicalDeviceImageFormatProperties", "tiling", "VkImageTiling", tiling, "VUID-vkGetPhysicalDeviceImageFormatProperties-tiling-parameter");
    skip |= ValidateFlags("vkGetPhysicalDeviceImageFormatProperties", "usage", "VkImageUsageFlagBits", AllVkImageUsageFlagBits, usage, kRequiredFlags, "VUID-vkGetPhysicalDeviceImageFormatProperties-usage-parameter", "VUID-vkGetPhysicalDeviceImageFormatProperties-usage-requiredbitmask");
    skip |= ValidateFlags("vkGetPhysicalDeviceImageFormatProperties", "flags", "VkImageCreateFlagBits", AllVkImageCreateFlagBits, flags, kOptionalFlags, "VUID-vkGetPhysicalDeviceImageFormatProperties-flags-parameter");
    skip |= ValidateRequiredPointer("vkGetPhysicalDeviceImageFormatProperties", "pImageFormatProperties", pImageFormatProperties, "VUID-vkGetPhysicalDeviceImageFormatProperties-pImageFormatProperties-parameter");
    if (pImageFormatProperties != nullptr)
    {
        // No xml-driven validation
    }
    if (!skip) skip |= manual_PreCallValidateGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties*                 pProperties) const {
    bool skip = false;
    skip |= ValidateRequiredPointer("vkGetPhysicalDeviceProperties", "pProperties", pProperties, "VUID-vkGetPhysicalDeviceProperties-pProperties-parameter");
    if (pProperties != nullptr)
    {
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties*                    pQueueFamilyProperties) const {
    bool skip = false;
    skip |= ValidateArray("vkGetPhysicalDeviceQueueFamilyProperties", "pQueueFamilyPropertyCount", "pQueueFamilyProperties", pQueueFamilyPropertyCount, &pQueueFamilyProperties, true, false, false, kVUIDUndefined, "VUID-vkGetPhysicalDeviceQueueFamilyProperties-pQueueFamilyProperties-parameter");
    if (pQueueFamilyProperties != nullptr)
    {
        for (uint32_t pQueueFamilyPropertyIndex = 0; pQueueFamilyPropertyIndex < *pQueueFamilyPropertyCount; ++pQueueFamilyPropertyIndex)
        {
            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties*           pMemoryProperties) const {
    bool skip = false;
    skip |= ValidateRequiredPointer("vkGetPhysicalDeviceMemoryProperties", "pMemoryProperties", pMemoryProperties, "VUID-vkGetPhysicalDeviceMemoryProperties-pMemoryProperties-parameter");
    if (pMemoryProperties != nullptr)
    {
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateDevice", "pCreateInfo", "VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO, true, "VUID-vkCreateDevice-pCreateInfo-parameter", "VUID-VkDeviceCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkDeviceCreateInfo = { VK_STRUCTURE_TYPE_APPLICATION_PARAMETERS_EXT, VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO, VK_STRUCTURE_TYPE_DEVICE_OBJECT_RESERVATION_CREATE_INFO, VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO, VK_STRUCTURE_TYPE_DEVICE_SEMAPHORE_SCI_SYNC_POOL_RESERVATION_CREATE_INFO_NV, VK_STRUCTURE_TYPE_FAULT_CALLBACK_INFO, VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_RESERVATION_INFO_KHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCI_BUF_FEATURES_NV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_2_FEATURES_NV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_FEATURES_NV, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES };

        skip |= ValidateStructPnext("vkCreateDevice", "pCreateInfo->pNext", "VkApplicationParametersEXT, VkDeviceGroupDeviceCreateInfo, VkDeviceObjectReservationCreateInfo, VkDevicePrivateDataCreateInfo, VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV, VkFaultCallbackInfo, VkPerformanceQueryReservationInfoKHR, VkPhysicalDevice16BitStorageFeatures, VkPhysicalDevice4444FormatsFeaturesEXT, VkPhysicalDevice8BitStorageFeatures, VkPhysicalDeviceASTCDecodeFeaturesEXT, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT, VkPhysicalDeviceBufferDeviceAddressFeatures, VkPhysicalDeviceColorWriteEnableFeaturesEXT, VkPhysicalDeviceCustomBorderColorFeaturesEXT, VkPhysicalDeviceDepthClipEnableFeaturesEXT, VkPhysicalDeviceDescriptorIndexingFeatures, VkPhysicalDeviceDynamicRenderingFeatures, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT, VkPhysicalDeviceExternalMemorySciBufFeaturesNV, VkPhysicalDeviceExternalSciSync2FeaturesNV, VkPhysicalDeviceExternalSciSyncFeaturesNV, VkPhysicalDeviceFeatures2, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT, VkPhysicalDeviceFragmentShadingRateFeaturesKHR, VkPhysicalDeviceHostQueryResetFeatures, VkPhysicalDeviceImageRobustnessFeatures, VkPhysicalDeviceImagelessFramebufferFeatures, VkPhysicalDeviceIndexTypeUint8FeaturesEXT, VkPhysicalDeviceInlineUniformBlockFeatures, VkPhysicalDeviceLineRasterizationFeaturesEXT, VkPhysicalDeviceMaintenance4Features, VkPhysicalDeviceMultiviewFeatures, VkPhysicalDevicePerformanceQueryFeaturesKHR, VkPhysicalDevicePipelineCreationCacheControlFeatures, VkPhysicalDevicePrivateDataFeatures, VkPhysicalDeviceProtectedMemoryFeatures, VkPhysicalDeviceRobustness2FeaturesEXT, VkPhysicalDeviceSamplerYcbcrConversionFeatures, VkPhysicalDeviceScalarBlockLayoutFeatures, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT, VkPhysicalDeviceShaderAtomicInt64Features, VkPhysicalDeviceShaderClockFeaturesKHR, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures, VkPhysicalDeviceShaderDrawParametersFeatures, VkPhysicalDeviceShaderFloat16Int8Features, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT, VkPhysicalDeviceShaderIntegerDotProductFeatures, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures, VkPhysicalDeviceShaderTerminateInvocationFeatures, VkPhysicalDeviceSubgroupSizeControlFeatures, VkPhysicalDeviceSynchronization2Features, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT, VkPhysicalDeviceTextureCompressionASTCHDRFeatures, VkPhysicalDeviceTimelineSemaphoreFeatures, VkPhysicalDeviceUniformBufferStandardLayoutFeatures, VkPhysicalDeviceVariablePointersFeatures, VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT, VkPhysicalDeviceVulkan11Features, VkPhysicalDeviceVulkan12Features, VkPhysicalDeviceVulkan13Features, VkPhysicalDeviceVulkanMemoryModelFeatures, VkPhysicalDeviceVulkanSC10Features, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures", pCreateInfo->pNext, allowed_structs_VkDeviceCreateInfo.size(), allowed_structs_VkDeviceCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkDeviceCreateInfo-pNext-pNext", "VUID-VkDeviceCreateInfo-sType-unique", true, true);

        skip |= ValidateReservedFlags("vkCreateDevice", "pCreateInfo->flags", pCreateInfo->flags, "VUID-VkDeviceCreateInfo-flags-zerobitmask");

        skip |= ValidateStructTypeArray("vkCreateDevice", "pCreateInfo->queueCreateInfoCount", "pCreateInfo->pQueueCreateInfos", "VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO", pCreateInfo->queueCreateInfoCount, pCreateInfo->pQueueCreateInfos, VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO, true, true, "VUID-VkDeviceQueueCreateInfo-sType-sType", "VUID-VkDeviceCreateInfo-pQueueCreateInfos-parameter", "VUID-VkDeviceCreateInfo-queueCreateInfoCount-arraylength");

        if (pCreateInfo->pQueueCreateInfos != nullptr)
        {
            for (uint32_t queueCreateInfoIndex = 0; queueCreateInfoIndex < pCreateInfo->queueCreateInfoCount; ++queueCreateInfoIndex)
            {
                constexpr std::array allowed_structs_VkDeviceQueueCreateInfo = { VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR };

                skip |= ValidateStructPnext("vkCreateDevice", ParameterName("pCreateInfo->pQueueCreateInfos[%i].pNext", ParameterName::IndexVector{ queueCreateInfoIndex }), "VkDeviceQueueGlobalPriorityCreateInfoKHR", pCreateInfo->pQueueCreateInfos[queueCreateInfoIndex].pNext, allowed_structs_VkDeviceQueueCreateInfo.size(), allowed_structs_VkDeviceQueueCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkDeviceQueueCreateInfo-pNext-pNext", "VUID-VkDeviceQueueCreateInfo-sType-unique", true, true);

                skip |= ValidateFlags("vkCreateDevice", ParameterName("pCreateInfo->pQueueCreateInfos[%i].flags", ParameterName::IndexVector{ queueCreateInfoIndex }), "VkDeviceQueueCreateFlagBits", AllVkDeviceQueueCreateFlagBits, pCreateInfo->pQueueCreateInfos[queueCreateInfoIndex].flags, kOptionalFlags, "VUID-VkDeviceQueueCreateInfo-flags-parameter");

                skip |= ValidateArray("vkCreateDevice", ParameterName("pCreateInfo->pQueueCreateInfos[%i].queueCount", ParameterName::IndexVector{ queueCreateInfoIndex }), ParameterName("pCreateInfo->pQueueCreateInfos[%i].pQueuePriorities", ParameterName::IndexVector{ queueCreateInfoIndex }), pCreateInfo->pQueueCreateInfos[queueCreateInfoIndex].queueCount, &pCreateInfo->pQueueCreateInfos[queueCreateInfoIndex].pQueuePriorities, true, true, "VUID-VkDeviceQueueCreateInfo-queueCount-arraylength", "VUID-VkDeviceQueueCreateInfo-pQueuePriorities-parameter");
            }
        }

        skip |= ValidateStringArray("vkCreateDevice", "pCreateInfo->enabledLayerCount", "pCreateInfo->ppEnabledLayerNames", pCreateInfo->enabledLayerCount, pCreateInfo->ppEnabledLayerNames, false, true, kVUIDUndefined, "VUID-VkDeviceCreateInfo-ppEnabledLayerNames-parameter");

        skip |= ValidateStringArray("vkCreateDevice", "pCreateInfo->enabledExtensionCount", "pCreateInfo->ppEnabledExtensionNames", pCreateInfo->enabledExtensionCount, pCreateInfo->ppEnabledExtensionNames, false, true, kVUIDUndefined, "VUID-VkDeviceCreateInfo-ppEnabledExtensionNames-parameter");

        if (pCreateInfo->pEnabledFeatures != nullptr)
        {
            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->robustBufferAccess", pCreateInfo->pEnabledFeatures->robustBufferAccess);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->fullDrawIndexUint32", pCreateInfo->pEnabledFeatures->fullDrawIndexUint32);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->imageCubeArray", pCreateInfo->pEnabledFeatures->imageCubeArray);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->independentBlend", pCreateInfo->pEnabledFeatures->independentBlend);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->geometryShader", pCreateInfo->pEnabledFeatures->geometryShader);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->tessellationShader", pCreateInfo->pEnabledFeatures->tessellationShader);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->sampleRateShading", pCreateInfo->pEnabledFeatures->sampleRateShading);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->dualSrcBlend", pCreateInfo->pEnabledFeatures->dualSrcBlend);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->logicOp", pCreateInfo->pEnabledFeatures->logicOp);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->multiDrawIndirect", pCreateInfo->pEnabledFeatures->multiDrawIndirect);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->drawIndirectFirstInstance", pCreateInfo->pEnabledFeatures->drawIndirectFirstInstance);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->depthClamp", pCreateInfo->pEnabledFeatures->depthClamp);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->depthBiasClamp", pCreateInfo->pEnabledFeatures->depthBiasClamp);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->fillModeNonSolid", pCreateInfo->pEnabledFeatures->fillModeNonSolid);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->depthBounds", pCreateInfo->pEnabledFeatures->depthBounds);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->wideLines", pCreateInfo->pEnabledFeatures->wideLines);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->largePoints", pCreateInfo->pEnabledFeatures->largePoints);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->alphaToOne", pCreateInfo->pEnabledFeatures->alphaToOne);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->multiViewport", pCreateInfo->pEnabledFeatures->multiViewport);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->samplerAnisotropy", pCreateInfo->pEnabledFeatures->samplerAnisotropy);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->textureCompressionETC2", pCreateInfo->pEnabledFeatures->textureCompressionETC2);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->textureCompressionASTC_LDR", pCreateInfo->pEnabledFeatures->textureCompressionASTC_LDR);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->textureCompressionBC", pCreateInfo->pEnabledFeatures->textureCompressionBC);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->occlusionQueryPrecise", pCreateInfo->pEnabledFeatures->occlusionQueryPrecise);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->pipelineStatisticsQuery", pCreateInfo->pEnabledFeatures->pipelineStatisticsQuery);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->vertexPipelineStoresAndAtomics", pCreateInfo->pEnabledFeatures->vertexPipelineStoresAndAtomics);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->fragmentStoresAndAtomics", pCreateInfo->pEnabledFeatures->fragmentStoresAndAtomics);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderTessellationAndGeometryPointSize", pCreateInfo->pEnabledFeatures->shaderTessellationAndGeometryPointSize);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderImageGatherExtended", pCreateInfo->pEnabledFeatures->shaderImageGatherExtended);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderStorageImageExtendedFormats", pCreateInfo->pEnabledFeatures->shaderStorageImageExtendedFormats);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderStorageImageMultisample", pCreateInfo->pEnabledFeatures->shaderStorageImageMultisample);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderStorageImageReadWithoutFormat", pCreateInfo->pEnabledFeatures->shaderStorageImageReadWithoutFormat);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderStorageImageWriteWithoutFormat", pCreateInfo->pEnabledFeatures->shaderStorageImageWriteWithoutFormat);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderUniformBufferArrayDynamicIndexing", pCreateInfo->pEnabledFeatures->shaderUniformBufferArrayDynamicIndexing);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderSampledImageArrayDynamicIndexing", pCreateInfo->pEnabledFeatures->shaderSampledImageArrayDynamicIndexing);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderStorageBufferArrayDynamicIndexing", pCreateInfo->pEnabledFeatures->shaderStorageBufferArrayDynamicIndexing);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderStorageImageArrayDynamicIndexing", pCreateInfo->pEnabledFeatures->shaderStorageImageArrayDynamicIndexing);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderClipDistance", pCreateInfo->pEnabledFeatures->shaderClipDistance);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderCullDistance", pCreateInfo->pEnabledFeatures->shaderCullDistance);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderFloat64", pCreateInfo->pEnabledFeatures->shaderFloat64);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderInt64", pCreateInfo->pEnabledFeatures->shaderInt64);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderInt16", pCreateInfo->pEnabledFeatures->shaderInt16);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderResourceResidency", pCreateInfo->pEnabledFeatures->shaderResourceResidency);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->shaderResourceMinLod", pCreateInfo->pEnabledFeatures->shaderResourceMinLod);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->sparseBinding", pCreateInfo->pEnabledFeatures->sparseBinding);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->sparseResidencyBuffer", pCreateInfo->pEnabledFeatures->sparseResidencyBuffer);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->sparseResidencyImage2D", pCreateInfo->pEnabledFeatures->sparseResidencyImage2D);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->sparseResidencyImage3D", pCreateInfo->pEnabledFeatures->sparseResidencyImage3D);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->sparseResidency2Samples", pCreateInfo->pEnabledFeatures->sparseResidency2Samples);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->sparseResidency4Samples", pCreateInfo->pEnabledFeatures->sparseResidency4Samples);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->sparseResidency8Samples", pCreateInfo->pEnabledFeatures->sparseResidency8Samples);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->sparseResidency16Samples", pCreateInfo->pEnabledFeatures->sparseResidency16Samples);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->sparseResidencyAliased", pCreateInfo->pEnabledFeatures->sparseResidencyAliased);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->variableMultisampleRate", pCreateInfo->pEnabledFeatures->variableMultisampleRate);

            skip |= ValidateBool32("vkCreateDevice", "pCreateInfo->pEnabledFeatures->inheritedQueries", pCreateInfo->pEnabledFeatures->inheritedQueries);
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateDevice-pAllocator-null", "vkCreateDevice(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateDevice", "pDevice", pDevice, "VUID-vkCreateDevice-pDevice-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyDevice(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyDevice-pAllocator-null", "vkDestroyDevice(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceQueue(
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    VkQueue*                                    pQueue) const {
    bool skip = false;
    skip |= ValidateRequiredPointer("vkGetDeviceQueue", "pQueue", pQueue, "VUID-vkGetDeviceQueue-pQueue-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateQueueSubmit(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo*                         pSubmits,
    VkFence                                     fence) const {
    bool skip = false;
    skip |= ValidateStructTypeArray("vkQueueSubmit", "submitCount", "pSubmits", "VK_STRUCTURE_TYPE_SUBMIT_INFO", submitCount, pSubmits, VK_STRUCTURE_TYPE_SUBMIT_INFO, false, true, "VUID-VkSubmitInfo-sType-sType", "VUID-vkQueueSubmit-pSubmits-parameter", kVUIDUndefined);
    if (pSubmits != nullptr)
    {
        for (uint32_t submitIndex = 0; submitIndex < submitCount; ++submitIndex)
        {
            constexpr std::array allowed_structs_VkSubmitInfo = { VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO, VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR, VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO, VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO };

            skip |= ValidateStructPnext("vkQueueSubmit", ParameterName("pSubmits[%i].pNext", ParameterName::IndexVector{ submitIndex }), "VkDeviceGroupSubmitInfo, VkPerformanceQuerySubmitInfoKHR, VkProtectedSubmitInfo, VkTimelineSemaphoreSubmitInfo", pSubmits[submitIndex].pNext, allowed_structs_VkSubmitInfo.size(), allowed_structs_VkSubmitInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkSubmitInfo-pNext-pNext", "VUID-VkSubmitInfo-sType-unique", false, true);

            skip |= ValidateArray("vkQueueSubmit", ParameterName("pSubmits[%i].waitSemaphoreCount", ParameterName::IndexVector{ submitIndex }), ParameterName("pSubmits[%i].pWaitSemaphores", ParameterName::IndexVector{ submitIndex }), pSubmits[submitIndex].waitSemaphoreCount, &pSubmits[submitIndex].pWaitSemaphores, false, true, kVUIDUndefined, "VUID-VkSubmitInfo-pWaitSemaphores-parameter");

            skip |= ValidateFlagsArray("VkSubmitInfo", ParameterName("pSubmits[%i].waitSemaphoreCount", ParameterName::IndexVector{ submitIndex }), ParameterName("pSubmits[%i].pWaitDstStageMask", ParameterName::IndexVector{ submitIndex }), "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, pSubmits[submitIndex].waitSemaphoreCount, pSubmits[submitIndex].pWaitDstStageMask, false, "VUID-VkSubmitInfo-pWaitDstStageMask-parameter");

            skip |= ValidateArray("vkQueueSubmit", ParameterName("pSubmits[%i].commandBufferCount", ParameterName::IndexVector{ submitIndex }), ParameterName("pSubmits[%i].pCommandBuffers", ParameterName::IndexVector{ submitIndex }), pSubmits[submitIndex].commandBufferCount, &pSubmits[submitIndex].pCommandBuffers, false, true, kVUIDUndefined, "VUID-VkSubmitInfo-pCommandBuffers-parameter");

            skip |= ValidateArray("vkQueueSubmit", ParameterName("pSubmits[%i].signalSemaphoreCount", ParameterName::IndexVector{ submitIndex }), ParameterName("pSubmits[%i].pSignalSemaphores", ParameterName::IndexVector{ submitIndex }), pSubmits[submitIndex].signalSemaphoreCount, &pSubmits[submitIndex].pSignalSemaphores, false, true, kVUIDUndefined, "VUID-VkSubmitInfo-pSignalSemaphores-parameter");
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateQueueWaitIdle(
    VkQueue                                     queue) const {
    bool skip = false;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateDeviceWaitIdle(
    VkDevice                                    device) const {
    bool skip = false;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateAllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDeviceMemory*                             pMemory) const {
    bool skip = false;
    skip |= ValidateStructType("vkAllocateMemory", "pAllocateInfo", "VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO", pAllocateInfo, VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, true, "VUID-vkAllocateMemory-pAllocateInfo-parameter", "VUID-VkMemoryAllocateInfo-sType-sType");
    if (pAllocateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkMemoryAllocateInfo = { VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO, VK_STRUCTURE_TYPE_EXPORT_MEMORY_SCI_BUF_INFO_NV, VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR, VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT, VK_STRUCTURE_TYPE_IMPORT_MEMORY_SCI_BUF_INFO_NV, VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO, VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO, VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO };

        skip |= ValidateStructPnext("vkAllocateMemory", "pAllocateInfo->pNext", "VkExportMemoryAllocateInfo, VkExportMemorySciBufInfoNV, VkImportMemoryFdInfoKHR, VkImportMemoryHostPointerInfoEXT, VkImportMemorySciBufInfoNV, VkMemoryAllocateFlagsInfo, VkMemoryDedicatedAllocateInfo, VkMemoryOpaqueCaptureAddressAllocateInfo", pAllocateInfo->pNext, allowed_structs_VkMemoryAllocateInfo.size(), allowed_structs_VkMemoryAllocateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkMemoryAllocateInfo-pNext-pNext", "VUID-VkMemoryAllocateInfo-sType-unique", false, true);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkAllocateMemory-pAllocator-null", "vkAllocateMemory(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkAllocateMemory", "pMemory", pMemory, "VUID-vkAllocateMemory-pMemory-parameter");
    if (!skip) skip |= manual_PreCallValidateAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    return skip;
}

bool StatelessValidation::PreCallValidateMapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    void**                                      ppData) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkMapMemory", "memory", memory);
    skip |= ValidateReservedFlags("vkMapMemory", "flags", flags, "VUID-vkMapMemory-flags-zerobitmask");
    return skip;
}

bool StatelessValidation::PreCallValidateUnmapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkUnmapMemory", "memory", memory);
    return skip;
}

bool StatelessValidation::PreCallValidateFlushMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges) const {
    bool skip = false;
    skip |= ValidateStructTypeArray("vkFlushMappedMemoryRanges", "memoryRangeCount", "pMemoryRanges", "VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE", memoryRangeCount, pMemoryRanges, VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE, true, true, "VUID-VkMappedMemoryRange-sType-sType", "VUID-vkFlushMappedMemoryRanges-pMemoryRanges-parameter", "VUID-vkFlushMappedMemoryRanges-memoryRangeCount-arraylength");
    if (pMemoryRanges != nullptr)
    {
        for (uint32_t memoryRangeIndex = 0; memoryRangeIndex < memoryRangeCount; ++memoryRangeIndex)
        {
            skip |= ValidateStructPnext("vkFlushMappedMemoryRanges", ParameterName("pMemoryRanges[%i].pNext", ParameterName::IndexVector{ memoryRangeIndex }), nullptr, pMemoryRanges[memoryRangeIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkMappedMemoryRange-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateRequiredHandle("vkFlushMappedMemoryRanges", ParameterName("pMemoryRanges[%i].memory", ParameterName::IndexVector{ memoryRangeIndex }), pMemoryRanges[memoryRangeIndex].memory);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateInvalidateMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges) const {
    bool skip = false;
    skip |= ValidateStructTypeArray("vkInvalidateMappedMemoryRanges", "memoryRangeCount", "pMemoryRanges", "VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE", memoryRangeCount, pMemoryRanges, VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE, true, true, "VUID-VkMappedMemoryRange-sType-sType", "VUID-vkInvalidateMappedMemoryRanges-pMemoryRanges-parameter", "VUID-vkInvalidateMappedMemoryRanges-memoryRangeCount-arraylength");
    if (pMemoryRanges != nullptr)
    {
        for (uint32_t memoryRangeIndex = 0; memoryRangeIndex < memoryRangeCount; ++memoryRangeIndex)
        {
            skip |= ValidateStructPnext("vkInvalidateMappedMemoryRanges", ParameterName("pMemoryRanges[%i].pNext", ParameterName::IndexVector{ memoryRangeIndex }), nullptr, pMemoryRanges[memoryRangeIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkMappedMemoryRange-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateRequiredHandle("vkInvalidateMappedMemoryRanges", ParameterName("pMemoryRanges[%i].memory", ParameterName::IndexVector{ memoryRangeIndex }), pMemoryRanges[memoryRangeIndex].memory);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceMemoryCommitment(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize*                               pCommittedMemoryInBytes) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkGetDeviceMemoryCommitment", "memory", memory);
    skip |= ValidateRequiredPointer("vkGetDeviceMemoryCommitment", "pCommittedMemoryInBytes", pCommittedMemoryInBytes, "VUID-vkGetDeviceMemoryCommitment-pCommittedMemoryInBytes-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateBindBufferMemory(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkBindBufferMemory", "buffer", buffer);
    skip |= ValidateRequiredHandle("vkBindBufferMemory", "memory", memory);
    return skip;
}

bool StatelessValidation::PreCallValidateBindImageMemory(
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkBindImageMemory", "image", image);
    skip |= ValidateRequiredHandle("vkBindImageMemory", "memory", memory);
    return skip;
}

bool StatelessValidation::PreCallValidateGetBufferMemoryRequirements(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkMemoryRequirements*                       pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkGetBufferMemoryRequirements", "buffer", buffer);
    skip |= ValidateRequiredPointer("vkGetBufferMemoryRequirements", "pMemoryRequirements", pMemoryRequirements, "VUID-vkGetBufferMemoryRequirements-pMemoryRequirements-parameter");
    if (pMemoryRequirements != nullptr)
    {
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetImageMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    VkMemoryRequirements*                       pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkGetImageMemoryRequirements", "image", image);
    skip |= ValidateRequiredPointer("vkGetImageMemoryRequirements", "pMemoryRequirements", pMemoryRequirements, "VUID-vkGetImageMemoryRequirements-pMemoryRequirements-parameter");
    if (pMemoryRequirements != nullptr)
    {
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateFence", "pCreateInfo", "VK_STRUCTURE_TYPE_FENCE_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, true, "VUID-vkCreateFence-pCreateInfo-parameter", "VUID-VkFenceCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkFenceCreateInfo = { VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO, VK_STRUCTURE_TYPE_EXPORT_FENCE_SCI_SYNC_INFO_NV };

        skip |= ValidateStructPnext("vkCreateFence", "pCreateInfo->pNext", "VkExportFenceCreateInfo, VkExportFenceSciSyncInfoNV", pCreateInfo->pNext, allowed_structs_VkFenceCreateInfo.size(), allowed_structs_VkFenceCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkFenceCreateInfo-pNext-pNext", "VUID-VkFenceCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags("vkCreateFence", "pCreateInfo->flags", "VkFenceCreateFlagBits", AllVkFenceCreateFlagBits, pCreateInfo->flags, kOptionalFlags, "VUID-VkFenceCreateInfo-flags-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateFence-pAllocator-null", "vkCreateFence(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateFence", "pFence", pFence, "VUID-vkCreateFence-pFence-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyFence(
    VkDevice                                    device,
    VkFence                                     fence,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyFence-pAllocator-null", "vkDestroyFence(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateResetFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences) const {
    bool skip = false;
    skip |= ValidateHandleArray("vkResetFences", "fenceCount", "pFences", fenceCount, pFences, true, true, "VUID-vkResetFences-fenceCount-arraylength");
    return skip;
}

bool StatelessValidation::PreCallValidateGetFenceStatus(
    VkDevice                                    device,
    VkFence                                     fence) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkGetFenceStatus", "fence", fence);
    return skip;
}

bool StatelessValidation::PreCallValidateWaitForFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout) const {
    bool skip = false;
    skip |= ValidateHandleArray("vkWaitForFences", "fenceCount", "pFences", fenceCount, pFences, true, true, "VUID-vkWaitForFences-fenceCount-arraylength");
    skip |= ValidateBool32("vkWaitForFences", "waitAll", waitAll);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphore*                                pSemaphore) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateSemaphore", "pCreateInfo", "VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO, true, "VUID-vkCreateSemaphore-pCreateInfo-parameter", "VUID-VkSemaphoreCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkSemaphoreCreateInfo = { VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO, VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_SCI_SYNC_INFO_NV, VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_CREATE_INFO_NV, VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO };

        skip |= ValidateStructPnext("vkCreateSemaphore", "pCreateInfo->pNext", "VkExportSemaphoreCreateInfo, VkExportSemaphoreSciSyncInfoNV, VkSemaphoreSciSyncCreateInfoNV, VkSemaphoreTypeCreateInfo", pCreateInfo->pNext, allowed_structs_VkSemaphoreCreateInfo.size(), allowed_structs_VkSemaphoreCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkSemaphoreCreateInfo-pNext-pNext", "VUID-VkSemaphoreCreateInfo-sType-unique", false, true);

        skip |= ValidateReservedFlags("vkCreateSemaphore", "pCreateInfo->flags", pCreateInfo->flags, "VUID-VkSemaphoreCreateInfo-flags-zerobitmask");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateSemaphore-pAllocator-null", "vkCreateSemaphore(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateSemaphore", "pSemaphore", pSemaphore, "VUID-vkCreateSemaphore-pSemaphore-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroySemaphore-pAllocator-null", "vkDestroySemaphore(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkEvent*                                    pEvent) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateEvent", "pCreateInfo", "VK_STRUCTURE_TYPE_EVENT_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_EVENT_CREATE_INFO, true, "VUID-vkCreateEvent-pCreateInfo-parameter", "VUID-VkEventCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCreateEvent", "pCreateInfo->pNext", nullptr, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkEventCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags("vkCreateEvent", "pCreateInfo->flags", "VkEventCreateFlagBits", AllVkEventCreateFlagBits, pCreateInfo->flags, kOptionalFlags, "VUID-VkEventCreateInfo-flags-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateEvent-pAllocator-null", "vkCreateEvent(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateEvent", "pEvent", pEvent, "VUID-vkCreateEvent-pEvent-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateEvent(device, pCreateInfo, pAllocator, pEvent);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyEvent-pAllocator-null", "vkDestroyEvent(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetEventStatus(
    VkDevice                                    device,
    VkEvent                                     event) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkGetEventStatus", "event", event);
    return skip;
}

bool StatelessValidation::PreCallValidateSetEvent(
    VkDevice                                    device,
    VkEvent                                     event) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkSetEvent", "event", event);
    return skip;
}

bool StatelessValidation::PreCallValidateResetEvent(
    VkDevice                                    device,
    VkEvent                                     event) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkResetEvent", "event", event);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkQueryPool*                                pQueryPool) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateQueryPool", "pCreateInfo", "VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO, true, "VUID-vkCreateQueryPool-pCreateInfo-parameter", "VUID-VkQueryPoolCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkQueryPoolCreateInfo = { VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR };

        skip |= ValidateStructPnext("vkCreateQueryPool", "pCreateInfo->pNext", "VkQueryPoolPerformanceCreateInfoKHR", pCreateInfo->pNext, allowed_structs_VkQueryPoolCreateInfo.size(), allowed_structs_VkQueryPoolCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkQueryPoolCreateInfo-pNext-pNext", "VUID-VkQueryPoolCreateInfo-sType-unique", false, true);

        skip |= ValidateReservedFlags("vkCreateQueryPool", "pCreateInfo->flags", pCreateInfo->flags, "VUID-VkQueryPoolCreateInfo-flags-zerobitmask");

        skip |= ValidateRangedEnum("vkCreateQueryPool", "pCreateInfo->queryType", "VkQueryType", pCreateInfo->queryType, "VUID-VkQueryPoolCreateInfo-queryType-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateQueryPool-pAllocator-null", "vkCreateQueryPool(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateQueryPool", "pQueryPool", pQueryPool, "VUID-vkCreateQueryPool-pQueryPool-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    return skip;
}

bool StatelessValidation::PreCallValidateGetQueryPoolResults(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    void*                                       pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkGetQueryPoolResults", "queryPool", queryPool);
    skip |= ValidateArray("vkGetQueryPoolResults", "dataSize", "pData", dataSize, &pData, true, true, "VUID-vkGetQueryPoolResults-dataSize-arraylength", "VUID-vkGetQueryPoolResults-pData-parameter");
    skip |= ValidateFlags("vkGetQueryPoolResults", "flags", "VkQueryResultFlagBits", AllVkQueryResultFlagBits, flags, kOptionalFlags, "VUID-vkGetQueryPoolResults-flags-parameter");
    if (!skip) skip |= manual_PreCallValidateGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBuffer*                                   pBuffer) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateBuffer", "pCreateInfo", "VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO, true, "VUID-vkCreateBuffer-pCreateInfo-parameter", "VUID-VkBufferCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkBufferCreateInfo = { VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO };

        skip |= ValidateStructPnext("vkCreateBuffer", "pCreateInfo->pNext", "VkBufferOpaqueCaptureAddressCreateInfo, VkExternalMemoryBufferCreateInfo", pCreateInfo->pNext, allowed_structs_VkBufferCreateInfo.size(), allowed_structs_VkBufferCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkBufferCreateInfo-pNext-pNext", "VUID-VkBufferCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags("vkCreateBuffer", "pCreateInfo->flags", "VkBufferCreateFlagBits", AllVkBufferCreateFlagBits, pCreateInfo->flags, kOptionalFlags, "VUID-VkBufferCreateInfo-flags-parameter");

        skip |= ValidateFlags("vkCreateBuffer", "pCreateInfo->usage", "VkBufferUsageFlagBits", AllVkBufferUsageFlagBits, pCreateInfo->usage, kRequiredFlags, "VUID-VkBufferCreateInfo-usage-parameter", "VUID-VkBufferCreateInfo-usage-requiredbitmask");

        skip |= ValidateRangedEnum("vkCreateBuffer", "pCreateInfo->sharingMode", "VkSharingMode", pCreateInfo->sharingMode, "VUID-VkBufferCreateInfo-sharingMode-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateBuffer-pAllocator-null", "vkCreateBuffer(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateBuffer", "pBuffer", pBuffer, "VUID-vkCreateBuffer-pBuffer-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyBuffer-pAllocator-null", "vkDestroyBuffer(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferView*                               pView) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateBufferView", "pCreateInfo", "VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO, true, "VUID-vkCreateBufferView-pCreateInfo-parameter", "VUID-VkBufferViewCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCreateBufferView", "pCreateInfo->pNext", nullptr, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferViewCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags("vkCreateBufferView", "pCreateInfo->flags", pCreateInfo->flags, "VUID-VkBufferViewCreateInfo-flags-zerobitmask");

        skip |= ValidateRequiredHandle("vkCreateBufferView", "pCreateInfo->buffer", pCreateInfo->buffer);

        skip |= ValidateRangedEnum("vkCreateBufferView", "pCreateInfo->format", "VkFormat", pCreateInfo->format, "VUID-VkBufferViewCreateInfo-format-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateBufferView-pAllocator-null", "vkCreateBufferView(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateBufferView", "pView", pView, "VUID-vkCreateBufferView-pView-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateBufferView(device, pCreateInfo, pAllocator, pView);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyBufferView-pAllocator-null", "vkDestroyBufferView(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImage*                                    pImage) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateImage", "pCreateInfo", "VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO, true, "VUID-vkCreateImage-pCreateInfo-parameter", "VUID-VkImageCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkImageCreateInfo = { VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT, VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO, VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO, VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR };

        skip |= ValidateStructPnext("vkCreateImage", "pCreateInfo->pNext", "VkExternalMemoryImageCreateInfo, VkImageDrmFormatModifierExplicitCreateInfoEXT, VkImageDrmFormatModifierListCreateInfoEXT, VkImageFormatListCreateInfo, VkImageStencilUsageCreateInfo, VkImageSwapchainCreateInfoKHR", pCreateInfo->pNext, allowed_structs_VkImageCreateInfo.size(), allowed_structs_VkImageCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageCreateInfo-pNext-pNext", "VUID-VkImageCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags("vkCreateImage", "pCreateInfo->flags", "VkImageCreateFlagBits", AllVkImageCreateFlagBits, pCreateInfo->flags, kOptionalFlags, "VUID-VkImageCreateInfo-flags-parameter");

        skip |= ValidateRangedEnum("vkCreateImage", "pCreateInfo->imageType", "VkImageType", pCreateInfo->imageType, "VUID-VkImageCreateInfo-imageType-parameter");

        skip |= ValidateRangedEnum("vkCreateImage", "pCreateInfo->format", "VkFormat", pCreateInfo->format, "VUID-VkImageCreateInfo-format-parameter");

        // No xml-driven validation

        skip |= ValidateFlags("vkCreateImage", "pCreateInfo->samples", "VkSampleCountFlagBits", AllVkSampleCountFlagBits, pCreateInfo->samples, kRequiredSingleBit, "VUID-VkImageCreateInfo-samples-parameter", "VUID-VkImageCreateInfo-samples-parameter");

        skip |= ValidateRangedEnum("vkCreateImage", "pCreateInfo->tiling", "VkImageTiling", pCreateInfo->tiling, "VUID-VkImageCreateInfo-tiling-parameter");

        skip |= ValidateFlags("vkCreateImage", "pCreateInfo->usage", "VkImageUsageFlagBits", AllVkImageUsageFlagBits, pCreateInfo->usage, kRequiredFlags, "VUID-VkImageCreateInfo-usage-parameter", "VUID-VkImageCreateInfo-usage-requiredbitmask");

        skip |= ValidateRangedEnum("vkCreateImage", "pCreateInfo->sharingMode", "VkSharingMode", pCreateInfo->sharingMode, "VUID-VkImageCreateInfo-sharingMode-parameter");

        skip |= ValidateRangedEnum("vkCreateImage", "pCreateInfo->initialLayout", "VkImageLayout", pCreateInfo->initialLayout, "VUID-VkImageCreateInfo-initialLayout-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateImage-pAllocator-null", "vkCreateImage(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateImage", "pImage", pImage, "VUID-vkCreateImage-pImage-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateImage(device, pCreateInfo, pAllocator, pImage);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyImage(
    VkDevice                                    device,
    VkImage                                     image,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyImage-pAllocator-null", "vkDestroyImage(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetImageSubresourceLayout(
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource*                   pSubresource,
    VkSubresourceLayout*                        pLayout) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkGetImageSubresourceLayout", "image", image);
    skip |= ValidateRequiredPointer("vkGetImageSubresourceLayout", "pSubresource", pSubresource, "VUID-vkGetImageSubresourceLayout-pSubresource-parameter");
    if (pSubresource != nullptr)
    {
        skip |= ValidateFlags("vkGetImageSubresourceLayout", "pSubresource->aspectMask", "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pSubresource->aspectMask, kRequiredFlags, "VUID-VkImageSubresource-aspectMask-parameter", "VUID-VkImageSubresource-aspectMask-requiredbitmask");
    }
    skip |= ValidateRequiredPointer("vkGetImageSubresourceLayout", "pLayout", pLayout, "VUID-vkGetImageSubresourceLayout-pLayout-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImageView*                                pView) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateImageView", "pCreateInfo", "VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO, true, "VUID-vkCreateImageView-pCreateInfo-parameter", "VUID-VkImageViewCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkImageViewCreateInfo = { VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT, VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO };

        skip |= ValidateStructPnext("vkCreateImageView", "pCreateInfo->pNext", "VkImageViewASTCDecodeModeEXT, VkImageViewUsageCreateInfo, VkSamplerYcbcrConversionInfo", pCreateInfo->pNext, allowed_structs_VkImageViewCreateInfo.size(), allowed_structs_VkImageViewCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageViewCreateInfo-pNext-pNext", "VUID-VkImageViewCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags("vkCreateImageView", "pCreateInfo->flags", "VkImageViewCreateFlagBits", AllVkImageViewCreateFlagBits, pCreateInfo->flags, kOptionalFlags, kVUIDUndefined);

        skip |= ValidateRequiredHandle("vkCreateImageView", "pCreateInfo->image", pCreateInfo->image);

        skip |= ValidateRangedEnum("vkCreateImageView", "pCreateInfo->viewType", "VkImageViewType", pCreateInfo->viewType, "VUID-VkImageViewCreateInfo-viewType-parameter");

        skip |= ValidateRangedEnum("vkCreateImageView", "pCreateInfo->format", "VkFormat", pCreateInfo->format, "VUID-VkImageViewCreateInfo-format-parameter");

        skip |= ValidateRangedEnum("vkCreateImageView", "pCreateInfo->components.r", "VkComponentSwizzle", pCreateInfo->components.r, "VUID-VkComponentMapping-r-parameter");

        skip |= ValidateRangedEnum("vkCreateImageView", "pCreateInfo->components.g", "VkComponentSwizzle", pCreateInfo->components.g, "VUID-VkComponentMapping-g-parameter");

        skip |= ValidateRangedEnum("vkCreateImageView", "pCreateInfo->components.b", "VkComponentSwizzle", pCreateInfo->components.b, "VUID-VkComponentMapping-b-parameter");

        skip |= ValidateRangedEnum("vkCreateImageView", "pCreateInfo->components.a", "VkComponentSwizzle", pCreateInfo->components.a, "VUID-VkComponentMapping-a-parameter");

        skip |= ValidateFlags("vkCreateImageView", "pCreateInfo->subresourceRange.aspectMask", "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pCreateInfo->subresourceRange.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateImageView-pAllocator-null", "vkCreateImageView(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateImageView", "pView", pView, "VUID-vkCreateImageView-pView-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateImageView(device, pCreateInfo, pAllocator, pView);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyImageView-pAllocator-null", "vkDestroyImageView(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineCache*                            pPipelineCache) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreatePipelineCache", "pCreateInfo", "VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO, true, "VUID-vkCreatePipelineCache-pCreateInfo-parameter", "VUID-VkPipelineCacheCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCreatePipelineCache", "pCreateInfo->pNext", nullptr, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkPipelineCacheCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags("vkCreatePipelineCache", "pCreateInfo->flags", "VkPipelineCacheCreateFlagBits", AllVkPipelineCacheCreateFlagBits, pCreateInfo->flags, kOptionalFlags, "VUID-VkPipelineCacheCreateInfo-flags-parameter");

        skip |= ValidateArray("vkCreatePipelineCache", "pCreateInfo->initialDataSize", "pCreateInfo->pInitialData", pCreateInfo->initialDataSize, &pCreateInfo->pInitialData, true, true, "VUID-VkPipelineCacheCreateInfo-initialDataSize-arraylength", "VUID-VkPipelineCacheCreateInfo-pInitialData-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreatePipelineCache-pAllocator-null", "vkCreatePipelineCache(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreatePipelineCache", "pPipelineCache", pPipelineCache, "VUID-vkCreatePipelineCache-pPipelineCache-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyPipelineCache-pAllocator-null", "vkDestroyPipelineCache(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCreateGraphicsPipelines", "pipelineCache", pipelineCache);
    skip |= ValidateStructTypeArray("vkCreateGraphicsPipelines", "createInfoCount", "pCreateInfos", "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO", createInfoCount, pCreateInfos, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO, true, true, "VUID-VkGraphicsPipelineCreateInfo-sType-sType", "VUID-vkCreateGraphicsPipelines-pCreateInfos-parameter", "VUID-vkCreateGraphicsPipelines-createInfoCount-arraylength");
    if (pCreateInfos != nullptr)
    {
        for (uint32_t createInfoIndex = 0; createInfoIndex < createInfoCount; ++createInfoIndex)
        {
            constexpr std::array allowed_structs_VkGraphicsPipelineCreateInfo = { VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO, VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT, VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR, VK_STRUCTURE_TYPE_PIPELINE_OFFLINE_CREATE_INFO, VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO };

            skip |= ValidateStructPnext("vkCreateGraphicsPipelines", ParameterName("pCreateInfos[%i].pNext", ParameterName::IndexVector{ createInfoIndex }), "VkPipelineCreationFeedbackCreateInfo, VkPipelineDiscardRectangleStateCreateInfoEXT, VkPipelineFragmentShadingRateStateCreateInfoKHR, VkPipelineOfflineCreateInfo, VkPipelineRenderingCreateInfo", pCreateInfos[createInfoIndex].pNext, allowed_structs_VkGraphicsPipelineCreateInfo.size(), allowed_structs_VkGraphicsPipelineCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkGraphicsPipelineCreateInfo-pNext-pNext", "VUID-VkGraphicsPipelineCreateInfo-sType-unique", false, true);

            skip |= ValidateFlags("vkCreateGraphicsPipelines", ParameterName("pCreateInfos[%i].flags", ParameterName::IndexVector{ createInfoIndex }), "VkPipelineCreateFlagBits", AllVkPipelineCreateFlagBits, pCreateInfos[createInfoIndex].flags, kOptionalFlags, "VUID-VkGraphicsPipelineCreateInfo-flags-parameter");

            skip |= ValidateStructType("vkCreateGraphicsPipelines", ParameterName("pCreateInfos[%i].pDynamicState", ParameterName::IndexVector{ createInfoIndex }), "VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO", pCreateInfos[createInfoIndex].pDynamicState, VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO, false, "VUID-VkGraphicsPipelineCreateInfo-pDynamicState-parameter", "VUID-VkPipelineDynamicStateCreateInfo-sType-sType");

            if (pCreateInfos[createInfoIndex].pDynamicState != nullptr)
            {
                skip |= ValidateStructPnext("vkCreateGraphicsPipelines", ParameterName("pCreateInfos[%i].pDynamicState->pNext", ParameterName::IndexVector{ createInfoIndex }), nullptr, pCreateInfos[createInfoIndex].pDynamicState->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkPipelineDynamicStateCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateReservedFlags("vkCreateGraphicsPipelines", ParameterName("pCreateInfos[%i].pDynamicState->flags", ParameterName::IndexVector{ createInfoIndex }), pCreateInfos[createInfoIndex].pDynamicState->flags, "VUID-VkPipelineDynamicStateCreateInfo-flags-zerobitmask");

                skip |= ValidateRangedEnumArray("vkCreateGraphicsPipelines", ParameterName("pCreateInfos[%i].pDynamicState->dynamicStateCount", ParameterName::IndexVector{ createInfoIndex }), ParameterName("pCreateInfos[%i].pDynamicState->pDynamicStates", ParameterName::IndexVector{ createInfoIndex }), "VkDynamicState", pCreateInfos[createInfoIndex].pDynamicState->dynamicStateCount, pCreateInfos[createInfoIndex].pDynamicState->pDynamicStates, false, true);
            }
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateGraphicsPipelines-pAllocator-null", "vkCreateGraphicsPipelines(): pAllocator must be NULL");
    }
    skip |= ValidateArray("vkCreateGraphicsPipelines", "createInfoCount", "pPipelines", createInfoCount, &pPipelines, true, true, "VUID-vkCreateGraphicsPipelines-createInfoCount-arraylength", "VUID-vkCreateGraphicsPipelines-pPipelines-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCreateComputePipelines", "pipelineCache", pipelineCache);
    skip |= ValidateStructTypeArray("vkCreateComputePipelines", "createInfoCount", "pCreateInfos", "VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO", createInfoCount, pCreateInfos, VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO, true, true, "VUID-VkComputePipelineCreateInfo-sType-sType", "VUID-vkCreateComputePipelines-pCreateInfos-parameter", "VUID-vkCreateComputePipelines-createInfoCount-arraylength");
    if (pCreateInfos != nullptr)
    {
        for (uint32_t createInfoIndex = 0; createInfoIndex < createInfoCount; ++createInfoIndex)
        {
            constexpr std::array allowed_structs_VkComputePipelineCreateInfo = { VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO, VK_STRUCTURE_TYPE_PIPELINE_OFFLINE_CREATE_INFO };

            skip |= ValidateStructPnext("vkCreateComputePipelines", ParameterName("pCreateInfos[%i].pNext", ParameterName::IndexVector{ createInfoIndex }), "VkPipelineCreationFeedbackCreateInfo, VkPipelineOfflineCreateInfo", pCreateInfos[createInfoIndex].pNext, allowed_structs_VkComputePipelineCreateInfo.size(), allowed_structs_VkComputePipelineCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkComputePipelineCreateInfo-pNext-pNext", "VUID-VkComputePipelineCreateInfo-sType-unique", false, true);

            skip |= ValidateFlags("vkCreateComputePipelines", ParameterName("pCreateInfos[%i].flags", ParameterName::IndexVector{ createInfoIndex }), "VkPipelineCreateFlagBits", AllVkPipelineCreateFlagBits, pCreateInfos[createInfoIndex].flags, kOptionalFlags, "VUID-VkComputePipelineCreateInfo-flags-parameter");

            skip |= ValidateStructType("vkCreateComputePipelines", ParameterName("pCreateInfos[%i].stage", ParameterName::IndexVector{ createInfoIndex }), "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO", &(pCreateInfos[createInfoIndex].stage), VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, false, kVUIDUndefined, "VUID-VkPipelineShaderStageCreateInfo-sType-sType");

            constexpr std::array allowed_structs_VkPipelineShaderStageCreateInfo = { VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT, VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO };

            skip |= ValidateStructPnext("vkCreateComputePipelines", ParameterName("pCreateInfos[%i].stage.pNext", ParameterName::IndexVector{ createInfoIndex }), "VkDebugUtilsObjectNameInfoEXT, VkPipelineShaderStageRequiredSubgroupSizeCreateInfo", pCreateInfos[createInfoIndex].stage.pNext, allowed_structs_VkPipelineShaderStageCreateInfo.size(), allowed_structs_VkPipelineShaderStageCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkPipelineShaderStageCreateInfo-pNext-pNext", "VUID-VkPipelineShaderStageCreateInfo-sType-unique", false, true);

            skip |= ValidateFlags("vkCreateComputePipelines", ParameterName("pCreateInfos[%i].stage.flags", ParameterName::IndexVector{ createInfoIndex }), "VkPipelineShaderStageCreateFlagBits", AllVkPipelineShaderStageCreateFlagBits, pCreateInfos[createInfoIndex].stage.flags, kOptionalFlags, "VUID-VkPipelineShaderStageCreateInfo-flags-parameter");

            skip |= ValidateFlags("vkCreateComputePipelines", ParameterName("pCreateInfos[%i].stage.stage", ParameterName::IndexVector{ createInfoIndex }), "VkShaderStageFlagBits", AllVkShaderStageFlagBits, pCreateInfos[createInfoIndex].stage.stage, kRequiredSingleBit, "VUID-VkPipelineShaderStageCreateInfo-stage-parameter", "VUID-VkPipelineShaderStageCreateInfo-stage-parameter");

            if (pCreateInfos[createInfoIndex].stage.pSpecializationInfo != nullptr)
            {
                skip |= ValidateArray("vkCreateComputePipelines", ParameterName("pCreateInfos[%i].stage.pSpecializationInfo->mapEntryCount", ParameterName::IndexVector{ createInfoIndex }), ParameterName("pCreateInfos[%i].stage.pSpecializationInfo->pMapEntries", ParameterName::IndexVector{ createInfoIndex }), pCreateInfos[createInfoIndex].stage.pSpecializationInfo->mapEntryCount, &pCreateInfos[createInfoIndex].stage.pSpecializationInfo->pMapEntries, false, true, kVUIDUndefined, "VUID-VkSpecializationInfo-pMapEntries-parameter");

                if (pCreateInfos[createInfoIndex].stage.pSpecializationInfo->pMapEntries != nullptr)
                {
                    for (uint32_t mapEntryIndex = 0; mapEntryIndex < pCreateInfos[createInfoIndex].stage.pSpecializationInfo->mapEntryCount; ++mapEntryIndex)
                    {
                        // No xml-driven validation
                    }
                }

                skip |= ValidateArray("vkCreateComputePipelines", ParameterName("pCreateInfos[%i].stage.pSpecializationInfo->dataSize", ParameterName::IndexVector{ createInfoIndex }), ParameterName("pCreateInfos[%i].stage.pSpecializationInfo->pData", ParameterName::IndexVector{ createInfoIndex }), pCreateInfos[createInfoIndex].stage.pSpecializationInfo->dataSize, &pCreateInfos[createInfoIndex].stage.pSpecializationInfo->pData, false, true, kVUIDUndefined, "VUID-VkSpecializationInfo-pData-parameter");
            }

            skip |= ValidateRequiredHandle("vkCreateComputePipelines", ParameterName("pCreateInfos[%i].layout", ParameterName::IndexVector{ createInfoIndex }), pCreateInfos[createInfoIndex].layout);
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateComputePipelines-pAllocator-null", "vkCreateComputePipelines(): pAllocator must be NULL");
    }
    skip |= ValidateArray("vkCreateComputePipelines", "createInfoCount", "pPipelines", createInfoCount, &pPipelines, true, true, "VUID-vkCreateComputePipelines-createInfoCount-arraylength", "VUID-vkCreateComputePipelines-pPipelines-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyPipeline-pAllocator-null", "vkDestroyPipeline(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineLayout*                           pPipelineLayout) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreatePipelineLayout", "pCreateInfo", "VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO, true, "VUID-vkCreatePipelineLayout-pCreateInfo-parameter", "VUID-VkPipelineLayoutCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCreatePipelineLayout", "pCreateInfo->pNext", nullptr, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkPipelineLayoutCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags("vkCreatePipelineLayout", "pCreateInfo->flags", "VkPipelineLayoutCreateFlagBits", AllVkPipelineLayoutCreateFlagBits, pCreateInfo->flags, kOptionalFlags, kVUIDUndefined);

        skip |= ValidateArray("vkCreatePipelineLayout", "pCreateInfo->pushConstantRangeCount", "pCreateInfo->pPushConstantRanges", pCreateInfo->pushConstantRangeCount, &pCreateInfo->pPushConstantRanges, false, true, kVUIDUndefined, "VUID-VkPipelineLayoutCreateInfo-pPushConstantRanges-parameter");

        if (pCreateInfo->pPushConstantRanges != nullptr)
        {
            for (uint32_t pushConstantRangeIndex = 0; pushConstantRangeIndex < pCreateInfo->pushConstantRangeCount; ++pushConstantRangeIndex)
            {
                skip |= ValidateFlags("vkCreatePipelineLayout", ParameterName("pCreateInfo->pPushConstantRanges[%i].stageFlags", ParameterName::IndexVector{ pushConstantRangeIndex }), "VkShaderStageFlagBits", AllVkShaderStageFlagBits, pCreateInfo->pPushConstantRanges[pushConstantRangeIndex].stageFlags, kRequiredFlags, "VUID-VkPushConstantRange-stageFlags-parameter", "VUID-VkPushConstantRange-stageFlags-requiredbitmask");
            }
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreatePipelineLayout-pAllocator-null", "vkCreatePipelineLayout(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreatePipelineLayout", "pPipelineLayout", pPipelineLayout, "VUID-vkCreatePipelineLayout-pPipelineLayout-parameter");
    if (!skip) skip |= manual_PreCallValidateCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyPipelineLayout-pAllocator-null", "vkDestroyPipelineLayout(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSampler*                                  pSampler) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateSampler", "pCreateInfo", "VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO, true, "VUID-vkCreateSampler-pCreateInfo-parameter", "VUID-VkSamplerCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkSamplerCreateInfo = { VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT, VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO };

        skip |= ValidateStructPnext("vkCreateSampler", "pCreateInfo->pNext", "VkSamplerCustomBorderColorCreateInfoEXT, VkSamplerReductionModeCreateInfo, VkSamplerYcbcrConversionInfo", pCreateInfo->pNext, allowed_structs_VkSamplerCreateInfo.size(), allowed_structs_VkSamplerCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkSamplerCreateInfo-pNext-pNext", "VUID-VkSamplerCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags("vkCreateSampler", "pCreateInfo->flags", "VkSamplerCreateFlagBits", AllVkSamplerCreateFlagBits, pCreateInfo->flags, kOptionalFlags, kVUIDUndefined);

        skip |= ValidateRangedEnum("vkCreateSampler", "pCreateInfo->magFilter", "VkFilter", pCreateInfo->magFilter, "VUID-VkSamplerCreateInfo-magFilter-parameter");

        skip |= ValidateRangedEnum("vkCreateSampler", "pCreateInfo->minFilter", "VkFilter", pCreateInfo->minFilter, "VUID-VkSamplerCreateInfo-minFilter-parameter");

        skip |= ValidateRangedEnum("vkCreateSampler", "pCreateInfo->mipmapMode", "VkSamplerMipmapMode", pCreateInfo->mipmapMode, "VUID-VkSamplerCreateInfo-mipmapMode-parameter");

        skip |= ValidateRangedEnum("vkCreateSampler", "pCreateInfo->addressModeU", "VkSamplerAddressMode", pCreateInfo->addressModeU, "VUID-VkSamplerCreateInfo-addressModeU-parameter");

        skip |= ValidateRangedEnum("vkCreateSampler", "pCreateInfo->addressModeV", "VkSamplerAddressMode", pCreateInfo->addressModeV, "VUID-VkSamplerCreateInfo-addressModeV-parameter");

        skip |= ValidateRangedEnum("vkCreateSampler", "pCreateInfo->addressModeW", "VkSamplerAddressMode", pCreateInfo->addressModeW, "VUID-VkSamplerCreateInfo-addressModeW-parameter");

        skip |= ValidateBool32("vkCreateSampler", "pCreateInfo->anisotropyEnable", pCreateInfo->anisotropyEnable);

        skip |= ValidateBool32("vkCreateSampler", "pCreateInfo->compareEnable", pCreateInfo->compareEnable);

        skip |= ValidateBool32("vkCreateSampler", "pCreateInfo->unnormalizedCoordinates", pCreateInfo->unnormalizedCoordinates);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateSampler-pAllocator-null", "vkCreateSampler(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateSampler", "pSampler", pSampler, "VUID-vkCreateSampler-pSampler-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateSampler(device, pCreateInfo, pAllocator, pSampler);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroySampler-pAllocator-null", "vkDestroySampler(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorSetLayout*                      pSetLayout) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateDescriptorSetLayout", "pCreateInfo", "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO, true, "VUID-vkCreateDescriptorSetLayout-pCreateInfo-parameter", "VUID-VkDescriptorSetLayoutCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkDescriptorSetLayoutCreateInfo = { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO };

        skip |= ValidateStructPnext("vkCreateDescriptorSetLayout", "pCreateInfo->pNext", "VkDescriptorSetLayoutBindingFlagsCreateInfo", pCreateInfo->pNext, allowed_structs_VkDescriptorSetLayoutCreateInfo.size(), allowed_structs_VkDescriptorSetLayoutCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkDescriptorSetLayoutCreateInfo-pNext-pNext", "VUID-VkDescriptorSetLayoutCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags("vkCreateDescriptorSetLayout", "pCreateInfo->flags", "VkDescriptorSetLayoutCreateFlagBits", AllVkDescriptorSetLayoutCreateFlagBits, pCreateInfo->flags, kOptionalFlags, "VUID-VkDescriptorSetLayoutCreateInfo-flags-parameter");

        skip |= ValidateArray("vkCreateDescriptorSetLayout", "pCreateInfo->bindingCount", "pCreateInfo->pBindings", pCreateInfo->bindingCount, &pCreateInfo->pBindings, false, true, kVUIDUndefined, "VUID-VkDescriptorSetLayoutCreateInfo-pBindings-parameter");

        if (pCreateInfo->pBindings != nullptr)
        {
            for (uint32_t bindingIndex = 0; bindingIndex < pCreateInfo->bindingCount; ++bindingIndex)
            {
                skip |= ValidateRangedEnum("vkCreateDescriptorSetLayout", ParameterName("pCreateInfo->pBindings[%i].descriptorType", ParameterName::IndexVector{ bindingIndex }), "VkDescriptorType", pCreateInfo->pBindings[bindingIndex].descriptorType, "VUID-VkDescriptorSetLayoutBinding-descriptorType-parameter");
            }
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateDescriptorSetLayout-pAllocator-null", "vkCreateDescriptorSetLayout(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateDescriptorSetLayout", "pSetLayout", pSetLayout, "VUID-vkCreateDescriptorSetLayout-pSetLayout-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyDescriptorSetLayout-pAllocator-null", "vkDestroyDescriptorSetLayout(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorPool*                           pDescriptorPool) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateDescriptorPool", "pCreateInfo", "VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO, true, "VUID-vkCreateDescriptorPool-pCreateInfo-parameter", "VUID-VkDescriptorPoolCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkDescriptorPoolCreateInfo = { VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO };

        skip |= ValidateStructPnext("vkCreateDescriptorPool", "pCreateInfo->pNext", "VkDescriptorPoolInlineUniformBlockCreateInfo", pCreateInfo->pNext, allowed_structs_VkDescriptorPoolCreateInfo.size(), allowed_structs_VkDescriptorPoolCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkDescriptorPoolCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags("vkCreateDescriptorPool", "pCreateInfo->flags", "VkDescriptorPoolCreateFlagBits", AllVkDescriptorPoolCreateFlagBits, pCreateInfo->flags, kOptionalFlags, "VUID-VkDescriptorPoolCreateInfo-flags-parameter");

        skip |= ValidateArray("vkCreateDescriptorPool", "pCreateInfo->poolSizeCount", "pCreateInfo->pPoolSizes", pCreateInfo->poolSizeCount, &pCreateInfo->pPoolSizes, false, true, kVUIDUndefined, "VUID-VkDescriptorPoolCreateInfo-pPoolSizes-parameter");

        if (pCreateInfo->pPoolSizes != nullptr)
        {
            for (uint32_t poolSizeIndex = 0; poolSizeIndex < pCreateInfo->poolSizeCount; ++poolSizeIndex)
            {
                skip |= ValidateRangedEnum("vkCreateDescriptorPool", ParameterName("pCreateInfo->pPoolSizes[%i].type", ParameterName::IndexVector{ poolSizeIndex }), "VkDescriptorType", pCreateInfo->pPoolSizes[poolSizeIndex].type, "VUID-VkDescriptorPoolSize-type-parameter");
            }
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateDescriptorPool-pAllocator-null", "vkCreateDescriptorPool(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateDescriptorPool", "pDescriptorPool", pDescriptorPool, "VUID-vkCreateDescriptorPool-pDescriptorPool-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    return skip;
}

bool StatelessValidation::PreCallValidateResetDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkResetDescriptorPool", "descriptorPool", descriptorPool);
    skip |= ValidateReservedFlags("vkResetDescriptorPool", "flags", flags, "VUID-vkResetDescriptorPool-flags-zerobitmask");
    return skip;
}

bool StatelessValidation::PreCallValidateAllocateDescriptorSets(
    VkDevice                                    device,
    const VkDescriptorSetAllocateInfo*          pAllocateInfo,
    VkDescriptorSet*                            pDescriptorSets) const {
    bool skip = false;
    skip |= ValidateStructType("vkAllocateDescriptorSets", "pAllocateInfo", "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO", pAllocateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO, true, "VUID-vkAllocateDescriptorSets-pAllocateInfo-parameter", "VUID-VkDescriptorSetAllocateInfo-sType-sType");
    if (pAllocateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkDescriptorSetAllocateInfo = { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO };

        skip |= ValidateStructPnext("vkAllocateDescriptorSets", "pAllocateInfo->pNext", "VkDescriptorSetVariableDescriptorCountAllocateInfo", pAllocateInfo->pNext, allowed_structs_VkDescriptorSetAllocateInfo.size(), allowed_structs_VkDescriptorSetAllocateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkDescriptorSetAllocateInfo-pNext-pNext", "VUID-VkDescriptorSetAllocateInfo-sType-unique", false, true);

        skip |= ValidateRequiredHandle("vkAllocateDescriptorSets", "pAllocateInfo->descriptorPool", pAllocateInfo->descriptorPool);

        skip |= ValidateHandleArray("vkAllocateDescriptorSets", "pAllocateInfo->descriptorSetCount", "pAllocateInfo->pSetLayouts", pAllocateInfo->descriptorSetCount, pAllocateInfo->pSetLayouts, true, true, kVUIDUndefined);
    }
    if (pAllocateInfo != nullptr) {
        skip |= ValidateArray("vkAllocateDescriptorSets", "pAllocateInfo->descriptorSetCount", "pDescriptorSets", pAllocateInfo->descriptorSetCount, &pDescriptorSets, true, true, "VUID-vkAllocateDescriptorSets-pAllocateInfo::descriptorSetCount-arraylength", "VUID-vkAllocateDescriptorSets-pDescriptorSets-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateFreeDescriptorSets(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkFreeDescriptorSets", "descriptorPool", descriptorPool);
    skip |= ValidateArray("vkFreeDescriptorSets", "descriptorSetCount", "", descriptorSetCount, &pDescriptorSets, true, false, "VUID-vkFreeDescriptorSets-descriptorSetCount-arraylength", kVUIDUndefined);
    if (!skip) skip |= manual_PreCallValidateFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    return skip;
}

bool StatelessValidation::PreCallValidateUpdateDescriptorSets(
    VkDevice                                    device,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    const VkCopyDescriptorSet*                  pDescriptorCopies) const {
    bool skip = false;
    skip |= ValidateStructTypeArray("vkUpdateDescriptorSets", "descriptorWriteCount", "pDescriptorWrites", "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET", descriptorWriteCount, pDescriptorWrites, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET, false, true, "VUID-VkWriteDescriptorSet-sType-sType", "VUID-vkUpdateDescriptorSets-pDescriptorWrites-parameter", kVUIDUndefined);
    if (pDescriptorWrites != nullptr)
    {
        for (uint32_t descriptorWriteIndex = 0; descriptorWriteIndex < descriptorWriteCount; ++descriptorWriteIndex)
        {
            constexpr std::array allowed_structs_VkWriteDescriptorSet = { VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK };

            skip |= ValidateStructPnext("vkUpdateDescriptorSets", ParameterName("pDescriptorWrites[%i].pNext", ParameterName::IndexVector{ descriptorWriteIndex }), "VkWriteDescriptorSetInlineUniformBlock", pDescriptorWrites[descriptorWriteIndex].pNext, allowed_structs_VkWriteDescriptorSet.size(), allowed_structs_VkWriteDescriptorSet.data(), GeneratedVulkanHeaderVersion, "VUID-VkWriteDescriptorSet-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateRangedEnum("vkUpdateDescriptorSets", ParameterName("pDescriptorWrites[%i].descriptorType", ParameterName::IndexVector{ descriptorWriteIndex }), "VkDescriptorType", pDescriptorWrites[descriptorWriteIndex].descriptorType, "VUID-VkWriteDescriptorSet-descriptorType-parameter");

            skip |= ValidateArray("vkUpdateDescriptorSets", ParameterName("pDescriptorWrites[%i].descriptorCount", ParameterName::IndexVector{ descriptorWriteIndex }), "", pDescriptorWrites[descriptorWriteIndex].descriptorCount, &pDescriptorWrites[descriptorWriteIndex].pImageInfo, true, false, "VUID-VkWriteDescriptorSet-descriptorCount-arraylength", kVUIDUndefined);
        }
    }
    skip |= ValidateStructTypeArray("vkUpdateDescriptorSets", "descriptorCopyCount", "pDescriptorCopies", "VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET", descriptorCopyCount, pDescriptorCopies, VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET, false, true, "VUID-VkCopyDescriptorSet-sType-sType", "VUID-vkUpdateDescriptorSets-pDescriptorCopies-parameter", kVUIDUndefined);
    if (pDescriptorCopies != nullptr)
    {
        for (uint32_t descriptorCopyIndex = 0; descriptorCopyIndex < descriptorCopyCount; ++descriptorCopyIndex)
        {
            skip |= ValidateStructPnext("vkUpdateDescriptorSets", ParameterName("pDescriptorCopies[%i].pNext", ParameterName::IndexVector{ descriptorCopyIndex }), nullptr, pDescriptorCopies[descriptorCopyIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCopyDescriptorSet-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateRequiredHandle("vkUpdateDescriptorSets", ParameterName("pDescriptorCopies[%i].srcSet", ParameterName::IndexVector{ descriptorCopyIndex }), pDescriptorCopies[descriptorCopyIndex].srcSet);

            skip |= ValidateRequiredHandle("vkUpdateDescriptorSets", ParameterName("pDescriptorCopies[%i].dstSet", ParameterName::IndexVector{ descriptorCopyIndex }), pDescriptorCopies[descriptorCopyIndex].dstSet);
        }
    }
    if (!skip) skip |= manual_PreCallValidateUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFramebuffer*                              pFramebuffer) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateFramebuffer", "pCreateInfo", "VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO, true, "VUID-vkCreateFramebuffer-pCreateInfo-parameter", "VUID-VkFramebufferCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkFramebufferCreateInfo = { VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO };

        skip |= ValidateStructPnext("vkCreateFramebuffer", "pCreateInfo->pNext", "VkFramebufferAttachmentsCreateInfo", pCreateInfo->pNext, allowed_structs_VkFramebufferCreateInfo.size(), allowed_structs_VkFramebufferCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkFramebufferCreateInfo-pNext-pNext", "VUID-VkFramebufferCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags("vkCreateFramebuffer", "pCreateInfo->flags", "VkFramebufferCreateFlagBits", AllVkFramebufferCreateFlagBits, pCreateInfo->flags, kOptionalFlags, "VUID-VkFramebufferCreateInfo-flags-parameter");

        skip |= ValidateRequiredHandle("vkCreateFramebuffer", "pCreateInfo->renderPass", pCreateInfo->renderPass);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateFramebuffer-pAllocator-null", "vkCreateFramebuffer(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateFramebuffer", "pFramebuffer", pFramebuffer, "VUID-vkCreateFramebuffer-pFramebuffer-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyFramebuffer-pAllocator-null", "vkDestroyFramebuffer(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateRenderPass", "pCreateInfo", "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO, true, "VUID-vkCreateRenderPass-pCreateInfo-parameter", "VUID-VkRenderPassCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkRenderPassCreateInfo = { VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO, VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO };

        skip |= ValidateStructPnext("vkCreateRenderPass", "pCreateInfo->pNext", "VkRenderPassInputAttachmentAspectCreateInfo, VkRenderPassMultiviewCreateInfo", pCreateInfo->pNext, allowed_structs_VkRenderPassCreateInfo.size(), allowed_structs_VkRenderPassCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkRenderPassCreateInfo-pNext-pNext", "VUID-VkRenderPassCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags("vkCreateRenderPass", "pCreateInfo->flags", "VkRenderPassCreateFlagBits", AllVkRenderPassCreateFlagBits, pCreateInfo->flags, kOptionalFlags, kVUIDUndefined);

        skip |= ValidateArray("vkCreateRenderPass", "pCreateInfo->attachmentCount", "pCreateInfo->pAttachments", pCreateInfo->attachmentCount, &pCreateInfo->pAttachments, false, true, kVUIDUndefined, "VUID-VkRenderPassCreateInfo-pAttachments-parameter");

        if (pCreateInfo->pAttachments != nullptr)
        {
            for (uint32_t attachmentIndex = 0; attachmentIndex < pCreateInfo->attachmentCount; ++attachmentIndex)
            {
                skip |= ValidateFlags("vkCreateRenderPass", ParameterName("pCreateInfo->pAttachments[%i].flags", ParameterName::IndexVector{ attachmentIndex }), "VkAttachmentDescriptionFlagBits", AllVkAttachmentDescriptionFlagBits, pCreateInfo->pAttachments[attachmentIndex].flags, kOptionalFlags, "VUID-VkAttachmentDescription-flags-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass", ParameterName("pCreateInfo->pAttachments[%i].format", ParameterName::IndexVector{ attachmentIndex }), "VkFormat", pCreateInfo->pAttachments[attachmentIndex].format, "VUID-VkAttachmentDescription-format-parameter");

                skip |= ValidateFlags("vkCreateRenderPass", ParameterName("pCreateInfo->pAttachments[%i].samples", ParameterName::IndexVector{ attachmentIndex }), "VkSampleCountFlagBits", AllVkSampleCountFlagBits, pCreateInfo->pAttachments[attachmentIndex].samples, kRequiredSingleBit, "VUID-VkAttachmentDescription-samples-parameter", "VUID-VkAttachmentDescription-samples-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass", ParameterName("pCreateInfo->pAttachments[%i].loadOp", ParameterName::IndexVector{ attachmentIndex }), "VkAttachmentLoadOp", pCreateInfo->pAttachments[attachmentIndex].loadOp, "VUID-VkAttachmentDescription-loadOp-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass", ParameterName("pCreateInfo->pAttachments[%i].storeOp", ParameterName::IndexVector{ attachmentIndex }), "VkAttachmentStoreOp", pCreateInfo->pAttachments[attachmentIndex].storeOp, "VUID-VkAttachmentDescription-storeOp-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass", ParameterName("pCreateInfo->pAttachments[%i].stencilLoadOp", ParameterName::IndexVector{ attachmentIndex }), "VkAttachmentLoadOp", pCreateInfo->pAttachments[attachmentIndex].stencilLoadOp, "VUID-VkAttachmentDescription-stencilLoadOp-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass", ParameterName("pCreateInfo->pAttachments[%i].stencilStoreOp", ParameterName::IndexVector{ attachmentIndex }), "VkAttachmentStoreOp", pCreateInfo->pAttachments[attachmentIndex].stencilStoreOp, "VUID-VkAttachmentDescription-stencilStoreOp-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass", ParameterName("pCreateInfo->pAttachments[%i].initialLayout", ParameterName::IndexVector{ attachmentIndex }), "VkImageLayout", pCreateInfo->pAttachments[attachmentIndex].initialLayout, "VUID-VkAttachmentDescription-initialLayout-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass", ParameterName("pCreateInfo->pAttachments[%i].finalLayout", ParameterName::IndexVector{ attachmentIndex }), "VkImageLayout", pCreateInfo->pAttachments[attachmentIndex].finalLayout, "VUID-VkAttachmentDescription-finalLayout-parameter");
            }
        }

        skip |= ValidateArray("vkCreateRenderPass", "pCreateInfo->subpassCount", "pCreateInfo->pSubpasses", pCreateInfo->subpassCount, &pCreateInfo->pSubpasses, true, true, "VUID-VkRenderPassCreateInfo-subpassCount-arraylength", "VUID-VkRenderPassCreateInfo-pSubpasses-parameter");

        if (pCreateInfo->pSubpasses != nullptr)
        {
            for (uint32_t subpassIndex = 0; subpassIndex < pCreateInfo->subpassCount; ++subpassIndex)
            {
                skip |= ValidateFlags("vkCreateRenderPass", ParameterName("pCreateInfo->pSubpasses[%i].flags", ParameterName::IndexVector{ subpassIndex }), "VkSubpassDescriptionFlagBits", AllVkSubpassDescriptionFlagBits, pCreateInfo->pSubpasses[subpassIndex].flags, kOptionalFlags, kVUIDUndefined);

                skip |= ValidateRangedEnum("vkCreateRenderPass", ParameterName("pCreateInfo->pSubpasses[%i].pipelineBindPoint", ParameterName::IndexVector{ subpassIndex }), "VkPipelineBindPoint", pCreateInfo->pSubpasses[subpassIndex].pipelineBindPoint, "VUID-VkSubpassDescription-pipelineBindPoint-parameter");

                skip |= ValidateArray("vkCreateRenderPass", ParameterName("pCreateInfo->pSubpasses[%i].inputAttachmentCount", ParameterName::IndexVector{ subpassIndex }), ParameterName("pCreateInfo->pSubpasses[%i].pInputAttachments", ParameterName::IndexVector{ subpassIndex }), pCreateInfo->pSubpasses[subpassIndex].inputAttachmentCount, &pCreateInfo->pSubpasses[subpassIndex].pInputAttachments, false, true, kVUIDUndefined, "VUID-VkSubpassDescription-pInputAttachments-parameter");

                if (pCreateInfo->pSubpasses[subpassIndex].pInputAttachments != nullptr)
                {
                    for (uint32_t inputAttachmentIndex = 0; inputAttachmentIndex < pCreateInfo->pSubpasses[subpassIndex].inputAttachmentCount; ++inputAttachmentIndex)
                    {
                        skip |= ValidateRangedEnum("vkCreateRenderPass", ParameterName("pCreateInfo->pSubpasses[%i].pInputAttachments[%i].layout", ParameterName::IndexVector{ subpassIndex, inputAttachmentIndex }), "VkImageLayout", pCreateInfo->pSubpasses[subpassIndex].pInputAttachments[inputAttachmentIndex].layout, "VUID-VkAttachmentReference-layout-parameter");
                    }
                }

                skip |= ValidateArray("vkCreateRenderPass", ParameterName("pCreateInfo->pSubpasses[%i].colorAttachmentCount", ParameterName::IndexVector{ subpassIndex }), ParameterName("pCreateInfo->pSubpasses[%i].pColorAttachments", ParameterName::IndexVector{ subpassIndex }), pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount, &pCreateInfo->pSubpasses[subpassIndex].pColorAttachments, false, true, kVUIDUndefined, "VUID-VkSubpassDescription-pColorAttachments-parameter");

                if (pCreateInfo->pSubpasses[subpassIndex].pColorAttachments != nullptr)
                {
                    for (uint32_t colorAttachmentIndex = 0; colorAttachmentIndex < pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount; ++colorAttachmentIndex)
                    {
                        skip |= ValidateRangedEnum("vkCreateRenderPass", ParameterName("pCreateInfo->pSubpasses[%i].pColorAttachments[%i].layout", ParameterName::IndexVector{ subpassIndex, colorAttachmentIndex }), "VkImageLayout", pCreateInfo->pSubpasses[subpassIndex].pColorAttachments[colorAttachmentIndex].layout, "VUID-VkAttachmentReference-layout-parameter");
                    }
                }

                if (pCreateInfo->pSubpasses[subpassIndex].pResolveAttachments != nullptr)
                {
                    for (uint32_t colorAttachmentIndex = 0; colorAttachmentIndex < pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount; ++colorAttachmentIndex)
                    {
                        skip |= ValidateRangedEnum("vkCreateRenderPass", ParameterName("pCreateInfo->pSubpasses[%i].pResolveAttachments[%i].layout", ParameterName::IndexVector{ subpassIndex, colorAttachmentIndex }), "VkImageLayout", pCreateInfo->pSubpasses[subpassIndex].pResolveAttachments[colorAttachmentIndex].layout, "VUID-VkAttachmentReference-layout-parameter");
                    }
                }

                if (pCreateInfo->pSubpasses[subpassIndex].pDepthStencilAttachment != nullptr)
                {
                    skip |= ValidateRangedEnum("vkCreateRenderPass", ParameterName("pCreateInfo->pSubpasses[%i].pDepthStencilAttachment->layout", ParameterName::IndexVector{ subpassIndex }), "VkImageLayout", pCreateInfo->pSubpasses[subpassIndex].pDepthStencilAttachment->layout, "VUID-VkAttachmentReference-layout-parameter");
                }

                skip |= ValidateArray("vkCreateRenderPass", ParameterName("pCreateInfo->pSubpasses[%i].preserveAttachmentCount", ParameterName::IndexVector{ subpassIndex }), ParameterName("pCreateInfo->pSubpasses[%i].pPreserveAttachments", ParameterName::IndexVector{ subpassIndex }), pCreateInfo->pSubpasses[subpassIndex].preserveAttachmentCount, &pCreateInfo->pSubpasses[subpassIndex].pPreserveAttachments, false, true, kVUIDUndefined, "VUID-VkSubpassDescription-pPreserveAttachments-parameter");
            }
        }

        skip |= ValidateArray("vkCreateRenderPass", "pCreateInfo->dependencyCount", "pCreateInfo->pDependencies", pCreateInfo->dependencyCount, &pCreateInfo->pDependencies, false, true, kVUIDUndefined, "VUID-VkRenderPassCreateInfo-pDependencies-parameter");

        if (pCreateInfo->pDependencies != nullptr)
        {
            for (uint32_t dependencyIndex = 0; dependencyIndex < pCreateInfo->dependencyCount; ++dependencyIndex)
            {
                skip |= ValidateFlags("vkCreateRenderPass", ParameterName("pCreateInfo->pDependencies[%i].srcStageMask", ParameterName::IndexVector{ dependencyIndex }), "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, pCreateInfo->pDependencies[dependencyIndex].srcStageMask, kOptionalFlags, "VUID-VkSubpassDependency-srcStageMask-parameter");

                skip |= ValidateFlags("vkCreateRenderPass", ParameterName("pCreateInfo->pDependencies[%i].dstStageMask", ParameterName::IndexVector{ dependencyIndex }), "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, pCreateInfo->pDependencies[dependencyIndex].dstStageMask, kOptionalFlags, "VUID-VkSubpassDependency-dstStageMask-parameter");

                skip |= ValidateFlags("vkCreateRenderPass", ParameterName("pCreateInfo->pDependencies[%i].srcAccessMask", ParameterName::IndexVector{ dependencyIndex }), "VkAccessFlagBits", AllVkAccessFlagBits, pCreateInfo->pDependencies[dependencyIndex].srcAccessMask, kOptionalFlags, "VUID-VkSubpassDependency-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCreateRenderPass", ParameterName("pCreateInfo->pDependencies[%i].dstAccessMask", ParameterName::IndexVector{ dependencyIndex }), "VkAccessFlagBits", AllVkAccessFlagBits, pCreateInfo->pDependencies[dependencyIndex].dstAccessMask, kOptionalFlags, "VUID-VkSubpassDependency-dstAccessMask-parameter");

                skip |= ValidateFlags("vkCreateRenderPass", ParameterName("pCreateInfo->pDependencies[%i].dependencyFlags", ParameterName::IndexVector{ dependencyIndex }), "VkDependencyFlagBits", AllVkDependencyFlagBits, pCreateInfo->pDependencies[dependencyIndex].dependencyFlags, kOptionalFlags, "VUID-VkSubpassDependency-dependencyFlags-parameter");
            }
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateRenderPass-pAllocator-null", "vkCreateRenderPass(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateRenderPass", "pRenderPass", pRenderPass, "VUID-vkCreateRenderPass-pRenderPass-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyRenderPass-pAllocator-null", "vkDestroyRenderPass(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetRenderAreaGranularity(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    VkExtent2D*                                 pGranularity) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkGetRenderAreaGranularity", "renderPass", renderPass);
    skip |= ValidateRequiredPointer("vkGetRenderAreaGranularity", "pGranularity", pGranularity, "VUID-vkGetRenderAreaGranularity-pGranularity-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCommandPool*                              pCommandPool) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateCommandPool", "pCreateInfo", "VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO, true, "VUID-vkCreateCommandPool-pCreateInfo-parameter", "VUID-VkCommandPoolCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkCommandPoolCreateInfo = { VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_RESERVATION_CREATE_INFO };

        skip |= ValidateStructPnext("vkCreateCommandPool", "pCreateInfo->pNext", "VkCommandPoolMemoryReservationCreateInfo", pCreateInfo->pNext, allowed_structs_VkCommandPoolCreateInfo.size(), allowed_structs_VkCommandPoolCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkCommandPoolCreateInfo-pNext-pNext", "VUID-VkCommandPoolCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags("vkCreateCommandPool", "pCreateInfo->flags", "VkCommandPoolCreateFlagBits", AllVkCommandPoolCreateFlagBits, pCreateInfo->flags, kOptionalFlags, "VUID-VkCommandPoolCreateInfo-flags-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateCommandPool-pAllocator-null", "vkCreateCommandPool(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateCommandPool", "pCommandPool", pCommandPool, "VUID-vkCreateCommandPool-pCommandPool-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateResetCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkResetCommandPool", "commandPool", commandPool);
    skip |= ValidateReservedFlags("vkResetCommandPool", "flags", flags, "VUID-vkResetCommandPool-flags-zerobitmask");
    return skip;
}

bool StatelessValidation::PreCallValidateAllocateCommandBuffers(
    VkDevice                                    device,
    const VkCommandBufferAllocateInfo*          pAllocateInfo,
    VkCommandBuffer*                            pCommandBuffers) const {
    bool skip = false;
    skip |= ValidateStructType("vkAllocateCommandBuffers", "pAllocateInfo", "VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO", pAllocateInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO, true, "VUID-vkAllocateCommandBuffers-pAllocateInfo-parameter", "VUID-VkCommandBufferAllocateInfo-sType-sType");
    if (pAllocateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkAllocateCommandBuffers", "pAllocateInfo->pNext", nullptr, pAllocateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCommandBufferAllocateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkAllocateCommandBuffers", "pAllocateInfo->commandPool", pAllocateInfo->commandPool);

        skip |= ValidateRangedEnum("vkAllocateCommandBuffers", "pAllocateInfo->level", "VkCommandBufferLevel", pAllocateInfo->level, "VUID-VkCommandBufferAllocateInfo-level-parameter");
    }
    if (pAllocateInfo != nullptr) {
        skip |= ValidateArray("vkAllocateCommandBuffers", "pAllocateInfo->commandBufferCount", "pCommandBuffers", pAllocateInfo->commandBufferCount, &pCommandBuffers, true, true, "VUID-vkAllocateCommandBuffers-pAllocateInfo::commandBufferCount-arraylength", "VUID-vkAllocateCommandBuffers-pCommandBuffers-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateFreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkFreeCommandBuffers", "commandPool", commandPool);
    skip |= ValidateArray("vkFreeCommandBuffers", "commandBufferCount", "", commandBufferCount, &pCommandBuffers, true, false, "VUID-vkFreeCommandBuffers-commandBufferCount-arraylength", kVUIDUndefined);
    return skip;
}

bool StatelessValidation::PreCallValidateBeginCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkBeginCommandBuffer", "pBeginInfo", "VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO", pBeginInfo, VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, true, "VUID-vkBeginCommandBuffer-pBeginInfo-parameter", "VUID-VkCommandBufferBeginInfo-sType-sType");
    if (pBeginInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkCommandBufferBeginInfo = { VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO };

        skip |= ValidateStructPnext("vkBeginCommandBuffer", "pBeginInfo->pNext", "VkDeviceGroupCommandBufferBeginInfo", pBeginInfo->pNext, allowed_structs_VkCommandBufferBeginInfo.size(), allowed_structs_VkCommandBufferBeginInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkCommandBufferBeginInfo-pNext-pNext", "VUID-VkCommandBufferBeginInfo-sType-unique", false, true);

        skip |= ValidateFlags("vkBeginCommandBuffer", "pBeginInfo->flags", "VkCommandBufferUsageFlagBits", AllVkCommandBufferUsageFlagBits, pBeginInfo->flags, kOptionalFlags, "VUID-VkCommandBufferBeginInfo-flags-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateBeginCommandBuffer(commandBuffer, pBeginInfo);
    return skip;
}

bool StatelessValidation::PreCallValidateEndCommandBuffer(
    VkCommandBuffer                             commandBuffer) const {
    bool skip = false;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateResetCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags) const {
    bool skip = false;
    skip |= ValidateFlags("vkResetCommandBuffer", "flags", "VkCommandBufferResetFlagBits", AllVkCommandBufferResetFlagBits, flags, kOptionalFlags, "VUID-vkResetCommandBuffer-flags-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline) const {
    bool skip = false;
    skip |= ValidateRangedEnum("vkCmdBindPipeline", "pipelineBindPoint", "VkPipelineBindPoint", pipelineBindPoint, "VUID-vkCmdBindPipeline-pipelineBindPoint-parameter");
    skip |= ValidateRequiredHandle("vkCmdBindPipeline", "pipeline", pipeline);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) const {
    bool skip = false;
    skip |= ValidateArray("vkCmdSetViewport", "viewportCount", "pViewports", viewportCount, &pViewports, true, true, "VUID-vkCmdSetViewport-viewportCount-arraylength", "VUID-vkCmdSetViewport-pViewports-parameter");
    if (pViewports != nullptr)
    {
        for (uint32_t viewportIndex = 0; viewportIndex < viewportCount; ++viewportIndex)
        {
            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) const {
    bool skip = false;
    skip |= ValidateArray("vkCmdSetScissor", "scissorCount", "pScissors", scissorCount, &pScissors, true, true, "VUID-vkCmdSetScissor-scissorCount-arraylength", "VUID-vkCmdSetScissor-pScissors-parameter");
    if (pScissors != nullptr)
    {
        for (uint32_t scissorIndex = 0; scissorIndex < scissorCount; ++scissorIndex)
        {
            // No xml-driven validation

            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth) const {
    bool skip = false;
    // No xml-driven validation
    if (!skip) skip |= manual_PreCallValidateCmdSetLineWidth(commandBuffer, lineWidth);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor) const {
    bool skip = false;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4]) const {
    bool skip = false;
    skip |= ValidateRequiredPointer("vkCmdSetBlendConstants", "blendConstants", blendConstants, kVUIDUndefined);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds) const {
    bool skip = false;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask) const {
    bool skip = false;
    skip |= ValidateFlags("vkCmdSetStencilCompareMask", "faceMask", "VkStencilFaceFlagBits", AllVkStencilFaceFlagBits, faceMask, kRequiredFlags, "VUID-vkCmdSetStencilCompareMask-faceMask-parameter", "VUID-vkCmdSetStencilCompareMask-faceMask-requiredbitmask");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask) const {
    bool skip = false;
    skip |= ValidateFlags("vkCmdSetStencilWriteMask", "faceMask", "VkStencilFaceFlagBits", AllVkStencilFaceFlagBits, faceMask, kRequiredFlags, "VUID-vkCmdSetStencilWriteMask-faceMask-parameter", "VUID-vkCmdSetStencilWriteMask-faceMask-requiredbitmask");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference) const {
    bool skip = false;
    skip |= ValidateFlags("vkCmdSetStencilReference", "faceMask", "VkStencilFaceFlagBits", AllVkStencilFaceFlagBits, faceMask, kRequiredFlags, "VUID-vkCmdSetStencilReference-faceMask-parameter", "VUID-vkCmdSetStencilReference-faceMask-requiredbitmask");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets) const {
    bool skip = false;
    skip |= ValidateRangedEnum("vkCmdBindDescriptorSets", "pipelineBindPoint", "VkPipelineBindPoint", pipelineBindPoint, "VUID-vkCmdBindDescriptorSets-pipelineBindPoint-parameter");
    skip |= ValidateRequiredHandle("vkCmdBindDescriptorSets", "layout", layout);
    skip |= ValidateArray("vkCmdBindDescriptorSets", "descriptorSetCount", "pDescriptorSets", descriptorSetCount, &pDescriptorSets, true, false, "VUID-vkCmdBindDescriptorSets-descriptorSetCount-arraylength", "VUID-vkCmdBindDescriptorSets-pDescriptorSets-parameter");
    skip |= ValidateArray("vkCmdBindDescriptorSets", "dynamicOffsetCount", "pDynamicOffsets", dynamicOffsetCount, &pDynamicOffsets, false, true, kVUIDUndefined, "VUID-vkCmdBindDescriptorSets-pDynamicOffsets-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdBindIndexBuffer", "buffer", buffer);
    skip |= ValidateRangedEnum("vkCmdBindIndexBuffer", "indexType", "VkIndexType", indexType, "VUID-vkCmdBindIndexBuffer-indexType-parameter");
    if (!skip) skip |= manual_PreCallValidateCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets) const {
    bool skip = false;
    skip |= ValidateArray("vkCmdBindVertexBuffers", "bindingCount", "pBuffers", bindingCount, &pBuffers, true, false, "VUID-vkCmdBindVertexBuffers-bindingCount-arraylength", "VUID-vkCmdBindVertexBuffers-pBuffers-parameter");
    skip |= ValidateArray("vkCmdBindVertexBuffers", "bindingCount", "pOffsets", bindingCount, &pOffsets, true, true, "VUID-vkCmdBindVertexBuffers-bindingCount-arraylength", "VUID-vkCmdBindVertexBuffers-pOffsets-parameter");
    if (!skip) skip |= manual_PreCallValidateCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance) const {
    bool skip = false;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance) const {
    bool skip = false;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdDrawIndirect", "buffer", buffer);
    if (!skip) skip |= manual_PreCallValidateCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdDrawIndexedIndirect", "buffer", buffer);
    if (!skip) skip |= manual_PreCallValidateCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) const {
    bool skip = false;
    // No xml-driven validation
    if (!skip) skip |= manual_PreCallValidateCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdDispatchIndirect", "buffer", buffer);
    if (!skip) skip |= manual_PreCallValidateCmdDispatchIndirect(commandBuffer, buffer, offset);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdCopyBuffer", "srcBuffer", srcBuffer);
    skip |= ValidateRequiredHandle("vkCmdCopyBuffer", "dstBuffer", dstBuffer);
    skip |= ValidateArray("vkCmdCopyBuffer", "regionCount", "pRegions", regionCount, &pRegions, true, true, "VUID-vkCmdCopyBuffer-regionCount-arraylength", "VUID-vkCmdCopyBuffer-pRegions-parameter");
    if (pRegions != nullptr)
    {
        for (uint32_t regionIndex = 0; regionIndex < regionCount; ++regionIndex)
        {
            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdCopyImage", "srcImage", srcImage);
    skip |= ValidateRangedEnum("vkCmdCopyImage", "srcImageLayout", "VkImageLayout", srcImageLayout, "VUID-vkCmdCopyImage-srcImageLayout-parameter");
    skip |= ValidateRequiredHandle("vkCmdCopyImage", "dstImage", dstImage);
    skip |= ValidateRangedEnum("vkCmdCopyImage", "dstImageLayout", "VkImageLayout", dstImageLayout, "VUID-vkCmdCopyImage-dstImageLayout-parameter");
    skip |= ValidateArray("vkCmdCopyImage", "regionCount", "pRegions", regionCount, &pRegions, true, true, "VUID-vkCmdCopyImage-regionCount-arraylength", "VUID-vkCmdCopyImage-pRegions-parameter");
    if (pRegions != nullptr)
    {
        for (uint32_t regionIndex = 0; regionIndex < regionCount; ++regionIndex)
        {
            skip |= ValidateFlags("vkCmdCopyImage", ParameterName("pRegions[%i].srcSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            // No xml-driven validation

            skip |= ValidateFlags("vkCmdCopyImage", ParameterName("pRegions[%i].dstSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            // No xml-driven validation

            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdBlitImage", "srcImage", srcImage);
    skip |= ValidateRangedEnum("vkCmdBlitImage", "srcImageLayout", "VkImageLayout", srcImageLayout, "VUID-vkCmdBlitImage-srcImageLayout-parameter");
    skip |= ValidateRequiredHandle("vkCmdBlitImage", "dstImage", dstImage);
    skip |= ValidateRangedEnum("vkCmdBlitImage", "dstImageLayout", "VkImageLayout", dstImageLayout, "VUID-vkCmdBlitImage-dstImageLayout-parameter");
    skip |= ValidateArray("vkCmdBlitImage", "regionCount", "pRegions", regionCount, &pRegions, true, true, "VUID-vkCmdBlitImage-regionCount-arraylength", "VUID-vkCmdBlitImage-pRegions-parameter");
    if (pRegions != nullptr)
    {
        for (uint32_t regionIndex = 0; regionIndex < regionCount; ++regionIndex)
        {
            skip |= ValidateFlags("vkCmdBlitImage", ParameterName("pRegions[%i].srcSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            skip |= ValidateFlags("vkCmdBlitImage", ParameterName("pRegions[%i].dstSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");
        }
    }
    skip |= ValidateRangedEnum("vkCmdBlitImage", "filter", "VkFilter", filter, "VUID-vkCmdBlitImage-filter-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdCopyBufferToImage", "srcBuffer", srcBuffer);
    skip |= ValidateRequiredHandle("vkCmdCopyBufferToImage", "dstImage", dstImage);
    skip |= ValidateRangedEnum("vkCmdCopyBufferToImage", "dstImageLayout", "VkImageLayout", dstImageLayout, "VUID-vkCmdCopyBufferToImage-dstImageLayout-parameter");
    skip |= ValidateArray("vkCmdCopyBufferToImage", "regionCount", "pRegions", regionCount, &pRegions, true, true, "VUID-vkCmdCopyBufferToImage-regionCount-arraylength", "VUID-vkCmdCopyBufferToImage-pRegions-parameter");
    if (pRegions != nullptr)
    {
        for (uint32_t regionIndex = 0; regionIndex < regionCount; ++regionIndex)
        {
            skip |= ValidateFlags("vkCmdCopyBufferToImage", ParameterName("pRegions[%i].imageSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pRegions[regionIndex].imageSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            // No xml-driven validation

            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdCopyImageToBuffer", "srcImage", srcImage);
    skip |= ValidateRangedEnum("vkCmdCopyImageToBuffer", "srcImageLayout", "VkImageLayout", srcImageLayout, "VUID-vkCmdCopyImageToBuffer-srcImageLayout-parameter");
    skip |= ValidateRequiredHandle("vkCmdCopyImageToBuffer", "dstBuffer", dstBuffer);
    skip |= ValidateArray("vkCmdCopyImageToBuffer", "regionCount", "pRegions", regionCount, &pRegions, true, true, "VUID-vkCmdCopyImageToBuffer-regionCount-arraylength", "VUID-vkCmdCopyImageToBuffer-pRegions-parameter");
    if (pRegions != nullptr)
    {
        for (uint32_t regionIndex = 0; regionIndex < regionCount; ++regionIndex)
        {
            skip |= ValidateFlags("vkCmdCopyImageToBuffer", ParameterName("pRegions[%i].imageSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pRegions[regionIndex].imageSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            // No xml-driven validation

            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdUpdateBuffer", "dstBuffer", dstBuffer);
    skip |= ValidateArray("vkCmdUpdateBuffer", "dataSize", "pData", dataSize, &pData, true, true, "VUID-vkCmdUpdateBuffer-dataSize-arraylength", "VUID-vkCmdUpdateBuffer-pData-parameter");
    if (!skip) skip |= manual_PreCallValidateCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdFillBuffer", "dstBuffer", dstBuffer);
    if (!skip) skip |= manual_PreCallValidateCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdClearColorImage", "image", image);
    skip |= ValidateRangedEnum("vkCmdClearColorImage", "imageLayout", "VkImageLayout", imageLayout, "VUID-vkCmdClearColorImage-imageLayout-parameter");
    skip |= ValidateArray("vkCmdClearColorImage", "rangeCount", "pRanges", rangeCount, &pRanges, true, true, "VUID-vkCmdClearColorImage-rangeCount-arraylength", "VUID-vkCmdClearColorImage-pRanges-parameter");
    if (pRanges != nullptr)
    {
        for (uint32_t rangeIndex = 0; rangeIndex < rangeCount; ++rangeIndex)
        {
            skip |= ValidateFlags("vkCmdClearColorImage", ParameterName("pRanges[%i].aspectMask", ParameterName::IndexVector{ rangeIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pRanges[rangeIndex].aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdClearDepthStencilImage", "image", image);
    skip |= ValidateRangedEnum("vkCmdClearDepthStencilImage", "imageLayout", "VkImageLayout", imageLayout, "VUID-vkCmdClearDepthStencilImage-imageLayout-parameter");
    skip |= ValidateRequiredPointer("vkCmdClearDepthStencilImage", "pDepthStencil", pDepthStencil, "VUID-vkCmdClearDepthStencilImage-pDepthStencil-parameter");
    if (pDepthStencil != nullptr)
    {
        // No xml-driven validation
    }
    skip |= ValidateArray("vkCmdClearDepthStencilImage", "rangeCount", "pRanges", rangeCount, &pRanges, true, true, "VUID-vkCmdClearDepthStencilImage-rangeCount-arraylength", "VUID-vkCmdClearDepthStencilImage-pRanges-parameter");
    if (pRanges != nullptr)
    {
        for (uint32_t rangeIndex = 0; rangeIndex < rangeCount; ++rangeIndex)
        {
            skip |= ValidateFlags("vkCmdClearDepthStencilImage", ParameterName("pRanges[%i].aspectMask", ParameterName::IndexVector{ rangeIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pRanges[rangeIndex].aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects) const {
    bool skip = false;
    skip |= ValidateArray("vkCmdClearAttachments", "attachmentCount", "pAttachments", attachmentCount, &pAttachments, true, true, "VUID-vkCmdClearAttachments-attachmentCount-arraylength", "VUID-vkCmdClearAttachments-pAttachments-parameter");
    if (pAttachments != nullptr)
    {
        for (uint32_t attachmentIndex = 0; attachmentIndex < attachmentCount; ++attachmentIndex)
        {
            skip |= ValidateFlags("vkCmdClearAttachments", ParameterName("pAttachments[%i].aspectMask", ParameterName::IndexVector{ attachmentIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pAttachments[attachmentIndex].aspectMask, kRequiredFlags, "VUID-VkClearAttachment-aspectMask-parameter", "VUID-VkClearAttachment-aspectMask-requiredbitmask");
        }
    }
    skip |= ValidateArray("vkCmdClearAttachments", "rectCount", "pRects", rectCount, &pRects, true, true, "VUID-vkCmdClearAttachments-rectCount-arraylength", "VUID-vkCmdClearAttachments-pRects-parameter");
    if (pRects != nullptr)
    {
        for (uint32_t rectIndex = 0; rectIndex < rectCount; ++rectIndex)
        {
            // No xml-driven validation

            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdResolveImage", "srcImage", srcImage);
    skip |= ValidateRangedEnum("vkCmdResolveImage", "srcImageLayout", "VkImageLayout", srcImageLayout, "VUID-vkCmdResolveImage-srcImageLayout-parameter");
    skip |= ValidateRequiredHandle("vkCmdResolveImage", "dstImage", dstImage);
    skip |= ValidateRangedEnum("vkCmdResolveImage", "dstImageLayout", "VkImageLayout", dstImageLayout, "VUID-vkCmdResolveImage-dstImageLayout-parameter");
    skip |= ValidateArray("vkCmdResolveImage", "regionCount", "pRegions", regionCount, &pRegions, true, true, "VUID-vkCmdResolveImage-regionCount-arraylength", "VUID-vkCmdResolveImage-pRegions-parameter");
    if (pRegions != nullptr)
    {
        for (uint32_t regionIndex = 0; regionIndex < regionCount; ++regionIndex)
        {
            skip |= ValidateFlags("vkCmdResolveImage", ParameterName("pRegions[%i].srcSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            // No xml-driven validation

            skip |= ValidateFlags("vkCmdResolveImage", ParameterName("pRegions[%i].dstSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            // No xml-driven validation

            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdSetEvent", "event", event);
    skip |= ValidateFlags("vkCmdSetEvent", "stageMask", "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, stageMask, kOptionalFlags, "VUID-vkCmdSetEvent-stageMask-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdResetEvent", "event", event);
    skip |= ValidateFlags("vkCmdResetEvent", "stageMask", "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, stageMask, kOptionalFlags, "VUID-vkCmdResetEvent-stageMask-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWaitEvents(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers) const {
    bool skip = false;
    skip |= ValidateHandleArray("vkCmdWaitEvents", "eventCount", "pEvents", eventCount, pEvents, true, true, "VUID-vkCmdWaitEvents-eventCount-arraylength");
    skip |= ValidateFlags("vkCmdWaitEvents", "srcStageMask", "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, srcStageMask, kOptionalFlags, "VUID-vkCmdWaitEvents-srcStageMask-parameter");
    skip |= ValidateFlags("vkCmdWaitEvents", "dstStageMask", "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, dstStageMask, kOptionalFlags, "VUID-vkCmdWaitEvents-dstStageMask-parameter");
    skip |= ValidateStructTypeArray("vkCmdWaitEvents", "memoryBarrierCount", "pMemoryBarriers", "VK_STRUCTURE_TYPE_MEMORY_BARRIER", memoryBarrierCount, pMemoryBarriers, VK_STRUCTURE_TYPE_MEMORY_BARRIER, false, true, "VUID-VkMemoryBarrier-sType-sType", "VUID-vkCmdWaitEvents-pMemoryBarriers-parameter", kVUIDUndefined);
    if (pMemoryBarriers != nullptr)
    {
        for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < memoryBarrierCount; ++memoryBarrierIndex)
        {
            skip |= ValidateStructPnext("vkCmdWaitEvents", ParameterName("pMemoryBarriers[%i].pNext", ParameterName::IndexVector{ memoryBarrierIndex }), nullptr, pMemoryBarriers[memoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkMemoryBarrier-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateFlags("vkCmdWaitEvents", ParameterName("pMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkAccessFlagBits", AllVkAccessFlagBits, pMemoryBarriers[memoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier-srcAccessMask-parameter");

            skip |= ValidateFlags("vkCmdWaitEvents", ParameterName("pMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkAccessFlagBits", AllVkAccessFlagBits, pMemoryBarriers[memoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier-dstAccessMask-parameter");
        }
    }
    skip |= ValidateStructTypeArray("vkCmdWaitEvents", "bufferMemoryBarrierCount", "pBufferMemoryBarriers", "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER", bufferMemoryBarrierCount, pBufferMemoryBarriers, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER, false, true, "VUID-VkBufferMemoryBarrier-sType-sType", "VUID-vkCmdWaitEvents-pBufferMemoryBarriers-parameter", kVUIDUndefined);
    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t bufferMemoryBarrierIndex = 0; bufferMemoryBarrierIndex < bufferMemoryBarrierCount; ++bufferMemoryBarrierIndex)
        {
            skip |= ValidateStructPnext("vkCmdWaitEvents", ParameterName("pBufferMemoryBarriers[%i].pNext", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), nullptr, pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateRequiredHandle("vkCmdWaitEvents", ParameterName("pBufferMemoryBarriers[%i].buffer", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
        }
    }
    skip |= ValidateStructTypeArray("vkCmdWaitEvents", "imageMemoryBarrierCount", "pImageMemoryBarriers", "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER", imageMemoryBarrierCount, pImageMemoryBarriers, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER, false, true, "VUID-VkImageMemoryBarrier-sType-sType", "VUID-vkCmdWaitEvents-pImageMemoryBarriers-parameter", kVUIDUndefined);
    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t imageMemoryBarrierIndex = 0; imageMemoryBarrierIndex < imageMemoryBarrierCount; ++imageMemoryBarrierIndex)
        {
            constexpr std::array allowed_structs_VkImageMemoryBarrier = { VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT };

            skip |= ValidateStructPnext("vkCmdWaitEvents", ParameterName("pImageMemoryBarriers[%i].pNext", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkSampleLocationsInfoEXT", pImageMemoryBarriers[imageMemoryBarrierIndex].pNext, allowed_structs_VkImageMemoryBarrier.size(), allowed_structs_VkImageMemoryBarrier.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier-pNext-pNext", "VUID-VkImageMemoryBarrier-sType-unique", false, true);

            skip |= ValidateRangedEnum("vkCmdWaitEvents", ParameterName("pImageMemoryBarriers[%i].oldLayout", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageLayout", pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout, "VUID-VkImageMemoryBarrier-oldLayout-parameter");

            skip |= ValidateRangedEnum("vkCmdWaitEvents", ParameterName("pImageMemoryBarriers[%i].newLayout", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageLayout", pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout, "VUID-VkImageMemoryBarrier-newLayout-parameter");

            skip |= ValidateRequiredHandle("vkCmdWaitEvents", ParameterName("pImageMemoryBarriers[%i].image", ParameterName::IndexVector{ imageMemoryBarrierIndex }), pImageMemoryBarriers[imageMemoryBarrierIndex].image);

            skip |= ValidateFlags("vkCmdWaitEvents", ParameterName("pImageMemoryBarriers[%i].subresourceRange.aspectMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers) const {
    bool skip = false;
    skip |= ValidateFlags("vkCmdPipelineBarrier", "srcStageMask", "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, srcStageMask, kOptionalFlags, "VUID-vkCmdPipelineBarrier-srcStageMask-parameter");
    skip |= ValidateFlags("vkCmdPipelineBarrier", "dstStageMask", "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, dstStageMask, kOptionalFlags, "VUID-vkCmdPipelineBarrier-dstStageMask-parameter");
    skip |= ValidateFlags("vkCmdPipelineBarrier", "dependencyFlags", "VkDependencyFlagBits", AllVkDependencyFlagBits, dependencyFlags, kOptionalFlags, "VUID-vkCmdPipelineBarrier-dependencyFlags-parameter");
    skip |= ValidateStructTypeArray("vkCmdPipelineBarrier", "memoryBarrierCount", "pMemoryBarriers", "VK_STRUCTURE_TYPE_MEMORY_BARRIER", memoryBarrierCount, pMemoryBarriers, VK_STRUCTURE_TYPE_MEMORY_BARRIER, false, true, "VUID-VkMemoryBarrier-sType-sType", "VUID-vkCmdPipelineBarrier-pMemoryBarriers-parameter", kVUIDUndefined);
    if (pMemoryBarriers != nullptr)
    {
        for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < memoryBarrierCount; ++memoryBarrierIndex)
        {
            skip |= ValidateStructPnext("vkCmdPipelineBarrier", ParameterName("pMemoryBarriers[%i].pNext", ParameterName::IndexVector{ memoryBarrierIndex }), nullptr, pMemoryBarriers[memoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkMemoryBarrier-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateFlags("vkCmdPipelineBarrier", ParameterName("pMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkAccessFlagBits", AllVkAccessFlagBits, pMemoryBarriers[memoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier-srcAccessMask-parameter");

            skip |= ValidateFlags("vkCmdPipelineBarrier", ParameterName("pMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkAccessFlagBits", AllVkAccessFlagBits, pMemoryBarriers[memoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier-dstAccessMask-parameter");
        }
    }
    skip |= ValidateStructTypeArray("vkCmdPipelineBarrier", "bufferMemoryBarrierCount", "pBufferMemoryBarriers", "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER", bufferMemoryBarrierCount, pBufferMemoryBarriers, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER, false, true, "VUID-VkBufferMemoryBarrier-sType-sType", "VUID-vkCmdPipelineBarrier-pBufferMemoryBarriers-parameter", kVUIDUndefined);
    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t bufferMemoryBarrierIndex = 0; bufferMemoryBarrierIndex < bufferMemoryBarrierCount; ++bufferMemoryBarrierIndex)
        {
            skip |= ValidateStructPnext("vkCmdPipelineBarrier", ParameterName("pBufferMemoryBarriers[%i].pNext", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), nullptr, pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateRequiredHandle("vkCmdPipelineBarrier", ParameterName("pBufferMemoryBarriers[%i].buffer", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
        }
    }
    skip |= ValidateStructTypeArray("vkCmdPipelineBarrier", "imageMemoryBarrierCount", "pImageMemoryBarriers", "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER", imageMemoryBarrierCount, pImageMemoryBarriers, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER, false, true, "VUID-VkImageMemoryBarrier-sType-sType", "VUID-vkCmdPipelineBarrier-pImageMemoryBarriers-parameter", kVUIDUndefined);
    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t imageMemoryBarrierIndex = 0; imageMemoryBarrierIndex < imageMemoryBarrierCount; ++imageMemoryBarrierIndex)
        {
            constexpr std::array allowed_structs_VkImageMemoryBarrier = { VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT };

            skip |= ValidateStructPnext("vkCmdPipelineBarrier", ParameterName("pImageMemoryBarriers[%i].pNext", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkSampleLocationsInfoEXT", pImageMemoryBarriers[imageMemoryBarrierIndex].pNext, allowed_structs_VkImageMemoryBarrier.size(), allowed_structs_VkImageMemoryBarrier.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier-pNext-pNext", "VUID-VkImageMemoryBarrier-sType-unique", false, true);

            skip |= ValidateRangedEnum("vkCmdPipelineBarrier", ParameterName("pImageMemoryBarriers[%i].oldLayout", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageLayout", pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout, "VUID-VkImageMemoryBarrier-oldLayout-parameter");

            skip |= ValidateRangedEnum("vkCmdPipelineBarrier", ParameterName("pImageMemoryBarriers[%i].newLayout", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageLayout", pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout, "VUID-VkImageMemoryBarrier-newLayout-parameter");

            skip |= ValidateRequiredHandle("vkCmdPipelineBarrier", ParameterName("pImageMemoryBarriers[%i].image", ParameterName::IndexVector{ imageMemoryBarrierIndex }), pImageMemoryBarriers[imageMemoryBarrierIndex].image);

            skip |= ValidateFlags("vkCmdPipelineBarrier", ParameterName("pImageMemoryBarriers[%i].subresourceRange.aspectMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdBeginQuery", "queryPool", queryPool);
    skip |= ValidateFlags("vkCmdBeginQuery", "flags", "VkQueryControlFlagBits", AllVkQueryControlFlagBits, flags, kOptionalFlags, "VUID-vkCmdBeginQuery-flags-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdEndQuery", "queryPool", queryPool);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdResetQueryPool", "queryPool", queryPool);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) const {
    bool skip = false;
    skip |= ValidateFlags("vkCmdWriteTimestamp", "pipelineStage", "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, pipelineStage, kRequiredSingleBit, "VUID-vkCmdWriteTimestamp-pipelineStage-parameter", "VUID-vkCmdWriteTimestamp-pipelineStage-parameter");
    skip |= ValidateRequiredHandle("vkCmdWriteTimestamp", "queryPool", queryPool);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdCopyQueryPoolResults", "queryPool", queryPool);
    skip |= ValidateRequiredHandle("vkCmdCopyQueryPoolResults", "dstBuffer", dstBuffer);
    skip |= ValidateFlags("vkCmdCopyQueryPoolResults", "flags", "VkQueryResultFlagBits", AllVkQueryResultFlagBits, flags, kOptionalFlags, "VUID-vkCmdCopyQueryPoolResults-flags-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdPushConstants", "layout", layout);
    skip |= ValidateFlags("vkCmdPushConstants", "stageFlags", "VkShaderStageFlagBits", AllVkShaderStageFlagBits, stageFlags, kRequiredFlags, "VUID-vkCmdPushConstants-stageFlags-parameter", "VUID-vkCmdPushConstants-stageFlags-requiredbitmask");
    skip |= ValidateArray("vkCmdPushConstants", "size", "pValues", size, &pValues, true, true, "VUID-vkCmdPushConstants-size-arraylength", "VUID-vkCmdPushConstants-pValues-parameter");
    if (!skip) skip |= manual_PreCallValidateCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents) const {
    bool skip = false;
    skip |= ValidateStructType("vkCmdBeginRenderPass", "pRenderPassBegin", "VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO", pRenderPassBegin, VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO, true, "VUID-vkCmdBeginRenderPass-pRenderPassBegin-parameter", "VUID-VkRenderPassBeginInfo-sType-sType");
    if (pRenderPassBegin != nullptr)
    {
        constexpr std::array allowed_structs_VkRenderPassBeginInfo = { VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO, VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO, VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT };

        skip |= ValidateStructPnext("vkCmdBeginRenderPass", "pRenderPassBegin->pNext", "VkDeviceGroupRenderPassBeginInfo, VkRenderPassAttachmentBeginInfo, VkRenderPassSampleLocationsBeginInfoEXT", pRenderPassBegin->pNext, allowed_structs_VkRenderPassBeginInfo.size(), allowed_structs_VkRenderPassBeginInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkRenderPassBeginInfo-pNext-pNext", "VUID-VkRenderPassBeginInfo-sType-unique", false, true);

        skip |= ValidateRequiredHandle("vkCmdBeginRenderPass", "pRenderPassBegin->renderPass", pRenderPassBegin->renderPass);

        skip |= ValidateRequiredHandle("vkCmdBeginRenderPass", "pRenderPassBegin->framebuffer", pRenderPassBegin->framebuffer);

        // No xml-driven validation

        // No xml-driven validation
    }
    skip |= ValidateRangedEnum("vkCmdBeginRenderPass", "contents", "VkSubpassContents", contents, "VUID-vkCmdBeginRenderPass-contents-parameter");
    if (!skip) skip |= manual_PreCallValidateCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents) const {
    bool skip = false;
    skip |= ValidateRangedEnum("vkCmdNextSubpass", "contents", "VkSubpassContents", contents, "VUID-vkCmdNextSubpass-contents-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdEndRenderPass(
    VkCommandBuffer                             commandBuffer) const {
    bool skip = false;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers) const {
    bool skip = false;
    skip |= ValidateHandleArray("vkCmdExecuteCommands", "commandBufferCount", "pCommandBuffers", commandBufferCount, pCommandBuffers, true, true, "VUID-vkCmdExecuteCommands-commandBufferCount-arraylength");
    return skip;
}



bool StatelessValidation::PreCallValidateBindBufferMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos) const {
    bool skip = false;
    skip |= ValidateStructTypeArray("vkBindBufferMemory2", "bindInfoCount", "pBindInfos", "VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO", bindInfoCount, pBindInfos, VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO, true, true, "VUID-VkBindBufferMemoryInfo-sType-sType", "VUID-vkBindBufferMemory2-pBindInfos-parameter", "VUID-vkBindBufferMemory2-bindInfoCount-arraylength");
    if (pBindInfos != nullptr)
    {
        for (uint32_t bindInfoIndex = 0; bindInfoIndex < bindInfoCount; ++bindInfoIndex)
        {
            constexpr std::array allowed_structs_VkBindBufferMemoryInfo = { VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO };

            skip |= ValidateStructPnext("vkBindBufferMemory2", ParameterName("pBindInfos[%i].pNext", ParameterName::IndexVector{ bindInfoIndex }), "VkBindBufferMemoryDeviceGroupInfo", pBindInfos[bindInfoIndex].pNext, allowed_structs_VkBindBufferMemoryInfo.size(), allowed_structs_VkBindBufferMemoryInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkBindBufferMemoryInfo-pNext-pNext", "VUID-VkBindBufferMemoryInfo-sType-unique", false, true);

            skip |= ValidateRequiredHandle("vkBindBufferMemory2", ParameterName("pBindInfos[%i].buffer", ParameterName::IndexVector{ bindInfoIndex }), pBindInfos[bindInfoIndex].buffer);

            skip |= ValidateRequiredHandle("vkBindBufferMemory2", ParameterName("pBindInfos[%i].memory", ParameterName::IndexVector{ bindInfoIndex }), pBindInfos[bindInfoIndex].memory);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateBindImageMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos) const {
    bool skip = false;
    skip |= ValidateStructTypeArray("vkBindImageMemory2", "bindInfoCount", "pBindInfos", "VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO", bindInfoCount, pBindInfos, VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO, true, true, "VUID-VkBindImageMemoryInfo-sType-sType", "VUID-vkBindImageMemory2-pBindInfos-parameter", "VUID-vkBindImageMemory2-bindInfoCount-arraylength");
    if (pBindInfos != nullptr)
    {
        for (uint32_t bindInfoIndex = 0; bindInfoIndex < bindInfoCount; ++bindInfoIndex)
        {
            constexpr std::array allowed_structs_VkBindImageMemoryInfo = { VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO, VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR, VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO };

            skip |= ValidateStructPnext("vkBindImageMemory2", ParameterName("pBindInfos[%i].pNext", ParameterName::IndexVector{ bindInfoIndex }), "VkBindImageMemoryDeviceGroupInfo, VkBindImageMemorySwapchainInfoKHR, VkBindImagePlaneMemoryInfo", pBindInfos[bindInfoIndex].pNext, allowed_structs_VkBindImageMemoryInfo.size(), allowed_structs_VkBindImageMemoryInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkBindImageMemoryInfo-pNext-pNext", "VUID-VkBindImageMemoryInfo-sType-unique", false, true);

            skip |= ValidateRequiredHandle("vkBindImageMemory2", ParameterName("pBindInfos[%i].image", ParameterName::IndexVector{ bindInfoIndex }), pBindInfos[bindInfoIndex].image);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceGroupPeerMemoryFeatures(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures) const {
    bool skip = false;
    skip |= ValidateRequiredPointer("vkGetDeviceGroupPeerMemoryFeatures", "pPeerMemoryFeatures", pPeerMemoryFeatures, "VUID-vkGetDeviceGroupPeerMemoryFeatures-pPeerMemoryFeatures-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) const {
    bool skip = false;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) const {
    bool skip = false;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateEnumeratePhysicalDeviceGroups(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties) const {
    bool skip = false;
     if (CheckPromotedApiAgainstVulkanVersion(instance, "vkEnumeratePhysicalDeviceGroups", VK_API_VERSION_1_1)) return true;
    skip |= ValidateStructTypeArray("vkEnumeratePhysicalDeviceGroups", "pPhysicalDeviceGroupCount", "pPhysicalDeviceGroupProperties", "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES", pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES, true, false, false, "VUID-VkPhysicalDeviceGroupProperties-sType-sType", "VUID-vkEnumeratePhysicalDeviceGroups-pPhysicalDeviceGroupProperties-parameter", kVUIDUndefined);
    if (pPhysicalDeviceGroupProperties != nullptr)
    {
        for (uint32_t pPhysicalDeviceGroupIndex = 0; pPhysicalDeviceGroupIndex < *pPhysicalDeviceGroupCount; ++pPhysicalDeviceGroupIndex)
        {
            skip |= ValidateStructPnext("vkEnumeratePhysicalDeviceGroups", ParameterName("pPhysicalDeviceGroupProperties[%i].pNext", ParameterName::IndexVector{ pPhysicalDeviceGroupIndex }), nullptr, pPhysicalDeviceGroupProperties[pPhysicalDeviceGroupIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkPhysicalDeviceGroupProperties-pNext-pNext", kVUIDUndefined, false, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetImageMemoryRequirements2(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateStructType("vkGetImageMemoryRequirements2", "pInfo", "VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2", pInfo, VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2, true, "VUID-vkGetImageMemoryRequirements2-pInfo-parameter", "VUID-VkImageMemoryRequirementsInfo2-sType-sType");
    if (pInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkImageMemoryRequirementsInfo2 = { VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO };

        skip |= ValidateStructPnext("vkGetImageMemoryRequirements2", "pInfo->pNext", "VkImagePlaneMemoryRequirementsInfo", pInfo->pNext, allowed_structs_VkImageMemoryRequirementsInfo2.size(), allowed_structs_VkImageMemoryRequirementsInfo2.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryRequirementsInfo2-pNext-pNext", "VUID-VkImageMemoryRequirementsInfo2-sType-unique", false, true);

        skip |= ValidateRequiredHandle("vkGetImageMemoryRequirements2", "pInfo->image", pInfo->image);
    }
    skip |= ValidateStructType("vkGetImageMemoryRequirements2", "pMemoryRequirements", "VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2", pMemoryRequirements, VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, true, "VUID-vkGetImageMemoryRequirements2-pMemoryRequirements-parameter", "VUID-VkMemoryRequirements2-sType-sType");
    if (pMemoryRequirements != nullptr)
    {
        constexpr std::array allowed_structs_VkMemoryRequirements2 = { VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS };

        skip |= ValidateStructPnext("vkGetImageMemoryRequirements2", "pMemoryRequirements->pNext", "VkMemoryDedicatedRequirements", pMemoryRequirements->pNext, allowed_structs_VkMemoryRequirements2.size(), allowed_structs_VkMemoryRequirements2.data(), GeneratedVulkanHeaderVersion, "VUID-VkMemoryRequirements2-pNext-pNext", "VUID-VkMemoryRequirements2-sType-unique", false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetBufferMemoryRequirements2(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateStructType("vkGetBufferMemoryRequirements2", "pInfo", "VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2", pInfo, VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2, true, "VUID-vkGetBufferMemoryRequirements2-pInfo-parameter", "VUID-VkBufferMemoryRequirementsInfo2-sType-sType");
    if (pInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetBufferMemoryRequirements2", "pInfo->pNext", nullptr, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryRequirementsInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkGetBufferMemoryRequirements2", "pInfo->buffer", pInfo->buffer);
    }
    skip |= ValidateStructType("vkGetBufferMemoryRequirements2", "pMemoryRequirements", "VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2", pMemoryRequirements, VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, true, "VUID-vkGetBufferMemoryRequirements2-pMemoryRequirements-parameter", "VUID-VkMemoryRequirements2-sType-sType");
    if (pMemoryRequirements != nullptr)
    {
        constexpr std::array allowed_structs_VkMemoryRequirements2 = { VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS };

        skip |= ValidateStructPnext("vkGetBufferMemoryRequirements2", "pMemoryRequirements->pNext", "VkMemoryDedicatedRequirements", pMemoryRequirements->pNext, allowed_structs_VkMemoryRequirements2.size(), allowed_structs_VkMemoryRequirements2.data(), GeneratedVulkanHeaderVersion, "VUID-VkMemoryRequirements2-pNext-pNext", "VUID-VkMemoryRequirements2-sType-unique", false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceFeatures2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures) const {
    bool skip = false;
     if (CheckPromotedApiAgainstVulkanVersion(physicalDevice, "vkGetPhysicalDeviceFeatures2", VK_API_VERSION_1_1)) return true;
    skip |= ValidateStructType("vkGetPhysicalDeviceFeatures2", "pFeatures", "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2", pFeatures, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, true, "VUID-vkGetPhysicalDeviceFeatures2-pFeatures-parameter", "VUID-VkPhysicalDeviceFeatures2-sType-sType");
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties) const {
    bool skip = false;
     if (CheckPromotedApiAgainstVulkanVersion(physicalDevice, "vkGetPhysicalDeviceProperties2", VK_API_VERSION_1_1)) return true;
    skip |= ValidateStructType("vkGetPhysicalDeviceProperties2", "pProperties", "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2", pProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, true, "VUID-vkGetPhysicalDeviceProperties2-pProperties-parameter", "VUID-VkPhysicalDeviceProperties2-sType-sType");
    if (pProperties != nullptr)
    {
        constexpr std::array allowed_structs_VkPhysicalDeviceProperties2 = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES };

        skip |= ValidateStructPnext("vkGetPhysicalDeviceProperties2", "pProperties->pNext", "VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT, VkPhysicalDeviceConservativeRasterizationPropertiesEXT, VkPhysicalDeviceCustomBorderColorPropertiesEXT, VkPhysicalDeviceDepthStencilResolveProperties, VkPhysicalDeviceDescriptorIndexingProperties, VkPhysicalDeviceDiscardRectanglePropertiesEXT, VkPhysicalDeviceDriverProperties, VkPhysicalDeviceExternalMemoryHostPropertiesEXT, VkPhysicalDeviceFloatControlsProperties, VkPhysicalDeviceFragmentShadingRatePropertiesKHR, VkPhysicalDeviceIDProperties, VkPhysicalDeviceInlineUniformBlockProperties, VkPhysicalDeviceLineRasterizationPropertiesEXT, VkPhysicalDeviceMaintenance3Properties, VkPhysicalDeviceMaintenance4Properties, VkPhysicalDeviceMultiviewProperties, VkPhysicalDevicePCIBusInfoPropertiesEXT, VkPhysicalDevicePerformanceQueryPropertiesKHR, VkPhysicalDevicePointClippingProperties, VkPhysicalDeviceProtectedMemoryProperties, VkPhysicalDeviceRobustness2PropertiesEXT, VkPhysicalDeviceSampleLocationsPropertiesEXT, VkPhysicalDeviceSamplerFilterMinmaxProperties, VkPhysicalDeviceShaderIntegerDotProductProperties, VkPhysicalDeviceSubgroupProperties, VkPhysicalDeviceSubgroupSizeControlProperties, VkPhysicalDeviceTexelBufferAlignmentProperties, VkPhysicalDeviceTimelineSemaphoreProperties, VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT, VkPhysicalDeviceVulkan11Properties, VkPhysicalDeviceVulkan12Properties, VkPhysicalDeviceVulkan13Properties, VkPhysicalDeviceVulkanSC10Properties", pProperties->pNext, allowed_structs_VkPhysicalDeviceProperties2.size(), allowed_structs_VkPhysicalDeviceProperties2.data(), GeneratedVulkanHeaderVersion, "VUID-VkPhysicalDeviceProperties2-pNext-pNext", "VUID-VkPhysicalDeviceProperties2-sType-unique", true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties) const {
    bool skip = false;
     if (CheckPromotedApiAgainstVulkanVersion(physicalDevice, "vkGetPhysicalDeviceFormatProperties2", VK_API_VERSION_1_1)) return true;
    skip |= ValidateRangedEnum("vkGetPhysicalDeviceFormatProperties2", "format", "VkFormat", format, "VUID-vkGetPhysicalDeviceFormatProperties2-format-parameter");
    skip |= ValidateStructType("vkGetPhysicalDeviceFormatProperties2", "pFormatProperties", "VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2", pFormatProperties, VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2, true, "VUID-vkGetPhysicalDeviceFormatProperties2-pFormatProperties-parameter", "VUID-VkFormatProperties2-sType-sType");
    if (pFormatProperties != nullptr)
    {
        constexpr std::array allowed_structs_VkFormatProperties2 = { VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT, VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT, VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3 };

        skip |= ValidateStructPnext("vkGetPhysicalDeviceFormatProperties2", "pFormatProperties->pNext", "VkDrmFormatModifierPropertiesList2EXT, VkDrmFormatModifierPropertiesListEXT, VkFormatProperties3", pFormatProperties->pNext, allowed_structs_VkFormatProperties2.size(), allowed_structs_VkFormatProperties2.data(), GeneratedVulkanHeaderVersion, "VUID-VkFormatProperties2-pNext-pNext", "VUID-VkFormatProperties2-sType-unique", true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties) const {
    bool skip = false;
     if (CheckPromotedApiAgainstVulkanVersion(physicalDevice, "vkGetPhysicalDeviceImageFormatProperties2", VK_API_VERSION_1_1)) return true;
    skip |= ValidateStructType("vkGetPhysicalDeviceImageFormatProperties2", "pImageFormatInfo", "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2", pImageFormatInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2, true, "VUID-vkGetPhysicalDeviceImageFormatProperties2-pImageFormatInfo-parameter", "VUID-VkPhysicalDeviceImageFormatInfo2-sType-sType");
    if (pImageFormatInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkPhysicalDeviceImageFormatInfo2 = { VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO, VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT };

        skip |= ValidateStructPnext("vkGetPhysicalDeviceImageFormatProperties2", "pImageFormatInfo->pNext", "VkImageFormatListCreateInfo, VkImageStencilUsageCreateInfo, VkPhysicalDeviceExternalImageFormatInfo, VkPhysicalDeviceImageDrmFormatModifierInfoEXT, VkPhysicalDeviceImageViewImageFormatInfoEXT", pImageFormatInfo->pNext, allowed_structs_VkPhysicalDeviceImageFormatInfo2.size(), allowed_structs_VkPhysicalDeviceImageFormatInfo2.data(), GeneratedVulkanHeaderVersion, "VUID-VkPhysicalDeviceImageFormatInfo2-pNext-pNext", "VUID-VkPhysicalDeviceImageFormatInfo2-sType-unique", true, true);

        skip |= ValidateRangedEnum("vkGetPhysicalDeviceImageFormatProperties2", "pImageFormatInfo->format", "VkFormat", pImageFormatInfo->format, "VUID-VkPhysicalDeviceImageFormatInfo2-format-parameter");

        skip |= ValidateRangedEnum("vkGetPhysicalDeviceImageFormatProperties2", "pImageFormatInfo->type", "VkImageType", pImageFormatInfo->type, "VUID-VkPhysicalDeviceImageFormatInfo2-type-parameter");

        skip |= ValidateRangedEnum("vkGetPhysicalDeviceImageFormatProperties2", "pImageFormatInfo->tiling", "VkImageTiling", pImageFormatInfo->tiling, "VUID-VkPhysicalDeviceImageFormatInfo2-tiling-parameter");

        skip |= ValidateFlags("vkGetPhysicalDeviceImageFormatProperties2", "pImageFormatInfo->usage", "VkImageUsageFlagBits", AllVkImageUsageFlagBits, pImageFormatInfo->usage, kRequiredFlags, "VUID-VkPhysicalDeviceImageFormatInfo2-usage-parameter", "VUID-VkPhysicalDeviceImageFormatInfo2-usage-requiredbitmask");

        skip |= ValidateFlags("vkGetPhysicalDeviceImageFormatProperties2", "pImageFormatInfo->flags", "VkImageCreateFlagBits", AllVkImageCreateFlagBits, pImageFormatInfo->flags, kOptionalFlags, "VUID-VkPhysicalDeviceImageFormatInfo2-flags-parameter");
    }
    skip |= ValidateStructType("vkGetPhysicalDeviceImageFormatProperties2", "pImageFormatProperties", "VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2", pImageFormatProperties, VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2, true, "VUID-vkGetPhysicalDeviceImageFormatProperties2-pImageFormatProperties-parameter", "VUID-VkImageFormatProperties2-sType-sType");
    if (pImageFormatProperties != nullptr)
    {
        constexpr std::array allowed_structs_VkImageFormatProperties2 = { VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES, VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES };

        skip |= ValidateStructPnext("vkGetPhysicalDeviceImageFormatProperties2", "pImageFormatProperties->pNext", "VkExternalImageFormatProperties, VkFilterCubicImageViewImageFormatPropertiesEXT, VkSamplerYcbcrConversionImageFormatProperties", pImageFormatProperties->pNext, allowed_structs_VkImageFormatProperties2.size(), allowed_structs_VkImageFormatProperties2.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageFormatProperties2-pNext-pNext", "VUID-VkImageFormatProperties2-sType-unique", true, false);
    }
    if (!skip) skip |= manual_PreCallValidateGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceQueueFamilyProperties2(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties) const {
    bool skip = false;
     if (CheckPromotedApiAgainstVulkanVersion(physicalDevice, "vkGetPhysicalDeviceQueueFamilyProperties2", VK_API_VERSION_1_1)) return true;
    skip |= ValidateStructTypeArray("vkGetPhysicalDeviceQueueFamilyProperties2", "pQueueFamilyPropertyCount", "pQueueFamilyProperties", "VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2", pQueueFamilyPropertyCount, pQueueFamilyProperties, VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2, true, false, false, "VUID-VkQueueFamilyProperties2-sType-sType", "VUID-vkGetPhysicalDeviceQueueFamilyProperties2-pQueueFamilyProperties-parameter", kVUIDUndefined);
    if (pQueueFamilyProperties != nullptr)
    {
        for (uint32_t pQueueFamilyPropertyIndex = 0; pQueueFamilyPropertyIndex < *pQueueFamilyPropertyCount; ++pQueueFamilyPropertyIndex)
        {
            constexpr std::array allowed_structs_VkQueueFamilyProperties2 = { VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV };

            skip |= ValidateStructPnext("vkGetPhysicalDeviceQueueFamilyProperties2", ParameterName("pQueueFamilyProperties[%i].pNext", ParameterName::IndexVector{ pQueueFamilyPropertyIndex }), "VkQueueFamilyCheckpointProperties2NV", pQueueFamilyProperties[pQueueFamilyPropertyIndex].pNext, allowed_structs_VkQueueFamilyProperties2.size(), allowed_structs_VkQueueFamilyProperties2.data(), GeneratedVulkanHeaderVersion, "VUID-VkQueueFamilyProperties2-pNext-pNext", "VUID-VkQueueFamilyProperties2-sType-unique", true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceMemoryProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties) const {
    bool skip = false;
     if (CheckPromotedApiAgainstVulkanVersion(physicalDevice, "vkGetPhysicalDeviceMemoryProperties2", VK_API_VERSION_1_1)) return true;
    skip |= ValidateStructType("vkGetPhysicalDeviceMemoryProperties2", "pMemoryProperties", "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2", pMemoryProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2, true, "VUID-vkGetPhysicalDeviceMemoryProperties2-pMemoryProperties-parameter", "VUID-VkPhysicalDeviceMemoryProperties2-sType-sType");
    if (pMemoryProperties != nullptr)
    {
        constexpr std::array allowed_structs_VkPhysicalDeviceMemoryProperties2 = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT };

        skip |= ValidateStructPnext("vkGetPhysicalDeviceMemoryProperties2", "pMemoryProperties->pNext", "VkPhysicalDeviceMemoryBudgetPropertiesEXT", pMemoryProperties->pNext, allowed_structs_VkPhysicalDeviceMemoryProperties2.size(), allowed_structs_VkPhysicalDeviceMemoryProperties2.data(), GeneratedVulkanHeaderVersion, "VUID-VkPhysicalDeviceMemoryProperties2-pNext-pNext", "VUID-VkPhysicalDeviceMemoryProperties2-sType-unique", true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceQueue2(
    VkDevice                                    device,
    const VkDeviceQueueInfo2*                   pQueueInfo,
    VkQueue*                                    pQueue) const {
    bool skip = false;
    skip |= ValidateStructType("vkGetDeviceQueue2", "pQueueInfo", "VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2", pQueueInfo, VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2, true, "VUID-vkGetDeviceQueue2-pQueueInfo-parameter", "VUID-VkDeviceQueueInfo2-sType-sType");
    if (pQueueInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetDeviceQueue2", "pQueueInfo->pNext", nullptr, pQueueInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDeviceQueueInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags("vkGetDeviceQueue2", "pQueueInfo->flags", "VkDeviceQueueCreateFlagBits", AllVkDeviceQueueCreateFlagBits, pQueueInfo->flags, kOptionalFlags, "VUID-VkDeviceQueueInfo2-flags-parameter");
    }
    skip |= ValidateRequiredPointer("vkGetDeviceQueue2", "pQueue", pQueue, "VUID-vkGetDeviceQueue2-pQueue-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCreateSamplerYcbcrConversion(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateSamplerYcbcrConversion", "pCreateInfo", "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO, true, "VUID-vkCreateSamplerYcbcrConversion-pCreateInfo-parameter", "VUID-VkSamplerYcbcrConversionCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCreateSamplerYcbcrConversion", "pCreateInfo->pNext", nullptr, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSamplerYcbcrConversionCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum("vkCreateSamplerYcbcrConversion", "pCreateInfo->format", "VkFormat", pCreateInfo->format, "VUID-VkSamplerYcbcrConversionCreateInfo-format-parameter");

        skip |= ValidateRangedEnum("vkCreateSamplerYcbcrConversion", "pCreateInfo->ycbcrModel", "VkSamplerYcbcrModelConversion", pCreateInfo->ycbcrModel, "VUID-VkSamplerYcbcrConversionCreateInfo-ycbcrModel-parameter");

        skip |= ValidateRangedEnum("vkCreateSamplerYcbcrConversion", "pCreateInfo->ycbcrRange", "VkSamplerYcbcrRange", pCreateInfo->ycbcrRange, "VUID-VkSamplerYcbcrConversionCreateInfo-ycbcrRange-parameter");

        skip |= ValidateRangedEnum("vkCreateSamplerYcbcrConversion", "pCreateInfo->components.r", "VkComponentSwizzle", pCreateInfo->components.r, "VUID-VkComponentMapping-r-parameter");

        skip |= ValidateRangedEnum("vkCreateSamplerYcbcrConversion", "pCreateInfo->components.g", "VkComponentSwizzle", pCreateInfo->components.g, "VUID-VkComponentMapping-g-parameter");

        skip |= ValidateRangedEnum("vkCreateSamplerYcbcrConversion", "pCreateInfo->components.b", "VkComponentSwizzle", pCreateInfo->components.b, "VUID-VkComponentMapping-b-parameter");

        skip |= ValidateRangedEnum("vkCreateSamplerYcbcrConversion", "pCreateInfo->components.a", "VkComponentSwizzle", pCreateInfo->components.a, "VUID-VkComponentMapping-a-parameter");

        skip |= ValidateRangedEnum("vkCreateSamplerYcbcrConversion", "pCreateInfo->xChromaOffset", "VkChromaLocation", pCreateInfo->xChromaOffset, "VUID-VkSamplerYcbcrConversionCreateInfo-xChromaOffset-parameter");

        skip |= ValidateRangedEnum("vkCreateSamplerYcbcrConversion", "pCreateInfo->yChromaOffset", "VkChromaLocation", pCreateInfo->yChromaOffset, "VUID-VkSamplerYcbcrConversionCreateInfo-yChromaOffset-parameter");

        skip |= ValidateRangedEnum("vkCreateSamplerYcbcrConversion", "pCreateInfo->chromaFilter", "VkFilter", pCreateInfo->chromaFilter, "VUID-VkSamplerYcbcrConversionCreateInfo-chromaFilter-parameter");

        skip |= ValidateBool32("vkCreateSamplerYcbcrConversion", "pCreateInfo->forceExplicitReconstruction", pCreateInfo->forceExplicitReconstruction);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateSamplerYcbcrConversion-pAllocator-null", "vkCreateSamplerYcbcrConversion(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateSamplerYcbcrConversion", "pYcbcrConversion", pYcbcrConversion, "VUID-vkCreateSamplerYcbcrConversion-pYcbcrConversion-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroySamplerYcbcrConversion(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroySamplerYcbcrConversion-pAllocator-null", "vkDestroySamplerYcbcrConversion(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties) const {
    bool skip = false;
     if (CheckPromotedApiAgainstVulkanVersion(physicalDevice, "vkGetPhysicalDeviceExternalBufferProperties", VK_API_VERSION_1_1)) return true;
    skip |= ValidateStructType("vkGetPhysicalDeviceExternalBufferProperties", "pExternalBufferInfo", "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO", pExternalBufferInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO, true, "VUID-vkGetPhysicalDeviceExternalBufferProperties-pExternalBufferInfo-parameter", "VUID-VkPhysicalDeviceExternalBufferInfo-sType-sType");
    if (pExternalBufferInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetPhysicalDeviceExternalBufferProperties", "pExternalBufferInfo->pNext", nullptr, pExternalBufferInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkPhysicalDeviceExternalBufferInfo-pNext-pNext", kVUIDUndefined, true, true);

        skip |= ValidateFlags("vkGetPhysicalDeviceExternalBufferProperties", "pExternalBufferInfo->flags", "VkBufferCreateFlagBits", AllVkBufferCreateFlagBits, pExternalBufferInfo->flags, kOptionalFlags, "VUID-VkPhysicalDeviceExternalBufferInfo-flags-parameter");

        skip |= ValidateFlags("vkGetPhysicalDeviceExternalBufferProperties", "pExternalBufferInfo->usage", "VkBufferUsageFlagBits", AllVkBufferUsageFlagBits, pExternalBufferInfo->usage, kRequiredFlags, "VUID-VkPhysicalDeviceExternalBufferInfo-usage-parameter", "VUID-VkPhysicalDeviceExternalBufferInfo-usage-requiredbitmask");

        skip |= ValidateFlags("vkGetPhysicalDeviceExternalBufferProperties", "pExternalBufferInfo->handleType", "VkExternalMemoryHandleTypeFlagBits", AllVkExternalMemoryHandleTypeFlagBits, pExternalBufferInfo->handleType, kRequiredSingleBit, "VUID-VkPhysicalDeviceExternalBufferInfo-handleType-parameter", "VUID-VkPhysicalDeviceExternalBufferInfo-handleType-parameter");
    }
    skip |= ValidateStructType("vkGetPhysicalDeviceExternalBufferProperties", "pExternalBufferProperties", "VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES", pExternalBufferProperties, VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES, true, "VUID-vkGetPhysicalDeviceExternalBufferProperties-pExternalBufferProperties-parameter", "VUID-VkExternalBufferProperties-sType-sType");
    if (pExternalBufferProperties != nullptr)
    {
        skip |= ValidateStructPnext("vkGetPhysicalDeviceExternalBufferProperties", "pExternalBufferProperties->pNext", nullptr, pExternalBufferProperties->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkExternalBufferProperties-pNext-pNext", kVUIDUndefined, true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceExternalFenceProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties) const {
    bool skip = false;
     if (CheckPromotedApiAgainstVulkanVersion(physicalDevice, "vkGetPhysicalDeviceExternalFenceProperties", VK_API_VERSION_1_1)) return true;
    skip |= ValidateStructType("vkGetPhysicalDeviceExternalFenceProperties", "pExternalFenceInfo", "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO", pExternalFenceInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO, true, "VUID-vkGetPhysicalDeviceExternalFenceProperties-pExternalFenceInfo-parameter", "VUID-VkPhysicalDeviceExternalFenceInfo-sType-sType");
    if (pExternalFenceInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetPhysicalDeviceExternalFenceProperties", "pExternalFenceInfo->pNext", nullptr, pExternalFenceInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkPhysicalDeviceExternalFenceInfo-pNext-pNext", kVUIDUndefined, true, true);

        skip |= ValidateFlags("vkGetPhysicalDeviceExternalFenceProperties", "pExternalFenceInfo->handleType", "VkExternalFenceHandleTypeFlagBits", AllVkExternalFenceHandleTypeFlagBits, pExternalFenceInfo->handleType, kRequiredSingleBit, "VUID-VkPhysicalDeviceExternalFenceInfo-handleType-parameter", "VUID-VkPhysicalDeviceExternalFenceInfo-handleType-parameter");
    }
    skip |= ValidateStructType("vkGetPhysicalDeviceExternalFenceProperties", "pExternalFenceProperties", "VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES", pExternalFenceProperties, VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES, true, "VUID-vkGetPhysicalDeviceExternalFenceProperties-pExternalFenceProperties-parameter", "VUID-VkExternalFenceProperties-sType-sType");
    if (pExternalFenceProperties != nullptr)
    {
        skip |= ValidateStructPnext("vkGetPhysicalDeviceExternalFenceProperties", "pExternalFenceProperties->pNext", nullptr, pExternalFenceProperties->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkExternalFenceProperties-pNext-pNext", kVUIDUndefined, true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties) const {
    bool skip = false;
     if (CheckPromotedApiAgainstVulkanVersion(physicalDevice, "vkGetPhysicalDeviceExternalSemaphoreProperties", VK_API_VERSION_1_1)) return true;
    skip |= ValidateStructType("vkGetPhysicalDeviceExternalSemaphoreProperties", "pExternalSemaphoreInfo", "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO", pExternalSemaphoreInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO, true, "VUID-vkGetPhysicalDeviceExternalSemaphoreProperties-pExternalSemaphoreInfo-parameter", "VUID-VkPhysicalDeviceExternalSemaphoreInfo-sType-sType");
    if (pExternalSemaphoreInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkPhysicalDeviceExternalSemaphoreInfo = { VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO };

        skip |= ValidateStructPnext("vkGetPhysicalDeviceExternalSemaphoreProperties", "pExternalSemaphoreInfo->pNext", "VkSemaphoreTypeCreateInfo", pExternalSemaphoreInfo->pNext, allowed_structs_VkPhysicalDeviceExternalSemaphoreInfo.size(), allowed_structs_VkPhysicalDeviceExternalSemaphoreInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkPhysicalDeviceExternalSemaphoreInfo-pNext-pNext", "VUID-VkPhysicalDeviceExternalSemaphoreInfo-sType-unique", true, true);

        skip |= ValidateFlags("vkGetPhysicalDeviceExternalSemaphoreProperties", "pExternalSemaphoreInfo->handleType", "VkExternalSemaphoreHandleTypeFlagBits", AllVkExternalSemaphoreHandleTypeFlagBits, pExternalSemaphoreInfo->handleType, kRequiredSingleBit, "VUID-VkPhysicalDeviceExternalSemaphoreInfo-handleType-parameter", "VUID-VkPhysicalDeviceExternalSemaphoreInfo-handleType-parameter");
    }
    skip |= ValidateStructType("vkGetPhysicalDeviceExternalSemaphoreProperties", "pExternalSemaphoreProperties", "VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES", pExternalSemaphoreProperties, VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES, true, "VUID-vkGetPhysicalDeviceExternalSemaphoreProperties-pExternalSemaphoreProperties-parameter", "VUID-VkExternalSemaphoreProperties-sType-sType");
    if (pExternalSemaphoreProperties != nullptr)
    {
        skip |= ValidateStructPnext("vkGetPhysicalDeviceExternalSemaphoreProperties", "pExternalSemaphoreProperties->pNext", nullptr, pExternalSemaphoreProperties->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkExternalSemaphoreProperties-pNext-pNext", kVUIDUndefined, true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDescriptorSetLayoutSupport(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport) const {
    bool skip = false;
    skip |= ValidateStructType("vkGetDescriptorSetLayoutSupport", "pCreateInfo", "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO, true, "VUID-vkGetDescriptorSetLayoutSupport-pCreateInfo-parameter", "VUID-VkDescriptorSetLayoutCreateInfo-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkDescriptorSetLayoutCreateInfo = { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO };

        skip |= ValidateStructPnext("vkGetDescriptorSetLayoutSupport", "pCreateInfo->pNext", "VkDescriptorSetLayoutBindingFlagsCreateInfo", pCreateInfo->pNext, allowed_structs_VkDescriptorSetLayoutCreateInfo.size(), allowed_structs_VkDescriptorSetLayoutCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkDescriptorSetLayoutCreateInfo-pNext-pNext", "VUID-VkDescriptorSetLayoutCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags("vkGetDescriptorSetLayoutSupport", "pCreateInfo->flags", "VkDescriptorSetLayoutCreateFlagBits", AllVkDescriptorSetLayoutCreateFlagBits, pCreateInfo->flags, kOptionalFlags, "VUID-VkDescriptorSetLayoutCreateInfo-flags-parameter");

        skip |= ValidateArray("vkGetDescriptorSetLayoutSupport", "pCreateInfo->bindingCount", "pCreateInfo->pBindings", pCreateInfo->bindingCount, &pCreateInfo->pBindings, false, true, kVUIDUndefined, "VUID-VkDescriptorSetLayoutCreateInfo-pBindings-parameter");

        if (pCreateInfo->pBindings != nullptr)
        {
            for (uint32_t bindingIndex = 0; bindingIndex < pCreateInfo->bindingCount; ++bindingIndex)
            {
                skip |= ValidateRangedEnum("vkGetDescriptorSetLayoutSupport", ParameterName("pCreateInfo->pBindings[%i].descriptorType", ParameterName::IndexVector{ bindingIndex }), "VkDescriptorType", pCreateInfo->pBindings[bindingIndex].descriptorType, "VUID-VkDescriptorSetLayoutBinding-descriptorType-parameter");
            }
        }
    }
    skip |= ValidateStructType("vkGetDescriptorSetLayoutSupport", "pSupport", "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT", pSupport, VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT, true, "VUID-vkGetDescriptorSetLayoutSupport-pSupport-parameter", "VUID-VkDescriptorSetLayoutSupport-sType-sType");
    if (pSupport != nullptr)
    {
        constexpr std::array allowed_structs_VkDescriptorSetLayoutSupport = { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT };

        skip |= ValidateStructPnext("vkGetDescriptorSetLayoutSupport", "pSupport->pNext", "VkDescriptorSetVariableDescriptorCountLayoutSupport", pSupport->pNext, allowed_structs_VkDescriptorSetLayoutSupport.size(), allowed_structs_VkDescriptorSetLayoutSupport.data(), GeneratedVulkanHeaderVersion, "VUID-VkDescriptorSetLayoutSupport-pNext-pNext", "VUID-VkDescriptorSetLayoutSupport-sType-unique", false, false);
    }
    return skip;
}



bool StatelessValidation::PreCallValidateCmdDrawIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdDrawIndirectCount", "buffer", buffer);
    skip |= ValidateRequiredHandle("vkCmdDrawIndirectCount", "countBuffer", countBuffer);
    if (!skip) skip |= manual_PreCallValidateCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDrawIndexedIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdDrawIndexedIndirectCount", "buffer", buffer);
    skip |= ValidateRequiredHandle("vkCmdDrawIndexedIndirectCount", "countBuffer", countBuffer);
    if (!skip) skip |= manual_PreCallValidateCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateRenderPass2(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreateRenderPass2", "pCreateInfo", "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2", pCreateInfo, VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2, true, "VUID-vkCreateRenderPass2-pCreateInfo-parameter", "VUID-VkRenderPassCreateInfo2-sType-sType");
    if (pCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCreateRenderPass2", "pCreateInfo->pNext", nullptr, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkRenderPassCreateInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags("vkCreateRenderPass2", "pCreateInfo->flags", "VkRenderPassCreateFlagBits", AllVkRenderPassCreateFlagBits, pCreateInfo->flags, kOptionalFlags, kVUIDUndefined);

        skip |= ValidateStructTypeArray("vkCreateRenderPass2", "pCreateInfo->attachmentCount", "pCreateInfo->pAttachments", "VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2", pCreateInfo->attachmentCount, pCreateInfo->pAttachments, VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2, false, true, "VUID-VkAttachmentDescription2-sType-sType", "VUID-VkRenderPassCreateInfo2-pAttachments-parameter", kVUIDUndefined);

        if (pCreateInfo->pAttachments != nullptr)
        {
            for (uint32_t attachmentIndex = 0; attachmentIndex < pCreateInfo->attachmentCount; ++attachmentIndex)
            {
                constexpr std::array allowed_structs_VkAttachmentDescription2 = { VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT };

                skip |= ValidateStructPnext("vkCreateRenderPass2", ParameterName("pCreateInfo->pAttachments[%i].pNext", ParameterName::IndexVector{ attachmentIndex }), "VkAttachmentDescriptionStencilLayout", pCreateInfo->pAttachments[attachmentIndex].pNext, allowed_structs_VkAttachmentDescription2.size(), allowed_structs_VkAttachmentDescription2.data(), GeneratedVulkanHeaderVersion, "VUID-VkAttachmentDescription2-pNext-pNext", "VUID-VkAttachmentDescription2-sType-unique", false, true);

                skip |= ValidateFlags("vkCreateRenderPass2", ParameterName("pCreateInfo->pAttachments[%i].flags", ParameterName::IndexVector{ attachmentIndex }), "VkAttachmentDescriptionFlagBits", AllVkAttachmentDescriptionFlagBits, pCreateInfo->pAttachments[attachmentIndex].flags, kOptionalFlags, "VUID-VkAttachmentDescription2-flags-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass2", ParameterName("pCreateInfo->pAttachments[%i].format", ParameterName::IndexVector{ attachmentIndex }), "VkFormat", pCreateInfo->pAttachments[attachmentIndex].format, "VUID-VkAttachmentDescription2-format-parameter");

                skip |= ValidateFlags("vkCreateRenderPass2", ParameterName("pCreateInfo->pAttachments[%i].samples", ParameterName::IndexVector{ attachmentIndex }), "VkSampleCountFlagBits", AllVkSampleCountFlagBits, pCreateInfo->pAttachments[attachmentIndex].samples, kRequiredSingleBit, "VUID-VkAttachmentDescription2-samples-parameter", "VUID-VkAttachmentDescription2-samples-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass2", ParameterName("pCreateInfo->pAttachments[%i].loadOp", ParameterName::IndexVector{ attachmentIndex }), "VkAttachmentLoadOp", pCreateInfo->pAttachments[attachmentIndex].loadOp, "VUID-VkAttachmentDescription2-loadOp-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass2", ParameterName("pCreateInfo->pAttachments[%i].storeOp", ParameterName::IndexVector{ attachmentIndex }), "VkAttachmentStoreOp", pCreateInfo->pAttachments[attachmentIndex].storeOp, "VUID-VkAttachmentDescription2-storeOp-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass2", ParameterName("pCreateInfo->pAttachments[%i].stencilLoadOp", ParameterName::IndexVector{ attachmentIndex }), "VkAttachmentLoadOp", pCreateInfo->pAttachments[attachmentIndex].stencilLoadOp, "VUID-VkAttachmentDescription2-stencilLoadOp-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass2", ParameterName("pCreateInfo->pAttachments[%i].stencilStoreOp", ParameterName::IndexVector{ attachmentIndex }), "VkAttachmentStoreOp", pCreateInfo->pAttachments[attachmentIndex].stencilStoreOp, "VUID-VkAttachmentDescription2-stencilStoreOp-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass2", ParameterName("pCreateInfo->pAttachments[%i].initialLayout", ParameterName::IndexVector{ attachmentIndex }), "VkImageLayout", pCreateInfo->pAttachments[attachmentIndex].initialLayout, "VUID-VkAttachmentDescription2-initialLayout-parameter");

                skip |= ValidateRangedEnum("vkCreateRenderPass2", ParameterName("pCreateInfo->pAttachments[%i].finalLayout", ParameterName::IndexVector{ attachmentIndex }), "VkImageLayout", pCreateInfo->pAttachments[attachmentIndex].finalLayout, "VUID-VkAttachmentDescription2-finalLayout-parameter");
            }
        }

        skip |= ValidateStructTypeArray("vkCreateRenderPass2", "pCreateInfo->subpassCount", "pCreateInfo->pSubpasses", "VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2", pCreateInfo->subpassCount, pCreateInfo->pSubpasses, VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2, true, true, "VUID-VkSubpassDescription2-sType-sType", "VUID-VkRenderPassCreateInfo2-pSubpasses-parameter", "VUID-VkRenderPassCreateInfo2-subpassCount-arraylength");

        if (pCreateInfo->pSubpasses != nullptr)
        {
            for (uint32_t subpassIndex = 0; subpassIndex < pCreateInfo->subpassCount; ++subpassIndex)
            {
                constexpr std::array allowed_structs_VkSubpassDescription2 = { VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR, VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE };

                skip |= ValidateStructPnext("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].pNext", ParameterName::IndexVector{ subpassIndex }), "VkFragmentShadingRateAttachmentInfoKHR, VkSubpassDescriptionDepthStencilResolve", pCreateInfo->pSubpasses[subpassIndex].pNext, allowed_structs_VkSubpassDescription2.size(), allowed_structs_VkSubpassDescription2.data(), GeneratedVulkanHeaderVersion, "VUID-VkSubpassDescription2-pNext-pNext", "VUID-VkSubpassDescription2-sType-unique", false, true);

                skip |= ValidateFlags("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].flags", ParameterName::IndexVector{ subpassIndex }), "VkSubpassDescriptionFlagBits", AllVkSubpassDescriptionFlagBits, pCreateInfo->pSubpasses[subpassIndex].flags, kOptionalFlags, kVUIDUndefined);

                skip |= ValidateRangedEnum("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].pipelineBindPoint", ParameterName::IndexVector{ subpassIndex }), "VkPipelineBindPoint", pCreateInfo->pSubpasses[subpassIndex].pipelineBindPoint, "VUID-VkSubpassDescription2-pipelineBindPoint-parameter");

                skip |= ValidateStructTypeArray("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].inputAttachmentCount", ParameterName::IndexVector{ subpassIndex }), ParameterName("pCreateInfo->pSubpasses[%i].pInputAttachments", ParameterName::IndexVector{ subpassIndex }), "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2", pCreateInfo->pSubpasses[subpassIndex].inputAttachmentCount, pCreateInfo->pSubpasses[subpassIndex].pInputAttachments, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2, false, true, "VUID-VkAttachmentReference2-sType-sType", "VUID-VkSubpassDescription2-pInputAttachments-parameter", kVUIDUndefined);

                if (pCreateInfo->pSubpasses[subpassIndex].pInputAttachments != nullptr)
                {
                    for (uint32_t inputAttachmentIndex = 0; inputAttachmentIndex < pCreateInfo->pSubpasses[subpassIndex].inputAttachmentCount; ++inputAttachmentIndex)
                    {
                        constexpr std::array allowed_structs_VkAttachmentReference2 = { VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT };

                        skip |= ValidateStructPnext("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].pInputAttachments[%i].pNext", ParameterName::IndexVector{ subpassIndex, inputAttachmentIndex }), "VkAttachmentReferenceStencilLayout", pCreateInfo->pSubpasses[subpassIndex].pInputAttachments[inputAttachmentIndex].pNext, allowed_structs_VkAttachmentReference2.size(), allowed_structs_VkAttachmentReference2.data(), GeneratedVulkanHeaderVersion, "VUID-VkAttachmentReference2-pNext-pNext", "VUID-VkAttachmentReference2-sType-unique", false, true);

                        skip |= ValidateRangedEnum("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].pInputAttachments[%i].layout", ParameterName::IndexVector{ subpassIndex, inputAttachmentIndex }), "VkImageLayout", pCreateInfo->pSubpasses[subpassIndex].pInputAttachments[inputAttachmentIndex].layout, "VUID-VkAttachmentReference2-layout-parameter");
                    }
                }

                skip |= ValidateStructTypeArray("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].colorAttachmentCount", ParameterName::IndexVector{ subpassIndex }), ParameterName("pCreateInfo->pSubpasses[%i].pColorAttachments", ParameterName::IndexVector{ subpassIndex }), "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2", pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount, pCreateInfo->pSubpasses[subpassIndex].pColorAttachments, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2, false, true, "VUID-VkAttachmentReference2-sType-sType", "VUID-VkSubpassDescription2-pColorAttachments-parameter", kVUIDUndefined);

                if (pCreateInfo->pSubpasses[subpassIndex].pColorAttachments != nullptr)
                {
                    for (uint32_t colorAttachmentIndex = 0; colorAttachmentIndex < pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount; ++colorAttachmentIndex)
                    {
                        constexpr std::array allowed_structs_VkAttachmentReference2 = { VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT };

                        skip |= ValidateStructPnext("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].pColorAttachments[%i].pNext", ParameterName::IndexVector{ subpassIndex, colorAttachmentIndex }), "VkAttachmentReferenceStencilLayout", pCreateInfo->pSubpasses[subpassIndex].pColorAttachments[colorAttachmentIndex].pNext, allowed_structs_VkAttachmentReference2.size(), allowed_structs_VkAttachmentReference2.data(), GeneratedVulkanHeaderVersion, "VUID-VkAttachmentReference2-pNext-pNext", "VUID-VkAttachmentReference2-sType-unique", false, true);

                        skip |= ValidateRangedEnum("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].pColorAttachments[%i].layout", ParameterName::IndexVector{ subpassIndex, colorAttachmentIndex }), "VkImageLayout", pCreateInfo->pSubpasses[subpassIndex].pColorAttachments[colorAttachmentIndex].layout, "VUID-VkAttachmentReference2-layout-parameter");
                    }
                }

                skip |= ValidateStructTypeArray("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].colorAttachmentCount", ParameterName::IndexVector{ subpassIndex }), ParameterName("pCreateInfo->pSubpasses[%i].pResolveAttachments", ParameterName::IndexVector{ subpassIndex }), "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2", pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount, pCreateInfo->pSubpasses[subpassIndex].pResolveAttachments, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2, false, false, "VUID-VkAttachmentReference2-sType-sType", "VUID-VkSubpassDescription2-pResolveAttachments-parameter", kVUIDUndefined);

                if (pCreateInfo->pSubpasses[subpassIndex].pResolveAttachments != nullptr)
                {
                    for (uint32_t colorAttachmentIndex = 0; colorAttachmentIndex < pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount; ++colorAttachmentIndex)
                    {
                        constexpr std::array allowed_structs_VkAttachmentReference2 = { VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT };

                        skip |= ValidateStructPnext("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].pResolveAttachments[%i].pNext", ParameterName::IndexVector{ subpassIndex, colorAttachmentIndex }), "VkAttachmentReferenceStencilLayout", pCreateInfo->pSubpasses[subpassIndex].pResolveAttachments[colorAttachmentIndex].pNext, allowed_structs_VkAttachmentReference2.size(), allowed_structs_VkAttachmentReference2.data(), GeneratedVulkanHeaderVersion, "VUID-VkAttachmentReference2-pNext-pNext", "VUID-VkAttachmentReference2-sType-unique", false, true);

                        skip |= ValidateRangedEnum("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].pResolveAttachments[%i].layout", ParameterName::IndexVector{ subpassIndex, colorAttachmentIndex }), "VkImageLayout", pCreateInfo->pSubpasses[subpassIndex].pResolveAttachments[colorAttachmentIndex].layout, "VUID-VkAttachmentReference2-layout-parameter");
                    }
                }

                skip |= ValidateStructType("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].pDepthStencilAttachment", ParameterName::IndexVector{ subpassIndex }), "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2", pCreateInfo->pSubpasses[subpassIndex].pDepthStencilAttachment, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2, false, "VUID-VkSubpassDescription2-pDepthStencilAttachment-parameter", "VUID-VkAttachmentReference2-sType-sType");

                if (pCreateInfo->pSubpasses[subpassIndex].pDepthStencilAttachment != nullptr)
                {
                    constexpr std::array allowed_structs_VkAttachmentReference2 = { VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT };

                    skip |= ValidateStructPnext("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].pDepthStencilAttachment->pNext", ParameterName::IndexVector{ subpassIndex }), "VkAttachmentReferenceStencilLayout", pCreateInfo->pSubpasses[subpassIndex].pDepthStencilAttachment->pNext, allowed_structs_VkAttachmentReference2.size(), allowed_structs_VkAttachmentReference2.data(), GeneratedVulkanHeaderVersion, "VUID-VkAttachmentReference2-pNext-pNext", "VUID-VkAttachmentReference2-sType-unique", false, true);

                    skip |= ValidateRangedEnum("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].pDepthStencilAttachment->layout", ParameterName::IndexVector{ subpassIndex }), "VkImageLayout", pCreateInfo->pSubpasses[subpassIndex].pDepthStencilAttachment->layout, "VUID-VkAttachmentReference2-layout-parameter");
                }

                skip |= ValidateArray("vkCreateRenderPass2", ParameterName("pCreateInfo->pSubpasses[%i].preserveAttachmentCount", ParameterName::IndexVector{ subpassIndex }), ParameterName("pCreateInfo->pSubpasses[%i].pPreserveAttachments", ParameterName::IndexVector{ subpassIndex }), pCreateInfo->pSubpasses[subpassIndex].preserveAttachmentCount, &pCreateInfo->pSubpasses[subpassIndex].pPreserveAttachments, false, true, kVUIDUndefined, "VUID-VkSubpassDescription2-pPreserveAttachments-parameter");
            }
        }

        skip |= ValidateStructTypeArray("vkCreateRenderPass2", "pCreateInfo->dependencyCount", "pCreateInfo->pDependencies", "VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2", pCreateInfo->dependencyCount, pCreateInfo->pDependencies, VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2, false, true, "VUID-VkSubpassDependency2-sType-sType", "VUID-VkRenderPassCreateInfo2-pDependencies-parameter", kVUIDUndefined);

        if (pCreateInfo->pDependencies != nullptr)
        {
            for (uint32_t dependencyIndex = 0; dependencyIndex < pCreateInfo->dependencyCount; ++dependencyIndex)
            {
                constexpr std::array allowed_structs_VkSubpassDependency2 = { VK_STRUCTURE_TYPE_MEMORY_BARRIER_2 };

                skip |= ValidateStructPnext("vkCreateRenderPass2", ParameterName("pCreateInfo->pDependencies[%i].pNext", ParameterName::IndexVector{ dependencyIndex }), "VkMemoryBarrier2", pCreateInfo->pDependencies[dependencyIndex].pNext, allowed_structs_VkSubpassDependency2.size(), allowed_structs_VkSubpassDependency2.data(), GeneratedVulkanHeaderVersion, "VUID-VkSubpassDependency2-pNext-pNext", "VUID-VkSubpassDependency2-sType-unique", false, true);

                if (!LvlFindInChain<VkMemoryBarrier2>(pCreateInfo->pDependencies[dependencyIndex].pNext))
                {
                    skip |= ValidateFlags("vkCreateRenderPass2", ParameterName("pCreateInfo->pDependencies[%i].srcStageMask", ParameterName::IndexVector{ dependencyIndex }), "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, pCreateInfo->pDependencies[dependencyIndex].srcStageMask, kOptionalFlags, "VUID-VkSubpassDependency2-srcStageMask-parameter");
                }

                if (!LvlFindInChain<VkMemoryBarrier2>(pCreateInfo->pDependencies[dependencyIndex].pNext))
                {
                    skip |= ValidateFlags("vkCreateRenderPass2", ParameterName("pCreateInfo->pDependencies[%i].dstStageMask", ParameterName::IndexVector{ dependencyIndex }), "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, pCreateInfo->pDependencies[dependencyIndex].dstStageMask, kOptionalFlags, "VUID-VkSubpassDependency2-dstStageMask-parameter");
                }

                if (!LvlFindInChain<VkMemoryBarrier2>(pCreateInfo->pDependencies[dependencyIndex].pNext))
                {
                    skip |= ValidateFlags("vkCreateRenderPass2", ParameterName("pCreateInfo->pDependencies[%i].srcAccessMask", ParameterName::IndexVector{ dependencyIndex }), "VkAccessFlagBits", AllVkAccessFlagBits, pCreateInfo->pDependencies[dependencyIndex].srcAccessMask, kOptionalFlags, "VUID-VkSubpassDependency2-srcAccessMask-parameter");
                }

                if (!LvlFindInChain<VkMemoryBarrier2>(pCreateInfo->pDependencies[dependencyIndex].pNext))
                {
                    skip |= ValidateFlags("vkCreateRenderPass2", ParameterName("pCreateInfo->pDependencies[%i].dstAccessMask", ParameterName::IndexVector{ dependencyIndex }), "VkAccessFlagBits", AllVkAccessFlagBits, pCreateInfo->pDependencies[dependencyIndex].dstAccessMask, kOptionalFlags, "VUID-VkSubpassDependency2-dstAccessMask-parameter");
                }

                skip |= ValidateFlags("vkCreateRenderPass2", ParameterName("pCreateInfo->pDependencies[%i].dependencyFlags", ParameterName::IndexVector{ dependencyIndex }), "VkDependencyFlagBits", AllVkDependencyFlagBits, pCreateInfo->pDependencies[dependencyIndex].dependencyFlags, kOptionalFlags, "VUID-VkSubpassDependency2-dependencyFlags-parameter");
            }
        }

        skip |= ValidateArray("vkCreateRenderPass2", "pCreateInfo->correlatedViewMaskCount", "pCreateInfo->pCorrelatedViewMasks", pCreateInfo->correlatedViewMaskCount, &pCreateInfo->pCorrelatedViewMasks, false, true, kVUIDUndefined, "VUID-VkRenderPassCreateInfo2-pCorrelatedViewMasks-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateRenderPass2-pAllocator-null", "vkCreateRenderPass2(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateRenderPass2", "pRenderPass", pRenderPass, "VUID-vkCreateRenderPass2-pRenderPass-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBeginRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkCmdBeginRenderPass2", "pRenderPassBegin", "VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO", pRenderPassBegin, VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO, true, "VUID-vkCmdBeginRenderPass2-pRenderPassBegin-parameter", "VUID-VkRenderPassBeginInfo-sType-sType");
    if (pRenderPassBegin != nullptr)
    {
        constexpr std::array allowed_structs_VkRenderPassBeginInfo = { VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO, VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO, VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT };

        skip |= ValidateStructPnext("vkCmdBeginRenderPass2", "pRenderPassBegin->pNext", "VkDeviceGroupRenderPassBeginInfo, VkRenderPassAttachmentBeginInfo, VkRenderPassSampleLocationsBeginInfoEXT", pRenderPassBegin->pNext, allowed_structs_VkRenderPassBeginInfo.size(), allowed_structs_VkRenderPassBeginInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkRenderPassBeginInfo-pNext-pNext", "VUID-VkRenderPassBeginInfo-sType-unique", false, true);

        skip |= ValidateRequiredHandle("vkCmdBeginRenderPass2", "pRenderPassBegin->renderPass", pRenderPassBegin->renderPass);

        skip |= ValidateRequiredHandle("vkCmdBeginRenderPass2", "pRenderPassBegin->framebuffer", pRenderPassBegin->framebuffer);

        // No xml-driven validation

        // No xml-driven validation
    }
    skip |= ValidateStructType("vkCmdBeginRenderPass2", "pSubpassBeginInfo", "VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO", pSubpassBeginInfo, VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO, true, "VUID-vkCmdBeginRenderPass2-pSubpassBeginInfo-parameter", "VUID-VkSubpassBeginInfo-sType-sType");
    if (pSubpassBeginInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdBeginRenderPass2", "pSubpassBeginInfo->pNext", nullptr, pSubpassBeginInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSubpassBeginInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum("vkCmdBeginRenderPass2", "pSubpassBeginInfo->contents", "VkSubpassContents", pSubpassBeginInfo->contents, "VUID-VkSubpassBeginInfo-contents-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdNextSubpass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkCmdNextSubpass2", "pSubpassBeginInfo", "VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO", pSubpassBeginInfo, VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO, true, "VUID-vkCmdNextSubpass2-pSubpassBeginInfo-parameter", "VUID-VkSubpassBeginInfo-sType-sType");
    if (pSubpassBeginInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdNextSubpass2", "pSubpassBeginInfo->pNext", nullptr, pSubpassBeginInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSubpassBeginInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum("vkCmdNextSubpass2", "pSubpassBeginInfo->contents", "VkSubpassContents", pSubpassBeginInfo->contents, "VUID-VkSubpassBeginInfo-contents-parameter");
    }
    skip |= ValidateStructType("vkCmdNextSubpass2", "pSubpassEndInfo", "VK_STRUCTURE_TYPE_SUBPASS_END_INFO", pSubpassEndInfo, VK_STRUCTURE_TYPE_SUBPASS_END_INFO, true, "VUID-vkCmdNextSubpass2-pSubpassEndInfo-parameter", "VUID-VkSubpassEndInfo-sType-sType");
    if (pSubpassEndInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdNextSubpass2", "pSubpassEndInfo->pNext", nullptr, pSubpassEndInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSubpassEndInfo-pNext-pNext", kVUIDUndefined, false, true);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdEndRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkCmdEndRenderPass2", "pSubpassEndInfo", "VK_STRUCTURE_TYPE_SUBPASS_END_INFO", pSubpassEndInfo, VK_STRUCTURE_TYPE_SUBPASS_END_INFO, true, "VUID-vkCmdEndRenderPass2-pSubpassEndInfo-parameter", "VUID-VkSubpassEndInfo-sType-sType");
    if (pSubpassEndInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdEndRenderPass2", "pSubpassEndInfo->pNext", nullptr, pSubpassEndInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSubpassEndInfo-pNext-pNext", kVUIDUndefined, false, true);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateResetQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkResetQueryPool", "queryPool", queryPool);
    return skip;
}

bool StatelessValidation::PreCallValidateGetSemaphoreCounterValue(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    uint64_t*                                   pValue) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkGetSemaphoreCounterValue", "semaphore", semaphore);
    skip |= ValidateRequiredPointer("vkGetSemaphoreCounterValue", "pValue", pValue, "VUID-vkGetSemaphoreCounterValue-pValue-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateWaitSemaphores(
    VkDevice                                    device,
    const VkSemaphoreWaitInfo*                  pWaitInfo,
    uint64_t                                    timeout) const {
    bool skip = false;
    skip |= ValidateStructType("vkWaitSemaphores", "pWaitInfo", "VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO", pWaitInfo, VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO, true, "VUID-vkWaitSemaphores-pWaitInfo-parameter", "VUID-VkSemaphoreWaitInfo-sType-sType");
    if (pWaitInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkWaitSemaphores", "pWaitInfo->pNext", nullptr, pWaitInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSemaphoreWaitInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags("vkWaitSemaphores", "pWaitInfo->flags", "VkSemaphoreWaitFlagBits", AllVkSemaphoreWaitFlagBits, pWaitInfo->flags, kOptionalFlags, "VUID-VkSemaphoreWaitInfo-flags-parameter");

        skip |= ValidateHandleArray("vkWaitSemaphores", "pWaitInfo->semaphoreCount", "pWaitInfo->pSemaphores", pWaitInfo->semaphoreCount, pWaitInfo->pSemaphores, true, true, kVUIDUndefined);

        skip |= ValidateArray("vkWaitSemaphores", "pWaitInfo->semaphoreCount", "pWaitInfo->pValues", pWaitInfo->semaphoreCount, &pWaitInfo->pValues, true, true, "VUID-VkSemaphoreWaitInfo-semaphoreCount-arraylength", "VUID-VkSemaphoreWaitInfo-pValues-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateSignalSemaphore(
    VkDevice                                    device,
    const VkSemaphoreSignalInfo*                pSignalInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkSignalSemaphore", "pSignalInfo", "VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO", pSignalInfo, VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO, true, "VUID-vkSignalSemaphore-pSignalInfo-parameter", "VUID-VkSemaphoreSignalInfo-sType-sType");
    if (pSignalInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkSignalSemaphore", "pSignalInfo->pNext", nullptr, pSignalInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSemaphoreSignalInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkSignalSemaphore", "pSignalInfo->semaphore", pSignalInfo->semaphore);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetBufferDeviceAddress(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkGetBufferDeviceAddress", "pInfo", "VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO", pInfo, VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO, true, "VUID-vkGetBufferDeviceAddress-pInfo-parameter", "VUID-VkBufferDeviceAddressInfo-sType-sType");
    if (pInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetBufferDeviceAddress", "pInfo->pNext", nullptr, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferDeviceAddressInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkGetBufferDeviceAddress", "pInfo->buffer", pInfo->buffer);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetBufferOpaqueCaptureAddress(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkGetBufferOpaqueCaptureAddress", "pInfo", "VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO", pInfo, VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO, true, "VUID-vkGetBufferOpaqueCaptureAddress-pInfo-parameter", "VUID-VkBufferDeviceAddressInfo-sType-sType");
    if (pInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetBufferOpaqueCaptureAddress", "pInfo->pNext", nullptr, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferDeviceAddressInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkGetBufferOpaqueCaptureAddress", "pInfo->buffer", pInfo->buffer);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceMemoryOpaqueCaptureAddress(
    VkDevice                                    device,
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkGetDeviceMemoryOpaqueCaptureAddress", "pInfo", "VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO", pInfo, VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO, true, "VUID-vkGetDeviceMemoryOpaqueCaptureAddress-pInfo-parameter", "VUID-VkDeviceMemoryOpaqueCaptureAddressInfo-sType-sType");
    if (pInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetDeviceMemoryOpaqueCaptureAddress", "pInfo->pNext", nullptr, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDeviceMemoryOpaqueCaptureAddressInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkGetDeviceMemoryOpaqueCaptureAddress", "pInfo->memory", pInfo->memory);
    }
    return skip;
}



bool StatelessValidation::PreCallValidateGetPhysicalDeviceToolProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pToolCount,
    VkPhysicalDeviceToolProperties*             pToolProperties) const {
    bool skip = false;
     if (CheckPromotedApiAgainstVulkanVersion(physicalDevice, "vkGetPhysicalDeviceToolProperties", VK_API_VERSION_1_3)) return true;
    skip |= ValidateStructTypeArray("vkGetPhysicalDeviceToolProperties", "pToolCount", "pToolProperties", "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES", pToolCount, pToolProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES, true, false, false, kVUIDUndefined, kVUIDUndefined, kVUIDUndefined);
    if (pToolProperties != nullptr)
    {
        for (uint32_t pToolIndex = 0; pToolIndex < *pToolCount; ++pToolIndex)
        {
            skip |= ValidateStructPnext("vkGetPhysicalDeviceToolProperties", ParameterName("pToolProperties[%i].pNext", ParameterName::IndexVector{ pToolIndex }), nullptr, pToolProperties[pToolIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreatePrivateDataSlot(
    VkDevice                                    device,
    const VkPrivateDataSlotCreateInfo*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPrivateDataSlot*                          pPrivateDataSlot) const {
    bool skip = false;
    skip |= ValidateStructType("vkCreatePrivateDataSlot", "pCreateInfo", "VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO", pCreateInfo, VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO, true, kVUIDUndefined, kVUIDUndefined);
    if (pCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCreatePrivateDataSlot", "pCreateInfo->pNext", nullptr, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags("vkCreatePrivateDataSlot", "pCreateInfo->flags", pCreateInfo->flags, kVUIDUndefined);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreatePrivateDataSlot-pAllocator-null", "vkCreatePrivateDataSlot(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreatePrivateDataSlot", "pPrivateDataSlot", pPrivateDataSlot, kVUIDUndefined);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyPrivateDataSlot(
    VkDevice                                    device,
    VkPrivateDataSlot                           privateDataSlot,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyPrivateDataSlot-pAllocator-null", "vkDestroyPrivateDataSlot(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateSetPrivateData(
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t                                    data) const {
    bool skip = false;
    skip |= ValidateRangedEnum("vkSetPrivateData", "objectType", "VkObjectType", objectType, kVUIDUndefined);
    skip |= ValidateRequiredHandle("vkSetPrivateData", "privateDataSlot", privateDataSlot);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPrivateData(
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t*                                   pData) const {
    bool skip = false;
    skip |= ValidateRangedEnum("vkGetPrivateData", "objectType", "VkObjectType", objectType, kVUIDUndefined);
    skip |= ValidateRequiredHandle("vkGetPrivateData", "privateDataSlot", privateDataSlot);
    skip |= ValidateRequiredPointer("vkGetPrivateData", "pData", pData, kVUIDUndefined);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdSetEvent2", "event", event);
    skip |= ValidateStructType("vkCmdSetEvent2", "pDependencyInfo", "VK_STRUCTURE_TYPE_DEPENDENCY_INFO", pDependencyInfo, VK_STRUCTURE_TYPE_DEPENDENCY_INFO, true, "VUID-vkCmdSetEvent2-pDependencyInfo-parameter", "VUID-VkDependencyInfo-sType-sType");
    if (pDependencyInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdSetEvent2", "pDependencyInfo->pNext", nullptr, pDependencyInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDependencyInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags("vkCmdSetEvent2", "pDependencyInfo->dependencyFlags", "VkDependencyFlagBits", AllVkDependencyFlagBits, pDependencyInfo->dependencyFlags, kOptionalFlags, "VUID-VkDependencyInfo-dependencyFlags-parameter");

        skip |= ValidateStructTypeArray("vkCmdSetEvent2", "pDependencyInfo->memoryBarrierCount", "pDependencyInfo->pMemoryBarriers", "VK_STRUCTURE_TYPE_MEMORY_BARRIER_2", pDependencyInfo->memoryBarrierCount, pDependencyInfo->pMemoryBarriers, VK_STRUCTURE_TYPE_MEMORY_BARRIER_2, false, true, "VUID-VkMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pMemoryBarriers != nullptr)
        {
            for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < pDependencyInfo->memoryBarrierCount; ++memoryBarrierIndex)
            {
                skip |= ValidateStructPnext("vkCmdSetEvent2", ParameterName("pDependencyInfo->pMemoryBarriers[%i].pNext", ParameterName::IndexVector{ memoryBarrierIndex }), nullptr, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstAccessMask-parameter");
            }
        }

        skip |= ValidateStructTypeArray("vkCmdSetEvent2", "pDependencyInfo->bufferMemoryBarrierCount", "pDependencyInfo->pBufferMemoryBarriers", "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2", pDependencyInfo->bufferMemoryBarrierCount, pDependencyInfo->pBufferMemoryBarriers, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2, false, true, "VUID-VkBufferMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pBufferMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t bufferMemoryBarrierIndex = 0; bufferMemoryBarrierIndex < pDependencyInfo->bufferMemoryBarrierCount; ++bufferMemoryBarrierIndex)
            {
                skip |= ValidateStructPnext("vkCmdSetEvent2", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].pNext", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), nullptr, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstAccessMask-parameter");

                skip |= ValidateRequiredHandle("vkCmdSetEvent2", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].buffer", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
            }
        }

        skip |= ValidateStructTypeArray("vkCmdSetEvent2", "pDependencyInfo->imageMemoryBarrierCount", "pDependencyInfo->pImageMemoryBarriers", "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2", pDependencyInfo->imageMemoryBarrierCount, pDependencyInfo->pImageMemoryBarriers, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2, false, true, "VUID-VkImageMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pImageMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t imageMemoryBarrierIndex = 0; imageMemoryBarrierIndex < pDependencyInfo->imageMemoryBarrierCount; ++imageMemoryBarrierIndex)
            {
                constexpr std::array allowed_structs_VkImageMemoryBarrier2 = { VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT };

                skip |= ValidateStructPnext("vkCmdSetEvent2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].pNext", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkSampleLocationsInfoEXT", pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].pNext, allowed_structs_VkImageMemoryBarrier2.size(), allowed_structs_VkImageMemoryBarrier2.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier2-pNext-pNext", "VUID-VkImageMemoryBarrier2-sType-unique", false, true);

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstAccessMask-parameter");

                skip |= ValidateRangedEnum("vkCmdSetEvent2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].oldLayout", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageLayout", pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout, "VUID-VkImageMemoryBarrier2-oldLayout-parameter");

                skip |= ValidateRangedEnum("vkCmdSetEvent2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].newLayout", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageLayout", pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout, "VUID-VkImageMemoryBarrier2-newLayout-parameter");

                skip |= ValidateRequiredHandle("vkCmdSetEvent2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].image", ParameterName::IndexVector{ imageMemoryBarrierIndex }), pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].image);

                skip |= ValidateFlags("vkCmdSetEvent2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].subresourceRange.aspectMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkCmdResetEvent2", "event", event);
    skip |= ValidateFlags("vkCmdResetEvent2", "stageMask", "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, stageMask, kOptionalFlags, "VUID-vkCmdResetEvent2-stageMask-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWaitEvents2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) const {
    bool skip = false;
    skip |= ValidateHandleArray("vkCmdWaitEvents2", "eventCount", "pEvents", eventCount, pEvents, true, true, "VUID-vkCmdWaitEvents2-eventCount-arraylength");
    skip |= ValidateStructTypeArray("vkCmdWaitEvents2", "eventCount", "pDependencyInfos", "VK_STRUCTURE_TYPE_DEPENDENCY_INFO", eventCount, pDependencyInfos, VK_STRUCTURE_TYPE_DEPENDENCY_INFO, true, true, "VUID-VkDependencyInfo-sType-sType", "VUID-vkCmdWaitEvents2-pDependencyInfos-parameter", "VUID-vkCmdWaitEvents2-eventCount-arraylength");
    if (pDependencyInfos != nullptr)
    {
        for (uint32_t eventIndex = 0; eventIndex < eventCount; ++eventIndex)
        {
            skip |= ValidateStructPnext("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pNext", ParameterName::IndexVector{ eventIndex }), nullptr, pDependencyInfos[eventIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDependencyInfo-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].dependencyFlags", ParameterName::IndexVector{ eventIndex }), "VkDependencyFlagBits", AllVkDependencyFlagBits, pDependencyInfos[eventIndex].dependencyFlags, kOptionalFlags, "VUID-VkDependencyInfo-dependencyFlags-parameter");

            skip |= ValidateStructTypeArray("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].memoryBarrierCount", ParameterName::IndexVector{ eventIndex }), ParameterName("pDependencyInfos[%i].pMemoryBarriers", ParameterName::IndexVector{ eventIndex }), "VK_STRUCTURE_TYPE_MEMORY_BARRIER_2", pDependencyInfos[eventIndex].memoryBarrierCount, pDependencyInfos[eventIndex].pMemoryBarriers, VK_STRUCTURE_TYPE_MEMORY_BARRIER_2, false, true, "VUID-VkMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pMemoryBarriers-parameter", kVUIDUndefined);

            if (pDependencyInfos[eventIndex].pMemoryBarriers != nullptr)
            {
                for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < pDependencyInfos[eventIndex].memoryBarrierCount; ++memoryBarrierIndex)
                {
                    skip |= ValidateStructPnext("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pMemoryBarriers[%i].pNext", ParameterName::IndexVector{ eventIndex, memoryBarrierIndex }), nullptr, pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ eventIndex, memoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcStageMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ eventIndex, memoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcAccessMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ eventIndex, memoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstStageMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ eventIndex, memoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstAccessMask-parameter");
                }
            }

            skip |= ValidateStructTypeArray("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].bufferMemoryBarrierCount", ParameterName::IndexVector{ eventIndex }), ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers", ParameterName::IndexVector{ eventIndex }), "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2", pDependencyInfos[eventIndex].bufferMemoryBarrierCount, pDependencyInfos[eventIndex].pBufferMemoryBarriers, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2, false, true, "VUID-VkBufferMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pBufferMemoryBarriers-parameter", kVUIDUndefined);

            if (pDependencyInfos[eventIndex].pBufferMemoryBarriers != nullptr)
            {
                for (uint32_t bufferMemoryBarrierIndex = 0; bufferMemoryBarrierIndex < pDependencyInfos[eventIndex].bufferMemoryBarrierCount; ++bufferMemoryBarrierIndex)
                {
                    skip |= ValidateStructPnext("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers[%i].pNext", ParameterName::IndexVector{ eventIndex, bufferMemoryBarrierIndex }), nullptr, pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier2-pNext-pNext", kVUIDUndefined, false, true);

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ eventIndex, bufferMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcStageMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ eventIndex, bufferMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcAccessMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ eventIndex, bufferMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstStageMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ eventIndex, bufferMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstAccessMask-parameter");

                    skip |= ValidateRequiredHandle("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers[%i].buffer", ParameterName::IndexVector{ eventIndex, bufferMemoryBarrierIndex }), pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
                }
            }

            skip |= ValidateStructTypeArray("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].imageMemoryBarrierCount", ParameterName::IndexVector{ eventIndex }), ParameterName("pDependencyInfos[%i].pImageMemoryBarriers", ParameterName::IndexVector{ eventIndex }), "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2", pDependencyInfos[eventIndex].imageMemoryBarrierCount, pDependencyInfos[eventIndex].pImageMemoryBarriers, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2, false, true, "VUID-VkImageMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pImageMemoryBarriers-parameter", kVUIDUndefined);

            if (pDependencyInfos[eventIndex].pImageMemoryBarriers != nullptr)
            {
                for (uint32_t imageMemoryBarrierIndex = 0; imageMemoryBarrierIndex < pDependencyInfos[eventIndex].imageMemoryBarrierCount; ++imageMemoryBarrierIndex)
                {
                    constexpr std::array allowed_structs_VkImageMemoryBarrier2 = { VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT };

                    skip |= ValidateStructPnext("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].pNext", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkSampleLocationsInfoEXT", pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].pNext, allowed_structs_VkImageMemoryBarrier2.size(), allowed_structs_VkImageMemoryBarrier2.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier2-pNext-pNext", "VUID-VkImageMemoryBarrier2-sType-unique", false, true);

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcStageMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcAccessMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstStageMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstAccessMask-parameter");

                    skip |= ValidateRangedEnum("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].oldLayout", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkImageLayout", pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout, "VUID-VkImageMemoryBarrier2-oldLayout-parameter");

                    skip |= ValidateRangedEnum("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].newLayout", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkImageLayout", pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout, "VUID-VkImageMemoryBarrier2-newLayout-parameter");

                    skip |= ValidateRequiredHandle("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].image", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].image);

                    skip |= ValidateFlags("vkCmdWaitEvents2", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].subresourceRange.aspectMask", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
                }
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdPipelineBarrier2(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkCmdPipelineBarrier2", "pDependencyInfo", "VK_STRUCTURE_TYPE_DEPENDENCY_INFO", pDependencyInfo, VK_STRUCTURE_TYPE_DEPENDENCY_INFO, true, "VUID-vkCmdPipelineBarrier2-pDependencyInfo-parameter", "VUID-VkDependencyInfo-sType-sType");
    if (pDependencyInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdPipelineBarrier2", "pDependencyInfo->pNext", nullptr, pDependencyInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDependencyInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags("vkCmdPipelineBarrier2", "pDependencyInfo->dependencyFlags", "VkDependencyFlagBits", AllVkDependencyFlagBits, pDependencyInfo->dependencyFlags, kOptionalFlags, "VUID-VkDependencyInfo-dependencyFlags-parameter");

        skip |= ValidateStructTypeArray("vkCmdPipelineBarrier2", "pDependencyInfo->memoryBarrierCount", "pDependencyInfo->pMemoryBarriers", "VK_STRUCTURE_TYPE_MEMORY_BARRIER_2", pDependencyInfo->memoryBarrierCount, pDependencyInfo->pMemoryBarriers, VK_STRUCTURE_TYPE_MEMORY_BARRIER_2, false, true, "VUID-VkMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pMemoryBarriers != nullptr)
        {
            for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < pDependencyInfo->memoryBarrierCount; ++memoryBarrierIndex)
            {
                skip |= ValidateStructPnext("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pMemoryBarriers[%i].pNext", ParameterName::IndexVector{ memoryBarrierIndex }), nullptr, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstAccessMask-parameter");
            }
        }

        skip |= ValidateStructTypeArray("vkCmdPipelineBarrier2", "pDependencyInfo->bufferMemoryBarrierCount", "pDependencyInfo->pBufferMemoryBarriers", "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2", pDependencyInfo->bufferMemoryBarrierCount, pDependencyInfo->pBufferMemoryBarriers, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2, false, true, "VUID-VkBufferMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pBufferMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t bufferMemoryBarrierIndex = 0; bufferMemoryBarrierIndex < pDependencyInfo->bufferMemoryBarrierCount; ++bufferMemoryBarrierIndex)
            {
                skip |= ValidateStructPnext("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].pNext", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), nullptr, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstAccessMask-parameter");

                skip |= ValidateRequiredHandle("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].buffer", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
            }
        }

        skip |= ValidateStructTypeArray("vkCmdPipelineBarrier2", "pDependencyInfo->imageMemoryBarrierCount", "pDependencyInfo->pImageMemoryBarriers", "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2", pDependencyInfo->imageMemoryBarrierCount, pDependencyInfo->pImageMemoryBarriers, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2, false, true, "VUID-VkImageMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pImageMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t imageMemoryBarrierIndex = 0; imageMemoryBarrierIndex < pDependencyInfo->imageMemoryBarrierCount; ++imageMemoryBarrierIndex)
            {
                constexpr std::array allowed_structs_VkImageMemoryBarrier2 = { VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT };

                skip |= ValidateStructPnext("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].pNext", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkSampleLocationsInfoEXT", pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].pNext, allowed_structs_VkImageMemoryBarrier2.size(), allowed_structs_VkImageMemoryBarrier2.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier2-pNext-pNext", "VUID-VkImageMemoryBarrier2-sType-unique", false, true);

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstAccessMask-parameter");

                skip |= ValidateRangedEnum("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].oldLayout", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageLayout", pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout, "VUID-VkImageMemoryBarrier2-oldLayout-parameter");

                skip |= ValidateRangedEnum("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].newLayout", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageLayout", pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout, "VUID-VkImageMemoryBarrier2-newLayout-parameter");

                skip |= ValidateRequiredHandle("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].image", ParameterName::IndexVector{ imageMemoryBarrierIndex }), pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].image);

                skip |= ValidateFlags("vkCmdPipelineBarrier2", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].subresourceRange.aspectMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWriteTimestamp2(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) const {
    bool skip = false;
    skip |= ValidateFlags("vkCmdWriteTimestamp2", "stage", "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, stage, kOptionalFlags, "VUID-vkCmdWriteTimestamp2-stage-parameter");
    skip |= ValidateRequiredHandle("vkCmdWriteTimestamp2", "queryPool", queryPool);
    return skip;
}

bool StatelessValidation::PreCallValidateQueueSubmit2(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo2*                        pSubmits,
    VkFence                                     fence) const {
    bool skip = false;
    skip |= ValidateStructTypeArray("vkQueueSubmit2", "submitCount", "pSubmits", "VK_STRUCTURE_TYPE_SUBMIT_INFO_2", submitCount, pSubmits, VK_STRUCTURE_TYPE_SUBMIT_INFO_2, false, true, "VUID-VkSubmitInfo2-sType-sType", "VUID-vkQueueSubmit2-pSubmits-parameter", kVUIDUndefined);
    if (pSubmits != nullptr)
    {
        for (uint32_t submitIndex = 0; submitIndex < submitCount; ++submitIndex)
        {
            constexpr std::array allowed_structs_VkSubmitInfo2 = { VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR };

            skip |= ValidateStructPnext("vkQueueSubmit2", ParameterName("pSubmits[%i].pNext", ParameterName::IndexVector{ submitIndex }), "VkPerformanceQuerySubmitInfoKHR", pSubmits[submitIndex].pNext, allowed_structs_VkSubmitInfo2.size(), allowed_structs_VkSubmitInfo2.data(), GeneratedVulkanHeaderVersion, "VUID-VkSubmitInfo2-pNext-pNext", "VUID-VkSubmitInfo2-sType-unique", false, true);

            skip |= ValidateFlags("vkQueueSubmit2", ParameterName("pSubmits[%i].flags", ParameterName::IndexVector{ submitIndex }), "VkSubmitFlagBits", AllVkSubmitFlagBits, pSubmits[submitIndex].flags, kOptionalFlags, "VUID-VkSubmitInfo2-flags-parameter");

            skip |= ValidateStructTypeArray("vkQueueSubmit2", ParameterName("pSubmits[%i].waitSemaphoreInfoCount", ParameterName::IndexVector{ submitIndex }), ParameterName("pSubmits[%i].pWaitSemaphoreInfos", ParameterName::IndexVector{ submitIndex }), "VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO", pSubmits[submitIndex].waitSemaphoreInfoCount, pSubmits[submitIndex].pWaitSemaphoreInfos, VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO, false, true, "VUID-VkSemaphoreSubmitInfo-sType-sType", "VUID-VkSubmitInfo2-pWaitSemaphoreInfos-parameter", kVUIDUndefined);

            if (pSubmits[submitIndex].pWaitSemaphoreInfos != nullptr)
            {
                for (uint32_t waitSemaphoreInfoIndex = 0; waitSemaphoreInfoIndex < pSubmits[submitIndex].waitSemaphoreInfoCount; ++waitSemaphoreInfoIndex)
                {
                    skip |= ValidateStructPnext("vkQueueSubmit2", ParameterName("pSubmits[%i].pWaitSemaphoreInfos[%i].pNext", ParameterName::IndexVector{ submitIndex, waitSemaphoreInfoIndex }), nullptr, pSubmits[submitIndex].pWaitSemaphoreInfos[waitSemaphoreInfoIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSemaphoreSubmitInfo-pNext-pNext", kVUIDUndefined, false, true);

                    skip |= ValidateRequiredHandle("vkQueueSubmit2", ParameterName("pSubmits[%i].pWaitSemaphoreInfos[%i].semaphore", ParameterName::IndexVector{ submitIndex, waitSemaphoreInfoIndex }), pSubmits[submitIndex].pWaitSemaphoreInfos[waitSemaphoreInfoIndex].semaphore);

                    skip |= ValidateFlags("vkQueueSubmit2", ParameterName("pSubmits[%i].pWaitSemaphoreInfos[%i].stageMask", ParameterName::IndexVector{ submitIndex, waitSemaphoreInfoIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pSubmits[submitIndex].pWaitSemaphoreInfos[waitSemaphoreInfoIndex].stageMask, kOptionalFlags, "VUID-VkSemaphoreSubmitInfo-stageMask-parameter");
                }
            }

            skip |= ValidateStructTypeArray("vkQueueSubmit2", ParameterName("pSubmits[%i].commandBufferInfoCount", ParameterName::IndexVector{ submitIndex }), ParameterName("pSubmits[%i].pCommandBufferInfos", ParameterName::IndexVector{ submitIndex }), "VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO", pSubmits[submitIndex].commandBufferInfoCount, pSubmits[submitIndex].pCommandBufferInfos, VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO, false, true, "VUID-VkCommandBufferSubmitInfo-sType-sType", "VUID-VkSubmitInfo2-pCommandBufferInfos-parameter", kVUIDUndefined);

            if (pSubmits[submitIndex].pCommandBufferInfos != nullptr)
            {
                for (uint32_t commandBufferInfoIndex = 0; commandBufferInfoIndex < pSubmits[submitIndex].commandBufferInfoCount; ++commandBufferInfoIndex)
                {
                    skip |= ValidateStructPnext("vkQueueSubmit2", ParameterName("pSubmits[%i].pCommandBufferInfos[%i].pNext", ParameterName::IndexVector{ submitIndex, commandBufferInfoIndex }), nullptr, pSubmits[submitIndex].pCommandBufferInfos[commandBufferInfoIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCommandBufferSubmitInfo-pNext-pNext", kVUIDUndefined, false, true);

                    skip |= ValidateRequiredHandle("vkQueueSubmit2", ParameterName("pSubmits[%i].pCommandBufferInfos[%i].commandBuffer", ParameterName::IndexVector{ submitIndex, commandBufferInfoIndex }), pSubmits[submitIndex].pCommandBufferInfos[commandBufferInfoIndex].commandBuffer);
                }
            }

            skip |= ValidateStructTypeArray("vkQueueSubmit2", ParameterName("pSubmits[%i].signalSemaphoreInfoCount", ParameterName::IndexVector{ submitIndex }), ParameterName("pSubmits[%i].pSignalSemaphoreInfos", ParameterName::IndexVector{ submitIndex }), "VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO", pSubmits[submitIndex].signalSemaphoreInfoCount, pSubmits[submitIndex].pSignalSemaphoreInfos, VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO, false, true, "VUID-VkSemaphoreSubmitInfo-sType-sType", "VUID-VkSubmitInfo2-pSignalSemaphoreInfos-parameter", kVUIDUndefined);

            if (pSubmits[submitIndex].pSignalSemaphoreInfos != nullptr)
            {
                for (uint32_t signalSemaphoreInfoIndex = 0; signalSemaphoreInfoIndex < pSubmits[submitIndex].signalSemaphoreInfoCount; ++signalSemaphoreInfoIndex)
                {
                    skip |= ValidateStructPnext("vkQueueSubmit2", ParameterName("pSubmits[%i].pSignalSemaphoreInfos[%i].pNext", ParameterName::IndexVector{ submitIndex, signalSemaphoreInfoIndex }), nullptr, pSubmits[submitIndex].pSignalSemaphoreInfos[signalSemaphoreInfoIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSemaphoreSubmitInfo-pNext-pNext", kVUIDUndefined, false, true);

                    skip |= ValidateRequiredHandle("vkQueueSubmit2", ParameterName("pSubmits[%i].pSignalSemaphoreInfos[%i].semaphore", ParameterName::IndexVector{ submitIndex, signalSemaphoreInfoIndex }), pSubmits[submitIndex].pSignalSemaphoreInfos[signalSemaphoreInfoIndex].semaphore);

                    skip |= ValidateFlags("vkQueueSubmit2", ParameterName("pSubmits[%i].pSignalSemaphoreInfos[%i].stageMask", ParameterName::IndexVector{ submitIndex, signalSemaphoreInfoIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pSubmits[submitIndex].pSignalSemaphoreInfos[signalSemaphoreInfoIndex].stageMask, kOptionalFlags, "VUID-VkSemaphoreSubmitInfo-stageMask-parameter");
                }
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkCmdCopyBuffer2", "pCopyBufferInfo", "VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2", pCopyBufferInfo, VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2, true, "VUID-vkCmdCopyBuffer2-pCopyBufferInfo-parameter", "VUID-VkCopyBufferInfo2-sType-sType");
    if (pCopyBufferInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdCopyBuffer2", "pCopyBufferInfo->pNext", nullptr, pCopyBufferInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCopyBufferInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkCmdCopyBuffer2", "pCopyBufferInfo->srcBuffer", pCopyBufferInfo->srcBuffer);

        skip |= ValidateRequiredHandle("vkCmdCopyBuffer2", "pCopyBufferInfo->dstBuffer", pCopyBufferInfo->dstBuffer);

        skip |= ValidateStructTypeArray("vkCmdCopyBuffer2", "pCopyBufferInfo->regionCount", "pCopyBufferInfo->pRegions", "VK_STRUCTURE_TYPE_BUFFER_COPY_2", pCopyBufferInfo->regionCount, pCopyBufferInfo->pRegions, VK_STRUCTURE_TYPE_BUFFER_COPY_2, true, true, "VUID-VkBufferCopy2-sType-sType", "VUID-VkCopyBufferInfo2-pRegions-parameter", "VUID-VkCopyBufferInfo2-regionCount-arraylength");

        if (pCopyBufferInfo->pRegions != nullptr)
        {
            for (uint32_t regionIndex = 0; regionIndex < pCopyBufferInfo->regionCount; ++regionIndex)
            {
                skip |= ValidateStructPnext("vkCmdCopyBuffer2", ParameterName("pCopyBufferInfo->pRegions[%i].pNext", ParameterName::IndexVector{ regionIndex }), nullptr, pCopyBufferInfo->pRegions[regionIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferCopy2-pNext-pNext", kVUIDUndefined, false, true);
            }
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkCmdCopyImage2", "pCopyImageInfo", "VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2", pCopyImageInfo, VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2, true, "VUID-vkCmdCopyImage2-pCopyImageInfo-parameter", "VUID-VkCopyImageInfo2-sType-sType");
    if (pCopyImageInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdCopyImage2", "pCopyImageInfo->pNext", nullptr, pCopyImageInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCopyImageInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkCmdCopyImage2", "pCopyImageInfo->srcImage", pCopyImageInfo->srcImage);

        skip |= ValidateRangedEnum("vkCmdCopyImage2", "pCopyImageInfo->srcImageLayout", "VkImageLayout", pCopyImageInfo->srcImageLayout, "VUID-VkCopyImageInfo2-srcImageLayout-parameter");

        skip |= ValidateRequiredHandle("vkCmdCopyImage2", "pCopyImageInfo->dstImage", pCopyImageInfo->dstImage);

        skip |= ValidateRangedEnum("vkCmdCopyImage2", "pCopyImageInfo->dstImageLayout", "VkImageLayout", pCopyImageInfo->dstImageLayout, "VUID-VkCopyImageInfo2-dstImageLayout-parameter");

        skip |= ValidateStructTypeArray("vkCmdCopyImage2", "pCopyImageInfo->regionCount", "pCopyImageInfo->pRegions", "VK_STRUCTURE_TYPE_IMAGE_COPY_2", pCopyImageInfo->regionCount, pCopyImageInfo->pRegions, VK_STRUCTURE_TYPE_IMAGE_COPY_2, true, true, "VUID-VkImageCopy2-sType-sType", "VUID-VkCopyImageInfo2-pRegions-parameter", "VUID-VkCopyImageInfo2-regionCount-arraylength");

        if (pCopyImageInfo->pRegions != nullptr)
        {
            for (uint32_t regionIndex = 0; regionIndex < pCopyImageInfo->regionCount; ++regionIndex)
            {
                skip |= ValidateStructPnext("vkCmdCopyImage2", ParameterName("pCopyImageInfo->pRegions[%i].pNext", ParameterName::IndexVector{ regionIndex }), nullptr, pCopyImageInfo->pRegions[regionIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkImageCopy2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdCopyImage2", ParameterName("pCopyImageInfo->pRegions[%i].srcSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pCopyImageInfo->pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                skip |= ValidateFlags("vkCmdCopyImage2", ParameterName("pCopyImageInfo->pRegions[%i].dstSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pCopyImageInfo->pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyBufferToImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkCmdCopyBufferToImage2", "pCopyBufferToImageInfo", "VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2", pCopyBufferToImageInfo, VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2, true, "VUID-vkCmdCopyBufferToImage2-pCopyBufferToImageInfo-parameter", "VUID-VkCopyBufferToImageInfo2-sType-sType");
    if (pCopyBufferToImageInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdCopyBufferToImage2", "pCopyBufferToImageInfo->pNext", nullptr, pCopyBufferToImageInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCopyBufferToImageInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkCmdCopyBufferToImage2", "pCopyBufferToImageInfo->srcBuffer", pCopyBufferToImageInfo->srcBuffer);

        skip |= ValidateRequiredHandle("vkCmdCopyBufferToImage2", "pCopyBufferToImageInfo->dstImage", pCopyBufferToImageInfo->dstImage);

        skip |= ValidateRangedEnum("vkCmdCopyBufferToImage2", "pCopyBufferToImageInfo->dstImageLayout", "VkImageLayout", pCopyBufferToImageInfo->dstImageLayout, "VUID-VkCopyBufferToImageInfo2-dstImageLayout-parameter");

        skip |= ValidateStructTypeArray("vkCmdCopyBufferToImage2", "pCopyBufferToImageInfo->regionCount", "pCopyBufferToImageInfo->pRegions", "VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2", pCopyBufferToImageInfo->regionCount, pCopyBufferToImageInfo->pRegions, VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2, true, true, "VUID-VkBufferImageCopy2-sType-sType", "VUID-VkCopyBufferToImageInfo2-pRegions-parameter", "VUID-VkCopyBufferToImageInfo2-regionCount-arraylength");

        if (pCopyBufferToImageInfo->pRegions != nullptr)
        {
            for (uint32_t regionIndex = 0; regionIndex < pCopyBufferToImageInfo->regionCount; ++regionIndex)
            {
                skip |= ValidateStructPnext("vkCmdCopyBufferToImage2", ParameterName("pCopyBufferToImageInfo->pRegions[%i].pNext", ParameterName::IndexVector{ regionIndex }), nullptr, pCopyBufferToImageInfo->pRegions[regionIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferImageCopy2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdCopyBufferToImage2", ParameterName("pCopyBufferToImageInfo->pRegions[%i].imageSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pCopyBufferToImageInfo->pRegions[regionIndex].imageSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyImageToBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkCmdCopyImageToBuffer2", "pCopyImageToBufferInfo", "VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2", pCopyImageToBufferInfo, VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2, true, "VUID-vkCmdCopyImageToBuffer2-pCopyImageToBufferInfo-parameter", "VUID-VkCopyImageToBufferInfo2-sType-sType");
    if (pCopyImageToBufferInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdCopyImageToBuffer2", "pCopyImageToBufferInfo->pNext", nullptr, pCopyImageToBufferInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCopyImageToBufferInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkCmdCopyImageToBuffer2", "pCopyImageToBufferInfo->srcImage", pCopyImageToBufferInfo->srcImage);

        skip |= ValidateRangedEnum("vkCmdCopyImageToBuffer2", "pCopyImageToBufferInfo->srcImageLayout", "VkImageLayout", pCopyImageToBufferInfo->srcImageLayout, "VUID-VkCopyImageToBufferInfo2-srcImageLayout-parameter");

        skip |= ValidateRequiredHandle("vkCmdCopyImageToBuffer2", "pCopyImageToBufferInfo->dstBuffer", pCopyImageToBufferInfo->dstBuffer);

        skip |= ValidateStructTypeArray("vkCmdCopyImageToBuffer2", "pCopyImageToBufferInfo->regionCount", "pCopyImageToBufferInfo->pRegions", "VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2", pCopyImageToBufferInfo->regionCount, pCopyImageToBufferInfo->pRegions, VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2, true, true, "VUID-VkBufferImageCopy2-sType-sType", "VUID-VkCopyImageToBufferInfo2-pRegions-parameter", "VUID-VkCopyImageToBufferInfo2-regionCount-arraylength");

        if (pCopyImageToBufferInfo->pRegions != nullptr)
        {
            for (uint32_t regionIndex = 0; regionIndex < pCopyImageToBufferInfo->regionCount; ++regionIndex)
            {
                skip |= ValidateStructPnext("vkCmdCopyImageToBuffer2", ParameterName("pCopyImageToBufferInfo->pRegions[%i].pNext", ParameterName::IndexVector{ regionIndex }), nullptr, pCopyImageToBufferInfo->pRegions[regionIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferImageCopy2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdCopyImageToBuffer2", ParameterName("pCopyImageToBufferInfo->pRegions[%i].imageSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pCopyImageToBufferInfo->pRegions[regionIndex].imageSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBlitImage2(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkCmdBlitImage2", "pBlitImageInfo", "VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2", pBlitImageInfo, VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2, true, "VUID-vkCmdBlitImage2-pBlitImageInfo-parameter", "VUID-VkBlitImageInfo2-sType-sType");
    if (pBlitImageInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdBlitImage2", "pBlitImageInfo->pNext", nullptr, pBlitImageInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBlitImageInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkCmdBlitImage2", "pBlitImageInfo->srcImage", pBlitImageInfo->srcImage);

        skip |= ValidateRangedEnum("vkCmdBlitImage2", "pBlitImageInfo->srcImageLayout", "VkImageLayout", pBlitImageInfo->srcImageLayout, "VUID-VkBlitImageInfo2-srcImageLayout-parameter");

        skip |= ValidateRequiredHandle("vkCmdBlitImage2", "pBlitImageInfo->dstImage", pBlitImageInfo->dstImage);

        skip |= ValidateRangedEnum("vkCmdBlitImage2", "pBlitImageInfo->dstImageLayout", "VkImageLayout", pBlitImageInfo->dstImageLayout, "VUID-VkBlitImageInfo2-dstImageLayout-parameter");

        skip |= ValidateStructTypeArray("vkCmdBlitImage2", "pBlitImageInfo->regionCount", "pBlitImageInfo->pRegions", "VK_STRUCTURE_TYPE_IMAGE_BLIT_2", pBlitImageInfo->regionCount, pBlitImageInfo->pRegions, VK_STRUCTURE_TYPE_IMAGE_BLIT_2, true, true, "VUID-VkImageBlit2-sType-sType", "VUID-VkBlitImageInfo2-pRegions-parameter", "VUID-VkBlitImageInfo2-regionCount-arraylength");

        if (pBlitImageInfo->pRegions != nullptr)
        {
            for (uint32_t regionIndex = 0; regionIndex < pBlitImageInfo->regionCount; ++regionIndex)
            {
                skip |= ValidateStructPnext("vkCmdBlitImage2", ParameterName("pBlitImageInfo->pRegions[%i].pNext", ParameterName::IndexVector{ regionIndex }), nullptr, pBlitImageInfo->pRegions[regionIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkImageBlit2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdBlitImage2", ParameterName("pBlitImageInfo->pRegions[%i].srcSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pBlitImageInfo->pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                skip |= ValidateFlags("vkCmdBlitImage2", ParameterName("pBlitImageInfo->pRegions[%i].dstSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pBlitImageInfo->pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");
            }
        }

        skip |= ValidateRangedEnum("vkCmdBlitImage2", "pBlitImageInfo->filter", "VkFilter", pBlitImageInfo->filter, "VUID-VkBlitImageInfo2-filter-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResolveImage2(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkCmdResolveImage2", "pResolveImageInfo", "VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2", pResolveImageInfo, VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2, true, "VUID-vkCmdResolveImage2-pResolveImageInfo-parameter", "VUID-VkResolveImageInfo2-sType-sType");
    if (pResolveImageInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdResolveImage2", "pResolveImageInfo->pNext", nullptr, pResolveImageInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkResolveImageInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkCmdResolveImage2", "pResolveImageInfo->srcImage", pResolveImageInfo->srcImage);

        skip |= ValidateRangedEnum("vkCmdResolveImage2", "pResolveImageInfo->srcImageLayout", "VkImageLayout", pResolveImageInfo->srcImageLayout, "VUID-VkResolveImageInfo2-srcImageLayout-parameter");

        skip |= ValidateRequiredHandle("vkCmdResolveImage2", "pResolveImageInfo->dstImage", pResolveImageInfo->dstImage);

        skip |= ValidateRangedEnum("vkCmdResolveImage2", "pResolveImageInfo->dstImageLayout", "VkImageLayout", pResolveImageInfo->dstImageLayout, "VUID-VkResolveImageInfo2-dstImageLayout-parameter");

        skip |= ValidateStructTypeArray("vkCmdResolveImage2", "pResolveImageInfo->regionCount", "pResolveImageInfo->pRegions", "VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2", pResolveImageInfo->regionCount, pResolveImageInfo->pRegions, VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2, true, true, "VUID-VkImageResolve2-sType-sType", "VUID-VkResolveImageInfo2-pRegions-parameter", "VUID-VkResolveImageInfo2-regionCount-arraylength");

        if (pResolveImageInfo->pRegions != nullptr)
        {
            for (uint32_t regionIndex = 0; regionIndex < pResolveImageInfo->regionCount; ++regionIndex)
            {
                skip |= ValidateStructPnext("vkCmdResolveImage2", ParameterName("pResolveImageInfo->pRegions[%i].pNext", ParameterName::IndexVector{ regionIndex }), nullptr, pResolveImageInfo->pRegions[regionIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkImageResolve2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdResolveImage2", ParameterName("pResolveImageInfo->pRegions[%i].srcSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pResolveImageInfo->pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                skip |= ValidateFlags("vkCmdResolveImage2", ParameterName("pResolveImageInfo->pRegions[%i].dstSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pResolveImageInfo->pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBeginRendering(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) const {
    bool skip = false;
    skip |= ValidateStructType("vkCmdBeginRendering", "pRenderingInfo", "VK_STRUCTURE_TYPE_RENDERING_INFO", pRenderingInfo, VK_STRUCTURE_TYPE_RENDERING_INFO, true, kVUIDUndefined, kVUIDUndefined);
    if (pRenderingInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkRenderingInfo = { VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO };

        skip |= ValidateStructPnext("vkCmdBeginRendering", "pRenderingInfo->pNext", "VkDeviceGroupRenderPassBeginInfo", pRenderingInfo->pNext, allowed_structs_VkRenderingInfo.size(), allowed_structs_VkRenderingInfo.data(), GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

        skip |= ValidateFlags("vkCmdBeginRendering", "pRenderingInfo->flags", "VkRenderingFlagBits", AllVkRenderingFlagBits, pRenderingInfo->flags, kOptionalFlags, kVUIDUndefined);

        // No xml-driven validation

        // No xml-driven validation

        skip |= ValidateStructTypeArray("vkCmdBeginRendering", "pRenderingInfo->colorAttachmentCount", "pRenderingInfo->pColorAttachments", "VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO", pRenderingInfo->colorAttachmentCount, pRenderingInfo->pColorAttachments, VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO, false, true, kVUIDUndefined, kVUIDUndefined, kVUIDUndefined);

        if (pRenderingInfo->pColorAttachments != nullptr)
        {
            for (uint32_t colorAttachmentIndex = 0; colorAttachmentIndex < pRenderingInfo->colorAttachmentCount; ++colorAttachmentIndex)
            {
                skip |= ValidateStructPnext("vkCmdBeginRendering", ParameterName("pRenderingInfo->pColorAttachments[%i].pNext", ParameterName::IndexVector{ colorAttachmentIndex }), nullptr, pRenderingInfo->pColorAttachments[colorAttachmentIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                skip |= ValidateRangedEnum("vkCmdBeginRendering", ParameterName("pRenderingInfo->pColorAttachments[%i].imageLayout", ParameterName::IndexVector{ colorAttachmentIndex }), "VkImageLayout", pRenderingInfo->pColorAttachments[colorAttachmentIndex].imageLayout, kVUIDUndefined);

                skip |= ValidateFlags("vkCmdBeginRendering", ParameterName("pRenderingInfo->pColorAttachments[%i].resolveMode", ParameterName::IndexVector{ colorAttachmentIndex }), "VkResolveModeFlagBits", AllVkResolveModeFlagBits, pRenderingInfo->pColorAttachments[colorAttachmentIndex].resolveMode, kOptionalSingleBit, kVUIDUndefined);

                skip |= ValidateRangedEnum("vkCmdBeginRendering", ParameterName("pRenderingInfo->pColorAttachments[%i].resolveImageLayout", ParameterName::IndexVector{ colorAttachmentIndex }), "VkImageLayout", pRenderingInfo->pColorAttachments[colorAttachmentIndex].resolveImageLayout, kVUIDUndefined);

                skip |= ValidateRangedEnum("vkCmdBeginRendering", ParameterName("pRenderingInfo->pColorAttachments[%i].loadOp", ParameterName::IndexVector{ colorAttachmentIndex }), "VkAttachmentLoadOp", pRenderingInfo->pColorAttachments[colorAttachmentIndex].loadOp, kVUIDUndefined);

                skip |= ValidateRangedEnum("vkCmdBeginRendering", ParameterName("pRenderingInfo->pColorAttachments[%i].storeOp", ParameterName::IndexVector{ colorAttachmentIndex }), "VkAttachmentStoreOp", pRenderingInfo->pColorAttachments[colorAttachmentIndex].storeOp, kVUIDUndefined);

                // No xml-driven validation
            }
        }

        skip |= ValidateStructType("vkCmdBeginRendering", "pRenderingInfo->pDepthAttachment", "VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO", pRenderingInfo->pDepthAttachment, VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO, false, kVUIDUndefined, kVUIDUndefined);

        if (pRenderingInfo->pDepthAttachment != nullptr)
        {
            skip |= ValidateStructPnext("vkCmdBeginRendering", "pRenderingInfo->pDepthAttachment->pNext", nullptr, pRenderingInfo->pDepthAttachment->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

            skip |= ValidateRangedEnum("vkCmdBeginRendering", "pRenderingInfo->pDepthAttachment->imageLayout", "VkImageLayout", pRenderingInfo->pDepthAttachment->imageLayout, kVUIDUndefined);

            skip |= ValidateFlags("vkCmdBeginRendering", "pRenderingInfo->pDepthAttachment->resolveMode", "VkResolveModeFlagBits", AllVkResolveModeFlagBits, pRenderingInfo->pDepthAttachment->resolveMode, kOptionalSingleBit, kVUIDUndefined);

            skip |= ValidateRangedEnum("vkCmdBeginRendering", "pRenderingInfo->pDepthAttachment->resolveImageLayout", "VkImageLayout", pRenderingInfo->pDepthAttachment->resolveImageLayout, kVUIDUndefined);

            skip |= ValidateRangedEnum("vkCmdBeginRendering", "pRenderingInfo->pDepthAttachment->loadOp", "VkAttachmentLoadOp", pRenderingInfo->pDepthAttachment->loadOp, kVUIDUndefined);

            skip |= ValidateRangedEnum("vkCmdBeginRendering", "pRenderingInfo->pDepthAttachment->storeOp", "VkAttachmentStoreOp", pRenderingInfo->pDepthAttachment->storeOp, kVUIDUndefined);

            // No xml-driven validation
        }

        skip |= ValidateStructType("vkCmdBeginRendering", "pRenderingInfo->pStencilAttachment", "VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO", pRenderingInfo->pStencilAttachment, VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO, false, kVUIDUndefined, kVUIDUndefined);

        if (pRenderingInfo->pStencilAttachment != nullptr)
        {
            skip |= ValidateStructPnext("vkCmdBeginRendering", "pRenderingInfo->pStencilAttachment->pNext", nullptr, pRenderingInfo->pStencilAttachment->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

            skip |= ValidateRangedEnum("vkCmdBeginRendering", "pRenderingInfo->pStencilAttachment->imageLayout", "VkImageLayout", pRenderingInfo->pStencilAttachment->imageLayout, kVUIDUndefined);

            skip |= ValidateFlags("vkCmdBeginRendering", "pRenderingInfo->pStencilAttachment->resolveMode", "VkResolveModeFlagBits", AllVkResolveModeFlagBits, pRenderingInfo->pStencilAttachment->resolveMode, kOptionalSingleBit, kVUIDUndefined);

            skip |= ValidateRangedEnum("vkCmdBeginRendering", "pRenderingInfo->pStencilAttachment->resolveImageLayout", "VkImageLayout", pRenderingInfo->pStencilAttachment->resolveImageLayout, kVUIDUndefined);

            skip |= ValidateRangedEnum("vkCmdBeginRendering", "pRenderingInfo->pStencilAttachment->loadOp", "VkAttachmentLoadOp", pRenderingInfo->pStencilAttachment->loadOp, kVUIDUndefined);

            skip |= ValidateRangedEnum("vkCmdBeginRendering", "pRenderingInfo->pStencilAttachment->storeOp", "VkAttachmentStoreOp", pRenderingInfo->pStencilAttachment->storeOp, kVUIDUndefined);

            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdBeginRendering(commandBuffer, pRenderingInfo);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdEndRendering(
    VkCommandBuffer                             commandBuffer) const {
    bool skip = false;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetCullMode(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) const {
    bool skip = false;
    skip |= ValidateFlags("vkCmdSetCullMode", "cullMode", "VkCullModeFlagBits", AllVkCullModeFlagBits, cullMode, kOptionalFlags, "VUID-vkCmdSetCullMode-cullMode-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetFrontFace(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) const {
    bool skip = false;
    skip |= ValidateRangedEnum("vkCmdSetFrontFace", "frontFace", "VkFrontFace", frontFace, "VUID-vkCmdSetFrontFace-frontFace-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetPrimitiveTopology(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) const {
    bool skip = false;
    skip |= ValidateRangedEnum("vkCmdSetPrimitiveTopology", "primitiveTopology", "VkPrimitiveTopology", primitiveTopology, "VUID-vkCmdSetPrimitiveTopology-primitiveTopology-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetViewportWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) const {
    bool skip = false;
    skip |= ValidateArray("vkCmdSetViewportWithCount", "viewportCount", "pViewports", viewportCount, &pViewports, true, true, "VUID-vkCmdSetViewportWithCount-viewportCount-arraylength", "VUID-vkCmdSetViewportWithCount-pViewports-parameter");
    if (pViewports != nullptr)
    {
        for (uint32_t viewportIndex = 0; viewportIndex < viewportCount; ++viewportIndex)
        {
            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetScissorWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) const {
    bool skip = false;
    skip |= ValidateArray("vkCmdSetScissorWithCount", "scissorCount", "pScissors", scissorCount, &pScissors, true, true, "VUID-vkCmdSetScissorWithCount-scissorCount-arraylength", "VUID-vkCmdSetScissorWithCount-pScissors-parameter");
    if (pScissors != nullptr)
    {
        for (uint32_t scissorIndex = 0; scissorIndex < scissorCount; ++scissorIndex)
        {
            // No xml-driven validation

            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBindVertexBuffers2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) const {
    bool skip = false;
    // No xml-driven validation
    if (!skip) skip |= manual_PreCallValidateCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) const {
    bool skip = false;
    skip |= ValidateBool32("vkCmdSetDepthTestEnable", "depthTestEnable", depthTestEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthWriteEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) const {
    bool skip = false;
    skip |= ValidateBool32("vkCmdSetDepthWriteEnable", "depthWriteEnable", depthWriteEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthCompareOp(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) const {
    bool skip = false;
    skip |= ValidateRangedEnum("vkCmdSetDepthCompareOp", "depthCompareOp", "VkCompareOp", depthCompareOp, "VUID-vkCmdSetDepthCompareOp-depthCompareOp-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthBoundsTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) const {
    bool skip = false;
    skip |= ValidateBool32("vkCmdSetDepthBoundsTestEnable", "depthBoundsTestEnable", depthBoundsTestEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) const {
    bool skip = false;
    skip |= ValidateBool32("vkCmdSetStencilTestEnable", "stencilTestEnable", stencilTestEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilOp(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) const {
    bool skip = false;
    skip |= ValidateFlags("vkCmdSetStencilOp", "faceMask", "VkStencilFaceFlagBits", AllVkStencilFaceFlagBits, faceMask, kRequiredFlags, "VUID-vkCmdSetStencilOp-faceMask-parameter", "VUID-vkCmdSetStencilOp-faceMask-requiredbitmask");
    skip |= ValidateRangedEnum("vkCmdSetStencilOp", "failOp", "VkStencilOp", failOp, "VUID-vkCmdSetStencilOp-failOp-parameter");
    skip |= ValidateRangedEnum("vkCmdSetStencilOp", "passOp", "VkStencilOp", passOp, "VUID-vkCmdSetStencilOp-passOp-parameter");
    skip |= ValidateRangedEnum("vkCmdSetStencilOp", "depthFailOp", "VkStencilOp", depthFailOp, "VUID-vkCmdSetStencilOp-depthFailOp-parameter");
    skip |= ValidateRangedEnum("vkCmdSetStencilOp", "compareOp", "VkCompareOp", compareOp, "VUID-vkCmdSetStencilOp-compareOp-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetRasterizerDiscardEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) const {
    bool skip = false;
    skip |= ValidateBool32("vkCmdSetRasterizerDiscardEnable", "rasterizerDiscardEnable", rasterizerDiscardEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthBiasEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) const {
    bool skip = false;
    skip |= ValidateBool32("vkCmdSetDepthBiasEnable", "depthBiasEnable", depthBiasEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetPrimitiveRestartEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) const {
    bool skip = false;
    skip |= ValidateBool32("vkCmdSetPrimitiveRestartEnable", "primitiveRestartEnable", primitiveRestartEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceBufferMemoryRequirements(
    VkDevice                                    device,
    const VkDeviceBufferMemoryRequirements*     pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateStructType("vkGetDeviceBufferMemoryRequirements", "pInfo", "VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS", pInfo, VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetDeviceBufferMemoryRequirements", "pInfo->pNext", nullptr, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

        skip |= ValidateStructType("vkGetDeviceBufferMemoryRequirements", "pInfo->pCreateInfo", "VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO", pInfo->pCreateInfo, VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO, true, kVUIDUndefined, "VUID-VkBufferCreateInfo-sType-sType");

        if (pInfo->pCreateInfo != nullptr)
        {
            constexpr std::array allowed_structs_VkBufferCreateInfo = { VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO, VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO };

            skip |= ValidateStructPnext("vkGetDeviceBufferMemoryRequirements", "pInfo->pCreateInfo->pNext", "VkBufferOpaqueCaptureAddressCreateInfo, VkExternalMemoryBufferCreateInfo", pInfo->pCreateInfo->pNext, allowed_structs_VkBufferCreateInfo.size(), allowed_structs_VkBufferCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkBufferCreateInfo-pNext-pNext", "VUID-VkBufferCreateInfo-sType-unique", false, true);

            skip |= ValidateFlags("vkGetDeviceBufferMemoryRequirements", "pInfo->pCreateInfo->flags", "VkBufferCreateFlagBits", AllVkBufferCreateFlagBits, pInfo->pCreateInfo->flags, kOptionalFlags, "VUID-VkBufferCreateInfo-flags-parameter");

            skip |= ValidateFlags("vkGetDeviceBufferMemoryRequirements", "pInfo->pCreateInfo->usage", "VkBufferUsageFlagBits", AllVkBufferUsageFlagBits, pInfo->pCreateInfo->usage, kRequiredFlags, "VUID-VkBufferCreateInfo-usage-parameter", "VUID-VkBufferCreateInfo-usage-requiredbitmask");

            skip |= ValidateRangedEnum("vkGetDeviceBufferMemoryRequirements", "pInfo->pCreateInfo->sharingMode", "VkSharingMode", pInfo->pCreateInfo->sharingMode, "VUID-VkBufferCreateInfo-sharingMode-parameter");
        }
    }
    skip |= ValidateStructType("vkGetDeviceBufferMemoryRequirements", "pMemoryRequirements", "VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2", pMemoryRequirements, VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, true, kVUIDUndefined, "VUID-VkMemoryRequirements2-sType-sType");
    if (pMemoryRequirements != nullptr)
    {
        constexpr std::array allowed_structs_VkMemoryRequirements2 = { VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS };

        skip |= ValidateStructPnext("vkGetDeviceBufferMemoryRequirements", "pMemoryRequirements->pNext", "VkMemoryDedicatedRequirements", pMemoryRequirements->pNext, allowed_structs_VkMemoryRequirements2.size(), allowed_structs_VkMemoryRequirements2.data(), GeneratedVulkanHeaderVersion, "VUID-VkMemoryRequirements2-pNext-pNext", "VUID-VkMemoryRequirements2-sType-unique", false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceImageMemoryRequirements(
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateStructType("vkGetDeviceImageMemoryRequirements", "pInfo", "VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS", pInfo, VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetDeviceImageMemoryRequirements", "pInfo->pNext", nullptr, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

        skip |= ValidateStructType("vkGetDeviceImageMemoryRequirements", "pInfo->pCreateInfo", "VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO", pInfo->pCreateInfo, VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO, true, kVUIDUndefined, "VUID-VkImageCreateInfo-sType-sType");

        if (pInfo->pCreateInfo != nullptr)
        {
            constexpr std::array allowed_structs_VkImageCreateInfo = { VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT, VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO, VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO, VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR };

            skip |= ValidateStructPnext("vkGetDeviceImageMemoryRequirements", "pInfo->pCreateInfo->pNext", "VkExternalMemoryImageCreateInfo, VkImageDrmFormatModifierExplicitCreateInfoEXT, VkImageDrmFormatModifierListCreateInfoEXT, VkImageFormatListCreateInfo, VkImageStencilUsageCreateInfo, VkImageSwapchainCreateInfoKHR", pInfo->pCreateInfo->pNext, allowed_structs_VkImageCreateInfo.size(), allowed_structs_VkImageCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageCreateInfo-pNext-pNext", "VUID-VkImageCreateInfo-sType-unique", false, true);

            skip |= ValidateFlags("vkGetDeviceImageMemoryRequirements", "pInfo->pCreateInfo->flags", "VkImageCreateFlagBits", AllVkImageCreateFlagBits, pInfo->pCreateInfo->flags, kOptionalFlags, "VUID-VkImageCreateInfo-flags-parameter");

            skip |= ValidateRangedEnum("vkGetDeviceImageMemoryRequirements", "pInfo->pCreateInfo->imageType", "VkImageType", pInfo->pCreateInfo->imageType, "VUID-VkImageCreateInfo-imageType-parameter");

            skip |= ValidateRangedEnum("vkGetDeviceImageMemoryRequirements", "pInfo->pCreateInfo->format", "VkFormat", pInfo->pCreateInfo->format, "VUID-VkImageCreateInfo-format-parameter");

            // No xml-driven validation

            skip |= ValidateFlags("vkGetDeviceImageMemoryRequirements", "pInfo->pCreateInfo->samples", "VkSampleCountFlagBits", AllVkSampleCountFlagBits, pInfo->pCreateInfo->samples, kRequiredSingleBit, "VUID-VkImageCreateInfo-samples-parameter", "VUID-VkImageCreateInfo-samples-parameter");

            skip |= ValidateRangedEnum("vkGetDeviceImageMemoryRequirements", "pInfo->pCreateInfo->tiling", "VkImageTiling", pInfo->pCreateInfo->tiling, "VUID-VkImageCreateInfo-tiling-parameter");

            skip |= ValidateFlags("vkGetDeviceImageMemoryRequirements", "pInfo->pCreateInfo->usage", "VkImageUsageFlagBits", AllVkImageUsageFlagBits, pInfo->pCreateInfo->usage, kRequiredFlags, "VUID-VkImageCreateInfo-usage-parameter", "VUID-VkImageCreateInfo-usage-requiredbitmask");

            skip |= ValidateRangedEnum("vkGetDeviceImageMemoryRequirements", "pInfo->pCreateInfo->sharingMode", "VkSharingMode", pInfo->pCreateInfo->sharingMode, "VUID-VkImageCreateInfo-sharingMode-parameter");

            skip |= ValidateRangedEnum("vkGetDeviceImageMemoryRequirements", "pInfo->pCreateInfo->initialLayout", "VkImageLayout", pInfo->pCreateInfo->initialLayout, "VUID-VkImageCreateInfo-initialLayout-parameter");
        }

        skip |= ValidateFlags("vkGetDeviceImageMemoryRequirements", "pInfo->planeAspect", "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pInfo->planeAspect, kOptionalSingleBit, kVUIDUndefined);
    }
    skip |= ValidateStructType("vkGetDeviceImageMemoryRequirements", "pMemoryRequirements", "VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2", pMemoryRequirements, VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, true, kVUIDUndefined, "VUID-VkMemoryRequirements2-sType-sType");
    if (pMemoryRequirements != nullptr)
    {
        constexpr std::array allowed_structs_VkMemoryRequirements2 = { VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS };

        skip |= ValidateStructPnext("vkGetDeviceImageMemoryRequirements", "pMemoryRequirements->pNext", "VkMemoryDedicatedRequirements", pMemoryRequirements->pNext, allowed_structs_VkMemoryRequirements2.size(), allowed_structs_VkMemoryRequirements2.data(), GeneratedVulkanHeaderVersion, "VUID-VkMemoryRequirements2-pNext-pNext", "VUID-VkMemoryRequirements2-sType-unique", false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceImageSparseMemoryRequirements(
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements) const {
    bool skip = false;
    skip |= ValidateStructType("vkGetDeviceImageSparseMemoryRequirements", "pInfo", "VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS", pInfo, VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetDeviceImageSparseMemoryRequirements", "pInfo->pNext", nullptr, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

        skip |= ValidateStructType("vkGetDeviceImageSparseMemoryRequirements", "pInfo->pCreateInfo", "VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO", pInfo->pCreateInfo, VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO, true, kVUIDUndefined, "VUID-VkImageCreateInfo-sType-sType");

        if (pInfo->pCreateInfo != nullptr)
        {
            constexpr std::array allowed_structs_VkImageCreateInfo = { VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT, VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO, VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO, VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR };

            skip |= ValidateStructPnext("vkGetDeviceImageSparseMemoryRequirements", "pInfo->pCreateInfo->pNext", "VkExternalMemoryImageCreateInfo, VkImageDrmFormatModifierExplicitCreateInfoEXT, VkImageDrmFormatModifierListCreateInfoEXT, VkImageFormatListCreateInfo, VkImageStencilUsageCreateInfo, VkImageSwapchainCreateInfoKHR", pInfo->pCreateInfo->pNext, allowed_structs_VkImageCreateInfo.size(), allowed_structs_VkImageCreateInfo.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageCreateInfo-pNext-pNext", "VUID-VkImageCreateInfo-sType-unique", false, true);

            skip |= ValidateFlags("vkGetDeviceImageSparseMemoryRequirements", "pInfo->pCreateInfo->flags", "VkImageCreateFlagBits", AllVkImageCreateFlagBits, pInfo->pCreateInfo->flags, kOptionalFlags, "VUID-VkImageCreateInfo-flags-parameter");

            skip |= ValidateRangedEnum("vkGetDeviceImageSparseMemoryRequirements", "pInfo->pCreateInfo->imageType", "VkImageType", pInfo->pCreateInfo->imageType, "VUID-VkImageCreateInfo-imageType-parameter");

            skip |= ValidateRangedEnum("vkGetDeviceImageSparseMemoryRequirements", "pInfo->pCreateInfo->format", "VkFormat", pInfo->pCreateInfo->format, "VUID-VkImageCreateInfo-format-parameter");

            // No xml-driven validation

            skip |= ValidateFlags("vkGetDeviceImageSparseMemoryRequirements", "pInfo->pCreateInfo->samples", "VkSampleCountFlagBits", AllVkSampleCountFlagBits, pInfo->pCreateInfo->samples, kRequiredSingleBit, "VUID-VkImageCreateInfo-samples-parameter", "VUID-VkImageCreateInfo-samples-parameter");

            skip |= ValidateRangedEnum("vkGetDeviceImageSparseMemoryRequirements", "pInfo->pCreateInfo->tiling", "VkImageTiling", pInfo->pCreateInfo->tiling, "VUID-VkImageCreateInfo-tiling-parameter");

            skip |= ValidateFlags("vkGetDeviceImageSparseMemoryRequirements", "pInfo->pCreateInfo->usage", "VkImageUsageFlagBits", AllVkImageUsageFlagBits, pInfo->pCreateInfo->usage, kRequiredFlags, "VUID-VkImageCreateInfo-usage-parameter", "VUID-VkImageCreateInfo-usage-requiredbitmask");

            skip |= ValidateRangedEnum("vkGetDeviceImageSparseMemoryRequirements", "pInfo->pCreateInfo->sharingMode", "VkSharingMode", pInfo->pCreateInfo->sharingMode, "VUID-VkImageCreateInfo-sharingMode-parameter");

            skip |= ValidateRangedEnum("vkGetDeviceImageSparseMemoryRequirements", "pInfo->pCreateInfo->initialLayout", "VkImageLayout", pInfo->pCreateInfo->initialLayout, "VUID-VkImageCreateInfo-initialLayout-parameter");
        }

        skip |= ValidateFlags("vkGetDeviceImageSparseMemoryRequirements", "pInfo->planeAspect", "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pInfo->planeAspect, kOptionalSingleBit, kVUIDUndefined);
    }
    skip |= ValidateStructTypeArray("vkGetDeviceImageSparseMemoryRequirements", "pSparseMemoryRequirementCount", "pSparseMemoryRequirements", "VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2", pSparseMemoryRequirementCount, pSparseMemoryRequirements, VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, true, false, false, kVUIDUndefined, kVUIDUndefined, kVUIDUndefined);
    return skip;
}



bool StatelessValidation::PreCallValidateGetCommandPoolMemoryConsumption(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandBuffer                             commandBuffer,
    VkCommandPoolMemoryConsumption*             pConsumption) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkGetCommandPoolMemoryConsumption", "commandPool", commandPool);
    skip |= ValidateStructType("vkGetCommandPoolMemoryConsumption", "pConsumption", "VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_CONSUMPTION", pConsumption, VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_CONSUMPTION, true, "VUID-vkGetCommandPoolMemoryConsumption-pConsumption-parameter", "VUID-VkCommandPoolMemoryConsumption-sType-sType");
    if (pConsumption != nullptr)
    {
        skip |= ValidateStructPnext("vkGetCommandPoolMemoryConsumption", "pConsumption->pNext", nullptr, pConsumption->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCommandPoolMemoryConsumption-pNext-pNext", kVUIDUndefined, false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetFaultData(
    VkDevice                                    device,
    VkFaultQueryBehavior                        faultQueryBehavior,
    VkBool32*                                   pUnrecordedFaults,
    uint32_t*                                   pFaultCount,
    VkFaultData*                                pFaults) const {
    bool skip = false;
    skip |= ValidateRangedEnum("vkGetFaultData", "faultQueryBehavior", "VkFaultQueryBehavior", faultQueryBehavior, "VUID-vkGetFaultData-faultQueryBehavior-parameter");
    skip |= ValidateRequiredPointer("vkGetFaultData", "pUnrecordedFaults", pUnrecordedFaults, "VUID-vkGetFaultData-pUnrecordedFaults-parameter");
    skip |= ValidateStructTypeArray("vkGetFaultData", "pFaultCount", "pFaults", "VK_STRUCTURE_TYPE_FAULT_DATA", pFaultCount, pFaults, VK_STRUCTURE_TYPE_FAULT_DATA, true, true, false, "VUID-VkFaultData-sType-sType", "VUID-vkGetFaultData-pFaults-parameter", "VUID-vkGetFaultData-pFaultCount-arraylength");
    if (pFaults != nullptr)
    {
        for (uint32_t pFaultIndex = 0; pFaultIndex < *pFaultCount; ++pFaultIndex)
        {
            // No xml-driven validation
        }
    }
    return skip;
}



bool StatelessValidation::PreCallValidateDestroySurfaceKHR(
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkDestroySurfaceKHR", "VK_KHR_surface");
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroySurfaceKHR-pAllocator-null", "vkDestroySurfaceKHR(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfaceSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    VkBool32*                                   pSupported) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkGetPhysicalDeviceSurfaceSupportKHR", "VK_KHR_surface");
    skip |= ValidateRequiredHandle("vkGetPhysicalDeviceSurfaceSupportKHR", "surface", surface);
    skip |= ValidateRequiredPointer("vkGetPhysicalDeviceSurfaceSupportKHR", "pSupported", pSupported, "VUID-vkGetPhysicalDeviceSurfaceSupportKHR-pSupported-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilitiesKHR*                   pSurfaceCapabilities) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkGetPhysicalDeviceSurfaceCapabilitiesKHR", "VK_KHR_surface");
    skip |= ValidateRequiredHandle("vkGetPhysicalDeviceSurfaceCapabilitiesKHR", "surface", surface);
    skip |= ValidateRequiredPointer("vkGetPhysicalDeviceSurfaceCapabilitiesKHR", "pSurfaceCapabilities", pSurfaceCapabilities, "VUID-vkGetPhysicalDeviceSurfaceCapabilitiesKHR-pSurfaceCapabilities-parameter");
    if (pSurfaceCapabilities != nullptr)
    {
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfaceFormatsKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormatKHR*                         pSurfaceFormats) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkGetPhysicalDeviceSurfaceFormatsKHR", "VK_KHR_surface");
    skip |= ValidateArray("vkGetPhysicalDeviceSurfaceFormatsKHR", "pSurfaceFormatCount", "pSurfaceFormats", pSurfaceFormatCount, &pSurfaceFormats, true, false, false, kVUIDUndefined, "VUID-vkGetPhysicalDeviceSurfaceFormatsKHR-pSurfaceFormats-parameter");
    if (pSurfaceFormats != nullptr)
    {
        for (uint32_t pSurfaceFormatIndex = 0; pSurfaceFormatIndex < *pSurfaceFormatCount; ++pSurfaceFormatIndex)
        {
            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfacePresentModesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkGetPhysicalDeviceSurfacePresentModesKHR", "VK_KHR_surface");
    skip |= ValidateArray("vkGetPhysicalDeviceSurfacePresentModesKHR", "pPresentModeCount", "pPresentModes", pPresentModeCount, &pPresentModes, true, false, false, kVUIDUndefined, "VUID-vkGetPhysicalDeviceSurfacePresentModesKHR-pPresentModes-parameter");
    if (!skip) skip |= manual_PreCallValidateGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    return skip;
}



bool StatelessValidation::PreCallValidateCreateSwapchainKHR(
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchain) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_khr_surface)) skip |= OutputExtensionError("vkCreateSwapchainKHR", "VK_KHR_surface");
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkCreateSwapchainKHR", "VK_KHR_swapchain");
    skip |= ValidateStructType("vkCreateSwapchainKHR", "pCreateInfo", "VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR", pCreateInfo, VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR, true, "VUID-vkCreateSwapchainKHR-pCreateInfo-parameter", "VUID-VkSwapchainCreateInfoKHR-sType-sType");
    if (pCreateInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkSwapchainCreateInfoKHR = { VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR, VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO, VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT };

        skip |= ValidateStructPnext("vkCreateSwapchainKHR", "pCreateInfo->pNext", "VkDeviceGroupSwapchainCreateInfoKHR, VkImageFormatListCreateInfo, VkSwapchainCounterCreateInfoEXT", pCreateInfo->pNext, allowed_structs_VkSwapchainCreateInfoKHR.size(), allowed_structs_VkSwapchainCreateInfoKHR.data(), GeneratedVulkanHeaderVersion, "VUID-VkSwapchainCreateInfoKHR-pNext-pNext", "VUID-VkSwapchainCreateInfoKHR-sType-unique", false, true);

        skip |= ValidateFlags("vkCreateSwapchainKHR", "pCreateInfo->flags", "VkSwapchainCreateFlagBitsKHR", AllVkSwapchainCreateFlagBitsKHR, pCreateInfo->flags, kOptionalFlags, "VUID-VkSwapchainCreateInfoKHR-flags-parameter");

        skip |= ValidateRequiredHandle("vkCreateSwapchainKHR", "pCreateInfo->surface", pCreateInfo->surface);

        skip |= ValidateRangedEnum("vkCreateSwapchainKHR", "pCreateInfo->imageFormat", "VkFormat", pCreateInfo->imageFormat, "VUID-VkSwapchainCreateInfoKHR-imageFormat-parameter");

        skip |= ValidateRangedEnum("vkCreateSwapchainKHR", "pCreateInfo->imageColorSpace", "VkColorSpaceKHR", pCreateInfo->imageColorSpace, "VUID-VkSwapchainCreateInfoKHR-imageColorSpace-parameter");

        // No xml-driven validation

        skip |= ValidateFlags("vkCreateSwapchainKHR", "pCreateInfo->imageUsage", "VkImageUsageFlagBits", AllVkImageUsageFlagBits, pCreateInfo->imageUsage, kRequiredFlags, "VUID-VkSwapchainCreateInfoKHR-imageUsage-parameter", "VUID-VkSwapchainCreateInfoKHR-imageUsage-requiredbitmask");

        skip |= ValidateRangedEnum("vkCreateSwapchainKHR", "pCreateInfo->imageSharingMode", "VkSharingMode", pCreateInfo->imageSharingMode, "VUID-VkSwapchainCreateInfoKHR-imageSharingMode-parameter");

        skip |= ValidateFlags("vkCreateSwapchainKHR", "pCreateInfo->preTransform", "VkSurfaceTransformFlagBitsKHR", AllVkSurfaceTransformFlagBitsKHR, pCreateInfo->preTransform, kRequiredSingleBit, "VUID-VkSwapchainCreateInfoKHR-preTransform-parameter", "VUID-VkSwapchainCreateInfoKHR-preTransform-parameter");

        skip |= ValidateFlags("vkCreateSwapchainKHR", "pCreateInfo->compositeAlpha", "VkCompositeAlphaFlagBitsKHR", AllVkCompositeAlphaFlagBitsKHR, pCreateInfo->compositeAlpha, kRequiredSingleBit, "VUID-VkSwapchainCreateInfoKHR-compositeAlpha-parameter", "VUID-VkSwapchainCreateInfoKHR-compositeAlpha-parameter");

        skip |= ValidateRangedEnum("vkCreateSwapchainKHR", "pCreateInfo->presentMode", "VkPresentModeKHR", pCreateInfo->presentMode, "VUID-VkSwapchainCreateInfoKHR-presentMode-parameter");

        skip |= ValidateBool32("vkCreateSwapchainKHR", "pCreateInfo->clipped", pCreateInfo->clipped);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateSwapchainKHR-pAllocator-null", "vkCreateSwapchainKHR(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateSwapchainKHR", "pSwapchain", pSwapchain, "VUID-vkCreateSwapchainKHR-pSwapchain-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    return skip;
}

bool StatelessValidation::PreCallValidateGetSwapchainImagesKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pSwapchainImageCount,
    VkImage*                                    pSwapchainImages) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_khr_surface)) skip |= OutputExtensionError("vkGetSwapchainImagesKHR", "VK_KHR_surface");
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkGetSwapchainImagesKHR", "VK_KHR_swapchain");
    skip |= ValidateRequiredHandle("vkGetSwapchainImagesKHR", "swapchain", swapchain);
    skip |= ValidateArray("vkGetSwapchainImagesKHR", "pSwapchainImageCount", "pSwapchainImages", pSwapchainImageCount, &pSwapchainImages, true, false, false, kVUIDUndefined, "VUID-vkGetSwapchainImagesKHR-pSwapchainImages-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateAcquireNextImageKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    timeout,
    VkSemaphore                                 semaphore,
    VkFence                                     fence,
    uint32_t*                                   pImageIndex) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_khr_surface)) skip |= OutputExtensionError("vkAcquireNextImageKHR", "VK_KHR_surface");
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkAcquireNextImageKHR", "VK_KHR_swapchain");
    skip |= ValidateRequiredHandle("vkAcquireNextImageKHR", "swapchain", swapchain);
    skip |= ValidateRequiredPointer("vkAcquireNextImageKHR", "pImageIndex", pImageIndex, "VUID-vkAcquireNextImageKHR-pImageIndex-parameter");
    if (!skip) skip |= manual_PreCallValidateAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    return skip;
}

bool StatelessValidation::PreCallValidateQueuePresentKHR(
    VkQueue                                     queue,
    const VkPresentInfoKHR*                     pPresentInfo) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_khr_surface)) skip |= OutputExtensionError("vkQueuePresentKHR", "VK_KHR_surface");
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkQueuePresentKHR", "VK_KHR_swapchain");
    skip |= ValidateStructType("vkQueuePresentKHR", "pPresentInfo", "VK_STRUCTURE_TYPE_PRESENT_INFO_KHR", pPresentInfo, VK_STRUCTURE_TYPE_PRESENT_INFO_KHR, true, "VUID-vkQueuePresentKHR-pPresentInfo-parameter", "VUID-VkPresentInfoKHR-sType-sType");
    if (pPresentInfo != nullptr)
    {
        constexpr std::array allowed_structs_VkPresentInfoKHR = { VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR, VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR, VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR };

        skip |= ValidateStructPnext("vkQueuePresentKHR", "pPresentInfo->pNext", "VkDeviceGroupPresentInfoKHR, VkDisplayPresentInfoKHR, VkPresentRegionsKHR", pPresentInfo->pNext, allowed_structs_VkPresentInfoKHR.size(), allowed_structs_VkPresentInfoKHR.data(), GeneratedVulkanHeaderVersion, "VUID-VkPresentInfoKHR-pNext-pNext", "VUID-VkPresentInfoKHR-sType-unique", false, true);

        skip |= ValidateArray("vkQueuePresentKHR", "pPresentInfo->waitSemaphoreCount", "pPresentInfo->pWaitSemaphores", pPresentInfo->waitSemaphoreCount, &pPresentInfo->pWaitSemaphores, false, true, kVUIDUndefined, "VUID-VkPresentInfoKHR-pWaitSemaphores-parameter");

        skip |= ValidateHandleArray("vkQueuePresentKHR", "pPresentInfo->swapchainCount", "pPresentInfo->pSwapchains", pPresentInfo->swapchainCount, pPresentInfo->pSwapchains, true, true, kVUIDUndefined);

        skip |= ValidateArray("vkQueuePresentKHR", "pPresentInfo->swapchainCount", "pPresentInfo->pImageIndices", pPresentInfo->swapchainCount, &pPresentInfo->pImageIndices, true, true, "VUID-VkPresentInfoKHR-swapchainCount-arraylength", "VUID-VkPresentInfoKHR-pImageIndices-parameter");

        skip |= ValidateArray("vkQueuePresentKHR", "pPresentInfo->swapchainCount", "pPresentInfo->pResults", pPresentInfo->swapchainCount, &pPresentInfo->pResults, true, false, "VUID-VkPresentInfoKHR-swapchainCount-arraylength", "VUID-VkPresentInfoKHR-pResults-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateQueuePresentKHR(queue, pPresentInfo);
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceGroupPresentCapabilitiesKHR(
    VkDevice                                    device,
    VkDeviceGroupPresentCapabilitiesKHR*        pDeviceGroupPresentCapabilities) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkGetDeviceGroupPresentCapabilitiesKHR", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_khr_surface)) skip |= OutputExtensionError("vkGetDeviceGroupPresentCapabilitiesKHR", "VK_KHR_surface");
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkGetDeviceGroupPresentCapabilitiesKHR", "VK_KHR_swapchain");
    skip |= ValidateStructType("vkGetDeviceGroupPresentCapabilitiesKHR", "pDeviceGroupPresentCapabilities", "VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR", pDeviceGroupPresentCapabilities, VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR, true, "VUID-vkGetDeviceGroupPresentCapabilitiesKHR-pDeviceGroupPresentCapabilities-parameter", "VUID-VkDeviceGroupPresentCapabilitiesKHR-sType-sType");
    if (pDeviceGroupPresentCapabilities != nullptr)
    {
        skip |= ValidateStructPnext("vkGetDeviceGroupPresentCapabilitiesKHR", "pDeviceGroupPresentCapabilities->pNext", nullptr, pDeviceGroupPresentCapabilities->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDeviceGroupPresentCapabilitiesKHR-pNext-pNext", kVUIDUndefined, false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceGroupSurfacePresentModesKHR(
    VkDevice                                    device,
    VkSurfaceKHR                                surface,
    VkDeviceGroupPresentModeFlagsKHR*           pModes) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkGetDeviceGroupSurfacePresentModesKHR", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_khr_surface)) skip |= OutputExtensionError("vkGetDeviceGroupSurfacePresentModesKHR", "VK_KHR_surface");
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkGetDeviceGroupSurfacePresentModesKHR", "VK_KHR_swapchain");
    skip |= ValidateRequiredHandle("vkGetDeviceGroupSurfacePresentModesKHR", "surface", surface);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDevicePresentRectanglesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pRectCount,
    VkRect2D*                                   pRects) const {
    bool skip = false;
    skip |= ValidateRequiredHandle("vkGetPhysicalDevicePresentRectanglesKHR", "surface", surface);
    skip |= ValidateArray("vkGetPhysicalDevicePresentRectanglesKHR", "pRectCount", "pRects", pRectCount, &pRects, true, false, false, kVUIDUndefined, "VUID-vkGetPhysicalDevicePresentRectanglesKHR-pRects-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateAcquireNextImage2KHR(
    VkDevice                                    device,
    const VkAcquireNextImageInfoKHR*            pAcquireInfo,
    uint32_t*                                   pImageIndex) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkAcquireNextImage2KHR", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_khr_surface)) skip |= OutputExtensionError("vkAcquireNextImage2KHR", "VK_KHR_surface");
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkAcquireNextImage2KHR", "VK_KHR_swapchain");
    skip |= ValidateStructType("vkAcquireNextImage2KHR", "pAcquireInfo", "VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR", pAcquireInfo, VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR, true, "VUID-vkAcquireNextImage2KHR-pAcquireInfo-parameter", "VUID-VkAcquireNextImageInfoKHR-sType-sType");
    if (pAcquireInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkAcquireNextImage2KHR", "pAcquireInfo->pNext", nullptr, pAcquireInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkAcquireNextImageInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkAcquireNextImage2KHR", "pAcquireInfo->swapchain", pAcquireInfo->swapchain);
    }
    skip |= ValidateRequiredPointer("vkAcquireNextImage2KHR", "pImageIndex", pImageIndex, "VUID-vkAcquireNextImage2KHR-pImageIndex-parameter");
    if (!skip) skip |= manual_PreCallValidateAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
    return skip;
}



bool StatelessValidation::PreCallValidateGetPhysicalDeviceDisplayPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPropertiesKHR*                     pProperties) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkGetPhysicalDeviceDisplayPropertiesKHR", "VK_KHR_surface");
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkGetPhysicalDeviceDisplayPropertiesKHR", "VK_KHR_display");
    skip |= ValidateArray("vkGetPhysicalDeviceDisplayPropertiesKHR", "pPropertyCount", "pProperties", pPropertyCount, &pProperties, true, false, false, kVUIDUndefined, "VUID-vkGetPhysicalDeviceDisplayPropertiesKHR-pProperties-parameter");
    if (pProperties != nullptr)
    {
        for (uint32_t pPropertyIndex = 0; pPropertyIndex < *pPropertyCount; ++pPropertyIndex)
        {
            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlanePropertiesKHR*                pProperties) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", "VK_KHR_surface");
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", "VK_KHR_display");
    skip |= ValidateArray("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", "pPropertyCount", "pProperties", pPropertyCount, &pProperties, true, false, false, kVUIDUndefined, "VUID-vkGetPhysicalDeviceDisplayPlanePropertiesKHR-pProperties-parameter");
    if (pProperties != nullptr)
    {
        for (uint32_t pPropertyIndex = 0; pPropertyIndex < *pPropertyCount; ++pPropertyIndex)
        {
            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDisplayPlaneSupportedDisplaysKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    uint32_t*                                   pDisplayCount,
    VkDisplayKHR*                               pDisplays) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkGetDisplayPlaneSupportedDisplaysKHR", "VK_KHR_surface");
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkGetDisplayPlaneSupportedDisplaysKHR", "VK_KHR_display");
    skip |= ValidateArray("vkGetDisplayPlaneSupportedDisplaysKHR", "pDisplayCount", "pDisplays", pDisplayCount, &pDisplays, true, false, false, kVUIDUndefined, "VUID-vkGetDisplayPlaneSupportedDisplaysKHR-pDisplays-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetDisplayModePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModePropertiesKHR*                 pProperties) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkGetDisplayModePropertiesKHR", "VK_KHR_surface");
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkGetDisplayModePropertiesKHR", "VK_KHR_display");
    skip |= ValidateRequiredHandle("vkGetDisplayModePropertiesKHR", "display", display);
    skip |= ValidateArray("vkGetDisplayModePropertiesKHR", "pPropertyCount", "pProperties", pPropertyCount, &pProperties, true, false, false, kVUIDUndefined, "VUID-vkGetDisplayModePropertiesKHR-pProperties-parameter");
    if (pProperties != nullptr)
    {
        for (uint32_t pPropertyIndex = 0; pPropertyIndex < *pPropertyCount; ++pPropertyIndex)
        {
            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateDisplayModeKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const VkDisplayModeCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDisplayModeKHR*                           pMode) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkCreateDisplayModeKHR", "VK_KHR_surface");
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkCreateDisplayModeKHR", "VK_KHR_display");
    skip |= ValidateRequiredHandle("vkCreateDisplayModeKHR", "display", display);
    skip |= ValidateStructType("vkCreateDisplayModeKHR", "pCreateInfo", "VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR", pCreateInfo, VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR, true, "VUID-vkCreateDisplayModeKHR-pCreateInfo-parameter", "VUID-VkDisplayModeCreateInfoKHR-sType-sType");
    if (pCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCreateDisplayModeKHR", "pCreateInfo->pNext", nullptr, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDisplayModeCreateInfoKHR-pNext-pNext", kVUIDUndefined, true, true);

        skip |= ValidateReservedFlags("vkCreateDisplayModeKHR", "pCreateInfo->flags", pCreateInfo->flags, "VUID-VkDisplayModeCreateInfoKHR-flags-zerobitmask");

        // No xml-driven validation
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateDisplayModeKHR-pAllocator-null", "vkCreateDisplayModeKHR(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateDisplayModeKHR", "pMode", pMode, "VUID-vkCreateDisplayModeKHR-pMode-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
    return skip;
}

bool StatelessValidation::PreCallValidateGetDisplayPlaneCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayModeKHR                            mode,
    uint32_t                                    planeIndex,
    VkDisplayPlaneCapabilitiesKHR*              pCapabilities) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkGetDisplayPlaneCapabilitiesKHR", "VK_KHR_surface");
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkGetDisplayPlaneCapabilitiesKHR", "VK_KHR_display");
    skip |= ValidateRequiredHandle("vkGetDisplayPlaneCapabilitiesKHR", "mode", mode);
    skip |= ValidateRequiredPointer("vkGetDisplayPlaneCapabilitiesKHR", "pCapabilities", pCapabilities, "VUID-vkGetDisplayPlaneCapabilitiesKHR-pCapabilities-parameter");
    if (pCapabilities != nullptr)
    {
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateDisplayPlaneSurfaceKHR(
    VkInstance                                  instance,
    const VkDisplaySurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkCreateDisplayPlaneSurfaceKHR", "VK_KHR_surface");
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkCreateDisplayPlaneSurfaceKHR", "VK_KHR_display");
    skip |= ValidateStructType("vkCreateDisplayPlaneSurfaceKHR", "pCreateInfo", "VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR", pCreateInfo, VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR, true, "VUID-vkCreateDisplayPlaneSurfaceKHR-pCreateInfo-parameter", "VUID-VkDisplaySurfaceCreateInfoKHR-sType-sType");
    if (pCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCreateDisplayPlaneSurfaceKHR", "pCreateInfo->pNext", nullptr, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDisplaySurfaceCreateInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags("vkCreateDisplayPlaneSurfaceKHR", "pCreateInfo->flags", pCreateInfo->flags, "VUID-VkDisplaySurfaceCreateInfoKHR-flags-zerobitmask");

        skip |= ValidateRequiredHandle("vkCreateDisplayPlaneSurfaceKHR", "pCreateInfo->displayMode", pCreateInfo->displayMode);

        skip |= ValidateFlags("vkCreateDisplayPlaneSurfaceKHR", "pCreateInfo->transform", "VkSurfaceTransformFlagBitsKHR", AllVkSurfaceTransformFlagBitsKHR, pCreateInfo->transform, kRequiredSingleBit, "VUID-VkDisplaySurfaceCreateInfoKHR-transform-parameter", "VUID-VkDisplaySurfaceCreateInfoKHR-transform-parameter");

        skip |= ValidateFlags("vkCreateDisplayPlaneSurfaceKHR", "pCreateInfo->alphaMode", "VkDisplayPlaneAlphaFlagBitsKHR", AllVkDisplayPlaneAlphaFlagBitsKHR, pCreateInfo->alphaMode, kRequiredSingleBit, "VUID-VkDisplaySurfaceCreateInfoKHR-alphaMode-parameter", "VUID-VkDisplaySurfaceCreateInfoKHR-alphaMode-parameter");

        // No xml-driven validation
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateDisplayPlaneSurfaceKHR-pAllocator-null", "vkCreateDisplayPlaneSurfaceKHR(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateDisplayPlaneSurfaceKHR", "pSurface", pSurface, "VUID-vkCreateDisplayPlaneSurfaceKHR-pSurface-parameter");
    return skip;
}



bool StatelessValidation::PreCallValidateCreateSharedSwapchainsKHR(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainCreateInfoKHR*             pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchains) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_khr_display)) skip |= OutputExtensionError("vkCreateSharedSwapchainsKHR", "VK_KHR_display");
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkCreateSharedSwapchainsKHR", "VK_KHR_swapchain");
    if (!IsExtEnabled(device_extensions.vk_khr_display_swapchain)) skip |= OutputExtensionError("vkCreateSharedSwapchainsKHR", "VK_KHR_display_swapchain");
    skip |= ValidateStructTypeArray("vkCreateSharedSwapchainsKHR", "swapchainCount", "pCreateInfos", "VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR", swapchainCount, pCreateInfos, VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR, true, true, "VUID-VkSwapchainCreateInfoKHR-sType-sType", "VUID-vkCreateSharedSwapchainsKHR-pCreateInfos-parameter", "VUID-vkCreateSharedSwapchainsKHR-swapchainCount-arraylength");
    if (pCreateInfos != nullptr)
    {
        for (uint32_t swapchainIndex = 0; swapchainIndex < swapchainCount; ++swapchainIndex)
        {
            constexpr std::array allowed_structs_VkSwapchainCreateInfoKHR = { VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR, VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO, VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT };

            skip |= ValidateStructPnext("vkCreateSharedSwapchainsKHR", ParameterName("pCreateInfos[%i].pNext", ParameterName::IndexVector{ swapchainIndex }), "VkDeviceGroupSwapchainCreateInfoKHR, VkImageFormatListCreateInfo, VkSwapchainCounterCreateInfoEXT", pCreateInfos[swapchainIndex].pNext, allowed_structs_VkSwapchainCreateInfoKHR.size(), allowed_structs_VkSwapchainCreateInfoKHR.data(), GeneratedVulkanHeaderVersion, "VUID-VkSwapchainCreateInfoKHR-pNext-pNext", "VUID-VkSwapchainCreateInfoKHR-sType-unique", false, true);

            skip |= ValidateFlags("vkCreateSharedSwapchainsKHR", ParameterName("pCreateInfos[%i].flags", ParameterName::IndexVector{ swapchainIndex }), "VkSwapchainCreateFlagBitsKHR", AllVkSwapchainCreateFlagBitsKHR, pCreateInfos[swapchainIndex].flags, kOptionalFlags, "VUID-VkSwapchainCreateInfoKHR-flags-parameter");

            skip |= ValidateRequiredHandle("vkCreateSharedSwapchainsKHR", ParameterName("pCreateInfos[%i].surface", ParameterName::IndexVector{ swapchainIndex }), pCreateInfos[swapchainIndex].surface);

            skip |= ValidateRangedEnum("vkCreateSharedSwapchainsKHR", ParameterName("pCreateInfos[%i].imageFormat", ParameterName::IndexVector{ swapchainIndex }), "VkFormat", pCreateInfos[swapchainIndex].imageFormat, "VUID-VkSwapchainCreateInfoKHR-imageFormat-parameter");

            skip |= ValidateRangedEnum("vkCreateSharedSwapchainsKHR", ParameterName("pCreateInfos[%i].imageColorSpace", ParameterName::IndexVector{ swapchainIndex }), "VkColorSpaceKHR", pCreateInfos[swapchainIndex].imageColorSpace, "VUID-VkSwapchainCreateInfoKHR-imageColorSpace-parameter");

            // No xml-driven validation

            skip |= ValidateFlags("vkCreateSharedSwapchainsKHR", ParameterName("pCreateInfos[%i].imageUsage", ParameterName::IndexVector{ swapchainIndex }), "VkImageUsageFlagBits", AllVkImageUsageFlagBits, pCreateInfos[swapchainIndex].imageUsage, kRequiredFlags, "VUID-VkSwapchainCreateInfoKHR-imageUsage-parameter", "VUID-VkSwapchainCreateInfoKHR-imageUsage-requiredbitmask");

            skip |= ValidateRangedEnum("vkCreateSharedSwapchainsKHR", ParameterName("pCreateInfos[%i].imageSharingMode", ParameterName::IndexVector{ swapchainIndex }), "VkSharingMode", pCreateInfos[swapchainIndex].imageSharingMode, "VUID-VkSwapchainCreateInfoKHR-imageSharingMode-parameter");

            skip |= ValidateFlags("vkCreateSharedSwapchainsKHR", ParameterName("pCreateInfos[%i].preTransform", ParameterName::IndexVector{ swapchainIndex }), "VkSurfaceTransformFlagBitsKHR", AllVkSurfaceTransformFlagBitsKHR, pCreateInfos[swapchainIndex].preTransform, kRequiredSingleBit, "VUID-VkSwapchainCreateInfoKHR-preTransform-parameter", "VUID-VkSwapchainCreateInfoKHR-preTransform-parameter");

            skip |= ValidateFlags("vkCreateSharedSwapchainsKHR", ParameterName("pCreateInfos[%i].compositeAlpha", ParameterName::IndexVector{ swapchainIndex }), "VkCompositeAlphaFlagBitsKHR", AllVkCompositeAlphaFlagBitsKHR, pCreateInfos[swapchainIndex].compositeAlpha, kRequiredSingleBit, "VUID-VkSwapchainCreateInfoKHR-compositeAlpha-parameter", "VUID-VkSwapchainCreateInfoKHR-compositeAlpha-parameter");

            skip |= ValidateRangedEnum("vkCreateSharedSwapchainsKHR", ParameterName("pCreateInfos[%i].presentMode", ParameterName::IndexVector{ swapchainIndex }), "VkPresentModeKHR", pCreateInfos[swapchainIndex].presentMode, "VUID-VkSwapchainCreateInfoKHR-presentMode-parameter");

            skip |= ValidateBool32("vkCreateSharedSwapchainsKHR", ParameterName("pCreateInfos[%i].clipped", ParameterName::IndexVector{ swapchainIndex }), pCreateInfos[swapchainIndex].clipped);
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateSharedSwapchainsKHR-pAllocator-null", "vkCreateSharedSwapchainsKHR(): pAllocator must be NULL");
    }
    skip |= ValidateArray("vkCreateSharedSwapchainsKHR", "swapchainCount", "pSwapchains", swapchainCount, &pSwapchains, true, true, "VUID-vkCreateSharedSwapchainsKHR-swapchainCount-arraylength", "VUID-vkCreateSharedSwapchainsKHR-pSwapchains-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    return skip;
}



bool StatelessValidation::PreCallValidateGetMemoryFdKHR(
    VkDevice                                    device,
    const VkMemoryGetFdInfoKHR*                 pGetFdInfo,
    int*                                        pFd) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_external_memory_fd) && (IsExtEnabled(device_extensions.vk_khr_external_memory) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkGetMemoryFdKHR", "VK_KHR_external_memory_fd && (VK_KHR_external_memory || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkGetMemoryFdKHR", "pGetFdInfo", "VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR", pGetFdInfo, VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR, true, "VUID-vkGetMemoryFdKHR-pGetFdInfo-parameter", "VUID-VkMemoryGetFdInfoKHR-sType-sType");
    if (pGetFdInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetMemoryFdKHR", "pGetFdInfo->pNext", nullptr, pGetFdInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkMemoryGetFdInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkGetMemoryFdKHR", "pGetFdInfo->memory", pGetFdInfo->memory);

        skip |= ValidateFlags("vkGetMemoryFdKHR", "pGetFdInfo->handleType", "VkExternalMemoryHandleTypeFlagBits", AllVkExternalMemoryHandleTypeFlagBits, pGetFdInfo->handleType, kRequiredSingleBit, "VUID-VkMemoryGetFdInfoKHR-handleType-parameter", "VUID-VkMemoryGetFdInfoKHR-handleType-parameter");
    }
    skip |= ValidateRequiredPointer("vkGetMemoryFdKHR", "pFd", pFd, "VUID-vkGetMemoryFdKHR-pFd-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetMemoryFdPropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    VkMemoryFdPropertiesKHR*                    pMemoryFdProperties) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_external_memory_fd) && (IsExtEnabled(device_extensions.vk_khr_external_memory) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkGetMemoryFdPropertiesKHR", "VK_KHR_external_memory_fd && (VK_KHR_external_memory || VK_VERSION_1_1)");
    skip |= ValidateFlags("vkGetMemoryFdPropertiesKHR", "handleType", "VkExternalMemoryHandleTypeFlagBits", AllVkExternalMemoryHandleTypeFlagBits, handleType, kRequiredSingleBit, "VUID-vkGetMemoryFdPropertiesKHR-handleType-parameter", "VUID-vkGetMemoryFdPropertiesKHR-handleType-parameter");
    skip |= ValidateStructType("vkGetMemoryFdPropertiesKHR", "pMemoryFdProperties", "VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR", pMemoryFdProperties, VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR, true, "VUID-vkGetMemoryFdPropertiesKHR-pMemoryFdProperties-parameter", "VUID-VkMemoryFdPropertiesKHR-sType-sType");
    if (pMemoryFdProperties != nullptr)
    {
        skip |= ValidateStructPnext("vkGetMemoryFdPropertiesKHR", "pMemoryFdProperties->pNext", nullptr, pMemoryFdProperties->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkMemoryFdPropertiesKHR-pNext-pNext", kVUIDUndefined, false, false);
    }
    return skip;
}



bool StatelessValidation::PreCallValidateImportSemaphoreFdKHR(
    VkDevice                                    device,
    const VkImportSemaphoreFdInfoKHR*           pImportSemaphoreFdInfo) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_external_semaphore_fd) && (IsExtEnabled(device_extensions.vk_khr_external_semaphore) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkImportSemaphoreFdKHR", "VK_KHR_external_semaphore_fd && (VK_KHR_external_semaphore || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkImportSemaphoreFdKHR", "pImportSemaphoreFdInfo", "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR", pImportSemaphoreFdInfo, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR, true, "VUID-vkImportSemaphoreFdKHR-pImportSemaphoreFdInfo-parameter", "VUID-VkImportSemaphoreFdInfoKHR-sType-sType");
    if (pImportSemaphoreFdInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkImportSemaphoreFdKHR", "pImportSemaphoreFdInfo->pNext", nullptr, pImportSemaphoreFdInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkImportSemaphoreFdInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkImportSemaphoreFdKHR", "pImportSemaphoreFdInfo->semaphore", pImportSemaphoreFdInfo->semaphore);

        skip |= ValidateFlags("vkImportSemaphoreFdKHR", "pImportSemaphoreFdInfo->flags", "VkSemaphoreImportFlagBits", AllVkSemaphoreImportFlagBits, pImportSemaphoreFdInfo->flags, kOptionalFlags, "VUID-VkImportSemaphoreFdInfoKHR-flags-parameter");

        skip |= ValidateFlags("vkImportSemaphoreFdKHR", "pImportSemaphoreFdInfo->handleType", "VkExternalSemaphoreHandleTypeFlagBits", AllVkExternalSemaphoreHandleTypeFlagBits, pImportSemaphoreFdInfo->handleType, kRequiredSingleBit, "VUID-VkImportSemaphoreFdInfoKHR-handleType-parameter", "VUID-VkImportSemaphoreFdInfoKHR-handleType-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
    return skip;
}

bool StatelessValidation::PreCallValidateGetSemaphoreFdKHR(
    VkDevice                                    device,
    const VkSemaphoreGetFdInfoKHR*              pGetFdInfo,
    int*                                        pFd) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_external_semaphore_fd) && (IsExtEnabled(device_extensions.vk_khr_external_semaphore) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkGetSemaphoreFdKHR", "VK_KHR_external_semaphore_fd && (VK_KHR_external_semaphore || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkGetSemaphoreFdKHR", "pGetFdInfo", "VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR", pGetFdInfo, VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR, true, "VUID-vkGetSemaphoreFdKHR-pGetFdInfo-parameter", "VUID-VkSemaphoreGetFdInfoKHR-sType-sType");
    if (pGetFdInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetSemaphoreFdKHR", "pGetFdInfo->pNext", nullptr, pGetFdInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSemaphoreGetFdInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkGetSemaphoreFdKHR", "pGetFdInfo->semaphore", pGetFdInfo->semaphore);

        skip |= ValidateFlags("vkGetSemaphoreFdKHR", "pGetFdInfo->handleType", "VkExternalSemaphoreHandleTypeFlagBits", AllVkExternalSemaphoreHandleTypeFlagBits, pGetFdInfo->handleType, kRequiredSingleBit, "VUID-VkSemaphoreGetFdInfoKHR-handleType-parameter", "VUID-VkSemaphoreGetFdInfoKHR-handleType-parameter");
    }
    skip |= ValidateRequiredPointer("vkGetSemaphoreFdKHR", "pFd", pFd, "VUID-vkGetSemaphoreFdKHR-pFd-parameter");
    if (!skip) skip |= manual_PreCallValidateGetSemaphoreFdKHR(device, pGetFdInfo, pFd);
    return skip;
}





bool StatelessValidation::PreCallValidateGetSwapchainStatusKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkGetSwapchainStatusKHR", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2)) skip |= OutputExtensionError("vkGetSwapchainStatusKHR", "VK_KHR_get_physical_device_properties2");
    if (!IsExtEnabled(device_extensions.vk_khr_get_surface_capabilities2)) skip |= OutputExtensionError("vkGetSwapchainStatusKHR", "VK_KHR_get_surface_capabilities2");
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkGetSwapchainStatusKHR", "VK_KHR_swapchain");
    if (!IsExtEnabled(device_extensions.vk_khr_shared_presentable_image)) skip |= OutputExtensionError("vkGetSwapchainStatusKHR", "VK_KHR_shared_presentable_image");
    skip |= ValidateRequiredHandle("vkGetSwapchainStatusKHR", "swapchain", swapchain);
    return skip;
}



bool StatelessValidation::PreCallValidateImportFenceFdKHR(
    VkDevice                                    device,
    const VkImportFenceFdInfoKHR*               pImportFenceFdInfo) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_external_fence_fd) && (IsExtEnabled(device_extensions.vk_khr_external_fence) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkImportFenceFdKHR", "VK_KHR_external_fence_fd && (VK_KHR_external_fence || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkImportFenceFdKHR", "pImportFenceFdInfo", "VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR", pImportFenceFdInfo, VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR, true, "VUID-vkImportFenceFdKHR-pImportFenceFdInfo-parameter", "VUID-VkImportFenceFdInfoKHR-sType-sType");
    if (pImportFenceFdInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkImportFenceFdKHR", "pImportFenceFdInfo->pNext", nullptr, pImportFenceFdInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkImportFenceFdInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkImportFenceFdKHR", "pImportFenceFdInfo->fence", pImportFenceFdInfo->fence);

        skip |= ValidateFlags("vkImportFenceFdKHR", "pImportFenceFdInfo->flags", "VkFenceImportFlagBits", AllVkFenceImportFlagBits, pImportFenceFdInfo->flags, kOptionalFlags, "VUID-VkImportFenceFdInfoKHR-flags-parameter");

        skip |= ValidateFlags("vkImportFenceFdKHR", "pImportFenceFdInfo->handleType", "VkExternalFenceHandleTypeFlagBits", AllVkExternalFenceHandleTypeFlagBits, pImportFenceFdInfo->handleType, kRequiredSingleBit, "VUID-VkImportFenceFdInfoKHR-handleType-parameter", "VUID-VkImportFenceFdInfoKHR-handleType-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateImportFenceFdKHR(device, pImportFenceFdInfo);
    return skip;
}

bool StatelessValidation::PreCallValidateGetFenceFdKHR(
    VkDevice                                    device,
    const VkFenceGetFdInfoKHR*                  pGetFdInfo,
    int*                                        pFd) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_external_fence_fd) && (IsExtEnabled(device_extensions.vk_khr_external_fence) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkGetFenceFdKHR", "VK_KHR_external_fence_fd && (VK_KHR_external_fence || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkGetFenceFdKHR", "pGetFdInfo", "VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR", pGetFdInfo, VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR, true, "VUID-vkGetFenceFdKHR-pGetFdInfo-parameter", "VUID-VkFenceGetFdInfoKHR-sType-sType");
    if (pGetFdInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetFenceFdKHR", "pGetFdInfo->pNext", nullptr, pGetFdInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkFenceGetFdInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkGetFenceFdKHR", "pGetFdInfo->fence", pGetFdInfo->fence);

        skip |= ValidateFlags("vkGetFenceFdKHR", "pGetFdInfo->handleType", "VkExternalFenceHandleTypeFlagBits", AllVkExternalFenceHandleTypeFlagBits, pGetFdInfo->handleType, kRequiredSingleBit, "VUID-VkFenceGetFdInfoKHR-handleType-parameter", "VUID-VkFenceGetFdInfoKHR-handleType-parameter");
    }
    skip |= ValidateRequiredPointer("vkGetFenceFdKHR", "pFd", pFd, "VUID-vkGetFenceFdKHR-pFd-parameter");
    if (!skip) skip |= manual_PreCallValidateGetFenceFdKHR(device, pGetFdInfo, pFd);
    return skip;
}



bool StatelessValidation::PreCallValidateEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint32_t*                                   pCounterCount,
    VkPerformanceCounterKHR*                    pCounters,
    VkPerformanceCounterDescriptionKHR*         pCounterDescriptions) const {
    bool skip = false;
    skip |= ValidateStructTypeArray("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", "pCounterCount", "pCounters", "VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR", pCounterCount, pCounters, VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR, true, false, false, "VUID-VkPerformanceCounterKHR-sType-sType", "VUID-vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR-pCounters-parameter", kVUIDUndefined);
    if (pCounters != nullptr)
    {
        for (uint32_t pIndexerIndex = 0; pIndexerIndex < *pCounterCount; ++pIndexerIndex)
        {
            skip |= ValidateStructPnext("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", ParameterName("pCounters[%i].pNext", ParameterName::IndexVector{ pIndexerIndex }), nullptr, pCounters[pIndexerIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkPerformanceCounterKHR-pNext-pNext", kVUIDUndefined, true, false);
        }
    }
    skip |= ValidateStructTypeArray("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", "pCounterCount", "pCounterDescriptions", "VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR", pCounterCount, pCounterDescriptions, VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR, true, false, false, "VUID-VkPerformanceCounterDescriptionKHR-sType-sType", "VUID-vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR-pCounterDescriptions-parameter", kVUIDUndefined);
    if (pCounterDescriptions != nullptr)
    {
        for (uint32_t pIndexerIndex = 0; pIndexerIndex < *pCounterCount; ++pIndexerIndex)
        {
            skip |= ValidateStructPnext("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", ParameterName("pCounterDescriptions[%i].pNext", ParameterName::IndexVector{ pIndexerIndex }), nullptr, pCounterDescriptions[pIndexerIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkPerformanceCounterDescriptionKHR-pNext-pNext", kVUIDUndefined, true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkQueryPoolPerformanceCreateInfoKHR*  pPerformanceQueryCreateInfo,
    uint32_t*                                   pNumPasses) const {
    bool skip = false;
    skip |= ValidateStructType("vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", "pPerformanceQueryCreateInfo", "VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR", pPerformanceQueryCreateInfo, VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR, true, "VUID-vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR-pPerformanceQueryCreateInfo-parameter", "VUID-VkQueryPoolPerformanceCreateInfoKHR-sType-sType");
    if (pPerformanceQueryCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", "pPerformanceQueryCreateInfo->pNext", nullptr, pPerformanceQueryCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, true, true);

        skip |= ValidateArray("vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", "pPerformanceQueryCreateInfo->counterIndexCount", "pPerformanceQueryCreateInfo->pCounterIndices", pPerformanceQueryCreateInfo->counterIndexCount, &pPerformanceQueryCreateInfo->pCounterIndices, true, true, "VUID-VkQueryPoolPerformanceCreateInfoKHR-counterIndexCount-arraylength", "VUID-VkQueryPoolPerformanceCreateInfoKHR-pCounterIndices-parameter");
    }
    skip |= ValidateRequiredPointer("vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", "pNumPasses", pNumPasses, "VUID-vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR-pNumPasses-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateAcquireProfilingLockKHR(
    VkDevice                                    device,
    const VkAcquireProfilingLockInfoKHR*        pInfo) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_performance_query) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkAcquireProfilingLockKHR", "VK_KHR_performance_query && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkAcquireProfilingLockKHR", "pInfo", "VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR", pInfo, VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR, true, "VUID-vkAcquireProfilingLockKHR-pInfo-parameter", "VUID-VkAcquireProfilingLockInfoKHR-sType-sType");
    if (pInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkAcquireProfilingLockKHR", "pInfo->pNext", nullptr, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkAcquireProfilingLockInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags("vkAcquireProfilingLockKHR", "pInfo->flags", pInfo->flags, "VUID-VkAcquireProfilingLockInfoKHR-flags-zerobitmask");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateReleaseProfilingLockKHR(
    VkDevice                                    device) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_performance_query) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkReleaseProfilingLockKHR", "VK_KHR_performance_query && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    // No xml-driven validation
    return skip;
}



bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfaceCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkSurfaceCapabilities2KHR*                  pSurfaceCapabilities) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkGetPhysicalDeviceSurfaceCapabilities2KHR", "VK_KHR_surface");
    if (!instance_extensions.vk_khr_get_surface_capabilities2) skip |= OutputExtensionError("vkGetPhysicalDeviceSurfaceCapabilities2KHR", "VK_KHR_get_surface_capabilities2");
    skip |= ValidateStructType("vkGetPhysicalDeviceSurfaceCapabilities2KHR", "pSurfaceInfo", "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR", pSurfaceInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR, true, "VUID-vkGetPhysicalDeviceSurfaceCapabilities2KHR-pSurfaceInfo-parameter", "VUID-VkPhysicalDeviceSurfaceInfo2KHR-sType-sType");
    if (pSurfaceInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetPhysicalDeviceSurfaceCapabilities2KHR", "pSurfaceInfo->pNext", nullptr, pSurfaceInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkPhysicalDeviceSurfaceInfo2KHR-pNext-pNext", kVUIDUndefined, true, true);
    }
    skip |= ValidateStructType("vkGetPhysicalDeviceSurfaceCapabilities2KHR", "pSurfaceCapabilities", "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR", pSurfaceCapabilities, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR, true, "VUID-vkGetPhysicalDeviceSurfaceCapabilities2KHR-pSurfaceCapabilities-parameter", "VUID-VkSurfaceCapabilities2KHR-sType-sType");
    if (pSurfaceCapabilities != nullptr)
    {
        constexpr std::array allowed_structs_VkSurfaceCapabilities2KHR = { VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR };

        skip |= ValidateStructPnext("vkGetPhysicalDeviceSurfaceCapabilities2KHR", "pSurfaceCapabilities->pNext", "VkSharedPresentSurfaceCapabilitiesKHR", pSurfaceCapabilities->pNext, allowed_structs_VkSurfaceCapabilities2KHR.size(), allowed_structs_VkSurfaceCapabilities2KHR.data(), GeneratedVulkanHeaderVersion, "VUID-VkSurfaceCapabilities2KHR-pNext-pNext", "VUID-VkSurfaceCapabilities2KHR-sType-unique", true, false);
    }
    if (!skip) skip |= manual_PreCallValidateGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfaceFormats2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormat2KHR*                        pSurfaceFormats) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkGetPhysicalDeviceSurfaceFormats2KHR", "VK_KHR_surface");
    if (!instance_extensions.vk_khr_get_surface_capabilities2) skip |= OutputExtensionError("vkGetPhysicalDeviceSurfaceFormats2KHR", "VK_KHR_get_surface_capabilities2");
    skip |= ValidateStructType("vkGetPhysicalDeviceSurfaceFormats2KHR", "pSurfaceInfo", "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR", pSurfaceInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR, true, "VUID-vkGetPhysicalDeviceSurfaceFormats2KHR-pSurfaceInfo-parameter", "VUID-VkPhysicalDeviceSurfaceInfo2KHR-sType-sType");
    if (pSurfaceInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetPhysicalDeviceSurfaceFormats2KHR", "pSurfaceInfo->pNext", nullptr, pSurfaceInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkPhysicalDeviceSurfaceInfo2KHR-pNext-pNext", kVUIDUndefined, true, true);
    }
    skip |= ValidateStructTypeArray("vkGetPhysicalDeviceSurfaceFormats2KHR", "pSurfaceFormatCount", "pSurfaceFormats", "VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR", pSurfaceFormatCount, pSurfaceFormats, VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR, true, false, false, "VUID-VkSurfaceFormat2KHR-sType-sType", "VUID-vkGetPhysicalDeviceSurfaceFormats2KHR-pSurfaceFormats-parameter", kVUIDUndefined);
    if (pSurfaceFormats != nullptr)
    {
        for (uint32_t pSurfaceFormatIndex = 0; pSurfaceFormatIndex < *pSurfaceFormatCount; ++pSurfaceFormatIndex)
        {
            skip |= ValidateStructPnext("vkGetPhysicalDeviceSurfaceFormats2KHR", ParameterName("pSurfaceFormats[%i].pNext", ParameterName::IndexVector{ pSurfaceFormatIndex }), nullptr, pSurfaceFormats[pSurfaceFormatIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSurfaceFormat2KHR-pNext-pNext", kVUIDUndefined, true, false);
        }
    }
    if (!skip) skip |= manual_PreCallValidateGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    return skip;
}



bool StatelessValidation::PreCallValidateGetPhysicalDeviceDisplayProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayProperties2KHR*                    pProperties) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkGetPhysicalDeviceDisplayProperties2KHR", "VK_KHR_display");
    if (!instance_extensions.vk_khr_get_display_properties2) skip |= OutputExtensionError("vkGetPhysicalDeviceDisplayProperties2KHR", "VK_KHR_get_display_properties2");
    skip |= ValidateStructTypeArray("vkGetPhysicalDeviceDisplayProperties2KHR", "pPropertyCount", "pProperties", "VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR", pPropertyCount, pProperties, VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR, true, false, false, "VUID-VkDisplayProperties2KHR-sType-sType", "VUID-vkGetPhysicalDeviceDisplayProperties2KHR-pProperties-parameter", kVUIDUndefined);
    if (pProperties != nullptr)
    {
        for (uint32_t pPropertyIndex = 0; pPropertyIndex < *pPropertyCount; ++pPropertyIndex)
        {
            skip |= ValidateStructPnext("vkGetPhysicalDeviceDisplayProperties2KHR", ParameterName("pProperties[%i].pNext", ParameterName::IndexVector{ pPropertyIndex }), nullptr, pProperties[pPropertyIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDisplayProperties2KHR-pNext-pNext", kVUIDUndefined, true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlaneProperties2KHR*               pProperties) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", "VK_KHR_display");
    if (!instance_extensions.vk_khr_get_display_properties2) skip |= OutputExtensionError("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", "VK_KHR_get_display_properties2");
    skip |= ValidateStructTypeArray("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", "pPropertyCount", "pProperties", "VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR", pPropertyCount, pProperties, VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR, true, false, false, "VUID-VkDisplayPlaneProperties2KHR-sType-sType", "VUID-vkGetPhysicalDeviceDisplayPlaneProperties2KHR-pProperties-parameter", kVUIDUndefined);
    if (pProperties != nullptr)
    {
        for (uint32_t pPropertyIndex = 0; pPropertyIndex < *pPropertyCount; ++pPropertyIndex)
        {
            skip |= ValidateStructPnext("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", ParameterName("pProperties[%i].pNext", ParameterName::IndexVector{ pPropertyIndex }), nullptr, pProperties[pPropertyIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDisplayPlaneProperties2KHR-pNext-pNext", kVUIDUndefined, true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDisplayModeProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModeProperties2KHR*                pProperties) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkGetDisplayModeProperties2KHR", "VK_KHR_display");
    if (!instance_extensions.vk_khr_get_display_properties2) skip |= OutputExtensionError("vkGetDisplayModeProperties2KHR", "VK_KHR_get_display_properties2");
    skip |= ValidateRequiredHandle("vkGetDisplayModeProperties2KHR", "display", display);
    skip |= ValidateStructTypeArray("vkGetDisplayModeProperties2KHR", "pPropertyCount", "pProperties", "VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR", pPropertyCount, pProperties, VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR, true, false, false, "VUID-VkDisplayModeProperties2KHR-sType-sType", "VUID-vkGetDisplayModeProperties2KHR-pProperties-parameter", kVUIDUndefined);
    if (pProperties != nullptr)
    {
        for (uint32_t pPropertyIndex = 0; pPropertyIndex < *pPropertyCount; ++pPropertyIndex)
        {
            skip |= ValidateStructPnext("vkGetDisplayModeProperties2KHR", ParameterName("pProperties[%i].pNext", ParameterName::IndexVector{ pPropertyIndex }), nullptr, pProperties[pPropertyIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDisplayModeProperties2KHR-pNext-pNext", kVUIDUndefined, true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDisplayPlaneCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkDisplayPlaneInfo2KHR*               pDisplayPlaneInfo,
    VkDisplayPlaneCapabilities2KHR*             pCapabilities) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkGetDisplayPlaneCapabilities2KHR", "VK_KHR_display");
    if (!instance_extensions.vk_khr_get_display_properties2) skip |= OutputExtensionError("vkGetDisplayPlaneCapabilities2KHR", "VK_KHR_get_display_properties2");
    skip |= ValidateStructType("vkGetDisplayPlaneCapabilities2KHR", "pDisplayPlaneInfo", "VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR", pDisplayPlaneInfo, VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR, true, "VUID-vkGetDisplayPlaneCapabilities2KHR-pDisplayPlaneInfo-parameter", "VUID-VkDisplayPlaneInfo2KHR-sType-sType");
    if (pDisplayPlaneInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetDisplayPlaneCapabilities2KHR", "pDisplayPlaneInfo->pNext", nullptr, pDisplayPlaneInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDisplayPlaneInfo2KHR-pNext-pNext", kVUIDUndefined, true, true);

        skip |= ValidateRequiredHandle("vkGetDisplayPlaneCapabilities2KHR", "pDisplayPlaneInfo->mode", pDisplayPlaneInfo->mode);
    }
    skip |= ValidateStructType("vkGetDisplayPlaneCapabilities2KHR", "pCapabilities", "VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR", pCapabilities, VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR, true, "VUID-vkGetDisplayPlaneCapabilities2KHR-pCapabilities-parameter", "VUID-VkDisplayPlaneCapabilities2KHR-sType-sType");
    if (pCapabilities != nullptr)
    {
        skip |= ValidateStructPnext("vkGetDisplayPlaneCapabilities2KHR", "pCapabilities->pNext", nullptr, pCapabilities->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDisplayPlaneCapabilities2KHR-pNext-pNext", kVUIDUndefined, true, false);
    }
    return skip;
}









bool StatelessValidation::PreCallValidateGetPhysicalDeviceFragmentShadingRatesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pFragmentShadingRateCount,
    VkPhysicalDeviceFragmentShadingRateKHR*     pFragmentShadingRates) const {
    bool skip = false;
    skip |= ValidateStructTypeArray("vkGetPhysicalDeviceFragmentShadingRatesKHR", "pFragmentShadingRateCount", "pFragmentShadingRates", "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR", pFragmentShadingRateCount, pFragmentShadingRates, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR, true, false, false, "VUID-VkPhysicalDeviceFragmentShadingRateKHR-sType-sType", "VUID-vkGetPhysicalDeviceFragmentShadingRatesKHR-pFragmentShadingRates-parameter", kVUIDUndefined);
    if (pFragmentShadingRates != nullptr)
    {
        for (uint32_t pFragmentShadingRateIndex = 0; pFragmentShadingRateIndex < *pFragmentShadingRateCount; ++pFragmentShadingRateIndex)
        {
            skip |= ValidateStructPnext("vkGetPhysicalDeviceFragmentShadingRatesKHR", ParameterName("pFragmentShadingRates[%i].pNext", ParameterName::IndexVector{ pFragmentShadingRateIndex }), nullptr, pFragmentShadingRates[pFragmentShadingRateIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkPhysicalDeviceFragmentShadingRateKHR-pNext-pNext", kVUIDUndefined, true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetFragmentShadingRateKHR(
    VkCommandBuffer                             commandBuffer,
    const VkExtent2D*                           pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkCmdSetFragmentShadingRateKHR", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2)) skip |= OutputExtensionError("vkCmdSetFragmentShadingRateKHR", "VK_KHR_get_physical_device_properties2");
    if (!instance_extensions.vk_feature_version_1_2) skip |= OutputExtensionError("vkCmdSetFragmentShadingRateKHR", "VK_VERSION_1_2");
    if (!IsExtEnabled(device_extensions.vk_khr_create_renderpass2)) skip |= OutputExtensionError("vkCmdSetFragmentShadingRateKHR", "VK_KHR_create_renderpass2");
    if (!IsExtEnabled(device_extensions.vk_khr_fragment_shading_rate)) skip |= OutputExtensionError("vkCmdSetFragmentShadingRateKHR", "VK_KHR_fragment_shading_rate");
    skip |= ValidateRequiredPointer("vkCmdSetFragmentShadingRateKHR", "pFragmentSize", pFragmentSize, "VUID-vkCmdSetFragmentShadingRateKHR-pFragmentSize-parameter");
    if (pFragmentSize != nullptr)
    {
        // No xml-driven validation
    }
    skip |= ValidateRangedEnumArray("vkCmdSetFragmentShadingRateKHR", "None", "combinerOps", "VkFragmentShadingRateCombinerOpKHR", 2, combinerOps, false, true);
    return skip;
}



bool StatelessValidation::PreCallValidateCmdRefreshObjectsKHR(
    VkCommandBuffer                             commandBuffer,
    const VkRefreshObjectListKHR*               pRefreshObjects) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_khr_object_refresh)) skip |= OutputExtensionError("vkCmdRefreshObjectsKHR", "VK_KHR_object_refresh");
    skip |= ValidateStructType("vkCmdRefreshObjectsKHR", "pRefreshObjects", "VK_STRUCTURE_TYPE_REFRESH_OBJECT_LIST_KHR", pRefreshObjects, VK_STRUCTURE_TYPE_REFRESH_OBJECT_LIST_KHR, true, "VUID-vkCmdRefreshObjectsKHR-pRefreshObjects-parameter", "VUID-VkRefreshObjectListKHR-sType-sType");
    if (pRefreshObjects != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdRefreshObjectsKHR", "pRefreshObjects->pNext", nullptr, pRefreshObjects->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkRefreshObjectListKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateArray("vkCmdRefreshObjectsKHR", "pRefreshObjects->objectCount", "pRefreshObjects->pObjects", pRefreshObjects->objectCount, &pRefreshObjects->pObjects, true, true, "VUID-VkRefreshObjectListKHR-objectCount-arraylength", "VUID-VkRefreshObjectListKHR-pObjects-parameter");

        if (pRefreshObjects->pObjects != nullptr)
        {
            for (uint32_t objectIndex = 0; objectIndex < pRefreshObjects->objectCount; ++objectIndex)
            {
                skip |= ValidateRangedEnum("vkCmdRefreshObjectsKHR", ParameterName("pRefreshObjects->pObjects[%i].objectType", ParameterName::IndexVector{ objectIndex }), "VkObjectType", pRefreshObjects->pObjects[objectIndex].objectType, "VUID-VkRefreshObjectKHR-objectType-parameter");

                skip |= ValidateReservedFlags("vkCmdRefreshObjectsKHR", ParameterName("pRefreshObjects->pObjects[%i].flags", ParameterName::IndexVector{ objectIndex }), pRefreshObjects->pObjects[objectIndex].flags, "VUID-VkRefreshObjectKHR-flags-zerobitmask");
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceRefreshableObjectTypesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pRefreshableObjectTypeCount,
    VkObjectType*                               pRefreshableObjectTypes) const {
    bool skip = false;
    skip |= ValidateArray("vkGetPhysicalDeviceRefreshableObjectTypesKHR", "pRefreshableObjectTypeCount", "pRefreshableObjectTypes", pRefreshableObjectTypeCount, &pRefreshableObjectTypes, true, false, false, kVUIDUndefined, "VUID-vkGetPhysicalDeviceRefreshableObjectTypesKHR-pRefreshableObjectTypes-parameter");
    return skip;
}



bool StatelessValidation::PreCallValidateCmdSetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_synchronization2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetEvent2KHR", "VK_KHR_synchronization2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateRequiredHandle("vkCmdSetEvent2KHR", "event", event);
    skip |= ValidateStructType("vkCmdSetEvent2KHR", "pDependencyInfo", "VK_STRUCTURE_TYPE_DEPENDENCY_INFO", pDependencyInfo, VK_STRUCTURE_TYPE_DEPENDENCY_INFO, true, "VUID-vkCmdSetEvent2-pDependencyInfo-parameter", "VUID-VkDependencyInfo-sType-sType");
    if (pDependencyInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdSetEvent2KHR", "pDependencyInfo->pNext", nullptr, pDependencyInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDependencyInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags("vkCmdSetEvent2KHR", "pDependencyInfo->dependencyFlags", "VkDependencyFlagBits", AllVkDependencyFlagBits, pDependencyInfo->dependencyFlags, kOptionalFlags, "VUID-VkDependencyInfo-dependencyFlags-parameter");

        skip |= ValidateStructTypeArray("vkCmdSetEvent2KHR", "pDependencyInfo->memoryBarrierCount", "pDependencyInfo->pMemoryBarriers", "VK_STRUCTURE_TYPE_MEMORY_BARRIER_2", pDependencyInfo->memoryBarrierCount, pDependencyInfo->pMemoryBarriers, VK_STRUCTURE_TYPE_MEMORY_BARRIER_2, false, true, "VUID-VkMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pMemoryBarriers != nullptr)
        {
            for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < pDependencyInfo->memoryBarrierCount; ++memoryBarrierIndex)
            {
                skip |= ValidateStructPnext("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pMemoryBarriers[%i].pNext", ParameterName::IndexVector{ memoryBarrierIndex }), nullptr, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstAccessMask-parameter");
            }
        }

        skip |= ValidateStructTypeArray("vkCmdSetEvent2KHR", "pDependencyInfo->bufferMemoryBarrierCount", "pDependencyInfo->pBufferMemoryBarriers", "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2", pDependencyInfo->bufferMemoryBarrierCount, pDependencyInfo->pBufferMemoryBarriers, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2, false, true, "VUID-VkBufferMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pBufferMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t bufferMemoryBarrierIndex = 0; bufferMemoryBarrierIndex < pDependencyInfo->bufferMemoryBarrierCount; ++bufferMemoryBarrierIndex)
            {
                skip |= ValidateStructPnext("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].pNext", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), nullptr, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstAccessMask-parameter");

                skip |= ValidateRequiredHandle("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].buffer", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
            }
        }

        skip |= ValidateStructTypeArray("vkCmdSetEvent2KHR", "pDependencyInfo->imageMemoryBarrierCount", "pDependencyInfo->pImageMemoryBarriers", "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2", pDependencyInfo->imageMemoryBarrierCount, pDependencyInfo->pImageMemoryBarriers, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2, false, true, "VUID-VkImageMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pImageMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t imageMemoryBarrierIndex = 0; imageMemoryBarrierIndex < pDependencyInfo->imageMemoryBarrierCount; ++imageMemoryBarrierIndex)
            {
                constexpr std::array allowed_structs_VkImageMemoryBarrier2 = { VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT };

                skip |= ValidateStructPnext("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].pNext", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkSampleLocationsInfoEXT", pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].pNext, allowed_structs_VkImageMemoryBarrier2.size(), allowed_structs_VkImageMemoryBarrier2.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier2-pNext-pNext", "VUID-VkImageMemoryBarrier2-sType-unique", false, true);

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstAccessMask-parameter");

                skip |= ValidateRangedEnum("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].oldLayout", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageLayout", pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout, "VUID-VkImageMemoryBarrier2-oldLayout-parameter");

                skip |= ValidateRangedEnum("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].newLayout", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageLayout", pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout, "VUID-VkImageMemoryBarrier2-newLayout-parameter");

                skip |= ValidateRequiredHandle("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].image", ParameterName::IndexVector{ imageMemoryBarrierIndex }), pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].image);

                skip |= ValidateFlags("vkCmdSetEvent2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].subresourceRange.aspectMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_synchronization2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdResetEvent2KHR", "VK_KHR_synchronization2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateRequiredHandle("vkCmdResetEvent2KHR", "event", event);
    skip |= ValidateFlags("vkCmdResetEvent2KHR", "stageMask", "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, stageMask, kOptionalFlags, "VUID-vkCmdResetEvent2-stageMask-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWaitEvents2KHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_synchronization2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdWaitEvents2KHR", "VK_KHR_synchronization2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateHandleArray("vkCmdWaitEvents2KHR", "eventCount", "pEvents", eventCount, pEvents, true, true, "VUID-vkCmdWaitEvents2-eventCount-arraylength");
    skip |= ValidateStructTypeArray("vkCmdWaitEvents2KHR", "eventCount", "pDependencyInfos", "VK_STRUCTURE_TYPE_DEPENDENCY_INFO", eventCount, pDependencyInfos, VK_STRUCTURE_TYPE_DEPENDENCY_INFO, true, true, "VUID-VkDependencyInfo-sType-sType", "VUID-vkCmdWaitEvents2-pDependencyInfos-parameter", "VUID-vkCmdWaitEvents2-eventCount-arraylength");
    if (pDependencyInfos != nullptr)
    {
        for (uint32_t eventIndex = 0; eventIndex < eventCount; ++eventIndex)
        {
            skip |= ValidateStructPnext("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pNext", ParameterName::IndexVector{ eventIndex }), nullptr, pDependencyInfos[eventIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDependencyInfo-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].dependencyFlags", ParameterName::IndexVector{ eventIndex }), "VkDependencyFlagBits", AllVkDependencyFlagBits, pDependencyInfos[eventIndex].dependencyFlags, kOptionalFlags, "VUID-VkDependencyInfo-dependencyFlags-parameter");

            skip |= ValidateStructTypeArray("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].memoryBarrierCount", ParameterName::IndexVector{ eventIndex }), ParameterName("pDependencyInfos[%i].pMemoryBarriers", ParameterName::IndexVector{ eventIndex }), "VK_STRUCTURE_TYPE_MEMORY_BARRIER_2", pDependencyInfos[eventIndex].memoryBarrierCount, pDependencyInfos[eventIndex].pMemoryBarriers, VK_STRUCTURE_TYPE_MEMORY_BARRIER_2, false, true, "VUID-VkMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pMemoryBarriers-parameter", kVUIDUndefined);

            if (pDependencyInfos[eventIndex].pMemoryBarriers != nullptr)
            {
                for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < pDependencyInfos[eventIndex].memoryBarrierCount; ++memoryBarrierIndex)
                {
                    skip |= ValidateStructPnext("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pMemoryBarriers[%i].pNext", ParameterName::IndexVector{ eventIndex, memoryBarrierIndex }), nullptr, pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ eventIndex, memoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcStageMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ eventIndex, memoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcAccessMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ eventIndex, memoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstStageMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ eventIndex, memoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstAccessMask-parameter");
                }
            }

            skip |= ValidateStructTypeArray("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].bufferMemoryBarrierCount", ParameterName::IndexVector{ eventIndex }), ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers", ParameterName::IndexVector{ eventIndex }), "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2", pDependencyInfos[eventIndex].bufferMemoryBarrierCount, pDependencyInfos[eventIndex].pBufferMemoryBarriers, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2, false, true, "VUID-VkBufferMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pBufferMemoryBarriers-parameter", kVUIDUndefined);

            if (pDependencyInfos[eventIndex].pBufferMemoryBarriers != nullptr)
            {
                for (uint32_t bufferMemoryBarrierIndex = 0; bufferMemoryBarrierIndex < pDependencyInfos[eventIndex].bufferMemoryBarrierCount; ++bufferMemoryBarrierIndex)
                {
                    skip |= ValidateStructPnext("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers[%i].pNext", ParameterName::IndexVector{ eventIndex, bufferMemoryBarrierIndex }), nullptr, pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier2-pNext-pNext", kVUIDUndefined, false, true);

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ eventIndex, bufferMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcStageMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ eventIndex, bufferMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcAccessMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ eventIndex, bufferMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstStageMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ eventIndex, bufferMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstAccessMask-parameter");

                    skip |= ValidateRequiredHandle("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pBufferMemoryBarriers[%i].buffer", ParameterName::IndexVector{ eventIndex, bufferMemoryBarrierIndex }), pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
                }
            }

            skip |= ValidateStructTypeArray("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].imageMemoryBarrierCount", ParameterName::IndexVector{ eventIndex }), ParameterName("pDependencyInfos[%i].pImageMemoryBarriers", ParameterName::IndexVector{ eventIndex }), "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2", pDependencyInfos[eventIndex].imageMemoryBarrierCount, pDependencyInfos[eventIndex].pImageMemoryBarriers, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2, false, true, "VUID-VkImageMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pImageMemoryBarriers-parameter", kVUIDUndefined);

            if (pDependencyInfos[eventIndex].pImageMemoryBarriers != nullptr)
            {
                for (uint32_t imageMemoryBarrierIndex = 0; imageMemoryBarrierIndex < pDependencyInfos[eventIndex].imageMemoryBarrierCount; ++imageMemoryBarrierIndex)
                {
                    constexpr std::array allowed_structs_VkImageMemoryBarrier2 = { VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT };

                    skip |= ValidateStructPnext("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].pNext", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkSampleLocationsInfoEXT", pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].pNext, allowed_structs_VkImageMemoryBarrier2.size(), allowed_structs_VkImageMemoryBarrier2.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier2-pNext-pNext", "VUID-VkImageMemoryBarrier2-sType-unique", false, true);

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcStageMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcAccessMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstStageMask-parameter");

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstAccessMask-parameter");

                    skip |= ValidateRangedEnum("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].oldLayout", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkImageLayout", pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout, "VUID-VkImageMemoryBarrier2-oldLayout-parameter");

                    skip |= ValidateRangedEnum("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].newLayout", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkImageLayout", pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout, "VUID-VkImageMemoryBarrier2-newLayout-parameter");

                    skip |= ValidateRequiredHandle("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].image", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].image);

                    skip |= ValidateFlags("vkCmdWaitEvents2KHR", ParameterName("pDependencyInfos[%i].pImageMemoryBarriers[%i].subresourceRange.aspectMask", ParameterName::IndexVector{ eventIndex, imageMemoryBarrierIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
                }
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdPipelineBarrier2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_synchronization2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdPipelineBarrier2KHR", "VK_KHR_synchronization2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkCmdPipelineBarrier2KHR", "pDependencyInfo", "VK_STRUCTURE_TYPE_DEPENDENCY_INFO", pDependencyInfo, VK_STRUCTURE_TYPE_DEPENDENCY_INFO, true, "VUID-vkCmdPipelineBarrier2-pDependencyInfo-parameter", "VUID-VkDependencyInfo-sType-sType");
    if (pDependencyInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdPipelineBarrier2KHR", "pDependencyInfo->pNext", nullptr, pDependencyInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDependencyInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", "pDependencyInfo->dependencyFlags", "VkDependencyFlagBits", AllVkDependencyFlagBits, pDependencyInfo->dependencyFlags, kOptionalFlags, "VUID-VkDependencyInfo-dependencyFlags-parameter");

        skip |= ValidateStructTypeArray("vkCmdPipelineBarrier2KHR", "pDependencyInfo->memoryBarrierCount", "pDependencyInfo->pMemoryBarriers", "VK_STRUCTURE_TYPE_MEMORY_BARRIER_2", pDependencyInfo->memoryBarrierCount, pDependencyInfo->pMemoryBarriers, VK_STRUCTURE_TYPE_MEMORY_BARRIER_2, false, true, "VUID-VkMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pMemoryBarriers != nullptr)
        {
            for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < pDependencyInfo->memoryBarrierCount; ++memoryBarrierIndex)
            {
                skip |= ValidateStructPnext("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pMemoryBarriers[%i].pNext", ParameterName::IndexVector{ memoryBarrierIndex }), nullptr, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ memoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstAccessMask-parameter");
            }
        }

        skip |= ValidateStructTypeArray("vkCmdPipelineBarrier2KHR", "pDependencyInfo->bufferMemoryBarrierCount", "pDependencyInfo->pBufferMemoryBarriers", "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2", pDependencyInfo->bufferMemoryBarrierCount, pDependencyInfo->pBufferMemoryBarriers, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2, false, true, "VUID-VkBufferMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pBufferMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t bufferMemoryBarrierIndex = 0; bufferMemoryBarrierIndex < pDependencyInfo->bufferMemoryBarrierCount; ++bufferMemoryBarrierIndex)
            {
                skip |= ValidateStructPnext("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].pNext", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), nullptr, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstAccessMask-parameter");

                skip |= ValidateRequiredHandle("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pBufferMemoryBarriers[%i].buffer", ParameterName::IndexVector{ bufferMemoryBarrierIndex }), pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
            }
        }

        skip |= ValidateStructTypeArray("vkCmdPipelineBarrier2KHR", "pDependencyInfo->imageMemoryBarrierCount", "pDependencyInfo->pImageMemoryBarriers", "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2", pDependencyInfo->imageMemoryBarrierCount, pDependencyInfo->pImageMemoryBarriers, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2, false, true, "VUID-VkImageMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pImageMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t imageMemoryBarrierIndex = 0; imageMemoryBarrierIndex < pDependencyInfo->imageMemoryBarrierCount; ++imageMemoryBarrierIndex)
            {
                constexpr std::array allowed_structs_VkImageMemoryBarrier2 = { VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT };

                skip |= ValidateStructPnext("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].pNext", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkSampleLocationsInfoEXT", pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].pNext, allowed_structs_VkImageMemoryBarrier2.size(), allowed_structs_VkImageMemoryBarrier2.data(), GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier2-pNext-pNext", "VUID-VkImageMemoryBarrier2-sType-unique", false, true);

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].srcStageMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].srcStageMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].srcAccessMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].srcAccessMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].dstStageMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].dstStageMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].dstAccessMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkAccessFlagBits2", AllVkAccessFlagBits2, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].dstAccessMask, kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstAccessMask-parameter");

                skip |= ValidateRangedEnum("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].oldLayout", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageLayout", pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout, "VUID-VkImageMemoryBarrier2-oldLayout-parameter");

                skip |= ValidateRangedEnum("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].newLayout", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageLayout", pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout, "VUID-VkImageMemoryBarrier2-newLayout-parameter");

                skip |= ValidateRequiredHandle("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].image", ParameterName::IndexVector{ imageMemoryBarrierIndex }), pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].image);

                skip |= ValidateFlags("vkCmdPipelineBarrier2KHR", ParameterName("pDependencyInfo->pImageMemoryBarriers[%i].subresourceRange.aspectMask", ParameterName::IndexVector{ imageMemoryBarrierIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWriteTimestamp2KHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_synchronization2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdWriteTimestamp2KHR", "VK_KHR_synchronization2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateFlags("vkCmdWriteTimestamp2KHR", "stage", "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, stage, kOptionalFlags, "VUID-vkCmdWriteTimestamp2-stage-parameter");
    skip |= ValidateRequiredHandle("vkCmdWriteTimestamp2KHR", "queryPool", queryPool);
    return skip;
}

bool StatelessValidation::PreCallValidateQueueSubmit2KHR(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo2*                        pSubmits,
    VkFence                                     fence) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_synchronization2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkQueueSubmit2KHR", "VK_KHR_synchronization2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructTypeArray("vkQueueSubmit2KHR", "submitCount", "pSubmits", "VK_STRUCTURE_TYPE_SUBMIT_INFO_2", submitCount, pSubmits, VK_STRUCTURE_TYPE_SUBMIT_INFO_2, false, true, "VUID-VkSubmitInfo2-sType-sType", "VUID-vkQueueSubmit2-pSubmits-parameter", kVUIDUndefined);
    if (pSubmits != nullptr)
    {
        for (uint32_t submitIndex = 0; submitIndex < submitCount; ++submitIndex)
        {
            constexpr std::array allowed_structs_VkSubmitInfo2 = { VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR };

            skip |= ValidateStructPnext("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].pNext", ParameterName::IndexVector{ submitIndex }), "VkPerformanceQuerySubmitInfoKHR", pSubmits[submitIndex].pNext, allowed_structs_VkSubmitInfo2.size(), allowed_structs_VkSubmitInfo2.data(), GeneratedVulkanHeaderVersion, "VUID-VkSubmitInfo2-pNext-pNext", "VUID-VkSubmitInfo2-sType-unique", false, true);

            skip |= ValidateFlags("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].flags", ParameterName::IndexVector{ submitIndex }), "VkSubmitFlagBits", AllVkSubmitFlagBits, pSubmits[submitIndex].flags, kOptionalFlags, "VUID-VkSubmitInfo2-flags-parameter");

            skip |= ValidateStructTypeArray("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].waitSemaphoreInfoCount", ParameterName::IndexVector{ submitIndex }), ParameterName("pSubmits[%i].pWaitSemaphoreInfos", ParameterName::IndexVector{ submitIndex }), "VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO", pSubmits[submitIndex].waitSemaphoreInfoCount, pSubmits[submitIndex].pWaitSemaphoreInfos, VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO, false, true, "VUID-VkSemaphoreSubmitInfo-sType-sType", "VUID-VkSubmitInfo2-pWaitSemaphoreInfos-parameter", kVUIDUndefined);

            if (pSubmits[submitIndex].pWaitSemaphoreInfos != nullptr)
            {
                for (uint32_t waitSemaphoreInfoIndex = 0; waitSemaphoreInfoIndex < pSubmits[submitIndex].waitSemaphoreInfoCount; ++waitSemaphoreInfoIndex)
                {
                    skip |= ValidateStructPnext("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].pWaitSemaphoreInfos[%i].pNext", ParameterName::IndexVector{ submitIndex, waitSemaphoreInfoIndex }), nullptr, pSubmits[submitIndex].pWaitSemaphoreInfos[waitSemaphoreInfoIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSemaphoreSubmitInfo-pNext-pNext", kVUIDUndefined, false, true);

                    skip |= ValidateRequiredHandle("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].pWaitSemaphoreInfos[%i].semaphore", ParameterName::IndexVector{ submitIndex, waitSemaphoreInfoIndex }), pSubmits[submitIndex].pWaitSemaphoreInfos[waitSemaphoreInfoIndex].semaphore);

                    skip |= ValidateFlags("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].pWaitSemaphoreInfos[%i].stageMask", ParameterName::IndexVector{ submitIndex, waitSemaphoreInfoIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pSubmits[submitIndex].pWaitSemaphoreInfos[waitSemaphoreInfoIndex].stageMask, kOptionalFlags, "VUID-VkSemaphoreSubmitInfo-stageMask-parameter");
                }
            }

            skip |= ValidateStructTypeArray("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].commandBufferInfoCount", ParameterName::IndexVector{ submitIndex }), ParameterName("pSubmits[%i].pCommandBufferInfos", ParameterName::IndexVector{ submitIndex }), "VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO", pSubmits[submitIndex].commandBufferInfoCount, pSubmits[submitIndex].pCommandBufferInfos, VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO, false, true, "VUID-VkCommandBufferSubmitInfo-sType-sType", "VUID-VkSubmitInfo2-pCommandBufferInfos-parameter", kVUIDUndefined);

            if (pSubmits[submitIndex].pCommandBufferInfos != nullptr)
            {
                for (uint32_t commandBufferInfoIndex = 0; commandBufferInfoIndex < pSubmits[submitIndex].commandBufferInfoCount; ++commandBufferInfoIndex)
                {
                    skip |= ValidateStructPnext("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].pCommandBufferInfos[%i].pNext", ParameterName::IndexVector{ submitIndex, commandBufferInfoIndex }), nullptr, pSubmits[submitIndex].pCommandBufferInfos[commandBufferInfoIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCommandBufferSubmitInfo-pNext-pNext", kVUIDUndefined, false, true);

                    skip |= ValidateRequiredHandle("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].pCommandBufferInfos[%i].commandBuffer", ParameterName::IndexVector{ submitIndex, commandBufferInfoIndex }), pSubmits[submitIndex].pCommandBufferInfos[commandBufferInfoIndex].commandBuffer);
                }
            }

            skip |= ValidateStructTypeArray("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].signalSemaphoreInfoCount", ParameterName::IndexVector{ submitIndex }), ParameterName("pSubmits[%i].pSignalSemaphoreInfos", ParameterName::IndexVector{ submitIndex }), "VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO", pSubmits[submitIndex].signalSemaphoreInfoCount, pSubmits[submitIndex].pSignalSemaphoreInfos, VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO, false, true, "VUID-VkSemaphoreSubmitInfo-sType-sType", "VUID-VkSubmitInfo2-pSignalSemaphoreInfos-parameter", kVUIDUndefined);

            if (pSubmits[submitIndex].pSignalSemaphoreInfos != nullptr)
            {
                for (uint32_t signalSemaphoreInfoIndex = 0; signalSemaphoreInfoIndex < pSubmits[submitIndex].signalSemaphoreInfoCount; ++signalSemaphoreInfoIndex)
                {
                    skip |= ValidateStructPnext("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].pSignalSemaphoreInfos[%i].pNext", ParameterName::IndexVector{ submitIndex, signalSemaphoreInfoIndex }), nullptr, pSubmits[submitIndex].pSignalSemaphoreInfos[signalSemaphoreInfoIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSemaphoreSubmitInfo-pNext-pNext", kVUIDUndefined, false, true);

                    skip |= ValidateRequiredHandle("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].pSignalSemaphoreInfos[%i].semaphore", ParameterName::IndexVector{ submitIndex, signalSemaphoreInfoIndex }), pSubmits[submitIndex].pSignalSemaphoreInfos[signalSemaphoreInfoIndex].semaphore);

                    skip |= ValidateFlags("vkQueueSubmit2KHR", ParameterName("pSubmits[%i].pSignalSemaphoreInfos[%i].stageMask", ParameterName::IndexVector{ submitIndex, signalSemaphoreInfoIndex }), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, pSubmits[submitIndex].pSignalSemaphoreInfos[signalSemaphoreInfoIndex].stageMask, kOptionalFlags, "VUID-VkSemaphoreSubmitInfo-stageMask-parameter");
                }
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWriteBufferMarker2AMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_amd_buffer_marker)) skip |= OutputExtensionError("vkCmdWriteBufferMarker2AMD", "VK_AMD_buffer_marker");
    if (!(IsExtEnabled(device_extensions.vk_khr_synchronization2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdWriteBufferMarker2AMD", "VK_KHR_synchronization2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateFlags("vkCmdWriteBufferMarker2AMD", "stage", "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, stage, kOptionalFlags, "VUID-vkCmdWriteBufferMarker2AMD-stage-parameter");
    skip |= ValidateRequiredHandle("vkCmdWriteBufferMarker2AMD", "dstBuffer", dstBuffer);
    return skip;
}

bool StatelessValidation::PreCallValidateGetQueueCheckpointData2NV(
    VkQueue                                     queue,
    uint32_t*                                   pCheckpointDataCount,
    VkCheckpointData2NV*                        pCheckpointData) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_nv_device_diagnostic_checkpoints)) skip |= OutputExtensionError("vkGetQueueCheckpointData2NV", "VK_NV_device_diagnostic_checkpoints");
    if (!(IsExtEnabled(device_extensions.vk_khr_synchronization2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkGetQueueCheckpointData2NV", "VK_KHR_synchronization2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructTypeArray("vkGetQueueCheckpointData2NV", "pCheckpointDataCount", "pCheckpointData", "VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV", pCheckpointDataCount, pCheckpointData, VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV, true, false, false, "VUID-VkCheckpointData2NV-sType-sType", "VUID-vkGetQueueCheckpointData2NV-pCheckpointData-parameter", kVUIDUndefined);
    if (pCheckpointData != nullptr)
    {
        for (uint32_t pCheckpointDataIndex = 0; pCheckpointDataIndex < *pCheckpointDataCount; ++pCheckpointDataIndex)
        {
            skip |= ValidateStructPnext("vkGetQueueCheckpointData2NV", ParameterName("pCheckpointData[%i].pNext", ParameterName::IndexVector{ pCheckpointDataIndex }), nullptr, pCheckpointData[pCheckpointDataIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCheckpointData2NV-pNext-pNext", kVUIDUndefined, false, false);
        }
    }
    return skip;
}



bool StatelessValidation::PreCallValidateCmdCopyBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_copy_commands2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdCopyBuffer2KHR", "VK_KHR_copy_commands2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkCmdCopyBuffer2KHR", "pCopyBufferInfo", "VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2", pCopyBufferInfo, VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2, true, "VUID-vkCmdCopyBuffer2-pCopyBufferInfo-parameter", "VUID-VkCopyBufferInfo2-sType-sType");
    if (pCopyBufferInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdCopyBuffer2KHR", "pCopyBufferInfo->pNext", nullptr, pCopyBufferInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCopyBufferInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkCmdCopyBuffer2KHR", "pCopyBufferInfo->srcBuffer", pCopyBufferInfo->srcBuffer);

        skip |= ValidateRequiredHandle("vkCmdCopyBuffer2KHR", "pCopyBufferInfo->dstBuffer", pCopyBufferInfo->dstBuffer);

        skip |= ValidateStructTypeArray("vkCmdCopyBuffer2KHR", "pCopyBufferInfo->regionCount", "pCopyBufferInfo->pRegions", "VK_STRUCTURE_TYPE_BUFFER_COPY_2", pCopyBufferInfo->regionCount, pCopyBufferInfo->pRegions, VK_STRUCTURE_TYPE_BUFFER_COPY_2, true, true, "VUID-VkBufferCopy2-sType-sType", "VUID-VkCopyBufferInfo2-pRegions-parameter", "VUID-VkCopyBufferInfo2-regionCount-arraylength");

        if (pCopyBufferInfo->pRegions != nullptr)
        {
            for (uint32_t regionIndex = 0; regionIndex < pCopyBufferInfo->regionCount; ++regionIndex)
            {
                skip |= ValidateStructPnext("vkCmdCopyBuffer2KHR", ParameterName("pCopyBufferInfo->pRegions[%i].pNext", ParameterName::IndexVector{ regionIndex }), nullptr, pCopyBufferInfo->pRegions[regionIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferCopy2-pNext-pNext", kVUIDUndefined, false, true);
            }
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_copy_commands2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdCopyImage2KHR", "VK_KHR_copy_commands2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkCmdCopyImage2KHR", "pCopyImageInfo", "VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2", pCopyImageInfo, VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2, true, "VUID-vkCmdCopyImage2-pCopyImageInfo-parameter", "VUID-VkCopyImageInfo2-sType-sType");
    if (pCopyImageInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdCopyImage2KHR", "pCopyImageInfo->pNext", nullptr, pCopyImageInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCopyImageInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkCmdCopyImage2KHR", "pCopyImageInfo->srcImage", pCopyImageInfo->srcImage);

        skip |= ValidateRangedEnum("vkCmdCopyImage2KHR", "pCopyImageInfo->srcImageLayout", "VkImageLayout", pCopyImageInfo->srcImageLayout, "VUID-VkCopyImageInfo2-srcImageLayout-parameter");

        skip |= ValidateRequiredHandle("vkCmdCopyImage2KHR", "pCopyImageInfo->dstImage", pCopyImageInfo->dstImage);

        skip |= ValidateRangedEnum("vkCmdCopyImage2KHR", "pCopyImageInfo->dstImageLayout", "VkImageLayout", pCopyImageInfo->dstImageLayout, "VUID-VkCopyImageInfo2-dstImageLayout-parameter");

        skip |= ValidateStructTypeArray("vkCmdCopyImage2KHR", "pCopyImageInfo->regionCount", "pCopyImageInfo->pRegions", "VK_STRUCTURE_TYPE_IMAGE_COPY_2", pCopyImageInfo->regionCount, pCopyImageInfo->pRegions, VK_STRUCTURE_TYPE_IMAGE_COPY_2, true, true, "VUID-VkImageCopy2-sType-sType", "VUID-VkCopyImageInfo2-pRegions-parameter", "VUID-VkCopyImageInfo2-regionCount-arraylength");

        if (pCopyImageInfo->pRegions != nullptr)
        {
            for (uint32_t regionIndex = 0; regionIndex < pCopyImageInfo->regionCount; ++regionIndex)
            {
                skip |= ValidateStructPnext("vkCmdCopyImage2KHR", ParameterName("pCopyImageInfo->pRegions[%i].pNext", ParameterName::IndexVector{ regionIndex }), nullptr, pCopyImageInfo->pRegions[regionIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkImageCopy2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdCopyImage2KHR", ParameterName("pCopyImageInfo->pRegions[%i].srcSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pCopyImageInfo->pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                skip |= ValidateFlags("vkCmdCopyImage2KHR", ParameterName("pCopyImageInfo->pRegions[%i].dstSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pCopyImageInfo->pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyBufferToImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_copy_commands2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdCopyBufferToImage2KHR", "VK_KHR_copy_commands2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkCmdCopyBufferToImage2KHR", "pCopyBufferToImageInfo", "VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2", pCopyBufferToImageInfo, VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2, true, "VUID-vkCmdCopyBufferToImage2-pCopyBufferToImageInfo-parameter", "VUID-VkCopyBufferToImageInfo2-sType-sType");
    if (pCopyBufferToImageInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdCopyBufferToImage2KHR", "pCopyBufferToImageInfo->pNext", nullptr, pCopyBufferToImageInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCopyBufferToImageInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkCmdCopyBufferToImage2KHR", "pCopyBufferToImageInfo->srcBuffer", pCopyBufferToImageInfo->srcBuffer);

        skip |= ValidateRequiredHandle("vkCmdCopyBufferToImage2KHR", "pCopyBufferToImageInfo->dstImage", pCopyBufferToImageInfo->dstImage);

        skip |= ValidateRangedEnum("vkCmdCopyBufferToImage2KHR", "pCopyBufferToImageInfo->dstImageLayout", "VkImageLayout", pCopyBufferToImageInfo->dstImageLayout, "VUID-VkCopyBufferToImageInfo2-dstImageLayout-parameter");

        skip |= ValidateStructTypeArray("vkCmdCopyBufferToImage2KHR", "pCopyBufferToImageInfo->regionCount", "pCopyBufferToImageInfo->pRegions", "VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2", pCopyBufferToImageInfo->regionCount, pCopyBufferToImageInfo->pRegions, VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2, true, true, "VUID-VkBufferImageCopy2-sType-sType", "VUID-VkCopyBufferToImageInfo2-pRegions-parameter", "VUID-VkCopyBufferToImageInfo2-regionCount-arraylength");

        if (pCopyBufferToImageInfo->pRegions != nullptr)
        {
            for (uint32_t regionIndex = 0; regionIndex < pCopyBufferToImageInfo->regionCount; ++regionIndex)
            {
                skip |= ValidateStructPnext("vkCmdCopyBufferToImage2KHR", ParameterName("pCopyBufferToImageInfo->pRegions[%i].pNext", ParameterName::IndexVector{ regionIndex }), nullptr, pCopyBufferToImageInfo->pRegions[regionIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferImageCopy2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdCopyBufferToImage2KHR", ParameterName("pCopyBufferToImageInfo->pRegions[%i].imageSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pCopyBufferToImageInfo->pRegions[regionIndex].imageSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyImageToBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_copy_commands2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdCopyImageToBuffer2KHR", "VK_KHR_copy_commands2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkCmdCopyImageToBuffer2KHR", "pCopyImageToBufferInfo", "VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2", pCopyImageToBufferInfo, VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2, true, "VUID-vkCmdCopyImageToBuffer2-pCopyImageToBufferInfo-parameter", "VUID-VkCopyImageToBufferInfo2-sType-sType");
    if (pCopyImageToBufferInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdCopyImageToBuffer2KHR", "pCopyImageToBufferInfo->pNext", nullptr, pCopyImageToBufferInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCopyImageToBufferInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkCmdCopyImageToBuffer2KHR", "pCopyImageToBufferInfo->srcImage", pCopyImageToBufferInfo->srcImage);

        skip |= ValidateRangedEnum("vkCmdCopyImageToBuffer2KHR", "pCopyImageToBufferInfo->srcImageLayout", "VkImageLayout", pCopyImageToBufferInfo->srcImageLayout, "VUID-VkCopyImageToBufferInfo2-srcImageLayout-parameter");

        skip |= ValidateRequiredHandle("vkCmdCopyImageToBuffer2KHR", "pCopyImageToBufferInfo->dstBuffer", pCopyImageToBufferInfo->dstBuffer);

        skip |= ValidateStructTypeArray("vkCmdCopyImageToBuffer2KHR", "pCopyImageToBufferInfo->regionCount", "pCopyImageToBufferInfo->pRegions", "VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2", pCopyImageToBufferInfo->regionCount, pCopyImageToBufferInfo->pRegions, VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2, true, true, "VUID-VkBufferImageCopy2-sType-sType", "VUID-VkCopyImageToBufferInfo2-pRegions-parameter", "VUID-VkCopyImageToBufferInfo2-regionCount-arraylength");

        if (pCopyImageToBufferInfo->pRegions != nullptr)
        {
            for (uint32_t regionIndex = 0; regionIndex < pCopyImageToBufferInfo->regionCount; ++regionIndex)
            {
                skip |= ValidateStructPnext("vkCmdCopyImageToBuffer2KHR", ParameterName("pCopyImageToBufferInfo->pRegions[%i].pNext", ParameterName::IndexVector{ regionIndex }), nullptr, pCopyImageToBufferInfo->pRegions[regionIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferImageCopy2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdCopyImageToBuffer2KHR", ParameterName("pCopyImageToBufferInfo->pRegions[%i].imageSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pCopyImageToBufferInfo->pRegions[regionIndex].imageSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBlitImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_copy_commands2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdBlitImage2KHR", "VK_KHR_copy_commands2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkCmdBlitImage2KHR", "pBlitImageInfo", "VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2", pBlitImageInfo, VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2, true, "VUID-vkCmdBlitImage2-pBlitImageInfo-parameter", "VUID-VkBlitImageInfo2-sType-sType");
    if (pBlitImageInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdBlitImage2KHR", "pBlitImageInfo->pNext", nullptr, pBlitImageInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBlitImageInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkCmdBlitImage2KHR", "pBlitImageInfo->srcImage", pBlitImageInfo->srcImage);

        skip |= ValidateRangedEnum("vkCmdBlitImage2KHR", "pBlitImageInfo->srcImageLayout", "VkImageLayout", pBlitImageInfo->srcImageLayout, "VUID-VkBlitImageInfo2-srcImageLayout-parameter");

        skip |= ValidateRequiredHandle("vkCmdBlitImage2KHR", "pBlitImageInfo->dstImage", pBlitImageInfo->dstImage);

        skip |= ValidateRangedEnum("vkCmdBlitImage2KHR", "pBlitImageInfo->dstImageLayout", "VkImageLayout", pBlitImageInfo->dstImageLayout, "VUID-VkBlitImageInfo2-dstImageLayout-parameter");

        skip |= ValidateStructTypeArray("vkCmdBlitImage2KHR", "pBlitImageInfo->regionCount", "pBlitImageInfo->pRegions", "VK_STRUCTURE_TYPE_IMAGE_BLIT_2", pBlitImageInfo->regionCount, pBlitImageInfo->pRegions, VK_STRUCTURE_TYPE_IMAGE_BLIT_2, true, true, "VUID-VkImageBlit2-sType-sType", "VUID-VkBlitImageInfo2-pRegions-parameter", "VUID-VkBlitImageInfo2-regionCount-arraylength");

        if (pBlitImageInfo->pRegions != nullptr)
        {
            for (uint32_t regionIndex = 0; regionIndex < pBlitImageInfo->regionCount; ++regionIndex)
            {
                skip |= ValidateStructPnext("vkCmdBlitImage2KHR", ParameterName("pBlitImageInfo->pRegions[%i].pNext", ParameterName::IndexVector{ regionIndex }), nullptr, pBlitImageInfo->pRegions[regionIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkImageBlit2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdBlitImage2KHR", ParameterName("pBlitImageInfo->pRegions[%i].srcSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pBlitImageInfo->pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                skip |= ValidateFlags("vkCmdBlitImage2KHR", ParameterName("pBlitImageInfo->pRegions[%i].dstSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pBlitImageInfo->pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");
            }
        }

        skip |= ValidateRangedEnum("vkCmdBlitImage2KHR", "pBlitImageInfo->filter", "VkFilter", pBlitImageInfo->filter, "VUID-VkBlitImageInfo2-filter-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResolveImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_khr_copy_commands2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdResolveImage2KHR", "VK_KHR_copy_commands2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkCmdResolveImage2KHR", "pResolveImageInfo", "VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2", pResolveImageInfo, VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2, true, "VUID-vkCmdResolveImage2-pResolveImageInfo-parameter", "VUID-VkResolveImageInfo2-sType-sType");
    if (pResolveImageInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdResolveImage2KHR", "pResolveImageInfo->pNext", nullptr, pResolveImageInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkResolveImageInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkCmdResolveImage2KHR", "pResolveImageInfo->srcImage", pResolveImageInfo->srcImage);

        skip |= ValidateRangedEnum("vkCmdResolveImage2KHR", "pResolveImageInfo->srcImageLayout", "VkImageLayout", pResolveImageInfo->srcImageLayout, "VUID-VkResolveImageInfo2-srcImageLayout-parameter");

        skip |= ValidateRequiredHandle("vkCmdResolveImage2KHR", "pResolveImageInfo->dstImage", pResolveImageInfo->dstImage);

        skip |= ValidateRangedEnum("vkCmdResolveImage2KHR", "pResolveImageInfo->dstImageLayout", "VkImageLayout", pResolveImageInfo->dstImageLayout, "VUID-VkResolveImageInfo2-dstImageLayout-parameter");

        skip |= ValidateStructTypeArray("vkCmdResolveImage2KHR", "pResolveImageInfo->regionCount", "pResolveImageInfo->pRegions", "VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2", pResolveImageInfo->regionCount, pResolveImageInfo->pRegions, VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2, true, true, "VUID-VkImageResolve2-sType-sType", "VUID-VkResolveImageInfo2-pRegions-parameter", "VUID-VkResolveImageInfo2-regionCount-arraylength");

        if (pResolveImageInfo->pRegions != nullptr)
        {
            for (uint32_t regionIndex = 0; regionIndex < pResolveImageInfo->regionCount; ++regionIndex)
            {
                skip |= ValidateStructPnext("vkCmdResolveImage2KHR", ParameterName("pResolveImageInfo->pRegions[%i].pNext", ParameterName::IndexVector{ regionIndex }), nullptr, pResolveImageInfo->pRegions[regionIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkImageResolve2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags("vkCmdResolveImage2KHR", ParameterName("pResolveImageInfo->pRegions[%i].srcSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pResolveImageInfo->pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                skip |= ValidateFlags("vkCmdResolveImage2KHR", ParameterName("pResolveImageInfo->pRegions[%i].dstSubresource.aspectMask", ParameterName::IndexVector{ regionIndex }), "VkImageAspectFlagBits", AllVkImageAspectFlagBits, pResolveImageInfo->pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags, "VUID-VkImageSubresourceLayers-aspectMask-parameter", "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                // No xml-driven validation
            }
        }
    }
    return skip;
}











bool StatelessValidation::PreCallValidateReleaseDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkReleaseDisplayEXT", "VK_KHR_display");
    if (!instance_extensions.vk_ext_direct_mode_display) skip |= OutputExtensionError("vkReleaseDisplayEXT", "VK_EXT_direct_mode_display");
    skip |= ValidateRequiredHandle("vkReleaseDisplayEXT", "display", display);
    return skip;
}



bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfaceCapabilities2EXT(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilities2EXT*                  pSurfaceCapabilities) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError("vkGetPhysicalDeviceSurfaceCapabilities2EXT", "VK_KHR_display");
    if (!instance_extensions.vk_ext_display_surface_counter) skip |= OutputExtensionError("vkGetPhysicalDeviceSurfaceCapabilities2EXT", "VK_EXT_display_surface_counter");
    skip |= ValidateRequiredHandle("vkGetPhysicalDeviceSurfaceCapabilities2EXT", "surface", surface);
    skip |= ValidateStructType("vkGetPhysicalDeviceSurfaceCapabilities2EXT", "pSurfaceCapabilities", "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT", pSurfaceCapabilities, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT, true, "VUID-vkGetPhysicalDeviceSurfaceCapabilities2EXT-pSurfaceCapabilities-parameter", "VUID-VkSurfaceCapabilities2EXT-sType-sType");
    if (pSurfaceCapabilities != nullptr)
    {
        skip |= ValidateStructPnext("vkGetPhysicalDeviceSurfaceCapabilities2EXT", "pSurfaceCapabilities->pNext", nullptr, pSurfaceCapabilities->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSurfaceCapabilities2EXT-pNext-pNext", kVUIDUndefined, true, false);
    }
    return skip;
}



bool StatelessValidation::PreCallValidateDisplayPowerControlEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayPowerInfoEXT*                pDisplayPowerInfo) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkDisplayPowerControlEXT", "VK_KHR_swapchain");
    if (!IsExtEnabled(device_extensions.vk_ext_display_surface_counter)) skip |= OutputExtensionError("vkDisplayPowerControlEXT", "VK_EXT_display_surface_counter");
    if (!IsExtEnabled(device_extensions.vk_ext_display_control)) skip |= OutputExtensionError("vkDisplayPowerControlEXT", "VK_EXT_display_control");
    skip |= ValidateRequiredHandle("vkDisplayPowerControlEXT", "display", display);
    skip |= ValidateStructType("vkDisplayPowerControlEXT", "pDisplayPowerInfo", "VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT", pDisplayPowerInfo, VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT, true, "VUID-vkDisplayPowerControlEXT-pDisplayPowerInfo-parameter", "VUID-VkDisplayPowerInfoEXT-sType-sType");
    if (pDisplayPowerInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkDisplayPowerControlEXT", "pDisplayPowerInfo->pNext", nullptr, pDisplayPowerInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDisplayPowerInfoEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum("vkDisplayPowerControlEXT", "pDisplayPowerInfo->powerState", "VkDisplayPowerStateEXT", pDisplayPowerInfo->powerState, "VUID-VkDisplayPowerInfoEXT-powerState-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateRegisterDeviceEventEXT(
    VkDevice                                    device,
    const VkDeviceEventInfoEXT*                 pDeviceEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkRegisterDeviceEventEXT", "VK_KHR_swapchain");
    if (!IsExtEnabled(device_extensions.vk_ext_display_surface_counter)) skip |= OutputExtensionError("vkRegisterDeviceEventEXT", "VK_EXT_display_surface_counter");
    if (!IsExtEnabled(device_extensions.vk_ext_display_control)) skip |= OutputExtensionError("vkRegisterDeviceEventEXT", "VK_EXT_display_control");
    skip |= ValidateStructType("vkRegisterDeviceEventEXT", "pDeviceEventInfo", "VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT", pDeviceEventInfo, VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT, true, "VUID-vkRegisterDeviceEventEXT-pDeviceEventInfo-parameter", "VUID-VkDeviceEventInfoEXT-sType-sType");
    if (pDeviceEventInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkRegisterDeviceEventEXT", "pDeviceEventInfo->pNext", nullptr, pDeviceEventInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDeviceEventInfoEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum("vkRegisterDeviceEventEXT", "pDeviceEventInfo->deviceEvent", "VkDeviceEventTypeEXT", pDeviceEventInfo->deviceEvent, "VUID-VkDeviceEventInfoEXT-deviceEvent-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkRegisterDeviceEventEXT-pAllocator-null", "vkRegisterDeviceEventEXT(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkRegisterDeviceEventEXT", "pFence", pFence, "VUID-vkRegisterDeviceEventEXT-pFence-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateRegisterDisplayEventEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayEventInfoEXT*                pDisplayEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkRegisterDisplayEventEXT", "VK_KHR_swapchain");
    if (!IsExtEnabled(device_extensions.vk_ext_display_surface_counter)) skip |= OutputExtensionError("vkRegisterDisplayEventEXT", "VK_EXT_display_surface_counter");
    if (!IsExtEnabled(device_extensions.vk_ext_display_control)) skip |= OutputExtensionError("vkRegisterDisplayEventEXT", "VK_EXT_display_control");
    skip |= ValidateRequiredHandle("vkRegisterDisplayEventEXT", "display", display);
    skip |= ValidateStructType("vkRegisterDisplayEventEXT", "pDisplayEventInfo", "VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT", pDisplayEventInfo, VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT, true, "VUID-vkRegisterDisplayEventEXT-pDisplayEventInfo-parameter", "VUID-VkDisplayEventInfoEXT-sType-sType");
    if (pDisplayEventInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkRegisterDisplayEventEXT", "pDisplayEventInfo->pNext", nullptr, pDisplayEventInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDisplayEventInfoEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum("vkRegisterDisplayEventEXT", "pDisplayEventInfo->displayEvent", "VkDisplayEventTypeEXT", pDisplayEventInfo->displayEvent, "VUID-VkDisplayEventInfoEXT-displayEvent-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkRegisterDisplayEventEXT-pAllocator-null", "vkRegisterDisplayEventEXT(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkRegisterDisplayEventEXT", "pFence", pFence, "VUID-vkRegisterDisplayEventEXT-pFence-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetSwapchainCounterEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    uint64_t*                                   pCounterValue) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkGetSwapchainCounterEXT", "VK_KHR_swapchain");
    if (!IsExtEnabled(device_extensions.vk_ext_display_surface_counter)) skip |= OutputExtensionError("vkGetSwapchainCounterEXT", "VK_EXT_display_surface_counter");
    if (!IsExtEnabled(device_extensions.vk_ext_display_control)) skip |= OutputExtensionError("vkGetSwapchainCounterEXT", "VK_EXT_display_control");
    skip |= ValidateRequiredHandle("vkGetSwapchainCounterEXT", "swapchain", swapchain);
    skip |= ValidateFlags("vkGetSwapchainCounterEXT", "counter", "VkSurfaceCounterFlagBitsEXT", AllVkSurfaceCounterFlagBitsEXT, counter, kRequiredSingleBit, "VUID-vkGetSwapchainCounterEXT-counter-parameter", "VUID-vkGetSwapchainCounterEXT-counter-parameter");
    skip |= ValidateRequiredPointer("vkGetSwapchainCounterEXT", "pCounterValue", pCounterValue, "VUID-vkGetSwapchainCounterEXT-pCounterValue-parameter");
    return skip;
}



bool StatelessValidation::PreCallValidateCmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_discard_rectangles) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetDiscardRectangleEXT", "VK_EXT_discard_rectangles && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateArray("vkCmdSetDiscardRectangleEXT", "discardRectangleCount", "pDiscardRectangles", discardRectangleCount, &pDiscardRectangles, true, true, "VUID-vkCmdSetDiscardRectangleEXT-discardRectangleCount-arraylength", "VUID-vkCmdSetDiscardRectangleEXT-pDiscardRectangles-parameter");
    if (pDiscardRectangles != nullptr)
    {
        for (uint32_t discardRectangleIndex = 0; discardRectangleIndex < discardRectangleCount; ++discardRectangleIndex)
        {
            // No xml-driven validation

            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDiscardRectangleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    discardRectangleEnable) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_discard_rectangles) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetDiscardRectangleEnableEXT", "VK_EXT_discard_rectangles && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateBool32("vkCmdSetDiscardRectangleEnableEXT", "discardRectangleEnable", discardRectangleEnable);
    if (!skip) skip |= manual_PreCallValidateCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDiscardRectangleModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_discard_rectangles) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetDiscardRectangleModeEXT", "VK_EXT_discard_rectangles && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateRangedEnum("vkCmdSetDiscardRectangleModeEXT", "discardRectangleMode", "VkDiscardRectangleModeEXT", discardRectangleMode, "VUID-vkCmdSetDiscardRectangleModeEXT-discardRectangleMode-parameter");
    if (!skip) skip |= manual_PreCallValidateCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
    return skip;
}









bool StatelessValidation::PreCallValidateSetHdrMetadataEXT(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainKHR*                       pSwapchains,
    const VkHdrMetadataEXT*                     pMetadata) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError("vkSetHdrMetadataEXT", "VK_KHR_swapchain");
    if (!IsExtEnabled(device_extensions.vk_ext_hdr_metadata)) skip |= OutputExtensionError("vkSetHdrMetadataEXT", "VK_EXT_hdr_metadata");
    skip |= ValidateHandleArray("vkSetHdrMetadataEXT", "swapchainCount", "pSwapchains", swapchainCount, pSwapchains, true, true, "VUID-vkSetHdrMetadataEXT-swapchainCount-arraylength");
    skip |= ValidateStructTypeArray("vkSetHdrMetadataEXT", "swapchainCount", "pMetadata", "VK_STRUCTURE_TYPE_HDR_METADATA_EXT", swapchainCount, pMetadata, VK_STRUCTURE_TYPE_HDR_METADATA_EXT, true, true, "VUID-VkHdrMetadataEXT-sType-sType", "VUID-vkSetHdrMetadataEXT-pMetadata-parameter", "VUID-vkSetHdrMetadataEXT-swapchainCount-arraylength");
    if (pMetadata != nullptr)
    {
        for (uint32_t swapchainIndex = 0; swapchainIndex < swapchainCount; ++swapchainIndex)
        {
            skip |= ValidateStructPnext("vkSetHdrMetadataEXT", ParameterName("pMetadata[%i].pNext", ParameterName::IndexVector{ swapchainIndex }), nullptr, pMetadata[swapchainIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkHdrMetadataEXT-pNext-pNext", kVUIDUndefined, false, true);
        }
    }
    return skip;
}







bool StatelessValidation::PreCallValidateSetDebugUtilsObjectNameEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectNameInfoEXT*        pNameInfo) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_ext_debug_utils)) skip |= OutputExtensionError("vkSetDebugUtilsObjectNameEXT", "VK_EXT_debug_utils");
    skip |= ValidateStructType("vkSetDebugUtilsObjectNameEXT", "pNameInfo", "VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT", pNameInfo, VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT, true, "VUID-vkSetDebugUtilsObjectNameEXT-pNameInfo-parameter", "VUID-VkDebugUtilsObjectNameInfoEXT-sType-sType");
    if (pNameInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkSetDebugUtilsObjectNameEXT", "pNameInfo->pNext", nullptr, pNameInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum("vkSetDebugUtilsObjectNameEXT", "pNameInfo->objectType", "VkObjectType", pNameInfo->objectType, "VUID-VkDebugUtilsObjectNameInfoEXT-objectType-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateSetDebugUtilsObjectNameEXT(device, pNameInfo);
    return skip;
}

bool StatelessValidation::PreCallValidateSetDebugUtilsObjectTagEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectTagInfoEXT*         pTagInfo) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_ext_debug_utils)) skip |= OutputExtensionError("vkSetDebugUtilsObjectTagEXT", "VK_EXT_debug_utils");
    skip |= ValidateStructType("vkSetDebugUtilsObjectTagEXT", "pTagInfo", "VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT", pTagInfo, VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT, true, "VUID-vkSetDebugUtilsObjectTagEXT-pTagInfo-parameter", "VUID-VkDebugUtilsObjectTagInfoEXT-sType-sType");
    if (pTagInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkSetDebugUtilsObjectTagEXT", "pTagInfo->pNext", nullptr, pTagInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDebugUtilsObjectTagInfoEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum("vkSetDebugUtilsObjectTagEXT", "pTagInfo->objectType", "VkObjectType", pTagInfo->objectType, "VUID-VkDebugUtilsObjectTagInfoEXT-objectType-parameter");

        skip |= ValidateArray("vkSetDebugUtilsObjectTagEXT", "pTagInfo->tagSize", "pTagInfo->pTag", pTagInfo->tagSize, &pTagInfo->pTag, true, true, "VUID-VkDebugUtilsObjectTagInfoEXT-tagSize-arraylength", "VUID-VkDebugUtilsObjectTagInfoEXT-pTag-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateSetDebugUtilsObjectTagEXT(device, pTagInfo);
    return skip;
}

bool StatelessValidation::PreCallValidateQueueBeginDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_ext_debug_utils)) skip |= OutputExtensionError("vkQueueBeginDebugUtilsLabelEXT", "VK_EXT_debug_utils");
    skip |= ValidateStructType("vkQueueBeginDebugUtilsLabelEXT", "pLabelInfo", "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT", pLabelInfo, VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, true, "VUID-vkQueueBeginDebugUtilsLabelEXT-pLabelInfo-parameter", "VUID-VkDebugUtilsLabelEXT-sType-sType");
    if (pLabelInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkQueueBeginDebugUtilsLabelEXT", "pLabelInfo->pNext", nullptr, pLabelInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDebugUtilsLabelEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredPointer("vkQueueBeginDebugUtilsLabelEXT", "pLabelInfo->pLabelName", pLabelInfo->pLabelName, "VUID-VkDebugUtilsLabelEXT-pLabelName-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateQueueEndDebugUtilsLabelEXT(
    VkQueue                                     queue) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_ext_debug_utils)) skip |= OutputExtensionError("vkQueueEndDebugUtilsLabelEXT", "VK_EXT_debug_utils");
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateQueueInsertDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_ext_debug_utils)) skip |= OutputExtensionError("vkQueueInsertDebugUtilsLabelEXT", "VK_EXT_debug_utils");
    skip |= ValidateStructType("vkQueueInsertDebugUtilsLabelEXT", "pLabelInfo", "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT", pLabelInfo, VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, true, "VUID-vkQueueInsertDebugUtilsLabelEXT-pLabelInfo-parameter", "VUID-VkDebugUtilsLabelEXT-sType-sType");
    if (pLabelInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkQueueInsertDebugUtilsLabelEXT", "pLabelInfo->pNext", nullptr, pLabelInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDebugUtilsLabelEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredPointer("vkQueueInsertDebugUtilsLabelEXT", "pLabelInfo->pLabelName", pLabelInfo->pLabelName, "VUID-VkDebugUtilsLabelEXT-pLabelName-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_ext_debug_utils)) skip |= OutputExtensionError("vkCmdBeginDebugUtilsLabelEXT", "VK_EXT_debug_utils");
    skip |= ValidateStructType("vkCmdBeginDebugUtilsLabelEXT", "pLabelInfo", "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT", pLabelInfo, VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, true, "VUID-vkCmdBeginDebugUtilsLabelEXT-pLabelInfo-parameter", "VUID-VkDebugUtilsLabelEXT-sType-sType");
    if (pLabelInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdBeginDebugUtilsLabelEXT", "pLabelInfo->pNext", nullptr, pLabelInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDebugUtilsLabelEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredPointer("vkCmdBeginDebugUtilsLabelEXT", "pLabelInfo->pLabelName", pLabelInfo->pLabelName, "VUID-VkDebugUtilsLabelEXT-pLabelName-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_ext_debug_utils)) skip |= OutputExtensionError("vkCmdEndDebugUtilsLabelEXT", "VK_EXT_debug_utils");
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) const {
    bool skip = false;
    if (!IsExtEnabled(device_extensions.vk_ext_debug_utils)) skip |= OutputExtensionError("vkCmdInsertDebugUtilsLabelEXT", "VK_EXT_debug_utils");
    skip |= ValidateStructType("vkCmdInsertDebugUtilsLabelEXT", "pLabelInfo", "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT", pLabelInfo, VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, true, "VUID-vkCmdInsertDebugUtilsLabelEXT-pLabelInfo-parameter", "VUID-VkDebugUtilsLabelEXT-sType-sType");
    if (pLabelInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdInsertDebugUtilsLabelEXT", "pLabelInfo->pNext", nullptr, pLabelInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDebugUtilsLabelEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredPointer("vkCmdInsertDebugUtilsLabelEXT", "pLabelInfo->pLabelName", pLabelInfo->pLabelName, "VUID-VkDebugUtilsLabelEXT-pLabelName-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    const VkDebugUtilsMessengerCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugUtilsMessengerEXT*                   pMessenger) const {
    bool skip = false;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError("vkCreateDebugUtilsMessengerEXT", "VK_EXT_debug_utils");
    skip |= ValidateStructType("vkCreateDebugUtilsMessengerEXT", "pCreateInfo", "VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT", pCreateInfo, VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT, true, "VUID-vkCreateDebugUtilsMessengerEXT-pCreateInfo-parameter", "VUID-VkDebugUtilsMessengerCreateInfoEXT-sType-sType");
    if (pCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCreateDebugUtilsMessengerEXT", "pCreateInfo->pNext", nullptr, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags("vkCreateDebugUtilsMessengerEXT", "pCreateInfo->flags", pCreateInfo->flags, "VUID-VkDebugUtilsMessengerCreateInfoEXT-flags-zerobitmask");

        skip |= ValidateFlags("vkCreateDebugUtilsMessengerEXT", "pCreateInfo->messageSeverity", "VkDebugUtilsMessageSeverityFlagBitsEXT", AllVkDebugUtilsMessageSeverityFlagBitsEXT, pCreateInfo->messageSeverity, kRequiredFlags, "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageSeverity-parameter", "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageSeverity-requiredbitmask");

        skip |= ValidateFlags("vkCreateDebugUtilsMessengerEXT", "pCreateInfo->messageType", "VkDebugUtilsMessageTypeFlagBitsEXT", AllVkDebugUtilsMessageTypeFlagBitsEXT, pCreateInfo->messageType, kRequiredFlags, "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageType-parameter", "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageType-requiredbitmask");

        skip |= ValidateRequiredPointer("vkCreateDebugUtilsMessengerEXT", "pCreateInfo->pfnUserCallback", reinterpret_cast<const void*>(pCreateInfo->pfnUserCallback), "VUID-VkDebugUtilsMessengerCreateInfoEXT-pfnUserCallback-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateDebugUtilsMessengerEXT-pAllocator-null", "vkCreateDebugUtilsMessengerEXT(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateDebugUtilsMessengerEXT", "pMessenger", pMessenger, "VUID-vkCreateDebugUtilsMessengerEXT-pMessenger-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessengerEXT                    messenger,
    const VkAllocationCallbacks*                pAllocator) const {
    bool skip = false;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError("vkDestroyDebugUtilsMessengerEXT", "VK_EXT_debug_utils");
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyDebugUtilsMessengerEXT-pAllocator-null", "vkDestroyDebugUtilsMessengerEXT(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateSubmitDebugUtilsMessageEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) const {
    bool skip = false;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError("vkSubmitDebugUtilsMessageEXT", "VK_EXT_debug_utils");
    skip |= ValidateFlags("vkSubmitDebugUtilsMessageEXT", "messageSeverity", "VkDebugUtilsMessageSeverityFlagBitsEXT", AllVkDebugUtilsMessageSeverityFlagBitsEXT, messageSeverity, kRequiredSingleBit, "VUID-vkSubmitDebugUtilsMessageEXT-messageSeverity-parameter", "VUID-vkSubmitDebugUtilsMessageEXT-messageSeverity-parameter");
    skip |= ValidateFlags("vkSubmitDebugUtilsMessageEXT", "messageTypes", "VkDebugUtilsMessageTypeFlagBitsEXT", AllVkDebugUtilsMessageTypeFlagBitsEXT, messageTypes, kRequiredFlags, "VUID-vkSubmitDebugUtilsMessageEXT-messageTypes-parameter", "VUID-vkSubmitDebugUtilsMessageEXT-messageTypes-requiredbitmask");
    skip |= ValidateStructType("vkSubmitDebugUtilsMessageEXT", "pCallbackData", "VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT", pCallbackData, VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT, true, "VUID-vkSubmitDebugUtilsMessageEXT-pCallbackData-parameter", "VUID-VkDebugUtilsMessengerCallbackDataEXT-sType-sType");
    if (pCallbackData != nullptr)
    {
        skip |= ValidateStructPnext("vkSubmitDebugUtilsMessageEXT", "pCallbackData->pNext", nullptr, pCallbackData->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDebugUtilsMessengerCallbackDataEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags("vkSubmitDebugUtilsMessageEXT", "pCallbackData->flags", pCallbackData->flags, "VUID-VkDebugUtilsMessengerCallbackDataEXT-flags-zerobitmask");

        skip |= ValidateRequiredPointer("vkSubmitDebugUtilsMessageEXT", "pCallbackData->pMessage", pCallbackData->pMessage, "VUID-VkDebugUtilsMessengerCallbackDataEXT-pMessage-parameter");

        skip |= ValidateStructTypeArray("vkSubmitDebugUtilsMessageEXT", "pCallbackData->queueLabelCount", "pCallbackData->pQueueLabels", "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT", pCallbackData->queueLabelCount, pCallbackData->pQueueLabels, VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, false, true, "VUID-VkDebugUtilsLabelEXT-sType-sType", "VUID-VkDebugUtilsMessengerCallbackDataEXT-pQueueLabels-parameter", kVUIDUndefined);

        if (pCallbackData->pQueueLabels != nullptr)
        {
            for (uint32_t queueLabelIndex = 0; queueLabelIndex < pCallbackData->queueLabelCount; ++queueLabelIndex)
            {
                skip |= ValidateStructPnext("vkSubmitDebugUtilsMessageEXT", ParameterName("pCallbackData->pQueueLabels[%i].pNext", ParameterName::IndexVector{ queueLabelIndex }), nullptr, pCallbackData->pQueueLabels[queueLabelIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDebugUtilsLabelEXT-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateRequiredPointer("vkSubmitDebugUtilsMessageEXT", ParameterName("pCallbackData->pQueueLabels[%i].pLabelName", ParameterName::IndexVector{ queueLabelIndex }), pCallbackData->pQueueLabels[queueLabelIndex].pLabelName, "VUID-VkDebugUtilsLabelEXT-pLabelName-parameter");
            }
        }

        skip |= ValidateStructTypeArray("vkSubmitDebugUtilsMessageEXT", "pCallbackData->cmdBufLabelCount", "pCallbackData->pCmdBufLabels", "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT", pCallbackData->cmdBufLabelCount, pCallbackData->pCmdBufLabels, VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, false, true, "VUID-VkDebugUtilsLabelEXT-sType-sType", "VUID-VkDebugUtilsMessengerCallbackDataEXT-pCmdBufLabels-parameter", kVUIDUndefined);

        if (pCallbackData->pCmdBufLabels != nullptr)
        {
            for (uint32_t cmdBufLabelIndex = 0; cmdBufLabelIndex < pCallbackData->cmdBufLabelCount; ++cmdBufLabelIndex)
            {
                skip |= ValidateStructPnext("vkSubmitDebugUtilsMessageEXT", ParameterName("pCallbackData->pCmdBufLabels[%i].pNext", ParameterName::IndexVector{ cmdBufLabelIndex }), nullptr, pCallbackData->pCmdBufLabels[cmdBufLabelIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkDebugUtilsLabelEXT-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateRequiredPointer("vkSubmitDebugUtilsMessageEXT", ParameterName("pCallbackData->pCmdBufLabels[%i].pLabelName", ParameterName::IndexVector{ cmdBufLabelIndex }), pCallbackData->pCmdBufLabels[cmdBufLabelIndex].pLabelName, "VUID-VkDebugUtilsLabelEXT-pLabelName-parameter");
            }
        }

        skip |= ValidateStructTypeArray("vkSubmitDebugUtilsMessageEXT", "pCallbackData->objectCount", "pCallbackData->pObjects", "VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT", pCallbackData->objectCount, pCallbackData->pObjects, VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT, false, true, "VUID-VkDebugUtilsObjectNameInfoEXT-sType-sType", "VUID-VkDebugUtilsMessengerCallbackDataEXT-pObjects-parameter", kVUIDUndefined);

        if (pCallbackData->pObjects != nullptr)
        {
            for (uint32_t objectIndex = 0; objectIndex < pCallbackData->objectCount; ++objectIndex)
            {
                skip |= ValidateStructPnext("vkSubmitDebugUtilsMessageEXT", ParameterName("pCallbackData->pObjects[%i].pNext", ParameterName::IndexVector{ objectIndex }), nullptr, pCallbackData->pObjects[objectIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                skip |= ValidateRangedEnum("vkSubmitDebugUtilsMessageEXT", ParameterName("pCallbackData->pObjects[%i].objectType", ParameterName::IndexVector{ objectIndex }), "VkObjectType", pCallbackData->pObjects[objectIndex].objectType, "VUID-VkDebugUtilsObjectNameInfoEXT-objectType-parameter");
            }
        }
    }
    return skip;
}





bool StatelessValidation::PreCallValidateCmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_sample_locations) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetSampleLocationsEXT", "VK_EXT_sample_locations && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructType("vkCmdSetSampleLocationsEXT", "pSampleLocationsInfo", "VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT", pSampleLocationsInfo, VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT, true, "VUID-vkCmdSetSampleLocationsEXT-pSampleLocationsInfo-parameter", "VUID-VkSampleLocationsInfoEXT-sType-sType");
    if (pSampleLocationsInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCmdSetSampleLocationsEXT", "pSampleLocationsInfo->pNext", nullptr, pSampleLocationsInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

        // No xml-driven validation

        skip |= ValidateArray("vkCmdSetSampleLocationsEXT", "pSampleLocationsInfo->sampleLocationsCount", "pSampleLocationsInfo->pSampleLocations", pSampleLocationsInfo->sampleLocationsCount, &pSampleLocationsInfo->pSampleLocations, false, true, kVUIDUndefined, "VUID-VkSampleLocationsInfoEXT-pSampleLocations-parameter");

        if (pSampleLocationsInfo->pSampleLocations != nullptr)
        {
            for (uint32_t sampleLocationsIndex = 0; sampleLocationsIndex < pSampleLocationsInfo->sampleLocationsCount; ++sampleLocationsIndex)
            {
                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceMultisamplePropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    VkMultisamplePropertiesEXT*                 pMultisampleProperties) const {
    bool skip = false;
    skip |= ValidateFlags("vkGetPhysicalDeviceMultisamplePropertiesEXT", "samples", "VkSampleCountFlagBits", AllVkSampleCountFlagBits, samples, kRequiredSingleBit, "VUID-vkGetPhysicalDeviceMultisamplePropertiesEXT-samples-parameter", "VUID-vkGetPhysicalDeviceMultisamplePropertiesEXT-samples-parameter");
    skip |= ValidateStructType("vkGetPhysicalDeviceMultisamplePropertiesEXT", "pMultisampleProperties", "VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT", pMultisampleProperties, VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT, true, "VUID-vkGetPhysicalDeviceMultisamplePropertiesEXT-pMultisampleProperties-parameter", "VUID-VkMultisamplePropertiesEXT-sType-sType");
    if (pMultisampleProperties != nullptr)
    {
        skip |= ValidateStructPnext("vkGetPhysicalDeviceMultisamplePropertiesEXT", "pMultisampleProperties->pNext", nullptr, pMultisampleProperties->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkMultisamplePropertiesEXT-pNext-pNext", kVUIDUndefined, true, false);
    }
    return skip;
}







bool StatelessValidation::PreCallValidateGetImageDrmFormatModifierPropertiesEXT(
    VkDevice                                    device,
    VkImage                                     image,
    VkImageDrmFormatModifierPropertiesEXT*      pProperties) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_2) skip |= OutputExtensionError("vkGetImageDrmFormatModifierPropertiesEXT", "VK_VERSION_1_2");
    if (!IsExtEnabled(device_extensions.vk_khr_image_format_list)) skip |= OutputExtensionError("vkGetImageDrmFormatModifierPropertiesEXT", "VK_KHR_image_format_list");
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkGetImageDrmFormatModifierPropertiesEXT", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_khr_sampler_ycbcr_conversion)) skip |= OutputExtensionError("vkGetImageDrmFormatModifierPropertiesEXT", "VK_KHR_sampler_ycbcr_conversion");
    if (!IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2)) skip |= OutputExtensionError("vkGetImageDrmFormatModifierPropertiesEXT", "VK_KHR_get_physical_device_properties2");
    if (!IsExtEnabled(device_extensions.vk_khr_bind_memory2)) skip |= OutputExtensionError("vkGetImageDrmFormatModifierPropertiesEXT", "VK_KHR_bind_memory2");
    if (!IsExtEnabled(device_extensions.vk_ext_image_drm_format_modifier)) skip |= OutputExtensionError("vkGetImageDrmFormatModifierPropertiesEXT", "VK_EXT_image_drm_format_modifier");
    skip |= ValidateRequiredHandle("vkGetImageDrmFormatModifierPropertiesEXT", "image", image);
    skip |= ValidateStructType("vkGetImageDrmFormatModifierPropertiesEXT", "pProperties", "VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT", pProperties, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT, true, "VUID-vkGetImageDrmFormatModifierPropertiesEXT-pProperties-parameter", "VUID-VkImageDrmFormatModifierPropertiesEXT-sType-sType");
    if (pProperties != nullptr)
    {
        skip |= ValidateStructPnext("vkGetImageDrmFormatModifierPropertiesEXT", "pProperties->pNext", nullptr, pProperties->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkImageDrmFormatModifierPropertiesEXT-pNext-pNext", kVUIDUndefined, false, false);
    }
    return skip;
}







bool StatelessValidation::PreCallValidateGetMemoryHostPointerPropertiesEXT(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    const void*                                 pHostPointer,
    VkMemoryHostPointerPropertiesEXT*           pMemoryHostPointerProperties) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_external_memory_host) && (IsExtEnabled(device_extensions.vk_khr_external_memory) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkGetMemoryHostPointerPropertiesEXT", "VK_EXT_external_memory_host && (VK_KHR_external_memory || VK_VERSION_1_1)");
    skip |= ValidateFlags("vkGetMemoryHostPointerPropertiesEXT", "handleType", "VkExternalMemoryHandleTypeFlagBits", AllVkExternalMemoryHandleTypeFlagBits, handleType, kRequiredSingleBit, "VUID-vkGetMemoryHostPointerPropertiesEXT-handleType-parameter", "VUID-vkGetMemoryHostPointerPropertiesEXT-handleType-parameter");
    skip |= ValidateRequiredPointer("vkGetMemoryHostPointerPropertiesEXT", "pHostPointer", pHostPointer, kVUIDUndefined);
    skip |= ValidateStructType("vkGetMemoryHostPointerPropertiesEXT", "pMemoryHostPointerProperties", "VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT", pMemoryHostPointerProperties, VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT, true, "VUID-vkGetMemoryHostPointerPropertiesEXT-pMemoryHostPointerProperties-parameter", "VUID-VkMemoryHostPointerPropertiesEXT-sType-sType");
    if (pMemoryHostPointerProperties != nullptr)
    {
        skip |= ValidateStructPnext("vkGetMemoryHostPointerPropertiesEXT", "pMemoryHostPointerProperties->pNext", nullptr, pMemoryHostPointerProperties->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkMemoryHostPointerPropertiesEXT-pNext-pNext", kVUIDUndefined, false, false);
    }
    return skip;
}



bool StatelessValidation::PreCallValidateGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pTimeDomainCount,
    VkTimeDomainEXT*                            pTimeDomains) const {
    bool skip = false;
    skip |= ValidateArray("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", "pTimeDomainCount", "pTimeDomains", pTimeDomainCount, &pTimeDomains, true, false, false, kVUIDUndefined, "VUID-vkGetPhysicalDeviceCalibrateableTimeDomainsEXT-pTimeDomains-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetCalibratedTimestampsEXT(
    VkDevice                                    device,
    uint32_t                                    timestampCount,
    const VkCalibratedTimestampInfoEXT*         pTimestampInfos,
    uint64_t*                                   pTimestamps,
    uint64_t*                                   pMaxDeviation) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_calibrated_timestamps) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkGetCalibratedTimestampsEXT", "VK_EXT_calibrated_timestamps && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructTypeArray("vkGetCalibratedTimestampsEXT", "timestampCount", "pTimestampInfos", "VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT", timestampCount, pTimestampInfos, VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT, true, true, "VUID-VkCalibratedTimestampInfoEXT-sType-sType", "VUID-vkGetCalibratedTimestampsEXT-pTimestampInfos-parameter", "VUID-vkGetCalibratedTimestampsEXT-timestampCount-arraylength");
    if (pTimestampInfos != nullptr)
    {
        for (uint32_t timestampIndex = 0; timestampIndex < timestampCount; ++timestampIndex)
        {
            skip |= ValidateStructPnext("vkGetCalibratedTimestampsEXT", ParameterName("pTimestampInfos[%i].pNext", ParameterName::IndexVector{ timestampIndex }), nullptr, pTimestampInfos[timestampIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkCalibratedTimestampInfoEXT-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateRangedEnum("vkGetCalibratedTimestampsEXT", ParameterName("pTimestampInfos[%i].timeDomain", ParameterName::IndexVector{ timestampIndex }), "VkTimeDomainEXT", pTimestampInfos[timestampIndex].timeDomain, "VUID-VkCalibratedTimestampInfoEXT-timeDomain-parameter");
        }
    }
    skip |= ValidateArray("vkGetCalibratedTimestampsEXT", "timestampCount", "pTimestamps", timestampCount, &pTimestamps, true, true, "VUID-vkGetCalibratedTimestampsEXT-timestampCount-arraylength", "VUID-vkGetCalibratedTimestampsEXT-pTimestamps-parameter");
    skip |= ValidateRequiredPointer("vkGetCalibratedTimestampsEXT", "pMaxDeviation", pMaxDeviation, "VUID-vkGetCalibratedTimestampsEXT-pMaxDeviation-parameter");
    return skip;
}



















bool StatelessValidation::PreCallValidateCreateHeadlessSurfaceEXT(
    VkInstance                                  instance,
    const VkHeadlessSurfaceCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface) const {
    bool skip = false;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError("vkCreateHeadlessSurfaceEXT", "VK_KHR_surface");
    if (!instance_extensions.vk_ext_headless_surface) skip |= OutputExtensionError("vkCreateHeadlessSurfaceEXT", "VK_EXT_headless_surface");
    skip |= ValidateStructType("vkCreateHeadlessSurfaceEXT", "pCreateInfo", "VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT", pCreateInfo, VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT, true, "VUID-vkCreateHeadlessSurfaceEXT-pCreateInfo-parameter", "VUID-VkHeadlessSurfaceCreateInfoEXT-sType-sType");
    if (pCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCreateHeadlessSurfaceEXT", "pCreateInfo->pNext", nullptr, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkHeadlessSurfaceCreateInfoEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags("vkCreateHeadlessSurfaceEXT", "pCreateInfo->flags", pCreateInfo->flags, "VUID-VkHeadlessSurfaceCreateInfoEXT-flags-zerobitmask");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateHeadlessSurfaceEXT-pAllocator-null", "vkCreateHeadlessSurfaceEXT(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateHeadlessSurfaceEXT", "pSurface", pSurface, "VUID-vkCreateHeadlessSurfaceEXT-pSurface-parameter");
    return skip;
}



bool StatelessValidation::PreCallValidateCmdSetLineStippleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_line_rasterization) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetLineStippleEXT", "VK_EXT_line_rasterization && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    // No xml-driven validation
    if (!skip) skip |= manual_PreCallValidateCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    return skip;
}







bool StatelessValidation::PreCallValidateCmdSetCullModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetCullModeEXT", "VK_EXT_extended_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateFlags("vkCmdSetCullModeEXT", "cullMode", "VkCullModeFlagBits", AllVkCullModeFlagBits, cullMode, kOptionalFlags, "VUID-vkCmdSetCullMode-cullMode-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetFrontFaceEXT(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetFrontFaceEXT", "VK_EXT_extended_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateRangedEnum("vkCmdSetFrontFaceEXT", "frontFace", "VkFrontFace", frontFace, "VUID-vkCmdSetFrontFace-frontFace-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetPrimitiveTopologyEXT(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetPrimitiveTopologyEXT", "VK_EXT_extended_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateRangedEnum("vkCmdSetPrimitiveTopologyEXT", "primitiveTopology", "VkPrimitiveTopology", primitiveTopology, "VUID-vkCmdSetPrimitiveTopology-primitiveTopology-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetViewportWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetViewportWithCountEXT", "VK_EXT_extended_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateArray("vkCmdSetViewportWithCountEXT", "viewportCount", "pViewports", viewportCount, &pViewports, true, true, "VUID-vkCmdSetViewportWithCount-viewportCount-arraylength", "VUID-vkCmdSetViewportWithCount-pViewports-parameter");
    if (pViewports != nullptr)
    {
        for (uint32_t viewportIndex = 0; viewportIndex < viewportCount; ++viewportIndex)
        {
            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetScissorWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetScissorWithCountEXT", "VK_EXT_extended_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateArray("vkCmdSetScissorWithCountEXT", "scissorCount", "pScissors", scissorCount, &pScissors, true, true, "VUID-vkCmdSetScissorWithCount-scissorCount-arraylength", "VUID-vkCmdSetScissorWithCount-pScissors-parameter");
    if (pScissors != nullptr)
    {
        for (uint32_t scissorIndex = 0; scissorIndex < scissorCount; ++scissorIndex)
        {
            // No xml-driven validation

            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBindVertexBuffers2EXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdBindVertexBuffers2EXT", "VK_EXT_extended_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    // No xml-driven validation
    if (!skip) skip |= manual_PreCallValidateCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetDepthTestEnableEXT", "VK_EXT_extended_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateBool32("vkCmdSetDepthTestEnableEXT", "depthTestEnable", depthTestEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetDepthWriteEnableEXT", "VK_EXT_extended_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateBool32("vkCmdSetDepthWriteEnableEXT", "depthWriteEnable", depthWriteEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthCompareOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetDepthCompareOpEXT", "VK_EXT_extended_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateRangedEnum("vkCmdSetDepthCompareOpEXT", "depthCompareOp", "VkCompareOp", depthCompareOp, "VUID-vkCmdSetDepthCompareOp-depthCompareOp-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthBoundsTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetDepthBoundsTestEnableEXT", "VK_EXT_extended_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateBool32("vkCmdSetDepthBoundsTestEnableEXT", "depthBoundsTestEnable", depthBoundsTestEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetStencilTestEnableEXT", "VK_EXT_extended_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateBool32("vkCmdSetStencilTestEnableEXT", "stencilTestEnable", stencilTestEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetStencilOpEXT", "VK_EXT_extended_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateFlags("vkCmdSetStencilOpEXT", "faceMask", "VkStencilFaceFlagBits", AllVkStencilFaceFlagBits, faceMask, kRequiredFlags, "VUID-vkCmdSetStencilOp-faceMask-parameter", "VUID-vkCmdSetStencilOp-faceMask-requiredbitmask");
    skip |= ValidateRangedEnum("vkCmdSetStencilOpEXT", "failOp", "VkStencilOp", failOp, "VUID-vkCmdSetStencilOp-failOp-parameter");
    skip |= ValidateRangedEnum("vkCmdSetStencilOpEXT", "passOp", "VkStencilOp", passOp, "VUID-vkCmdSetStencilOp-passOp-parameter");
    skip |= ValidateRangedEnum("vkCmdSetStencilOpEXT", "depthFailOp", "VkStencilOp", depthFailOp, "VUID-vkCmdSetStencilOp-depthFailOp-parameter");
    skip |= ValidateRangedEnum("vkCmdSetStencilOpEXT", "compareOp", "VkCompareOp", compareOp, "VUID-vkCmdSetStencilOp-compareOp-parameter");
    return skip;
}

















bool StatelessValidation::PreCallValidateCmdSetVertexInputEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT*  pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_vertex_input_dynamic_state) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetVertexInputEXT", "VK_EXT_vertex_input_dynamic_state && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateStructTypeArray("vkCmdSetVertexInputEXT", "vertexBindingDescriptionCount", "pVertexBindingDescriptions", "VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT", vertexBindingDescriptionCount, pVertexBindingDescriptions, VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT, false, true, "VUID-VkVertexInputBindingDescription2EXT-sType-sType", "VUID-vkCmdSetVertexInputEXT-pVertexBindingDescriptions-parameter", kVUIDUndefined);
    if (pVertexBindingDescriptions != nullptr)
    {
        for (uint32_t vertexBindingDescriptionIndex = 0; vertexBindingDescriptionIndex < vertexBindingDescriptionCount; ++vertexBindingDescriptionIndex)
        {
            skip |= ValidateRangedEnum("vkCmdSetVertexInputEXT", ParameterName("pVertexBindingDescriptions[%i].inputRate", ParameterName::IndexVector{ vertexBindingDescriptionIndex }), "VkVertexInputRate", pVertexBindingDescriptions[vertexBindingDescriptionIndex].inputRate, "VUID-VkVertexInputBindingDescription2EXT-inputRate-parameter");
        }
    }
    skip |= ValidateStructTypeArray("vkCmdSetVertexInputEXT", "vertexAttributeDescriptionCount", "pVertexAttributeDescriptions", "VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT", vertexAttributeDescriptionCount, pVertexAttributeDescriptions, VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT, false, true, "VUID-VkVertexInputAttributeDescription2EXT-sType-sType", "VUID-vkCmdSetVertexInputEXT-pVertexAttributeDescriptions-parameter", kVUIDUndefined);
    if (pVertexAttributeDescriptions != nullptr)
    {
        for (uint32_t vertexAttributeDescriptionIndex = 0; vertexAttributeDescriptionIndex < vertexAttributeDescriptionCount; ++vertexAttributeDescriptionIndex)
        {
            skip |= ValidateRangedEnum("vkCmdSetVertexInputEXT", ParameterName("pVertexAttributeDescriptions[%i].format", ParameterName::IndexVector{ vertexAttributeDescriptionIndex }), "VkFormat", pVertexAttributeDescriptions[vertexAttributeDescriptionIndex].format, "VUID-VkVertexInputAttributeDescription2EXT-format-parameter");
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    return skip;
}



#ifdef VK_USE_PLATFORM_SCI

bool StatelessValidation::PreCallValidateGetFenceSciSyncFenceNV(
    VkDevice                                    device,
    const VkFenceGetSciSyncInfoNV*              pGetSciSyncHandleInfo,
    void*                                       pHandle) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkGetFenceSciSyncFenceNV", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_nv_external_sci_sync)) skip |= OutputExtensionError("vkGetFenceSciSyncFenceNV", "VK_NV_external_sci_sync");
    skip |= ValidateStructType("vkGetFenceSciSyncFenceNV", "pGetSciSyncHandleInfo", "VK_STRUCTURE_TYPE_FENCE_GET_SCI_SYNC_INFO_NV", pGetSciSyncHandleInfo, VK_STRUCTURE_TYPE_FENCE_GET_SCI_SYNC_INFO_NV, true, "VUID-vkGetFenceSciSyncFenceNV-pGetSciSyncHandleInfo-parameter", "VUID-VkFenceGetSciSyncInfoNV-sType-sType");
    if (pGetSciSyncHandleInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetFenceSciSyncFenceNV", "pGetSciSyncHandleInfo->pNext", nullptr, pGetSciSyncHandleInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkFenceGetSciSyncInfoNV-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkGetFenceSciSyncFenceNV", "pGetSciSyncHandleInfo->fence", pGetSciSyncHandleInfo->fence);

        skip |= ValidateFlags("vkGetFenceSciSyncFenceNV", "pGetSciSyncHandleInfo->handleType", "VkExternalFenceHandleTypeFlagBits", AllVkExternalFenceHandleTypeFlagBits, pGetSciSyncHandleInfo->handleType, kRequiredSingleBit, "VUID-VkFenceGetSciSyncInfoNV-handleType-parameter", "VUID-VkFenceGetSciSyncInfoNV-handleType-parameter");
    }
    skip |= ValidateRequiredPointer("vkGetFenceSciSyncFenceNV", "pHandle", pHandle, "VUID-vkGetFenceSciSyncFenceNV-pHandle-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetFenceSciSyncObjNV(
    VkDevice                                    device,
    const VkFenceGetSciSyncInfoNV*              pGetSciSyncHandleInfo,
    void*                                       pHandle) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkGetFenceSciSyncObjNV", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_nv_external_sci_sync)) skip |= OutputExtensionError("vkGetFenceSciSyncObjNV", "VK_NV_external_sci_sync");
    skip |= ValidateStructType("vkGetFenceSciSyncObjNV", "pGetSciSyncHandleInfo", "VK_STRUCTURE_TYPE_FENCE_GET_SCI_SYNC_INFO_NV", pGetSciSyncHandleInfo, VK_STRUCTURE_TYPE_FENCE_GET_SCI_SYNC_INFO_NV, true, "VUID-vkGetFenceSciSyncObjNV-pGetSciSyncHandleInfo-parameter", "VUID-VkFenceGetSciSyncInfoNV-sType-sType");
    if (pGetSciSyncHandleInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetFenceSciSyncObjNV", "pGetSciSyncHandleInfo->pNext", nullptr, pGetSciSyncHandleInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkFenceGetSciSyncInfoNV-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkGetFenceSciSyncObjNV", "pGetSciSyncHandleInfo->fence", pGetSciSyncHandleInfo->fence);

        skip |= ValidateFlags("vkGetFenceSciSyncObjNV", "pGetSciSyncHandleInfo->handleType", "VkExternalFenceHandleTypeFlagBits", AllVkExternalFenceHandleTypeFlagBits, pGetSciSyncHandleInfo->handleType, kRequiredSingleBit, "VUID-VkFenceGetSciSyncInfoNV-handleType-parameter", "VUID-VkFenceGetSciSyncInfoNV-handleType-parameter");
    }
    skip |= ValidateRequiredPointer("vkGetFenceSciSyncObjNV", "pHandle", pHandle, "VUID-vkGetFenceSciSyncObjNV-pHandle-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateImportFenceSciSyncFenceNV(
    VkDevice                                    device,
    const VkImportFenceSciSyncInfoNV*           pImportFenceSciSyncInfo) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkImportFenceSciSyncFenceNV", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_nv_external_sci_sync)) skip |= OutputExtensionError("vkImportFenceSciSyncFenceNV", "VK_NV_external_sci_sync");
    skip |= ValidateStructType("vkImportFenceSciSyncFenceNV", "pImportFenceSciSyncInfo", "VK_STRUCTURE_TYPE_IMPORT_FENCE_SCI_SYNC_INFO_NV", pImportFenceSciSyncInfo, VK_STRUCTURE_TYPE_IMPORT_FENCE_SCI_SYNC_INFO_NV, true, "VUID-vkImportFenceSciSyncFenceNV-pImportFenceSciSyncInfo-parameter", "VUID-VkImportFenceSciSyncInfoNV-sType-sType");
    if (pImportFenceSciSyncInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkImportFenceSciSyncFenceNV", "pImportFenceSciSyncInfo->pNext", nullptr, pImportFenceSciSyncInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkImportFenceSciSyncInfoNV-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkImportFenceSciSyncFenceNV", "pImportFenceSciSyncInfo->fence", pImportFenceSciSyncInfo->fence);

        skip |= ValidateFlags("vkImportFenceSciSyncFenceNV", "pImportFenceSciSyncInfo->handleType", "VkExternalFenceHandleTypeFlagBits", AllVkExternalFenceHandleTypeFlagBits, pImportFenceSciSyncInfo->handleType, kRequiredSingleBit, "VUID-VkImportFenceSciSyncInfoNV-handleType-parameter", "VUID-VkImportFenceSciSyncInfoNV-handleType-parameter");

        skip |= ValidateRequiredPointer("vkImportFenceSciSyncFenceNV", "pImportFenceSciSyncInfo->handle", pImportFenceSciSyncInfo->handle, "VUID-VkImportFenceSciSyncInfoNV-handle-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateImportFenceSciSyncObjNV(
    VkDevice                                    device,
    const VkImportFenceSciSyncInfoNV*           pImportFenceSciSyncInfo) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkImportFenceSciSyncObjNV", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_nv_external_sci_sync)) skip |= OutputExtensionError("vkImportFenceSciSyncObjNV", "VK_NV_external_sci_sync");
    skip |= ValidateStructType("vkImportFenceSciSyncObjNV", "pImportFenceSciSyncInfo", "VK_STRUCTURE_TYPE_IMPORT_FENCE_SCI_SYNC_INFO_NV", pImportFenceSciSyncInfo, VK_STRUCTURE_TYPE_IMPORT_FENCE_SCI_SYNC_INFO_NV, true, "VUID-vkImportFenceSciSyncObjNV-pImportFenceSciSyncInfo-parameter", "VUID-VkImportFenceSciSyncInfoNV-sType-sType");
    if (pImportFenceSciSyncInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkImportFenceSciSyncObjNV", "pImportFenceSciSyncInfo->pNext", nullptr, pImportFenceSciSyncInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkImportFenceSciSyncInfoNV-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkImportFenceSciSyncObjNV", "pImportFenceSciSyncInfo->fence", pImportFenceSciSyncInfo->fence);

        skip |= ValidateFlags("vkImportFenceSciSyncObjNV", "pImportFenceSciSyncInfo->handleType", "VkExternalFenceHandleTypeFlagBits", AllVkExternalFenceHandleTypeFlagBits, pImportFenceSciSyncInfo->handleType, kRequiredSingleBit, "VUID-VkImportFenceSciSyncInfoNV-handleType-parameter", "VUID-VkImportFenceSciSyncInfoNV-handleType-parameter");

        skip |= ValidateRequiredPointer("vkImportFenceSciSyncObjNV", "pImportFenceSciSyncInfo->handle", pImportFenceSciSyncInfo->handle, "VUID-VkImportFenceSciSyncInfoNV-handle-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSciSyncAttributesNV(
    VkPhysicalDevice                            physicalDevice,
    const VkSciSyncAttributesInfoNV*            pSciSyncAttributesInfo,
    NvSciSyncAttrList                           pAttributes) const {
    bool skip = false;
    skip |= ValidateStructType("vkGetPhysicalDeviceSciSyncAttributesNV", "pSciSyncAttributesInfo", "VK_STRUCTURE_TYPE_SCI_SYNC_ATTRIBUTES_INFO_NV", pSciSyncAttributesInfo, VK_STRUCTURE_TYPE_SCI_SYNC_ATTRIBUTES_INFO_NV, true, "VUID-vkGetPhysicalDeviceSciSyncAttributesNV-pSciSyncAttributesInfo-parameter", "VUID-VkSciSyncAttributesInfoNV-sType-sType");
    if (pSciSyncAttributesInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetPhysicalDeviceSciSyncAttributesNV", "pSciSyncAttributesInfo->pNext", nullptr, pSciSyncAttributesInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSciSyncAttributesInfoNV-pNext-pNext", kVUIDUndefined, true, true);

        skip |= ValidateRangedEnum("vkGetPhysicalDeviceSciSyncAttributesNV", "pSciSyncAttributesInfo->clientType", "VkSciSyncClientTypeNV", pSciSyncAttributesInfo->clientType, "VUID-VkSciSyncAttributesInfoNV-clientType-parameter");

        skip |= ValidateRangedEnum("vkGetPhysicalDeviceSciSyncAttributesNV", "pSciSyncAttributesInfo->primitiveType", "VkSciSyncPrimitiveTypeNV", pSciSyncAttributesInfo->primitiveType, "VUID-VkSciSyncAttributesInfoNV-primitiveType-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetSemaphoreSciSyncObjNV(
    VkDevice                                    device,
    const VkSemaphoreGetSciSyncInfoNV*          pGetSciSyncInfo,
    void*                                       pHandle) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkGetSemaphoreSciSyncObjNV", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_nv_external_sci_sync)) skip |= OutputExtensionError("vkGetSemaphoreSciSyncObjNV", "VK_NV_external_sci_sync");
    skip |= ValidateStructType("vkGetSemaphoreSciSyncObjNV", "pGetSciSyncInfo", "VK_STRUCTURE_TYPE_SEMAPHORE_GET_SCI_SYNC_INFO_NV", pGetSciSyncInfo, VK_STRUCTURE_TYPE_SEMAPHORE_GET_SCI_SYNC_INFO_NV, true, "VUID-vkGetSemaphoreSciSyncObjNV-pGetSciSyncInfo-parameter", "VUID-VkSemaphoreGetSciSyncInfoNV-sType-sType");
    if (pGetSciSyncInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetSemaphoreSciSyncObjNV", "pGetSciSyncInfo->pNext", nullptr, pGetSciSyncInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSemaphoreGetSciSyncInfoNV-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkGetSemaphoreSciSyncObjNV", "pGetSciSyncInfo->semaphore", pGetSciSyncInfo->semaphore);

        skip |= ValidateFlags("vkGetSemaphoreSciSyncObjNV", "pGetSciSyncInfo->handleType", "VkExternalSemaphoreHandleTypeFlagBits", AllVkExternalSemaphoreHandleTypeFlagBits, pGetSciSyncInfo->handleType, kRequiredSingleBit, "VUID-VkSemaphoreGetSciSyncInfoNV-handleType-parameter", "VUID-VkSemaphoreGetSciSyncInfoNV-handleType-parameter");
    }
    skip |= ValidateRequiredPointer("vkGetSemaphoreSciSyncObjNV", "pHandle", pHandle, "VUID-vkGetSemaphoreSciSyncObjNV-pHandle-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateImportSemaphoreSciSyncObjNV(
    VkDevice                                    device,
    const VkImportSemaphoreSciSyncInfoNV*       pImportSemaphoreSciSyncInfo) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkImportSemaphoreSciSyncObjNV", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_nv_external_sci_sync)) skip |= OutputExtensionError("vkImportSemaphoreSciSyncObjNV", "VK_NV_external_sci_sync");
    skip |= ValidateStructType("vkImportSemaphoreSciSyncObjNV", "pImportSemaphoreSciSyncInfo", "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_SCI_SYNC_INFO_NV", pImportSemaphoreSciSyncInfo, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_SCI_SYNC_INFO_NV, true, "VUID-vkImportSemaphoreSciSyncObjNV-pImportSemaphoreSciSyncInfo-parameter", "VUID-VkImportSemaphoreSciSyncInfoNV-sType-sType");
    if (pImportSemaphoreSciSyncInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkImportSemaphoreSciSyncObjNV", "pImportSemaphoreSciSyncInfo->pNext", nullptr, pImportSemaphoreSciSyncInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkImportSemaphoreSciSyncInfoNV-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkImportSemaphoreSciSyncObjNV", "pImportSemaphoreSciSyncInfo->semaphore", pImportSemaphoreSciSyncInfo->semaphore);

        skip |= ValidateFlags("vkImportSemaphoreSciSyncObjNV", "pImportSemaphoreSciSyncInfo->handleType", "VkExternalSemaphoreHandleTypeFlagBits", AllVkExternalSemaphoreHandleTypeFlagBits, pImportSemaphoreSciSyncInfo->handleType, kRequiredSingleBit, "VUID-VkImportSemaphoreSciSyncInfoNV-handleType-parameter", "VUID-VkImportSemaphoreSciSyncInfoNV-handleType-parameter");

        skip |= ValidateRequiredPointer("vkImportSemaphoreSciSyncObjNV", "pImportSemaphoreSciSyncInfo->handle", pImportSemaphoreSciSyncInfo->handle, "VUID-VkImportSemaphoreSciSyncInfoNV-handle-parameter");
    }
    return skip;
}

#endif // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCI

bool StatelessValidation::PreCallValidateGetMemorySciBufNV(
    VkDevice                                    device,
    const VkMemoryGetSciBufInfoNV*              pGetSciBufInfo,
    NvSciBufObj*                                pHandle) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkGetMemorySciBufNV", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_nv_external_memory_sci_buf)) skip |= OutputExtensionError("vkGetMemorySciBufNV", "VK_NV_external_memory_sci_buf");
    skip |= ValidateStructType("vkGetMemorySciBufNV", "pGetSciBufInfo", "VK_STRUCTURE_TYPE_MEMORY_GET_SCI_BUF_INFO_NV", pGetSciBufInfo, VK_STRUCTURE_TYPE_MEMORY_GET_SCI_BUF_INFO_NV, true, "VUID-vkGetMemorySciBufNV-pGetSciBufInfo-parameter", "VUID-VkMemoryGetSciBufInfoNV-sType-sType");
    if (pGetSciBufInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkGetMemorySciBufNV", "pGetSciBufInfo->pNext", nullptr, pGetSciBufInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkMemoryGetSciBufInfoNV-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle("vkGetMemorySciBufNV", "pGetSciBufInfo->memory", pGetSciBufInfo->memory);

        skip |= ValidateFlags("vkGetMemorySciBufNV", "pGetSciBufInfo->handleType", "VkExternalMemoryHandleTypeFlagBits", AllVkExternalMemoryHandleTypeFlagBits, pGetSciBufInfo->handleType, kRequiredSingleBit, "VUID-VkMemoryGetSciBufInfoNV-handleType-parameter", "VUID-VkMemoryGetSciBufInfoNV-handleType-parameter");
    }
    skip |= ValidateRequiredPointer("vkGetMemorySciBufNV", "pHandle", pHandle, "VUID-vkGetMemorySciBufNV-pHandle-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceExternalMemorySciBufPropertiesNV(
    VkPhysicalDevice                            physicalDevice,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    NvSciBufObj                                 handle,
    VkMemorySciBufPropertiesNV*                 pMemorySciBufProperties) const {
    bool skip = false;
    skip |= ValidateFlags("vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV", "handleType", "VkExternalMemoryHandleTypeFlagBits", AllVkExternalMemoryHandleTypeFlagBits, handleType, kRequiredSingleBit, "VUID-vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV-handleType-parameter", "VUID-vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV-handleType-parameter");
    skip |= ValidateStructType("vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV", "pMemorySciBufProperties", "VK_STRUCTURE_TYPE_MEMORY_SCI_BUF_PROPERTIES_NV", pMemorySciBufProperties, VK_STRUCTURE_TYPE_MEMORY_SCI_BUF_PROPERTIES_NV, true, "VUID-vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV-pMemorySciBufProperties-parameter", "VUID-VkMemorySciBufPropertiesNV-sType-sType");
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSciBufAttributesNV(
    VkPhysicalDevice                            physicalDevice,
    NvSciBufAttrList                            pAttributes) const {
    bool skip = false;
    // No xml-driven validation
    return skip;
}

#endif // VK_USE_PLATFORM_SCI

bool StatelessValidation::PreCallValidateCmdSetPatchControlPointsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    patchControlPoints) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetPatchControlPointsEXT", "VK_EXT_extended_dynamic_state2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetRasterizerDiscardEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetRasterizerDiscardEnableEXT", "VK_EXT_extended_dynamic_state2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateBool32("vkCmdSetRasterizerDiscardEnableEXT", "rasterizerDiscardEnable", rasterizerDiscardEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthBiasEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetDepthBiasEnableEXT", "VK_EXT_extended_dynamic_state2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateBool32("vkCmdSetDepthBiasEnableEXT", "depthBiasEnable", depthBiasEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetLogicOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkLogicOp                                   logicOp) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetLogicOpEXT", "VK_EXT_extended_dynamic_state2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateRangedEnum("vkCmdSetLogicOpEXT", "logicOp", "VkLogicOp", logicOp, "VUID-vkCmdSetLogicOpEXT-logicOp-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetPrimitiveRestartEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state2) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetPrimitiveRestartEnableEXT", "VK_EXT_extended_dynamic_state2 && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateBool32("vkCmdSetPrimitiveRestartEnableEXT", "primitiveRestartEnable", primitiveRestartEnable);
    return skip;
}



bool StatelessValidation::PreCallValidateCmdSetColorWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorWriteEnables) const {
    bool skip = false;
    if (!(IsExtEnabled(device_extensions.vk_ext_color_write_enable) && (IsExtEnabled(device_extensions.vk_khr_get_physical_device_properties2) || instance_extensions.vk_feature_version_1_1))) skip |= OutputExtensionError("vkCmdSetColorWriteEnableEXT", "VK_EXT_color_write_enable && (VK_KHR_get_physical_device_properties2 || VK_VERSION_1_1)");
    skip |= ValidateBool32Array("vkCmdSetColorWriteEnableEXT", "attachmentCount", "pColorWriteEnables", attachmentCount, pColorWriteEnables, true, true);
    return skip;
}





#ifdef VK_USE_PLATFORM_SCI

bool StatelessValidation::PreCallValidateCreateSemaphoreSciSyncPoolNV(
    VkDevice                                    device,
    const VkSemaphoreSciSyncPoolCreateInfoNV*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphoreSciSyncPoolNV*                   pSemaphorePool) const {
    bool skip = false;
    if (!instance_extensions.vk_feature_version_1_1) skip |= OutputExtensionError("vkCreateSemaphoreSciSyncPoolNV", "VK_VERSION_1_1");
    if (!IsExtEnabled(device_extensions.vk_nv_external_sci_sync2)) skip |= OutputExtensionError("vkCreateSemaphoreSciSyncPoolNV", "VK_NV_external_sci_sync2");
    skip |= ValidateStructType("vkCreateSemaphoreSciSyncPoolNV", "pCreateInfo", "VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_POOL_CREATE_INFO_NV", pCreateInfo, VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_POOL_CREATE_INFO_NV, true, "VUID-vkCreateSemaphoreSciSyncPoolNV-pCreateInfo-parameter", "VUID-VkSemaphoreSciSyncPoolCreateInfoNV-sType-sType");
    if (pCreateInfo != nullptr)
    {
        skip |= ValidateStructPnext("vkCreateSemaphoreSciSyncPoolNV", "pCreateInfo->pNext", nullptr, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSemaphoreSciSyncPoolCreateInfoNV-pNext-pNext", kVUIDUndefined, false, true);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateSemaphoreSciSyncPoolNV-pAllocator-null", "vkCreateSemaphoreSciSyncPoolNV(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer("vkCreateSemaphoreSciSyncPoolNV", "pSemaphorePool", pSemaphorePool, "VUID-vkCreateSemaphoreSciSyncPoolNV-pSemaphorePool-parameter");
    return skip;
}

#endif // VK_USE_PLATFORM_SCI

