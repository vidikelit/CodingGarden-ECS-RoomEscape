#ifndef ECS_GAME_SCENE_H
#define ECS_GAME_SCENE_H

#include <lib/scenes/i_scene.h>
#include "lib/ecs/engine.h"
#include "game/control.h"

class GameScene : public IScene {
 private:
  int current_room_ = 2;
  int width_wall_ = 21;
  int hight_wall_ = 9;
  const Engine engine{};
  const Controls& controls;

 public:
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
  void OnPreLoad();

  GameScene(Context* const ctx, const Controls& controls);
};

#endif  // ECS_GAME_SCENE_H
