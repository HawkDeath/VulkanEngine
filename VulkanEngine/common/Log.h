#pragma once

#include <spdlog/spdlog.h>

#define __LOGGER
#ifdef __LOGGER
#define ELOG(...) spdlog::error(__VA_ARGS__);
#define WLOG(...) spdlog::warn(__VA_ARGS__);
#define LOG(...) spdlog::info(__VA_ARGS__);
#else
#define ELOG()
#define WLOG()
#define LOG()
#endif

namespace VulkanEngine::glfwUtils {
static void error_callback(int error, const char *description) {
  ELOG("GLFW code {0}: {1}", error, description);
}
} // namespace VulkanEngine::glfwUtils