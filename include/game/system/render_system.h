#ifndef ECS_RENDER_SYSTEM_H
#define ECS_RENDER_SYSTEM_H

#include "lib/ecs/system.h"

class RenderSystem : public ISystem {
 private:
  int current_room_;
  void CheckCurrentRoom();

 protected:
  void OnPreUpdate() override;
  void OnUpdate() override;
  void OnPostUpdate() override;

 public:
  RenderSystem(EntityManager *entityManager, SystemManager *systemManager);
};

#endif  // ECS_RENDER_SYSTEM_H
