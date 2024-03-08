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

TEST_F(VkSCPositiveLayerTest, PipelineCacheCreateInfo) {
    TEST_DESCRIPTION("Test that we can create pipeline caches based on the infos specified at device create time");

    const uint32_t pc_create_info_count = 50;
    const uint32_t pc_create_infos_per_object_reservation_info = 10;
    const uint32_t additional_object_reservation_infos = pc_create_info_count / pc_create_infos_per_object_reservation_info;

    std::vector<VkDeviceObjectReservationCreateInfo> object_reservation_infos{};
    object_reservation_infos.reserve(1 + additional_object_reservation_infos);
    object_reservation_infos.push_back(vksc::GetDefaultObjectReservationCreateInfo());

    std::vector<VkPipelineCacheCreateInfo> pc_create_infos{};
    std::vector<vksc::PipelineCacheBuilder> builders(pc_create_info_count);
    for (uint32_t i = 0; i < pc_create_info_count; ++i) {
        auto header = builders[i].AddDefaultHeaderVersionSCOne();
        builders[i].AddPipelineEntry(header, "1265a236-e369-11ed-b5ea-0242ac120002", 4000);
        pc_create_infos.push_back(builders[i].MakeCreateInfo());
    }

    for (uint32_t i = 0; i < additional_object_reservation_infos; ++i) {
        auto object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>();
        object_reservation_info.pNext = &object_reservation_infos.back();
        object_reservation_info.pipelineCacheCreateInfoCount = pc_create_infos_per_object_reservation_info;
        object_reservation_info.pPipelineCacheCreateInfos = &pc_create_infos[i * pc_create_infos_per_object_reservation_info];
        object_reservation_infos.push_back(object_reservation_info);
    }

    RETURN_IF_SKIP(InitFramework());
    ASSERT_NO_FATAL_FAILURE(InitState(nullptr, &object_reservation_infos.back()));

    for (uint32_t i = 0; i < pc_create_info_count; ++i) {
        VkPipelineCache pipeline_cache = VK_NULL_HANDLE;
        vksc::CreatePipelineCache(m_device->handle(), &pc_create_infos[i], nullptr, &pipeline_cache);
        vksc::DestroyPipelineCache(m_device->handle(), pipeline_cache, nullptr);
    }
}
