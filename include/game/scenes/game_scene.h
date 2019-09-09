#ifndef ECS_GAME_SCENE_H
#define ECS_GAME_SCENE_H

#include <lib/scenes/i_scene.h>
#include "lib/ecs/engine.h"
#include "game/control.h"

class GameScene : public IScene {
 private:
  const Engine engine{};
  const Controls& controls;

 public:
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;

  GameScene(Context* const ctx, const Controls& controls);
};

#endif  // ECS_GAME_SCENE_H
