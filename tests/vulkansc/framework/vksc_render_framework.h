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

#include "../../framework/render.h"

class VkSCRenderFramework : public VkRenderFramework {
  public:
    virtual bool GLSLtoSPV(VkPhysicalDeviceLimits const *const device_limits, const VkShaderStageFlagBits shader_type,
                           const char *pshader, std::vector<uint32_t> &spv, bool debug = false,
                           const spv_target_env spv_env = SPV_ENV_VULKAN_1_0) override;
    virtual bool ASMtoSPV(const spv_target_env target_env, const uint32_t options, const char *pasm,
                          std::vector<uint32_t> &spv) override;

    VkSCRenderFramework();
    virtual ~VkSCRenderFramework() override;

    VkPipelineCache GetDefaultPipelineCache();

    static VkSCRenderFramework& Instance() {
        assert(s_instance != nullptr);
        return *s_instance;
    }


  private:
    VkPipelineCache default_pipeline_cache_{VK_NULL_HANDLE};

    inline static VkSCRenderFramework* s_instance{nullptr};
};
