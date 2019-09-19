#ifndef ECS_DEATH_SCENE_H
#define ECS_DEATH_SCENE_H

#include "lib/scenes/i_scene.h"
#include "game/control.h"
#include "lib/ecs/engine.h"

class DeathScene : public IScene {
 private:
  const Controls& controls;
 public:
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
  DeathScene(Context* const ctx, const Controls& controls);
};

#endif  // ECS_DEATH_SCENE_H
