#!/usr/bin/env python3
# Copyright (c) 2023-2023 The Khronos Group Inc.
# Copyright (c) 2020-2023 Valve Corporation
# Copyright (c) 2020-2023 LunarG, Inc.
# Copyright (c) 2023-2023 RasterGrid Kft.

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
import subprocess
import platform
import shutil
import argparse

if sys.version_info[0] != 3:
    print("This script requires Python 3. Run script with [-h] option for more details.")
    sys_exit(0)

# Use Ninja for all platforms for performance/simplicity
os.environ['CMAKE_GENERATOR'] = "Ninja"

# Utility for creating a directory if it does not exist. Behaves similarly to 'mkdir -p'
def make_dirs(path, clean=False):
    if clean and os.path.isdir(path):
        shutil.rmtree(path)
    os.makedirs(path, exist_ok=True)

# helper to define paths relative to the repo root
def RepoRelative(path):
    return os.path.abspath(os.path.join(os.path.dirname(__file__), '..', path))

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.split(os.path.abspath(__file__))[0], '..'))

# TODO: Pass this in as arg, may be useful for running locally
EXTERNAL_DIR_NAME = "external"
BUILD_DIR_NAME = "build"
VVL_BUILD_DIR = RepoRelative(BUILD_DIR_NAME)
TEST_INSTALL_DIR = RepoRelative("build/install")

def externalDir(config): return os.path.join(RepoRelative(EXTERNAL_DIR_NAME), config)

# Runs a command in a directory and returns its return code.
# Directory is project root by default, or a relative path from project root
def RunShellCmd(command, start_dir = PROJECT_ROOT, env=None, verbose=False):
    if start_dir != PROJECT_ROOT:
        start_dir = RepoRelative(start_dir)
    cmd_list = command.split(" ")
    if verbose or ('VVL_CI_VERBOSE' in os.environ and os.environ['VVL_CI_VERBOSE'] != '0'):
        print(f'CICMD({cmd_list}, env={env})')
    subprocess.check_call(cmd_list, cwd=start_dir, env=env)

#
# Prepare the Validation Layers for testing
def BuildVVL(config, cmake_args, build_tests):
    print("Log CMake version")
    cmake_ver_cmd = 'cmake --version'
    RunShellCmd(cmake_ver_cmd)

    print("Run CMake for Validation Layers")
    cmake_cmd = f'cmake -S . -B {VVL_BUILD_DIR} -DUPDATE_DEPS=ON -DCMAKE_BUILD_TYPE={config}'
    # By default BUILD_WERROR is OFF, CI should always enable it.
    cmake_cmd += ' -DBUILD_WERROR=ON'
    cmake_cmd += f' -DBUILD_TESTS={build_tests}'
    cmake_cmd += ' -DVULKANSC=ON'

    if cmake_args:
         cmake_cmd += f' {cmake_args}'

    RunShellCmd(cmake_cmd)

    print("Build Validation Layers and Tests")
    build_cmd = f'cmake --build {VVL_BUILD_DIR}'
    RunShellCmd(build_cmd)

    print("Install Validation Layers")
    install_cmd = f'cmake --install {VVL_BUILD_DIR} --prefix {TEST_INSTALL_DIR}'
    RunShellCmd(install_cmd)

    print('Run vk_validation_stats.py')
    ext_dir = externalDir(config)
    stats_script = RepoRelative('scripts/vk_validation_stats.py')
    validusage = os.path.join(ext_dir, 'Vulkan-Headers', 'registry', 'validusage.json')
    outfile = os.path.join('layers', 'vuid_coverage_database.txt')
    RunShellCmd(f'{sys.executable} {stats_script} {validusage} -text {outfile}', VVL_BUILD_DIR)

#
# Prepare Loader for executing Layer Validation Tests
def BuildLoader():
    LOADER_DIR = RepoRelative(os.path.join("%s/VulkanSC-Loader" % EXTERNAL_DIR_NAME))
    # Clone Loader repo
    if not os.path.exists(LOADER_DIR):
        print("Clone Loader Source Code")
        clone_loader_cmd = 'git clone https://github.com/KhronosGroup/VulkanSC-Loader.git'
        RunShellCmd(clone_loader_cmd, EXTERNAL_DIR_NAME)

    print("Run CMake for Loader")
    LOADER_BUILD_DIR = RepoRelative("%s/VulkanSC-Loader/%s" % (EXTERNAL_DIR_NAME, BUILD_DIR_NAME))

    print("Run CMake for Loader")
    cmake_cmd = f'cmake -S {LOADER_DIR} -B {LOADER_BUILD_DIR} '
    cmake_cmd += '-D UPDATE_DEPS=ON -D BUILD_TESTS=OFF -D CMAKE_BUILD_TYPE=Release'
    cmake_cmd += ' -D VULKANSC=ON'
    # This enables better stack traces from leak sanitizer by using the loader feature which prevents unloading of libraries at shutdown.
    if platform.os == 'Linux':
        cmake_cmd += ' -D LOADER_ENABLE_ADDRESS_SANITIZER=ON -D LOADER_DISABLE_DYNAMIC_LIBRARY_UNLOADING=ON'
    RunShellCmd(cmake_cmd)

    print("Build Loader")
    build_cmd = f'cmake --build {LOADER_BUILD_DIR}'
    RunShellCmd(build_cmd)

    print("Install Loader")
    install_cmd = f'cmake --install {LOADER_BUILD_DIR} --prefix {TEST_INSTALL_DIR}'
    RunShellCmd(install_cmd)

