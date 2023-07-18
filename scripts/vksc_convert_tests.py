#!/usr/bin/python3
#
# Copyright (c) 2013-2023 The Khronos Group Inc.
# Copyright (c) 2023-2023 RasterGrid Kft.
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

This program can be used with Python 3.7 and newer.

Convertion database
-------------------

This program expects to find a JSON file containing a dictionary of the
test suites, within them a dictionary of individual test cases or the
"*" wildcard matching all test cases within the test suite, with the
value of the entries indicating the test suite name to replace the
source test suite name so that appropriate custom test framework
utilities get applied to them. If the value is "false" instead of a
test suite, then the test case is disabled.
For test suite names starting with "Negative" and "Positive" we just
use the original name by default.

Program Options
---------------

See the help text (update_deps.py --help) for a complete list of options.

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

import argparse, os, json, pathlib, re

def convert_test_file(args, filename, data, converted_cases):
    result = True
    missing_group_rule = set()
    missing_case_rule = set()

    with open(f'{args.testdir}/unit/{filename}', 'r') as input, open(f'{args.testdir}/vulkansc/converted/{filename}', 'w') as output:
        output.write('// *** THIS FILE IS GENERATED - DO NOT EDIT ***\n')
        output.write('// See vksc_convert_tests.py for modifications\n')
        output.write('\n')
        for line in input:
            m = re.search('\s*TEST_F\(\s*(\w+)\s*,\s*(\w+)\s*\)', line)
            if not m:
                output.write(line)
            else:
                test_suite = m.group(1)
                test_case = m.group(2)

                if test_suite in data:
                    group_data = data[test_suite]
                elif test_suite.startswith('Negative') or test_suite.startswith('Positive'):
                    # Just default to using the name of the test group
                    group_data = {
                        '*': test_suite
                    }
                else:
                    if test_suite not in missing_group_rule:
                        print(f'ERROR: Could not find rule for test suite "{test_suite}" in file "{filename}"')
                        missing_group_rule.add(test_suite)
                    result = False
                    output.write(line)
                    continue

                if test_case in group_data:
                    case_data = group_data[test_case]
                elif '*' in group_data:
                    case_data = group_data['*']
                elif test_suite.startswith('Negative') or test_suite.startswith('Positive'):
                    # Just default to using the name of the test group
                    case_data = test_suite
                else:
                    full_case_name = f"{test_suite}.{test_case}"
                    if full_case_name not in missing_case_rule:
                        print(f'ERROR: Could not find rule for test case "{full_case_name}" in file "{filename}"')
                        missing_case_rule.add(full_case_name)
                    result = False
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

                if case_data == False:
                    output.write(line.replace(test_case, f"DISABLED_{test_case}"))
                else:
                    output.write(line.replace(test_suite, case_data))

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

    file = open(args.input, 'r')
    data = json.load(file)
    file.close()

    exceptions = [ 'vksyncvaltests.cpp' ]

    filenames = []
    converted_cases = {}

    result = True
    for filename in sorted(os.listdir(f'{args.testdir}/unit')):
        filenames.append(filename)
        if not convert_test_file(args, filename, data, converted_cases):
            result = False

    for test_suite in data:
        if not test_suite in converted_cases:
            print(f'ERROR: Could not find test suite for rule "{test_suite}"')
            result = False
        for test_case in data[test_suite]:
            if not test_case.startswith('@') and test_case != "*":
                if not test_case in converted_cases[test_suite]:
                    print(f'ERROR: Could not find test case for rule "{test_suite}.{test_case}"')
                    result = False

    if not result:
        exit(1)

    for filename in sorted(os.listdir(f'{args.testdir}/vulkansc/converted')):
        if not filename in filenames:
            print(f'WARNING: Deleting no longer existing converted test case file "{filename}"')
            os.remove(f'{args.testdir}/vulkansc/converted/{filename}')


    with open(f'{args.testdir}/vulkansc/convertedTests.cmake', 'w') as cmake:
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
