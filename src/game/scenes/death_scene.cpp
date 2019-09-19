#include "game/scenes/death_scene.h"
#include <BearLibTerminal.h>

void DeathScene::OnCreate() {}
void DeathScene::OnRender() {
  terminal_clear();
  terminal_print(1, 1, "Вас убили! \nPress Enter");
  if (controls.IsPressed(TK_ENTER)) ctx_->scene_ = "menu";
  terminal_refresh();
}
void DeathScene::OnExit() {}
DeathScene::DeathScene(Context* const ctx, const Controls& controls) : IScene(ctx), controls(controls) {}
