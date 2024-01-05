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

#include "vksc_test_dispatch_helper.h"
#include "vksc_test_pipeline_cache_helper.h"
#include "vksc_render_framework.h"

#include "gtest/gtest.h"

#include <functional>
#include <vector>
#include <tuple>

#include <assert.h>
#include <string.h>

namespace vksc {

static VkDeviceObjectReservationCreateInfo default_object_reservation_info{};
static VkPerformanceQueryReservationInfoKHR default_perf_query_reservation_info{};

static void InitDefaultObjectReservationInfo() {
    // Initialize default object reservation info
    default_object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>();

    default_object_reservation_info.pipelineCacheCreateInfoCount = 1;
    default_object_reservation_info.pPipelineCacheCreateInfos = &GetDefaultPipelineCacheCreateInfo();

    default_object_reservation_info.pipelinePoolSizeCount = 1;
    default_object_reservation_info.pPipelinePoolSizes = &GetDefaultPipelinePoolSize();

    // Use some reasonable upper bounds for object request counts
    default_object_reservation_info.semaphoreRequestCount = 65536;
    default_object_reservation_info.commandBufferRequestCount = 4096;
    default_object_reservation_info.fenceRequestCount = 65536;
    default_object_reservation_info.deviceMemoryRequestCount = 1024;
    default_object_reservation_info.bufferRequestCount = 256;
    default_object_reservation_info.imageRequestCount = 256;
    default_object_reservation_info.eventRequestCount = 4096;
    default_object_reservation_info.queryPoolRequestCount = 256;
    default_object_reservation_info.bufferViewRequestCount = 1024;
    default_object_reservation_info.imageViewRequestCount = 1024;
    default_object_reservation_info.layeredImageViewRequestCount = 1024;
    default_object_reservation_info.pipelineCacheRequestCount = 64;
    default_object_reservation_info.pipelineLayoutRequestCount = 64;
    default_object_reservation_info.renderPassRequestCount = 64;
    default_object_reservation_info.graphicsPipelineRequestCount = 64;
    default_object_reservation_info.computePipelineRequestCount = 64;
    default_object_reservation_info.descriptorSetLayoutRequestCount = 256;
    default_object_reservation_info.samplerRequestCount = 256;
    default_object_reservation_info.descriptorPoolRequestCount = 64;
    default_object_reservation_info.descriptorSetRequestCount = 1024;
    default_object_reservation_info.framebufferRequestCount = 64;
    default_object_reservation_info.commandPoolRequestCount = 64;
    default_object_reservation_info.samplerYcbcrConversionRequestCount = 64;
    default_object_reservation_info.surfaceRequestCount = 0;
    default_object_reservation_info.swapchainRequestCount = 64;
    default_object_reservation_info.displayModeRequestCount = 0;
    default_object_reservation_info.subpassDescriptionRequestCount = 64;
    default_object_reservation_info.attachmentDescriptionRequestCount = 256;
    default_object_reservation_info.descriptorSetLayoutBindingRequestCount = 1024;

    default_object_reservation_info.descriptorSetLayoutBindingLimit = 1024;
    default_object_reservation_info.maxImageViewMipLevels = 13;
    default_object_reservation_info.maxImageViewArrayLayers = 256;
    default_object_reservation_info.maxLayeredImageViewMipLevels = 13;
    default_object_reservation_info.maxOcclusionQueriesPerPool = 256;
    default_object_reservation_info.maxPipelineStatisticsQueriesPerPool = 256;
    default_object_reservation_info.maxTimestampQueriesPerPool = 256;
    default_object_reservation_info.maxImmutableSamplersPerDescriptorSetLayout = 256;

    // TODO: Vulkan SC - Enable this once private data support actually arrives to Vulkan SC
#if 0
    // Private data reservation info
    default_private_data_reservation_info = vku::InitStruct<VkDevicePrivateDataCreateInfoEXT>();
    default_private_data_reservation_info.privateDataSlotRequestCount = 16;
#endif

    // Performance query reservation info
    default_perf_query_reservation_info = vku::InitStruct<VkPerformanceQueryReservationInfoKHR>();
    default_perf_query_reservation_info.maxPerformanceQueriesPerPool = 8;
}

const VkDeviceObjectReservationCreateInfo& GetDefaultObjectReservationCreateInfo() { return default_object_reservation_info; }

}  // namespace vksc

