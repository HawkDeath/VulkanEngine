#pragma warning(disable : 4996)

#include "Engine.h"
#include "common/Log.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <ctime>
#include <iomanip>
#include <sstream>

namespace VulkanEngine {

std::string return_current_time_and_date() {
  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);

  std::stringstream ss;
  ss << std::put_time(std::localtime(&in_time_t), "%Y_%m_%d_%H_%M_%S");
  return ss.str();
}

Engine::Engine(int argc, const char *argv[]) : window(nullptr) {
  auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
      "log-" + return_current_time_and_date() + ".log", true);

  spdlog::set_default_logger(std::make_shared<spdlog::logger>(
      "multi_sink", spdlog::sinks_init_list({console_sink, file_sink})));
}

std::int32_t Engine::run() {
  VulkanEngine::WindowDesc winDesc;
  window = std::make_unique<VulkanEngine::Window>(winDesc);

  VulkanEngine::Input &input = window->getInput();

  while (!window->shouldClose()) {
    window->update();

    if (input.keyDown(VulkanEngine::InputUtils::Key::Escape)) {
      LOG("Escape has been pressed")
      glfwSetWindowShouldClose(window->getWindowHandler(), true);
    }
  }
  return 0;
}

}