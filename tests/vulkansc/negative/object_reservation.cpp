/*
 * Copyright (c) 2023-2024 The Khronos Group Inc.
 * Copyright (c) 2023-2024 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#include "../framework/vksc_layer_validation_tests.h"

#include <algorithm>
#include <functional>

class VkSCObjectReservationLayerTest : public VkSCLayerTest {
  public:
    using caps_func_t = std::function<bool(VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit)>;
    using setup_func_t = std::function<bool(vkt::Device& device)>;
    using create_func_t = std::function<void(vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail)>;
    using destroy_func_t = std::function<void(vkt::Device& device, uint32_t index, uint32_t destroy_count)>;
    using teardown_func_t = std::function<void(vkt::Device& device)>;

    std::vector<const char*> device_extensions{};

    void TestObjectReservationLimit(uint32_t max_create_count, bool can_destroy, bool has_parent, void* device_features,
                                    caps_func_t caps_func, setup_func_t setup_func, create_func_t create_func,
                                    destroy_func_t destroy_func, teardown_func_t teardown_func) {
        auto sc_10_features = vku::InitStruct<VkPhysicalDeviceVulkanSC10Features>(device_features);
        auto object_reservation_info = vku::InitStruct<VkDeviceObjectReservationCreateInfo>(&sc_10_features);

        const std::vector<uint32_t> tested_limits{0, 1, 7, 13, 42, 111, 499};
        for (auto tested_limit : tested_limits) {
            const uint32_t over_limit = 5;

            if (!caps_func(object_reservation_info, tested_limit)) {
                continue;
            }

            vkt::Device device(gpu(), device_extensions, nullptr, &object_reservation_info);

            if (setup_func) {
                if (!setup_func(device)) {
                    if (teardown_func) {
                        teardown_func(device);
                    }
                    continue;
                }
            }

            if (max_create_count == 0) {
                // Commands can only create a single object at a time

                // Create up to the desired limit
                for (uint32_t i = 0; i < tested_limit; ++i) {
                    create_func(device, i, 1, false);
                }

                // Expect additional creates to fail
                for (uint32_t i = 0; i < over_limit; ++i) {
                    create_func(device, tested_limit + i, 1, true);
                }

                if (can_destroy) {
                    // Destroy some objects
                    for (uint32_t i = 0; i < tested_limit; i += 5) {
                        destroy_func(device, i, 1);
                    }

                    // Expect that we can create new objects instead of the destroyed ones
                    for (uint32_t i = 0; i < tested_limit; i += 5) {
                        create_func(device, i, 1, false);
                    }

                    // Expect additional creates to fail once again
                    for (uint32_t i = 0; i < over_limit; ++i) {
                        create_func(device, tested_limit + i, 1, true);
                    }

                    if (tested_limit > 0) {
                        // Destroy the first object multiple times (later destroys will be ignored)
                        for (uint32_t i = 0; i < 5; ++i) {
                            destroy_func(device, 0, 1);
                        }

                        // Expect to be able to create an object instead of it
                        create_func(device, 0, 1, false);

                        // Expect additional attempts to fail once again
                        for (uint32_t i = 0; i < over_limit; ++i) {
                            create_func(device, tested_limit + i, 1, true);
                        }
                    }

                    // Destroy all objects
                    for (uint32_t i = 0; i < tested_limit; ++i) {
                        destroy_func(device, i, 1);
                    }
                }
            } else if (!has_parent) {
                // Commands can create multiple objects at a time, and they're not part of a parent object
                // (e.g. like pipelines)

                // Create up to the desired limit
                uint32_t already_created_count = 0;
                while (already_created_count < tested_limit) {
                    uint32_t create_count = std::min(tested_limit - already_created_count, max_create_count);
                    create_func(device, already_created_count, create_count, false);
                    already_created_count += create_count;
                }

                // Expect additional creates to fail
                for (uint32_t i = 0; i < over_limit; ++i) {
                    create_func(device, tested_limit + i, over_limit - i, true);
                }

                if (can_destroy) {
                    // Destroy some objects
                    uint32_t destroy_count = tested_limit / 4;
                    for (uint32_t i = 0; i < destroy_count; ++i) {
                        destroy_func(device, i, 1);
                        destroy_func(device, i + tested_limit / 2, 1);
                    }

                    // Expect that we can create new objects instead of the destroyed ones
                    for (uint32_t i = 0; i < destroy_count; ++i) {
                        create_func(device, i, 1, false);
                        create_func(device, i + tested_limit / 2, 1, false);
                    }

                    // Expect additional creates to fail again
                    for (uint32_t i = 0; i < over_limit; ++i) {
                        create_func(device, tested_limit + i, over_limit - i, true);
                    }

                    if (tested_limit > 0) {
                        // Destroy the first object multiple times (later destroys will be ignored)
                        for (uint32_t i = 0; i < 5; ++i) {
                            destroy_func(device, 0, 1);
                        }

                        // Expect to be able to create an object instead of it
                        create_func(device, 0, 1, false);

                        // Expect additional attempts to fail once again
                        for (uint32_t i = 0; i < over_limit; ++i) {
                            create_func(device, tested_limit + i, 1, true);
                        }
                    }

                    // Destroy all objects
                    for (uint32_t i = 0; i < tested_limit; ++i) {
                        destroy_func(device, i, 1);
                    }
                }
            } else {
                // Commands can create multiple objects at a time, and they're part of a parent object
                // (e.g. like render pass attachment descriptions)

                // Create up to the desired limit minus max_create_count - 1
                uint32_t object_count = 0;
                uint32_t left_to_create = (tested_limit >= max_create_count) ? tested_limit + 1 - max_create_count : 0;
                while (left_to_create >= max_create_count) {
                    create_func(device, object_count++, max_create_count, false);
                    left_to_create -= max_create_count;
                }

                if (left_to_create > 0) {
                    create_func(device, object_count++, left_to_create, false);
                }

                // Trying to create another max_create_count number should fail
                create_func(device, object_count, max_create_count, true);

                // Now allocate one by one and try to reserve one more than remaining
                uint32_t remaining_count = std::min(max_create_count - 1, tested_limit);
                for (uint32_t i = 0; i < remaining_count; ++i) {
                    create_func(device, object_count++, 1, false);
                    create_func(device, object_count, remaining_count - i + 1, true);
                }

                if (can_destroy) {
                    // Destroy one by one the allocations done in the previous step
                    for (uint32_t i = 0; i < remaining_count; ++i) {
                        destroy_func(device, --object_count, 0);
                    }

                    if (tested_limit > 0) {
                        if (max_create_count > 1) {
                            // Expect to be able to create a single object instead of it with max_create_count - 1
                            create_func(device, object_count++, std::min(max_create_count - 1, tested_limit), false);
                        }

                        // After that any attempts to create should fail
                        create_func(device, object_count, 1, true);

                        // Destroy the first object multiple times (later destroys will be ignored)
                        for (uint32_t i = 0; i < 5; ++i) {
                            destroy_func(device, 0, 0);
                        }

                        // Expect to be able to create an object instead of it
                        create_func(device, 0, std::min(max_create_count, tested_limit), false);

                        // Expect additional attempts to fail once again
                        for (uint32_t i = 0; i < over_limit; ++i) {
                            create_func(device, tested_limit + i, 1, true);
                        }
                    }

                    // Destroy all objects
                    for (uint32_t i = 0; i < object_count; ++i) {
                        destroy_func(device, i, 0);
                    }
                }
            }

            if (teardown_func) {
                teardown_func(device);
            }
        }
    }
};

TEST_F(VkSCObjectReservationLayerTest, CommandPoolRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::commandPoolRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkCommandPool> cmd_pools{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = false;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.commandPoolRequestCount = tested_limit;
            object_reservation_info.commandBufferRequestCount = tested_limit + 1;

            data.cmd_pools.clear();
            data.cmd_pools.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkCommandPool cmd_pool = VK_NULL_HANDLE;

            auto mem_reservation_info = vku::InitStruct<VkCommandPoolMemoryReservationCreateInfo>();
            mem_reservation_info.commandPoolReservedSize = 64 * 1024;
            mem_reservation_info.commandPoolMaxCommandBuffers = 1;

            auto create_info = vku::InitStruct<VkCommandPoolCreateInfo>(&mem_reservation_info);

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateCommandPool-device-05068");
                vksc::CreateCommandPool(device.handle(), &create_info, nullptr, &cmd_pool);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.cmd_pools.size());
                vksc::CreateCommandPool(device.handle(), &create_info, nullptr, &data.cmd_pools[index]);
            }
        },
        // Destroy objects
        nullptr,
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, CommandBufferRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::commandBufferRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkCommandPool> cmd_pools{};
    } data;

    const uint32_t max_create_count = std::min(GetVulkanSC10Properties(gpu()).maxCommandPoolCommandBuffers, 16u);
    const bool can_destroy = false;
    const bool has_parent = true;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.commandPoolRequestCount = tested_limit + 1;
            object_reservation_info.commandBufferRequestCount = tested_limit;

            data.cmd_pools.clear();
            data.cmd_pools.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkCommandPool cmd_pool = VK_NULL_HANDLE;

            auto mem_reservation_info = vku::InitStruct<VkCommandPoolMemoryReservationCreateInfo>();
            mem_reservation_info.commandPoolReservedSize = 1024 * 1024;
            mem_reservation_info.commandPoolMaxCommandBuffers = create_count;

            auto create_info = vku::InitStruct<VkCommandPoolCreateInfo>(&mem_reservation_info);

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(
                    kErrorBit, "VUID-VkCommandPoolMemoryReservationCreateInfo-commandPoolMaxCommandBuffers-05074");
                vksc::CreateCommandPool(device.handle(), &create_info, nullptr, &cmd_pool);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.cmd_pools.size());
                vksc::CreateCommandPool(device.handle(), &create_info, nullptr, &data.cmd_pools[index]);
            }
        },
        // Destroy objects
        nullptr,
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, DescriptorSetLayoutRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::descriptorSetLayoutRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkDescriptorSetLayout> descriptor_set_layouts{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.descriptorSetLayoutRequestCount = tested_limit;
            object_reservation_info.descriptorSetLayoutBindingRequestCount = tested_limit + 1;
            object_reservation_info.descriptorSetLayoutBindingLimit = 1;

            data.descriptor_set_layouts.clear();
            data.descriptor_set_layouts.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkDescriptorSetLayout descriptor_set_layout = VK_NULL_HANDLE;

            VkDescriptorSetLayoutBinding binding{};
            binding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
            binding.descriptorCount = 1;
            binding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;

            auto create_info = vku::InitStruct<VkDescriptorSetLayoutCreateInfo>();
            create_info.bindingCount = 1;
            create_info.pBindings = &binding;

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateDescriptorSetLayout-device-05068");
                vksc::CreateDescriptorSetLayout(device.handle(), &create_info, nullptr, &descriptor_set_layout);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.descriptor_set_layouts.size());
                vksc::CreateDescriptorSetLayout(device.handle(), &create_info, nullptr, &data.descriptor_set_layouts[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.descriptor_set_layouts.size());
            assert(destroy_count == 1);

            vksc::DestroyDescriptorSetLayout(device.handle(), data.descriptor_set_layouts[index], nullptr);
            data.descriptor_set_layouts[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, DescriptorSetLayoutBindingRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::descriptorSetLayoutBindingRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkDescriptorSetLayout> descriptor_set_layouts{};
    } data;

    const uint32_t max_create_count = 4;
    const bool can_destroy = true;
    const bool has_parent = true;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.descriptorSetLayoutRequestCount = tested_limit + 1;
            object_reservation_info.descriptorSetLayoutBindingRequestCount = tested_limit;
            object_reservation_info.descriptorSetLayoutBindingLimit = 4;

            data.descriptor_set_layouts.clear();
            data.descriptor_set_layouts.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkDescriptorSetLayout descriptor_set_layout = VK_NULL_HANDLE;

            uint32_t binding_count = 0;
            std::vector<VkDescriptorSetLayoutBinding> bindings(create_count, VkDescriptorSetLayoutBinding{});
            for (auto& binding : bindings) {
                binding.binding = binding_count++;
                binding.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
                binding.descriptorCount = 2;
                binding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
            }

            auto create_info = vku::InitStruct<VkDescriptorSetLayoutCreateInfo>();
            create_info.bindingCount = binding_count;
            create_info.pBindings = bindings.data();

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateDescriptorSetLayout-layoutbindings-device-05089");
                vksc::CreateDescriptorSetLayout(device.handle(), &create_info, nullptr, &descriptor_set_layout);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.descriptor_set_layouts.size());
                vksc::CreateDescriptorSetLayout(device.handle(), &create_info, nullptr, &data.descriptor_set_layouts[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.descriptor_set_layouts.size());
            assert(destroy_count == 0);

            vksc::DestroyDescriptorSetLayout(device.handle(), data.descriptor_set_layouts[index], nullptr);
            data.descriptor_set_layouts[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, PipelineLayoutRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::pipelineLayoutRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        VkDescriptorSetLayout descriptor_set_layout{VK_NULL_HANDLE};
        std::vector<VkPipelineLayout> pipeline_layouts{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.pipelineLayoutRequestCount = tested_limit;
            object_reservation_info.descriptorSetLayoutRequestCount = 1;
            object_reservation_info.descriptorSetLayoutBindingRequestCount = 1;
            object_reservation_info.descriptorSetLayoutBindingLimit = 1;

            data.pipeline_layouts.clear();
            data.pipeline_layouts.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        [&](vkt::Device& device) {
            VkResult result = VK_SUCCESS;

            VkDescriptorSetLayoutBinding binding{};
            binding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
            binding.descriptorCount = 1;
            binding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;

            auto create_info = vku::InitStruct<VkDescriptorSetLayoutCreateInfo>();
            create_info.bindingCount = 1;
            create_info.pBindings = &binding;

            result = vksc::CreateDescriptorSetLayout(device.handle(), &create_info, nullptr, &data.descriptor_set_layout);
            if (result != VK_SUCCESS) return false;

            return true;
        },
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkPipelineLayout pipeline_layout = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkPipelineLayoutCreateInfo>();
            create_info.setLayoutCount = 1;
            create_info.pSetLayouts = &data.descriptor_set_layout;

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreatePipelineLayout-device-05068");
                vksc::CreatePipelineLayout(device.handle(), &create_info, nullptr, &pipeline_layout);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.pipeline_layouts.size());
                vksc::CreatePipelineLayout(device.handle(), &create_info, nullptr, &data.pipeline_layouts[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.pipeline_layouts.size());
            assert(destroy_count == 1);

            vksc::DestroyPipelineLayout(device.handle(), data.pipeline_layouts[index], nullptr);
            data.pipeline_layouts[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        [&](vkt::Device& device) { vksc::DestroyDescriptorSetLayout(device.handle(), data.descriptor_set_layout, nullptr); });
}

TEST_F(VkSCObjectReservationLayerTest, DescriptorPoolRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::descriptorPoolRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkDescriptorPool> descriptor_pools{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = false;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.descriptorPoolRequestCount = tested_limit;
            object_reservation_info.descriptorSetRequestCount = tested_limit + 1;

            data.descriptor_pools.clear();
            data.descriptor_pools.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkDescriptorPool descriptor_pool = VK_NULL_HANDLE;

            VkDescriptorPoolSize pool_size{};
            pool_size.type = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
            pool_size.descriptorCount = 4;

            auto create_info = vku::InitStruct<VkDescriptorPoolCreateInfo>();
            create_info.maxSets = 1;
            create_info.poolSizeCount = 1;
            create_info.pPoolSizes = &pool_size;

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateDescriptorPool-device-05068");
                vksc::CreateDescriptorPool(device.handle(), &create_info, nullptr, &descriptor_pool);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.descriptor_pools.size());
                vksc::CreateDescriptorPool(device.handle(), &create_info, nullptr, &data.descriptor_pools[index]);
            }
        },
        // Destroy objects
        nullptr,
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, DescriptorSetRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::descriptorSetRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        const uint32_t max_descriptor_sets_per_pool = 16;
        VkDescriptorSetLayout descriptor_set_layout{};
        VkDescriptorPool descriptor_pool_to_use_on_fail{};
        std::vector<VkDescriptorPool> descriptor_pools{};
    } data;

    const uint32_t max_create_count = data.max_descriptor_sets_per_pool;
    const bool can_destroy = true;
    const bool has_parent = true;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.descriptorPoolRequestCount = tested_limit + 1;
            object_reservation_info.descriptorSetRequestCount = tested_limit;
            object_reservation_info.descriptorSetLayoutRequestCount = 1;
            object_reservation_info.descriptorSetLayoutBindingRequestCount = 1;
            object_reservation_info.descriptorSetLayoutBindingLimit = 1;

            data.descriptor_set_layout = VK_NULL_HANDLE;
            data.descriptor_pool_to_use_on_fail = VK_NULL_HANDLE;
            data.descriptor_pools.clear();
            data.descriptor_pools.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        [&](vkt::Device& device) {
            VkResult result = VK_SUCCESS;

            VkDescriptorSetLayoutBinding binding{};
            binding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
            binding.descriptorCount = 2;
            binding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;

            auto create_info = vku::InitStruct<VkDescriptorSetLayoutCreateInfo>();
            create_info.bindingCount = 1;
            create_info.pBindings = &binding;

            result = vksc::CreateDescriptorSetLayout(device.handle(), &create_info, nullptr, &data.descriptor_set_layout);
            if (result != VK_SUCCESS) return false;

            return true;
        },
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            std::vector<VkDescriptorSet> descriptor_sets(create_count, VK_NULL_HANDLE);
            std::vector<VkDescriptorSetLayout> set_layouts(create_count, data.descriptor_set_layout);

            auto alloc_info = vku::InitStruct<VkDescriptorSetAllocateInfo>();
            alloc_info.descriptorSetCount = create_count;
            alloc_info.pSetLayouts = set_layouts.data();

            // Create descriptor pool first if needed
            {
                VkDescriptorPoolSize pool_size{};
                pool_size.type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
                pool_size.descriptorCount = 50;

                auto create_info = vku::InitStruct<VkDescriptorPoolCreateInfo>();
                create_info.maxSets = data.max_descriptor_sets_per_pool;
                create_info.poolSizeCount = 1;
                create_info.pPoolSizes = &pool_size;

                if (should_fail) {
                    if (data.descriptor_pool_to_use_on_fail == VK_NULL_HANDLE) {
                        vksc::CreateDescriptorPool(device.handle(), &create_info, nullptr, &data.descriptor_pool_to_use_on_fail);
                    } else {
                        vksc::ResetDescriptorPool(device.handle(), data.descriptor_pool_to_use_on_fail, 0);
                    }
                    alloc_info.descriptorPool = data.descriptor_pool_to_use_on_fail;
                } else {
                    assert(index < data.descriptor_pools.size());
                    if (data.descriptor_pools[index] == VK_NULL_HANDLE) {
                        vksc::CreateDescriptorPool(device.handle(), &create_info, nullptr, &data.descriptor_pools[index]);
                    }
                    alloc_info.descriptorPool = data.descriptor_pools[index];
                }
            }

            if (alloc_info.descriptorPool != VK_NULL_HANDLE) {
                if (should_fail) {
                    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkAllocateDescriptorSets-device-05068");
                    vksc::AllocateDescriptorSets(device.handle(), &alloc_info, descriptor_sets.data());
                    m_errorMonitor->VerifyFound();
                } else {
                    vksc::AllocateDescriptorSets(device.handle(), &alloc_info, descriptor_sets.data());
                }
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.descriptor_pools.size());

            if (data.descriptor_pools[index] != VK_NULL_HANDLE) {
                vksc::ResetDescriptorPool(device.handle(), data.descriptor_pools[index], 0);
            }
        },
        // Teardown common device objects
        [&](vkt::Device& device) { vksc::DestroyDescriptorSetLayout(device.handle(), data.descriptor_set_layout, nullptr); });
}

TEST_F(VkSCObjectReservationLayerTest, DeviceMemoryRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::deviceMemoryRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkDeviceMemory> device_memories{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = false;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.deviceMemoryRequestCount = tested_limit;

            data.device_memories.clear();
            data.device_memories.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkDeviceMemory device_memory = VK_NULL_HANDLE;

            auto alloc_info = vku::InitStruct<VkMemoryAllocateInfo>();
            alloc_info.allocationSize = 1024;
            alloc_info.memoryTypeIndex = 0;

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkAllocateMemory-device-05068");
                vksc::AllocateMemory(device.handle(), &alloc_info, nullptr, &device_memory);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.device_memories.size());
                vksc::AllocateMemory(device.handle(), &alloc_info, nullptr, &data.device_memories[index]);
            }
        },
        // Destroy objects
        nullptr,
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, PipelineCacheRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::pipelineCacheRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkPipelineCache> pipeline_caches{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.pipelineCacheCreateInfoCount = 1;
            object_reservation_info.pPipelineCacheCreateInfos = &vksc::GetDefaultPipelineCacheCreateInfo();

            object_reservation_info.pipelineCacheRequestCount = tested_limit;

            data.pipeline_caches.clear();
            data.pipeline_caches.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkPipelineCache pipeline_cache = VK_NULL_HANDLE;

            auto create_info = vksc::GetDefaultPipelineCacheCreateInfo();

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreatePipelineCache-device-05068");
                vksc::CreatePipelineCache(device.handle(), &create_info, nullptr, &pipeline_cache);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.pipeline_caches.size());
                vksc::CreatePipelineCache(device.handle(), &create_info, nullptr, &data.pipeline_caches[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.pipeline_caches.size());
            assert(destroy_count == 1);

            vksc::DestroyPipelineCache(device.handle(), data.pipeline_caches[index], nullptr);
            data.pipeline_caches[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, ComputePipelineRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::computePipelineRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        VkPipelinePoolSize pipeline_pool_size{};
        VkPipelineLayout pipeline_layout{VK_NULL_HANDLE};
        VkPipelineCache pipeline_cache{VK_NULL_HANDLE};
        std::vector<VkPipeline> pipelines{};
    } data;

    const uint32_t max_create_count = 16;
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.pipelineCacheCreateInfoCount = 1;
            object_reservation_info.pPipelineCacheCreateInfos = &vksc::GetDefaultPipelineCacheCreateInfo();

            data.pipeline_pool_size = vksc::GetDefaultPipelinePoolSize();
            data.pipeline_pool_size.poolEntryCount = 100 + tested_limit * 3;

            object_reservation_info.pipelinePoolSizeCount = 1;
            object_reservation_info.pPipelinePoolSizes = &data.pipeline_pool_size;

            object_reservation_info.pipelineCacheRequestCount = 1;
            object_reservation_info.pipelineLayoutRequestCount = 1;
            object_reservation_info.computePipelineRequestCount = tested_limit;

            data.pipeline_layout = VK_NULL_HANDLE;
            data.pipeline_cache = VK_NULL_HANDLE;
            data.pipelines.clear();
            data.pipelines.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        [&](vkt::Device& device) {
            VkResult result = VK_SUCCESS;

            {
                auto create_info = vksc::GetDefaultPipelineCacheCreateInfo();
                result = vksc::CreatePipelineCache(device.handle(), &create_info, nullptr, &data.pipeline_cache);
                if (result != VK_SUCCESS) return false;
            }

            {
                auto create_info = vku::InitStruct<VkPipelineLayoutCreateInfo>();
                result = vksc::CreatePipelineLayout(device.handle(), &create_info, nullptr, &data.pipeline_layout);
                if (result != VK_SUCCESS) return false;
            }

            return true;
        },
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            std::vector<VkPipeline> pipelines(create_count, VK_NULL_HANDLE);

            auto offline_info = vksc::GetDefaultPipelineOfflineCreateInfo();
            std::vector<VkComputePipelineCreateInfo> create_info(create_count,
                                                                 vku::InitStruct<VkComputePipelineCreateInfo>(&offline_info));
            for (uint32_t i = 0; i < create_count; ++i) {
                create_info[i].stage = vku::InitStruct<VkPipelineShaderStageCreateInfo>();
                create_info[i].stage.stage = VK_SHADER_STAGE_COMPUTE_BIT;
                create_info[i].stage.pName = "main";
                create_info[i].layout = data.pipeline_layout;
            }

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateComputePipelines-device-05068");
                vksc::CreateComputePipelines(device.handle(), data.pipeline_cache, create_count, create_info.data(), nullptr,
                                             pipelines.data());
                m_errorMonitor->VerifyFound();
            } else {
                assert(index + create_count <= data.pipelines.size());
                vksc::CreateComputePipelines(device.handle(), data.pipeline_cache, create_count, create_info.data(), nullptr,
                                             &data.pipelines[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.pipelines.size());
            assert(destroy_count == 1);

            vksc::DestroyPipeline(device.handle(), data.pipelines[index], nullptr);
            data.pipelines[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        [&](vkt::Device& device) {
            vksc::DestroyPipelineCache(device.handle(), data.pipeline_cache, nullptr);
            vksc::DestroyPipelineLayout(device.handle(), data.pipeline_layout, nullptr);
        });
}

TEST_F(VkSCObjectReservationLayerTest, GraphicsPipelineRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::graphicsPipelineRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        VkPipelinePoolSize pipeline_pool_size{};
        VkRenderPass render_pass{VK_NULL_HANDLE};
        VkPipelineLayout pipeline_layout{VK_NULL_HANDLE};
        VkPipelineCache pipeline_cache{VK_NULL_HANDLE};
        std::vector<VkPipeline> pipelines{};
    } data;

    const uint32_t max_create_count = 16;
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.pipelineCacheCreateInfoCount = 1;
            object_reservation_info.pPipelineCacheCreateInfos = &vksc::GetDefaultPipelineCacheCreateInfo();

            data.pipeline_pool_size = vksc::GetDefaultPipelinePoolSize();
            data.pipeline_pool_size.poolEntryCount = 100 + tested_limit * 3;

            object_reservation_info.pipelinePoolSizeCount = 1;
            object_reservation_info.pPipelinePoolSizes = &data.pipeline_pool_size;

            object_reservation_info.renderPassRequestCount = 1;
            object_reservation_info.subpassDescriptionRequestCount = 1;
            object_reservation_info.pipelineCacheRequestCount = 1;
            object_reservation_info.pipelineLayoutRequestCount = 1;
            object_reservation_info.graphicsPipelineRequestCount = tested_limit;

            data.render_pass = VK_NULL_HANDLE;
            data.pipeline_layout = VK_NULL_HANDLE;
            data.pipeline_cache = VK_NULL_HANDLE;
            data.pipelines.clear();
            data.pipelines.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        [&](vkt::Device& device) {
            VkResult result = VK_SUCCESS;

            {
                VkSubpassDescription subpass{};
                subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

                auto create_info = vku::InitStruct<VkRenderPassCreateInfo>();
                create_info.subpassCount = 1;
                create_info.pSubpasses = &subpass;

                result = vksc::CreateRenderPass(device.handle(), &create_info, nullptr, &data.render_pass);
                if (result != VK_SUCCESS) return false;
            }

            {
                auto create_info = vksc::GetDefaultPipelineCacheCreateInfo();
                result = vksc::CreatePipelineCache(device.handle(), &create_info, nullptr, &data.pipeline_cache);
                if (result != VK_SUCCESS) return false;
            }

            {
                auto create_info = vku::InitStruct<VkPipelineLayoutCreateInfo>();
                result = vksc::CreatePipelineLayout(device.handle(), &create_info, nullptr, &data.pipeline_layout);
                if (result != VK_SUCCESS) return false;
            }

            return true;
        },
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            std::vector<VkPipeline> pipelines(create_count, VK_NULL_HANDLE);

            auto stage_info = vku::InitStruct<VkPipelineShaderStageCreateInfo>();
            stage_info.stage = VK_SHADER_STAGE_VERTEX_BIT;
            stage_info.pName = "main";

            auto vi_state = vku::InitStruct<VkPipelineVertexInputStateCreateInfo>();
            auto ia_state = vku::InitStruct<VkPipelineInputAssemblyStateCreateInfo>();
            auto rs_state = vku::InitStruct<VkPipelineRasterizationStateCreateInfo>();
            rs_state.rasterizerDiscardEnable = VK_TRUE;
            rs_state.lineWidth = 1.f;

            auto offline_info = vksc::GetDefaultPipelineOfflineCreateInfo();
            std::vector<VkGraphicsPipelineCreateInfo> create_info(create_count,
                                                                  vku::InitStruct<VkGraphicsPipelineCreateInfo>(&offline_info));
            for (uint32_t i = 0; i < create_count; ++i) {
                create_info[i].stageCount = 1;
                create_info[i].pStages = &stage_info;
                create_info[i].pVertexInputState = &vi_state;
                create_info[i].pInputAssemblyState = &ia_state;
                create_info[i].pRasterizationState = &rs_state;
                create_info[i].layout = data.pipeline_layout;
                create_info[i].renderPass = data.render_pass;
            }

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateGraphicsPipelines-device-05068");
                vksc::CreateGraphicsPipelines(device.handle(), data.pipeline_cache, create_count, create_info.data(), nullptr,
                                              pipelines.data());
                m_errorMonitor->VerifyFound();
            } else {
                assert(index + create_count <= data.pipelines.size());
                vksc::CreateGraphicsPipelines(device.handle(), data.pipeline_cache, create_count, create_info.data(), nullptr,
                                              &data.pipelines[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.pipelines.size());
            assert(destroy_count == 1);

            vksc::DestroyPipeline(device.handle(), data.pipelines[index], nullptr);
            data.pipelines[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        [&](vkt::Device& device) {
            vksc::DestroyRenderPass(device.handle(), data.render_pass, nullptr);
            vksc::DestroyPipelineCache(device.handle(), data.pipeline_cache, nullptr);
            vksc::DestroyPipelineLayout(device.handle(), data.pipeline_layout, nullptr);
        });
}

TEST_F(VkSCObjectReservationLayerTest, QueryPoolRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::queryPoolRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkQueryPool> query_pools{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = false;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.queryPoolRequestCount = tested_limit;
            object_reservation_info.maxOcclusionQueriesPerPool = 8;

            data.query_pools.clear();
            data.query_pools.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkQueryPool query_pool = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkQueryPoolCreateInfo>();
            create_info.queryType = VK_QUERY_TYPE_OCCLUSION;
            create_info.queryCount = 8;

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateQueryPool-device-05068");
                vksc::CreateQueryPool(device.handle(), &create_info, nullptr, &query_pool);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.query_pools.size());
                vksc::CreateQueryPool(device.handle(), &create_info, nullptr, &data.query_pools[index]);
            }
        },
        // Destroy objects
        nullptr,
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, RenderPassRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::renderPassRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        bool use_create_render_pass2{};
        std::vector<VkRenderPass> render_passes{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.renderPassRequestCount = tested_limit;
            object_reservation_info.subpassDescriptionRequestCount = tested_limit;

            data.render_passes.clear();
            data.render_passes.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkRenderPass render_pass = VK_NULL_HANDLE;

            // Use CreateRenderPass2 for every second create call
            data.use_create_render_pass2 = !data.use_create_render_pass2;
            if (data.use_create_render_pass2) {
                auto subpass = vku::InitStruct<VkSubpassDescription2>();
                subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

                auto create_info = vku::InitStruct<VkRenderPassCreateInfo2>();
                create_info.subpassCount = 1;
                create_info.pSubpasses = &subpass;

                if (should_fail) {
                    m_errorMonitor->SetAllowedFailureMsg("VUID-vkCreateRenderPass2-subpasses-device-05089");
                    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateRenderPass2-device-05068");
                    vksc::CreateRenderPass2(device.handle(), &create_info, nullptr, &render_pass);
                    m_errorMonitor->VerifyFound();
                } else {
                    assert(index < data.render_passes.size());
                    vksc::CreateRenderPass2(device.handle(), &create_info, nullptr, &data.render_passes[index]);
                }
            } else {
                VkSubpassDescription subpass{};
                subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

                auto create_info = vku::InitStruct<VkRenderPassCreateInfo>();
                create_info.subpassCount = 1;
                create_info.pSubpasses = &subpass;

                if (should_fail) {
                    m_errorMonitor->SetAllowedFailureMsg("VUID-vkCreateRenderPass-subpasses-device-05089");
                    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateRenderPass-device-05068");
                    vksc::CreateRenderPass(device.handle(), &create_info, nullptr, &render_pass);
                    m_errorMonitor->VerifyFound();
                } else {
                    assert(index < data.render_passes.size());
                    vksc::CreateRenderPass(device.handle(), &create_info, nullptr, &data.render_passes[index]);
                }
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.render_passes.size());
            assert(destroy_count == 1);

            vksc::DestroyRenderPass(device.handle(), data.render_passes[index], nullptr);
            data.render_passes[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, SubpassDescriptionRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::subpassDescriptionRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        bool use_create_render_pass2{};
        std::vector<VkRenderPass> render_passes{};
    } data;

    const uint32_t max_create_count = std::min(GetVulkanSC10Properties(gpu()).maxRenderPassSubpasses, 4u);
    const bool can_destroy = true;
    const bool has_parent = true;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.renderPassRequestCount = tested_limit + 1;
            object_reservation_info.subpassDescriptionRequestCount = tested_limit;

            data.render_passes.clear();
            data.render_passes.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkRenderPass render_pass = VK_NULL_HANDLE;

            // Use CreateRenderPass2 for every second create call
            data.use_create_render_pass2 = !data.use_create_render_pass2;
            if (data.use_create_render_pass2) {
                std::vector<VkSubpassDescription2> subpasses(create_count, vku::InitStruct<VkSubpassDescription2>());
                for (auto& subpass : subpasses) {
                    subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
                }

                auto create_info = vku::InitStruct<VkRenderPassCreateInfo2>();
                create_info.subpassCount = create_count;
                create_info.pSubpasses = subpasses.data();

                if (should_fail) {
                    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateRenderPass2-subpasses-device-05089");
                    vksc::CreateRenderPass2(device.handle(), &create_info, nullptr, &render_pass);
                    m_errorMonitor->VerifyFound();
                } else {
                    assert(index < data.render_passes.size());
                    vksc::CreateRenderPass2(device.handle(), &create_info, nullptr, &data.render_passes[index]);
                }
            } else {
                std::vector<VkSubpassDescription> subpasses(create_count, VkSubpassDescription{});
                for (auto& subpass : subpasses) {
                    subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
                }

                auto create_info = vku::InitStruct<VkRenderPassCreateInfo>();
                create_info.subpassCount = create_count;
                create_info.pSubpasses = subpasses.data();

                if (should_fail) {
                    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateRenderPass-subpasses-device-05089");
                    vksc::CreateRenderPass(device.handle(), &create_info, nullptr, &render_pass);
                    m_errorMonitor->VerifyFound();
                } else {
                    assert(index < data.render_passes.size());
                    vksc::CreateRenderPass(device.handle(), &create_info, nullptr, &data.render_passes[index]);
                }
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.render_passes.size());
            assert(destroy_count == 0);

            vksc::DestroyRenderPass(device.handle(), data.render_passes[index], nullptr);
            data.render_passes[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, AttachmentDescriptionRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::attachmentDescriptionRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        bool use_create_render_pass2{};
        std::vector<VkRenderPass> render_passes{};
    } data;

    const uint32_t max_create_count = 4;
    const bool can_destroy = true;
    const bool has_parent = true;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.renderPassRequestCount = tested_limit + 1;
            object_reservation_info.subpassDescriptionRequestCount = tested_limit + 1;
            object_reservation_info.attachmentDescriptionRequestCount = tested_limit;

            data.render_passes.clear();
            data.render_passes.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkRenderPass render_pass = VK_NULL_HANDLE;

            // Use CreateRenderPass2 for every second create call
            data.use_create_render_pass2 = !data.use_create_render_pass2;
            if (data.use_create_render_pass2) {
                std::vector<VkAttachmentDescription2> attachments(create_count, vku::InitStruct<VkAttachmentDescription2>());
                for (auto& attachment : attachments) {
                    attachment.format = VK_FORMAT_R8G8B8A8_UNORM;
                    attachment.samples = VK_SAMPLE_COUNT_1_BIT;
                    attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
                    attachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
                    attachment.initialLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
                    attachment.finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
                }

                auto subpass = vku::InitStruct<VkSubpassDescription2>();
                subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

                auto create_info = vku::InitStruct<VkRenderPassCreateInfo2>();
                create_info.attachmentCount = create_count;
                create_info.pAttachments = attachments.data();
                create_info.subpassCount = 1;
                create_info.pSubpasses = &subpass;

                if (should_fail) {
                    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateRenderPass2-attachments-device-05089");
                    vksc::CreateRenderPass2(device.handle(), &create_info, nullptr, &render_pass);
                    m_errorMonitor->VerifyFound();
                } else {
                    assert(index < data.render_passes.size());
                    vksc::CreateRenderPass2(device.handle(), &create_info, nullptr, &data.render_passes[index]);
                }
            } else {
                std::vector<VkAttachmentDescription> attachments(create_count, VkAttachmentDescription{});
                for (auto& attachment : attachments) {
                    attachment.format = VK_FORMAT_R8G8B8A8_UNORM;
                    attachment.samples = VK_SAMPLE_COUNT_1_BIT;
                    attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
                    attachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
                    attachment.initialLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
                    attachment.finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
                }

                VkSubpassDescription subpass{};
                subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

                auto create_info = vku::InitStruct<VkRenderPassCreateInfo>();
                create_info.attachmentCount = create_count;
                create_info.pAttachments = attachments.data();
                create_info.subpassCount = 1;
                create_info.pSubpasses = &subpass;

                if (should_fail) {
                    m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateRenderPass-attachments-device-05089");
                    vksc::CreateRenderPass(device.handle(), &create_info, nullptr, &render_pass);
                    m_errorMonitor->VerifyFound();
                } else {
                    assert(index < data.render_passes.size());
                    vksc::CreateRenderPass(device.handle(), &create_info, nullptr, &data.render_passes[index]);
                }
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.render_passes.size());
            assert(destroy_count == 0);

            vksc::DestroyRenderPass(device.handle(), data.render_passes[index], nullptr);
            data.render_passes[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, FramebufferRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::framebufferRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        VkRenderPass render_pass{VK_NULL_HANDLE};
        std::vector<VkFramebuffer> framebuffers{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.renderPassRequestCount = 1;
            object_reservation_info.subpassDescriptionRequestCount = 1;
            object_reservation_info.framebufferRequestCount = tested_limit;

            data.render_pass = VK_NULL_HANDLE;
            data.framebuffers.clear();
            data.framebuffers.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        [&](vkt::Device& device) {
            VkResult result = VK_SUCCESS;

            VkSubpassDescription subpass{};
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

            auto create_info = vku::InitStruct<VkRenderPassCreateInfo>();
            create_info.subpassCount = 1;
            create_info.pSubpasses = &subpass;

            result = vksc::CreateRenderPass(device.handle(), &create_info, nullptr, &data.render_pass);
            if (result != VK_SUCCESS) return false;

            return true;
        },
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkFramebuffer framebuffer = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkFramebufferCreateInfo>();
            create_info.renderPass = data.render_pass;
            create_info.width = 128;
            create_info.height = 128;
            create_info.layers = 1;

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateFramebuffer-device-05068");
                vksc::CreateFramebuffer(device.handle(), &create_info, nullptr, &framebuffer);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.framebuffers.size());
                vksc::CreateFramebuffer(device.handle(), &create_info, nullptr, &data.framebuffers[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.framebuffers.size());
            assert(destroy_count == 1);

            vksc::DestroyFramebuffer(device.handle(), data.framebuffers[index], nullptr);
            data.framebuffers[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        [&](vkt::Device& device) { vksc::DestroyRenderPass(device.handle(), data.render_pass, nullptr); });
}

TEST_F(VkSCObjectReservationLayerTest, BufferRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::bufferRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkBuffer> buffers{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.bufferRequestCount = tested_limit;

            data.buffers.clear();
            data.buffers.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkBuffer buffer = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkBufferCreateInfo>();
            create_info.size = 1024;
            create_info.usage = VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT;

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateBuffer-device-05068");
                vksc::CreateBuffer(device.handle(), &create_info, nullptr, &buffer);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.buffers.size());
                vksc::CreateBuffer(device.handle(), &create_info, nullptr, &data.buffers[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.buffers.size());
            assert(destroy_count == 1);

            vksc::DestroyBuffer(device.handle(), data.buffers[index], nullptr);
            data.buffers[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, BufferViewRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::bufferViewRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::unique_ptr<vkt::Buffer> buffer{};
        std::vector<VkBufferView> buffer_views{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.deviceMemoryRequestCount = 1;
            object_reservation_info.bufferRequestCount = 1;
            object_reservation_info.bufferViewRequestCount = tested_limit;

            data.buffer_views.clear();
            data.buffer_views.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        [&](vkt::Device& device) {
            auto create_info = vku::InitStruct<VkBufferCreateInfo>();
            create_info.size = 1024;
            create_info.usage = VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT;

            data.buffer = std::make_unique<vkt::Buffer>(device, create_info);
            if (data.buffer->memory().handle() == VK_NULL_HANDLE) return false;

            return true;
        },
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkBufferView buffer_view = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkBufferViewCreateInfo>();
            create_info.buffer = data.buffer->handle();
            create_info.format = VK_FORMAT_R32_UINT;
            create_info.range = 256;

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateBufferView-device-05068");
                vksc::CreateBufferView(device.handle(), &create_info, nullptr, &buffer_view);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.buffer_views.size());
                vksc::CreateBufferView(device.handle(), &create_info, nullptr, &data.buffer_views[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.buffer_views.size());
            assert(destroy_count == 1);

            vksc::DestroyBufferView(device.handle(), data.buffer_views[index], nullptr);
            data.buffer_views[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        [&](vkt::Device& device) { data.buffer = nullptr; });
}

TEST_F(VkSCObjectReservationLayerTest, ImageRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::imageRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkImage> images{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.imageRequestCount = tested_limit;

            data.images.clear();
            data.images.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkImage image = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkImageCreateInfo>();
            create_info.imageType = VK_IMAGE_TYPE_2D;
            create_info.format = VK_FORMAT_R8G8B8A8_UNORM;
            create_info.extent = {16, 16, 1};
            create_info.mipLevels = 1;
            create_info.arrayLayers = 1;
            create_info.samples = VK_SAMPLE_COUNT_1_BIT;
            create_info.tiling = VK_IMAGE_TILING_OPTIMAL;
            create_info.usage = VK_IMAGE_USAGE_SAMPLED_BIT;

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateImage-device-05068");
                vksc::CreateImage(device.handle(), &create_info, nullptr, &image);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.images.size());
                vksc::CreateImage(device.handle(), &create_info, nullptr, &data.images[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.images.size());
            assert(destroy_count == 1);

            vksc::DestroyImage(device.handle(), data.images[index], nullptr);
            data.images[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, ImageViewRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::imageViewRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::unique_ptr<vkt::Image> image{};
        std::vector<VkImageView> image_views{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.deviceMemoryRequestCount = 1;
            object_reservation_info.imageRequestCount = 1;
            object_reservation_info.imageViewRequestCount = tested_limit;
            object_reservation_info.maxImageViewMipLevels = 1;
            object_reservation_info.maxImageViewArrayLayers = 1;

            data.image_views.clear();
            data.image_views.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        [&](vkt::Device& device) {
            auto create_info = vku::InitStruct<VkImageCreateInfo>();
            create_info.imageType = VK_IMAGE_TYPE_2D;
            create_info.format = VK_FORMAT_R8G8B8A8_UNORM;
            create_info.extent = {16, 16, 1};
            create_info.mipLevels = 1;
            create_info.arrayLayers = 1;
            create_info.samples = VK_SAMPLE_COUNT_1_BIT;
            create_info.tiling = VK_IMAGE_TILING_OPTIMAL;
            create_info.usage = VK_IMAGE_USAGE_SAMPLED_BIT;

            data.image = std::make_unique<vkt::Image>(device, create_info);
            if (data.image->memory().handle() == VK_NULL_HANDLE) return false;

            return true;
        },
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkImageView image_view = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkImageViewCreateInfo>();
            create_info.image = data.image->handle();
            create_info.viewType = VK_IMAGE_VIEW_TYPE_2D;
            create_info.format = VK_FORMAT_R8G8B8A8_UNORM;
            create_info.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1};

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateImageView-device-05068");
                vksc::CreateImageView(device.handle(), &create_info, nullptr, &image_view);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.image_views.size());
                vksc::CreateImageView(device.handle(), &create_info, nullptr, &data.image_views[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.image_views.size());
            assert(destroy_count == 1);

            vksc::DestroyImageView(device.handle(), data.image_views[index], nullptr);
            data.image_views[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        [&](vkt::Device& device) { data.image = nullptr; });
}

TEST_F(VkSCObjectReservationLayerTest, LayeredImageViewRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::layeredImageViewRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        const uint32_t layer_count = 32;
        std::unique_ptr<vkt::Image> image{};
        std::vector<VkImageView> non_layered_image_views{};
        std::vector<VkImageView> layered_image_views{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.deviceMemoryRequestCount = 1;
            object_reservation_info.imageRequestCount = 1;
            object_reservation_info.imageViewRequestCount = tested_limit + data.layer_count + 1;
            object_reservation_info.layeredImageViewRequestCount = tested_limit;
            object_reservation_info.maxImageViewMipLevels = 1;
            object_reservation_info.maxImageViewArrayLayers = data.layer_count;
            object_reservation_info.maxLayeredImageViewMipLevels = 1;

            data.non_layered_image_views.clear();
            data.non_layered_image_views.resize(data.layer_count, VK_NULL_HANDLE);
            data.layered_image_views.clear();
            data.layered_image_views.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        [&](vkt::Device& device) {
            VkResult result = VK_SUCCESS;

            auto create_info = vku::InitStruct<VkImageCreateInfo>();
            create_info.imageType = VK_IMAGE_TYPE_2D;
            create_info.format = VK_FORMAT_R8G8B8A8_UNORM;
            create_info.extent = {16, 16, 1};
            create_info.mipLevels = 1;
            create_info.arrayLayers = data.layer_count;
            create_info.samples = VK_SAMPLE_COUNT_1_BIT;
            create_info.tiling = VK_IMAGE_TILING_OPTIMAL;
            create_info.usage = VK_IMAGE_USAGE_SAMPLED_BIT;

            data.image = std::make_unique<vkt::Image>(device, create_info);
            if (data.image->memory().handle() == VK_NULL_HANDLE) return false;

            for (uint32_t i = 0; i < data.layer_count; ++i) {
                auto view_create_info = vku::InitStruct<VkImageViewCreateInfo>();
                view_create_info.image = data.image->handle();
                view_create_info.viewType = VK_IMAGE_VIEW_TYPE_2D_ARRAY;
                view_create_info.format = VK_FORMAT_R8G8B8A8_UNORM;
                view_create_info.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, i, 1};

                result = vksc::CreateImageView(device.handle(), &view_create_info, nullptr, &data.non_layered_image_views[i]);
                if (result != VK_SUCCESS) return false;
            }

            return true;
        },
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkImageView image_view = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkImageViewCreateInfo>();
            create_info.image = data.image->handle();
            create_info.viewType = VK_IMAGE_VIEW_TYPE_2D_ARRAY;
            create_info.format = VK_FORMAT_R8G8B8A8_UNORM;
            create_info.subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1};
            create_info.subresourceRange.baseArrayLayer = index % (data.layer_count / 2);
            create_info.subresourceRange.layerCount = (index % 2 == 0) ? data.layer_count / 2 : VK_REMAINING_ARRAY_LAYERS;

            assert(create_info.subresourceRange.layerCount > 1);

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateImageView-subresourceRange-05063");
                vksc::CreateImageView(device.handle(), &create_info, nullptr, &image_view);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.layered_image_views.size());
                vksc::CreateImageView(device.handle(), &create_info, nullptr, &data.layered_image_views[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.layered_image_views.size());
            assert(destroy_count == 1);

            vksc::DestroyImageView(device.handle(), data.layered_image_views[index], nullptr);
            data.layered_image_views[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        [&](vkt::Device& device) {
            for (uint32_t i = 0; i < data.layer_count; ++i) {
                vksc::DestroyImageView(device.handle(), data.non_layered_image_views[i], nullptr);
            }
            data.image = nullptr;
        });
}

TEST_F(VkSCObjectReservationLayerTest, SamplerRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::samplerRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkSampler> samplers{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.samplerRequestCount = tested_limit;

            data.samplers.clear();
            data.samplers.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkSampler sampler = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkSamplerCreateInfo>();
            create_info.magFilter = VK_FILTER_LINEAR;
            create_info.minFilter = VK_FILTER_LINEAR;

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateSampler-device-05068");
                vksc::CreateSampler(device.handle(), &create_info, nullptr, &sampler);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.samplers.size());
                vksc::CreateSampler(device.handle(), &create_info, nullptr, &data.samplers[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.samplers.size());
            assert(destroy_count == 1);

            vksc::DestroySampler(device.handle(), data.samplers[index], nullptr);
            data.samplers[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, SamplerYcbcrConversionRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::samplerYcbcrConversionRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        VkFormat ycbcr_format = VK_FORMAT_UNDEFINED;
        std::vector<VkSamplerYcbcrConversion> sampler_ycbcr_conversions{};
    } data;

    auto sampler_ycbcr_conversion_features = vku::InitStruct<VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR>();
    GetPhysicalDeviceFeatures2(sampler_ycbcr_conversion_features);
    if (!sampler_ycbcr_conversion_features.samplerYcbcrConversion) {
        GTEST_SKIP() << "Test requires samplerYcbcrConversion";
    }

    const std::vector<VkFormat> ycbcr_formats{VK_FORMAT_G8B8G8R8_422_UNORM,        VK_FORMAT_B8G8R8G8_422_UNORM,
                                              VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM, VK_FORMAT_G8_B8R8_2PLANE_420_UNORM,
                                              VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM, VK_FORMAT_G8_B8R8_2PLANE_422_UNORM,
                                              VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM};
    for (const auto format : ycbcr_formats) {
        if (FormatFeaturesAreSupported(gpu(), format, VK_IMAGE_TILING_OPTIMAL, VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT)) {
            data.ycbcr_format = format;
            break;
        }
    }
    if (data.ycbcr_format == VK_FORMAT_UNDEFINED) {
        GTEST_SKIP() << "Test requires a YCbCr format supporting sampled image usage";
    }

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, &sampler_ycbcr_conversion_features,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.samplerYcbcrConversionRequestCount = tested_limit;

            data.sampler_ycbcr_conversions.clear();
            data.sampler_ycbcr_conversions.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkSamplerYcbcrConversion sampler_ycbcr_conversion = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkSamplerYcbcrConversionCreateInfo>();
            create_info.format = data.ycbcr_format;

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateSamplerYcbcrConversion-device-05068");
                vksc::CreateSamplerYcbcrConversion(device.handle(), &create_info, nullptr, &sampler_ycbcr_conversion);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.sampler_ycbcr_conversions.size());
                vksc::CreateSamplerYcbcrConversion(device.handle(), &create_info, nullptr, &data.sampler_ycbcr_conversions[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.sampler_ycbcr_conversions.size());
            assert(destroy_count == 1);

            vksc::DestroySamplerYcbcrConversion(device.handle(), data.sampler_ycbcr_conversions[index], nullptr);
            data.sampler_ycbcr_conversions[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, FenceRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::fenceRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkFence> fences{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.fenceRequestCount = tested_limit;

            data.fences.clear();
            data.fences.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkFence fence = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkFenceCreateInfo>();

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateFence-device-05068");
                vksc::CreateFence(device.handle(), &create_info, nullptr, &fence);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.fences.size());
                vksc::CreateFence(device.handle(), &create_info, nullptr, &data.fences[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.fences.size());
            assert(destroy_count == 1);

            vksc::DestroyFence(device.handle(), data.fences[index], nullptr);
            data.fences[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, SemaphoreRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::semaphoreRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkSemaphore> semaphores{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.semaphoreRequestCount = tested_limit;

            data.semaphores.clear();
            data.semaphores.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkSemaphore semaphore = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkSemaphoreCreateInfo>();

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateSemaphore-device-05068");
                vksc::CreateSemaphore(device.handle(), &create_info, nullptr, &semaphore);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.semaphores.size());
                vksc::CreateSemaphore(device.handle(), &create_info, nullptr, &data.semaphores[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.semaphores.size());
            assert(destroy_count == 1);

            vksc::DestroySemaphore(device.handle(), data.semaphores[index], nullptr);
            data.semaphores[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, EventRequestCount) {
    TEST_DESCRIPTION("Test VkDeviceObjectReservationCreateInfo::eventRequestCount");

    RETURN_IF_SKIP(InitFramework());

    struct {
        std::vector<VkEvent> events{};
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            object_reservation_info.eventRequestCount = tested_limit;

            data.events.clear();
            data.events.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        nullptr,
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkEvent event = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkEventCreateInfo>();

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreateEvent-device-05068");
                vksc::CreateEvent(device.handle(), &create_info, nullptr, &event);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.events.size());
                vksc::CreateEvent(device.handle(), &create_info, nullptr, &data.events[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.events.size());
            assert(destroy_count == 1);

            vksc::DestroyEvent(device.handle(), data.events[index], nullptr);
            data.events[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}

TEST_F(VkSCObjectReservationLayerTest, PrivateDataSlotRequestCount) {
    TEST_DESCRIPTION("Test VkDevicePrivateDataCreateInfoEXT::privateDataSlotRequestCount");

    RETURN_IF_SKIP(InitFramework());

    if (!DeviceExtensionSupported(VK_EXT_PRIVATE_DATA_EXTENSION_NAME)) {
        GTEST_SKIP() << "Test requires VK_EXT_private_data";
    }

    device_extensions.push_back(VK_EXT_PRIVATE_DATA_EXTENSION_NAME);

    struct {
        VkDevicePrivateDataCreateInfoEXT private_data_slot_reservation_info{};
        std::vector<VkPrivateDataSlotEXT> private_data_slots{};

        PFN_vkCreatePrivateDataSlotEXT pfn_vkCreatePrivateDataSlotEXT;
        PFN_vkDestroyPrivateDataSlotEXT pfn_vkDestroyPrivateDataSlotEXT;
    } data;

    const uint32_t max_create_count = 0;  // Not a multi-create API
    const bool can_destroy = true;
    const bool has_parent = false;

    TestObjectReservationLimit(
        max_create_count, can_destroy, has_parent, nullptr,
        // Init object reservation info
        [&](VkDeviceObjectReservationCreateInfo& object_reservation_info, uint32_t tested_limit) {
            if (tested_limit > 50) {
                // Do not try to test unreasonably large private data slot counts
                return false;
            }

            data.private_data_slot_reservation_info = vku::InitStruct<VkDevicePrivateDataCreateInfoEXT>();
            data.private_data_slot_reservation_info.privateDataSlotRequestCount = tested_limit;
            data.private_data_slot_reservation_info.pNext = object_reservation_info.pNext;
            object_reservation_info.pNext = &data.private_data_slot_reservation_info;

            data.private_data_slots.clear();
            data.private_data_slots.resize(tested_limit, VK_NULL_HANDLE);

            return true;
        },
        // Setup common device objects
        [&](vkt::Device& device) {
            // Load extension function pointers
            data.pfn_vkCreatePrivateDataSlotEXT =
                (PFN_vkCreatePrivateDataSlotEXT)vk::GetDeviceProcAddr(device.handle(), "vkCreatePrivateDataSlotEXT");
            data.pfn_vkDestroyPrivateDataSlotEXT =
                (PFN_vkDestroyPrivateDataSlotEXT)vk::GetDeviceProcAddr(device.handle(), "vkDestroyPrivateDataSlotEXT");

            return data.pfn_vkCreatePrivateDataSlotEXT && data.pfn_vkDestroyPrivateDataSlotEXT;
        },
        // Create objects
        [&](vkt::Device& device, uint32_t index, uint32_t create_count, bool should_fail) {
            VkPrivateDataSlotEXT private_data_slot = VK_NULL_HANDLE;

            auto create_info = vku::InitStruct<VkPrivateDataSlotCreateInfoEXT>();

            if (should_fail) {
                m_errorMonitor->SetDesiredFailureMsg(kErrorBit, "VUID-vkCreatePrivateDataSlotEXT-device-05000");
                data.pfn_vkCreatePrivateDataSlotEXT(device.handle(), &create_info, nullptr, &private_data_slot);
                m_errorMonitor->VerifyFound();
            } else {
                assert(index < data.private_data_slots.size());
                data.pfn_vkCreatePrivateDataSlotEXT(device.handle(), &create_info, nullptr, &data.private_data_slots[index]);
            }
        },
        // Destroy objects
        [&](vkt::Device& device, uint32_t index, uint32_t destroy_count) {
            assert(index < data.private_data_slots.size());
            assert(destroy_count == 1);

            data.pfn_vkDestroyPrivateDataSlotEXT(device.handle(), data.private_data_slots[index], nullptr);
            data.private_data_slots[index] = VK_NULL_HANDLE;
        },
        // Teardown common device objects
        nullptr);
}
