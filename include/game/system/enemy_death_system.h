#ifndef ECS_ENEMY_DEATH_SYSTEM_H
#define ECS_ENEMY_DEATH_SYSTEM_H

#include <lib/ecs/engine.h>
#include "lib/ecs/system.h"

class EnemyDeathSystem : public ISystem {
 private:
  const Engine &engine;

 protected:
  void OnUpdate() override;

 public:
  EnemyDeathSystem(EntityManager *entityManager, SystemManager *systemManager, const Engine &engine);
};

#endif  // ECS_ENEMY_DEATH_SYSTEM_H
