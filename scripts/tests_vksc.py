#!/usr/bin/env python3
# Copyright (c) 2023-2025 The Khronos Group Inc.
# Copyright (c) 2020-2024 Valve Corporation
# Copyright (c) 2020-2024 LunarG, Inc.
# Copyright (c) 2023-2025 RasterGrid Kft.

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import subprocess
import sys
import os
import argparse
import common_ci

# Where all artifacts will ultimately be placed under
CI_BUILD_DIR = common_ci.RepoRelative('build-ci')
# Where all dependencies will be installed under
CI_EXTERNAL_DIR = f'{CI_BUILD_DIR}/external'
# Where all repos will install to
CI_INSTALL_DIR = f'{CI_BUILD_DIR}/install'

#
# Prepare the Validation Layers for testing
def BuildVVL(config, cmake_args, build_tests):
    print("Log CMake version")
    cmake_ver_cmd = 'cmake --version'
    common_ci.RunShellCmd(cmake_ver_cmd)

    SRC_DIR = common_ci.PROJECT_SRC_DIR
    BUILD_DIR = f'{CI_BUILD_DIR}/vvl'

    print("Configure VVL")
    cmake_cmd = f'cmake -S {SRC_DIR} -B {BUILD_DIR}'
    cmake_cmd += f' -D CMAKE_BUILD_TYPE={config}'
    cmake_cmd += f' -D BUILD_TESTS={build_tests}'
    cmake_cmd += f' -D UPDATE_DEPS=ON -D UPDATE_DEPS_DIR={CI_EXTERNAL_DIR}'
    cmake_cmd += ' -D BUILD_WERROR=ON'
    cmake_cmd += ' -D INSTALL_VVL_TEST_ICD=ON'

    if cmake_args:
         cmake_cmd += f' {cmake_args}'

    common_ci.RunShellCmd(cmake_cmd)

    print("Build VVL")
    build_cmd = f'cmake --build {BUILD_DIR}'
    common_ci.RunShellCmd(build_cmd)

    print("Install VVL")
    install_cmd = f'cmake --install {BUILD_DIR} --prefix {CI_INSTALL_DIR}'
    common_ci.RunShellCmd(install_cmd)

#
# Prepare Loader for executing Layer Validation Tests
def BuildLoader():
    SRC_DIR = f'{CI_EXTERNAL_DIR}/Vulkan-Loader'
    BUILD_DIR = f'{SRC_DIR}/build'

    if not os.path.exists(SRC_DIR):
        print("Unable to find VulkanSC-Loader")
        sys.exit(1)

    print("Run CMake for Loader")
    cmake_cmd = f'cmake -S {SRC_DIR} -B {BUILD_DIR}'
    cmake_cmd += ' -D UPDATE_DEPS=ON -D CMAKE_BUILD_TYPE=Release'

    # GitHub actions runs our test as admin on Windows
    if common_ci.IsGHA() and common_ci.IsWindows():
        cmake_cmd += ' -D LOADER_USE_UNSAFE_FILE_SEARCH=ON'

    common_ci.RunShellCmd(cmake_cmd)

    print("Build Loader")
    build_cmd = f'cmake --build {BUILD_DIR}'
    common_ci.RunShellCmd(build_cmd)

    print("Install Loader")
    install_cmd = f'cmake --install {BUILD_DIR} --prefix {CI_INSTALL_DIR}'
    common_ci.RunShellCmd(install_cmd)

#
# Prepare Mock ICD and device simulation layer for use with Layer Validation Tests
def BuildTools():
    SRC_DIR = f'{CI_EXTERNAL_DIR}/Vulkan-Tools'
    BUILD_DIR = f'{SRC_DIR}/build'

    if not os.path.exists(SRC_DIR):
        print("Unable to find VulkanSC-Tools")
        sys.exit(1)

    print("Configure Tools")
    cmake_cmd = f'cmake -S {SRC_DIR} -B {BUILD_DIR} -D CMAKE_BUILD_TYPE=Release '
    cmake_cmd += '-DBUILD_CUBE=NO -DBUILD_VULKANINFO=NO -D INSTALL_ICD=ON -D UPDATE_DEPS=ON'
    common_ci.RunShellCmd(cmake_cmd)

    print("Build Tools")
    build_cmd = f'cmake --build {BUILD_DIR}'
    common_ci.RunShellCmd(build_cmd)

    print("Install Tools")
    install_cmd = f'cmake --install {BUILD_DIR} --prefix {CI_INSTALL_DIR}'
    common_ci.RunShellCmd(install_cmd)

