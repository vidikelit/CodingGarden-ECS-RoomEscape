#ifndef ECS_MOVEMENT_COMPONENT_H
#define ECS_MOVEMENT_COMPONENT_H

#include "lib/ecs/component.h"

class MovementComponent : public IComponent {
 public:
  float speed_;        // скорость предвежения
  float max_speed_x_;  // максимальная скорость по х
  float max_speed_y;   // максимальная скорость по y

  explicit MovementComponent(float speed) : speed_(speed) {}
};

#endif  // ECS_MOVEMENT_COMPONENT_H
