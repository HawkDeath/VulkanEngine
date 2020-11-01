#include "Input.h"

using VulkanEngine::InputUtils::CursorMode;
using VulkanEngine::InputUtils::Key;
using VulkanEngine::InputUtils::KeyState;
using VulkanEngine::InputUtils::MouseButton;

namespace VulkanEngine {
Input::Input(GLFWwindow *window_) : mWindow(window_) {}

void Input::handleKeyInput(int inKey, int scancode, int action, int mods) {
  const Key key = static_cast<Key>(inKey);
  auto it = mKeysStates.find(key);

  if (it == mKeysStates.end()) { // key is not pressed
    if (action == GLFW_PRESS) {
      auto data = mKeysStates.insert(key);

      if (data.second) {
        mKeysDown.insert(key);
      }
    }
  } else { // key is pressed
    if (action == GLFW_RELEASE) {
      auto itPressKey = mKeysStates.find(key); // find key if pressed

      if (itPressKey != mKeysStates.end()) {
        mKeysStates.erase(itPressKey);
        mKeysUp.insert(key);
      }
    }
  }
}

void Input::handleMousePosition(double xPos, double yPos) {
  glm::vec2 newPosition = {static_cast<float>(xPos), static_cast<float>(yPos)};

  mMouseDeltaValue = newPosition - mMousePosition;
  mMousePosition = newPosition;
}

void Input::handleMouseButton(int mouseButton, int action, int modes) {
  const MouseButton button = static_cast<MouseButton>(mouseButton);
  auto it = mMouseButtonsState.find(button);

  if (it == mMouseButtonsState.end()) { // button is not pressed
    if (action == GLFW_PRESS) {
      auto data = mMouseButtonsState.insert(button);

      if (data.second) {
        mMouseButtonsDown.insert(button);
      }
    }
  } else { // button is pressed
    if (action == GLFW_RELEASE) {
      auto itPressKey =
          mMouseButtonsState.find(button); // find button if pressed

      if (itPressKey != mMouseButtonsState.end()) {
        mMouseButtonsState.erase(itPressKey);
        mMouseButtonsUp.insert(button);
      }
    }
  }
}

void Input::reset() {
  mMouseDeltaValue = {};

  mKeysDown.clear();
  mKeysUp.clear();

  mMouseButtonsDown.clear();
  mMouseButtonsUp.clear();
}

bool Input::keyDown(Key key) const {
  return mKeysDown.find(key) != mKeysDown.end();
}

bool Input::keyUp(Key key) const { return mKeysUp.find(key) != mKeysUp.end(); }

bool Input::keyHold(Key key) const {
  return mKeysStates.find(key) != mKeysStates.end();
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
  return mMouseButtonsDown.find(button) != mMouseButtonsDown.end();
}

bool Input::mouseButtonUp(MouseButton button) const {
  return mMouseButtonsUp.find(button) != mMouseButtonsUp.end();
}

bool Input::mouseButtonHold(MouseButton button) const {
  return mMouseButtonsState.find(button) != mMouseButtonsState.end();
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
  if (mode == mCursorMode)
    return;

  if (mode == CursorMode::Normal) {
    glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
  } else if (mode == CursorMode::Hided) {
    glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  }

  mCursorMode = mode;

  double cursorX, cursorY;
  glfwGetCursorPos(mWindow, &cursorX, &cursorY);

  mMousePosition = {static_cast<float>(cursorX), static_cast<float>(cursorY)};
  mMouseDeltaValue = {};
}
} // namespace VulkanEngine