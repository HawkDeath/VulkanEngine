#include "Input.h"

using VulkanEngine::InputUtils::CursorMode;
using VulkanEngine::InputUtils::Key;
using VulkanEngine::InputUtils::KeyState;
using VulkanEngine::InputUtils::MouseButton;

namespace VulkanEngine {
Input::Input(GLFWwindow *window_) : window(window_) {}

void Input::handleKeyInput(int inKey, int scancode, int action, int mods) {
  const Key key = static_cast<Key>(inKey);
  auto it = keysStates.find(key);

  if (it == keysStates.end()) { // key is not pressed
    if (action == GLFW_PRESS) {
      auto data = keysStates.insert(key);

      if (data.second) {
        keysDown.insert(key);
      }
    }
  } else { // key is pressed
    if (action == GLFW_RELEASE) {
      auto itPressKey = keysStates.find(key); // find key if pressed

      if (itPressKey != keysStates.end()) {
        keysStates.erase(itPressKey);
        keysUp.insert(key);
      }
    }
  }
}

void Input::handleMousePosition(double xPos, double yPos) {
  glm::vec2 newPosition = {static_cast<float>(xPos), static_cast<float>(yPos)};

  mouseDeltaValue = newPosition - mousePosition;
  mousePosition = newPosition;
}

void Input::handleMouseButton(int mouseButton, int action, int modes) {
  const MouseButton button = static_cast<MouseButton>(mouseButton);
  auto it = mouseButtonsState.find(button);

  if (it == mouseButtonsState.end()) { // button is not pressed
    if (action == GLFW_PRESS) {
      auto data = mouseButtonsState.insert(button);

      if (data.second) {
        mouseButtonsDown.insert(button);
      }
    }
  } else { // button is pressed
    if (action == GLFW_RELEASE) {
      auto itPressKey =
          mouseButtonsState.find(button); // find button if pressed

      if (itPressKey != mouseButtonsState.end()) {
        mouseButtonsState.erase(itPressKey);
        mouseButtonsUp.insert(button);
      }
    }
  }
}

void Input::reset() {
  mouseDeltaValue = {};

  keysDown.clear();
  keysUp.clear();

  mouseButtonsDown.clear();
  mouseButtonsUp.clear();
}

bool Input::keyDown(Key key) const {
  return keysDown.find(key) != keysDown.end();
}

bool Input::keyUp(Key key) const {
  return keysUp.find(key) != keysUp.end();
}

bool Input::keyHold(Key key) const {
  return keysStates.find(key) != keysStates.end();
}

KeyState Input::keyState(Key key) const {
  KeyState result = KeyState::None;

  if (keyDown(key)) {
    result |= KeyState::Down;
  }

  if (keyUp(key)) {
    result |= KeyState::Up;
  }

  if (keyHold(key)) {
    result |= KeyState::Hold;
  }

  return result;
}

bool Input::mouseButtonDown(MouseButton button) const {
  return mouseButtonsDown.find(button) != mouseButtonsDown.end();
}

bool Input::mouseButtonUp(MouseButton button) const {
  return mouseButtonsUp.find(button) != mouseButtonsUp.end();
}

bool Input::mouseButtonHold(MouseButton button) const {
  return mouseButtonsState.find(button) != mouseButtonsState.end();
}

KeyState Input::mouseState(MouseButton button) const {
  KeyState result = KeyState::None;
  if (mouseButtonDown(button)) {
    result |= KeyState::Down;
  }

  if (mouseButtonUp(button)) {
    result |= KeyState::Up;
  }

  if (mouseButtonHold(button)) {
    result |= KeyState::Hold;
  }
  return result;
}

void Input::setCursorMode(InputUtils::CursorMode mode) {
  if (mode == cursorMode)
    return;

  if (mode == CursorMode::Normal) {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
  } else if (mode == CursorMode::Hided) {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  }

  cursorMode = mode;

  double cursorX, cursorY;
  glfwGetCursorPos(window, &cursorX, &cursorY);

  mousePosition = { static_cast<float>(cursorX), static_cast<float>(cursorY) };
  mouseDeltaValue = {};
}
} // namespace VulkanEngine