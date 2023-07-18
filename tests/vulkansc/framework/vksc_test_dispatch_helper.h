/*
 * Copyright (c) 2023-2023 The Khronos Group Inc.
 * Copyright (c) 2023-2023 RasterGrid Kft.
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

#include "generated/vk_function_pointers.h"

namespace vksc {

using namespace ::vk;

extern PFN_vkCreateDevice CreateDevice;
extern PFN_vkCreatePipelineCache CreatePipelineCache;
extern PFN_vkCreateComputePipelines CreateComputePipelines;
extern PFN_vkCreateGraphicsPipelines CreateGraphicsPipelines;
extern PFN_vkCreateCommandPool CreateCommandPool;

void PatchDispatchTable();
const VkDeviceObjectReservationCreateInfo& GetDefaultObjectReservationCreateInfo();

}  // namespace vksc
