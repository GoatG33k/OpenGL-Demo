/**
 * SPDX-License-Identifier: (WTFPL OR CC0-1.0) AND Apache-2.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/vulkan.h>

#ifndef GLAD_IMPL_UTIL_C_
#define GLAD_IMPL_UTIL_C_

#ifdef _MSC_VER
#define GLAD_IMPL_UTIL_SSCANF sscanf_s
#else
#define GLAD_IMPL_UTIL_SSCANF sscanf
#endif

#endif /* GLAD_IMPL_UTIL_C_ */

#ifdef __cplusplus
extern "C" {
#endif



int GLAD_VK_VERSION_1_0 = 0;
int GLAD_VK_VERSION_1_1 = 0;
int GLAD_VK_VERSION_1_2 = 0;
int GLAD_VK_VERSION_1_3 = 0;
int GLAD_VK_AMD_draw_indirect_count = 0;
int GLAD_VK_EXT_buffer_device_address = 0;
int GLAD_VK_EXT_extended_dynamic_state = 0;
int GLAD_VK_EXT_extended_dynamic_state2 = 0;
int GLAD_VK_EXT_host_query_reset = 0;
int GLAD_VK_EXT_private_data = 0;
int GLAD_VK_EXT_shader_object = 0;
int GLAD_VK_EXT_tooling_info = 0;
int GLAD_VK_KHR_bind_memory2 = 0;
int GLAD_VK_KHR_buffer_device_address = 0;
int GLAD_VK_KHR_copy_commands2 = 0;
int GLAD_VK_KHR_create_renderpass2 = 0;
int GLAD_VK_KHR_descriptor_update_template = 0;
int GLAD_VK_KHR_device_group = 0;
int GLAD_VK_KHR_device_group_creation = 0;
int GLAD_VK_KHR_draw_indirect_count = 0;
int GLAD_VK_KHR_dynamic_rendering = 0;
int GLAD_VK_KHR_external_fence_capabilities = 0;
int GLAD_VK_KHR_external_memory_capabilities = 0;
int GLAD_VK_KHR_external_semaphore_capabilities = 0;
int GLAD_VK_KHR_get_memory_requirements2 = 0;
int GLAD_VK_KHR_get_physical_device_properties2 = 0;
int GLAD_VK_KHR_maintenance1 = 0;
int GLAD_VK_KHR_maintenance3 = 0;
int GLAD_VK_KHR_maintenance4 = 0;
int GLAD_VK_KHR_sampler_ycbcr_conversion = 0;
int GLAD_VK_KHR_synchronization2 = 0;
int GLAD_VK_KHR_timeline_semaphore = 0;



PFN_vkAcquireNextImage2KHR glad_vkAcquireNextImage2KHR = NULL;
PFN_vkAllocateCommandBuffers glad_vkAllocateCommandBuffers = NULL;
PFN_vkAllocateDescriptorSets glad_vkAllocateDescriptorSets = NULL;
PFN_vkAllocateMemory glad_vkAllocateMemory = NULL;
PFN_vkBeginCommandBuffer glad_vkBeginCommandBuffer = NULL;
PFN_vkBindBufferMemory glad_vkBindBufferMemory = NULL;
PFN_vkBindBufferMemory2 glad_vkBindBufferMemory2 = NULL;
PFN_vkBindBufferMemory2KHR glad_vkBindBufferMemory2KHR = NULL;
PFN_vkBindImageMemory glad_vkBindImageMemory = NULL;
PFN_vkBindImageMemory2 glad_vkBindImageMemory2 = NULL;
PFN_vkBindImageMemory2KHR glad_vkBindImageMemory2KHR = NULL;
PFN_vkCmdBeginQuery glad_vkCmdBeginQuery = NULL;
PFN_vkCmdBeginRenderPass glad_vkCmdBeginRenderPass = NULL;
PFN_vkCmdBeginRenderPass2 glad_vkCmdBeginRenderPass2 = NULL;
PFN_vkCmdBeginRenderPass2KHR glad_vkCmdBeginRenderPass2KHR = NULL;
PFN_vkCmdBeginRendering glad_vkCmdBeginRendering = NULL;
PFN_vkCmdBeginRenderingKHR glad_vkCmdBeginRenderingKHR = NULL;
PFN_vkCmdBindDescriptorSets glad_vkCmdBindDescriptorSets = NULL;
PFN_vkCmdBindIndexBuffer glad_vkCmdBindIndexBuffer = NULL;
PFN_vkCmdBindPipeline glad_vkCmdBindPipeline = NULL;
PFN_vkCmdBindShadersEXT glad_vkCmdBindShadersEXT = NULL;
PFN_vkCmdBindVertexBuffers glad_vkCmdBindVertexBuffers = NULL;
PFN_vkCmdBindVertexBuffers2 glad_vkCmdBindVertexBuffers2 = NULL;
PFN_vkCmdBindVertexBuffers2EXT glad_vkCmdBindVertexBuffers2EXT = NULL;
PFN_vkCmdBlitImage glad_vkCmdBlitImage = NULL;
PFN_vkCmdBlitImage2 glad_vkCmdBlitImage2 = NULL;
PFN_vkCmdBlitImage2KHR glad_vkCmdBlitImage2KHR = NULL;
PFN_vkCmdClearAttachments glad_vkCmdClearAttachments = NULL;
PFN_vkCmdClearColorImage glad_vkCmdClearColorImage = NULL;
PFN_vkCmdClearDepthStencilImage glad_vkCmdClearDepthStencilImage = NULL;
PFN_vkCmdCopyBuffer glad_vkCmdCopyBuffer = NULL;
PFN_vkCmdCopyBuffer2 glad_vkCmdCopyBuffer2 = NULL;
PFN_vkCmdCopyBuffer2KHR glad_vkCmdCopyBuffer2KHR = NULL;
PFN_vkCmdCopyBufferToImage glad_vkCmdCopyBufferToImage = NULL;
PFN_vkCmdCopyBufferToImage2 glad_vkCmdCopyBufferToImage2 = NULL;
PFN_vkCmdCopyBufferToImage2KHR glad_vkCmdCopyBufferToImage2KHR = NULL;
PFN_vkCmdCopyImage glad_vkCmdCopyImage = NULL;
PFN_vkCmdCopyImage2 glad_vkCmdCopyImage2 = NULL;
PFN_vkCmdCopyImage2KHR glad_vkCmdCopyImage2KHR = NULL;
PFN_vkCmdCopyImageToBuffer glad_vkCmdCopyImageToBuffer = NULL;
PFN_vkCmdCopyImageToBuffer2 glad_vkCmdCopyImageToBuffer2 = NULL;
PFN_vkCmdCopyImageToBuffer2KHR glad_vkCmdCopyImageToBuffer2KHR = NULL;
PFN_vkCmdCopyQueryPoolResults glad_vkCmdCopyQueryPoolResults = NULL;
PFN_vkCmdDispatch glad_vkCmdDispatch = NULL;
PFN_vkCmdDispatchBase glad_vkCmdDispatchBase = NULL;
PFN_vkCmdDispatchBaseKHR glad_vkCmdDispatchBaseKHR = NULL;
PFN_vkCmdDispatchIndirect glad_vkCmdDispatchIndirect = NULL;
PFN_vkCmdDraw glad_vkCmdDraw = NULL;
PFN_vkCmdDrawIndexed glad_vkCmdDrawIndexed = NULL;
PFN_vkCmdDrawIndexedIndirect glad_vkCmdDrawIndexedIndirect = NULL;
PFN_vkCmdDrawIndexedIndirectCount glad_vkCmdDrawIndexedIndirectCount = NULL;
PFN_vkCmdDrawIndexedIndirectCountAMD glad_vkCmdDrawIndexedIndirectCountAMD = NULL;
PFN_vkCmdDrawIndexedIndirectCountKHR glad_vkCmdDrawIndexedIndirectCountKHR = NULL;
PFN_vkCmdDrawIndirect glad_vkCmdDrawIndirect = NULL;
PFN_vkCmdDrawIndirectCount glad_vkCmdDrawIndirectCount = NULL;
PFN_vkCmdDrawIndirectCountAMD glad_vkCmdDrawIndirectCountAMD = NULL;
PFN_vkCmdDrawIndirectCountKHR glad_vkCmdDrawIndirectCountKHR = NULL;
PFN_vkCmdEndQuery glad_vkCmdEndQuery = NULL;
PFN_vkCmdEndRenderPass glad_vkCmdEndRenderPass = NULL;
PFN_vkCmdEndRenderPass2 glad_vkCmdEndRenderPass2 = NULL;
PFN_vkCmdEndRenderPass2KHR glad_vkCmdEndRenderPass2KHR = NULL;
PFN_vkCmdEndRendering glad_vkCmdEndRendering = NULL;
PFN_vkCmdEndRenderingKHR glad_vkCmdEndRenderingKHR = NULL;
PFN_vkCmdExecuteCommands glad_vkCmdExecuteCommands = NULL;
PFN_vkCmdFillBuffer glad_vkCmdFillBuffer = NULL;
PFN_vkCmdNextSubpass glad_vkCmdNextSubpass = NULL;
PFN_vkCmdNextSubpass2 glad_vkCmdNextSubpass2 = NULL;
PFN_vkCmdNextSubpass2KHR glad_vkCmdNextSubpass2KHR = NULL;
PFN_vkCmdPipelineBarrier glad_vkCmdPipelineBarrier = NULL;
PFN_vkCmdPipelineBarrier2 glad_vkCmdPipelineBarrier2 = NULL;
PFN_vkCmdPipelineBarrier2KHR glad_vkCmdPipelineBarrier2KHR = NULL;
PFN_vkCmdPushConstants glad_vkCmdPushConstants = NULL;
PFN_vkCmdPushDescriptorSetWithTemplateKHR glad_vkCmdPushDescriptorSetWithTemplateKHR = NULL;
PFN_vkCmdResetEvent glad_vkCmdResetEvent = NULL;
PFN_vkCmdResetEvent2 glad_vkCmdResetEvent2 = NULL;
PFN_vkCmdResetEvent2KHR glad_vkCmdResetEvent2KHR = NULL;
PFN_vkCmdResetQueryPool glad_vkCmdResetQueryPool = NULL;
PFN_vkCmdResolveImage glad_vkCmdResolveImage = NULL;
PFN_vkCmdResolveImage2 glad_vkCmdResolveImage2 = NULL;
PFN_vkCmdResolveImage2KHR glad_vkCmdResolveImage2KHR = NULL;
PFN_vkCmdSetAlphaToCoverageEnableEXT glad_vkCmdSetAlphaToCoverageEnableEXT = NULL;
PFN_vkCmdSetAlphaToOneEnableEXT glad_vkCmdSetAlphaToOneEnableEXT = NULL;
PFN_vkCmdSetBlendConstants glad_vkCmdSetBlendConstants = NULL;
PFN_vkCmdSetColorBlendAdvancedEXT glad_vkCmdSetColorBlendAdvancedEXT = NULL;
PFN_vkCmdSetColorBlendEnableEXT glad_vkCmdSetColorBlendEnableEXT = NULL;
PFN_vkCmdSetColorBlendEquationEXT glad_vkCmdSetColorBlendEquationEXT = NULL;
PFN_vkCmdSetColorWriteMaskEXT glad_vkCmdSetColorWriteMaskEXT = NULL;
PFN_vkCmdSetConservativeRasterizationModeEXT glad_vkCmdSetConservativeRasterizationModeEXT = NULL;
PFN_vkCmdSetCoverageModulationModeNV glad_vkCmdSetCoverageModulationModeNV = NULL;
PFN_vkCmdSetCoverageModulationTableEnableNV glad_vkCmdSetCoverageModulationTableEnableNV = NULL;
PFN_vkCmdSetCoverageModulationTableNV glad_vkCmdSetCoverageModulationTableNV = NULL;
PFN_vkCmdSetCoverageReductionModeNV glad_vkCmdSetCoverageReductionModeNV = NULL;
PFN_vkCmdSetCoverageToColorEnableNV glad_vkCmdSetCoverageToColorEnableNV = NULL;
PFN_vkCmdSetCoverageToColorLocationNV glad_vkCmdSetCoverageToColorLocationNV = NULL;
PFN_vkCmdSetCullMode glad_vkCmdSetCullMode = NULL;
PFN_vkCmdSetCullModeEXT glad_vkCmdSetCullModeEXT = NULL;
PFN_vkCmdSetDepthBias glad_vkCmdSetDepthBias = NULL;
PFN_vkCmdSetDepthBiasEnable glad_vkCmdSetDepthBiasEnable = NULL;
PFN_vkCmdSetDepthBiasEnableEXT glad_vkCmdSetDepthBiasEnableEXT = NULL;
PFN_vkCmdSetDepthBounds glad_vkCmdSetDepthBounds = NULL;
PFN_vkCmdSetDepthBoundsTestEnable glad_vkCmdSetDepthBoundsTestEnable = NULL;
PFN_vkCmdSetDepthBoundsTestEnableEXT glad_vkCmdSetDepthBoundsTestEnableEXT = NULL;
PFN_vkCmdSetDepthClampEnableEXT glad_vkCmdSetDepthClampEnableEXT = NULL;
PFN_vkCmdSetDepthClipEnableEXT glad_vkCmdSetDepthClipEnableEXT = NULL;
PFN_vkCmdSetDepthClipNegativeOneToOneEXT glad_vkCmdSetDepthClipNegativeOneToOneEXT = NULL;
PFN_vkCmdSetDepthCompareOp glad_vkCmdSetDepthCompareOp = NULL;
PFN_vkCmdSetDepthCompareOpEXT glad_vkCmdSetDepthCompareOpEXT = NULL;
PFN_vkCmdSetDepthTestEnable glad_vkCmdSetDepthTestEnable = NULL;
PFN_vkCmdSetDepthTestEnableEXT glad_vkCmdSetDepthTestEnableEXT = NULL;
PFN_vkCmdSetDepthWriteEnable glad_vkCmdSetDepthWriteEnable = NULL;
PFN_vkCmdSetDepthWriteEnableEXT glad_vkCmdSetDepthWriteEnableEXT = NULL;
PFN_vkCmdSetDeviceMask glad_vkCmdSetDeviceMask = NULL;
PFN_vkCmdSetDeviceMaskKHR glad_vkCmdSetDeviceMaskKHR = NULL;
PFN_vkCmdSetEvent glad_vkCmdSetEvent = NULL;
PFN_vkCmdSetEvent2 glad_vkCmdSetEvent2 = NULL;
PFN_vkCmdSetEvent2KHR glad_vkCmdSetEvent2KHR = NULL;
PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT glad_vkCmdSetExtraPrimitiveOverestimationSizeEXT = NULL;
PFN_vkCmdSetFrontFace glad_vkCmdSetFrontFace = NULL;
PFN_vkCmdSetFrontFaceEXT glad_vkCmdSetFrontFaceEXT = NULL;
PFN_vkCmdSetLineRasterizationModeEXT glad_vkCmdSetLineRasterizationModeEXT = NULL;
PFN_vkCmdSetLineStippleEnableEXT glad_vkCmdSetLineStippleEnableEXT = NULL;
PFN_vkCmdSetLineWidth glad_vkCmdSetLineWidth = NULL;
PFN_vkCmdSetLogicOpEXT glad_vkCmdSetLogicOpEXT = NULL;
PFN_vkCmdSetLogicOpEnableEXT glad_vkCmdSetLogicOpEnableEXT = NULL;
PFN_vkCmdSetPatchControlPointsEXT glad_vkCmdSetPatchControlPointsEXT = NULL;
PFN_vkCmdSetPolygonModeEXT glad_vkCmdSetPolygonModeEXT = NULL;
PFN_vkCmdSetPrimitiveRestartEnable glad_vkCmdSetPrimitiveRestartEnable = NULL;
PFN_vkCmdSetPrimitiveRestartEnableEXT glad_vkCmdSetPrimitiveRestartEnableEXT = NULL;
PFN_vkCmdSetPrimitiveTopology glad_vkCmdSetPrimitiveTopology = NULL;
PFN_vkCmdSetPrimitiveTopologyEXT glad_vkCmdSetPrimitiveTopologyEXT = NULL;
PFN_vkCmdSetProvokingVertexModeEXT glad_vkCmdSetProvokingVertexModeEXT = NULL;
PFN_vkCmdSetRasterizationSamplesEXT glad_vkCmdSetRasterizationSamplesEXT = NULL;
PFN_vkCmdSetRasterizationStreamEXT glad_vkCmdSetRasterizationStreamEXT = NULL;
PFN_vkCmdSetRasterizerDiscardEnable glad_vkCmdSetRasterizerDiscardEnable = NULL;
PFN_vkCmdSetRasterizerDiscardEnableEXT glad_vkCmdSetRasterizerDiscardEnableEXT = NULL;
PFN_vkCmdSetRepresentativeFragmentTestEnableNV glad_vkCmdSetRepresentativeFragmentTestEnableNV = NULL;
PFN_vkCmdSetSampleLocationsEnableEXT glad_vkCmdSetSampleLocationsEnableEXT = NULL;
PFN_vkCmdSetSampleMaskEXT glad_vkCmdSetSampleMaskEXT = NULL;
PFN_vkCmdSetScissor glad_vkCmdSetScissor = NULL;
PFN_vkCmdSetScissorWithCount glad_vkCmdSetScissorWithCount = NULL;
PFN_vkCmdSetScissorWithCountEXT glad_vkCmdSetScissorWithCountEXT = NULL;
PFN_vkCmdSetShadingRateImageEnableNV glad_vkCmdSetShadingRateImageEnableNV = NULL;
PFN_vkCmdSetStencilCompareMask glad_vkCmdSetStencilCompareMask = NULL;
PFN_vkCmdSetStencilOp glad_vkCmdSetStencilOp = NULL;
PFN_vkCmdSetStencilOpEXT glad_vkCmdSetStencilOpEXT = NULL;
PFN_vkCmdSetStencilReference glad_vkCmdSetStencilReference = NULL;
PFN_vkCmdSetStencilTestEnable glad_vkCmdSetStencilTestEnable = NULL;
PFN_vkCmdSetStencilTestEnableEXT glad_vkCmdSetStencilTestEnableEXT = NULL;
PFN_vkCmdSetStencilWriteMask glad_vkCmdSetStencilWriteMask = NULL;
PFN_vkCmdSetTessellationDomainOriginEXT glad_vkCmdSetTessellationDomainOriginEXT = NULL;
PFN_vkCmdSetVertexInputEXT glad_vkCmdSetVertexInputEXT = NULL;
PFN_vkCmdSetViewport glad_vkCmdSetViewport = NULL;
PFN_vkCmdSetViewportSwizzleNV glad_vkCmdSetViewportSwizzleNV = NULL;
PFN_vkCmdSetViewportWScalingEnableNV glad_vkCmdSetViewportWScalingEnableNV = NULL;
PFN_vkCmdSetViewportWithCount glad_vkCmdSetViewportWithCount = NULL;
PFN_vkCmdSetViewportWithCountEXT glad_vkCmdSetViewportWithCountEXT = NULL;
PFN_vkCmdUpdateBuffer glad_vkCmdUpdateBuffer = NULL;
PFN_vkCmdWaitEvents glad_vkCmdWaitEvents = NULL;
PFN_vkCmdWaitEvents2 glad_vkCmdWaitEvents2 = NULL;
PFN_vkCmdWaitEvents2KHR glad_vkCmdWaitEvents2KHR = NULL;
PFN_vkCmdWriteBufferMarker2AMD glad_vkCmdWriteBufferMarker2AMD = NULL;
PFN_vkCmdWriteTimestamp glad_vkCmdWriteTimestamp = NULL;
PFN_vkCmdWriteTimestamp2 glad_vkCmdWriteTimestamp2 = NULL;
PFN_vkCmdWriteTimestamp2KHR glad_vkCmdWriteTimestamp2KHR = NULL;
PFN_vkCreateBuffer glad_vkCreateBuffer = NULL;
PFN_vkCreateBufferView glad_vkCreateBufferView = NULL;
PFN_vkCreateCommandPool glad_vkCreateCommandPool = NULL;
PFN_vkCreateComputePipelines glad_vkCreateComputePipelines = NULL;
PFN_vkCreateDescriptorPool glad_vkCreateDescriptorPool = NULL;
PFN_vkCreateDescriptorSetLayout glad_vkCreateDescriptorSetLayout = NULL;
PFN_vkCreateDescriptorUpdateTemplate glad_vkCreateDescriptorUpdateTemplate = NULL;
PFN_vkCreateDescriptorUpdateTemplateKHR glad_vkCreateDescriptorUpdateTemplateKHR = NULL;
PFN_vkCreateDevice glad_vkCreateDevice = NULL;
PFN_vkCreateEvent glad_vkCreateEvent = NULL;
PFN_vkCreateFence glad_vkCreateFence = NULL;
PFN_vkCreateFramebuffer glad_vkCreateFramebuffer = NULL;
PFN_vkCreateGraphicsPipelines glad_vkCreateGraphicsPipelines = NULL;
PFN_vkCreateImage glad_vkCreateImage = NULL;
PFN_vkCreateImageView glad_vkCreateImageView = NULL;
PFN_vkCreateInstance glad_vkCreateInstance = NULL;
PFN_vkCreatePipelineCache glad_vkCreatePipelineCache = NULL;
PFN_vkCreatePipelineLayout glad_vkCreatePipelineLayout = NULL;
PFN_vkCreatePrivateDataSlot glad_vkCreatePrivateDataSlot = NULL;
PFN_vkCreatePrivateDataSlotEXT glad_vkCreatePrivateDataSlotEXT = NULL;
PFN_vkCreateQueryPool glad_vkCreateQueryPool = NULL;
PFN_vkCreateRenderPass glad_vkCreateRenderPass = NULL;
PFN_vkCreateRenderPass2 glad_vkCreateRenderPass2 = NULL;
PFN_vkCreateRenderPass2KHR glad_vkCreateRenderPass2KHR = NULL;
PFN_vkCreateSampler glad_vkCreateSampler = NULL;
PFN_vkCreateSamplerYcbcrConversion glad_vkCreateSamplerYcbcrConversion = NULL;
PFN_vkCreateSamplerYcbcrConversionKHR glad_vkCreateSamplerYcbcrConversionKHR = NULL;
PFN_vkCreateSemaphore glad_vkCreateSemaphore = NULL;
PFN_vkCreateShaderModule glad_vkCreateShaderModule = NULL;
PFN_vkCreateShadersEXT glad_vkCreateShadersEXT = NULL;
PFN_vkDestroyBuffer glad_vkDestroyBuffer = NULL;
PFN_vkDestroyBufferView glad_vkDestroyBufferView = NULL;
PFN_vkDestroyCommandPool glad_vkDestroyCommandPool = NULL;
PFN_vkDestroyDescriptorPool glad_vkDestroyDescriptorPool = NULL;
PFN_vkDestroyDescriptorSetLayout glad_vkDestroyDescriptorSetLayout = NULL;
PFN_vkDestroyDescriptorUpdateTemplate glad_vkDestroyDescriptorUpdateTemplate = NULL;
PFN_vkDestroyDescriptorUpdateTemplateKHR glad_vkDestroyDescriptorUpdateTemplateKHR = NULL;
PFN_vkDestroyDevice glad_vkDestroyDevice = NULL;
PFN_vkDestroyEvent glad_vkDestroyEvent = NULL;
PFN_vkDestroyFence glad_vkDestroyFence = NULL;
PFN_vkDestroyFramebuffer glad_vkDestroyFramebuffer = NULL;
PFN_vkDestroyImage glad_vkDestroyImage = NULL;
PFN_vkDestroyImageView glad_vkDestroyImageView = NULL;
PFN_vkDestroyInstance glad_vkDestroyInstance = NULL;
PFN_vkDestroyPipeline glad_vkDestroyPipeline = NULL;
PFN_vkDestroyPipelineCache glad_vkDestroyPipelineCache = NULL;
PFN_vkDestroyPipelineLayout glad_vkDestroyPipelineLayout = NULL;
PFN_vkDestroyPrivateDataSlot glad_vkDestroyPrivateDataSlot = NULL;
PFN_vkDestroyPrivateDataSlotEXT glad_vkDestroyPrivateDataSlotEXT = NULL;
PFN_vkDestroyQueryPool glad_vkDestroyQueryPool = NULL;
PFN_vkDestroyRenderPass glad_vkDestroyRenderPass = NULL;
PFN_vkDestroySampler glad_vkDestroySampler = NULL;
PFN_vkDestroySamplerYcbcrConversion glad_vkDestroySamplerYcbcrConversion = NULL;
PFN_vkDestroySamplerYcbcrConversionKHR glad_vkDestroySamplerYcbcrConversionKHR = NULL;
PFN_vkDestroySemaphore glad_vkDestroySemaphore = NULL;
PFN_vkDestroyShaderEXT glad_vkDestroyShaderEXT = NULL;
PFN_vkDestroyShaderModule glad_vkDestroyShaderModule = NULL;
PFN_vkDeviceWaitIdle glad_vkDeviceWaitIdle = NULL;
PFN_vkEndCommandBuffer glad_vkEndCommandBuffer = NULL;
PFN_vkEnumerateDeviceExtensionProperties glad_vkEnumerateDeviceExtensionProperties = NULL;
PFN_vkEnumerateDeviceLayerProperties glad_vkEnumerateDeviceLayerProperties = NULL;
PFN_vkEnumerateInstanceExtensionProperties glad_vkEnumerateInstanceExtensionProperties = NULL;
PFN_vkEnumerateInstanceLayerProperties glad_vkEnumerateInstanceLayerProperties = NULL;
PFN_vkEnumerateInstanceVersion glad_vkEnumerateInstanceVersion = NULL;
PFN_vkEnumeratePhysicalDeviceGroups glad_vkEnumeratePhysicalDeviceGroups = NULL;
PFN_vkEnumeratePhysicalDeviceGroupsKHR glad_vkEnumeratePhysicalDeviceGroupsKHR = NULL;
PFN_vkEnumeratePhysicalDevices glad_vkEnumeratePhysicalDevices = NULL;
PFN_vkFlushMappedMemoryRanges glad_vkFlushMappedMemoryRanges = NULL;
PFN_vkFreeCommandBuffers glad_vkFreeCommandBuffers = NULL;
PFN_vkFreeDescriptorSets glad_vkFreeDescriptorSets = NULL;
PFN_vkFreeMemory glad_vkFreeMemory = NULL;
PFN_vkGetBufferDeviceAddress glad_vkGetBufferDeviceAddress = NULL;
PFN_vkGetBufferDeviceAddressEXT glad_vkGetBufferDeviceAddressEXT = NULL;
PFN_vkGetBufferDeviceAddressKHR glad_vkGetBufferDeviceAddressKHR = NULL;
PFN_vkGetBufferMemoryRequirements glad_vkGetBufferMemoryRequirements = NULL;
PFN_vkGetBufferMemoryRequirements2 glad_vkGetBufferMemoryRequirements2 = NULL;
PFN_vkGetBufferMemoryRequirements2KHR glad_vkGetBufferMemoryRequirements2KHR = NULL;
PFN_vkGetBufferOpaqueCaptureAddress glad_vkGetBufferOpaqueCaptureAddress = NULL;
PFN_vkGetBufferOpaqueCaptureAddressKHR glad_vkGetBufferOpaqueCaptureAddressKHR = NULL;
PFN_vkGetDescriptorSetLayoutSupport glad_vkGetDescriptorSetLayoutSupport = NULL;
PFN_vkGetDescriptorSetLayoutSupportKHR glad_vkGetDescriptorSetLayoutSupportKHR = NULL;
PFN_vkGetDeviceBufferMemoryRequirements glad_vkGetDeviceBufferMemoryRequirements = NULL;
PFN_vkGetDeviceBufferMemoryRequirementsKHR glad_vkGetDeviceBufferMemoryRequirementsKHR = NULL;
PFN_vkGetDeviceGroupPeerMemoryFeatures glad_vkGetDeviceGroupPeerMemoryFeatures = NULL;
PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR glad_vkGetDeviceGroupPeerMemoryFeaturesKHR = NULL;
PFN_vkGetDeviceGroupPresentCapabilitiesKHR glad_vkGetDeviceGroupPresentCapabilitiesKHR = NULL;
PFN_vkGetDeviceGroupSurfacePresentModesKHR glad_vkGetDeviceGroupSurfacePresentModesKHR = NULL;
PFN_vkGetDeviceImageMemoryRequirements glad_vkGetDeviceImageMemoryRequirements = NULL;
PFN_vkGetDeviceImageMemoryRequirementsKHR glad_vkGetDeviceImageMemoryRequirementsKHR = NULL;
PFN_vkGetDeviceImageSparseMemoryRequirements glad_vkGetDeviceImageSparseMemoryRequirements = NULL;
PFN_vkGetDeviceImageSparseMemoryRequirementsKHR glad_vkGetDeviceImageSparseMemoryRequirementsKHR = NULL;
PFN_vkGetDeviceMemoryCommitment glad_vkGetDeviceMemoryCommitment = NULL;
PFN_vkGetDeviceMemoryOpaqueCaptureAddress glad_vkGetDeviceMemoryOpaqueCaptureAddress = NULL;
PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR glad_vkGetDeviceMemoryOpaqueCaptureAddressKHR = NULL;
PFN_vkGetDeviceProcAddr glad_vkGetDeviceProcAddr = NULL;
PFN_vkGetDeviceQueue glad_vkGetDeviceQueue = NULL;
PFN_vkGetDeviceQueue2 glad_vkGetDeviceQueue2 = NULL;
PFN_vkGetEventStatus glad_vkGetEventStatus = NULL;
PFN_vkGetFenceStatus glad_vkGetFenceStatus = NULL;
PFN_vkGetImageMemoryRequirements glad_vkGetImageMemoryRequirements = NULL;
PFN_vkGetImageMemoryRequirements2 glad_vkGetImageMemoryRequirements2 = NULL;
PFN_vkGetImageMemoryRequirements2KHR glad_vkGetImageMemoryRequirements2KHR = NULL;
PFN_vkGetImageSparseMemoryRequirements glad_vkGetImageSparseMemoryRequirements = NULL;
PFN_vkGetImageSparseMemoryRequirements2 glad_vkGetImageSparseMemoryRequirements2 = NULL;
PFN_vkGetImageSparseMemoryRequirements2KHR glad_vkGetImageSparseMemoryRequirements2KHR = NULL;
PFN_vkGetImageSubresourceLayout glad_vkGetImageSubresourceLayout = NULL;
PFN_vkGetInstanceProcAddr glad_vkGetInstanceProcAddr = NULL;
PFN_vkGetPhysicalDeviceExternalBufferProperties glad_vkGetPhysicalDeviceExternalBufferProperties = NULL;
PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR glad_vkGetPhysicalDeviceExternalBufferPropertiesKHR = NULL;
PFN_vkGetPhysicalDeviceExternalFenceProperties glad_vkGetPhysicalDeviceExternalFenceProperties = NULL;
PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR glad_vkGetPhysicalDeviceExternalFencePropertiesKHR = NULL;
PFN_vkGetPhysicalDeviceExternalSemaphoreProperties glad_vkGetPhysicalDeviceExternalSemaphoreProperties = NULL;
PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR glad_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = NULL;
PFN_vkGetPhysicalDeviceFeatures glad_vkGetPhysicalDeviceFeatures = NULL;
PFN_vkGetPhysicalDeviceFeatures2 glad_vkGetPhysicalDeviceFeatures2 = NULL;
PFN_vkGetPhysicalDeviceFeatures2KHR glad_vkGetPhysicalDeviceFeatures2KHR = NULL;
PFN_vkGetPhysicalDeviceFormatProperties glad_vkGetPhysicalDeviceFormatProperties = NULL;
PFN_vkGetPhysicalDeviceFormatProperties2 glad_vkGetPhysicalDeviceFormatProperties2 = NULL;
PFN_vkGetPhysicalDeviceFormatProperties2KHR glad_vkGetPhysicalDeviceFormatProperties2KHR = NULL;
PFN_vkGetPhysicalDeviceImageFormatProperties glad_vkGetPhysicalDeviceImageFormatProperties = NULL;
PFN_vkGetPhysicalDeviceImageFormatProperties2 glad_vkGetPhysicalDeviceImageFormatProperties2 = NULL;
PFN_vkGetPhysicalDeviceImageFormatProperties2KHR glad_vkGetPhysicalDeviceImageFormatProperties2KHR = NULL;
PFN_vkGetPhysicalDeviceMemoryProperties glad_vkGetPhysicalDeviceMemoryProperties = NULL;
PFN_vkGetPhysicalDeviceMemoryProperties2 glad_vkGetPhysicalDeviceMemoryProperties2 = NULL;
PFN_vkGetPhysicalDeviceMemoryProperties2KHR glad_vkGetPhysicalDeviceMemoryProperties2KHR = NULL;
PFN_vkGetPhysicalDevicePresentRectanglesKHR glad_vkGetPhysicalDevicePresentRectanglesKHR = NULL;
PFN_vkGetPhysicalDeviceProperties glad_vkGetPhysicalDeviceProperties = NULL;
PFN_vkGetPhysicalDeviceProperties2 glad_vkGetPhysicalDeviceProperties2 = NULL;
PFN_vkGetPhysicalDeviceProperties2KHR glad_vkGetPhysicalDeviceProperties2KHR = NULL;
PFN_vkGetPhysicalDeviceQueueFamilyProperties glad_vkGetPhysicalDeviceQueueFamilyProperties = NULL;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2 glad_vkGetPhysicalDeviceQueueFamilyProperties2 = NULL;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR glad_vkGetPhysicalDeviceQueueFamilyProperties2KHR = NULL;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties glad_vkGetPhysicalDeviceSparseImageFormatProperties = NULL;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 glad_vkGetPhysicalDeviceSparseImageFormatProperties2 = NULL;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR glad_vkGetPhysicalDeviceSparseImageFormatProperties2KHR = NULL;
PFN_vkGetPhysicalDeviceToolProperties glad_vkGetPhysicalDeviceToolProperties = NULL;
PFN_vkGetPhysicalDeviceToolPropertiesEXT glad_vkGetPhysicalDeviceToolPropertiesEXT = NULL;
PFN_vkGetPipelineCacheData glad_vkGetPipelineCacheData = NULL;
PFN_vkGetPrivateData glad_vkGetPrivateData = NULL;
PFN_vkGetPrivateDataEXT glad_vkGetPrivateDataEXT = NULL;
PFN_vkGetQueryPoolResults glad_vkGetQueryPoolResults = NULL;
PFN_vkGetQueueCheckpointData2NV glad_vkGetQueueCheckpointData2NV = NULL;
PFN_vkGetRenderAreaGranularity glad_vkGetRenderAreaGranularity = NULL;
PFN_vkGetSemaphoreCounterValue glad_vkGetSemaphoreCounterValue = NULL;
PFN_vkGetSemaphoreCounterValueKHR glad_vkGetSemaphoreCounterValueKHR = NULL;
PFN_vkGetShaderBinaryDataEXT glad_vkGetShaderBinaryDataEXT = NULL;
PFN_vkInvalidateMappedMemoryRanges glad_vkInvalidateMappedMemoryRanges = NULL;
PFN_vkMapMemory glad_vkMapMemory = NULL;
PFN_vkMergePipelineCaches glad_vkMergePipelineCaches = NULL;
PFN_vkQueueBindSparse glad_vkQueueBindSparse = NULL;
PFN_vkQueueSubmit glad_vkQueueSubmit = NULL;
PFN_vkQueueSubmit2 glad_vkQueueSubmit2 = NULL;
PFN_vkQueueSubmit2KHR glad_vkQueueSubmit2KHR = NULL;
PFN_vkQueueWaitIdle glad_vkQueueWaitIdle = NULL;
PFN_vkResetCommandBuffer glad_vkResetCommandBuffer = NULL;
PFN_vkResetCommandPool glad_vkResetCommandPool = NULL;
PFN_vkResetDescriptorPool glad_vkResetDescriptorPool = NULL;
PFN_vkResetEvent glad_vkResetEvent = NULL;
PFN_vkResetFences glad_vkResetFences = NULL;
PFN_vkResetQueryPool glad_vkResetQueryPool = NULL;
PFN_vkResetQueryPoolEXT glad_vkResetQueryPoolEXT = NULL;
PFN_vkSetEvent glad_vkSetEvent = NULL;
PFN_vkSetPrivateData glad_vkSetPrivateData = NULL;
PFN_vkSetPrivateDataEXT glad_vkSetPrivateDataEXT = NULL;
PFN_vkSignalSemaphore glad_vkSignalSemaphore = NULL;
PFN_vkSignalSemaphoreKHR glad_vkSignalSemaphoreKHR = NULL;
PFN_vkTrimCommandPool glad_vkTrimCommandPool = NULL;
PFN_vkTrimCommandPoolKHR glad_vkTrimCommandPoolKHR = NULL;
PFN_vkUnmapMemory glad_vkUnmapMemory = NULL;
PFN_vkUpdateDescriptorSetWithTemplate glad_vkUpdateDescriptorSetWithTemplate = NULL;
PFN_vkUpdateDescriptorSetWithTemplateKHR glad_vkUpdateDescriptorSetWithTemplateKHR = NULL;
PFN_vkUpdateDescriptorSets glad_vkUpdateDescriptorSets = NULL;
PFN_vkWaitForFences glad_vkWaitForFences = NULL;
PFN_vkWaitSemaphores glad_vkWaitSemaphores = NULL;
PFN_vkWaitSemaphoresKHR glad_vkWaitSemaphoresKHR = NULL;


static void glad_vk_load_VK_VERSION_1_0( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_0) return;
    glad_vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers) load(userptr, "vkAllocateCommandBuffers");
    glad_vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets) load(userptr, "vkAllocateDescriptorSets");
    glad_vkAllocateMemory = (PFN_vkAllocateMemory) load(userptr, "vkAllocateMemory");
    glad_vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer) load(userptr, "vkBeginCommandBuffer");
    glad_vkBindBufferMemory = (PFN_vkBindBufferMemory) load(userptr, "vkBindBufferMemory");
    glad_vkBindImageMemory = (PFN_vkBindImageMemory) load(userptr, "vkBindImageMemory");
    glad_vkCmdBeginQuery = (PFN_vkCmdBeginQuery) load(userptr, "vkCmdBeginQuery");
    glad_vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass) load(userptr, "vkCmdBeginRenderPass");
    glad_vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets) load(userptr, "vkCmdBindDescriptorSets");
    glad_vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer) load(userptr, "vkCmdBindIndexBuffer");
    glad_vkCmdBindPipeline = (PFN_vkCmdBindPipeline) load(userptr, "vkCmdBindPipeline");
    glad_vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers) load(userptr, "vkCmdBindVertexBuffers");
    glad_vkCmdBlitImage = (PFN_vkCmdBlitImage) load(userptr, "vkCmdBlitImage");
    glad_vkCmdClearAttachments = (PFN_vkCmdClearAttachments) load(userptr, "vkCmdClearAttachments");
    glad_vkCmdClearColorImage = (PFN_vkCmdClearColorImage) load(userptr, "vkCmdClearColorImage");
    glad_vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage) load(userptr, "vkCmdClearDepthStencilImage");
    glad_vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer) load(userptr, "vkCmdCopyBuffer");
    glad_vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage) load(userptr, "vkCmdCopyBufferToImage");
    glad_vkCmdCopyImage = (PFN_vkCmdCopyImage) load(userptr, "vkCmdCopyImage");
    glad_vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer) load(userptr, "vkCmdCopyImageToBuffer");
    glad_vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults) load(userptr, "vkCmdCopyQueryPoolResults");
    glad_vkCmdDispatch = (PFN_vkCmdDispatch) load(userptr, "vkCmdDispatch");
    glad_vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect) load(userptr, "vkCmdDispatchIndirect");
    glad_vkCmdDraw = (PFN_vkCmdDraw) load(userptr, "vkCmdDraw");
    glad_vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed) load(userptr, "vkCmdDrawIndexed");
    glad_vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect) load(userptr, "vkCmdDrawIndexedIndirect");
    glad_vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect) load(userptr, "vkCmdDrawIndirect");
    glad_vkCmdEndQuery = (PFN_vkCmdEndQuery) load(userptr, "vkCmdEndQuery");
    glad_vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass) load(userptr, "vkCmdEndRenderPass");
    glad_vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands) load(userptr, "vkCmdExecuteCommands");
    glad_vkCmdFillBuffer = (PFN_vkCmdFillBuffer) load(userptr, "vkCmdFillBuffer");
    glad_vkCmdNextSubpass = (PFN_vkCmdNextSubpass) load(userptr, "vkCmdNextSubpass");
    glad_vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier) load(userptr, "vkCmdPipelineBarrier");
    glad_vkCmdPushConstants = (PFN_vkCmdPushConstants) load(userptr, "vkCmdPushConstants");
    glad_vkCmdResetEvent = (PFN_vkCmdResetEvent) load(userptr, "vkCmdResetEvent");
    glad_vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool) load(userptr, "vkCmdResetQueryPool");
    glad_vkCmdResolveImage = (PFN_vkCmdResolveImage) load(userptr, "vkCmdResolveImage");
    glad_vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants) load(userptr, "vkCmdSetBlendConstants");
    glad_vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias) load(userptr, "vkCmdSetDepthBias");
    glad_vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds) load(userptr, "vkCmdSetDepthBounds");
    glad_vkCmdSetEvent = (PFN_vkCmdSetEvent) load(userptr, "vkCmdSetEvent");
    glad_vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth) load(userptr, "vkCmdSetLineWidth");
    glad_vkCmdSetScissor = (PFN_vkCmdSetScissor) load(userptr, "vkCmdSetScissor");
    glad_vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask) load(userptr, "vkCmdSetStencilCompareMask");
    glad_vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference) load(userptr, "vkCmdSetStencilReference");
    glad_vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask) load(userptr, "vkCmdSetStencilWriteMask");
    glad_vkCmdSetViewport = (PFN_vkCmdSetViewport) load(userptr, "vkCmdSetViewport");
    glad_vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer) load(userptr, "vkCmdUpdateBuffer");
    glad_vkCmdWaitEvents = (PFN_vkCmdWaitEvents) load(userptr, "vkCmdWaitEvents");
    glad_vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp) load(userptr, "vkCmdWriteTimestamp");
    glad_vkCreateBuffer = (PFN_vkCreateBuffer) load(userptr, "vkCreateBuffer");
    glad_vkCreateBufferView = (PFN_vkCreateBufferView) load(userptr, "vkCreateBufferView");
    glad_vkCreateCommandPool = (PFN_vkCreateCommandPool) load(userptr, "vkCreateCommandPool");
    glad_vkCreateComputePipelines = (PFN_vkCreateComputePipelines) load(userptr, "vkCreateComputePipelines");
    glad_vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool) load(userptr, "vkCreateDescriptorPool");
    glad_vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout) load(userptr, "vkCreateDescriptorSetLayout");
    glad_vkCreateDevice = (PFN_vkCreateDevice) load(userptr, "vkCreateDevice");
    glad_vkCreateEvent = (PFN_vkCreateEvent) load(userptr, "vkCreateEvent");
    glad_vkCreateFence = (PFN_vkCreateFence) load(userptr, "vkCreateFence");
    glad_vkCreateFramebuffer = (PFN_vkCreateFramebuffer) load(userptr, "vkCreateFramebuffer");
    glad_vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines) load(userptr, "vkCreateGraphicsPipelines");
    glad_vkCreateImage = (PFN_vkCreateImage) load(userptr, "vkCreateImage");
    glad_vkCreateImageView = (PFN_vkCreateImageView) load(userptr, "vkCreateImageView");
    glad_vkCreateInstance = (PFN_vkCreateInstance) load(userptr, "vkCreateInstance");
    glad_vkCreatePipelineCache = (PFN_vkCreatePipelineCache) load(userptr, "vkCreatePipelineCache");
    glad_vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout) load(userptr, "vkCreatePipelineLayout");
    glad_vkCreateQueryPool = (PFN_vkCreateQueryPool) load(userptr, "vkCreateQueryPool");
    glad_vkCreateRenderPass = (PFN_vkCreateRenderPass) load(userptr, "vkCreateRenderPass");
    glad_vkCreateSampler = (PFN_vkCreateSampler) load(userptr, "vkCreateSampler");
    glad_vkCreateSemaphore = (PFN_vkCreateSemaphore) load(userptr, "vkCreateSemaphore");
    glad_vkCreateShaderModule = (PFN_vkCreateShaderModule) load(userptr, "vkCreateShaderModule");
    glad_vkDestroyBuffer = (PFN_vkDestroyBuffer) load(userptr, "vkDestroyBuffer");
    glad_vkDestroyBufferView = (PFN_vkDestroyBufferView) load(userptr, "vkDestroyBufferView");
    glad_vkDestroyCommandPool = (PFN_vkDestroyCommandPool) load(userptr, "vkDestroyCommandPool");
    glad_vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool) load(userptr, "vkDestroyDescriptorPool");
    glad_vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout) load(userptr, "vkDestroyDescriptorSetLayout");
    glad_vkDestroyDevice = (PFN_vkDestroyDevice) load(userptr, "vkDestroyDevice");
    glad_vkDestroyEvent = (PFN_vkDestroyEvent) load(userptr, "vkDestroyEvent");
    glad_vkDestroyFence = (PFN_vkDestroyFence) load(userptr, "vkDestroyFence");
    glad_vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer) load(userptr, "vkDestroyFramebuffer");
    glad_vkDestroyImage = (PFN_vkDestroyImage) load(userptr, "vkDestroyImage");
    glad_vkDestroyImageView = (PFN_vkDestroyImageView) load(userptr, "vkDestroyImageView");
    glad_vkDestroyInstance = (PFN_vkDestroyInstance) load(userptr, "vkDestroyInstance");
    glad_vkDestroyPipeline = (PFN_vkDestroyPipeline) load(userptr, "vkDestroyPipeline");
    glad_vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache) load(userptr, "vkDestroyPipelineCache");
    glad_vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout) load(userptr, "vkDestroyPipelineLayout");
    glad_vkDestroyQueryPool = (PFN_vkDestroyQueryPool) load(userptr, "vkDestroyQueryPool");
    glad_vkDestroyRenderPass = (PFN_vkDestroyRenderPass) load(userptr, "vkDestroyRenderPass");
    glad_vkDestroySampler = (PFN_vkDestroySampler) load(userptr, "vkDestroySampler");
    glad_vkDestroySemaphore = (PFN_vkDestroySemaphore) load(userptr, "vkDestroySemaphore");
    glad_vkDestroyShaderModule = (PFN_vkDestroyShaderModule) load(userptr, "vkDestroyShaderModule");
    glad_vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle) load(userptr, "vkDeviceWaitIdle");
    glad_vkEndCommandBuffer = (PFN_vkEndCommandBuffer) load(userptr, "vkEndCommandBuffer");
    glad_vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties) load(userptr, "vkEnumerateDeviceExtensionProperties");
    glad_vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties) load(userptr, "vkEnumerateDeviceLayerProperties");
    glad_vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties) load(userptr, "vkEnumerateInstanceExtensionProperties");
    glad_vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties) load(userptr, "vkEnumerateInstanceLayerProperties");
    glad_vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices) load(userptr, "vkEnumeratePhysicalDevices");
    glad_vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges) load(userptr, "vkFlushMappedMemoryRanges");
    glad_vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers) load(userptr, "vkFreeCommandBuffers");
    glad_vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets) load(userptr, "vkFreeDescriptorSets");
    glad_vkFreeMemory = (PFN_vkFreeMemory) load(userptr, "vkFreeMemory");
    glad_vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements) load(userptr, "vkGetBufferMemoryRequirements");
    glad_vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment) load(userptr, "vkGetDeviceMemoryCommitment");
    glad_vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr) load(userptr, "vkGetDeviceProcAddr");
    glad_vkGetDeviceQueue = (PFN_vkGetDeviceQueue) load(userptr, "vkGetDeviceQueue");
    glad_vkGetEventStatus = (PFN_vkGetEventStatus) load(userptr, "vkGetEventStatus");
    glad_vkGetFenceStatus = (PFN_vkGetFenceStatus) load(userptr, "vkGetFenceStatus");
    glad_vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements) load(userptr, "vkGetImageMemoryRequirements");
    glad_vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements) load(userptr, "vkGetImageSparseMemoryRequirements");
    glad_vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout) load(userptr, "vkGetImageSubresourceLayout");
    glad_vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr) load(userptr, "vkGetInstanceProcAddr");
    glad_vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures) load(userptr, "vkGetPhysicalDeviceFeatures");
    glad_vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties) load(userptr, "vkGetPhysicalDeviceFormatProperties");
    glad_vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties) load(userptr, "vkGetPhysicalDeviceImageFormatProperties");
    glad_vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties) load(userptr, "vkGetPhysicalDeviceMemoryProperties");
    glad_vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties) load(userptr, "vkGetPhysicalDeviceProperties");
    glad_vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties) load(userptr, "vkGetPhysicalDeviceQueueFamilyProperties");
    glad_vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties) load(userptr, "vkGetPhysicalDeviceSparseImageFormatProperties");
    glad_vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData) load(userptr, "vkGetPipelineCacheData");
    glad_vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults) load(userptr, "vkGetQueryPoolResults");
    glad_vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity) load(userptr, "vkGetRenderAreaGranularity");
    glad_vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges) load(userptr, "vkInvalidateMappedMemoryRanges");
    glad_vkMapMemory = (PFN_vkMapMemory) load(userptr, "vkMapMemory");
    glad_vkMergePipelineCaches = (PFN_vkMergePipelineCaches) load(userptr, "vkMergePipelineCaches");
    glad_vkQueueBindSparse = (PFN_vkQueueBindSparse) load(userptr, "vkQueueBindSparse");
    glad_vkQueueSubmit = (PFN_vkQueueSubmit) load(userptr, "vkQueueSubmit");
    glad_vkQueueWaitIdle = (PFN_vkQueueWaitIdle) load(userptr, "vkQueueWaitIdle");
    glad_vkResetCommandBuffer = (PFN_vkResetCommandBuffer) load(userptr, "vkResetCommandBuffer");
    glad_vkResetCommandPool = (PFN_vkResetCommandPool) load(userptr, "vkResetCommandPool");
    glad_vkResetDescriptorPool = (PFN_vkResetDescriptorPool) load(userptr, "vkResetDescriptorPool");
    glad_vkResetEvent = (PFN_vkResetEvent) load(userptr, "vkResetEvent");
    glad_vkResetFences = (PFN_vkResetFences) load(userptr, "vkResetFences");
    glad_vkSetEvent = (PFN_vkSetEvent) load(userptr, "vkSetEvent");
    glad_vkUnmapMemory = (PFN_vkUnmapMemory) load(userptr, "vkUnmapMemory");
    glad_vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets) load(userptr, "vkUpdateDescriptorSets");
    glad_vkWaitForFences = (PFN_vkWaitForFences) load(userptr, "vkWaitForFences");
}
static void glad_vk_load_VK_VERSION_1_1( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_1) return;
    glad_vkBindBufferMemory2 = (PFN_vkBindBufferMemory2) load(userptr, "vkBindBufferMemory2");
    glad_vkBindImageMemory2 = (PFN_vkBindImageMemory2) load(userptr, "vkBindImageMemory2");
    glad_vkCmdDispatchBase = (PFN_vkCmdDispatchBase) load(userptr, "vkCmdDispatchBase");
    glad_vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask) load(userptr, "vkCmdSetDeviceMask");
    glad_vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate) load(userptr, "vkCreateDescriptorUpdateTemplate");
    glad_vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion) load(userptr, "vkCreateSamplerYcbcrConversion");
    glad_vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate) load(userptr, "vkDestroyDescriptorUpdateTemplate");
    glad_vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion) load(userptr, "vkDestroySamplerYcbcrConversion");
    glad_vkEnumerateInstanceVersion = (PFN_vkEnumerateInstanceVersion) load(userptr, "vkEnumerateInstanceVersion");
    glad_vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups) load(userptr, "vkEnumeratePhysicalDeviceGroups");
    glad_vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2) load(userptr, "vkGetBufferMemoryRequirements2");
    glad_vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport) load(userptr, "vkGetDescriptorSetLayoutSupport");
    glad_vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures) load(userptr, "vkGetDeviceGroupPeerMemoryFeatures");
    glad_vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2) load(userptr, "vkGetDeviceQueue2");
    glad_vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2) load(userptr, "vkGetImageMemoryRequirements2");
    glad_vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2) load(userptr, "vkGetImageSparseMemoryRequirements2");
    glad_vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties) load(userptr, "vkGetPhysicalDeviceExternalBufferProperties");
    glad_vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties) load(userptr, "vkGetPhysicalDeviceExternalFenceProperties");
    glad_vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties) load(userptr, "vkGetPhysicalDeviceExternalSemaphoreProperties");
    glad_vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2) load(userptr, "vkGetPhysicalDeviceFeatures2");
    glad_vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2) load(userptr, "vkGetPhysicalDeviceFormatProperties2");
    glad_vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2) load(userptr, "vkGetPhysicalDeviceImageFormatProperties2");
    glad_vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2) load(userptr, "vkGetPhysicalDeviceMemoryProperties2");
    glad_vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2) load(userptr, "vkGetPhysicalDeviceProperties2");
    glad_vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2) load(userptr, "vkGetPhysicalDeviceQueueFamilyProperties2");
    glad_vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2) load(userptr, "vkGetPhysicalDeviceSparseImageFormatProperties2");
    glad_vkTrimCommandPool = (PFN_vkTrimCommandPool) load(userptr, "vkTrimCommandPool");
    glad_vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate) load(userptr, "vkUpdateDescriptorSetWithTemplate");
}
static void glad_vk_load_VK_VERSION_1_2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_2) return;
    glad_vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2) load(userptr, "vkCmdBeginRenderPass2");
    glad_vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount) load(userptr, "vkCmdDrawIndexedIndirectCount");
    glad_vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount) load(userptr, "vkCmdDrawIndirectCount");
    glad_vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2) load(userptr, "vkCmdEndRenderPass2");
    glad_vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2) load(userptr, "vkCmdNextSubpass2");
    glad_vkCreateRenderPass2 = (PFN_vkCreateRenderPass2) load(userptr, "vkCreateRenderPass2");
    glad_vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress) load(userptr, "vkGetBufferDeviceAddress");
    glad_vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress) load(userptr, "vkGetBufferOpaqueCaptureAddress");
    glad_vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress) load(userptr, "vkGetDeviceMemoryOpaqueCaptureAddress");
    glad_vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue) load(userptr, "vkGetSemaphoreCounterValue");
    glad_vkResetQueryPool = (PFN_vkResetQueryPool) load(userptr, "vkResetQueryPool");
    glad_vkSignalSemaphore = (PFN_vkSignalSemaphore) load(userptr, "vkSignalSemaphore");
    glad_vkWaitSemaphores = (PFN_vkWaitSemaphores) load(userptr, "vkWaitSemaphores");
}
static void glad_vk_load_VK_VERSION_1_3( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_3) return;
    glad_vkCmdBeginRendering = (PFN_vkCmdBeginRendering) load(userptr, "vkCmdBeginRendering");
    glad_vkCmdBindVertexBuffers2 = (PFN_vkCmdBindVertexBuffers2) load(userptr, "vkCmdBindVertexBuffers2");
    glad_vkCmdBlitImage2 = (PFN_vkCmdBlitImage2) load(userptr, "vkCmdBlitImage2");
    glad_vkCmdCopyBuffer2 = (PFN_vkCmdCopyBuffer2) load(userptr, "vkCmdCopyBuffer2");
    glad_vkCmdCopyBufferToImage2 = (PFN_vkCmdCopyBufferToImage2) load(userptr, "vkCmdCopyBufferToImage2");
    glad_vkCmdCopyImage2 = (PFN_vkCmdCopyImage2) load(userptr, "vkCmdCopyImage2");
    glad_vkCmdCopyImageToBuffer2 = (PFN_vkCmdCopyImageToBuffer2) load(userptr, "vkCmdCopyImageToBuffer2");
    glad_vkCmdEndRendering = (PFN_vkCmdEndRendering) load(userptr, "vkCmdEndRendering");
    glad_vkCmdPipelineBarrier2 = (PFN_vkCmdPipelineBarrier2) load(userptr, "vkCmdPipelineBarrier2");
    glad_vkCmdResetEvent2 = (PFN_vkCmdResetEvent2) load(userptr, "vkCmdResetEvent2");
    glad_vkCmdResolveImage2 = (PFN_vkCmdResolveImage2) load(userptr, "vkCmdResolveImage2");
    glad_vkCmdSetCullMode = (PFN_vkCmdSetCullMode) load(userptr, "vkCmdSetCullMode");
    glad_vkCmdSetDepthBiasEnable = (PFN_vkCmdSetDepthBiasEnable) load(userptr, "vkCmdSetDepthBiasEnable");
    glad_vkCmdSetDepthBoundsTestEnable = (PFN_vkCmdSetDepthBoundsTestEnable) load(userptr, "vkCmdSetDepthBoundsTestEnable");
    glad_vkCmdSetDepthCompareOp = (PFN_vkCmdSetDepthCompareOp) load(userptr, "vkCmdSetDepthCompareOp");
    glad_vkCmdSetDepthTestEnable = (PFN_vkCmdSetDepthTestEnable) load(userptr, "vkCmdSetDepthTestEnable");
    glad_vkCmdSetDepthWriteEnable = (PFN_vkCmdSetDepthWriteEnable) load(userptr, "vkCmdSetDepthWriteEnable");
    glad_vkCmdSetEvent2 = (PFN_vkCmdSetEvent2) load(userptr, "vkCmdSetEvent2");
    glad_vkCmdSetFrontFace = (PFN_vkCmdSetFrontFace) load(userptr, "vkCmdSetFrontFace");
    glad_vkCmdSetPrimitiveRestartEnable = (PFN_vkCmdSetPrimitiveRestartEnable) load(userptr, "vkCmdSetPrimitiveRestartEnable");
    glad_vkCmdSetPrimitiveTopology = (PFN_vkCmdSetPrimitiveTopology) load(userptr, "vkCmdSetPrimitiveTopology");
    glad_vkCmdSetRasterizerDiscardEnable = (PFN_vkCmdSetRasterizerDiscardEnable) load(userptr, "vkCmdSetRasterizerDiscardEnable");
    glad_vkCmdSetScissorWithCount = (PFN_vkCmdSetScissorWithCount) load(userptr, "vkCmdSetScissorWithCount");
    glad_vkCmdSetStencilOp = (PFN_vkCmdSetStencilOp) load(userptr, "vkCmdSetStencilOp");
    glad_vkCmdSetStencilTestEnable = (PFN_vkCmdSetStencilTestEnable) load(userptr, "vkCmdSetStencilTestEnable");
    glad_vkCmdSetViewportWithCount = (PFN_vkCmdSetViewportWithCount) load(userptr, "vkCmdSetViewportWithCount");
    glad_vkCmdWaitEvents2 = (PFN_vkCmdWaitEvents2) load(userptr, "vkCmdWaitEvents2");
    glad_vkCmdWriteTimestamp2 = (PFN_vkCmdWriteTimestamp2) load(userptr, "vkCmdWriteTimestamp2");
    glad_vkCreatePrivateDataSlot = (PFN_vkCreatePrivateDataSlot) load(userptr, "vkCreatePrivateDataSlot");
    glad_vkDestroyPrivateDataSlot = (PFN_vkDestroyPrivateDataSlot) load(userptr, "vkDestroyPrivateDataSlot");
    glad_vkGetDeviceBufferMemoryRequirements = (PFN_vkGetDeviceBufferMemoryRequirements) load(userptr, "vkGetDeviceBufferMemoryRequirements");
    glad_vkGetDeviceImageMemoryRequirements = (PFN_vkGetDeviceImageMemoryRequirements) load(userptr, "vkGetDeviceImageMemoryRequirements");
    glad_vkGetDeviceImageSparseMemoryRequirements = (PFN_vkGetDeviceImageSparseMemoryRequirements) load(userptr, "vkGetDeviceImageSparseMemoryRequirements");
    glad_vkGetPhysicalDeviceToolProperties = (PFN_vkGetPhysicalDeviceToolProperties) load(userptr, "vkGetPhysicalDeviceToolProperties");
    glad_vkGetPrivateData = (PFN_vkGetPrivateData) load(userptr, "vkGetPrivateData");
    glad_vkQueueSubmit2 = (PFN_vkQueueSubmit2) load(userptr, "vkQueueSubmit2");
    glad_vkSetPrivateData = (PFN_vkSetPrivateData) load(userptr, "vkSetPrivateData");
}
static void glad_vk_load_VK_AMD_draw_indirect_count( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_AMD_draw_indirect_count) return;
    glad_vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD) load(userptr, "vkCmdDrawIndexedIndirectCountAMD");
    glad_vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD) load(userptr, "vkCmdDrawIndirectCountAMD");
}
static void glad_vk_load_VK_EXT_buffer_device_address( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_buffer_device_address) return;
    glad_vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT) load(userptr, "vkGetBufferDeviceAddressEXT");
}
static void glad_vk_load_VK_EXT_extended_dynamic_state( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_extended_dynamic_state) return;
    glad_vkCmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT) load(userptr, "vkCmdBindVertexBuffers2EXT");
    glad_vkCmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT) load(userptr, "vkCmdSetCullModeEXT");
    glad_vkCmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT) load(userptr, "vkCmdSetDepthBoundsTestEnableEXT");
    glad_vkCmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT) load(userptr, "vkCmdSetDepthCompareOpEXT");
    glad_vkCmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT) load(userptr, "vkCmdSetDepthTestEnableEXT");
    glad_vkCmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT) load(userptr, "vkCmdSetDepthWriteEnableEXT");
    glad_vkCmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT) load(userptr, "vkCmdSetFrontFaceEXT");
    glad_vkCmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT) load(userptr, "vkCmdSetPrimitiveTopologyEXT");
    glad_vkCmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT) load(userptr, "vkCmdSetScissorWithCountEXT");
    glad_vkCmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT) load(userptr, "vkCmdSetStencilOpEXT");
    glad_vkCmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT) load(userptr, "vkCmdSetStencilTestEnableEXT");
    glad_vkCmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT) load(userptr, "vkCmdSetViewportWithCountEXT");
}
static void glad_vk_load_VK_EXT_extended_dynamic_state2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_extended_dynamic_state2) return;
    glad_vkCmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT) load(userptr, "vkCmdSetDepthBiasEnableEXT");
    glad_vkCmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT) load(userptr, "vkCmdSetLogicOpEXT");
    glad_vkCmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT) load(userptr, "vkCmdSetPatchControlPointsEXT");
    glad_vkCmdSetPrimitiveRestartEnableEXT = (PFN_vkCmdSetPrimitiveRestartEnableEXT) load(userptr, "vkCmdSetPrimitiveRestartEnableEXT");
    glad_vkCmdSetRasterizerDiscardEnableEXT = (PFN_vkCmdSetRasterizerDiscardEnableEXT) load(userptr, "vkCmdSetRasterizerDiscardEnableEXT");
}
static void glad_vk_load_VK_EXT_host_query_reset( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_host_query_reset) return;
    glad_vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT) load(userptr, "vkResetQueryPoolEXT");
}
static void glad_vk_load_VK_EXT_private_data( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_private_data) return;
    glad_vkCreatePrivateDataSlotEXT = (PFN_vkCreatePrivateDataSlotEXT) load(userptr, "vkCreatePrivateDataSlotEXT");
    glad_vkDestroyPrivateDataSlotEXT = (PFN_vkDestroyPrivateDataSlotEXT) load(userptr, "vkDestroyPrivateDataSlotEXT");
    glad_vkGetPrivateDataEXT = (PFN_vkGetPrivateDataEXT) load(userptr, "vkGetPrivateDataEXT");
    glad_vkSetPrivateDataEXT = (PFN_vkSetPrivateDataEXT) load(userptr, "vkSetPrivateDataEXT");
}
static void glad_vk_load_VK_EXT_shader_object( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_shader_object) return;
    glad_vkCmdBindShadersEXT = (PFN_vkCmdBindShadersEXT) load(userptr, "vkCmdBindShadersEXT");
    glad_vkCmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT) load(userptr, "vkCmdBindVertexBuffers2EXT");
    glad_vkCmdSetAlphaToCoverageEnableEXT = (PFN_vkCmdSetAlphaToCoverageEnableEXT) load(userptr, "vkCmdSetAlphaToCoverageEnableEXT");
    glad_vkCmdSetAlphaToOneEnableEXT = (PFN_vkCmdSetAlphaToOneEnableEXT) load(userptr, "vkCmdSetAlphaToOneEnableEXT");
    glad_vkCmdSetColorBlendAdvancedEXT = (PFN_vkCmdSetColorBlendAdvancedEXT) load(userptr, "vkCmdSetColorBlendAdvancedEXT");
    glad_vkCmdSetColorBlendEnableEXT = (PFN_vkCmdSetColorBlendEnableEXT) load(userptr, "vkCmdSetColorBlendEnableEXT");
    glad_vkCmdSetColorBlendEquationEXT = (PFN_vkCmdSetColorBlendEquationEXT) load(userptr, "vkCmdSetColorBlendEquationEXT");
    glad_vkCmdSetColorWriteMaskEXT = (PFN_vkCmdSetColorWriteMaskEXT) load(userptr, "vkCmdSetColorWriteMaskEXT");
    glad_vkCmdSetConservativeRasterizationModeEXT = (PFN_vkCmdSetConservativeRasterizationModeEXT) load(userptr, "vkCmdSetConservativeRasterizationModeEXT");
    glad_vkCmdSetCoverageModulationModeNV = (PFN_vkCmdSetCoverageModulationModeNV) load(userptr, "vkCmdSetCoverageModulationModeNV");
    glad_vkCmdSetCoverageModulationTableEnableNV = (PFN_vkCmdSetCoverageModulationTableEnableNV) load(userptr, "vkCmdSetCoverageModulationTableEnableNV");
    glad_vkCmdSetCoverageModulationTableNV = (PFN_vkCmdSetCoverageModulationTableNV) load(userptr, "vkCmdSetCoverageModulationTableNV");
    glad_vkCmdSetCoverageReductionModeNV = (PFN_vkCmdSetCoverageReductionModeNV) load(userptr, "vkCmdSetCoverageReductionModeNV");
    glad_vkCmdSetCoverageToColorEnableNV = (PFN_vkCmdSetCoverageToColorEnableNV) load(userptr, "vkCmdSetCoverageToColorEnableNV");
    glad_vkCmdSetCoverageToColorLocationNV = (PFN_vkCmdSetCoverageToColorLocationNV) load(userptr, "vkCmdSetCoverageToColorLocationNV");
    glad_vkCmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT) load(userptr, "vkCmdSetCullModeEXT");
    glad_vkCmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT) load(userptr, "vkCmdSetDepthBiasEnableEXT");
    glad_vkCmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT) load(userptr, "vkCmdSetDepthBoundsTestEnableEXT");
    glad_vkCmdSetDepthClampEnableEXT = (PFN_vkCmdSetDepthClampEnableEXT) load(userptr, "vkCmdSetDepthClampEnableEXT");
    glad_vkCmdSetDepthClipEnableEXT = (PFN_vkCmdSetDepthClipEnableEXT) load(userptr, "vkCmdSetDepthClipEnableEXT");
    glad_vkCmdSetDepthClipNegativeOneToOneEXT = (PFN_vkCmdSetDepthClipNegativeOneToOneEXT) load(userptr, "vkCmdSetDepthClipNegativeOneToOneEXT");
    glad_vkCmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT) load(userptr, "vkCmdSetDepthCompareOpEXT");
    glad_vkCmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT) load(userptr, "vkCmdSetDepthTestEnableEXT");
    glad_vkCmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT) load(userptr, "vkCmdSetDepthWriteEnableEXT");
    glad_vkCmdSetExtraPrimitiveOverestimationSizeEXT = (PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT) load(userptr, "vkCmdSetExtraPrimitiveOverestimationSizeEXT");
    glad_vkCmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT) load(userptr, "vkCmdSetFrontFaceEXT");
    glad_vkCmdSetLineRasterizationModeEXT = (PFN_vkCmdSetLineRasterizationModeEXT) load(userptr, "vkCmdSetLineRasterizationModeEXT");
    glad_vkCmdSetLineStippleEnableEXT = (PFN_vkCmdSetLineStippleEnableEXT) load(userptr, "vkCmdSetLineStippleEnableEXT");
    glad_vkCmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT) load(userptr, "vkCmdSetLogicOpEXT");
    glad_vkCmdSetLogicOpEnableEXT = (PFN_vkCmdSetLogicOpEnableEXT) load(userptr, "vkCmdSetLogicOpEnableEXT");
    glad_vkCmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT) load(userptr, "vkCmdSetPatchControlPointsEXT");
    glad_vkCmdSetPolygonModeEXT = (PFN_vkCmdSetPolygonModeEXT) load(userptr, "vkCmdSetPolygonModeEXT");
    glad_vkCmdSetPrimitiveRestartEnableEXT = (PFN_vkCmdSetPrimitiveRestartEnableEXT) load(userptr, "vkCmdSetPrimitiveRestartEnableEXT");
    glad_vkCmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT) load(userptr, "vkCmdSetPrimitiveTopologyEXT");
    glad_vkCmdSetProvokingVertexModeEXT = (PFN_vkCmdSetProvokingVertexModeEXT) load(userptr, "vkCmdSetProvokingVertexModeEXT");
    glad_vkCmdSetRasterizationSamplesEXT = (PFN_vkCmdSetRasterizationSamplesEXT) load(userptr, "vkCmdSetRasterizationSamplesEXT");
    glad_vkCmdSetRasterizationStreamEXT = (PFN_vkCmdSetRasterizationStreamEXT) load(userptr, "vkCmdSetRasterizationStreamEXT");
    glad_vkCmdSetRasterizerDiscardEnableEXT = (PFN_vkCmdSetRasterizerDiscardEnableEXT) load(userptr, "vkCmdSetRasterizerDiscardEnableEXT");
    glad_vkCmdSetRepresentativeFragmentTestEnableNV = (PFN_vkCmdSetRepresentativeFragmentTestEnableNV) load(userptr, "vkCmdSetRepresentativeFragmentTestEnableNV");
    glad_vkCmdSetSampleLocationsEnableEXT = (PFN_vkCmdSetSampleLocationsEnableEXT) load(userptr, "vkCmdSetSampleLocationsEnableEXT");
    glad_vkCmdSetSampleMaskEXT = (PFN_vkCmdSetSampleMaskEXT) load(userptr, "vkCmdSetSampleMaskEXT");
    glad_vkCmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT) load(userptr, "vkCmdSetScissorWithCountEXT");
    glad_vkCmdSetShadingRateImageEnableNV = (PFN_vkCmdSetShadingRateImageEnableNV) load(userptr, "vkCmdSetShadingRateImageEnableNV");
    glad_vkCmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT) load(userptr, "vkCmdSetStencilOpEXT");
    glad_vkCmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT) load(userptr, "vkCmdSetStencilTestEnableEXT");
    glad_vkCmdSetTessellationDomainOriginEXT = (PFN_vkCmdSetTessellationDomainOriginEXT) load(userptr, "vkCmdSetTessellationDomainOriginEXT");
    glad_vkCmdSetVertexInputEXT = (PFN_vkCmdSetVertexInputEXT) load(userptr, "vkCmdSetVertexInputEXT");
    glad_vkCmdSetViewportSwizzleNV = (PFN_vkCmdSetViewportSwizzleNV) load(userptr, "vkCmdSetViewportSwizzleNV");
    glad_vkCmdSetViewportWScalingEnableNV = (PFN_vkCmdSetViewportWScalingEnableNV) load(userptr, "vkCmdSetViewportWScalingEnableNV");
    glad_vkCmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT) load(userptr, "vkCmdSetViewportWithCountEXT");
    glad_vkCreateShadersEXT = (PFN_vkCreateShadersEXT) load(userptr, "vkCreateShadersEXT");
    glad_vkDestroyShaderEXT = (PFN_vkDestroyShaderEXT) load(userptr, "vkDestroyShaderEXT");
    glad_vkGetShaderBinaryDataEXT = (PFN_vkGetShaderBinaryDataEXT) load(userptr, "vkGetShaderBinaryDataEXT");
}
static void glad_vk_load_VK_EXT_tooling_info( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_tooling_info) return;
    glad_vkGetPhysicalDeviceToolPropertiesEXT = (PFN_vkGetPhysicalDeviceToolPropertiesEXT) load(userptr, "vkGetPhysicalDeviceToolPropertiesEXT");
}
static void glad_vk_load_VK_KHR_bind_memory2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_bind_memory2) return;
    glad_vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR) load(userptr, "vkBindBufferMemory2KHR");
    glad_vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR) load(userptr, "vkBindImageMemory2KHR");
}
static void glad_vk_load_VK_KHR_buffer_device_address( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_buffer_device_address) return;
    glad_vkGetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR) load(userptr, "vkGetBufferDeviceAddressKHR");
    glad_vkGetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR) load(userptr, "vkGetBufferOpaqueCaptureAddressKHR");
    glad_vkGetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR) load(userptr, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
}
static void glad_vk_load_VK_KHR_copy_commands2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_copy_commands2) return;
    glad_vkCmdBlitImage2KHR = (PFN_vkCmdBlitImage2KHR) load(userptr, "vkCmdBlitImage2KHR");
    glad_vkCmdCopyBuffer2KHR = (PFN_vkCmdCopyBuffer2KHR) load(userptr, "vkCmdCopyBuffer2KHR");
    glad_vkCmdCopyBufferToImage2KHR = (PFN_vkCmdCopyBufferToImage2KHR) load(userptr, "vkCmdCopyBufferToImage2KHR");
    glad_vkCmdCopyImage2KHR = (PFN_vkCmdCopyImage2KHR) load(userptr, "vkCmdCopyImage2KHR");
    glad_vkCmdCopyImageToBuffer2KHR = (PFN_vkCmdCopyImageToBuffer2KHR) load(userptr, "vkCmdCopyImageToBuffer2KHR");
    glad_vkCmdResolveImage2KHR = (PFN_vkCmdResolveImage2KHR) load(userptr, "vkCmdResolveImage2KHR");
}
static void glad_vk_load_VK_KHR_create_renderpass2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_create_renderpass2) return;
    glad_vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR) load(userptr, "vkCmdBeginRenderPass2KHR");
    glad_vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR) load(userptr, "vkCmdEndRenderPass2KHR");
    glad_vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR) load(userptr, "vkCmdNextSubpass2KHR");
    glad_vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR) load(userptr, "vkCreateRenderPass2KHR");
}
static void glad_vk_load_VK_KHR_descriptor_update_template( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_descriptor_update_template) return;
    glad_vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR) load(userptr, "vkCmdPushDescriptorSetWithTemplateKHR");
    glad_vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR) load(userptr, "vkCreateDescriptorUpdateTemplateKHR");
    glad_vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR) load(userptr, "vkDestroyDescriptorUpdateTemplateKHR");
    glad_vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR) load(userptr, "vkUpdateDescriptorSetWithTemplateKHR");
}
static void glad_vk_load_VK_KHR_device_group( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_device_group) return;
    glad_vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR) load(userptr, "vkAcquireNextImage2KHR");
    glad_vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR) load(userptr, "vkCmdDispatchBaseKHR");
    glad_vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR) load(userptr, "vkCmdSetDeviceMaskKHR");
    glad_vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR) load(userptr, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
    glad_vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR) load(userptr, "vkGetDeviceGroupPresentCapabilitiesKHR");
    glad_vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR) load(userptr, "vkGetDeviceGroupSurfacePresentModesKHR");
    glad_vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR) load(userptr, "vkGetPhysicalDevicePresentRectanglesKHR");
}
static void glad_vk_load_VK_KHR_device_group_creation( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_device_group_creation) return;
    glad_vkEnumeratePhysicalDeviceGroupsKHR = (PFN_vkEnumeratePhysicalDeviceGroupsKHR) load(userptr, "vkEnumeratePhysicalDeviceGroupsKHR");
}
static void glad_vk_load_VK_KHR_draw_indirect_count( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_draw_indirect_count) return;
    glad_vkCmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR) load(userptr, "vkCmdDrawIndexedIndirectCountKHR");
    glad_vkCmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR) load(userptr, "vkCmdDrawIndirectCountKHR");
}
static void glad_vk_load_VK_KHR_dynamic_rendering( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_dynamic_rendering) return;
    glad_vkCmdBeginRenderingKHR = (PFN_vkCmdBeginRenderingKHR) load(userptr, "vkCmdBeginRenderingKHR");
    glad_vkCmdEndRenderingKHR = (PFN_vkCmdEndRenderingKHR) load(userptr, "vkCmdEndRenderingKHR");
}
static void glad_vk_load_VK_KHR_external_fence_capabilities( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_fence_capabilities) return;
    glad_vkGetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR) load(userptr, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
}
static void glad_vk_load_VK_KHR_external_memory_capabilities( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_memory_capabilities) return;
    glad_vkGetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR) load(userptr, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
}
static void glad_vk_load_VK_KHR_external_semaphore_capabilities( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_semaphore_capabilities) return;
    glad_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR) load(userptr, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
}
static void glad_vk_load_VK_KHR_get_memory_requirements2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_get_memory_requirements2) return;
    glad_vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR) load(userptr, "vkGetBufferMemoryRequirements2KHR");
    glad_vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR) load(userptr, "vkGetImageMemoryRequirements2KHR");
    glad_vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR) load(userptr, "vkGetImageSparseMemoryRequirements2KHR");
}
static void glad_vk_load_VK_KHR_get_physical_device_properties2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_get_physical_device_properties2) return;
    glad_vkGetPhysicalDeviceFeatures2KHR = (PFN_vkGetPhysicalDeviceFeatures2KHR) load(userptr, "vkGetPhysicalDeviceFeatures2KHR");
    glad_vkGetPhysicalDeviceFormatProperties2KHR = (PFN_vkGetPhysicalDeviceFormatProperties2KHR) load(userptr, "vkGetPhysicalDeviceFormatProperties2KHR");
    glad_vkGetPhysicalDeviceImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR) load(userptr, "vkGetPhysicalDeviceImageFormatProperties2KHR");
    glad_vkGetPhysicalDeviceMemoryProperties2KHR = (PFN_vkGetPhysicalDeviceMemoryProperties2KHR) load(userptr, "vkGetPhysicalDeviceMemoryProperties2KHR");
    glad_vkGetPhysicalDeviceProperties2KHR = (PFN_vkGetPhysicalDeviceProperties2KHR) load(userptr, "vkGetPhysicalDeviceProperties2KHR");
    glad_vkGetPhysicalDeviceQueueFamilyProperties2KHR = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR) load(userptr, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
    glad_vkGetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR) load(userptr, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
}
static void glad_vk_load_VK_KHR_maintenance1( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_maintenance1) return;
    glad_vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR) load(userptr, "vkTrimCommandPoolKHR");
}
static void glad_vk_load_VK_KHR_maintenance3( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_maintenance3) return;
    glad_vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR) load(userptr, "vkGetDescriptorSetLayoutSupportKHR");
}
static void glad_vk_load_VK_KHR_maintenance4( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_maintenance4) return;
    glad_vkGetDeviceBufferMemoryRequirementsKHR = (PFN_vkGetDeviceBufferMemoryRequirementsKHR) load(userptr, "vkGetDeviceBufferMemoryRequirementsKHR");
    glad_vkGetDeviceImageMemoryRequirementsKHR = (PFN_vkGetDeviceImageMemoryRequirementsKHR) load(userptr, "vkGetDeviceImageMemoryRequirementsKHR");
    glad_vkGetDeviceImageSparseMemoryRequirementsKHR = (PFN_vkGetDeviceImageSparseMemoryRequirementsKHR) load(userptr, "vkGetDeviceImageSparseMemoryRequirementsKHR");
}
static void glad_vk_load_VK_KHR_sampler_ycbcr_conversion( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_sampler_ycbcr_conversion) return;
    glad_vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR) load(userptr, "vkCreateSamplerYcbcrConversionKHR");
    glad_vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR) load(userptr, "vkDestroySamplerYcbcrConversionKHR");
}
static void glad_vk_load_VK_KHR_synchronization2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_synchronization2) return;
    glad_vkCmdPipelineBarrier2KHR = (PFN_vkCmdPipelineBarrier2KHR) load(userptr, "vkCmdPipelineBarrier2KHR");
    glad_vkCmdResetEvent2KHR = (PFN_vkCmdResetEvent2KHR) load(userptr, "vkCmdResetEvent2KHR");
    glad_vkCmdSetEvent2KHR = (PFN_vkCmdSetEvent2KHR) load(userptr, "vkCmdSetEvent2KHR");
    glad_vkCmdWaitEvents2KHR = (PFN_vkCmdWaitEvents2KHR) load(userptr, "vkCmdWaitEvents2KHR");
    glad_vkCmdWriteBufferMarker2AMD = (PFN_vkCmdWriteBufferMarker2AMD) load(userptr, "vkCmdWriteBufferMarker2AMD");
    glad_vkCmdWriteTimestamp2KHR = (PFN_vkCmdWriteTimestamp2KHR) load(userptr, "vkCmdWriteTimestamp2KHR");
    glad_vkGetQueueCheckpointData2NV = (PFN_vkGetQueueCheckpointData2NV) load(userptr, "vkGetQueueCheckpointData2NV");
    glad_vkQueueSubmit2KHR = (PFN_vkQueueSubmit2KHR) load(userptr, "vkQueueSubmit2KHR");
}
static void glad_vk_load_VK_KHR_timeline_semaphore( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_timeline_semaphore) return;
    glad_vkGetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR) load(userptr, "vkGetSemaphoreCounterValueKHR");
    glad_vkSignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR) load(userptr, "vkSignalSemaphoreKHR");
    glad_vkWaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR) load(userptr, "vkWaitSemaphoresKHR");
}


