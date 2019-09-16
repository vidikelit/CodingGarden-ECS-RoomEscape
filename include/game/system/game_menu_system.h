#ifndef ECS_GAME_MENU_SYSTEM_H
#define ECS_GAME_MENU_SYSTEM_H

#include "game/control.h"
#include "game/status.h"
#include "lib/ecs/system.h"

class GameMenuSystem : public ISystem {
 private:
  const Controls &controls;
  Status* status;

  void MainMenu();

 protected:
  void OnUpdate() override;

 public:
  GameMenuSystem(EntityManager *entityManager, SystemManager *systemManager, const Controls &controls, Status *status);
};

#endif  // ECS_GAME_MENU_SYSTEM_H
