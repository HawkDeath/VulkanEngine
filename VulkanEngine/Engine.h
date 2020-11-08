#pragma once

#include "common/Log.h"
#include "renderer/VulkanDevice.h"
#include "window/Window.h"
#include <cstdint>
#include <memory>

namespace VulkanEngine {
class VulkanDevice;
class Engine final {
public:
  explicit Engine(int argc, const char *argv[]);
  ~Engine() = default;

  Engine(const Engine &) = delete;
  Engine &operator=(const Engine &) = delete;

  std::int32_t run();

private:
  void initialize();

private:
  // void updateFrame(int &_w, int &_h) {
  //  w = _w;
  //  h = _h;
  //  LOG("width {0}, height {1}", w, h);
  //}

  std::unique_ptr<Window> mWindow;
  std::unique_ptr<VulkanDevice> mRenderDevice;
};

} // namespace VulkanEngine