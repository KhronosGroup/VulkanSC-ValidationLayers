# ~~~
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
# ~~~
include(convertedTests.cmake) # include generated test source file list

add_definitions(-DVULKANSC)

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
    framework/vksc_test_pipeline_helper.h
    framework/vksc_test_pipeline_helper.cpp
    framework/vksc_layer_validation_tests.h
    framework/vksc_layer_validation_tests.cpp
    framework/vksc_pipeline_templates.h
    framework/vksc_render_framework.h
    framework/vksc_render_framework.cpp
    framework/vksc_shader_templates.h
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
    ../framework/shader_helper.h
    ../framework/shader_helper.cpp
    ../framework/pipeline_helper.h
    ../framework/pipeline_helper.cpp
    ../framework/ray_tracing_helper_nv.h
    ../framework/ray_tracing_helper_nv.cpp
    ../framework/ray_tracing_objects.h
    ../framework/ray_tracing_objects.cpp
    ../framework/external_memory_sync.h
    ../framework/external_memory_sync.cpp
    ../framework/barrier_queue_family.h
    ../framework/barrier_queue_family.cpp
    ../framework/descriptor_helper.h
    ../framework/descriptor_helper.cpp
    ../framework/thread_helper.h
    ../framework/thread_helper.cpp
    ../framework/render_pass_helper.h
    ../framework/render_pass_helper.cpp
    ../framework/feature_requirements.h
    ../framework/feature_requirements.cpp
    ../framework/queue_submit_context.h
    ../framework/queue_submit_context.cpp
    negative/command.cpp
    negative/device_create.cpp
    negative/implicit.cpp
    negative/object_reservation.cpp
    negative/others.cpp
    negative/pipeline.cpp
    negative/ported.cpp
    negative/render_pass.cpp
    negative/shader_spirv.cpp
    negative/wsi.cpp
    positive/device_create.cpp
    positive/implicit.cpp
    positive/instance.cpp
    positive/others.cpp
    positive/pipeline.cpp
    positive/shader_spirv.cpp
)

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

find_package(GTest CONFIG)
find_package(glslang CONFIG)

target_link_libraries(vksc_layer_validation_tests PRIVATE
    VkLayer_utils
    glslang::SPIRV
    glslang::SPVRemapper
    SPIRV-Headers::SPIRV-Headers
    GTest::gtest
    GTest::gtest_main
    $<TARGET_NAME_IF_EXISTS:PkgConfig::XCB>
    $<TARGET_NAME_IF_EXISTS:PkgConfig::X11>
    $<TARGET_NAME_IF_EXISTS:PkgConfig::WAYlAND_CLIENT>
)

find_package(SPIRV-Tools CONFIG QUIET)

# See https://github.com/KhronosGroup/SPIRV-Tools/issues/3909 for background on this.
# The targets available from SPIRV-Tools change depending on how SPIRV_TOOLS_BUILD_STATIC is set.
# Try to handle all possible combinations so that we work with externally built packages.
if (TARGET SPIRV-Tools)
    target_link_libraries(vksc_layer_validation_tests PRIVATE SPIRV-Tools)
elseif(TARGET SPIRV-Tools-static)
    target_link_libraries(vksc_layer_validation_tests PRIVATE SPIRV-Tools-static)
elseif(TARGET SPIRV-Tools-shared)
    target_link_libraries(vksc_layer_validation_tests PRIVATE SPIRV-Tools-shared)
else()
    message(FATAL_ERROR "Cannot determine SPIRV-Tools target name")
endif()

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
