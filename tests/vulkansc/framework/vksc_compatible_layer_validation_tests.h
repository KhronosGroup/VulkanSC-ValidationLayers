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
#pragma once

#include "../../framework/layer_validation_tests.h"

class VkCompatibleLayerTest : public VkLayerTest {
  public:
    virtual bool GLSLtoSPV(VkPhysicalDeviceLimits const *const device_limits, const VkShaderStageFlagBits shader_type,
                           const char *pshader, std::vector<uint32_t> &spv, bool debug = false,
                           const spv_target_env spv_env = SPV_ENV_VULKAN_1_0) override;
    virtual bool ASMtoSPV(const spv_target_env target_env, const uint32_t options, const char *pasm,
                          std::vector<uint32_t> &spv) override;
};

class VkCompatiblePositiveLayerTest : public VkCompatibleLayerTest {};
class VkCompatibleLayerQueryTest : public VkCompatibleLayerTest {};
class VkCompatibleGraphicsLibraryLayerTest : public VkCompatibleLayerTest {};
class VkCompatiblePositiveGraphicsLibraryLayerTest : public VkCompatibleLayerTest {};
class VkCompatiblePositiveWsiTest : public VkCompatiblePositiveLayerTest {};
class VkCompatiblePortabilitySubsetTest : public VkCompatibleLayerTest {};

class VkCompatibleSyncValTest : public VkCompatibleLayerTest {
  public:
    void InitSyncValFramework(bool enable_queue_submit_validation = false);

  protected:
    VkValidationFeatureEnableEXT enables_[1] = {VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT};
    VkValidationFeatureDisableEXT disables_[4] = {
        VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT, VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT,
        VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT, VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT};
    VkValidationFeaturesEXT features_ = {VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT, nullptr, 1, enables_, 4, disables_};
};

// Override the superclass of test file defined subclasses
#define VkLayerTest VkCompatibleLayerTest
#define VkPositiveLayerTest VkCompatiblePositiveLayerTest

// Override the name of test file defined subclasses
#define RenderPassCreatePotentialFormatFeaturesTest VkCompatibleRenderPassCreatePotentialFormatFeaturesTest
#define DynamicRenderingCommandBufferInheritanceRenderingInfoTest \
    VkCompatibleDynamicRenderingCommandBufferInheritanceRenderingInfoTest
#define VkVideoLayerTest VkCompatibleVideoLayerTest
#define VkPositiveVideoLayerTest VkCompatiblePositiveVideoLayerTest
