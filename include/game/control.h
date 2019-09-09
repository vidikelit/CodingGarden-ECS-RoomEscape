#ifndef ECS_CONTROL_H
#define ECS_CONTROL_H

#include <BearLibTerminal.h>
#include <map>
#include <vector>
class Controls {
  std::map<int, bool> is_pressed_{};

 public:
  void Press(int btn_key) {
    is_pressed_[btn_key] = true;
  }
  bool IsPressed(int btn_key) const {
    if (is_pressed_.count(btn_key) == 0) {
      return false;
    }
    return is_pressed_.at(btn_key);
  }
  void Reset() {
    for (auto& btn : is_pressed_) {
      btn.second = false;
    }
  }
  void OnUpdate() {
    while (terminal_has_input()) {
      auto key = terminal_read();
      is_pressed_[key] = true;
    }
  }
};

#endif  // ECS_CONTROL_H
