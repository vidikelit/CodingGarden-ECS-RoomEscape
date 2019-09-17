#ifndef ECS_DEATH_SCENE_H
#define ECS_DEATH_SCENE_H

#include "lib/scenes/i_scene.h"

class DeathScene : public IScene {
 public:
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
  explicit DeathScene(Context* const ctx);
};

#endif  // ECS_DEATH_SCENE_H
