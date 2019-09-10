#ifndef ECS_COLLIDER_COMPONENT_H
#define ECS_COLLIDER_COMPONENT_H

#include <lib/math/vec2.h>
#include <set>
#include "lib/ecs/component.h"

class Entity;

class ColliderComponent : public IComponent {
  std::set<Entity*> collisions_{};

 public:
  Vec2 size_;
  Vec2 offset_;

  explicit ColliderComponent(const Vec2& size, const Vec2& offset = ZeroVec2) : size_(size), offset_(offset) {}

  const std::set<Entity*>& GetCollisions() const {
    return collisions_;
  }

  bool AnyCollisions() const {
    return !collisions_.empty();
  }

  void Collide(Entity* entity) {
    collisions_.insert(entity);
  }

  void Clear() {
    collisions_.clear();
  }
};
#endif  // ECS_COLLIDER_COMPONENT_H
