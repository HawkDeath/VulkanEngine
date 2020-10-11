#pragma once

#include <GLFW/glfw3.h>

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
  ~Window();

  GLFWwindow *getWindowHandler() const { return window; }

  const WindowDesc &getDescription() const { return windowDescription; }

  Input &getInput() const { return *input; }

  const std::int32_t getFrameBufferWidth() const { return framebufferWidth; }

  const std::int32_t getFrameBufferHeight() const { return framebufferHeight; }

  bool isMinimalized() const {
    return minimalized || framebufferHeight == 0 || framebufferWidth == 0;
  }

  bool shouldClose() const {
    return static_cast<bool>(glfwWindowShouldClose(window));
  }

  void update();

private:
  void destroyWindow();

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
  GLFWwindow *window;
  WindowDesc windowDescription;

  std::int32_t framebufferWidth;
  std::int32_t framebufferHeight;

  bool minimalized;
  bool resized;

  std::unique_ptr<Input> input;
};
} // namespace VulkanEngine