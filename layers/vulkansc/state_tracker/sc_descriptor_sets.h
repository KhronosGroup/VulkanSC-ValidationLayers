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
#pragma once
#include "state_tracker/descriptor_sets.h"

#include <atomic>

namespace vvl::sc {

class DescriptorPool : public vvl::DescriptorPool {
  public:
    std::atomic_uint32_t allocated_descriptor_sets{0};

    DescriptorPool(Device &dev, const VkDescriptorPool handle, const VkDescriptorPoolCreateInfo *pCreateInfo)
        : vvl::DescriptorPool(dev, handle, pCreateInfo) {}
};

}  // namespace vvl::sc
