#ifndef ECS_ENDGAME_SCENE_H
#define ECS_ENDGAME_SCENE_H

#include "lib/scenes/i_scene.h"
#include "game/control.h"

class EndGameScene : public IScene {
 private:
  const Controls& controls;
 public:
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
  EndGameScene(Context* const ctx, const Controls& controls);
};

#endif  // ECS_ENDGAME_SCENE_H
