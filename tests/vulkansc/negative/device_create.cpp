/*
 * Copyright (c) 2023-2025 The Khronos Group Inc.
 * Copyright (c) 2023-2025 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#include "../framework/vksc_layer_validation_tests.h"

TEST_F(VkSCNegativeDeviceCreate, MissingVulkanSC10Features) {
    TEST_DESCRIPTION("vkCreateDevice with missing VkPhysicalDeviceVulkanSC10Features.");

    RETURN_IF_SKIP(InitFramework());

    auto object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>();

    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "UNASSIGNED-VkDeviceCreateInfo-pNext-VkPhysicalDeviceVulkanSC10Features");
    TestCreateDevice(&object_reservation_info);
}

TEST_F(VkSCNegativeDeviceCreate, MissingObjectReservationInfo) {
    TEST_DESCRIPTION("vkCreateDevice with missing VkDeviceObjectReservationCreateInfo.");

    RETURN_IF_SKIP(InitFramework());

    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();

    m_errorMonitor->SetDesiredFailureMsg(kWarningBit, "UNASSIGNED-VkDeviceCreateInfo-pNext-VkDeviceObjectReservationCreateInfo");
    TestCreateDevice(&sc_10_features);
}

TEST_F(VkSCNegativeDeviceCreate, MaxMemoryAllocationCountExceeded) {
    TEST_DESCRIPTION("vkCreateDevice - requested memory count exceeds maximum");

    RETURN_IF_SKIP(InitFramework());

    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();

    const uint32_t max_count = 10;
    std::vector<VkDeviceObjectReservationCreateInfo> object_reservation_info(
        max_count, vku::InitStruct<VkDeviceObjectReservationCreateInfo>());
    object_reservation_info[0].pNext = &sc_10_features;
    for (uint32_t i = 1; i < max_count; ++i) {
        object_reservation_info[i].pNext = &object_reservation_info[i - 1];
    }

    for (uint32_t used_count = 1; used_count <= max_count; ++used_count) {
        uint32_t remaining = phys_dev_props.limits.maxMemoryAllocationCount;
        for (uint32_t i = 1; i < used_count; ++i) {
            object_reservation_info[i].deviceMemoryRequestCount = remaining / 2;
            remaining -= object_reservation_info[i].deviceMemoryRequestCount;
        }
        object_reservation_info[0].deviceMemoryRequestCount = remaining;

        void* chain = &object_reservation_info[used_count - 1];

        TestCreateDevice(chain);

        object_reservation_info[used_count / 2].deviceMemoryRequestCount++;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateDevice-deviceMemoryRequestCount-05095");
        TestCreateDevice(chain);
    }
}

TEST_F(VkSCNegativeDeviceCreate, MaxSamplerAllocationCountExceeded) {
    TEST_DESCRIPTION("vkCreateDevice - requested memory count exceeds maximum");

    RETURN_IF_SKIP(InitFramework());

    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();

    const uint32_t max_count = 10;
    std::vector<VkDeviceObjectReservationCreateInfo> object_reservation_info(
        max_count, vku::InitStruct<VkDeviceObjectReservationCreateInfo>());
    object_reservation_info[0].pNext = &sc_10_features;
    for (uint32_t i = 1; i < max_count; ++i) {
        object_reservation_info[i].pNext = &object_reservation_info[i - 1];
    }

    for (uint32_t used_count = 1; used_count <= max_count; ++used_count) {
        uint32_t remaining = phys_dev_props.limits.maxSamplerAllocationCount;
        for (uint32_t i = 1; i < used_count; ++i) {
            object_reservation_info[i].samplerRequestCount = remaining / 2;
            remaining -= object_reservation_info[i].samplerRequestCount;
        }
        object_reservation_info[0].samplerRequestCount = remaining;

        void* chain = &object_reservation_info[used_count - 1];

        TestCreateDevice(chain);

        object_reservation_info[used_count / 2].samplerRequestCount++;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateDevice-samplerRequestCount-05096");
        TestCreateDevice(chain);
    }
}

TEST_F(VkSCNegativeDeviceCreate, MaxImageArrayLayersExceeded) {
    TEST_DESCRIPTION("vkCreateDevice - requested max image view array layers exceeds maximum");

    RETURN_IF_SKIP(InitFramework());

    ObjectReservation().maxImageViewArrayLayers = GetVulkanProperties().limits.maxImageArrayLayers + 1;
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkDeviceObjectReservationCreateInfo-maxImageViewArrayLayers-05014");
    TestCreateDevice(&ObjectReservation());
}

TEST_F(VkSCNegativeDeviceCreate, MaxMipLevelsExceeded) {
    TEST_DESCRIPTION("vkCreateDevice - requested max image view mip levels exceeds maximum");

    RETURN_IF_SKIP(InitFramework());

    auto pd_props = GetVulkanProperties();

    uint32_t max_mip_levels =
        1u + static_cast<uint32_t>(log2(std::max({pd_props.limits.maxImageDimension1D, pd_props.limits.maxImageDimension2D,
                                                  pd_props.limits.maxImageDimension3D, pd_props.limits.maxImageDimensionCube})));

    ObjectReservation().maxImageViewMipLevels = max_mip_levels + 1;
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkDeviceObjectReservationCreateInfo-maxImageViewMipLevels-05015");
    TestCreateDevice(&ObjectReservation());

    ObjectReservation().maxImageViewMipLevels = max_mip_levels;
    ObjectReservation().maxLayeredImageViewMipLevels = max_mip_levels + 1;
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkDeviceObjectReservationCreateInfo-maxLayeredImageViewMipLevels-05016");
    TestCreateDevice(&ObjectReservation());
}

TEST_F(VkSCNegativeDeviceCreate, MaxTotalSubpassDescriptions) {
    TEST_DESCRIPTION("vkCreateDevice - requested subpass description count exceeds maximum possible");

    RETURN_IF_SKIP(InitFramework());

    auto sc_10_props = GetVulkanSC10Properties();
    const uint32_t rp_request_count = 42;

    ObjectReservation().renderPassRequestCount = rp_request_count;
    ObjectReservation().subpassDescriptionRequestCount = rp_request_count * sc_10_props.maxRenderPassSubpasses;
    ObjectReservation().attachmentDescriptionRequestCount = rp_request_count * sc_10_props.maxFramebufferAttachments;

    ObjectReservation().subpassDescriptionRequestCount++;

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit,
                                         "VUID-VkDeviceObjectReservationCreateInfo-subpassDescriptionRequestCount-05017");
    TestCreateDevice(&ObjectReservation());

    ObjectReservation().subpassDescriptionRequestCount--;
    ObjectReservation().attachmentDescriptionRequestCount++;

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit,
                                         "VUID-VkDeviceObjectReservationCreateInfo-attachmentDescriptionRequestCount-05018");
    TestCreateDevice(&ObjectReservation());
}

TEST_F(VkSCNegativeDeviceCreate, PipelineCacheCreateMissingRequiredFlags) {
    TEST_DESCRIPTION("vkCreateDevice - VkPipelineCacheCreateInfo is missing required flags");

    RETURN_IF_SKIP(InitFramework());

    VkPipelineCacheCreateInfo create_info{};
    ObjectReservation().pipelineCacheCreateInfoCount = 1;
    ObjectReservation().pPipelineCacheCreateInfos = &create_info;

    vksc::PipelineCacheBuilder builder{};
    auto header = builder.AddDefaultHeaderVersionSCOne();
    builder.AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);

    create_info = builder.MakeCreateInfo(VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT);
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineCacheCreateInfo-flags-05043");
    TestCreateDevice(&ObjectReservation());

    create_info = builder.MakeCreateInfo(VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT);
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkPipelineCacheCreateInfo-flags-05044");
    TestCreateDevice(&ObjectReservation());
}
