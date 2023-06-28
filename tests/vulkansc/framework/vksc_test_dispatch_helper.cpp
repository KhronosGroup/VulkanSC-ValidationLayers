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
#include "vk_typemap_helper.h"

#include <assert.h>

namespace vksc {

static VkDeviceObjectReservationCreateInfo default_object_reservation_info{};
static VkDevicePrivateDataCreateInfoEXT default_private_data_reservation_info{};
static VkPerformanceQueryReservationInfoKHR default_perf_query_reservation_info{};

static void InitDefaultObjectReservationInfo() {
    // Initialize default object reservation info
    default_object_reservation_info = LvlInitStruct<VkDeviceObjectReservationCreateInfo>();

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
    default_object_reservation_info.subpassDescriptionRequestCount = 256;
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

    // Private data reservation info
    default_private_data_reservation_info = LvlInitStruct<VkDevicePrivateDataCreateInfoEXT>();
    default_private_data_reservation_info.privateDataSlotRequestCount = 16;
    default_private_data_reservation_info.pNext = default_object_reservation_info.pNext;
    default_object_reservation_info.pNext = &default_private_data_reservation_info;

    // Performance query reservation info
    default_perf_query_reservation_info = LvlInitStruct<VkPerformanceQueryReservationInfoKHR>();
    default_perf_query_reservation_info.maxPerformanceQueriesPerPool = 8;
    default_perf_query_reservation_info.pNext = default_object_reservation_info.pNext;
    default_object_reservation_info.pNext = &default_perf_query_reservation_info;
}

const VkDeviceObjectReservationCreateInfo& GetDefaultObjectReservationCreateInfo() { return default_object_reservation_info; }

}  // namespace vksc

