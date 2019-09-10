#include "game/system/movement_control_system.h"
#include "game/components/movement_component.h"
#include "game/components/player_control_component.h"
#include "game/components/save_step_component.h"
#include "game/components/transform_component.h"
#include "lib/ecs/entity.h"
#include "lib/ecs/entity_manager.h"

static bool Filter(const Entity &entity) {
  return entity.Contains<MovementComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<PlayerControlComponent>();
}

void MovementControlSystem::OnUpdateEntity(Entity *entity) const {
  auto mc = entity->Get<MovementComponent>();
  auto tc = entity->Get<TransformComponent>();
  auto pcc = entity->Get<PlayerControlComponent>();
  auto ssc = entity->Get<SaveStepComponent>();

  if (controls_.IsPressed(pcc->up_button_)) {
    ssc->prev_step_.x = tc->pos_.x;
    ssc->prev_step_.y = tc->pos_.y;
    tc->pos_.y -= mc->speed_;
  }
  if (controls_.IsPressed(pcc->down_button_)) {
    ssc->prev_step_.x = tc->pos_.x;
    ssc->prev_step_.y = tc->pos_.y;
    tc->pos_.y += mc->speed_;
  }
  if (controls_.IsPressed(pcc->left_button_))  {
    ssc->prev_step_.x = tc->pos_.x;
    ssc->prev_step_.y = tc->pos_.y;
    tc->pos_.x -= mc->speed_;
  }
  if (controls_.IsPressed(pcc->right_button_)) {
    ssc->prev_step_.x = tc->pos_.x;
    ssc->prev_step_.y = tc->pos_.y;
    tc->pos_.x += mc->speed_;
  }
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
