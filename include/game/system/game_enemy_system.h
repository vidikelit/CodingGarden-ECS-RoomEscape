#ifndef ECS_GAME_ENEMY_SYSTEM_H
#define ECS_GAME_ENEMY_SYSTEM_H

#include "lib/ecs/engine.h"
#include "lib/ecs/system.h"
#include "lib/math/vec2.h"

class GameEnemySystem : public ISystem {
 private:
  const Engine &engine;
  void GenerateEnemy();

 protected:
  void OnUpdate() override;

 public:
  GameEnemySystem(EntityManager *entityManager, SystemManager *systemManager, const Engine &engine);
};

#endif  // ECS_GAME_ENEMY_SYSTEM_H
