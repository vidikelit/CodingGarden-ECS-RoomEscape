#ifndef ECS_COINS_COMPONENT_H
#define ECS_COINS_COMPONENT_H

#include "lib/ecs/component.h"

class CoinsComponent : public IComponent {
 public:
  int count_;
  explicit CoinsComponent(int count) : count_(count) {}
};
#endif  // ECS_COINS_COMPONENT_H
