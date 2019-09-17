#ifndef ECS_PLAYER_COINS_COMPONENT_H
#define ECS_PLAYER_COINS_COMPONENT_H

#include "lib/ecs/component.h"

class PlayerCoinsComponent : public IComponent {
 public:
  int coins_;
  explicit PlayerCoinsComponent(int coins) : coins_(coins) {}
};
#endif  // ECS_PLAYER_COINS_COMPONENT_H
