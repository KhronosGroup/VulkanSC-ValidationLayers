/*
 * Copyright (c) 2024-2025 The Khronos Group Inc.
 * Copyright (c) 2024-2025 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <vulkan/utility/vk_struct_helper.hpp>
#include "spirv-tools/libspirv.h"
#include "../../framework/binding.h"
#include "../../framework/descriptor_helper.h"
#include "vksc_test_pipeline_cache_helper.h"

#include <assert.h>
#include <memory>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <string.h>

class VkSCRenderFramework;

namespace vksc {

// Helper class for building shaders to be used by pipeline builders
class Shader {
  public:
    enum class SourceType { ASM, GLSL };

    Shader() = default;
    Shader& ASM(const char* source) {
        source_ = source;
        source_type_ = SourceType::ASM;
        return *this;
    }
    Shader& GLSL(const char* source) {
        source_ = source;
        source_type_ = SourceType::GLSL;
        return *this;
    }
    Shader& Stage(VkShaderStageFlagBits stage) {
        stage_ = stage;
        return *this;
    }
    Shader& Env(spv_target_env env) {
        spirv_env_ = env;
        return *this;
    }
    Shader& SpecInfo(const VkSpecializationInfo* spec_info) {
        spec_info_ = spec_info;
        return *this;
    }
    Shader& EntryPoint(const char* entry_point) {
        entry_point_ = entry_point;
        return *this;
    }

    static Shader Compute(const char* source = nullptr) { return Shader().ASM(source).Stage(VK_SHADER_STAGE_COMPUTE_BIT); }

    static Shader ComputeGLSL(const char* source = nullptr) { return Shader().GLSL(source).Stage(VK_SHADER_STAGE_COMPUTE_BIT); }

    static Shader Vertex(const char* source = nullptr) { return Shader().ASM(source).Stage(VK_SHADER_STAGE_VERTEX_BIT); }

    static Shader VertexGLSL(const char* source = nullptr) { return Shader().GLSL(source).Stage(VK_SHADER_STAGE_VERTEX_BIT); }

    static Shader Fragment(const char* source = nullptr) { return Shader().ASM(source).Stage(VK_SHADER_STAGE_FRAGMENT_BIT); }

    static Shader FragmentGLSL(const char* source = nullptr) { return Shader().GLSL(source).Stage(VK_SHADER_STAGE_FRAGMENT_BIT); }

  protected:
    const char* source_ = nullptr;
    SourceType source_type_ = SourceType::ASM;
    VkShaderStageFlagBits stage_ = VK_SHADER_STAGE_ALL;
    spv_target_env spirv_env_ = SPV_ENV_VULKAN_1_2;
    const VkSpecializationInfo* spec_info_ = nullptr;
    const char* entry_point_ = "main";

    friend class PipelineBuilder;
};

class Pipeline : public vkt::Pipeline {
  public:
    Pipeline() = default;
    Pipeline(VkDevice device, VkPipeline handle) { NonDispHandle::init(device, handle); }
};

// Helper class for building pipelines and corresponding pipeline cache data
class PipelineBuilder {
  public:
    PipelineBuilder(VkSCRenderFramework* framework);

    void AddBinding(uint32_t binding, VkDescriptorType desc_type, uint32_t count = 1,
                    VkShaderStageFlags stage_flags = VK_SHADER_STAGE_ALL) {
        dsl_bindings_.emplace_back(VkDescriptorSetLayoutBinding{binding, desc_type, count, stage_flags, nullptr});
    }

    void SetPipelineJsonData(const std::string data) { pipeline_json_data_ = data; }
    virtual void AddStage(const Shader& shader);
    virtual void BuildCacheData();
    void TestDeviceCreateFail();
    vksc::PipelineCache CreatePipelineCache(vkt::Device& device);
    virtual vksc::Pipeline CreatePipeline(vkt::Device& device);

    std::vector<VkPipelineShaderStageCreateInfo> stage_ci;
    VkPipelineOfflineCreateInfo offline_ci;

  protected:
    inline static const char* kPipelineId = "3ddda923-b6fc-433e-803c-822c1bccbc05";

    VkSCRenderFramework& framework_;
    vkt::Device& device_;
    PipelineCacheBuilder* cache_builder_;
    vkt::PipelineCache pipeline_cache_;
    std::string pipeline_json_data_;
    std::vector<std::vector<uint32_t>> spirv_data_;

    std::vector<VkDescriptorSetLayoutBinding> dsl_bindings_;
    std::unique_ptr<OneOffDescriptorSet> descriptor_set_;
    VkPipelineLayoutCreateInfo pipeline_layout_ci_;
    vkt::PipelineLayout pipeline_layout_;
};

// Helper class for building compute pipelines and corresponding pipeline cache data
class ComputePipelineBuilder : public PipelineBuilder {
  public:
    ComputePipelineBuilder(VkSCRenderFramework* framework);

    ComputePipelineBuilder& Init(const Shader& shader = vksc::Shader::Compute());

    vksc::Pipeline CreatePipeline(vkt::Device& device) override;

    VkComputePipelineCreateInfo pipeline_ci;
};

// Helper class for building graphics pipelines and corresponding pipeline cache data
class GraphicsPipelineBuilder : public PipelineBuilder {
  public:
    GraphicsPipelineBuilder(VkSCRenderFramework* framework);

    void InitStateDefaults();

    GraphicsPipelineBuilder& InitVs(const Shader& vs = vksc::Shader::Vertex());
    GraphicsPipelineBuilder& InitVsFs(const Shader& vs = vksc::Shader::Vertex(), const Shader& fs = vksc::Shader::Fragment());

    vksc::Pipeline CreatePipeline(vkt::Device& device) override;

    VkGraphicsPipelineCreateInfo pipeline_ci;

    VkPipelineInputAssemblyStateCreateInfo ia_state;
    VkPipelineVertexInputStateCreateInfo vi_state;
    VkPipelineRasterizationStateCreateInfo rs_state;
    VkPipelineViewportStateCreateInfo vp_state;
    VkPipelineColorBlendStateCreateInfo cb_state;
    VkPipelineMultisampleStateCreateInfo ms_state;

  private:
    VkViewport viewport_;
    VkRect2D scissor_;
    VkPipelineColorBlendAttachmentState cb_attach_state_;
};

}  // namespace vksc
