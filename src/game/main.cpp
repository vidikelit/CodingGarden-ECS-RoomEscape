#include <BearLibTerminal.h>
#include <game/scenes/game_scene.h>
#include <lib/scenes/scene_manager.h>
#include "game/control.h"

int main() {
  terminal_open();
  terminal_refresh();

  Controls controls;
  Context ctx{};
  SceneManager sm(ctx);

  sm.Put("game", new GameScene(&ctx, controls));

  ctx.scene_ = "game";

  while (true) {
    controls.OnUpdate();
    if (controls.IsPressed(TK_CLOSE)) {
      break;
    }
    sm.OnRender();
    controls.Reset();
  }
  sm.OnExit();
  terminal_close();
}
