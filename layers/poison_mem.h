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

// Thread Local Storage for RP/AD info to key on RP object handle.
thread_local std::vector<bool> ad_modified_indices{};

class PoisonMem : public ValidationObject {
  public:
    // Override chassis read/write locks for this validation object
    // This override takes a deferred lock. i.e. it is not acquired.
    // This class does its own locking with a shared mutex.
    virtual read_lock_guard_t read_lock() { return read_lock_guard_t(validation_object_mutex, std::defer_lock); }
    virtual write_lock_guard_t write_lock() { return write_lock_guard_t(validation_object_mutex, std::defer_lock); }

    VkPhysicalDeviceMemoryProperties phys_dev_mem_properties = {};
    static const int MEM_POISONING_FILL_VALUE = 0xA5;

    std::unordered_map<VkRenderPass, std::vector<bool>> renderpass_modified_attachment_map{};

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

    void PreCallRecordCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
        bool has_color_load_op = false;
        std::vector<bool> is_color_attachment{};
        is_color_attachment.resize(pCreateInfo->attachmentCount);
        ad_modified_indices.resize(pCreateInfo->attachmentCount);

        // Find all color attachments
        for (uint32_t subpass = 0; subpass < pCreateInfo->subpassCount; subpass++) {
            for (uint32_t color_attachment = 0; color_attachment < pCreateInfo->pSubpasses[subpass].colorAttachmentCount;
                 color_attachment++) {
                if (pCreateInfo->pSubpasses[subpass].pColorAttachments[color_attachment].attachment != VK_ATTACHMENT_UNUSED) {
                    is_color_attachment[pCreateInfo->pSubpasses[subpass].pColorAttachments[color_attachment].attachment] = true;
                }
            }
        }

        for (uint32_t i = 0; i < pCreateInfo->attachmentCount; i++) {
            if ((is_color_attachment[i]) && (pCreateInfo->pAttachments[i].loadOp == VK_ATTACHMENT_LOAD_OP_DONT_CARE)) {
                // Change the load op from DC to CLEAR
                const_cast<VkAttachmentLoadOp>(pCreateInfo->pAttachments[i].loadOp) = VK_ATTACHMENT_LOAD_OP_CLEAR;
                has_color_load_op = ad_modified_indices[i] = true;
            } else {
                ad_modified_indices[i] = false;
            }
        }

        if (!has_color_load_op) {
            ad_modified_indices.clear();
        }
    }

    void PostCallRecordCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass, VkResult result) {
        if (ad_modified_indices.size()) {
            renderpass_modified_attachment_map[*pRenderPass] = std::move(ad_modified_indices);
        }
    }

    void PreCallRecordDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) {
        // Remove AD vector from the RP map.
        auto target_renderpass = renderpass_modified_attachment_map.find(renderPass);
        if (target_renderpass != renderpass_modified_attachment_map.end()) {
            renderpass_modified_attachment_map.erase(target_renderpass);
        }
    }

    void PreCallRecordCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                         VkSubpassContents contents) {
        auto target_renderpass = renderpass_modified_attachment_map.find(pRenderPassBegin->renderPass);
        if (target_renderpass == renderpass_modified_attachment_map.end()) return;

        uint32_t att_count = static_cast<uint32_t>(target_renderpass->second.size());
        uint32_t i;
        // We need to reallocate some clear values here!
        VkClearValue* new_clear_values = new VkClearValue[att_count];

        for (i = 0; i < pRenderPassBegin->clearValueCount; i++) {
            if (target_renderpass->second[i]) {
                new_clear_values[i].color = {0xA5, 0xA5, 0xA5, 0xA5};
            } else {
                new_clear_values[i] = pRenderPassBegin->pClearValues[i];
            }
        }

        for (i; i < att_count; i++) {
            if (target_renderpass->second[i]) {
                new_clear_values[i].color = {0xA5, 0xA5, 0xA5, 0xA5};
            }
        }

        // Change the clear values in the down-chain call.
        // We should prolly use a safe struct here and blow it away in PostCallRecord
        const_cast<VkRenderPassBeginInfo*>(pRenderPassBegin)->clearValueCount = att_count;
        const_cast<VkRenderPassBeginInfo*>(pRenderPassBegin)->pClearValues = new_clear_values;
    }

    // void PreCallRecordCreateRenderPass2KHR(
    //    VkDevice                                    device,
    //    const VkRenderPassCreateInfo2KHR*           pCreateInfo,
    //    const VkAllocationCallbacks*                pAllocator,
    //    VkRenderPass*                               pRenderPass);

    // bool PreCallRecordCmdBeginRenderPass2KHR(
    //    VkCommandBuffer                             commandBuffer,
    //    const VkRenderPassBeginInfo*                pRenderPassBegin,
    //    const VkSubpassBeginInfoKHR*                pSubpassBeginInfo);
};
