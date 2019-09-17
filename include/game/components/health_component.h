#ifndef ECS_PLAYER_HEALTH_COMPONENT_H
#define ECS_PLAYER_HEALTH_COMPONENT_H

#include "lib/ecs/component.h"

class PlayerHealthComponent : public IComponent {
 public:
  int health_;
  explicit PlayerHealthComponent(int health) : health_(health) {}
};

#endif  // ECS_PLAYER_HEALTH_COMPONENT_H
