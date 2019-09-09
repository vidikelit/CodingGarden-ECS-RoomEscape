#ifndef ECS_MOVEMENT_CONTROL_SYSTEM_H
#define ECS_MOVEMENT_CONTROL_SYSTEM_H

#include "game/control.h"
#include "lib/ecs/system.h"

class Entity;

class MovementControlSystem : public ISystem {
 private:
  const Controls& controls_;
  void OnUpdateEntity(Entity* entity) const;

 protected:
  void OnUpdate() override;

 public:
  MovementControlSystem(EntityManager* entityManager, SystemManager* systemManager, const Controls& controls);
};

#endif  // ECS_MOVEMENT_CONTROL_SYSTEM_H
