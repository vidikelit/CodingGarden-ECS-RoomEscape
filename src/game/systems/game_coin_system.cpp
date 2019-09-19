#include <experimental/random>

#include "game/components/coin_component.h"
#include "game/components/collider_component.h"
#include "game/components/room_component.h"
#include "game/components/texture_component.h"
#include "game/components/transform_component.h"
#include "game/components/room_size_component.h"
#include "game/system/game_coin_system.h"

#include "lib/ecs/entity_manager.h"

void GameCoinSystem::GenerateCoin() {
  for (auto &room : GetEntityManager()) {
    if (room.Contains<RoomComponent>()) {
      for (int i = 0; i < std::experimental::randint(1, 4); i++) {
        auto coin = engine.GetEntityManager()->CreateEntity();
        coin->Add<TransformComponent>(Vec2(std::experimental::randint(3, 16), std::experimental::randint(9, 14)));
        coin->Add<CoinComponent>(room.GetId());
        coin->Add<TextureComponent>('$');
        coin->Add<ColliderComponent>(OnesVec2, ZeroVec2);
        coin->Add<RoomSizeComponent>();
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
