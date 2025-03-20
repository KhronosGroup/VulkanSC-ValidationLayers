/* Copyright (c) 2023-2025 The Khronos Group Inc.
 * Copyright (c) 2023-2025 RasterGrid Kft.
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

#include <algorithm>
#include <array>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <string>
#include <valarray>
#include <algorithm>

#include "vulkan/vk_enum_string_helper.h"
#include "vulkansc/sc_vuid_enums.h"
#include "vulkansc/core_checks/sc_core_validation.h"
#include "vulkansc/state_tracker/sc_pipeline_state.h"
#include "state_tracker/shader_module.h"
#include "utils/vk_layer_utils.h"
#include "generated/enum_flag_bits.h"
#include "generated/spirv_grammar_helper.h"
#include "state_tracker/shader_instruction.h"

namespace core::sc {

bool Instance::ValidatePipelineCacheSpirv(VkPhysicalDevice physical_device,
                                          const stateless::SpirvValidator& stateless_spirv_validator,
                                          const vvl::sc::PipelineCacheData& data, uint32_t pipeline_index, uint32_t stage_index,
                                          const Location& loc) const {
    bool skip = false;
    spv_result_t spv_valid = SPV_SUCCESS;

    auto entry = data.PipelineIndexEntry(pipeline_index);
    assert(entry);
    auto id = entry.PipelineID();
    auto stage_info = entry.StageIndexEntry(stage_index);
    assert(stage_info);

    if (disabled[shader_validation]) {
        return false;
    }

    if (SafeModulo(stage_info->codeSize, 4) != 0) {
        skip |= LogError(kVUID_SC_PipelineCacheData_CodeSizeNotMultipleOfFour, physical_device, loc.dot(Field::pInitialData),
                         "contains pipeline identifier {%s} with invalid SPIR-V module data for stage "
                         "index entry #%u that cannot be validated as its codeSize (%" PRIu64 ") is not a multiple of 4.",
                         id.toString().c_str(), stage_index, stage_info->codeSize);
    } else if (stage_info->codeSize == 0) {
        skip |= LogError(kVUID_SC_PipelineCacheData_CodeSizeZero, physical_device, loc.dot(Field::pInitialData),
                         "contains pipeline identifier {%s} with invalid SPIR-V module data for stage "
                         "index entry #%u that cannot be validated as its codeSize is zero.",
                         id.toString().c_str(), stage_index);
    } else if (stage_info->codeOffset + stage_info->codeSize > data.create_info.initialDataSize) {
        skip |= LogError(kVUID_SC_PipelineCacheData_CodeDataOutOfBounds, physical_device, loc.dot(Field::initialDataSize),
                         "is too small (%zu bytes) to fit the SPIR-V module data for "
                         "stage index entry #%u for pipeline identifier {%s} stored at "
                         "codeOffset (%" PRIu64 ") with codeSize (%" PRIu64
                         ") and thus "
                         "it cannot be validated.",
                         data.create_info.initialDataSize, stage_index, id.toString().c_str(), stage_info->codeOffset,
                         stage_info->codeSize);
    } else {
        auto code = entry.StageSPIRV(stage_index);

        if (code.size() <= 1) {
            skip |= LogError("VUID-VkShaderModuleCreateInfo-pCode-08736", physical_device, loc.dot(Field::pInitialData),
                             "contains pipeline identifier {%s} with SPIR-V module data for"
                             "index entry #%u that contains an invalid header (too small).",
                             id.toString().c_str(), stage_index);
        }

        if (code[0] != spv::MagicNumber) {
            skip |= LogError("VUID-VkShaderModuleCreateInfo-pCode-08736", physical_device, loc.dot(Field::pInitialData),
                             "contains pipeline identifier {%s} with SPIR-V module data for"
                             "index entry #%u that contains an invalid header (incorrect magic number).",
                             id.toString().c_str(), stage_index);
        }

        // We cannot perform SPIR-V "stateless" validation during vkCreateDevice validation because the
        // needed state (populated device feature and property information) is not yet available
        if (loc.function == Func::vkCreateDevice) {
            return skip;
        }

        // Use SPIRV-Tools validator to try and catch any issues with the module itself. If specialization constants are present,
        // the default values will be used during validation.
        spv_target_env spirv_environment = PickSpirvEnv(api_version, true);
        spv_context ctx = spvContextCreate(spirv_environment);
        spv_const_binary_t binary{code.data(), code.size()};
        spv_diagnostic diag = nullptr;
        spvtools::ValidatorOptions options;
        AdjustValidatorOptions(extensions, stateless_spirv_validator.enabled_features, options, nullptr);
        spv_valid = spvValidateWithOptions(ctx, options, &binary, &diag);
        if (spv_valid != SPV_SUCCESS) {
            if (spv_valid == SPV_WARNING) {
                skip |= LogWarning("VUID-VkShaderModuleCreateInfo-pCode-08737", physical_device, loc.dot(Field::pInitialData),
                                   "contains pipeline identifier {%s} with SPIR-V module data for stage "
                                   "index entry #%u that produced spirv-val warning:\n%s",
                                   id.toString().c_str(), stage_index, diag && diag->error ? diag->error : "(no error text)");
            } else {
                skip |= LogError("VUID-VkShaderModuleCreateInfo-pCode-08737", physical_device, loc.dot(Field::pInitialData),
                                 "contains pipeline identifier {%s} with SPIR-V module data for stage "
                                 "index entry #%u that produced spirv-val error:\n%s",
                                 id.toString().c_str(), stage_index, diag && diag->error ? diag->error : "(no error text)");
            }
        }

        spvDiagnosticDestroy(diag);
        spvContextDestroy(ctx);

        if (spv_valid == SPV_SUCCESS || spv_valid == SPV_WARNING) {
            spirv::StatelessData stateless_data{};
            spirv::Module temp_module(code.size() * sizeof(uint32_t), code.data(), &stateless_data);

            if (stateless_data.atomic_inst.size() > 0 &&
                (stateless_spirv_validator.enabled_features.shaderAtomicInstructions == VK_FALSE)) {
                skip |= LogError("VUID-RuntimeSpirv-OpAtomic-05091", physical_device, loc.dot(Field::pInitialData),
                                 "contains pipeline identifier {%s} with SPIR-V module data for stage index entry %u "
                                 "that is using atomic instructions, but shaderAtomicInstructions was not enabled.",
                                 id.toString().c_str(), stage_index);
            }

            // We set the entry point name to vkCreateShaderModule here to trigger the vkCreateShaderModule
            // VUIDs instead of the vkCreateShadersEXT VUIDs introduced by VK_EXT_shader_objects
            skip |= stateless_spirv_validator.Validate(temp_module, stateless_data, Location(Func::vkCreateShaderModule));
        }
    }

    return skip;
}

bool Device::ValidatePipelineStageInfo(uint32_t stage_index, const VkPipelineShaderStageCreateInfo& stage_info,
                                       const vvl::sc::PipelineCache* pipeline_cache_state,
                                       const VkPipelineOfflineCreateInfo* offline_info, const Location& loc) const {
    bool skip = false;

    if (!pipeline_cache_state || !offline_info) return skip;

    auto pipeline_entry = pipeline_cache_state->GetPipeline(offline_info);
    if (!pipeline_entry) return skip;

    std::shared_ptr<vvl::ShaderModule> module_state = pipeline_entry->GetShaderModule(stage_index);
    if (!module_state) return skip;

    if (stage_info.pName != nullptr) {
        auto entrypoint = module_state->spirv->FindEntrypoint(stage_info.pName, stage_info.stage);
        if (!entrypoint) {
            skip |= LogError("VUID-VkPipelineShaderStageCreateInfo-pName-05027", device, loc.dot(Field::pName),
                             "(`%s`) does not match any of the entry points in the SPIR-V module data "
                             "for stage index entry #%u (stage %s) of the pipeline with identifier {%s}.",
                             stage_info.pName, stage_index, string_VkShaderStageFlagBits(stage_info.stage),
                             pipeline_entry->PipelineID().toString().c_str());
        }
    } else {
        // Try to check if we have entry point information in the pipeline JSON info
        auto json_entrypoint_name = pipeline_entry->GetJsonEntryPointName(stage_index);
        if (json_entrypoint_name) {
            auto entrypoint = module_state->spirv->FindEntrypoint(json_entrypoint_name, stage_info.stage);
            if (!entrypoint) {
                skip |= LogError("VUID-VkPipelineShaderStageCreateInfo-pName-05027", device, loc.dot(Field::pName),
                                 "is NULL and the entry point name in the pipeline JSON data does not match any of the "
                                 "entry points in the SPIR-V module data for stage index entry #%u (stage %s) of the "
                                 "pipeline with identifier {%s}.",
                                 stage_index, string_VkShaderStageFlagBits(stage_info.stage),
                                 pipeline_entry->PipelineID().toString().c_str());
            }
        } else {
            skip |= LogWarning(kVUID_SC_PipelineCacheData_SpirvDepValMissingInfo, device, loc.dot(Field::pName),
                               "is NULL and pipeline JSON data does not contain the entry point name thus available "
                               "SPIR-V module data for stage index entry #%u (stage %s) of the pipeline with identifier "
                               "{%s} cannot be used for SPIR-V dependent validation.",
                               stage_index, string_VkShaderStageFlagBits(stage_info.stage),
                               pipeline_entry->PipelineID().toString().c_str());
        }
    }

    if (module_state->spirv->static_data_.has_specialization_constants && stage_info.pSpecializationInfo == nullptr) {
        // Try to check if we have specialization information in the pipeline JSON info
        auto json_spec_info = pipeline_entry->GetJsonSpecializationInfo(stage_index);
        if (!json_spec_info) {
            skip |= LogWarning(kVUID_SC_PipelineCacheData_SpirvDepValMissingInfo, device, loc.dot(Field::pSpecializationInfo),
                               "is NULL and pipeline JSON data does not contain specialization info but SPIR-V "
                               "module data has specialization constants for stage index entry #%u (stage %s) "
                               "of the pipeline with identifier {%s} and thus cannot be used for SPIR-V "
                               "dependent validation.",
                               stage_index, string_VkShaderStageFlagBits(stage_info.stage),
                               pipeline_entry->PipelineID().toString().c_str());
        }
    }

    return skip;
}

}  // namespace core::sc
