#ifndef ECS_RENDER_SYMBOLS_SYSTEM_H
#define ECS_RENDER_SYMBOLS_SYSTEM_H

#include <vector>
#include "lib/ecs/system.h"
#include "game/status.h"

class RenderSymbolsSystem : public ISystem {
 private:
  int current_room_;
  const Status& status;

  void CheckCurrentRoom();

 protected:
  void OnPreUpdate() override;
  void OnUpdate() override;
  void OnPostUpdate() override;

 public:
  RenderSymbolsSystem(EntityManager *entityManager, SystemManager *systemManager, const Status &status);
};

#endif  // ECS_RENDER_SYMBOLS_SYSTEM_H
