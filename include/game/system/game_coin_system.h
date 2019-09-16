#ifndef ECS_GAME_COIN_SYSTEM_H
#define ECS_GAME_COIN_SYSTEM_H

#include "lib/ecs/engine.h"
#include "lib/ecs/system.h"
#include "lib/math/vec2.h"

class GameCoinSystem : public ISystem {
 private:
  const Engine &engine;
  void GenerateCoin();

 protected:
  void OnUpdate() override;

 public:
  GameCoinSystem(EntityManager *entityManager, SystemManager *systemManager, const Engine &engine);
};

#endif  // ECS_GAME_COIN_SYSTEM_H
