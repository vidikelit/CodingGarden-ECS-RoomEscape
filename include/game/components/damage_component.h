#ifndef ECS_DAMAGE_COMPONENT_H
#define ECS_DAMAGE_COMPONENT_H

#include <experimental/random>
#include "lib/ecs/component.h"
#include "game/math-utils.h"

class DamageComponent : public IComponent {
 public:
  float min_damage_;
  float max_damage_;

  int getDamage() {
    return ToPos(max_damage_ + std::experimental::randint(1, 5) * (max_damage_ - min_damage_));
  }

  DamageComponent(float minDamage, float maxDamage) : min_damage_(minDamage), max_damage_(maxDamage) {}
};

#endif  // ECS_DAMAGE_COMPONENT_H
