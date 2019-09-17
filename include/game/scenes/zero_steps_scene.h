#ifndef ECS_ZERO_STEPS_SCENE_H
#define ECS_ZERO_STEPS_SCENE_H

#include "lib/scenes/i_scene.h"
#include "game/control.h"
#include "lib/ecs/engine.h"

class ZeroStepsScene : public IScene {
 private:
  const Engine& engine;
  const Controls& controls;
 public:
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
  ZeroStepsScene(Context* const ctx, const Engine& engine, const Controls& controls);
};

#endif  // ECS_ZERO_STEPS_SCENE_H
