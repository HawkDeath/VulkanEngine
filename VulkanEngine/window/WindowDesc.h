#pragma once

#include <cstdint>
#include <string>

namespace VulkanEngine {
struct WindowDesc {
  explicit WindowDesc() = default;

  std::int32_t width = 1280;
  std::int32_t height = 720;
  std::int32_t bits = 32;
  bool fullscreen = false;
  bool vsync = false;
};

} // namespace VulkanEngine