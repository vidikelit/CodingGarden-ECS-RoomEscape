#ifndef ECS_ENDGAME_SYSTEM_H
#define ECS_ENDGAME_SYSTEM_H

#include "lib/ecs/system.h"
#include "lib/scenes/context.h"

class EndGameSystem : public ISystem {
 private:
  int coin_count_;
  Context* ctx_;

 protected:
  void OnUpdate() override;
  void CheckCoin();

 public:
  EndGameSystem(EntityManager *entityManager, SystemManager *systemManager, Context *ctx);
};

#endif  // ECS_ENDGAME_SYSTEM_H
