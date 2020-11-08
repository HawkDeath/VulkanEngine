#include "Window.h"

#include "../common/Log.h"
#include "../common/Profiler.h"

namespace VulkanEngine {

entt::sigh<void(int &, int &)> Window::mFramebufferSignal;

Window::Window(const WindowDesc &winDesc, const std::string &title)
    : mWindow(nullptr, WinDestroyer()), mWindowDescription(winDesc), mMinimalized(false),
      mResized(false), mTitle(title), mFramebuffer(mFramebufferSignal) {
  glfwSetErrorCallback(glfwUtils::error_callback);

  if (glfwInit() != GLFW_TRUE) {
    throw std::exception("Failed to initialize GLFW");
  }

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

  // window support only one monitor at the same time
  mWindow.reset(glfwCreateWindow(mWindowDescription.width,
                                 mWindowDescription.height, title.c_str(),
                                 nullptr, nullptr));

  if (mWindow == nullptr) {
    throw std::exception("Failed to create window");
  }

  LOG("GLFW {0}.{1}.{2} has been initialized", GLFW_VERSION_MAJOR,
      GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

  glfwSetWindowUserPointer(mWindow.get(), this);

  mInput = std::shared_ptr<Input>(new Input(mWindow.get()));

  glfwSetWindowSizeCallback(mWindow.get(), &Window::handleWindowResize);
  glfwSetFramebufferSizeCallback(mWindow.get(),
                                 &Window::handleFramebufferResize);
  glfwSetWindowIconifyCallback(mWindow.get(), &Window::handleMinimalize);

  glfwSetKeyCallback(mWindow.get(), &Window::handleKeyInput);
  glfwSetMouseButtonCallback(mWindow.get(), &Window::handleMouseButton);
  glfwSetCursorPosCallback(mWindow.get(), &Window::handleMousePosition);

  int fbWidth, fbHeight;
  glfwGetFramebufferSize(mWindow.get(), &fbWidth, &fbHeight);
  ;
  mFramebufferSignal.publish(fbWidth, fbHeight);
}

void Window::update() {
  mInput->reset();

  if (mMinimalized) {
    glfwWaitEvents();
  } else {
    glfwPollEvents();
  }
  mInput->update();

  if (mResized) {
    mResized = false;

    // do something in the future
  }
}

void Window::handleFramebufferResize(GLFWwindow *win, int w, int h) {
  auto window = getInternalWindow(win);
  window->mResized = true;
  mFramebufferSignal.publish(w, h);
}

void Window::handleWindowResize(GLFWwindow *win, int w, int h) {
  auto window = getInternalWindow(win);
  window->mResized = true;
  window->mWindowDescription.width = static_cast<std::int32_t>(w);
  window->mWindowDescription.height = static_cast<std::int32_t>(h);
}

void Window::handleMinimalize(GLFWwindow *win, int status) {
  auto window = getInternalWindow(win);
  window->mMinimalized = static_cast<bool>(status);
}

void Window::handleKeyInput(GLFWwindow *win, int key, int scancode, int action,
                            int mods) {
  auto window = getInternalWindow(win);
  Input *input = window->mInput.get();
  input->handleKeyInput(key, scancode, action, mods);
}

void Window::handleMousePosition(GLFWwindow *win, double xPos, double yPos) {
  auto window = getInternalWindow(win);
  Input *input = window->mInput.get();
  input->handleMousePosition(xPos, yPos);
}

void Window::handleMouseButton(GLFWwindow *win, int mouseButton, int action,
                               int mods) {
  auto window = getInternalWindow(win);
  Input *input = window->mInput.get();
  input->handleMouseButton(mouseButton, action, mods);
}
} // namespace VulkanEngine