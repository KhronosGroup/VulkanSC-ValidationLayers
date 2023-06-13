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

// NOTE: These test cases have been ported from the upstream Vulkan test cases with the same name
// due to parts of the test cases testing scenarios that don't apply to Vulkan SC or otherwise
// the tests needed to be modified.
// In the future, we can consider refactoring the upstream test cases to separate out sub-cases
// which don't apply to Vulkan SC or parameterize them accordingly.

TEST_F(VkSCLayerTest, SpecLinks) {
    TEST_DESCRIPTION("Test that spec links in a typical error message are well-formed");
    ASSERT_NO_FATAL_FAILURE(Init());

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "registry/VulkanSC/specs");
    vk::GetPhysicalDeviceFeatures(gpu(), NULL);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCLayerTest, LeakAnObject) {
    TEST_DESCRIPTION("Create a fence and destroy its device without first destroying the fence.");

    ASSERT_NO_FATAL_FAILURE(InitFramework(m_errorMonitor));
    if (!IsPlatform(kMockICD)) {
        // This test leaks a fence (on purpose) and should not be run on a real driver
        GTEST_SKIP() << "This test only runs on the mock ICD";
    }

    auto sc_10_features = LvlInitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vksc::GetDefaultObjectReservationCreateInfo();
    object_reservation_info.pNext = &sc_10_features;

    const float q_priority[] = {1.0f};
    VkDeviceQueueCreateInfo queue_ci = LvlInitStruct<VkDeviceQueueCreateInfo>();
    queue_ci.queueFamilyIndex = 0;
    queue_ci.queueCount = 1;
    queue_ci.pQueuePriorities = q_priority;

    VkDeviceCreateInfo device_ci = LvlInitStruct<VkDeviceCreateInfo>(&object_reservation_info);
    device_ci.queueCreateInfoCount = 1;
    device_ci.pQueueCreateInfos = &queue_ci;

    VkDevice leaky_device;
    ASSERT_VK_SUCCESS(vksc::CreateDevice(gpu(), &device_ci, nullptr, &leaky_device));

    const VkFenceCreateInfo fence_ci = LvlInitStruct<VkFenceCreateInfo>();
    VkFence leaked_fence;
    ASSERT_VK_SUCCESS(vksc::CreateFence(leaky_device, &fence_ci, nullptr, &leaked_fence));

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkDestroyDevice-device-05137");
    vksc::DestroyDevice(leaky_device, nullptr);
    m_errorMonitor->VerifyFound();

    // There's no way we can destroy the fence at this point. Even though DestroyDevice failed, the loader has already removed
    // references to the device
    m_errorMonitor->SetUnexpectedError("VUID-vkDestroyDevice-device-05137");
    m_errorMonitor->SetUnexpectedError("UNASSIGNED-ObjectTracker-ObjectLeak");
}

