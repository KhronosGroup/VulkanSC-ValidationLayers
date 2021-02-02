/* Copyright (c) 2021 The Khronos Group Inc.
 * Copyright (c) 2021 Valve Corporation
 * Copyright (c) 2021 LunarG, Inc.
 * Copyright (C) 2021 Google Inc.
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
 * Author: Jeremy Gebben <jeremyg@lunarg.com>
 */
#pragma once

#include <cstdint>
#include <string>
#include <sstream>

#include "vk_layer_data.h"

// structure to track where a validation error occurs, and capture enough information
// to generate the start of a log message and find the correct VUID for many commonvalidity errors.
//
// usage example:
// CoreErrorLocation outer("vkCmdPipelineBarrier", "VkImageMemoryBarrier");
//     auto struct_level = outer("pImageMemoryBarriers", i);
//        auto field_level = struct_level("srcAccessMask");
//        std::cout << field_level.Message() << std::endl;
// will print:
//        vkCmdPipelineBarrier(): pImageMemoryBarriers[42].srcAccessMask
// VUID could be constructed with:
//        std::stringstream s;
//        s << "VUID-" << field_level.refpage << "-" << field_level.field_name << "-" << vuid_number;
//
struct CoreErrorLocation {
    static const uint32_t kNoIndex = UINT32_MAX;

    // name of the vulkan function we're checking
    std::string func_name;

    // VUID-{refpage}-{field_name}-#####
    std::string refpage;
    std::string field_name;
    // optional index if checking an array.
    uint32_t index;

    // tracking for how we walk down into arrays of structures
    struct Path {
        std::string field;
        uint32_t index;
    };
    // should be sized to cover the common struct nesting depths without allocating.
    small_vector<Path, 3> field_path;

    CoreErrorLocation(const std::string &func, const std::string &ref, const std::string &field = "", uint32_t i = kNoIndex)
        : func_name(func), refpage(ref), index(i) {}

    std::string Message() const {
        std::stringstream out;
        out << func_name << "(): ";
        for (const auto &f : field_path) {
            out << f.field;
            if (f.index != kNoIndex) {
                out << "[" << f.index << "]";
            }
            out << ".";
        }
        out << field_name;
        if (index != kNoIndex) {
            out << "[" << index << "]";
        }
        return out.str();
    }

    CoreErrorLocation operator()(const std::string &sub_field, uint32_t sub_index = kNoIndex) const {
        CoreErrorLocation result(this->func_name, this->refpage);
        result.field_path.reserve(this->field_path.size() + 1);
        result.field_path = this->field_path;
        if (this->field_name.size() > 0) {
            result.field_path.emplace_back(Path{this->field_name, this->index});
        }
        result.field_name = sub_field;
        result.index = sub_index;
        return result;
    }
};
