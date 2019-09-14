#ifndef ECS_RENDER_SYSTEM_H
#define ECS_RENDER_SYSTEM_H

#include "lib/ecs/system.h"

class RenderSystem : public ISystem {
 protected:
  void OnPreUpdate() override;
  void OnUpdate() override;
  void OnPostUpdate() override;

 public:
  int current_room_;
  RenderSystem(EntityManager *entityManager, SystemManager *systemManager, int currentRoom);
};

#endif  // ECS_RENDER_SYSTEM_H
