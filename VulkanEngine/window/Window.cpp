#include "Window.h"

#include "../common/Log.h"
#include "../common/Profiler.h"

namespace VulkanEngine {
Window::Window(const WindowDesc &winDesc, const std::string &title)
    : window(nullptr), windowDescription(winDesc), minimalized(false),
      resized(false) {
  PROFILE_FUNCTION()
  glfwSetErrorCallback(glfwUtils::error_callback);

  if (glfwInit() != GLFW_TRUE) {
    throw std::exception("Failed to initialize GLFW");
  }

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  // window support only one monitor at the same time
  window = glfwCreateWindow(windowDescription.width, windowDescription.height,
                            title.c_str(), nullptr, nullptr);

  if (window == nullptr) {
    throw std::exception("Failed to create window");
  }
  LOG("GLFW {0}.{1}.{2} has been initialized", GLFW_VERSION_MAJOR,
      GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

  glfwSetWindowUserPointer(window, this);

  input = std::unique_ptr<Input>(new Input(window));

  glfwSetWindowSizeCallback(window, &handleWindowResize);
  glfwSetFramebufferSizeCallback(window, &handleFramebufferResize);
  glfwSetWindowIconifyCallback(window, &handleMinimalize);

  glfwSetKeyCallback(window, &handleKeyInput);
  glfwSetMouseButtonCallback(window, &handleMouseButton);
  glfwSetCursorPosCallback(window, &handleMousePosition);

  int fbWidth, fbHeight;
  glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
  framebufferWidth = static_cast<uint32_t>(fbWidth);
  framebufferHeight = static_cast<uint32_t>(fbHeight);
}

Window::~Window() {
  PROFILE_FUNCTION()
  destroyWindow();
}

void Window::destroyWindow() {
  if (window != nullptr) {
    glfwDestroyWindow(window);
  }
}

void Window::update() {
  PROFILE_FUNCTION()
  input->reset();

  if (minimalized) {
    glfwWaitEvents();
  } else {
    glfwPollEvents();
  }

  if (resized) {
    resized = false;

    // do something in the future
  }
}

void Window::handleFramebufferResize(GLFWwindow *win, int w, int h) {
  PROFILE_FUNCTION()
  auto window = getInternalWindow(win);
  window->resized = true;
  window->framebufferWidth = static_cast<std::int32_t>(w);
  window->framebufferHeight = static_cast<std::int32_t>(h);
  // TODO: Vulkan must handle this
}

void Window::handleWindowResize(GLFWwindow *win, int w, int h) {
  PROFILE_FUNCTION()
  auto window = getInternalWindow(win);
  window->resized = true;
  window->windowDescription.width = static_cast<std::int32_t>(w);
  window->windowDescription.height = static_cast<std::int32_t>(h);
  // TODO: Vulkan must handle this
}

void Window::handleMinimalize(GLFWwindow *win, int status) {
  PROFILE_FUNCTION()
  auto window = getInternalWindow(win);
  window->minimalized = static_cast<bool>(status);
}

void Window::handleKeyInput(GLFWwindow *win, int key, int scancode, int action,
                            int mods) {
  PROFILE_FUNCTION()
  auto window = getInternalWindow(win);
  Input *input = window->input.get();
  input->handleKeyInput(key, scancode, action, mods);
}

void Window::handleMousePosition(GLFWwindow *win, double xPos, double yPos) {
  PROFILE_FUNCTION()
  auto window = getInternalWindow(win);
  Input *input = window->input.get();
  input->handleMousePosition(xPos, yPos);
}

void Window::handleMouseButton(GLFWwindow *win, int mouseButton, int action,
                               int mods) {
  PROFILE_FUNCTION()
  auto window = getInternalWindow(win);
  Input *input = window->input.get();
  input->handleMouseButton(mouseButton, action, mods);
}
} // namespace VulkanEngine