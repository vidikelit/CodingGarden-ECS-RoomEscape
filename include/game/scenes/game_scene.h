#ifndef ECS_GAME_SCENE_H
#define ECS_GAME_SCENE_H

#include <lib/scenes/i_scene.h>
#include "game/control.h"
#include "game/status.h"
#include "lib/ecs/engine.h"

class GameScene : public IScene {
 private:
  int width_wall_ = 21;
  int hight_wall_ = 9;

  const Engine& engine;
  const Controls& controls;
  const Status& status;

 public:
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;

  GameScene(Context* const ctx, const Engine& engine, const Controls& controls, const Status& status);
};

#endif  // ECS_GAME_SCENE_H