TEST_F(VkSCLayerTest, CreateImageMiscErrors) {
    TEST_DESCRIPTION("Misc leftover valid usage errors in VkImageCreateInfo struct");

    VkPhysicalDeviceFeatures features{};
    ASSERT_NO_FATAL_FAILURE(Init(&features));

    VkImageCreateInfo tmp_img_ci = LvlInitStruct<VkImageCreateInfo>();
    tmp_img_ci.flags = 0;                          // assumably any is supported
    tmp_img_ci.imageType = VK_IMAGE_TYPE_2D;       // any is supported
    tmp_img_ci.format = VK_FORMAT_R8G8B8A8_UNORM;  // has mandatory support for all usages
    tmp_img_ci.extent = {64, 64, 1};               // limit is 256 for 3D, or 4096
    tmp_img_ci.mipLevels = 1;                      // any is supported
    tmp_img_ci.arrayLayers = 1;                    // limit is 256
    tmp_img_ci.samples = VK_SAMPLE_COUNT_1_BIT;    // needs to be 1 if TILING_LINEAR
    // if VK_IMAGE_TILING_LINEAR imageType must be 2D, usage must be TRANSFER, and levels layers samplers all 1
    tmp_img_ci.tiling = VK_IMAGE_TILING_OPTIMAL;
    tmp_img_ci.usage = VK_IMAGE_USAGE_TRANSFER_SRC_BIT;  // depends on format
    tmp_img_ci.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    const VkImageCreateInfo safe_image_ci = tmp_img_ci;

    ASSERT_VK_SUCCESS(GPDIFPHelper(gpu(), &safe_image_ci));

    {
        VkImageCreateInfo image_ci = safe_image_ci;
        image_ci.format = VK_FORMAT_UNDEFINED;
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-format-00943");
    }

    {
        VkImageCreateInfo image_ci = safe_image_ci;
        image_ci.flags = VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT;
        image_ci.arrayLayers = 6;
        image_ci.imageType = VK_IMAGE_TYPE_1D;
        image_ci.extent = {64, 1, 1};
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-flags-00949");

        image_ci = safe_image_ci;
        image_ci.flags = VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT;
        image_ci.imageType = VK_IMAGE_TYPE_3D;
        image_ci.extent = {4, 4, 4};
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-flags-00949");
    }

    {
        VkImageCreateInfo image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;  // always has 4 samples support
        image_ci.samples = VK_SAMPLE_COUNT_4_BIT;
        image_ci.imageType = VK_IMAGE_TYPE_3D;
        image_ci.extent = {4, 4, 4};
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-samples-02257");

        image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;  // always has 4 samples support
        image_ci.samples = VK_SAMPLE_COUNT_4_BIT;
        image_ci.flags = VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT;
        image_ci.arrayLayers = 6;
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-samples-02257");

        image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;  // always has 4 samples support
        image_ci.samples = VK_SAMPLE_COUNT_4_BIT;
        image_ci.tiling = VK_IMAGE_TILING_LINEAR;
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-samples-02257");

        image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;  // always has 4 samples support
        image_ci.samples = VK_SAMPLE_COUNT_4_BIT;
        image_ci.mipLevels = 2;
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-samples-02257");

        image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        image_ci.samples = VK_SAMPLE_COUNT_4_BIT;
        image_ci.mipLevels = 1;
        image_ci.tiling = VK_IMAGE_TILING_LINEAR;
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-samples-02257");
    }

    {
        VkImageCreateInfo image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        image_ci.usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-usage-00963");

        image_ci.usage = VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT;
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-usage-00966");

        image_ci.usage = VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT;
        image_ci.usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkImageCreateInfo-usage-00963");
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-usage-00966");
    }

    // InitialLayout not VK_IMAGE_LAYOUT_UNDEFINED or VK_IMAGE_LAYOUT_PREDEFINED
    {
        VkImageCreateInfo image_ci = safe_image_ci;
        image_ci.initialLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-initialLayout-00993");
    }

    // Storage usage can't be multisample if feature not set
    {
        // Feature should not have been set for these tests
        ASSERT_TRUE(features.shaderStorageImageMultisample == VK_FALSE);
        VkImageCreateInfo image_ci = safe_image_ci;
        image_ci.usage = VK_IMAGE_USAGE_STORAGE_BIT;
        image_ci.samples = VK_SAMPLE_COUNT_2_BIT;
        CreateImageTest(*this, &image_ci, "VUID-VkImageCreateInfo-usage-00968");
    }
}

