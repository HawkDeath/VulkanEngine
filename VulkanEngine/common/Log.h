#pragma once

#include <spdlog/spdlog.h>

#define __LOGGER
#ifdef __LOGGER
#define ELOG(...)                                                              \
  do {                                                                         \
    spdlog::error(__VA_ARGS__);                                                \
  } while (0);
#define WLOG(...)                                                              \
  do {                                                                         \
    spdlog::warn(__VA_ARGS__);                                                 \
  } while (0);
#define LOG(...)                                                               \
  do {                                                                         \
    spdlog::info(__VA_ARGS__);                                                 \
  } while (0);
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