#
# Module Entrypoint
def Build(args):
    config = args.configuration

    # Since this script uses Ninja to build Windows users need to be in a developer command prompt.
    if common_ci.IsWindows():
        # This environment variable is arbitrary. I just picked one set by the developer command prompt.
        if "VSCMD_ARG_TGT_ARCH" not in os.environ:
            print("This script must be invoked in a developer command prompt!")
            sys.exit(1)

    try:
        BuildVVL(config = config, cmake_args = args.cmake, build_tests = "ON")
        BuildLoader()
        BuildTools()

    except subprocess.CalledProcessError as proc_error:
        print('Command "%s" failed with return code %s' % (' '.join(proc_error.cmd), proc_error.returncode))
        sys.exit(proc_error.returncode)
    except Exception as unknown_error:
        print('An unknown error occured: %s', unknown_error)
        sys.exit(1)

    sys.exit(0)

#
# Run the Layer Validation Tests
def RunVVLTests(args):
    print("Run VVL Tests using Mock ICD")

    lvt_env = dict(os.environ)

    # Because we installed everything to CI_INSTALL_DIR all the libraries/json files are in pre-determined locations
    # defined by GNUInstallDirs. This makes setting VK_LAYER_PATH and other environment variables trivial/robust.
    if common_ci.IsWindows():
        lvt_env['VK_LAYER_PATH'] = os.path.join(CI_INSTALL_DIR, 'bin')
        lvt_env['VK_DRIVER_FILES'] = os.path.join(CI_INSTALL_DIR, 'bin\\VVL_Test_ICD_vksc.json')
    else:
        lvt_env['LD_LIBRARY_PATH'] = os.path.join(CI_INSTALL_DIR, 'lib')
        lvt_env['DYLD_LIBRARY_PATH'] = os.path.join(CI_INSTALL_DIR, 'lib')
        lvt_env['VK_LAYER_PATH'] = os.path.join(CI_INSTALL_DIR, 'share/vulkansc/explicit_layer.d')
        lvt_env['VK_DRIVER_FILES'] = os.path.join(CI_INSTALL_DIR, 'share/vulkansc/icd.d/VVL_Test_ICD_vksc.json')

    # This enables better stack traces from tools like leak sanitizer by using the loader feature which prevents unloading of libraries at shutdown.
    lvt_env['VK_LOADER_DISABLE_DYNAMIC_LIBRARY_UNLOADING'] = '1'

    # Useful for debugging
    # lvt_env['VK_LOADER_DEBUG'] = 'error,warn,info'
    # lvt_env['VK_LAYER_TESTS_PRINT_DRIVER'] = '1'

    lvt_env['VK_INSTANCE_LAYERS'] = 'VK_LAYER_KHRONOS_validation' + os.pathsep + 'VK_LAYER_KHRONOS_device_simulation'

    lvt_cmd = os.path.join(CI_INSTALL_DIR, 'bin', 'vksc_layer_validation_tests')

    if args.tsan:
        # These are tests we have decided are worth using Thread Sanitize as it will take about 9x longer to run a test
        # We have also seen TSAN turn bug out and make each test incrementally take longer
        # (https://github.com/KhronosGroup/Vulkan-ValidationLayers/issues/8931)
        common_ci.RunShellCmd(lvt_cmd + " --gtest_filter=*SyncVal.*:*Threading.*:*SyncObject.*:*Wsi.*:-*Video*", env=lvt_env)
        return

    common_ci.RunShellCmd(lvt_cmd, env=lvt_env)

    print("Re-Running multithreaded tests with VK_LAYER_FINE_GRAINED_LOCKING disabled")
    lvt_env['VK_LAYER_FINE_GRAINED_LOCKING'] = '0'
    common_ci.RunShellCmd(lvt_cmd + ' --gtest_filter=*Thread*', env=lvt_env)

def Test(args):
    try:
        RunVVLTests(args)

    except subprocess.CalledProcessError as proc_error:
        print('Command "%s" failed with return code %s' % (' '.join(proc_error.cmd), proc_error.returncode))
        sys.exit(proc_error.returncode)
    except Exception as unknown_error:
        print('An unknown error occured: %s', unknown_error)
        sys.exit(1)

    sys.exit(0)

if __name__ == '__main__':
    configs = ['release', 'debug']
    default_config = configs[0]

    parser = argparse.ArgumentParser()
    parser.add_argument(
        '-c', '--config', dest='configuration',
        metavar='CONFIG', action='store',
        choices=configs, default=default_config,
        help='Build target configuration. Can be one of: {0}'.format(
            ', '.join(configs)))
    parser.add_argument(
        '--cmake', dest='cmake',
        metavar='CMAKE', type=str,
        default='', help='Additional args to pass to cmake')
    parser.add_argument(
        '--build', dest='build',
        action='store_true', help='Build the layers')
    parser.add_argument(
        '--test', dest='test',
        action='store_true', help='Tests the layers')
    parser.add_argument(
        '--tsan', dest='tsan',
        action='store_true', help='Filter out tests for TSAN')

    args = parser.parse_args()

    if (args.build):
        Build(args)
    if (args.test):
        Test(args)
