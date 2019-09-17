#include <BearLibTerminal.h>
#include "game/scenes/zero_steps_scene.h"

void ZeroStepsScene::OnCreate() {}
void ZeroStepsScene::OnRender() {
  terminal_clear();
  terminal_print(1, 1, "Game Over\nPress Enter");
  terminal_refresh();
  if (controls.IsPressed(TK_ENTER)) {
    engine.GetEntityManager()->DeleteAll();
    engine.GetSystemManager()->DeleteAll();
    ctx_->scene_ = "menu";
  }
}
void ZeroStepsScene::OnExit() {
  engine.OnUpdate();
}
ZeroStepsScene::ZeroStepsScene(Context* const ctx, const Engine& engine, const Controls& controls)
    : IScene(ctx), engine(engine), controls(controls) {}