namespace vk {

namespace compatibility {

static vksc::TestDispatchHelper* DispatchHelper() { return VkSCCompatibilityRenderFramework::DispatchHelper(); }
static VkSCCompatibilityRenderFramework& RenderFramework() { return VkSCCompatibilityRenderFramework::RenderFrameworkInstance(); }

template <typename T>
static T Features() {
    return RenderFramework().GetVulkanFeatures<T>();
}

template <typename T>
static T Props() {
    return RenderFramework().GetVulkanProperties<T>();
}

static const char* GetCompatibilityProcName(const char* pName) {
    // Make KHR Vulkan entry points for Vulkan SC core features available, as many test
    // cases do not actually check for the right pre-conditions to decide whether to use
    // the core or extension entry points of promoted features
#define VKSC__KHR_COMPAT_EP(name) std::make_pair<std::string, const char*>(std::string("vk" #name "KHR"), "vk" #name)
#define VKSC__EXT_COMPAT_EP(name) std::make_pair<std::string, const char*>(std::string("vk" #name "EXT"), "vk" #name)

    static std::unordered_map<std::string, const char*> compatibility_table = {

        // VK_KHR_bind_memory2 -> Vulkan 1.1 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(BindBufferMemory2),
        VKSC__KHR_COMPAT_EP(BindImageMemory2),

        // VK_KHR_device_group -> Vulkan 1.1 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(GetDeviceGroupPeerMemoryFeatures),
        VKSC__KHR_COMPAT_EP(CmdSetDeviceMask),
        VKSC__KHR_COMPAT_EP(CmdDispatchBase),

        // VK_KHR_device_group_creation -> Vulkan 1.1 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(EnumeratePhysicalDeviceGroups),

        // VK_KHR_get_memory_requirements2 -> Vulkan 1.1 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(GetImageMemoryRequirements2),
        VKSC__KHR_COMPAT_EP(GetBufferMemoryRequirements2),

        // VK_KHR_get_physical_device_properties2 -> Vulkan 1.1 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(GetPhysicalDeviceFeatures2),
        VKSC__KHR_COMPAT_EP(GetPhysicalDeviceProperties2),
        VKSC__KHR_COMPAT_EP(GetPhysicalDeviceFormatProperties2),
        VKSC__KHR_COMPAT_EP(GetPhysicalDeviceImageFormatProperties2),
        VKSC__KHR_COMPAT_EP(GetPhysicalDeviceQueueFamilyProperties2),
        VKSC__KHR_COMPAT_EP(GetPhysicalDeviceMemoryProperties2),

        // VK_KHR_sampler_ycbcr_conversion -> Vulkan 1.1 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(CreateSamplerYcbcrConversion),
        VKSC__KHR_COMPAT_EP(DestroySamplerYcbcrConversion),

        // VK_KHR_external_memory_capabilities -> Vulkan 1.1 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(GetPhysicalDeviceExternalBufferProperties),

        // VK_KHR_external_fence_capabilities -> Vulkan 1.1 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(GetPhysicalDeviceExternalFenceProperties),

        // VK_KHR_external_semaphore_capabilities -> Vulkan 1.1 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(GetPhysicalDeviceExternalSemaphoreProperties),

        // VK_KHR_maintenance3 -> Vulkan 1.1 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(GetDescriptorSetLayoutSupport),

        // VK_KHR_draw_indirect_count -> Vulkan 1.2 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(CmdDrawIndirectCount),
        VKSC__KHR_COMPAT_EP(CmdDrawIndexedIndirectCount),

        // VK_KHR_create_renderpass2 -> Vulkan 1.2 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(CreateRenderPass2),
        VKSC__KHR_COMPAT_EP(CmdBeginRenderPass2),
        VKSC__KHR_COMPAT_EP(CmdNextSubpass2),
        VKSC__KHR_COMPAT_EP(CmdEndRenderPass2),

        // VK_EXT_host_query_reset -> Vulkan 1.2 -> Vulkan SC 1.0
        VKSC__EXT_COMPAT_EP(ResetQueryPool),

        // VK_KHR_timeline_semaphore -> Vulkan 1.2 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(GetSemaphoreCounterValue),
        VKSC__KHR_COMPAT_EP(WaitSemaphores),
        VKSC__KHR_COMPAT_EP(SignalSemaphore),

        // VK_KHR_buffer_device_address -> Vulkan 1.2 -> Vulkan SC 1.0
        VKSC__KHR_COMPAT_EP(GetBufferDeviceAddress),
        VKSC__KHR_COMPAT_EP(GetBufferOpaqueCaptureAddress),
        VKSC__KHR_COMPAT_EP(GetDeviceMemoryOpaqueCaptureAddress),
    };

    auto it = compatibility_table.find(pName);
    if (it != compatibility_table.end()) {
        return it->second;
    } else {
        return pName;
    }
}

static VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetInstanceProcAddr(VkInstance instance, const char* pName) {
    return vksc::GetInstanceProcAddr(instance, GetCompatibilityProcName(pName));
}

static VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetDeviceProcAddr(VkDevice device, const char* pName) {
    return vksc::GetDeviceProcAddr(device, GetCompatibilityProcName(pName));
}

static VKAPI_ATTR void VKAPI_CALL FreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) {
    // Vulkan SC removed vkFreeMemory(), but we provide an implementation here that is treated
    // as a no-op for Vulkan validation layer test compatibility.
}

static VKAPI_ATTR void VKAPI_CALL DestroyQueryPool(VkDevice device, VkQueryPool queryPool,
                                                   const VkAllocationCallbacks* pAllocator) {
    // Vulkan SC removed vkDestroyQueryPool(), but we provide an implementation here that is
    // treated as a no-op for Vulkan validation layer test compatibility.
}

static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool,
                                                        const VkAllocationCallbacks* pAllocator) {
    // Vulkan SC removed vkDestroyDescriptorPool(), but we provide an implementation here that is
    // treated as a no-op for Vulkan validation layer test compatibility.
}