namespace vk {

namespace compatibility {

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

static VKAPI_ATTR VkResult VKAPI_CALL CreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) {
    // When running Vulkan validation layer tests against the Vulkan SC validation layers
    // we need to manually inject the default Vulkan SC 1.0 features and object reservation info
    // structures to the pNext chain of pCreateInfo.
    VkDeviceCreateInfo create_info = *pCreateInfo;

    VkDeviceObjectReservationCreateInfo object_reservation_info;
    if (!LvlFindInChain<VkDeviceObjectReservationCreateInfo>(create_info.pNext)) {
        object_reservation_info = vksc::default_object_reservation_info;
        object_reservation_info.pNext = create_info.pNext;
        create_info.pNext = &object_reservation_info;
    }

    VkPhysicalDeviceVulkanSC10Features sc_10_features;
    if (!LvlFindInChain<VkPhysicalDeviceVulkanSC10Features>(create_info.pNext)) {
        sc_10_features = LvlInitStruct<VkPhysicalDeviceVulkanSC10Features>();
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
    // When running Vulkan validation layer tests against the Vulkan SC validation layers
    // we need to manually inject the default offline pipeline creation info, if not present.
    bool need_to_chain_offline_info = false;
    for (uint32_t i = 0; i < create_info_count; ++i) {
        if (!LvlFindInChain<VkPipelineOfflineCreateInfo>(create_infos[i].pNext)) {
            need_to_chain_offline_info = true;
        }
    }
    if (need_to_chain_offline_info) {
        if (create_info_count == 1) {
            auto offline_info = vksc::GetDefaultPipelineOfflineCreateInfo();
            auto create_info = create_infos[0];
            offline_info.pNext = create_info.pNext;
            create_info.pNext = &offline_info;
            return create_func(device, pipeline_cache, 1, &create_info, nullptr, pipelines);
        } else {
            std::vector<VkPipelineOfflineCreateInfo> offline_info(create_info_count, vksc::GetDefaultPipelineOfflineCreateInfo());
            std::vector<CREATE_INFO> create_info_vec(create_info_count);
            for (uint32_t i = 0; i < create_info_count; ++i) {
                create_info_vec[i] = create_infos[i];
                offline_info[i].pNext = create_info_vec[i].pNext;
                create_info_vec[i].pNext = &offline_info[i];
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

    auto mem_reservation_info = LvlInitStruct<VkCommandPoolMemoryReservationCreateInfo>();
    if (!LvlFindInChain<VkCommandPoolMemoryReservationCreateInfo>(create_info.pNext)) {
        mem_reservation_info.commandPoolReservedSize = 1024 * 1024;
        mem_reservation_info.commandPoolMaxCommandBuffers = 64;
        mem_reservation_info.pNext = create_info.pNext;
        create_info.pNext = &mem_reservation_info;
    }

    return vksc::CreateCommandPool(device, &create_info, pAllocator, pCommandPool);
}

#undef VKSC_TEST

}  // namespace compatibility

// Destroy and free commands removed in Vulkan SC are permanently attached to placeholder
// implementations to enable running Vulkan validation layer tests against the Vulkan SC
// validation layers.
PFN_vkFreeMemory FreeMemory = compatibility::FreeMemory;
PFN_vkDestroyQueryPool DestroyQueryPool = compatibility::DestroyQueryPool;
PFN_vkDestroyDescriptorPool DestroyDescriptorPool = compatibility::DestroyDescriptorPool;
PFN_vkDestroyCommandPool DestroyCommandPool = compatibility::DestroyCommandPool;
PFN_vkDestroySwapchainKHR DestroySwapchainKHR = compatibility::DestroySwapchainKHR;
PFN_vkCreateShaderModule CreateShaderModule = compatibility::CreateShaderModule;
PFN_vkDestroyShaderModule DestroyShaderModule = compatibility::DestroyShaderModule;

// Other removed functions are unavailable by default.
PFN_vkGetImageSparseMemoryRequirements GetImageSparseMemoryRequirements = nullptr;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties GetPhysicalDeviceSparseImageFormatProperties = nullptr;
PFN_vkQueueBindSparse QueueBindSparse = nullptr;
PFN_vkGetPipelineCacheData GetPipelineCacheData = nullptr;
PFN_vkMergePipelineCaches MergePipelineCaches = nullptr;
PFN_vkGetImageSparseMemoryRequirements2 GetImageSparseMemoryRequirements2 = nullptr;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 GetPhysicalDeviceSparseImageFormatProperties2 = nullptr;
PFN_vkTrimCommandPool TrimCommandPool = nullptr;
PFN_vkCreateDescriptorUpdateTemplate CreateDescriptorUpdateTemplate = nullptr;
PFN_vkDestroyDescriptorUpdateTemplate DestroyDescriptorUpdateTemplate = nullptr;
PFN_vkUpdateDescriptorSetWithTemplate UpdateDescriptorSetWithTemplate = nullptr;
#ifdef VK_USE_PLATFORM_XLIB_KHR
PFN_vkCreateXlibSurfaceKHR CreateXlibSurfaceKHR = nullptr;
#endif  // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR GetPhysicalDeviceXlibPresentationSupportKHR = nullptr;
#endif  // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
PFN_vkCreateXcbSurfaceKHR CreateXcbSurfaceKHR = nullptr;
#endif  // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR GetPhysicalDeviceXcbPresentationSupportKHR = nullptr;
#endif  // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
PFN_vkCreateWaylandSurfaceKHR CreateWaylandSurfaceKHR = nullptr;
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR GetPhysicalDeviceWaylandPresentationSupportKHR = nullptr;
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
PFN_vkCreateAndroidSurfaceKHR CreateAndroidSurfaceKHR = nullptr;
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
PFN_vkCreateWin32SurfaceKHR CreateWin32SurfaceKHR = nullptr;
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR GetPhysicalDeviceWin32PresentationSupportKHR = nullptr;
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_MACOS_MVK
PFN_vkCreateMacOSSurfaceMVK CreateMacOSSurfaceMVK = nullptr;
#endif  // VK_USE_PLATFORM_MACOS_MVK

}  // namespace vk

namespace vksc {

PFN_vkCreateDevice CreateDevice = nullptr;
PFN_vkCreatePipelineCache CreatePipelineCache = nullptr;
PFN_vkCreateComputePipelines CreateComputePipelines = nullptr;
PFN_vkCreateGraphicsPipelines CreateGraphicsPipelines = nullptr;
PFN_vkCreateCommandPool CreateCommandPool = nullptr;

void PatchDispatchTable() {
#define VKSC__SWAP_COMPAT_EP(name) \
    vksc::name = vk::name;         \
    vk::name = vk::compatibility::name;

    VKSC__SWAP_COMPAT_EP(CreateDevice);
    VKSC__SWAP_COMPAT_EP(CreatePipelineCache);
    VKSC__SWAP_COMPAT_EP(CreateComputePipelines);
    VKSC__SWAP_COMPAT_EP(CreateGraphicsPipelines);
    VKSC__SWAP_COMPAT_EP(CreateCommandPool);

    InitDefaultPipelineCacheData();
    InitDefaultObjectReservationInfo();
}

}  // namespace vksc
