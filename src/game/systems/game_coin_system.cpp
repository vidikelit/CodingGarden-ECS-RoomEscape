#include <experimental/random>

#include "game/system/game_coin_system.h"
#include "game/components/room_component.h"
#include "game/components/coin_component.h"
#include "game/components/collider_component.h"
#include "game/components/texture_component.h"
#include "game/components/transform_component.h"

#include "lib/ecs/entity_manager.h"

void GameCoinSystem::GenerateCoin() {
  for (auto &room : GetEntityManager()) {
    if (room.Contains<RoomComponent>()) {
      for (int i = 0; i < std::experimental::randint(1, 4); i++) {
        auto door = engine.GetEntityManager()->CreateEntity();
        door->Add<TransformComponent>(Vec2(std::experimental::randint(3, 16), std::experimental::randint(9, 14)));
        door->Add<CoinComponent>(room.GetId());
        door->Add<TextureComponent>('$');
        door->Add<ColliderComponent>(OnesVec2, ZeroVec2);
      }
    }
  }
}
void GameCoinSystem::OnUpdate() {
  GenerateCoin();
  auto sys = engine.GetSystemManager();
  sys->Disable<GameCoinSystem>();
}
GameCoinSystem::GameCoinSystem(EntityManager *entityManager, SystemManager *systemManager, const Engine &engine)
    : ISystem(entityManager, systemManager), engine(engine) {}