TEST_F(VkSCLayerTest, BindInvalidMemory) {
    VkResult err;
    bool pass;

    AddOptionalExtensions(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
    AddOptionalExtensions(VK_AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME);
    ASSERT_NO_FATAL_FAILURE(InitFramework());

    if (IsExtensionsEnabled(VK_AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME) &&
        IsExtensionsEnabled(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME)) {
        auto coherent_mem_features = LvlInitStruct<VkPhysicalDeviceCoherentMemoryFeaturesAMD>();
        GetPhysicalDeviceFeatures2(coherent_mem_features);
        ASSERT_NO_FATAL_FAILURE(InitState(nullptr, &coherent_mem_features));
    } else {
        ASSERT_NO_FATAL_FAILURE(InitState());
    }

    const VkFormat tex_format = VK_FORMAT_R8G8B8A8_UNORM;
    const int32_t tex_width = 256;
    const int32_t tex_height = 256;

    VkImageCreateInfo image_create_info = LvlInitStruct<VkImageCreateInfo>();
    image_create_info.imageType = VK_IMAGE_TYPE_2D;
    image_create_info.format = tex_format;
    image_create_info.extent.width = tex_width;
    image_create_info.extent.height = tex_height;
    image_create_info.extent.depth = 1;
    image_create_info.mipLevels = 1;
    image_create_info.arrayLayers = 1;
    image_create_info.samples = VK_SAMPLE_COUNT_1_BIT;
    image_create_info.tiling = VK_IMAGE_TILING_OPTIMAL;
    image_create_info.usage = VK_IMAGE_USAGE_SAMPLED_BIT;
    image_create_info.flags = 0;

    VkBufferCreateInfo buffer_create_info = LvlInitStruct<VkBufferCreateInfo>();
    buffer_create_info.flags = 0;
    buffer_create_info.size = 4 * 1024 * 1024;
    buffer_create_info.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
    buffer_create_info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    // Try to bind memory to an object that already has a memory binding
    {
        VkImage image = VK_NULL_HANDLE;
        err = vk::CreateImage(device(), &image_create_info, NULL, &image);
        ASSERT_VK_SUCCESS(err);
        VkBuffer buffer = VK_NULL_HANDLE;
        err = vk::CreateBuffer(device(), &buffer_create_info, NULL, &buffer);
        ASSERT_VK_SUCCESS(err);
        VkMemoryRequirements image_mem_reqs = {}, buffer_mem_reqs = {};
        vk::GetImageMemoryRequirements(device(), image, &image_mem_reqs);
        vk::GetBufferMemoryRequirements(device(), buffer, &buffer_mem_reqs);
        VkMemoryAllocateInfo image_alloc_info = LvlInitStruct<VkMemoryAllocateInfo>();
        VkMemoryAllocateInfo buffer_alloc_info = LvlInitStruct<VkMemoryAllocateInfo>();
        image_alloc_info.allocationSize = image_mem_reqs.size;
        buffer_alloc_info.allocationSize = buffer_mem_reqs.size;
        pass = m_device->phy().set_memory_type(image_mem_reqs.memoryTypeBits, &image_alloc_info, 0);
        ASSERT_TRUE(pass);
        pass = m_device->phy().set_memory_type(buffer_mem_reqs.memoryTypeBits, &buffer_alloc_info, 0);
        ASSERT_TRUE(pass);
        VkDeviceMemory image_mem, buffer_mem;
        err = vk::AllocateMemory(device(), &image_alloc_info, NULL, &image_mem);
        ASSERT_VK_SUCCESS(err);
        err = vk::AllocateMemory(device(), &buffer_alloc_info, NULL, &buffer_mem);
        ASSERT_VK_SUCCESS(err);

        err = vk::BindImageMemory(device(), image, image_mem, 0);
        ASSERT_VK_SUCCESS(err);
        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBindImageMemory-image-07460");
        err = vk::BindImageMemory(device(), image, image_mem, 0);
        (void)err;  // This may very well return an error.
        m_errorMonitor->VerifyFound();

        err = vk::BindBufferMemory(device(), buffer, buffer_mem, 0);
        ASSERT_VK_SUCCESS(err);
        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBindBufferMemory-buffer-07459");
        err = vk::BindBufferMemory(device(), buffer, buffer_mem, 0);
        (void)err;  // This may very well return an error.
        m_errorMonitor->VerifyFound();

        vk::FreeMemory(device(), image_mem, NULL);
        vk::FreeMemory(device(), buffer_mem, NULL);
        vk::DestroyImage(device(), image, NULL);
        vk::DestroyBuffer(device(), buffer, NULL);
    }

    // Try to bind memory to an object with an invalid memoryOffset
    {
        VkImage image = VK_NULL_HANDLE;
        err = vk::CreateImage(device(), &image_create_info, NULL, &image);
        ASSERT_VK_SUCCESS(err);
        VkBuffer buffer = VK_NULL_HANDLE;
        err = vk::CreateBuffer(device(), &buffer_create_info, NULL, &buffer);
        ASSERT_VK_SUCCESS(err);
        VkMemoryRequirements image_mem_reqs = {}, buffer_mem_reqs = {};
        vk::GetImageMemoryRequirements(device(), image, &image_mem_reqs);
        vk::GetBufferMemoryRequirements(device(), buffer, &buffer_mem_reqs);
        VkMemoryAllocateInfo image_alloc_info = LvlInitStruct<VkMemoryAllocateInfo>();
        VkMemoryAllocateInfo buffer_alloc_info = LvlInitStruct<VkMemoryAllocateInfo>();
        // Leave some extra space for alignment wiggle room
        image_alloc_info.allocationSize = image_mem_reqs.size + image_mem_reqs.alignment;
        buffer_alloc_info.allocationSize = buffer_mem_reqs.size + buffer_mem_reqs.alignment;
        pass = m_device->phy().set_memory_type(image_mem_reqs.memoryTypeBits, &image_alloc_info, 0);
        ASSERT_TRUE(pass);
        pass = m_device->phy().set_memory_type(buffer_mem_reqs.memoryTypeBits, &buffer_alloc_info, 0);
        ASSERT_TRUE(pass);
        VkDeviceMemory image_mem, buffer_mem;
        err = vk::AllocateMemory(device(), &image_alloc_info, NULL, &image_mem);
        ASSERT_VK_SUCCESS(err);
        err = vk::AllocateMemory(device(), &buffer_alloc_info, NULL, &buffer_mem);
        ASSERT_VK_SUCCESS(err);

        // Test unaligned memory offset
        {
            if (image_mem_reqs.alignment > 1) {
                VkDeviceSize image_offset = 1;
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBindImageMemory-memoryOffset-01048");
                err = vk::BindImageMemory(device(), image, image_mem, image_offset);
                (void)err;  // This may very well return an error.
                m_errorMonitor->VerifyFound();
            }

            if (buffer_mem_reqs.alignment > 1) {
                VkDeviceSize buffer_offset = 1;
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBindBufferMemory-memoryOffset-01036");
                err = vk::BindBufferMemory(device(), buffer, buffer_mem, buffer_offset);
                (void)err;  // This may very well return an error.
                m_errorMonitor->VerifyFound();
            }
        }

        // Test memory offsets outside the memory allocation
        {
            VkDeviceSize image_offset =
                (image_alloc_info.allocationSize + image_mem_reqs.alignment) & ~(image_mem_reqs.alignment - 1);
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBindImageMemory-memoryOffset-01046");
            err = vk::BindImageMemory(device(), image, image_mem, image_offset);
            (void)err;  // This may very well return an error.
            m_errorMonitor->VerifyFound();

            VkDeviceSize buffer_offset =
                (buffer_alloc_info.allocationSize + buffer_mem_reqs.alignment) & ~(buffer_mem_reqs.alignment - 1);
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBindBufferMemory-memoryOffset-01031");
            err = vk::BindBufferMemory(device(), buffer, buffer_mem, buffer_offset);
            (void)err;  // This may very well return an error.
            m_errorMonitor->VerifyFound();
        }

        // Test memory offsets within the memory allocation, but which leave too little memory for
        // the resource.
        {
            VkDeviceSize image_offset = (image_mem_reqs.size - 1) & ~(image_mem_reqs.alignment - 1);
            if ((image_offset > 0) && (image_mem_reqs.size < (image_alloc_info.allocationSize - image_mem_reqs.alignment))) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBindImageMemory-size-01049");
                err = vk::BindImageMemory(device(), image, image_mem, image_offset);
                (void)err;  // This may very well return an error.
                m_errorMonitor->VerifyFound();
            }

            VkDeviceSize buffer_offset = (buffer_mem_reqs.size - 1) & ~(buffer_mem_reqs.alignment - 1);
            if (buffer_offset > 0) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBindBufferMemory-size-01037");
                err = vk::BindBufferMemory(device(), buffer, buffer_mem, buffer_offset);
                (void)err;  // This may very well return an error.
                m_errorMonitor->VerifyFound();
            }
        }

        vk::FreeMemory(device(), image_mem, NULL);
        vk::FreeMemory(device(), buffer_mem, NULL);
        vk::DestroyImage(device(), image, NULL);
        vk::DestroyBuffer(device(), buffer, NULL);
    }

    // Try to bind memory to an object with an invalid memory type
    {
        VkImage image = VK_NULL_HANDLE;
        err = vk::CreateImage(device(), &image_create_info, NULL, &image);
        ASSERT_VK_SUCCESS(err);
        VkBuffer buffer = VK_NULL_HANDLE;
        err = vk::CreateBuffer(device(), &buffer_create_info, NULL, &buffer);
        ASSERT_VK_SUCCESS(err);
        VkMemoryRequirements image_mem_reqs = {}, buffer_mem_reqs = {};
        vk::GetImageMemoryRequirements(device(), image, &image_mem_reqs);
        vk::GetBufferMemoryRequirements(device(), buffer, &buffer_mem_reqs);
        VkMemoryAllocateInfo image_alloc_info = LvlInitStruct<VkMemoryAllocateInfo>();
        VkMemoryAllocateInfo buffer_alloc_info = LvlInitStruct<VkMemoryAllocateInfo>();
        image_alloc_info.allocationSize = image_mem_reqs.size;
        buffer_alloc_info.allocationSize = buffer_mem_reqs.size;
        // Create a mask of available memory types *not* supported by these resources,
        // and try to use one of them.
        VkPhysicalDeviceMemoryProperties memory_properties = {};
        vk::GetPhysicalDeviceMemoryProperties(m_device->phy().handle(), &memory_properties);
        VkDeviceMemory image_mem, buffer_mem;

        uint32_t image_unsupported_mem_type_bits = ((1 << memory_properties.memoryTypeCount) - 1) & ~image_mem_reqs.memoryTypeBits;
        if (image_unsupported_mem_type_bits != 0) {
            pass = m_device->phy().set_memory_type(image_unsupported_mem_type_bits, &image_alloc_info, 0);
            ASSERT_TRUE(pass);
            err = vk::AllocateMemory(device(), &image_alloc_info, NULL, &image_mem);
            ASSERT_VK_SUCCESS(err);
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBindImageMemory-memory-01047");
            err = vk::BindImageMemory(device(), image, image_mem, 0);
            (void)err;  // This may very well return an error.
            m_errorMonitor->VerifyFound();
            vk::FreeMemory(device(), image_mem, NULL);
        }

        uint32_t buffer_unsupported_mem_type_bits =
            ((1 << memory_properties.memoryTypeCount) - 1) & ~buffer_mem_reqs.memoryTypeBits;
        if (buffer_unsupported_mem_type_bits != 0) {
            pass = m_device->phy().set_memory_type(buffer_unsupported_mem_type_bits, &buffer_alloc_info, 0);
            ASSERT_TRUE(pass);
            err = vk::AllocateMemory(device(), &buffer_alloc_info, NULL, &buffer_mem);
            ASSERT_VK_SUCCESS(err);
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBindBufferMemory-memory-01035");
            err = vk::BindBufferMemory(device(), buffer, buffer_mem, 0);
            (void)err;  // This may very well return an error.
            m_errorMonitor->VerifyFound();
            vk::FreeMemory(device(), buffer_mem, NULL);
        }

        vk::DestroyImage(device(), image, NULL);
        vk::DestroyBuffer(device(), buffer, NULL);
    }

    // Try to bind memory to an image created with sparse memory flags
    {
        VkImageCreateInfo sparse_image_create_info = image_create_info;
        sparse_image_create_info.flags |= VK_IMAGE_CREATE_SPARSE_BINDING_BIT;
        VkImageFormatProperties image_format_properties = {};
        err = vk::GetPhysicalDeviceImageFormatProperties(m_device->phy().handle(), sparse_image_create_info.format,
                                                         sparse_image_create_info.imageType, sparse_image_create_info.tiling,
                                                         sparse_image_create_info.usage, sparse_image_create_info.flags,
                                                         &image_format_properties);
        if (!m_device->phy().features().sparseResidencyImage2D || err == VK_ERROR_FORMAT_NOT_SUPPORTED) {
            // most likely means sparse formats aren't supported here; skip this test.
        } else {
            ASSERT_VK_SUCCESS(err);
            if (image_format_properties.maxExtent.width == 0) {
                GTEST_SKIP() << "Sparse image format not supported";
            } else {
                VkImage sparse_image = VK_NULL_HANDLE;
                err = vk::CreateImage(m_device->device(), &sparse_image_create_info, NULL, &sparse_image);
                ASSERT_VK_SUCCESS(err);
                VkMemoryRequirements sparse_mem_reqs = {};
                vk::GetImageMemoryRequirements(m_device->device(), sparse_image, &sparse_mem_reqs);
                if (sparse_mem_reqs.memoryTypeBits != 0) {
                    VkMemoryAllocateInfo sparse_mem_alloc = LvlInitStruct<VkMemoryAllocateInfo>();
                    sparse_mem_alloc.allocationSize = sparse_mem_reqs.size;
                    sparse_mem_alloc.memoryTypeIndex = 0;
                    pass = m_device->phy().set_memory_type(sparse_mem_reqs.memoryTypeBits, &sparse_mem_alloc, 0);
                    ASSERT_TRUE(pass);
                    VkDeviceMemory sparse_mem = VK_NULL_HANDLE;
                    err = vk::AllocateMemory(m_device->device(), &sparse_mem_alloc, NULL, &sparse_mem);
                    ASSERT_VK_SUCCESS(err);
                    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkBindImageMemory-image-01045");
                    err = vk::BindImageMemory(m_device->device(), sparse_image, sparse_mem, 0);
                    // This may very well return an error.
                    (void)err;
                    m_errorMonitor->VerifyFound();
                    vk::FreeMemory(m_device->device(), sparse_mem, NULL);
                }
                vk::DestroyImage(m_device->device(), sparse_image, NULL);
            }
        }
    }
}
