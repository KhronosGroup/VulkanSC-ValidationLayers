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

// NOTE: These test cases have been ported from the upstream Vulkan test cases with the same name
// due to parts of the test cases testing scenarios that don't apply to Vulkan SC or otherwise
// the tests needed to be modified.
// In the future, we can consider refactoring the upstream test cases to separate out sub-cases
// which don't apply to Vulkan SC or parameterize them accordingly.

class VkSCPortedLayerTest : public VkLayerTest {};
class NegativeImage : public ImageTest {};
class VkSCPortedNegativeImage : public NegativeImage {};
class NegativeMemory : public VkLayerTest {};
class VkSCPortedNegativeMemory : public NegativeMemory {};

TEST_F(VkSCPortedLayerTest, SpecLinks) {
    TEST_DESCRIPTION("Test that spec links in a typical error message are well-formed");
    RETURN_IF_SKIP(Init());

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "registry/VulkanSC/specs");
    vksc::GetPhysicalDeviceFeatures(Gpu(), NULL);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCPortedLayerTest, LeakAnObject) {
    TEST_DESCRIPTION("Create a fence and destroy its device without first destroying the fence.");

    RETURN_IF_SKIP(InitFramework())
    if (!IsPlatformMockICD()) {
        // This test leaks a fence (on purpose) and should not be run on a real driver
        GTEST_SKIP() << "This test only runs on the mock ICD";
    }

    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vksc::GetDefaultObjectReservationCreateInfo();
    object_reservation_info.pNext = &sc_10_features;

    const float q_priority[] = {1.0f};
    VkDeviceQueueCreateInfo queue_ci = vku::InitStruct<VkDeviceQueueCreateInfo>();
    queue_ci.queueFamilyIndex = 0;
    queue_ci.queueCount = 1;
    queue_ci.pQueuePriorities = q_priority;

    VkDeviceCreateInfo device_ci = vku::InitStruct<VkDeviceCreateInfo>(&object_reservation_info);
    device_ci.queueCreateInfoCount = 1;
    device_ci.pQueueCreateInfos = &queue_ci;

    VkDevice leaky_device;
    ASSERT_EQ(VK_SUCCESS, vksc::CreateDevice(Gpu(), &device_ci, nullptr, &leaky_device));

    const VkFenceCreateInfo fence_ci = vku::InitStruct<VkFenceCreateInfo>();
    VkFence leaked_fence;
    ASSERT_EQ(VK_SUCCESS, vksc::CreateFence(leaky_device, &fence_ci, nullptr, &leaked_fence));

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkDestroyDevice-device-05137");
    vksc::DestroyDevice(leaky_device, nullptr);
    m_errorMonitor->VerifyFound();

    // There's no way we can destroy the fence at this point. Even though DestroyDevice failed, the loader has already removed
    // references to the device
    m_errorMonitor->SetUnexpectedError("VUID-vkDestroyDevice-device-05137");
    m_errorMonitor->SetUnexpectedError("UNASSIGNED-ObjectTracker-ObjectLeak");
}

TEST_F(VkSCPortedNegativeImage, ImageMisc) {
    TEST_DESCRIPTION("Misc leftover valid usage errors in VkImageCreateInfo struct");

    VkPhysicalDeviceFeatures features{};
    ASSERT_NO_FATAL_FAILURE(Init(&features));

    const VkImageCreateInfo safe_image_ci = DefaultImageInfo();

    ASSERT_EQ(VK_SUCCESS, GPDIFPHelper(Gpu(), &safe_image_ci));

    {
        VkImageCreateInfo image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;  // always has 4 samples support
        image_ci.samples = VK_SAMPLE_COUNT_4_BIT;
        image_ci.imageType = VK_IMAGE_TYPE_3D;
        image_ci.extent = {4, 4, 4};
        CreateImageTest(image_ci, "VUID-VkImageCreateInfo-samples-02257");

        image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;  // always has 4 samples support
        image_ci.samples = VK_SAMPLE_COUNT_4_BIT;
        image_ci.flags = VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT;
        image_ci.arrayLayers = 6;
        CreateImageTest(image_ci, "VUID-VkImageCreateInfo-samples-02257");

        image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;  // always has 4 samples support
        image_ci.samples = VK_SAMPLE_COUNT_4_BIT;
        image_ci.tiling = VK_IMAGE_TILING_LINEAR;
        CreateImageTest(image_ci, "VUID-VkImageCreateInfo-samples-02257");

        image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;  // always has 4 samples support
        image_ci.samples = VK_SAMPLE_COUNT_4_BIT;
        image_ci.mipLevels = 2;
        CreateImageTest(image_ci, "VUID-VkImageCreateInfo-samples-02257");

        image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        image_ci.samples = VK_SAMPLE_COUNT_4_BIT;
        image_ci.mipLevels = 1;
        image_ci.tiling = VK_IMAGE_TILING_LINEAR;
        CreateImageTest(image_ci, "VUID-VkImageCreateInfo-samples-02257");
    }

    {
        VkImageCreateInfo image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        image_ci.usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
        CreateImageTest(image_ci, "VUID-VkImageCreateInfo-usage-00963");

        image_ci.usage = VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT;
        CreateImageTest(image_ci, "VUID-VkImageCreateInfo-usage-00966");

        image_ci.usage = VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT;
        image_ci.usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkImageCreateInfo-usage-00963");
        CreateImageTest(image_ci, "VUID-VkImageCreateInfo-usage-00966");
    }

    // InitialLayout not VK_IMAGE_LAYOUT_UNDEFINED or VK_IMAGE_LAYOUT_PREDEFINED
    {
        VkImageCreateInfo image_ci = safe_image_ci;
        image_ci.initialLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
        CreateImageTest(image_ci, "VUID-VkImageCreateInfo-initialLayout-00993");
    }

    // Storage usage can't be multisample if feature not set
    {
        // Feature should not have been set for these tests
        ASSERT_TRUE(features.shaderStorageImageMultisample == VK_FALSE);
        VkImageCreateInfo image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_STORAGE_BIT;
        image_ci.samples = VK_SAMPLE_COUNT_2_BIT;
        CreateImageTest(image_ci, "VUID-VkImageCreateInfo-usage-00968");
    }
}

