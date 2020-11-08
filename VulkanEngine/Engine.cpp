#pragma warning(disable : 4996)

#include "Engine.h"
#include "common/Log.h"
#include "common/Utils.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace VulkanEngine {

Engine::Engine(int argc, const char *argv[]) : mWindow(nullptr) {
  auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
      "log-" + current_time_and_date() + ".log", true);

  spdlog::set_default_logger(std::make_shared<spdlog::logger>(
      "multi_sink", spdlog::sinks_init_list({console_sink, file_sink})));
}

std::int32_t Engine::run() {
  initialize();
  // connect to window framebuffer
  // window->framebuffer().connect<&Engine::updateFrame>(this);
  auto input = mWindow->getInput();
  input->reg(VulkanEngine::InputUtils::Key::Escape, [&]() -> bool {
    LOG("Escape has been pressed")
    glfwSetWindowShouldClose(mWindow->getWindowHandler(), true);
    return true;
  });

  while (!mWindow->shouldClose()) {
    mWindow->update();

    /*if (input->keyDown(VulkanEngine::InputUtils::Key::Escape)) {
      LOG("Escape has been pressed")
      glfwSetWindowShouldClose(mWindow->getWindowHandler(), true);
    }*/

    mRenderDevice->present();
  }
  return 0;
}

void Engine::initialize() {
  VulkanEngine::WindowDesc winDesc;
  mWindow = std::make_unique<VulkanEngine::Window>(winDesc);
  mRenderDevice = std::make_unique<VulkanDevice>(mWindow.get());

}

} // namespace VulkanEngine