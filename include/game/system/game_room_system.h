#ifndef ECS_GAME_ROOM_SYSTEM_H
#define ECS_GAME_ROOM_SYSTEM_H

#include "lib/math/vec2.h"
#include "lib/ecs/engine.h"
#include "lib/ecs/system.h"

class GameRoomSystem : public ISystem {
 private:
  Vec2 map_ = Vec2(0, 0);          // временные координаты
  Vec2 size_ = Vec2(21, 17);       // размер комнат
  Vec2 rage_rooms_ = Vec2(1, 5);  // диапазон количества комнат

  const Engine& engine;

  void GenerateRoom();
  void GenerateCoordinates();

 protected:
  void OnUpdate() override;

 public:
  GameRoomSystem(EntityManager *entityManager, SystemManager *systemManager, const Engine &engine);
};

#endif  // ECS_GAME_ROOM_SYSTEM_H
