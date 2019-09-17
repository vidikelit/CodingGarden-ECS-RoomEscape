#ifndef ECS_ZERO_STEPS_SYSTEM_H
#define ECS_ZERO_STEPS_SYSTEM_H

#include "lib/ecs/system.h"
#include "lib/scenes/context.h"

class ZeroStepsSystem : public ISystem {
 private:
  Context *ctx_;

  void ZeroSteps();

 protected:
  void OnUpdate() override;

 public:
  ZeroStepsSystem(EntityManager *entityManager, SystemManager *systemManager, Context *ctx);
};

#endif  // ECS_ZERO_STEPS_SYSTEM_H
