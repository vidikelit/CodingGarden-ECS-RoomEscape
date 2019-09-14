#include "lib/ecs/entity.h"
#include "lib/ecs/entity_manager.h"

#include "game/components/collider_component.h"
#include "game/components/door_component.h"
#include "game/components/obstacle_component.h"
#include "game/components/room_component.h"
#include "game/components/texture_component.h"
#include "game/components/transform_component.h"
#include "game/math-utils.h"
#include "game/system/game_door_system.h"

static bool Filter(const Entity &entity) {
  return entity.Contains<RoomComponent>();
}
void GameDoorSystem::GenerateDoor() {
  for (auto &entity1 : GetEntityManager()) {
    if (Filter(entity1)) {
      for (auto &entity2 : GetEntityManager()) {
        if (Filter(entity2)) {
          auto rc1 = entity1.Get<RoomComponent>();
          auto rc2 = entity2.Get<RoomComponent>();

          if (abs(abs(ToPos(rc1->pos_.y)) - abs(ToPos(rc2->pos_.y))) == ToPos(size_.y) &&
              ToPos(rc1->pos_.x) == ToPos(rc2->pos_.x)) {
            // вверх
            if (ToPos(rc1->pos_.y) > ToPos(rc2->pos_.y)) {
              auto door = engine.GetEntityManager()->CreateEntity();
              door->Add<DoorComponent>(entity1.GetId());
              door->Add<TransformComponent>(Vec2(10, 6));
              door->Add<TextureComponent>('>');
              door->Add<ObstacleComponent>();
              door->Add<ColliderComponent>(OnesVec2, ZeroVec2);
            }
            // вниз
            if (ToPos(rc1->pos_.y) < ToPos(rc2->pos_.y)) {
              auto door = engine.GetEntityManager()->CreateEntity();
              door->Add<DoorComponent>(entity1.GetId());
              door->Add<TransformComponent>(Vec2(10, 16));
              door->Add<TextureComponent>('>');
              door->Add<ObstacleComponent>();
              door->Add<ColliderComponent>(OnesVec2, ZeroVec2);
            }
          }
          if (abs(abs(ToPos(rc1->pos_.x)) - abs(ToPos(rc2->pos_.x))) == ToPos(size_.x) &&
              ToPos(rc1->pos_.y) == ToPos(rc2->pos_.y)) {
            // влево
            if (ToPos(rc1->pos_.x) > ToPos(rc2->pos_.x)) {
              auto door = engine.GetEntityManager()->CreateEntity();
              door->Add<DoorComponent>(entity1.GetId());
              door->Add<TransformComponent>(Vec2(0, 11));
              door->Add<TextureComponent>('>');
              door->Add<ObstacleComponent>();
              door->Add<ColliderComponent>(OnesVec2, ZeroVec2);
            }
            // вправо
            if (ToPos(rc1->pos_.x) < ToPos(rc2->pos_.x)) {
              auto door = engine.GetEntityManager()->CreateEntity();
              door->Add<DoorComponent>(entity1.GetId());
              door->Add<TransformComponent>(Vec2(20, 11));
              door->Add<TextureComponent>('>');
              door->Add<ObstacleComponent>();
              door->Add<ColliderComponent>(OnesVec2, ZeroVec2);
            }
          }
        }
      }
    }
  }
}
void GameDoorSystem::OnUpdate() {
  GenerateDoor();
  auto sys = engine.GetSystemManager();
  sys->Disable<GameDoorSystem>();
}
GameDoorSystem::GameDoorSystem(EntityManager *entityManager, SystemManager *systemManager, const Engine &engine)
    : ISystem(entityManager, systemManager), engine(engine) {}
