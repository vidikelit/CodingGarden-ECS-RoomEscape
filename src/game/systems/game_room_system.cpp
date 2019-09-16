#include <experimental/random>

#include "lib/ecs/entity.h"
#include "lib/ecs/entity_manager.h"

#include "game/components/room_component.h"
#include "game/math-utils.h"
#include "game/system/game_room_system.h"

static bool Filter(const Entity &entity) {
  return entity.Contains<RoomComponent>();
}
void GameRoomSystem::GenerateRoom() {
  for (int i = 0; i < std::experimental::randint(ToPos(rage_rooms_.x), ToPos(rage_rooms_.y)); i++) {
    float x = map_.x;
    float y = map_.y;
    GenerateCoordinates();
    bool a = true;
    while (a) {
      a = false;
      for (auto &entity : GetEntityManager()) {
        if (Filter(entity)) {
          if (ToPos(entity.Get<RoomComponent>()->pos_.x) == ToPos(map_.x) &&
              ToPos(entity.Get<RoomComponent>()->pos_.y) == ToPos(map_.y)) {
            map_.x = x;
            map_.y = y;
            GenerateCoordinates();
            a = true;
          }
        }
      }
    }
    auto room = engine.GetEntityManager()->CreateEntity();
    room->Add<RoomComponent>(Vec2(map_.x, map_.y), false);
  }
}
void GameRoomSystem::GenerateCoordinates() {
  int random = std::experimental::randint(1, 100);
  // вверх
  if (random <= 25) map_.y = map_.y - size_.y;
  // вниз
  if (random > 25 && random <= 50) map_.y = map_.y + size_.y;
  // влево
  if (random > 50 && random <= 75) map_.x = map_.x - size_.x;
  // вправо
  if (random > 75) map_.x = map_.x + size_.x;
}
void GameRoomSystem::OnUpdate() {
  GenerateRoom();
  auto sys = engine.GetSystemManager();
  sys->Disable<GameRoomSystem>();
}
GameRoomSystem::GameRoomSystem(EntityManager *entityManager, SystemManager *systemManager, const Engine &engine)
    : ISystem(entityManager, systemManager), engine(engine) {}
