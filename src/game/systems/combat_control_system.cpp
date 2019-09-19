#include "game/system/combat_control_system.h"
#include <game/components/room_component.h>
#include "game/components/combat_component.h"
#include "game/components/damage_component.h"
#include "game/components/enimy_component.h"
#include "game/components/health_component.h"
#include "game/components/player_component.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<PlayerComponent>();
}
static bool IsCollision(const Entity& entity) {
  auto cc = entity.Get<CombatComponent>();

  for (const auto& enemy : cc->GetEnemies()) {
    if (enemy->Contains<EnimyComponent>()) {
      return true;
    }
  }
  return false;
}
void CombatControlSystem::Combat(const Entity& entity) {
  CheckCurrentRoom();
  auto cc = entity.Get<CombatComponent>();
  auto hc = entity.Get<HealthComponent>();
  auto dc = entity.Get<DamageComponent>();

  for (const auto& enemy : cc->GetEnemies()) {
    if (enemy->Get<EnimyComponent>()->id_room_ == current_room_ && enemy->Get<HealthComponent>()->count_ > 0) {
      // урон игроку
      hc->count_ -= enemy->Get<DamageComponent>()->getDamage();
      // урон персонажа
      enemy->Get<HealthComponent>()->count_ -= dc->getDamage();
    } else {
      engine.GetEntityManager()->DeleteEntity(enemy->GetId());
    }
  }
}
void CombatControlSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity) && IsCollision(entity)) {
      Combat(entity);
    }
  }
}
void CombatControlSystem::CheckCurrentRoom() {
  for (auto& room : GetEntityManager()) {
    if (room.Contains<RoomComponent>()) {
      if (room.Get<RoomComponent>()->current) current_room_ = room.GetId();
    }
  }
}
CombatControlSystem::CombatControlSystem(EntityManager* entityManager, SystemManager* systemManager,
                                         const Engine& engine)
    : ISystem(entityManager, systemManager), engine(engine) {}
