#ifndef ECS_ENEMY_COLLISION_SYSTEM_H
#define ECS_ENEMY_COLLISION_SYSTEM_H

#include "lib/ecs/system.h"

class EnemyCollisionSystem : public ISystem {
 protected:
  void OnUpdate() override;

 public:
  EnemyCollisionSystem(EntityManager *entityManager, SystemManager *systemManager);
};

#endif  // ECS_ENEMY_COLLISION_SYSTEM_H
