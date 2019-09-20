#include <BearLibTerminal.h>
#include "game/scenes/endgame_scene.h"

void EndGameScene::OnCreate() {}
void EndGameScene::OnRender() {
  terminal_clear();
  terminal_print(1, 1, "Вы победили! \nPress Enter");
  if (controls.IsPressed(TK_ENTER)) ctx_->scene_ = "menu";
  terminal_refresh();
}
void EndGameScene::OnExit() {}
EndGameScene::EndGameScene(Context* const ctx, const Controls& controls) : IScene(ctx), controls(controls) {}
