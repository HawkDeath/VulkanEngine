#pragma once

#include <vulkan/vulkan.h>

namespace VulkanEngine {
namespace init {

VkApplicationInfo applicationInfo() {
  VkApplicationInfo appInfo = {};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  return appInfo;
}

VkInstanceCreateInfo instanceInfo() {
  VkInstanceCreateInfo instanceInfo = {};
  instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  return instanceInfo;
}

VkDeviceCreateInfo deviceInfo() {
  VkDeviceCreateInfo deviceInfo = {};
  deviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
  return deviceInfo;
}

VkSwapchainCreateInfoKHR swapchainInfo() {
  VkSwapchainCreateInfoKHR swapchainInfo = {};
  swapchainInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
  return swapchainInfo;
}

VkDeviceQueueCreateInfo deviceQueueInfo() {
  VkDeviceQueueCreateInfo deviceQueueInfo = {};
  deviceQueueInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
  return deviceQueueInfo;
}

VkRenderPassCreateInfo renderPassInfo() {
  VkRenderPassCreateInfo renderPassInfo = {};
  renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
  return renderPassInfo;
}

VkWriteDescriptorSet writeDescriptorSet() {
  VkWriteDescriptorSet descSet = {};
  descSet.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
  return descSet;
}

VkDescriptorSetLayoutCreateInfo descriptorSetLayoutInfo() {
  VkDescriptorSetLayoutCreateInfo descriptorSetLayoutInfo = {};
  descriptorSetLayoutInfo.sType =
      VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
  return descriptorSetLayoutInfo;
}

VkDescriptorPoolCreateInfo descriptorPoolInfo() {
  VkDescriptorPoolCreateInfo descPoolInfo = {};
  descPoolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
  return descPoolInfo;
}

VkDescriptorSetAllocateInfo descriptorSetAllocateInfo() {
  VkDescriptorSetAllocateInfo descSetAllocInfo = {};
  descSetAllocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
  return descSetAllocInfo;
}

VkPipelineShaderStageCreateInfo pipelineShaderStageInfo() {
  VkPipelineShaderStageCreateInfo pipelineInfo = {};
  pipelineInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
  return pipelineInfo;
}

VkPipelineVertexInputStateCreateInfo pipelineVertexInputStateInfo() {
  VkPipelineVertexInputStateCreateInfo pipelineVertexInfo = {};
  pipelineVertexInfo.sType =
      VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
  return pipelineVertexInfo;
}

VkPipelineInputAssemblyStateCreateInfo pipelineInputAssemblyStateInfo() {
  VkPipelineInputAssemblyStateCreateInfo pipelineAssembly = {};
  pipelineAssembly.sType =
      VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
  return pipelineAssembly;
}

VkPipelineViewportStateCreateInfo pipelineViewportStateInfo() {
  VkPipelineViewportStateCreateInfo pipelineViewport = {};
  pipelineViewport.sType =
      VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
  return pipelineViewport;
}

VkPipelineRasterizationStateCreateInfo pipelineRasterizationStateInfo() {
  VkPipelineRasterizationStateCreateInfo rasterInfo = {};
  rasterInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
  return rasterInfo;
}

VkPipelineMultisampleStateCreateInfo pipelineMultisampleStateInfo() {
  VkPipelineMultisampleStateCreateInfo multisampleInfo = {};
  multisampleInfo.sType =
      VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
  return multisampleInfo;
}

VkPipelineDepthStencilStateCreateInfo pipelineDepthStencilStateInfo() {
  VkPipelineDepthStencilStateCreateInfo depthStencilInfo = {};
  depthStencilInfo.sType =
      VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
  return depthStencilInfo;
}

VkPipelineColorBlendStateCreateInfo pipelineColorBlendStateInfo() {
  VkPipelineColorBlendStateCreateInfo colorBlendInfo = {};
  colorBlendInfo.sType =
      VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
  return colorBlendInfo;
}

VkPipelineLayoutCreateInfo pipelineLayoutInfo() {
  VkPipelineLayoutCreateInfo layoutInfo = {};
  layoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
  return layoutInfo;
}

VkGraphicsPipelineCreateInfo graphicsPipelineInfo() {
  VkGraphicsPipelineCreateInfo graphicsInfo = {};
  graphicsInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
  return graphicsInfo;
}

VkFramebufferCreateInfo framebufferInfo() {
  VkFramebufferCreateInfo bufferInfo = {};
  bufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
  return bufferInfo;
}

VkCommandPoolCreateInfo commandPoolInfo() {
  VkCommandPoolCreateInfo cmdPoolInfo = {};
  cmdPoolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
  return cmdPoolInfo;
}

VkCommandBufferAllocateInfo commandBufferAllocateInfo() {
  VkCommandBufferAllocateInfo cmdBuffAllocInfo = {};
  cmdBuffAllocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
  return cmdBuffAllocInfo;
}

VkCommandBufferBeginInfo commandBufferBeginInfo() {
  VkCommandBufferBeginInfo cmdBuffBeginInfo = {};
  cmdBuffBeginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
  return cmdBuffBeginInfo;
}

VkImageMemoryBarrier imageMemoryBarrierInfo() {
  VkImageMemoryBarrier imgMemoryBarrier = {};
  imgMemoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
  return imgMemoryBarrier;
}

VkImageViewCreateInfo imageViewInfo() {
  VkImageViewCreateInfo imgViewInfo = {};
  imgViewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
  return imgViewInfo;
}

VkImageCreateInfo imageInfo() {
  VkImageCreateInfo imgInfo = {};
  imgInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
  return imgInfo;
}

VkSamplerCreateInfo samplerInfo() {
  VkSamplerCreateInfo samplerInfo = {};
  samplerInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
  return samplerInfo;
}

VkMemoryAllocateInfo memoryAllocateInfo() {
  VkMemoryAllocateInfo memAllocInfo = {};
  memAllocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
  return memAllocInfo;
}

VkBufferCreateInfo bufferInfo() {
  VkBufferCreateInfo buffInfo = {};
  buffInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
  return buffInfo;
}

VkSubmitInfo sumbitInfo() {
  VkSubmitInfo subInfo = {};
  subInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
  return subInfo;
}

VkSemaphoreCreateInfo semaphoreInfo() {
  VkSemaphoreCreateInfo semaphoreInfo = {};
  semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
  return semaphoreInfo;
}

VkFenceCreateInfo fenceInfo() {
  VkFenceCreateInfo fenceInfo = {};
  fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
  return fenceInfo;
}

VkPresentInfoKHR presentInfo() {
  VkPresentInfoKHR presentInfo = {};
  presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
  return presentInfo;
}

VkShaderModuleCreateInfo shaderModuleInfo() {
  VkShaderModuleCreateInfo shaderInfo = {};
  shaderInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
  return shaderInfo;
}


// VkDebugUtilsMessengerCreateInfoEXT::pfnUserCallback is null 
VkDebugUtilsMessengerCreateInfoEXT debugUtilsMessageInfo() {
  VkDebugUtilsMessengerCreateInfoEXT debugInfo = {};
  debugInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
  debugInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
                               VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                               VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
  debugInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
                           VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                           VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
  debugInfo.pfnUserCallback = nullptr;
  return debugInfo;
}

} // namespace init
} // namespace VulkanEngine