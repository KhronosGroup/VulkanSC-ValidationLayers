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

class VkSCNegativeWsi : public VkSCLayerTest {
  public:
    void SetupForWSI() {
        AddRequiredExtensions(VK_KHR_SURFACE_EXTENSION_NAME);
        AddRequiredExtensions(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
        AddOptionalExtensions(VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME);
    }

    ~VkSCNegativeWsi() { vksc::DestroySurfaceKHR(instance(), surface_, nullptr); }

    VkSurfaceKHR WSISurface() {
        if (surface_ == VK_NULL_HANDLE) {
            VkResult result = VK_ERROR_INITIALIZATION_FAILED;

            if (InstanceExtensionSupported(VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME)) {
                auto create_info = vku::InitStruct<VkHeadlessSurfaceCreateInfoEXT>();
                result = vksc::CreateHeadlessSurfaceEXT(instance(), &create_info, nullptr, &surface_);
            }

            if (result == VK_SUCCESS) {
                result = vksc::GetPhysicalDeviceSurfaceCapabilitiesKHR(gpu(), surface_, &surface_caps_);
            }

            if (result == VK_SUCCESS) {
                uint32_t count = 0;
                result = vksc::GetPhysicalDeviceSurfaceFormatsKHR(gpu(), surface_, &count, nullptr);
                if (count == 0) {
                    result = VK_ERROR_INITIALIZATION_FAILED;
                }
                if (result == VK_SUCCESS) {
                    surface_formats_.resize(count);
                    result = vksc::GetPhysicalDeviceSurfaceFormatsKHR(gpu(), surface_, &count, surface_formats_.data());
                }
            }

            if (result == VK_SUCCESS) {
                uint32_t count = 0;
                result = vksc::GetPhysicalDeviceSurfacePresentModesKHR(gpu(), surface_, &count, nullptr);
                if (count == 0) {
                    result = VK_ERROR_INITIALIZATION_FAILED;
                }
                if (result == VK_SUCCESS) {
                    surface_present_modes_.resize(count);
                    result = vksc::GetPhysicalDeviceSurfacePresentModesKHR(gpu(), surface_, &count, surface_present_modes_.data());
                }
            }

            if (result == VK_SUCCESS) {
                swapchain_create_info_ = vku::InitStruct<VkSwapchainCreateInfoKHR>();
                swapchain_create_info_.surface = surface_;
                swapchain_create_info_.minImageCount = surface_caps_.minImageCount;
                swapchain_create_info_.imageFormat = surface_formats_[0].format;
                swapchain_create_info_.imageColorSpace = surface_formats_[0].colorSpace;
                swapchain_create_info_.imageExtent = surface_caps_.minImageExtent;
                swapchain_create_info_.imageArrayLayers = 1;
                swapchain_create_info_.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
                swapchain_create_info_.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
                swapchain_create_info_.preTransform = surface_caps_.currentTransform;
                swapchain_create_info_.compositeAlpha = static_cast<VkCompositeAlphaFlagBitsKHR>(
                    1 << static_cast<uint32_t>(log2(surface_caps_.supportedCompositeAlpha)));
                swapchain_create_info_.presentMode = surface_present_modes_[0];
            }

            if (result != VK_SUCCESS) {
                vksc::DestroySurfaceKHR(instance(), surface_, nullptr);
                surface_ = VK_NULL_HANDLE;
            }
        }
        return surface_;
    }

    const VkSurfaceCapabilitiesKHR& WSISurfaceCaps() const { return surface_caps_; }

    const std::vector<VkSurfaceFormatKHR>& WSISurfaceFormats() const { return surface_formats_; }

    const std::vector<VkPresentModeKHR> WSIPresentModes() const { return surface_present_modes_; }

    const VkSwapchainCreateInfoKHR& WSISwapchainCreateInfo() const { return swapchain_create_info_; }

  protected:
    VkSurfaceKHR surface_{VK_NULL_HANDLE};
    VkSurfaceCapabilitiesKHR surface_caps_{};
    std::vector<VkSurfaceFormatKHR> surface_formats_{};
    std::vector<VkPresentModeKHR> surface_present_modes_{};
    VkSwapchainCreateInfoKHR swapchain_create_info_{};
};

TEST_F(VkSCNegativeWsi, CreateSwapchainSplitInstanceBindRegionsNotAllowed) {
    TEST_DESCRIPTION("vkCreateSwapchain - VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR not allowed");

    SetupForWSI();

    RETURN_IF_SKIP(Init());

    if (!WSISurface() || !DeviceExtensionSupported(VK_KHR_SWAPCHAIN_EXTENSION_NAME)) {
        GTEST_SKIP() << "Test requires WSI support";
    }

    VkSwapchainKHR swapchain = VK_NULL_HANDLE;
    auto create_info = WSISwapchainCreateInfo();
    create_info.flags |= VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR;

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkSwapchainCreateInfoKHR-flags-05072");
    vksc::CreateSwapchainKHR(m_device->device(), &create_info, nullptr, &swapchain);
    m_errorMonitor->VerifyFound();
}

TEST_F(VkSCNegativeWsi, CreateSwapchainOldSwapchainNotNull) {
    TEST_DESCRIPTION("vkCreateSwapchain - oldSwapchain must be VK_NULL_HANDLE");

    SetupForWSI();

    RETURN_IF_SKIP(Init());

    if (!WSISurface() || !DeviceExtensionSupported(VK_KHR_SWAPCHAIN_EXTENSION_NAME)) {
        GTEST_SKIP() << "Test requires WSI support";
    }

    VkSwapchainKHR swapchain = VK_NULL_HANDLE;
    auto create_info = WSISwapchainCreateInfo();

    vksc::CreateSwapchainKHR(m_device->device(), &create_info, nullptr, &swapchain);

    create_info.oldSwapchain = swapchain;

    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-VkSwapchainCreateInfoKHR-oldSwapchain-05073");
    vksc::CreateSwapchainKHR(m_device->device(), &create_info, nullptr, &swapchain);
    m_errorMonitor->VerifyFound();
}
