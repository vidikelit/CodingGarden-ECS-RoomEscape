#include "game/system/game_enemy_system.h"
#include <experimental/random>
#include "game/components/collider_component.h"
#include "game/components/combat_component.h"
#include "game/components/damage_component.h"
#include "game/components/enimy_component.h"
#include "game/components/room_component.h"
#include "game/components/texture_component.h"
#include "game/components/transform_component.h"
#include "game/components/health_component.h"
#include "game/components/room_size_component.h"
#include "game/components/movement_component.h"

void GameEnemySystem::GenerateEnemy() {
  for (auto &room : GetEntityManager()) {
    if (room.Contains<RoomComponent>()) {
      for (int i = 0; i < std::experimental::randint(1, 2); i++) {
        auto enemy = engine.GetEntityManager()->CreateEntity();
        enemy->Add<TransformComponent>(Vec2(std::experimental::randint(3, 16), std::experimental::randint(9, 14)));
        enemy->Add<EnimyComponent>(room.GetId());
        enemy->Add<TextureComponent>('*');
        enemy->Add<ColliderComponent>(OnesVec2, ZeroVec2);
        enemy->Add<DamageComponent>(1, 3);
        enemy->Add<CombatComponent>(OnesVec2, ZeroVec2);
        enemy->Add<HealthComponent>(50);
        enemy->Add<RoomSizeComponent>();
        enemy->Add<MovementComponent>(1);
      }
    }
  }
}
void GameEnemySystem::OnUpdate() {
  GenerateEnemy();
  auto sys = engine.GetSystemManager();
  sys->Disable<GameEnemySystem>();
}
GameEnemySystem::GameEnemySystem(EntityManager *entityManager, SystemManager *systemManager, const Engine &engine)
    : ISystem(entityManager, systemManager), engine(engine) {}