static VKAPI_ATTR void VKAPI_CALL DestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                                     const VkAllocationCallbacks* pAllocator) {
    // Vulkan SC removed vkDestroyCommandPool(), but we provide an implementation here that is
    // treated as a no-op for Vulkan validation layer test compatibility.
}

static VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain,
                                                      const VkAllocationCallbacks* pAllocator) {
    // Vulkan SC removed vkDestroySwapchainKHR(), but we provide an implementation here that is
    // treated as a no-op for Vulkan validation layer test compatibility.
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) {
    // Vulkan SC removed shader modules, but as some of the Vulkan validation layer test framework
    // relies on calling this, we simply "emulate" it by always returning a null handle but
    // success. This seems sufficient to run the upstream tests against MockICD.
    *pShaderModule = VK_NULL_HANDLE;
    return VK_SUCCESS;
}

static VKAPI_ATTR void VKAPI_CALL DestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                                      const VkAllocationCallbacks* pAllocator) {
    // Vulkan SC removed shader modules, but we add a placeholder no-op implementation for
    // Vulkan validation layer test compatibility. Only VK_NULL_HANDLE is expected here.
    assert(shaderModule == VK_NULL_HANDLE);
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateInstance(const VkInstanceCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) {
    // Override requested Vulkan API version with corresponding Vulkan SC API version
    auto create_info = *pCreateInfo;
    auto app_info = vku::InitStruct<VkApplicationInfo>();
    if (create_info.pApplicationInfo != nullptr) {
        app_info = *create_info.pApplicationInfo;
    }
    create_info.pApplicationInfo = &app_info;
    if (VK_API_VERSION_VARIANT(app_info.apiVersion) != VKSC_API_VARIANT) {
        if (app_info.apiVersion < VK_API_VERSION_1_3) {
            app_info.apiVersion = VKSC_API_VERSION_1_0;
        } else {
            DispatchHelper()->SkipUnsupportedTest("Test case was written against Vulkan 1.3");
        }
    }
    VkResult result = vksc::CreateInstance(&create_info, pAllocator, pInstance);
    if (result == VK_SUCCESS && DispatchHelper() != nullptr) {
        DispatchHelper()->RegisterInstance(*pInstance);
    }
    return result;
}

static VKAPI_ATTR void VKAPI_CALL DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) {
    if (DispatchHelper() != nullptr) {
        DispatchHelper()->UnregisterInstance(instance);
    }
    vksc::DestroyInstance(instance, pAllocator);
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) {
    // When running Vulkan validation layer tests against the Vulkan SC validation layers
    // we need to manually inject the default Vulkan SC 1.0 features and object reservation info
    // structures to the pNext chain of pCreateInfo.
    VkDeviceCreateInfo create_info = *pCreateInfo;

    VkDeviceObjectReservationCreateInfo object_reservation_info;
    if (!vku::FindStructInPNextChain<VkDeviceObjectReservationCreateInfo>(create_info.pNext)) {
        object_reservation_info = vksc::default_object_reservation_info;
        object_reservation_info.pNext = create_info.pNext;
        create_info.pNext = &object_reservation_info;
    }

    VkPerformanceQueryReservationInfoKHR perf_query_reservation_info;
    if (!vku::FindStructInPNextChain<VkPerformanceQueryReservationInfoKHR>(create_info.pNext)) {
        perf_query_reservation_info = vksc::default_perf_query_reservation_info;
        perf_query_reservation_info.pNext = create_info.pNext;
        create_info.pNext = &perf_query_reservation_info;
    }

    VkPhysicalDeviceVulkanSC10Features sc_10_features;
    if (!vku::FindStructInPNextChain<VkPhysicalDeviceVulkanSC10Features>(create_info.pNext)) {
        sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>();
        sc_10_features.pNext = (void*)create_info.pNext;
        create_info.pNext = &sc_10_features;
    }

    return vksc::CreateDevice(physicalDevice, &create_info, pAllocator, pDevice);
}

static VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo,
                                                          const VkAllocationCallbacks* pAllocator,
                                                          VkPipelineCache* pPipelineCache) {
    VkPipelineCacheCreateInfo create_info = *pCreateInfo;
    if (create_info.initialDataSize == 0) {
        // When running Vulkan validation layer tests against the Vulkan SC validation layers
        // we need to manually inject placeholder pipeline cache data, as in Vulkan SC pipeline
        // caches cannot be created without any data in them like in Vulkan.
        create_info.flags |= VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT | VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT;
        create_info.initialDataSize = vksc::GetDefaultPipelineCacheData().size();
        create_info.pInitialData = vksc::GetDefaultPipelineCacheData().data();
    }

    return vksc::CreatePipelineCache(device, &create_info, pAllocator, pPipelineCache);
}

template <typename CREATE_INFO, typename CREATE_FUNC>
static VkResult CreatePipelines(VkDevice device, VkPipelineCache pipeline_cache, uint32_t create_info_count,
                                const CREATE_INFO* create_infos, VkPipeline* pipelines, CREATE_FUNC create_func) {
    // If the application did not provide a pipeline cache, let's use a default one
    if (pipeline_cache == VK_NULL_HANDLE) {
        pipeline_cache = RenderFramework().GetDefaultPipelineCache();
    }

    // When running Vulkan validation layer tests against the Vulkan SC validation layers
    // we need to manually inject the default offline pipeline creation info, if not present.
    bool need_to_chain_offline_info = false;
    for (uint32_t i = 0; i < create_info_count; ++i) {
        if (!vku::FindStructInPNextChain<VkPipelineOfflineCreateInfo>(create_infos[i].pNext)) {
            need_to_chain_offline_info = true;
        }
    }
    if (need_to_chain_offline_info) {
        if (create_info_count == 1) {
            auto offline_info = vksc::GetDefaultPipelineOfflineCreateInfo();
            auto create_info = create_infos[0];
            offline_info.pNext = create_info.pNext;
            create_info.pNext = &offline_info;

            // Make sure basePipelineIndex is not -1, as in Vulkan that's the "default" value
            create_info.basePipelineIndex = 0;

            return create_func(device, pipeline_cache, 1, &create_info, nullptr, pipelines);
        } else {
            std::vector<VkPipelineOfflineCreateInfo> offline_info(create_info_count, vksc::GetDefaultPipelineOfflineCreateInfo());
            std::vector<CREATE_INFO> create_info_vec(create_info_count);
            for (uint32_t i = 0; i < create_info_count; ++i) {
                create_info_vec[i] = create_infos[i];
                offline_info[i].pNext = create_info_vec[i].pNext;
                create_info_vec[i].pNext = &offline_info[i];

                // Make sure basePipelineIndex is not -1, as in Vulkan that's the "default" value
                create_info_vec[i].basePipelineIndex = 0;
            }
            return create_func(device, pipeline_cache, create_info_count, create_info_vec.data(), nullptr, pipelines);
        }
    } else {
        return create_func(device, pipeline_cache, create_info_count, create_infos, nullptr, pipelines);
    }
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                             uint32_t createInfoCount,
                                                             const VkComputePipelineCreateInfo* pCreateInfos,
                                                             const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    // Handle any Vulkan SC specific patching needed for pipeline creation
    return CreatePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pPipelines, vksc::CreateComputePipelines);
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                              uint32_t createInfoCount,
                                                              const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                              const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    // Handle any Vulkan SC specific patching needed for pipeline creation
    return CreatePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pPipelines, vksc::CreateGraphicsPipelines);
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) {
    // When running Vulkan validation layer tests against the Vulkan SC validation layers
    // we need to manually inject the command pool memory reservation info structure to the
    // pNext chain of pCreateInfo.
    VkCommandPoolCreateInfo create_info = *pCreateInfo;

    auto mem_reservation_info = vku::InitStruct<VkCommandPoolMemoryReservationCreateInfo>();
    if (!vku::FindStructInPNextChain<VkCommandPoolMemoryReservationCreateInfo>(create_info.pNext)) {
        mem_reservation_info.commandPoolReservedSize = 1024 * 1024;
        mem_reservation_info.commandPoolMaxCommandBuffers = 64;
        mem_reservation_info.pNext = create_info.pNext;
        create_info.pNext = &mem_reservation_info;
    }

    return vksc::CreateCommandPool(device, &create_info, pAllocator, pCommandPool);
}

static VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(VkCommandBuffer commandBuffer,
                                                         const VkCommandBufferBeginInfo* pBeginInfo) {
    static auto policy =
        DispatchHelper()
            ->CreateDispatchPolicy()
            .SkipOnMessage("VUID-vkBeginCommandBuffer-commandPoolResetCommandBuffer-05136",
                           "Test requires VkPhysicalDeviceVulkanSC10Properties::commandPoolResetCommandBuffer")
            .SkipOnMessage("VUID-vkBeginCommandBuffer-commandPoolMultipleCommandBuffersRecording-05007",
                           "Test requires VkPhysicalDeviceVulkanSC10Properties::commandPoolMultipleCommandBuffersRecording")
            .SkipOnMessage("VUID-vkBeginCommandBuffer-commandBufferSimultaneousUse-05008",
                           "Test requires VkPhysicalDeviceVulkanSC10Properties::commandBufferSimultaneousUse")
            .SkipOnMessage("VUID-VkCommandBufferBeginInfo-flags-05010",
                           "Test requires VkPhysicalDeviceVulkanSC10Properties::secondaryCommandBufferNullOrImagelessFramebuffer");
    DispatchHelper()->BeginDispatchPolicy(policy);
    VkResult result = vksc::BeginCommandBuffer(commandBuffer, pBeginInfo);
    DispatchHelper()->EndDispatchPolicy(policy);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    static auto policy = DispatchHelper()->CreateDispatchPolicy().SkipOnMessage(
        "VUID-vkResetCommandBuffer-commandPoolResetCommandBuffer-05135",
        "Test requires VkPhysicalDeviceVulkanSC10Properties::commandPoolResetCommandBuffer");
    DispatchHelper()->BeginDispatchPolicy(policy);
    VkResult result = vksc::ResetCommandBuffer(commandBuffer, flags);
    DispatchHelper()->EndDispatchPolicy(policy);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    static auto policy =
        DispatchHelper()
            ->CreateDispatchPolicy()
            .SkipOnMessage("VUID-VkRenderPassCreateInfo-subpassCount-05050",
                           "Test requires higher limit for VkPhysicalDeviceVulkanSC10Properties::maxRenderPassSubpasses")
            .SkipOnMessage("VUID-VkRenderPassCreateInfo-dependencyCount-05051",
                           "Test requires higher limit for VkPhysicalDeviceVulkanSC10Properties::maxRenderPassDependencies")
            .SkipOnMessage("VUID-VkRenderPassCreateInfo-attachmentCount-05052",
                           "Test requires higher limit for VkPhysicalDeviceVulkanSC10Properties::maxFramebufferAttachments")
            .SkipOnMessage("VUID-VkSubpassDescription-inputAttachmentCount-05053",
                           "Test requires higher limit for VkPhysicalDeviceVulkanSC10Properties::maxSubpassInputAttachments")
            .SkipOnMessage("VUID-VkSubpassDescription-preserveAttachmentCount-05054",
                           "Test requires higher limit for VkPhysicalDeviceVulkanSC10Properties::maxSubpassPreserveAttachments")
            .SkipOnMessage("VUID-VkRenderPassMultiviewCreateInfo-pViewMasks-06697",
                           "Test requires multiview support which is not required in Vulkan SC.",
                           !Features<VkPhysicalDeviceVulkan11Features>().multiview)
            .SkipOnMessage("VUID-VkSubpassDescription2-viewMask-06706",
                           "Test requires multiview support which is not required in Vulkan SC..",
                           !Features<VkPhysicalDeviceVulkan11Features>().multiview)
            .SkipOnMessage("VUID-VkSubpassDescription2-multiview-06558",
                           "Test requires multiview support which is not required in Vulkan SC..",
                           !Features<VkPhysicalDeviceVulkan11Features>().multiview)
            .SkipOnMessage("VUID-VkRenderPassMultiviewCreateInfo-multiview-06555",
                           "Test requires multiview support which is not required in Vulkan SC..",
                           !Features<VkPhysicalDeviceVulkan11Features>().multiview)
            .SkipOnMessage("VUID-VkSubpassDescriptionDepthStencilResolve-depthResolveMode-03183",
                           "Test requires depth/stencil resolve modes which are not required in Vulkan SC.",
                           Props<VkPhysicalDeviceVulkan12Properties>().supportedDepthResolveModes == 0)
            .SkipOnMessage("VUID-VkSubpassDescriptionDepthStencilResolve-stencilResolveMode-03184",
                           "Test requires stencil resolve modes which are not required in Vulkan SC.",
                           Props<VkPhysicalDeviceVulkan12Properties>().supportedStencilResolveModes == 0);
    DispatchHelper()->BeginDispatchPolicy(policy);
    VkResult result = vksc::CreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    DispatchHelper()->EndDispatchPolicy(policy);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    static auto policy =
        DispatchHelper()
            ->CreateDispatchPolicy()
            .SkipOnMessage("VUID-VkRenderPassCreateInfo2-subpassCount-05055",
                           "Test requires higher limit for VkPhysicalDeviceVulkanSC10Properties::maxRenderPassSubpasses")
            .SkipOnMessage("VUID-VkRenderPassCreateInfo2-dependencyCount-05056",
                           "Test requires higher limit for VkPhysicalDeviceVulkanSC10Properties::maxRenderPassDependencies")
            .SkipOnMessage("VUID-VkRenderPassCreateInfo2-attachmentCount-05057",
                           "Test requires higher limit for VkPhysicalDeviceVulkanSC10Properties::maxFramebufferAttachments")
            .SkipOnMessage("VUID-VkSubpassDescription2-inputAttachmentCount-05058",
                           "Test requires higher limit for VkPhysicalDeviceVulkanSC10Properties::maxSubpassInputAttachments")
            .SkipOnMessage("VUID-VkSubpassDescription2-preserveAttachmentCount-05059",
                           "Test requires higher limit for VkPhysicalDeviceVulkanSC10Properties::maxSubpassPreserveAttachments")
            .SkipOnMessage("VUID-VkRenderPassMultiviewCreateInfo-pViewMasks-06697",
                           "Test requires multiview support which is not required in Vulkan SC.",
                           !Features<VkPhysicalDeviceVulkan11Features>().multiview)
            .SkipOnMessage("VUID-VkSubpassDescription2-viewMask-06706",
                           "Test requires multiview support which is not required in Vulkan SC..",
                           !Features<VkPhysicalDeviceVulkan11Features>().multiview)
            .SkipOnMessage("VUID-VkSubpassDescription2-multiview-06558",
                           "Test requires multiview support which is not required in Vulkan SC..",
                           !Features<VkPhysicalDeviceVulkan11Features>().multiview)
            .SkipOnMessage("VUID-VkRenderPassMultiviewCreateInfo-multiview-06555",
                           "Test requires multiview support which is not required in Vulkan SC..",
                           !Features<VkPhysicalDeviceVulkan11Features>().multiview)
            .SkipOnMessage("VUID-VkSubpassDescriptionDepthStencilResolve-depthResolveMode-03183",
                           "Test requires depth/stencil resolve modes which are not required in Vulkan SC.",
                           Props<VkPhysicalDeviceVulkan12Properties>().supportedDepthResolveModes == 0)
            .SkipOnMessage("VUID-VkSubpassDescriptionDepthStencilResolve-stencilResolveMode-03184",
                           "Test requires stencil resolve modes which are not required in Vulkan SC.",
                           Props<VkPhysicalDeviceVulkan12Properties>().supportedStencilResolveModes == 0);
    DispatchHelper()->BeginDispatchPolicy(policy);
    VkResult result = vksc::CreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    DispatchHelper()->EndDispatchPolicy(policy);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) {
    // Vulkan SC allows maxFramebufferLayers = 1 in certain cases while Vulkan requires 256
    // so we have to skip test cases that rely on higher capabilities
    const uint32_t max_framebuffer_layers =
        DispatchHelper()->TestCase()->DeviceObj()->phy().properties_.limits.maxFramebufferLayers;
    if (max_framebuffer_layers < 256 && pCreateInfo->layers > max_framebuffer_layers) {
        DispatchHelper()->SkipUnsupportedTest(
            "Test case relies on Vulkan minimum for maxFramebufferLayers but Vulkan SC allows for lower values");
    }
    return vksc::CreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
}

static VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) {
    static auto policy = DispatchHelper()->CreateDispatchPolicy().SkipOnMessage(
        "VUID-VkSemaphoreTypeCreateInfo-timelineSemaphore-03252",
        "Test requires timelineSemaphore support which is not required in Vulkan SC.",
        !Features<VkPhysicalDeviceVulkan12Features>().timelineSemaphore);
    DispatchHelper()->BeginDispatchPolicy(policy);
    VkResult result = vksc::CreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    DispatchHelper()->EndDispatchPolicy(policy);
    return result;
}

}  // namespace compatibility

}  // namespace vk

namespace vksc {

PFN_vkGetInstanceProcAddr GetInstanceProcAddr = nullptr;
PFN_vkGetDeviceProcAddr GetDeviceProcAddr = nullptr;
PFN_vkCreateInstance CreateInstance = nullptr;
PFN_vkDestroyInstance DestroyInstance = nullptr;
PFN_vkCreateDevice CreateDevice = nullptr;
PFN_vkCreatePipelineCache CreatePipelineCache = nullptr;
PFN_vkCreateComputePipelines CreateComputePipelines = nullptr;
PFN_vkCreateGraphicsPipelines CreateGraphicsPipelines = nullptr;
PFN_vkCreateCommandPool CreateCommandPool = nullptr;
PFN_vkBeginCommandBuffer BeginCommandBuffer = nullptr;
PFN_vkResetCommandBuffer ResetCommandBuffer = nullptr;
PFN_vkCreateRenderPass CreateRenderPass = nullptr;
PFN_vkCreateRenderPass2 CreateRenderPass2 = nullptr;
PFN_vkCreateFramebuffer CreateFramebuffer = nullptr;
PFN_vkCreateSemaphore CreateSemaphore = nullptr;

void TestDispatchHelper::PatchDispatchTable() {
    // Add compatibility implementations for entry points that are not supported in Vulkan SC

#define VK_ONLY__SWAP_COMPAT_EP(name) vk::name = vk::compatibility::name

    VK_ONLY__SWAP_COMPAT_EP(FreeMemory);
    VK_ONLY__SWAP_COMPAT_EP(DestroyQueryPool);
    VK_ONLY__SWAP_COMPAT_EP(DestroyDescriptorPool);
    VK_ONLY__SWAP_COMPAT_EP(DestroyCommandPool);
    VK_ONLY__SWAP_COMPAT_EP(DestroySwapchainKHR);
    VK_ONLY__SWAP_COMPAT_EP(CreateShaderModule);
    VK_ONLY__SWAP_COMPAT_EP(DestroyShaderModule);

    // Replace certain entry points with compatibility implementations to be able to run
    // Vulkan validation test cases against Vulkan SC

#define VKSC__SWAP_COMPAT_EP(name) \
    vksc::name = vk::name;         \
    vk::name = vk::compatibility::name;

    VKSC__SWAP_COMPAT_EP(GetInstanceProcAddr);
    VKSC__SWAP_COMPAT_EP(GetDeviceProcAddr);
    VKSC__SWAP_COMPAT_EP(CreateInstance);
    VKSC__SWAP_COMPAT_EP(DestroyInstance);
    VKSC__SWAP_COMPAT_EP(CreateDevice);
    VKSC__SWAP_COMPAT_EP(CreatePipelineCache);
    VKSC__SWAP_COMPAT_EP(CreateComputePipelines);
    VKSC__SWAP_COMPAT_EP(CreateGraphicsPipelines);
    VKSC__SWAP_COMPAT_EP(CreateCommandPool);
    VKSC__SWAP_COMPAT_EP(BeginCommandBuffer);
    VKSC__SWAP_COMPAT_EP(ResetCommandBuffer);
    VKSC__SWAP_COMPAT_EP(CreateRenderPass);
    VKSC__SWAP_COMPAT_EP(CreateRenderPass2);
    VKSC__SWAP_COMPAT_EP(CreateFramebuffer);
    VKSC__SWAP_COMPAT_EP(CreateSemaphore);

    InitDefaultPipelineCacheData();
    InitDefaultObjectReservationInfo();
}

TestDispatchHelper::TestDispatchHelper(VkSCCompatibilityRenderFramework* test_case) : test_case_(test_case) {}

TestDispatchHelper::~TestDispatchHelper() {
    // Destroy all debug messengers
    for (const auto& it : messengers_) {
        auto pfn_destroy_messenger = reinterpret_cast<PFN_vkDestroyDebugUtilsMessengerEXT>(
            vksc::GetInstanceProcAddr(it.first, "vkDestroyDebugUtilsMessengerEXT"));

        pfn_destroy_messenger(it.first, it.second, nullptr);
    }
    messengers_.clear();
}

void TestDispatchHelper::RegisterInstance(VkInstance instance) {
    // Create debug messenger for the instance (needed by some of the compatibility utilities)
    VkDebugUtilsMessengerEXT messenger = VK_NULL_HANDLE;

    auto create_info = vku::InitStruct<VkDebugUtilsMessengerCreateInfoEXT>();
    create_info.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                                  VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT;
    create_info.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    create_info.pfnUserCallback = DebugCallback;
    create_info.pUserData = this;

    auto pfn_create_messenger =
        reinterpret_cast<PFN_vkCreateDebugUtilsMessengerEXT>(vksc::GetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT"));
    if (pfn_create_messenger && pfn_create_messenger(instance, &create_info, nullptr, &messenger) == VK_SUCCESS) {
        messengers_.insert({instance, messenger});
    } else {
        // If we failed to register the debug messenger then consider the config invalid
        messengers_valid_ = false;
    }
}

void TestDispatchHelper::UnregisterInstance(VkInstance instance) {
    // Destroy debug messenger for the instance if it was created
    auto it = messengers_.find(instance);
    if (it != messengers_.end()) {
        auto pfn_destroy_messenger = reinterpret_cast<PFN_vkDestroyDebugUtilsMessengerEXT>(
            vksc::GetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT"));
        pfn_destroy_messenger(instance, it->second, nullptr);
        messengers_.erase(instance);
    } else {
        // If we failed to unregister the debug messenger then consider the config invalid
        messengers_valid_ = false;
    }
}

void TestDispatchHelper::BeginDispatchPolicy(DispatchPolicy& policy) {
    assert(tls_dispatch_policy_ == nullptr);
    tls_skip_message_ = nullptr;
    tls_dispatch_policy_ = &policy;
}

void TestDispatchHelper::EndDispatchPolicy(DispatchPolicy& policy) {
    assert(MessengersValid());

    assert(tls_dispatch_policy_ == &policy);
    tls_dispatch_policy_ = nullptr;

    if (tls_skip_message_ != nullptr) {
        SkipUnsupportedTest(tls_skip_message_);
    }
}

VKAPI_ATTR VkBool32 VKAPI_CALL TestDispatchHelper::DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT message_severity,
                                                                 VkDebugUtilsMessageTypeFlagsEXT message_types,
                                                                 const VkDebugUtilsMessengerCallbackDataEXT* callback_data,
                                                                 void* user_data) {
    auto self = reinterpret_cast<TestDispatchHelper*>(user_data);
    if (tls_dispatch_policy_ != nullptr) {
        // Check VUIDs that, if triggered, should cause the test case to be skipped
        for (const auto& skip_on_vuid : tls_dispatch_policy_->skip_on_vuids_) {
            if (strstr(callback_data->pMessage, skip_on_vuid.first)) {
                // Prevent the VUID from causing a test failure
                self->test_case_->Monitor().SetAllowedFailureMsg(skip_on_vuid.first);
                // Set the skip message to the first one received
                if (tls_skip_message_ == nullptr) {
                    tls_skip_message_ = skip_on_vuid.second;
                }
                return VK_FALSE;
            }
        }
    }
    return VK_FALSE;
}

void TestDispatchHelper::SkipUnsupportedTest(const char* message) {
    // Reset message monitor to avoid unfilled expectations due to the test skipping
    test_case_->Monitor().Reset();
    // We also allow any failure message from here to handle cascading effects
    test_case_->Monitor().SetAllowedFailureMsg("");

    GTEST_MESSAGE_AT_(__FILE__, __LINE__, "", ::testing::TestPartResult::kSkip) << message;
    throw testing::AssertionException(testing::TestPartResult(testing::TestPartResult::kSkip, __FILE__, __LINE__, ""));
}

}  // namespace vksc
