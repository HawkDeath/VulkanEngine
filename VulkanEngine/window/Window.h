#pragma once

#include <GLFW/glfw3.h>
#include <entt/signal/sigh.hpp>

#include <cstdint>
#include <memory>
#include <string>

#include "Input.h"
#include "WindowDesc.h"

// class HelloTriangleApplication;

namespace VulkanEngine {
class Window final {
  //	friend class HelloTriangleApplication;
public:
  Window(const WindowDesc &winDesc,
         const std::string &title = "framework-test");
  ~Window() = default;

  GLFWwindow *getWindowHandler() const { return mWindow.get(); }

  const WindowDesc &getDescription() const { return mWindowDescription; }

  Input &getInput() const { return *mInput; }

  bool isMinimalized() const { return mMinimalized; }

  bool shouldClose() const {
    return static_cast<bool>(glfwWindowShouldClose(mWindow.get()));
  }

  void update();

  entt::sink<void(std::int32_t &, std::int32_t &)> framebuffer() {
    return mFramebuffer;
  }

private:
  static void handleFramebufferResize(GLFWwindow *win, int w, int h);
  static void handleWindowResize(GLFWwindow *win, int w, int h);
  static void handleMinimalize(GLFWwindow *win, int status);

  static void handleKeyInput(GLFWwindow *win, int key, int scancode, int action,
                             int mods);
  static void handleMousePosition(GLFWwindow *win, double xPos, double yPos);
  static void handleMouseButton(GLFWwindow *win, int mouseButton, int action,
                                int mods);

  static Window *getInternalWindow(GLFWwindow *win) {
    return static_cast<Window *>(glfwGetWindowUserPointer(win));
  }

private:
  struct WinDestroyer {
    void operator()(GLFWwindow *win) {
      if (win != nullptr) {
        glfwDestroyWindow(win);
      }
    }
  };

  std::unique_ptr<GLFWwindow, WinDestroyer> mWindow;
  WindowDesc mWindowDescription;

  bool mMinimalized;
  bool mResized;

  std::string mTitle;
  std::unique_ptr<Input> mInput;

  static entt::sigh<void(std::int32_t &, std::int32_t &)> mFramebufferSignal;
  entt::sink<void(std::int32_t &, std::int32_t &)> mFramebuffer;
};
} // namespace VulkanEngine