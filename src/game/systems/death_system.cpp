#include "game/system/death_system.h"
#include "game/components/health_component.h"
#include "game/components/player_component.h"
#include "lib/ecs/entity.h"
#include "lib/ecs/entity_manager.h"

static bool Filter(const Entity &entity) {
  return entity.Contains<PlayerComponent>();
}
static bool IsDeath(const Entity &entity) {
  auto hc = entity.Get<HealthComponent>();

  return hc->count_ <= 0;
}
void DeathSystem::OnUpdate() {
  for (auto &entity : GetEntityManager()) {
    if (Filter(entity) && IsDeath(entity)) {
      ctx_->scene_ = "death";
    }
  }
}
DeathSystem::DeathSystem(EntityManager *entityManager, SystemManager *systemManager, Context *ctx)
    : ISystem(entityManager, systemManager), ctx_(ctx) {}
