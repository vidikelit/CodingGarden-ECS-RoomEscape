#ifndef ECS_ENDGAME_SCENE_H
#define ECS_ENDGAME_SCENE_H

#include "lib/scenes/i_scene.h"

class EndGameScene : public IScene {
 public:
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
  explicit EndGameScene(Context* const ctx);
};

#endif  // ECS_ENDGAME_SCENE_H
