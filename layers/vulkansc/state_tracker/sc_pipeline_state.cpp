/* Copyright (c) 2023-2024 The Khronos Group Inc.
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
 *
 * Author: Daniel Rakos <daniel.rakos@rastergrid.com>
 */

#include "sc_pipeline_state.h"
#include "state_tracker/state_tracker.h"
#include "vulkansc/sc_vuid_enums.h"

#include <sstream>

namespace vvl::sc {

PipelineCache::PipelineCache(const ValidationStateTracker* dev_data, VkPipelineCache pipeline_cache,
                             const VkPipelineCacheCreateInfo* pCreateInfo)
    : vvl::PipelineCache(pipeline_cache, pCreateInfo), pipelines_() {
    vvl::sc::PipelineCacheData pipeline_cache_data(*pCreateInfo);

    for (uint32_t pipeline_index = 0; pipeline_index < pipeline_cache_data.PipelineIndexCount(); ++pipeline_index) {
        auto cache_entry = pipeline_cache_data.PipelineIndexEntry(pipeline_index);
        if (cache_entry) {
            pipelines_.emplace(cache_entry.PipelineID(), Entry(dev_data, cache_entry));
        }
    }
}

PipelineCache::Entry::StageModules PipelineCache::Entry::InitShaderModules(const ValidationStateTracker* dev_data,
                                                                           const PipelineCacheData::Entry& cache_entry) {
    Entry::StageModules stage_modules;
    stage_modules.reserve(cache_entry.StageIndexCount());

    for (uint32_t stage_index = 0; stage_index < cache_entry.StageIndexCount(); ++stage_index) {
        auto code = cache_entry.StageSPIRV(stage_index);

        if (code.size() > 0) {
            auto spirv_module = std::make_shared<spirv::Module>(code);

            if (spirv_module->static_data_.has_group_decoration) {
                // Run optimizer to flatten group decorations
                spv_target_env spirv_environment = PickSpirvEnv(dev_data->api_version, true);
                spvtools::Optimizer optimizer(spirv_environment);
                optimizer.RegisterPass(spvtools::CreateFlattenDecorationPass());
                std::vector<uint32_t> optimized_binary;
                auto result = optimizer.Run(spirv_module->words_.data(), spirv_module->words_.size(), &optimized_binary,
                                            spvtools::ValidatorOptions(), true);
                if (result) {
                    spirv_module = std::make_shared<spirv::Module>(optimized_binary);
                }
            }

            // We use the SPIR-V module pointer as the internal shader module handle
            auto handle = (VkShaderModule)spirv_module.get();
            auto module_state = std::make_shared<vvl::ShaderModule>(handle, spirv_module, 0);

            stage_modules.emplace_back(std::move(module_state));
        } else {
            stage_modules.emplace_back(nullptr);
        }
    }
    return stage_modules;
}

PipelineCache::Entry::JsonData PipelineCache::Entry::ParseJsonData(const PipelineCacheData::Entry& cache_entry) {
    PipelineCache::Entry::JsonData data{};

    auto parse_entrypoint_name = [](const Json::Value& entrypoint_name) -> std::string {
        if (entrypoint_name.isString()) {
            auto result = entrypoint_name.asString();
            if (result != "" && result != "NULL") {
                return result;
            }
        }
        return std::string();
    };

    auto parse_spec_info = [](const Json::Value& spec_info) -> std::unique_ptr<safe_VkSpecializationInfo> {
        if (spec_info.isObject()) {
            auto result = std::make_unique<safe_VkSpecializationInfo>();
            result->mapEntryCount = spec_info["mapEntryCount"].asUInt();
            auto map_entries = new VkSpecializationMapEntry[result->mapEntryCount];
            auto map_entries_json = spec_info["pMapEntries"];
            for (uint32_t i = 0; i < result->mapEntryCount; ++i) {
                map_entries[i].constantID = map_entries_json["constantID"].asUInt();
                map_entries[i].offset = map_entries_json["offset"].asUInt();
                map_entries[i].size = map_entries_json["size"].asUInt();
            }
            result->pMapEntries = map_entries;
            result->dataSize = spec_info["dataSize"].asUInt();
            auto data = new std::byte[result->dataSize];
            auto data_json = spec_info["pData"];
            for (size_t i = 0; i < result->dataSize; ++i) {
                data[i] = static_cast<std::byte>(data_json[static_cast<uint32_t>(i)].asUInt());
            }
            result->pData = data;
            return result;
        }
        return nullptr;
    };

    if (cache_entry.JSONDataSize() > 0) {
        std::string json_string(cache_entry.JSONData(), static_cast<std::size_t>(cache_entry.JSONDataSize()));
        std::istringstream json_stream(json_string);
        std::string json_errors{};
        Json::CharReaderBuilder builder{};
        bool parse_ok = Json::parseFromStream(builder, json_stream, &data.json, &json_errors);
        if (parse_ok) {
            auto graphics_pipe_state = data.json["GraphicsPipelineState"];
            if (graphics_pipe_state != Json::nullValue) {
                auto stages = graphics_pipe_state["GraphicsPipeline"]["pStages"];
                uint32_t stage_count = graphics_pipe_state["GraphicsPipeline"]["stageCount"].asUInt();
                data.entrypoint_name.reserve(stage_count);
                data.specialization_info.reserve(stage_count);
                for (uint32_t stage_index = 0; stage_index < stage_count; ++stage_index) {
                    auto stage = stages[stage_index];
                    data.entrypoint_name.push_back(parse_entrypoint_name(stage["pName"]));
                    data.specialization_info.push_back(parse_spec_info(stage["pSpecializationInfo"]));
                }
            }

            auto compute_pipe_state = data.json["ComputePipelineState"];
            if (compute_pipe_state != Json::nullValue) {
                auto stage = compute_pipe_state["ComputePipeline"]["stage"];
                data.entrypoint_name.push_back(parse_entrypoint_name(stage["pName"]));
                data.specialization_info.push_back(parse_spec_info(stage["pSpecializationInfo"]));
            }
        }
    }

    return data;
}

}  // namespace vvl::sc
