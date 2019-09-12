#ifndef ECS_WINDOW_H
#define ECS_WINDOW_H

#include <BearLibTerminal.h>

class Windows {
 private:
  const char* title_ = "RoomEscape";
  int window_x_ = 21;
  int window_y_ = 17;
  bool fullscreen_ = true;

 public:
  void StartupSettings() {
    terminal_setf("window: cellsize=64x64, title='%s', size=%dx%d, fullscreen=%d", title_, window_x_, window_y_,
                  fullscreen_);
    terminal_set("font: ../resources/fonts/RussoOne-Regular.ttf, size=48");
  }
};
#endif  // ECS_WINDOW_H
