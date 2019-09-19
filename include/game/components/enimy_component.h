#ifndef ECS_ENIMY_COMPONENT_H
#define ECS_ENIMY_COMPONENT_H

#include "lib/ecs/component.h"

class EnimyComponent : public IComponent {
 public:
  int id_room_;
  explicit EnimyComponent(int idRoom) : id_room_(idRoom) {}
};

#endif  // ECS_ENIMY_COMPONENT_H
