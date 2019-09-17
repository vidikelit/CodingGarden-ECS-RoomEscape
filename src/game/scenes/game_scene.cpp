#include <BearLibTerminal.h>
#include <game/scenes/game_scene.h>

#include "game/system/collision_system.h"
#include "game/system/cross_room_system.h"
#include "game/system/game_coin_system.h"
#include "game/system/game_door_system.h"
#include "game/system/game_room_system.h"
#include "game/system/movement_control_system.h"
#include "game/system/obstacles_control_system.h"
#include "game/system/render_system.h"
#include "game/system/zero_steps_system.h"

#include "game/components/coins_component.h"
#include "game/components/collider_component.h"
#include "game/components/health_component.h"
#include "game/components/movement_component.h"
#include "game/components/obstacle_component.h"
#include "game/components/player_component.h"
#include "game/components/player_control_component.h"
#include "game/components/room_component.h"
#include "game/components/room_size_component.h"
#include "game/components/save_step_component.h"
#include "game/components/steps_component.h"
#include "game/components/texture_component.h"
#include "game/components/transform_component.h"

void GameScene::OnCreate() {
  {
    auto room = engine.GetEntityManager()->CreateEntity();
    room->Add<RoomComponent>(Vec2(0, 0), true);
  }
  {
    // игрок
    auto player = engine.GetEntityManager()->CreateEntity();
    player->Add<PlayerComponent>();
    player->Add<TransformComponent>(Vec2(10, 11));
    player->Add<SaveStepComponent>(Vec2(10, 11));
    player->Add<TextureComponent>('@');
    player->Add<ObstacleComponent>();
    player->Add<MovementComponent>(1);
    player->Add<PlayerControlComponent>(TK_UP, TK_DOWN, TK_LEFT, TK_RIGHT);
    player->Add<ColliderComponent>(OnesVec2, ZeroVec2);
    player->Add<RoomSizeComponent>();
    player->Add<HealthComponent>(100);
    player->Add<CoinsComponent>(0);
    player->Add<StepsComponent>(50);
  }
  {
    // стенка
    for (int i = 0; i < width_wall_; i++) {
      // верхняя
      auto wall_top = engine.GetEntityManager()->CreateEntity();
      wall_top->Add<TransformComponent>(Vec2(i, 6));
      wall_top->Add<TextureComponent>('#');
      wall_top->Add<ObstacleComponent>();
      wall_top->Add<ColliderComponent>(OnesVec2, ZeroVec2);
      // нижняя
      auto wall_bottom = engine.GetEntityManager()->CreateEntity();
      wall_bottom->Add<TransformComponent>(Vec2(i, 16));
      wall_bottom->Add<TextureComponent>('#');
      wall_bottom->Add<ObstacleComponent>();
      wall_bottom->Add<ColliderComponent>(OnesVec2, ZeroVec2);
    }
    for (int i = 0; i < hight_wall_; i++) {
      // левая
      auto wall_left = engine.GetEntityManager()->CreateEntity();
      wall_left->Add<TransformComponent>(Vec2(0, 7 + i));
      wall_left->Add<TextureComponent>('#');
      wall_left->Add<ObstacleComponent>();
      wall_left->Add<ColliderComponent>(OnesVec2, ZeroVec2);
      // правая
      auto wall_right = engine.GetEntityManager()->CreateEntity();
      wall_right->Add<TransformComponent>(Vec2(width_wall_ - 1, 7 + i));
      wall_right->Add<TextureComponent>('#');
      wall_right->Add<ObstacleComponent>();
      wall_right->Add<ColliderComponent>(OnesVec2, ZeroVec2);
    }
  }
  {
    auto sys = engine.GetSystemManager();
    sys->AddSystem<GameRoomSystem>(engine);
    engine.OnUpdate();
    sys->AddSystem<GameDoorSystem>(engine);
    sys->AddSystem<GameCoinSystem>(engine);
    sys->AddSystem<RenderSystem>();
    sys->AddSystem<CrossRoomSystem>(controls);
    sys->AddSystem<MovementControlSystem>(controls);
    sys->AddSystem<ObstaclesControlSystem>(engine);
    sys->AddSystem<CollisionSystem>();
    sys->AddSystem<ZeroStepsSystem>(ctx_);
  }
}
void GameScene::OnRender() {
  if (controls.IsPressed(TK_ESCAPE)) ctx_->scene_ = "menu";
  engine.OnUpdate();
}
void GameScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
GameScene::GameScene(Context* const ctx, const Engine& engine, const Controls& controls, Status* status)
    : IScene(ctx), engine(engine), controls(controls), status(status) {}
