/*
 * Copyright (c) 2023-2023 The Khronos Group Inc.
 * Copyright (c) 2023-2023 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#include "../framework/vksc_layer_validation_tests.h"

TEST_F(VkSCLayerTest, CreateCommandPoolMissingMemoryReservationInfo) {
    TEST_DESCRIPTION("vkCreateCommandPool - missing VkCommandPoolMemoryReservationCreateInfo");

    ASSERT_NO_FATAL_FAILURE(Init());

    auto create_info = LvlInitStruct<VkCommandPoolCreateInfo>();
    VkCommandPool cmd_pool = VK_NULL_HANDLE;

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkCommandPoolCreateInfo-pNext-05002");
    vksc::CreateCommandPool(m_device->device(), &create_info, nullptr, &cmd_pool);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCLayerTest, CreateCommandPoolInvalidReservedSize) {
    TEST_DESCRIPTION("vkCreateCommandPool - commandPoolReservedSize is zero");

    ASSERT_NO_FATAL_FAILURE(Init());

    auto mem_reservation_info = LvlInitStruct<VkCommandPoolMemoryReservationCreateInfo>();
    mem_reservation_info.commandPoolReservedSize = 0;
    mem_reservation_info.commandPoolMaxCommandBuffers = 1;

    auto create_info = LvlInitStruct<VkCommandPoolCreateInfo>(&mem_reservation_info);
    VkCommandPool cmd_pool = VK_NULL_HANDLE;

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkCommandPoolMemoryReservationCreateInfo-commandPoolReservedSize-05003");
    vksc::CreateCommandPool(m_device->device(), &create_info, nullptr, &cmd_pool);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCLayerTest, CreateCommandPoolInvalidMaxCommandBuffers) {
    TEST_DESCRIPTION("vkCreateCommandPool - commandPoolMaxCommandBuffers is zero or greater than maxCommandPoolCommandBuffers");

    ASSERT_NO_FATAL_FAILURE(Init());

    auto mem_reservation_info = LvlInitStruct<VkCommandPoolMemoryReservationCreateInfo>();
    mem_reservation_info.commandPoolReservedSize = 16 * 1024 * 1024;
    mem_reservation_info.commandPoolMaxCommandBuffers = 1;

    auto create_info = LvlInitStruct<VkCommandPoolCreateInfo>(&mem_reservation_info);
    VkCommandPool cmd_pool = VK_NULL_HANDLE;

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit,
                                         "VUID-VkCommandPoolMemoryReservationCreateInfo-commandPoolMaxCommandBuffers-05004");
    mem_reservation_info.commandPoolMaxCommandBuffers = 0;
    vksc::CreateCommandPool(m_device->device(), &create_info, nullptr, &cmd_pool);
    m_errorMonitor->VerifyFound();

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit,
                                         "VUID-VkCommandPoolMemoryReservationCreateInfo-commandPoolMaxCommandBuffers-05090");
    mem_reservation_info.commandPoolMaxCommandBuffers = GetVulkanSC10Properties(gpu()).maxCommandPoolCommandBuffers + 1;
    vksc::CreateCommandPool(m_device->device(), &create_info, nullptr, &cmd_pool);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCLayerTest, AllocateCommandBuffersExceededMaxCommandBuffers) {
    TEST_DESCRIPTION("vkAllocateCommandBuffers - cannot allocate more command buffers from pool than commandPoolMaxCommandBuffers");

    ASSERT_NO_FATAL_FAILURE(Init());

    const uint32_t max_cmd_buffers = 13;

    auto mem_reservation_info = LvlInitStruct<VkCommandPoolMemoryReservationCreateInfo>();
    mem_reservation_info.commandPoolReservedSize = 16 * 1024 * 1024;
    mem_reservation_info.commandPoolMaxCommandBuffers = max_cmd_buffers;

    auto create_info = LvlInitStruct<VkCommandPoolCreateInfo>(&mem_reservation_info);

    vk_testing::CommandPool cmd_pool(*m_device, create_info);

    auto alloc_info = LvlInitStruct<VkCommandBufferAllocateInfo>();
    alloc_info.commandPool = cmd_pool.handle();

    VkCommandBuffer cmd_buffers[max_cmd_buffers + 1];
    vk_testing::CommandBuffer tmp_cmd_buffers[max_cmd_buffers];
    uint32_t avail_cmd_buffers = max_cmd_buffers;

    // Cannot allocate more than reserved
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkCommandBufferAllocateInfo-commandPool-05006");
    alloc_info.commandBufferCount = max_cmd_buffers + 1;
    vksc::AllocateCommandBuffers(m_device->device(), &alloc_info, cmd_buffers);
    m_errorMonitor->VerifyFound();

    // Allocate some command buffers and try to allocate more than remaining
    for (uint32_t i = 0; i < max_cmd_buffers; ++i) {
        alloc_info.commandBufferCount = 1;
        tmp_cmd_buffers[i].init(*m_device, alloc_info);
        avail_cmd_buffers--;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkCommandBufferAllocateInfo-commandPool-05006");
        alloc_info.commandBufferCount = avail_cmd_buffers + 1;
        vksc::AllocateCommandBuffers(m_device->device(), &alloc_info, cmd_buffers);
        m_errorMonitor->VerifyFound();
    }

    // Check that freeing command buffers makes exactly as many more available again as expected
    for (uint32_t i = 0; i < max_cmd_buffers / 4; ++i) {
        uint32_t cmd_buffers_to_free = i * 4;
        for (uint32_t j = 0; j < cmd_buffers_to_free; ++j) {
            tmp_cmd_buffers[j].destroy();
            avail_cmd_buffers++;
        }

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkCommandBufferAllocateInfo-commandPool-05006");
        alloc_info.commandBufferCount = avail_cmd_buffers + 1;
        vksc::AllocateCommandBuffers(m_device->device(), &alloc_info, cmd_buffers);
        m_errorMonitor->VerifyFound();

        for (uint32_t j = 0; j < cmd_buffers_to_free; ++j) {
            alloc_info.commandBufferCount = 1;
            tmp_cmd_buffers[j].init(*m_device, alloc_info);
            avail_cmd_buffers--;
        }
    }
}

TEST_F(VkSCLayerTest, ResetCommandBufferNotSupported) {
    TEST_DESCRIPTION("vkReset/BeginCommandBuffer - commandPoolResetCommandBuffer not supported");

    ASSERT_NO_FATAL_FAILURE(Init());

    if (GetVulkanSC10Properties(gpu()).commandPoolResetCommandBuffer) {
        GTEST_SKIP() << "Only applicable if commandPoolResetCommandBuffer is not supported";
    }

    auto mem_reservation_info = LvlInitStruct<VkCommandPoolMemoryReservationCreateInfo>();
    mem_reservation_info.commandPoolReservedSize = 1024 * 1024;
    mem_reservation_info.commandPoolMaxCommandBuffers = 1;
    auto create_info = LvlInitStruct<VkCommandPoolCreateInfo>(&mem_reservation_info);
    create_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    vk_testing::CommandPool cmd_pool(*m_device, create_info);

    auto alloc_info = LvlInitStruct<VkCommandBufferAllocateInfo>();
    alloc_info.commandPool = cmd_pool.handle();
    alloc_info.commandBufferCount = 1;
    vk_testing::CommandBuffer cmd_buffer(*m_device, alloc_info);

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkResetCommandBuffer-commandPoolResetCommandBuffer-05135");
    vksc::ResetCommandBuffer(cmd_buffer.handle(), 0);
    m_errorMonitor->VerifyFound();

    auto begin_info = LvlInitStruct<VkCommandBufferBeginInfo>();
    vksc::BeginCommandBuffer(cmd_buffer.handle(), &begin_info);
    vksc::EndCommandBuffer(cmd_buffer.handle());

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBeginCommandBuffer-commandPoolResetCommandBuffer-05136");
    vksc::BeginCommandBuffer(cmd_buffer.handle(), &begin_info);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCLayerTest, CommandPoolMultipleRecordingNotSupported) {
    TEST_DESCRIPTION("vkBeginCommandBuffer - commandPoolMultipleCommandBuffersRecording not supported");

    ASSERT_NO_FATAL_FAILURE(Init());

    if (GetVulkanSC10Properties(gpu()).commandPoolMultipleCommandBuffersRecording) {
        GTEST_SKIP() << "Only applicable if commandPoolMultipleCommandBuffersRecording is not supported";
    }

    auto mem_reservation_info = LvlInitStruct<VkCommandPoolMemoryReservationCreateInfo>();
    mem_reservation_info.commandPoolReservedSize = 1024 * 1024;
    mem_reservation_info.commandPoolMaxCommandBuffers = 2;
    auto create_info = LvlInitStruct<VkCommandPoolCreateInfo>(&mem_reservation_info);
    create_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    vk_testing::CommandPool cmd_pool1(*m_device, create_info);
    vk_testing::CommandPool cmd_pool2(*m_device, create_info);

    auto alloc_info = LvlInitStruct<VkCommandBufferAllocateInfo>();
    alloc_info.commandPool = cmd_pool1.handle();
    alloc_info.commandBufferCount = 1;
    vk_testing::CommandBuffer cb1(*m_device, alloc_info);
    vk_testing::CommandBuffer cb2(*m_device, alloc_info);

    alloc_info.commandPool = cmd_pool2.handle();
    vk_testing::CommandBuffer cb_other_pool(*m_device, alloc_info);

    auto begin_info = LvlInitStruct<VkCommandBufferBeginInfo>();

    cb1.begin();
    cb_other_pool.begin();

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBeginCommandBuffer-commandPoolMultipleCommandBuffersRecording-05007");
    vksc::BeginCommandBuffer(cb2.handle(), &begin_info);
    m_errorMonitor->VerifyFound();

    cb1.end();
    cb_other_pool.end();
}

TEST_F(VkSCLayerTest, SimulatenousUseNotSupported) {
    TEST_DESCRIPTION("vkBeginCommandBuffer - commandBufferSimultaneousUse not supported");

    ASSERT_NO_FATAL_FAILURE(Init());

    if (GetVulkanSC10Properties(gpu()).commandBufferSimultaneousUse) {
        GTEST_SKIP() << "Only applicable if commandBufferSimultaneousUse is not supported";
    }

    auto mem_reservation_info = LvlInitStruct<VkCommandPoolMemoryReservationCreateInfo>();
    mem_reservation_info.commandPoolReservedSize = 1024 * 1024;
    mem_reservation_info.commandPoolMaxCommandBuffers = 1;
    auto create_info = LvlInitStruct<VkCommandPoolCreateInfo>(&mem_reservation_info);
    create_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    vk_testing::CommandPool cmd_pool(*m_device, create_info);

    auto alloc_info = LvlInitStruct<VkCommandBufferAllocateInfo>();
    alloc_info.commandPool = cmd_pool.handle();
    alloc_info.commandBufferCount = 1;
    vk_testing::CommandBuffer cmd_buffer(*m_device, alloc_info);

    auto begin_info = LvlInitStruct<VkCommandBufferBeginInfo>();
    begin_info.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBeginCommandBuffer-commandBufferSimultaneousUse-05008");
    vksc::BeginCommandBuffer(cmd_buffer.handle(), &begin_info);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCLayerTest, SecondaryCommandBufferNullOrImagelessFramebuffer) {
    TEST_DESCRIPTION("vkBeginCommandBuffer - test effects of secondaryCommandBufferNullOrImagelessFramebuffer");

    ASSERT_NO_FATAL_FAILURE(InitFramework());

    auto imageless_fb_features = LvlInitStruct<VkPhysicalDeviceImagelessFramebufferFeaturesKHR>();
    auto features2 = GetPhysicalDeviceFeatures2(imageless_fb_features);

    ASSERT_NO_FATAL_FAILURE(InitState(nullptr, &features2));

    auto mem_reservation_info = LvlInitStruct<VkCommandPoolMemoryReservationCreateInfo>();
    mem_reservation_info.commandPoolReservedSize = 1024 * 1024;
    mem_reservation_info.commandPoolMaxCommandBuffers = 1;
    auto create_info = LvlInitStruct<VkCommandPoolCreateInfo>(&mem_reservation_info);
    create_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    vk_testing::CommandPool cmd_pool(*m_device, create_info);

    auto alloc_info = LvlInitStruct<VkCommandBufferAllocateInfo>();
    alloc_info.commandPool = cmd_pool.handle();
    alloc_info.level = VK_COMMAND_BUFFER_LEVEL_SECONDARY;
    alloc_info.commandBufferCount = 1;
    vk_testing::CommandBuffer cmd_buffer(*m_device, alloc_info);

    VkAttachmentDescription attachment{0,
                                       VK_FORMAT_R8G8B8A8_UNORM,
                                       VK_SAMPLE_COUNT_1_BIT,
                                       VK_ATTACHMENT_LOAD_OP_DONT_CARE,
                                       VK_ATTACHMENT_STORE_OP_DONT_CARE,
                                       VK_ATTACHMENT_LOAD_OP_DONT_CARE,
                                       VK_ATTACHMENT_STORE_OP_DONT_CARE,
                                       VK_IMAGE_LAYOUT_UNDEFINED,
                                       VK_IMAGE_LAYOUT_GENERAL};
    VkSubpassDescription subpasses[2] = {};

    auto renderpass_ci = LvlInitStruct<VkRenderPassCreateInfo>();
    renderpass_ci.subpassCount = 1;
    renderpass_ci.pSubpasses = &subpasses[0];
    renderpass_ci.attachmentCount = 1;
    renderpass_ci.pAttachments = &attachment;
    vk_testing::RenderPass renderpass1(*m_device, renderpass_ci);

    renderpass_ci.subpassCount = 2;
    vk_testing::RenderPass renderpass2(*m_device, renderpass_ci);

    auto image_ci = LvlInitStruct<VkImageCreateInfo>();
    image_ci.imageType = VK_IMAGE_TYPE_2D;
    image_ci.format = VK_FORMAT_R8G8B8A8_UNORM;
    image_ci.extent = {128, 128, 1};
    image_ci.mipLevels = 1;
    image_ci.arrayLayers = 1;
    image_ci.samples = VK_SAMPLE_COUNT_1_BIT;
    image_ci.tiling = VK_IMAGE_TILING_OPTIMAL;
    image_ci.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    image_ci.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    vk_testing::Image image(*m_device, image_ci);

    auto image_view_ci = LvlInitStruct<VkImageViewCreateInfo>();
    image_view_ci.image = image.handle();
    image_view_ci.viewType = VK_IMAGE_VIEW_TYPE_2D;
    image_view_ci.format = VK_FORMAT_R8G8B8A8_UNORM;
    image_view_ci.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};
    vk_testing::ImageView image_view(*m_device, image_view_ci);

    VkImageView fb_attachment = image_view.handle();
    auto framebuffer_ci = LvlInitStruct<VkFramebufferCreateInfo>();
    framebuffer_ci.renderPass = renderpass1;
    framebuffer_ci.attachmentCount = 1;
    framebuffer_ci.pAttachments = &fb_attachment;
    framebuffer_ci.width = 128;
    framebuffer_ci.height = 128;
    framebuffer_ci.layers = 1;
    vk_testing::Framebuffer framebuffer(*m_device, framebuffer_ci);

    auto inherit_info = LvlInitStruct<VkCommandBufferInheritanceInfo>();
    inherit_info.framebuffer = framebuffer;
    inherit_info.renderPass = renderpass2;

    auto begin_info = LvlInitStruct<VkCommandBufferBeginInfo>();
    begin_info.flags = VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT;
    begin_info.pInheritanceInfo = &inherit_info;

    const char *expected_vuid = GetVulkanSC10Properties(gpu()).secondaryCommandBufferNullOrImagelessFramebuffer
                                    ? "VUID-VkCommandBufferBeginInfo-flags-05009"
                                    : "VUID-VkCommandBufferBeginInfo-flags-05010";

    // Check with incompatible render pass
    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, expected_vuid);
    vksc::BeginCommandBuffer(cmd_buffer.handle(), &begin_info);
    m_errorMonitor->VerifyFound();

    if (!GetVulkanSC10Properties(gpu()).secondaryCommandBufferNullOrImagelessFramebuffer) {
        // Check with no framebuffer
        inherit_info.framebuffer = VK_NULL_HANDLE;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, expected_vuid);
        vksc::BeginCommandBuffer(cmd_buffer.handle(), &begin_info);
        m_errorMonitor->VerifyFound();

        // Check with framebuffer created with VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT
        if (imageless_fb_features.imagelessFramebuffer) {
            auto attachment_info = LvlInitStruct<VkFramebufferAttachmentsCreateInfo>();
            framebuffer_ci.pNext = &attachment_info;
            framebuffer_ci.flags = VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT;
            vk_testing::Framebuffer imageless_framebuffer(*m_device, framebuffer_ci);
            inherit_info.framebuffer = imageless_framebuffer;

            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, expected_vuid);
            vksc::BeginCommandBuffer(cmd_buffer.handle(), &begin_info);
            m_errorMonitor->VerifyFound();
        }
    }
}
