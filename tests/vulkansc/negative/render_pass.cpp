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

TEST_F(VkSCLayerTest, CreateRenderPassMaxRenderPassSubpassesExceeded) {
    TEST_DESCRIPTION(
        "vkCreateRenderPass - VkRenderPassCreateInfo::subpassCount must be "
        "less than or equal to maxRenderPassSubpasses");
    ASSERT_NO_FATAL_FAILURE(InitFramework());

    const auto limit = GetVulkanSC10Properties(gpu()).maxRenderPassSubpasses;
    const auto subpass_count = limit + 1;
    auto sc_10_features = LvlInitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vksc::GetDefaultObjectReservationCreateInfo();
    object_reservation_info.pNext = &sc_10_features;
    object_reservation_info.subpassDescriptionRequestCount = subpass_count;
    ASSERT_NO_FATAL_FAILURE(InitState(nullptr, &object_reservation_info));

    VkRenderPass render_pass{VK_NULL_HANDLE};

    {
        std::vector<VkSubpassDescription> subpasses{subpass_count, VkSubpassDescription{}};
        for (auto& subpass : subpasses) {
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
        }

        auto create_info = LvlInitStruct<VkRenderPassCreateInfo>();
        create_info.pSubpasses = subpasses.data();
        create_info.subpassCount = subpasses.size();

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkRenderPassCreateInfo-subpassCount-05050");
        vksc::CreateRenderPass(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
    {
        std::vector<VkSubpassDescription2> subpasses(subpass_count, LvlInitStruct<VkSubpassDescription2>());
        for (auto& subpass : subpasses) {
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
        }

        auto create_info = LvlInitStruct<VkRenderPassCreateInfo2>();
        create_info.pSubpasses = subpasses.data();
        create_info.subpassCount = subpasses.size();

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkRenderPassCreateInfo2-subpassCount-05055");
        vksc::CreateRenderPass2(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
}

TEST_F(VkSCLayerTest, CreateRenderPassMaxRenderPassDependenciesExceeded) {
    TEST_DESCRIPTION(
        "vkCreateRenderPass - VkRenderPassCreateInfo::dependencyCount must be "
        "less than or equal to maxRenderPassDependencies");
    ASSERT_NO_FATAL_FAILURE(InitFramework());

    const auto limit = GetVulkanSC10Properties(gpu()).maxRenderPassDependencies;
    const auto dependency_count = limit + 1;
    auto sc_10_features = LvlInitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vksc::GetDefaultObjectReservationCreateInfo();
    object_reservation_info.pNext = &sc_10_features;
    ASSERT_NO_FATAL_FAILURE(InitState(nullptr, &object_reservation_info));

    VkRenderPass render_pass{VK_NULL_HANDLE};

    {
        auto subpass = VkSubpassDescription{};
        subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

        std::vector<VkSubpassDependency> dependencies{dependency_count, VkSubpassDependency{}};
        for (auto& dependency : dependencies) {
            dependency.srcSubpass = 0;
            dependency.dstSubpass = 0;
            dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
            dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
            dependency.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            dependency.dependencyFlags = VK_DEPENDENCY_BY_REGION_BIT;
        }

        auto create_info = LvlInitStruct<VkRenderPassCreateInfo>();
        create_info.pDependencies = dependencies.data();
        create_info.dependencyCount = dependencies.size();
        create_info.pSubpasses = &subpass;
        create_info.subpassCount = 1;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkRenderPassCreateInfo-dependencyCount-05051");
        vksc::CreateRenderPass(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
    {
        auto subpass = LvlInitStruct<VkSubpassDescription2>();
        subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

        std::vector<VkSubpassDependency2> dependencies{dependency_count, LvlInitStruct<VkSubpassDependency2>()};
        for (auto& dependency : dependencies) {
            dependency.srcSubpass = 0;
            dependency.dstSubpass = 0;
            dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
            dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
            dependency.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            dependency.dependencyFlags = VK_DEPENDENCY_BY_REGION_BIT;
        }

        auto create_info = LvlInitStruct<VkRenderPassCreateInfo2>();
        create_info.pDependencies = dependencies.data();
        create_info.dependencyCount = dependencies.size();
        create_info.pSubpasses = &subpass;
        create_info.subpassCount = 1;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkRenderPassCreateInfo2-dependencyCount-05056");
        vksc::CreateRenderPass2(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
}

TEST_F(VkSCLayerTest, CreateRenderPassMaxFramebufferAttachmentsExceeded) {
    TEST_DESCRIPTION(
        "vkCreateRenderPass - VkRenderPassCreateInfo::attachmentCount must be "
        "less than or equal to maxFramebufferAttachments");

    ASSERT_NO_FATAL_FAILURE(InitFramework());

    const auto limit = GetVulkanSC10Properties(gpu()).maxFramebufferAttachments;
    const auto attachments_count = limit + 1;
    auto sc_10_features = LvlInitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vksc::GetDefaultObjectReservationCreateInfo();
    object_reservation_info.pNext = &sc_10_features;
    object_reservation_info.attachmentDescriptionRequestCount = attachments_count;
    ASSERT_NO_FATAL_FAILURE(InitState(nullptr, &object_reservation_info));

    VkRenderPass render_pass{VK_NULL_HANDLE};

    {
        auto subpass = VkSubpassDescription{};
        subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

        std::vector<VkAttachmentDescription> attachments(attachments_count, VkAttachmentDescription{});
        for (auto& attachment : attachments) {
            attachment.format = VK_FORMAT_R8G8B8A8_UNORM;
            attachment.samples = VK_SAMPLE_COUNT_1_BIT;
            attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
            attachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            attachment.initialLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            attachment.finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
        }

        auto create_info = LvlInitStruct<VkRenderPassCreateInfo>();
        create_info.pAttachments = attachments.data();
        create_info.attachmentCount = attachments.size();
        create_info.pSubpasses = &subpass;
        create_info.subpassCount = 1;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkRenderPassCreateInfo-attachmentCount-05052");
        vksc::CreateRenderPass(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
    {
        auto subpass = LvlInitStruct<VkSubpassDescription2>();
        subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

        std::vector<VkAttachmentDescription2> attachments(attachments_count, LvlInitStruct<VkAttachmentDescription2>());
        for (auto& attachment : attachments) {
            attachment.format = VK_FORMAT_R8G8B8A8_UNORM;
            attachment.samples = VK_SAMPLE_COUNT_1_BIT;
            attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
            attachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            attachment.initialLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            attachment.finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
        }

        auto create_info = LvlInitStruct<VkRenderPassCreateInfo2>();
        create_info.pAttachments = attachments.data();
        create_info.attachmentCount = attachments.size();
        create_info.pSubpasses = &subpass;
        create_info.subpassCount = 1;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkRenderPassCreateInfo2-attachmentCount-05057");
        vksc::CreateRenderPass2(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
}
