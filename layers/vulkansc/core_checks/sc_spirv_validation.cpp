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
#include "generated/enum_flag_bits.h"
#include "generated/spirv_grammar_helper.h"
#include "state_tracker/shader_instruction.h"
#include "utils/math_utils.h"
#include "utils/spirv_tools_utils.h"

namespace core::sc {

bool Device::ValidatePipelineEntryStage(uint32_t stage_index, const VkPipelineShaderStageCreateInfo& stage_info,
                                        const vvl::sc::PipelineCache* pipeline_cache_state,
                                        const VkPipelineOfflineCreateInfo* offline_info, const Location& create_info_loc,
                                        const Location& stage_info_loc) const {
    bool skip = false;

    if (disabled[shader_validation]) {
        // If shader validation is disabled, then these are not expected to be validated
        return skip;
    }

    if (!pipeline_cache_state || !offline_info) return skip;

    auto pipeline_entry = pipeline_cache_state->GetPipeline(offline_info);
    if (!pipeline_entry) return skip;

    auto shader_stage = pipeline_entry->GetShaderStage(stage_index);
    if (!shader_stage || !shader_stage->shader_module) return skip;

    auto& spv_module = *shader_stage->shader_module->spirv.get();

    if (stage_info.pName != nullptr) {
        auto entrypoint = spv_module.FindEntrypoint(stage_info.pName, stage_info.stage);
        if (!entrypoint) {
            skip |= LogError("VUID-VkPipelineShaderStageCreateInfo-pName-05027", device, stage_info_loc.dot(Field::pName),
                             "(`%s`) does not match any of the entry points in the SPIR-V module data "
                             "for stage index entry #%u (stage %s) of the pipeline with identifier {%s}.",
                             stage_info.pName, stage_index, string_VkShaderStageFlagBits(stage_info.stage),
                             pipeline_entry->PipelineID().toString().c_str());
        }
    } else {
        // Try to check if we have entry point information in the pipeline JSON info
        auto json_entrypoint_name = pipeline_entry->GetJsonEntryPointName(stage_index);
        if (json_entrypoint_name) {
            auto entrypoint = spv_module.FindEntrypoint(json_entrypoint_name, stage_info.stage);
            if (!entrypoint) {
                skip |= LogError("VUID-VkPipelineShaderStageCreateInfo-pName-05027", device, stage_info_loc.dot(Field::pName),
                                 "is NULL and the entry point name in the pipeline JSON data does not match any of the "
                                 "entry points in the SPIR-V module data for stage index entry #%u (stage %s) of the "
                                 "pipeline with identifier {%s}.",
                                 stage_index, string_VkShaderStageFlagBits(stage_info.stage),
                                 pipeline_entry->PipelineID().toString().c_str());
            }
        } else {
            skip |= LogWarning(kVUID_SC_PipelineCacheData_SpirvDepValMissingInfo, device, stage_info_loc.dot(Field::pName),
                               "is NULL and pipeline JSON data does not contain the entry point name thus available "
                               "SPIR-V module data for stage index entry #%u (stage %s) of the pipeline with identifier "
                               "{%s} cannot be used for SPIR-V dependent validation.",
                               stage_index, string_VkShaderStageFlagBits(stage_info.stage),
                               pipeline_entry->PipelineID().toString().c_str());
        }
    }

    if (spv_module.static_data_.has_specialization_constants && stage_info.pSpecializationInfo == nullptr) {
        // Try to check if we have specialization information in the pipeline JSON info
        auto json_spec_info = pipeline_entry->GetJsonSpecializationInfo(stage_index);
        if (!json_spec_info) {
            skip |= LogWarning(
                kVUID_SC_PipelineCacheData_SpirvDepValMissingInfo, device, stage_info_loc.dot(Field::pSpecializationInfo),
                "is NULL and pipeline JSON data does not contain specialization info but SPIR-V "
                "module data has specialization constants for stage index entry #%u (stage %s) "
                "of the pipeline with identifier {%s} and thus cannot be used for SPIR-V "
                "dependent validation.",
                stage_index, string_VkShaderStageFlagBits(stage_info.stage), pipeline_entry->PipelineID().toString().c_str());
        }
    }

    // This is where we do SPIR-V validation for the following reasons:
    // - Vulkan SC does not have VkShaderModule objects so validation won't happen there
    // - Vulkan only validates at pipeline creation time if using inline VkShaderModuleCreateInfo which does not apply for Vulkan SC
    // - We cannot do validation earlier (e.g. vkCreatePipelineCache time) as a pipeline cache can have entries that may not be
    // compatible with the device

    if (!global_settings.debug_disable_spirv_val) {
        // Use SPIRV-Tools validator to try and catch any issues with the module itself. If specialization constants are present,
        // the default values will be used during validation.
        // We use the original SPIR-V code for SPIR-V validation
        spv_target_env spirv_environment = PickSpirvEnv(api_version, true);
        spv_context ctx = spvContextCreate(spirv_environment);
        spv_const_binary_t binary{shader_stage->original_code.data(), shader_stage->original_code.size()};
        spv_diagnostic diag = nullptr;
        const spv_result_t spv_valid = spvValidateWithOptions(ctx, spirv_val_options, &binary, &diag);
        if (spv_valid != SPV_SUCCESS) {
            if (spv_valid == SPV_WARNING) {
                skip |= LogWarning("VUID-VkShaderModuleCreateInfo-pCode-08737", device,
                                   create_info_loc.pNext(Struct::VkPipelineOfflineCreateInfo),
                                   "contains pipeline identifier {%s} with SPIR-V module data for stage "
                                   "index entry #%u that produced spirv-val warning:\n%s",
                                   pipeline_entry->PipelineID().toString().c_str(), stage_index,
                                   diag && diag->error ? diag->error : "(no error text)");
            } else {
                skip |= LogError("VUID-VkShaderModuleCreateInfo-pCode-08737", device,
                                 create_info_loc.pNext(Struct::VkPipelineOfflineCreateInfo),
                                 "contains pipeline identifier {%s} with SPIR-V module data for stage "
                                 "index entry #%u that produced spirv-val error:\n%s",
                                 pipeline_entry->PipelineID().toString().c_str(), stage_index,
                                 diag && diag->error ? diag->error : "(no error text)");
            }
        }
        spvDiagnosticDestroy(diag);
        spvContextDestroy(ctx);

        if (spv_valid != SPV_SUCCESS && spv_valid != SPV_WARNING) {
            // Return immediately here as doing stateless SPIR-V validation with illegal SPIR-V can
            // result in all sorts of misbehavior
            return skip;
        }
    }

    // Do stateless SPIR-V validation (if SPIR-V was illegal this might misbehave)
    skip |= stateless_spirv_validator.Validate(spv_module, shader_stage->stateless_data, stage_info_loc);

    if (shader_stage->stateless_data.atomic_inst.size() > 0 &&
        (stateless_spirv_validator.enabled_features.shaderAtomicInstructions == VK_FALSE)) {
        skip |= LogError("VUID-RuntimeSpirv-OpAtomic-05091", device, create_info_loc.pNext(Struct::VkPipelineOfflineCreateInfo),
                         "contains pipeline identifier {%s} with SPIR-V module data for stage index entry %u "
                         "that is using atomic instructions, but shaderAtomicInstructions was not enabled.",
                         pipeline_entry->PipelineID().toString().c_str(), stage_index);
    }

    return skip;
}

}  // namespace core::sc
