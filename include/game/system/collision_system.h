#ifndef ECS_COLLISION_SYSTEM_H
#define ECS_COLLISION_SYSTEM_H

#include "lib/ecs/system.h"

class CollisionSystem: public ISystem {
 public:
  CollisionSystem(EntityManager *entityManager, SystemManager *systemManager);

 protected:
  void OnUpdate() override;
};
#endif  // ECS_COLLISION_SYSTEM_H
