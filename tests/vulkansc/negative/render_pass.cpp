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
    TEST_DESCRIPTION("vkCreateRenderPass - subpassCount exceeds maxRenderPassSubpasses");

    ASSERT_NO_FATAL_FAILURE(InitFramework());

    const auto subpass_count = GetVulkanSC10Properties(gpu()).maxRenderPassSubpasses + 1;
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
    TEST_DESCRIPTION("vkCreateRenderPass - dependencyCount exceeds maxRenderPassDependencies");
    ASSERT_NO_FATAL_FAILURE(InitFramework());

    const auto dependency_count = GetVulkanSC10Properties(gpu()).maxRenderPassDependencies + 1;
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
    TEST_DESCRIPTION("vkCreateRenderPass - attachmentCount exceeds maxFramebufferAttachments");

    ASSERT_NO_FATAL_FAILURE(InitFramework());

    const auto attachments_count = GetVulkanSC10Properties(gpu()).maxFramebufferAttachments + 1;
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

TEST_F(VkSCLayerTest, CreateRenderPassMaxSubpassInputAttachmentsExceeded) {
    TEST_DESCRIPTION("vkCreateRenderPass - inputAttachmentCount exceeds maxSubpassInputAttachments");

    ASSERT_NO_FATAL_FAILURE(Init());

    const auto subpass_count = 2;
    const auto input_attachment_count = GetVulkanSC10Properties(gpu()).maxSubpassInputAttachments + 1;

    VkRenderPass render_pass{VK_NULL_HANDLE};
    {
        std::vector<VkAttachmentDescription> attachments(input_attachment_count);
        for (auto& attachment : attachments) {
            attachment.format = VK_FORMAT_R8G8B8A8_UNORM;
            attachment.samples = VK_SAMPLE_COUNT_1_BIT;
            attachment.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
            attachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            attachment.initialLayout = VK_IMAGE_LAYOUT_GENERAL;
            attachment.finalLayout = VK_IMAGE_LAYOUT_GENERAL;
        }
        std::vector<VkAttachmentReference> input_attachments(input_attachment_count);
        for (uint32_t i = 0; i < input_attachments.size(); ++i) {
            input_attachments[i].layout = VK_IMAGE_LAYOUT_GENERAL;
            input_attachments[i].attachment = i;
        }
        std::vector<VkSubpassDescription> subpasses{subpass_count, VkSubpassDescription{}};
        for (auto& subpass : subpasses) {
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
            subpass.pInputAttachments = input_attachments.data();
            subpass.inputAttachmentCount = input_attachments.size();
        }

        auto create_info = LvlInitStruct<VkRenderPassCreateInfo>();
        create_info.pAttachments = attachments.data();
        create_info.attachmentCount = attachments.size();
        create_info.pSubpasses = subpasses.data();
        create_info.subpassCount = subpasses.size();

        m_errorMonitor->SetAllowedFailureMsg("VUID-vkCreateRenderPass2-attachments-device-05089");
        m_errorMonitor->SetAllowedFailureMsg("VUID-VkRenderPassCreateInfo-attachmentCount-05052");
        for (int i = 0; i < subpass_count; ++i)
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkSubpassDescription-inputAttachmentCount-05053");
        vksc::CreateRenderPass(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
    {
        std::vector<VkAttachmentDescription2> attachments(input_attachment_count, LvlInitStruct<VkAttachmentDescription2>());
        for (auto& attachment : attachments) {
            attachment.format = VK_FORMAT_R8G8B8A8_UNORM;
            attachment.samples = VK_SAMPLE_COUNT_1_BIT;
            attachment.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
            attachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            attachment.initialLayout = VK_IMAGE_LAYOUT_GENERAL;
            attachment.finalLayout = VK_IMAGE_LAYOUT_GENERAL;
        }
        std::vector<VkAttachmentReference2> input_attachments(input_attachment_count, LvlInitStruct<VkAttachmentReference2>());
        for (uint32_t i = 0; i < input_attachments.size(); ++i) {
            input_attachments[i].layout = VK_IMAGE_LAYOUT_GENERAL;
            input_attachments[i].attachment = i;
            input_attachments[i].aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        }
        std::vector<VkSubpassDescription2> subpasses(subpass_count, LvlInitStruct<VkSubpassDescription2>());
        for (auto& subpass : subpasses) {
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
            subpass.pInputAttachments = input_attachments.data();
            subpass.inputAttachmentCount = input_attachments.size();
        }

        auto create_info = LvlInitStruct<VkRenderPassCreateInfo2>();
        create_info.pAttachments = attachments.data();
        create_info.attachmentCount = attachments.size();
        create_info.pSubpasses = subpasses.data();
        create_info.subpassCount = subpasses.size();

        m_errorMonitor->SetAllowedFailureMsg("VUID-vkCreateRenderPass2-attachments-device-05089");
        m_errorMonitor->SetAllowedFailureMsg("VUID-VkRenderPassCreateInfo2-attachmentCount-05057");
        for (int i = 0; i < subpass_count; ++i)
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkSubpassDescription2-inputAttachmentCount-05058");
        vksc::CreateRenderPass2(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
}

TEST_F(VkSCLayerTest, CreateRenderPassMaxSubpassPreserveAttachmentsExceeded) {
    TEST_DESCRIPTION("vkCreateRenderPass - preserveAttachmentCount exceeds maxSubpassPreserveAttachments");

    ASSERT_NO_FATAL_FAILURE(Init());

    const auto subpass_count = 2;
    const auto preserve_attachment_count = GetVulkanSC10Properties(gpu()).maxSubpassPreserveAttachments + 1;

    VkRenderPass render_pass{VK_NULL_HANDLE};

    {
        std::vector<VkAttachmentDescription> attachments(preserve_attachment_count);
        for (auto& attachment : attachments) {
            attachment.format = VK_FORMAT_R8G8B8A8_UNORM;
            attachment.samples = VK_SAMPLE_COUNT_1_BIT;
            attachment.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
            attachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            attachment.initialLayout = VK_IMAGE_LAYOUT_GENERAL;
            attachment.finalLayout = VK_IMAGE_LAYOUT_GENERAL;
        }
        std::vector<uint32_t> preserve_attachments(preserve_attachment_count, 0u);
        std::vector<VkSubpassDescription> subpasses{subpass_count, VkSubpassDescription{}};
        for (auto& subpass : subpasses) {
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
            subpass.pPreserveAttachments = preserve_attachments.data();
            subpass.preserveAttachmentCount = preserve_attachments.size();
        }

        auto create_info = LvlInitStruct<VkRenderPassCreateInfo>();
        create_info.pAttachments = attachments.data();
        create_info.attachmentCount = attachments.size();
        create_info.pSubpasses = subpasses.data();
        create_info.subpassCount = subpasses.size();

        m_errorMonitor->SetAllowedFailureMsg("VUID-vkCreateRenderPass2-attachments-device-05089");
        for (int i = 0; i < subpass_count; ++i)
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkSubpassDescription-preserveAttachmentCount-05054");
        vksc::CreateRenderPass(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
    {
        std::vector<VkAttachmentDescription2> attachments(preserve_attachment_count, LvlInitStruct<VkAttachmentDescription2>());
        for (auto& attachment : attachments) {
            attachment.format = VK_FORMAT_R8G8B8A8_UNORM;
            attachment.samples = VK_SAMPLE_COUNT_1_BIT;
            attachment.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
            attachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            attachment.initialLayout = VK_IMAGE_LAYOUT_GENERAL;
            attachment.finalLayout = VK_IMAGE_LAYOUT_GENERAL;
        }
        std::vector<uint32_t> preserve_attachments(preserve_attachment_count, 0u);
        std::vector<VkSubpassDescription2> subpasses(subpass_count, LvlInitStruct<VkSubpassDescription2>());
        for (auto& subpass : subpasses) {
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
            subpass.pPreserveAttachments = preserve_attachments.data();
            subpass.preserveAttachmentCount = preserve_attachments.size();
        }

        auto create_info = LvlInitStruct<VkRenderPassCreateInfo2>();
        create_info.pAttachments = attachments.data();
        create_info.attachmentCount = attachments.size();
        create_info.pSubpasses = subpasses.data();
        create_info.subpassCount = subpasses.size();

        m_errorMonitor->SetAllowedFailureMsg("VUID-vkCreateRenderPass2-attachments-device-05089");
        for (int i = 0; i < subpass_count; ++i)
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkSubpassDescription2-preserveAttachmentCount-05059");
        vksc::CreateRenderPass2(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
}