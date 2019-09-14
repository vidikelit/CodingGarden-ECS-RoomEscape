#include "game/system/obstacles_control_system.h"

#include "game/components/collider_component.h"
#include "game/components/obstacle_component.h"
#include "game/components/save_step_component.h"
#include "game/components/transform_component.h"
#include "lib/ecs/entity_manager.h"
#include "game/math-utils.h"

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
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity) && IsRollback(entity)) {
      Rollback(entity);
    }
  }
}
ObstaclesControlSystem::ObstaclesControlSystem(EntityManager* entityManager, SystemManager* systemManager)
    : ISystem(entityManager, systemManager) {}
