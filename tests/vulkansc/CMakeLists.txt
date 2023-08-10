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
include(convertedTests.cmake) # include generated test source file list

add_executable(vksc_layer_validation_tests)
set_target_properties(vksc_layer_validation_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../)

target_compile_definitions(vksc_layer_validation_tests PRIVATE VVL_TESTS_USE_CUSTOM_TEST_FRAMEWORK)

target_sources(vksc_layer_validation_tests PRIVATE
    ${VKSC_CONVERTED_TEST_FILES}
    framework/custom_test_framework.h
    framework/vksc_test_environment.cpp
    framework/vksc_test_dispatch_helper.h
    framework/vksc_test_dispatch_helper.cpp
    framework/vksc_test_pipeline_cache_helper.h
    framework/vksc_test_pipeline_cache_helper.cpp
    framework/vksc_layer_validation_tests.h
    framework/vksc_layer_validation_tests.cpp
    framework/vksc_render_framework.h
    framework/vksc_render_framework.cpp
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
    ../framework/test_framework.cpp
    ../framework/ray_tracing_objects.h
    ../framework/ray_tracing_objects.cpp
    negative/command.cpp
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

# TODO: Remove once Android.mk is gone.
target_compile_definitions(vksc_layer_validation_tests PRIVATE VVL_TESTS_USE_CMAKE)

add_dependencies(vksc_layer_validation_tests vvl)
target_include_directories(vksc_layer_validation_tests PRIVATE . ..)

target_compile_options(vksc_layer_validation_tests PRIVATE "$<IF:$<CXX_COMPILER_ID:MSVC>,/wd4100,-Wno-unused-parameter>")

if(${CMAKE_CXX_COMPILER_ID} MATCHES "(GNU|Clang)")
    target_compile_options(vksc_layer_validation_tests PRIVATE
        -Wno-sign-compare
        -Wno-shorten-64-to-32
        -Wno-missing-field-initializers
    )
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(vksc_layer_validation_tests PRIVATE
            -Wno-sign-conversion
            -Wno-implicit-int-conversion
        )
    endif()
elseif(MSVC)
    target_compile_options(vksc_layer_validation_tests PRIVATE
        /wd4389 # signed/unsigned mismatch
        /wd4267 # Disable some signed/unsigned mismatch warnings.
    )

    set_target_properties(vksc_layer_validation_tests PROPERTIES VS_DEBUGGER_ENVIRONMENT "VK_LAYER_PATH=$<TARGET_FILE_DIR:vvl>")

    if (CMAKE_SIZEOF_VOID_P EQUAL 4)
        # Due to IHV driver issues, we need the extra 2GB of virtual address space for 32 bit testing
        target_link_options(vksc_layer_validation_tests PRIVATE /LARGEADDRESSAWARE)
    endif()
endif()

find_package(GTest REQUIRED CONFIG QUIET)
find_package(glslang REQUIRED CONFIG QUIET)

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
    $<TARGET_NAME_IF_EXISTS:PkgConfig::XCB>
    $<TARGET_NAME_IF_EXISTS:PkgConfig::X11>
    $<TARGET_NAME_IF_EXISTS:PkgConfig::WAYlAND_CLIENT>
)

install(TARGETS vksc_layer_validation_tests)

include(GoogleTest)
# gtest_discover_tests requires running the output binaries which will not
# work with cross-compiling, thus we fall back to using gtest_add_tests
if (CMAKE_CROSSCOMPILING)
    gtest_add_tests(TARGET vksc_layer_validation_tests)
else()
    gtest_discover_tests(vksc_layer_validation_tests DISCOVERY_TIMEOUT 100)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../layers ${CMAKE_CURRENT_BINARY_DIR}/../layers)
