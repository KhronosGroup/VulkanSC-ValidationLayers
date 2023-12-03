// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See stateless_validation_helper_generator.py for modifications

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

#include "stateless/stateless_validation.h"
#include "enum_flag_bits.h"

#include <vulkan/layer/vk_layer_settings_ext.h>

bool StatelessValidation::ValidatePnextStructContents(const Location& loc, const VkBaseOutStructure* header, const char* pnext_vuid,
                                                      bool is_physdev_api, bool is_const_param) const {
    bool skip = false;
    switch (header->sType) {
        // Validation code for VkPhysicalDeviceSubgroupProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES: {  // Covers VUID-VkPhysicalDeviceSubgroupProperties-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES) "
                                 "which was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDevice16BitStorageFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES: {  // Covers
                                                                          // VUID-VkPhysicalDevice16BitStorageFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES) "
                             "which was added in VK_API_VERSION_1_1 but the "
                             "current effective API version is %s.",
                             StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDevice16BitStorageFeatures);
                VkPhysicalDevice16BitStorageFeatures* structure = (VkPhysicalDevice16BitStorageFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::storageBuffer16BitAccess), structure->storageBuffer16BitAccess);

                skip |= ValidateBool32(pNext_loc.dot(Field::uniformAndStorageBuffer16BitAccess),
                                       structure->uniformAndStorageBuffer16BitAccess);

                skip |= ValidateBool32(pNext_loc.dot(Field::storagePushConstant16), structure->storagePushConstant16);

                skip |= ValidateBool32(pNext_loc.dot(Field::storageInputOutput16), structure->storageInputOutput16);
            }
        } break;

        // Validation code for VkMemoryDedicatedRequirements structure members
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS: {  // Covers VUID-VkMemoryDedicatedRequirements-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS) which "
                                 "was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkMemoryDedicatedAllocateInfo structure members
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO: {  // Covers VUID-VkMemoryDedicatedAllocateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO) which "
                                 "was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkMemoryAllocateFlagsInfo structure members
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO: {  // Covers VUID-VkMemoryAllocateFlagsInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO) which was "
                                 "added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkMemoryAllocateFlagsInfo);
                VkMemoryAllocateFlagsInfo* structure = (VkMemoryAllocateFlagsInfo*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::flags), "VkMemoryAllocateFlagBits", AllVkMemoryAllocateFlagBits,
                                      structure->flags, kOptionalFlags, "VUID-VkMemoryAllocateFlagsInfo-flags-parameter");
            }
        } break;

        // Validation code for VkDeviceGroupRenderPassBeginInfo structure members
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO: {  // Covers VUID-VkDeviceGroupRenderPassBeginInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO) "
                                 "which was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkDeviceGroupRenderPassBeginInfo);
                VkDeviceGroupRenderPassBeginInfo* structure = (VkDeviceGroupRenderPassBeginInfo*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::deviceRenderAreaCount), pNext_loc.dot(Field::pDeviceRenderAreas),
                                      structure->deviceRenderAreaCount, &structure->pDeviceRenderAreas, false, true, kVUIDUndefined,
                                      "VUID-VkDeviceGroupRenderPassBeginInfo-pDeviceRenderAreas-parameter");

                if (structure->pDeviceRenderAreas != nullptr) {
                    for (uint32_t deviceRenderAreaIndex = 0; deviceRenderAreaIndex < structure->deviceRenderAreaCount;
                         ++deviceRenderAreaIndex) {
                        [[maybe_unused]] const Location pDeviceRenderAreas_loc =
                            pNext_loc.dot(Field::pDeviceRenderAreas, deviceRenderAreaIndex);
                    }
                }
            }
        } break;

        // Validation code for VkDeviceGroupCommandBufferBeginInfo structure members
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO: {  // Covers
                                                                          // VUID-VkDeviceGroupCommandBufferBeginInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO) "
                             "which was added in VK_API_VERSION_1_1 but the "
                             "current effective API version is %s.",
                             StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkDeviceGroupSubmitInfo structure members
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO: {  // Covers VUID-VkDeviceGroupSubmitInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO) which was "
                                 "added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkDeviceGroupSubmitInfo);
                VkDeviceGroupSubmitInfo* structure = (VkDeviceGroupSubmitInfo*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::waitSemaphoreCount), pNext_loc.dot(Field::pWaitSemaphoreDeviceIndices),
                                      structure->waitSemaphoreCount, &structure->pWaitSemaphoreDeviceIndices, false, true,
                                      kVUIDUndefined, "VUID-VkDeviceGroupSubmitInfo-pWaitSemaphoreDeviceIndices-parameter");

                skip |= ValidateArray(pNext_loc.dot(Field::commandBufferCount), pNext_loc.dot(Field::pCommandBufferDeviceMasks),
                                      structure->commandBufferCount, &structure->pCommandBufferDeviceMasks, false, true,
                                      kVUIDUndefined, "VUID-VkDeviceGroupSubmitInfo-pCommandBufferDeviceMasks-parameter");

                skip |=
                    ValidateArray(pNext_loc.dot(Field::signalSemaphoreCount), pNext_loc.dot(Field::pSignalSemaphoreDeviceIndices),
                                  structure->signalSemaphoreCount, &structure->pSignalSemaphoreDeviceIndices, false, true,
                                  kVUIDUndefined, "VUID-VkDeviceGroupSubmitInfo-pSignalSemaphoreDeviceIndices-parameter");
            }
        } break;

        // Validation code for VkBindBufferMemoryDeviceGroupInfo structure members
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO: {  // Covers VUID-VkBindBufferMemoryDeviceGroupInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO) "
                                 "which was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkBindBufferMemoryDeviceGroupInfo);
                VkBindBufferMemoryDeviceGroupInfo* structure = (VkBindBufferMemoryDeviceGroupInfo*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::deviceIndexCount), pNext_loc.dot(Field::pDeviceIndices),
                                      structure->deviceIndexCount, &structure->pDeviceIndices, false, true, kVUIDUndefined,
                                      "VUID-VkBindBufferMemoryDeviceGroupInfo-pDeviceIndices-parameter");
            }
        } break;

        // Validation code for VkBindImageMemoryDeviceGroupInfo structure members
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO: {  // Covers VUID-VkBindImageMemoryDeviceGroupInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO) "
                                 "which was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkBindImageMemoryDeviceGroupInfo);
                VkBindImageMemoryDeviceGroupInfo* structure = (VkBindImageMemoryDeviceGroupInfo*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::deviceIndexCount), pNext_loc.dot(Field::pDeviceIndices),
                                      structure->deviceIndexCount, &structure->pDeviceIndices, false, true, kVUIDUndefined,
                                      "VUID-VkBindImageMemoryDeviceGroupInfo-pDeviceIndices-parameter");

                skip |= ValidateArray(pNext_loc.dot(Field::splitInstanceBindRegionCount),
                                      pNext_loc.dot(Field::pSplitInstanceBindRegions), structure->splitInstanceBindRegionCount,
                                      &structure->pSplitInstanceBindRegions, false, true, kVUIDUndefined,
                                      "VUID-VkBindImageMemoryDeviceGroupInfo-pSplitInstanceBindRegions-parameter");

                if (structure->pSplitInstanceBindRegions != nullptr) {
                    for (uint32_t splitInstanceBindRegionIndex = 0;
                         splitInstanceBindRegionIndex < structure->splitInstanceBindRegionCount; ++splitInstanceBindRegionIndex) {
                        [[maybe_unused]] const Location pSplitInstanceBindRegions_loc =
                            pNext_loc.dot(Field::pSplitInstanceBindRegions, splitInstanceBindRegionIndex);
                    }
                }
            }
        } break;

        // Validation code for VkDeviceGroupDeviceCreateInfo structure members
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO: {  // Covers VUID-VkDeviceGroupDeviceCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO) "
                                 "which was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkDeviceGroupDeviceCreateInfo);
                VkDeviceGroupDeviceCreateInfo* structure = (VkDeviceGroupDeviceCreateInfo*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::physicalDeviceCount), pNext_loc.dot(Field::pPhysicalDevices),
                                      structure->physicalDeviceCount, &structure->pPhysicalDevices, false, true, kVUIDUndefined,
                                      "VUID-VkDeviceGroupDeviceCreateInfo-pPhysicalDevices-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceFeatures2 structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2: {  // Covers VUID-VkPhysicalDeviceFeatures2-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2) which was "
                                 "added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceFeatures2);
                VkPhysicalDeviceFeatures2* structure = (VkPhysicalDeviceFeatures2*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::robustBufferAccess), structure->features.robustBufferAccess);

                skip |= ValidateBool32(pNext_loc.dot(Field::fullDrawIndexUint32), structure->features.fullDrawIndexUint32);

                skip |= ValidateBool32(pNext_loc.dot(Field::imageCubeArray), structure->features.imageCubeArray);

                skip |= ValidateBool32(pNext_loc.dot(Field::independentBlend), structure->features.independentBlend);

                skip |= ValidateBool32(pNext_loc.dot(Field::geometryShader), structure->features.geometryShader);

                skip |= ValidateBool32(pNext_loc.dot(Field::tessellationShader), structure->features.tessellationShader);

                skip |= ValidateBool32(pNext_loc.dot(Field::sampleRateShading), structure->features.sampleRateShading);

                skip |= ValidateBool32(pNext_loc.dot(Field::dualSrcBlend), structure->features.dualSrcBlend);

                skip |= ValidateBool32(pNext_loc.dot(Field::logicOp), structure->features.logicOp);

                skip |= ValidateBool32(pNext_loc.dot(Field::multiDrawIndirect), structure->features.multiDrawIndirect);

                skip |=
                    ValidateBool32(pNext_loc.dot(Field::drawIndirectFirstInstance), structure->features.drawIndirectFirstInstance);

                skip |= ValidateBool32(pNext_loc.dot(Field::depthClamp), structure->features.depthClamp);

                skip |= ValidateBool32(pNext_loc.dot(Field::depthBiasClamp), structure->features.depthBiasClamp);

                skip |= ValidateBool32(pNext_loc.dot(Field::fillModeNonSolid), structure->features.fillModeNonSolid);

                skip |= ValidateBool32(pNext_loc.dot(Field::depthBounds), structure->features.depthBounds);

                skip |= ValidateBool32(pNext_loc.dot(Field::wideLines), structure->features.wideLines);

                skip |= ValidateBool32(pNext_loc.dot(Field::largePoints), structure->features.largePoints);

                skip |= ValidateBool32(pNext_loc.dot(Field::alphaToOne), structure->features.alphaToOne);

                skip |= ValidateBool32(pNext_loc.dot(Field::multiViewport), structure->features.multiViewport);

                skip |= ValidateBool32(pNext_loc.dot(Field::samplerAnisotropy), structure->features.samplerAnisotropy);

                skip |= ValidateBool32(pNext_loc.dot(Field::textureCompressionETC2), structure->features.textureCompressionETC2);

                skip |= ValidateBool32(pNext_loc.dot(Field::textureCompressionASTC_LDR),
                                       structure->features.textureCompressionASTC_LDR);

                skip |= ValidateBool32(pNext_loc.dot(Field::textureCompressionBC), structure->features.textureCompressionBC);

                skip |= ValidateBool32(pNext_loc.dot(Field::occlusionQueryPrecise), structure->features.occlusionQueryPrecise);

                skip |= ValidateBool32(pNext_loc.dot(Field::pipelineStatisticsQuery), structure->features.pipelineStatisticsQuery);

                skip |= ValidateBool32(pNext_loc.dot(Field::vertexPipelineStoresAndAtomics),
                                       structure->features.vertexPipelineStoresAndAtomics);

                skip |=
                    ValidateBool32(pNext_loc.dot(Field::fragmentStoresAndAtomics), structure->features.fragmentStoresAndAtomics);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderTessellationAndGeometryPointSize),
                                       structure->features.shaderTessellationAndGeometryPointSize);

                skip |=
                    ValidateBool32(pNext_loc.dot(Field::shaderImageGatherExtended), structure->features.shaderImageGatherExtended);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageImageExtendedFormats),
                                       structure->features.shaderStorageImageExtendedFormats);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageImageMultisample),
                                       structure->features.shaderStorageImageMultisample);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageImageReadWithoutFormat),
                                       structure->features.shaderStorageImageReadWithoutFormat);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageImageWriteWithoutFormat),
                                       structure->features.shaderStorageImageWriteWithoutFormat);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderUniformBufferArrayDynamicIndexing),
                                       structure->features.shaderUniformBufferArrayDynamicIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderSampledImageArrayDynamicIndexing),
                                       structure->features.shaderSampledImageArrayDynamicIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageBufferArrayDynamicIndexing),
                                       structure->features.shaderStorageBufferArrayDynamicIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageImageArrayDynamicIndexing),
                                       structure->features.shaderStorageImageArrayDynamicIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderClipDistance), structure->features.shaderClipDistance);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderCullDistance), structure->features.shaderCullDistance);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderFloat64), structure->features.shaderFloat64);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderInt64), structure->features.shaderInt64);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderInt16), structure->features.shaderInt16);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderResourceResidency), structure->features.shaderResourceResidency);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderResourceMinLod), structure->features.shaderResourceMinLod);

                skip |= ValidateBool32(pNext_loc.dot(Field::sparseBinding), structure->features.sparseBinding);

                skip |= ValidateBool32(pNext_loc.dot(Field::sparseResidencyBuffer), structure->features.sparseResidencyBuffer);

                skip |= ValidateBool32(pNext_loc.dot(Field::sparseResidencyImage2D), structure->features.sparseResidencyImage2D);

                skip |= ValidateBool32(pNext_loc.dot(Field::sparseResidencyImage3D), structure->features.sparseResidencyImage3D);

                skip |= ValidateBool32(pNext_loc.dot(Field::sparseResidency2Samples), structure->features.sparseResidency2Samples);

                skip |= ValidateBool32(pNext_loc.dot(Field::sparseResidency4Samples), structure->features.sparseResidency4Samples);

                skip |= ValidateBool32(pNext_loc.dot(Field::sparseResidency8Samples), structure->features.sparseResidency8Samples);

                skip |=
                    ValidateBool32(pNext_loc.dot(Field::sparseResidency16Samples), structure->features.sparseResidency16Samples);

                skip |= ValidateBool32(pNext_loc.dot(Field::sparseResidencyAliased), structure->features.sparseResidencyAliased);

                skip |= ValidateBool32(pNext_loc.dot(Field::variableMultisampleRate), structure->features.variableMultisampleRate);

                skip |= ValidateBool32(pNext_loc.dot(Field::inheritedQueries), structure->features.inheritedQueries);
            }
        } break;

        // Validation code for VkPhysicalDevicePointClippingProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES: {  // Covers
                                                                             // VUID-VkPhysicalDevicePointClippingProperties-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES) which "
                    "was added in VK_API_VERSION_1_1 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkRenderPassInputAttachmentAspectCreateInfo structure members
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO: {  // Covers
                                                                                   // VUID-VkRenderPassInputAttachmentAspectCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO) "
                    "which was added in VK_API_VERSION_1_1 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkRenderPassInputAttachmentAspectCreateInfo);
                VkRenderPassInputAttachmentAspectCreateInfo* structure = (VkRenderPassInputAttachmentAspectCreateInfo*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::aspectReferenceCount), pNext_loc.dot(Field::pAspectReferences),
                                      structure->aspectReferenceCount, &structure->pAspectReferences, true, true,
                                      "VUID-VkRenderPassInputAttachmentAspectCreateInfo-aspectReferenceCount-arraylength",
                                      "VUID-VkRenderPassInputAttachmentAspectCreateInfo-pAspectReferences-parameter");

                if (structure->pAspectReferences != nullptr) {
                    for (uint32_t aspectReferenceIndex = 0; aspectReferenceIndex < structure->aspectReferenceCount;
                         ++aspectReferenceIndex) {
                        [[maybe_unused]] const Location pAspectReferences_loc =
                            pNext_loc.dot(Field::pAspectReferences, aspectReferenceIndex);
                        skip |=
                            ValidateFlags(pAspectReferences_loc.dot(Field::aspectMask), "VkImageAspectFlagBits",
                                          AllVkImageAspectFlagBits, structure->pAspectReferences[aspectReferenceIndex].aspectMask,
                                          kRequiredFlags, "VUID-VkInputAttachmentAspectReference-aspectMask-parameter",
                                          "VUID-VkInputAttachmentAspectReference-aspectMask-requiredbitmask");
                    }
                }
            }
        } break;

        // Validation code for VkImageViewUsageCreateInfo structure members
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO: {  // Covers VUID-VkImageViewUsageCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO) which "
                                 "was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkImageViewUsageCreateInfo);
                VkImageViewUsageCreateInfo* structure = (VkImageViewUsageCreateInfo*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::usage), "VkImageUsageFlagBits", AllVkImageUsageFlagBits,
                                      structure->usage, kRequiredFlags, "VUID-VkImageViewUsageCreateInfo-usage-parameter",
                                      "VUID-VkImageViewUsageCreateInfo-usage-requiredbitmask");
            }
        } break;

        // Validation code for VkPipelineTessellationDomainOriginStateCreateInfo structure members
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO: {  // Covers
                                                                                         // VUID-VkPipelineTessellationDomainOriginStateCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO) which was added in "
                                 "VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPipelineTessellationDomainOriginStateCreateInfo);
                VkPipelineTessellationDomainOriginStateCreateInfo* structure =
                    (VkPipelineTessellationDomainOriginStateCreateInfo*)header;
                skip |=
                    ValidateRangedEnum(pNext_loc.dot(Field::domainOrigin), "VkTessellationDomainOrigin", structure->domainOrigin,
                                       "VUID-VkPipelineTessellationDomainOriginStateCreateInfo-domainOrigin-parameter");
            }
        } break;

        // Validation code for VkRenderPassMultiviewCreateInfo structure members
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO: {  // Covers VUID-VkRenderPassMultiviewCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO) "
                                 "which was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkRenderPassMultiviewCreateInfo);
                VkRenderPassMultiviewCreateInfo* structure = (VkRenderPassMultiviewCreateInfo*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::subpassCount), pNext_loc.dot(Field::pViewMasks), structure->subpassCount,
                                      &structure->pViewMasks, false, true, kVUIDUndefined,
                                      "VUID-VkRenderPassMultiviewCreateInfo-pViewMasks-parameter");

                skip |= ValidateArray(pNext_loc.dot(Field::dependencyCount), pNext_loc.dot(Field::pViewOffsets),
                                      structure->dependencyCount, &structure->pViewOffsets, false, true, kVUIDUndefined,
                                      "VUID-VkRenderPassMultiviewCreateInfo-pViewOffsets-parameter");

                skip |= ValidateArray(pNext_loc.dot(Field::correlationMaskCount), pNext_loc.dot(Field::pCorrelationMasks),
                                      structure->correlationMaskCount, &structure->pCorrelationMasks, false, true, kVUIDUndefined,
                                      "VUID-VkRenderPassMultiviewCreateInfo-pCorrelationMasks-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceMultiviewFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES: {  // Covers VUID-VkPhysicalDeviceMultiviewFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES) "
                                 "which was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceMultiviewFeatures);
                VkPhysicalDeviceMultiviewFeatures* structure = (VkPhysicalDeviceMultiviewFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::multiview), structure->multiview);

                skip |= ValidateBool32(pNext_loc.dot(Field::multiviewGeometryShader), structure->multiviewGeometryShader);

                skip |= ValidateBool32(pNext_loc.dot(Field::multiviewTessellationShader), structure->multiviewTessellationShader);
            }
        } break;

        // Validation code for VkPhysicalDeviceMultiviewProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES: {  // Covers
                                                                        // VUID-VkPhysicalDeviceMultiviewProperties-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES) "
                                 "which was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceVariablePointersFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES: {  // Covers
                                                                              // VUID-VkPhysicalDeviceVariablePointersFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES) which "
                    "was added in VK_API_VERSION_1_1 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceVariablePointersFeatures);
                VkPhysicalDeviceVariablePointersFeatures* structure = (VkPhysicalDeviceVariablePointersFeatures*)header;
                skip |=
                    ValidateBool32(pNext_loc.dot(Field::variablePointersStorageBuffer), structure->variablePointersStorageBuffer);

                skip |= ValidateBool32(pNext_loc.dot(Field::variablePointers), structure->variablePointers);
            }
        } break;

        // Validation code for VkPhysicalDeviceProtectedMemoryFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES: {  // Covers
                                                                             // VUID-VkPhysicalDeviceProtectedMemoryFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES) which "
                    "was added in VK_API_VERSION_1_1 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceProtectedMemoryFeatures);
                VkPhysicalDeviceProtectedMemoryFeatures* structure = (VkPhysicalDeviceProtectedMemoryFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::protectedMemory), structure->protectedMemory);
            }
        } break;

        // Validation code for VkPhysicalDeviceProtectedMemoryProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES: {  // Covers
                                                                               // VUID-VkPhysicalDeviceProtectedMemoryProperties-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES) which "
                    "was added in VK_API_VERSION_1_1 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkProtectedSubmitInfo structure members
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO: {  // Covers VUID-VkProtectedSubmitInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO) which was "
                                 "added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkProtectedSubmitInfo);
                VkProtectedSubmitInfo* structure = (VkProtectedSubmitInfo*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::protectedSubmit), structure->protectedSubmit);
            }
        } break;

        // Validation code for VkSamplerYcbcrConversionInfo structure members
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO: {  // Covers VUID-VkSamplerYcbcrConversionInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO) which "
                                 "was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkSamplerYcbcrConversionInfo);
                VkSamplerYcbcrConversionInfo* structure = (VkSamplerYcbcrConversionInfo*)header;
                skip |= ValidateRequiredHandle(pNext_loc.dot(Field::conversion), structure->conversion);
            }
        } break;

        // Validation code for VkBindImagePlaneMemoryInfo structure members
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO: {  // Covers VUID-VkBindImagePlaneMemoryInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO) which "
                                 "was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkBindImagePlaneMemoryInfo);
                VkBindImagePlaneMemoryInfo* structure = (VkBindImagePlaneMemoryInfo*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::planeAspect), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                      structure->planeAspect, kRequiredSingleBit,
                                      "VUID-VkBindImagePlaneMemoryInfo-planeAspect-parameter",
                                      "VUID-VkBindImagePlaneMemoryInfo-planeAspect-parameter");
            }
        } break;

        // Validation code for VkImagePlaneMemoryRequirementsInfo structure members
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO: {  // Covers
                                                                        // VUID-VkImagePlaneMemoryRequirementsInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO) "
                                 "which was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkImagePlaneMemoryRequirementsInfo);
                VkImagePlaneMemoryRequirementsInfo* structure = (VkImagePlaneMemoryRequirementsInfo*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::planeAspect), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                      structure->planeAspect, kRequiredSingleBit,
                                      "VUID-VkImagePlaneMemoryRequirementsInfo-planeAspect-parameter",
                                      "VUID-VkImagePlaneMemoryRequirementsInfo-planeAspect-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceSamplerYcbcrConversionFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES: {  // Covers
                                                                                     // VUID-VkPhysicalDeviceSamplerYcbcrConversionFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES) "
                    "which was added in VK_API_VERSION_1_1 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceSamplerYcbcrConversionFeatures);
                VkPhysicalDeviceSamplerYcbcrConversionFeatures* structure = (VkPhysicalDeviceSamplerYcbcrConversionFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::samplerYcbcrConversion), structure->samplerYcbcrConversion);
            }
        } break;

        // Validation code for VkSamplerYcbcrConversionImageFormatProperties structure members
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES: {  // Covers
                                                                                    // VUID-VkSamplerYcbcrConversionImageFormatProperties-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES) "
                    "which was added in VK_API_VERSION_1_1 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceExternalImageFormatInfo structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO: {  // Covers
                                                                              // VUID-VkPhysicalDeviceExternalImageFormatInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO) which "
                    "was added in VK_API_VERSION_1_1 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceExternalImageFormatInfo);
                VkPhysicalDeviceExternalImageFormatInfo* structure = (VkPhysicalDeviceExternalImageFormatInfo*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::handleType), "VkExternalMemoryHandleTypeFlagBits",
                                      AllVkExternalMemoryHandleTypeFlagBits, structure->handleType, kOptionalSingleBit,
                                      "VUID-VkPhysicalDeviceExternalImageFormatInfo-handleType-parameter");
            }
        } break;

        // Validation code for VkExternalImageFormatProperties structure members
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES: {  // Covers VUID-VkExternalImageFormatProperties-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES) "
                                 "which was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceIDProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES: {  // Covers VUID-VkPhysicalDeviceIDProperties-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES) which "
                                 "was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkExternalMemoryImageCreateInfo structure members
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO: {  // Covers VUID-VkExternalMemoryImageCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO) "
                                 "which was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkExternalMemoryImageCreateInfo);
                VkExternalMemoryImageCreateInfo* structure = (VkExternalMemoryImageCreateInfo*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::handleTypes), "VkExternalMemoryHandleTypeFlagBits",
                                      AllVkExternalMemoryHandleTypeFlagBits, structure->handleTypes, kOptionalFlags,
                                      "VUID-VkExternalMemoryImageCreateInfo-handleTypes-parameter");
            }
        } break;

        // Validation code for VkExternalMemoryBufferCreateInfo structure members
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO: {  // Covers VUID-VkExternalMemoryBufferCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO) "
                                 "which was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkExternalMemoryBufferCreateInfo);
                VkExternalMemoryBufferCreateInfo* structure = (VkExternalMemoryBufferCreateInfo*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::handleTypes), "VkExternalMemoryHandleTypeFlagBits",
                                      AllVkExternalMemoryHandleTypeFlagBits, structure->handleTypes, kOptionalFlags,
                                      "VUID-VkExternalMemoryBufferCreateInfo-handleTypes-parameter");
            }
        } break;

        // Validation code for VkExportMemoryAllocateInfo structure members
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO: {  // Covers VUID-VkExportMemoryAllocateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO) which "
                                 "was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkExportMemoryAllocateInfo);
                VkExportMemoryAllocateInfo* structure = (VkExportMemoryAllocateInfo*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::handleTypes), "VkExternalMemoryHandleTypeFlagBits",
                                      AllVkExternalMemoryHandleTypeFlagBits, structure->handleTypes, kOptionalFlags,
                                      "VUID-VkExportMemoryAllocateInfo-handleTypes-parameter");
            }
        } break;

        // Validation code for VkExportFenceCreateInfo structure members
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO: {  // Covers VUID-VkExportFenceCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO) which was "
                                 "added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkExportFenceCreateInfo);
                VkExportFenceCreateInfo* structure = (VkExportFenceCreateInfo*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::handleTypes), "VkExternalFenceHandleTypeFlagBits",
                                      AllVkExternalFenceHandleTypeFlagBits, structure->handleTypes, kOptionalFlags,
                                      "VUID-VkExportFenceCreateInfo-handleTypes-parameter");
            }
        } break;

        // Validation code for VkExportSemaphoreCreateInfo structure members
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO: {  // Covers VUID-VkExportSemaphoreCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO) which "
                                 "was added in VK_API_VERSION_1_1 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkExportSemaphoreCreateInfo);
                VkExportSemaphoreCreateInfo* structure = (VkExportSemaphoreCreateInfo*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::handleTypes), "VkExternalSemaphoreHandleTypeFlagBits",
                                      AllVkExternalSemaphoreHandleTypeFlagBits, structure->handleTypes, kOptionalFlags,
                                      "VUID-VkExportSemaphoreCreateInfo-handleTypes-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceMaintenance3Properties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES: {  // Covers
                                                                            // VUID-VkPhysicalDeviceMaintenance3Properties-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES) "
                             "which was added in VK_API_VERSION_1_1 but the "
                             "current effective API version is %s.",
                             StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderDrawParametersFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES: {  // Covers
                                                                                   // VUID-VkPhysicalDeviceShaderDrawParametersFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_1) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES) "
                    "which was added in VK_API_VERSION_1_1 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceShaderDrawParametersFeatures);
                VkPhysicalDeviceShaderDrawParametersFeatures* structure = (VkPhysicalDeviceShaderDrawParametersFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::shaderDrawParameters), structure->shaderDrawParameters);
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkan11Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {  // Covers VUID-VkPhysicalDeviceVulkan11Features-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES) "
                                 "which was added in VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceVulkan11Features);
                VkPhysicalDeviceVulkan11Features* structure = (VkPhysicalDeviceVulkan11Features*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::storageBuffer16BitAccess), structure->storageBuffer16BitAccess);

                skip |= ValidateBool32(pNext_loc.dot(Field::uniformAndStorageBuffer16BitAccess),
                                       structure->uniformAndStorageBuffer16BitAccess);

                skip |= ValidateBool32(pNext_loc.dot(Field::storagePushConstant16), structure->storagePushConstant16);

                skip |= ValidateBool32(pNext_loc.dot(Field::storageInputOutput16), structure->storageInputOutput16);

                skip |= ValidateBool32(pNext_loc.dot(Field::multiview), structure->multiview);

                skip |= ValidateBool32(pNext_loc.dot(Field::multiviewGeometryShader), structure->multiviewGeometryShader);

                skip |= ValidateBool32(pNext_loc.dot(Field::multiviewTessellationShader), structure->multiviewTessellationShader);

                skip |=
                    ValidateBool32(pNext_loc.dot(Field::variablePointersStorageBuffer), structure->variablePointersStorageBuffer);

                skip |= ValidateBool32(pNext_loc.dot(Field::variablePointers), structure->variablePointers);

                skip |= ValidateBool32(pNext_loc.dot(Field::protectedMemory), structure->protectedMemory);

                skip |= ValidateBool32(pNext_loc.dot(Field::samplerYcbcrConversion), structure->samplerYcbcrConversion);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderDrawParameters), structure->shaderDrawParameters);
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkan11Properties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: {  // Covers
                                                                         // VUID-VkPhysicalDeviceVulkan11Properties-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES) "
                             "which was added in VK_API_VERSION_1_2 but the "
                             "current effective API version is %s.",
                             StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkan12Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {  // Covers VUID-VkPhysicalDeviceVulkan12Features-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES) "
                                 "which was added in VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceVulkan12Features);
                VkPhysicalDeviceVulkan12Features* structure = (VkPhysicalDeviceVulkan12Features*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::samplerMirrorClampToEdge), structure->samplerMirrorClampToEdge);

                skip |= ValidateBool32(pNext_loc.dot(Field::drawIndirectCount), structure->drawIndirectCount);

                skip |= ValidateBool32(pNext_loc.dot(Field::storageBuffer8BitAccess), structure->storageBuffer8BitAccess);

                skip |= ValidateBool32(pNext_loc.dot(Field::uniformAndStorageBuffer8BitAccess),
                                       structure->uniformAndStorageBuffer8BitAccess);

                skip |= ValidateBool32(pNext_loc.dot(Field::storagePushConstant8), structure->storagePushConstant8);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderBufferInt64Atomics), structure->shaderBufferInt64Atomics);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderSharedInt64Atomics), structure->shaderSharedInt64Atomics);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderFloat16), structure->shaderFloat16);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderInt8), structure->shaderInt8);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorIndexing), structure->descriptorIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderInputAttachmentArrayDynamicIndexing),
                                       structure->shaderInputAttachmentArrayDynamicIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderUniformTexelBufferArrayDynamicIndexing),
                                       structure->shaderUniformTexelBufferArrayDynamicIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageTexelBufferArrayDynamicIndexing),
                                       structure->shaderStorageTexelBufferArrayDynamicIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderUniformBufferArrayNonUniformIndexing),
                                       structure->shaderUniformBufferArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderSampledImageArrayNonUniformIndexing),
                                       structure->shaderSampledImageArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageBufferArrayNonUniformIndexing),
                                       structure->shaderStorageBufferArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageImageArrayNonUniformIndexing),
                                       structure->shaderStorageImageArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderInputAttachmentArrayNonUniformIndexing),
                                       structure->shaderInputAttachmentArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderUniformTexelBufferArrayNonUniformIndexing),
                                       structure->shaderUniformTexelBufferArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageTexelBufferArrayNonUniformIndexing),
                                       structure->shaderStorageTexelBufferArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingUniformBufferUpdateAfterBind),
                                       structure->descriptorBindingUniformBufferUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingSampledImageUpdateAfterBind),
                                       structure->descriptorBindingSampledImageUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingStorageImageUpdateAfterBind),
                                       structure->descriptorBindingStorageImageUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingStorageBufferUpdateAfterBind),
                                       structure->descriptorBindingStorageBufferUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingUniformTexelBufferUpdateAfterBind),
                                       structure->descriptorBindingUniformTexelBufferUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingStorageTexelBufferUpdateAfterBind),
                                       structure->descriptorBindingStorageTexelBufferUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingUpdateUnusedWhilePending),
                                       structure->descriptorBindingUpdateUnusedWhilePending);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingPartiallyBound),
                                       structure->descriptorBindingPartiallyBound);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingVariableDescriptorCount),
                                       structure->descriptorBindingVariableDescriptorCount);

                skip |= ValidateBool32(pNext_loc.dot(Field::runtimeDescriptorArray), structure->runtimeDescriptorArray);

                skip |= ValidateBool32(pNext_loc.dot(Field::samplerFilterMinmax), structure->samplerFilterMinmax);

                skip |= ValidateBool32(pNext_loc.dot(Field::scalarBlockLayout), structure->scalarBlockLayout);

                skip |= ValidateBool32(pNext_loc.dot(Field::imagelessFramebuffer), structure->imagelessFramebuffer);

                skip |= ValidateBool32(pNext_loc.dot(Field::uniformBufferStandardLayout), structure->uniformBufferStandardLayout);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderSubgroupExtendedTypes), structure->shaderSubgroupExtendedTypes);

                skip |= ValidateBool32(pNext_loc.dot(Field::separateDepthStencilLayouts), structure->separateDepthStencilLayouts);

                skip |= ValidateBool32(pNext_loc.dot(Field::hostQueryReset), structure->hostQueryReset);

                skip |= ValidateBool32(pNext_loc.dot(Field::timelineSemaphore), structure->timelineSemaphore);

                skip |= ValidateBool32(pNext_loc.dot(Field::bufferDeviceAddress), structure->bufferDeviceAddress);

                skip |= ValidateBool32(pNext_loc.dot(Field::bufferDeviceAddressCaptureReplay),
                                       structure->bufferDeviceAddressCaptureReplay);

                skip |=
                    ValidateBool32(pNext_loc.dot(Field::bufferDeviceAddressMultiDevice), structure->bufferDeviceAddressMultiDevice);

                skip |= ValidateBool32(pNext_loc.dot(Field::vulkanMemoryModel), structure->vulkanMemoryModel);

                skip |= ValidateBool32(pNext_loc.dot(Field::vulkanMemoryModelDeviceScope), structure->vulkanMemoryModelDeviceScope);

                skip |= ValidateBool32(pNext_loc.dot(Field::vulkanMemoryModelAvailabilityVisibilityChains),
                                       structure->vulkanMemoryModelAvailabilityVisibilityChains);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderOutputViewportIndex), structure->shaderOutputViewportIndex);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderOutputLayer), structure->shaderOutputLayer);

                skip |= ValidateBool32(pNext_loc.dot(Field::subgroupBroadcastDynamicId), structure->subgroupBroadcastDynamicId);
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkan12Properties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {  // Covers
                                                                         // VUID-VkPhysicalDeviceVulkan12Properties-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES) "
                             "which was added in VK_API_VERSION_1_2 but the "
                             "current effective API version is %s.",
                             StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkImageFormatListCreateInfo structure members
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO: {  // Covers VUID-VkImageFormatListCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO) which "
                                 "was added in VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkImageFormatListCreateInfo);
                VkImageFormatListCreateInfo* structure = (VkImageFormatListCreateInfo*)header;
                skip |= ValidateRangedEnumArray(pNext_loc.dot(Field::viewFormatCount), pNext_loc.dot(Field::pViewFormats),
                                                "VkFormat", structure->viewFormatCount, structure->pViewFormats, false, true);
            }
        } break;

        // Validation code for VkPhysicalDevice8BitStorageFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES: {  // Covers
                                                                         // VUID-VkPhysicalDevice8BitStorageFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES) "
                             "which was added in VK_API_VERSION_1_2 but the "
                             "current effective API version is %s.",
                             StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDevice8BitStorageFeatures);
                VkPhysicalDevice8BitStorageFeatures* structure = (VkPhysicalDevice8BitStorageFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::storageBuffer8BitAccess), structure->storageBuffer8BitAccess);

                skip |= ValidateBool32(pNext_loc.dot(Field::uniformAndStorageBuffer8BitAccess),
                                       structure->uniformAndStorageBuffer8BitAccess);

                skip |= ValidateBool32(pNext_loc.dot(Field::storagePushConstant8), structure->storagePushConstant8);
            }
        } break;

        // Validation code for VkPhysicalDeviceDriverProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES: {  // Covers VUID-VkPhysicalDeviceDriverProperties-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES) "
                                 "which was added in VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderAtomicInt64Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES: {  // Covers
                                                                                // VUID-VkPhysicalDeviceShaderAtomicInt64Features-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES) "
                    "which was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceShaderAtomicInt64Features);
                VkPhysicalDeviceShaderAtomicInt64Features* structure = (VkPhysicalDeviceShaderAtomicInt64Features*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::shaderBufferInt64Atomics), structure->shaderBufferInt64Atomics);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderSharedInt64Atomics), structure->shaderSharedInt64Atomics);
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderFloat16Int8Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES: {  // Covers
                                                                                // VUID-VkPhysicalDeviceShaderFloat16Int8Features-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES) "
                    "which was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceShaderFloat16Int8Features);
                VkPhysicalDeviceShaderFloat16Int8Features* structure = (VkPhysicalDeviceShaderFloat16Int8Features*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::shaderFloat16), structure->shaderFloat16);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderInt8), structure->shaderInt8);
            }
        } break;

        // Validation code for VkPhysicalDeviceFloatControlsProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES: {  // Covers
                                                                             // VUID-VkPhysicalDeviceFloatControlsProperties-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES) which "
                    "was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkDescriptorSetLayoutBindingFlagsCreateInfo structure members
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO: {  // Covers
                                                                                   // VUID-VkDescriptorSetLayoutBindingFlagsCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO) "
                    "which was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkDescriptorSetLayoutBindingFlagsCreateInfo);
                VkDescriptorSetLayoutBindingFlagsCreateInfo* structure = (VkDescriptorSetLayoutBindingFlagsCreateInfo*)header;
                skip |= ValidateFlagsArray(pNext_loc.dot(Field::bindingCount), pNext_loc.dot(Field::pBindingFlags),
                                           "VkDescriptorBindingFlagBits", AllVkDescriptorBindingFlagBits, structure->bindingCount,
                                           structure->pBindingFlags, false,
                                           "VUID-VkDescriptorSetLayoutBindingFlagsCreateInfo-pBindingFlags-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceDescriptorIndexingFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES: {  // Covers
                                                                                // VUID-VkPhysicalDeviceDescriptorIndexingFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES) "
                    "which was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceDescriptorIndexingFeatures);
                VkPhysicalDeviceDescriptorIndexingFeatures* structure = (VkPhysicalDeviceDescriptorIndexingFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::shaderInputAttachmentArrayDynamicIndexing),
                                       structure->shaderInputAttachmentArrayDynamicIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderUniformTexelBufferArrayDynamicIndexing),
                                       structure->shaderUniformTexelBufferArrayDynamicIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageTexelBufferArrayDynamicIndexing),
                                       structure->shaderStorageTexelBufferArrayDynamicIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderUniformBufferArrayNonUniformIndexing),
                                       structure->shaderUniformBufferArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderSampledImageArrayNonUniformIndexing),
                                       structure->shaderSampledImageArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageBufferArrayNonUniformIndexing),
                                       structure->shaderStorageBufferArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageImageArrayNonUniformIndexing),
                                       structure->shaderStorageImageArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderInputAttachmentArrayNonUniformIndexing),
                                       structure->shaderInputAttachmentArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderUniformTexelBufferArrayNonUniformIndexing),
                                       structure->shaderUniformTexelBufferArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderStorageTexelBufferArrayNonUniformIndexing),
                                       structure->shaderStorageTexelBufferArrayNonUniformIndexing);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingUniformBufferUpdateAfterBind),
                                       structure->descriptorBindingUniformBufferUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingSampledImageUpdateAfterBind),
                                       structure->descriptorBindingSampledImageUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingStorageImageUpdateAfterBind),
                                       structure->descriptorBindingStorageImageUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingStorageBufferUpdateAfterBind),
                                       structure->descriptorBindingStorageBufferUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingUniformTexelBufferUpdateAfterBind),
                                       structure->descriptorBindingUniformTexelBufferUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingStorageTexelBufferUpdateAfterBind),
                                       structure->descriptorBindingStorageTexelBufferUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingUpdateUnusedWhilePending),
                                       structure->descriptorBindingUpdateUnusedWhilePending);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingPartiallyBound),
                                       structure->descriptorBindingPartiallyBound);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingVariableDescriptorCount),
                                       structure->descriptorBindingVariableDescriptorCount);

                skip |= ValidateBool32(pNext_loc.dot(Field::runtimeDescriptorArray), structure->runtimeDescriptorArray);
            }
        } break;

        // Validation code for VkPhysicalDeviceDescriptorIndexingProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES: {  // Covers
                                                                                  // VUID-VkPhysicalDeviceDescriptorIndexingProperties-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES) "
                    "which was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkDescriptorSetVariableDescriptorCountAllocateInfo structure members
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO: {  // Covers
                                                                                          // VUID-VkDescriptorSetVariableDescriptorCountAllocateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO) which was added in "
                                 "VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkDescriptorSetVariableDescriptorCountAllocateInfo);
                VkDescriptorSetVariableDescriptorCountAllocateInfo* structure =
                    (VkDescriptorSetVariableDescriptorCountAllocateInfo*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::descriptorSetCount), pNext_loc.dot(Field::pDescriptorCounts),
                                      structure->descriptorSetCount, &structure->pDescriptorCounts, false, true, kVUIDUndefined,
                                      "VUID-VkDescriptorSetVariableDescriptorCountAllocateInfo-pDescriptorCounts-parameter");
            }
        } break;

        // Validation code for VkDescriptorSetVariableDescriptorCountLayoutSupport structure members
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT: {  // Covers
                                                                                           // VUID-VkDescriptorSetVariableDescriptorCountLayoutSupport-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT) which was added in "
                                 "VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkSubpassDescriptionDepthStencilResolve structure members
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE: {  // Covers
                                                                             // VUID-VkSubpassDescriptionDepthStencilResolve-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE) which "
                    "was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkSubpassDescriptionDepthStencilResolve);
                VkSubpassDescriptionDepthStencilResolve* structure = (VkSubpassDescriptionDepthStencilResolve*)header;
                skip |= ValidateStructType(pNext_loc.dot(Field::pDepthStencilResolveAttachment),
                                           "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2", structure->pDepthStencilResolveAttachment,
                                           VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2, false,
                                           "VUID-VkSubpassDescriptionDepthStencilResolve-pDepthStencilResolveAttachment-parameter",
                                           "VUID-VkAttachmentReference2-sType-sType");

                if (structure->pDepthStencilResolveAttachment != nullptr) {
                    [[maybe_unused]] const Location pDepthStencilResolveAttachment_loc =
                        pNext_loc.dot(Field::pDepthStencilResolveAttachment);
                    skip |= ValidateRangedEnum(pDepthStencilResolveAttachment_loc.dot(Field::layout), "VkImageLayout",
                                               structure->pDepthStencilResolveAttachment->layout,
                                               "VUID-VkAttachmentReference2-layout-parameter");
                }
            }
        } break;

        // Validation code for VkPhysicalDeviceDepthStencilResolveProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES: {  // Covers
                                                                                    // VUID-VkPhysicalDeviceDepthStencilResolveProperties-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES) "
                    "which was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceScalarBlockLayoutFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES: {  // Covers
                                                                                // VUID-VkPhysicalDeviceScalarBlockLayoutFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES) "
                    "which was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceScalarBlockLayoutFeatures);
                VkPhysicalDeviceScalarBlockLayoutFeatures* structure = (VkPhysicalDeviceScalarBlockLayoutFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::scalarBlockLayout), structure->scalarBlockLayout);
            }
        } break;

        // Validation code for VkImageStencilUsageCreateInfo structure members
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO: {  // Covers VUID-VkImageStencilUsageCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO) "
                                 "which was added in VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkImageStencilUsageCreateInfo);
                VkImageStencilUsageCreateInfo* structure = (VkImageStencilUsageCreateInfo*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::stencilUsage), "VkImageUsageFlagBits", AllVkImageUsageFlagBits,
                                      structure->stencilUsage, kRequiredFlags,
                                      "VUID-VkImageStencilUsageCreateInfo-stencilUsage-parameter",
                                      "VUID-VkImageStencilUsageCreateInfo-stencilUsage-requiredbitmask");
            }
        } break;

        // Validation code for VkSamplerReductionModeCreateInfo structure members
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO: {  // Covers VUID-VkSamplerReductionModeCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO) "
                                 "which was added in VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkSamplerReductionModeCreateInfo);
                VkSamplerReductionModeCreateInfo* structure = (VkSamplerReductionModeCreateInfo*)header;
                skip |= ValidateRangedEnum(pNext_loc.dot(Field::reductionMode), "VkSamplerReductionMode", structure->reductionMode,
                                           "VUID-VkSamplerReductionModeCreateInfo-reductionMode-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceSamplerFilterMinmaxProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES: {  // Covers
                                                                                    // VUID-VkPhysicalDeviceSamplerFilterMinmaxProperties-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES) "
                    "which was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkanMemoryModelFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES: {  // Covers
                                                                                // VUID-VkPhysicalDeviceVulkanMemoryModelFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES) "
                    "which was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceVulkanMemoryModelFeatures);
                VkPhysicalDeviceVulkanMemoryModelFeatures* structure = (VkPhysicalDeviceVulkanMemoryModelFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::vulkanMemoryModel), structure->vulkanMemoryModel);

                skip |= ValidateBool32(pNext_loc.dot(Field::vulkanMemoryModelDeviceScope), structure->vulkanMemoryModelDeviceScope);

                skip |= ValidateBool32(pNext_loc.dot(Field::vulkanMemoryModelAvailabilityVisibilityChains),
                                       structure->vulkanMemoryModelAvailabilityVisibilityChains);
            }
        } break;

        // Validation code for VkPhysicalDeviceImagelessFramebufferFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES: {  // Covers
                                                                                  // VUID-VkPhysicalDeviceImagelessFramebufferFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES) "
                    "which was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceImagelessFramebufferFeatures);
                VkPhysicalDeviceImagelessFramebufferFeatures* structure = (VkPhysicalDeviceImagelessFramebufferFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::imagelessFramebuffer), structure->imagelessFramebuffer);
            }
        } break;

        // Validation code for VkFramebufferAttachmentsCreateInfo structure members
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO: {  // Covers VUID-VkFramebufferAttachmentsCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO) "
                                 "which was added in VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkFramebufferAttachmentsCreateInfo);
                VkFramebufferAttachmentsCreateInfo* structure = (VkFramebufferAttachmentsCreateInfo*)header;
                skip |= ValidateStructTypeArray(
                    pNext_loc.dot(Field::attachmentImageInfoCount), pNext_loc.dot(Field::pAttachmentImageInfos),
                    "VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO", structure->attachmentImageInfoCount,
                    structure->pAttachmentImageInfos, VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO, false, true,
                    "VUID-VkFramebufferAttachmentImageInfo-sType-sType",
                    "VUID-VkFramebufferAttachmentsCreateInfo-pAttachmentImageInfos-parameter", kVUIDUndefined);

                if (structure->pAttachmentImageInfos != nullptr) {
                    for (uint32_t attachmentImageInfoIndex = 0; attachmentImageInfoIndex < structure->attachmentImageInfoCount;
                         ++attachmentImageInfoIndex) {
                        [[maybe_unused]] const Location pAttachmentImageInfos_loc =
                            pNext_loc.dot(Field::pAttachmentImageInfos, attachmentImageInfoIndex);
                        skip |= ValidateFlags(pAttachmentImageInfos_loc.dot(Field::flags), "VkImageCreateFlagBits",
                                              AllVkImageCreateFlagBits,
                                              structure->pAttachmentImageInfos[attachmentImageInfoIndex].flags, kOptionalFlags,
                                              "VUID-VkFramebufferAttachmentImageInfo-flags-parameter");

                        skip |=
                            ValidateFlags(pAttachmentImageInfos_loc.dot(Field::usage), "VkImageUsageFlagBits",
                                          AllVkImageUsageFlagBits, structure->pAttachmentImageInfos[attachmentImageInfoIndex].usage,
                                          kRequiredFlags, "VUID-VkFramebufferAttachmentImageInfo-usage-parameter",
                                          "VUID-VkFramebufferAttachmentImageInfo-usage-requiredbitmask");

                        skip |= ValidateRangedEnumArray(pAttachmentImageInfos_loc.dot(Field::viewFormatCount),
                                                        pAttachmentImageInfos_loc.dot(Field::pViewFormats), "VkFormat",
                                                        structure->pAttachmentImageInfos[attachmentImageInfoIndex].viewFormatCount,
                                                        structure->pAttachmentImageInfos[attachmentImageInfoIndex].pViewFormats,
                                                        false, true);
                    }
                }
            }
        } break;

        // Validation code for VkRenderPassAttachmentBeginInfo structure members
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO: {  // Covers VUID-VkRenderPassAttachmentBeginInfo-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO) "
                                 "which was added in VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkRenderPassAttachmentBeginInfo);
                VkRenderPassAttachmentBeginInfo* structure = (VkRenderPassAttachmentBeginInfo*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::attachmentCount), pNext_loc.dot(Field::pAttachments),
                                      structure->attachmentCount, &structure->pAttachments, false, true, kVUIDUndefined,
                                      "VUID-VkRenderPassAttachmentBeginInfo-pAttachments-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceUniformBufferStandardLayoutFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES: {  // Covers
                                                                                           // VUID-VkPhysicalDeviceUniformBufferStandardLayoutFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES) which was added in "
                                 "VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceUniformBufferStandardLayoutFeatures);
                VkPhysicalDeviceUniformBufferStandardLayoutFeatures* structure =
                    (VkPhysicalDeviceUniformBufferStandardLayoutFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::uniformBufferStandardLayout), structure->uniformBufferStandardLayout);
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES: {  // Covers
                                                                                           // VUID-VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES) which was added in "
                                 "VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES: {  // Covers
                                                                                           // VUID-VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES) which was added in "
                                 "VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures);
                VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* structure =
                    (VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::separateDepthStencilLayouts), structure->separateDepthStencilLayouts);
            }
        } break;

        // Validation code for VkAttachmentReferenceStencilLayout structure members
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT: {  // Covers VUID-VkAttachmentReferenceStencilLayout-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT) "
                                 "which was added in VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkAttachmentReferenceStencilLayout);
                VkAttachmentReferenceStencilLayout* structure = (VkAttachmentReferenceStencilLayout*)header;
                skip |= ValidateRangedEnum(pNext_loc.dot(Field::stencilLayout), "VkImageLayout", structure->stencilLayout,
                                           "VUID-VkAttachmentReferenceStencilLayout-stencilLayout-parameter");
            }
        } break;

        // Validation code for VkAttachmentDescriptionStencilLayout structure members
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT: {  // Covers
                                                                         // VUID-VkAttachmentDescriptionStencilLayout-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT) "
                             "which was added in VK_API_VERSION_1_2 but the "
                             "current effective API version is %s.",
                             StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkAttachmentDescriptionStencilLayout);
                VkAttachmentDescriptionStencilLayout* structure = (VkAttachmentDescriptionStencilLayout*)header;
                skip |=
                    ValidateRangedEnum(pNext_loc.dot(Field::stencilInitialLayout), "VkImageLayout", structure->stencilInitialLayout,
                                       "VUID-VkAttachmentDescriptionStencilLayout-stencilInitialLayout-parameter");

                skip |= ValidateRangedEnum(pNext_loc.dot(Field::stencilFinalLayout), "VkImageLayout", structure->stencilFinalLayout,
                                           "VUID-VkAttachmentDescriptionStencilLayout-stencilFinalLayout-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceHostQueryResetFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES: {  // Covers
                                                                             // VUID-VkPhysicalDeviceHostQueryResetFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES) which "
                    "was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceHostQueryResetFeatures);
                VkPhysicalDeviceHostQueryResetFeatures* structure = (VkPhysicalDeviceHostQueryResetFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::hostQueryReset), structure->hostQueryReset);
            }
        } break;

        // Validation code for VkPhysicalDeviceTimelineSemaphoreFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES: {  // Covers
                                                                               // VUID-VkPhysicalDeviceTimelineSemaphoreFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES) which "
                    "was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceTimelineSemaphoreFeatures);
                VkPhysicalDeviceTimelineSemaphoreFeatures* structure = (VkPhysicalDeviceTimelineSemaphoreFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::timelineSemaphore), structure->timelineSemaphore);
            }
        } break;

        // Validation code for VkPhysicalDeviceTimelineSemaphoreProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES: {  // Covers
                                                                                 // VUID-VkPhysicalDeviceTimelineSemaphoreProperties-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES) "
                    "which was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkSemaphoreTypeCreateInfo structure members
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO: {  // Covers VUID-VkSemaphoreTypeCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO) which was "
                                 "added in VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkSemaphoreTypeCreateInfo);
                VkSemaphoreTypeCreateInfo* structure = (VkSemaphoreTypeCreateInfo*)header;
                skip |= ValidateRangedEnum(pNext_loc.dot(Field::semaphoreType), "VkSemaphoreType", structure->semaphoreType,
                                           "VUID-VkSemaphoreTypeCreateInfo-semaphoreType-parameter");
            }
        } break;

        // Validation code for VkTimelineSemaphoreSubmitInfo structure members
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO: {  // Covers VUID-VkTimelineSemaphoreSubmitInfo-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO) which "
                                 "was added in VK_API_VERSION_1_2 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceBufferDeviceAddressFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES: {  // Covers
                                                                                  // VUID-VkPhysicalDeviceBufferDeviceAddressFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES) "
                    "which was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceBufferDeviceAddressFeatures);
                VkPhysicalDeviceBufferDeviceAddressFeatures* structure = (VkPhysicalDeviceBufferDeviceAddressFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::bufferDeviceAddress), structure->bufferDeviceAddress);

                skip |= ValidateBool32(pNext_loc.dot(Field::bufferDeviceAddressCaptureReplay),
                                       structure->bufferDeviceAddressCaptureReplay);

                skip |=
                    ValidateBool32(pNext_loc.dot(Field::bufferDeviceAddressMultiDevice), structure->bufferDeviceAddressMultiDevice);
            }
        } break;

        // Validation code for VkBufferOpaqueCaptureAddressCreateInfo structure members
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO: {  // Covers
                                                                             // VUID-VkBufferOpaqueCaptureAddressCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO) which "
                    "was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkMemoryOpaqueCaptureAddressAllocateInfo structure members
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO: {  // Covers
                                                                               // VUID-VkMemoryOpaqueCaptureAddressAllocateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_2) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO) which "
                    "was added in VK_API_VERSION_1_2 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkan13Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {  // Covers VUID-VkPhysicalDeviceVulkan13Features-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES) "
                                 "which was added in VK_API_VERSION_1_3 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceVulkan13Features);
                VkPhysicalDeviceVulkan13Features* structure = (VkPhysicalDeviceVulkan13Features*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::robustImageAccess), structure->robustImageAccess);

                skip |= ValidateBool32(pNext_loc.dot(Field::inlineUniformBlock), structure->inlineUniformBlock);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingInlineUniformBlockUpdateAfterBind),
                                       structure->descriptorBindingInlineUniformBlockUpdateAfterBind);

                skip |= ValidateBool32(pNext_loc.dot(Field::pipelineCreationCacheControl), structure->pipelineCreationCacheControl);

                skip |= ValidateBool32(pNext_loc.dot(Field::privateData), structure->privateData);

                skip |=
                    ValidateBool32(pNext_loc.dot(Field::shaderDemoteToHelperInvocation), structure->shaderDemoteToHelperInvocation);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderTerminateInvocation), structure->shaderTerminateInvocation);

                skip |= ValidateBool32(pNext_loc.dot(Field::subgroupSizeControl), structure->subgroupSizeControl);

                skip |= ValidateBool32(pNext_loc.dot(Field::computeFullSubgroups), structure->computeFullSubgroups);

                skip |= ValidateBool32(pNext_loc.dot(Field::synchronization2), structure->synchronization2);

                skip |= ValidateBool32(pNext_loc.dot(Field::textureCompressionASTC_HDR), structure->textureCompressionASTC_HDR);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderZeroInitializeWorkgroupMemory),
                                       structure->shaderZeroInitializeWorkgroupMemory);

                skip |= ValidateBool32(pNext_loc.dot(Field::dynamicRendering), structure->dynamicRendering);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderIntegerDotProduct), structure->shaderIntegerDotProduct);

                skip |= ValidateBool32(pNext_loc.dot(Field::maintenance4), structure->maintenance4);
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkan13Properties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES: {  // Covers
                                                                         // VUID-VkPhysicalDeviceVulkan13Properties-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES) "
                             "which was added in VK_API_VERSION_1_3 but the "
                             "current effective API version is %s.",
                             StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPipelineCreationFeedbackCreateInfo structure members
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO: {  // Covers
                                                                          // VUID-VkPipelineCreationFeedbackCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO) "
                             "which was added in VK_API_VERSION_1_3 but the "
                             "current effective API version is %s.",
                             StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPipelineCreationFeedbackCreateInfo);
                VkPipelineCreationFeedbackCreateInfo* structure = (VkPipelineCreationFeedbackCreateInfo*)header;
                skip |= ValidateRequiredPointer(pNext_loc.dot(Field::pPipelineCreationFeedback),
                                                structure->pPipelineCreationFeedback, kVUIDUndefined);

                if (structure->pPipelineCreationFeedback != nullptr) {
                    [[maybe_unused]] const Location pPipelineCreationFeedback_loc = pNext_loc.dot(Field::pPipelineCreationFeedback);
                }

                skip |= ValidateArray(pNext_loc.dot(Field::pipelineStageCreationFeedbackCount),
                                      pNext_loc.dot(Field::pPipelineStageCreationFeedbacks),
                                      structure->pipelineStageCreationFeedbackCount, &structure->pPipelineStageCreationFeedbacks,
                                      false, true, kVUIDUndefined, kVUIDUndefined);

                if (structure->pPipelineStageCreationFeedbacks != nullptr) {
                    for (uint32_t pipelineStageCreationFeedbackIndex = 0;
                         pipelineStageCreationFeedbackIndex < structure->pipelineStageCreationFeedbackCount;
                         ++pipelineStageCreationFeedbackIndex) {
                        [[maybe_unused]] const Location pPipelineStageCreationFeedbacks_loc =
                            pNext_loc.dot(Field::pPipelineStageCreationFeedbacks, pipelineStageCreationFeedbackIndex);
                    }
                }
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderTerminateInvocationFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES: {  // Covers
                                                                                        // VUID-VkPhysicalDeviceShaderTerminateInvocationFeatures-sType-sType

            if ((is_physdev_api && !SupportedByPdev(physical_device, VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME)) ||
                (!is_physdev_api && !IsExtEnabled(device_extensions.vk_khr_shader_terminate_invocation))) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType "
                             "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES), but its parent extension "
                             "VK_KHR_shader_terminate_invocation has not been enabled.");
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceShaderTerminateInvocationFeatures);
                VkPhysicalDeviceShaderTerminateInvocationFeatures* structure =
                    (VkPhysicalDeviceShaderTerminateInvocationFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::shaderTerminateInvocation), structure->shaderTerminateInvocation);
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES: {  // Covers
                                                                                               // VUID-VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures-sType-sType

            if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME)) ||
                (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_shader_demote_to_helper_invocation))) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType "
                    "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES), but its parent extension "
                    "VK_EXT_shader_demote_to_helper_invocation has not been enabled.");
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc =
                    loc.pNext(Struct::VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures);
                VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* structure =
                    (VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*)header;
                skip |=
                    ValidateBool32(pNext_loc.dot(Field::shaderDemoteToHelperInvocation), structure->shaderDemoteToHelperInvocation);
            }
        } break;

        // Validation code for VkPhysicalDevicePrivateDataFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES: {  // Covers
                                                                         // VUID-VkPhysicalDevicePrivateDataFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES) "
                             "which was added in VK_API_VERSION_1_3 but the "
                             "current effective API version is %s.",
                             StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDevicePrivateDataFeatures);
                VkPhysicalDevicePrivateDataFeatures* structure = (VkPhysicalDevicePrivateDataFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::privateData), structure->privateData);
            }
        } break;

        // Validation code for VkDevicePrivateDataCreateInfo structure members
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO: {  // Covers VUID-VkDevicePrivateDataCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO) "
                                 "which was added in VK_API_VERSION_1_3 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDevicePipelineCreationCacheControlFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES: {  // Covers
                                                                                            // VUID-VkPhysicalDevicePipelineCreationCacheControlFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES) which was added in "
                                 "VK_API_VERSION_1_3 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDevicePipelineCreationCacheControlFeatures);
                VkPhysicalDevicePipelineCreationCacheControlFeatures* structure =
                    (VkPhysicalDevicePipelineCreationCacheControlFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::pipelineCreationCacheControl), structure->pipelineCreationCacheControl);
            }
        } break;

        // Validation code for VkMemoryBarrier2 structure members
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2: {  // Covers VUID-VkMemoryBarrier2-sType-sType

            if ((is_physdev_api && !SupportedByPdev(physical_device, VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME)) ||
                (!is_physdev_api && !IsExtEnabled(device_extensions.vk_khr_synchronization2))) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_MEMORY_BARRIER_2), but its parent extension "
                    "VK_KHR_synchronization2 has not been enabled.");
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkMemoryBarrier2);
                VkMemoryBarrier2* structure = (VkMemoryBarrier2*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2,
                                      structure->srcStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags(pNext_loc.dot(Field::srcAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                      structure->srcAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags(pNext_loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2,
                                      structure->dstStageMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags(pNext_loc.dot(Field::dstAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                      structure->dstAccessMask, kOptionalFlags, "VUID-VkMemoryBarrier2-dstAccessMask-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceSynchronization2Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES: {  // Covers
                                                                              // VUID-VkPhysicalDeviceSynchronization2Features-sType-sType

            if ((is_physdev_api && !SupportedByPdev(physical_device, VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME)) ||
                (!is_physdev_api && !IsExtEnabled(device_extensions.vk_khr_synchronization2))) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES), but its parent extension "
                                 "VK_KHR_synchronization2 has not been enabled.");
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceSynchronization2Features);
                VkPhysicalDeviceSynchronization2Features* structure = (VkPhysicalDeviceSynchronization2Features*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::synchronization2), structure->synchronization2);
            }
        } break;

        // Validation code for VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES: {  // Covers
                                                                                             // VUID-VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES) which was added in "
                                 "VK_API_VERSION_1_3 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc =
                    loc.pNext(Struct::VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures);
                VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* structure =
                    (VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::shaderZeroInitializeWorkgroupMemory),
                                       structure->shaderZeroInitializeWorkgroupMemory);
            }
        } break;

        // Validation code for VkPhysicalDeviceImageRobustnessFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES: {  // Covers
                                                                             // VUID-VkPhysicalDeviceImageRobustnessFeatures-sType-sType

            if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME)) ||
                (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_image_robustness))) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES), but its parent extension "
                                 "VK_EXT_image_robustness has not been enabled.");
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceImageRobustnessFeatures);
                VkPhysicalDeviceImageRobustnessFeatures* structure = (VkPhysicalDeviceImageRobustnessFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::robustImageAccess), structure->robustImageAccess);
            }
        } break;

        // Validation code for VkPhysicalDeviceSubgroupSizeControlFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES: {  // Covers
                                                                                  // VUID-VkPhysicalDeviceSubgroupSizeControlFeatures-sType-sType

            if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME)) ||
                (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_subgroup_size_control))) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES), but its parent extension "
                                 "VK_EXT_subgroup_size_control has not been enabled.");
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceSubgroupSizeControlFeatures);
                VkPhysicalDeviceSubgroupSizeControlFeatures* structure = (VkPhysicalDeviceSubgroupSizeControlFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::subgroupSizeControl), structure->subgroupSizeControl);

                skip |= ValidateBool32(pNext_loc.dot(Field::computeFullSubgroups), structure->computeFullSubgroups);
            }
        } break;

        // Validation code for VkPhysicalDeviceSubgroupSizeControlProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES: {  // Covers
                                                                                    // VUID-VkPhysicalDeviceSubgroupSizeControlProperties-sType-sType

            if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME)) ||
                (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_subgroup_size_control))) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES), but its parent extension "
                                 "VK_EXT_subgroup_size_control has not been enabled.");
            }
        } break;

        // Validation code for VkPipelineShaderStageRequiredSubgroupSizeCreateInfo structure members
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO: {  // Covers
                                                                                            // VUID-VkPipelineShaderStageRequiredSubgroupSizeCreateInfo-sType-sType

            if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME)) ||
                (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_subgroup_size_control))) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType "
                    "(VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO), but its parent extension "
                    "VK_EXT_subgroup_size_control has not been enabled.");
            }
        } break;

        // Validation code for VkPhysicalDeviceInlineUniformBlockFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES: {  // Covers
                                                                                 // VUID-VkPhysicalDeviceInlineUniformBlockFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES) "
                    "which was added in VK_API_VERSION_1_3 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceInlineUniformBlockFeatures);
                VkPhysicalDeviceInlineUniformBlockFeatures* structure = (VkPhysicalDeviceInlineUniformBlockFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::inlineUniformBlock), structure->inlineUniformBlock);

                skip |= ValidateBool32(pNext_loc.dot(Field::descriptorBindingInlineUniformBlockUpdateAfterBind),
                                       structure->descriptorBindingInlineUniformBlockUpdateAfterBind);
            }
        } break;

        // Validation code for VkPhysicalDeviceInlineUniformBlockProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES: {  // Covers
                                                                                   // VUID-VkPhysicalDeviceInlineUniformBlockProperties-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES) "
                    "which was added in VK_API_VERSION_1_3 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkWriteDescriptorSetInlineUniformBlock structure members
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK: {  // Covers
                                                                             // VUID-VkWriteDescriptorSetInlineUniformBlock-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK) which "
                    "was added in VK_API_VERSION_1_3 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkWriteDescriptorSetInlineUniformBlock);
                VkWriteDescriptorSetInlineUniformBlock* structure = (VkWriteDescriptorSetInlineUniformBlock*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::dataSize), pNext_loc.dot(Field::pData), structure->dataSize,
                                      &structure->pData, true, true, kVUIDUndefined, kVUIDUndefined);
            }
        } break;

        // Validation code for VkDescriptorPoolInlineUniformBlockCreateInfo structure members
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO: {  // Covers
                                                                                    // VUID-VkDescriptorPoolInlineUniformBlockCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO) "
                    "which was added in VK_API_VERSION_1_3 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceTextureCompressionASTCHDRFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES: {  // Covers
                                                                                         // VUID-VkPhysicalDeviceTextureCompressionASTCHDRFeatures-sType-sType

            if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME)) ||
                (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_texture_compression_astc_hdr))) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType "
                             "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES), but its parent extension "
                             "VK_EXT_texture_compression_astc_hdr has not been enabled.");
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceTextureCompressionASTCHDRFeatures);
                VkPhysicalDeviceTextureCompressionASTCHDRFeatures* structure =
                    (VkPhysicalDeviceTextureCompressionASTCHDRFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::textureCompressionASTC_HDR), structure->textureCompressionASTC_HDR);
            }
        } break;

        // Validation code for VkPipelineRenderingCreateInfo structure members
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO: {  // Covers VUID-VkPipelineRenderingCreateInfo-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO) which "
                                 "was added in VK_API_VERSION_1_3 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceDynamicRenderingFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES: {  // Covers
                                                                              // VUID-VkPhysicalDeviceDynamicRenderingFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES) which "
                    "was added in VK_API_VERSION_1_3 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceDynamicRenderingFeatures);
                VkPhysicalDeviceDynamicRenderingFeatures* structure = (VkPhysicalDeviceDynamicRenderingFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::dynamicRendering), structure->dynamicRendering);
            }
        } break;

        // Validation code for VkCommandBufferInheritanceRenderingInfo structure members
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO: {  // Covers
                                                                             // VUID-VkCommandBufferInheritanceRenderingInfo-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(
                    pnext_vuid, instance, loc.dot(Field::pNext),
                    "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO) which "
                    "was added in VK_API_VERSION_1_3 but the "
                    "current effective API version is %s.",
                    StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkCommandBufferInheritanceRenderingInfo);
                VkCommandBufferInheritanceRenderingInfo* structure = (VkCommandBufferInheritanceRenderingInfo*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::flags), "VkRenderingFlagBits", AllVkRenderingFlagBits, structure->flags,
                                      kOptionalFlags, kVUIDUndefined);

                skip |= ValidateRangedEnumArray(pNext_loc.dot(Field::colorAttachmentCount),
                                                pNext_loc.dot(Field::pColorAttachmentFormats), "VkFormat",
                                                structure->colorAttachmentCount, structure->pColorAttachmentFormats, true, true);

                skip |= ValidateRangedEnum(pNext_loc.dot(Field::depthAttachmentFormat), "VkFormat",
                                           structure->depthAttachmentFormat, kVUIDUndefined);

                skip |= ValidateRangedEnum(pNext_loc.dot(Field::stencilAttachmentFormat), "VkFormat",
                                           structure->stencilAttachmentFormat, kVUIDUndefined);

                skip |= ValidateFlags(pNext_loc.dot(Field::rasterizationSamples), "VkSampleCountFlagBits", AllVkSampleCountFlagBits,
                                      structure->rasterizationSamples, kOptionalSingleBit, kVUIDUndefined);
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderIntegerDotProductFeatures structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES: {  // Covers
                                                                                       // VUID-VkPhysicalDeviceShaderIntegerDotProductFeatures-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES) which was added in "
                                 "VK_API_VERSION_1_3 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceShaderIntegerDotProductFeatures);
                VkPhysicalDeviceShaderIntegerDotProductFeatures* structure =
                    (VkPhysicalDeviceShaderIntegerDotProductFeatures*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::shaderIntegerDotProduct), structure->shaderIntegerDotProduct);
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderIntegerDotProductProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES: {  // Covers
                                                                                         // VUID-VkPhysicalDeviceShaderIntegerDotProductProperties-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES) which was added in "
                                 "VK_API_VERSION_1_3 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceTexelBufferAlignmentProperties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES: {  // Covers
                                                                                     // VUID-VkPhysicalDeviceTexelBufferAlignmentProperties-sType-sType

            if ((is_physdev_api && !SupportedByPdev(physical_device, VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME)) ||
                (!is_physdev_api && !IsExtEnabled(device_extensions.vk_ext_texel_buffer_alignment))) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType "
                                 "(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES), but its parent extension "
                                 "VK_EXT_texel_buffer_alignment has not been enabled.");
            }
        } break;

        // Validation code for VkFormatProperties3 structure members
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3: {  // Covers VUID-VkFormatProperties3-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |= LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                                 "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3) which was added "
                                 "in VK_API_VERSION_1_3 but the "
                                 "current effective API version is %s.",
                                 StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceMaintenance4Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES: {  // Covers
                                                                          // VUID-VkPhysicalDeviceMaintenance4Features-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES) "
                             "which was added in VK_API_VERSION_1_3 but the "
                             "current effective API version is %s.",
                             StringAPIVersion(api_version).c_str());
            }
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceMaintenance4Features);
                VkPhysicalDeviceMaintenance4Features* structure = (VkPhysicalDeviceMaintenance4Features*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::maintenance4), structure->maintenance4);
            }
        } break;

        // Validation code for VkPhysicalDeviceMaintenance4Properties structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES: {  // Covers
                                                                            // VUID-VkPhysicalDeviceMaintenance4Properties-sType-sType

            if (api_version < VK_API_VERSION_1_3) {
                skip |=
                    LogError(pnext_vuid, instance, loc.dot(Field::pNext),
                             "includes a pointer to a VkStructureType (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES) "
                             "which was added in VK_API_VERSION_1_3 but the "
                             "current effective API version is %s.",
                             StringAPIVersion(api_version).c_str());
            }
        } break;

        // Validation code for VkPhysicalDeviceVulkanSC10Features structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES: {  // Covers
                                                                          // VUID-VkPhysicalDeviceVulkanSC10Features-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceVulkanSC10Features);
                VkPhysicalDeviceVulkanSC10Features* structure = (VkPhysicalDeviceVulkanSC10Features*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::shaderAtomicInstructions), structure->shaderAtomicInstructions);
            }
        } break;

        // No Validation code for VkPhysicalDeviceVulkanSC10Properties structure members  -- Covers
        // VUID-VkPhysicalDeviceVulkanSC10Properties-sType-sType

        // Validation code for VkDeviceObjectReservationCreateInfo structure members
        case VK_STRUCTURE_TYPE_DEVICE_OBJECT_RESERVATION_CREATE_INFO: {  // Covers
                                                                         // VUID-VkDeviceObjectReservationCreateInfo-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkDeviceObjectReservationCreateInfo);
                VkDeviceObjectReservationCreateInfo* structure = (VkDeviceObjectReservationCreateInfo*)header;
                skip |= ValidateStructTypeArray(
                    pNext_loc.dot(Field::pipelineCacheCreateInfoCount), pNext_loc.dot(Field::pPipelineCacheCreateInfos),
                    "VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO", structure->pipelineCacheCreateInfoCount,
                    structure->pPipelineCacheCreateInfos, VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO, false, true,
                    "VUID-VkPipelineCacheCreateInfo-sType-sType",
                    "VUID-VkDeviceObjectReservationCreateInfo-pPipelineCacheCreateInfos-parameter", kVUIDUndefined);

                if (structure->pPipelineCacheCreateInfos != nullptr) {
                    for (uint32_t pipelineCacheCreateInfoIndex = 0;
                         pipelineCacheCreateInfoIndex < structure->pipelineCacheCreateInfoCount; ++pipelineCacheCreateInfoIndex) {
                        [[maybe_unused]] const Location pPipelineCacheCreateInfos_loc =
                            pNext_loc.dot(Field::pPipelineCacheCreateInfos, pipelineCacheCreateInfoIndex);
                        skip |= ValidateFlags(pPipelineCacheCreateInfos_loc.dot(Field::flags), "VkPipelineCacheCreateFlagBits",
                                              AllVkPipelineCacheCreateFlagBits,
                                              structure->pPipelineCacheCreateInfos[pipelineCacheCreateInfoIndex].flags,
                                              kOptionalFlags, "VUID-VkPipelineCacheCreateInfo-flags-parameter");

                        skip |= ValidateArray(pPipelineCacheCreateInfos_loc.dot(Field::initialDataSize),
                                              pPipelineCacheCreateInfos_loc.dot(Field::pInitialData),
                                              structure->pPipelineCacheCreateInfos[pipelineCacheCreateInfoIndex].initialDataSize,
                                              &structure->pPipelineCacheCreateInfos[pipelineCacheCreateInfoIndex].pInitialData,
                                              true, true, "VUID-VkPipelineCacheCreateInfo-initialDataSize-arraylength",
                                              "VUID-VkPipelineCacheCreateInfo-pInitialData-parameter");
                    }
                }

                skip |= ValidateStructTypeArray(
                    pNext_loc.dot(Field::pipelinePoolSizeCount), pNext_loc.dot(Field::pPipelinePoolSizes),
                    "VK_STRUCTURE_TYPE_PIPELINE_POOL_SIZE", structure->pipelinePoolSizeCount, structure->pPipelinePoolSizes,
                    VK_STRUCTURE_TYPE_PIPELINE_POOL_SIZE, false, true, "VUID-VkPipelinePoolSize-sType-sType",
                    "VUID-VkDeviceObjectReservationCreateInfo-pPipelinePoolSizes-parameter", kVUIDUndefined);

                if (structure->pPipelinePoolSizes != nullptr) {
                    for (uint32_t pipelinePoolSizeIndex = 0; pipelinePoolSizeIndex < structure->pipelinePoolSizeCount;
                         ++pipelinePoolSizeIndex) {
                        [[maybe_unused]] const Location pPipelinePoolSizes_loc =
                            pNext_loc.dot(Field::pPipelinePoolSizes, pipelinePoolSizeIndex);
                    }
                }
            }
        } break;

        // No Validation code for VkCommandPoolMemoryReservationCreateInfo structure members  -- Covers
        // VUID-VkCommandPoolMemoryReservationCreateInfo-sType-sType

        // Validation code for VkFaultCallbackInfo structure members
        case VK_STRUCTURE_TYPE_FAULT_CALLBACK_INFO: {  // Covers VUID-VkFaultCallbackInfo-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkFaultCallbackInfo);
                VkFaultCallbackInfo* structure = (VkFaultCallbackInfo*)header;
                skip |= ValidateStructTypeArray(pNext_loc.dot(Field::faultCount), pNext_loc.dot(Field::pFaults),
                                                "VK_STRUCTURE_TYPE_FAULT_DATA", structure->faultCount, structure->pFaults,
                                                VK_STRUCTURE_TYPE_FAULT_DATA, false, false, "VUID-VkFaultData-sType-sType",
                                                "VUID-VkFaultCallbackInfo-pFaults-parameter", kVUIDUndefined);

                if (structure->pFaults != nullptr) {
                    for (uint32_t faultIndex = 0; faultIndex < structure->faultCount; ++faultIndex) {
                        [[maybe_unused]] const Location pFaults_loc = pNext_loc.dot(Field::pFaults, faultIndex);
                    }
                }

                skip |= ValidateRequiredPointer(pNext_loc.dot(Field::pfnFaultCallback),
                                                reinterpret_cast<const void*>(structure->pfnFaultCallback),
                                                "VUID-VkFaultCallbackInfo-pfnFaultCallback-parameter");
            }
        } break;

        // Validation code for VkPipelineOfflineCreateInfo structure members
        case VK_STRUCTURE_TYPE_PIPELINE_OFFLINE_CREATE_INFO: {  // Covers VUID-VkPipelineOfflineCreateInfo-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPipelineOfflineCreateInfo);
                VkPipelineOfflineCreateInfo* structure = (VkPipelineOfflineCreateInfo*)header;
                skip |= ValidateRangedEnum(pNext_loc.dot(Field::matchControl), "VkPipelineMatchControl", structure->matchControl,
                                           "VUID-VkPipelineOfflineCreateInfo-matchControl-parameter");
            }
        } break;

        // No Validation code for VkImageSwapchainCreateInfoKHR structure members  -- Covers
        // VUID-VkImageSwapchainCreateInfoKHR-sType-sType

        // Validation code for VkBindImageMemorySwapchainInfoKHR structure members
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR: {  // Covers VUID-VkBindImageMemorySwapchainInfoKHR-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkBindImageMemorySwapchainInfoKHR);
                VkBindImageMemorySwapchainInfoKHR* structure = (VkBindImageMemorySwapchainInfoKHR*)header;
                skip |= ValidateRequiredHandle(pNext_loc.dot(Field::swapchain), structure->swapchain);
            }
        } break;

        // Validation code for VkDeviceGroupPresentInfoKHR structure members
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR: {  // Covers VUID-VkDeviceGroupPresentInfoKHR-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkDeviceGroupPresentInfoKHR);
                VkDeviceGroupPresentInfoKHR* structure = (VkDeviceGroupPresentInfoKHR*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::swapchainCount), pNext_loc.dot(Field::pDeviceMasks),
                                      structure->swapchainCount, &structure->pDeviceMasks, false, true, kVUIDUndefined,
                                      "VUID-VkDeviceGroupPresentInfoKHR-pDeviceMasks-parameter");

                skip |= ValidateFlags(pNext_loc.dot(Field::mode), "VkDeviceGroupPresentModeFlagBitsKHR",
                                      AllVkDeviceGroupPresentModeFlagBitsKHR, structure->mode, kRequiredSingleBit,
                                      "VUID-VkDeviceGroupPresentInfoKHR-mode-parameter",
                                      "VUID-VkDeviceGroupPresentInfoKHR-mode-parameter");
            }
        } break;

        // Validation code for VkDeviceGroupSwapchainCreateInfoKHR structure members
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR: {  // Covers
                                                                          // VUID-VkDeviceGroupSwapchainCreateInfoKHR-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkDeviceGroupSwapchainCreateInfoKHR);
                VkDeviceGroupSwapchainCreateInfoKHR* structure = (VkDeviceGroupSwapchainCreateInfoKHR*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::modes), "VkDeviceGroupPresentModeFlagBitsKHR",
                                      AllVkDeviceGroupPresentModeFlagBitsKHR, structure->modes, kRequiredFlags,
                                      "VUID-VkDeviceGroupSwapchainCreateInfoKHR-modes-parameter",
                                      "VUID-VkDeviceGroupSwapchainCreateInfoKHR-modes-requiredbitmask");
            }
        } break;

        // Validation code for VkDisplayPresentInfoKHR structure members
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR: {  // Covers VUID-VkDisplayPresentInfoKHR-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkDisplayPresentInfoKHR);
                VkDisplayPresentInfoKHR* structure = (VkDisplayPresentInfoKHR*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::persistent), structure->persistent);
            }
        } break;

        // Validation code for VkImportMemoryFdInfoKHR structure members
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR: {  // Covers VUID-VkImportMemoryFdInfoKHR-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkImportMemoryFdInfoKHR);
                VkImportMemoryFdInfoKHR* structure = (VkImportMemoryFdInfoKHR*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::handleType), "VkExternalMemoryHandleTypeFlagBits",
                                      AllVkExternalMemoryHandleTypeFlagBits, structure->handleType, kOptionalSingleBit,
                                      "VUID-VkImportMemoryFdInfoKHR-handleType-parameter");
            }
        } break;

        // Validation code for VkPresentRegionsKHR structure members
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR: {  // Covers VUID-VkPresentRegionsKHR-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPresentRegionsKHR);
                VkPresentRegionsKHR* structure = (VkPresentRegionsKHR*)header;
                skip |=
                    ValidateArray(pNext_loc.dot(Field::swapchainCount), pNext_loc.dot(Field::pRegions), structure->swapchainCount,
                                  &structure->pRegions, true, false, "VUID-VkPresentRegionsKHR-swapchainCount-arraylength",
                                  "VUID-VkPresentRegionsKHR-pRegions-parameter");

                if (structure->pRegions != nullptr) {
                    for (uint32_t swapchainIndex = 0; swapchainIndex < structure->swapchainCount; ++swapchainIndex) {
                        [[maybe_unused]] const Location pRegions_loc = pNext_loc.dot(Field::pRegions, swapchainIndex);
                        if (structure->pRegions[swapchainIndex].pRectangles != nullptr) {
                            for (uint32_t rectangleIndex = 0; rectangleIndex < structure->pRegions[swapchainIndex].rectangleCount;
                                 ++rectangleIndex) {
                                [[maybe_unused]] const Location pRectangles_loc =
                                    pRegions_loc.dot(Field::pRectangles, rectangleIndex);
                            }
                        }
                    }
                }
            }
        } break;

        // No Validation code for VkSharedPresentSurfaceCapabilitiesKHR structure members  -- Covers
        // VUID-VkSharedPresentSurfaceCapabilitiesKHR-sType-sType

        // Validation code for VkPhysicalDevicePerformanceQueryFeaturesKHR structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR: {  // Covers
                                                                                  // VUID-VkPhysicalDevicePerformanceQueryFeaturesKHR-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDevicePerformanceQueryFeaturesKHR);
                VkPhysicalDevicePerformanceQueryFeaturesKHR* structure = (VkPhysicalDevicePerformanceQueryFeaturesKHR*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::performanceCounterQueryPools), structure->performanceCounterQueryPools);

                skip |= ValidateBool32(pNext_loc.dot(Field::performanceCounterMultipleQueryPools),
                                       structure->performanceCounterMultipleQueryPools);
            }
        } break;

        // No Validation code for VkPhysicalDevicePerformanceQueryPropertiesKHR structure members  -- Covers
        // VUID-VkPhysicalDevicePerformanceQueryPropertiesKHR-sType-sType

        // Validation code for VkQueryPoolPerformanceCreateInfoKHR structure members
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR: {  // Covers
                                                                          // VUID-VkQueryPoolPerformanceCreateInfoKHR-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkQueryPoolPerformanceCreateInfoKHR);
                VkQueryPoolPerformanceCreateInfoKHR* structure = (VkQueryPoolPerformanceCreateInfoKHR*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::counterIndexCount), pNext_loc.dot(Field::pCounterIndices),
                                      structure->counterIndexCount, &structure->pCounterIndices, true, true,
                                      "VUID-VkQueryPoolPerformanceCreateInfoKHR-counterIndexCount-arraylength",
                                      "VUID-VkQueryPoolPerformanceCreateInfoKHR-pCounterIndices-parameter");
            }
        } break;

        // No Validation code for VkPerformanceQuerySubmitInfoKHR structure members  -- Covers
        // VUID-VkPerformanceQuerySubmitInfoKHR-sType-sType

        // No Validation code for VkPerformanceQueryReservationInfoKHR structure members  -- Covers
        // VUID-VkPerformanceQueryReservationInfoKHR-sType-sType

        // Validation code for VkPhysicalDeviceShaderClockFeaturesKHR structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR: {  // Covers
                                                                             // VUID-VkPhysicalDeviceShaderClockFeaturesKHR-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceShaderClockFeaturesKHR);
                VkPhysicalDeviceShaderClockFeaturesKHR* structure = (VkPhysicalDeviceShaderClockFeaturesKHR*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::shaderSubgroupClock), structure->shaderSubgroupClock);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderDeviceClock), structure->shaderDeviceClock);
            }
        } break;

        // Validation code for VkFragmentShadingRateAttachmentInfoKHR structure members
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: {  // Covers
                                                                             // VUID-VkFragmentShadingRateAttachmentInfoKHR-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkFragmentShadingRateAttachmentInfoKHR);
                VkFragmentShadingRateAttachmentInfoKHR* structure = (VkFragmentShadingRateAttachmentInfoKHR*)header;
                skip |= ValidateStructType(pNext_loc.dot(Field::pFragmentShadingRateAttachment),
                                           "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2", structure->pFragmentShadingRateAttachment,
                                           VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2, false,
                                           "VUID-VkFragmentShadingRateAttachmentInfoKHR-pFragmentShadingRateAttachment-parameter",
                                           "VUID-VkAttachmentReference2-sType-sType");

                if (structure->pFragmentShadingRateAttachment != nullptr) {
                    [[maybe_unused]] const Location pFragmentShadingRateAttachment_loc =
                        pNext_loc.dot(Field::pFragmentShadingRateAttachment);
                    skip |= ValidateRangedEnum(pFragmentShadingRateAttachment_loc.dot(Field::layout), "VkImageLayout",
                                               structure->pFragmentShadingRateAttachment->layout,
                                               "VUID-VkAttachmentReference2-layout-parameter");
                }
            }
        } break;

        // No Validation code for VkPipelineFragmentShadingRateStateCreateInfoKHR structure members  -- Covers
        // VUID-VkPipelineFragmentShadingRateStateCreateInfoKHR-sType-sType

        // Validation code for VkPhysicalDeviceFragmentShadingRateFeaturesKHR structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR: {  // Covers
                                                                                      // VUID-VkPhysicalDeviceFragmentShadingRateFeaturesKHR-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceFragmentShadingRateFeaturesKHR);
                VkPhysicalDeviceFragmentShadingRateFeaturesKHR* structure = (VkPhysicalDeviceFragmentShadingRateFeaturesKHR*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::pipelineFragmentShadingRate), structure->pipelineFragmentShadingRate);

                skip |= ValidateBool32(pNext_loc.dot(Field::primitiveFragmentShadingRate), structure->primitiveFragmentShadingRate);

                skip |=
                    ValidateBool32(pNext_loc.dot(Field::attachmentFragmentShadingRate), structure->attachmentFragmentShadingRate);
            }
        } break;

        // No Validation code for VkPhysicalDeviceFragmentShadingRatePropertiesKHR structure members  -- Covers
        // VUID-VkPhysicalDeviceFragmentShadingRatePropertiesKHR-sType-sType

        // No Validation code for VkQueueFamilyCheckpointProperties2NV structure members  -- Covers
        // VUID-VkQueueFamilyCheckpointProperties2NV-sType-sType

        // Validation code for VkImageViewASTCDecodeModeEXT structure members
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT: {  // Covers VUID-VkImageViewASTCDecodeModeEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkImageViewASTCDecodeModeEXT);
                VkImageViewASTCDecodeModeEXT* structure = (VkImageViewASTCDecodeModeEXT*)header;
                skip |= ValidateRangedEnum(pNext_loc.dot(Field::decodeMode), "VkFormat", structure->decodeMode,
                                           "VUID-VkImageViewASTCDecodeModeEXT-decodeMode-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceASTCDecodeFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT: {  // Covers
                                                                            // VUID-VkPhysicalDeviceASTCDecodeFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceASTCDecodeFeaturesEXT);
                VkPhysicalDeviceASTCDecodeFeaturesEXT* structure = (VkPhysicalDeviceASTCDecodeFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::decodeModeSharedExponent), structure->decodeModeSharedExponent);
            }
        } break;

        // Validation code for VkSwapchainCounterCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT: {  // Covers VUID-VkSwapchainCounterCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkSwapchainCounterCreateInfoEXT);
                VkSwapchainCounterCreateInfoEXT* structure = (VkSwapchainCounterCreateInfoEXT*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::surfaceCounters), "VkSurfaceCounterFlagBitsEXT",
                                      AllVkSurfaceCounterFlagBitsEXT, structure->surfaceCounters, kOptionalFlags,
                                      "VUID-VkSwapchainCounterCreateInfoEXT-surfaceCounters-parameter");
            }
        } break;

        // No Validation code for VkPhysicalDeviceDiscardRectanglePropertiesEXT structure members  -- Covers
        // VUID-VkPhysicalDeviceDiscardRectanglePropertiesEXT-sType-sType

        // Validation code for VkPipelineDiscardRectangleStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT: {  // Covers
                                                                                    // VUID-VkPipelineDiscardRectangleStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPipelineDiscardRectangleStateCreateInfoEXT);
                VkPipelineDiscardRectangleStateCreateInfoEXT* structure = (VkPipelineDiscardRectangleStateCreateInfoEXT*)header;
                skip |= ValidateReservedFlags(pNext_loc.dot(Field::flags), structure->flags,
                                              "VUID-VkPipelineDiscardRectangleStateCreateInfoEXT-flags-zerobitmask");

                skip |= ValidateRangedEnum(pNext_loc.dot(Field::discardRectangleMode), "VkDiscardRectangleModeEXT",
                                           structure->discardRectangleMode,
                                           "VUID-VkPipelineDiscardRectangleStateCreateInfoEXT-discardRectangleMode-parameter");
            }
        } break;

        // No Validation code for VkPhysicalDeviceConservativeRasterizationPropertiesEXT structure members  -- Covers
        // VUID-VkPhysicalDeviceConservativeRasterizationPropertiesEXT-sType-sType

        // Validation code for VkPipelineRasterizationConservativeStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT: {  // Covers
                                                                                             // VUID-VkPipelineRasterizationConservativeStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc =
                    loc.pNext(Struct::VkPipelineRasterizationConservativeStateCreateInfoEXT);
                VkPipelineRasterizationConservativeStateCreateInfoEXT* structure =
                    (VkPipelineRasterizationConservativeStateCreateInfoEXT*)header;
                skip |= ValidateReservedFlags(pNext_loc.dot(Field::flags), structure->flags,
                                              "VUID-VkPipelineRasterizationConservativeStateCreateInfoEXT-flags-zerobitmask");

                skip |= ValidateRangedEnum(
                    pNext_loc.dot(Field::conservativeRasterizationMode), "VkConservativeRasterizationModeEXT",
                    structure->conservativeRasterizationMode,
                    "VUID-VkPipelineRasterizationConservativeStateCreateInfoEXT-conservativeRasterizationMode-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceDepthClipEnableFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT: {  // Covers
                                                                                  // VUID-VkPhysicalDeviceDepthClipEnableFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceDepthClipEnableFeaturesEXT);
                VkPhysicalDeviceDepthClipEnableFeaturesEXT* structure = (VkPhysicalDeviceDepthClipEnableFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::depthClipEnable), structure->depthClipEnable);
            }
        } break;

        // Validation code for VkPipelineRasterizationDepthClipStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT: {  // Covers
                                                                                           // VUID-VkPipelineRasterizationDepthClipStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPipelineRasterizationDepthClipStateCreateInfoEXT);
                VkPipelineRasterizationDepthClipStateCreateInfoEXT* structure =
                    (VkPipelineRasterizationDepthClipStateCreateInfoEXT*)header;
                skip |= ValidateReservedFlags(pNext_loc.dot(Field::flags), structure->flags,
                                              "VUID-VkPipelineRasterizationDepthClipStateCreateInfoEXT-flags-zerobitmask");

                skip |= ValidateBool32(pNext_loc.dot(Field::depthClipEnable), structure->depthClipEnable);
            }
        } break;

        // Validation code for VkDebugUtilsObjectNameInfoEXT structure members
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT: {  // Covers VUID-VkDebugUtilsObjectNameInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkDebugUtilsObjectNameInfoEXT);
                VkDebugUtilsObjectNameInfoEXT* structure = (VkDebugUtilsObjectNameInfoEXT*)header;
                skip |= ValidateRangedEnum(pNext_loc.dot(Field::objectType), "VkObjectType", structure->objectType,
                                           "VUID-VkDebugUtilsObjectNameInfoEXT-objectType-parameter");
            }
        } break;

        // Validation code for VkDebugUtilsMessengerCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT: {  // Covers
                                                                         // VUID-VkDebugUtilsMessengerCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkDebugUtilsMessengerCreateInfoEXT);
                VkDebugUtilsMessengerCreateInfoEXT* structure = (VkDebugUtilsMessengerCreateInfoEXT*)header;
                skip |= ValidateReservedFlags(pNext_loc.dot(Field::flags), structure->flags,
                                              "VUID-VkDebugUtilsMessengerCreateInfoEXT-flags-zerobitmask");

                skip |= ValidateFlags(pNext_loc.dot(Field::messageSeverity), "VkDebugUtilsMessageSeverityFlagBitsEXT",
                                      AllVkDebugUtilsMessageSeverityFlagBitsEXT, structure->messageSeverity, kRequiredFlags,
                                      "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageSeverity-parameter",
                                      "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageSeverity-requiredbitmask");

                skip |= ValidateFlags(pNext_loc.dot(Field::messageType), "VkDebugUtilsMessageTypeFlagBitsEXT",
                                      AllVkDebugUtilsMessageTypeFlagBitsEXT, structure->messageType, kRequiredFlags,
                                      "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageType-parameter",
                                      "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageType-requiredbitmask");

                skip |= ValidateRequiredPointer(pNext_loc.dot(Field::pfnUserCallback),
                                                reinterpret_cast<const void*>(structure->pfnUserCallback),
                                                "VUID-VkDebugUtilsMessengerCreateInfoEXT-pfnUserCallback-parameter");
            }
        } break;

        // Validation code for VkSampleLocationsInfoEXT structure members
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: {  // Covers VUID-VkSampleLocationsInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkSampleLocationsInfoEXT);
                VkSampleLocationsInfoEXT* structure = (VkSampleLocationsInfoEXT*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::sampleLocationsCount), pNext_loc.dot(Field::pSampleLocations),
                                      structure->sampleLocationsCount, &structure->pSampleLocations, false, true, kVUIDUndefined,
                                      "VUID-VkSampleLocationsInfoEXT-pSampleLocations-parameter");

                if (structure->pSampleLocations != nullptr) {
                    for (uint32_t sampleLocationsIndex = 0; sampleLocationsIndex < structure->sampleLocationsCount;
                         ++sampleLocationsIndex) {
                        [[maybe_unused]] const Location pSampleLocations_loc =
                            pNext_loc.dot(Field::pSampleLocations, sampleLocationsIndex);
                    }
                }
            }
        } break;

        // Validation code for VkRenderPassSampleLocationsBeginInfoEXT structure members
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT: {  // Covers
                                                                               // VUID-VkRenderPassSampleLocationsBeginInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkRenderPassSampleLocationsBeginInfoEXT);
                VkRenderPassSampleLocationsBeginInfoEXT* structure = (VkRenderPassSampleLocationsBeginInfoEXT*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::attachmentInitialSampleLocationsCount),
                                      pNext_loc.dot(Field::pAttachmentInitialSampleLocations),
                                      structure->attachmentInitialSampleLocationsCount,
                                      &structure->pAttachmentInitialSampleLocations, false, true, kVUIDUndefined,
                                      "VUID-VkRenderPassSampleLocationsBeginInfoEXT-pAttachmentInitialSampleLocations-parameter");

                if (structure->pAttachmentInitialSampleLocations != nullptr) {
                    for (uint32_t attachmentInitialSampleLocationsIndex = 0;
                         attachmentInitialSampleLocationsIndex < structure->attachmentInitialSampleLocationsCount;
                         ++attachmentInitialSampleLocationsIndex) {
                        [[maybe_unused]] const Location pAttachmentInitialSampleLocations_loc =
                            pNext_loc.dot(Field::pAttachmentInitialSampleLocations, attachmentInitialSampleLocationsIndex);
                        skip |=
                            ValidateStructType(pAttachmentInitialSampleLocations_loc.dot(Field::sampleLocationsInfo),
                                               "VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT",
                                               &(structure->pAttachmentInitialSampleLocations[attachmentInitialSampleLocationsIndex]
                                                     .sampleLocationsInfo),
                                               VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT, false, kVUIDUndefined,
                                               "VUID-VkSampleLocationsInfoEXT-sType-sType");

                        skip |=
                            ValidateArray(pAttachmentInitialSampleLocations_loc.dot(Field::sampleLocationsCount),
                                          pAttachmentInitialSampleLocations_loc.dot(Field::pSampleLocations),
                                          structure->pAttachmentInitialSampleLocations[attachmentInitialSampleLocationsIndex]
                                              .sampleLocationsInfo.sampleLocationsCount,
                                          &structure->pAttachmentInitialSampleLocations[attachmentInitialSampleLocationsIndex]
                                               .sampleLocationsInfo.pSampleLocations,
                                          false, true, kVUIDUndefined, "VUID-VkSampleLocationsInfoEXT-pSampleLocations-parameter");

                        if (structure->pAttachmentInitialSampleLocations[attachmentInitialSampleLocationsIndex]
                                .sampleLocationsInfo.pSampleLocations != nullptr) {
                            for (uint32_t sampleLocationsIndex = 0;
                                 sampleLocationsIndex <
                                 structure->pAttachmentInitialSampleLocations[attachmentInitialSampleLocationsIndex]
                                     .sampleLocationsInfo.sampleLocationsCount;
                                 ++sampleLocationsIndex) {
                                [[maybe_unused]] const Location pSampleLocations_loc =
                                    pAttachmentInitialSampleLocations_loc.dot(Field::pSampleLocations, sampleLocationsIndex);
                            }
                        }
                    }
                }

                skip |= ValidateArray(pNext_loc.dot(Field::postSubpassSampleLocationsCount),
                                      pNext_loc.dot(Field::pPostSubpassSampleLocations), structure->postSubpassSampleLocationsCount,
                                      &structure->pPostSubpassSampleLocations, false, true, kVUIDUndefined,
                                      "VUID-VkRenderPassSampleLocationsBeginInfoEXT-pPostSubpassSampleLocations-parameter");

                if (structure->pPostSubpassSampleLocations != nullptr) {
                    for (uint32_t postSubpassSampleLocationsIndex = 0;
                         postSubpassSampleLocationsIndex < structure->postSubpassSampleLocationsCount;
                         ++postSubpassSampleLocationsIndex) {
                        [[maybe_unused]] const Location pPostSubpassSampleLocations_loc =
                            pNext_loc.dot(Field::pPostSubpassSampleLocations, postSubpassSampleLocationsIndex);
                        skip |= ValidateStructType(
                            pPostSubpassSampleLocations_loc.dot(Field::sampleLocationsInfo),
                            "VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT",
                            &(structure->pPostSubpassSampleLocations[postSubpassSampleLocationsIndex].sampleLocationsInfo),
                            VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT, false, kVUIDUndefined,
                            "VUID-VkSampleLocationsInfoEXT-sType-sType");

                        skip |=
                            ValidateArray(pPostSubpassSampleLocations_loc.dot(Field::sampleLocationsCount),
                                          pPostSubpassSampleLocations_loc.dot(Field::pSampleLocations),
                                          structure->pPostSubpassSampleLocations[postSubpassSampleLocationsIndex]
                                              .sampleLocationsInfo.sampleLocationsCount,
                                          &structure->pPostSubpassSampleLocations[postSubpassSampleLocationsIndex]
                                               .sampleLocationsInfo.pSampleLocations,
                                          false, true, kVUIDUndefined, "VUID-VkSampleLocationsInfoEXT-pSampleLocations-parameter");

                        if (structure->pPostSubpassSampleLocations[postSubpassSampleLocationsIndex]
                                .sampleLocationsInfo.pSampleLocations != nullptr) {
                            for (uint32_t sampleLocationsIndex = 0;
                                 sampleLocationsIndex < structure->pPostSubpassSampleLocations[postSubpassSampleLocationsIndex]
                                                            .sampleLocationsInfo.sampleLocationsCount;
                                 ++sampleLocationsIndex) {
                                [[maybe_unused]] const Location pSampleLocations_loc =
                                    pPostSubpassSampleLocations_loc.dot(Field::pSampleLocations, sampleLocationsIndex);
                            }
                        }
                    }
                }
            }
        } break;

        // Validation code for VkPipelineSampleLocationsStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT: {  // Covers
                                                                                   // VUID-VkPipelineSampleLocationsStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPipelineSampleLocationsStateCreateInfoEXT);
                VkPipelineSampleLocationsStateCreateInfoEXT* structure = (VkPipelineSampleLocationsStateCreateInfoEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::sampleLocationsEnable), structure->sampleLocationsEnable);

                skip |= ValidateStructType(pNext_loc.dot(Field::sampleLocationsInfo), "VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT",
                                           &(structure->sampleLocationsInfo), VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT, false,
                                           kVUIDUndefined, "VUID-VkSampleLocationsInfoEXT-sType-sType");

                skip |= ValidateArray(pNext_loc.dot(Field::sampleLocationsCount), pNext_loc.dot(Field::pSampleLocations),
                                      structure->sampleLocationsInfo.sampleLocationsCount,
                                      &structure->sampleLocationsInfo.pSampleLocations, false, true, kVUIDUndefined,
                                      "VUID-VkSampleLocationsInfoEXT-pSampleLocations-parameter");

                if (structure->sampleLocationsInfo.pSampleLocations != nullptr) {
                    for (uint32_t sampleLocationsIndex = 0;
                         sampleLocationsIndex < structure->sampleLocationsInfo.sampleLocationsCount; ++sampleLocationsIndex) {
                        [[maybe_unused]] const Location pSampleLocations_loc =
                            pNext_loc.dot(Field::pSampleLocations, sampleLocationsIndex);
                    }
                }
            }
        } break;

        // No Validation code for VkPhysicalDeviceSampleLocationsPropertiesEXT structure members  -- Covers
        // VUID-VkPhysicalDeviceSampleLocationsPropertiesEXT-sType-sType

        // Validation code for VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT: {  // Covers
                                                                                         // VUID-VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT);
                VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* structure =
                    (VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::advancedBlendCoherentOperations),
                                       structure->advancedBlendCoherentOperations);
            }
        } break;

        // No Validation code for VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT structure members  -- Covers
        // VUID-VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT-sType-sType

        // Validation code for VkPipelineColorBlendAdvancedStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT: {  // Covers
                                                                                       // VUID-VkPipelineColorBlendAdvancedStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPipelineColorBlendAdvancedStateCreateInfoEXT);
                VkPipelineColorBlendAdvancedStateCreateInfoEXT* structure = (VkPipelineColorBlendAdvancedStateCreateInfoEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::srcPremultiplied), structure->srcPremultiplied);

                skip |= ValidateBool32(pNext_loc.dot(Field::dstPremultiplied), structure->dstPremultiplied);

                skip |= ValidateRangedEnum(pNext_loc.dot(Field::blendOverlap), "VkBlendOverlapEXT", structure->blendOverlap,
                                           "VUID-VkPipelineColorBlendAdvancedStateCreateInfoEXT-blendOverlap-parameter");
            }
        } break;

        // No Validation code for VkDrmFormatModifierPropertiesListEXT structure members  -- Covers
        // VUID-VkDrmFormatModifierPropertiesListEXT-sType-sType

        // Validation code for VkPhysicalDeviceImageDrmFormatModifierInfoEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT: {  // Covers
                                                                                      // VUID-VkPhysicalDeviceImageDrmFormatModifierInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceImageDrmFormatModifierInfoEXT);
                VkPhysicalDeviceImageDrmFormatModifierInfoEXT* structure = (VkPhysicalDeviceImageDrmFormatModifierInfoEXT*)header;
                skip |= ValidateRangedEnum(pNext_loc.dot(Field::sharingMode), "VkSharingMode", structure->sharingMode,
                                           "VUID-VkPhysicalDeviceImageDrmFormatModifierInfoEXT-sharingMode-parameter");
            }
        } break;

        // Validation code for VkImageDrmFormatModifierListCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT: {  // Covers
                                                                                  // VUID-VkImageDrmFormatModifierListCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkImageDrmFormatModifierListCreateInfoEXT);
                VkImageDrmFormatModifierListCreateInfoEXT* structure = (VkImageDrmFormatModifierListCreateInfoEXT*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::drmFormatModifierCount), pNext_loc.dot(Field::pDrmFormatModifiers),
                                      structure->drmFormatModifierCount, &structure->pDrmFormatModifiers, true, true,
                                      "VUID-VkImageDrmFormatModifierListCreateInfoEXT-drmFormatModifierCount-arraylength",
                                      "VUID-VkImageDrmFormatModifierListCreateInfoEXT-pDrmFormatModifiers-parameter");
            }
        } break;

        // Validation code for VkImageDrmFormatModifierExplicitCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT: {  // Covers
                                                                                      // VUID-VkImageDrmFormatModifierExplicitCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkImageDrmFormatModifierExplicitCreateInfoEXT);
                VkImageDrmFormatModifierExplicitCreateInfoEXT* structure = (VkImageDrmFormatModifierExplicitCreateInfoEXT*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::drmFormatModifierPlaneCount), pNext_loc.dot(Field::pPlaneLayouts),
                                      structure->drmFormatModifierPlaneCount, &structure->pPlaneLayouts, true, true,
                                      "VUID-VkImageDrmFormatModifierExplicitCreateInfoEXT-drmFormatModifierPlaneCount-arraylength",
                                      "VUID-VkImageDrmFormatModifierExplicitCreateInfoEXT-pPlaneLayouts-parameter");

                if (structure->pPlaneLayouts != nullptr) {
                    for (uint32_t drmFormatModifierPlaneIndex = 0;
                         drmFormatModifierPlaneIndex < structure->drmFormatModifierPlaneCount; ++drmFormatModifierPlaneIndex) {
                        [[maybe_unused]] const Location pPlaneLayouts_loc =
                            pNext_loc.dot(Field::pPlaneLayouts, drmFormatModifierPlaneIndex);
                    }
                }
            }
        } break;

        // No Validation code for VkDrmFormatModifierPropertiesList2EXT structure members  -- Covers
        // VUID-VkDrmFormatModifierPropertiesList2EXT-sType-sType

        // Validation code for VkPhysicalDeviceImageViewImageFormatInfoEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT: {  // Covers
                                                                                    // VUID-VkPhysicalDeviceImageViewImageFormatInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceImageViewImageFormatInfoEXT);
                VkPhysicalDeviceImageViewImageFormatInfoEXT* structure = (VkPhysicalDeviceImageViewImageFormatInfoEXT*)header;
                skip |= ValidateRangedEnum(pNext_loc.dot(Field::imageViewType), "VkImageViewType", structure->imageViewType,
                                           "VUID-VkPhysicalDeviceImageViewImageFormatInfoEXT-imageViewType-parameter");
            }
        } break;

        // No Validation code for VkFilterCubicImageViewImageFormatPropertiesEXT structure members  -- Covers
        // VUID-VkFilterCubicImageViewImageFormatPropertiesEXT-sType-sType

        // Validation code for VkDeviceQueueGlobalPriorityCreateInfoKHR structure members
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR: {  // Covers
                                                                                // VUID-VkDeviceQueueGlobalPriorityCreateInfoKHR-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkDeviceQueueGlobalPriorityCreateInfoKHR);
                VkDeviceQueueGlobalPriorityCreateInfoKHR* structure = (VkDeviceQueueGlobalPriorityCreateInfoKHR*)header;
                skip |=
                    ValidateRangedEnum(pNext_loc.dot(Field::globalPriority), "VkQueueGlobalPriorityKHR", structure->globalPriority,
                                       "VUID-VkDeviceQueueGlobalPriorityCreateInfoKHR-globalPriority-parameter");
            }
        } break;

        // Validation code for VkImportMemoryHostPointerInfoEXT structure members
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT: {  // Covers VUID-VkImportMemoryHostPointerInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkImportMemoryHostPointerInfoEXT);
                VkImportMemoryHostPointerInfoEXT* structure = (VkImportMemoryHostPointerInfoEXT*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::handleType), "VkExternalMemoryHandleTypeFlagBits",
                                      AllVkExternalMemoryHandleTypeFlagBits, structure->handleType, kRequiredSingleBit,
                                      "VUID-VkImportMemoryHostPointerInfoEXT-handleType-parameter",
                                      "VUID-VkImportMemoryHostPointerInfoEXT-handleType-parameter");

                skip |= ValidateRequiredPointer(pNext_loc.dot(Field::pHostPointer), structure->pHostPointer,
                                                "VUID-VkImportMemoryHostPointerInfoEXT-pHostPointer-parameter");
            }
        } break;

        // No Validation code for VkPhysicalDeviceExternalMemoryHostPropertiesEXT structure members  -- Covers
        // VUID-VkPhysicalDeviceExternalMemoryHostPropertiesEXT-sType-sType

        // No Validation code for VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT structure members  -- Covers
        // VUID-VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT-sType-sType

        // Validation code for VkPipelineVertexInputDivisorStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT: {  // Covers
                                                                                       // VUID-VkPipelineVertexInputDivisorStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPipelineVertexInputDivisorStateCreateInfoEXT);
                VkPipelineVertexInputDivisorStateCreateInfoEXT* structure = (VkPipelineVertexInputDivisorStateCreateInfoEXT*)header;
                skip |= ValidateArray(pNext_loc.dot(Field::vertexBindingDivisorCount), pNext_loc.dot(Field::pVertexBindingDivisors),
                                      structure->vertexBindingDivisorCount, &structure->pVertexBindingDivisors, true, true,
                                      "VUID-VkPipelineVertexInputDivisorStateCreateInfoEXT-vertexBindingDivisorCount-arraylength",
                                      "VUID-VkPipelineVertexInputDivisorStateCreateInfoEXT-pVertexBindingDivisors-parameter");

                if (structure->pVertexBindingDivisors != nullptr) {
                    for (uint32_t vertexBindingDivisorIndex = 0; vertexBindingDivisorIndex < structure->vertexBindingDivisorCount;
                         ++vertexBindingDivisorIndex) {
                        [[maybe_unused]] const Location pVertexBindingDivisors_loc =
                            pNext_loc.dot(Field::pVertexBindingDivisors, vertexBindingDivisorIndex);
                    }
                }
            }
        } break;

        // Validation code for VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT: {  // Covers
                                                                                         // VUID-VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT);
                VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* structure =
                    (VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::vertexAttributeInstanceRateDivisor),
                                       structure->vertexAttributeInstanceRateDivisor);

                skip |= ValidateBool32(pNext_loc.dot(Field::vertexAttributeInstanceRateZeroDivisor),
                                       structure->vertexAttributeInstanceRateZeroDivisor);
            }
        } break;

        // No Validation code for VkPhysicalDevicePCIBusInfoPropertiesEXT structure members  -- Covers
        // VUID-VkPhysicalDevicePCIBusInfoPropertiesEXT-sType-sType

        // Validation code for VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT: {  // Covers
                                                                                          // VUID-VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT);
                VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* structure =
                    (VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::shaderImageInt64Atomics), structure->shaderImageInt64Atomics);

                skip |= ValidateBool32(pNext_loc.dot(Field::sparseImageInt64Atomics), structure->sparseImageInt64Atomics);
            }
        } break;

        // No Validation code for VkPhysicalDeviceMemoryBudgetPropertiesEXT structure members  -- Covers
        // VUID-VkPhysicalDeviceMemoryBudgetPropertiesEXT-sType-sType

        // Validation code for VkValidationFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT: {  // Covers VUID-VkValidationFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkValidationFeaturesEXT);
                VkValidationFeaturesEXT* structure = (VkValidationFeaturesEXT*)header;
                skip |= ValidateRangedEnumArray(pNext_loc.dot(Field::enabledValidationFeatureCount),
                                                pNext_loc.dot(Field::pEnabledValidationFeatures), "VkValidationFeatureEnableEXT",
                                                structure->enabledValidationFeatureCount, structure->pEnabledValidationFeatures,
                                                false, true);

                skip |= ValidateRangedEnumArray(pNext_loc.dot(Field::disabledValidationFeatureCount),
                                                pNext_loc.dot(Field::pDisabledValidationFeatures), "VkValidationFeatureDisableEXT",
                                                structure->disabledValidationFeatureCount, structure->pDisabledValidationFeatures,
                                                false, true);
            }
        } break;

        // Validation code for VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT: {  // Covers
                                                                                          // VUID-VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT);
                VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* structure =
                    (VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*)header;
                skip |=
                    ValidateBool32(pNext_loc.dot(Field::fragmentShaderSampleInterlock), structure->fragmentShaderSampleInterlock);

                skip |= ValidateBool32(pNext_loc.dot(Field::fragmentShaderPixelInterlock), structure->fragmentShaderPixelInterlock);

                skip |= ValidateBool32(pNext_loc.dot(Field::fragmentShaderShadingRateInterlock),
                                       structure->fragmentShaderShadingRateInterlock);
            }
        } break;

        // Validation code for VkPhysicalDeviceYcbcrImageArraysFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT: {  // Covers
                                                                                   // VUID-VkPhysicalDeviceYcbcrImageArraysFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceYcbcrImageArraysFeaturesEXT);
                VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* structure = (VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::ycbcrImageArrays), structure->ycbcrImageArrays);
            }
        } break;

        // Validation code for VkPhysicalDeviceLineRasterizationFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT: {  // Covers
                                                                                   // VUID-VkPhysicalDeviceLineRasterizationFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceLineRasterizationFeaturesEXT);
                VkPhysicalDeviceLineRasterizationFeaturesEXT* structure = (VkPhysicalDeviceLineRasterizationFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::rectangularLines), structure->rectangularLines);

                skip |= ValidateBool32(pNext_loc.dot(Field::bresenhamLines), structure->bresenhamLines);

                skip |= ValidateBool32(pNext_loc.dot(Field::smoothLines), structure->smoothLines);

                skip |= ValidateBool32(pNext_loc.dot(Field::stippledRectangularLines), structure->stippledRectangularLines);

                skip |= ValidateBool32(pNext_loc.dot(Field::stippledBresenhamLines), structure->stippledBresenhamLines);

                skip |= ValidateBool32(pNext_loc.dot(Field::stippledSmoothLines), structure->stippledSmoothLines);
            }
        } break;

        // No Validation code for VkPhysicalDeviceLineRasterizationPropertiesEXT structure members  -- Covers
        // VUID-VkPhysicalDeviceLineRasterizationPropertiesEXT-sType-sType

        // Validation code for VkPipelineRasterizationLineStateCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT: {  // Covers
                                                                                     // VUID-VkPipelineRasterizationLineStateCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPipelineRasterizationLineStateCreateInfoEXT);
                VkPipelineRasterizationLineStateCreateInfoEXT* structure = (VkPipelineRasterizationLineStateCreateInfoEXT*)header;
                skip |= ValidateRangedEnum(pNext_loc.dot(Field::lineRasterizationMode), "VkLineRasterizationModeEXT",
                                           structure->lineRasterizationMode,
                                           "VUID-VkPipelineRasterizationLineStateCreateInfoEXT-lineRasterizationMode-parameter");

                skip |= ValidateBool32(pNext_loc.dot(Field::stippledLineEnable), structure->stippledLineEnable);
            }
        } break;

        // Validation code for VkPhysicalDeviceShaderAtomicFloatFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT: {  // Covers
                                                                                    // VUID-VkPhysicalDeviceShaderAtomicFloatFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceShaderAtomicFloatFeaturesEXT);
                VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* structure = (VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::shaderBufferFloat32Atomics), structure->shaderBufferFloat32Atomics);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderBufferFloat32AtomicAdd), structure->shaderBufferFloat32AtomicAdd);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderBufferFloat64Atomics), structure->shaderBufferFloat64Atomics);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderBufferFloat64AtomicAdd), structure->shaderBufferFloat64AtomicAdd);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderSharedFloat32Atomics), structure->shaderSharedFloat32Atomics);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderSharedFloat32AtomicAdd), structure->shaderSharedFloat32AtomicAdd);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderSharedFloat64Atomics), structure->shaderSharedFloat64Atomics);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderSharedFloat64AtomicAdd), structure->shaderSharedFloat64AtomicAdd);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderImageFloat32Atomics), structure->shaderImageFloat32Atomics);

                skip |= ValidateBool32(pNext_loc.dot(Field::shaderImageFloat32AtomicAdd), structure->shaderImageFloat32AtomicAdd);

                skip |= ValidateBool32(pNext_loc.dot(Field::sparseImageFloat32Atomics), structure->sparseImageFloat32Atomics);

                skip |= ValidateBool32(pNext_loc.dot(Field::sparseImageFloat32AtomicAdd), structure->sparseImageFloat32AtomicAdd);
            }
        } break;

        // Validation code for VkPhysicalDeviceIndexTypeUint8FeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT: {  // Covers
                                                                                 // VUID-VkPhysicalDeviceIndexTypeUint8FeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceIndexTypeUint8FeaturesEXT);
                VkPhysicalDeviceIndexTypeUint8FeaturesEXT* structure = (VkPhysicalDeviceIndexTypeUint8FeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::indexTypeUint8), structure->indexTypeUint8);
            }
        } break;

        // Validation code for VkPhysicalDeviceExtendedDynamicStateFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT: {  // Covers
                                                                                       // VUID-VkPhysicalDeviceExtendedDynamicStateFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceExtendedDynamicStateFeaturesEXT);
                VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* structure =
                    (VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::extendedDynamicState), structure->extendedDynamicState);
            }
        } break;

        // Validation code for VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT: {  // Covers
                                                                                       // VUID-VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT);
                VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* structure =
                    (VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::texelBufferAlignment), structure->texelBufferAlignment);
            }
        } break;

        // Validation code for VkPhysicalDeviceRobustness2FeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT: {  // Covers
                                                                             // VUID-VkPhysicalDeviceRobustness2FeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceRobustness2FeaturesEXT);
                VkPhysicalDeviceRobustness2FeaturesEXT* structure = (VkPhysicalDeviceRobustness2FeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::robustBufferAccess2), structure->robustBufferAccess2);

                skip |= ValidateBool32(pNext_loc.dot(Field::robustImageAccess2), structure->robustImageAccess2);

                skip |= ValidateBool32(pNext_loc.dot(Field::nullDescriptor), structure->nullDescriptor);
            }
        } break;

        // No Validation code for VkPhysicalDeviceRobustness2PropertiesEXT structure members  -- Covers
        // VUID-VkPhysicalDeviceRobustness2PropertiesEXT-sType-sType

        // Validation code for VkSamplerCustomBorderColorCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT: {  // Covers
                                                                               // VUID-VkSamplerCustomBorderColorCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkSamplerCustomBorderColorCreateInfoEXT);
                VkSamplerCustomBorderColorCreateInfoEXT* structure = (VkSamplerCustomBorderColorCreateInfoEXT*)header;
                skip |= ValidateRangedEnum(pNext_loc.dot(Field::format), "VkFormat", structure->format,
                                           "VUID-VkSamplerCustomBorderColorCreateInfoEXT-format-parameter");
            }
        } break;

        // No Validation code for VkPhysicalDeviceCustomBorderColorPropertiesEXT structure members  -- Covers
        // VUID-VkPhysicalDeviceCustomBorderColorPropertiesEXT-sType-sType

        // Validation code for VkPhysicalDeviceCustomBorderColorFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT: {  // Covers
                                                                                    // VUID-VkPhysicalDeviceCustomBorderColorFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceCustomBorderColorFeaturesEXT);
                VkPhysicalDeviceCustomBorderColorFeaturesEXT* structure = (VkPhysicalDeviceCustomBorderColorFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::customBorderColors), structure->customBorderColors);

                skip |=
                    ValidateBool32(pNext_loc.dot(Field::customBorderColorWithoutFormat), structure->customBorderColorWithoutFormat);
            }
        } break;

        // Validation code for VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT: {  // Covers
                                                                                          // VUID-VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT);
                VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* structure =
                    (VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::ycbcr2plane444Formats), structure->ycbcr2plane444Formats);
            }
        } break;

        // Validation code for VkPhysicalDevice4444FormatsFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT: {  // Covers
                                                                             // VUID-VkPhysicalDevice4444FormatsFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDevice4444FormatsFeaturesEXT);
                VkPhysicalDevice4444FormatsFeaturesEXT* structure = (VkPhysicalDevice4444FormatsFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::formatA4R4G4B4), structure->formatA4R4G4B4);

                skip |= ValidateBool32(pNext_loc.dot(Field::formatA4B4G4R4), structure->formatA4B4G4R4);
            }
        } break;

        // Validation code for VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT: {  // Covers
                                                                                           // VUID-VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT);
                VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* structure =
                    (VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::vertexInputDynamicState), structure->vertexInputDynamicState);
            }
        } break;
#ifdef VK_USE_PLATFORM_SCI

        // No Validation code for VkExportFenceSciSyncInfoNV structure members  -- Covers
        // VUID-VkExportFenceSciSyncInfoNV-sType-sType

        // No Validation code for VkExportSemaphoreSciSyncInfoNV structure members  -- Covers
        // VUID-VkExportSemaphoreSciSyncInfoNV-sType-sType

        // Validation code for VkPhysicalDeviceExternalSciSyncFeaturesNV structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_FEATURES_NV: {  // Covers
                                                                                 // VUID-VkPhysicalDeviceExternalSciSyncFeaturesNV-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceExternalSciSyncFeaturesNV);
                VkPhysicalDeviceExternalSciSyncFeaturesNV* structure = (VkPhysicalDeviceExternalSciSyncFeaturesNV*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::sciSyncFence), structure->sciSyncFence);

                skip |= ValidateBool32(pNext_loc.dot(Field::sciSyncSemaphore), structure->sciSyncSemaphore);

                skip |= ValidateBool32(pNext_loc.dot(Field::sciSyncImport), structure->sciSyncImport);

                skip |= ValidateBool32(pNext_loc.dot(Field::sciSyncExport), structure->sciSyncExport);
            }
        } break;

        // No Validation code for VkExportMemorySciBufInfoNV structure members  -- Covers
        // VUID-VkExportMemorySciBufInfoNV-sType-sType

        // Validation code for VkImportMemorySciBufInfoNV structure members
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_SCI_BUF_INFO_NV: {  // Covers VUID-VkImportMemorySciBufInfoNV-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkImportMemorySciBufInfoNV);
                VkImportMemorySciBufInfoNV* structure = (VkImportMemorySciBufInfoNV*)header;
                skip |= ValidateFlags(pNext_loc.dot(Field::handleType), "VkExternalMemoryHandleTypeFlagBits",
                                      AllVkExternalMemoryHandleTypeFlagBits, structure->handleType, kRequiredSingleBit,
                                      "VUID-VkImportMemorySciBufInfoNV-handleType-parameter",
                                      "VUID-VkImportMemorySciBufInfoNV-handleType-parameter");
            }
        } break;

        // Validation code for VkPhysicalDeviceExternalMemorySciBufFeaturesNV structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCI_BUF_FEATURES_NV: {  // Covers
                                                                                       // VUID-VkPhysicalDeviceExternalMemorySciBufFeaturesNV-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceExternalMemorySciBufFeaturesNV);
                VkPhysicalDeviceExternalMemorySciBufFeaturesNV* structure = (VkPhysicalDeviceExternalMemorySciBufFeaturesNV*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::sciBufImport), structure->sciBufImport);

                skip |= ValidateBool32(pNext_loc.dot(Field::sciBufExport), structure->sciBufExport);
            }
        } break;
#endif  // VK_USE_PLATFORM_SCI

        // Validation code for VkPhysicalDeviceExtendedDynamicState2FeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT: {  // Covers
                                                                                         // VUID-VkPhysicalDeviceExtendedDynamicState2FeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceExtendedDynamicState2FeaturesEXT);
                VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* structure =
                    (VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::extendedDynamicState2), structure->extendedDynamicState2);

                skip |= ValidateBool32(pNext_loc.dot(Field::extendedDynamicState2LogicOp), structure->extendedDynamicState2LogicOp);

                skip |= ValidateBool32(pNext_loc.dot(Field::extendedDynamicState2PatchControlPoints),
                                       structure->extendedDynamicState2PatchControlPoints);
            }
        } break;

        // Validation code for VkPhysicalDeviceColorWriteEnableFeaturesEXT structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT: {  // Covers
                                                                                   // VUID-VkPhysicalDeviceColorWriteEnableFeaturesEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceColorWriteEnableFeaturesEXT);
                VkPhysicalDeviceColorWriteEnableFeaturesEXT* structure = (VkPhysicalDeviceColorWriteEnableFeaturesEXT*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::colorWriteEnable), structure->colorWriteEnable);
            }
        } break;

        // Validation code for VkPipelineColorWriteCreateInfoEXT structure members
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT: {  // Covers VUID-VkPipelineColorWriteCreateInfoEXT-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPipelineColorWriteCreateInfoEXT);
                VkPipelineColorWriteCreateInfoEXT* structure = (VkPipelineColorWriteCreateInfoEXT*)header;
                skip |= ValidateBool32Array(pNext_loc.dot(Field::attachmentCount), pNext_loc.dot(Field::pColorWriteEnables),
                                            structure->attachmentCount, structure->pColorWriteEnables, false, true);
            }
        } break;

        // No Validation code for VkApplicationParametersEXT structure members  -- Covers
        // VUID-VkApplicationParametersEXT-sType-sType
#ifdef VK_USE_PLATFORM_SCI

        // Validation code for VkPhysicalDeviceExternalSciSync2FeaturesNV structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_2_FEATURES_NV: {  // Covers
                                                                                   // VUID-VkPhysicalDeviceExternalSciSync2FeaturesNV-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkPhysicalDeviceExternalSciSync2FeaturesNV);
                VkPhysicalDeviceExternalSciSync2FeaturesNV* structure = (VkPhysicalDeviceExternalSciSync2FeaturesNV*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::sciSyncFence), structure->sciSyncFence);

                skip |= ValidateBool32(pNext_loc.dot(Field::sciSyncSemaphore2), structure->sciSyncSemaphore2);

                skip |= ValidateBool32(pNext_loc.dot(Field::sciSyncImport), structure->sciSyncImport);

                skip |= ValidateBool32(pNext_loc.dot(Field::sciSyncExport), structure->sciSyncExport);
            }
        } break;

        // Validation code for VkSemaphoreSciSyncCreateInfoNV structure members
        case VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_CREATE_INFO_NV: {  // Covers VUID-VkSemaphoreSciSyncCreateInfoNV-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc = loc.pNext(Struct::VkSemaphoreSciSyncCreateInfoNV);
                VkSemaphoreSciSyncCreateInfoNV* structure = (VkSemaphoreSciSyncCreateInfoNV*)header;
                skip |= ValidateRequiredHandle(pNext_loc.dot(Field::semaphorePool), structure->semaphorePool);

                skip |= ValidateRequiredPointer(pNext_loc.dot(Field::pFence), structure->pFence,
                                                "VUID-VkSemaphoreSciSyncCreateInfoNV-pFence-parameter");
            }
        } break;

        // No Validation code for VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV structure members  -- Covers
        // VUID-VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV-sType-sType
#endif  // VK_USE_PLATFORM_SCI
#ifdef VK_USE_PLATFORM_SCREEN_QNX

        // No Validation code for VkScreenBufferFormatPropertiesQNX structure members  -- Covers
        // VUID-VkScreenBufferFormatPropertiesQNX-sType-sType

        // No Validation code for VkImportScreenBufferInfoQNX structure members  -- Covers
        // VUID-VkImportScreenBufferInfoQNX-sType-sType

        // No Validation code for VkExternalFormatQNX structure members  -- Covers VUID-VkExternalFormatQNX-sType-sType

        // Validation code for VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX structure members
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX: {  // Covers
                                                                                              // VUID-VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX-sType-sType
            if (is_const_param) {
                [[maybe_unused]] const Location pNext_loc =
                    loc.pNext(Struct::VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX);
                VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX* structure =
                    (VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX*)header;
                skip |= ValidateBool32(pNext_loc.dot(Field::screenBufferImport), structure->screenBufferImport);
            }
        } break;
#endif  // VK_USE_PLATFORM_SCREEN_QNX

        default:
            skip = false;
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateInstance(const VkInstanceCreateInfo* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkInstance* pInstance,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO, true, "VUID-vkCreateInstance-pCreateInfo-parameter",
                               "VUID-VkInstanceCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkInstanceCreateInfo = {VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
                                                                     VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT,
                                                                     VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkInstanceCreateInfo.size(),
                                    allowed_structs_VkInstanceCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkInstanceCreateInfo-pNext-pNext", "VUID-VkInstanceCreateInfo-sType-unique", false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkInstanceCreateInfo-flags-zerobitmask");

        skip |= ValidateStructType(pCreateInfo_loc.dot(Field::pApplicationInfo), "VK_STRUCTURE_TYPE_APPLICATION_INFO",
                                   pCreateInfo->pApplicationInfo, VK_STRUCTURE_TYPE_APPLICATION_INFO, false,
                                   "VUID-VkInstanceCreateInfo-pApplicationInfo-parameter", "VUID-VkApplicationInfo-sType-sType");

        if (pCreateInfo->pApplicationInfo != nullptr) {
            [[maybe_unused]] const Location pApplicationInfo_loc = pCreateInfo_loc.dot(Field::pApplicationInfo);
            constexpr std::array allowed_structs_VkApplicationInfo = {VK_STRUCTURE_TYPE_APPLICATION_PARAMETERS_EXT};

            skip |= ValidateStructPnext(pApplicationInfo_loc, pCreateInfo->pApplicationInfo->pNext,
                                        allowed_structs_VkApplicationInfo.size(), allowed_structs_VkApplicationInfo.data(),
                                        GeneratedVulkanHeaderVersion, "VUID-VkApplicationInfo-pNext-pNext",
                                        "VUID-VkApplicationInfo-sType-unique", false, true);
        }

        skip |= ValidateStringArray(pCreateInfo_loc.dot(Field::enabledLayerCount), pCreateInfo_loc.dot(Field::ppEnabledLayerNames),
                                    pCreateInfo->enabledLayerCount, pCreateInfo->ppEnabledLayerNames, false, true, kVUIDUndefined,
                                    "VUID-VkInstanceCreateInfo-ppEnabledLayerNames-parameter");

        skip |= ValidateStringArray(pCreateInfo_loc.dot(Field::enabledExtensionCount),
                                    pCreateInfo_loc.dot(Field::ppEnabledExtensionNames), pCreateInfo->enabledExtensionCount,
                                    pCreateInfo->ppEnabledExtensionNames, false, true, kVUIDUndefined,
                                    "VUID-VkInstanceCreateInfo-ppEnabledExtensionNames-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateInstance-pAllocator-null", "vkCreateInstance(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pInstance), pInstance, "VUID-vkCreateInstance-pInstance-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateInstance(pCreateInfo, pAllocator, pInstance, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyInstance-pAllocator-null", "vkDestroyInstance(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateEnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount,
                                                                  VkPhysicalDevice* pPhysicalDevices,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateArray(loc.dot(Field::pPhysicalDeviceCount), loc.dot(Field::pPhysicalDevices), pPhysicalDeviceCount,
                          &pPhysicalDevices, true, false, false, kVUIDUndefined,
                          "VUID-vkEnumeratePhysicalDevices-pPhysicalDevices-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice,
                                                                   VkPhysicalDeviceFeatures* pFeatures,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredPointer(loc.dot(Field::pFeatures), pFeatures, "VUID-vkGetPhysicalDeviceFeatures-pFeatures-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                           VkFormatProperties* pFormatProperties,
                                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |=
        ValidateRangedEnum(loc.dot(Field::format), "VkFormat", format, "VUID-vkGetPhysicalDeviceFormatProperties-format-parameter");
    skip |= ValidateRequiredPointer(loc.dot(Field::pFormatProperties), pFormatProperties,
                                    "VUID-vkGetPhysicalDeviceFormatProperties-pFormatProperties-parameter");
    if (pFormatProperties != nullptr) {
        [[maybe_unused]] const Location pFormatProperties_loc = loc.dot(Field::pFormatProperties);
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                                VkImageType type, VkImageTiling tiling,
                                                                                VkImageUsageFlags usage, VkImageCreateFlags flags,
                                                                                VkImageFormatProperties* pImageFormatProperties,
                                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRangedEnum(loc.dot(Field::format), "VkFormat", format,
                               "VUID-vkGetPhysicalDeviceImageFormatProperties-format-parameter");
    skip |= ValidateRangedEnum(loc.dot(Field::type), "VkImageType", type,
                               "VUID-vkGetPhysicalDeviceImageFormatProperties-type-parameter");
    skip |= ValidateRangedEnum(loc.dot(Field::tiling), "VkImageTiling", tiling,
                               "VUID-vkGetPhysicalDeviceImageFormatProperties-tiling-parameter");
    skip |= ValidateFlags(loc.dot(Field::usage), "VkImageUsageFlagBits", AllVkImageUsageFlagBits, usage, kRequiredFlags,
                          "VUID-vkGetPhysicalDeviceImageFormatProperties-usage-parameter",
                          "VUID-vkGetPhysicalDeviceImageFormatProperties-usage-requiredbitmask");
    skip |= ValidateFlags(loc.dot(Field::flags), "VkImageCreateFlagBits", AllVkImageCreateFlagBits, flags, kOptionalFlags,
                          "VUID-vkGetPhysicalDeviceImageFormatProperties-flags-parameter");
    skip |= ValidateRequiredPointer(loc.dot(Field::pImageFormatProperties), pImageFormatProperties,
                                    "VUID-vkGetPhysicalDeviceImageFormatProperties-pImageFormatProperties-parameter");
    if (pImageFormatProperties != nullptr) {
        [[maybe_unused]] const Location pImageFormatProperties_loc = loc.dot(Field::pImageFormatProperties);
        // No xml-driven validation
    }
    if (!skip)
        skip |= manual_PreCallValidateGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags,
                                                                             pImageFormatProperties, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice,
                                                                     VkPhysicalDeviceProperties* pProperties,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredPointer(loc.dot(Field::pProperties), pProperties,
                                    "VUID-vkGetPhysicalDeviceProperties-pProperties-parameter");
    if (pProperties != nullptr) {
        [[maybe_unused]] const Location pProperties_loc = loc.dot(Field::pProperties);
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice,
                                                                                uint32_t* pQueueFamilyPropertyCount,
                                                                                VkQueueFamilyProperties* pQueueFamilyProperties,
                                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateArray(loc.dot(Field::pQueueFamilyPropertyCount), loc.dot(Field::pQueueFamilyProperties),
                          pQueueFamilyPropertyCount, &pQueueFamilyProperties, true, false, false, kVUIDUndefined,
                          "VUID-vkGetPhysicalDeviceQueueFamilyProperties-pQueueFamilyProperties-parameter");
    if (pQueueFamilyProperties != nullptr) {
        for (uint32_t pQueueFamilyPropertyIndex = 0; pQueueFamilyPropertyIndex < *pQueueFamilyPropertyCount;
             ++pQueueFamilyPropertyIndex) {
            [[maybe_unused]] const Location pQueueFamilyProperties_loc =
                loc.dot(Field::pQueueFamilyProperties, pQueueFamilyPropertyIndex);
            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice,
                                                                           VkPhysicalDeviceMemoryProperties* pMemoryProperties,
                                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredPointer(loc.dot(Field::pMemoryProperties), pMemoryProperties,
                                    "VUID-vkGetPhysicalDeviceMemoryProperties-pMemoryProperties-parameter");
    if (pMemoryProperties != nullptr) {
        [[maybe_unused]] const Location pMemoryProperties_loc = loc.dot(Field::pMemoryProperties);
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkDevice* pDevice,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO, true, "VUID-vkCreateDevice-pCreateInfo-parameter",
                               "VUID-VkDeviceCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkDeviceCreateInfo = {
            VK_STRUCTURE_TYPE_APPLICATION_PARAMETERS_EXT,
            VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO,
            VK_STRUCTURE_TYPE_DEVICE_OBJECT_RESERVATION_CREATE_INFO,
            VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO,
            VK_STRUCTURE_TYPE_DEVICE_SEMAPHORE_SCI_SYNC_POOL_RESERVATION_CREATE_INFO_NV,
            VK_STRUCTURE_TYPE_FAULT_CALLBACK_INFO,
            VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_RESERVATION_INFO_KHR,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCI_BUF_FEATURES_NV,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_2_FEATURES_NV,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_FEATURES_NV,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkDeviceCreateInfo.size(),
                                    allowed_structs_VkDeviceCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkDeviceCreateInfo-pNext-pNext", "VUID-VkDeviceCreateInfo-sType-unique", true, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkDeviceCreateInfo-flags-zerobitmask");

        skip |= ValidateStructTypeArray(
            pCreateInfo_loc.dot(Field::queueCreateInfoCount), pCreateInfo_loc.dot(Field::pQueueCreateInfos),
            "VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO", pCreateInfo->queueCreateInfoCount, pCreateInfo->pQueueCreateInfos,
            VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO, true, true, "VUID-VkDeviceQueueCreateInfo-sType-sType",
            "VUID-VkDeviceCreateInfo-pQueueCreateInfos-parameter", "VUID-VkDeviceCreateInfo-queueCreateInfoCount-arraylength");

        if (pCreateInfo->pQueueCreateInfos != nullptr) {
            for (uint32_t queueCreateInfoIndex = 0; queueCreateInfoIndex < pCreateInfo->queueCreateInfoCount;
                 ++queueCreateInfoIndex) {
                [[maybe_unused]] const Location pQueueCreateInfos_loc =
                    pCreateInfo_loc.dot(Field::pQueueCreateInfos, queueCreateInfoIndex);
                constexpr std::array allowed_structs_VkDeviceQueueCreateInfo = {
                    VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR};

                skip |= ValidateStructPnext(pQueueCreateInfos_loc, pCreateInfo->pQueueCreateInfos[queueCreateInfoIndex].pNext,
                                            allowed_structs_VkDeviceQueueCreateInfo.size(),
                                            allowed_structs_VkDeviceQueueCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                            "VUID-VkDeviceQueueCreateInfo-pNext-pNext", "VUID-VkDeviceQueueCreateInfo-sType-unique",
                                            true, true);

                skip |= ValidateFlags(pQueueCreateInfos_loc.dot(Field::flags), "VkDeviceQueueCreateFlagBits",
                                      AllVkDeviceQueueCreateFlagBits, pCreateInfo->pQueueCreateInfos[queueCreateInfoIndex].flags,
                                      kOptionalFlags, "VUID-VkDeviceQueueCreateInfo-flags-parameter");

                skip |=
                    ValidateArray(pQueueCreateInfos_loc.dot(Field::queueCount), pQueueCreateInfos_loc.dot(Field::pQueuePriorities),
                                  pCreateInfo->pQueueCreateInfos[queueCreateInfoIndex].queueCount,
                                  &pCreateInfo->pQueueCreateInfos[queueCreateInfoIndex].pQueuePriorities, true, true,
                                  "VUID-VkDeviceQueueCreateInfo-queueCount-arraylength",
                                  "VUID-VkDeviceQueueCreateInfo-pQueuePriorities-parameter");
            }
        }

        skip |= ValidateStringArray(pCreateInfo_loc.dot(Field::enabledLayerCount), pCreateInfo_loc.dot(Field::ppEnabledLayerNames),
                                    pCreateInfo->enabledLayerCount, pCreateInfo->ppEnabledLayerNames, false, true, kVUIDUndefined,
                                    "VUID-VkDeviceCreateInfo-ppEnabledLayerNames-parameter");

        skip |= ValidateStringArray(pCreateInfo_loc.dot(Field::enabledExtensionCount),
                                    pCreateInfo_loc.dot(Field::ppEnabledExtensionNames), pCreateInfo->enabledExtensionCount,
                                    pCreateInfo->ppEnabledExtensionNames, false, true, kVUIDUndefined,
                                    "VUID-VkDeviceCreateInfo-ppEnabledExtensionNames-parameter");

        if (pCreateInfo->pEnabledFeatures != nullptr) {
            [[maybe_unused]] const Location pEnabledFeatures_loc = pCreateInfo_loc.dot(Field::pEnabledFeatures);
            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::robustBufferAccess),
                                   pCreateInfo->pEnabledFeatures->robustBufferAccess);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::fullDrawIndexUint32),
                                   pCreateInfo->pEnabledFeatures->fullDrawIndexUint32);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::imageCubeArray), pCreateInfo->pEnabledFeatures->imageCubeArray);

            skip |=
                ValidateBool32(pEnabledFeatures_loc.dot(Field::independentBlend), pCreateInfo->pEnabledFeatures->independentBlend);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::geometryShader), pCreateInfo->pEnabledFeatures->geometryShader);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::tessellationShader),
                                   pCreateInfo->pEnabledFeatures->tessellationShader);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::sampleRateShading),
                                   pCreateInfo->pEnabledFeatures->sampleRateShading);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::dualSrcBlend), pCreateInfo->pEnabledFeatures->dualSrcBlend);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::logicOp), pCreateInfo->pEnabledFeatures->logicOp);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::multiDrawIndirect),
                                   pCreateInfo->pEnabledFeatures->multiDrawIndirect);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::drawIndirectFirstInstance),
                                   pCreateInfo->pEnabledFeatures->drawIndirectFirstInstance);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::depthClamp), pCreateInfo->pEnabledFeatures->depthClamp);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::depthBiasClamp), pCreateInfo->pEnabledFeatures->depthBiasClamp);

            skip |=
                ValidateBool32(pEnabledFeatures_loc.dot(Field::fillModeNonSolid), pCreateInfo->pEnabledFeatures->fillModeNonSolid);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::depthBounds), pCreateInfo->pEnabledFeatures->depthBounds);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::wideLines), pCreateInfo->pEnabledFeatures->wideLines);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::largePoints), pCreateInfo->pEnabledFeatures->largePoints);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::alphaToOne), pCreateInfo->pEnabledFeatures->alphaToOne);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::multiViewport), pCreateInfo->pEnabledFeatures->multiViewport);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::samplerAnisotropy),
                                   pCreateInfo->pEnabledFeatures->samplerAnisotropy);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::textureCompressionETC2),
                                   pCreateInfo->pEnabledFeatures->textureCompressionETC2);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::textureCompressionASTC_LDR),
                                   pCreateInfo->pEnabledFeatures->textureCompressionASTC_LDR);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::textureCompressionBC),
                                   pCreateInfo->pEnabledFeatures->textureCompressionBC);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::occlusionQueryPrecise),
                                   pCreateInfo->pEnabledFeatures->occlusionQueryPrecise);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::pipelineStatisticsQuery),
                                   pCreateInfo->pEnabledFeatures->pipelineStatisticsQuery);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::vertexPipelineStoresAndAtomics),
                                   pCreateInfo->pEnabledFeatures->vertexPipelineStoresAndAtomics);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::fragmentStoresAndAtomics),
                                   pCreateInfo->pEnabledFeatures->fragmentStoresAndAtomics);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderTessellationAndGeometryPointSize),
                                   pCreateInfo->pEnabledFeatures->shaderTessellationAndGeometryPointSize);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderImageGatherExtended),
                                   pCreateInfo->pEnabledFeatures->shaderImageGatherExtended);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderStorageImageExtendedFormats),
                                   pCreateInfo->pEnabledFeatures->shaderStorageImageExtendedFormats);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderStorageImageMultisample),
                                   pCreateInfo->pEnabledFeatures->shaderStorageImageMultisample);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderStorageImageReadWithoutFormat),
                                   pCreateInfo->pEnabledFeatures->shaderStorageImageReadWithoutFormat);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderStorageImageWriteWithoutFormat),
                                   pCreateInfo->pEnabledFeatures->shaderStorageImageWriteWithoutFormat);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderUniformBufferArrayDynamicIndexing),
                                   pCreateInfo->pEnabledFeatures->shaderUniformBufferArrayDynamicIndexing);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderSampledImageArrayDynamicIndexing),
                                   pCreateInfo->pEnabledFeatures->shaderSampledImageArrayDynamicIndexing);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderStorageBufferArrayDynamicIndexing),
                                   pCreateInfo->pEnabledFeatures->shaderStorageBufferArrayDynamicIndexing);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderStorageImageArrayDynamicIndexing),
                                   pCreateInfo->pEnabledFeatures->shaderStorageImageArrayDynamicIndexing);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderClipDistance),
                                   pCreateInfo->pEnabledFeatures->shaderClipDistance);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderCullDistance),
                                   pCreateInfo->pEnabledFeatures->shaderCullDistance);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderFloat64), pCreateInfo->pEnabledFeatures->shaderFloat64);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderInt64), pCreateInfo->pEnabledFeatures->shaderInt64);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderInt16), pCreateInfo->pEnabledFeatures->shaderInt16);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderResourceResidency),
                                   pCreateInfo->pEnabledFeatures->shaderResourceResidency);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::shaderResourceMinLod),
                                   pCreateInfo->pEnabledFeatures->shaderResourceMinLod);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::sparseBinding), pCreateInfo->pEnabledFeatures->sparseBinding);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::sparseResidencyBuffer),
                                   pCreateInfo->pEnabledFeatures->sparseResidencyBuffer);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::sparseResidencyImage2D),
                                   pCreateInfo->pEnabledFeatures->sparseResidencyImage2D);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::sparseResidencyImage3D),
                                   pCreateInfo->pEnabledFeatures->sparseResidencyImage3D);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::sparseResidency2Samples),
                                   pCreateInfo->pEnabledFeatures->sparseResidency2Samples);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::sparseResidency4Samples),
                                   pCreateInfo->pEnabledFeatures->sparseResidency4Samples);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::sparseResidency8Samples),
                                   pCreateInfo->pEnabledFeatures->sparseResidency8Samples);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::sparseResidency16Samples),
                                   pCreateInfo->pEnabledFeatures->sparseResidency16Samples);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::sparseResidencyAliased),
                                   pCreateInfo->pEnabledFeatures->sparseResidencyAliased);

            skip |= ValidateBool32(pEnabledFeatures_loc.dot(Field::variableMultisampleRate),
                                   pCreateInfo->pEnabledFeatures->variableMultisampleRate);

            skip |=
                ValidateBool32(pEnabledFeatures_loc.dot(Field::inheritedQueries), pCreateInfo->pEnabledFeatures->inheritedQueries);
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateDevice-pAllocator-null", "vkCreateDevice(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pDevice), pDevice, "VUID-vkCreateDevice-pDevice-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyDevice-pAllocator-null", "vkDestroyDevice(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex,
                                                        VkQueue* pQueue, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredPointer(loc.dot(Field::pQueue), pQueue, "VUID-vkGetDeviceQueue-pQueue-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits,
                                                     VkFence fence, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructTypeArray(loc.dot(Field::submitCount), loc.dot(Field::pSubmits), "VK_STRUCTURE_TYPE_SUBMIT_INFO",
                                    submitCount, pSubmits, VK_STRUCTURE_TYPE_SUBMIT_INFO, false, true,
                                    "VUID-VkSubmitInfo-sType-sType", "VUID-vkQueueSubmit-pSubmits-parameter", kVUIDUndefined);
    if (pSubmits != nullptr) {
        for (uint32_t submitIndex = 0; submitIndex < submitCount; ++submitIndex) {
            [[maybe_unused]] const Location pSubmits_loc = loc.dot(Field::pSubmits, submitIndex);
            constexpr std::array allowed_structs_VkSubmitInfo = {
                VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO, VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR,
                VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO, VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO};

            skip |= ValidateStructPnext(pSubmits_loc, pSubmits[submitIndex].pNext, allowed_structs_VkSubmitInfo.size(),
                                        allowed_structs_VkSubmitInfo.data(), GeneratedVulkanHeaderVersion,
                                        "VUID-VkSubmitInfo-pNext-pNext", "VUID-VkSubmitInfo-sType-unique", false, true);

            skip |= ValidateArray(pSubmits_loc.dot(Field::waitSemaphoreCount), pSubmits_loc.dot(Field::pWaitSemaphores),
                                  pSubmits[submitIndex].waitSemaphoreCount, &pSubmits[submitIndex].pWaitSemaphores, false, true,
                                  kVUIDUndefined, "VUID-VkSubmitInfo-pWaitSemaphores-parameter");

            skip |=
                ValidateFlagsArray(pSubmits_loc.dot(Field::waitSemaphoreCount), pSubmits_loc.dot(Field::pWaitDstStageMask),
                                   "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, pSubmits[submitIndex].waitSemaphoreCount,
                                   pSubmits[submitIndex].pWaitDstStageMask, false, "VUID-VkSubmitInfo-pWaitDstStageMask-parameter");

            skip |= ValidateArray(pSubmits_loc.dot(Field::commandBufferCount), pSubmits_loc.dot(Field::pCommandBuffers),
                                  pSubmits[submitIndex].commandBufferCount, &pSubmits[submitIndex].pCommandBuffers, false, true,
                                  kVUIDUndefined, "VUID-VkSubmitInfo-pCommandBuffers-parameter");

            skip |= ValidateArray(pSubmits_loc.dot(Field::signalSemaphoreCount), pSubmits_loc.dot(Field::pSignalSemaphores),
                                  pSubmits[submitIndex].signalSemaphoreCount, &pSubmits[submitIndex].pSignalSemaphores, false, true,
                                  kVUIDUndefined, "VUID-VkSubmitInfo-pSignalSemaphores-parameter");
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateQueueWaitIdle(VkQueue queue, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateDeviceWaitIdle(VkDevice device, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pAllocateInfo), "VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO", pAllocateInfo,
                               VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, true, "VUID-vkAllocateMemory-pAllocateInfo-parameter",
                               "VUID-VkMemoryAllocateInfo-sType-sType");
    if (pAllocateInfo != nullptr) {
        [[maybe_unused]] const Location pAllocateInfo_loc = loc.dot(Field::pAllocateInfo);
        constexpr std::array allowed_structs_VkMemoryAllocateInfo = {VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO,
                                                                     VK_STRUCTURE_TYPE_EXPORT_MEMORY_SCI_BUF_INFO_NV,
                                                                     VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR,
                                                                     VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT,
                                                                     VK_STRUCTURE_TYPE_IMPORT_MEMORY_SCI_BUF_INFO_NV,
                                                                     VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX,
                                                                     VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO,
                                                                     VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO,
                                                                     VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO};

        skip |= ValidateStructPnext(pAllocateInfo_loc, pAllocateInfo->pNext, allowed_structs_VkMemoryAllocateInfo.size(),
                                    allowed_structs_VkMemoryAllocateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkMemoryAllocateInfo-pNext-pNext", "VUID-VkMemoryAllocateInfo-sType-unique", false, true);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkAllocateMemory-pAllocator-null", "vkAllocateMemory(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pMemory), pMemory, "VUID-vkAllocateMemory-pMemory-parameter");
    if (!skip) skip |= manual_PreCallValidateAllocateMemory(device, pAllocateInfo, pAllocator, pMemory, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size,
                                                   VkMemoryMapFlags flags, void** ppData, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::memory), memory);
    skip |= ValidateReservedFlags(loc.dot(Field::flags), flags, "VUID-vkMapMemory-flags-zerobitmask");
    return skip;
}

bool StatelessValidation::PreCallValidateUnmapMemory(VkDevice device, VkDeviceMemory memory, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::memory), memory);
    return skip;
}

bool StatelessValidation::PreCallValidateFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                                 const VkMappedMemoryRange* pMemoryRanges,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructTypeArray(
        loc.dot(Field::memoryRangeCount), loc.dot(Field::pMemoryRanges), "VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE", memoryRangeCount,
        pMemoryRanges, VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE, true, true, "VUID-VkMappedMemoryRange-sType-sType",
        "VUID-vkFlushMappedMemoryRanges-pMemoryRanges-parameter", "VUID-vkFlushMappedMemoryRanges-memoryRangeCount-arraylength");
    if (pMemoryRanges != nullptr) {
        for (uint32_t memoryRangeIndex = 0; memoryRangeIndex < memoryRangeCount; ++memoryRangeIndex) {
            [[maybe_unused]] const Location pMemoryRanges_loc = loc.dot(Field::pMemoryRanges, memoryRangeIndex);
            skip |= ValidateStructPnext(pMemoryRanges_loc, pMemoryRanges[memoryRangeIndex].pNext, 0, nullptr,
                                        GeneratedVulkanHeaderVersion, "VUID-VkMappedMemoryRange-pNext-pNext", kVUIDUndefined, false,
                                        true);

            skip |= ValidateRequiredHandle(pMemoryRanges_loc.dot(Field::memory), pMemoryRanges[memoryRangeIndex].memory);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount,
                                                                      const VkMappedMemoryRange* pMemoryRanges,
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructTypeArray(loc.dot(Field::memoryRangeCount), loc.dot(Field::pMemoryRanges),
                                    "VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE", memoryRangeCount, pMemoryRanges,
                                    VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE, true, true, "VUID-VkMappedMemoryRange-sType-sType",
                                    "VUID-vkInvalidateMappedMemoryRanges-pMemoryRanges-parameter",
                                    "VUID-vkInvalidateMappedMemoryRanges-memoryRangeCount-arraylength");
    if (pMemoryRanges != nullptr) {
        for (uint32_t memoryRangeIndex = 0; memoryRangeIndex < memoryRangeCount; ++memoryRangeIndex) {
            [[maybe_unused]] const Location pMemoryRanges_loc = loc.dot(Field::pMemoryRanges, memoryRangeIndex);
            skip |= ValidateStructPnext(pMemoryRanges_loc, pMemoryRanges[memoryRangeIndex].pNext, 0, nullptr,
                                        GeneratedVulkanHeaderVersion, "VUID-VkMappedMemoryRange-pNext-pNext", kVUIDUndefined, false,
                                        true);

            skip |= ValidateRequiredHandle(pMemoryRanges_loc.dot(Field::memory), pMemoryRanges[memoryRangeIndex].memory);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory,
                                                                   VkDeviceSize* pCommittedMemoryInBytes,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::memory), memory);
    skip |= ValidateRequiredPointer(loc.dot(Field::pCommittedMemoryInBytes), pCommittedMemoryInBytes,
                                    "VUID-vkGetDeviceMemoryCommitment-pCommittedMemoryInBytes-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory,
                                                          VkDeviceSize memoryOffset, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::buffer), buffer);
    skip |= ValidateRequiredHandle(loc.dot(Field::memory), memory);
    return skip;
}

bool StatelessValidation::PreCallValidateBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory,
                                                         VkDeviceSize memoryOffset, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::image), image);
    skip |= ValidateRequiredHandle(loc.dot(Field::memory), memory);
    return skip;
}

bool StatelessValidation::PreCallValidateGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer,
                                                                     VkMemoryRequirements* pMemoryRequirements,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::buffer), buffer);
    skip |= ValidateRequiredPointer(loc.dot(Field::pMemoryRequirements), pMemoryRequirements,
                                    "VUID-vkGetBufferMemoryRequirements-pMemoryRequirements-parameter");
    if (pMemoryRequirements != nullptr) {
        [[maybe_unused]] const Location pMemoryRequirements_loc = loc.dot(Field::pMemoryRequirements);
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetImageMemoryRequirements(VkDevice device, VkImage image,
                                                                    VkMemoryRequirements* pMemoryRequirements,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::image), image);
    skip |= ValidateRequiredPointer(loc.dot(Field::pMemoryRequirements), pMemoryRequirements,
                                    "VUID-vkGetImageMemoryRequirements-pMemoryRequirements-parameter");
    if (pMemoryRequirements != nullptr) {
        [[maybe_unused]] const Location pMemoryRequirements_loc = loc.dot(Field::pMemoryRequirements);
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkFence* pFence,
                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_FENCE_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, true, "VUID-vkCreateFence-pCreateInfo-parameter",
                               "VUID-VkFenceCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkFenceCreateInfo = {VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO,
                                                                  VK_STRUCTURE_TYPE_EXPORT_FENCE_SCI_SYNC_INFO_NV};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkFenceCreateInfo.size(),
                                    allowed_structs_VkFenceCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkFenceCreateInfo-pNext-pNext", "VUID-VkFenceCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkFenceCreateFlagBits", AllVkFenceCreateFlagBits,
                              pCreateInfo->flags, kOptionalFlags, "VUID-VkFenceCreateInfo-flags-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateFence-pAllocator-null", "vkCreateFence(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pFence), pFence, "VUID-vkCreateFence-pFence-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyFence-pAllocator-null", "vkDestroyFence(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences,
                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateHandleArray(loc.dot(Field::fenceCount), loc.dot(Field::pFences), fenceCount, pFences, true, true,
                                "VUID-vkResetFences-fenceCount-arraylength");
    return skip;
}

bool StatelessValidation::PreCallValidateGetFenceStatus(VkDevice device, VkFence fence, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::fence), fence);
    return skip;
}

bool StatelessValidation::PreCallValidateWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences,
                                                       VkBool32 waitAll, uint64_t timeout, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateHandleArray(loc.dot(Field::fenceCount), loc.dot(Field::pFences), fenceCount, pFences, true, true,
                                "VUID-vkWaitForFences-fenceCount-arraylength");
    skip |= ValidateBool32(loc.dot(Field::waitAll), waitAll);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO, true, "VUID-vkCreateSemaphore-pCreateInfo-parameter",
                               "VUID-VkSemaphoreCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkSemaphoreCreateInfo = {
            VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO, VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_SCI_SYNC_INFO_NV,
            VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_CREATE_INFO_NV, VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO};

        skip |=
            ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkSemaphoreCreateInfo.size(),
                                allowed_structs_VkSemaphoreCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkSemaphoreCreateInfo-pNext-pNext", "VUID-VkSemaphoreCreateInfo-sType-unique", false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkSemaphoreCreateInfo-flags-zerobitmask");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateSemaphore-pAllocator-null", "vkCreateSemaphore(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pSemaphore), pSemaphore, "VUID-vkCreateSemaphore-pSemaphore-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroySemaphore(VkDevice device, VkSemaphore semaphore,
                                                          const VkAllocationCallbacks* pAllocator,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroySemaphore-pAllocator-null", "vkDestroySemaphore(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkEvent* pEvent,
                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_EVENT_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_EVENT_CREATE_INFO, true, "VUID-vkCreateEvent-pCreateInfo-parameter",
                               "VUID-VkEventCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkEventCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkEventCreateFlagBits", AllVkEventCreateFlagBits,
                              pCreateInfo->flags, kOptionalFlags, "VUID-VkEventCreateInfo-flags-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateEvent-pAllocator-null", "vkCreateEvent(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pEvent), pEvent, "VUID-vkCreateEvent-pEvent-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateEvent(device, pCreateInfo, pAllocator, pEvent, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyEvent-pAllocator-null", "vkDestroyEvent(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetEventStatus(VkDevice device, VkEvent event, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::event), event);
    return skip;
}

bool StatelessValidation::PreCallValidateSetEvent(VkDevice device, VkEvent event, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::event), event);
    return skip;
}

bool StatelessValidation::PreCallValidateResetEvent(VkDevice device, VkEvent event, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::event), event);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO, true, "VUID-vkCreateQueryPool-pCreateInfo-parameter",
                               "VUID-VkQueryPoolCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkQueryPoolCreateInfo = {VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR};

        skip |=
            ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkQueryPoolCreateInfo.size(),
                                allowed_structs_VkQueryPoolCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkQueryPoolCreateInfo-pNext-pNext", "VUID-VkQueryPoolCreateInfo-sType-unique", false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkQueryPoolCreateInfo-flags-zerobitmask");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::queryType), "VkQueryType", pCreateInfo->queryType,
                                   "VUID-VkQueryPoolCreateInfo-queryType-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateQueryPool-pAllocator-null", "vkCreateQueryPool(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pQueryPool), pQueryPool, "VUID-vkCreateQueryPool-pQueryPool-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                                             uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride,
                                                             VkQueryResultFlags flags, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::queryPool), queryPool);
    skip |= ValidateArray(loc.dot(Field::dataSize), loc.dot(Field::pData), dataSize, &pData, true, true,
                          "VUID-vkGetQueryPoolResults-dataSize-arraylength", "VUID-vkGetQueryPoolResults-pData-parameter");
    skip |= ValidateFlags(loc.dot(Field::flags), "VkQueryResultFlagBits", AllVkQueryResultFlagBits, flags, kOptionalFlags,
                          "VUID-vkGetQueryPoolResults-flags-parameter");
    if (!skip)
        skip |= manual_PreCallValidateGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags,
                                                          error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO, true, "VUID-vkCreateBuffer-pCreateInfo-parameter",
                               "VUID-VkBufferCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkBufferCreateInfo = {VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO,
                                                                   VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkBufferCreateInfo.size(),
                                    allowed_structs_VkBufferCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkBufferCreateInfo-pNext-pNext", "VUID-VkBufferCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkBufferCreateFlagBits", AllVkBufferCreateFlagBits,
                              pCreateInfo->flags, kOptionalFlags, "VUID-VkBufferCreateInfo-flags-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::sharingMode), "VkSharingMode", pCreateInfo->sharingMode,
                                   "VUID-VkBufferCreateInfo-sharingMode-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateBuffer-pAllocator-null", "vkCreateBuffer(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pBuffer), pBuffer, "VUID-vkCreateBuffer-pBuffer-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateBuffer(device, pCreateInfo, pAllocator, pBuffer, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyBuffer-pAllocator-null", "vkDestroyBuffer(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator, VkBufferView* pView,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO, true, "VUID-vkCreateBufferView-pCreateInfo-parameter",
                               "VUID-VkBufferViewCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkBufferViewCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkBufferViewCreateInfo-flags-zerobitmask");

        skip |= ValidateRequiredHandle(pCreateInfo_loc.dot(Field::buffer), pCreateInfo->buffer);

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::format), "VkFormat", pCreateInfo->format,
                                   "VUID-VkBufferViewCreateInfo-format-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateBufferView-pAllocator-null", "vkCreateBufferView(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pView), pView, "VUID-vkCreateBufferView-pView-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateBufferView(device, pCreateInfo, pAllocator, pView, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyBufferView(VkDevice device, VkBufferView bufferView,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyBufferView-pAllocator-null", "vkDestroyBufferView(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkImage* pImage,
                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO, true, "VUID-vkCreateImage-pCreateInfo-parameter",
                               "VUID-VkImageCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkImageCreateInfo = {
            VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX,
            VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO,
            VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT,
            VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT,
            VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO,
            VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO,
            VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkImageCreateInfo.size(),
                                    allowed_structs_VkImageCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkImageCreateInfo-pNext-pNext", "VUID-VkImageCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkImageCreateFlagBits", AllVkImageCreateFlagBits,
                              pCreateInfo->flags, kOptionalFlags, "VUID-VkImageCreateInfo-flags-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::imageType), "VkImageType", pCreateInfo->imageType,
                                   "VUID-VkImageCreateInfo-imageType-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::format), "VkFormat", pCreateInfo->format,
                                   "VUID-VkImageCreateInfo-format-parameter");

        // No xml-driven validation

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::samples), "VkSampleCountFlagBits", AllVkSampleCountFlagBits,
                              pCreateInfo->samples, kRequiredSingleBit, "VUID-VkImageCreateInfo-samples-parameter",
                              "VUID-VkImageCreateInfo-samples-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::tiling), "VkImageTiling", pCreateInfo->tiling,
                                   "VUID-VkImageCreateInfo-tiling-parameter");

        skip |=
            ValidateFlags(pCreateInfo_loc.dot(Field::usage), "VkImageUsageFlagBits", AllVkImageUsageFlagBits, pCreateInfo->usage,
                          kRequiredFlags, "VUID-VkImageCreateInfo-usage-parameter", "VUID-VkImageCreateInfo-usage-requiredbitmask");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::sharingMode), "VkSharingMode", pCreateInfo->sharingMode,
                                   "VUID-VkImageCreateInfo-sharingMode-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::initialLayout), "VkImageLayout", pCreateInfo->initialLayout,
                                   "VUID-VkImageCreateInfo-initialLayout-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateImage-pAllocator-null", "vkCreateImage(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pImage), pImage, "VUID-vkCreateImage-pImage-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateImage(device, pCreateInfo, pAllocator, pImage, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyImage-pAllocator-null", "vkDestroyImage(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetImageSubresourceLayout(VkDevice device, VkImage image,
                                                                   const VkImageSubresource* pSubresource,
                                                                   VkSubresourceLayout* pLayout,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::image), image);
    skip |= ValidateRequiredPointer(loc.dot(Field::pSubresource), pSubresource,
                                    "VUID-vkGetImageSubresourceLayout-pSubresource-parameter");
    if (pSubresource != nullptr) {
        [[maybe_unused]] const Location pSubresource_loc = loc.dot(Field::pSubresource);
        skip |= ValidateFlags(pSubresource_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                              pSubresource->aspectMask, kRequiredFlags, "VUID-VkImageSubresource-aspectMask-parameter",
                              "VUID-VkImageSubresource-aspectMask-requiredbitmask");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pLayout), pLayout, "VUID-vkGetImageSubresourceLayout-pLayout-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator, VkImageView* pView,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO, true, "VUID-vkCreateImageView-pCreateInfo-parameter",
                               "VUID-VkImageViewCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkImageViewCreateInfo = {VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT,
                                                                      VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO,
                                                                      VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO};

        skip |=
            ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkImageViewCreateInfo.size(),
                                allowed_structs_VkImageViewCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkImageViewCreateInfo-pNext-pNext", "VUID-VkImageViewCreateInfo-sType-unique", false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkImageViewCreateInfo-flags-zerobitmask");

        skip |= ValidateRequiredHandle(pCreateInfo_loc.dot(Field::image), pCreateInfo->image);

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::viewType), "VkImageViewType", pCreateInfo->viewType,
                                   "VUID-VkImageViewCreateInfo-viewType-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::format), "VkFormat", pCreateInfo->format,
                                   "VUID-VkImageViewCreateInfo-format-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::r), "VkComponentSwizzle", pCreateInfo->components.r,
                                   "VUID-VkComponentMapping-r-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::g), "VkComponentSwizzle", pCreateInfo->components.g,
                                   "VUID-VkComponentMapping-g-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::b), "VkComponentSwizzle", pCreateInfo->components.b,
                                   "VUID-VkComponentMapping-b-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::a), "VkComponentSwizzle", pCreateInfo->components.a,
                                   "VUID-VkComponentMapping-a-parameter");

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                              pCreateInfo->subresourceRange.aspectMask, kRequiredFlags,
                              "VUID-VkImageSubresourceRange-aspectMask-parameter",
                              "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateImageView-pAllocator-null", "vkCreateImageView(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pView), pView, "VUID-vkCreateImageView-pView-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateImageView(device, pCreateInfo, pAllocator, pView, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyImageView(VkDevice device, VkImageView imageView,
                                                          const VkAllocationCallbacks* pAllocator,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyImageView-pAllocator-null", "vkDestroyImageView(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                                             const VkAllocationCallbacks* pAllocator,
                                                             VkPipelineCache* pPipelineCache, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO, true,
                               "VUID-vkCreatePipelineCache-pCreateInfo-parameter", "VUID-VkPipelineCacheCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkPipelineCacheCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkPipelineCacheCreateFlagBits", AllVkPipelineCacheCreateFlagBits,
                              pCreateInfo->flags, kOptionalFlags, "VUID-VkPipelineCacheCreateInfo-flags-parameter");

        skip |= ValidateArray(pCreateInfo_loc.dot(Field::initialDataSize), pCreateInfo_loc.dot(Field::pInitialData),
                              pCreateInfo->initialDataSize, &pCreateInfo->pInitialData, true, true,
                              "VUID-VkPipelineCacheCreateInfo-initialDataSize-arraylength",
                              "VUID-VkPipelineCacheCreateInfo-pInitialData-parameter");
    }
    if (pAllocator != nullptr) {
        skip |=
            LogError(instance, "VUID-vkCreatePipelineCache-pAllocator-null", "vkCreatePipelineCache(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pPipelineCache), pPipelineCache,
                                    "VUID-vkCreatePipelineCache-pPipelineCache-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache,
                                                              const VkAllocationCallbacks* pAllocator,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |=
            LogError(instance, "VUID-vkDestroyPipelineCache-pAllocator-null", "vkDestroyPipelineCache(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                                 uint32_t createInfoCount,
                                                                 const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                                 const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::pipelineCache), pipelineCache);
    skip |= ValidateStructTypeArray(
        loc.dot(Field::createInfoCount), loc.dot(Field::pCreateInfos), "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO",
        createInfoCount, pCreateInfos, VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO, true, true,
        "VUID-VkGraphicsPipelineCreateInfo-sType-sType", "VUID-vkCreateGraphicsPipelines-pCreateInfos-parameter",
        "VUID-vkCreateGraphicsPipelines-createInfoCount-arraylength");
    if (pCreateInfos != nullptr) {
        for (uint32_t createInfoIndex = 0; createInfoIndex < createInfoCount; ++createInfoIndex) {
            [[maybe_unused]] const Location pCreateInfos_loc = loc.dot(Field::pCreateInfos, createInfoIndex);
            constexpr std::array allowed_structs_VkGraphicsPipelineCreateInfo = {
                VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO,
                VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT,
                VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR,
                VK_STRUCTURE_TYPE_PIPELINE_OFFLINE_CREATE_INFO, VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO};

            skip |= ValidateStructPnext(
                pCreateInfos_loc, pCreateInfos[createInfoIndex].pNext, allowed_structs_VkGraphicsPipelineCreateInfo.size(),
                allowed_structs_VkGraphicsPipelineCreateInfo.data(), GeneratedVulkanHeaderVersion,
                "VUID-VkGraphicsPipelineCreateInfo-pNext-pNext", "VUID-VkGraphicsPipelineCreateInfo-sType-unique", false, true);

            skip |= ValidateFlags(pCreateInfos_loc.dot(Field::flags), "VkPipelineCreateFlagBits", AllVkPipelineCreateFlagBits,
                                  pCreateInfos[createInfoIndex].flags, kOptionalFlags,
                                  "VUID-VkGraphicsPipelineCreateInfo-flags-parameter");

            skip |= ValidateStructType(
                pCreateInfos_loc.dot(Field::pDynamicState), "VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO",
                pCreateInfos[createInfoIndex].pDynamicState, VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO, false,
                "VUID-VkGraphicsPipelineCreateInfo-pDynamicState-parameter", "VUID-VkPipelineDynamicStateCreateInfo-sType-sType");

            if (pCreateInfos[createInfoIndex].pDynamicState != nullptr) {
                [[maybe_unused]] const Location pDynamicState_loc = pCreateInfos_loc.dot(Field::pDynamicState);
                skip |= ValidateStructPnext(pDynamicState_loc, pCreateInfos[createInfoIndex].pDynamicState->pNext, 0, nullptr,
                                            GeneratedVulkanHeaderVersion, "VUID-VkPipelineDynamicStateCreateInfo-pNext-pNext",
                                            kVUIDUndefined, false, true);

                skip |=
                    ValidateReservedFlags(pDynamicState_loc.dot(Field::flags), pCreateInfos[createInfoIndex].pDynamicState->flags,
                                          "VUID-VkPipelineDynamicStateCreateInfo-flags-zerobitmask");

                skip |= ValidateRangedEnumArray(pDynamicState_loc.dot(Field::dynamicStateCount),
                                                pDynamicState_loc.dot(Field::pDynamicStates), "VkDynamicState",
                                                pCreateInfos[createInfoIndex].pDynamicState->dynamicStateCount,
                                                pCreateInfos[createInfoIndex].pDynamicState->pDynamicStates, false, true);
            }
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateGraphicsPipelines-pAllocator-null",
                         "vkCreateGraphicsPipelines(): pAllocator must be NULL");
    }
    skip |= ValidateArray(loc.dot(Field::createInfoCount), loc.dot(Field::pPipelines), createInfoCount, &pPipelines, true, true,
                          "VUID-vkCreateGraphicsPipelines-createInfoCount-arraylength",
                          "VUID-vkCreateGraphicsPipelines-pPipelines-parameter");
    if (!skip)
        skip |= manual_PreCallValidateCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                                              pPipelines, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                                uint32_t createInfoCount,
                                                                const VkComputePipelineCreateInfo* pCreateInfos,
                                                                const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::pipelineCache), pipelineCache);
    skip |= ValidateStructTypeArray(
        loc.dot(Field::createInfoCount), loc.dot(Field::pCreateInfos), "VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO",
        createInfoCount, pCreateInfos, VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO, true, true,
        "VUID-VkComputePipelineCreateInfo-sType-sType", "VUID-vkCreateComputePipelines-pCreateInfos-parameter",
        "VUID-vkCreateComputePipelines-createInfoCount-arraylength");
    if (pCreateInfos != nullptr) {
        for (uint32_t createInfoIndex = 0; createInfoIndex < createInfoCount; ++createInfoIndex) {
            [[maybe_unused]] const Location pCreateInfos_loc = loc.dot(Field::pCreateInfos, createInfoIndex);
            constexpr std::array allowed_structs_VkComputePipelineCreateInfo = {
                VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO, VK_STRUCTURE_TYPE_PIPELINE_OFFLINE_CREATE_INFO};

            skip |= ValidateStructPnext(
                pCreateInfos_loc, pCreateInfos[createInfoIndex].pNext, allowed_structs_VkComputePipelineCreateInfo.size(),
                allowed_structs_VkComputePipelineCreateInfo.data(), GeneratedVulkanHeaderVersion,
                "VUID-VkComputePipelineCreateInfo-pNext-pNext", "VUID-VkComputePipelineCreateInfo-sType-unique", false, true);

            skip |= ValidateFlags(pCreateInfos_loc.dot(Field::flags), "VkPipelineCreateFlagBits", AllVkPipelineCreateFlagBits,
                                  pCreateInfos[createInfoIndex].flags, kOptionalFlags,
                                  "VUID-VkComputePipelineCreateInfo-flags-parameter");

            skip |= ValidateStructType(pCreateInfos_loc.dot(Field::stage), "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO",
                                       &(pCreateInfos[createInfoIndex].stage), VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
                                       false, kVUIDUndefined, "VUID-VkPipelineShaderStageCreateInfo-sType-sType");

            constexpr std::array allowed_structs_VkPipelineShaderStageCreateInfo = {
                VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT,
                VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO};

            skip |= ValidateStructPnext(pCreateInfos_loc, pCreateInfos[createInfoIndex].stage.pNext,
                                        allowed_structs_VkPipelineShaderStageCreateInfo.size(),
                                        allowed_structs_VkPipelineShaderStageCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                        "VUID-VkPipelineShaderStageCreateInfo-pNext-pNext",
                                        "VUID-VkPipelineShaderStageCreateInfo-sType-unique", false, true);

            skip |= ValidateFlags(pCreateInfos_loc.dot(Field::flags), "VkPipelineShaderStageCreateFlagBits",
                                  AllVkPipelineShaderStageCreateFlagBits, pCreateInfos[createInfoIndex].stage.flags, kOptionalFlags,
                                  "VUID-VkPipelineShaderStageCreateInfo-flags-parameter");

            skip |= ValidateFlags(pCreateInfos_loc.dot(Field::stage), "VkShaderStageFlagBits", AllVkShaderStageFlagBits,
                                  pCreateInfos[createInfoIndex].stage.stage, kRequiredSingleBit,
                                  "VUID-VkPipelineShaderStageCreateInfo-stage-parameter",
                                  "VUID-VkPipelineShaderStageCreateInfo-stage-parameter");

            if (pCreateInfos[createInfoIndex].stage.pSpecializationInfo != nullptr) {
                [[maybe_unused]] const Location pSpecializationInfo_loc = pCreateInfos_loc.dot(Field::pSpecializationInfo);
                skip |= ValidateArray(pSpecializationInfo_loc.dot(Field::mapEntryCount),
                                      pSpecializationInfo_loc.dot(Field::pMapEntries),
                                      pCreateInfos[createInfoIndex].stage.pSpecializationInfo->mapEntryCount,
                                      &pCreateInfos[createInfoIndex].stage.pSpecializationInfo->pMapEntries, false, true,
                                      kVUIDUndefined, "VUID-VkSpecializationInfo-pMapEntries-parameter");

                if (pCreateInfos[createInfoIndex].stage.pSpecializationInfo->pMapEntries != nullptr) {
                    for (uint32_t mapEntryIndex = 0;
                         mapEntryIndex < pCreateInfos[createInfoIndex].stage.pSpecializationInfo->mapEntryCount; ++mapEntryIndex) {
                        [[maybe_unused]] const Location pMapEntries_loc =
                            pSpecializationInfo_loc.dot(Field::pMapEntries, mapEntryIndex);
                        // No xml-driven validation
                    }
                }

                skip |= ValidateArray(pSpecializationInfo_loc.dot(Field::dataSize), pSpecializationInfo_loc.dot(Field::pData),
                                      pCreateInfos[createInfoIndex].stage.pSpecializationInfo->dataSize,
                                      &pCreateInfos[createInfoIndex].stage.pSpecializationInfo->pData, false, true, kVUIDUndefined,
                                      "VUID-VkSpecializationInfo-pData-parameter");
            }

            skip |= ValidateRequiredHandle(pCreateInfos_loc.dot(Field::layout), pCreateInfos[createInfoIndex].layout);
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateComputePipelines-pAllocator-null",
                         "vkCreateComputePipelines(): pAllocator must be NULL");
    }
    skip |= ValidateArray(loc.dot(Field::createInfoCount), loc.dot(Field::pPipelines), createInfoCount, &pPipelines, true, true,
                          "VUID-vkCreateComputePipelines-createInfoCount-arraylength",
                          "VUID-vkCreateComputePipelines-pPipelines-parameter");
    if (!skip)
        skip |= manual_PreCallValidateCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                                             pPipelines, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyPipeline(VkDevice device, VkPipeline pipeline,
                                                         const VkAllocationCallbacks* pAllocator,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyPipeline-pAllocator-null", "vkDestroyPipeline(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo,
                                                              const VkAllocationCallbacks* pAllocator,
                                                              VkPipelineLayout* pPipelineLayout,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO, true,
                               "VUID-vkCreatePipelineLayout-pCreateInfo-parameter", "VUID-VkPipelineLayoutCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkPipelineLayoutCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkPipelineLayoutCreateInfo-flags-zerobitmask");

        skip |= ValidateArray(pCreateInfo_loc.dot(Field::pushConstantRangeCount), pCreateInfo_loc.dot(Field::pPushConstantRanges),
                              pCreateInfo->pushConstantRangeCount, &pCreateInfo->pPushConstantRanges, false, true, kVUIDUndefined,
                              "VUID-VkPipelineLayoutCreateInfo-pPushConstantRanges-parameter");

        if (pCreateInfo->pPushConstantRanges != nullptr) {
            for (uint32_t pushConstantRangeIndex = 0; pushConstantRangeIndex < pCreateInfo->pushConstantRangeCount;
                 ++pushConstantRangeIndex) {
                [[maybe_unused]] const Location pPushConstantRanges_loc =
                    pCreateInfo_loc.dot(Field::pPushConstantRanges, pushConstantRangeIndex);
                skip |= ValidateFlags(pPushConstantRanges_loc.dot(Field::stageFlags), "VkShaderStageFlagBits",
                                      AllVkShaderStageFlagBits, pCreateInfo->pPushConstantRanges[pushConstantRangeIndex].stageFlags,
                                      kRequiredFlags, "VUID-VkPushConstantRange-stageFlags-parameter",
                                      "VUID-VkPushConstantRange-stageFlags-requiredbitmask");
            }
        }
    }
    if (pAllocator != nullptr) {
        skip |=
            LogError(instance, "VUID-vkCreatePipelineLayout-pAllocator-null", "vkCreatePipelineLayout(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pPipelineLayout), pPipelineLayout,
                                    "VUID-vkCreatePipelineLayout-pPipelineLayout-parameter");
    if (!skip) skip |= manual_PreCallValidateCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyPipelineLayout-pAllocator-null",
                         "vkDestroyPipelineLayout(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkSampler* pSampler,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO, true, "VUID-vkCreateSampler-pCreateInfo-parameter",
                               "VUID-VkSamplerCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkSamplerCreateInfo = {VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT,
                                                                    VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO,
                                                                    VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkSamplerCreateInfo.size(),
                                    allowed_structs_VkSamplerCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkSamplerCreateInfo-pNext-pNext", "VUID-VkSamplerCreateInfo-sType-unique", false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkSamplerCreateInfo-flags-zerobitmask");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::magFilter), "VkFilter", pCreateInfo->magFilter,
                                   "VUID-VkSamplerCreateInfo-magFilter-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::minFilter), "VkFilter", pCreateInfo->minFilter,
                                   "VUID-VkSamplerCreateInfo-minFilter-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::mipmapMode), "VkSamplerMipmapMode", pCreateInfo->mipmapMode,
                                   "VUID-VkSamplerCreateInfo-mipmapMode-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::addressModeU), "VkSamplerAddressMode", pCreateInfo->addressModeU,
                                   "VUID-VkSamplerCreateInfo-addressModeU-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::addressModeV), "VkSamplerAddressMode", pCreateInfo->addressModeV,
                                   "VUID-VkSamplerCreateInfo-addressModeV-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::addressModeW), "VkSamplerAddressMode", pCreateInfo->addressModeW,
                                   "VUID-VkSamplerCreateInfo-addressModeW-parameter");

        skip |= ValidateBool32(pCreateInfo_loc.dot(Field::anisotropyEnable), pCreateInfo->anisotropyEnable);

        skip |= ValidateBool32(pCreateInfo_loc.dot(Field::compareEnable), pCreateInfo->compareEnable);

        skip |= ValidateBool32(pCreateInfo_loc.dot(Field::unnormalizedCoordinates), pCreateInfo->unnormalizedCoordinates);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateSampler-pAllocator-null", "vkCreateSampler(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pSampler), pSampler, "VUID-vkCreateSampler-pSampler-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateSampler(device, pCreateInfo, pAllocator, pSampler, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroySampler-pAllocator-null", "vkDestroySampler(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateDescriptorSetLayout(VkDevice device,
                                                                   const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   VkDescriptorSetLayout* pSetLayout,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO, true,
                               "VUID-vkCreateDescriptorSetLayout-pCreateInfo-parameter",
                               "VUID-VkDescriptorSetLayoutCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkDescriptorSetLayoutCreateInfo = {
            VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkDescriptorSetLayoutCreateInfo.size(),
                                    allowed_structs_VkDescriptorSetLayoutCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkDescriptorSetLayoutCreateInfo-pNext-pNext",
                                    "VUID-VkDescriptorSetLayoutCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkDescriptorSetLayoutCreateFlagBits",
                              AllVkDescriptorSetLayoutCreateFlagBits, pCreateInfo->flags, kOptionalFlags,
                              "VUID-VkDescriptorSetLayoutCreateInfo-flags-parameter");

        skip |= ValidateArray(pCreateInfo_loc.dot(Field::bindingCount), pCreateInfo_loc.dot(Field::pBindings),
                              pCreateInfo->bindingCount, &pCreateInfo->pBindings, false, true, kVUIDUndefined,
                              "VUID-VkDescriptorSetLayoutCreateInfo-pBindings-parameter");

        if (pCreateInfo->pBindings != nullptr) {
            for (uint32_t bindingIndex = 0; bindingIndex < pCreateInfo->bindingCount; ++bindingIndex) {
                [[maybe_unused]] const Location pBindings_loc = pCreateInfo_loc.dot(Field::pBindings, bindingIndex);
                skip |= ValidateRangedEnum(pBindings_loc.dot(Field::descriptorType), "VkDescriptorType",
                                           pCreateInfo->pBindings[bindingIndex].descriptorType,
                                           "VUID-VkDescriptorSetLayoutBinding-descriptorType-parameter");
            }
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateDescriptorSetLayout-pAllocator-null",
                         "vkCreateDescriptorSetLayout(): pAllocator must be NULL");
    }
    skip |=
        ValidateRequiredPointer(loc.dot(Field::pSetLayout), pSetLayout, "VUID-vkCreateDescriptorSetLayout-pSetLayout-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout,
                                                                    const VkAllocationCallbacks* pAllocator,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyDescriptorSetLayout-pAllocator-null",
                         "vkDestroyDescriptorSetLayout(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo,
                                                              const VkAllocationCallbacks* pAllocator,
                                                              VkDescriptorPool* pDescriptorPool,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO, true,
                               "VUID-vkCreateDescriptorPool-pCreateInfo-parameter", "VUID-VkDescriptorPoolCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkDescriptorPoolCreateInfo = {
            VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkDescriptorPoolCreateInfo.size(),
                                    allowed_structs_VkDescriptorPoolCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkDescriptorPoolCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |=
            ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkDescriptorPoolCreateFlagBits", AllVkDescriptorPoolCreateFlagBits,
                          pCreateInfo->flags, kOptionalFlags, "VUID-VkDescriptorPoolCreateInfo-flags-parameter");

        skip |= ValidateArray(pCreateInfo_loc.dot(Field::poolSizeCount), pCreateInfo_loc.dot(Field::pPoolSizes),
                              pCreateInfo->poolSizeCount, &pCreateInfo->pPoolSizes, false, true, kVUIDUndefined,
                              "VUID-VkDescriptorPoolCreateInfo-pPoolSizes-parameter");

        if (pCreateInfo->pPoolSizes != nullptr) {
            for (uint32_t poolSizeIndex = 0; poolSizeIndex < pCreateInfo->poolSizeCount; ++poolSizeIndex) {
                [[maybe_unused]] const Location pPoolSizes_loc = pCreateInfo_loc.dot(Field::pPoolSizes, poolSizeIndex);
                skip |= ValidateRangedEnum(pPoolSizes_loc.dot(Field::type), "VkDescriptorType",
                                           pCreateInfo->pPoolSizes[poolSizeIndex].type, "VUID-VkDescriptorPoolSize-type-parameter");
            }
        }
    }
    if (pAllocator != nullptr) {
        skip |=
            LogError(instance, "VUID-vkCreateDescriptorPool-pAllocator-null", "vkCreateDescriptorPool(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pDescriptorPool), pDescriptorPool,
                                    "VUID-vkCreateDescriptorPool-pDescriptorPool-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool,
                                                             VkDescriptorPoolResetFlags flags, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::descriptorPool), descriptorPool);
    skip |= ValidateReservedFlags(loc.dot(Field::flags), flags, "VUID-vkResetDescriptorPool-flags-zerobitmask");
    return skip;
}

bool StatelessValidation::PreCallValidateAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                                                VkDescriptorSet* pDescriptorSets,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |=
        ValidateStructType(loc.dot(Field::pAllocateInfo), "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO", pAllocateInfo,
                           VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO, true,
                           "VUID-vkAllocateDescriptorSets-pAllocateInfo-parameter", "VUID-VkDescriptorSetAllocateInfo-sType-sType");
    if (pAllocateInfo != nullptr) {
        [[maybe_unused]] const Location pAllocateInfo_loc = loc.dot(Field::pAllocateInfo);
        constexpr std::array allowed_structs_VkDescriptorSetAllocateInfo = {
            VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO};

        skip |= ValidateStructPnext(pAllocateInfo_loc, pAllocateInfo->pNext, allowed_structs_VkDescriptorSetAllocateInfo.size(),
                                    allowed_structs_VkDescriptorSetAllocateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkDescriptorSetAllocateInfo-pNext-pNext", "VUID-VkDescriptorSetAllocateInfo-sType-unique",
                                    false, true);

        skip |= ValidateRequiredHandle(pAllocateInfo_loc.dot(Field::descriptorPool), pAllocateInfo->descriptorPool);

        skip |= ValidateHandleArray(pAllocateInfo_loc.dot(Field::descriptorSetCount), pAllocateInfo_loc.dot(Field::pSetLayouts),
                                    pAllocateInfo->descriptorSetCount, pAllocateInfo->pSetLayouts, true, true, kVUIDUndefined);
    }
    if (pAllocateInfo != nullptr) {
        skip |= ValidateArray(loc.dot(Field::pAllocateInfo).dot(Field::descriptorSetCount), loc.dot(Field::pDescriptorSets),
                              pAllocateInfo->descriptorSetCount, &pDescriptorSets, true, true,
                              "VUID-vkAllocateDescriptorSets-pAllocateInfo::descriptorSetCount-arraylength",
                              "VUID-vkAllocateDescriptorSets-pDescriptorSets-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool,
                                                            uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::descriptorPool), descriptorPool);
    skip |= ValidateArray(loc.dot(Field::descriptorSetCount), loc, descriptorSetCount, &pDescriptorSets, true, false,
                          "VUID-vkFreeDescriptorSets-descriptorSetCount-arraylength", kVUIDUndefined);
    if (!skip)
        skip |= manual_PreCallValidateFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount,
                                                              const VkWriteDescriptorSet* pDescriptorWrites,
                                                              uint32_t descriptorCopyCount,
                                                              const VkCopyDescriptorSet* pDescriptorCopies,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructTypeArray(loc.dot(Field::descriptorWriteCount), loc.dot(Field::pDescriptorWrites),
                                    "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET", descriptorWriteCount, pDescriptorWrites,
                                    VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET, false, true, "VUID-VkWriteDescriptorSet-sType-sType",
                                    "VUID-vkUpdateDescriptorSets-pDescriptorWrites-parameter", kVUIDUndefined);
    if (pDescriptorWrites != nullptr) {
        for (uint32_t descriptorWriteIndex = 0; descriptorWriteIndex < descriptorWriteCount; ++descriptorWriteIndex) {
            [[maybe_unused]] const Location pDescriptorWrites_loc = loc.dot(Field::pDescriptorWrites, descriptorWriteIndex);
            constexpr std::array allowed_structs_VkWriteDescriptorSet = {
                VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK};

            skip |= ValidateStructPnext(pDescriptorWrites_loc, pDescriptorWrites[descriptorWriteIndex].pNext,
                                        allowed_structs_VkWriteDescriptorSet.size(), allowed_structs_VkWriteDescriptorSet.data(),
                                        GeneratedVulkanHeaderVersion, "VUID-VkWriteDescriptorSet-pNext-pNext", kVUIDUndefined,
                                        false, true);

            skip |= ValidateRangedEnum(pDescriptorWrites_loc.dot(Field::descriptorType), "VkDescriptorType",
                                       pDescriptorWrites[descriptorWriteIndex].descriptorType,
                                       "VUID-VkWriteDescriptorSet-descriptorType-parameter");

            skip |= ValidateArray(pDescriptorWrites_loc.dot(Field::descriptorCount), loc,
                                  pDescriptorWrites[descriptorWriteIndex].descriptorCount,
                                  &pDescriptorWrites[descriptorWriteIndex].pImageInfo, true, false,
                                  "VUID-VkWriteDescriptorSet-descriptorCount-arraylength", kVUIDUndefined);
        }
    }
    skip |= ValidateStructTypeArray(loc.dot(Field::descriptorCopyCount), loc.dot(Field::pDescriptorCopies),
                                    "VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET", descriptorCopyCount, pDescriptorCopies,
                                    VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET, false, true, "VUID-VkCopyDescriptorSet-sType-sType",
                                    "VUID-vkUpdateDescriptorSets-pDescriptorCopies-parameter", kVUIDUndefined);
    if (pDescriptorCopies != nullptr) {
        for (uint32_t descriptorCopyIndex = 0; descriptorCopyIndex < descriptorCopyCount; ++descriptorCopyIndex) {
            [[maybe_unused]] const Location pDescriptorCopies_loc = loc.dot(Field::pDescriptorCopies, descriptorCopyIndex);
            skip |= ValidateStructPnext(pDescriptorCopies_loc, pDescriptorCopies[descriptorCopyIndex].pNext, 0, nullptr,
                                        GeneratedVulkanHeaderVersion, "VUID-VkCopyDescriptorSet-pNext-pNext", kVUIDUndefined, false,
                                        true);

            skip |= ValidateRequiredHandle(pDescriptorCopies_loc.dot(Field::srcSet), pDescriptorCopies[descriptorCopyIndex].srcSet);

            skip |= ValidateRequiredHandle(pDescriptorCopies_loc.dot(Field::dstSet), pDescriptorCopies[descriptorCopyIndex].dstSet);
        }
    }
    if (!skip)
        skip |= manual_PreCallValidateUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount,
                                                           pDescriptorCopies, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO, true, "VUID-vkCreateFramebuffer-pCreateInfo-parameter",
                               "VUID-VkFramebufferCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkFramebufferCreateInfo = {VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkFramebufferCreateInfo.size(),
                                    allowed_structs_VkFramebufferCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkFramebufferCreateInfo-pNext-pNext", "VUID-VkFramebufferCreateInfo-sType-unique", false,
                                    true);

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkFramebufferCreateFlagBits", AllVkFramebufferCreateFlagBits,
                              pCreateInfo->flags, kOptionalFlags, "VUID-VkFramebufferCreateInfo-flags-parameter");

        skip |= ValidateRequiredHandle(pCreateInfo_loc.dot(Field::renderPass), pCreateInfo->renderPass);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateFramebuffer-pAllocator-null", "vkCreateFramebuffer(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pFramebuffer), pFramebuffer, "VUID-vkCreateFramebuffer-pFramebuffer-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer,
                                                            const VkAllocationCallbacks* pAllocator,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyFramebuffer-pAllocator-null", "vkDestroyFramebuffer(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO, true, "VUID-vkCreateRenderPass-pCreateInfo-parameter",
                               "VUID-VkRenderPassCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkRenderPassCreateInfo = {
            VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO, VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO};

        skip |=
            ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkRenderPassCreateInfo.size(),
                                allowed_structs_VkRenderPassCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkRenderPassCreateInfo-pNext-pNext", "VUID-VkRenderPassCreateInfo-sType-unique", false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkRenderPassCreateInfo-flags-zerobitmask");

        skip |= ValidateArray(pCreateInfo_loc.dot(Field::attachmentCount), pCreateInfo_loc.dot(Field::pAttachments),
                              pCreateInfo->attachmentCount, &pCreateInfo->pAttachments, false, true, kVUIDUndefined,
                              "VUID-VkRenderPassCreateInfo-pAttachments-parameter");

        if (pCreateInfo->pAttachments != nullptr) {
            for (uint32_t attachmentIndex = 0; attachmentIndex < pCreateInfo->attachmentCount; ++attachmentIndex) {
                [[maybe_unused]] const Location pAttachments_loc = pCreateInfo_loc.dot(Field::pAttachments, attachmentIndex);
                skip |= ValidateFlags(pAttachments_loc.dot(Field::flags), "VkAttachmentDescriptionFlagBits",
                                      AllVkAttachmentDescriptionFlagBits, pCreateInfo->pAttachments[attachmentIndex].flags,
                                      kOptionalFlags, "VUID-VkAttachmentDescription-flags-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::format), "VkFormat",
                                           pCreateInfo->pAttachments[attachmentIndex].format,
                                           "VUID-VkAttachmentDescription-format-parameter");

                skip |= ValidateFlags(pAttachments_loc.dot(Field::samples), "VkSampleCountFlagBits", AllVkSampleCountFlagBits,
                                      pCreateInfo->pAttachments[attachmentIndex].samples, kRequiredSingleBit,
                                      "VUID-VkAttachmentDescription-samples-parameter",
                                      "VUID-VkAttachmentDescription-samples-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::loadOp), "VkAttachmentLoadOp",
                                           pCreateInfo->pAttachments[attachmentIndex].loadOp,
                                           "VUID-VkAttachmentDescription-loadOp-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::storeOp), "VkAttachmentStoreOp",
                                           pCreateInfo->pAttachments[attachmentIndex].storeOp,
                                           "VUID-VkAttachmentDescription-storeOp-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::stencilLoadOp), "VkAttachmentLoadOp",
                                           pCreateInfo->pAttachments[attachmentIndex].stencilLoadOp,
                                           "VUID-VkAttachmentDescription-stencilLoadOp-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::stencilStoreOp), "VkAttachmentStoreOp",
                                           pCreateInfo->pAttachments[attachmentIndex].stencilStoreOp,
                                           "VUID-VkAttachmentDescription-stencilStoreOp-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::initialLayout), "VkImageLayout",
                                           pCreateInfo->pAttachments[attachmentIndex].initialLayout,
                                           "VUID-VkAttachmentDescription-initialLayout-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::finalLayout), "VkImageLayout",
                                           pCreateInfo->pAttachments[attachmentIndex].finalLayout,
                                           "VUID-VkAttachmentDescription-finalLayout-parameter");
            }
        }

        skip |= ValidateArray(pCreateInfo_loc.dot(Field::subpassCount), pCreateInfo_loc.dot(Field::pSubpasses),
                              pCreateInfo->subpassCount, &pCreateInfo->pSubpasses, true, true,
                              "VUID-VkRenderPassCreateInfo-subpassCount-arraylength",
                              "VUID-VkRenderPassCreateInfo-pSubpasses-parameter");

        if (pCreateInfo->pSubpasses != nullptr) {
            for (uint32_t subpassIndex = 0; subpassIndex < pCreateInfo->subpassCount; ++subpassIndex) {
                [[maybe_unused]] const Location pSubpasses_loc = pCreateInfo_loc.dot(Field::pSubpasses, subpassIndex);
                skip |= ValidateReservedFlags(pSubpasses_loc.dot(Field::flags), pCreateInfo->pSubpasses[subpassIndex].flags,
                                              "VUID-VkSubpassDescription-flags-zerobitmask");

                skip |= ValidateRangedEnum(pSubpasses_loc.dot(Field::pipelineBindPoint), "VkPipelineBindPoint",
                                           pCreateInfo->pSubpasses[subpassIndex].pipelineBindPoint,
                                           "VUID-VkSubpassDescription-pipelineBindPoint-parameter");

                skip |= ValidateArray(pSubpasses_loc.dot(Field::inputAttachmentCount), pSubpasses_loc.dot(Field::pInputAttachments),
                                      pCreateInfo->pSubpasses[subpassIndex].inputAttachmentCount,
                                      &pCreateInfo->pSubpasses[subpassIndex].pInputAttachments, false, true, kVUIDUndefined,
                                      "VUID-VkSubpassDescription-pInputAttachments-parameter");

                if (pCreateInfo->pSubpasses[subpassIndex].pInputAttachments != nullptr) {
                    for (uint32_t inputAttachmentIndex = 0;
                         inputAttachmentIndex < pCreateInfo->pSubpasses[subpassIndex].inputAttachmentCount;
                         ++inputAttachmentIndex) {
                        [[maybe_unused]] const Location pInputAttachments_loc =
                            pSubpasses_loc.dot(Field::pInputAttachments, inputAttachmentIndex);
                        skip |=
                            ValidateRangedEnum(pInputAttachments_loc.dot(Field::layout), "VkImageLayout",
                                               pCreateInfo->pSubpasses[subpassIndex].pInputAttachments[inputAttachmentIndex].layout,
                                               "VUID-VkAttachmentReference-layout-parameter");
                    }
                }

                skip |= ValidateArray(pSubpasses_loc.dot(Field::colorAttachmentCount), pSubpasses_loc.dot(Field::pColorAttachments),
                                      pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount,
                                      &pCreateInfo->pSubpasses[subpassIndex].pColorAttachments, false, true, kVUIDUndefined,
                                      "VUID-VkSubpassDescription-pColorAttachments-parameter");

                if (pCreateInfo->pSubpasses[subpassIndex].pColorAttachments != nullptr) {
                    for (uint32_t colorAttachmentIndex = 0;
                         colorAttachmentIndex < pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount;
                         ++colorAttachmentIndex) {
                        [[maybe_unused]] const Location pColorAttachments_loc =
                            pSubpasses_loc.dot(Field::pColorAttachments, colorAttachmentIndex);
                        skip |=
                            ValidateRangedEnum(pColorAttachments_loc.dot(Field::layout), "VkImageLayout",
                                               pCreateInfo->pSubpasses[subpassIndex].pColorAttachments[colorAttachmentIndex].layout,
                                               "VUID-VkAttachmentReference-layout-parameter");
                    }
                }

                if (pCreateInfo->pSubpasses[subpassIndex].pResolveAttachments != nullptr) {
                    for (uint32_t colorAttachmentIndex = 0;
                         colorAttachmentIndex < pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount;
                         ++colorAttachmentIndex) {
                        [[maybe_unused]] const Location pResolveAttachments_loc =
                            pSubpasses_loc.dot(Field::pResolveAttachments, colorAttachmentIndex);
                        skip |= ValidateRangedEnum(
                            pResolveAttachments_loc.dot(Field::layout), "VkImageLayout",
                            pCreateInfo->pSubpasses[subpassIndex].pResolveAttachments[colorAttachmentIndex].layout,
                            "VUID-VkAttachmentReference-layout-parameter");
                    }
                }

                if (pCreateInfo->pSubpasses[subpassIndex].pDepthStencilAttachment != nullptr) {
                    [[maybe_unused]] const Location pDepthStencilAttachment_loc =
                        pSubpasses_loc.dot(Field::pDepthStencilAttachment);
                    skip |= ValidateRangedEnum(pDepthStencilAttachment_loc.dot(Field::layout), "VkImageLayout",
                                               pCreateInfo->pSubpasses[subpassIndex].pDepthStencilAttachment->layout,
                                               "VUID-VkAttachmentReference-layout-parameter");
                }

                skip |= ValidateArray(pSubpasses_loc.dot(Field::preserveAttachmentCount),
                                      pSubpasses_loc.dot(Field::pPreserveAttachments),
                                      pCreateInfo->pSubpasses[subpassIndex].preserveAttachmentCount,
                                      &pCreateInfo->pSubpasses[subpassIndex].pPreserveAttachments, false, true, kVUIDUndefined,
                                      "VUID-VkSubpassDescription-pPreserveAttachments-parameter");
            }
        }

        skip |= ValidateArray(pCreateInfo_loc.dot(Field::dependencyCount), pCreateInfo_loc.dot(Field::pDependencies),
                              pCreateInfo->dependencyCount, &pCreateInfo->pDependencies, false, true, kVUIDUndefined,
                              "VUID-VkRenderPassCreateInfo-pDependencies-parameter");

        if (pCreateInfo->pDependencies != nullptr) {
            for (uint32_t dependencyIndex = 0; dependencyIndex < pCreateInfo->dependencyCount; ++dependencyIndex) {
                [[maybe_unused]] const Location pDependencies_loc = pCreateInfo_loc.dot(Field::pDependencies, dependencyIndex);
                skip |= ValidateFlags(pDependencies_loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits",
                                      AllVkPipelineStageFlagBits, pCreateInfo->pDependencies[dependencyIndex].srcStageMask,
                                      kOptionalFlags, "VUID-VkSubpassDependency-srcStageMask-parameter");

                skip |= ValidateFlags(pDependencies_loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits",
                                      AllVkPipelineStageFlagBits, pCreateInfo->pDependencies[dependencyIndex].dstStageMask,
                                      kOptionalFlags, "VUID-VkSubpassDependency-dstStageMask-parameter");

                skip |= ValidateFlags(pDependencies_loc.dot(Field::srcAccessMask), "VkAccessFlagBits", AllVkAccessFlagBits,
                                      pCreateInfo->pDependencies[dependencyIndex].srcAccessMask, kOptionalFlags,
                                      "VUID-VkSubpassDependency-srcAccessMask-parameter");

                skip |= ValidateFlags(pDependencies_loc.dot(Field::dstAccessMask), "VkAccessFlagBits", AllVkAccessFlagBits,
                                      pCreateInfo->pDependencies[dependencyIndex].dstAccessMask, kOptionalFlags,
                                      "VUID-VkSubpassDependency-dstAccessMask-parameter");

                skip |= ValidateFlags(pDependencies_loc.dot(Field::dependencyFlags), "VkDependencyFlagBits",
                                      AllVkDependencyFlagBits, pCreateInfo->pDependencies[dependencyIndex].dependencyFlags,
                                      kOptionalFlags, "VUID-VkSubpassDependency-dependencyFlags-parameter");
            }
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateRenderPass-pAllocator-null", "vkCreateRenderPass(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pRenderPass), pRenderPass, "VUID-vkCreateRenderPass-pRenderPass-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyRenderPass(VkDevice device, VkRenderPass renderPass,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyRenderPass-pAllocator-null", "vkDestroyRenderPass(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass,
                                                                  VkExtent2D* pGranularity, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::renderPass), renderPass);
    skip |= ValidateRequiredPointer(loc.dot(Field::pGranularity), pGranularity,
                                    "VUID-vkGetRenderAreaGranularity-pGranularity-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO, true, "VUID-vkCreateCommandPool-pCreateInfo-parameter",
                               "VUID-VkCommandPoolCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkCommandPoolCreateInfo = {
            VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_RESERVATION_CREATE_INFO};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkCommandPoolCreateInfo.size(),
                                    allowed_structs_VkCommandPoolCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkCommandPoolCreateInfo-pNext-pNext", "VUID-VkCommandPoolCreateInfo-sType-unique", false,
                                    true);

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkCommandPoolCreateFlagBits", AllVkCommandPoolCreateFlagBits,
                              pCreateInfo->flags, kOptionalFlags, "VUID-VkCommandPoolCreateInfo-flags-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateCommandPool-pAllocator-null", "vkCreateCommandPool(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pCommandPool), pCommandPool, "VUID-vkCreateCommandPool-pCommandPool-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::commandPool), commandPool);
    skip |= ValidateReservedFlags(loc.dot(Field::flags), flags, "VUID-vkResetCommandPool-flags-zerobitmask");
    return skip;
}

bool StatelessValidation::PreCallValidateAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                                                VkCommandBuffer* pCommandBuffers,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |=
        ValidateStructType(loc.dot(Field::pAllocateInfo), "VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO", pAllocateInfo,
                           VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO, true,
                           "VUID-vkAllocateCommandBuffers-pAllocateInfo-parameter", "VUID-VkCommandBufferAllocateInfo-sType-sType");
    if (pAllocateInfo != nullptr) {
        [[maybe_unused]] const Location pAllocateInfo_loc = loc.dot(Field::pAllocateInfo);
        skip |= ValidateStructPnext(pAllocateInfo_loc, pAllocateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkCommandBufferAllocateInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pAllocateInfo_loc.dot(Field::commandPool), pAllocateInfo->commandPool);

        skip |= ValidateRangedEnum(pAllocateInfo_loc.dot(Field::level), "VkCommandBufferLevel", pAllocateInfo->level,
                                   "VUID-VkCommandBufferAllocateInfo-level-parameter");
    }
    if (pAllocateInfo != nullptr) {
        skip |= ValidateArray(loc.dot(Field::pAllocateInfo).dot(Field::commandBufferCount), loc.dot(Field::pCommandBuffers),
                              pAllocateInfo->commandBufferCount, &pCommandBuffers, true, true,
                              "VUID-vkAllocateCommandBuffers-pAllocateInfo::commandBufferCount-arraylength",
                              "VUID-vkAllocateCommandBuffers-pCommandBuffers-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                                            const VkCommandBuffer* pCommandBuffers,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::commandPool), commandPool);
    skip |= ValidateArray(loc.dot(Field::commandBufferCount), loc, commandBufferCount, &pCommandBuffers, true, false,
                          "VUID-vkFreeCommandBuffers-commandBufferCount-arraylength", kVUIDUndefined);
    if (!skip)
        skip |= manual_PreCallValidateFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateBeginCommandBuffer(VkCommandBuffer commandBuffer,
                                                            const VkCommandBufferBeginInfo* pBeginInfo,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pBeginInfo), "VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO", pBeginInfo,
                               VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, true, "VUID-vkBeginCommandBuffer-pBeginInfo-parameter",
                               "VUID-VkCommandBufferBeginInfo-sType-sType");
    if (pBeginInfo != nullptr) {
        [[maybe_unused]] const Location pBeginInfo_loc = loc.dot(Field::pBeginInfo);
        constexpr std::array allowed_structs_VkCommandBufferBeginInfo = {VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO};

        skip |= ValidateStructPnext(pBeginInfo_loc, pBeginInfo->pNext, allowed_structs_VkCommandBufferBeginInfo.size(),
                                    allowed_structs_VkCommandBufferBeginInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkCommandBufferBeginInfo-pNext-pNext", "VUID-VkCommandBufferBeginInfo-sType-unique",
                                    false, true);

        skip |= ValidateFlags(pBeginInfo_loc.dot(Field::flags), "VkCommandBufferUsageFlagBits", AllVkCommandBufferUsageFlagBits,
                              pBeginInfo->flags, kOptionalFlags, "VUID-VkCommandBufferBeginInfo-flags-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateBeginCommandBuffer(commandBuffer, pBeginInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateEndCommandBuffer(VkCommandBuffer commandBuffer, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateFlags(loc.dot(Field::flags), "VkCommandBufferResetFlagBits", AllVkCommandBufferResetFlagBits, flags,
                          kOptionalFlags, "VUID-vkResetCommandBuffer-flags-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                         VkPipeline pipeline, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRangedEnum(loc.dot(Field::pipelineBindPoint), "VkPipelineBindPoint", pipelineBindPoint,
                               "VUID-vkCmdBindPipeline-pipelineBindPoint-parameter");
    skip |= ValidateRequiredHandle(loc.dot(Field::pipeline), pipeline);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                        uint32_t viewportCount, const VkViewport* pViewports,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateArray(loc.dot(Field::viewportCount), loc.dot(Field::pViewports), viewportCount, &pViewports, true, true,
                          "VUID-vkCmdSetViewport-viewportCount-arraylength", "VUID-vkCmdSetViewport-pViewports-parameter");
    if (pViewports != nullptr) {
        for (uint32_t viewportIndex = 0; viewportIndex < viewportCount; ++viewportIndex) {
            [[maybe_unused]] const Location pViewports_loc = loc.dot(Field::pViewports, viewportIndex);
            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                                       const VkRect2D* pScissors, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateArray(loc.dot(Field::scissorCount), loc.dot(Field::pScissors), scissorCount, &pScissors, true, true,
                          "VUID-vkCmdSetScissor-scissorCount-arraylength", "VUID-vkCmdSetScissor-pScissors-parameter");
    if (pScissors != nullptr) {
        for (uint32_t scissorIndex = 0; scissorIndex < scissorCount; ++scissorIndex) {
            [[maybe_unused]] const Location pScissors_loc = loc.dot(Field::pScissors, scissorIndex);
            // No xml-driven validation

            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    if (!skip) skip |= manual_PreCallValidateCmdSetLineWidth(commandBuffer, lineWidth, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor,
                                                         float depthBiasClamp, float depthBiasSlopeFactor,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4],
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds,
                                                           float maxDepthBounds, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                                  uint32_t compareMask, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateFlags(loc.dot(Field::faceMask), "VkStencilFaceFlagBits", AllVkStencilFaceFlagBits, faceMask, kRequiredFlags,
                          "VUID-vkCmdSetStencilCompareMask-faceMask-parameter",
                          "VUID-vkCmdSetStencilCompareMask-faceMask-requiredbitmask");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                                uint32_t writeMask, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |=
        ValidateFlags(loc.dot(Field::faceMask), "VkStencilFaceFlagBits", AllVkStencilFaceFlagBits, faceMask, kRequiredFlags,
                      "VUID-vkCmdSetStencilWriteMask-faceMask-parameter", "VUID-vkCmdSetStencilWriteMask-faceMask-requiredbitmask");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                                uint32_t reference, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |=
        ValidateFlags(loc.dot(Field::faceMask), "VkStencilFaceFlagBits", AllVkStencilFaceFlagBits, faceMask, kRequiredFlags,
                      "VUID-vkCmdSetStencilReference-faceMask-parameter", "VUID-vkCmdSetStencilReference-faceMask-requiredbitmask");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                               VkPipelineLayout layout, uint32_t firstSet,
                                                               uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets,
                                                               uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRangedEnum(loc.dot(Field::pipelineBindPoint), "VkPipelineBindPoint", pipelineBindPoint,
                               "VUID-vkCmdBindDescriptorSets-pipelineBindPoint-parameter");
    skip |= ValidateRequiredHandle(loc.dot(Field::layout), layout);
    skip |= ValidateArray(loc.dot(Field::descriptorSetCount), loc.dot(Field::pDescriptorSets), descriptorSetCount, &pDescriptorSets,
                          true, false, "VUID-vkCmdBindDescriptorSets-descriptorSetCount-arraylength",
                          "VUID-vkCmdBindDescriptorSets-pDescriptorSets-parameter");
    skip |= ValidateArray(loc.dot(Field::dynamicOffsetCount), loc.dot(Field::pDynamicOffsets), dynamicOffsetCount, &pDynamicOffsets,
                          false, true, kVUIDUndefined, "VUID-vkCmdBindDescriptorSets-pDynamicOffsets-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                            VkIndexType indexType, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::buffer), buffer);
    skip |=
        ValidateRangedEnum(loc.dot(Field::indexType), "VkIndexType", indexType, "VUID-vkCmdBindIndexBuffer-indexType-parameter");
    if (!skip) skip |= manual_PreCallValidateCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                              uint32_t bindingCount, const VkBuffer* pBuffers,
                                                              const VkDeviceSize* pOffsets, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateArray(loc.dot(Field::bindingCount), loc.dot(Field::pBuffers), bindingCount, &pBuffers, true, false,
                          "VUID-vkCmdBindVertexBuffers-bindingCount-arraylength", "VUID-vkCmdBindVertexBuffers-pBuffers-parameter");
    skip |= ValidateArray(loc.dot(Field::bindingCount), loc.dot(Field::pOffsets), bindingCount, &pOffsets, true, true,
                          "VUID-vkCmdBindVertexBuffers-bindingCount-arraylength", "VUID-vkCmdBindVertexBuffers-pOffsets-parameter");
    if (!skip)
        skip |=
            manual_PreCallValidateCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                                                 uint32_t firstVertex, uint32_t firstInstance, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                                        uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                         uint32_t drawCount, uint32_t stride, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::buffer), buffer);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                                uint32_t drawCount, uint32_t stride,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::buffer), buffer);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                                     uint32_t groupCountZ, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::buffer), buffer);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                                       uint32_t regionCount, const VkBufferCopy* pRegions,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::srcBuffer), srcBuffer);
    skip |= ValidateRequiredHandle(loc.dot(Field::dstBuffer), dstBuffer);
    skip |= ValidateArray(loc.dot(Field::regionCount), loc.dot(Field::pRegions), regionCount, &pRegions, true, true,
                          "VUID-vkCmdCopyBuffer-regionCount-arraylength", "VUID-vkCmdCopyBuffer-pRegions-parameter");
    if (pRegions != nullptr) {
        for (uint32_t regionIndex = 0; regionIndex < regionCount; ++regionIndex) {
            [[maybe_unused]] const Location pRegions_loc = loc.dot(Field::pRegions, regionIndex);
            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                                      VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                                      const VkImageCopy* pRegions, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::srcImage), srcImage);
    skip |= ValidateRangedEnum(loc.dot(Field::srcImageLayout), "VkImageLayout", srcImageLayout,
                               "VUID-vkCmdCopyImage-srcImageLayout-parameter");
    skip |= ValidateRequiredHandle(loc.dot(Field::dstImage), dstImage);
    skip |= ValidateRangedEnum(loc.dot(Field::dstImageLayout), "VkImageLayout", dstImageLayout,
                               "VUID-vkCmdCopyImage-dstImageLayout-parameter");
    skip |= ValidateArray(loc.dot(Field::regionCount), loc.dot(Field::pRegions), regionCount, &pRegions, true, true,
                          "VUID-vkCmdCopyImage-regionCount-arraylength", "VUID-vkCmdCopyImage-pRegions-parameter");
    if (pRegions != nullptr) {
        for (uint32_t regionIndex = 0; regionIndex < regionCount; ++regionIndex) {
            [[maybe_unused]] const Location pRegions_loc = loc.dot(Field::pRegions, regionIndex);
            skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                  pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags,
                                  "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                  "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            // No xml-driven validation

            skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                  pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags,
                                  "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                  "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            // No xml-driven validation

            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                                      VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                                      const VkImageBlit* pRegions, VkFilter filter,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::srcImage), srcImage);
    skip |= ValidateRangedEnum(loc.dot(Field::srcImageLayout), "VkImageLayout", srcImageLayout,
                               "VUID-vkCmdBlitImage-srcImageLayout-parameter");
    skip |= ValidateRequiredHandle(loc.dot(Field::dstImage), dstImage);
    skip |= ValidateRangedEnum(loc.dot(Field::dstImageLayout), "VkImageLayout", dstImageLayout,
                               "VUID-vkCmdBlitImage-dstImageLayout-parameter");
    skip |= ValidateArray(loc.dot(Field::regionCount), loc.dot(Field::pRegions), regionCount, &pRegions, true, true,
                          "VUID-vkCmdBlitImage-regionCount-arraylength", "VUID-vkCmdBlitImage-pRegions-parameter");
    if (pRegions != nullptr) {
        for (uint32_t regionIndex = 0; regionIndex < regionCount; ++regionIndex) {
            [[maybe_unused]] const Location pRegions_loc = loc.dot(Field::pRegions, regionIndex);
            skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                  pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags,
                                  "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                  "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                  pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags,
                                  "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                  "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");
        }
    }
    skip |= ValidateRangedEnum(loc.dot(Field::filter), "VkFilter", filter, "VUID-vkCmdBlitImage-filter-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                                              VkImageLayout dstImageLayout, uint32_t regionCount,
                                                              const VkBufferImageCopy* pRegions,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::srcBuffer), srcBuffer);
    skip |= ValidateRequiredHandle(loc.dot(Field::dstImage), dstImage);
    skip |= ValidateRangedEnum(loc.dot(Field::dstImageLayout), "VkImageLayout", dstImageLayout,
                               "VUID-vkCmdCopyBufferToImage-dstImageLayout-parameter");
    skip |= ValidateArray(loc.dot(Field::regionCount), loc.dot(Field::pRegions), regionCount, &pRegions, true, true,
                          "VUID-vkCmdCopyBufferToImage-regionCount-arraylength", "VUID-vkCmdCopyBufferToImage-pRegions-parameter");
    if (pRegions != nullptr) {
        for (uint32_t regionIndex = 0; regionIndex < regionCount; ++regionIndex) {
            [[maybe_unused]] const Location pRegions_loc = loc.dot(Field::pRegions, regionIndex);
            skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                  pRegions[regionIndex].imageSubresource.aspectMask, kRequiredFlags,
                                  "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                  "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            // No xml-driven validation

            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                              VkImageLayout srcImageLayout, VkBuffer dstBuffer,
                                                              uint32_t regionCount, const VkBufferImageCopy* pRegions,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::srcImage), srcImage);
    skip |= ValidateRangedEnum(loc.dot(Field::srcImageLayout), "VkImageLayout", srcImageLayout,
                               "VUID-vkCmdCopyImageToBuffer-srcImageLayout-parameter");
    skip |= ValidateRequiredHandle(loc.dot(Field::dstBuffer), dstBuffer);
    skip |= ValidateArray(loc.dot(Field::regionCount), loc.dot(Field::pRegions), regionCount, &pRegions, true, true,
                          "VUID-vkCmdCopyImageToBuffer-regionCount-arraylength", "VUID-vkCmdCopyImageToBuffer-pRegions-parameter");
    if (pRegions != nullptr) {
        for (uint32_t regionIndex = 0; regionIndex < regionCount; ++regionIndex) {
            [[maybe_unused]] const Location pRegions_loc = loc.dot(Field::pRegions, regionIndex);
            skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                  pRegions[regionIndex].imageSubresource.aspectMask, kRequiredFlags,
                                  "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                  "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            // No xml-driven validation

            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                         VkDeviceSize dataSize, const void* pData,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::dstBuffer), dstBuffer);
    skip |= ValidateArray(loc.dot(Field::dataSize), loc.dot(Field::pData), dataSize, &pData, true, true,
                          "VUID-vkCmdUpdateBuffer-dataSize-arraylength", "VUID-vkCmdUpdateBuffer-pData-parameter");
    if (!skip) skip |= manual_PreCallValidateCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                       VkDeviceSize size, uint32_t data, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::dstBuffer), dstBuffer);
    if (!skip) skip |= manual_PreCallValidateCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                                            const VkClearColorValue* pColor, uint32_t rangeCount,
                                                            const VkImageSubresourceRange* pRanges,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::image), image);
    skip |= ValidateRangedEnum(loc.dot(Field::imageLayout), "VkImageLayout", imageLayout,
                               "VUID-vkCmdClearColorImage-imageLayout-parameter");
    skip |= ValidateArray(loc.dot(Field::rangeCount), loc.dot(Field::pRanges), rangeCount, &pRanges, true, true,
                          "VUID-vkCmdClearColorImage-rangeCount-arraylength", "VUID-vkCmdClearColorImage-pRanges-parameter");
    if (pRanges != nullptr) {
        for (uint32_t rangeIndex = 0; rangeIndex < rangeCount; ++rangeIndex) {
            [[maybe_unused]] const Location pRanges_loc = loc.dot(Field::pRanges, rangeIndex);
            skip |=
                ValidateFlags(pRanges_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                              pRanges[rangeIndex].aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter",
                              "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
        }
    }
    if (!skip)
        skip |= manual_PreCallValidateCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image,
                                                                   VkImageLayout imageLayout,
                                                                   const VkClearDepthStencilValue* pDepthStencil,
                                                                   uint32_t rangeCount, const VkImageSubresourceRange* pRanges,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::image), image);
    skip |= ValidateRangedEnum(loc.dot(Field::imageLayout), "VkImageLayout", imageLayout,
                               "VUID-vkCmdClearDepthStencilImage-imageLayout-parameter");
    skip |= ValidateRequiredPointer(loc.dot(Field::pDepthStencil), pDepthStencil,
                                    "VUID-vkCmdClearDepthStencilImage-pDepthStencil-parameter");
    if (pDepthStencil != nullptr) {
        [[maybe_unused]] const Location pDepthStencil_loc = loc.dot(Field::pDepthStencil);
        // No xml-driven validation
    }
    skip |= ValidateArray(loc.dot(Field::rangeCount), loc.dot(Field::pRanges), rangeCount, &pRanges, true, true,
                          "VUID-vkCmdClearDepthStencilImage-rangeCount-arraylength",
                          "VUID-vkCmdClearDepthStencilImage-pRanges-parameter");
    if (pRanges != nullptr) {
        for (uint32_t rangeIndex = 0; rangeIndex < rangeCount; ++rangeIndex) {
            [[maybe_unused]] const Location pRanges_loc = loc.dot(Field::pRanges, rangeIndex);
            skip |=
                ValidateFlags(pRanges_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                              pRanges[rangeIndex].aspectMask, kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter",
                              "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                             const VkClearAttachment* pAttachments, uint32_t rectCount,
                                                             const VkClearRect* pRects, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateArray(loc.dot(Field::attachmentCount), loc.dot(Field::pAttachments), attachmentCount, &pAttachments, true, true,
                          "VUID-vkCmdClearAttachments-attachmentCount-arraylength",
                          "VUID-vkCmdClearAttachments-pAttachments-parameter");
    if (pAttachments != nullptr) {
        for (uint32_t attachmentIndex = 0; attachmentIndex < attachmentCount; ++attachmentIndex) {
            [[maybe_unused]] const Location pAttachments_loc = loc.dot(Field::pAttachments, attachmentIndex);
            skip |=
                ValidateFlags(pAttachments_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                              pAttachments[attachmentIndex].aspectMask, kRequiredFlags,
                              "VUID-VkClearAttachment-aspectMask-parameter", "VUID-VkClearAttachment-aspectMask-requiredbitmask");
        }
    }
    skip |= ValidateArray(loc.dot(Field::rectCount), loc.dot(Field::pRects), rectCount, &pRects, true, true,
                          "VUID-vkCmdClearAttachments-rectCount-arraylength", "VUID-vkCmdClearAttachments-pRects-parameter");
    if (pRects != nullptr) {
        for (uint32_t rectIndex = 0; rectIndex < rectCount; ++rectIndex) {
            [[maybe_unused]] const Location pRects_loc = loc.dot(Field::pRects, rectIndex);
            // No xml-driven validation

            // No xml-driven validation
        }
    }
    if (!skip)
        skip |=
            manual_PreCallValidateCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                         VkImageLayout srcImageLayout, VkImage dstImage,
                                                         VkImageLayout dstImageLayout, uint32_t regionCount,
                                                         const VkImageResolve* pRegions, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::srcImage), srcImage);
    skip |= ValidateRangedEnum(loc.dot(Field::srcImageLayout), "VkImageLayout", srcImageLayout,
                               "VUID-vkCmdResolveImage-srcImageLayout-parameter");
    skip |= ValidateRequiredHandle(loc.dot(Field::dstImage), dstImage);
    skip |= ValidateRangedEnum(loc.dot(Field::dstImageLayout), "VkImageLayout", dstImageLayout,
                               "VUID-vkCmdResolveImage-dstImageLayout-parameter");
    skip |= ValidateArray(loc.dot(Field::regionCount), loc.dot(Field::pRegions), regionCount, &pRegions, true, true,
                          "VUID-vkCmdResolveImage-regionCount-arraylength", "VUID-vkCmdResolveImage-pRegions-parameter");
    if (pRegions != nullptr) {
        for (uint32_t regionIndex = 0; regionIndex < regionCount; ++regionIndex) {
            [[maybe_unused]] const Location pRegions_loc = loc.dot(Field::pRegions, regionIndex);
            skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                  pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags,
                                  "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                  "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            // No xml-driven validation

            skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                  pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags,
                                  "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                  "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

            // No xml-driven validation

            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask,
                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::event), event);
    skip |= ValidateFlags(loc.dot(Field::stageMask), "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, stageMask,
                          kOptionalFlags, "VUID-vkCmdSetEvent-stageMask-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::event), event);
    skip |= ValidateFlags(loc.dot(Field::stageMask), "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, stageMask,
                          kOptionalFlags, "VUID-vkCmdResetEvent-stageMask-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWaitEvents(
    VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask,
    VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
    uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount,
    const VkImageMemoryBarrier* pImageMemoryBarriers, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateHandleArray(loc.dot(Field::eventCount), loc.dot(Field::pEvents), eventCount, pEvents, true, true,
                                "VUID-vkCmdWaitEvents-eventCount-arraylength");
    skip |= ValidateFlags(loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, srcStageMask,
                          kOptionalFlags, "VUID-vkCmdWaitEvents-srcStageMask-parameter");
    skip |= ValidateFlags(loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, dstStageMask,
                          kOptionalFlags, "VUID-vkCmdWaitEvents-dstStageMask-parameter");
    skip |= ValidateStructTypeArray(loc.dot(Field::memoryBarrierCount), loc.dot(Field::pMemoryBarriers),
                                    "VK_STRUCTURE_TYPE_MEMORY_BARRIER", memoryBarrierCount, pMemoryBarriers,
                                    VK_STRUCTURE_TYPE_MEMORY_BARRIER, false, true, "VUID-VkMemoryBarrier-sType-sType",
                                    "VUID-vkCmdWaitEvents-pMemoryBarriers-parameter", kVUIDUndefined);
    if (pMemoryBarriers != nullptr) {
        for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < memoryBarrierCount; ++memoryBarrierIndex) {
            [[maybe_unused]] const Location pMemoryBarriers_loc = loc.dot(Field::pMemoryBarriers, memoryBarrierIndex);
            skip |=
                ValidateStructPnext(pMemoryBarriers_loc, pMemoryBarriers[memoryBarrierIndex].pNext, 0, nullptr,
                                    GeneratedVulkanHeaderVersion, "VUID-VkMemoryBarrier-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateFlags(pMemoryBarriers_loc.dot(Field::srcAccessMask), "VkAccessFlagBits", AllVkAccessFlagBits,
                                  pMemoryBarriers[memoryBarrierIndex].srcAccessMask, kOptionalFlags,
                                  "VUID-VkMemoryBarrier-srcAccessMask-parameter");

            skip |= ValidateFlags(pMemoryBarriers_loc.dot(Field::dstAccessMask), "VkAccessFlagBits", AllVkAccessFlagBits,
                                  pMemoryBarriers[memoryBarrierIndex].dstAccessMask, kOptionalFlags,
                                  "VUID-VkMemoryBarrier-dstAccessMask-parameter");
        }
    }
    skip |= ValidateStructTypeArray(loc.dot(Field::bufferMemoryBarrierCount), loc.dot(Field::pBufferMemoryBarriers),
                                    "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER", bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                    VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER, false, true, "VUID-VkBufferMemoryBarrier-sType-sType",
                                    "VUID-vkCmdWaitEvents-pBufferMemoryBarriers-parameter", kVUIDUndefined);
    if (pBufferMemoryBarriers != nullptr) {
        for (uint32_t bufferMemoryBarrierIndex = 0; bufferMemoryBarrierIndex < bufferMemoryBarrierCount;
             ++bufferMemoryBarrierIndex) {
            [[maybe_unused]] const Location pBufferMemoryBarriers_loc =
                loc.dot(Field::pBufferMemoryBarriers, bufferMemoryBarrierIndex);
            skip |= ValidateStructPnext(pBufferMemoryBarriers_loc, pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext, 0,
                                        nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier-pNext-pNext",
                                        kVUIDUndefined, false, true);

            skip |= ValidateRequiredHandle(pBufferMemoryBarriers_loc.dot(Field::buffer),
                                           pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
        }
    }
    skip |= ValidateStructTypeArray(loc.dot(Field::imageMemoryBarrierCount), loc.dot(Field::pImageMemoryBarriers),
                                    "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER", imageMemoryBarrierCount, pImageMemoryBarriers,
                                    VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER, false, true, "VUID-VkImageMemoryBarrier-sType-sType",
                                    "VUID-vkCmdWaitEvents-pImageMemoryBarriers-parameter", kVUIDUndefined);
    if (pImageMemoryBarriers != nullptr) {
        for (uint32_t imageMemoryBarrierIndex = 0; imageMemoryBarrierIndex < imageMemoryBarrierCount; ++imageMemoryBarrierIndex) {
            [[maybe_unused]] const Location pImageMemoryBarriers_loc =
                loc.dot(Field::pImageMemoryBarriers, imageMemoryBarrierIndex);
            constexpr std::array allowed_structs_VkImageMemoryBarrier = {VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT};

            skip |= ValidateStructPnext(pImageMemoryBarriers_loc, pImageMemoryBarriers[imageMemoryBarrierIndex].pNext,
                                        allowed_structs_VkImageMemoryBarrier.size(), allowed_structs_VkImageMemoryBarrier.data(),
                                        GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier-pNext-pNext",
                                        "VUID-VkImageMemoryBarrier-sType-unique", false, true);

            skip |= ValidateRangedEnum(pImageMemoryBarriers_loc.dot(Field::oldLayout), "VkImageLayout",
                                       pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout,
                                       "VUID-VkImageMemoryBarrier-oldLayout-parameter");

            skip |= ValidateRangedEnum(pImageMemoryBarriers_loc.dot(Field::newLayout), "VkImageLayout",
                                       pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout,
                                       "VUID-VkImageMemoryBarrier-newLayout-parameter");

            skip |= ValidateRequiredHandle(pImageMemoryBarriers_loc.dot(Field::image),
                                           pImageMemoryBarriers[imageMemoryBarrierIndex].image);

            skip |= ValidateFlags(
                pImageMemoryBarriers_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask, kRequiredFlags,
                "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdPipelineBarrier(
    VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
    VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
    uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount,
    const VkImageMemoryBarrier* pImageMemoryBarriers, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateFlags(loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, srcStageMask,
                          kOptionalFlags, "VUID-vkCmdPipelineBarrier-srcStageMask-parameter");
    skip |= ValidateFlags(loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, dstStageMask,
                          kOptionalFlags, "VUID-vkCmdPipelineBarrier-dstStageMask-parameter");
    skip |= ValidateFlags(loc.dot(Field::dependencyFlags), "VkDependencyFlagBits", AllVkDependencyFlagBits, dependencyFlags,
                          kOptionalFlags, "VUID-vkCmdPipelineBarrier-dependencyFlags-parameter");
    skip |= ValidateStructTypeArray(loc.dot(Field::memoryBarrierCount), loc.dot(Field::pMemoryBarriers),
                                    "VK_STRUCTURE_TYPE_MEMORY_BARRIER", memoryBarrierCount, pMemoryBarriers,
                                    VK_STRUCTURE_TYPE_MEMORY_BARRIER, false, true, "VUID-VkMemoryBarrier-sType-sType",
                                    "VUID-vkCmdPipelineBarrier-pMemoryBarriers-parameter", kVUIDUndefined);
    if (pMemoryBarriers != nullptr) {
        for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < memoryBarrierCount; ++memoryBarrierIndex) {
            [[maybe_unused]] const Location pMemoryBarriers_loc = loc.dot(Field::pMemoryBarriers, memoryBarrierIndex);
            skip |=
                ValidateStructPnext(pMemoryBarriers_loc, pMemoryBarriers[memoryBarrierIndex].pNext, 0, nullptr,
                                    GeneratedVulkanHeaderVersion, "VUID-VkMemoryBarrier-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateFlags(pMemoryBarriers_loc.dot(Field::srcAccessMask), "VkAccessFlagBits", AllVkAccessFlagBits,
                                  pMemoryBarriers[memoryBarrierIndex].srcAccessMask, kOptionalFlags,
                                  "VUID-VkMemoryBarrier-srcAccessMask-parameter");

            skip |= ValidateFlags(pMemoryBarriers_loc.dot(Field::dstAccessMask), "VkAccessFlagBits", AllVkAccessFlagBits,
                                  pMemoryBarriers[memoryBarrierIndex].dstAccessMask, kOptionalFlags,
                                  "VUID-VkMemoryBarrier-dstAccessMask-parameter");
        }
    }
    skip |= ValidateStructTypeArray(loc.dot(Field::bufferMemoryBarrierCount), loc.dot(Field::pBufferMemoryBarriers),
                                    "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER", bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                    VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER, false, true, "VUID-VkBufferMemoryBarrier-sType-sType",
                                    "VUID-vkCmdPipelineBarrier-pBufferMemoryBarriers-parameter", kVUIDUndefined);
    if (pBufferMemoryBarriers != nullptr) {
        for (uint32_t bufferMemoryBarrierIndex = 0; bufferMemoryBarrierIndex < bufferMemoryBarrierCount;
             ++bufferMemoryBarrierIndex) {
            [[maybe_unused]] const Location pBufferMemoryBarriers_loc =
                loc.dot(Field::pBufferMemoryBarriers, bufferMemoryBarrierIndex);
            skip |= ValidateStructPnext(pBufferMemoryBarriers_loc, pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext, 0,
                                        nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier-pNext-pNext",
                                        kVUIDUndefined, false, true);

            skip |= ValidateRequiredHandle(pBufferMemoryBarriers_loc.dot(Field::buffer),
                                           pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
        }
    }
    skip |= ValidateStructTypeArray(loc.dot(Field::imageMemoryBarrierCount), loc.dot(Field::pImageMemoryBarriers),
                                    "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER", imageMemoryBarrierCount, pImageMemoryBarriers,
                                    VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER, false, true, "VUID-VkImageMemoryBarrier-sType-sType",
                                    "VUID-vkCmdPipelineBarrier-pImageMemoryBarriers-parameter", kVUIDUndefined);
    if (pImageMemoryBarriers != nullptr) {
        for (uint32_t imageMemoryBarrierIndex = 0; imageMemoryBarrierIndex < imageMemoryBarrierCount; ++imageMemoryBarrierIndex) {
            [[maybe_unused]] const Location pImageMemoryBarriers_loc =
                loc.dot(Field::pImageMemoryBarriers, imageMemoryBarrierIndex);
            constexpr std::array allowed_structs_VkImageMemoryBarrier = {VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT};

            skip |= ValidateStructPnext(pImageMemoryBarriers_loc, pImageMemoryBarriers[imageMemoryBarrierIndex].pNext,
                                        allowed_structs_VkImageMemoryBarrier.size(), allowed_structs_VkImageMemoryBarrier.data(),
                                        GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier-pNext-pNext",
                                        "VUID-VkImageMemoryBarrier-sType-unique", false, true);

            skip |= ValidateRangedEnum(pImageMemoryBarriers_loc.dot(Field::oldLayout), "VkImageLayout",
                                       pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout,
                                       "VUID-VkImageMemoryBarrier-oldLayout-parameter");

            skip |= ValidateRangedEnum(pImageMemoryBarriers_loc.dot(Field::newLayout), "VkImageLayout",
                                       pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout,
                                       "VUID-VkImageMemoryBarrier-newLayout-parameter");

            skip |= ValidateRequiredHandle(pImageMemoryBarriers_loc.dot(Field::image),
                                           pImageMemoryBarriers[imageMemoryBarrierIndex].image);

            skip |= ValidateFlags(
                pImageMemoryBarriers_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask, kRequiredFlags,
                "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                                       VkQueryControlFlags flags, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::queryPool), queryPool);
    skip |= ValidateFlags(loc.dot(Field::flags), "VkQueryControlFlagBits", AllVkQueryControlFlagBits, flags, kOptionalFlags,
                          "VUID-vkCmdBeginQuery-flags-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::queryPool), queryPool);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                           uint32_t firstQuery, uint32_t queryCount,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::queryPool), queryPool);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                                           VkQueryPool queryPool, uint32_t query,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateFlags(loc.dot(Field::pipelineStage), "VkPipelineStageFlagBits", AllVkPipelineStageFlagBits, pipelineStage,
                          kRequiredSingleBit, "VUID-vkCmdWriteTimestamp-pipelineStage-parameter",
                          "VUID-vkCmdWriteTimestamp-pipelineStage-parameter");
    skip |= ValidateRequiredHandle(loc.dot(Field::queryPool), queryPool);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                                 uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer,
                                                                 VkDeviceSize dstOffset, VkDeviceSize stride,
                                                                 VkQueryResultFlags flags, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::queryPool), queryPool);
    skip |= ValidateRequiredHandle(loc.dot(Field::dstBuffer), dstBuffer);
    skip |= ValidateFlags(loc.dot(Field::flags), "VkQueryResultFlagBits", AllVkQueryResultFlagBits, flags, kOptionalFlags,
                          "VUID-vkCmdCopyQueryPoolResults-flags-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                                          VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                                          const void* pValues, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::layout), layout);
    skip |= ValidateFlags(loc.dot(Field::stageFlags), "VkShaderStageFlagBits", AllVkShaderStageFlagBits, stageFlags, kRequiredFlags,
                          "VUID-vkCmdPushConstants-stageFlags-parameter", "VUID-vkCmdPushConstants-stageFlags-requiredbitmask");
    skip |= ValidateArray(loc.dot(Field::size), loc.dot(Field::pValues), size, &pValues, true, true,
                          "VUID-vkCmdPushConstants-size-arraylength", "VUID-vkCmdPushConstants-pValues-parameter");
    if (!skip) skip |= manual_PreCallValidateCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBeginRenderPass(VkCommandBuffer commandBuffer,
                                                            const VkRenderPassBeginInfo* pRenderPassBegin,
                                                            VkSubpassContents contents, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pRenderPassBegin), "VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO", pRenderPassBegin,
                               VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO, true,
                               "VUID-vkCmdBeginRenderPass-pRenderPassBegin-parameter", "VUID-VkRenderPassBeginInfo-sType-sType");
    if (pRenderPassBegin != nullptr) {
        [[maybe_unused]] const Location pRenderPassBegin_loc = loc.dot(Field::pRenderPassBegin);
        constexpr std::array allowed_structs_VkRenderPassBeginInfo = {
            VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO, VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO,
            VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT};

        skip |=
            ValidateStructPnext(pRenderPassBegin_loc, pRenderPassBegin->pNext, allowed_structs_VkRenderPassBeginInfo.size(),
                                allowed_structs_VkRenderPassBeginInfo.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkRenderPassBeginInfo-pNext-pNext", "VUID-VkRenderPassBeginInfo-sType-unique", false, true);

        skip |= ValidateRequiredHandle(pRenderPassBegin_loc.dot(Field::renderPass), pRenderPassBegin->renderPass);

        skip |= ValidateRequiredHandle(pRenderPassBegin_loc.dot(Field::framebuffer), pRenderPassBegin->framebuffer);

        // No xml-driven validation

        // No xml-driven validation
    }
    skip |=
        ValidateRangedEnum(loc.dot(Field::contents), "VkSubpassContents", contents, "VUID-vkCmdBeginRenderPass-contents-parameter");
    if (!skip) skip |= manual_PreCallValidateCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRangedEnum(loc.dot(Field::contents), "VkSubpassContents", contents, "VUID-vkCmdNextSubpass-contents-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdEndRenderPass(VkCommandBuffer commandBuffer, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                                            const VkCommandBuffer* pCommandBuffers,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateHandleArray(loc.dot(Field::commandBufferCount), loc.dot(Field::pCommandBuffers), commandBufferCount,
                                pCommandBuffers, true, true, "VUID-vkCmdExecuteCommands-commandBufferCount-arraylength");
    return skip;
}

bool StatelessValidation::PreCallValidateBindBufferMemory2(VkDevice device, uint32_t bindInfoCount,
                                                           const VkBindBufferMemoryInfo* pBindInfos,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructTypeArray(
        loc.dot(Field::bindInfoCount), loc.dot(Field::pBindInfos), "VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO", bindInfoCount,
        pBindInfos, VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO, true, true, "VUID-VkBindBufferMemoryInfo-sType-sType",
        "VUID-vkBindBufferMemory2-pBindInfos-parameter", "VUID-vkBindBufferMemory2-bindInfoCount-arraylength");
    if (pBindInfos != nullptr) {
        for (uint32_t bindInfoIndex = 0; bindInfoIndex < bindInfoCount; ++bindInfoIndex) {
            [[maybe_unused]] const Location pBindInfos_loc = loc.dot(Field::pBindInfos, bindInfoIndex);
            constexpr std::array allowed_structs_VkBindBufferMemoryInfo = {VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO};

            skip |= ValidateStructPnext(
                pBindInfos_loc, pBindInfos[bindInfoIndex].pNext, allowed_structs_VkBindBufferMemoryInfo.size(),
                allowed_structs_VkBindBufferMemoryInfo.data(), GeneratedVulkanHeaderVersion,
                "VUID-VkBindBufferMemoryInfo-pNext-pNext", "VUID-VkBindBufferMemoryInfo-sType-unique", false, true);

            skip |= ValidateRequiredHandle(pBindInfos_loc.dot(Field::buffer), pBindInfos[bindInfoIndex].buffer);

            skip |= ValidateRequiredHandle(pBindInfos_loc.dot(Field::memory), pBindInfos[bindInfoIndex].memory);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateBindImageMemory2(VkDevice device, uint32_t bindInfoCount,
                                                          const VkBindImageMemoryInfo* pBindInfos,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructTypeArray(
        loc.dot(Field::bindInfoCount), loc.dot(Field::pBindInfos), "VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO", bindInfoCount,
        pBindInfos, VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO, true, true, "VUID-VkBindImageMemoryInfo-sType-sType",
        "VUID-vkBindImageMemory2-pBindInfos-parameter", "VUID-vkBindImageMemory2-bindInfoCount-arraylength");
    if (pBindInfos != nullptr) {
        for (uint32_t bindInfoIndex = 0; bindInfoIndex < bindInfoCount; ++bindInfoIndex) {
            [[maybe_unused]] const Location pBindInfos_loc = loc.dot(Field::pBindInfos, bindInfoIndex);
            constexpr std::array allowed_structs_VkBindImageMemoryInfo = {VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO,
                                                                          VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR,
                                                                          VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO};

            skip |= ValidateStructPnext(pBindInfos_loc, pBindInfos[bindInfoIndex].pNext,
                                        allowed_structs_VkBindImageMemoryInfo.size(), allowed_structs_VkBindImageMemoryInfo.data(),
                                        GeneratedVulkanHeaderVersion, "VUID-VkBindImageMemoryInfo-pNext-pNext",
                                        "VUID-VkBindImageMemoryInfo-sType-unique", false, true);

            skip |= ValidateRequiredHandle(pBindInfos_loc.dot(Field::image), pBindInfos[bindInfoIndex].image);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex,
                                                                          uint32_t localDeviceIndex, uint32_t remoteDeviceIndex,
                                                                          VkPeerMemoryFeatureFlags* pPeerMemoryFeatures,
                                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredPointer(loc.dot(Field::pPeerMemoryFeatures), pPeerMemoryFeatures,
                                    "VUID-vkGetDeviceGroupPeerMemoryFeatures-pPeerMemoryFeatures-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                                         uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                                         uint32_t groupCountZ, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateEnumeratePhysicalDeviceGroups(
    VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties,
    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (loc.function == vvl::Func::vkEnumeratePhysicalDeviceGroups &&
        CheckPromotedApiAgainstVulkanVersion(instance, loc, VK_API_VERSION_1_1))
        return true;
    skip |= ValidateStructTypeArray(
        loc.dot(Field::pPhysicalDeviceGroupCount), loc.dot(Field::pPhysicalDeviceGroupProperties),
        "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES", pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties,
        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES, true, false, false, "VUID-VkPhysicalDeviceGroupProperties-sType-sType",
        "VUID-vkEnumeratePhysicalDeviceGroups-pPhysicalDeviceGroupProperties-parameter", kVUIDUndefined);
    if (pPhysicalDeviceGroupProperties != nullptr) {
        for (uint32_t pPhysicalDeviceGroupIndex = 0; pPhysicalDeviceGroupIndex < *pPhysicalDeviceGroupCount;
             ++pPhysicalDeviceGroupIndex) {
            [[maybe_unused]] const Location pPhysicalDeviceGroupProperties_loc =
                loc.dot(Field::pPhysicalDeviceGroupProperties, pPhysicalDeviceGroupIndex);
            skip |= ValidateStructPnext(
                pPhysicalDeviceGroupProperties_loc, pPhysicalDeviceGroupProperties[pPhysicalDeviceGroupIndex].pNext, 0, nullptr,
                GeneratedVulkanHeaderVersion, "VUID-VkPhysicalDeviceGroupProperties-pNext-pNext", kVUIDUndefined, false, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo,
                                                                     VkMemoryRequirements2* pMemoryRequirements,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |=
        ValidateStructType(loc.dot(Field::pInfo), "VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2", pInfo,
                           VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2, true,
                           "VUID-vkGetImageMemoryRequirements2-pInfo-parameter", "VUID-VkImageMemoryRequirementsInfo2-sType-sType");
    if (pInfo != nullptr) {
        [[maybe_unused]] const Location pInfo_loc = loc.dot(Field::pInfo);
        constexpr std::array allowed_structs_VkImageMemoryRequirementsInfo2 = {
            VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO};

        skip |= ValidateStructPnext(pInfo_loc, pInfo->pNext, allowed_structs_VkImageMemoryRequirementsInfo2.size(),
                                    allowed_structs_VkImageMemoryRequirementsInfo2.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkImageMemoryRequirementsInfo2-pNext-pNext",
                                    "VUID-VkImageMemoryRequirementsInfo2-sType-unique", false, true);

        skip |= ValidateRequiredHandle(pInfo_loc.dot(Field::image), pInfo->image);
    }
    skip |= ValidateStructType(loc.dot(Field::pMemoryRequirements), "VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2", pMemoryRequirements,
                               VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, true,
                               "VUID-vkGetImageMemoryRequirements2-pMemoryRequirements-parameter",
                               "VUID-VkMemoryRequirements2-sType-sType");
    if (pMemoryRequirements != nullptr) {
        [[maybe_unused]] const Location pMemoryRequirements_loc = loc.dot(Field::pMemoryRequirements);
        constexpr std::array allowed_structs_VkMemoryRequirements2 = {VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS};

        skip |=
            ValidateStructPnext(pMemoryRequirements_loc, pMemoryRequirements->pNext, allowed_structs_VkMemoryRequirements2.size(),
                                allowed_structs_VkMemoryRequirements2.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkMemoryRequirements2-pNext-pNext", "VUID-VkMemoryRequirements2-sType-unique", false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo,
                                                                      VkMemoryRequirements2* pMemoryRequirements,
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pInfo), "VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2", pInfo,
                               VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2, true,
                               "VUID-vkGetBufferMemoryRequirements2-pInfo-parameter",
                               "VUID-VkBufferMemoryRequirementsInfo2-sType-sType");
    if (pInfo != nullptr) {
        [[maybe_unused]] const Location pInfo_loc = loc.dot(Field::pInfo);
        skip |= ValidateStructPnext(pInfo_loc, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkBufferMemoryRequirementsInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pInfo_loc.dot(Field::buffer), pInfo->buffer);
    }
    skip |= ValidateStructType(loc.dot(Field::pMemoryRequirements), "VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2", pMemoryRequirements,
                               VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, true,
                               "VUID-vkGetBufferMemoryRequirements2-pMemoryRequirements-parameter",
                               "VUID-VkMemoryRequirements2-sType-sType");
    if (pMemoryRequirements != nullptr) {
        [[maybe_unused]] const Location pMemoryRequirements_loc = loc.dot(Field::pMemoryRequirements);
        constexpr std::array allowed_structs_VkMemoryRequirements2 = {VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS};

        skip |=
            ValidateStructPnext(pMemoryRequirements_loc, pMemoryRequirements->pNext, allowed_structs_VkMemoryRequirements2.size(),
                                allowed_structs_VkMemoryRequirements2.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkMemoryRequirements2-pNext-pNext", "VUID-VkMemoryRequirements2-sType-unique", false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice,
                                                                    VkPhysicalDeviceFeatures2* pFeatures,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (loc.function == vvl::Func::vkGetPhysicalDeviceFeatures2 &&
        CheckPromotedApiAgainstVulkanVersion(physicalDevice, loc, VK_API_VERSION_1_1))
        return true;
    skip |=
        ValidateStructType(loc.dot(Field::pFeatures), "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2", pFeatures,
                           VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, true,
                           "VUID-vkGetPhysicalDeviceFeatures2-pFeatures-parameter", "VUID-VkPhysicalDeviceFeatures2-sType-sType");
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice,
                                                                      VkPhysicalDeviceProperties2* pProperties,
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (loc.function == vvl::Func::vkGetPhysicalDeviceProperties2 &&
        CheckPromotedApiAgainstVulkanVersion(physicalDevice, loc, VK_API_VERSION_1_1))
        return true;
    skip |= ValidateStructType(loc.dot(Field::pProperties), "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2", pProperties,
                               VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, true,
                               "VUID-vkGetPhysicalDeviceProperties2-pProperties-parameter",
                               "VUID-VkPhysicalDeviceProperties2-sType-sType");
    if (pProperties != nullptr) {
        [[maybe_unused]] const Location pProperties_loc = loc.dot(Field::pProperties);
        constexpr std::array allowed_structs_VkPhysicalDeviceProperties2 = {
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES};

        skip |= ValidateStructPnext(pProperties_loc, pProperties->pNext, allowed_structs_VkPhysicalDeviceProperties2.size(),
                                    allowed_structs_VkPhysicalDeviceProperties2.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkPhysicalDeviceProperties2-pNext-pNext", "VUID-VkPhysicalDeviceProperties2-sType-unique",
                                    true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                            VkFormatProperties2* pFormatProperties,
                                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (loc.function == vvl::Func::vkGetPhysicalDeviceFormatProperties2 &&
        CheckPromotedApiAgainstVulkanVersion(physicalDevice, loc, VK_API_VERSION_1_1))
        return true;
    skip |= ValidateRangedEnum(loc.dot(Field::format), "VkFormat", format,
                               "VUID-vkGetPhysicalDeviceFormatProperties2-format-parameter");
    skip |= ValidateStructType(loc.dot(Field::pFormatProperties), "VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2", pFormatProperties,
                               VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2, true,
                               "VUID-vkGetPhysicalDeviceFormatProperties2-pFormatProperties-parameter",
                               "VUID-VkFormatProperties2-sType-sType");
    if (pFormatProperties != nullptr) {
        [[maybe_unused]] const Location pFormatProperties_loc = loc.dot(Field::pFormatProperties);
        constexpr std::array allowed_structs_VkFormatProperties2 = {VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT,
                                                                    VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT,
                                                                    VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3};

        skip |= ValidateStructPnext(pFormatProperties_loc, pFormatProperties->pNext, allowed_structs_VkFormatProperties2.size(),
                                    allowed_structs_VkFormatProperties2.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkFormatProperties2-pNext-pNext", "VUID-VkFormatProperties2-sType-unique", true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceImageFormatProperties2(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
    VkImageFormatProperties2* pImageFormatProperties, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (loc.function == vvl::Func::vkGetPhysicalDeviceImageFormatProperties2 &&
        CheckPromotedApiAgainstVulkanVersion(physicalDevice, loc, VK_API_VERSION_1_1))
        return true;
    skip |= ValidateStructType(loc.dot(Field::pImageFormatInfo), "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2",
                               pImageFormatInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2, true,
                               "VUID-vkGetPhysicalDeviceImageFormatProperties2-pImageFormatInfo-parameter",
                               "VUID-VkPhysicalDeviceImageFormatInfo2-sType-sType");
    if (pImageFormatInfo != nullptr) {
        [[maybe_unused]] const Location pImageFormatInfo_loc = loc.dot(Field::pImageFormatInfo);
        constexpr std::array allowed_structs_VkPhysicalDeviceImageFormatInfo2 = {
            VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO, VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT,
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT};

        skip |= ValidateStructPnext(
            pImageFormatInfo_loc, pImageFormatInfo->pNext, allowed_structs_VkPhysicalDeviceImageFormatInfo2.size(),
            allowed_structs_VkPhysicalDeviceImageFormatInfo2.data(), GeneratedVulkanHeaderVersion,
            "VUID-VkPhysicalDeviceImageFormatInfo2-pNext-pNext", "VUID-VkPhysicalDeviceImageFormatInfo2-sType-unique", true, true);

        skip |= ValidateRangedEnum(pImageFormatInfo_loc.dot(Field::format), "VkFormat", pImageFormatInfo->format,
                                   "VUID-VkPhysicalDeviceImageFormatInfo2-format-parameter");

        skip |= ValidateRangedEnum(pImageFormatInfo_loc.dot(Field::type), "VkImageType", pImageFormatInfo->type,
                                   "VUID-VkPhysicalDeviceImageFormatInfo2-type-parameter");

        skip |= ValidateRangedEnum(pImageFormatInfo_loc.dot(Field::tiling), "VkImageTiling", pImageFormatInfo->tiling,
                                   "VUID-VkPhysicalDeviceImageFormatInfo2-tiling-parameter");

        skip |= ValidateFlags(pImageFormatInfo_loc.dot(Field::usage), "VkImageUsageFlagBits", AllVkImageUsageFlagBits,
                              pImageFormatInfo->usage, kRequiredFlags, "VUID-VkPhysicalDeviceImageFormatInfo2-usage-parameter",
                              "VUID-VkPhysicalDeviceImageFormatInfo2-usage-requiredbitmask");

        skip |= ValidateFlags(pImageFormatInfo_loc.dot(Field::flags), "VkImageCreateFlagBits", AllVkImageCreateFlagBits,
                              pImageFormatInfo->flags, kOptionalFlags, "VUID-VkPhysicalDeviceImageFormatInfo2-flags-parameter");
    }
    skip |= ValidateStructType(loc.dot(Field::pImageFormatProperties), "VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2",
                               pImageFormatProperties, VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2, true,
                               "VUID-vkGetPhysicalDeviceImageFormatProperties2-pImageFormatProperties-parameter",
                               "VUID-VkImageFormatProperties2-sType-sType");
    if (pImageFormatProperties != nullptr) {
        [[maybe_unused]] const Location pImageFormatProperties_loc = loc.dot(Field::pImageFormatProperties);
        constexpr std::array allowed_structs_VkImageFormatProperties2 = {
            VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES,
            VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT,
            VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES};

        skip |= ValidateStructPnext(
            pImageFormatProperties_loc, pImageFormatProperties->pNext, allowed_structs_VkImageFormatProperties2.size(),
            allowed_structs_VkImageFormatProperties2.data(), GeneratedVulkanHeaderVersion,
            "VUID-VkImageFormatProperties2-pNext-pNext", "VUID-VkImageFormatProperties2-sType-unique", true, false);
    }
    if (!skip)
        skip |= manual_PreCallValidateGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo,
                                                                              pImageFormatProperties, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice,
                                                                                 uint32_t* pQueueFamilyPropertyCount,
                                                                                 VkQueueFamilyProperties2* pQueueFamilyProperties,
                                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (loc.function == vvl::Func::vkGetPhysicalDeviceQueueFamilyProperties2 &&
        CheckPromotedApiAgainstVulkanVersion(physicalDevice, loc, VK_API_VERSION_1_1))
        return true;
    skip |= ValidateStructTypeArray(
        loc.dot(Field::pQueueFamilyPropertyCount), loc.dot(Field::pQueueFamilyProperties),
        "VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2", pQueueFamilyPropertyCount, pQueueFamilyProperties,
        VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2, true, false, false, "VUID-VkQueueFamilyProperties2-sType-sType",
        "VUID-vkGetPhysicalDeviceQueueFamilyProperties2-pQueueFamilyProperties-parameter", kVUIDUndefined);
    if (pQueueFamilyProperties != nullptr) {
        for (uint32_t pQueueFamilyPropertyIndex = 0; pQueueFamilyPropertyIndex < *pQueueFamilyPropertyCount;
             ++pQueueFamilyPropertyIndex) {
            [[maybe_unused]] const Location pQueueFamilyProperties_loc =
                loc.dot(Field::pQueueFamilyProperties, pQueueFamilyPropertyIndex);
            constexpr std::array allowed_structs_VkQueueFamilyProperties2 = {
                VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV};

            skip |= ValidateStructPnext(pQueueFamilyProperties_loc, pQueueFamilyProperties[pQueueFamilyPropertyIndex].pNext,
                                        allowed_structs_VkQueueFamilyProperties2.size(),
                                        allowed_structs_VkQueueFamilyProperties2.data(), GeneratedVulkanHeaderVersion,
                                        "VUID-VkQueueFamilyProperties2-pNext-pNext", "VUID-VkQueueFamilyProperties2-sType-unique",
                                        true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice,
                                                                            VkPhysicalDeviceMemoryProperties2* pMemoryProperties,
                                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (loc.function == vvl::Func::vkGetPhysicalDeviceMemoryProperties2 &&
        CheckPromotedApiAgainstVulkanVersion(physicalDevice, loc, VK_API_VERSION_1_1))
        return true;
    skip |= ValidateStructType(loc.dot(Field::pMemoryProperties), "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2",
                               pMemoryProperties, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2, true,
                               "VUID-vkGetPhysicalDeviceMemoryProperties2-pMemoryProperties-parameter",
                               "VUID-VkPhysicalDeviceMemoryProperties2-sType-sType");
    if (pMemoryProperties != nullptr) {
        [[maybe_unused]] const Location pMemoryProperties_loc = loc.dot(Field::pMemoryProperties);
        constexpr std::array allowed_structs_VkPhysicalDeviceMemoryProperties2 = {
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT};

        skip |= ValidateStructPnext(pMemoryProperties_loc, pMemoryProperties->pNext,
                                    allowed_structs_VkPhysicalDeviceMemoryProperties2.size(),
                                    allowed_structs_VkPhysicalDeviceMemoryProperties2.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkPhysicalDeviceMemoryProperties2-pNext-pNext",
                                    "VUID-VkPhysicalDeviceMemoryProperties2-sType-unique", true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pQueueInfo), "VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2", pQueueInfo,
                               VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2, true, "VUID-vkGetDeviceQueue2-pQueueInfo-parameter",
                               "VUID-VkDeviceQueueInfo2-sType-sType");
    if (pQueueInfo != nullptr) {
        [[maybe_unused]] const Location pQueueInfo_loc = loc.dot(Field::pQueueInfo);
        skip |= ValidateStructPnext(pQueueInfo_loc, pQueueInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDeviceQueueInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags(pQueueInfo_loc.dot(Field::flags), "VkDeviceQueueCreateFlagBits", AllVkDeviceQueueCreateFlagBits,
                              pQueueInfo->flags, kOptionalFlags, "VUID-VkDeviceQueueInfo2-flags-parameter");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pQueue), pQueue, "VUID-vkGetDeviceQueue2-pQueue-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCreateSamplerYcbcrConversion(VkDevice device,
                                                                      const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                                      const VkAllocationCallbacks* pAllocator,
                                                                      VkSamplerYcbcrConversion* pYcbcrConversion,
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO, true,
                               "VUID-vkCreateSamplerYcbcrConversion-pCreateInfo-parameter",
                               "VUID-VkSamplerYcbcrConversionCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkSamplerYcbcrConversionCreateInfo = {VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkSamplerYcbcrConversionCreateInfo.size(),
                                    allowed_structs_VkSamplerYcbcrConversionCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkSamplerYcbcrConversionCreateInfo-pNext-pNext",
                                    "VUID-VkSamplerYcbcrConversionCreateInfo-sType-unique", false, true);

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::format), "VkFormat", pCreateInfo->format,
                                   "VUID-VkSamplerYcbcrConversionCreateInfo-format-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::ycbcrModel), "VkSamplerYcbcrModelConversion", pCreateInfo->ycbcrModel,
                                   "VUID-VkSamplerYcbcrConversionCreateInfo-ycbcrModel-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::ycbcrRange), "VkSamplerYcbcrRange", pCreateInfo->ycbcrRange,
                                   "VUID-VkSamplerYcbcrConversionCreateInfo-ycbcrRange-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::r), "VkComponentSwizzle", pCreateInfo->components.r,
                                   "VUID-VkComponentMapping-r-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::g), "VkComponentSwizzle", pCreateInfo->components.g,
                                   "VUID-VkComponentMapping-g-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::b), "VkComponentSwizzle", pCreateInfo->components.b,
                                   "VUID-VkComponentMapping-b-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::a), "VkComponentSwizzle", pCreateInfo->components.a,
                                   "VUID-VkComponentMapping-a-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::xChromaOffset), "VkChromaLocation", pCreateInfo->xChromaOffset,
                                   "VUID-VkSamplerYcbcrConversionCreateInfo-xChromaOffset-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::yChromaOffset), "VkChromaLocation", pCreateInfo->yChromaOffset,
                                   "VUID-VkSamplerYcbcrConversionCreateInfo-yChromaOffset-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::chromaFilter), "VkFilter", pCreateInfo->chromaFilter,
                                   "VUID-VkSamplerYcbcrConversionCreateInfo-chromaFilter-parameter");

        skip |= ValidateBool32(pCreateInfo_loc.dot(Field::forceExplicitReconstruction), pCreateInfo->forceExplicitReconstruction);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateSamplerYcbcrConversion-pAllocator-null",
                         "vkCreateSamplerYcbcrConversion(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pYcbcrConversion), pYcbcrConversion,
                                    "VUID-vkCreateSamplerYcbcrConversion-pYcbcrConversion-parameter");
    if (!skip)
        skip |= manual_PreCallValidateCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion,
                                                                       const VkAllocationCallbacks* pAllocator,
                                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroySamplerYcbcrConversion-pAllocator-null",
                         "vkDestroySamplerYcbcrConversion(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
    VkExternalBufferProperties* pExternalBufferProperties, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (loc.function == vvl::Func::vkGetPhysicalDeviceExternalBufferProperties &&
        CheckPromotedApiAgainstVulkanVersion(physicalDevice, loc, VK_API_VERSION_1_1))
        return true;
    skip |= ValidateStructType(loc.dot(Field::pExternalBufferInfo), "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO",
                               pExternalBufferInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO, true,
                               "VUID-vkGetPhysicalDeviceExternalBufferProperties-pExternalBufferInfo-parameter",
                               "VUID-VkPhysicalDeviceExternalBufferInfo-sType-sType");
    if (pExternalBufferInfo != nullptr) {
        [[maybe_unused]] const Location pExternalBufferInfo_loc = loc.dot(Field::pExternalBufferInfo);
        skip |= ValidateStructPnext(pExternalBufferInfo_loc, pExternalBufferInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkPhysicalDeviceExternalBufferInfo-pNext-pNext", kVUIDUndefined, true, true);

        skip |=
            ValidateFlags(pExternalBufferInfo_loc.dot(Field::flags), "VkBufferCreateFlagBits", AllVkBufferCreateFlagBits,
                          pExternalBufferInfo->flags, kOptionalFlags, "VUID-VkPhysicalDeviceExternalBufferInfo-flags-parameter");

        skip |= ValidateFlags(pExternalBufferInfo_loc.dot(Field::usage), "VkBufferUsageFlagBits", AllVkBufferUsageFlagBits,
                              pExternalBufferInfo->usage, kRequiredFlags, "VUID-VkPhysicalDeviceExternalBufferInfo-usage-parameter",
                              "VUID-VkPhysicalDeviceExternalBufferInfo-usage-requiredbitmask");

        skip |= ValidateFlags(pExternalBufferInfo_loc.dot(Field::handleType), "VkExternalMemoryHandleTypeFlagBits",
                              AllVkExternalMemoryHandleTypeFlagBits, pExternalBufferInfo->handleType, kRequiredSingleBit,
                              "VUID-VkPhysicalDeviceExternalBufferInfo-handleType-parameter",
                              "VUID-VkPhysicalDeviceExternalBufferInfo-handleType-parameter");
    }
    skip |= ValidateStructType(loc.dot(Field::pExternalBufferProperties), "VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES",
                               pExternalBufferProperties, VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES, true,
                               "VUID-vkGetPhysicalDeviceExternalBufferProperties-pExternalBufferProperties-parameter",
                               "VUID-VkExternalBufferProperties-sType-sType");
    if (pExternalBufferProperties != nullptr) {
        [[maybe_unused]] const Location pExternalBufferProperties_loc = loc.dot(Field::pExternalBufferProperties);
        skip |= ValidateStructPnext(pExternalBufferProperties_loc, pExternalBufferProperties->pNext, 0, nullptr,
                                    GeneratedVulkanHeaderVersion, "VUID-VkExternalBufferProperties-pNext-pNext", kVUIDUndefined,
                                    true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceExternalFenceProperties(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
    VkExternalFenceProperties* pExternalFenceProperties, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (loc.function == vvl::Func::vkGetPhysicalDeviceExternalFenceProperties &&
        CheckPromotedApiAgainstVulkanVersion(physicalDevice, loc, VK_API_VERSION_1_1))
        return true;
    skip |= ValidateStructType(loc.dot(Field::pExternalFenceInfo), "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO",
                               pExternalFenceInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO, true,
                               "VUID-vkGetPhysicalDeviceExternalFenceProperties-pExternalFenceInfo-parameter",
                               "VUID-VkPhysicalDeviceExternalFenceInfo-sType-sType");
    if (pExternalFenceInfo != nullptr) {
        [[maybe_unused]] const Location pExternalFenceInfo_loc = loc.dot(Field::pExternalFenceInfo);
        skip |= ValidateStructPnext(pExternalFenceInfo_loc, pExternalFenceInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkPhysicalDeviceExternalFenceInfo-pNext-pNext", kVUIDUndefined, true, true);

        skip |= ValidateFlags(pExternalFenceInfo_loc.dot(Field::handleType), "VkExternalFenceHandleTypeFlagBits",
                              AllVkExternalFenceHandleTypeFlagBits, pExternalFenceInfo->handleType, kRequiredSingleBit,
                              "VUID-VkPhysicalDeviceExternalFenceInfo-handleType-parameter",
                              "VUID-VkPhysicalDeviceExternalFenceInfo-handleType-parameter");
    }
    skip |= ValidateStructType(loc.dot(Field::pExternalFenceProperties), "VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES",
                               pExternalFenceProperties, VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES, true,
                               "VUID-vkGetPhysicalDeviceExternalFenceProperties-pExternalFenceProperties-parameter",
                               "VUID-VkExternalFenceProperties-sType-sType");
    if (pExternalFenceProperties != nullptr) {
        [[maybe_unused]] const Location pExternalFenceProperties_loc = loc.dot(Field::pExternalFenceProperties);
        skip |= ValidateStructPnext(pExternalFenceProperties_loc, pExternalFenceProperties->pNext, 0, nullptr,
                                    GeneratedVulkanHeaderVersion, "VUID-VkExternalFenceProperties-pNext-pNext", kVUIDUndefined,
                                    true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties* pExternalSemaphoreProperties, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (loc.function == vvl::Func::vkGetPhysicalDeviceExternalSemaphoreProperties &&
        CheckPromotedApiAgainstVulkanVersion(physicalDevice, loc, VK_API_VERSION_1_1))
        return true;
    skip |= ValidateStructType(loc.dot(Field::pExternalSemaphoreInfo), "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO",
                               pExternalSemaphoreInfo, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO, true,
                               "VUID-vkGetPhysicalDeviceExternalSemaphoreProperties-pExternalSemaphoreInfo-parameter",
                               "VUID-VkPhysicalDeviceExternalSemaphoreInfo-sType-sType");
    if (pExternalSemaphoreInfo != nullptr) {
        [[maybe_unused]] const Location pExternalSemaphoreInfo_loc = loc.dot(Field::pExternalSemaphoreInfo);
        constexpr std::array allowed_structs_VkPhysicalDeviceExternalSemaphoreInfo = {VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO};

        skip |= ValidateStructPnext(pExternalSemaphoreInfo_loc, pExternalSemaphoreInfo->pNext,
                                    allowed_structs_VkPhysicalDeviceExternalSemaphoreInfo.size(),
                                    allowed_structs_VkPhysicalDeviceExternalSemaphoreInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkPhysicalDeviceExternalSemaphoreInfo-pNext-pNext",
                                    "VUID-VkPhysicalDeviceExternalSemaphoreInfo-sType-unique", true, true);

        skip |= ValidateFlags(pExternalSemaphoreInfo_loc.dot(Field::handleType), "VkExternalSemaphoreHandleTypeFlagBits",
                              AllVkExternalSemaphoreHandleTypeFlagBits, pExternalSemaphoreInfo->handleType, kRequiredSingleBit,
                              "VUID-VkPhysicalDeviceExternalSemaphoreInfo-handleType-parameter",
                              "VUID-VkPhysicalDeviceExternalSemaphoreInfo-handleType-parameter");
    }
    skip |= ValidateStructType(loc.dot(Field::pExternalSemaphoreProperties), "VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES",
                               pExternalSemaphoreProperties, VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES, true,
                               "VUID-vkGetPhysicalDeviceExternalSemaphoreProperties-pExternalSemaphoreProperties-parameter",
                               "VUID-VkExternalSemaphoreProperties-sType-sType");
    if (pExternalSemaphoreProperties != nullptr) {
        [[maybe_unused]] const Location pExternalSemaphoreProperties_loc = loc.dot(Field::pExternalSemaphoreProperties);
        skip |= ValidateStructPnext(pExternalSemaphoreProperties_loc, pExternalSemaphoreProperties->pNext, 0, nullptr,
                                    GeneratedVulkanHeaderVersion, "VUID-VkExternalSemaphoreProperties-pNext-pNext", kVUIDUndefined,
                                    true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDescriptorSetLayoutSupport(VkDevice device,
                                                                       const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                                       VkDescriptorSetLayoutSupport* pSupport,
                                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO, true,
                               "VUID-vkGetDescriptorSetLayoutSupport-pCreateInfo-parameter",
                               "VUID-VkDescriptorSetLayoutCreateInfo-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkDescriptorSetLayoutCreateInfo = {
            VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkDescriptorSetLayoutCreateInfo.size(),
                                    allowed_structs_VkDescriptorSetLayoutCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkDescriptorSetLayoutCreateInfo-pNext-pNext",
                                    "VUID-VkDescriptorSetLayoutCreateInfo-sType-unique", false, true);

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkDescriptorSetLayoutCreateFlagBits",
                              AllVkDescriptorSetLayoutCreateFlagBits, pCreateInfo->flags, kOptionalFlags,
                              "VUID-VkDescriptorSetLayoutCreateInfo-flags-parameter");

        skip |= ValidateArray(pCreateInfo_loc.dot(Field::bindingCount), pCreateInfo_loc.dot(Field::pBindings),
                              pCreateInfo->bindingCount, &pCreateInfo->pBindings, false, true, kVUIDUndefined,
                              "VUID-VkDescriptorSetLayoutCreateInfo-pBindings-parameter");

        if (pCreateInfo->pBindings != nullptr) {
            for (uint32_t bindingIndex = 0; bindingIndex < pCreateInfo->bindingCount; ++bindingIndex) {
                [[maybe_unused]] const Location pBindings_loc = pCreateInfo_loc.dot(Field::pBindings, bindingIndex);
                skip |= ValidateRangedEnum(pBindings_loc.dot(Field::descriptorType), "VkDescriptorType",
                                           pCreateInfo->pBindings[bindingIndex].descriptorType,
                                           "VUID-VkDescriptorSetLayoutBinding-descriptorType-parameter");
            }
        }
    }
    skip |= ValidateStructType(loc.dot(Field::pSupport), "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT", pSupport,
                               VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT, true,
                               "VUID-vkGetDescriptorSetLayoutSupport-pSupport-parameter",
                               "VUID-VkDescriptorSetLayoutSupport-sType-sType");
    if (pSupport != nullptr) {
        [[maybe_unused]] const Location pSupport_loc = loc.dot(Field::pSupport);
        constexpr std::array allowed_structs_VkDescriptorSetLayoutSupport = {
            VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT};

        skip |= ValidateStructPnext(pSupport_loc, pSupport->pNext, allowed_structs_VkDescriptorSetLayoutSupport.size(),
                                    allowed_structs_VkDescriptorSetLayoutSupport.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkDescriptorSetLayoutSupport-pNext-pNext",
                                    "VUID-VkDescriptorSetLayoutSupport-sType-unique", false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                              VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                              uint32_t maxDrawCount, uint32_t stride,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::buffer), buffer);
    skip |= ValidateRequiredHandle(loc.dot(Field::countBuffer), countBuffer);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                     VkDeviceSize offset, VkBuffer countBuffer,
                                                                     VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                                     uint32_t stride, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::buffer), buffer);
    skip |= ValidateRequiredHandle(loc.dot(Field::countBuffer), countBuffer);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                                           const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2", pCreateInfo,
                               VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2, true, "VUID-vkCreateRenderPass2-pCreateInfo-parameter",
                               "VUID-VkRenderPassCreateInfo2-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkRenderPassCreateInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkRenderPassCreateInfo2-flags-zerobitmask");

        skip |= ValidateStructTypeArray(pCreateInfo_loc.dot(Field::attachmentCount), pCreateInfo_loc.dot(Field::pAttachments),
                                        "VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2", pCreateInfo->attachmentCount,
                                        pCreateInfo->pAttachments, VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2, false, true,
                                        "VUID-VkAttachmentDescription2-sType-sType",
                                        "VUID-VkRenderPassCreateInfo2-pAttachments-parameter", kVUIDUndefined);

        if (pCreateInfo->pAttachments != nullptr) {
            for (uint32_t attachmentIndex = 0; attachmentIndex < pCreateInfo->attachmentCount; ++attachmentIndex) {
                [[maybe_unused]] const Location pAttachments_loc = pCreateInfo_loc.dot(Field::pAttachments, attachmentIndex);
                constexpr std::array allowed_structs_VkAttachmentDescription2 = {
                    VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT};

                skip |= ValidateStructPnext(pAttachments_loc, pCreateInfo->pAttachments[attachmentIndex].pNext,
                                            allowed_structs_VkAttachmentDescription2.size(),
                                            allowed_structs_VkAttachmentDescription2.data(), GeneratedVulkanHeaderVersion,
                                            "VUID-VkAttachmentDescription2-pNext-pNext",
                                            "VUID-VkAttachmentDescription2-sType-unique", false, true);

                skip |= ValidateFlags(pAttachments_loc.dot(Field::flags), "VkAttachmentDescriptionFlagBits",
                                      AllVkAttachmentDescriptionFlagBits, pCreateInfo->pAttachments[attachmentIndex].flags,
                                      kOptionalFlags, "VUID-VkAttachmentDescription2-flags-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::format), "VkFormat",
                                           pCreateInfo->pAttachments[attachmentIndex].format,
                                           "VUID-VkAttachmentDescription2-format-parameter");

                skip |= ValidateFlags(pAttachments_loc.dot(Field::samples), "VkSampleCountFlagBits", AllVkSampleCountFlagBits,
                                      pCreateInfo->pAttachments[attachmentIndex].samples, kRequiredSingleBit,
                                      "VUID-VkAttachmentDescription2-samples-parameter",
                                      "VUID-VkAttachmentDescription2-samples-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::loadOp), "VkAttachmentLoadOp",
                                           pCreateInfo->pAttachments[attachmentIndex].loadOp,
                                           "VUID-VkAttachmentDescription2-loadOp-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::storeOp), "VkAttachmentStoreOp",
                                           pCreateInfo->pAttachments[attachmentIndex].storeOp,
                                           "VUID-VkAttachmentDescription2-storeOp-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::stencilLoadOp), "VkAttachmentLoadOp",
                                           pCreateInfo->pAttachments[attachmentIndex].stencilLoadOp,
                                           "VUID-VkAttachmentDescription2-stencilLoadOp-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::stencilStoreOp), "VkAttachmentStoreOp",
                                           pCreateInfo->pAttachments[attachmentIndex].stencilStoreOp,
                                           "VUID-VkAttachmentDescription2-stencilStoreOp-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::initialLayout), "VkImageLayout",
                                           pCreateInfo->pAttachments[attachmentIndex].initialLayout,
                                           "VUID-VkAttachmentDescription2-initialLayout-parameter");

                skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::finalLayout), "VkImageLayout",
                                           pCreateInfo->pAttachments[attachmentIndex].finalLayout,
                                           "VUID-VkAttachmentDescription2-finalLayout-parameter");
            }
        }

        skip |= ValidateStructTypeArray(
            pCreateInfo_loc.dot(Field::subpassCount), pCreateInfo_loc.dot(Field::pSubpasses),
            "VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2", pCreateInfo->subpassCount, pCreateInfo->pSubpasses,
            VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2, true, true, "VUID-VkSubpassDescription2-sType-sType",
            "VUID-VkRenderPassCreateInfo2-pSubpasses-parameter", "VUID-VkRenderPassCreateInfo2-subpassCount-arraylength");

        if (pCreateInfo->pSubpasses != nullptr) {
            for (uint32_t subpassIndex = 0; subpassIndex < pCreateInfo->subpassCount; ++subpassIndex) {
                [[maybe_unused]] const Location pSubpasses_loc = pCreateInfo_loc.dot(Field::pSubpasses, subpassIndex);
                constexpr std::array allowed_structs_VkSubpassDescription2 = {
                    VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR,
                    VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE};

                skip |= ValidateStructPnext(
                    pSubpasses_loc, pCreateInfo->pSubpasses[subpassIndex].pNext, allowed_structs_VkSubpassDescription2.size(),
                    allowed_structs_VkSubpassDescription2.data(), GeneratedVulkanHeaderVersion,
                    "VUID-VkSubpassDescription2-pNext-pNext", "VUID-VkSubpassDescription2-sType-unique", false, true);

                skip |= ValidateReservedFlags(pSubpasses_loc.dot(Field::flags), pCreateInfo->pSubpasses[subpassIndex].flags,
                                              "VUID-VkSubpassDescription2-flags-zerobitmask");

                skip |= ValidateRangedEnum(pSubpasses_loc.dot(Field::pipelineBindPoint), "VkPipelineBindPoint",
                                           pCreateInfo->pSubpasses[subpassIndex].pipelineBindPoint,
                                           "VUID-VkSubpassDescription2-pipelineBindPoint-parameter");

                skip |= ValidateStructTypeArray(
                    pSubpasses_loc.dot(Field::inputAttachmentCount), pSubpasses_loc.dot(Field::pInputAttachments),
                    "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2", pCreateInfo->pSubpasses[subpassIndex].inputAttachmentCount,
                    pCreateInfo->pSubpasses[subpassIndex].pInputAttachments, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2, false, true,
                    "VUID-VkAttachmentReference2-sType-sType", "VUID-VkSubpassDescription2-pInputAttachments-parameter",
                    kVUIDUndefined);

                if (pCreateInfo->pSubpasses[subpassIndex].pInputAttachments != nullptr) {
                    for (uint32_t inputAttachmentIndex = 0;
                         inputAttachmentIndex < pCreateInfo->pSubpasses[subpassIndex].inputAttachmentCount;
                         ++inputAttachmentIndex) {
                        [[maybe_unused]] const Location pInputAttachments_loc =
                            pSubpasses_loc.dot(Field::pInputAttachments, inputAttachmentIndex);
                        constexpr std::array allowed_structs_VkAttachmentReference2 = {
                            VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT};

                        skip |= ValidateStructPnext(
                            pInputAttachments_loc,
                            pCreateInfo->pSubpasses[subpassIndex].pInputAttachments[inputAttachmentIndex].pNext,
                            allowed_structs_VkAttachmentReference2.size(), allowed_structs_VkAttachmentReference2.data(),
                            GeneratedVulkanHeaderVersion, "VUID-VkAttachmentReference2-pNext-pNext",
                            "VUID-VkAttachmentReference2-sType-unique", false, true);

                        skip |=
                            ValidateRangedEnum(pInputAttachments_loc.dot(Field::layout), "VkImageLayout",
                                               pCreateInfo->pSubpasses[subpassIndex].pInputAttachments[inputAttachmentIndex].layout,
                                               "VUID-VkAttachmentReference2-layout-parameter");
                    }
                }

                skip |= ValidateStructTypeArray(
                    pSubpasses_loc.dot(Field::colorAttachmentCount), pSubpasses_loc.dot(Field::pColorAttachments),
                    "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2", pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount,
                    pCreateInfo->pSubpasses[subpassIndex].pColorAttachments, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2, false, true,
                    "VUID-VkAttachmentReference2-sType-sType", "VUID-VkSubpassDescription2-pColorAttachments-parameter",
                    kVUIDUndefined);

                if (pCreateInfo->pSubpasses[subpassIndex].pColorAttachments != nullptr) {
                    for (uint32_t colorAttachmentIndex = 0;
                         colorAttachmentIndex < pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount;
                         ++colorAttachmentIndex) {
                        [[maybe_unused]] const Location pColorAttachments_loc =
                            pSubpasses_loc.dot(Field::pColorAttachments, colorAttachmentIndex);
                        constexpr std::array allowed_structs_VkAttachmentReference2 = {
                            VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT};

                        skip |= ValidateStructPnext(
                            pColorAttachments_loc,
                            pCreateInfo->pSubpasses[subpassIndex].pColorAttachments[colorAttachmentIndex].pNext,
                            allowed_structs_VkAttachmentReference2.size(), allowed_structs_VkAttachmentReference2.data(),
                            GeneratedVulkanHeaderVersion, "VUID-VkAttachmentReference2-pNext-pNext",
                            "VUID-VkAttachmentReference2-sType-unique", false, true);

                        skip |=
                            ValidateRangedEnum(pColorAttachments_loc.dot(Field::layout), "VkImageLayout",
                                               pCreateInfo->pSubpasses[subpassIndex].pColorAttachments[colorAttachmentIndex].layout,
                                               "VUID-VkAttachmentReference2-layout-parameter");
                    }
                }

                skip |= ValidateStructTypeArray(
                    pSubpasses_loc.dot(Field::colorAttachmentCount), pSubpasses_loc.dot(Field::pResolveAttachments),
                    "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2", pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount,
                    pCreateInfo->pSubpasses[subpassIndex].pResolveAttachments, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2, false,
                    false, "VUID-VkAttachmentReference2-sType-sType", "VUID-VkSubpassDescription2-pResolveAttachments-parameter",
                    kVUIDUndefined);

                if (pCreateInfo->pSubpasses[subpassIndex].pResolveAttachments != nullptr) {
                    for (uint32_t colorAttachmentIndex = 0;
                         colorAttachmentIndex < pCreateInfo->pSubpasses[subpassIndex].colorAttachmentCount;
                         ++colorAttachmentIndex) {
                        [[maybe_unused]] const Location pResolveAttachments_loc =
                            pSubpasses_loc.dot(Field::pResolveAttachments, colorAttachmentIndex);
                        constexpr std::array allowed_structs_VkAttachmentReference2 = {
                            VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT};

                        skip |= ValidateStructPnext(
                            pResolveAttachments_loc,
                            pCreateInfo->pSubpasses[subpassIndex].pResolveAttachments[colorAttachmentIndex].pNext,
                            allowed_structs_VkAttachmentReference2.size(), allowed_structs_VkAttachmentReference2.data(),
                            GeneratedVulkanHeaderVersion, "VUID-VkAttachmentReference2-pNext-pNext",
                            "VUID-VkAttachmentReference2-sType-unique", false, true);

                        skip |= ValidateRangedEnum(
                            pResolveAttachments_loc.dot(Field::layout), "VkImageLayout",
                            pCreateInfo->pSubpasses[subpassIndex].pResolveAttachments[colorAttachmentIndex].layout,
                            "VUID-VkAttachmentReference2-layout-parameter");
                    }
                }

                skip |= ValidateStructType(
                    pSubpasses_loc.dot(Field::pDepthStencilAttachment), "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2",
                    pCreateInfo->pSubpasses[subpassIndex].pDepthStencilAttachment, VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2, false,
                    "VUID-VkSubpassDescription2-pDepthStencilAttachment-parameter", "VUID-VkAttachmentReference2-sType-sType");

                if (pCreateInfo->pSubpasses[subpassIndex].pDepthStencilAttachment != nullptr) {
                    [[maybe_unused]] const Location pDepthStencilAttachment_loc =
                        pSubpasses_loc.dot(Field::pDepthStencilAttachment);
                    constexpr std::array allowed_structs_VkAttachmentReference2 = {
                        VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT};

                    skip |= ValidateStructPnext(
                        pDepthStencilAttachment_loc, pCreateInfo->pSubpasses[subpassIndex].pDepthStencilAttachment->pNext,
                        allowed_structs_VkAttachmentReference2.size(), allowed_structs_VkAttachmentReference2.data(),
                        GeneratedVulkanHeaderVersion, "VUID-VkAttachmentReference2-pNext-pNext",
                        "VUID-VkAttachmentReference2-sType-unique", false, true);

                    skip |= ValidateRangedEnum(pDepthStencilAttachment_loc.dot(Field::layout), "VkImageLayout",
                                               pCreateInfo->pSubpasses[subpassIndex].pDepthStencilAttachment->layout,
                                               "VUID-VkAttachmentReference2-layout-parameter");
                }

                skip |= ValidateArray(pSubpasses_loc.dot(Field::preserveAttachmentCount),
                                      pSubpasses_loc.dot(Field::pPreserveAttachments),
                                      pCreateInfo->pSubpasses[subpassIndex].preserveAttachmentCount,
                                      &pCreateInfo->pSubpasses[subpassIndex].pPreserveAttachments, false, true, kVUIDUndefined,
                                      "VUID-VkSubpassDescription2-pPreserveAttachments-parameter");
            }
        }

        skip |= ValidateStructTypeArray(pCreateInfo_loc.dot(Field::dependencyCount), pCreateInfo_loc.dot(Field::pDependencies),
                                        "VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2", pCreateInfo->dependencyCount,
                                        pCreateInfo->pDependencies, VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2, false, true,
                                        "VUID-VkSubpassDependency2-sType-sType",
                                        "VUID-VkRenderPassCreateInfo2-pDependencies-parameter", kVUIDUndefined);

        if (pCreateInfo->pDependencies != nullptr) {
            for (uint32_t dependencyIndex = 0; dependencyIndex < pCreateInfo->dependencyCount; ++dependencyIndex) {
                [[maybe_unused]] const Location pDependencies_loc = pCreateInfo_loc.dot(Field::pDependencies, dependencyIndex);
                constexpr std::array allowed_structs_VkSubpassDependency2 = {VK_STRUCTURE_TYPE_MEMORY_BARRIER_2};

                skip |=
                    ValidateStructPnext(pDependencies_loc, pCreateInfo->pDependencies[dependencyIndex].pNext,
                                        allowed_structs_VkSubpassDependency2.size(), allowed_structs_VkSubpassDependency2.data(),
                                        GeneratedVulkanHeaderVersion, "VUID-VkSubpassDependency2-pNext-pNext",
                                        "VUID-VkSubpassDependency2-sType-unique", false, true);

                if (!vku::FindStructInPNextChain<VkMemoryBarrier2>(pCreateInfo->pDependencies[dependencyIndex].pNext)) {
                    skip |= ValidateFlags(pDependencies_loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits",
                                          AllVkPipelineStageFlagBits, pCreateInfo->pDependencies[dependencyIndex].srcStageMask,
                                          kOptionalFlags, "VUID-VkSubpassDependency2-srcStageMask-parameter");
                }

                if (!vku::FindStructInPNextChain<VkMemoryBarrier2>(pCreateInfo->pDependencies[dependencyIndex].pNext)) {
                    skip |= ValidateFlags(pDependencies_loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits",
                                          AllVkPipelineStageFlagBits, pCreateInfo->pDependencies[dependencyIndex].dstStageMask,
                                          kOptionalFlags, "VUID-VkSubpassDependency2-dstStageMask-parameter");
                }

                if (!vku::FindStructInPNextChain<VkMemoryBarrier2>(pCreateInfo->pDependencies[dependencyIndex].pNext)) {
                    skip |= ValidateFlags(pDependencies_loc.dot(Field::srcAccessMask), "VkAccessFlagBits", AllVkAccessFlagBits,
                                          pCreateInfo->pDependencies[dependencyIndex].srcAccessMask, kOptionalFlags,
                                          "VUID-VkSubpassDependency2-srcAccessMask-parameter");
                }

                if (!vku::FindStructInPNextChain<VkMemoryBarrier2>(pCreateInfo->pDependencies[dependencyIndex].pNext)) {
                    skip |= ValidateFlags(pDependencies_loc.dot(Field::dstAccessMask), "VkAccessFlagBits", AllVkAccessFlagBits,
                                          pCreateInfo->pDependencies[dependencyIndex].dstAccessMask, kOptionalFlags,
                                          "VUID-VkSubpassDependency2-dstAccessMask-parameter");
                }

                skip |= ValidateFlags(pDependencies_loc.dot(Field::dependencyFlags), "VkDependencyFlagBits",
                                      AllVkDependencyFlagBits, pCreateInfo->pDependencies[dependencyIndex].dependencyFlags,
                                      kOptionalFlags, "VUID-VkSubpassDependency2-dependencyFlags-parameter");
            }
        }

        skip |= ValidateArray(pCreateInfo_loc.dot(Field::correlatedViewMaskCount), pCreateInfo_loc.dot(Field::pCorrelatedViewMasks),
                              pCreateInfo->correlatedViewMaskCount, &pCreateInfo->pCorrelatedViewMasks, false, true, kVUIDUndefined,
                              "VUID-VkRenderPassCreateInfo2-pCorrelatedViewMasks-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateRenderPass2-pAllocator-null", "vkCreateRenderPass2(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pRenderPass), pRenderPass, "VUID-vkCreateRenderPass2-pRenderPass-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBeginRenderPass2(VkCommandBuffer commandBuffer,
                                                             const VkRenderPassBeginInfo* pRenderPassBegin,
                                                             const VkSubpassBeginInfo* pSubpassBeginInfo,
                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pRenderPassBegin), "VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO", pRenderPassBegin,
                               VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO, true,
                               "VUID-vkCmdBeginRenderPass2-pRenderPassBegin-parameter", "VUID-VkRenderPassBeginInfo-sType-sType");
    if (pRenderPassBegin != nullptr) {
        [[maybe_unused]] const Location pRenderPassBegin_loc = loc.dot(Field::pRenderPassBegin);
        constexpr std::array allowed_structs_VkRenderPassBeginInfo = {
            VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO, VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO,
            VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT};

        skip |=
            ValidateStructPnext(pRenderPassBegin_loc, pRenderPassBegin->pNext, allowed_structs_VkRenderPassBeginInfo.size(),
                                allowed_structs_VkRenderPassBeginInfo.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkRenderPassBeginInfo-pNext-pNext", "VUID-VkRenderPassBeginInfo-sType-unique", false, true);

        skip |= ValidateRequiredHandle(pRenderPassBegin_loc.dot(Field::renderPass), pRenderPassBegin->renderPass);

        skip |= ValidateRequiredHandle(pRenderPassBegin_loc.dot(Field::framebuffer), pRenderPassBegin->framebuffer);

        // No xml-driven validation

        // No xml-driven validation
    }
    skip |= ValidateStructType(loc.dot(Field::pSubpassBeginInfo), "VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO", pSubpassBeginInfo,
                               VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO, true, "VUID-vkCmdBeginRenderPass2-pSubpassBeginInfo-parameter",
                               "VUID-VkSubpassBeginInfo-sType-sType");
    if (pSubpassBeginInfo != nullptr) {
        [[maybe_unused]] const Location pSubpassBeginInfo_loc = loc.dot(Field::pSubpassBeginInfo);
        skip |= ValidateStructPnext(pSubpassBeginInfo_loc, pSubpassBeginInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkSubpassBeginInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum(pSubpassBeginInfo_loc.dot(Field::contents), "VkSubpassContents", pSubpassBeginInfo->contents,
                                   "VUID-VkSubpassBeginInfo-contents-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                                         const VkSubpassEndInfo* pSubpassEndInfo,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pSubpassBeginInfo), "VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO", pSubpassBeginInfo,
                               VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO, true, "VUID-vkCmdNextSubpass2-pSubpassBeginInfo-parameter",
                               "VUID-VkSubpassBeginInfo-sType-sType");
    if (pSubpassBeginInfo != nullptr) {
        [[maybe_unused]] const Location pSubpassBeginInfo_loc = loc.dot(Field::pSubpassBeginInfo);
        skip |= ValidateStructPnext(pSubpassBeginInfo_loc, pSubpassBeginInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkSubpassBeginInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum(pSubpassBeginInfo_loc.dot(Field::contents), "VkSubpassContents", pSubpassBeginInfo->contents,
                                   "VUID-VkSubpassBeginInfo-contents-parameter");
    }
    skip |= ValidateStructType(loc.dot(Field::pSubpassEndInfo), "VK_STRUCTURE_TYPE_SUBPASS_END_INFO", pSubpassEndInfo,
                               VK_STRUCTURE_TYPE_SUBPASS_END_INFO, true, "VUID-vkCmdNextSubpass2-pSubpassEndInfo-parameter",
                               "VUID-VkSubpassEndInfo-sType-sType");
    if (pSubpassEndInfo != nullptr) {
        [[maybe_unused]] const Location pSubpassEndInfo_loc = loc.dot(Field::pSubpassEndInfo);
        skip |= ValidateStructPnext(pSubpassEndInfo_loc, pSubpassEndInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkSubpassEndInfo-pNext-pNext", kVUIDUndefined, false, true);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pSubpassEndInfo), "VK_STRUCTURE_TYPE_SUBPASS_END_INFO", pSubpassEndInfo,
                               VK_STRUCTURE_TYPE_SUBPASS_END_INFO, true, "VUID-vkCmdEndRenderPass2-pSubpassEndInfo-parameter",
                               "VUID-VkSubpassEndInfo-sType-sType");
    if (pSubpassEndInfo != nullptr) {
        [[maybe_unused]] const Location pSubpassEndInfo_loc = loc.dot(Field::pSubpassEndInfo);
        skip |= ValidateStructPnext(pSubpassEndInfo_loc, pSubpassEndInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkSubpassEndInfo-pNext-pNext", kVUIDUndefined, false, true);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                                        uint32_t queryCount, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::queryPool), queryPool);
    return skip;
}

bool StatelessValidation::PreCallValidateGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::semaphore), semaphore);
    skip |= ValidateRequiredPointer(loc.dot(Field::pValue), pValue, "VUID-vkGetSemaphoreCounterValue-pValue-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pWaitInfo), "VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO", pWaitInfo,
                               VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO, true, "VUID-vkWaitSemaphores-pWaitInfo-parameter",
                               "VUID-VkSemaphoreWaitInfo-sType-sType");
    if (pWaitInfo != nullptr) {
        [[maybe_unused]] const Location pWaitInfo_loc = loc.dot(Field::pWaitInfo);
        skip |= ValidateStructPnext(pWaitInfo_loc, pWaitInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkSemaphoreWaitInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags(pWaitInfo_loc.dot(Field::flags), "VkSemaphoreWaitFlagBits", AllVkSemaphoreWaitFlagBits,
                              pWaitInfo->flags, kOptionalFlags, "VUID-VkSemaphoreWaitInfo-flags-parameter");

        skip |= ValidateHandleArray(pWaitInfo_loc.dot(Field::semaphoreCount), pWaitInfo_loc.dot(Field::pSemaphores),
                                    pWaitInfo->semaphoreCount, pWaitInfo->pSemaphores, true, true, kVUIDUndefined);

        skip |= ValidateArray(pWaitInfo_loc.dot(Field::semaphoreCount), pWaitInfo_loc.dot(Field::pValues),
                              pWaitInfo->semaphoreCount, &pWaitInfo->pValues, true, true,
                              "VUID-VkSemaphoreWaitInfo-semaphoreCount-arraylength", "VUID-VkSemaphoreWaitInfo-pValues-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pSignalInfo), "VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO", pSignalInfo,
                               VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO, true, "VUID-vkSignalSemaphore-pSignalInfo-parameter",
                               "VUID-VkSemaphoreSignalInfo-sType-sType");
    if (pSignalInfo != nullptr) {
        [[maybe_unused]] const Location pSignalInfo_loc = loc.dot(Field::pSignalInfo);
        skip |= ValidateStructPnext(pSignalInfo_loc, pSignalInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkSemaphoreSignalInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pSignalInfo_loc.dot(Field::semaphore), pSignalInfo->semaphore);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pInfo), "VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO", pInfo,
                               VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO, true, "VUID-vkGetBufferDeviceAddress-pInfo-parameter",
                               "VUID-VkBufferDeviceAddressInfo-sType-sType");
    if (pInfo != nullptr) {
        [[maybe_unused]] const Location pInfo_loc = loc.dot(Field::pInfo);
        skip |= ValidateStructPnext(pInfo_loc, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkBufferDeviceAddressInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pInfo_loc.dot(Field::buffer), pInfo->buffer);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo,
                                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(
        loc.dot(Field::pInfo), "VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO", pInfo, VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO,
        true, "VUID-vkGetBufferOpaqueCaptureAddress-pInfo-parameter", "VUID-VkBufferDeviceAddressInfo-sType-sType");
    if (pInfo != nullptr) {
        [[maybe_unused]] const Location pInfo_loc = loc.dot(Field::pInfo);
        skip |= ValidateStructPnext(pInfo_loc, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkBufferDeviceAddressInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pInfo_loc.dot(Field::buffer), pInfo->buffer);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceMemoryOpaqueCaptureAddress(VkDevice device,
                                                                             const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo,
                                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pInfo), "VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO", pInfo,
                               VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO, true,
                               "VUID-vkGetDeviceMemoryOpaqueCaptureAddress-pInfo-parameter",
                               "VUID-VkDeviceMemoryOpaqueCaptureAddressInfo-sType-sType");
    if (pInfo != nullptr) {
        [[maybe_unused]] const Location pInfo_loc = loc.dot(Field::pInfo);
        skip |= ValidateStructPnext(pInfo_loc, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDeviceMemoryOpaqueCaptureAddressInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pInfo_loc.dot(Field::memory), pInfo->memory);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount,
                                                                         VkPhysicalDeviceToolProperties* pToolProperties,
                                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (loc.function == vvl::Func::vkGetPhysicalDeviceToolProperties &&
        CheckPromotedApiAgainstVulkanVersion(physicalDevice, loc, VK_API_VERSION_1_3))
        return true;
    skip |= ValidateStructTypeArray(loc.dot(Field::pToolCount), loc.dot(Field::pToolProperties),
                                    "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES", pToolCount, pToolProperties,
                                    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES, true, false, false, kVUIDUndefined,
                                    kVUIDUndefined, kVUIDUndefined);
    if (pToolProperties != nullptr) {
        for (uint32_t pToolIndex = 0; pToolIndex < *pToolCount; ++pToolIndex) {
            [[maybe_unused]] const Location pToolProperties_loc = loc.dot(Field::pToolProperties, pToolIndex);
            skip |= ValidateStructPnext(pToolProperties_loc, pToolProperties[pToolIndex].pNext, 0, nullptr,
                                        GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               VkPrivateDataSlot* pPrivateDataSlot,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO", pCreateInfo,
                               VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO, true, kVUIDUndefined, kVUIDUndefined);
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined,
                                    kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags, kVUIDUndefined);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreatePrivateDataSlot-pAllocator-null",
                         "vkCreatePrivateDataSlot(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pPrivateDataSlot), pPrivateDataSlot, kVUIDUndefined);
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot,
                                                                const VkAllocationCallbacks* pAllocator,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyPrivateDataSlot-pAllocator-null",
                         "vkDestroyPrivateDataSlot(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateSetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle,
                                                        VkPrivateDataSlot privateDataSlot, uint64_t data,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRangedEnum(loc.dot(Field::objectType), "VkObjectType", objectType, kVUIDUndefined);
    skip |= ValidateRequiredHandle(loc.dot(Field::privateDataSlot), privateDataSlot);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle,
                                                        VkPrivateDataSlot privateDataSlot, uint64_t* pData,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRangedEnum(loc.dot(Field::objectType), "VkObjectType", objectType, kVUIDUndefined);
    skip |= ValidateRequiredHandle(loc.dot(Field::privateDataSlot), privateDataSlot);
    skip |= ValidateRequiredPointer(loc.dot(Field::pData), pData, kVUIDUndefined);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                                      const VkDependencyInfo* pDependencyInfo, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::event), event);
    skip |= ValidateStructType(loc.dot(Field::pDependencyInfo), "VK_STRUCTURE_TYPE_DEPENDENCY_INFO", pDependencyInfo,
                               VK_STRUCTURE_TYPE_DEPENDENCY_INFO, true, "VUID-vkCmdSetEvent2-pDependencyInfo-parameter",
                               "VUID-VkDependencyInfo-sType-sType");
    if (pDependencyInfo != nullptr) {
        [[maybe_unused]] const Location pDependencyInfo_loc = loc.dot(Field::pDependencyInfo);
        skip |= ValidateStructPnext(pDependencyInfo_loc, pDependencyInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDependencyInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags(pDependencyInfo_loc.dot(Field::dependencyFlags), "VkDependencyFlagBits", AllVkDependencyFlagBits,
                              pDependencyInfo->dependencyFlags, kOptionalFlags, "VUID-VkDependencyInfo-dependencyFlags-parameter");

        skip |= ValidateStructTypeArray(pDependencyInfo_loc.dot(Field::memoryBarrierCount),
                                        pDependencyInfo_loc.dot(Field::pMemoryBarriers), "VK_STRUCTURE_TYPE_MEMORY_BARRIER_2",
                                        pDependencyInfo->memoryBarrierCount, pDependencyInfo->pMemoryBarriers,
                                        VK_STRUCTURE_TYPE_MEMORY_BARRIER_2, false, true, "VUID-VkMemoryBarrier2-sType-sType",
                                        "VUID-VkDependencyInfo-pMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pMemoryBarriers != nullptr) {
            for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < pDependencyInfo->memoryBarrierCount; ++memoryBarrierIndex) {
                [[maybe_unused]] const Location pMemoryBarriers_loc =
                    pDependencyInfo_loc.dot(Field::pMemoryBarriers, memoryBarrierIndex);
                skip |= ValidateStructPnext(pMemoryBarriers_loc, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].pNext, 0,
                                            nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                skip |=
                    ValidateFlags(pMemoryBarriers_loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits2",
                                  AllVkPipelineStageFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].srcStageMask,
                                  kOptionalFlags, "VUID-VkMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags(pMemoryBarriers_loc.dot(Field::srcAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                      pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].srcAccessMask, kOptionalFlags,
                                      "VUID-VkMemoryBarrier2-srcAccessMask-parameter");

                skip |=
                    ValidateFlags(pMemoryBarriers_loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits2",
                                  AllVkPipelineStageFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].dstStageMask,
                                  kOptionalFlags, "VUID-VkMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags(pMemoryBarriers_loc.dot(Field::dstAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                      pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].dstAccessMask, kOptionalFlags,
                                      "VUID-VkMemoryBarrier2-dstAccessMask-parameter");
            }
        }

        skip |= ValidateStructTypeArray(
            pDependencyInfo_loc.dot(Field::bufferMemoryBarrierCount), pDependencyInfo_loc.dot(Field::pBufferMemoryBarriers),
            "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2", pDependencyInfo->bufferMemoryBarrierCount,
            pDependencyInfo->pBufferMemoryBarriers, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2, false, true,
            "VUID-VkBufferMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pBufferMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pBufferMemoryBarriers != nullptr) {
            for (uint32_t bufferMemoryBarrierIndex = 0; bufferMemoryBarrierIndex < pDependencyInfo->bufferMemoryBarrierCount;
                 ++bufferMemoryBarrierIndex) {
                [[maybe_unused]] const Location pBufferMemoryBarriers_loc =
                    pDependencyInfo_loc.dot(Field::pBufferMemoryBarriers, bufferMemoryBarrierIndex);
                skip |= ValidateStructPnext(
                    pBufferMemoryBarriers_loc, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext, 0, nullptr,
                    GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags(pBufferMemoryBarriers_loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits2",
                                      AllVkPipelineStageFlagBits2,
                                      pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcStageMask, kOptionalFlags,
                                      "VUID-VkBufferMemoryBarrier2-srcStageMask-parameter");

                skip |=
                    ValidateFlags(pBufferMemoryBarriers_loc.dot(Field::srcAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                  pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcAccessMask, kOptionalFlags,
                                  "VUID-VkBufferMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags(pBufferMemoryBarriers_loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits2",
                                      AllVkPipelineStageFlagBits2,
                                      pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstStageMask, kOptionalFlags,
                                      "VUID-VkBufferMemoryBarrier2-dstStageMask-parameter");

                skip |=
                    ValidateFlags(pBufferMemoryBarriers_loc.dot(Field::dstAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                  pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstAccessMask, kOptionalFlags,
                                  "VUID-VkBufferMemoryBarrier2-dstAccessMask-parameter");

                skip |= ValidateRequiredHandle(pBufferMemoryBarriers_loc.dot(Field::buffer),
                                               pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
            }
        }

        skip |= ValidateStructTypeArray(
            pDependencyInfo_loc.dot(Field::imageMemoryBarrierCount), pDependencyInfo_loc.dot(Field::pImageMemoryBarriers),
            "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2", pDependencyInfo->imageMemoryBarrierCount,
            pDependencyInfo->pImageMemoryBarriers, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2, false, true,
            "VUID-VkImageMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pImageMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pImageMemoryBarriers != nullptr) {
            for (uint32_t imageMemoryBarrierIndex = 0; imageMemoryBarrierIndex < pDependencyInfo->imageMemoryBarrierCount;
                 ++imageMemoryBarrierIndex) {
                [[maybe_unused]] const Location pImageMemoryBarriers_loc =
                    pDependencyInfo_loc.dot(Field::pImageMemoryBarriers, imageMemoryBarrierIndex);
                constexpr std::array allowed_structs_VkImageMemoryBarrier2 = {VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT};

                skip |= ValidateStructPnext(
                    pImageMemoryBarriers_loc, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].pNext,
                    allowed_structs_VkImageMemoryBarrier2.size(), allowed_structs_VkImageMemoryBarrier2.data(),
                    GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier2-pNext-pNext",
                    "VUID-VkImageMemoryBarrier2-sType-unique", false, true);

                skip |= ValidateFlags(pImageMemoryBarriers_loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits2",
                                      AllVkPipelineStageFlagBits2,
                                      pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].srcStageMask, kOptionalFlags,
                                      "VUID-VkImageMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags(pImageMemoryBarriers_loc.dot(Field::srcAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                      pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].srcAccessMask, kOptionalFlags,
                                      "VUID-VkImageMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags(pImageMemoryBarriers_loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits2",
                                      AllVkPipelineStageFlagBits2,
                                      pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].dstStageMask, kOptionalFlags,
                                      "VUID-VkImageMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags(pImageMemoryBarriers_loc.dot(Field::dstAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                      pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].dstAccessMask, kOptionalFlags,
                                      "VUID-VkImageMemoryBarrier2-dstAccessMask-parameter");

                skip |= ValidateRangedEnum(pImageMemoryBarriers_loc.dot(Field::oldLayout), "VkImageLayout",
                                           pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout,
                                           "VUID-VkImageMemoryBarrier2-oldLayout-parameter");

                skip |= ValidateRangedEnum(pImageMemoryBarriers_loc.dot(Field::newLayout), "VkImageLayout",
                                           pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout,
                                           "VUID-VkImageMemoryBarrier2-newLayout-parameter");

                skip |= ValidateRequiredHandle(pImageMemoryBarriers_loc.dot(Field::image),
                                               pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].image);

                skip |= ValidateFlags(
                    pImageMemoryBarriers_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                    pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask, kRequiredFlags,
                    "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                                        VkPipelineStageFlags2 stageMask, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::event), event);
    skip |= ValidateFlags(loc.dot(Field::stageMask), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, stageMask,
                          kOptionalFlags, "VUID-vkCmdResetEvent2-stageMask-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                                        const VkDependencyInfo* pDependencyInfos,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateHandleArray(loc.dot(Field::eventCount), loc.dot(Field::pEvents), eventCount, pEvents, true, true,
                                "VUID-vkCmdWaitEvents2-eventCount-arraylength");
    skip |= ValidateStructTypeArray(
        loc.dot(Field::eventCount), loc.dot(Field::pDependencyInfos), "VK_STRUCTURE_TYPE_DEPENDENCY_INFO", eventCount,
        pDependencyInfos, VK_STRUCTURE_TYPE_DEPENDENCY_INFO, true, true, "VUID-VkDependencyInfo-sType-sType",
        "VUID-vkCmdWaitEvents2-pDependencyInfos-parameter", "VUID-vkCmdWaitEvents2-eventCount-arraylength");
    if (pDependencyInfos != nullptr) {
        for (uint32_t eventIndex = 0; eventIndex < eventCount; ++eventIndex) {
            [[maybe_unused]] const Location pDependencyInfos_loc = loc.dot(Field::pDependencyInfos, eventIndex);
            skip |=
                ValidateStructPnext(pDependencyInfos_loc, pDependencyInfos[eventIndex].pNext, 0, nullptr,
                                    GeneratedVulkanHeaderVersion, "VUID-VkDependencyInfo-pNext-pNext", kVUIDUndefined, false, true);

            skip |= ValidateFlags(pDependencyInfos_loc.dot(Field::dependencyFlags), "VkDependencyFlagBits", AllVkDependencyFlagBits,
                                  pDependencyInfos[eventIndex].dependencyFlags, kOptionalFlags,
                                  "VUID-VkDependencyInfo-dependencyFlags-parameter");

            skip |= ValidateStructTypeArray(
                pDependencyInfos_loc.dot(Field::memoryBarrierCount), pDependencyInfos_loc.dot(Field::pMemoryBarriers),
                "VK_STRUCTURE_TYPE_MEMORY_BARRIER_2", pDependencyInfos[eventIndex].memoryBarrierCount,
                pDependencyInfos[eventIndex].pMemoryBarriers, VK_STRUCTURE_TYPE_MEMORY_BARRIER_2, false, true,
                "VUID-VkMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pMemoryBarriers-parameter", kVUIDUndefined);

            if (pDependencyInfos[eventIndex].pMemoryBarriers != nullptr) {
                for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < pDependencyInfos[eventIndex].memoryBarrierCount;
                     ++memoryBarrierIndex) {
                    [[maybe_unused]] const Location pMemoryBarriers_loc =
                        pDependencyInfos_loc.dot(Field::pMemoryBarriers, memoryBarrierIndex);
                    skip |= ValidateStructPnext(pMemoryBarriers_loc,
                                                pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].pNext, 0, nullptr,
                                                GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                    skip |= ValidateFlags(pMemoryBarriers_loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits2",
                                          AllVkPipelineStageFlagBits2,
                                          pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].srcStageMask,
                                          kOptionalFlags, "VUID-VkMemoryBarrier2-srcStageMask-parameter");

                    skip |= ValidateFlags(pMemoryBarriers_loc.dot(Field::srcAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                          pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].srcAccessMask,
                                          kOptionalFlags, "VUID-VkMemoryBarrier2-srcAccessMask-parameter");

                    skip |= ValidateFlags(pMemoryBarriers_loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits2",
                                          AllVkPipelineStageFlagBits2,
                                          pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].dstStageMask,
                                          kOptionalFlags, "VUID-VkMemoryBarrier2-dstStageMask-parameter");

                    skip |= ValidateFlags(pMemoryBarriers_loc.dot(Field::dstAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                          pDependencyInfos[eventIndex].pMemoryBarriers[memoryBarrierIndex].dstAccessMask,
                                          kOptionalFlags, "VUID-VkMemoryBarrier2-dstAccessMask-parameter");
                }
            }

            skip |= ValidateStructTypeArray(
                pDependencyInfos_loc.dot(Field::bufferMemoryBarrierCount), pDependencyInfos_loc.dot(Field::pBufferMemoryBarriers),
                "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2", pDependencyInfos[eventIndex].bufferMemoryBarrierCount,
                pDependencyInfos[eventIndex].pBufferMemoryBarriers, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2, false, true,
                "VUID-VkBufferMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pBufferMemoryBarriers-parameter", kVUIDUndefined);

            if (pDependencyInfos[eventIndex].pBufferMemoryBarriers != nullptr) {
                for (uint32_t bufferMemoryBarrierIndex = 0;
                     bufferMemoryBarrierIndex < pDependencyInfos[eventIndex].bufferMemoryBarrierCount; ++bufferMemoryBarrierIndex) {
                    [[maybe_unused]] const Location pBufferMemoryBarriers_loc =
                        pDependencyInfos_loc.dot(Field::pBufferMemoryBarriers, bufferMemoryBarrierIndex);
                    skip |= ValidateStructPnext(pBufferMemoryBarriers_loc,
                                                pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext,
                                                0, nullptr, GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier2-pNext-pNext",
                                                kVUIDUndefined, false, true);

                    skip |= ValidateFlags(pBufferMemoryBarriers_loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits2",
                                          AllVkPipelineStageFlagBits2,
                                          pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcStageMask,
                                          kOptionalFlags, "VUID-VkBufferMemoryBarrier2-srcStageMask-parameter");

                    skip |= ValidateFlags(
                        pBufferMemoryBarriers_loc.dot(Field::srcAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                        pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcAccessMask, kOptionalFlags,
                        "VUID-VkBufferMemoryBarrier2-srcAccessMask-parameter");

                    skip |= ValidateFlags(pBufferMemoryBarriers_loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits2",
                                          AllVkPipelineStageFlagBits2,
                                          pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstStageMask,
                                          kOptionalFlags, "VUID-VkBufferMemoryBarrier2-dstStageMask-parameter");

                    skip |= ValidateFlags(
                        pBufferMemoryBarriers_loc.dot(Field::dstAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                        pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstAccessMask, kOptionalFlags,
                        "VUID-VkBufferMemoryBarrier2-dstAccessMask-parameter");

                    skip |=
                        ValidateRequiredHandle(pBufferMemoryBarriers_loc.dot(Field::buffer),
                                               pDependencyInfos[eventIndex].pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
                }
            }

            skip |= ValidateStructTypeArray(
                pDependencyInfos_loc.dot(Field::imageMemoryBarrierCount), pDependencyInfos_loc.dot(Field::pImageMemoryBarriers),
                "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2", pDependencyInfos[eventIndex].imageMemoryBarrierCount,
                pDependencyInfos[eventIndex].pImageMemoryBarriers, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2, false, true,
                "VUID-VkImageMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pImageMemoryBarriers-parameter", kVUIDUndefined);

            if (pDependencyInfos[eventIndex].pImageMemoryBarriers != nullptr) {
                for (uint32_t imageMemoryBarrierIndex = 0;
                     imageMemoryBarrierIndex < pDependencyInfos[eventIndex].imageMemoryBarrierCount; ++imageMemoryBarrierIndex) {
                    [[maybe_unused]] const Location pImageMemoryBarriers_loc =
                        pDependencyInfos_loc.dot(Field::pImageMemoryBarriers, imageMemoryBarrierIndex);
                    constexpr std::array allowed_structs_VkImageMemoryBarrier2 = {VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT};

                    skip |= ValidateStructPnext(
                        pImageMemoryBarriers_loc, pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].pNext,
                        allowed_structs_VkImageMemoryBarrier2.size(), allowed_structs_VkImageMemoryBarrier2.data(),
                        GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier2-pNext-pNext",
                        "VUID-VkImageMemoryBarrier2-sType-unique", false, true);

                    skip |= ValidateFlags(pImageMemoryBarriers_loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits2",
                                          AllVkPipelineStageFlagBits2,
                                          pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].srcStageMask,
                                          kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcStageMask-parameter");

                    skip |=
                        ValidateFlags(pImageMemoryBarriers_loc.dot(Field::srcAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                      pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].srcAccessMask,
                                      kOptionalFlags, "VUID-VkImageMemoryBarrier2-srcAccessMask-parameter");

                    skip |= ValidateFlags(pImageMemoryBarriers_loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits2",
                                          AllVkPipelineStageFlagBits2,
                                          pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].dstStageMask,
                                          kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstStageMask-parameter");

                    skip |=
                        ValidateFlags(pImageMemoryBarriers_loc.dot(Field::dstAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                      pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].dstAccessMask,
                                      kOptionalFlags, "VUID-VkImageMemoryBarrier2-dstAccessMask-parameter");

                    skip |= ValidateRangedEnum(pImageMemoryBarriers_loc.dot(Field::oldLayout), "VkImageLayout",
                                               pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout,
                                               "VUID-VkImageMemoryBarrier2-oldLayout-parameter");

                    skip |= ValidateRangedEnum(pImageMemoryBarriers_loc.dot(Field::newLayout), "VkImageLayout",
                                               pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout,
                                               "VUID-VkImageMemoryBarrier2-newLayout-parameter");

                    skip |=
                        ValidateRequiredHandle(pImageMemoryBarriers_loc.dot(Field::image),
                                               pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].image);

                    skip |= ValidateFlags(
                        pImageMemoryBarriers_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                        pDependencyInfos[eventIndex].pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask,
                        kRequiredFlags, "VUID-VkImageSubresourceRange-aspectMask-parameter",
                        "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
                }
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo,
                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pDependencyInfo), "VK_STRUCTURE_TYPE_DEPENDENCY_INFO", pDependencyInfo,
                               VK_STRUCTURE_TYPE_DEPENDENCY_INFO, true, "VUID-vkCmdPipelineBarrier2-pDependencyInfo-parameter",
                               "VUID-VkDependencyInfo-sType-sType");
    if (pDependencyInfo != nullptr) {
        [[maybe_unused]] const Location pDependencyInfo_loc = loc.dot(Field::pDependencyInfo);
        skip |= ValidateStructPnext(pDependencyInfo_loc, pDependencyInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDependencyInfo-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateFlags(pDependencyInfo_loc.dot(Field::dependencyFlags), "VkDependencyFlagBits", AllVkDependencyFlagBits,
                              pDependencyInfo->dependencyFlags, kOptionalFlags, "VUID-VkDependencyInfo-dependencyFlags-parameter");

        skip |= ValidateStructTypeArray(pDependencyInfo_loc.dot(Field::memoryBarrierCount),
                                        pDependencyInfo_loc.dot(Field::pMemoryBarriers), "VK_STRUCTURE_TYPE_MEMORY_BARRIER_2",
                                        pDependencyInfo->memoryBarrierCount, pDependencyInfo->pMemoryBarriers,
                                        VK_STRUCTURE_TYPE_MEMORY_BARRIER_2, false, true, "VUID-VkMemoryBarrier2-sType-sType",
                                        "VUID-VkDependencyInfo-pMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pMemoryBarriers != nullptr) {
            for (uint32_t memoryBarrierIndex = 0; memoryBarrierIndex < pDependencyInfo->memoryBarrierCount; ++memoryBarrierIndex) {
                [[maybe_unused]] const Location pMemoryBarriers_loc =
                    pDependencyInfo_loc.dot(Field::pMemoryBarriers, memoryBarrierIndex);
                skip |= ValidateStructPnext(pMemoryBarriers_loc, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].pNext, 0,
                                            nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                skip |=
                    ValidateFlags(pMemoryBarriers_loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits2",
                                  AllVkPipelineStageFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].srcStageMask,
                                  kOptionalFlags, "VUID-VkMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags(pMemoryBarriers_loc.dot(Field::srcAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                      pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].srcAccessMask, kOptionalFlags,
                                      "VUID-VkMemoryBarrier2-srcAccessMask-parameter");

                skip |=
                    ValidateFlags(pMemoryBarriers_loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits2",
                                  AllVkPipelineStageFlagBits2, pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].dstStageMask,
                                  kOptionalFlags, "VUID-VkMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags(pMemoryBarriers_loc.dot(Field::dstAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                      pDependencyInfo->pMemoryBarriers[memoryBarrierIndex].dstAccessMask, kOptionalFlags,
                                      "VUID-VkMemoryBarrier2-dstAccessMask-parameter");
            }
        }

        skip |= ValidateStructTypeArray(
            pDependencyInfo_loc.dot(Field::bufferMemoryBarrierCount), pDependencyInfo_loc.dot(Field::pBufferMemoryBarriers),
            "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2", pDependencyInfo->bufferMemoryBarrierCount,
            pDependencyInfo->pBufferMemoryBarriers, VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2, false, true,
            "VUID-VkBufferMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pBufferMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pBufferMemoryBarriers != nullptr) {
            for (uint32_t bufferMemoryBarrierIndex = 0; bufferMemoryBarrierIndex < pDependencyInfo->bufferMemoryBarrierCount;
                 ++bufferMemoryBarrierIndex) {
                [[maybe_unused]] const Location pBufferMemoryBarriers_loc =
                    pDependencyInfo_loc.dot(Field::pBufferMemoryBarriers, bufferMemoryBarrierIndex);
                skip |= ValidateStructPnext(
                    pBufferMemoryBarriers_loc, pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].pNext, 0, nullptr,
                    GeneratedVulkanHeaderVersion, "VUID-VkBufferMemoryBarrier2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags(pBufferMemoryBarriers_loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits2",
                                      AllVkPipelineStageFlagBits2,
                                      pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcStageMask, kOptionalFlags,
                                      "VUID-VkBufferMemoryBarrier2-srcStageMask-parameter");

                skip |=
                    ValidateFlags(pBufferMemoryBarriers_loc.dot(Field::srcAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                  pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].srcAccessMask, kOptionalFlags,
                                  "VUID-VkBufferMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags(pBufferMemoryBarriers_loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits2",
                                      AllVkPipelineStageFlagBits2,
                                      pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstStageMask, kOptionalFlags,
                                      "VUID-VkBufferMemoryBarrier2-dstStageMask-parameter");

                skip |=
                    ValidateFlags(pBufferMemoryBarriers_loc.dot(Field::dstAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                  pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].dstAccessMask, kOptionalFlags,
                                  "VUID-VkBufferMemoryBarrier2-dstAccessMask-parameter");

                skip |= ValidateRequiredHandle(pBufferMemoryBarriers_loc.dot(Field::buffer),
                                               pDependencyInfo->pBufferMemoryBarriers[bufferMemoryBarrierIndex].buffer);
            }
        }

        skip |= ValidateStructTypeArray(
            pDependencyInfo_loc.dot(Field::imageMemoryBarrierCount), pDependencyInfo_loc.dot(Field::pImageMemoryBarriers),
            "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2", pDependencyInfo->imageMemoryBarrierCount,
            pDependencyInfo->pImageMemoryBarriers, VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2, false, true,
            "VUID-VkImageMemoryBarrier2-sType-sType", "VUID-VkDependencyInfo-pImageMemoryBarriers-parameter", kVUIDUndefined);

        if (pDependencyInfo->pImageMemoryBarriers != nullptr) {
            for (uint32_t imageMemoryBarrierIndex = 0; imageMemoryBarrierIndex < pDependencyInfo->imageMemoryBarrierCount;
                 ++imageMemoryBarrierIndex) {
                [[maybe_unused]] const Location pImageMemoryBarriers_loc =
                    pDependencyInfo_loc.dot(Field::pImageMemoryBarriers, imageMemoryBarrierIndex);
                constexpr std::array allowed_structs_VkImageMemoryBarrier2 = {VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT};

                skip |= ValidateStructPnext(
                    pImageMemoryBarriers_loc, pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].pNext,
                    allowed_structs_VkImageMemoryBarrier2.size(), allowed_structs_VkImageMemoryBarrier2.data(),
                    GeneratedVulkanHeaderVersion, "VUID-VkImageMemoryBarrier2-pNext-pNext",
                    "VUID-VkImageMemoryBarrier2-sType-unique", false, true);

                skip |= ValidateFlags(pImageMemoryBarriers_loc.dot(Field::srcStageMask), "VkPipelineStageFlagBits2",
                                      AllVkPipelineStageFlagBits2,
                                      pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].srcStageMask, kOptionalFlags,
                                      "VUID-VkImageMemoryBarrier2-srcStageMask-parameter");

                skip |= ValidateFlags(pImageMemoryBarriers_loc.dot(Field::srcAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                      pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].srcAccessMask, kOptionalFlags,
                                      "VUID-VkImageMemoryBarrier2-srcAccessMask-parameter");

                skip |= ValidateFlags(pImageMemoryBarriers_loc.dot(Field::dstStageMask), "VkPipelineStageFlagBits2",
                                      AllVkPipelineStageFlagBits2,
                                      pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].dstStageMask, kOptionalFlags,
                                      "VUID-VkImageMemoryBarrier2-dstStageMask-parameter");

                skip |= ValidateFlags(pImageMemoryBarriers_loc.dot(Field::dstAccessMask), "VkAccessFlagBits2", AllVkAccessFlagBits2,
                                      pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].dstAccessMask, kOptionalFlags,
                                      "VUID-VkImageMemoryBarrier2-dstAccessMask-parameter");

                skip |= ValidateRangedEnum(pImageMemoryBarriers_loc.dot(Field::oldLayout), "VkImageLayout",
                                           pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].oldLayout,
                                           "VUID-VkImageMemoryBarrier2-oldLayout-parameter");

                skip |= ValidateRangedEnum(pImageMemoryBarriers_loc.dot(Field::newLayout), "VkImageLayout",
                                           pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].newLayout,
                                           "VUID-VkImageMemoryBarrier2-newLayout-parameter");

                skip |= ValidateRequiredHandle(pImageMemoryBarriers_loc.dot(Field::image),
                                               pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].image);

                skip |= ValidateFlags(
                    pImageMemoryBarriers_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                    pDependencyInfo->pImageMemoryBarriers[imageMemoryBarrierIndex].subresourceRange.aspectMask, kRequiredFlags,
                    "VUID-VkImageSubresourceRange-aspectMask-parameter", "VUID-VkImageSubresourceRange-aspectMask-requiredbitmask");
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                            VkQueryPool queryPool, uint32_t query,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateFlags(loc.dot(Field::stage), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, stage, kOptionalFlags,
                          "VUID-vkCmdWriteTimestamp2-stage-parameter");
    skip |= ValidateRequiredHandle(loc.dot(Field::queryPool), queryPool);
    return skip;
}

bool StatelessValidation::PreCallValidateQueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits,
                                                      VkFence fence, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructTypeArray(loc.dot(Field::submitCount), loc.dot(Field::pSubmits), "VK_STRUCTURE_TYPE_SUBMIT_INFO_2",
                                    submitCount, pSubmits, VK_STRUCTURE_TYPE_SUBMIT_INFO_2, false, true,
                                    "VUID-VkSubmitInfo2-sType-sType", "VUID-vkQueueSubmit2-pSubmits-parameter", kVUIDUndefined);
    if (pSubmits != nullptr) {
        for (uint32_t submitIndex = 0; submitIndex < submitCount; ++submitIndex) {
            [[maybe_unused]] const Location pSubmits_loc = loc.dot(Field::pSubmits, submitIndex);
            constexpr std::array allowed_structs_VkSubmitInfo2 = {VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR};

            skip |= ValidateStructPnext(pSubmits_loc, pSubmits[submitIndex].pNext, allowed_structs_VkSubmitInfo2.size(),
                                        allowed_structs_VkSubmitInfo2.data(), GeneratedVulkanHeaderVersion,
                                        "VUID-VkSubmitInfo2-pNext-pNext", "VUID-VkSubmitInfo2-sType-unique", false, true);

            skip |= ValidateFlags(pSubmits_loc.dot(Field::flags), "VkSubmitFlagBits", AllVkSubmitFlagBits,
                                  pSubmits[submitIndex].flags, kOptionalFlags, "VUID-VkSubmitInfo2-flags-parameter");

            skip |= ValidateStructTypeArray(
                pSubmits_loc.dot(Field::waitSemaphoreInfoCount), pSubmits_loc.dot(Field::pWaitSemaphoreInfos),
                "VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO", pSubmits[submitIndex].waitSemaphoreInfoCount,
                pSubmits[submitIndex].pWaitSemaphoreInfos, VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO, false, true,
                "VUID-VkSemaphoreSubmitInfo-sType-sType", "VUID-VkSubmitInfo2-pWaitSemaphoreInfos-parameter", kVUIDUndefined);

            if (pSubmits[submitIndex].pWaitSemaphoreInfos != nullptr) {
                for (uint32_t waitSemaphoreInfoIndex = 0; waitSemaphoreInfoIndex < pSubmits[submitIndex].waitSemaphoreInfoCount;
                     ++waitSemaphoreInfoIndex) {
                    [[maybe_unused]] const Location pWaitSemaphoreInfos_loc =
                        pSubmits_loc.dot(Field::pWaitSemaphoreInfos, waitSemaphoreInfoIndex);
                    skip |= ValidateStructPnext(pWaitSemaphoreInfos_loc,
                                                pSubmits[submitIndex].pWaitSemaphoreInfos[waitSemaphoreInfoIndex].pNext, 0, nullptr,
                                                GeneratedVulkanHeaderVersion, "VUID-VkSemaphoreSubmitInfo-pNext-pNext",
                                                kVUIDUndefined, false, true);

                    skip |= ValidateRequiredHandle(pWaitSemaphoreInfos_loc.dot(Field::semaphore),
                                                   pSubmits[submitIndex].pWaitSemaphoreInfos[waitSemaphoreInfoIndex].semaphore);

                    skip |= ValidateFlags(pWaitSemaphoreInfos_loc.dot(Field::stageMask), "VkPipelineStageFlagBits2",
                                          AllVkPipelineStageFlagBits2,
                                          pSubmits[submitIndex].pWaitSemaphoreInfos[waitSemaphoreInfoIndex].stageMask,
                                          kOptionalFlags, "VUID-VkSemaphoreSubmitInfo-stageMask-parameter");
                }
            }

            skip |= ValidateStructTypeArray(
                pSubmits_loc.dot(Field::commandBufferInfoCount), pSubmits_loc.dot(Field::pCommandBufferInfos),
                "VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO", pSubmits[submitIndex].commandBufferInfoCount,
                pSubmits[submitIndex].pCommandBufferInfos, VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO, false, true,
                "VUID-VkCommandBufferSubmitInfo-sType-sType", "VUID-VkSubmitInfo2-pCommandBufferInfos-parameter", kVUIDUndefined);

            if (pSubmits[submitIndex].pCommandBufferInfos != nullptr) {
                for (uint32_t commandBufferInfoIndex = 0; commandBufferInfoIndex < pSubmits[submitIndex].commandBufferInfoCount;
                     ++commandBufferInfoIndex) {
                    [[maybe_unused]] const Location pCommandBufferInfos_loc =
                        pSubmits_loc.dot(Field::pCommandBufferInfos, commandBufferInfoIndex);
                    skip |= ValidateStructPnext(pCommandBufferInfos_loc,
                                                pSubmits[submitIndex].pCommandBufferInfos[commandBufferInfoIndex].pNext, 0, nullptr,
                                                GeneratedVulkanHeaderVersion, "VUID-VkCommandBufferSubmitInfo-pNext-pNext",
                                                kVUIDUndefined, false, true);

                    skip |= ValidateRequiredHandle(pCommandBufferInfos_loc.dot(Field::commandBuffer),
                                                   pSubmits[submitIndex].pCommandBufferInfos[commandBufferInfoIndex].commandBuffer);
                }
            }

            skip |= ValidateStructTypeArray(
                pSubmits_loc.dot(Field::signalSemaphoreInfoCount), pSubmits_loc.dot(Field::pSignalSemaphoreInfos),
                "VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO", pSubmits[submitIndex].signalSemaphoreInfoCount,
                pSubmits[submitIndex].pSignalSemaphoreInfos, VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO, false, true,
                "VUID-VkSemaphoreSubmitInfo-sType-sType", "VUID-VkSubmitInfo2-pSignalSemaphoreInfos-parameter", kVUIDUndefined);

            if (pSubmits[submitIndex].pSignalSemaphoreInfos != nullptr) {
                for (uint32_t signalSemaphoreInfoIndex = 0;
                     signalSemaphoreInfoIndex < pSubmits[submitIndex].signalSemaphoreInfoCount; ++signalSemaphoreInfoIndex) {
                    [[maybe_unused]] const Location pSignalSemaphoreInfos_loc =
                        pSubmits_loc.dot(Field::pSignalSemaphoreInfos, signalSemaphoreInfoIndex);
                    skip |= ValidateStructPnext(pSignalSemaphoreInfos_loc,
                                                pSubmits[submitIndex].pSignalSemaphoreInfos[signalSemaphoreInfoIndex].pNext, 0,
                                                nullptr, GeneratedVulkanHeaderVersion, "VUID-VkSemaphoreSubmitInfo-pNext-pNext",
                                                kVUIDUndefined, false, true);

                    skip |= ValidateRequiredHandle(pSignalSemaphoreInfos_loc.dot(Field::semaphore),
                                                   pSubmits[submitIndex].pSignalSemaphoreInfos[signalSemaphoreInfoIndex].semaphore);

                    skip |= ValidateFlags(pSignalSemaphoreInfos_loc.dot(Field::stageMask), "VkPipelineStageFlagBits2",
                                          AllVkPipelineStageFlagBits2,
                                          pSubmits[submitIndex].pSignalSemaphoreInfos[signalSemaphoreInfoIndex].stageMask,
                                          kOptionalFlags, "VUID-VkSemaphoreSubmitInfo-stageMask-parameter");
                }
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCopyBufferInfo), "VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2", pCopyBufferInfo,
                               VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2, true, "VUID-vkCmdCopyBuffer2-pCopyBufferInfo-parameter",
                               "VUID-VkCopyBufferInfo2-sType-sType");
    if (pCopyBufferInfo != nullptr) {
        [[maybe_unused]] const Location pCopyBufferInfo_loc = loc.dot(Field::pCopyBufferInfo);
        skip |= ValidateStructPnext(pCopyBufferInfo_loc, pCopyBufferInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkCopyBufferInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pCopyBufferInfo_loc.dot(Field::srcBuffer), pCopyBufferInfo->srcBuffer);

        skip |= ValidateRequiredHandle(pCopyBufferInfo_loc.dot(Field::dstBuffer), pCopyBufferInfo->dstBuffer);

        skip |=
            ValidateStructTypeArray(pCopyBufferInfo_loc.dot(Field::regionCount), pCopyBufferInfo_loc.dot(Field::pRegions),
                                    "VK_STRUCTURE_TYPE_BUFFER_COPY_2", pCopyBufferInfo->regionCount, pCopyBufferInfo->pRegions,
                                    VK_STRUCTURE_TYPE_BUFFER_COPY_2, true, true, "VUID-VkBufferCopy2-sType-sType",
                                    "VUID-VkCopyBufferInfo2-pRegions-parameter", "VUID-VkCopyBufferInfo2-regionCount-arraylength");

        if (pCopyBufferInfo->pRegions != nullptr) {
            for (uint32_t regionIndex = 0; regionIndex < pCopyBufferInfo->regionCount; ++regionIndex) {
                [[maybe_unused]] const Location pRegions_loc = pCopyBufferInfo_loc.dot(Field::pRegions, regionIndex);
                skip |= ValidateStructPnext(pRegions_loc, pCopyBufferInfo->pRegions[regionIndex].pNext, 0, nullptr,
                                            GeneratedVulkanHeaderVersion, "VUID-VkBufferCopy2-pNext-pNext", kVUIDUndefined, false,
                                            true);
            }
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdCopyBuffer2(commandBuffer, pCopyBufferInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCopyImageInfo), "VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2", pCopyImageInfo,
                               VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2, true, "VUID-vkCmdCopyImage2-pCopyImageInfo-parameter",
                               "VUID-VkCopyImageInfo2-sType-sType");
    if (pCopyImageInfo != nullptr) {
        [[maybe_unused]] const Location pCopyImageInfo_loc = loc.dot(Field::pCopyImageInfo);
        skip |= ValidateStructPnext(pCopyImageInfo_loc, pCopyImageInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkCopyImageInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pCopyImageInfo_loc.dot(Field::srcImage), pCopyImageInfo->srcImage);

        skip |= ValidateRangedEnum(pCopyImageInfo_loc.dot(Field::srcImageLayout), "VkImageLayout", pCopyImageInfo->srcImageLayout,
                                   "VUID-VkCopyImageInfo2-srcImageLayout-parameter");

        skip |= ValidateRequiredHandle(pCopyImageInfo_loc.dot(Field::dstImage), pCopyImageInfo->dstImage);

        skip |= ValidateRangedEnum(pCopyImageInfo_loc.dot(Field::dstImageLayout), "VkImageLayout", pCopyImageInfo->dstImageLayout,
                                   "VUID-VkCopyImageInfo2-dstImageLayout-parameter");

        skip |=
            ValidateStructTypeArray(pCopyImageInfo_loc.dot(Field::regionCount), pCopyImageInfo_loc.dot(Field::pRegions),
                                    "VK_STRUCTURE_TYPE_IMAGE_COPY_2", pCopyImageInfo->regionCount, pCopyImageInfo->pRegions,
                                    VK_STRUCTURE_TYPE_IMAGE_COPY_2, true, true, "VUID-VkImageCopy2-sType-sType",
                                    "VUID-VkCopyImageInfo2-pRegions-parameter", "VUID-VkCopyImageInfo2-regionCount-arraylength");

        if (pCopyImageInfo->pRegions != nullptr) {
            for (uint32_t regionIndex = 0; regionIndex < pCopyImageInfo->regionCount; ++regionIndex) {
                [[maybe_unused]] const Location pRegions_loc = pCopyImageInfo_loc.dot(Field::pRegions, regionIndex);
                skip |=
                    ValidateStructPnext(pRegions_loc, pCopyImageInfo->pRegions[regionIndex].pNext, 0, nullptr,
                                        GeneratedVulkanHeaderVersion, "VUID-VkImageCopy2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                      pCopyImageInfo->pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags,
                                      "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                      "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                      pCopyImageInfo->pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags,
                                      "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                      "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                                               const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCopyBufferToImageInfo), "VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2",
                               pCopyBufferToImageInfo, VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2, true,
                               "VUID-vkCmdCopyBufferToImage2-pCopyBufferToImageInfo-parameter",
                               "VUID-VkCopyBufferToImageInfo2-sType-sType");
    if (pCopyBufferToImageInfo != nullptr) {
        [[maybe_unused]] const Location pCopyBufferToImageInfo_loc = loc.dot(Field::pCopyBufferToImageInfo);
        skip |=
            ValidateStructPnext(pCopyBufferToImageInfo_loc, pCopyBufferToImageInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                "VUID-VkCopyBufferToImageInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pCopyBufferToImageInfo_loc.dot(Field::srcBuffer), pCopyBufferToImageInfo->srcBuffer);

        skip |= ValidateRequiredHandle(pCopyBufferToImageInfo_loc.dot(Field::dstImage), pCopyBufferToImageInfo->dstImage);

        skip |=
            ValidateRangedEnum(pCopyBufferToImageInfo_loc.dot(Field::dstImageLayout), "VkImageLayout",
                               pCopyBufferToImageInfo->dstImageLayout, "VUID-VkCopyBufferToImageInfo2-dstImageLayout-parameter");

        skip |= ValidateStructTypeArray(
            pCopyBufferToImageInfo_loc.dot(Field::regionCount), pCopyBufferToImageInfo_loc.dot(Field::pRegions),
            "VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2", pCopyBufferToImageInfo->regionCount, pCopyBufferToImageInfo->pRegions,
            VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2, true, true, "VUID-VkBufferImageCopy2-sType-sType",
            "VUID-VkCopyBufferToImageInfo2-pRegions-parameter", "VUID-VkCopyBufferToImageInfo2-regionCount-arraylength");

        if (pCopyBufferToImageInfo->pRegions != nullptr) {
            for (uint32_t regionIndex = 0; regionIndex < pCopyBufferToImageInfo->regionCount; ++regionIndex) {
                [[maybe_unused]] const Location pRegions_loc = pCopyBufferToImageInfo_loc.dot(Field::pRegions, regionIndex);
                skip |= ValidateStructPnext(pRegions_loc, pCopyBufferToImageInfo->pRegions[regionIndex].pNext, 0, nullptr,
                                            GeneratedVulkanHeaderVersion, "VUID-VkBufferImageCopy2-pNext-pNext", kVUIDUndefined,
                                            false, true);

                skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                      pCopyBufferToImageInfo->pRegions[regionIndex].imageSubresource.aspectMask, kRequiredFlags,
                                      "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                      "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                                               const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pCopyImageToBufferInfo), "VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2",
                               pCopyImageToBufferInfo, VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2, true,
                               "VUID-vkCmdCopyImageToBuffer2-pCopyImageToBufferInfo-parameter",
                               "VUID-VkCopyImageToBufferInfo2-sType-sType");
    if (pCopyImageToBufferInfo != nullptr) {
        [[maybe_unused]] const Location pCopyImageToBufferInfo_loc = loc.dot(Field::pCopyImageToBufferInfo);
        skip |=
            ValidateStructPnext(pCopyImageToBufferInfo_loc, pCopyImageToBufferInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                "VUID-VkCopyImageToBufferInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pCopyImageToBufferInfo_loc.dot(Field::srcImage), pCopyImageToBufferInfo->srcImage);

        skip |=
            ValidateRangedEnum(pCopyImageToBufferInfo_loc.dot(Field::srcImageLayout), "VkImageLayout",
                               pCopyImageToBufferInfo->srcImageLayout, "VUID-VkCopyImageToBufferInfo2-srcImageLayout-parameter");

        skip |= ValidateRequiredHandle(pCopyImageToBufferInfo_loc.dot(Field::dstBuffer), pCopyImageToBufferInfo->dstBuffer);

        skip |= ValidateStructTypeArray(
            pCopyImageToBufferInfo_loc.dot(Field::regionCount), pCopyImageToBufferInfo_loc.dot(Field::pRegions),
            "VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2", pCopyImageToBufferInfo->regionCount, pCopyImageToBufferInfo->pRegions,
            VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2, true, true, "VUID-VkBufferImageCopy2-sType-sType",
            "VUID-VkCopyImageToBufferInfo2-pRegions-parameter", "VUID-VkCopyImageToBufferInfo2-regionCount-arraylength");

        if (pCopyImageToBufferInfo->pRegions != nullptr) {
            for (uint32_t regionIndex = 0; regionIndex < pCopyImageToBufferInfo->regionCount; ++regionIndex) {
                [[maybe_unused]] const Location pRegions_loc = pCopyImageToBufferInfo_loc.dot(Field::pRegions, regionIndex);
                skip |= ValidateStructPnext(pRegions_loc, pCopyImageToBufferInfo->pRegions[regionIndex].pNext, 0, nullptr,
                                            GeneratedVulkanHeaderVersion, "VUID-VkBufferImageCopy2-pNext-pNext", kVUIDUndefined,
                                            false, true);

                skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                      pCopyImageToBufferInfo->pRegions[regionIndex].imageSubresource.aspectMask, kRequiredFlags,
                                      "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                      "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pBlitImageInfo), "VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2", pBlitImageInfo,
                               VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2, true, "VUID-vkCmdBlitImage2-pBlitImageInfo-parameter",
                               "VUID-VkBlitImageInfo2-sType-sType");
    if (pBlitImageInfo != nullptr) {
        [[maybe_unused]] const Location pBlitImageInfo_loc = loc.dot(Field::pBlitImageInfo);
        skip |= ValidateStructPnext(pBlitImageInfo_loc, pBlitImageInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkBlitImageInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pBlitImageInfo_loc.dot(Field::srcImage), pBlitImageInfo->srcImage);

        skip |= ValidateRangedEnum(pBlitImageInfo_loc.dot(Field::srcImageLayout), "VkImageLayout", pBlitImageInfo->srcImageLayout,
                                   "VUID-VkBlitImageInfo2-srcImageLayout-parameter");

        skip |= ValidateRequiredHandle(pBlitImageInfo_loc.dot(Field::dstImage), pBlitImageInfo->dstImage);

        skip |= ValidateRangedEnum(pBlitImageInfo_loc.dot(Field::dstImageLayout), "VkImageLayout", pBlitImageInfo->dstImageLayout,
                                   "VUID-VkBlitImageInfo2-dstImageLayout-parameter");

        skip |=
            ValidateStructTypeArray(pBlitImageInfo_loc.dot(Field::regionCount), pBlitImageInfo_loc.dot(Field::pRegions),
                                    "VK_STRUCTURE_TYPE_IMAGE_BLIT_2", pBlitImageInfo->regionCount, pBlitImageInfo->pRegions,
                                    VK_STRUCTURE_TYPE_IMAGE_BLIT_2, true, true, "VUID-VkImageBlit2-sType-sType",
                                    "VUID-VkBlitImageInfo2-pRegions-parameter", "VUID-VkBlitImageInfo2-regionCount-arraylength");

        if (pBlitImageInfo->pRegions != nullptr) {
            for (uint32_t regionIndex = 0; regionIndex < pBlitImageInfo->regionCount; ++regionIndex) {
                [[maybe_unused]] const Location pRegions_loc = pBlitImageInfo_loc.dot(Field::pRegions, regionIndex);
                skip |=
                    ValidateStructPnext(pRegions_loc, pBlitImageInfo->pRegions[regionIndex].pNext, 0, nullptr,
                                        GeneratedVulkanHeaderVersion, "VUID-VkImageBlit2-pNext-pNext", kVUIDUndefined, false, true);

                skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                      pBlitImageInfo->pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags,
                                      "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                      "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                      pBlitImageInfo->pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags,
                                      "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                      "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");
            }
        }

        skip |= ValidateRangedEnum(pBlitImageInfo_loc.dot(Field::filter), "VkFilter", pBlitImageInfo->filter,
                                   "VUID-VkBlitImageInfo2-filter-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResolveImage2(VkCommandBuffer commandBuffer,
                                                          const VkResolveImageInfo2* pResolveImageInfo,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pResolveImageInfo), "VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2", pResolveImageInfo,
                               VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2, true, "VUID-vkCmdResolveImage2-pResolveImageInfo-parameter",
                               "VUID-VkResolveImageInfo2-sType-sType");
    if (pResolveImageInfo != nullptr) {
        [[maybe_unused]] const Location pResolveImageInfo_loc = loc.dot(Field::pResolveImageInfo);
        skip |= ValidateStructPnext(pResolveImageInfo_loc, pResolveImageInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkResolveImageInfo2-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pResolveImageInfo_loc.dot(Field::srcImage), pResolveImageInfo->srcImage);

        skip |= ValidateRangedEnum(pResolveImageInfo_loc.dot(Field::srcImageLayout), "VkImageLayout",
                                   pResolveImageInfo->srcImageLayout, "VUID-VkResolveImageInfo2-srcImageLayout-parameter");

        skip |= ValidateRequiredHandle(pResolveImageInfo_loc.dot(Field::dstImage), pResolveImageInfo->dstImage);

        skip |= ValidateRangedEnum(pResolveImageInfo_loc.dot(Field::dstImageLayout), "VkImageLayout",
                                   pResolveImageInfo->dstImageLayout, "VUID-VkResolveImageInfo2-dstImageLayout-parameter");

        skip |= ValidateStructTypeArray(pResolveImageInfo_loc.dot(Field::regionCount), pResolveImageInfo_loc.dot(Field::pRegions),
                                        "VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2", pResolveImageInfo->regionCount,
                                        pResolveImageInfo->pRegions, VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2, true, true,
                                        "VUID-VkImageResolve2-sType-sType", "VUID-VkResolveImageInfo2-pRegions-parameter",
                                        "VUID-VkResolveImageInfo2-regionCount-arraylength");

        if (pResolveImageInfo->pRegions != nullptr) {
            for (uint32_t regionIndex = 0; regionIndex < pResolveImageInfo->regionCount; ++regionIndex) {
                [[maybe_unused]] const Location pRegions_loc = pResolveImageInfo_loc.dot(Field::pRegions, regionIndex);
                skip |= ValidateStructPnext(pRegions_loc, pResolveImageInfo->pRegions[regionIndex].pNext, 0, nullptr,
                                            GeneratedVulkanHeaderVersion, "VUID-VkImageResolve2-pNext-pNext", kVUIDUndefined, false,
                                            true);

                skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                      pResolveImageInfo->pRegions[regionIndex].srcSubresource.aspectMask, kRequiredFlags,
                                      "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                      "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                skip |= ValidateFlags(pRegions_loc.dot(Field::aspectMask), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                                      pResolveImageInfo->pRegions[regionIndex].dstSubresource.aspectMask, kRequiredFlags,
                                      "VUID-VkImageSubresourceLayers-aspectMask-parameter",
                                      "VUID-VkImageSubresourceLayers-aspectMask-requiredbitmask");

                // No xml-driven validation

                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pRenderingInfo), "VK_STRUCTURE_TYPE_RENDERING_INFO", pRenderingInfo,
                               VK_STRUCTURE_TYPE_RENDERING_INFO, true, kVUIDUndefined, kVUIDUndefined);
    if (pRenderingInfo != nullptr) {
        [[maybe_unused]] const Location pRenderingInfo_loc = loc.dot(Field::pRenderingInfo);
        constexpr std::array allowed_structs_VkRenderingInfo = {VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO};

        skip |= ValidateStructPnext(pRenderingInfo_loc, pRenderingInfo->pNext, allowed_structs_VkRenderingInfo.size(),
                                    allowed_structs_VkRenderingInfo.data(), GeneratedVulkanHeaderVersion, kVUIDUndefined,
                                    kVUIDUndefined, false, true);

        skip |= ValidateFlags(pRenderingInfo_loc.dot(Field::flags), "VkRenderingFlagBits", AllVkRenderingFlagBits,
                              pRenderingInfo->flags, kOptionalFlags, kVUIDUndefined);

        // No xml-driven validation

        // No xml-driven validation

        skip |= ValidateStructTypeArray(
            pRenderingInfo_loc.dot(Field::colorAttachmentCount), pRenderingInfo_loc.dot(Field::pColorAttachments),
            "VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO", pRenderingInfo->colorAttachmentCount, pRenderingInfo->pColorAttachments,
            VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO, false, true, kVUIDUndefined, kVUIDUndefined, kVUIDUndefined);

        if (pRenderingInfo->pColorAttachments != nullptr) {
            for (uint32_t colorAttachmentIndex = 0; colorAttachmentIndex < pRenderingInfo->colorAttachmentCount;
                 ++colorAttachmentIndex) {
                [[maybe_unused]] const Location pColorAttachments_loc =
                    pRenderingInfo_loc.dot(Field::pColorAttachments, colorAttachmentIndex);
                skip |= ValidateStructPnext(pColorAttachments_loc, pRenderingInfo->pColorAttachments[colorAttachmentIndex].pNext, 0,
                                            nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                skip |= ValidateRangedEnum(pColorAttachments_loc.dot(Field::imageLayout), "VkImageLayout",
                                           pRenderingInfo->pColorAttachments[colorAttachmentIndex].imageLayout, kVUIDUndefined);

                skip |= ValidateFlags(pColorAttachments_loc.dot(Field::resolveMode), "VkResolveModeFlagBits",
                                      AllVkResolveModeFlagBits, pRenderingInfo->pColorAttachments[colorAttachmentIndex].resolveMode,
                                      kOptionalSingleBit, kVUIDUndefined);

                skip |=
                    ValidateRangedEnum(pColorAttachments_loc.dot(Field::resolveImageLayout), "VkImageLayout",
                                       pRenderingInfo->pColorAttachments[colorAttachmentIndex].resolveImageLayout, kVUIDUndefined);

                skip |= ValidateRangedEnum(pColorAttachments_loc.dot(Field::loadOp), "VkAttachmentLoadOp",
                                           pRenderingInfo->pColorAttachments[colorAttachmentIndex].loadOp, kVUIDUndefined);

                skip |= ValidateRangedEnum(pColorAttachments_loc.dot(Field::storeOp), "VkAttachmentStoreOp",
                                           pRenderingInfo->pColorAttachments[colorAttachmentIndex].storeOp, kVUIDUndefined);

                // No xml-driven validation
            }
        }

        skip |= ValidateStructType(pRenderingInfo_loc.dot(Field::pDepthAttachment), "VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO",
                                   pRenderingInfo->pDepthAttachment, VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO, false,
                                   kVUIDUndefined, kVUIDUndefined);

        if (pRenderingInfo->pDepthAttachment != nullptr) {
            [[maybe_unused]] const Location pDepthAttachment_loc = pRenderingInfo_loc.dot(Field::pDepthAttachment);
            skip |= ValidateStructPnext(pDepthAttachment_loc, pRenderingInfo->pDepthAttachment->pNext, 0, nullptr,
                                        GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

            skip |= ValidateRangedEnum(pDepthAttachment_loc.dot(Field::imageLayout), "VkImageLayout",
                                       pRenderingInfo->pDepthAttachment->imageLayout, kVUIDUndefined);

            skip |= ValidateFlags(pDepthAttachment_loc.dot(Field::resolveMode), "VkResolveModeFlagBits", AllVkResolveModeFlagBits,
                                  pRenderingInfo->pDepthAttachment->resolveMode, kOptionalSingleBit, kVUIDUndefined);

            skip |= ValidateRangedEnum(pDepthAttachment_loc.dot(Field::resolveImageLayout), "VkImageLayout",
                                       pRenderingInfo->pDepthAttachment->resolveImageLayout, kVUIDUndefined);

            skip |= ValidateRangedEnum(pDepthAttachment_loc.dot(Field::loadOp), "VkAttachmentLoadOp",
                                       pRenderingInfo->pDepthAttachment->loadOp, kVUIDUndefined);

            skip |= ValidateRangedEnum(pDepthAttachment_loc.dot(Field::storeOp), "VkAttachmentStoreOp",
                                       pRenderingInfo->pDepthAttachment->storeOp, kVUIDUndefined);

            // No xml-driven validation
        }

        skip |= ValidateStructType(pRenderingInfo_loc.dot(Field::pStencilAttachment), "VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO",
                                   pRenderingInfo->pStencilAttachment, VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO, false,
                                   kVUIDUndefined, kVUIDUndefined);

        if (pRenderingInfo->pStencilAttachment != nullptr) {
            [[maybe_unused]] const Location pStencilAttachment_loc = pRenderingInfo_loc.dot(Field::pStencilAttachment);
            skip |= ValidateStructPnext(pStencilAttachment_loc, pRenderingInfo->pStencilAttachment->pNext, 0, nullptr,
                                        GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

            skip |= ValidateRangedEnum(pStencilAttachment_loc.dot(Field::imageLayout), "VkImageLayout",
                                       pRenderingInfo->pStencilAttachment->imageLayout, kVUIDUndefined);

            skip |= ValidateFlags(pStencilAttachment_loc.dot(Field::resolveMode), "VkResolveModeFlagBits", AllVkResolveModeFlagBits,
                                  pRenderingInfo->pStencilAttachment->resolveMode, kOptionalSingleBit, kVUIDUndefined);

            skip |= ValidateRangedEnum(pStencilAttachment_loc.dot(Field::resolveImageLayout), "VkImageLayout",
                                       pRenderingInfo->pStencilAttachment->resolveImageLayout, kVUIDUndefined);

            skip |= ValidateRangedEnum(pStencilAttachment_loc.dot(Field::loadOp), "VkAttachmentLoadOp",
                                       pRenderingInfo->pStencilAttachment->loadOp, kVUIDUndefined);

            skip |= ValidateRangedEnum(pStencilAttachment_loc.dot(Field::storeOp), "VkAttachmentStoreOp",
                                       pRenderingInfo->pStencilAttachment->storeOp, kVUIDUndefined);

            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdBeginRendering(commandBuffer, pRenderingInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdEndRendering(VkCommandBuffer commandBuffer, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateFlags(loc.dot(Field::cullMode), "VkCullModeFlagBits", AllVkCullModeFlagBits, cullMode, kOptionalFlags,
                          "VUID-vkCmdSetCullMode-cullMode-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRangedEnum(loc.dot(Field::frontFace), "VkFrontFace", frontFace, "VUID-vkCmdSetFrontFace-frontFace-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer,
                                                                 VkPrimitiveTopology primitiveTopology,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRangedEnum(loc.dot(Field::primitiveTopology), "VkPrimitiveTopology", primitiveTopology,
                               "VUID-vkCmdSetPrimitiveTopology-primitiveTopology-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                                 const VkViewport* pViewports, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateArray(loc.dot(Field::viewportCount), loc.dot(Field::pViewports), viewportCount, &pViewports, true, true,
                          "VUID-vkCmdSetViewportWithCount-viewportCount-arraylength",
                          "VUID-vkCmdSetViewportWithCount-pViewports-parameter");
    if (pViewports != nullptr) {
        for (uint32_t viewportIndex = 0; viewportIndex < viewportCount; ++viewportIndex) {
            [[maybe_unused]] const Location pViewports_loc = loc.dot(Field::pViewports, viewportIndex);
            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                                const VkRect2D* pScissors, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateArray(loc.dot(Field::scissorCount), loc.dot(Field::pScissors), scissorCount, &pScissors, true, true,
                          "VUID-vkCmdSetScissorWithCount-scissorCount-arraylength",
                          "VUID-vkCmdSetScissorWithCount-pScissors-parameter");
    if (pScissors != nullptr) {
        for (uint32_t scissorIndex = 0; scissorIndex < scissorCount; ++scissorIndex) {
            [[maybe_unused]] const Location pScissors_loc = loc.dot(Field::pScissors, scissorIndex);
            // No xml-driven validation

            // No xml-driven validation
        }
    }
    if (!skip) skip |= manual_PreCallValidateCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                               uint32_t bindingCount, const VkBuffer* pBuffers,
                                                               const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                               const VkDeviceSize* pStrides, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    if (!skip)
        skip |= manual_PreCallValidateCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                                            pStrides, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateBool32(loc.dot(Field::depthTestEnable), depthTestEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateBool32(loc.dot(Field::depthWriteEnable), depthWriteEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRangedEnum(loc.dot(Field::depthCompareOp), "VkCompareOp", depthCompareOp,
                               "VUID-vkCmdSetDepthCompareOp-depthCompareOp-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateBool32(loc.dot(Field::depthBoundsTestEnable), depthBoundsTestEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateBool32(loc.dot(Field::stencilTestEnable), stencilTestEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                         VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp,
                                                         VkCompareOp compareOp, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateFlags(loc.dot(Field::faceMask), "VkStencilFaceFlagBits", AllVkStencilFaceFlagBits, faceMask, kRequiredFlags,
                          "VUID-vkCmdSetStencilOp-faceMask-parameter", "VUID-vkCmdSetStencilOp-faceMask-requiredbitmask");
    skip |= ValidateRangedEnum(loc.dot(Field::failOp), "VkStencilOp", failOp, "VUID-vkCmdSetStencilOp-failOp-parameter");
    skip |= ValidateRangedEnum(loc.dot(Field::passOp), "VkStencilOp", passOp, "VUID-vkCmdSetStencilOp-passOp-parameter");
    skip |=
        ValidateRangedEnum(loc.dot(Field::depthFailOp), "VkStencilOp", depthFailOp, "VUID-vkCmdSetStencilOp-depthFailOp-parameter");
    skip |= ValidateRangedEnum(loc.dot(Field::compareOp), "VkCompareOp", compareOp, "VUID-vkCmdSetStencilOp-compareOp-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer,
                                                                       VkBool32 rasterizerDiscardEnable,
                                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateBool32(loc.dot(Field::rasterizerDiscardEnable), rasterizerDiscardEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateBool32(loc.dot(Field::depthBiasEnable), depthBiasEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer,
                                                                      VkBool32 primitiveRestartEnable,
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateBool32(loc.dot(Field::primitiveRestartEnable), primitiveRestartEnable);
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceBufferMemoryRequirements(VkDevice device,
                                                                           const VkDeviceBufferMemoryRequirements* pInfo,
                                                                           VkMemoryRequirements2* pMemoryRequirements,
                                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pInfo), "VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS", pInfo,
                               VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfo != nullptr) {
        [[maybe_unused]] const Location pInfo_loc = loc.dot(Field::pInfo);
        skip |= ValidateStructPnext(pInfo_loc, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined,
                                    kVUIDUndefined, false, true);

        skip |=
            ValidateStructType(pInfo_loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO", pInfo->pCreateInfo,
                               VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO, true, kVUIDUndefined, "VUID-VkBufferCreateInfo-sType-sType");

        if (pInfo->pCreateInfo != nullptr) {
            [[maybe_unused]] const Location pCreateInfo_loc = pInfo_loc.dot(Field::pCreateInfo);
            constexpr std::array allowed_structs_VkBufferCreateInfo = {VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO,
                                                                       VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO};

            skip |= ValidateStructPnext(pCreateInfo_loc, pInfo->pCreateInfo->pNext, allowed_structs_VkBufferCreateInfo.size(),
                                        allowed_structs_VkBufferCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                        "VUID-VkBufferCreateInfo-pNext-pNext", "VUID-VkBufferCreateInfo-sType-unique", false, true);

            skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkBufferCreateFlagBits", AllVkBufferCreateFlagBits,
                                  pInfo->pCreateInfo->flags, kOptionalFlags, "VUID-VkBufferCreateInfo-flags-parameter");

            skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::sharingMode), "VkSharingMode", pInfo->pCreateInfo->sharingMode,
                                       "VUID-VkBufferCreateInfo-sharingMode-parameter");
        }
    }
    skip |=
        ValidateStructType(loc.dot(Field::pMemoryRequirements), "VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2", pMemoryRequirements,
                           VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, true, kVUIDUndefined, "VUID-VkMemoryRequirements2-sType-sType");
    if (pMemoryRequirements != nullptr) {
        [[maybe_unused]] const Location pMemoryRequirements_loc = loc.dot(Field::pMemoryRequirements);
        constexpr std::array allowed_structs_VkMemoryRequirements2 = {VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS};

        skip |=
            ValidateStructPnext(pMemoryRequirements_loc, pMemoryRequirements->pNext, allowed_structs_VkMemoryRequirements2.size(),
                                allowed_structs_VkMemoryRequirements2.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkMemoryRequirements2-pNext-pNext", "VUID-VkMemoryRequirements2-sType-unique", false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceImageMemoryRequirements(VkDevice device,
                                                                          const VkDeviceImageMemoryRequirements* pInfo,
                                                                          VkMemoryRequirements2* pMemoryRequirements,
                                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pInfo), "VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS", pInfo,
                               VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfo != nullptr) {
        [[maybe_unused]] const Location pInfo_loc = loc.dot(Field::pInfo);
        skip |= ValidateStructPnext(pInfo_loc, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined,
                                    kVUIDUndefined, false, true);

        skip |= ValidateStructType(pInfo_loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO", pInfo->pCreateInfo,
                                   VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO, true, kVUIDUndefined, "VUID-VkImageCreateInfo-sType-sType");

        if (pInfo->pCreateInfo != nullptr) {
            [[maybe_unused]] const Location pCreateInfo_loc = pInfo_loc.dot(Field::pCreateInfo);
            constexpr std::array allowed_structs_VkImageCreateInfo = {
                VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX,
                VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO,
                VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT,
                VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT,
                VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO,
                VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO,
                VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR};

            skip |= ValidateStructPnext(pCreateInfo_loc, pInfo->pCreateInfo->pNext, allowed_structs_VkImageCreateInfo.size(),
                                        allowed_structs_VkImageCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                        "VUID-VkImageCreateInfo-pNext-pNext", "VUID-VkImageCreateInfo-sType-unique", false, true);

            skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkImageCreateFlagBits", AllVkImageCreateFlagBits,
                                  pInfo->pCreateInfo->flags, kOptionalFlags, "VUID-VkImageCreateInfo-flags-parameter");

            skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::imageType), "VkImageType", pInfo->pCreateInfo->imageType,
                                       "VUID-VkImageCreateInfo-imageType-parameter");

            skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::format), "VkFormat", pInfo->pCreateInfo->format,
                                       "VUID-VkImageCreateInfo-format-parameter");

            // No xml-driven validation

            skip |= ValidateFlags(pCreateInfo_loc.dot(Field::samples), "VkSampleCountFlagBits", AllVkSampleCountFlagBits,
                                  pInfo->pCreateInfo->samples, kRequiredSingleBit, "VUID-VkImageCreateInfo-samples-parameter",
                                  "VUID-VkImageCreateInfo-samples-parameter");

            skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::tiling), "VkImageTiling", pInfo->pCreateInfo->tiling,
                                       "VUID-VkImageCreateInfo-tiling-parameter");

            skip |= ValidateFlags(pCreateInfo_loc.dot(Field::usage), "VkImageUsageFlagBits", AllVkImageUsageFlagBits,
                                  pInfo->pCreateInfo->usage, kRequiredFlags, "VUID-VkImageCreateInfo-usage-parameter",
                                  "VUID-VkImageCreateInfo-usage-requiredbitmask");

            skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::sharingMode), "VkSharingMode", pInfo->pCreateInfo->sharingMode,
                                       "VUID-VkImageCreateInfo-sharingMode-parameter");

            skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::initialLayout), "VkImageLayout",
                                       pInfo->pCreateInfo->initialLayout, "VUID-VkImageCreateInfo-initialLayout-parameter");
        }

        skip |= ValidateFlags(pInfo_loc.dot(Field::planeAspect), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                              pInfo->planeAspect, kOptionalSingleBit, kVUIDUndefined);
    }
    skip |=
        ValidateStructType(loc.dot(Field::pMemoryRequirements), "VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2", pMemoryRequirements,
                           VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, true, kVUIDUndefined, "VUID-VkMemoryRequirements2-sType-sType");
    if (pMemoryRequirements != nullptr) {
        [[maybe_unused]] const Location pMemoryRequirements_loc = loc.dot(Field::pMemoryRequirements);
        constexpr std::array allowed_structs_VkMemoryRequirements2 = {VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS};

        skip |=
            ValidateStructPnext(pMemoryRequirements_loc, pMemoryRequirements->pNext, allowed_structs_VkMemoryRequirements2.size(),
                                allowed_structs_VkMemoryRequirements2.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkMemoryRequirements2-pNext-pNext", "VUID-VkMemoryRequirements2-sType-unique", false, false);
    }
    if (!skip) skip |= manual_PreCallValidateGetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceImageSparseMemoryRequirements(
    VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2* pSparseMemoryRequirements, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pInfo), "VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS", pInfo,
                               VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS, true, kVUIDUndefined, kVUIDUndefined);
    if (pInfo != nullptr) {
        [[maybe_unused]] const Location pInfo_loc = loc.dot(Field::pInfo);
        skip |= ValidateStructPnext(pInfo_loc, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined,
                                    kVUIDUndefined, false, true);

        skip |= ValidateStructType(pInfo_loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO", pInfo->pCreateInfo,
                                   VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO, true, kVUIDUndefined, "VUID-VkImageCreateInfo-sType-sType");

        if (pInfo->pCreateInfo != nullptr) {
            [[maybe_unused]] const Location pCreateInfo_loc = pInfo_loc.dot(Field::pCreateInfo);
            constexpr std::array allowed_structs_VkImageCreateInfo = {
                VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX,
                VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO,
                VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT,
                VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT,
                VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO,
                VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO,
                VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR};

            skip |= ValidateStructPnext(pCreateInfo_loc, pInfo->pCreateInfo->pNext, allowed_structs_VkImageCreateInfo.size(),
                                        allowed_structs_VkImageCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                        "VUID-VkImageCreateInfo-pNext-pNext", "VUID-VkImageCreateInfo-sType-unique", false, true);

            skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkImageCreateFlagBits", AllVkImageCreateFlagBits,
                                  pInfo->pCreateInfo->flags, kOptionalFlags, "VUID-VkImageCreateInfo-flags-parameter");

            skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::imageType), "VkImageType", pInfo->pCreateInfo->imageType,
                                       "VUID-VkImageCreateInfo-imageType-parameter");

            skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::format), "VkFormat", pInfo->pCreateInfo->format,
                                       "VUID-VkImageCreateInfo-format-parameter");

            // No xml-driven validation

            skip |= ValidateFlags(pCreateInfo_loc.dot(Field::samples), "VkSampleCountFlagBits", AllVkSampleCountFlagBits,
                                  pInfo->pCreateInfo->samples, kRequiredSingleBit, "VUID-VkImageCreateInfo-samples-parameter",
                                  "VUID-VkImageCreateInfo-samples-parameter");

            skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::tiling), "VkImageTiling", pInfo->pCreateInfo->tiling,
                                       "VUID-VkImageCreateInfo-tiling-parameter");

            skip |= ValidateFlags(pCreateInfo_loc.dot(Field::usage), "VkImageUsageFlagBits", AllVkImageUsageFlagBits,
                                  pInfo->pCreateInfo->usage, kRequiredFlags, "VUID-VkImageCreateInfo-usage-parameter",
                                  "VUID-VkImageCreateInfo-usage-requiredbitmask");

            skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::sharingMode), "VkSharingMode", pInfo->pCreateInfo->sharingMode,
                                       "VUID-VkImageCreateInfo-sharingMode-parameter");

            skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::initialLayout), "VkImageLayout",
                                       pInfo->pCreateInfo->initialLayout, "VUID-VkImageCreateInfo-initialLayout-parameter");
        }

        skip |= ValidateFlags(pInfo_loc.dot(Field::planeAspect), "VkImageAspectFlagBits", AllVkImageAspectFlagBits,
                              pInfo->planeAspect, kOptionalSingleBit, kVUIDUndefined);
    }
    skip |= ValidateArray(loc.dot(Field::pSparseMemoryRequirementCount), loc.dot(Field::pSparseMemoryRequirements),
                          pSparseMemoryRequirementCount, &pSparseMemoryRequirements, true, false, false, kVUIDUndefined,
                          kVUIDUndefined);
    if (!skip)
        skip |= manual_PreCallValidateGetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount,
                                                                             pSparseMemoryRequirements, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetCommandPoolMemoryConsumption(VkDevice device, VkCommandPool commandPool,
                                                                         VkCommandBuffer commandBuffer,
                                                                         VkCommandPoolMemoryConsumption* pConsumption,
                                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::commandPool), commandPool);
    skip |= ValidateStructType(loc.dot(Field::pConsumption), "VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_CONSUMPTION", pConsumption,
                               VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_CONSUMPTION, true,
                               "VUID-vkGetCommandPoolMemoryConsumption-pConsumption-parameter",
                               "VUID-VkCommandPoolMemoryConsumption-sType-sType");
    if (pConsumption != nullptr) {
        [[maybe_unused]] const Location pConsumption_loc = loc.dot(Field::pConsumption);
        skip |= ValidateStructPnext(pConsumption_loc, pConsumption->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkCommandPoolMemoryConsumption-pNext-pNext", kVUIDUndefined, false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetFaultData(VkDevice device, VkFaultQueryBehavior faultQueryBehavior,
                                                      VkBool32* pUnrecordedFaults, uint32_t* pFaultCount, VkFaultData* pFaults,
                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRangedEnum(loc.dot(Field::faultQueryBehavior), "VkFaultQueryBehavior", faultQueryBehavior,
                               "VUID-vkGetFaultData-faultQueryBehavior-parameter");
    skip |= ValidateRequiredPointer(loc.dot(Field::pUnrecordedFaults), pUnrecordedFaults,
                                    "VUID-vkGetFaultData-pUnrecordedFaults-parameter");
    skip |=
        ValidateStructTypeArray(loc.dot(Field::pFaultCount), loc.dot(Field::pFaults), "VK_STRUCTURE_TYPE_FAULT_DATA", pFaultCount,
                                pFaults, VK_STRUCTURE_TYPE_FAULT_DATA, true, false, false, "VUID-VkFaultData-sType-sType",
                                "VUID-vkGetFaultData-pFaults-parameter", "VUID-vkGetFaultData-pFaultCount-arraylength");
    if (pFaults != nullptr) {
        for (uint32_t pFaultIndex = 0; pFaultIndex < *pFaultCount; ++pFaultIndex) {
            [[maybe_unused]] const Location pFaults_loc = loc.dot(Field::pFaults, pFaultIndex);
            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface,
                                                           const VkAllocationCallbacks* pAllocator,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError(loc, "VK_KHR_surface");
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroySurfaceKHR-pAllocator-null", "vkDestroySurfaceKHR(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice,
                                                                            uint32_t queueFamilyIndex, VkSurfaceKHR surface,
                                                                            VkBool32* pSupported,
                                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError(loc, "VK_KHR_surface");
    skip |= ValidateRequiredHandle(loc.dot(Field::surface), surface);
    skip |= ValidateRequiredPointer(loc.dot(Field::pSupported), pSupported,
                                    "VUID-vkGetPhysicalDeviceSurfaceSupportKHR-pSupported-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice,
                                                                                 VkSurfaceKHR surface,
                                                                                 VkSurfaceCapabilitiesKHR* pSurfaceCapabilities,
                                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError(loc, "VK_KHR_surface");
    skip |= ValidateRequiredHandle(loc.dot(Field::surface), surface);
    skip |= ValidateRequiredPointer(loc.dot(Field::pSurfaceCapabilities), pSurfaceCapabilities,
                                    "VUID-vkGetPhysicalDeviceSurfaceCapabilitiesKHR-pSurfaceCapabilities-parameter");
    if (pSurfaceCapabilities != nullptr) {
        [[maybe_unused]] const Location pSurfaceCapabilities_loc = loc.dot(Field::pSurfaceCapabilities);
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface,
                                                                            uint32_t* pSurfaceFormatCount,
                                                                            VkSurfaceFormatKHR* pSurfaceFormats,
                                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError(loc, "VK_KHR_surface");
    skip |=
        ValidateArray(loc.dot(Field::pSurfaceFormatCount), loc.dot(Field::pSurfaceFormats), pSurfaceFormatCount, &pSurfaceFormats,
                      true, false, false, kVUIDUndefined, "VUID-vkGetPhysicalDeviceSurfaceFormatsKHR-pSurfaceFormats-parameter");
    if (pSurfaceFormats != nullptr) {
        for (uint32_t pSurfaceFormatIndex = 0; pSurfaceFormatIndex < *pSurfaceFormatCount; ++pSurfaceFormatIndex) {
            [[maybe_unused]] const Location pSurfaceFormats_loc = loc.dot(Field::pSurfaceFormats, pSurfaceFormatIndex);
            // No xml-driven validation
        }
    }
    if (!skip)
        skip |= manual_PreCallValidateGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount,
                                                                         pSurfaceFormats, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice,
                                                                                 VkSurfaceKHR surface, uint32_t* pPresentModeCount,
                                                                                 VkPresentModeKHR* pPresentModes,
                                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_surface) skip |= OutputExtensionError(loc, "VK_KHR_surface");
    skip |= ValidateArray(loc.dot(Field::pPresentModeCount), loc.dot(Field::pPresentModes), pPresentModeCount, &pPresentModes, true,
                          false, false, kVUIDUndefined, "VUID-vkGetPhysicalDeviceSurfacePresentModesKHR-pPresentModes-parameter");
    if (!skip)
        skip |= manual_PreCallValidateGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount,
                                                                              pPresentModes, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                            const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError(loc, "VK_KHR_swapchain");
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR", pCreateInfo,
                               VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR, true, "VUID-vkCreateSwapchainKHR-pCreateInfo-parameter",
                               "VUID-VkSwapchainCreateInfoKHR-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        constexpr std::array allowed_structs_VkSwapchainCreateInfoKHR = {VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR,
                                                                         VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO,
                                                                         VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT};

        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, allowed_structs_VkSwapchainCreateInfoKHR.size(),
                                    allowed_structs_VkSwapchainCreateInfoKHR.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkSwapchainCreateInfoKHR-pNext-pNext", "VUID-VkSwapchainCreateInfoKHR-sType-unique",
                                    false, true);

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::flags), "VkSwapchainCreateFlagBitsKHR", AllVkSwapchainCreateFlagBitsKHR,
                              pCreateInfo->flags, kOptionalFlags, "VUID-VkSwapchainCreateInfoKHR-flags-parameter");

        skip |= ValidateRequiredHandle(pCreateInfo_loc.dot(Field::surface), pCreateInfo->surface);

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::imageFormat), "VkFormat", pCreateInfo->imageFormat,
                                   "VUID-VkSwapchainCreateInfoKHR-imageFormat-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::imageColorSpace), "VkColorSpaceKHR", pCreateInfo->imageColorSpace,
                                   "VUID-VkSwapchainCreateInfoKHR-imageColorSpace-parameter");

        // No xml-driven validation

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::imageUsage), "VkImageUsageFlagBits", AllVkImageUsageFlagBits,
                              pCreateInfo->imageUsage, kRequiredFlags, "VUID-VkSwapchainCreateInfoKHR-imageUsage-parameter",
                              "VUID-VkSwapchainCreateInfoKHR-imageUsage-requiredbitmask");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::imageSharingMode), "VkSharingMode", pCreateInfo->imageSharingMode,
                                   "VUID-VkSwapchainCreateInfoKHR-imageSharingMode-parameter");

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::preTransform), "VkSurfaceTransformFlagBitsKHR",
                              AllVkSurfaceTransformFlagBitsKHR, pCreateInfo->preTransform, kRequiredSingleBit,
                              "VUID-VkSwapchainCreateInfoKHR-preTransform-parameter",
                              "VUID-VkSwapchainCreateInfoKHR-preTransform-parameter");

        skip |=
            ValidateFlags(pCreateInfo_loc.dot(Field::compositeAlpha), "VkCompositeAlphaFlagBitsKHR", AllVkCompositeAlphaFlagBitsKHR,
                          pCreateInfo->compositeAlpha, kRequiredSingleBit, "VUID-VkSwapchainCreateInfoKHR-compositeAlpha-parameter",
                          "VUID-VkSwapchainCreateInfoKHR-compositeAlpha-parameter");

        skip |= ValidateRangedEnum(pCreateInfo_loc.dot(Field::presentMode), "VkPresentModeKHR", pCreateInfo->presentMode,
                                   "VUID-VkSwapchainCreateInfoKHR-presentMode-parameter");

        skip |= ValidateBool32(pCreateInfo_loc.dot(Field::clipped), pCreateInfo->clipped);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateSwapchainKHR-pAllocator-null", "vkCreateSwapchainKHR(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pSwapchain), pSwapchain, "VUID-vkCreateSwapchainKHR-pSwapchain-parameter");
    if (!skip) skip |= manual_PreCallValidateCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain,
                                                               uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError(loc, "VK_KHR_swapchain");
    skip |= ValidateRequiredHandle(loc.dot(Field::swapchain), swapchain);
    skip |= ValidateArray(loc.dot(Field::pSwapchainImageCount), loc.dot(Field::pSwapchainImages), pSwapchainImageCount,
                          &pSwapchainImages, true, false, false, kVUIDUndefined,
                          "VUID-vkGetSwapchainImagesKHR-pSwapchainImages-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout,
                                                             VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex,
                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError(loc, "VK_KHR_swapchain");
    skip |= ValidateRequiredHandle(loc.dot(Field::swapchain), swapchain);
    skip |= ValidateRequiredPointer(loc.dot(Field::pImageIndex), pImageIndex, "VUID-vkAcquireNextImageKHR-pImageIndex-parameter");
    if (!skip)
        skip |= manual_PreCallValidateAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError(loc, "VK_KHR_swapchain");
    skip |= ValidateStructType(loc.dot(Field::pPresentInfo), "VK_STRUCTURE_TYPE_PRESENT_INFO_KHR", pPresentInfo,
                               VK_STRUCTURE_TYPE_PRESENT_INFO_KHR, true, "VUID-vkQueuePresentKHR-pPresentInfo-parameter",
                               "VUID-VkPresentInfoKHR-sType-sType");
    if (pPresentInfo != nullptr) {
        [[maybe_unused]] const Location pPresentInfo_loc = loc.dot(Field::pPresentInfo);
        constexpr std::array allowed_structs_VkPresentInfoKHR = {VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR,
                                                                 VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR,
                                                                 VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR};

        skip |= ValidateStructPnext(pPresentInfo_loc, pPresentInfo->pNext, allowed_structs_VkPresentInfoKHR.size(),
                                    allowed_structs_VkPresentInfoKHR.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkPresentInfoKHR-pNext-pNext", "VUID-VkPresentInfoKHR-sType-unique", false, true);

        skip |= ValidateArray(pPresentInfo_loc.dot(Field::waitSemaphoreCount), pPresentInfo_loc.dot(Field::pWaitSemaphores),
                              pPresentInfo->waitSemaphoreCount, &pPresentInfo->pWaitSemaphores, false, true, kVUIDUndefined,
                              "VUID-VkPresentInfoKHR-pWaitSemaphores-parameter");

        skip |= ValidateHandleArray(pPresentInfo_loc.dot(Field::swapchainCount), pPresentInfo_loc.dot(Field::pSwapchains),
                                    pPresentInfo->swapchainCount, pPresentInfo->pSwapchains, true, true, kVUIDUndefined);

        skip |= ValidateArray(pPresentInfo_loc.dot(Field::swapchainCount), pPresentInfo_loc.dot(Field::pImageIndices),
                              pPresentInfo->swapchainCount, &pPresentInfo->pImageIndices, true, true,
                              "VUID-VkPresentInfoKHR-swapchainCount-arraylength", "VUID-VkPresentInfoKHR-pImageIndices-parameter");

        skip |= ValidateArray(pPresentInfo_loc.dot(Field::swapchainCount), pPresentInfo_loc.dot(Field::pResults),
                              pPresentInfo->swapchainCount, &pPresentInfo->pResults, true, false,
                              "VUID-VkPresentInfoKHR-swapchainCount-arraylength", "VUID-VkPresentInfoKHR-pResults-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateQueuePresentKHR(queue, pPresentInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceGroupPresentCapabilitiesKHR(
    VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError(loc, "VK_KHR_swapchain");
    skip |= ValidateStructType(loc.dot(Field::pDeviceGroupPresentCapabilities),
                               "VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR", pDeviceGroupPresentCapabilities,
                               VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR, true,
                               "VUID-vkGetDeviceGroupPresentCapabilitiesKHR-pDeviceGroupPresentCapabilities-parameter",
                               "VUID-VkDeviceGroupPresentCapabilitiesKHR-sType-sType");
    if (pDeviceGroupPresentCapabilities != nullptr) {
        [[maybe_unused]] const Location pDeviceGroupPresentCapabilities_loc = loc.dot(Field::pDeviceGroupPresentCapabilities);
        skip |= ValidateStructPnext(pDeviceGroupPresentCapabilities_loc, pDeviceGroupPresentCapabilities->pNext, 0, nullptr,
                                    GeneratedVulkanHeaderVersion, "VUID-VkDeviceGroupPresentCapabilitiesKHR-pNext-pNext",
                                    kVUIDUndefined, false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface,
                                                                              VkDeviceGroupPresentModeFlagsKHR* pModes,
                                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError(loc, "VK_KHR_swapchain");
    skip |= ValidateRequiredHandle(loc.dot(Field::surface), surface);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice,
                                                                               VkSurfaceKHR surface, uint32_t* pRectCount,
                                                                               VkRect2D* pRects,
                                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateRequiredHandle(loc.dot(Field::surface), surface);
    skip |= ValidateArray(loc.dot(Field::pRectCount), loc.dot(Field::pRects), pRectCount, &pRects, true, false, false,
                          kVUIDUndefined, "VUID-vkGetPhysicalDevicePresentRectanglesKHR-pRects-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo,
                                                              uint32_t* pImageIndex, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_swapchain)) skip |= OutputExtensionError(loc, "VK_KHR_swapchain");
    skip |= ValidateStructType(loc.dot(Field::pAcquireInfo), "VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR", pAcquireInfo,
                               VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR, true,
                               "VUID-vkAcquireNextImage2KHR-pAcquireInfo-parameter", "VUID-VkAcquireNextImageInfoKHR-sType-sType");
    if (pAcquireInfo != nullptr) {
        [[maybe_unused]] const Location pAcquireInfo_loc = loc.dot(Field::pAcquireInfo);
        skip |= ValidateStructPnext(pAcquireInfo_loc, pAcquireInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkAcquireNextImageInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pAcquireInfo_loc.dot(Field::swapchain), pAcquireInfo->swapchain);
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pImageIndex), pImageIndex, "VUID-vkAcquireNextImage2KHR-pImageIndex-parameter");
    if (!skip) skip |= manual_PreCallValidateAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice,
                                                                               uint32_t* pPropertyCount,
                                                                               VkDisplayPropertiesKHR* pProperties,
                                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError(loc, "VK_KHR_display");
    skip |= ValidateArray(loc.dot(Field::pPropertyCount), loc.dot(Field::pProperties), pPropertyCount, &pProperties, true, false,
                          false, kVUIDUndefined, "VUID-vkGetPhysicalDeviceDisplayPropertiesKHR-pProperties-parameter");
    if (pProperties != nullptr) {
        for (uint32_t pPropertyIndex = 0; pPropertyIndex < *pPropertyCount; ++pPropertyIndex) {
            [[maybe_unused]] const Location pProperties_loc = loc.dot(Field::pProperties, pPropertyIndex);
            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice,
                                                                                    uint32_t* pPropertyCount,
                                                                                    VkDisplayPlanePropertiesKHR* pProperties,
                                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError(loc, "VK_KHR_display");
    skip |= ValidateArray(loc.dot(Field::pPropertyCount), loc.dot(Field::pProperties), pPropertyCount, &pProperties, true, false,
                          false, kVUIDUndefined, "VUID-vkGetPhysicalDeviceDisplayPlanePropertiesKHR-pProperties-parameter");
    if (pProperties != nullptr) {
        for (uint32_t pPropertyIndex = 0; pPropertyIndex < *pPropertyCount; ++pPropertyIndex) {
            [[maybe_unused]] const Location pProperties_loc = loc.dot(Field::pProperties, pPropertyIndex);
            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex,
                                                                             uint32_t* pDisplayCount, VkDisplayKHR* pDisplays,
                                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError(loc, "VK_KHR_display");
    skip |= ValidateArray(loc.dot(Field::pDisplayCount), loc.dot(Field::pDisplays), pDisplayCount, &pDisplays, true, false, false,
                          kVUIDUndefined, "VUID-vkGetDisplayPlaneSupportedDisplaysKHR-pDisplays-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                                     uint32_t* pPropertyCount,
                                                                     VkDisplayModePropertiesKHR* pProperties,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError(loc, "VK_KHR_display");
    skip |= ValidateRequiredHandle(loc.dot(Field::display), display);
    skip |= ValidateArray(loc.dot(Field::pPropertyCount), loc.dot(Field::pProperties), pPropertyCount, &pProperties, true, false,
                          false, kVUIDUndefined, "VUID-vkGetDisplayModePropertiesKHR-pProperties-parameter");
    if (pProperties != nullptr) {
        for (uint32_t pPropertyIndex = 0; pPropertyIndex < *pPropertyCount; ++pPropertyIndex) {
            [[maybe_unused]] const Location pProperties_loc = loc.dot(Field::pProperties, pPropertyIndex);
            // No xml-driven validation
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                              const VkDisplayModeCreateInfoKHR* pCreateInfo,
                                                              const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError(loc, "VK_KHR_display");
    skip |= ValidateRequiredHandle(loc.dot(Field::display), display);
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR", pCreateInfo,
                               VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR, true,
                               "VUID-vkCreateDisplayModeKHR-pCreateInfo-parameter", "VUID-VkDisplayModeCreateInfoKHR-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDisplayModeCreateInfoKHR-pNext-pNext", kVUIDUndefined, true, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkDisplayModeCreateInfoKHR-flags-zerobitmask");

        // No xml-driven validation
    }
    if (pAllocator != nullptr) {
        skip |=
            LogError(instance, "VUID-vkCreateDisplayModeKHR-pAllocator-null", "vkCreateDisplayModeKHR(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pMode), pMode, "VUID-vkCreateDisplayModeKHR-pMode-parameter");
    if (!skip)
        skip |= manual_PreCallValidateCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode,
                                                                        uint32_t planeIndex,
                                                                        VkDisplayPlaneCapabilitiesKHR* pCapabilities,
                                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError(loc, "VK_KHR_display");
    skip |= ValidateRequiredHandle(loc.dot(Field::mode), mode);
    skip |= ValidateRequiredPointer(loc.dot(Field::pCapabilities), pCapabilities,
                                    "VUID-vkGetDisplayPlaneCapabilitiesKHR-pCapabilities-parameter");
    if (pCapabilities != nullptr) {
        [[maybe_unused]] const Location pCapabilities_loc = loc.dot(Field::pCapabilities);
        // No xml-driven validation
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateDisplayPlaneSurfaceKHR(VkInstance instance,
                                                                      const VkDisplaySurfaceCreateInfoKHR* pCreateInfo,
                                                                      const VkAllocationCallbacks* pAllocator,
                                                                      VkSurfaceKHR* pSurface, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_display) skip |= OutputExtensionError(loc, "VK_KHR_display");
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR", pCreateInfo,
                               VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR, true,
                               "VUID-vkCreateDisplayPlaneSurfaceKHR-pCreateInfo-parameter",
                               "VUID-VkDisplaySurfaceCreateInfoKHR-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDisplaySurfaceCreateInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkDisplaySurfaceCreateInfoKHR-flags-zerobitmask");

        skip |= ValidateRequiredHandle(pCreateInfo_loc.dot(Field::displayMode), pCreateInfo->displayMode);

        skip |=
            ValidateFlags(pCreateInfo_loc.dot(Field::transform), "VkSurfaceTransformFlagBitsKHR", AllVkSurfaceTransformFlagBitsKHR,
                          pCreateInfo->transform, kRequiredSingleBit, "VUID-VkDisplaySurfaceCreateInfoKHR-transform-parameter",
                          "VUID-VkDisplaySurfaceCreateInfoKHR-transform-parameter");

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::alphaMode), "VkDisplayPlaneAlphaFlagBitsKHR",
                              AllVkDisplayPlaneAlphaFlagBitsKHR, pCreateInfo->alphaMode, kRequiredSingleBit,
                              "VUID-VkDisplaySurfaceCreateInfoKHR-alphaMode-parameter",
                              "VUID-VkDisplaySurfaceCreateInfoKHR-alphaMode-parameter");

        // No xml-driven validation
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateDisplayPlaneSurfaceKHR-pAllocator-null",
                         "vkCreateDisplayPlaneSurfaceKHR(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pSurface), pSurface, "VUID-vkCreateDisplayPlaneSurfaceKHR-pSurface-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount,
                                                                   const VkSwapchainCreateInfoKHR* pCreateInfos,
                                                                   const VkAllocationCallbacks* pAllocator,
                                                                   VkSwapchainKHR* pSwapchains,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_display_swapchain)) skip |= OutputExtensionError(loc, "VK_KHR_display_swapchain");
    skip |= ValidateStructTypeArray(
        loc.dot(Field::swapchainCount), loc.dot(Field::pCreateInfos), "VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR", swapchainCount,
        pCreateInfos, VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR, true, true, "VUID-VkSwapchainCreateInfoKHR-sType-sType",
        "VUID-vkCreateSharedSwapchainsKHR-pCreateInfos-parameter", "VUID-vkCreateSharedSwapchainsKHR-swapchainCount-arraylength");
    if (pCreateInfos != nullptr) {
        for (uint32_t swapchainIndex = 0; swapchainIndex < swapchainCount; ++swapchainIndex) {
            [[maybe_unused]] const Location pCreateInfos_loc = loc.dot(Field::pCreateInfos, swapchainIndex);
            constexpr std::array allowed_structs_VkSwapchainCreateInfoKHR = {
                VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR, VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO,
                VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT};

            skip |= ValidateStructPnext(
                pCreateInfos_loc, pCreateInfos[swapchainIndex].pNext, allowed_structs_VkSwapchainCreateInfoKHR.size(),
                allowed_structs_VkSwapchainCreateInfoKHR.data(), GeneratedVulkanHeaderVersion,
                "VUID-VkSwapchainCreateInfoKHR-pNext-pNext", "VUID-VkSwapchainCreateInfoKHR-sType-unique", false, true);

            skip |=
                ValidateFlags(pCreateInfos_loc.dot(Field::flags), "VkSwapchainCreateFlagBitsKHR", AllVkSwapchainCreateFlagBitsKHR,
                              pCreateInfos[swapchainIndex].flags, kOptionalFlags, "VUID-VkSwapchainCreateInfoKHR-flags-parameter");

            skip |= ValidateRequiredHandle(pCreateInfos_loc.dot(Field::surface), pCreateInfos[swapchainIndex].surface);

            skip |=
                ValidateRangedEnum(pCreateInfos_loc.dot(Field::imageFormat), "VkFormat", pCreateInfos[swapchainIndex].imageFormat,
                                   "VUID-VkSwapchainCreateInfoKHR-imageFormat-parameter");

            skip |= ValidateRangedEnum(pCreateInfos_loc.dot(Field::imageColorSpace), "VkColorSpaceKHR",
                                       pCreateInfos[swapchainIndex].imageColorSpace,
                                       "VUID-VkSwapchainCreateInfoKHR-imageColorSpace-parameter");

            // No xml-driven validation

            skip |= ValidateFlags(pCreateInfos_loc.dot(Field::imageUsage), "VkImageUsageFlagBits", AllVkImageUsageFlagBits,
                                  pCreateInfos[swapchainIndex].imageUsage, kRequiredFlags,
                                  "VUID-VkSwapchainCreateInfoKHR-imageUsage-parameter",
                                  "VUID-VkSwapchainCreateInfoKHR-imageUsage-requiredbitmask");

            skip |= ValidateRangedEnum(pCreateInfos_loc.dot(Field::imageSharingMode), "VkSharingMode",
                                       pCreateInfos[swapchainIndex].imageSharingMode,
                                       "VUID-VkSwapchainCreateInfoKHR-imageSharingMode-parameter");

            skip |= ValidateFlags(pCreateInfos_loc.dot(Field::preTransform), "VkSurfaceTransformFlagBitsKHR",
                                  AllVkSurfaceTransformFlagBitsKHR, pCreateInfos[swapchainIndex].preTransform, kRequiredSingleBit,
                                  "VUID-VkSwapchainCreateInfoKHR-preTransform-parameter",
                                  "VUID-VkSwapchainCreateInfoKHR-preTransform-parameter");

            skip |= ValidateFlags(pCreateInfos_loc.dot(Field::compositeAlpha), "VkCompositeAlphaFlagBitsKHR",
                                  AllVkCompositeAlphaFlagBitsKHR, pCreateInfos[swapchainIndex].compositeAlpha, kRequiredSingleBit,
                                  "VUID-VkSwapchainCreateInfoKHR-compositeAlpha-parameter",
                                  "VUID-VkSwapchainCreateInfoKHR-compositeAlpha-parameter");

            skip |=
                ValidateRangedEnum(pCreateInfos_loc.dot(Field::presentMode), "VkPresentModeKHR",
                                   pCreateInfos[swapchainIndex].presentMode, "VUID-VkSwapchainCreateInfoKHR-presentMode-parameter");

            skip |= ValidateBool32(pCreateInfos_loc.dot(Field::clipped), pCreateInfos[swapchainIndex].clipped);
        }
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateSharedSwapchainsKHR-pAllocator-null",
                         "vkCreateSharedSwapchainsKHR(): pAllocator must be NULL");
    }
    skip |= ValidateArray(loc.dot(Field::swapchainCount), loc.dot(Field::pSwapchains), swapchainCount, &pSwapchains, true, true,
                          "VUID-vkCreateSharedSwapchainsKHR-swapchainCount-arraylength",
                          "VUID-vkCreateSharedSwapchainsKHR-pSwapchains-parameter");
    if (!skip)
        skip |= manual_PreCallValidateCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains,
                                                                error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd,
                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_external_memory_fd)) skip |= OutputExtensionError(loc, "VK_KHR_external_memory_fd");
    skip |= ValidateStructType(loc.dot(Field::pGetFdInfo), "VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR", pGetFdInfo,
                               VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR, true, "VUID-vkGetMemoryFdKHR-pGetFdInfo-parameter",
                               "VUID-VkMemoryGetFdInfoKHR-sType-sType");
    if (pGetFdInfo != nullptr) {
        [[maybe_unused]] const Location pGetFdInfo_loc = loc.dot(Field::pGetFdInfo);
        skip |= ValidateStructPnext(pGetFdInfo_loc, pGetFdInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkMemoryGetFdInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pGetFdInfo_loc.dot(Field::memory), pGetFdInfo->memory);

        skip |= ValidateFlags(pGetFdInfo_loc.dot(Field::handleType), "VkExternalMemoryHandleTypeFlagBits",
                              AllVkExternalMemoryHandleTypeFlagBits, pGetFdInfo->handleType, kRequiredSingleBit,
                              "VUID-VkMemoryGetFdInfoKHR-handleType-parameter", "VUID-VkMemoryGetFdInfoKHR-handleType-parameter");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pFd), pFd, "VUID-vkGetMemoryFdKHR-pFd-parameter");
    if (!skip) skip |= manual_PreCallValidateGetMemoryFdKHR(device, pGetFdInfo, pFd, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType,
                                                                  int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_external_memory_fd)) skip |= OutputExtensionError(loc, "VK_KHR_external_memory_fd");
    skip |= ValidateFlags(loc.dot(Field::handleType), "VkExternalMemoryHandleTypeFlagBits", AllVkExternalMemoryHandleTypeFlagBits,
                          handleType, kRequiredSingleBit, "VUID-vkGetMemoryFdPropertiesKHR-handleType-parameter",
                          "VUID-vkGetMemoryFdPropertiesKHR-handleType-parameter");
    skip |= ValidateStructType(loc.dot(Field::pMemoryFdProperties), "VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR",
                               pMemoryFdProperties, VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR, true,
                               "VUID-vkGetMemoryFdPropertiesKHR-pMemoryFdProperties-parameter",
                               "VUID-VkMemoryFdPropertiesKHR-sType-sType");
    if (pMemoryFdProperties != nullptr) {
        [[maybe_unused]] const Location pMemoryFdProperties_loc = loc.dot(Field::pMemoryFdProperties);
        skip |= ValidateStructPnext(pMemoryFdProperties_loc, pMemoryFdProperties->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkMemoryFdPropertiesKHR-pNext-pNext", kVUIDUndefined, false, false);
    }
    if (!skip) skip |= manual_PreCallValidateGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateImportSemaphoreFdKHR(VkDevice device,
                                                              const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_external_semaphore_fd))
        skip |= OutputExtensionError(loc, "VK_KHR_external_semaphore_fd");
    skip |= ValidateStructType(loc.dot(Field::pImportSemaphoreFdInfo), "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR",
                               pImportSemaphoreFdInfo, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR, true,
                               "VUID-vkImportSemaphoreFdKHR-pImportSemaphoreFdInfo-parameter",
                               "VUID-VkImportSemaphoreFdInfoKHR-sType-sType");
    if (pImportSemaphoreFdInfo != nullptr) {
        [[maybe_unused]] const Location pImportSemaphoreFdInfo_loc = loc.dot(Field::pImportSemaphoreFdInfo);
        skip |=
            ValidateStructPnext(pImportSemaphoreFdInfo_loc, pImportSemaphoreFdInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                "VUID-VkImportSemaphoreFdInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pImportSemaphoreFdInfo_loc.dot(Field::semaphore), pImportSemaphoreFdInfo->semaphore);

        skip |=
            ValidateFlags(pImportSemaphoreFdInfo_loc.dot(Field::flags), "VkSemaphoreImportFlagBits", AllVkSemaphoreImportFlagBits,
                          pImportSemaphoreFdInfo->flags, kOptionalFlags, "VUID-VkImportSemaphoreFdInfoKHR-flags-parameter");

        skip |= ValidateFlags(pImportSemaphoreFdInfo_loc.dot(Field::handleType), "VkExternalSemaphoreHandleTypeFlagBits",
                              AllVkExternalSemaphoreHandleTypeFlagBits, pImportSemaphoreFdInfo->handleType, kRequiredSingleBit,
                              "VUID-VkImportSemaphoreFdInfoKHR-handleType-parameter",
                              "VUID-VkImportSemaphoreFdInfoKHR-handleType-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_external_semaphore_fd))
        skip |= OutputExtensionError(loc, "VK_KHR_external_semaphore_fd");
    skip |= ValidateStructType(loc.dot(Field::pGetFdInfo), "VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR", pGetFdInfo,
                               VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR, true, "VUID-vkGetSemaphoreFdKHR-pGetFdInfo-parameter",
                               "VUID-VkSemaphoreGetFdInfoKHR-sType-sType");
    if (pGetFdInfo != nullptr) {
        [[maybe_unused]] const Location pGetFdInfo_loc = loc.dot(Field::pGetFdInfo);
        skip |= ValidateStructPnext(pGetFdInfo_loc, pGetFdInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkSemaphoreGetFdInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pGetFdInfo_loc.dot(Field::semaphore), pGetFdInfo->semaphore);

        skip |=
            ValidateFlags(pGetFdInfo_loc.dot(Field::handleType), "VkExternalSemaphoreHandleTypeFlagBits",
                          AllVkExternalSemaphoreHandleTypeFlagBits, pGetFdInfo->handleType, kRequiredSingleBit,
                          "VUID-VkSemaphoreGetFdInfoKHR-handleType-parameter", "VUID-VkSemaphoreGetFdInfoKHR-handleType-parameter");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pFd), pFd, "VUID-vkGetSemaphoreFdKHR-pFd-parameter");
    if (!skip) skip |= manual_PreCallValidateGetSemaphoreFdKHR(device, pGetFdInfo, pFd, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_shared_presentable_image))
        skip |= OutputExtensionError(loc, "VK_KHR_shared_presentable_image");
    skip |= ValidateRequiredHandle(loc.dot(Field::swapchain), swapchain);
    return skip;
}

bool StatelessValidation::PreCallValidateImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_external_fence_fd)) skip |= OutputExtensionError(loc, "VK_KHR_external_fence_fd");
    skip |= ValidateStructType(loc.dot(Field::pImportFenceFdInfo), "VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR", pImportFenceFdInfo,
                               VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR, true,
                               "VUID-vkImportFenceFdKHR-pImportFenceFdInfo-parameter", "VUID-VkImportFenceFdInfoKHR-sType-sType");
    if (pImportFenceFdInfo != nullptr) {
        [[maybe_unused]] const Location pImportFenceFdInfo_loc = loc.dot(Field::pImportFenceFdInfo);
        skip |= ValidateStructPnext(pImportFenceFdInfo_loc, pImportFenceFdInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkImportFenceFdInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pImportFenceFdInfo_loc.dot(Field::fence), pImportFenceFdInfo->fence);

        skip |= ValidateFlags(pImportFenceFdInfo_loc.dot(Field::flags), "VkFenceImportFlagBits", AllVkFenceImportFlagBits,
                              pImportFenceFdInfo->flags, kOptionalFlags, "VUID-VkImportFenceFdInfoKHR-flags-parameter");

        skip |=
            ValidateFlags(pImportFenceFdInfo_loc.dot(Field::handleType), "VkExternalFenceHandleTypeFlagBits",
                          AllVkExternalFenceHandleTypeFlagBits, pImportFenceFdInfo->handleType, kRequiredSingleBit,
                          "VUID-VkImportFenceFdInfoKHR-handleType-parameter", "VUID-VkImportFenceFdInfoKHR-handleType-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateImportFenceFdKHR(device, pImportFenceFdInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd,
                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_external_fence_fd)) skip |= OutputExtensionError(loc, "VK_KHR_external_fence_fd");
    skip |= ValidateStructType(loc.dot(Field::pGetFdInfo), "VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR", pGetFdInfo,
                               VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR, true, "VUID-vkGetFenceFdKHR-pGetFdInfo-parameter",
                               "VUID-VkFenceGetFdInfoKHR-sType-sType");
    if (pGetFdInfo != nullptr) {
        [[maybe_unused]] const Location pGetFdInfo_loc = loc.dot(Field::pGetFdInfo);
        skip |= ValidateStructPnext(pGetFdInfo_loc, pGetFdInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkFenceGetFdInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pGetFdInfo_loc.dot(Field::fence), pGetFdInfo->fence);

        skip |= ValidateFlags(pGetFdInfo_loc.dot(Field::handleType), "VkExternalFenceHandleTypeFlagBits",
                              AllVkExternalFenceHandleTypeFlagBits, pGetFdInfo->handleType, kRequiredSingleBit,
                              "VUID-VkFenceGetFdInfoKHR-handleType-parameter", "VUID-VkFenceGetFdInfoKHR-handleType-parameter");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pFd), pFd, "VUID-vkGetFenceFdKHR-pFd-parameter");
    if (!skip) skip |= manual_PreCallValidateGetFenceFdKHR(device, pGetFdInfo, pFd, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters,
    VkPerformanceCounterDescriptionKHR* pCounterDescriptions, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructTypeArray(
        loc.dot(Field::pCounterCount), loc.dot(Field::pCounters), "VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR", pCounterCount,
        pCounters, VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR, true, false, false, "VUID-VkPerformanceCounterKHR-sType-sType",
        "VUID-vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR-pCounters-parameter", kVUIDUndefined);
    if (pCounters != nullptr) {
        for (uint32_t pIndexerIndex = 0; pIndexerIndex < *pCounterCount; ++pIndexerIndex) {
            [[maybe_unused]] const Location pCounters_loc = loc.dot(Field::pCounters, pIndexerIndex);
            skip |= ValidateStructPnext(pCounters_loc, pCounters[pIndexerIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                        "VUID-VkPerformanceCounterKHR-pNext-pNext", kVUIDUndefined, true, false);
        }
    }
    skip |= ValidateStructTypeArray(
        loc.dot(Field::pCounterCount), loc.dot(Field::pCounterDescriptions),
        "VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR", pCounterCount, pCounterDescriptions,
        VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR, true, false, false,
        "VUID-VkPerformanceCounterDescriptionKHR-sType-sType",
        "VUID-vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR-pCounterDescriptions-parameter", kVUIDUndefined);
    if (pCounterDescriptions != nullptr) {
        for (uint32_t pIndexerIndex = 0; pIndexerIndex < *pCounterCount; ++pIndexerIndex) {
            [[maybe_unused]] const Location pCounterDescriptions_loc = loc.dot(Field::pCounterDescriptions, pIndexerIndex);
            skip |= ValidateStructPnext(pCounterDescriptions_loc, pCounterDescriptions[pIndexerIndex].pNext, 0, nullptr,
                                        GeneratedVulkanHeaderVersion, "VUID-VkPerformanceCounterDescriptionKHR-pNext-pNext",
                                        kVUIDUndefined, true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses,
    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |=
        ValidateStructType(loc.dot(Field::pPerformanceQueryCreateInfo), "VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR",
                           pPerformanceQueryCreateInfo, VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR, true,
                           "VUID-vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR-pPerformanceQueryCreateInfo-parameter",
                           "VUID-VkQueryPoolPerformanceCreateInfoKHR-sType-sType");
    if (pPerformanceQueryCreateInfo != nullptr) {
        [[maybe_unused]] const Location pPerformanceQueryCreateInfo_loc = loc.dot(Field::pPerformanceQueryCreateInfo);
        skip |= ValidateStructPnext(pPerformanceQueryCreateInfo_loc, pPerformanceQueryCreateInfo->pNext, 0, nullptr,
                                    GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, true, true);

        skip |= ValidateArray(pPerformanceQueryCreateInfo_loc.dot(Field::counterIndexCount),
                              pPerformanceQueryCreateInfo_loc.dot(Field::pCounterIndices),
                              pPerformanceQueryCreateInfo->counterIndexCount, &pPerformanceQueryCreateInfo->pCounterIndices, true,
                              true, "VUID-VkQueryPoolPerformanceCreateInfoKHR-counterIndexCount-arraylength",
                              "VUID-VkQueryPoolPerformanceCreateInfoKHR-pCounterIndices-parameter");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pNumPasses), pNumPasses,
                                    "VUID-vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR-pNumPasses-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateAcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_performance_query)) skip |= OutputExtensionError(loc, "VK_KHR_performance_query");
    skip |= ValidateStructType(loc.dot(Field::pInfo), "VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR", pInfo,
                               VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR, true,
                               "VUID-vkAcquireProfilingLockKHR-pInfo-parameter", "VUID-VkAcquireProfilingLockInfoKHR-sType-sType");
    if (pInfo != nullptr) {
        [[maybe_unused]] const Location pInfo_loc = loc.dot(Field::pInfo);
        skip |= ValidateStructPnext(pInfo_loc, pInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkAcquireProfilingLockInfoKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags(pInfo_loc.dot(Field::flags), pInfo->flags,
                                      "VUID-VkAcquireProfilingLockInfoKHR-flags-zerobitmask");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateReleaseProfilingLockKHR(VkDevice device, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_performance_query)) skip |= OutputExtensionError(loc, "VK_KHR_performance_query");
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfaceCapabilities2KHR(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
    VkSurfaceCapabilities2KHR* pSurfaceCapabilities, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_get_surface_capabilities2)
        skip |= OutputExtensionError(loc, "VK_KHR_get_surface_capabilities2");
    skip |= ValidateStructType(loc.dot(Field::pSurfaceInfo), "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR", pSurfaceInfo,
                               VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR, true,
                               "VUID-vkGetPhysicalDeviceSurfaceCapabilities2KHR-pSurfaceInfo-parameter",
                               "VUID-VkPhysicalDeviceSurfaceInfo2KHR-sType-sType");
    if (pSurfaceInfo != nullptr) {
        [[maybe_unused]] const Location pSurfaceInfo_loc = loc.dot(Field::pSurfaceInfo);
        skip |= ValidateStructPnext(pSurfaceInfo_loc, pSurfaceInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkPhysicalDeviceSurfaceInfo2KHR-pNext-pNext", kVUIDUndefined, true, true);
    }
    skip |= ValidateStructType(loc.dot(Field::pSurfaceCapabilities), "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR",
                               pSurfaceCapabilities, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR, true,
                               "VUID-vkGetPhysicalDeviceSurfaceCapabilities2KHR-pSurfaceCapabilities-parameter",
                               "VUID-VkSurfaceCapabilities2KHR-sType-sType");
    if (pSurfaceCapabilities != nullptr) {
        [[maybe_unused]] const Location pSurfaceCapabilities_loc = loc.dot(Field::pSurfaceCapabilities);
        constexpr std::array allowed_structs_VkSurfaceCapabilities2KHR = {
            VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR};

        skip |= ValidateStructPnext(
            pSurfaceCapabilities_loc, pSurfaceCapabilities->pNext, allowed_structs_VkSurfaceCapabilities2KHR.size(),
            allowed_structs_VkSurfaceCapabilities2KHR.data(), GeneratedVulkanHeaderVersion,
            "VUID-VkSurfaceCapabilities2KHR-pNext-pNext", "VUID-VkSurfaceCapabilities2KHR-sType-unique", true, false);
    }
    if (!skip)
        skip |= manual_PreCallValidateGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities,
                                                                               error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice,
                                                                             const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                             uint32_t* pSurfaceFormatCount,
                                                                             VkSurfaceFormat2KHR* pSurfaceFormats,
                                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_get_surface_capabilities2)
        skip |= OutputExtensionError(loc, "VK_KHR_get_surface_capabilities2");
    skip |= ValidateStructType(loc.dot(Field::pSurfaceInfo), "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR", pSurfaceInfo,
                               VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR, true,
                               "VUID-vkGetPhysicalDeviceSurfaceFormats2KHR-pSurfaceInfo-parameter",
                               "VUID-VkPhysicalDeviceSurfaceInfo2KHR-sType-sType");
    if (pSurfaceInfo != nullptr) {
        [[maybe_unused]] const Location pSurfaceInfo_loc = loc.dot(Field::pSurfaceInfo);
        skip |= ValidateStructPnext(pSurfaceInfo_loc, pSurfaceInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkPhysicalDeviceSurfaceInfo2KHR-pNext-pNext", kVUIDUndefined, true, true);
    }
    skip |=
        ValidateStructTypeArray(loc.dot(Field::pSurfaceFormatCount), loc.dot(Field::pSurfaceFormats),
                                "VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR", pSurfaceFormatCount, pSurfaceFormats,
                                VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR, true, false, false, "VUID-VkSurfaceFormat2KHR-sType-sType",
                                "VUID-vkGetPhysicalDeviceSurfaceFormats2KHR-pSurfaceFormats-parameter", kVUIDUndefined);
    if (pSurfaceFormats != nullptr) {
        for (uint32_t pSurfaceFormatIndex = 0; pSurfaceFormatIndex < *pSurfaceFormatCount; ++pSurfaceFormatIndex) {
            [[maybe_unused]] const Location pSurfaceFormats_loc = loc.dot(Field::pSurfaceFormats, pSurfaceFormatIndex);
            skip |= ValidateStructPnext(pSurfaceFormats_loc, pSurfaceFormats[pSurfaceFormatIndex].pNext, 0, nullptr,
                                        GeneratedVulkanHeaderVersion, "VUID-VkSurfaceFormat2KHR-pNext-pNext", kVUIDUndefined, true,
                                        false);
        }
    }
    if (!skip)
        skip |= manual_PreCallValidateGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount,
                                                                          pSurfaceFormats, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice,
                                                                                uint32_t* pPropertyCount,
                                                                                VkDisplayProperties2KHR* pProperties,
                                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_get_display_properties2) skip |= OutputExtensionError(loc, "VK_KHR_get_display_properties2");
    skip |= ValidateStructTypeArray(
        loc.dot(Field::pPropertyCount), loc.dot(Field::pProperties), "VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR", pPropertyCount,
        pProperties, VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR, true, false, false, "VUID-VkDisplayProperties2KHR-sType-sType",
        "VUID-vkGetPhysicalDeviceDisplayProperties2KHR-pProperties-parameter", kVUIDUndefined);
    if (pProperties != nullptr) {
        for (uint32_t pPropertyIndex = 0; pPropertyIndex < *pPropertyCount; ++pPropertyIndex) {
            [[maybe_unused]] const Location pProperties_loc = loc.dot(Field::pProperties, pPropertyIndex);
            skip |=
                ValidateStructPnext(pProperties_loc, pProperties[pPropertyIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDisplayProperties2KHR-pNext-pNext", kVUIDUndefined, true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice,
                                                                                     uint32_t* pPropertyCount,
                                                                                     VkDisplayPlaneProperties2KHR* pProperties,
                                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_get_display_properties2) skip |= OutputExtensionError(loc, "VK_KHR_get_display_properties2");
    skip |= ValidateStructTypeArray(loc.dot(Field::pPropertyCount), loc.dot(Field::pProperties),
                                    "VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR", pPropertyCount, pProperties,
                                    VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR, true, false, false,
                                    "VUID-VkDisplayPlaneProperties2KHR-sType-sType",
                                    "VUID-vkGetPhysicalDeviceDisplayPlaneProperties2KHR-pProperties-parameter", kVUIDUndefined);
    if (pProperties != nullptr) {
        for (uint32_t pPropertyIndex = 0; pPropertyIndex < *pPropertyCount; ++pPropertyIndex) {
            [[maybe_unused]] const Location pProperties_loc = loc.dot(Field::pProperties, pPropertyIndex);
            skip |=
                ValidateStructPnext(pProperties_loc, pProperties[pPropertyIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDisplayPlaneProperties2KHR-pNext-pNext", kVUIDUndefined, true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                                      uint32_t* pPropertyCount,
                                                                      VkDisplayModeProperties2KHR* pProperties,
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_get_display_properties2) skip |= OutputExtensionError(loc, "VK_KHR_get_display_properties2");
    skip |= ValidateRequiredHandle(loc.dot(Field::display), display);
    skip |= ValidateStructTypeArray(loc.dot(Field::pPropertyCount), loc.dot(Field::pProperties),
                                    "VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR", pPropertyCount, pProperties,
                                    VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR, true, false, false,
                                    "VUID-VkDisplayModeProperties2KHR-sType-sType",
                                    "VUID-vkGetDisplayModeProperties2KHR-pProperties-parameter", kVUIDUndefined);
    if (pProperties != nullptr) {
        for (uint32_t pPropertyIndex = 0; pPropertyIndex < *pPropertyCount; ++pPropertyIndex) {
            [[maybe_unused]] const Location pProperties_loc = loc.dot(Field::pProperties, pPropertyIndex);
            skip |=
                ValidateStructPnext(pProperties_loc, pProperties[pPropertyIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDisplayModeProperties2KHR-pNext-pNext", kVUIDUndefined, true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice,
                                                                         const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo,
                                                                         VkDisplayPlaneCapabilities2KHR* pCapabilities,
                                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_khr_get_display_properties2) skip |= OutputExtensionError(loc, "VK_KHR_get_display_properties2");
    skip |= ValidateStructType(loc.dot(Field::pDisplayPlaneInfo), "VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR", pDisplayPlaneInfo,
                               VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR, true,
                               "VUID-vkGetDisplayPlaneCapabilities2KHR-pDisplayPlaneInfo-parameter",
                               "VUID-VkDisplayPlaneInfo2KHR-sType-sType");
    if (pDisplayPlaneInfo != nullptr) {
        [[maybe_unused]] const Location pDisplayPlaneInfo_loc = loc.dot(Field::pDisplayPlaneInfo);
        skip |= ValidateStructPnext(pDisplayPlaneInfo_loc, pDisplayPlaneInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDisplayPlaneInfo2KHR-pNext-pNext", kVUIDUndefined, true, true);

        skip |= ValidateRequiredHandle(pDisplayPlaneInfo_loc.dot(Field::mode), pDisplayPlaneInfo->mode);
    }
    skip |= ValidateStructType(loc.dot(Field::pCapabilities), "VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR", pCapabilities,
                               VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR, true,
                               "VUID-vkGetDisplayPlaneCapabilities2KHR-pCapabilities-parameter",
                               "VUID-VkDisplayPlaneCapabilities2KHR-sType-sType");
    if (pCapabilities != nullptr) {
        [[maybe_unused]] const Location pCapabilities_loc = loc.dot(Field::pCapabilities);
        skip |= ValidateStructPnext(pCapabilities_loc, pCapabilities->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDisplayPlaneCapabilities2KHR-pNext-pNext", kVUIDUndefined, true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceFragmentShadingRatesKHR(
    VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount,
    VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |=
        ValidateStructTypeArray(loc.dot(Field::pFragmentShadingRateCount), loc.dot(Field::pFragmentShadingRates),
                                "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR", pFragmentShadingRateCount,
                                pFragmentShadingRates, VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR, true, false,
                                false, "VUID-VkPhysicalDeviceFragmentShadingRateKHR-sType-sType",
                                "VUID-vkGetPhysicalDeviceFragmentShadingRatesKHR-pFragmentShadingRates-parameter", kVUIDUndefined);
    if (pFragmentShadingRates != nullptr) {
        for (uint32_t pFragmentShadingRateIndex = 0; pFragmentShadingRateIndex < *pFragmentShadingRateCount;
             ++pFragmentShadingRateIndex) {
            [[maybe_unused]] const Location pFragmentShadingRates_loc =
                loc.dot(Field::pFragmentShadingRates, pFragmentShadingRateIndex);
            skip |= ValidateStructPnext(pFragmentShadingRates_loc, pFragmentShadingRates[pFragmentShadingRateIndex].pNext, 0,
                                        nullptr, GeneratedVulkanHeaderVersion,
                                        "VUID-VkPhysicalDeviceFragmentShadingRateKHR-pNext-pNext", kVUIDUndefined, true, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer,
                                                                      const VkExtent2D* pFragmentSize,
                                                                      const VkFragmentShadingRateCombinerOpKHR combinerOps[2],
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_fragment_shading_rate))
        skip |= OutputExtensionError(loc, "VK_KHR_fragment_shading_rate");
    skip |= ValidateRequiredPointer(loc.dot(Field::pFragmentSize), pFragmentSize,
                                    "VUID-vkCmdSetFragmentShadingRateKHR-pFragmentSize-parameter");
    if (pFragmentSize != nullptr) {
        [[maybe_unused]] const Location pFragmentSize_loc = loc.dot(Field::pFragmentSize);
        // No xml-driven validation
    }
    skip |= ValidateRangedEnumArray(loc, loc.dot(Field::combinerOps), "VkFragmentShadingRateCombinerOpKHR", 2, combinerOps, false,
                                    true);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdRefreshObjectsKHR(VkCommandBuffer commandBuffer,
                                                              const VkRefreshObjectListKHR* pRefreshObjects,
                                                              const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_object_refresh)) skip |= OutputExtensionError(loc, "VK_KHR_object_refresh");
    skip |= ValidateStructType(loc.dot(Field::pRefreshObjects), "VK_STRUCTURE_TYPE_REFRESH_OBJECT_LIST_KHR", pRefreshObjects,
                               VK_STRUCTURE_TYPE_REFRESH_OBJECT_LIST_KHR, true,
                               "VUID-vkCmdRefreshObjectsKHR-pRefreshObjects-parameter", "VUID-VkRefreshObjectListKHR-sType-sType");
    if (pRefreshObjects != nullptr) {
        [[maybe_unused]] const Location pRefreshObjects_loc = loc.dot(Field::pRefreshObjects);
        skip |= ValidateStructPnext(pRefreshObjects_loc, pRefreshObjects->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkRefreshObjectListKHR-pNext-pNext", kVUIDUndefined, false, true);

        skip |=
            ValidateArray(pRefreshObjects_loc.dot(Field::objectCount), pRefreshObjects_loc.dot(Field::pObjects),
                          pRefreshObjects->objectCount, &pRefreshObjects->pObjects, true, true,
                          "VUID-VkRefreshObjectListKHR-objectCount-arraylength", "VUID-VkRefreshObjectListKHR-pObjects-parameter");

        if (pRefreshObjects->pObjects != nullptr) {
            for (uint32_t objectIndex = 0; objectIndex < pRefreshObjects->objectCount; ++objectIndex) {
                [[maybe_unused]] const Location pObjects_loc = pRefreshObjects_loc.dot(Field::pObjects, objectIndex);
                skip |= ValidateRangedEnum(pObjects_loc.dot(Field::objectType), "VkObjectType",
                                           pRefreshObjects->pObjects[objectIndex].objectType,
                                           "VUID-VkRefreshObjectKHR-objectType-parameter");

                skip |= ValidateReservedFlags(pObjects_loc.dot(Field::flags), pRefreshObjects->pObjects[objectIndex].flags,
                                              "VUID-VkRefreshObjectKHR-flags-zerobitmask");
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceRefreshableObjectTypesKHR(VkPhysicalDevice physicalDevice,
                                                                                    uint32_t* pRefreshableObjectTypeCount,
                                                                                    VkObjectType* pRefreshableObjectTypes,
                                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateArray(loc.dot(Field::pRefreshableObjectTypeCount), loc.dot(Field::pRefreshableObjectTypes),
                          pRefreshableObjectTypeCount, &pRefreshableObjectTypes, true, false, false, kVUIDUndefined,
                          "VUID-vkGetPhysicalDeviceRefreshableObjectTypesKHR-pRefreshableObjectTypes-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                                         const VkDependencyInfo* pDependencyInfo,
                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_synchronization2)) skip |= OutputExtensionError(loc, "VK_KHR_synchronization2");
    skip |= PreCallValidateCmdSetEvent2(commandBuffer, event, pDependencyInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                                           VkPipelineStageFlags2 stageMask, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_synchronization2)) skip |= OutputExtensionError(loc, "VK_KHR_synchronization2");
    skip |= PreCallValidateCmdResetEvent2(commandBuffer, event, stageMask, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount,
                                                           const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_synchronization2)) skip |= OutputExtensionError(loc, "VK_KHR_synchronization2");
    skip |= PreCallValidateCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer,
                                                                const VkDependencyInfo* pDependencyInfo,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_synchronization2)) skip |= OutputExtensionError(loc, "VK_KHR_synchronization2");
    skip |= PreCallValidateCmdPipelineBarrier2(commandBuffer, pDependencyInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                               VkQueryPool queryPool, uint32_t query,
                                                               const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_synchronization2)) skip |= OutputExtensionError(loc, "VK_KHR_synchronization2");
    skip |= PreCallValidateCmdWriteTimestamp2(commandBuffer, stage, queryPool, query, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateQueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits,
                                                         VkFence fence, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_synchronization2)) skip |= OutputExtensionError(loc, "VK_KHR_synchronization2");
    skip |= PreCallValidateQueueSubmit2(queue, submitCount, pSubmits, fence, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                                  VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_synchronization2)) skip |= OutputExtensionError(loc, "VK_KHR_synchronization2");
    skip |= ValidateFlags(loc.dot(Field::stage), "VkPipelineStageFlagBits2", AllVkPipelineStageFlagBits2, stage, kOptionalFlags,
                          kVUIDUndefined);
    skip |= ValidateRequiredHandle(loc.dot(Field::dstBuffer), dstBuffer);
    return skip;
}

bool StatelessValidation::PreCallValidateGetQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount,
                                                                   VkCheckpointData2NV* pCheckpointData,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_synchronization2)) skip |= OutputExtensionError(loc, "VK_KHR_synchronization2");
    skip |= ValidateStructTypeArray(loc.dot(Field::pCheckpointDataCount), loc.dot(Field::pCheckpointData),
                                    "VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV", pCheckpointDataCount, pCheckpointData,
                                    VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV, true, false, false, kVUIDUndefined, kVUIDUndefined,
                                    kVUIDUndefined);
    if (pCheckpointData != nullptr) {
        for (uint32_t pCheckpointDataIndex = 0; pCheckpointDataIndex < *pCheckpointDataCount; ++pCheckpointDataIndex) {
            [[maybe_unused]] const Location pCheckpointData_loc = loc.dot(Field::pCheckpointData, pCheckpointDataIndex);
            skip |= ValidateStructPnext(pCheckpointData_loc, pCheckpointData[pCheckpointDataIndex].pNext, 0, nullptr,
                                        GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, false);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_copy_commands2)) skip |= OutputExtensionError(loc, "VK_KHR_copy_commands2");
    skip |= PreCallValidateCmdCopyBuffer2(commandBuffer, pCopyBufferInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_copy_commands2)) skip |= OutputExtensionError(loc, "VK_KHR_copy_commands2");
    skip |= PreCallValidateCmdCopyImage2(commandBuffer, pCopyImageInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                                                  const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_copy_commands2)) skip |= OutputExtensionError(loc, "VK_KHR_copy_commands2");
    skip |= PreCallValidateCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                                                  const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_copy_commands2)) skip |= OutputExtensionError(loc, "VK_KHR_copy_commands2");
    skip |= PreCallValidateCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_copy_commands2)) skip |= OutputExtensionError(loc, "VK_KHR_copy_commands2");
    skip |= PreCallValidateCmdBlitImage2(commandBuffer, pBlitImageInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdResolveImage2KHR(VkCommandBuffer commandBuffer,
                                                             const VkResolveImageInfo2* pResolveImageInfo,
                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_khr_copy_commands2)) skip |= OutputExtensionError(loc, "VK_KHR_copy_commands2");
    skip |= PreCallValidateCmdResolveImage2(commandBuffer, pResolveImageInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_direct_mode_display) skip |= OutputExtensionError(loc, "VK_EXT_direct_mode_display");
    skip |= ValidateRequiredHandle(loc.dot(Field::display), display);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice,
                                                                                  VkSurfaceKHR surface,
                                                                                  VkSurfaceCapabilities2EXT* pSurfaceCapabilities,
                                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_display_surface_counter) skip |= OutputExtensionError(loc, "VK_EXT_display_surface_counter");
    skip |= ValidateRequiredHandle(loc.dot(Field::surface), surface);
    skip |= ValidateStructType(loc.dot(Field::pSurfaceCapabilities), "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT",
                               pSurfaceCapabilities, VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT, true,
                               "VUID-vkGetPhysicalDeviceSurfaceCapabilities2EXT-pSurfaceCapabilities-parameter",
                               "VUID-VkSurfaceCapabilities2EXT-sType-sType");
    if (pSurfaceCapabilities != nullptr) {
        [[maybe_unused]] const Location pSurfaceCapabilities_loc = loc.dot(Field::pSurfaceCapabilities);
        skip |= ValidateStructPnext(pSurfaceCapabilities_loc, pSurfaceCapabilities->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkSurfaceCapabilities2EXT-pNext-pNext", kVUIDUndefined, true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display,
                                                                const VkDisplayPowerInfoEXT* pDisplayPowerInfo,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_display_control)) skip |= OutputExtensionError(loc, "VK_EXT_display_control");
    skip |= ValidateRequiredHandle(loc.dot(Field::display), display);
    skip |=
        ValidateStructType(loc.dot(Field::pDisplayPowerInfo), "VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT", pDisplayPowerInfo,
                           VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT, true,
                           "VUID-vkDisplayPowerControlEXT-pDisplayPowerInfo-parameter", "VUID-VkDisplayPowerInfoEXT-sType-sType");
    if (pDisplayPowerInfo != nullptr) {
        [[maybe_unused]] const Location pDisplayPowerInfo_loc = loc.dot(Field::pDisplayPowerInfo);
        skip |= ValidateStructPnext(pDisplayPowerInfo_loc, pDisplayPowerInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDisplayPowerInfoEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum(pDisplayPowerInfo_loc.dot(Field::powerState), "VkDisplayPowerStateEXT",
                                   pDisplayPowerInfo->powerState, "VUID-VkDisplayPowerInfoEXT-powerState-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo,
                                                                const VkAllocationCallbacks* pAllocator, VkFence* pFence,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_display_control)) skip |= OutputExtensionError(loc, "VK_EXT_display_control");
    skip |= ValidateStructType(loc.dot(Field::pDeviceEventInfo), "VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT", pDeviceEventInfo,
                               VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT, true,
                               "VUID-vkRegisterDeviceEventEXT-pDeviceEventInfo-parameter", "VUID-VkDeviceEventInfoEXT-sType-sType");
    if (pDeviceEventInfo != nullptr) {
        [[maybe_unused]] const Location pDeviceEventInfo_loc = loc.dot(Field::pDeviceEventInfo);
        skip |= ValidateStructPnext(pDeviceEventInfo_loc, pDeviceEventInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDeviceEventInfoEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum(pDeviceEventInfo_loc.dot(Field::deviceEvent), "VkDeviceEventTypeEXT",
                                   pDeviceEventInfo->deviceEvent, "VUID-VkDeviceEventInfoEXT-deviceEvent-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkRegisterDeviceEventEXT-pAllocator-null",
                         "vkRegisterDeviceEventEXT(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pFence), pFence, "VUID-vkRegisterDeviceEventEXT-pFence-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display,
                                                                 const VkDisplayEventInfoEXT* pDisplayEventInfo,
                                                                 const VkAllocationCallbacks* pAllocator, VkFence* pFence,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_display_control)) skip |= OutputExtensionError(loc, "VK_EXT_display_control");
    skip |= ValidateRequiredHandle(loc.dot(Field::display), display);
    skip |=
        ValidateStructType(loc.dot(Field::pDisplayEventInfo), "VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT", pDisplayEventInfo,
                           VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT, true,
                           "VUID-vkRegisterDisplayEventEXT-pDisplayEventInfo-parameter", "VUID-VkDisplayEventInfoEXT-sType-sType");
    if (pDisplayEventInfo != nullptr) {
        [[maybe_unused]] const Location pDisplayEventInfo_loc = loc.dot(Field::pDisplayEventInfo);
        skip |= ValidateStructPnext(pDisplayEventInfo_loc, pDisplayEventInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDisplayEventInfoEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum(pDisplayEventInfo_loc.dot(Field::displayEvent), "VkDisplayEventTypeEXT",
                                   pDisplayEventInfo->displayEvent, "VUID-VkDisplayEventInfoEXT-displayEvent-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkRegisterDisplayEventEXT-pAllocator-null",
                         "vkRegisterDisplayEventEXT(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pFence), pFence, "VUID-vkRegisterDisplayEventEXT-pFence-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain,
                                                                VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_display_control)) skip |= OutputExtensionError(loc, "VK_EXT_display_control");
    skip |= ValidateRequiredHandle(loc.dot(Field::swapchain), swapchain);
    skip |= ValidateFlags(loc.dot(Field::counter), "VkSurfaceCounterFlagBitsEXT", AllVkSurfaceCounterFlagBitsEXT, counter,
                          kRequiredSingleBit, "VUID-vkGetSwapchainCounterEXT-counter-parameter",
                          "VUID-vkGetSwapchainCounterEXT-counter-parameter");
    skip |= ValidateRequiredPointer(loc.dot(Field::pCounterValue), pCounterValue,
                                    "VUID-vkGetSwapchainCounterEXT-pCounterValue-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                                                   uint32_t discardRectangleCount,
                                                                   const VkRect2D* pDiscardRectangles,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_discard_rectangles)) skip |= OutputExtensionError(loc, "VK_EXT_discard_rectangles");
    skip |= ValidateArray(loc.dot(Field::discardRectangleCount), loc.dot(Field::pDiscardRectangles), discardRectangleCount,
                          &pDiscardRectangles, true, true, "VUID-vkCmdSetDiscardRectangleEXT-discardRectangleCount-arraylength",
                          "VUID-vkCmdSetDiscardRectangleEXT-pDiscardRectangles-parameter");
    if (pDiscardRectangles != nullptr) {
        for (uint32_t discardRectangleIndex = 0; discardRectangleIndex < discardRectangleCount; ++discardRectangleIndex) {
            [[maybe_unused]] const Location pDiscardRectangles_loc = loc.dot(Field::pDiscardRectangles, discardRectangleIndex);
            // No xml-driven validation

            // No xml-driven validation
        }
    }
    if (!skip)
        skip |= manual_PreCallValidateCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                                                pDiscardRectangles, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer,
                                                                         VkBool32 discardRectangleEnable,
                                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_discard_rectangles)) skip |= OutputExtensionError(loc, "VK_EXT_discard_rectangles");
    skip |= ValidateBool32(loc.dot(Field::discardRectangleEnable), discardRectangleEnable);
    if (!skip) skip |= manual_PreCallValidateCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                                                       VkDiscardRectangleModeEXT discardRectangleMode,
                                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_discard_rectangles)) skip |= OutputExtensionError(loc, "VK_EXT_discard_rectangles");
    skip |= ValidateRangedEnum(loc.dot(Field::discardRectangleMode), "VkDiscardRectangleModeEXT", discardRectangleMode,
                               "VUID-vkCmdSetDiscardRectangleModeEXT-discardRectangleMode-parameter");
    if (!skip) skip |= manual_PreCallValidateCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount,
                                                           const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_hdr_metadata)) skip |= OutputExtensionError(loc, "VK_EXT_hdr_metadata");
    skip |= ValidateHandleArray(loc.dot(Field::swapchainCount), loc.dot(Field::pSwapchains), swapchainCount, pSwapchains, true,
                                true, "VUID-vkSetHdrMetadataEXT-swapchainCount-arraylength");
    skip |= ValidateStructTypeArray(loc.dot(Field::swapchainCount), loc.dot(Field::pMetadata), "VK_STRUCTURE_TYPE_HDR_METADATA_EXT",
                                    swapchainCount, pMetadata, VK_STRUCTURE_TYPE_HDR_METADATA_EXT, true, true,
                                    "VUID-VkHdrMetadataEXT-sType-sType", "VUID-vkSetHdrMetadataEXT-pMetadata-parameter",
                                    "VUID-vkSetHdrMetadataEXT-swapchainCount-arraylength");
    if (pMetadata != nullptr) {
        for (uint32_t swapchainIndex = 0; swapchainIndex < swapchainCount; ++swapchainIndex) {
            [[maybe_unused]] const Location pMetadata_loc = loc.dot(Field::pMetadata, swapchainIndex);
            skip |= ValidateStructPnext(pMetadata_loc, pMetadata[swapchainIndex].pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                        "VUID-VkHdrMetadataEXT-pNext-pNext", kVUIDUndefined, false, true);
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError(loc, "VK_EXT_debug_utils");
    skip |= ValidateStructType(loc.dot(Field::pNameInfo), "VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT", pNameInfo,
                               VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT, true,
                               "VUID-vkSetDebugUtilsObjectNameEXT-pNameInfo-parameter",
                               "VUID-VkDebugUtilsObjectNameInfoEXT-sType-sType");
    if (pNameInfo != nullptr) {
        [[maybe_unused]] const Location pNameInfo_loc = loc.dot(Field::pNameInfo);
        skip |= ValidateStructPnext(pNameInfo_loc, pNameInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined,
                                    kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum(pNameInfo_loc.dot(Field::objectType), "VkObjectType", pNameInfo->objectType,
                                   "VUID-VkDebugUtilsObjectNameInfoEXT-objectType-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateSetDebugUtilsObjectNameEXT(device, pNameInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError(loc, "VK_EXT_debug_utils");
    skip |=
        ValidateStructType(loc.dot(Field::pTagInfo), "VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT", pTagInfo,
                           VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT, true,
                           "VUID-vkSetDebugUtilsObjectTagEXT-pTagInfo-parameter", "VUID-VkDebugUtilsObjectTagInfoEXT-sType-sType");
    if (pTagInfo != nullptr) {
        [[maybe_unused]] const Location pTagInfo_loc = loc.dot(Field::pTagInfo);
        skip |= ValidateStructPnext(pTagInfo_loc, pTagInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDebugUtilsObjectTagInfoEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRangedEnum(pTagInfo_loc.dot(Field::objectType), "VkObjectType", pTagInfo->objectType,
                                   "VUID-VkDebugUtilsObjectTagInfoEXT-objectType-parameter");

        skip |= ValidateArray(pTagInfo_loc.dot(Field::tagSize), pTagInfo_loc.dot(Field::pTag), pTagInfo->tagSize, &pTagInfo->pTag,
                              true, true, "VUID-VkDebugUtilsObjectTagInfoEXT-tagSize-arraylength",
                              "VUID-VkDebugUtilsObjectTagInfoEXT-pTag-parameter");
    }
    if (!skip) skip |= manual_PreCallValidateSetDebugUtilsObjectTagEXT(device, pTagInfo, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateQueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo,
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError(loc, "VK_EXT_debug_utils");
    skip |= ValidateStructType(loc.dot(Field::pLabelInfo), "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT", pLabelInfo,
                               VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, true,
                               "VUID-vkQueueBeginDebugUtilsLabelEXT-pLabelInfo-parameter", "VUID-VkDebugUtilsLabelEXT-sType-sType");
    if (pLabelInfo != nullptr) {
        [[maybe_unused]] const Location pLabelInfo_loc = loc.dot(Field::pLabelInfo);
        skip |= ValidateStructPnext(pLabelInfo_loc, pLabelInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDebugUtilsLabelEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredPointer(pLabelInfo_loc.dot(Field::pLabelName), pLabelInfo->pLabelName,
                                        "VUID-VkDebugUtilsLabelEXT-pLabelName-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateQueueEndDebugUtilsLabelEXT(VkQueue queue, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError(loc, "VK_EXT_debug_utils");
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateQueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo,
                                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError(loc, "VK_EXT_debug_utils");
    skip |= ValidateStructType(
        loc.dot(Field::pLabelInfo), "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT", pLabelInfo, VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT,
        true, "VUID-vkQueueInsertDebugUtilsLabelEXT-pLabelInfo-parameter", "VUID-VkDebugUtilsLabelEXT-sType-sType");
    if (pLabelInfo != nullptr) {
        [[maybe_unused]] const Location pLabelInfo_loc = loc.dot(Field::pLabelInfo);
        skip |= ValidateStructPnext(pLabelInfo_loc, pLabelInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDebugUtilsLabelEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredPointer(pLabelInfo_loc.dot(Field::pLabelName), pLabelInfo->pLabelName,
                                        "VUID-VkDebugUtilsLabelEXT-pLabelName-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                                    const VkDebugUtilsLabelEXT* pLabelInfo,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError(loc, "VK_EXT_debug_utils");
    skip |= ValidateStructType(loc.dot(Field::pLabelInfo), "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT", pLabelInfo,
                               VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, true,
                               "VUID-vkCmdBeginDebugUtilsLabelEXT-pLabelInfo-parameter", "VUID-VkDebugUtilsLabelEXT-sType-sType");
    if (pLabelInfo != nullptr) {
        [[maybe_unused]] const Location pLabelInfo_loc = loc.dot(Field::pLabelInfo);
        skip |= ValidateStructPnext(pLabelInfo_loc, pLabelInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDebugUtilsLabelEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredPointer(pLabelInfo_loc.dot(Field::pLabelName), pLabelInfo->pLabelName,
                                        "VUID-VkDebugUtilsLabelEXT-pLabelName-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError(loc, "VK_EXT_debug_utils");
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                                     const VkDebugUtilsLabelEXT* pLabelInfo,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError(loc, "VK_EXT_debug_utils");
    skip |= ValidateStructType(loc.dot(Field::pLabelInfo), "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT", pLabelInfo,
                               VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, true,
                               "VUID-vkCmdInsertDebugUtilsLabelEXT-pLabelInfo-parameter", "VUID-VkDebugUtilsLabelEXT-sType-sType");
    if (pLabelInfo != nullptr) {
        [[maybe_unused]] const Location pLabelInfo_loc = loc.dot(Field::pLabelInfo);
        skip |= ValidateStructPnext(pLabelInfo_loc, pLabelInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDebugUtilsLabelEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredPointer(pLabelInfo_loc.dot(Field::pLabelName), pLabelInfo->pLabelName,
                                        "VUID-VkDebugUtilsLabelEXT-pLabelName-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCreateDebugUtilsMessengerEXT(VkInstance instance,
                                                                      const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                                      const VkAllocationCallbacks* pAllocator,
                                                                      VkDebugUtilsMessengerEXT* pMessenger,
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError(loc, "VK_EXT_debug_utils");
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT", pCreateInfo,
                               VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT, true,
                               "VUID-vkCreateDebugUtilsMessengerEXT-pCreateInfo-parameter",
                               "VUID-VkDebugUtilsMessengerCreateInfoEXT-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion, kVUIDUndefined,
                                    kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkDebugUtilsMessengerCreateInfoEXT-flags-zerobitmask");

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::messageSeverity), "VkDebugUtilsMessageSeverityFlagBitsEXT",
                              AllVkDebugUtilsMessageSeverityFlagBitsEXT, pCreateInfo->messageSeverity, kRequiredFlags,
                              "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageSeverity-parameter",
                              "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageSeverity-requiredbitmask");

        skip |= ValidateFlags(pCreateInfo_loc.dot(Field::messageType), "VkDebugUtilsMessageTypeFlagBitsEXT",
                              AllVkDebugUtilsMessageTypeFlagBitsEXT, pCreateInfo->messageType, kRequiredFlags,
                              "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageType-parameter",
                              "VUID-VkDebugUtilsMessengerCreateInfoEXT-messageType-requiredbitmask");

        skip |= ValidateRequiredPointer(pCreateInfo_loc.dot(Field::pfnUserCallback),
                                        reinterpret_cast<const void*>(pCreateInfo->pfnUserCallback),
                                        "VUID-VkDebugUtilsMessengerCreateInfoEXT-pfnUserCallback-parameter");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateDebugUtilsMessengerEXT-pAllocator-null",
                         "vkCreateDebugUtilsMessengerEXT(): pAllocator must be NULL");
    }
    skip |=
        ValidateRequiredPointer(loc.dot(Field::pMessenger), pMessenger, "VUID-vkCreateDebugUtilsMessengerEXT-pMessenger-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                                                       const VkAllocationCallbacks* pAllocator,
                                                                       const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError(loc, "VK_EXT_debug_utils");
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkDestroyDebugUtilsMessengerEXT-pAllocator-null",
                         "vkDestroyDebugUtilsMessengerEXT(): pAllocator must be NULL");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateSubmitDebugUtilsMessageEXT(VkInstance instance,
                                                                    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                                    VkDebugUtilsMessageTypeFlagsEXT messageTypes,
                                                                    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_debug_utils) skip |= OutputExtensionError(loc, "VK_EXT_debug_utils");
    skip |= ValidateFlags(loc.dot(Field::messageSeverity), "VkDebugUtilsMessageSeverityFlagBitsEXT",
                          AllVkDebugUtilsMessageSeverityFlagBitsEXT, messageSeverity, kRequiredSingleBit,
                          "VUID-vkSubmitDebugUtilsMessageEXT-messageSeverity-parameter",
                          "VUID-vkSubmitDebugUtilsMessageEXT-messageSeverity-parameter");
    skip |= ValidateFlags(loc.dot(Field::messageTypes), "VkDebugUtilsMessageTypeFlagBitsEXT", AllVkDebugUtilsMessageTypeFlagBitsEXT,
                          messageTypes, kRequiredFlags, "VUID-vkSubmitDebugUtilsMessageEXT-messageTypes-parameter",
                          "VUID-vkSubmitDebugUtilsMessageEXT-messageTypes-requiredbitmask");
    skip |= ValidateStructType(loc.dot(Field::pCallbackData), "VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT",
                               pCallbackData, VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT, true,
                               "VUID-vkSubmitDebugUtilsMessageEXT-pCallbackData-parameter",
                               "VUID-VkDebugUtilsMessengerCallbackDataEXT-sType-sType");
    if (pCallbackData != nullptr) {
        [[maybe_unused]] const Location pCallbackData_loc = loc.dot(Field::pCallbackData);
        skip |= ValidateStructPnext(pCallbackData_loc, pCallbackData->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkDebugUtilsMessengerCallbackDataEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags(pCallbackData_loc.dot(Field::flags), pCallbackData->flags,
                                      "VUID-VkDebugUtilsMessengerCallbackDataEXT-flags-zerobitmask");

        skip |= ValidateRequiredPointer(pCallbackData_loc.dot(Field::pMessage), pCallbackData->pMessage,
                                        "VUID-VkDebugUtilsMessengerCallbackDataEXT-pMessage-parameter");

        skip |= ValidateStructTypeArray(pCallbackData_loc.dot(Field::queueLabelCount), pCallbackData_loc.dot(Field::pQueueLabels),
                                        "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT", pCallbackData->queueLabelCount,
                                        pCallbackData->pQueueLabels, VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, false, true,
                                        "VUID-VkDebugUtilsLabelEXT-sType-sType",
                                        "VUID-VkDebugUtilsMessengerCallbackDataEXT-pQueueLabels-parameter", kVUIDUndefined);

        if (pCallbackData->pQueueLabels != nullptr) {
            for (uint32_t queueLabelIndex = 0; queueLabelIndex < pCallbackData->queueLabelCount; ++queueLabelIndex) {
                [[maybe_unused]] const Location pQueueLabels_loc = pCallbackData_loc.dot(Field::pQueueLabels, queueLabelIndex);
                skip |= ValidateStructPnext(pQueueLabels_loc, pCallbackData->pQueueLabels[queueLabelIndex].pNext, 0, nullptr,
                                            GeneratedVulkanHeaderVersion, "VUID-VkDebugUtilsLabelEXT-pNext-pNext", kVUIDUndefined,
                                            false, true);

                skip |= ValidateRequiredPointer(pQueueLabels_loc.dot(Field::pLabelName),
                                                pCallbackData->pQueueLabels[queueLabelIndex].pLabelName,
                                                "VUID-VkDebugUtilsLabelEXT-pLabelName-parameter");
            }
        }

        skip |= ValidateStructTypeArray(pCallbackData_loc.dot(Field::cmdBufLabelCount), pCallbackData_loc.dot(Field::pCmdBufLabels),
                                        "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT", pCallbackData->cmdBufLabelCount,
                                        pCallbackData->pCmdBufLabels, VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, false, true,
                                        "VUID-VkDebugUtilsLabelEXT-sType-sType",
                                        "VUID-VkDebugUtilsMessengerCallbackDataEXT-pCmdBufLabels-parameter", kVUIDUndefined);

        if (pCallbackData->pCmdBufLabels != nullptr) {
            for (uint32_t cmdBufLabelIndex = 0; cmdBufLabelIndex < pCallbackData->cmdBufLabelCount; ++cmdBufLabelIndex) {
                [[maybe_unused]] const Location pCmdBufLabels_loc = pCallbackData_loc.dot(Field::pCmdBufLabels, cmdBufLabelIndex);
                skip |= ValidateStructPnext(pCmdBufLabels_loc, pCallbackData->pCmdBufLabels[cmdBufLabelIndex].pNext, 0, nullptr,
                                            GeneratedVulkanHeaderVersion, "VUID-VkDebugUtilsLabelEXT-pNext-pNext", kVUIDUndefined,
                                            false, true);

                skip |= ValidateRequiredPointer(pCmdBufLabels_loc.dot(Field::pLabelName),
                                                pCallbackData->pCmdBufLabels[cmdBufLabelIndex].pLabelName,
                                                "VUID-VkDebugUtilsLabelEXT-pLabelName-parameter");
            }
        }

        skip |= ValidateStructTypeArray(pCallbackData_loc.dot(Field::objectCount), pCallbackData_loc.dot(Field::pObjects),
                                        "VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT", pCallbackData->objectCount,
                                        pCallbackData->pObjects, VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT, false, true,
                                        "VUID-VkDebugUtilsObjectNameInfoEXT-sType-sType",
                                        "VUID-VkDebugUtilsMessengerCallbackDataEXT-pObjects-parameter", kVUIDUndefined);

        if (pCallbackData->pObjects != nullptr) {
            for (uint32_t objectIndex = 0; objectIndex < pCallbackData->objectCount; ++objectIndex) {
                [[maybe_unused]] const Location pObjects_loc = pCallbackData_loc.dot(Field::pObjects, objectIndex);
                skip |= ValidateStructPnext(pObjects_loc, pCallbackData->pObjects[objectIndex].pNext, 0, nullptr,
                                            GeneratedVulkanHeaderVersion, kVUIDUndefined, kVUIDUndefined, false, true);

                skip |= ValidateRangedEnum(pObjects_loc.dot(Field::objectType), "VkObjectType",
                                           pCallbackData->pObjects[objectIndex].objectType,
                                           "VUID-VkDebugUtilsObjectNameInfoEXT-objectType-parameter");
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                                                  const VkSampleLocationsInfoEXT* pSampleLocationsInfo,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_sample_locations)) skip |= OutputExtensionError(loc, "VK_EXT_sample_locations");
    skip |= ValidateStructType(loc.dot(Field::pSampleLocationsInfo), "VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT",
                               pSampleLocationsInfo, VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT, true,
                               "VUID-vkCmdSetSampleLocationsEXT-pSampleLocationsInfo-parameter",
                               "VUID-VkSampleLocationsInfoEXT-sType-sType");
    if (pSampleLocationsInfo != nullptr) {
        [[maybe_unused]] const Location pSampleLocationsInfo_loc = loc.dot(Field::pSampleLocationsInfo);
        skip |= ValidateStructPnext(pSampleLocationsInfo_loc, pSampleLocationsInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    kVUIDUndefined, kVUIDUndefined, false, true);

        // No xml-driven validation

        skip |= ValidateArray(pSampleLocationsInfo_loc.dot(Field::sampleLocationsCount),
                              pSampleLocationsInfo_loc.dot(Field::pSampleLocations), pSampleLocationsInfo->sampleLocationsCount,
                              &pSampleLocationsInfo->pSampleLocations, false, true, kVUIDUndefined,
                              "VUID-VkSampleLocationsInfoEXT-pSampleLocations-parameter");

        if (pSampleLocationsInfo->pSampleLocations != nullptr) {
            for (uint32_t sampleLocationsIndex = 0; sampleLocationsIndex < pSampleLocationsInfo->sampleLocationsCount;
                 ++sampleLocationsIndex) {
                [[maybe_unused]] const Location pSampleLocations_loc =
                    pSampleLocationsInfo_loc.dot(Field::pSampleLocations, sampleLocationsIndex);
                // No xml-driven validation
            }
        }
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceMultisamplePropertiesEXT(
    VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties,
    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateFlags(loc.dot(Field::samples), "VkSampleCountFlagBits", AllVkSampleCountFlagBits, samples, kRequiredSingleBit,
                          "VUID-vkGetPhysicalDeviceMultisamplePropertiesEXT-samples-parameter",
                          "VUID-vkGetPhysicalDeviceMultisamplePropertiesEXT-samples-parameter");
    skip |= ValidateStructType(loc.dot(Field::pMultisampleProperties), "VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT",
                               pMultisampleProperties, VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT, true,
                               "VUID-vkGetPhysicalDeviceMultisamplePropertiesEXT-pMultisampleProperties-parameter",
                               "VUID-VkMultisamplePropertiesEXT-sType-sType");
    if (pMultisampleProperties != nullptr) {
        [[maybe_unused]] const Location pMultisampleProperties_loc = loc.dot(Field::pMultisampleProperties);
        skip |=
            ValidateStructPnext(pMultisampleProperties_loc, pMultisampleProperties->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                "VUID-VkMultisamplePropertiesEXT-pNext-pNext", kVUIDUndefined, true, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image,
                                                                                VkImageDrmFormatModifierPropertiesEXT* pProperties,
                                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_image_drm_format_modifier))
        skip |= OutputExtensionError(loc, "VK_EXT_image_drm_format_modifier");
    skip |= ValidateRequiredHandle(loc.dot(Field::image), image);
    skip |= ValidateStructType(loc.dot(Field::pProperties), "VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT",
                               pProperties, VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT, true,
                               "VUID-vkGetImageDrmFormatModifierPropertiesEXT-pProperties-parameter",
                               "VUID-VkImageDrmFormatModifierPropertiesEXT-sType-sType");
    if (pProperties != nullptr) {
        [[maybe_unused]] const Location pProperties_loc = loc.dot(Field::pProperties);
        skip |= ValidateStructPnext(pProperties_loc, pProperties->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkImageDrmFormatModifierPropertiesEXT-pNext-pNext", kVUIDUndefined, false, false);
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetMemoryHostPointerPropertiesEXT(
    VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer,
    VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_external_memory_host))
        skip |= OutputExtensionError(loc, "VK_EXT_external_memory_host");
    skip |= ValidateFlags(loc.dot(Field::handleType), "VkExternalMemoryHandleTypeFlagBits", AllVkExternalMemoryHandleTypeFlagBits,
                          handleType, kRequiredSingleBit, "VUID-vkGetMemoryHostPointerPropertiesEXT-handleType-parameter",
                          "VUID-vkGetMemoryHostPointerPropertiesEXT-handleType-parameter");
    skip |= ValidateRequiredPointer(loc.dot(Field::pHostPointer), pHostPointer,
                                    "VUID-vkGetMemoryHostPointerPropertiesEXT-pHostPointer-parameter");
    skip |= ValidateStructType(loc.dot(Field::pMemoryHostPointerProperties), "VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT",
                               pMemoryHostPointerProperties, VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT, true,
                               "VUID-vkGetMemoryHostPointerPropertiesEXT-pMemoryHostPointerProperties-parameter",
                               "VUID-VkMemoryHostPointerPropertiesEXT-sType-sType");
    if (pMemoryHostPointerProperties != nullptr) {
        [[maybe_unused]] const Location pMemoryHostPointerProperties_loc = loc.dot(Field::pMemoryHostPointerProperties);
        skip |= ValidateStructPnext(pMemoryHostPointerProperties_loc, pMemoryHostPointerProperties->pNext, 0, nullptr,
                                    GeneratedVulkanHeaderVersion, "VUID-VkMemoryHostPointerPropertiesEXT-pNext-pNext",
                                    kVUIDUndefined, false, false);
    }
    if (!skip)
        skip |= manual_PreCallValidateGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer,
                                                                        pMemoryHostPointerProperties, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice,
                                                                                      uint32_t* pTimeDomainCount,
                                                                                      VkTimeDomainEXT* pTimeDomains,
                                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |=
        ValidateArray(loc.dot(Field::pTimeDomainCount), loc.dot(Field::pTimeDomains), pTimeDomainCount, &pTimeDomains, true, false,
                      false, kVUIDUndefined, "VUID-vkGetPhysicalDeviceCalibrateableTimeDomainsEXT-pTimeDomains-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount,
                                                                    const VkCalibratedTimestampInfoEXT* pTimestampInfos,
                                                                    uint64_t* pTimestamps, uint64_t* pMaxDeviation,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_calibrated_timestamps))
        skip |= OutputExtensionError(loc, "VK_EXT_calibrated_timestamps");
    skip |= ValidateStructTypeArray(
        loc.dot(Field::timestampCount), loc.dot(Field::pTimestampInfos), "VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT",
        timestampCount, pTimestampInfos, VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT, true, true,
        "VUID-VkCalibratedTimestampInfoEXT-sType-sType", "VUID-vkGetCalibratedTimestampsEXT-pTimestampInfos-parameter",
        "VUID-vkGetCalibratedTimestampsEXT-timestampCount-arraylength");
    if (pTimestampInfos != nullptr) {
        for (uint32_t timestampIndex = 0; timestampIndex < timestampCount; ++timestampIndex) {
            [[maybe_unused]] const Location pTimestampInfos_loc = loc.dot(Field::pTimestampInfos, timestampIndex);
            skip |= ValidateStructPnext(pTimestampInfos_loc, pTimestampInfos[timestampIndex].pNext, 0, nullptr,
                                        GeneratedVulkanHeaderVersion, "VUID-VkCalibratedTimestampInfoEXT-pNext-pNext",
                                        kVUIDUndefined, false, true);

            skip |= ValidateRangedEnum(pTimestampInfos_loc.dot(Field::timeDomain), "VkTimeDomainEXT",
                                       pTimestampInfos[timestampIndex].timeDomain,
                                       "VUID-VkCalibratedTimestampInfoEXT-timeDomain-parameter");
        }
    }
    skip |= ValidateArray(loc.dot(Field::timestampCount), loc.dot(Field::pTimestamps), timestampCount, &pTimestamps, true, true,
                          "VUID-vkGetCalibratedTimestampsEXT-timestampCount-arraylength",
                          "VUID-vkGetCalibratedTimestampsEXT-pTimestamps-parameter");
    skip |= ValidateRequiredPointer(loc.dot(Field::pMaxDeviation), pMaxDeviation,
                                    "VUID-vkGetCalibratedTimestampsEXT-pMaxDeviation-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCreateHeadlessSurfaceEXT(VkInstance instance,
                                                                  const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo,
                                                                  const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!instance_extensions.vk_ext_headless_surface) skip |= OutputExtensionError(loc, "VK_EXT_headless_surface");
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT", pCreateInfo,
                               VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT, true,
                               "VUID-vkCreateHeadlessSurfaceEXT-pCreateInfo-parameter",
                               "VUID-VkHeadlessSurfaceCreateInfoEXT-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkHeadlessSurfaceCreateInfoEXT-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateReservedFlags(pCreateInfo_loc.dot(Field::flags), pCreateInfo->flags,
                                      "VUID-VkHeadlessSurfaceCreateInfoEXT-flags-zerobitmask");
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateHeadlessSurfaceEXT-pAllocator-null",
                         "vkCreateHeadlessSurfaceEXT(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pSurface), pSurface, "VUID-vkCreateHeadlessSurfaceEXT-pSurface-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                              uint16_t lineStipplePattern, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_line_rasterization)) skip |= OutputExtensionError(loc, "VK_EXT_line_rasterization");
    // No xml-driven validation
    if (!skip) skip |= manual_PreCallValidateCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode,
                                                           const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state");
    skip |= PreCallValidateCmdSetCullMode(commandBuffer, cullMode, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace,
                                                            const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state");
    skip |= PreCallValidateCmdSetFrontFace(commandBuffer, frontFace, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer,
                                                                    VkPrimitiveTopology primitiveTopology,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state");
    skip |= PreCallValidateCmdSetPrimitiveTopology(commandBuffer, primitiveTopology, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                                    const VkViewport* pViewports,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state");
    skip |= PreCallValidateCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                                   const VkRect2D* pScissors, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state");
    skip |= PreCallValidateCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                                  uint32_t bindingCount, const VkBuffer* pBuffers,
                                                                  const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                                  const VkDeviceSize* pStrides,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state");
    skip |= PreCallValidateCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides,
                                                 error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state");
    skip |= PreCallValidateCmdSetDepthTestEnable(commandBuffer, depthTestEnable, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state");
    skip |= PreCallValidateCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state");
    skip |= PreCallValidateCmdSetDepthCompareOp(commandBuffer, depthCompareOp, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer,
                                                                        VkBool32 depthBoundsTestEnable,
                                                                        const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state");
    skip |= PreCallValidateCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable,
                                                                    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state");
    skip |= PreCallValidateCmdSetStencilTestEnable(commandBuffer, stencilTestEnable, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                            VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp,
                                                            VkCompareOp compareOp, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state");
    skip |= PreCallValidateCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetVertexInputEXT(
    VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_vertex_input_dynamic_state))
        skip |= OutputExtensionError(loc, "VK_EXT_vertex_input_dynamic_state");
    skip |= ValidateStructTypeArray(loc.dot(Field::vertexBindingDescriptionCount), loc.dot(Field::pVertexBindingDescriptions),
                                    "VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT", vertexBindingDescriptionCount,
                                    pVertexBindingDescriptions, VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT, false,
                                    true, "VUID-VkVertexInputBindingDescription2EXT-sType-sType",
                                    "VUID-vkCmdSetVertexInputEXT-pVertexBindingDescriptions-parameter", kVUIDUndefined);
    if (pVertexBindingDescriptions != nullptr) {
        for (uint32_t vertexBindingDescriptionIndex = 0; vertexBindingDescriptionIndex < vertexBindingDescriptionCount;
             ++vertexBindingDescriptionIndex) {
            [[maybe_unused]] const Location pVertexBindingDescriptions_loc =
                loc.dot(Field::pVertexBindingDescriptions, vertexBindingDescriptionIndex);
            skip |= ValidateRangedEnum(pVertexBindingDescriptions_loc.dot(Field::inputRate), "VkVertexInputRate",
                                       pVertexBindingDescriptions[vertexBindingDescriptionIndex].inputRate,
                                       "VUID-VkVertexInputBindingDescription2EXT-inputRate-parameter");
        }
    }
    skip |= ValidateStructTypeArray(loc.dot(Field::vertexAttributeDescriptionCount), loc.dot(Field::pVertexAttributeDescriptions),
                                    "VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT", vertexAttributeDescriptionCount,
                                    pVertexAttributeDescriptions, VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT, false,
                                    true, "VUID-VkVertexInputAttributeDescription2EXT-sType-sType",
                                    "VUID-vkCmdSetVertexInputEXT-pVertexAttributeDescriptions-parameter", kVUIDUndefined);
    if (pVertexAttributeDescriptions != nullptr) {
        for (uint32_t vertexAttributeDescriptionIndex = 0; vertexAttributeDescriptionIndex < vertexAttributeDescriptionCount;
             ++vertexAttributeDescriptionIndex) {
            [[maybe_unused]] const Location pVertexAttributeDescriptions_loc =
                loc.dot(Field::pVertexAttributeDescriptions, vertexAttributeDescriptionIndex);
            skip |= ValidateRangedEnum(pVertexAttributeDescriptions_loc.dot(Field::format), "VkFormat",
                                       pVertexAttributeDescriptions[vertexAttributeDescriptionIndex].format,
                                       "VUID-VkVertexInputAttributeDescription2EXT-format-parameter");
        }
    }
    if (!skip)
        skip |=
            manual_PreCallValidateCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                                       vertexAttributeDescriptionCount, pVertexAttributeDescriptions, error_obj);
    return skip;
}

#ifdef VK_USE_PLATFORM_SCI
bool StatelessValidation::PreCallValidateGetFenceSciSyncFenceNV(VkDevice device,
                                                                const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo, void* pHandle,
                                                                const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!(IsExtEnabled(device_extensions.vk_nv_external_sci_sync) || IsExtEnabled(device_extensions.vk_nv_external_sci_sync2)))
        skip |= OutputExtensionError(loc, "VK_NV_external_sci_sync || VK_NV_external_sci_sync2");
    skip |= ValidateStructType(loc.dot(Field::pGetSciSyncHandleInfo), "VK_STRUCTURE_TYPE_FENCE_GET_SCI_SYNC_INFO_NV",
                               pGetSciSyncHandleInfo, VK_STRUCTURE_TYPE_FENCE_GET_SCI_SYNC_INFO_NV, true,
                               "VUID-vkGetFenceSciSyncFenceNV-pGetSciSyncHandleInfo-parameter",
                               "VUID-VkFenceGetSciSyncInfoNV-sType-sType");
    if (pGetSciSyncHandleInfo != nullptr) {
        [[maybe_unused]] const Location pGetSciSyncHandleInfo_loc = loc.dot(Field::pGetSciSyncHandleInfo);
        skip |=
            ValidateStructPnext(pGetSciSyncHandleInfo_loc, pGetSciSyncHandleInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                "VUID-VkFenceGetSciSyncInfoNV-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pGetSciSyncHandleInfo_loc.dot(Field::fence), pGetSciSyncHandleInfo->fence);

        skip |=
            ValidateFlags(pGetSciSyncHandleInfo_loc.dot(Field::handleType), "VkExternalFenceHandleTypeFlagBits",
                          AllVkExternalFenceHandleTypeFlagBits, pGetSciSyncHandleInfo->handleType, kRequiredSingleBit,
                          "VUID-VkFenceGetSciSyncInfoNV-handleType-parameter", "VUID-VkFenceGetSciSyncInfoNV-handleType-parameter");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pHandle), pHandle, "VUID-vkGetFenceSciSyncFenceNV-pHandle-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetFenceSciSyncObjNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo,
                                                              void* pHandle, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!(IsExtEnabled(device_extensions.vk_nv_external_sci_sync) || IsExtEnabled(device_extensions.vk_nv_external_sci_sync2)))
        skip |= OutputExtensionError(loc, "VK_NV_external_sci_sync || VK_NV_external_sci_sync2");
    skip |= ValidateStructType(loc.dot(Field::pGetSciSyncHandleInfo), "VK_STRUCTURE_TYPE_FENCE_GET_SCI_SYNC_INFO_NV",
                               pGetSciSyncHandleInfo, VK_STRUCTURE_TYPE_FENCE_GET_SCI_SYNC_INFO_NV, true,
                               "VUID-vkGetFenceSciSyncObjNV-pGetSciSyncHandleInfo-parameter",
                               "VUID-VkFenceGetSciSyncInfoNV-sType-sType");
    if (pGetSciSyncHandleInfo != nullptr) {
        [[maybe_unused]] const Location pGetSciSyncHandleInfo_loc = loc.dot(Field::pGetSciSyncHandleInfo);
        skip |=
            ValidateStructPnext(pGetSciSyncHandleInfo_loc, pGetSciSyncHandleInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                "VUID-VkFenceGetSciSyncInfoNV-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pGetSciSyncHandleInfo_loc.dot(Field::fence), pGetSciSyncHandleInfo->fence);

        skip |=
            ValidateFlags(pGetSciSyncHandleInfo_loc.dot(Field::handleType), "VkExternalFenceHandleTypeFlagBits",
                          AllVkExternalFenceHandleTypeFlagBits, pGetSciSyncHandleInfo->handleType, kRequiredSingleBit,
                          "VUID-VkFenceGetSciSyncInfoNV-handleType-parameter", "VUID-VkFenceGetSciSyncInfoNV-handleType-parameter");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pHandle), pHandle, "VUID-vkGetFenceSciSyncObjNV-pHandle-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateImportFenceSciSyncFenceNV(VkDevice device,
                                                                   const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!(IsExtEnabled(device_extensions.vk_nv_external_sci_sync) || IsExtEnabled(device_extensions.vk_nv_external_sci_sync2)))
        skip |= OutputExtensionError(loc, "VK_NV_external_sci_sync || VK_NV_external_sci_sync2");
    skip |= ValidateStructType(loc.dot(Field::pImportFenceSciSyncInfo), "VK_STRUCTURE_TYPE_IMPORT_FENCE_SCI_SYNC_INFO_NV",
                               pImportFenceSciSyncInfo, VK_STRUCTURE_TYPE_IMPORT_FENCE_SCI_SYNC_INFO_NV, true,
                               "VUID-vkImportFenceSciSyncFenceNV-pImportFenceSciSyncInfo-parameter",
                               "VUID-VkImportFenceSciSyncInfoNV-sType-sType");
    if (pImportFenceSciSyncInfo != nullptr) {
        [[maybe_unused]] const Location pImportFenceSciSyncInfo_loc = loc.dot(Field::pImportFenceSciSyncInfo);
        skip |= ValidateStructPnext(pImportFenceSciSyncInfo_loc, pImportFenceSciSyncInfo->pNext, 0, nullptr,
                                    GeneratedVulkanHeaderVersion, "VUID-VkImportFenceSciSyncInfoNV-pNext-pNext", kVUIDUndefined,
                                    false, true);

        skip |= ValidateRequiredHandle(pImportFenceSciSyncInfo_loc.dot(Field::fence), pImportFenceSciSyncInfo->fence);

        skip |= ValidateFlags(pImportFenceSciSyncInfo_loc.dot(Field::handleType), "VkExternalFenceHandleTypeFlagBits",
                              AllVkExternalFenceHandleTypeFlagBits, pImportFenceSciSyncInfo->handleType, kRequiredSingleBit,
                              "VUID-VkImportFenceSciSyncInfoNV-handleType-parameter",
                              "VUID-VkImportFenceSciSyncInfoNV-handleType-parameter");

        skip |= ValidateRequiredPointer(pImportFenceSciSyncInfo_loc.dot(Field::handle), pImportFenceSciSyncInfo->handle,
                                        "VUID-VkImportFenceSciSyncInfoNV-handle-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateImportFenceSciSyncObjNV(VkDevice device,
                                                                 const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo,
                                                                 const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!(IsExtEnabled(device_extensions.vk_nv_external_sci_sync) || IsExtEnabled(device_extensions.vk_nv_external_sci_sync2)))
        skip |= OutputExtensionError(loc, "VK_NV_external_sci_sync || VK_NV_external_sci_sync2");
    skip |= ValidateStructType(loc.dot(Field::pImportFenceSciSyncInfo), "VK_STRUCTURE_TYPE_IMPORT_FENCE_SCI_SYNC_INFO_NV",
                               pImportFenceSciSyncInfo, VK_STRUCTURE_TYPE_IMPORT_FENCE_SCI_SYNC_INFO_NV, true,
                               "VUID-vkImportFenceSciSyncObjNV-pImportFenceSciSyncInfo-parameter",
                               "VUID-VkImportFenceSciSyncInfoNV-sType-sType");
    if (pImportFenceSciSyncInfo != nullptr) {
        [[maybe_unused]] const Location pImportFenceSciSyncInfo_loc = loc.dot(Field::pImportFenceSciSyncInfo);
        skip |= ValidateStructPnext(pImportFenceSciSyncInfo_loc, pImportFenceSciSyncInfo->pNext, 0, nullptr,
                                    GeneratedVulkanHeaderVersion, "VUID-VkImportFenceSciSyncInfoNV-pNext-pNext", kVUIDUndefined,
                                    false, true);

        skip |= ValidateRequiredHandle(pImportFenceSciSyncInfo_loc.dot(Field::fence), pImportFenceSciSyncInfo->fence);

        skip |= ValidateFlags(pImportFenceSciSyncInfo_loc.dot(Field::handleType), "VkExternalFenceHandleTypeFlagBits",
                              AllVkExternalFenceHandleTypeFlagBits, pImportFenceSciSyncInfo->handleType, kRequiredSingleBit,
                              "VUID-VkImportFenceSciSyncInfoNV-handleType-parameter",
                              "VUID-VkImportFenceSciSyncInfoNV-handleType-parameter");

        skip |= ValidateRequiredPointer(pImportFenceSciSyncInfo_loc.dot(Field::handle), pImportFenceSciSyncInfo->handle,
                                        "VUID-VkImportFenceSciSyncInfoNV-handle-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSciSyncAttributesNV(
    VkPhysicalDevice physicalDevice, const VkSciSyncAttributesInfoNV* pSciSyncAttributesInfo, NvSciSyncAttrList pAttributes,
    const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateStructType(loc.dot(Field::pSciSyncAttributesInfo), "VK_STRUCTURE_TYPE_SCI_SYNC_ATTRIBUTES_INFO_NV",
                               pSciSyncAttributesInfo, VK_STRUCTURE_TYPE_SCI_SYNC_ATTRIBUTES_INFO_NV, true,
                               "VUID-vkGetPhysicalDeviceSciSyncAttributesNV-pSciSyncAttributesInfo-parameter",
                               "VUID-VkSciSyncAttributesInfoNV-sType-sType");
    if (pSciSyncAttributesInfo != nullptr) {
        [[maybe_unused]] const Location pSciSyncAttributesInfo_loc = loc.dot(Field::pSciSyncAttributesInfo);
        skip |=
            ValidateStructPnext(pSciSyncAttributesInfo_loc, pSciSyncAttributesInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                "VUID-VkSciSyncAttributesInfoNV-pNext-pNext", kVUIDUndefined, true, true);

        skip |= ValidateRangedEnum(pSciSyncAttributesInfo_loc.dot(Field::clientType), "VkSciSyncClientTypeNV",
                                   pSciSyncAttributesInfo->clientType, "VUID-VkSciSyncAttributesInfoNV-clientType-parameter");

        skip |= ValidateRangedEnum(pSciSyncAttributesInfo_loc.dot(Field::primitiveType), "VkSciSyncPrimitiveTypeNV",
                                   pSciSyncAttributesInfo->primitiveType, "VUID-VkSciSyncAttributesInfoNV-primitiveType-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetSemaphoreSciSyncObjNV(VkDevice device,
                                                                  const VkSemaphoreGetSciSyncInfoNV* pGetSciSyncInfo, void* pHandle,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_nv_external_sci_sync)) skip |= OutputExtensionError(loc, "VK_NV_external_sci_sync");
    skip |= ValidateStructType(loc.dot(Field::pGetSciSyncInfo), "VK_STRUCTURE_TYPE_SEMAPHORE_GET_SCI_SYNC_INFO_NV", pGetSciSyncInfo,
                               VK_STRUCTURE_TYPE_SEMAPHORE_GET_SCI_SYNC_INFO_NV, true,
                               "VUID-vkGetSemaphoreSciSyncObjNV-pGetSciSyncInfo-parameter",
                               "VUID-VkSemaphoreGetSciSyncInfoNV-sType-sType");
    if (pGetSciSyncInfo != nullptr) {
        [[maybe_unused]] const Location pGetSciSyncInfo_loc = loc.dot(Field::pGetSciSyncInfo);
        skip |= ValidateStructPnext(pGetSciSyncInfo_loc, pGetSciSyncInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkSemaphoreGetSciSyncInfoNV-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pGetSciSyncInfo_loc.dot(Field::semaphore), pGetSciSyncInfo->semaphore);

        skip |= ValidateFlags(pGetSciSyncInfo_loc.dot(Field::handleType), "VkExternalSemaphoreHandleTypeFlagBits",
                              AllVkExternalSemaphoreHandleTypeFlagBits, pGetSciSyncInfo->handleType, kRequiredSingleBit,
                              "VUID-VkSemaphoreGetSciSyncInfoNV-handleType-parameter",
                              "VUID-VkSemaphoreGetSciSyncInfoNV-handleType-parameter");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pHandle), pHandle, "VUID-vkGetSemaphoreSciSyncObjNV-pHandle-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateImportSemaphoreSciSyncObjNV(
    VkDevice device, const VkImportSemaphoreSciSyncInfoNV* pImportSemaphoreSciSyncInfo, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_nv_external_sci_sync)) skip |= OutputExtensionError(loc, "VK_NV_external_sci_sync");
    skip |= ValidateStructType(loc.dot(Field::pImportSemaphoreSciSyncInfo), "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_SCI_SYNC_INFO_NV",
                               pImportSemaphoreSciSyncInfo, VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_SCI_SYNC_INFO_NV, true,
                               "VUID-vkImportSemaphoreSciSyncObjNV-pImportSemaphoreSciSyncInfo-parameter",
                               "VUID-VkImportSemaphoreSciSyncInfoNV-sType-sType");
    if (pImportSemaphoreSciSyncInfo != nullptr) {
        [[maybe_unused]] const Location pImportSemaphoreSciSyncInfo_loc = loc.dot(Field::pImportSemaphoreSciSyncInfo);
        skip |= ValidateStructPnext(pImportSemaphoreSciSyncInfo_loc, pImportSemaphoreSciSyncInfo->pNext, 0, nullptr,
                                    GeneratedVulkanHeaderVersion, "VUID-VkImportSemaphoreSciSyncInfoNV-pNext-pNext", kVUIDUndefined,
                                    false, true);

        skip |=
            ValidateRequiredHandle(pImportSemaphoreSciSyncInfo_loc.dot(Field::semaphore), pImportSemaphoreSciSyncInfo->semaphore);

        skip |= ValidateFlags(pImportSemaphoreSciSyncInfo_loc.dot(Field::handleType), "VkExternalSemaphoreHandleTypeFlagBits",
                              AllVkExternalSemaphoreHandleTypeFlagBits, pImportSemaphoreSciSyncInfo->handleType, kRequiredSingleBit,
                              "VUID-VkImportSemaphoreSciSyncInfoNV-handleType-parameter",
                              "VUID-VkImportSemaphoreSciSyncInfoNV-handleType-parameter");

        skip |= ValidateRequiredPointer(pImportSemaphoreSciSyncInfo_loc.dot(Field::handle), pImportSemaphoreSciSyncInfo->handle,
                                        "VUID-VkImportSemaphoreSciSyncInfoNV-handle-parameter");
    }
    return skip;
}

bool StatelessValidation::PreCallValidateGetMemorySciBufNV(VkDevice device, const VkMemoryGetSciBufInfoNV* pGetSciBufInfo,
                                                           NvSciBufObj* pHandle, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_nv_external_memory_sci_buf))
        skip |= OutputExtensionError(loc, "VK_NV_external_memory_sci_buf");
    skip |= ValidateStructType(loc.dot(Field::pGetSciBufInfo), "VK_STRUCTURE_TYPE_MEMORY_GET_SCI_BUF_INFO_NV", pGetSciBufInfo,
                               VK_STRUCTURE_TYPE_MEMORY_GET_SCI_BUF_INFO_NV, true,
                               "VUID-vkGetMemorySciBufNV-pGetSciBufInfo-parameter", "VUID-VkMemoryGetSciBufInfoNV-sType-sType");
    if (pGetSciBufInfo != nullptr) {
        [[maybe_unused]] const Location pGetSciBufInfo_loc = loc.dot(Field::pGetSciBufInfo);
        skip |= ValidateStructPnext(pGetSciBufInfo_loc, pGetSciBufInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkMemoryGetSciBufInfoNV-pNext-pNext", kVUIDUndefined, false, true);

        skip |= ValidateRequiredHandle(pGetSciBufInfo_loc.dot(Field::memory), pGetSciBufInfo->memory);

        skip |=
            ValidateFlags(pGetSciBufInfo_loc.dot(Field::handleType), "VkExternalMemoryHandleTypeFlagBits",
                          AllVkExternalMemoryHandleTypeFlagBits, pGetSciBufInfo->handleType, kRequiredSingleBit,
                          "VUID-VkMemoryGetSciBufInfoNV-handleType-parameter", "VUID-VkMemoryGetSciBufInfoNV-handleType-parameter");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pHandle), pHandle, "VUID-vkGetMemorySciBufNV-pHandle-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceExternalMemorySciBufPropertiesNV(
    VkPhysicalDevice physicalDevice, VkExternalMemoryHandleTypeFlagBits handleType, NvSciBufObj handle,
    VkMemorySciBufPropertiesNV* pMemorySciBufProperties, const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    skip |= ValidateFlags(loc.dot(Field::handleType), "VkExternalMemoryHandleTypeFlagBits", AllVkExternalMemoryHandleTypeFlagBits,
                          handleType, kRequiredSingleBit,
                          "VUID-vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV-handleType-parameter",
                          "VUID-vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV-handleType-parameter");
    skip |= ValidateStructType(loc.dot(Field::pMemorySciBufProperties), "VK_STRUCTURE_TYPE_MEMORY_SCI_BUF_PROPERTIES_NV",
                               pMemorySciBufProperties, VK_STRUCTURE_TYPE_MEMORY_SCI_BUF_PROPERTIES_NV, true,
                               "VUID-vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV-pMemorySciBufProperties-parameter",
                               "VUID-VkMemorySciBufPropertiesNV-sType-sType");
    return skip;
}

bool StatelessValidation::PreCallValidateGetPhysicalDeviceSciBufAttributesNV(VkPhysicalDevice physicalDevice,
                                                                             NvSciBufAttrList pAttributes,
                                                                             const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    // No xml-driven validation
    return skip;
}
#endif  // VK_USE_PLATFORM_SCI

bool StatelessValidation::PreCallValidateCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints,
                                                                     const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state2))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state2");
    // No xml-driven validation
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer,
                                                                          VkBool32 rasterizerDiscardEnable,
                                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state2))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state2");
    skip |= PreCallValidateCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable,
                                                                  const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state2))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state2");
    skip |= PreCallValidateCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp,
                                                          const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state2))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state2");
    skip |= ValidateRangedEnum(loc.dot(Field::logicOp), "VkLogicOp", logicOp, "VUID-vkCmdSetLogicOpEXT-logicOp-parameter");
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer,
                                                                         VkBool32 primitiveRestartEnable,
                                                                         const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_extended_dynamic_state2))
        skip |= OutputExtensionError(loc, "VK_EXT_extended_dynamic_state2");
    skip |= PreCallValidateCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable, error_obj);
    return skip;
}

bool StatelessValidation::PreCallValidateCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                                   const VkBool32* pColorWriteEnables,
                                                                   const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_ext_color_write_enable)) skip |= OutputExtensionError(loc, "VK_EXT_color_write_enable");
    skip |= ValidateBool32Array(loc.dot(Field::attachmentCount), loc.dot(Field::pColorWriteEnables), attachmentCount,
                                pColorWriteEnables, true, true);
    return skip;
}

#ifdef VK_USE_PLATFORM_SCI
bool StatelessValidation::PreCallValidateCreateSemaphoreSciSyncPoolNV(VkDevice device,
                                                                      const VkSemaphoreSciSyncPoolCreateInfoNV* pCreateInfo,
                                                                      const VkAllocationCallbacks* pAllocator,
                                                                      VkSemaphoreSciSyncPoolNV* pSemaphorePool,
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_nv_external_sci_sync2)) skip |= OutputExtensionError(loc, "VK_NV_external_sci_sync2");
    skip |= ValidateStructType(loc.dot(Field::pCreateInfo), "VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_POOL_CREATE_INFO_NV", pCreateInfo,
                               VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_POOL_CREATE_INFO_NV, true,
                               "VUID-vkCreateSemaphoreSciSyncPoolNV-pCreateInfo-parameter",
                               "VUID-VkSemaphoreSciSyncPoolCreateInfoNV-sType-sType");
    if (pCreateInfo != nullptr) {
        [[maybe_unused]] const Location pCreateInfo_loc = loc.dot(Field::pCreateInfo);
        skip |= ValidateStructPnext(pCreateInfo_loc, pCreateInfo->pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                    "VUID-VkSemaphoreSciSyncPoolCreateInfoNV-pNext-pNext", kVUIDUndefined, false, true);
    }
    if (pAllocator != nullptr) {
        skip |= LogError(instance, "VUID-vkCreateSemaphoreSciSyncPoolNV-pAllocator-null",
                         "vkCreateSemaphoreSciSyncPoolNV(): pAllocator must be NULL");
    }
    skip |= ValidateRequiredPointer(loc.dot(Field::pSemaphorePool), pSemaphorePool,
                                    "VUID-vkCreateSemaphoreSciSyncPoolNV-pSemaphorePool-parameter");
    return skip;
}
#endif  // VK_USE_PLATFORM_SCI

#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool StatelessValidation::PreCallValidateGetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer,
                                                                      VkScreenBufferPropertiesQNX* pProperties,
                                                                      const ErrorObject& error_obj) const {
    bool skip = false;
    [[maybe_unused]] const Location loc = error_obj.location;
    if (!IsExtEnabled(device_extensions.vk_qnx_external_memory_screen_buffer))
        skip |= OutputExtensionError(loc, "VK_QNX_external_memory_screen_buffer");
    skip |= ValidateRequiredPointer(loc.dot(Field::buffer), buffer, "VUID-vkGetScreenBufferPropertiesQNX-buffer-parameter");
    skip |= ValidateStructType(loc.dot(Field::pProperties), "VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX", pProperties,
                               VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX, true,
                               "VUID-vkGetScreenBufferPropertiesQNX-pProperties-parameter",
                               "VUID-VkScreenBufferPropertiesQNX-sType-sType");
    if (pProperties != nullptr) {
        [[maybe_unused]] const Location pProperties_loc = loc.dot(Field::pProperties);
        constexpr std::array allowed_structs_VkScreenBufferPropertiesQNX = {VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX};

        skip |= ValidateStructPnext(pProperties_loc, pProperties->pNext, allowed_structs_VkScreenBufferPropertiesQNX.size(),
                                    allowed_structs_VkScreenBufferPropertiesQNX.data(), GeneratedVulkanHeaderVersion,
                                    "VUID-VkScreenBufferPropertiesQNX-pNext-pNext", "VUID-VkScreenBufferPropertiesQNX-sType-unique",
                                    false, false);
    }
    return skip;
}
#endif  // VK_USE_PLATFORM_SCREEN_QNX

bool StatelessValidation::ValidatePipelineViewportStateCreateInfo(const VkPipelineViewportStateCreateInfo& info,
                                                                  const Location& loc) const {
    bool skip = false;
    skip |= ValidateStructType(loc, "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO", &info,
                               VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO, false, kVUIDUndefined,
                               "VUID-VkPipelineViewportStateCreateInfo-sType-sType");

    skip |= ValidateStructPnext(loc, info.pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                "VUID-VkPipelineViewportStateCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

    skip |= ValidateReservedFlags(loc.dot(Field::flags), info.flags, "VUID-VkPipelineViewportStateCreateInfo-flags-zerobitmask");
    return skip;
}
bool StatelessValidation::ValidatePipelineTessellationStateCreateInfo(const VkPipelineTessellationStateCreateInfo& info,
                                                                      const Location& loc) const {
    bool skip = false;
    skip |= ValidateStructType(loc, "VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO", &info,
                               VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO, false, kVUIDUndefined,
                               "VUID-VkPipelineTessellationStateCreateInfo-sType-sType");

    constexpr std::array allowed_structs_VkPipelineTessellationStateCreateInfo = {
        VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO};

    skip |= ValidateStructPnext(loc, info.pNext, allowed_structs_VkPipelineTessellationStateCreateInfo.size(),
                                allowed_structs_VkPipelineTessellationStateCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkPipelineTessellationStateCreateInfo-pNext-pNext",
                                "VUID-VkPipelineTessellationStateCreateInfo-sType-unique", false, true);

    skip |=
        ValidateReservedFlags(loc.dot(Field::flags), info.flags, "VUID-VkPipelineTessellationStateCreateInfo-flags-zerobitmask");
    return skip;
}
bool StatelessValidation::ValidatePipelineVertexInputStateCreateInfo(const VkPipelineVertexInputStateCreateInfo& info,
                                                                     const Location& loc) const {
    bool skip = false;
    skip |= ValidateStructType(loc, "VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO", &info,
                               VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO, false, kVUIDUndefined,
                               "VUID-VkPipelineVertexInputStateCreateInfo-sType-sType");

    constexpr std::array allowed_structs_VkPipelineVertexInputStateCreateInfo = {
        VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT};

    skip |= ValidateStructPnext(loc, info.pNext, allowed_structs_VkPipelineVertexInputStateCreateInfo.size(),
                                allowed_structs_VkPipelineVertexInputStateCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkPipelineVertexInputStateCreateInfo-pNext-pNext",
                                "VUID-VkPipelineVertexInputStateCreateInfo-sType-unique", false, true);

    skip |= ValidateReservedFlags(loc.dot(Field::flags), info.flags, "VUID-VkPipelineVertexInputStateCreateInfo-flags-zerobitmask");

    skip |= ValidateArray(loc.dot(Field::vertexBindingDescriptionCount), loc.dot(Field::pVertexBindingDescriptions),
                          info.vertexBindingDescriptionCount, &info.pVertexBindingDescriptions, false, true, kVUIDUndefined,
                          "VUID-VkPipelineVertexInputStateCreateInfo-pVertexBindingDescriptions-parameter");

    if (info.pVertexBindingDescriptions != nullptr) {
        for (uint32_t vertexBindingDescriptionIndex = 0; vertexBindingDescriptionIndex < info.vertexBindingDescriptionCount;
             ++vertexBindingDescriptionIndex) {
            [[maybe_unused]] const Location pVertexBindingDescriptions_loc =
                loc.dot(Field::pVertexBindingDescriptions, vertexBindingDescriptionIndex);
            skip |= ValidateRangedEnum(pVertexBindingDescriptions_loc.dot(Field::inputRate), "VkVertexInputRate",
                                       info.pVertexBindingDescriptions[vertexBindingDescriptionIndex].inputRate,
                                       "VUID-VkVertexInputBindingDescription-inputRate-parameter");
        }
    }

    skip |= ValidateArray(loc.dot(Field::vertexAttributeDescriptionCount), loc.dot(Field::pVertexAttributeDescriptions),
                          info.vertexAttributeDescriptionCount, &info.pVertexAttributeDescriptions, false, true, kVUIDUndefined,
                          "VUID-VkPipelineVertexInputStateCreateInfo-pVertexAttributeDescriptions-parameter");

    if (info.pVertexAttributeDescriptions != nullptr) {
        for (uint32_t vertexAttributeDescriptionIndex = 0; vertexAttributeDescriptionIndex < info.vertexAttributeDescriptionCount;
             ++vertexAttributeDescriptionIndex) {
            [[maybe_unused]] const Location pVertexAttributeDescriptions_loc =
                loc.dot(Field::pVertexAttributeDescriptions, vertexAttributeDescriptionIndex);
            skip |= ValidateRangedEnum(pVertexAttributeDescriptions_loc.dot(Field::format), "VkFormat",
                                       info.pVertexAttributeDescriptions[vertexAttributeDescriptionIndex].format,
                                       "VUID-VkVertexInputAttributeDescription-format-parameter");
        }
    }
    return skip;
}
bool StatelessValidation::ValidatePipelineMultisampleStateCreateInfo(const VkPipelineMultisampleStateCreateInfo& info,
                                                                     const Location& loc) const {
    bool skip = false;
    skip |= ValidateStructType(loc, "VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO", &info,
                               VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO, false, kVUIDUndefined,
                               "VUID-VkPipelineMultisampleStateCreateInfo-sType-sType");

    constexpr std::array allowed_structs_VkPipelineMultisampleStateCreateInfo = {
        VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT};

    skip |= ValidateStructPnext(loc, info.pNext, allowed_structs_VkPipelineMultisampleStateCreateInfo.size(),
                                allowed_structs_VkPipelineMultisampleStateCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkPipelineMultisampleStateCreateInfo-pNext-pNext",
                                "VUID-VkPipelineMultisampleStateCreateInfo-sType-unique", false, true);

    skip |= ValidateReservedFlags(loc.dot(Field::flags), info.flags, "VUID-VkPipelineMultisampleStateCreateInfo-flags-zerobitmask");

    skip |= ValidateFlags(loc.dot(Field::rasterizationSamples), "VkSampleCountFlagBits", AllVkSampleCountFlagBits,
                          info.rasterizationSamples, kRequiredSingleBit,
                          "VUID-VkPipelineMultisampleStateCreateInfo-rasterizationSamples-parameter",
                          "VUID-VkPipelineMultisampleStateCreateInfo-rasterizationSamples-parameter");

    skip |= ValidateBool32(loc.dot(Field::sampleShadingEnable), info.sampleShadingEnable);

    skip |= ValidateArray(loc.dot(Field::rasterizationSamples), loc.dot(Field::pSampleMask), info.rasterizationSamples,
                          &info.pSampleMask, true, false, kVUIDUndefined,
                          "VUID-VkPipelineMultisampleStateCreateInfo-pSampleMask-parameter");

    skip |= ValidateBool32(loc.dot(Field::alphaToCoverageEnable), info.alphaToCoverageEnable);

    skip |= ValidateBool32(loc.dot(Field::alphaToOneEnable), info.alphaToOneEnable);
    return skip;
}
bool StatelessValidation::ValidatePipelineColorBlendStateCreateInfo(const VkPipelineColorBlendStateCreateInfo& info,
                                                                    const Location& loc) const {
    bool skip = false;
    skip |= ValidateStructType(loc, "VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO", &info,
                               VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO, false, kVUIDUndefined,
                               "VUID-VkPipelineColorBlendStateCreateInfo-sType-sType");

    constexpr std::array allowed_structs_VkPipelineColorBlendStateCreateInfo = {
        VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT,
        VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT};

    skip |= ValidateStructPnext(loc, info.pNext, allowed_structs_VkPipelineColorBlendStateCreateInfo.size(),
                                allowed_structs_VkPipelineColorBlendStateCreateInfo.data(), GeneratedVulkanHeaderVersion,
                                "VUID-VkPipelineColorBlendStateCreateInfo-pNext-pNext",
                                "VUID-VkPipelineColorBlendStateCreateInfo-sType-unique", false, true);

    skip |= ValidateReservedFlags(loc.dot(Field::flags), info.flags, "VUID-VkPipelineColorBlendStateCreateInfo-flags-zerobitmask");

    skip |= ValidateBool32(loc.dot(Field::logicOpEnable), info.logicOpEnable);

    if (info.pAttachments != nullptr) {
        for (uint32_t attachmentIndex = 0; attachmentIndex < info.attachmentCount; ++attachmentIndex) {
            [[maybe_unused]] const Location pAttachments_loc = loc.dot(Field::pAttachments, attachmentIndex);
            skip |= ValidateBool32(pAttachments_loc.dot(Field::blendEnable), info.pAttachments[attachmentIndex].blendEnable);

            skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::srcColorBlendFactor), "VkBlendFactor",
                                       info.pAttachments[attachmentIndex].srcColorBlendFactor,
                                       "VUID-VkPipelineColorBlendAttachmentState-srcColorBlendFactor-parameter");

            skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::dstColorBlendFactor), "VkBlendFactor",
                                       info.pAttachments[attachmentIndex].dstColorBlendFactor,
                                       "VUID-VkPipelineColorBlendAttachmentState-dstColorBlendFactor-parameter");

            skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::colorBlendOp), "VkBlendOp",
                                       info.pAttachments[attachmentIndex].colorBlendOp,
                                       "VUID-VkPipelineColorBlendAttachmentState-colorBlendOp-parameter");

            skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::srcAlphaBlendFactor), "VkBlendFactor",
                                       info.pAttachments[attachmentIndex].srcAlphaBlendFactor,
                                       "VUID-VkPipelineColorBlendAttachmentState-srcAlphaBlendFactor-parameter");

            skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::dstAlphaBlendFactor), "VkBlendFactor",
                                       info.pAttachments[attachmentIndex].dstAlphaBlendFactor,
                                       "VUID-VkPipelineColorBlendAttachmentState-dstAlphaBlendFactor-parameter");

            skip |= ValidateRangedEnum(pAttachments_loc.dot(Field::alphaBlendOp), "VkBlendOp",
                                       info.pAttachments[attachmentIndex].alphaBlendOp,
                                       "VUID-VkPipelineColorBlendAttachmentState-alphaBlendOp-parameter");

            skip |= ValidateFlags(pAttachments_loc.dot(Field::colorWriteMask), "VkColorComponentFlagBits",
                                  AllVkColorComponentFlagBits, info.pAttachments[attachmentIndex].colorWriteMask, kOptionalFlags,
                                  "VUID-VkPipelineColorBlendAttachmentState-colorWriteMask-parameter");
        }
    }
    return skip;
}
bool StatelessValidation::ValidatePipelineDepthStencilStateCreateInfo(const VkPipelineDepthStencilStateCreateInfo& info,
                                                                      const Location& loc) const {
    bool skip = false;
    skip |= ValidateStructType(loc, "VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO", &info,
                               VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO, false, kVUIDUndefined,
                               "VUID-VkPipelineDepthStencilStateCreateInfo-sType-sType");

    skip |= ValidateStructPnext(loc, info.pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                "VUID-VkPipelineDepthStencilStateCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

    skip |=
        ValidateReservedFlags(loc.dot(Field::flags), info.flags, "VUID-VkPipelineDepthStencilStateCreateInfo-flags-zerobitmask");

    skip |= ValidateBool32(loc.dot(Field::depthTestEnable), info.depthTestEnable);

    skip |= ValidateBool32(loc.dot(Field::depthWriteEnable), info.depthWriteEnable);

    skip |= ValidateRangedEnum(loc.dot(Field::depthCompareOp), "VkCompareOp", info.depthCompareOp,
                               "VUID-VkPipelineDepthStencilStateCreateInfo-depthCompareOp-parameter");

    skip |= ValidateBool32(loc.dot(Field::depthBoundsTestEnable), info.depthBoundsTestEnable);

    skip |= ValidateBool32(loc.dot(Field::stencilTestEnable), info.stencilTestEnable);

    skip |= ValidateRangedEnum(loc.dot(Field::failOp), "VkStencilOp", info.front.failOp, "VUID-VkStencilOpState-failOp-parameter");

    skip |= ValidateRangedEnum(loc.dot(Field::passOp), "VkStencilOp", info.front.passOp, "VUID-VkStencilOpState-passOp-parameter");

    skip |= ValidateRangedEnum(loc.dot(Field::depthFailOp), "VkStencilOp", info.front.depthFailOp,
                               "VUID-VkStencilOpState-depthFailOp-parameter");

    skip |= ValidateRangedEnum(loc.dot(Field::compareOp), "VkCompareOp", info.front.compareOp,
                               "VUID-VkStencilOpState-compareOp-parameter");

    skip |= ValidateRangedEnum(loc.dot(Field::failOp), "VkStencilOp", info.back.failOp, "VUID-VkStencilOpState-failOp-parameter");

    skip |= ValidateRangedEnum(loc.dot(Field::passOp), "VkStencilOp", info.back.passOp, "VUID-VkStencilOpState-passOp-parameter");

    skip |= ValidateRangedEnum(loc.dot(Field::depthFailOp), "VkStencilOp", info.back.depthFailOp,
                               "VUID-VkStencilOpState-depthFailOp-parameter");

    skip |= ValidateRangedEnum(loc.dot(Field::compareOp), "VkCompareOp", info.back.compareOp,
                               "VUID-VkStencilOpState-compareOp-parameter");
    return skip;
}
bool StatelessValidation::ValidatePipelineInputAssemblyStateCreateInfo(const VkPipelineInputAssemblyStateCreateInfo& info,
                                                                       const Location& loc) const {
    bool skip = false;
    skip |= ValidateStructType(loc, "VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO", &info,
                               VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO, false, kVUIDUndefined,
                               "VUID-VkPipelineInputAssemblyStateCreateInfo-sType-sType");

    skip |= ValidateStructPnext(loc, info.pNext, 0, nullptr, GeneratedVulkanHeaderVersion,
                                "VUID-VkPipelineInputAssemblyStateCreateInfo-pNext-pNext", kVUIDUndefined, false, true);

    skip |=
        ValidateReservedFlags(loc.dot(Field::flags), info.flags, "VUID-VkPipelineInputAssemblyStateCreateInfo-flags-zerobitmask");

    skip |= ValidateRangedEnum(loc.dot(Field::topology), "VkPrimitiveTopology", info.topology,
                               "VUID-VkPipelineInputAssemblyStateCreateInfo-topology-parameter");

    skip |= ValidateBool32(loc.dot(Field::primitiveRestartEnable), info.primitiveRestartEnable);
    return skip;
}

// NOLINTEND
