#include "game/system/endgame_system.h"
#include "game/components/coin_component.h"
#include "lib/ecs/entity_manager.h"

void EndGameSystem::OnUpdate() {
  CheckCoin();
  if (coin_count_ == 0) {
    ctx_->scene_ = "endgame";
  }
}
void EndGameSystem::CheckCoin() {
  coin_count_ = 0;
  for (auto &entity : GetEntityManager()) {
    if (entity.Contains<CoinComponent>()) {
      coin_count_++;
    }
  }
}
EndGameSystem::EndGameSystem(EntityManager *entityManager, SystemManager *systemManager, Context *ctx)
    : ISystem(entityManager, systemManager), ctx_(ctx) {}
