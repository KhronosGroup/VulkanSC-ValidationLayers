# ~~~
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
# ~~~
include(GoogleTest) # gtest_discover_tests

# GoogleTest is required for testing framework
find_package(GTest REQUIRED CONFIG)

# glslang is required for testing framework
find_package(glslang CONFIG REQUIRED)

include(convertedTests.cmake) # include generated test source file list

add_executable(vksc_layer_validation_tests)
set_target_properties(vksc_layer_validation_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../)

target_sources(vksc_layer_validation_tests PRIVATE
    ${VKSC_CONVERTED_TEST_FILES}
    framework/vksc_test_dispatch_helper.h
    framework/vksc_test_dispatch_helper.cpp
    framework/vksc_test_pipeline_cache_helper.h
    framework/vksc_test_pipeline_cache_helper.cpp
    framework/vksc_test_framework.cpp
    framework/vksc_layer_validation_tests.h
    framework/vksc_layer_validation_tests.cpp
    framework/vksc_compatible_layer_validation_tests.h
    framework/vksc_compatible_layer_validation_tests.cpp
    ../framework/layer_validation_tests.h
    ../framework/layer_validation_tests.cpp
    ../framework/test_common.h
    ../framework/error_monitor.cpp
    ../framework/error_monitor.h
    ../framework/video_objects.h
    ../framework/render.cpp
    ../framework/render.h
    ../framework/binding.h
    ../framework/binding.cpp
    ../framework/test_framework.h
    ../framework/ray_tracing_objects.h
    ../framework/ray_tracing_objects.cpp
    negative/device_create.cpp
    negative/implicit.cpp
    negative/object_reservation.cpp
    negative/others.cpp
    negative/pipeline.cpp
    negative/ported.cpp
    negative/render_pass.cpp
    positive/implicit.cpp
    positive/instance.cpp
    positive/others.cpp
    positive/pipeline.cpp
)

# gtest_discover_tests has problem with cross-compiling, but it is faster and more robust
if (CMAKE_CROSSCOMPILING)
    gtest_add_tests(TARGET vksc_layer_validation_tests)
else()
    gtest_discover_tests(vksc_layer_validation_tests DISCOVERY_TIMEOUT 100)
endif()

add_dependencies(vksc_layer_validation_tests vvl)
target_include_directories(vksc_layer_validation_tests PRIVATE . .. ${VVL_SOURCE_DIR}/layers/vulkansc/generated)

if(${CMAKE_CXX_COMPILER_ID} MATCHES "(GNU|Clang)")
    target_compile_options(vksc_layer_validation_tests PRIVATE
        -Wno-sign-compare
        -Wno-shorten-64-to-32
        -Wno-unused-parameter
        -Wno-missing-field-initializers
    )
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(vksc_layer_validation_tests PRIVATE 
            -Wno-sign-conversion
            -Wno-implicit-int-conversion
            -Wno-enum-enum-conversion
        )
    endif()
elseif(MSVC)
    # Disable some signed/unsigned mismatch warnings.
    target_compile_options(vksc_layer_validation_tests PRIVATE /wd4267)

    if(MSVC_IDE)
        set_target_properties(vksc_layer_validation_tests PROPERTIES VS_DEBUGGER_ENVIRONMENT "VK_LAYER_PATH=$<TARGET_FILE_DIR:vvl>")
    endif()

    if (CMAKE_SIZEOF_VOID_P EQUAL 4)
        # Due to IHV driver issues, we need the extra 2GB of virtual address space for 32 bit testing
        target_link_options(vksc_layer_validation_tests PRIVATE /LARGEADDRESSAWARE)
    endif()
endif()

target_link_libraries(vksc_layer_validation_tests PRIVATE
    VkLayer_utils
    glslang::glslang
    glslang::OGLCompiler
    glslang::OSDependent
    glslang::MachineIndependent
    glslang::GenericCodeGen
    glslang::HLSL
    glslang::SPIRV
    glslang::SPVRemapper
    VVL-SPIRV-LIBS
    GTest::gtest
    GTest::gtest_main
    ${CMAKE_DL_LIBS}
    $<TARGET_NAME_IF_EXISTS:PkgConfig::XCB>
    $<TARGET_NAME_IF_EXISTS:PkgConfig::X11>
    $<TARGET_NAME_IF_EXISTS:PkgConfig::WAYlAND_CLIENT>
)

option(INSTALL_TESTS "Install tests")
if(INSTALL_TESTS)
    install(TARGETS vksc_layer_validation_tests)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../layers ${CMAKE_CURRENT_BINARY_DIR}/../layers)
