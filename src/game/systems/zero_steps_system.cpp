#include "game/system/zero_steps_system.h"
#include "lib/ecs/system.h"
#include "lib/ecs/system_manager.h"
#include "game/components/player_component.h"
#include "game/components/steps_component.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<PlayerComponent>();
}
static bool IsGameOver(const Entity& entity) {
  return entity.Get<StepsComponent>()->count_ == 0;
}
void ZeroStepsSystem::ZeroSteps() {
  ctx_->scene_= "zero_steps";
}
void ZeroStepsSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity) && IsGameOver(entity)) {
      ZeroSteps();
    }
  }
}
ZeroStepsSystem::ZeroStepsSystem(EntityManager* entityManager, SystemManager* systemManager, Context* ctx)
    : ISystem(entityManager, systemManager), ctx_(ctx) {}
