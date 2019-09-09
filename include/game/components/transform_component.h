#ifndef ECS_TRANSFORM_COMPONENT_H
#define ECS_TRANSFORM_COMPONENT_H

#include <lib/ecs/component.h>
#include <lib/math/vec2.h>

class TransformComponent : public IComponent {
 public:
  Vec2 pos_;

  explicit TransformComponent(const Vec2& pos) : pos_(pos) {}
};
#endif  // ECS_TRANSFORM_COMPONENT_H
