/*
 * Copyright (c) 2023-2024 The Khronos Group Inc.
 * Copyright (c) 2023-2024 RasterGrid Kft.
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

#include "vksc_test_pipeline_helper.h"
#include "vksc_render_framework.h"

namespace vksc {

PipelineBuilder::PipelineBuilder(VkSCRenderFramework* framework)
    : stage_ci(),
      offline_ci(vku::InitStructHelper()),
      framework_(*framework),
      device_(*(framework->DeviceObj())),
      cache_builder_(framework->AddPipelineCacheBuilder()),
      pipeline_cache_(),
      pipeline_json_data_(nullptr),
      spirv_data_(),
      dsl_bindings_(),
      descriptor_set_(),
      pipeline_layout_ci_(vku::InitStructHelper()),
      pipeline_layout_() {}

void PipelineBuilder::AddStage(const Shader& shader) {
    if (shader.source_) {
        std::vector<uint32_t> spv;
        switch (shader.source_type_) {
            case Shader::SourceType::ASM:
                framework_.ASMtoSPV(shader.spirv_env_, 0, shader.source_, spv);
                break;
            case Shader::SourceType::GLSL:
                framework_.GLSLtoSPV(&device_.phy().limits_, shader.stage_, shader.source_, spv, shader.spirv_env_);
                break;
        }
        spirv_data_.emplace_back(std::move(spv));
    }

    auto stage_info = vku::InitStruct<VkPipelineShaderStageCreateInfo>();
    stage_info.stage = shader.stage_;
    stage_info.pName = shader.entry_point_;
    stage_info.pSpecializationInfo = shader.spec_info_;
    stage_ci.emplace_back(std::move(stage_info));
}

void PipelineBuilder::BuildCacheData() {
    if (spirv_data_.empty()) {
        offline_ci = vksc::GetDefaultPipelineOfflineCreateInfo();
    } else {
        auto pool_entry_size = vksc::GetDefaultPipelinePoolSize().poolEntrySize;
        auto header = cache_builder_->AddDefaultHeaderVersionSCOne();
        auto entry = cache_builder_->AddPipelineEntry(header, kPipelineId, pool_entry_size);
        cache_builder_->AddStageValidation(entry, pipeline_json_data_, std::move(spirv_data_));
        offline_ci.poolEntrySize = pool_entry_size;
        ParseUUID(kPipelineId, &offline_ci.pipelineIdentifier[0]);
    }
}

void PipelineBuilder::TestDeviceCreateFail() {
    auto cache_create_info = cache_builder_->MakeCreateInfo();
    auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
    auto object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>(&sc_10_features);
    object_reservation_info.pipelineCacheCreateInfoCount = 1;
    object_reservation_info.pPipelineCacheCreateInfos = &cache_create_info;

    float queue_priority = 1.f;
    auto queue_info = vku::InitStruct<VkDeviceQueueCreateInfo>();
    queue_info.queueCount = 1;
    queue_info.pQueuePriorities = &queue_priority;

    auto create_info = vku::InitStruct<VkDeviceCreateInfo>(&object_reservation_info);
    create_info.queueCreateInfoCount = 1;
    create_info.pQueueCreateInfos = &queue_info;

    VkDevice device = VK_NULL_HANDLE;

    vksc::CreateDevice(framework_.gpu(), &create_info, nullptr, &device);
    vksc::DestroyDevice(device, nullptr);
}

vksc::Pipeline PipelineBuilder::CreatePipeline(vkt::Device& device) {
    descriptor_set_.reset(new OneOffDescriptorSet(&device, dsl_bindings_));
    pipeline_layout_ = vkt::PipelineLayout(device, {&descriptor_set_->layout_}, {}, pipeline_layout_ci_.flags);

    if (spirv_data_.empty() && !pipeline_cache_) {
        pipeline_cache_.init(device, cache_builder_->MakeCreateInfo());
    }

    return vksc::Pipeline();
}

ComputePipelineBuilder::ComputePipelineBuilder(VkSCRenderFramework* framework)
    : PipelineBuilder(framework), pipeline_ci(vku::InitStructHelper()) {}

ComputePipelineBuilder& ComputePipelineBuilder::Init(const Shader& shader) {
    AddStage(shader);

    pipeline_ci.pNext = &offline_ci;
    pipeline_ci.stage = stage_ci[0];

    BuildCacheData();

    return *this;
}

vksc::Pipeline ComputePipelineBuilder::CreatePipeline(vkt::Device& device) {
    PipelineBuilder::CreatePipeline(device);

    pipeline_ci.layout = pipeline_layout_;

    VkPipeline pipeline = VK_NULL_HANDLE;
    vksc::CreateComputePipelines(device.handle(), pipeline_cache_.handle(), 1, &pipeline_ci, nullptr, &pipeline);
    return vksc::Pipeline(device.handle(), pipeline);
}

GraphicsPipelineBuilder::GraphicsPipelineBuilder(VkSCRenderFramework* framework)
    : PipelineBuilder(framework),
      pipeline_ci(vku::InitStructHelper()),
      ia_state(vku::InitStructHelper()),
      vi_state(vku::InitStructHelper()),
      rs_state(vku::InitStructHelper()),
      vp_state(vku::InitStructHelper()),
      cb_state(vku::InitStructHelper()),
      ms_state(vku::InitStructHelper()),
      viewport_(),
      scissor_(),
      cb_attach_state_() {
    InitStateDefaults();
}

void GraphicsPipelineBuilder::InitStateDefaults() {
    ia_state.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;

    rs_state.lineWidth = 1.f;

    viewport_ = {0, 0, 16, 16, 0, 1};
    scissor_ = {{0, 0}, {16, 16}};
    vp_state.viewportCount = 1;
    vp_state.pViewports = &viewport_;
    vp_state.scissorCount = 1;
    vp_state.pScissors = &scissor_;

    cb_attach_state_ = {};
    cb_state.attachmentCount = 1;
    cb_state.pAttachments = &cb_attach_state_;

    ms_state.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;

    pipeline_ci.pInputAssemblyState = &ia_state;
    pipeline_ci.pVertexInputState = &vi_state;
    pipeline_ci.pRasterizationState = &rs_state;
    pipeline_ci.pViewportState = &vp_state;
    pipeline_ci.pColorBlendState = &cb_state;
    pipeline_ci.pMultisampleState = &ms_state;
}

GraphicsPipelineBuilder& GraphicsPipelineBuilder::InitVs(const Shader& vs) {
    AddStage(vs);

    rs_state.rasterizerDiscardEnable = VK_TRUE;

    pipeline_ci.pNext = &offline_ci;
    pipeline_ci.stageCount = 1;
    pipeline_ci.pStages = stage_ci.data();

    BuildCacheData();

    return *this;
}

GraphicsPipelineBuilder& GraphicsPipelineBuilder::InitVsFs(const Shader& vs, const Shader& fs) {
    AddStage(vs);
    AddStage(fs);

    pipeline_ci.pNext = &offline_ci;
    pipeline_ci.stageCount = 2;
    pipeline_ci.pStages = stage_ci.data();

    BuildCacheData();

    return *this;
}

vksc::Pipeline GraphicsPipelineBuilder::CreatePipeline(vkt::Device& device) {
    PipelineBuilder::CreatePipeline(device);

    pipeline_ci.layout = pipeline_layout_;
    pipeline_ci.renderPass = framework_.renderPass();

    VkPipeline pipeline = VK_NULL_HANDLE;
    vksc::CreateGraphicsPipelines(device.handle(), pipeline_cache_.handle(), 1, &pipeline_ci, nullptr, &pipeline);
    return vksc::Pipeline(device.handle(), pipeline);
}

}  // namespace vksc
