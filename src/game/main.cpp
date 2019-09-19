#include <BearLibTerminal.h>
#include "game/components/menu_component.h"
#include "game/control.h"
#include "game/window.h"
#include "game/status.h"
#include "game/scenes/game_scene.h"
#include "game/scenes/menu_scene.h"
#include "game/scenes/death_scene.h"
#include "game/scenes/zero_steps_scene.h"
#include "lib/scenes/scene_manager.h"

int main() {
  terminal_open();
  terminal_refresh();
  terminal_set("input: filter=[keyboard+];");

  Windows windows;
  Engine engine;
  Controls controls;
  Status status;
  Context ctx{};
  SceneManager sm(ctx);

  windows.StartupSettings();

  sm.Put("menu", new MenuScene(&ctx, engine, controls, &status));
  sm.Put("game", new GameScene(&ctx, engine, controls, &status));
  sm.Put("zero_steps", new ZeroStepsScene(&ctx, engine, controls));
  sm.Put("death", new DeathScene(&ctx, controls));
  ctx.scene_ = "menu";

  while (true) {
    controls.OnUpdate();
    if (status.isEndGame()) break;
    sm.OnRender();
    controls.Reset();
  }while (true) {
    controls.OnUpdate();
    if (status.isEndGame()) break;
    sm.OnRender();
    controls.Reset();
  }
  sm.OnExit();
  terminal_close();
}
