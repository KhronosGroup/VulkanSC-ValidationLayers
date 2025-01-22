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

TEST_F(VkSCPositiveInstance, ValidationInstanceExtensions) {
    RETURN_IF_SKIP(Init());

    std::string layer_name = "VK_LAYER_KHRONOS_validation";
    std::vector<std::string> extensions = {VK_EXT_DEBUG_UTILS_EXTENSION_NAME,
                                           VK_EXT_VALIDATION_FEATURES_EXTENSION_NAME};
    uint32_t property_count;
    vk::EnumerateInstanceExtensionProperties(layer_name.c_str(), &property_count, NULL);
    std::vector<VkExtensionProperties> properties(property_count);
    vk::EnumerateInstanceExtensionProperties(layer_name.c_str(), &property_count, properties.data());
    for (size_t i = 0; i < extensions.size(); i++) {
        bool found = false;
        for (auto props : properties) {
            if (!strcmp(props.extensionName, extensions[i].c_str())) {
                found = true;
                break;
            }
        }
        if (!found) {
            FAIL() << "Validation layer is missing extension " << extensions[i].c_str();
        }
    }
}
