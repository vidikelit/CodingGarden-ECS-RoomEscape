#include "game/scenes/menu_scene.h"
#include "game/components/menu_component.h"
#include "game/system/game_menu_system.h"

void MenuScene::OnCreate() {
  {
    auto menu = engine.GetEntityManager()->CreateEntity();
    menu->Add<MenuComponent>();
  }
  {
    auto sys = engine.GetSystemManager();
    sys->AddSystem<GameMenuSystem>(controls, status);
  }
}
void MenuScene::OnRender() {
  engine.OnUpdate();
  if (status->isNewGame()) {
    status->setNewGame(false);
    ctx_->scene_ = "game";
  }
}
void MenuScene::OnExit() {
  engine.GetSystemManager()->DeleteAll();
}
MenuScene::MenuScene(Context* const ctx, const Engine& engine, const Controls& controls, Status* status)
    : IScene(ctx), engine(engine), controls(controls), status(status) {}