TEST_F(VkSCPortedNegativeMemory, BindMemory) {
    RETURN_IF_SKIP(Init());

    VkImageCreateInfo image_create_info =
        vkt::Image::ImageCreateInfo2D(256, 256, 1, 1, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_USAGE_SAMPLED_BIT);
    auto buffer_create_info = vkt::Buffer::CreateInfo(4 * 1024 * 1024, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);

    // Try to bind memory to an object that already has a memory binding
    {
        vkt::Image image(*m_device, image_create_info, vkt::no_mem);
        vkt::Buffer buffer(*m_device, buffer_create_info, vkt::no_mem);

        VkMemoryRequirements image_mem_reqs = {}, buffer_mem_reqs = {};
        vk::GetImageMemoryRequirements(device(), image, &image_mem_reqs);
        vk::GetBufferMemoryRequirements(device(), buffer, &buffer_mem_reqs);
        VkMemoryAllocateInfo image_alloc_info = vku::InitStructHelper();
        VkMemoryAllocateInfo buffer_alloc_info = vku::InitStructHelper();
        image_alloc_info.allocationSize = image_mem_reqs.size;
        buffer_alloc_info.allocationSize = buffer_mem_reqs.size;
        m_device->Physical().SetMemoryType(image_mem_reqs.memoryTypeBits, &image_alloc_info, 0);
        m_device->Physical().SetMemoryType(buffer_mem_reqs.memoryTypeBits, &buffer_alloc_info, 0);

        vkt::DeviceMemory image_mem(*m_device, image_alloc_info);
        vkt::DeviceMemory buffer_mem(*m_device, buffer_alloc_info);

        vk::BindImageMemory(device(), image, image_mem.handle(), 0);
        m_errorMonitor->SetDesiredError("VUID-vkBindImageMemory-image-07460");
        vk::BindImageMemory(device(), image, image_mem.handle(), 0);
        m_errorMonitor->VerifyFound();

        vk::BindBufferMemory(device(), buffer, buffer_mem.handle(), 0);
        m_errorMonitor->SetDesiredError("VUID-vkBindBufferMemory-buffer-07459");
        vk::BindBufferMemory(device(), buffer, buffer_mem.handle(), 0);
        m_errorMonitor->VerifyFound();
    }

    // Try to bind memory to an object with an invalid memoryOffset
    {
        vkt::Image image(*m_device, image_create_info, vkt::no_mem);
        vkt::Buffer buffer(*m_device, buffer_create_info, vkt::no_mem);

        VkMemoryRequirements image_mem_reqs = {}, buffer_mem_reqs = {};
        vk::GetImageMemoryRequirements(device(), image, &image_mem_reqs);
        vk::GetBufferMemoryRequirements(device(), buffer, &buffer_mem_reqs);
        VkMemoryAllocateInfo image_alloc_info = vku::InitStructHelper();
        VkMemoryAllocateInfo buffer_alloc_info = vku::InitStructHelper();
        // Leave some extra space for alignment wiggle room
        image_alloc_info.allocationSize = image_mem_reqs.size + image_mem_reqs.alignment;
        buffer_alloc_info.allocationSize = buffer_mem_reqs.size + buffer_mem_reqs.alignment;
        m_device->Physical().SetMemoryType(image_mem_reqs.memoryTypeBits, &image_alloc_info, 0);
        m_device->Physical().SetMemoryType(buffer_mem_reqs.memoryTypeBits, &buffer_alloc_info, 0);
        vkt::DeviceMemory image_mem(*m_device, image_alloc_info);
        vkt::DeviceMemory buffer_mem(*m_device, buffer_alloc_info);

        // Test unaligned memory offset
        {
            if (image_mem_reqs.alignment > 1) {
                VkDeviceSize image_offset = 1;
                m_errorMonitor->SetDesiredError("VUID-vkBindImageMemory-None-10735");
                vk::BindImageMemory(device(), image, image_mem.handle(), image_offset);
                m_errorMonitor->VerifyFound();
            }

            if (buffer_mem_reqs.alignment > 1) {
                VkDeviceSize buffer_offset = 1;
                m_errorMonitor->SetDesiredError("VUID-vkBindBufferMemory-None-10739");
                vk::BindBufferMemory(device(), buffer, buffer_mem.handle(), buffer_offset);
                m_errorMonitor->VerifyFound();
            }
        }

        // Test memory offsets outside the memory allocation
        {
            VkDeviceSize image_offset =
                (image_alloc_info.allocationSize + image_mem_reqs.alignment) & ~(image_mem_reqs.alignment - 1);
            m_errorMonitor->SetDesiredError("VUID-vkBindImageMemory-memoryOffset-01046");
            vk::BindImageMemory(device(), image, image_mem.handle(), image_offset);
            m_errorMonitor->VerifyFound();

            VkDeviceSize buffer_offset =
                (buffer_alloc_info.allocationSize + buffer_mem_reqs.alignment) & ~(buffer_mem_reqs.alignment - 1);
            m_errorMonitor->SetDesiredError("VUID-vkBindBufferMemory-memoryOffset-01031");
            vk::BindBufferMemory(device(), buffer, buffer_mem.handle(), buffer_offset);
            m_errorMonitor->VerifyFound();
        }

        // Test memory offsets within the memory allocation, but which leave too little memory for
        // the resource.
        {
            VkDeviceSize image_offset = (image_mem_reqs.size - 1) & ~(image_mem_reqs.alignment - 1);
            if ((image_offset > 0) && (image_mem_reqs.size < (image_alloc_info.allocationSize - image_mem_reqs.alignment))) {
                m_errorMonitor->SetDesiredError("VUID-vkBindImageMemory-None-10737");
                vk::BindImageMemory(device(), image, image_mem.handle(), image_offset);
                m_errorMonitor->VerifyFound();
            }

            VkDeviceSize buffer_offset = (buffer_mem_reqs.size - 1) & ~(buffer_mem_reqs.alignment - 1);
            if (buffer_offset > 0) {
                m_errorMonitor->SetDesiredError("VUID-vkBindBufferMemory-None-10741");
                vk::BindBufferMemory(device(), buffer, buffer_mem.handle(), buffer_offset);
                m_errorMonitor->VerifyFound();
            }
        }
    }
}

