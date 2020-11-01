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
  deviceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  return deviceInfo;
}

} // namespace init
} // namespace VulkanEngine