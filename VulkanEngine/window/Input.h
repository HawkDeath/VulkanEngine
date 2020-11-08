#pragma once

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <functional>
#include <unordered_map>
#include <unordered_set>

#include "InputUtils.h"

namespace VulkanEngine {
class Input final {
  friend class Window;

public:
  // Keyboard
  bool keyDown(InputUtils::Key key) const noexcept;
  bool keyUp(InputUtils::Key key) const noexcept;
  bool keyHold(InputUtils::Key key) const noexcept;
  InputUtils::KeyState keyState(InputUtils::Key key) const noexcept;

  // Mouse
  bool mouseButtonDown(InputUtils::MouseButton button) const noexcept;
  bool mouseButtonUp(InputUtils::MouseButton button) const noexcept;
  bool mouseButtonHold(InputUtils::MouseButton button) const noexcept;
  InputUtils::KeyState
  mouseState(InputUtils::MouseButton button) const noexcept;

  glm::vec2 mouseDelta() const noexcept { return mMouseDeltaValue; }
  void setCursorMode(InputUtils::CursorMode mode);

  void reg(InputUtils::Key key, std::function<bool()> func) {
    keyboardCallbacks.insert(std::make_pair(key, func));
  }

private:
  Input(GLFWwindow *window);

  GLFWwindow *mWindow;

  void handleKeyInput(int key, int scancode, int action, int mods);
  void handleMousePosition(double xPos, double yPos);
  void handleMouseButton(int mouseButton, int aciton, int modes);

  void reset();

  void update() {
    if (mKeysDown.empty())
      return;
    for (auto &key : mKeysDown) {
      auto action = keyboardCallbacks.find(key);
      if (action != keyboardCallbacks.end()) {
        action->second();
      }
    }
  }

private:
  // Callbacks
  std::unordered_map < InputUtils::Key, std::function<bool()>> keyboardCallbacks;

  // Keyboard
  std::unordered_set<InputUtils::Key> mKeysStates;
  std::unordered_set<InputUtils::Key> mKeysDown;
  std::unordered_set<InputUtils::Key> mKeysUp;

  // Mouse
  std::unordered_set<InputUtils::MouseButton> mMouseButtonsState;
  std::unordered_set<InputUtils::MouseButton> mMouseButtonsDown;
  std::unordered_set<InputUtils::MouseButton> mMouseButtonsUp;

  InputUtils::CursorMode mCursorMode;
  glm::vec2 mMousePosition;
  glm::vec2 mMouseDeltaValue;
};

static inline InputUtils::KeyState
operator|(const InputUtils::KeyState &left, const InputUtils::KeyState &right) {
  return static_cast<InputUtils::KeyState>(static_cast<std::int8_t>(left) |
                                           static_cast<std::int8_t>(right));
}

static inline InputUtils::KeyState operator|=(InputUtils::KeyState &left,
                                              InputUtils::KeyState right) {
  left = left | right;
  return left;
}

static inline InputUtils::KeyState
operator&(const InputUtils::KeyState &left, const InputUtils::KeyState &right) {
  return static_cast<InputUtils::KeyState>(static_cast<std::int8_t>(left) &
                                           static_cast<std::int8_t>(right));
}

static inline InputUtils::KeyState operator&=(InputUtils::KeyState &left,
                                              InputUtils::KeyState right) {
  left = left & right;
  return left;
}

} // namespace VulkanEngine