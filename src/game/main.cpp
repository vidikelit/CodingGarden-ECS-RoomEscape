#include <BearLibTerminal.h>
#include <game/scenes/game_scene.h>
#include <lib/scenes/scene_manager.h>
#include "game/control.h"
#include "game/window.h"

int main() {
  terminal_open();
  terminal_refresh();
  terminal_set("input: filter=[keyboard+];");

  Windows windows;
  Controls controls;
  Context ctx{};
  SceneManager sm(ctx);

  windows.StartupSettings();

  sm.Put("game", new GameScene(&ctx, controls));
  ctx.scene_ = "game";
  while (true) {
    controls.OnUpdate();
    if (controls.IsPressed(TK_ESCAPE)) break;
    sm.OnRender();
    controls.Reset();
  }
  sm.OnExit();
  terminal_close();
}
