#ifndef ECS_DEATH_SYSTEM_H
#define ECS_DEATH_SYSTEM_H

#include "lib/ecs/system.h"
#include "lib/scenes/context.h"

class DeathSystem : public ISystem {
 protected:
  Context* ctx_;

 protected:
  void OnUpdate() override;

 public:
  DeathSystem(EntityManager *entityManager, SystemManager *systemManager, Context *ctx);
};

#endif  // ECS_DEATH_SYSTEM_H
