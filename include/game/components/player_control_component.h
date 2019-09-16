#ifndef ECS_PLAYER_CONTROL_COMPONENT_H
#define ECS_PLAYER_CONTROL_COMPONENT_H

#include "lib/ecs/component.h"

class PlayerControlComponent : public  IComponent {
 public:
  int up_button_;
  int down_button_;
  int left_button_;
  int right_button_;

  int e_button_;

  PlayerControlComponent(int upButton, int downButton, int leftButton, int rightButton, int eButton)
      : up_button_(upButton),
        down_button_(downButton),
        left_button_(leftButton),
        right_button_(rightButton),
        e_button_(eButton) {}
};
#endif  // ECS_PLAYER_CONTROL_COMPONENT_H
