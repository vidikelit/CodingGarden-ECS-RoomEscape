#include "game/system/enemy_movement_system.h"
#include <experimental/random>
#include "game/components/enimy_component.h"
#include "game/components/movement_component.h"
#include "game/components/room_component.h"
#include "game/components/transform_component.h"
#include "lib/ecs/entity.h"
#include "lib/ecs/entity_manager.h"

static bool Filter(const Entity &entity) {
  return entity.Contains<EnimyComponent>();
}
void EnemyMovementSystem::OnUpdateEntity(Entity *entity) {
  auto mc = entity->Get<MovementComponent>();
  auto tc = entity->Get<TransformComponent>();
  CheckCurrentRoom();
  if (entity->Get<EnimyComponent>()->id_room_ == current_room_) {
    if (controls_.IsPressed(TK_UP) || controls_.IsPressed(TK_DOWN) || controls_.IsPressed(TK_LEFT) ||
        controls_.IsPressed(TK_RIGHT)) {
      int random = std::experimental::randint(0, 4);
      if (random == 0) tc->pos_.x += mc->speed_;
      if (random == 1) tc->pos_.x -= mc->speed_;
      if (random == 2) tc->pos_.y += mc->speed_;
      if (random == 3) tc->pos_.y -= mc->speed_;
      if (random == 4) tc->pos_.x = tc->pos_.x;

      if (tc->pos_.x <= 0) {
        tc->pos_.x++;
      }
      if (tc->pos_.x >= 19) {
        tc->pos_.x--;
      }
      if (tc->pos_.y <= 6) {
        tc->pos_.y++;
      }
      if (tc->pos_.y >= 15) {
        tc->pos_.y--;
      }
    }
  }
}
void EnemyMovementSystem::OnUpdate() {
  for (auto &entity : GetEntityManager()) {
    if (Filter(entity)) {
      OnUpdateEntity(&entity);
    }
  }
}
void EnemyMovementSystem::CheckCurrentRoom() {
  for (auto &room : GetEntityManager()) {
    if (room.Contains<RoomComponent>()) {
      if (room.Get<RoomComponent>()->current) current_room_ = room.GetId();
    }
  }
}
EnemyMovementSystem::EnemyMovementSystem(EntityManager *entityManager, SystemManager *systemManager,
                                         const Controls &controls)
    : ISystem(entityManager, systemManager), controls_(controls) {}
