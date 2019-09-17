#ifndef ECS_COIN_COMPONENT_H
#define ECS_COIN_COMPONENT_H

#include "lib/ecs/component.h"
#include "lib/math/vec2.h"

class CoinComponent : public IComponent {
 public:
  int id_room_;
  explicit CoinComponent(int idRoom) : id_room_(idRoom) {}
};
#endif  // ECS_COIN_COMPONENT_H
