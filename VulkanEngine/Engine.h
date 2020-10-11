#pragma once

#include "window/Window.h"

#include <cstdint>
#include <memory>

namespace VulkanEngine {
class Engine final {
public:
  explicit Engine(int argc, const char *argv[]);
  ~Engine() = default;

  Engine(const Engine &) = delete;
  Engine &operator=(const Engine &) = delete;

  std::int32_t run();

private:
  std::unique_ptr<Window> window;
};

} // namespace VulkanEngine