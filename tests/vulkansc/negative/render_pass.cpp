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

TEST_F(VkSCNegativeRenderPass, CreateRenderPassMaxRenderPassSubpassesExceeded) {
    TEST_DESCRIPTION("vkCreateRenderPass - subpassCount exceeds maxRenderPassSubpasses");

    RETURN_IF_SKIP(InitFramework());

    const auto subpass_count = GetVulkanSC10Properties().maxRenderPassSubpasses + 1;
    ObjectReservation().subpassDescriptionRequestCount = subpass_count;

    ASSERT_NO_FATAL_FAILURE(InitState());

    VkRenderPass render_pass{VK_NULL_HANDLE};

    {
        std::vector<VkSubpassDescription> subpasses{subpass_count, VkSubpassDescription{}};
        for (auto& subpass : subpasses) {
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
        }

        auto create_info = vku::InitStruct<VkRenderPassCreateInfo>();
        create_info.pSubpasses = subpasses.data();
        create_info.subpassCount = subpasses.size();

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkRenderPassCreateInfo-subpassCount-05050");
        vksc::CreateRenderPass(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
    {
        std::vector<VkSubpassDescription2> subpasses(subpass_count, vku::InitStruct<VkSubpassDescription2>());
        for (auto& subpass : subpasses) {
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
        }

        auto create_info = vku::InitStruct<VkRenderPassCreateInfo2>();
        create_info.pSubpasses = subpasses.data();
        create_info.subpassCount = subpasses.size();

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkRenderPassCreateInfo2-subpassCount-05055");
        vksc::CreateRenderPass2(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
}

TEST_F(VkSCNegativeRenderPass, CreateRenderPassMaxRenderPassDependenciesExceeded) {
    TEST_DESCRIPTION("vkCreateRenderPass - dependencyCount exceeds maxRenderPassDependencies");
    RETURN_IF_SKIP(InitFramework());

    const auto dependency_count = GetVulkanSC10Properties().maxRenderPassDependencies + 1;
    ASSERT_NO_FATAL_FAILURE(InitState());

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

        auto create_info = vku::InitStruct<VkRenderPassCreateInfo>();
        create_info.pDependencies = dependencies.data();
        create_info.dependencyCount = dependencies.size();
        create_info.pSubpasses = &subpass;
        create_info.subpassCount = 1;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkRenderPassCreateInfo-dependencyCount-05051");
        vksc::CreateRenderPass(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
    {
        auto subpass = vku::InitStruct<VkSubpassDescription2>();
        subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

        std::vector<VkSubpassDependency2> dependencies{dependency_count, vku::InitStruct<VkSubpassDependency2>()};
        for (auto& dependency : dependencies) {
            dependency.srcSubpass = 0;
            dependency.dstSubpass = 0;
            dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
            dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
            dependency.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            dependency.dependencyFlags = VK_DEPENDENCY_BY_REGION_BIT;
        }

        auto create_info = vku::InitStruct<VkRenderPassCreateInfo2>();
        create_info.pDependencies = dependencies.data();
        create_info.dependencyCount = dependencies.size();
        create_info.pSubpasses = &subpass;
        create_info.subpassCount = 1;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkRenderPassCreateInfo2-dependencyCount-05056");
        vksc::CreateRenderPass2(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
}

TEST_F(VkSCNegativeRenderPass, CreateRenderPassMaxFramebufferAttachmentsExceeded) {
    TEST_DESCRIPTION("vkCreateRenderPass - attachmentCount exceeds maxFramebufferAttachments");

    RETURN_IF_SKIP(InitFramework());

    const auto attachments_count = GetVulkanSC10Properties().maxFramebufferAttachments + 1;
    ObjectReservation().attachmentDescriptionRequestCount = attachments_count;
    ASSERT_NO_FATAL_FAILURE(InitState());

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

        auto create_info = vku::InitStruct<VkRenderPassCreateInfo>();
        create_info.pAttachments = attachments.data();
        create_info.attachmentCount = attachments.size();
        create_info.pSubpasses = &subpass;
        create_info.subpassCount = 1;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkRenderPassCreateInfo-attachmentCount-05052");
        vksc::CreateRenderPass(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
    {
        auto subpass = vku::InitStruct<VkSubpassDescription2>();
        subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

        std::vector<VkAttachmentDescription2> attachments(attachments_count, vku::InitStruct<VkAttachmentDescription2>());
        for (auto& attachment : attachments) {
            attachment.format = VK_FORMAT_R8G8B8A8_UNORM;
            attachment.samples = VK_SAMPLE_COUNT_1_BIT;
            attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
            attachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            attachment.initialLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            attachment.finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
        }

        auto create_info = vku::InitStruct<VkRenderPassCreateInfo2>();
        create_info.pAttachments = attachments.data();
        create_info.attachmentCount = attachments.size();
        create_info.pSubpasses = &subpass;
        create_info.subpassCount = 1;

        m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkRenderPassCreateInfo2-attachmentCount-05057");
        vksc::CreateRenderPass2(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
}

TEST_F(VkSCNegativeRenderPass, CreateRenderPassMaxSubpassInputAttachmentsExceeded) {
    TEST_DESCRIPTION("vkCreateRenderPass - inputAttachmentCount exceeds maxSubpassInputAttachments");

    RETURN_IF_SKIP(Init());

    const auto subpass_count = std::min(GetVulkanSC10Properties().maxRenderPassSubpasses, 2u);
    const auto input_attachment_count = GetVulkanSC10Properties().maxSubpassInputAttachments + 1;

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

        auto create_info = vku::InitStruct<VkRenderPassCreateInfo>();
        create_info.pAttachments = attachments.data();
        create_info.attachmentCount = attachments.size();
        create_info.pSubpasses = subpasses.data();
        create_info.subpassCount = subpasses.size();

        m_errorMonitor->SetAllowedFailureMsg("VUID-vkCreateRenderPass-attachments-device-05089");
        m_errorMonitor->SetAllowedFailureMsg("VUID-VkRenderPassCreateInfo-attachmentCount-05052");
        for (uint32_t i = 0; i < subpass_count; ++i)
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkSubpassDescription-inputAttachmentCount-05053");
        vksc::CreateRenderPass(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
    {
        std::vector<VkAttachmentDescription2> attachments(input_attachment_count, vku::InitStruct<VkAttachmentDescription2>());
        for (auto& attachment : attachments) {
            attachment.format = VK_FORMAT_R8G8B8A8_UNORM;
            attachment.samples = VK_SAMPLE_COUNT_1_BIT;
            attachment.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
            attachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            attachment.initialLayout = VK_IMAGE_LAYOUT_GENERAL;
            attachment.finalLayout = VK_IMAGE_LAYOUT_GENERAL;
        }
        std::vector<VkAttachmentReference2> input_attachments(input_attachment_count, vku::InitStruct<VkAttachmentReference2>());
        for (uint32_t i = 0; i < input_attachments.size(); ++i) {
            input_attachments[i].layout = VK_IMAGE_LAYOUT_GENERAL;
            input_attachments[i].attachment = i;
            input_attachments[i].aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        }
        std::vector<VkSubpassDescription2> subpasses(subpass_count, vku::InitStruct<VkSubpassDescription2>());
        for (auto& subpass : subpasses) {
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
            subpass.pInputAttachments = input_attachments.data();
            subpass.inputAttachmentCount = input_attachments.size();
        }

        auto create_info = vku::InitStruct<VkRenderPassCreateInfo2>();
        create_info.pAttachments = attachments.data();
        create_info.attachmentCount = attachments.size();
        create_info.pSubpasses = subpasses.data();
        create_info.subpassCount = subpasses.size();

        m_errorMonitor->SetAllowedFailureMsg("VUID-vkCreateRenderPass2-attachments-device-05089");
        m_errorMonitor->SetAllowedFailureMsg("VUID-VkRenderPassCreateInfo2-attachmentCount-05057");
        for (uint32_t i = 0; i < subpass_count; ++i)
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkSubpassDescription2-inputAttachmentCount-05058");
        vksc::CreateRenderPass2(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
}

TEST_F(VkSCNegativeRenderPass, CreateRenderPassMaxSubpassPreserveAttachmentsExceeded) {
    TEST_DESCRIPTION("vkCreateRenderPass - preserveAttachmentCount exceeds maxSubpassPreserveAttachments");

    RETURN_IF_SKIP(Init());

    const auto subpass_count = std::min(GetVulkanSC10Properties().maxRenderPassSubpasses, 2u);
    const auto preserve_attachment_count = GetVulkanSC10Properties().maxSubpassPreserveAttachments + 1;

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

        auto create_info = vku::InitStruct<VkRenderPassCreateInfo>();
        create_info.pAttachments = attachments.data();
        create_info.attachmentCount = attachments.size();
        create_info.pSubpasses = subpasses.data();
        create_info.subpassCount = subpasses.size();

        m_errorMonitor->SetAllowedFailureMsg("VUID-vkCreateRenderPass-attachments-device-05089");
        m_errorMonitor->SetAllowedFailureMsg("VUID-VkRenderPassCreateInfo-attachmentCount-05052");
        for (uint32_t i = 0; i < subpass_count; ++i)
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkSubpassDescription-preserveAttachmentCount-05054");
        vksc::CreateRenderPass(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
    {
        std::vector<VkAttachmentDescription2> attachments(preserve_attachment_count, vku::InitStruct<VkAttachmentDescription2>());
        for (auto& attachment : attachments) {
            attachment.format = VK_FORMAT_R8G8B8A8_UNORM;
            attachment.samples = VK_SAMPLE_COUNT_1_BIT;
            attachment.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
            attachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            attachment.initialLayout = VK_IMAGE_LAYOUT_GENERAL;
            attachment.finalLayout = VK_IMAGE_LAYOUT_GENERAL;
        }
        std::vector<uint32_t> preserve_attachments(preserve_attachment_count, 0u);
        std::vector<VkSubpassDescription2> subpasses(subpass_count, vku::InitStruct<VkSubpassDescription2>());
        for (auto& subpass : subpasses) {
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
            subpass.pPreserveAttachments = preserve_attachments.data();
            subpass.preserveAttachmentCount = preserve_attachments.size();
        }

        auto create_info = vku::InitStruct<VkRenderPassCreateInfo2>();
        create_info.pAttachments = attachments.data();
        create_info.attachmentCount = attachments.size();
        create_info.pSubpasses = subpasses.data();
        create_info.subpassCount = subpasses.size();

        m_errorMonitor->SetAllowedFailureMsg("VUID-vkCreateRenderPass2-attachments-device-05089");
        m_errorMonitor->SetAllowedFailureMsg("VUID-VkRenderPassCreateInfo2-attachmentCount-05057");
        for (uint32_t i = 0; i < subpass_count; ++i)
            m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkSubpassDescription2-preserveAttachmentCount-05059");
        vksc::CreateRenderPass2(device(), &create_info, nullptr, &render_pass);
        m_errorMonitor->VerifyFound();
    }
}
