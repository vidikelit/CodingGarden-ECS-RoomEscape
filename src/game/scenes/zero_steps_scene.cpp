#include <BearLibTerminal.h>
#include "game/scenes/zero_steps_scene.h"

void ZeroStepsScene::OnCreate() {}
void ZeroStepsScene::OnRender() {
  terminal_clear();
  terminal_print(1, 1, "Закончились шаги\nPress Enter");
  if (controls.IsPressed(TK_ENTER)) ctx_->scene_ = "menu";
  terminal_refresh();
}
void ZeroStepsScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
ZeroStepsScene::ZeroStepsScene(Context* const ctx, const Engine& engine, const Controls& controls)
    : IScene(ctx), engine(engine), controls(controls) {}
