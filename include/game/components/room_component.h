#ifndef ECS_ROOM_COMPONENT_H
#define ECS_ROOM_COMPONENT_H

#include <lib/math/vec2.h>
#include "lib/ecs/component.h"

class RoomComponent : public IComponent {
 public:
  Vec2 pos_;
  explicit RoomComponent(const Vec2& pos) : pos_(pos) {}
};

#endif  // ECS_ROOM_COMPONENT_H
