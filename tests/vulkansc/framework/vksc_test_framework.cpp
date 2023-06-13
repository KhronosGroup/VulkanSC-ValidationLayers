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

#include "../../framework/test_framework.h"
#include "../../framework/render.h"
#include "vksc_test_dispatch_helper.h"
#include <filesystem>
#include <climits>
#include <cmath>
#include <tuple>

// Command-line options
enum TOptions {
    EOptionNone = 0x000,
    EOptionIntermediate = 0x001,
    EOptionSuppressInfolog = 0x002,
    EOptionMemoryLeakMode = 0x004,
    EOptionRelaxedErrors = 0x008,
    EOptionGiveWarnings = 0x010,
    EOptionLinkProgram = 0x020,
    EOptionMultiThreaded = 0x040,
    EOptionDumpConfig = 0x080,
    EOptionDumpReflection = 0x100,
    EOptionSuppressWarnings = 0x200,
    EOptionDumpVersions = 0x400,
    EOptionSpv = 0x800,
    EOptionDefaultDesktop = 0x1000,
};

#ifndef _WIN32

#include <errno.h>

int fopen_s(FILE **pFile, const char *filename, const char *mode) {
    if (!pFile || !filename || !mode) {
        return EINVAL;
    }

    FILE *f = fopen(filename, mode);
    if (!f) {
        if (errno != 0) {
            return errno;
        } else {
            return ENOENT;
        }
    }
    *pFile = f;

    return 0;
}

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

void TestEnvironment::SetUp() {
    // Helps ensure common developer environment variables are set correctly
    CheckEnvironmentVariables();

    vk_testing::set_error_callback(test_error_callback);

    vk::InitDispatchTable("vulkansc");
    vksc::PatchDispatchTable();
}

void TestEnvironment::TearDown() {}

bool VkTestFramework::optionMatch(const char *option, char *optionLine) {
    if (strncmp(option, optionLine, strlen(option)) == 0)
        return true;
    else
        return false;
}

void VkTestFramework::InitArgs(int *argc, char *argv[]) {
    int i, n;

    for (i = 1, n = 1; i < *argc; i++) {
        if (optionMatch("--device-index", argv[i]) && ((i + 1) < *argc)) {
            m_phys_device_index = std::atoi(argv[++i]);
        } else if (optionMatch("--help", argv[i]) || optionMatch("-h", argv[i])) {
            printf("\nOther options:\n");
            printf(
                "\t--show-images\n"
                "\t\tDisplay test images in viewer after tests complete.\n");
            printf(
                "\t--save-images\n"
                "\t\tSave tests images as ppm files in current working directory.\n"
                "\t\tUsed to generate golden images for compare-images.\n");
            printf(
                "\t--compare-images\n"
                "\t\tCompare test images to 'golden' image in golden folder.\n"
                "\t\tAlso saves the generated test image in current working\n"
                "\t\t\tdirectory but only if the image is different from the golden\n"
                "\t\tSetting RENDERTEST_GOLDEN_DIR environment variable can specify\n"
                "\t\t\tdifferent directory for golden images\n"
                "\t\tSignal test failure if different.\n");
            printf(
                "\t--device-index <physical device index>\n"
                "\t\tIndex into VkPhysicalDevice array returned from vkEnumeratePhysicalDevices.\n"
                "\t\tThe default behavior is to automatically choose \"the most reasonable device.\"\n"
                "\t\tAn invalid index (i.e., outside the range [0, *pPhysicalDeviceCount)) will result in the default behavior\n");
            exit(0);
        } else {
            printf("\nUnrecognized option: %s\n", argv[i]);
            printf("\nUse --help or -h for option list.\n");
            exit(0);
        }

        /*
         * Since the above "consume" inputs, update argv
         * so that it contains the trimmed list of args for glutInit
         */

        argv[n] = argv[i];
        n++;
    }
}

void VkTestFramework::Finish() {}

bool VkTestFramework::SetConfigFile(const std::string &name) {
    assert(false);
    return false;
}

void VkTestFramework::ProcessConfigFile(VkPhysicalDeviceLimits const *const device_limits) {
    // Silence unused member variable warnings/errors
    std::ignore = m_num_shader_strings;
    std::ignore = Resources;
    assert(false);
}

void VkTestFramework::SetMessageOptions(EShMessages &messages) {
    if (m_compile_options & EOptionRelaxedErrors) messages = (EShMessages)(messages | EShMsgRelaxedErrors);
    if (m_compile_options & EOptionIntermediate) messages = (EShMessages)(messages | EShMsgAST);
    if (m_compile_options & EOptionSuppressWarnings) messages = (EShMessages)(messages | EShMsgSuppressWarnings);
}

char **VkTestFramework::ReadFileData(const char *fileName) {
    assert(false);
    return NULL;
}

void VkTestFramework::FreeFileData(char **data) { assert(false); }

EShLanguage VkTestFramework::FindLanguage(const std::string &name) {
    assert(false);
    return EShLangVertex;
}

EShLanguage VkTestFramework::FindLanguage(const VkShaderStageFlagBits shader_type) {
    assert(false);
    return EShLangVertex;
}

bool VkTestFramework::GLSLtoSPV(VkPhysicalDeviceLimits const *const device_limits, const VkShaderStageFlagBits shader_type,
                                const char *pshader, std::vector<uint32_t> &spirv, bool debug, const spv_target_env spv_env) {
    // Shader compilation is not supported in Vulkan SC
    assert(false);
    return false;
}

bool VkTestFramework::ASMtoSPV(const spv_target_env target_env, const uint32_t options, const char *pasm,
                               std::vector<uint32_t> &spv) {
    // Shader compilation is not supported in Vulkan SC
    assert(false);
    return false;
}
