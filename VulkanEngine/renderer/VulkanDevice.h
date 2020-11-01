#pragma once

#include <vulkan/vulkan.h>

#include "../window/Window.h"

namespace VulkanEngine {
class VulkanDevice final {
public:
  VulkanDevice(Window *window);
  ~VulkanDevice();

  void initialize();

  /*
  * call to all drawcall in queue
  */
  void present();

private:
  Window *mWindow;

  VkInstance mInstance;

};

}