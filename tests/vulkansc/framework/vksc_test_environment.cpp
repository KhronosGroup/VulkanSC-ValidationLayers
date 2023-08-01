/*
 * Copyright (c) 2015-2022 The Khronos Group Inc.
 * Copyright (c) 2015-2023 Valve Corporation
 * Copyright (c) 2015-2023 LunarG, Inc.
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
#include "../../framework/test_common.h"
#include "../../framework/test_framework.h"
#include "vksc_test_dispatch_helper.h"

#include <vector>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <list>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

// Certain VK_* environment variables accept lists.
// Return a vector of std::string containing each member in the list.
//
// EX input:
//  export VK_DRIVER_FILES=/intel.json:/amd.json
//  set VK_DRIVER_FILES=\nvidia.json;\mesa.json
static std::vector<std::string> GetVkEnvironmentVariable(const char *env_var) {
    const std::string str = GetEnvironment(env_var);
    if (str.empty()) {
        return {};
    }

    // Loader uses standard OS path separators per platform
    constexpr char delimiter =
#ifdef _WIN32
        ';';
#else
        ':';
#endif

    std::vector<std::string> items;
    std::string::size_type start = 0;

    std::string::size_type pos = str.find_first_of(delimiter, start);
    std::string::size_type length = pos;
    while (pos != std::string::npos) {
        // emplace uses std::substr which takes length from start
        items.emplace_back(str, start, length);

        start = pos + 1;

        pos = str.find_first_of(delimiter, start);

        length = pos - start;
    }
    items.emplace_back(str, start);

    return items;
}

static void CheckEnvironmentVariables() {
    for (const char *env_var : {"VK_DRIVER_FILES", "VK_ICD_FILENAMES"}) {
        const std::vector<std::string> driver_files = GetVkEnvironmentVariable(env_var);
        for (const std::string &driver_file : driver_files) {
            const std::filesystem::path icd_file(driver_file);

            // TODO: Error check relative paths (platform dependent)
            if (icd_file.is_relative()) {
                continue;
            }

            std::string user_provided;
            user_provided += "\n\n";
            user_provided += env_var;
            user_provided += " = ";
            user_provided += driver_file;

            if (!std::filesystem::exists(icd_file)) {
                std::cerr << "Invalid " << env_var << "! File doesn't exist!" << user_provided << std::endl;
                std::exit(EXIT_FAILURE);
            }

            if (icd_file.extension() != ".json") {
                std::cerr << "Invalid " << env_var << "! " << env_var << " must be a json file!\n" << user_provided << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }
    }

    const std::vector<std::string> vk_layer_paths = GetVkEnvironmentVariable("VK_LAYER_PATH");
    bool found_json = false;
    for (const std::string &layer_path : vk_layer_paths) {
        const std::filesystem::path layer_dir(layer_path);

        // TODO: Error check relative paths (platform dependent)
        if (layer_dir.is_relative()) {
            continue;
        }
        const std::string user_provided = "\n\nVK_LAYER_PATH = " + layer_path;

        if (!std::filesystem::exists(layer_dir)) {
            std::cerr << "Invalid VK_LAYER_PATH! Directory " << layer_dir << " doesn't exist!" << user_provided << std::endl;
            std::exit(EXIT_FAILURE);
        }

        if (!std::filesystem::is_directory(layer_dir)) {
            std::cerr << "Invalid VK_LAYER_PATH! " << layer_dir << " must be a directory!" << user_provided << std::endl;
            std::exit(EXIT_FAILURE);
        }

        for (auto const &dir_entry : std::filesystem::directory_iterator{layer_dir}) {
            if (dir_entry.path().filename() == "VkSCLayer_khronos_validation.json") {
                found_json = true;
                break;
            }
        }
    }

    if (!found_json) {
        std::cerr << "Invalid VK_LAYER_PATH! VK_LAYER_PATH directory must contain VkSCLayer_khronos_validation.json!"
                  << GetEnvironment("VK_LAYER_PATH") << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

class VkSCTestEnvironment : public ::testing::Environment {
  public:
    virtual void SetUp() override;
    virtual void TearDown() override;
};

void VkSCTestEnvironment::SetUp() {
    CheckEnvironmentVariables();

    vk_testing::set_error_callback(test_error_callback);

    vk::InitCore("vulkansc");

    vksc::TestDispatchHelper::PatchDispatchTable();
}

void VkSCTestEnvironment::TearDown() {}

int main(int argc, char **argv) {
    int result;

#if defined(_WIN32)
#if !defined(NDEBUG)
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
#endif
    // Avoid "Abort, Retry, Ignore" dialog boxes
    _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
#endif

    ::testing::InitGoogleTest(&argc, argv);
    VkTestFramework::InitArgs(&argc, argv);

    ::testing::AddGlobalTestEnvironment(new VkSCTestEnvironment);

    result = RUN_ALL_TESTS();

    VkTestFramework::Finish();
    return result;
}