static void glad_vk_resolve_aliases(void) {
    if (glad_vkBindBufferMemory2 == NULL && glad_vkBindBufferMemory2KHR != NULL) glad_vkBindBufferMemory2 = (PFN_vkBindBufferMemory2)glad_vkBindBufferMemory2KHR;
    if (glad_vkBindBufferMemory2KHR == NULL && glad_vkBindBufferMemory2 != NULL) glad_vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)glad_vkBindBufferMemory2;
    if (glad_vkBindImageMemory2 == NULL && glad_vkBindImageMemory2KHR != NULL) glad_vkBindImageMemory2 = (PFN_vkBindImageMemory2)glad_vkBindImageMemory2KHR;
    if (glad_vkBindImageMemory2KHR == NULL && glad_vkBindImageMemory2 != NULL) glad_vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)glad_vkBindImageMemory2;
    if (glad_vkCmdBeginRendering == NULL && glad_vkCmdBeginRenderingKHR != NULL) glad_vkCmdBeginRendering = (PFN_vkCmdBeginRendering)glad_vkCmdBeginRenderingKHR;
    if (glad_vkCmdBeginRenderingKHR == NULL && glad_vkCmdBeginRendering != NULL) glad_vkCmdBeginRenderingKHR = (PFN_vkCmdBeginRenderingKHR)glad_vkCmdBeginRendering;
    if (glad_vkCmdBeginRenderPass2 == NULL && glad_vkCmdBeginRenderPass2KHR != NULL) glad_vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2)glad_vkCmdBeginRenderPass2KHR;
    if (glad_vkCmdBeginRenderPass2KHR == NULL && glad_vkCmdBeginRenderPass2 != NULL) glad_vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)glad_vkCmdBeginRenderPass2;
    if (glad_vkCmdBindVertexBuffers2 == NULL && glad_vkCmdBindVertexBuffers2EXT != NULL) glad_vkCmdBindVertexBuffers2 = (PFN_vkCmdBindVertexBuffers2)glad_vkCmdBindVertexBuffers2EXT;
    if (glad_vkCmdBindVertexBuffers2EXT == NULL && glad_vkCmdBindVertexBuffers2 != NULL) glad_vkCmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT)glad_vkCmdBindVertexBuffers2;
    if (glad_vkCmdBlitImage2 == NULL && glad_vkCmdBlitImage2KHR != NULL) glad_vkCmdBlitImage2 = (PFN_vkCmdBlitImage2)glad_vkCmdBlitImage2KHR;
    if (glad_vkCmdBlitImage2KHR == NULL && glad_vkCmdBlitImage2 != NULL) glad_vkCmdBlitImage2KHR = (PFN_vkCmdBlitImage2KHR)glad_vkCmdBlitImage2;
    if (glad_vkCmdCopyBuffer2 == NULL && glad_vkCmdCopyBuffer2KHR != NULL) glad_vkCmdCopyBuffer2 = (PFN_vkCmdCopyBuffer2)glad_vkCmdCopyBuffer2KHR;
    if (glad_vkCmdCopyBuffer2KHR == NULL && glad_vkCmdCopyBuffer2 != NULL) glad_vkCmdCopyBuffer2KHR = (PFN_vkCmdCopyBuffer2KHR)glad_vkCmdCopyBuffer2;
    if (glad_vkCmdCopyBufferToImage2 == NULL && glad_vkCmdCopyBufferToImage2KHR != NULL) glad_vkCmdCopyBufferToImage2 = (PFN_vkCmdCopyBufferToImage2)glad_vkCmdCopyBufferToImage2KHR;
    if (glad_vkCmdCopyBufferToImage2KHR == NULL && glad_vkCmdCopyBufferToImage2 != NULL) glad_vkCmdCopyBufferToImage2KHR = (PFN_vkCmdCopyBufferToImage2KHR)glad_vkCmdCopyBufferToImage2;
    if (glad_vkCmdCopyImage2 == NULL && glad_vkCmdCopyImage2KHR != NULL) glad_vkCmdCopyImage2 = (PFN_vkCmdCopyImage2)glad_vkCmdCopyImage2KHR;
    if (glad_vkCmdCopyImage2KHR == NULL && glad_vkCmdCopyImage2 != NULL) glad_vkCmdCopyImage2KHR = (PFN_vkCmdCopyImage2KHR)glad_vkCmdCopyImage2;
    if (glad_vkCmdCopyImageToBuffer2 == NULL && glad_vkCmdCopyImageToBuffer2KHR != NULL) glad_vkCmdCopyImageToBuffer2 = (PFN_vkCmdCopyImageToBuffer2)glad_vkCmdCopyImageToBuffer2KHR;
    if (glad_vkCmdCopyImageToBuffer2KHR == NULL && glad_vkCmdCopyImageToBuffer2 != NULL) glad_vkCmdCopyImageToBuffer2KHR = (PFN_vkCmdCopyImageToBuffer2KHR)glad_vkCmdCopyImageToBuffer2;
    if (glad_vkCmdDispatchBase == NULL && glad_vkCmdDispatchBaseKHR != NULL) glad_vkCmdDispatchBase = (PFN_vkCmdDispatchBase)glad_vkCmdDispatchBaseKHR;
    if (glad_vkCmdDispatchBaseKHR == NULL && glad_vkCmdDispatchBase != NULL) glad_vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)glad_vkCmdDispatchBase;
    if (glad_vkCmdDrawIndexedIndirectCount == NULL && glad_vkCmdDrawIndexedIndirectCountAMD != NULL) glad_vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)glad_vkCmdDrawIndexedIndirectCountAMD;
    if (glad_vkCmdDrawIndexedIndirectCount == NULL && glad_vkCmdDrawIndexedIndirectCountKHR != NULL) glad_vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)glad_vkCmdDrawIndexedIndirectCountKHR;
    if (glad_vkCmdDrawIndexedIndirectCountAMD == NULL && glad_vkCmdDrawIndexedIndirectCount != NULL) glad_vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)glad_vkCmdDrawIndexedIndirectCount;
    if (glad_vkCmdDrawIndexedIndirectCountAMD == NULL && glad_vkCmdDrawIndexedIndirectCountKHR != NULL) glad_vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)glad_vkCmdDrawIndexedIndirectCountKHR;
    if (glad_vkCmdDrawIndexedIndirectCountKHR == NULL && glad_vkCmdDrawIndexedIndirectCount != NULL) glad_vkCmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR)glad_vkCmdDrawIndexedIndirectCount;
    if (glad_vkCmdDrawIndexedIndirectCountKHR == NULL && glad_vkCmdDrawIndexedIndirectCountAMD != NULL) glad_vkCmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR)glad_vkCmdDrawIndexedIndirectCountAMD;
    if (glad_vkCmdDrawIndirectCount == NULL && glad_vkCmdDrawIndirectCountAMD != NULL) glad_vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)glad_vkCmdDrawIndirectCountAMD;
    if (glad_vkCmdDrawIndirectCount == NULL && glad_vkCmdDrawIndirectCountKHR != NULL) glad_vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)glad_vkCmdDrawIndirectCountKHR;
    if (glad_vkCmdDrawIndirectCountAMD == NULL && glad_vkCmdDrawIndirectCount != NULL) glad_vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)glad_vkCmdDrawIndirectCount;
    if (glad_vkCmdDrawIndirectCountAMD == NULL && glad_vkCmdDrawIndirectCountKHR != NULL) glad_vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)glad_vkCmdDrawIndirectCountKHR;
    if (glad_vkCmdDrawIndirectCountKHR == NULL && glad_vkCmdDrawIndirectCount != NULL) glad_vkCmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR)glad_vkCmdDrawIndirectCount;
    if (glad_vkCmdDrawIndirectCountKHR == NULL && glad_vkCmdDrawIndirectCountAMD != NULL) glad_vkCmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR)glad_vkCmdDrawIndirectCountAMD;
    if (glad_vkCmdEndRendering == NULL && glad_vkCmdEndRenderingKHR != NULL) glad_vkCmdEndRendering = (PFN_vkCmdEndRendering)glad_vkCmdEndRenderingKHR;
    if (glad_vkCmdEndRenderingKHR == NULL && glad_vkCmdEndRendering != NULL) glad_vkCmdEndRenderingKHR = (PFN_vkCmdEndRenderingKHR)glad_vkCmdEndRendering;
    if (glad_vkCmdEndRenderPass2 == NULL && glad_vkCmdEndRenderPass2KHR != NULL) glad_vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2)glad_vkCmdEndRenderPass2KHR;
    if (glad_vkCmdEndRenderPass2KHR == NULL && glad_vkCmdEndRenderPass2 != NULL) glad_vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)glad_vkCmdEndRenderPass2;
    if (glad_vkCmdNextSubpass2 == NULL && glad_vkCmdNextSubpass2KHR != NULL) glad_vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2)glad_vkCmdNextSubpass2KHR;
    if (glad_vkCmdNextSubpass2KHR == NULL && glad_vkCmdNextSubpass2 != NULL) glad_vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)glad_vkCmdNextSubpass2;
    if (glad_vkCmdPipelineBarrier2 == NULL && glad_vkCmdPipelineBarrier2KHR != NULL) glad_vkCmdPipelineBarrier2 = (PFN_vkCmdPipelineBarrier2)glad_vkCmdPipelineBarrier2KHR;
    if (glad_vkCmdPipelineBarrier2KHR == NULL && glad_vkCmdPipelineBarrier2 != NULL) glad_vkCmdPipelineBarrier2KHR = (PFN_vkCmdPipelineBarrier2KHR)glad_vkCmdPipelineBarrier2;
    if (glad_vkCmdResetEvent2 == NULL && glad_vkCmdResetEvent2KHR != NULL) glad_vkCmdResetEvent2 = (PFN_vkCmdResetEvent2)glad_vkCmdResetEvent2KHR;
    if (glad_vkCmdResetEvent2KHR == NULL && glad_vkCmdResetEvent2 != NULL) glad_vkCmdResetEvent2KHR = (PFN_vkCmdResetEvent2KHR)glad_vkCmdResetEvent2;
    if (glad_vkCmdResolveImage2 == NULL && glad_vkCmdResolveImage2KHR != NULL) glad_vkCmdResolveImage2 = (PFN_vkCmdResolveImage2)glad_vkCmdResolveImage2KHR;
    if (glad_vkCmdResolveImage2KHR == NULL && glad_vkCmdResolveImage2 != NULL) glad_vkCmdResolveImage2KHR = (PFN_vkCmdResolveImage2KHR)glad_vkCmdResolveImage2;
    if (glad_vkCmdSetCullMode == NULL && glad_vkCmdSetCullModeEXT != NULL) glad_vkCmdSetCullMode = (PFN_vkCmdSetCullMode)glad_vkCmdSetCullModeEXT;
    if (glad_vkCmdSetCullModeEXT == NULL && glad_vkCmdSetCullMode != NULL) glad_vkCmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT)glad_vkCmdSetCullMode;
    if (glad_vkCmdSetDepthBiasEnable == NULL && glad_vkCmdSetDepthBiasEnableEXT != NULL) glad_vkCmdSetDepthBiasEnable = (PFN_vkCmdSetDepthBiasEnable)glad_vkCmdSetDepthBiasEnableEXT;
    if (glad_vkCmdSetDepthBiasEnableEXT == NULL && glad_vkCmdSetDepthBiasEnable != NULL) glad_vkCmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT)glad_vkCmdSetDepthBiasEnable;
    if (glad_vkCmdSetDepthBoundsTestEnable == NULL && glad_vkCmdSetDepthBoundsTestEnableEXT != NULL) glad_vkCmdSetDepthBoundsTestEnable = (PFN_vkCmdSetDepthBoundsTestEnable)glad_vkCmdSetDepthBoundsTestEnableEXT;
    if (glad_vkCmdSetDepthBoundsTestEnableEXT == NULL && glad_vkCmdSetDepthBoundsTestEnable != NULL) glad_vkCmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT)glad_vkCmdSetDepthBoundsTestEnable;
    if (glad_vkCmdSetDepthCompareOp == NULL && glad_vkCmdSetDepthCompareOpEXT != NULL) glad_vkCmdSetDepthCompareOp = (PFN_vkCmdSetDepthCompareOp)glad_vkCmdSetDepthCompareOpEXT;
    if (glad_vkCmdSetDepthCompareOpEXT == NULL && glad_vkCmdSetDepthCompareOp != NULL) glad_vkCmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT)glad_vkCmdSetDepthCompareOp;
    if (glad_vkCmdSetDepthTestEnable == NULL && glad_vkCmdSetDepthTestEnableEXT != NULL) glad_vkCmdSetDepthTestEnable = (PFN_vkCmdSetDepthTestEnable)glad_vkCmdSetDepthTestEnableEXT;
    if (glad_vkCmdSetDepthTestEnableEXT == NULL && glad_vkCmdSetDepthTestEnable != NULL) glad_vkCmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT)glad_vkCmdSetDepthTestEnable;
    if (glad_vkCmdSetDepthWriteEnable == NULL && glad_vkCmdSetDepthWriteEnableEXT != NULL) glad_vkCmdSetDepthWriteEnable = (PFN_vkCmdSetDepthWriteEnable)glad_vkCmdSetDepthWriteEnableEXT;
    if (glad_vkCmdSetDepthWriteEnableEXT == NULL && glad_vkCmdSetDepthWriteEnable != NULL) glad_vkCmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT)glad_vkCmdSetDepthWriteEnable;
    if (glad_vkCmdSetDeviceMask == NULL && glad_vkCmdSetDeviceMaskKHR != NULL) glad_vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)glad_vkCmdSetDeviceMaskKHR;
    if (glad_vkCmdSetDeviceMaskKHR == NULL && glad_vkCmdSetDeviceMask != NULL) glad_vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)glad_vkCmdSetDeviceMask;
    if (glad_vkCmdSetEvent2 == NULL && glad_vkCmdSetEvent2KHR != NULL) glad_vkCmdSetEvent2 = (PFN_vkCmdSetEvent2)glad_vkCmdSetEvent2KHR;
    if (glad_vkCmdSetEvent2KHR == NULL && glad_vkCmdSetEvent2 != NULL) glad_vkCmdSetEvent2KHR = (PFN_vkCmdSetEvent2KHR)glad_vkCmdSetEvent2;
    if (glad_vkCmdSetFrontFace == NULL && glad_vkCmdSetFrontFaceEXT != NULL) glad_vkCmdSetFrontFace = (PFN_vkCmdSetFrontFace)glad_vkCmdSetFrontFaceEXT;
    if (glad_vkCmdSetFrontFaceEXT == NULL && glad_vkCmdSetFrontFace != NULL) glad_vkCmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT)glad_vkCmdSetFrontFace;
    if (glad_vkCmdSetPrimitiveRestartEnable == NULL && glad_vkCmdSetPrimitiveRestartEnableEXT != NULL) glad_vkCmdSetPrimitiveRestartEnable = (PFN_vkCmdSetPrimitiveRestartEnable)glad_vkCmdSetPrimitiveRestartEnableEXT;
    if (glad_vkCmdSetPrimitiveRestartEnableEXT == NULL && glad_vkCmdSetPrimitiveRestartEnable != NULL) glad_vkCmdSetPrimitiveRestartEnableEXT = (PFN_vkCmdSetPrimitiveRestartEnableEXT)glad_vkCmdSetPrimitiveRestartEnable;
    if (glad_vkCmdSetPrimitiveTopology == NULL && glad_vkCmdSetPrimitiveTopologyEXT != NULL) glad_vkCmdSetPrimitiveTopology = (PFN_vkCmdSetPrimitiveTopology)glad_vkCmdSetPrimitiveTopologyEXT;
    if (glad_vkCmdSetPrimitiveTopologyEXT == NULL && glad_vkCmdSetPrimitiveTopology != NULL) glad_vkCmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT)glad_vkCmdSetPrimitiveTopology;
    if (glad_vkCmdSetRasterizerDiscardEnable == NULL && glad_vkCmdSetRasterizerDiscardEnableEXT != NULL) glad_vkCmdSetRasterizerDiscardEnable = (PFN_vkCmdSetRasterizerDiscardEnable)glad_vkCmdSetRasterizerDiscardEnableEXT;
    if (glad_vkCmdSetRasterizerDiscardEnableEXT == NULL && glad_vkCmdSetRasterizerDiscardEnable != NULL) glad_vkCmdSetRasterizerDiscardEnableEXT = (PFN_vkCmdSetRasterizerDiscardEnableEXT)glad_vkCmdSetRasterizerDiscardEnable;
    if (glad_vkCmdSetScissorWithCount == NULL && glad_vkCmdSetScissorWithCountEXT != NULL) glad_vkCmdSetScissorWithCount = (PFN_vkCmdSetScissorWithCount)glad_vkCmdSetScissorWithCountEXT;
    if (glad_vkCmdSetScissorWithCountEXT == NULL && glad_vkCmdSetScissorWithCount != NULL) glad_vkCmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT)glad_vkCmdSetScissorWithCount;
    if (glad_vkCmdSetStencilOp == NULL && glad_vkCmdSetStencilOpEXT != NULL) glad_vkCmdSetStencilOp = (PFN_vkCmdSetStencilOp)glad_vkCmdSetStencilOpEXT;
    if (glad_vkCmdSetStencilOpEXT == NULL && glad_vkCmdSetStencilOp != NULL) glad_vkCmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT)glad_vkCmdSetStencilOp;
    if (glad_vkCmdSetStencilTestEnable == NULL && glad_vkCmdSetStencilTestEnableEXT != NULL) glad_vkCmdSetStencilTestEnable = (PFN_vkCmdSetStencilTestEnable)glad_vkCmdSetStencilTestEnableEXT;
    if (glad_vkCmdSetStencilTestEnableEXT == NULL && glad_vkCmdSetStencilTestEnable != NULL) glad_vkCmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT)glad_vkCmdSetStencilTestEnable;
    if (glad_vkCmdSetViewportWithCount == NULL && glad_vkCmdSetViewportWithCountEXT != NULL) glad_vkCmdSetViewportWithCount = (PFN_vkCmdSetViewportWithCount)glad_vkCmdSetViewportWithCountEXT;
    if (glad_vkCmdSetViewportWithCountEXT == NULL && glad_vkCmdSetViewportWithCount != NULL) glad_vkCmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT)glad_vkCmdSetViewportWithCount;
    if (glad_vkCmdWaitEvents2 == NULL && glad_vkCmdWaitEvents2KHR != NULL) glad_vkCmdWaitEvents2 = (PFN_vkCmdWaitEvents2)glad_vkCmdWaitEvents2KHR;
    if (glad_vkCmdWaitEvents2KHR == NULL && glad_vkCmdWaitEvents2 != NULL) glad_vkCmdWaitEvents2KHR = (PFN_vkCmdWaitEvents2KHR)glad_vkCmdWaitEvents2;
    if (glad_vkCmdWriteTimestamp2 == NULL && glad_vkCmdWriteTimestamp2KHR != NULL) glad_vkCmdWriteTimestamp2 = (PFN_vkCmdWriteTimestamp2)glad_vkCmdWriteTimestamp2KHR;
    if (glad_vkCmdWriteTimestamp2KHR == NULL && glad_vkCmdWriteTimestamp2 != NULL) glad_vkCmdWriteTimestamp2KHR = (PFN_vkCmdWriteTimestamp2KHR)glad_vkCmdWriteTimestamp2;
    if (glad_vkCreateDescriptorUpdateTemplate == NULL && glad_vkCreateDescriptorUpdateTemplateKHR != NULL) glad_vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate)glad_vkCreateDescriptorUpdateTemplateKHR;
    if (glad_vkCreateDescriptorUpdateTemplateKHR == NULL && glad_vkCreateDescriptorUpdateTemplate != NULL) glad_vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR)glad_vkCreateDescriptorUpdateTemplate;
    if (glad_vkCreatePrivateDataSlot == NULL && glad_vkCreatePrivateDataSlotEXT != NULL) glad_vkCreatePrivateDataSlot = (PFN_vkCreatePrivateDataSlot)glad_vkCreatePrivateDataSlotEXT;
    if (glad_vkCreatePrivateDataSlotEXT == NULL && glad_vkCreatePrivateDataSlot != NULL) glad_vkCreatePrivateDataSlotEXT = (PFN_vkCreatePrivateDataSlotEXT)glad_vkCreatePrivateDataSlot;
    if (glad_vkCreateRenderPass2 == NULL && glad_vkCreateRenderPass2KHR != NULL) glad_vkCreateRenderPass2 = (PFN_vkCreateRenderPass2)glad_vkCreateRenderPass2KHR;
    if (glad_vkCreateRenderPass2KHR == NULL && glad_vkCreateRenderPass2 != NULL) glad_vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)glad_vkCreateRenderPass2;
    if (glad_vkCreateSamplerYcbcrConversion == NULL && glad_vkCreateSamplerYcbcrConversionKHR != NULL) glad_vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)glad_vkCreateSamplerYcbcrConversionKHR;
    if (glad_vkCreateSamplerYcbcrConversionKHR == NULL && glad_vkCreateSamplerYcbcrConversion != NULL) glad_vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR)glad_vkCreateSamplerYcbcrConversion;
    if (glad_vkDestroyDescriptorUpdateTemplate == NULL && glad_vkDestroyDescriptorUpdateTemplateKHR != NULL) glad_vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate)glad_vkDestroyDescriptorUpdateTemplateKHR;
    if (glad_vkDestroyDescriptorUpdateTemplateKHR == NULL && glad_vkDestroyDescriptorUpdateTemplate != NULL) glad_vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR)glad_vkDestroyDescriptorUpdateTemplate;
    if (glad_vkDestroyPrivateDataSlot == NULL && glad_vkDestroyPrivateDataSlotEXT != NULL) glad_vkDestroyPrivateDataSlot = (PFN_vkDestroyPrivateDataSlot)glad_vkDestroyPrivateDataSlotEXT;
    if (glad_vkDestroyPrivateDataSlotEXT == NULL && glad_vkDestroyPrivateDataSlot != NULL) glad_vkDestroyPrivateDataSlotEXT = (PFN_vkDestroyPrivateDataSlotEXT)glad_vkDestroyPrivateDataSlot;
    if (glad_vkDestroySamplerYcbcrConversion == NULL && glad_vkDestroySamplerYcbcrConversionKHR != NULL) glad_vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion)glad_vkDestroySamplerYcbcrConversionKHR;
    if (glad_vkDestroySamplerYcbcrConversionKHR == NULL && glad_vkDestroySamplerYcbcrConversion != NULL) glad_vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR)glad_vkDestroySamplerYcbcrConversion;
    if (glad_vkEnumeratePhysicalDeviceGroups == NULL && glad_vkEnumeratePhysicalDeviceGroupsKHR != NULL) glad_vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups)glad_vkEnumeratePhysicalDeviceGroupsKHR;
    if (glad_vkEnumeratePhysicalDeviceGroupsKHR == NULL && glad_vkEnumeratePhysicalDeviceGroups != NULL) glad_vkEnumeratePhysicalDeviceGroupsKHR = (PFN_vkEnumeratePhysicalDeviceGroupsKHR)glad_vkEnumeratePhysicalDeviceGroups;
    if (glad_vkGetBufferDeviceAddress == NULL && glad_vkGetBufferDeviceAddressEXT != NULL) glad_vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)glad_vkGetBufferDeviceAddressEXT;
    if (glad_vkGetBufferDeviceAddress == NULL && glad_vkGetBufferDeviceAddressKHR != NULL) glad_vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)glad_vkGetBufferDeviceAddressKHR;
    if (glad_vkGetBufferDeviceAddressEXT == NULL && glad_vkGetBufferDeviceAddress != NULL) glad_vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)glad_vkGetBufferDeviceAddress;
    if (glad_vkGetBufferDeviceAddressEXT == NULL && glad_vkGetBufferDeviceAddressKHR != NULL) glad_vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)glad_vkGetBufferDeviceAddressKHR;
    if (glad_vkGetBufferDeviceAddressKHR == NULL && glad_vkGetBufferDeviceAddress != NULL) glad_vkGetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR)glad_vkGetBufferDeviceAddress;
    if (glad_vkGetBufferDeviceAddressKHR == NULL && glad_vkGetBufferDeviceAddressEXT != NULL) glad_vkGetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR)glad_vkGetBufferDeviceAddressEXT;
    if (glad_vkGetBufferMemoryRequirements2 == NULL && glad_vkGetBufferMemoryRequirements2KHR != NULL) glad_vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)glad_vkGetBufferMemoryRequirements2KHR;
    if (glad_vkGetBufferMemoryRequirements2KHR == NULL && glad_vkGetBufferMemoryRequirements2 != NULL) glad_vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR)glad_vkGetBufferMemoryRequirements2;
    if (glad_vkGetBufferOpaqueCaptureAddress == NULL && glad_vkGetBufferOpaqueCaptureAddressKHR != NULL) glad_vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress)glad_vkGetBufferOpaqueCaptureAddressKHR;
    if (glad_vkGetBufferOpaqueCaptureAddressKHR == NULL && glad_vkGetBufferOpaqueCaptureAddress != NULL) glad_vkGetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR)glad_vkGetBufferOpaqueCaptureAddress;
    if (glad_vkGetDescriptorSetLayoutSupport == NULL && glad_vkGetDescriptorSetLayoutSupportKHR != NULL) glad_vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport)glad_vkGetDescriptorSetLayoutSupportKHR;
    if (glad_vkGetDescriptorSetLayoutSupportKHR == NULL && glad_vkGetDescriptorSetLayoutSupport != NULL) glad_vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR)glad_vkGetDescriptorSetLayoutSupport;
    if (glad_vkGetDeviceBufferMemoryRequirements == NULL && glad_vkGetDeviceBufferMemoryRequirementsKHR != NULL) glad_vkGetDeviceBufferMemoryRequirements = (PFN_vkGetDeviceBufferMemoryRequirements)glad_vkGetDeviceBufferMemoryRequirementsKHR;
    if (glad_vkGetDeviceBufferMemoryRequirementsKHR == NULL && glad_vkGetDeviceBufferMemoryRequirements != NULL) glad_vkGetDeviceBufferMemoryRequirementsKHR = (PFN_vkGetDeviceBufferMemoryRequirementsKHR)glad_vkGetDeviceBufferMemoryRequirements;
    if (glad_vkGetDeviceGroupPeerMemoryFeatures == NULL && glad_vkGetDeviceGroupPeerMemoryFeaturesKHR != NULL) glad_vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures)glad_vkGetDeviceGroupPeerMemoryFeaturesKHR;
    if (glad_vkGetDeviceGroupPeerMemoryFeaturesKHR == NULL && glad_vkGetDeviceGroupPeerMemoryFeatures != NULL) glad_vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)glad_vkGetDeviceGroupPeerMemoryFeatures;
    if (glad_vkGetDeviceImageMemoryRequirements == NULL && glad_vkGetDeviceImageMemoryRequirementsKHR != NULL) glad_vkGetDeviceImageMemoryRequirements = (PFN_vkGetDeviceImageMemoryRequirements)glad_vkGetDeviceImageMemoryRequirementsKHR;
    if (glad_vkGetDeviceImageMemoryRequirementsKHR == NULL && glad_vkGetDeviceImageMemoryRequirements != NULL) glad_vkGetDeviceImageMemoryRequirementsKHR = (PFN_vkGetDeviceImageMemoryRequirementsKHR)glad_vkGetDeviceImageMemoryRequirements;
    if (glad_vkGetDeviceImageSparseMemoryRequirements == NULL && glad_vkGetDeviceImageSparseMemoryRequirementsKHR != NULL) glad_vkGetDeviceImageSparseMemoryRequirements = (PFN_vkGetDeviceImageSparseMemoryRequirements)glad_vkGetDeviceImageSparseMemoryRequirementsKHR;
    if (glad_vkGetDeviceImageSparseMemoryRequirementsKHR == NULL && glad_vkGetDeviceImageSparseMemoryRequirements != NULL) glad_vkGetDeviceImageSparseMemoryRequirementsKHR = (PFN_vkGetDeviceImageSparseMemoryRequirementsKHR)glad_vkGetDeviceImageSparseMemoryRequirements;
    if (glad_vkGetDeviceMemoryOpaqueCaptureAddress == NULL && glad_vkGetDeviceMemoryOpaqueCaptureAddressKHR != NULL) glad_vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress)glad_vkGetDeviceMemoryOpaqueCaptureAddressKHR;
    if (glad_vkGetDeviceMemoryOpaqueCaptureAddressKHR == NULL && glad_vkGetDeviceMemoryOpaqueCaptureAddress != NULL) glad_vkGetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR)glad_vkGetDeviceMemoryOpaqueCaptureAddress;
    if (glad_vkGetImageMemoryRequirements2 == NULL && glad_vkGetImageMemoryRequirements2KHR != NULL) glad_vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)glad_vkGetImageMemoryRequirements2KHR;
    if (glad_vkGetImageMemoryRequirements2KHR == NULL && glad_vkGetImageMemoryRequirements2 != NULL) glad_vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR)glad_vkGetImageMemoryRequirements2;
    if (glad_vkGetImageSparseMemoryRequirements2 == NULL && glad_vkGetImageSparseMemoryRequirements2KHR != NULL) glad_vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2)glad_vkGetImageSparseMemoryRequirements2KHR;
    if (glad_vkGetImageSparseMemoryRequirements2KHR == NULL && glad_vkGetImageSparseMemoryRequirements2 != NULL) glad_vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR)glad_vkGetImageSparseMemoryRequirements2;
    if (glad_vkGetPhysicalDeviceExternalBufferProperties == NULL && glad_vkGetPhysicalDeviceExternalBufferPropertiesKHR != NULL) glad_vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties)glad_vkGetPhysicalDeviceExternalBufferPropertiesKHR;
    if (glad_vkGetPhysicalDeviceExternalBufferPropertiesKHR == NULL && glad_vkGetPhysicalDeviceExternalBufferProperties != NULL) glad_vkGetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR)glad_vkGetPhysicalDeviceExternalBufferProperties;
    if (glad_vkGetPhysicalDeviceExternalFenceProperties == NULL && glad_vkGetPhysicalDeviceExternalFencePropertiesKHR != NULL) glad_vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties)glad_vkGetPhysicalDeviceExternalFencePropertiesKHR;
    if (glad_vkGetPhysicalDeviceExternalFencePropertiesKHR == NULL && glad_vkGetPhysicalDeviceExternalFenceProperties != NULL) glad_vkGetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR)glad_vkGetPhysicalDeviceExternalFenceProperties;
    if (glad_vkGetPhysicalDeviceExternalSemaphoreProperties == NULL && glad_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR != NULL) glad_vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties)glad_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
    if (glad_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR == NULL && glad_vkGetPhysicalDeviceExternalSemaphoreProperties != NULL) glad_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR)glad_vkGetPhysicalDeviceExternalSemaphoreProperties;
    if (glad_vkGetPhysicalDeviceFeatures2 == NULL && glad_vkGetPhysicalDeviceFeatures2KHR != NULL) glad_vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2)glad_vkGetPhysicalDeviceFeatures2KHR;
    if (glad_vkGetPhysicalDeviceFeatures2KHR == NULL && glad_vkGetPhysicalDeviceFeatures2 != NULL) glad_vkGetPhysicalDeviceFeatures2KHR = (PFN_vkGetPhysicalDeviceFeatures2KHR)glad_vkGetPhysicalDeviceFeatures2;
    if (glad_vkGetPhysicalDeviceFormatProperties2 == NULL && glad_vkGetPhysicalDeviceFormatProperties2KHR != NULL) glad_vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2)glad_vkGetPhysicalDeviceFormatProperties2KHR;
    if (glad_vkGetPhysicalDeviceFormatProperties2KHR == NULL && glad_vkGetPhysicalDeviceFormatProperties2 != NULL) glad_vkGetPhysicalDeviceFormatProperties2KHR = (PFN_vkGetPhysicalDeviceFormatProperties2KHR)glad_vkGetPhysicalDeviceFormatProperties2;
    if (glad_vkGetPhysicalDeviceImageFormatProperties2 == NULL && glad_vkGetPhysicalDeviceImageFormatProperties2KHR != NULL) glad_vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2)glad_vkGetPhysicalDeviceImageFormatProperties2KHR;
    if (glad_vkGetPhysicalDeviceImageFormatProperties2KHR == NULL && glad_vkGetPhysicalDeviceImageFormatProperties2 != NULL) glad_vkGetPhysicalDeviceImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR)glad_vkGetPhysicalDeviceImageFormatProperties2;
    if (glad_vkGetPhysicalDeviceMemoryProperties2 == NULL && glad_vkGetPhysicalDeviceMemoryProperties2KHR != NULL) glad_vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2)glad_vkGetPhysicalDeviceMemoryProperties2KHR;
    if (glad_vkGetPhysicalDeviceMemoryProperties2KHR == NULL && glad_vkGetPhysicalDeviceMemoryProperties2 != NULL) glad_vkGetPhysicalDeviceMemoryProperties2KHR = (PFN_vkGetPhysicalDeviceMemoryProperties2KHR)glad_vkGetPhysicalDeviceMemoryProperties2;
    if (glad_vkGetPhysicalDeviceProperties2 == NULL && glad_vkGetPhysicalDeviceProperties2KHR != NULL) glad_vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2)glad_vkGetPhysicalDeviceProperties2KHR;
    if (glad_vkGetPhysicalDeviceProperties2KHR == NULL && glad_vkGetPhysicalDeviceProperties2 != NULL) glad_vkGetPhysicalDeviceProperties2KHR = (PFN_vkGetPhysicalDeviceProperties2KHR)glad_vkGetPhysicalDeviceProperties2;
    if (glad_vkGetPhysicalDeviceQueueFamilyProperties2 == NULL && glad_vkGetPhysicalDeviceQueueFamilyProperties2KHR != NULL) glad_vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2)glad_vkGetPhysicalDeviceQueueFamilyProperties2KHR;
    if (glad_vkGetPhysicalDeviceQueueFamilyProperties2KHR == NULL && glad_vkGetPhysicalDeviceQueueFamilyProperties2 != NULL) glad_vkGetPhysicalDeviceQueueFamilyProperties2KHR = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR)glad_vkGetPhysicalDeviceQueueFamilyProperties2;
    if (glad_vkGetPhysicalDeviceSparseImageFormatProperties2 == NULL && glad_vkGetPhysicalDeviceSparseImageFormatProperties2KHR != NULL) glad_vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2)glad_vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
    if (glad_vkGetPhysicalDeviceSparseImageFormatProperties2KHR == NULL && glad_vkGetPhysicalDeviceSparseImageFormatProperties2 != NULL) glad_vkGetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR)glad_vkGetPhysicalDeviceSparseImageFormatProperties2;
    if (glad_vkGetPhysicalDeviceToolProperties == NULL && glad_vkGetPhysicalDeviceToolPropertiesEXT != NULL) glad_vkGetPhysicalDeviceToolProperties = (PFN_vkGetPhysicalDeviceToolProperties)glad_vkGetPhysicalDeviceToolPropertiesEXT;
    if (glad_vkGetPhysicalDeviceToolPropertiesEXT == NULL && glad_vkGetPhysicalDeviceToolProperties != NULL) glad_vkGetPhysicalDeviceToolPropertiesEXT = (PFN_vkGetPhysicalDeviceToolPropertiesEXT)glad_vkGetPhysicalDeviceToolProperties;
    if (glad_vkGetPrivateData == NULL && glad_vkGetPrivateDataEXT != NULL) glad_vkGetPrivateData = (PFN_vkGetPrivateData)glad_vkGetPrivateDataEXT;
    if (glad_vkGetPrivateDataEXT == NULL && glad_vkGetPrivateData != NULL) glad_vkGetPrivateDataEXT = (PFN_vkGetPrivateDataEXT)glad_vkGetPrivateData;
    if (glad_vkGetSemaphoreCounterValue == NULL && glad_vkGetSemaphoreCounterValueKHR != NULL) glad_vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue)glad_vkGetSemaphoreCounterValueKHR;
    if (glad_vkGetSemaphoreCounterValueKHR == NULL && glad_vkGetSemaphoreCounterValue != NULL) glad_vkGetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR)glad_vkGetSemaphoreCounterValue;
    if (glad_vkQueueSubmit2 == NULL && glad_vkQueueSubmit2KHR != NULL) glad_vkQueueSubmit2 = (PFN_vkQueueSubmit2)glad_vkQueueSubmit2KHR;
    if (glad_vkQueueSubmit2KHR == NULL && glad_vkQueueSubmit2 != NULL) glad_vkQueueSubmit2KHR = (PFN_vkQueueSubmit2KHR)glad_vkQueueSubmit2;
    if (glad_vkResetQueryPool == NULL && glad_vkResetQueryPoolEXT != NULL) glad_vkResetQueryPool = (PFN_vkResetQueryPool)glad_vkResetQueryPoolEXT;
    if (glad_vkResetQueryPoolEXT == NULL && glad_vkResetQueryPool != NULL) glad_vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)glad_vkResetQueryPool;
    if (glad_vkSetPrivateData == NULL && glad_vkSetPrivateDataEXT != NULL) glad_vkSetPrivateData = (PFN_vkSetPrivateData)glad_vkSetPrivateDataEXT;
    if (glad_vkSetPrivateDataEXT == NULL && glad_vkSetPrivateData != NULL) glad_vkSetPrivateDataEXT = (PFN_vkSetPrivateDataEXT)glad_vkSetPrivateData;
    if (glad_vkSignalSemaphore == NULL && glad_vkSignalSemaphoreKHR != NULL) glad_vkSignalSemaphore = (PFN_vkSignalSemaphore)glad_vkSignalSemaphoreKHR;
    if (glad_vkSignalSemaphoreKHR == NULL && glad_vkSignalSemaphore != NULL) glad_vkSignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR)glad_vkSignalSemaphore;
    if (glad_vkTrimCommandPool == NULL && glad_vkTrimCommandPoolKHR != NULL) glad_vkTrimCommandPool = (PFN_vkTrimCommandPool)glad_vkTrimCommandPoolKHR;
    if (glad_vkTrimCommandPoolKHR == NULL && glad_vkTrimCommandPool != NULL) glad_vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)glad_vkTrimCommandPool;
    if (glad_vkUpdateDescriptorSetWithTemplate == NULL && glad_vkUpdateDescriptorSetWithTemplateKHR != NULL) glad_vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate)glad_vkUpdateDescriptorSetWithTemplateKHR;
    if (glad_vkUpdateDescriptorSetWithTemplateKHR == NULL && glad_vkUpdateDescriptorSetWithTemplate != NULL) glad_vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR)glad_vkUpdateDescriptorSetWithTemplate;
    if (glad_vkWaitSemaphores == NULL && glad_vkWaitSemaphoresKHR != NULL) glad_vkWaitSemaphores = (PFN_vkWaitSemaphores)glad_vkWaitSemaphoresKHR;
    if (glad_vkWaitSemaphoresKHR == NULL && glad_vkWaitSemaphores != NULL) glad_vkWaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR)glad_vkWaitSemaphores;
}

