#ifndef ECS_GAME_DOOR_SYSTEM_H
#define ECS_GAME_DOOR_SYSTEM_H

#include "lib/math/vec2.h"
#include "lib/ecs/engine.h"
#include "lib/ecs/system.h"

class GameDoorSystem : public ISystem {
 private:
  Vec2 size_ = Vec2(21, 17);       // размер комнат

  const Engine& engine;

  void GenerateDoor();
 protected:
  void OnUpdate() override;
 public:
  GameDoorSystem(EntityManager *entityManager, SystemManager *systemManager, const Engine &engine);
};

#endif  // ECS_GAME_DOOR_SYSTEM_H
