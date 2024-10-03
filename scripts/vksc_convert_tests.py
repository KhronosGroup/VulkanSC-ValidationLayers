#!/usr/bin/python3
#
# Copyright (c) 2023-2024 The Khronos Group Inc.
# Copyright (c) 2023-2024 RasterGrid Kft.
#
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
"""vksc_convert_tests.py

Convert Vulkan validation layer tests to Vulkan SC validation layer tests.

Purpose
-------

This program is intended to assist Vulkan SC Validation Layers maintainers
to convert existing Vulkan validation layer tests to Vulkan SC validation
layer tests by injecting the appropriate test framework to handle API
discrepancies and to disable non-applicable test cases.

Python Compatibility
--------------------

This program can be used with Python 3.10 and newer.

Convertion database
-------------------

This program expects to find a JSON file containing the rules for disabling
or modifying test cases. The JSON file contains a "disable" and "modify" key,
accordingly, each with an array of object entries containing the following
keys:

  - "reason" indicates the reason why the test case is disabled or modified
  - "cases" is an array of test case names with "." used as the group
    separator and ".*" matching all test cases within a group
  - for "modify" objects, "patch" is an array of statements to add to the
    beginning of the test case to modify its behavior

Program Options
---------------

See the help text (vksc_convert_tests.py --help) for a complete list of
options.

Program Operation
-----------------

Test case conversion happens with the following command:

$ scripts/vksc_convert_tests.py --input scripts/vksc_convert_tests.json

If the script is ran in a working directory different than the root
source directory, then the --testdir option can be used to indicate the
directory of the test files.

Helper CMake Config File
------------------------

When the program finishes the conversion, it writes a file named
"convertedTests.cmake" which is used by the Vulkan SC validation layer
test CMake build to determine the set of test case source files.

"""

import argparse, os, json, pathlib, re, filecmp, shutil, common_ci

def parse_case_data(test_data: dict, case_data: dict, type: str):
    result = True
    for case_name in case_data['cases']:
        try:
            if case_name[0] == '@':
                continue
            test_suite, test_case = case_name.split('.')
        except:
            print(f'ERROR: Failed to parse case name "{case_name}" in rule type "{type}"')
            result = False
            continue

        if not test_suite in test_data:
            test_data[test_suite] = dict()
        if test_case in test_data[test_suite]:
            print(f'ERROR: Duplicate rule for test case "{case_name}"')
            result = False
        else:
            test_data[test_suite][test_case] = dict()
            test_data[test_suite][test_case]['reason'] = case_data['reason']
            test_data[test_suite][test_case]['disable'] = False
            test_data[test_suite][test_case]['patch'] = []

            if type == 'disable':
                test_data[test_suite][test_case]['disable'] = True

            if type == 'modify':
                test_data[test_suite][test_case]['patch'] = case_data['patch']

    if not result:
        exit(1)

