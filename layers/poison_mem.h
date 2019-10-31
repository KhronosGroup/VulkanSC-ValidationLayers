/* Copyright (c) 2015-2019 The Khronos Group Inc.
 * Copyright (c) 2015-2019 Valve Corporation
 * Copyright (c) 2015-2019 LunarG, Inc.
 * Copyright (C) 2015-2019 Google Inc.
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
 *
 * Author: Mark Lobodzinski <mark@lunarg.com>
 */

class PoisonMem : public ValidationObject {
  public:
    // Override chassis read/write locks for this validation object
    // This override takes a deferred lock. i.e. it is not acquired.
    // This class does its own locking with a shared mutex.
    virtual read_lock_guard_t read_lock() { return read_lock_guard_t(validation_object_mutex, std::defer_lock); }
    virtual write_lock_guard_t write_lock() { return write_lock_guard_t(validation_object_mutex, std::defer_lock); }

    VkPhysicalDeviceMemoryProperties phys_dev_mem_properties = {};
    static const int MEM_POISONING_FILL_VALUE = 0xA5;

    void PostCallRecordAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo,
                                      const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory, VkResult result) {
        if (result == VK_SUCCESS) {
            if (phys_dev_mem_properties.memoryTypeCount == 0) {
                DispatchGetPhysicalDeviceMemoryProperties(physical_device, &phys_dev_mem_properties);
            }
            if ((phys_dev_mem_properties.memoryTypes[pAllocateInfo->memoryTypeIndex].propertyFlags &
                 VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)) {
                // map the memory, fill it with crap, and unmap it.
                void* data;
                auto otherresult = DispatchMapMemory(device, *pMemory, 0, pAllocateInfo->allocationSize, 0, &data);
                memset(data, MEM_POISONING_FILL_VALUE, pAllocateInfo->allocationSize);
                DispatchUnmapMemory(device, *pMemory);
            }
        }
    }
};
