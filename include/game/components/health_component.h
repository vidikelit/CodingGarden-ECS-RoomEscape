#ifndef ECS_HEALTH_COMPONENT_H
#define ECS_HEALTH_COMPONENT_H

#include "lib/ecs/component.h"

class HealthComponent : public IComponent {
 public:
  int count_;
  explicit HealthComponent(int count) : count_(count) {}
};

#endif  // ECS_HEALTH_COMPONENT_H
