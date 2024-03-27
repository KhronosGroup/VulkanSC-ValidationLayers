/*
 * Copyright (c) 2024-2024 The Khronos Group Inc.
 * Copyright (c) 2024-2024 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */
#pragma once

[[maybe_unused]] static char const kSampleComputePipelineJson[] = R"json(
    {
        "ComputePipelineState": {
            "YcbcrSamplers": [],
            "ImmutableSamplers": [],
            "DescriptorSetLayouts": [],
            "PipelineLayout": {
                "sType": "VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO",
                "pNext": "NULL",
                "flags": 0,
                "setLayoutCount": 0,
                "pSetLayouts": "NULL",
                "pushConstantRangeCount": 0,
                "pPushConstantRanges": "NULL"
            },
            "ComputePipeline": {
                "sType": "VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO",
                "pNext": "NULL",
                "flags": "0",
                "stage": {
                    "sType": "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO",
                    "pNext": "NULL",
                    "flags": "0",
                    "stage": "VK_SHADER_STAGE_COMPUTE_BIT",
                    "module": "",
                    "pName": "main",
                    "pSpecializationInfo": "NULL"
                },
                "layout": "",
                "basePipelineHandle": "",
                "basePipelineIndex": 0
            }
        }
    }
)json";

[[maybe_unused]] static char const kSampleGraphicsPipelineJson[] = R"json(
    {
        "GraphicsPipelineState": {
            "Renderpass": {
                "sType": "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO",
                "pNext":"NULL",
                "flags": "0",
                "attachmentCount": 0,
                "pAttachments": [],
                "subpassCount": 1,
                "pSubpasses": [
                    {
                        "flags": "0",
                        "pipelineBindPoint": "VK_PIPELINE_BIND_POINT_GRAPHICS",
                        "inputAttachmentCount": 0,
                        "pInputAttachments": "NULL",
                        "colorAttachmentCount" : 0,
                        "pColorAttachments": "NULL",
                        "pResolveAttachments": "NULL",
                        "pDepthStencilAttachment": "NULL",
                        "preserveAttachmentCount": 0,
                        "pPreserveAttachments": "NULL"
                    }
                ],
                "dependencyCount": 0,
                "pDependencies": "NULL"
            },
            "YcbcrSamplers": [],
            "ImmutableSamplers": [],
            "DescriptorSetLayouts": [],
            "PipelineLayout": {
                "sType": "VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO",
                "pNext": "NULL",
                "flags": 0,
                "setLayoutCount": 0,
                "pSetLayouts": "NULL",
                "pushConstantRangeCount": 0,
                "pPushConstantRanges": "NULL"
            },
            "GraphicsPipeline": {
                "sType": "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO",
                "pNext": "NULL",
                "flags": "0",
                "stageCount": 2,
                "pStages": [
                    {
                        "sType": "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO",
                        "pNext": "NULL",
                        "flags": "0",
                        "stage": "VK_SHADER_STAGE_VERTEX_BIT",
                        "module": "",
                        "pName": "main",
                        "pSpecializationInfo": "NULL"
                    },
                    {
                        "sType": "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO",
                        "pNext": "NULL",
                        "flags": "0",
                        "stage": "VK_SHADER_STAGE_FRAGMENT_BIT",
                        "module": "",
                        "pName": "main",
                        "pSpecializationInfo": "NULL"
                    }
                ],
                "pVertexInputState": "NULL",
                "pInputAssemblyState": {
                    "sType": "VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO",
                    "pNext": "NULL",
                    "flags": 0,
                    "topology": "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST",
                    "primitiveRestartEnable": "VK_FALSE"
                },
                "pTessellationState": "NULL",
                "pViewportState": {
                    "sType": "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO",
                    "pNext": "NULL",
                    "flags": 0,
                    "viewportCount": 1,
                    "pViewports": "NULL",
                    "scissorCount": 1,
                    "pScissors": "NULL"
                },
                "pRasterizationState": {
                    "sType": "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO",
                    "pNext":"NULL",
                    "flags": 0,
                    "depthClampEnable": "VK_FALSE",
                    "rasterizerDiscardEnable": "VK_FALSE",
                    "polygonMode": "VK_POLYGON_MODE_FILL",
                    "cullMode": "0",
                    "frontFace": "VK_FRONT_FACE_COUNTER_CLOCKWISE",
                    "depthBiasEnable": "VK_FALSE",
                    "depthBiasConstantFactor" : 0,
                    "depthBiasClamp": 0,
                    "depthBiasSlopeFactor" : 0,
                    "lineWidth": 1
                },
                "pMultisampleState": {
                    "sType": "VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO",
                    "pNext": "NULL",
                    "flags": 0,
                    "rasterizationSamples": "VK_SAMPLE_COUNT_1_BIT",
                    "sampleShadingEnable": "VK_FALSE",
                    "minSampleShading": 0,
                    "pSampleMask": "NULL",
                    "alphaToCoverageEnable": "VK_FALSE",
                    "alphaToOneEnable": "VK_FALSE"
                },
                "pDepthStencilState": "NULL",
                "pColorBlendState": {
                    "sType": "VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO",
                    "pNext": "NULL",
                    "flags": "0",
                    "logicOpEnable": "VK_FALSE",
                    "logicOp": "VK_LOGIC_OP_CLEAR",
                    "attachmentCount": 0,
                    "pAttachments": "NULL",
                    "blendConstants": [ 0, 0, 0, 0 ]
                },
                "pDynamicState": {
                    "sType": "VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO",
                    "pNext": "NULL",
                    "flags": 0,
                    "dynamicStateCount": 2,
                    "pDynamicStates": [
                        "VK_DYNAMIC_STATE_VIEWPORT",
                        "VK_DYNAMIC_STATE_SCISSOR"
                    ]
                },
                "layout": "",
                "renderPass": "",
                "subpass": 0,
                "basePipelineHandle": "",
                "basePipelineIndex": 0
            }
        }
    }
)json";

[[maybe_unused]] static char const kSampleComputePipelineWithSpecializationConstantJson[] = R"json(
    {
        "ComputePipelineState": {
            "YcbcrSamplers": [],
            "ImmutableSamplers": [],
            "DescriptorSetLayouts": [],
            "PipelineLayout": {
                "sType": "VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO",
                "pNext": "NULL",
                "flags": 0,
                "setLayoutCount": 0,
                "pSetLayouts": "NULL",
                "pushConstantRangeCount": 0,
                "pPushConstantRanges": "NULL"
            },
            "ComputePipeline": {
                "sType": "VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO",
                "pNext": "NULL",
                "flags": "0",
                "stage": {
                    "sType": "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO",
                    "pNext": "NULL",
                    "flags": "0",
                    "stage": "VK_SHADER_STAGE_COMPUTE_BIT",
                    "module": "",
                    "pName": "main",
                    "pSpecializationInfo": {
                        "mapEntryCount": 1,
                        "pMapEntries": {
                            "constantID": 0,
                            "offset": 0,
                            "size": 4
                        },
                        "dataSize": 4,
                        "pData": [ 0, 0, 0, 0 ]
                    }
                },
                "layout": "",
                "basePipelineHandle": "",
                "basePipelineIndex": 0
            }
        }
    }
)json";
