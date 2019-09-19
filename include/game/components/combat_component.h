#ifndef ECS_COMBAT_COMPONENT_H
#define ECS_COMBAT_COMPONENT_H

#include <lib/math/vec2.h>
#include <set>
#include "lib/ecs/component.h"

class Entity;

class CombatComponent : public IComponent {
  std::set<Entity*> enemies_{};

 public:
  Vec2 size_;
  Vec2 offset_;

  explicit CombatComponent(const Vec2& size, const Vec2& offset = ZeroVec2) : size_(size), offset_(offset) {}

  const std::set<Entity*>& GetEnemies() const {
    return enemies_;
  }

  bool AnyEnemies() const {
    return !enemies_.empty();
  }

  void Combat(Entity* entity) {
    enemies_.insert(entity);
  }

  void Clear() {
    enemies_.clear();
  }
};
#endif  // ECS_COMBAT_COMPONENT_H
