#ifndef ECS_STEPS_COMPONENT_H
#define ECS_STEPS_COMPONENT_H
#include "lib/ecs/component.h"

class StepsComponent : public IComponent {
 public:
  int count_;
  explicit StepsComponent(int count) : count_(count) {}
};
#endif  // ECS_STEPS_COMPONENT_H
