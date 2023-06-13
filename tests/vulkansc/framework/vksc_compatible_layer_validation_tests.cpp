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

#include "vksc_compatible_layer_validation_tests.h"

bool VkCompatibleLayerTest::GLSLtoSPV(VkPhysicalDeviceLimits const *const device_limits, const VkShaderStageFlagBits shader_type,
                                        const char *pshader, std::vector<uint32_t> &spv, bool debug, const spv_target_env spv_env) {
    if (IsPlatform(kMockICD)) {
        // For mock ICD runs we simply skip shader compilation as it won't affect test execution
        return true;
    } else {
        // We don't currently support shader-based test cases on real Vulkan SC drivers
        assert(false);
        return false;
    }
}

bool VkCompatibleLayerTest::ASMtoSPV(const spv_target_env target_env, const uint32_t options, const char *pasm,
                                       std::vector<uint32_t> &spv) {
    if (IsPlatform(kMockICD)) {
        // For mock ICD runs we simply skip shader compilation as it won't affect test execution
        return true;
    } else {
        // We don't currently support shader-based test cases on real Vulkan SC drivers
        assert(false);
        return false;
    }
}

void VkCompatibleSyncValTest::InitSyncValFramework(bool enable_queue_submit_validation) {
    // Enable synchronization validation

    // Optional feature definition, add if requested (but they can't be defined at the conditional scope)
    const char *kEnableQueuSubmitSyncValidation = "VALIDATION_CHECK_ENABLE_SYNCHRONIZATION_VALIDATION_QUEUE_SUBMIT";
    VkLayerSettingValueDataEXT qs_setting_string_value{};
    qs_setting_string_value.arrayString.pCharArray = kEnableQueuSubmitSyncValidation;
    qs_setting_string_value.arrayString.count = strlen(qs_setting_string_value.arrayString.pCharArray);
    VkLayerSettingValueEXT qs_enable_setting_val = {"enables", VK_LAYER_SETTING_VALUE_TYPE_STRING_ARRAY_EXT,
                                                    qs_setting_string_value};
    VkLayerSettingsEXT qs_settings{VK_STRUCTURE_TYPE_INSTANCE_LAYER_SETTINGS_EXT, nullptr, 1, &qs_enable_setting_val};

    if (enable_queue_submit_validation) {
        features_.pNext = &qs_settings;
    }
    InitFramework(m_errorMonitor, &features_);
}
