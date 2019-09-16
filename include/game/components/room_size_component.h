#ifndef ECS_ROOM_SIZE_COMPONENT_H
#define ECS_ROOM_SIZE_COMPONENT_H

#include <lib/math/vec2.h>
#include "lib/ecs/component.h"

class RoomSizeComponent : public IComponent {
 public:
  Vec2 size_ = Vec2(21, 17);
};

#endif  // ECS_ROOM_SIZE_COMPONENT_H
