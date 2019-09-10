#ifndef ECS_OBSTACLES_CONTROL_SYSTEM_H
#define ECS_OBSTACLES_CONTROL_SYSTEM_H

#include <lib/ecs/entity.h>
#include <lib/ecs/system.h>

class ObstaclesControlSystem : public ISystem {
 public:
  ObstaclesControlSystem(EntityManager* entityManager, SystemManager* systemManager);

 protected:
  void OnUpdate() override;
};

#endif  // ECS_OBSTACLES_CONTROL_SYSTEM_H