static int glad_vk_get_extensions( VkPhysicalDevice physical_device, uint32_t *out_extension_count, char ***out_extensions) {
    uint32_t i;
    uint32_t instance_extension_count = 0;
    uint32_t device_extension_count = 0;
    uint32_t max_extension_count = 0;
    uint32_t total_extension_count = 0;
    char **extensions = NULL;
    VkExtensionProperties *ext_properties = NULL;
    VkResult result;

    if (glad_vkEnumerateInstanceExtensionProperties == NULL || (physical_device != NULL && glad_vkEnumerateDeviceExtensionProperties == NULL)) {
        return 0;
    }

    result = glad_vkEnumerateInstanceExtensionProperties(NULL, &instance_extension_count, NULL);
    if (result != VK_SUCCESS) {
        return 0;
    }

    if (physical_device != NULL) {
        result = glad_vkEnumerateDeviceExtensionProperties(physical_device, NULL, &device_extension_count, NULL);
        if (result != VK_SUCCESS) {
            return 0;
        }
    }

    total_extension_count = instance_extension_count + device_extension_count;
    if (total_extension_count <= 0) {
        return 0;
    }

    max_extension_count = instance_extension_count > device_extension_count
        ? instance_extension_count : device_extension_count;

    ext_properties = (VkExtensionProperties*) malloc(max_extension_count * sizeof(VkExtensionProperties));
    if (ext_properties == NULL) {
        goto glad_vk_get_extensions_error;
    }

    result = glad_vkEnumerateInstanceExtensionProperties(NULL, &instance_extension_count, ext_properties);
    if (result != VK_SUCCESS) {
        goto glad_vk_get_extensions_error;
    }

    extensions = (char**) calloc(total_extension_count, sizeof(char*));
    if (extensions == NULL) {
        goto glad_vk_get_extensions_error;
    }

    for (i = 0; i < instance_extension_count; ++i) {
        VkExtensionProperties ext = ext_properties[i];

        size_t extension_name_length = strlen(ext.extensionName) + 1;
        extensions[i] = (char*) malloc(extension_name_length * sizeof(char));
        if (extensions[i] == NULL) {
            goto glad_vk_get_extensions_error;
        }
        memcpy(extensions[i], ext.extensionName, extension_name_length * sizeof(char));
    }

    if (physical_device != NULL) {
        result = glad_vkEnumerateDeviceExtensionProperties(physical_device, NULL, &device_extension_count, ext_properties);
        if (result != VK_SUCCESS) {
            goto glad_vk_get_extensions_error;
        }

        for (i = 0; i < device_extension_count; ++i) {
            VkExtensionProperties ext = ext_properties[i];

            size_t extension_name_length = strlen(ext.extensionName) + 1;
            extensions[instance_extension_count + i] = (char*) malloc(extension_name_length * sizeof(char));
            if (extensions[instance_extension_count + i] == NULL) {
                goto glad_vk_get_extensions_error;
            }
            memcpy(extensions[instance_extension_count + i], ext.extensionName, extension_name_length * sizeof(char));
        }
    }

    free((void*) ext_properties);

    *out_extension_count = total_extension_count;
    *out_extensions = extensions;

    return 1;

glad_vk_get_extensions_error:
    free((void*) ext_properties);
    if (extensions != NULL) {
        for (i = 0; i < total_extension_count; ++i) {
            free((void*) extensions[i]);
        }
        free(extensions);
    }
    return 0;
}