#
# Prepare Mock ICD for use with Layer Validation Tests
def BuildMockICD():
    VT_DIR = RepoRelative("%s/VulkanSC-Tools" % EXTERNAL_DIR_NAME)
    if not os.path.exists(VT_DIR):
        print("Clone VulkanSC-Tools Repository")
        clone_tools_cmd = 'git clone https://github.com/KhronosGroup/VulkanSC-Tools.git'
        RunShellCmd(clone_tools_cmd, EXTERNAL_DIR_NAME)

    ICD_BUILD_DIR = RepoRelative("%s/VulkanSC-Tools/%s" % (EXTERNAL_DIR_NAME,BUILD_DIR_NAME))

    print("Running update_deps.py for ICD")
    RunShellCmd(f'python3 scripts/update_deps.py --api vulkansc --dir {EXTERNAL_DIR_NAME} --config release', VT_DIR)

    print("Run CMake for ICD")
    cmake_cmd = f'cmake -S {VT_DIR} -B {ICD_BUILD_DIR} -D CMAKE_BUILD_TYPE=Release '
    cmake_cmd += '-DBUILD_CUBE=NO -DBUILD_VULKANINFO=NO -D INSTALL_ICD=ON '
    cmake_cmd += f'-C {VT_DIR}/{EXTERNAL_DIR_NAME}/helper.cmake'
    cmake_cmd += f' -D VULKANSC=ON'
    RunShellCmd(cmake_cmd)

    print("Build Mock ICD")
    build_cmd = f'cmake --build {ICD_BUILD_DIR}'
    RunShellCmd(build_cmd)

    print("Install Mock ICD")
    install_cmd = f'cmake --install {ICD_BUILD_DIR} --prefix {TEST_INSTALL_DIR}'
    RunShellCmd(install_cmd)

#
# Verify consistency of generated source code
def CheckVVL(config):
    print("Check Generated Source Code Consistency")
    ext_dir = externalDir(config)
    RunShellCmd(f'python3 scripts/generate_source.py --api vulkansc --verify {ext_dir}/Vulkan-Headers/registry {ext_dir}/SPIRV-Headers/include/spirv/unified1/')

#
# Run the Layer Validation Tests
def RunVVLTests(config):
    print("Run VulkanSC-ValidationLayer Tests using Mock ICD")

    lvt_cmd = os.path.join(PROJECT_ROOT, BUILD_DIR_NAME, 'tests', 'vksc_layer_validation_tests')

    lvt_env = dict(os.environ)

    # Because we installed everything to TEST_INSTALL_DIR all the libraries/json files are in pre-determined locations
    # defined by GNUInstallDirs. This makes adding the LD_LIBRARY_PATH and VK_LAYER_PATH trivial/robust.
    lvt_env['LD_LIBRARY_PATH'] = os.path.join(TEST_INSTALL_DIR, 'lib')
    lvt_env['VK_LAYER_PATH'] = os.path.join(TEST_INSTALL_DIR, 'share/vulkansc/explicit_layer.d')
    lvt_env['VK_ICD_FILENAMES'] = os.path.join(TEST_INSTALL_DIR, 'share/vulkansc/icd.d/VkICD_mock_icd_vksc.json')

    lvt_env['VK_INSTANCE_LAYERS'] = 'VK_LAYER_KHRONOS_validation'

    RunShellCmd(lvt_cmd, env=lvt_env)
    print("Re-Running multithreaded tests with VK_LAYER_FINE_GRAINED_LOCKING=1:")
    lvt_env['VK_LAYER_FINE_GRAINED_LOCKING'] = '1'
    RunShellCmd(lvt_cmd + ' --gtest_filter=*Thread*', env=lvt_env)

#
# Module Entrypoint
def Build(args):
    try:
        BuildVVL(args.config, cmake_args = args.cmake, build_tests = "ON")
        CheckVVL(args.config)

    except subprocess.CalledProcessError as proc_error:
        print('Command "%s" failed with return code %s' % (' '.join(proc_error.cmd), proc_error.returncode))
        sys.exit(proc_error.returncode)
    except Exception as unknown_error:
        print('An unkown error occured: %s', unknown_error)
        sys.exit(1)

    sys.exit(0)

def Test(args):
    try:
        BuildLoader()
        BuildMockICD()
        RunVVLTests(config = args.config)

    except subprocess.CalledProcessError as proc_error:
        print('Command "%s" failed with return code %s' % (' '.join(proc_error.cmd), proc_error.returncode))
        sys.exit(proc_error.returncode)
    except Exception as unknown_error:
        print('An unkown error occured: %s', unknown_error)
        sys.exit(1)

    sys.exit(0)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '-c', '--config', dest='config',
        metavar='CONFIG', action='store',
        required=True,
        choices=[ 'release', 'debug' ],
        help='Build target configuration.')
    parser.add_argument(
        '--cmake', dest='cmake',
        metavar='CMAKE', type=str,
        default='',
        help='Additional args to pass to cmake')
    parser.add_argument(
        '--build', dest='build',
        action='store_true',
        help='Build the layers')
    parser.add_argument(
        '--test', dest='test',
        action='store_true',
        help='Tests the layers')
    args = parser.parse_args()

    if (args.build):
        Build(args)
    if (args.test):
        Test(args)