def convert_test_file(args, filename, data, converted_cases):
    result = True

    with open(f'{args.testdir}/unit/{filename}', 'r', encoding='utf-8-sig') as input, open(f'{args.testdir}/vulkansc/converted/{filename}.tmp', 'w', encoding='utf-8') as output:
        output.write('// *** THIS FILE IS GENERATED - DO NOT EDIT ***\n')
        output.write('// See vksc_convert_tests.py for modifications\n')
        output.write('\n')
        for line in input:
            m = re.search(r'\s*TEST_F\(\s*(\w+)\s*,\s*(\w+)\s*\)', line)
            if not m:
                output.write(line)
            else:
                test_suite = m.group(1)
                test_case = m.group(2)

                if test_suite in data:
                    group_data = data[test_suite]
                else:
                    output.write(line)
                    continue

                if test_case in group_data:
                    case_data = group_data[test_case]
                elif '*' in group_data:
                    case_data = group_data['*']
                else:
                    output.write(line)
                    continue

                if not test_suite in converted_cases:
                    converted_cases[test_suite] = {}
                if not test_case in converted_cases[test_suite]:
                    converted_cases[test_suite][test_case] = True
                else:
                    print(f'ERROR: Duplicate test case "{test_suite}.{test_case}" in file "{filename}"')
                    result = False
                    output.write(line)
                    continue

                if case_data['disable']:
                    output.write(f"// {case_data['reason']}\n")
                    output.write(line.replace(test_case, f"DISABLED_{test_case}"))
                else:
                    output.write(line)
                    output.write(f"    // {case_data['reason']}\n")
                    for patch in case_data['patch']:
                        output.write(f'    {patch};\n')

    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Convert Vulkan validation layer tests to Vulkan SC validation layer tests.')

    parser.add_argument(
        '--input',
        dest='input',
        required=True,
        help='Specify input JSON file describing conversion policy')
    parser.add_argument(
        '--testdir',
        dest='testdir',
        default='tests',
        help='Directory containing the Vulkan validation layer tests')

    args = parser.parse_args()

    if not pathlib.Path(args.input).is_file():
        print(f'ERROR: Could not find input file "{args.input}"')
        parser.print_usage()
        exit(2)

    has_clang_format = shutil.which('clang-format') is not None
    if not has_clang_format:
        print("WARNING: Unable to find clang-format!")

    result = True

    file = open(args.input, 'r', encoding='utf-8')
    json_data = json.load(file)
    test_data = dict()
    for type in json_data.keys():
        for case_data in json_data[type]:
            parse_case_data(test_data, case_data, type)
    file.close()

    if not result:
        exit(1)

    filenames = []
    converted_cases = {}

    for filename in sorted(os.listdir(f'{args.testdir}/unit')):
        filenames.append(filename)
        if not convert_test_file(args, filename, test_data, converted_cases):
            result = False

    for test_suite in test_data:
        if not test_suite in converted_cases:
            print(f'ERROR: Could not find test suite for rule "{test_suite}"')
            result = False
        for test_case in test_data[test_suite]:
            if not test_case.startswith('@') and test_case != "*":
                if not test_case in converted_cases[test_suite]:
                    print(f'ERROR: Could not find test case for rule "{test_suite}.{test_case}"')
                    result = False

    if not result:
        for filename in sorted(os.listdir(f'{args.testdir}/vulkansc/converted')):
            if filename.endswith('.tmp'):
                os.remove(f'{args.testdir}/vulkansc/converted/{filename}')
        exit(1)

    for filename in sorted(os.listdir(f'{args.testdir}/vulkansc/converted')):
        if filename.endswith('.tmp'):
            continue
        if not filename in filenames:
            print(f'WARNING: Deleting no longer existing converted test case file "{filename}"')
            os.remove(f'{args.testdir}/vulkansc/converted/{filename}')

    for filename in filenames:
        temp_filename = f'{args.testdir}/vulkansc/converted/{filename}.tmp'
        repo_filename = f'{args.testdir}/vulkansc/converted/{filename}'
        # Run clang-format on the file
        if has_clang_format:
            common_ci.RunShellCmd(f'clang-format -i --style=file:{args.testdir}/../.clang-format {temp_filename}')
        if not os.path.exists(repo_filename) or not filecmp.cmp(temp_filename, repo_filename, shallow=False):
            print(f'Updating converted test case file "{filename}"')
            os.replace(temp_filename, repo_filename)
        else:
            os.remove(temp_filename)

    with open(f'{args.testdir}/vulkansc/convertedTests.cmake', 'w', encoding='utf-8') as cmake:
        cmake.write('# *** THIS FILE IS GENERATED - DO NOT EDIT ***\n')
        cmake.write('# See vksc_convert_tests.py for modifications\n')
        cmake.write('\n')
        cmake.write('# ~~~\n')
        cmake.write('# Copyright (c) 2023-2023 RasterGrid Kft.\n')
        cmake.write('#\n')
        cmake.write('# Licensed under the Apache License, Version 2.0 (the "License");\n')
        cmake.write('# you may not use this file except in compliance with the License.\n')
        cmake.write('# You may obtain a copy of the License at\n')
        cmake.write('#\n')
        cmake.write('#     http://www.apache.org/licenses/LICENSE-2.0\n')
        cmake.write('#\n')
        cmake.write('# Unless required by applicable law or agreed to in writing, software\n')
        cmake.write('# distributed under the License is distributed on an "AS IS" BASIS,\n')
        cmake.write('# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n')
        cmake.write('# See the License for the specific language governing permissions and\n')
        cmake.write('# limitations under the License.\n')
        cmake.write('# ~~~\n')
        cmake.write('\n')
        cmake.write('set(VKSC_CONVERTED_TEST_FILES\n')
        for filename in filenames:
            cmake.write(f'    converted/{filename}\n')
        cmake.write(')\n')

    print('DONE!')