static void glad_vk_free_extensions(uint32_t extension_count, char **extensions) {
    uint32_t i;

    for(i = 0; i < extension_count ; ++i) {
        free((void*) (extensions[i]));
    }

    free((void*) extensions);
}

static int glad_vk_has_extension(const char *name, uint32_t extension_count, char **extensions) {
    uint32_t i;

    for (i = 0; i < extension_count; ++i) {
        if(extensions[i] != NULL && strcmp(name, extensions[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

static GLADapiproc glad_vk_get_proc_from_userptr(void *userptr, const char* name) {
    return (GLAD_GNUC_EXTENSION (GLADapiproc (*)(const char *name)) userptr)(name);
}

static int glad_vk_find_extensions_vulkan( VkPhysicalDevice physical_device) {
    uint32_t extension_count = 0;
    char **extensions = NULL;
    if (!glad_vk_get_extensions(physical_device, &extension_count, &extensions)) return 0;

    GLAD_VK_AMD_draw_indirect_count = glad_vk_has_extension("VK_AMD_draw_indirect_count", extension_count, extensions);
    GLAD_VK_EXT_buffer_device_address = glad_vk_has_extension("VK_EXT_buffer_device_address", extension_count, extensions);
    GLAD_VK_EXT_extended_dynamic_state = glad_vk_has_extension("VK_EXT_extended_dynamic_state", extension_count, extensions);
    GLAD_VK_EXT_extended_dynamic_state2 = glad_vk_has_extension("VK_EXT_extended_dynamic_state2", extension_count, extensions);
    GLAD_VK_EXT_host_query_reset = glad_vk_has_extension("VK_EXT_host_query_reset", extension_count, extensions);
    GLAD_VK_EXT_private_data = glad_vk_has_extension("VK_EXT_private_data", extension_count, extensions);
    GLAD_VK_EXT_shader_object = glad_vk_has_extension("VK_EXT_shader_object", extension_count, extensions);
    GLAD_VK_EXT_tooling_info = glad_vk_has_extension("VK_EXT_tooling_info", extension_count, extensions);
    GLAD_VK_KHR_bind_memory2 = glad_vk_has_extension("VK_KHR_bind_memory2", extension_count, extensions);
    GLAD_VK_KHR_buffer_device_address = glad_vk_has_extension("VK_KHR_buffer_device_address", extension_count, extensions);
    GLAD_VK_KHR_copy_commands2 = glad_vk_has_extension("VK_KHR_copy_commands2", extension_count, extensions);
    GLAD_VK_KHR_create_renderpass2 = glad_vk_has_extension("VK_KHR_create_renderpass2", extension_count, extensions);
    GLAD_VK_KHR_descriptor_update_template = glad_vk_has_extension("VK_KHR_descriptor_update_template", extension_count, extensions);
    GLAD_VK_KHR_device_group = glad_vk_has_extension("VK_KHR_device_group", extension_count, extensions);
    GLAD_VK_KHR_device_group_creation = glad_vk_has_extension("VK_KHR_device_group_creation", extension_count, extensions);
    GLAD_VK_KHR_draw_indirect_count = glad_vk_has_extension("VK_KHR_draw_indirect_count", extension_count, extensions);
    GLAD_VK_KHR_dynamic_rendering = glad_vk_has_extension("VK_KHR_dynamic_rendering", extension_count, extensions);
    GLAD_VK_KHR_external_fence_capabilities = glad_vk_has_extension("VK_KHR_external_fence_capabilities", extension_count, extensions);
    GLAD_VK_KHR_external_memory_capabilities = glad_vk_has_extension("VK_KHR_external_memory_capabilities", extension_count, extensions);
    GLAD_VK_KHR_external_semaphore_capabilities = glad_vk_has_extension("VK_KHR_external_semaphore_capabilities", extension_count, extensions);
    GLAD_VK_KHR_get_memory_requirements2 = glad_vk_has_extension("VK_KHR_get_memory_requirements2", extension_count, extensions);
    GLAD_VK_KHR_get_physical_device_properties2 = glad_vk_has_extension("VK_KHR_get_physical_device_properties2", extension_count, extensions);
    GLAD_VK_KHR_maintenance1 = glad_vk_has_extension("VK_KHR_maintenance1", extension_count, extensions);
    GLAD_VK_KHR_maintenance3 = glad_vk_has_extension("VK_KHR_maintenance3", extension_count, extensions);
    GLAD_VK_KHR_maintenance4 = glad_vk_has_extension("VK_KHR_maintenance4", extension_count, extensions);
    GLAD_VK_KHR_sampler_ycbcr_conversion = glad_vk_has_extension("VK_KHR_sampler_ycbcr_conversion", extension_count, extensions);
    GLAD_VK_KHR_synchronization2 = glad_vk_has_extension("VK_KHR_synchronization2", extension_count, extensions);
    GLAD_VK_KHR_timeline_semaphore = glad_vk_has_extension("VK_KHR_timeline_semaphore", extension_count, extensions);

    GLAD_UNUSED(glad_vk_has_extension);

    glad_vk_free_extensions(extension_count, extensions);

    return 1;
}

static int glad_vk_find_core_vulkan( VkPhysicalDevice physical_device) {
    int major = 1;
    int minor = 0;

#ifdef VK_VERSION_1_1
    if (glad_vkEnumerateInstanceVersion != NULL) {
        uint32_t version;
        VkResult result;

        result = glad_vkEnumerateInstanceVersion(&version);
        if (result == VK_SUCCESS) {
            major = (int) VK_VERSION_MAJOR(version);
            minor = (int) VK_VERSION_MINOR(version);
        }
    }
#endif

    if (physical_device != NULL && glad_vkGetPhysicalDeviceProperties != NULL) {
        VkPhysicalDeviceProperties properties;
        glad_vkGetPhysicalDeviceProperties(physical_device, &properties);

        major = (int) VK_VERSION_MAJOR(properties.apiVersion);
        minor = (int) VK_VERSION_MINOR(properties.apiVersion);
    }

    GLAD_VK_VERSION_1_0 = (major == 1 && minor >= 0) || major > 1;
    GLAD_VK_VERSION_1_1 = (major == 1 && minor >= 1) || major > 1;
    GLAD_VK_VERSION_1_2 = (major == 1 && minor >= 2) || major > 1;
    GLAD_VK_VERSION_1_3 = (major == 1 && minor >= 3) || major > 1;

    return GLAD_MAKE_VERSION(major, minor);
}

int gladLoadVulkanUserPtr( VkPhysicalDevice physical_device, GLADuserptrloadfunc load, void *userptr) {
    int version;

#ifdef VK_VERSION_1_1
    glad_vkEnumerateInstanceVersion  = (PFN_vkEnumerateInstanceVersion) load(userptr, "vkEnumerateInstanceVersion");
#endif
    version = glad_vk_find_core_vulkan( physical_device);
    if (!version) {
        return 0;
    }

    glad_vk_load_VK_VERSION_1_0(load, userptr);
    glad_vk_load_VK_VERSION_1_1(load, userptr);
    glad_vk_load_VK_VERSION_1_2(load, userptr);
    glad_vk_load_VK_VERSION_1_3(load, userptr);

    if (!glad_vk_find_extensions_vulkan( physical_device)) return 0;
    glad_vk_load_VK_AMD_draw_indirect_count(load, userptr);
    glad_vk_load_VK_EXT_buffer_device_address(load, userptr);
    glad_vk_load_VK_EXT_extended_dynamic_state(load, userptr);
    glad_vk_load_VK_EXT_extended_dynamic_state2(load, userptr);
    glad_vk_load_VK_EXT_host_query_reset(load, userptr);
    glad_vk_load_VK_EXT_private_data(load, userptr);
    glad_vk_load_VK_EXT_shader_object(load, userptr);
    glad_vk_load_VK_EXT_tooling_info(load, userptr);
    glad_vk_load_VK_KHR_bind_memory2(load, userptr);
    glad_vk_load_VK_KHR_buffer_device_address(load, userptr);
    glad_vk_load_VK_KHR_copy_commands2(load, userptr);
    glad_vk_load_VK_KHR_create_renderpass2(load, userptr);
    glad_vk_load_VK_KHR_descriptor_update_template(load, userptr);
    glad_vk_load_VK_KHR_device_group(load, userptr);
    glad_vk_load_VK_KHR_device_group_creation(load, userptr);
    glad_vk_load_VK_KHR_draw_indirect_count(load, userptr);
    glad_vk_load_VK_KHR_dynamic_rendering(load, userptr);
    glad_vk_load_VK_KHR_external_fence_capabilities(load, userptr);
    glad_vk_load_VK_KHR_external_memory_capabilities(load, userptr);
    glad_vk_load_VK_KHR_external_semaphore_capabilities(load, userptr);
    glad_vk_load_VK_KHR_get_memory_requirements2(load, userptr);
    glad_vk_load_VK_KHR_get_physical_device_properties2(load, userptr);
    glad_vk_load_VK_KHR_maintenance1(load, userptr);
    glad_vk_load_VK_KHR_maintenance3(load, userptr);
    glad_vk_load_VK_KHR_maintenance4(load, userptr);
    glad_vk_load_VK_KHR_sampler_ycbcr_conversion(load, userptr);
    glad_vk_load_VK_KHR_synchronization2(load, userptr);
    glad_vk_load_VK_KHR_timeline_semaphore(load, userptr);

    glad_vk_resolve_aliases();

    return version;
}


int gladLoadVulkan( VkPhysicalDevice physical_device, GLADloadfunc load) {
    return gladLoadVulkanUserPtr( physical_device, glad_vk_get_proc_from_userptr, GLAD_GNUC_EXTENSION (void*) load);
}



 


#ifdef __cplusplus
}
#endif
