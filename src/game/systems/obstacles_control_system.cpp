#include "game/system/obstacles_control_system.h"

#include "game/components/coin_component.h"
#include "game/components/coins_component.h"
#include "game/components/collider_component.h"
#include "game/components/obstacle_component.h"
#include "game/components/room_component.h"
#include "game/components/save_step_component.h"
#include "game/components/steps_component.h"
#include "game/components/transform_component.h"
#include "lib/ecs/entity_manager.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<ColliderComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<SaveStepComponent>();
}
static bool IsRollback(const Entity& entity) {
  auto cc = entity.Get<ColliderComponent>();

  for (const auto& collision : cc->GetCollisions()) {
    if (collision->Contains<ObstacleComponent>()) {
      return true;
    }
  }
  return false;
}
static void Rollback(const Entity& entity) {
  auto tc = entity.Get<TransformComponent>();
  auto ssc = entity.Get<SaveStepComponent>();

  tc->pos_.x = ssc->prev_step_.x;
  tc->pos_.y = ssc->prev_step_.y;
}
void ObstaclesControlSystem::OnUpdate() {
  CheckCurrentRoom();
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity)) {
      auto player_coins = entity.Get<CoinsComponent>();
      auto player_steps = entity.Get<StepsComponent>();
      for (const auto& coin : entity.Get<ColliderComponent>()->GetCollisions()) {
        if (coin->Contains<CoinComponent>() && coin->Get<CoinComponent>()->id_room_ == current_room_) {
          engine.GetEntityManager()->DeleteEntity(coin->GetId());
          player_coins->count_++;
          player_steps->count_ += 2;
        }
      }
    }
    if (Filter(entity) && IsRollback(entity)) {
      Rollback(entity);
    }
  }
}
void ObstaclesControlSystem::CheckCurrentRoom() {
  for (auto& room : GetEntityManager()) {
    if (room.Contains<RoomComponent>()) {
      if (room.Get<RoomComponent>()->current) current_room_ = room.GetId();
    }
  }
}
ObstaclesControlSystem::ObstaclesControlSystem(EntityManager* entityManager, SystemManager* systemManager,
                                               const Engine& engine)
    : ISystem(entityManager, systemManager), engine(engine) {}
