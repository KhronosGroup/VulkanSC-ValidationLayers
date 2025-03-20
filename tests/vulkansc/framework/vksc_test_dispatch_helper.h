/*
 * Copyright (c) 2023-2025 The Khronos Group Inc.
 * Copyright (c) 2023-2025 RasterGrid Kft.
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
#pragma once

#include "generated/vk_function_pointers.h"
#include "containers/custom_containers.h"

#include <vector>

class VkSCCompatibilityRenderFramework;

namespace vksc {

using namespace ::vk;

extern PFN_vkGetInstanceProcAddr GetInstanceProcAddr;
extern PFN_vkGetDeviceProcAddr GetDeviceProcAddr;
extern PFN_vkCreateInstance CreateInstance;
extern PFN_vkDestroyInstance DestroyInstance;
extern PFN_vkCreateDevice CreateDevice;
extern PFN_vkCreatePipelineCache CreatePipelineCache;
extern PFN_vkCreateComputePipelines CreateComputePipelines;
extern PFN_vkCreateGraphicsPipelines CreateGraphicsPipelines;
extern PFN_vkDestroyPipeline DestroyPipeline;
extern PFN_vkCreateCommandPool CreateCommandPool;
extern PFN_vkBeginCommandBuffer BeginCommandBuffer;
extern PFN_vkResetCommandBuffer ResetCommandBuffer;
extern PFN_vkCreateRenderPass CreateRenderPass;
extern PFN_vkCreateRenderPass2 CreateRenderPass2;
extern PFN_vkCreateFramebuffer CreateFramebuffer;
extern PFN_vkCreateSemaphore CreateSemaphore;

const VkDeviceObjectReservationCreateInfo& GetDefaultObjectReservationCreateInfo();

class TestDispatchHelper {
  public:
    class DispatchPolicy {
      public:
        DispatchPolicy& SkipOnMessage(const char* vuid, const char* message, bool condition = true) {
            if (condition) {
                skip_on_vuids_.push_back(std::pair(vuid, message));
            }
            return *this;
        }

        DispatchPolicy& IgnoreMessage(const char* vuid, bool condition = true) {
            if (condition) {
                ignore_vuids_.push_back(vuid);
            }
            return *this;
        }

      private:
        DispatchPolicy() = default;
        friend class TestDispatchHelper;

        std::vector<std::pair<const char*, const char*>> skip_on_vuids_{};
        std::vector<const char*> ignore_vuids_{};
    };

    static void PatchDispatchTable();

    TestDispatchHelper(VkSCCompatibilityRenderFramework* test_case);
    virtual ~TestDispatchHelper();

    void RegisterInstance(VkInstance instance);
    void UnregisterInstance(VkInstance instance);

    VkSCCompatibilityRenderFramework* TestCase() const { return test_case_; }

    void SkipUnsupportedTest(const char* message);

    DispatchPolicy CreateDispatchPolicy() { return DispatchPolicy(); }

    void BeginDispatchPolicy(DispatchPolicy& policy);
    void EndDispatchPolicy(DispatchPolicy& policy);

  private:
    bool MessengersValid() const { return messengers_valid_; }

    static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT message_severity,
                                                        VkDebugUtilsMessageTypeFlagsEXT message_types,
                                                        const VkDebugUtilsMessengerCallbackDataEXT* callback_data, void* user_data);

    inline static thread_local const char* tls_skip_message_{nullptr};
    inline static thread_local DispatchPolicy* tls_dispatch_policy_{nullptr};

    VkSCCompatibilityRenderFramework* test_case_{nullptr};
    bool messengers_valid_{true};
    vvl::unordered_map<VkInstance, VkDebugUtilsMessengerEXT> messengers_{};
};

}  // namespace vksc
