#include "game/system/movement_control_system.h"
#include "game/components/movement_component.h"
#include "game/components/player_control_component.h"
#include "game/components/transform_component.h"
#include "lib/ecs/entity.h"
#include "lib/ecs/entity_manager.h"

static bool Filter(const Entity &entity) {
  return entity.Contains<MovementComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<PlayerControlComponent>();
}

void MovementControlSystem::OnUpdateEntity(Entity *entity) const {
  auto mc = entity->Get<MovementComponent>();
  auto pcc = entity->Get<PlayerControlComponent>();
  auto tc = entity->Get<TransformComponent>();

  if (controls_.IsPressed(pcc->up_button_))
    tc->pos_.y -= mc->speed_;
  if (controls_.IsPressed(pcc->down_button_))
    tc->pos_.y += mc->speed_;
  if (controls_.IsPressed(pcc->left_button_))
    tc->pos_.x -= mc->speed_;
  if (controls_.IsPressed(pcc->right_button_))
    tc->pos_.x += mc->speed_;
}

void MovementControlSystem::OnUpdate() {
  for (auto &entity : GetEntityManager()) {
    if (Filter(entity)) {
      OnUpdateEntity(&entity);
    }
  }
}
MovementControlSystem::MovementControlSystem(EntityManager *entityManager, SystemManager *systemManager,
                                             const Controls &controls)
    : ISystem(entityManager, systemManager), controls_(controls) {}
