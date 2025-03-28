/*
 * Copyright (c) 2023-2025 The Khronos Group Inc.
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
 */

#include "vksc_test_pipeline_cache_helper.h"

#include <memory.h>

namespace vksc {

static std::vector<uint8_t> default_pipeline_cache_data{};
static VkPipelinePoolSize default_pipeline_pool_size{};
static VkPipelineCacheCreateInfo default_pipeline_cache_create_info{};
static VkPipelineOfflineCreateInfo default_pipeline_offline_create_info{};
static const char* default_pipeline_identifier = "8f8ac002-e369-11ed-b5ea-0242ac120002";

void InitDefaultPipelineCacheData() {
    PipelineCacheBuilder builder{};
    auto header = builder.AddDefaultHeaderVersionSCOne();
    header->headerVersionOne.vendorID = 0xba5eba11;
    header->headerVersionOne.deviceID = 0xf005ba11;

    builder.AddPipelineEntry(header, default_pipeline_identifier, 65536);

    default_pipeline_cache_data = builder.GetData();

    default_pipeline_pool_size = vku::InitStruct<VkPipelinePoolSize>();
    default_pipeline_pool_size.poolEntrySize = 65536;
    default_pipeline_pool_size.poolEntryCount = 256;

    default_pipeline_cache_create_info = vku::InitStruct<VkPipelineCacheCreateInfo>();
    default_pipeline_cache_create_info.flags |=
        VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT | VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT;
    default_pipeline_cache_create_info.initialDataSize = default_pipeline_cache_data.size();
    default_pipeline_cache_create_info.pInitialData = default_pipeline_cache_data.data();

    default_pipeline_offline_create_info = vku::InitStruct<VkPipelineOfflineCreateInfo>();
    ParseUUID(default_pipeline_identifier, &default_pipeline_offline_create_info.pipelineIdentifier[0]);
    default_pipeline_offline_create_info.poolEntrySize = default_pipeline_pool_size.poolEntrySize;
}

const std::vector<uint8_t>& GetDefaultPipelineCacheData() { return default_pipeline_cache_data; }
const VkPipelinePoolSize& GetDefaultPipelinePoolSize() { return default_pipeline_pool_size; }
const VkPipelineCacheCreateInfo& GetDefaultPipelineCacheCreateInfo() { return default_pipeline_cache_create_info; }
const VkPipelineOfflineCreateInfo& GetDefaultPipelineOfflineCreateInfo() { return default_pipeline_offline_create_info; }

std::vector<uint32_t> CompileSPV(const spv_target_env target_env, const char* spv) {
    std::vector<uint32_t> output{};

    spv_binary binary;
    spv_diagnostic diagnostic = nullptr;
    spv_context context = spvContextCreate(target_env);
    spv_result_t error = spvTextToBinaryWithOptions(context, spv, strlen(spv), 0, &binary, &diagnostic);
    spvContextDestroy(context);
    if (error) {
        spvDiagnosticPrint(diagnostic);
        spvDiagnosticDestroy(diagnostic);
        return output;
    }

    output.insert(output.end(), binary->code, binary->code + binary->wordCount);
    spvBinaryDestroy(binary);

    return output;
}

void ParseUUID(const char* str, uint8_t* uuid) {
    uint32_t bytes_read = 0;
    while (bytes_read < VK_UUID_SIZE && str[0] != '\0' && str[1] != '\0') {
        uuid[bytes_read] = 0;
        for (uint32_t i = 0; i < 2; ++i) {
            if (*str >= '0' && *str <= '9') {
                uuid[bytes_read] |= *str - '0';
            } else if (*str >= 'a' && *str <= 'f') {
                uuid[bytes_read] |= *str - 'a' + 10;
            } else if (*str == '-' && i == 0 && (bytes_read == 4 || bytes_read == 6 || bytes_read == 8 || bytes_read == 10)) {
                str++;
                bytes_read--;
                break;
            } else {
                // Unexpected character in UUID
                assert(false);
                str++;
                break;
            }
            if (i == 0) {
                uuid[bytes_read] <<= 4;
            }
            str++;
        }
        bytes_read++;
    }
    assert(bytes_read == VK_UUID_SIZE);
}

}  // namespace vksc
