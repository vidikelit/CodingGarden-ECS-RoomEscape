#include <BearLibTerminal.h>
#include <game/scenes/game_scene.h>
#include "game/components/movement_component.h"
#include "game/components/player_control_component.h"
#include "game/components/transform_component.h"
#include "game/components/texture_component.h"
#include "game/system/movement_control_system.h"
#include "game/system/render_system.h"

void GameScene::OnCreate() {
  auto player = engine.GetEntityManager()->CreateEntity();
  player->Add<TransformComponent>(Vec2(10, 10));
  player->Add<TextureComponent>('@');
  player->Add<MovementComponent>(1);
  player->Add<PlayerControlComponent>(TK_UP, TK_DOWN, TK_LEFT, TK_RIGHT);

  auto sys = engine.GetSystemManager();
  sys->AddSystem<RenderSystem>();
  sys->AddSystem<MovementControlSystem>(controls);
}
void GameScene::OnRender() {
  engine.OnUpdate();
}
void GameScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
GameScene::GameScene(Context* const ctx, const Controls& controls) : IScene(ctx), controls(controls) {}
