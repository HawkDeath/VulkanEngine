#pragma once

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <unordered_set>

#include "InputUtils.h"

namespace VulkanEngine {
class Input final {
  friend class Window;

public:
  // Keyboard
  bool keyDown(InputUtils::Key key) const;
  bool keyUp(InputUtils::Key key) const;
  bool keyHold(InputUtils::Key key) const;
  InputUtils::KeyState keyState(InputUtils::Key key) const;

  // Mouse
  bool mouseButtonDown(InputUtils::MouseButton button) const;
  bool mouseButtonUp(InputUtils::MouseButton button) const;
  bool mouseButtonHold(InputUtils::MouseButton button) const;
  InputUtils::KeyState mouseState(InputUtils::MouseButton button) const;

  glm::vec2 mouseDelta() const { return mMouseDeltaValue; }
  void setCursorMode(InputUtils::CursorMode mode);

private:
  Input(GLFWwindow *window);

  GLFWwindow *mWindow;

  void handleKeyInput(int key, int scancode, int action, int mods);
  void handleMousePosition(double xPos, double yPos);
  void handleMouseButton(int mouseButton, int aciton, int modes);

  void reset();

private:
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