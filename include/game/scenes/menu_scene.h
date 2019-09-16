#ifndef ECS_MENU_SCENE_H
#define ECS_MENU_SCENE_H

#include <lib/scenes/i_scene.h>
#include <vector>
#include "game/control.h"
#include "game/status.h"
#include "lib/ecs/engine.h"

class MenuScene : public IScene {
 private:
  const Engine& engine;
  const Controls& controls;
  Status* status;

 public:
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;

  MenuScene(Context* const ctx, const Engine& engine, const Controls& controls, Status* status);
};

#endif  // ECS_MENU_SCENE_H
