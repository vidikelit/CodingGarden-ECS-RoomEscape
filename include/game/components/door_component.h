#ifndef ECS_DOOR_COMPONENT_H
#define ECS_DOOR_COMPONENT_H

#include "game/components/door_component.h"
#include "lib/ecs/component.h"
#include "lib/math/vec2.h"

class DoorComponent : public IComponent {
 public:
  int id_room_;
  explicit DoorComponent(int idRoom) : id_room_(idRoom) {}
};
#endif  // ECS_DOOR_COMPONENT_H
