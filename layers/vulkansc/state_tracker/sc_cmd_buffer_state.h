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
#include "state_tracker/cmd_buffer_state.h"

#include <atomic>

namespace vvl::sc {

class CommandPool : public vvl::CommandPool {
  public:
    uint32_t max_command_buffers;
    std::atomic_uint32_t command_buffers_recording;

    CommandPool(Device &dev, VkCommandPool cp, const VkCommandPoolCreateInfo *pCreateInfo, VkQueueFlags flags)
        : vvl::CommandPool(dev, cp, pCreateInfo, flags), max_command_buffers(0), command_buffers_recording(0) {
        const auto *mem_reservation_info =
            vku::FindStructInPNextChain<VkCommandPoolMemoryReservationCreateInfo>(pCreateInfo->pNext);
        if (mem_reservation_info) {
            max_command_buffers = mem_reservation_info->commandPoolMaxCommandBuffers;
        }
    }
};

}  // namespace vvl::sc
