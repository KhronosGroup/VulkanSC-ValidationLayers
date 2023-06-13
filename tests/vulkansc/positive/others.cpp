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

TEST_F(VkSCPositiveLayerTest, SetNegativeViewport) {
    TEST_DESCRIPTION("vkCmdSetViewport - test that the removed VUID 07917 is not triggered in Vulkan SC");

    ASSERT_NO_FATAL_FAILURE(Init());

    m_commandBuffer->begin();

    using std::vector;
    struct TestCase {
        VkViewport vp;
        std::string veid;
    };

    std::vector<VkViewport> test_cases = {{0.0, 0.0, 64.0, 0.0, 0.0, 1.0}, {0.0, 0.0, 64.0, -1.0, 0.0, 1.0}};

    for (const auto &test_case : test_cases) {
        vksc::CmdSetViewport(m_commandBuffer->handle(), 0, 1, &test_case);
    }

    m_commandBuffer->end();
}

TEST_F(VkSCPositiveLayerTest, CopyBetween2DAnd3DImage) {
    TEST_DESCRIPTION("vkCmdCopyImage - test that the removed VUIDs 07922, 07923, and 07941 are not triggered in Vulkan SC");

    ASSERT_NO_FATAL_FAILURE(Init());

    auto create_info = LvlInitStruct<VkImageCreateInfo>();
    create_info.format = VK_FORMAT_R8G8B8A8_UNORM;
    create_info.mipLevels = 3;
    create_info.samples = VK_SAMPLE_COUNT_1_BIT;
    create_info.tiling = VK_IMAGE_TILING_OPTIMAL;
    create_info.usage = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;

    VkImageObj image2D(m_device);
    create_info.imageType = VK_IMAGE_TYPE_2D;
    create_info.extent = {64, 64, 1};
    create_info.arrayLayers = 10;
    image2D.Init(create_info);

    VkImageObj image3D(m_device);
    create_info.imageType = VK_IMAGE_TYPE_3D;
    create_info.extent = {16, 16, 16};
    create_info.arrayLayers = 1;
    image3D.Init(create_info);

    VkImageCopy region{};

    m_commandBuffer->begin();

    region.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 2, 1, 4};
    region.srcOffset = {3, 4, 0};
    region.dstSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 1, 0, 1};
    region.dstOffset = {2, 1, 1};
    region.extent = {5, 3, 4};

    vksc::CmdCopyImage(m_commandBuffer->handle(), image2D.handle(), VK_IMAGE_LAYOUT_GENERAL, image3D.handle(),
                       VK_IMAGE_LAYOUT_GENERAL, 1, &region);

    region.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
    region.srcOffset = {4, 4, 0};
    region.dstSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 2, 3, 5};
    region.dstOffset = {4, 4, 0};
    region.extent = {8, 8, 5};

    vksc::CmdCopyImage(m_commandBuffer->handle(), image3D.handle(), VK_IMAGE_LAYOUT_GENERAL, image2D.handle(),
                       VK_IMAGE_LAYOUT_GENERAL, 1, &region);

    m_commandBuffer->end();
}

TEST_F(VkSCPositiveLayerTest, CopyImagePlane) {
    TEST_DESCRIPTION("vkCmdCopyImage - test that the removed VUID 07940 is not triggered in Vulkan SC");

    ASSERT_NO_FATAL_FAILURE(Init());

    if (!ImageFormatIsSupported(gpu(), VK_FORMAT_G8_B8R8_2PLANE_420_UNORM)) {
        GTEST_SKIP() << "VK_FORMAT_G8_B8R8_2PLANE_420_UNORM is unsupported";
    }

    auto create_info = LvlInitStruct<VkImageCreateInfo>();
    create_info.imageType = VK_IMAGE_TYPE_2D;
    create_info.extent = {64, 64, 1};
    create_info.mipLevels = 1;
    create_info.arrayLayers = 1;
    create_info.samples = VK_SAMPLE_COUNT_1_BIT;
    create_info.tiling = VK_IMAGE_TILING_OPTIMAL;
    create_info.usage = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;

    VkImageObj imageR8(m_device);
    create_info.format = VK_FORMAT_R8_UNORM;
    imageR8.Init(create_info);

    VkImageObj imageR8G8(m_device);
    create_info.format = VK_FORMAT_R8G8_UNORM;
    imageR8G8.Init(create_info);

    VkImageObj imageNV12(m_device);
    create_info.format = VK_FORMAT_G8_B8R8_2PLANE_420_UNORM;
    imageNV12.Init(create_info);

    VkImageCopy region{};
    region.srcSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
    region.srcOffset = {0, 0, 0};
    region.dstSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1};
    region.dstOffset = {0, 0, 0};
    region.extent = {32, 32, 1};

    m_commandBuffer->begin();

    region.srcSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    region.dstSubresource.aspectMask = VK_IMAGE_ASPECT_PLANE_0_BIT;

    vksc::CmdCopyImage(m_commandBuffer->handle(), imageR8.handle(), VK_IMAGE_LAYOUT_GENERAL, imageNV12.handle(),
                       VK_IMAGE_LAYOUT_GENERAL, 1, &region);

    region.srcSubresource.aspectMask = VK_IMAGE_ASPECT_PLANE_0_BIT;
    region.dstSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;

    vksc::CmdCopyImage(m_commandBuffer->handle(), imageNV12.handle(), VK_IMAGE_LAYOUT_GENERAL, imageR8.handle(),
                       VK_IMAGE_LAYOUT_GENERAL, 1, &region);

    region.srcSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    region.dstSubresource.aspectMask = VK_IMAGE_ASPECT_PLANE_1_BIT;

    vksc::CmdCopyImage(m_commandBuffer->handle(), imageR8G8.handle(), VK_IMAGE_LAYOUT_GENERAL, imageNV12.handle(),
                       VK_IMAGE_LAYOUT_GENERAL, 1, &region);

    region.srcSubresource.aspectMask = VK_IMAGE_ASPECT_PLANE_1_BIT;
    region.dstSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;

    vksc::CmdCopyImage(m_commandBuffer->handle(), imageNV12.handle(), VK_IMAGE_LAYOUT_GENERAL, imageR8G8.handle(),
                       VK_IMAGE_LAYOUT_GENERAL, 1, &region);

    m_commandBuffer->end();
}
