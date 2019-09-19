#ifndef ECS_ENEMY_MOVEMENT_SYSTEM_H
#define ECS_ENEMY_MOVEMENT_SYSTEM_H

#include "game/control.h"
#include "lib/ecs/system.h"

class Entity;

class EnemyMovementSystem : public ISystem {
 private:
  int current_room_;
  const Controls& controls_;
  void OnUpdateEntity(Entity* entity);
  void CheckCurrentRoom();

 protected:
  void OnUpdate() override;

 public:
  EnemyMovementSystem(EntityManager* entityManager, SystemManager* systemManager, const Controls& controls);
};

#endif  // ECS_ENEMY_MOVEMENT_SYSTEM_H