TEST_F(VkSCPortedLayerTest, MissingCreateInfo) {
    RETURN_IF_SKIP(Init());

    VkBuffer buffer;
    m_errorMonitor->SetDesiredError("VUID-vkCreateBuffer-pCreateInfo-parameter");
    vk::CreateBuffer(device(), nullptr, nullptr, &buffer);
    m_errorMonitor->VerifyFound();

    VkImage image;
    m_errorMonitor->SetDesiredError("VUID-vkCreateImage-pCreateInfo-parameter");
    vk::CreateImage(device(), nullptr, nullptr, &image);
    m_errorMonitor->VerifyFound();

    VkBufferView buffer_view;
    m_errorMonitor->SetDesiredError("VUID-vkCreateBufferView-pCreateInfo-parameter");
    vk::CreateBufferView(device(), nullptr, nullptr, &buffer_view);
    m_errorMonitor->VerifyFound();

    VkImageView image_view;
    m_errorMonitor->SetDesiredError("VUID-vkCreateImageView-pCreateInfo-parameter");
    vk::CreateImageView(device(), nullptr, nullptr, &image_view);
    m_errorMonitor->VerifyFound();

    VkRenderPass render_pass;
    m_errorMonitor->SetDesiredError("VUID-vkCreateRenderPass-pCreateInfo-parameter");
    vk::CreateRenderPass(device(), nullptr, nullptr, &render_pass);
    m_errorMonitor->VerifyFound();

    VkFramebuffer framebuffer;
    m_errorMonitor->SetDesiredError("VUID-vkCreateFramebuffer-pCreateInfo-parameter");
    vk::CreateFramebuffer(device(), nullptr, nullptr, &framebuffer);
    m_errorMonitor->VerifyFound();

    VkQueryPool query_pool;
    m_errorMonitor->SetDesiredError("VUID-vkCreateQueryPool-pCreateInfo-parameter");
    vk::CreateQueryPool(device(), nullptr, nullptr, &query_pool);
    m_errorMonitor->VerifyFound();

    VkPipelineLayout pipeline_layout;
    m_errorMonitor->SetDesiredError("VUID-vkCreatePipelineLayout-pCreateInfo-parameter");
    vk::CreatePipelineLayout(device(), nullptr, nullptr, &pipeline_layout);
    m_errorMonitor->VerifyFound();

    VkPipelineCache pipeline_cache;
    m_errorMonitor->SetDesiredError("VUID-vkCreatePipelineCache-pCreateInfo-parameter");
    vk::CreatePipelineCache(device(), nullptr, nullptr, &pipeline_cache);
    m_errorMonitor->VerifyFound();

    VkFence fence;
    m_errorMonitor->SetDesiredError("VUID-vkCreateFence-pCreateInfo-parameter");
    vk::CreateFence(device(), nullptr, nullptr, &fence);
    m_errorMonitor->VerifyFound();

    VkSemaphore semaphore;
    m_errorMonitor->SetDesiredError("VUID-vkCreateSemaphore-pCreateInfo-parameter");
    vk::CreateSemaphore(device(), nullptr, nullptr, &semaphore);
    m_errorMonitor->VerifyFound();

    VkEvent event;
    m_errorMonitor->SetDesiredError("VUID-vkCreateEvent-pCreateInfo-parameter");
    vk::CreateEvent(device(), nullptr, nullptr, &event);
    m_errorMonitor->VerifyFound();

    VkSampler sampler;
    m_errorMonitor->SetDesiredError("VUID-vkCreateSampler-pCreateInfo-parameter");
    vk::CreateSampler(device(), nullptr, nullptr, &sampler);
    m_errorMonitor->VerifyFound();

    VkCommandPool command_pool;
    m_errorMonitor->SetDesiredError("VUID-vkCreateCommandPool-pCreateInfo-parameter");
    vk::CreateCommandPool(device(), nullptr, nullptr, &command_pool);
    m_errorMonitor->VerifyFound();

    VkDescriptorSetLayout set_layout;
    m_errorMonitor->SetDesiredError("VUID-vkCreateDescriptorSetLayout-pCreateInfo-parameter");
    vk::CreateDescriptorSetLayout(device(), nullptr, nullptr, &set_layout);
    m_errorMonitor->VerifyFound();

    VkDescriptorPool descriptor_pool;
    m_errorMonitor->SetDesiredError("VUID-vkCreateDescriptorPool-pCreateInfo-parameter");
    vk::CreateDescriptorPool(device(), nullptr, nullptr, &descriptor_pool);
    m_errorMonitor->VerifyFound();

    VkCommandBuffer command_buffer;
    m_errorMonitor->SetDesiredError("VUID-vkAllocateCommandBuffers-pAllocateInfo-parameter");
    vk::AllocateCommandBuffers(device(), nullptr, &command_buffer);
    m_errorMonitor->VerifyFound();

    // TODO - vvl::AllocateDescriptorSetsData currently doesn't null check pAllocateInfo
    // VkDescriptorSet descriptor_set;
    // m_errorMonitor->SetDesiredError("VUID-vkAllocateDescriptorSets-pAllocateInfo-parameter");
    // vk::AllocateDescriptorSets(device(), nullptr, &descriptor_set);
    // m_errorMonitor->VerifyFound();

    VkDeviceMemory device_memory;
    m_errorMonitor->SetDesiredError("VUID-vkAllocateMemory-pAllocateInfo-parameter");
    vk::AllocateMemory(device(), nullptr, nullptr, &device_memory);
    m_errorMonitor->VerifyFound();

    VkPipeline pipeline;
    m_errorMonitor->SetDesiredError("VUID-vkCreateGraphicsPipelines-pCreateInfos-parameter");
    vk::CreateGraphicsPipelines(device(), GetDefaultPipelineCache(), 1, nullptr, nullptr, &pipeline);
    m_errorMonitor->VerifyFound();

    m_errorMonitor->SetDesiredError("VUID-vkCreateComputePipelines-pCreateInfos-parameter");
    vk::CreateComputePipelines(device(), GetDefaultPipelineCache(), 1, nullptr, nullptr, &pipeline);
    m_errorMonitor->VerifyFound();
}
