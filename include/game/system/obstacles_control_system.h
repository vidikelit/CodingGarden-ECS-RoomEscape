#ifndef ECS_OBSTACLES_CONTROL_SYSTEM_H
#define ECS_OBSTACLES_CONTROL_SYSTEM_H

#include <lib/ecs/engine.h>
#include <lib/ecs/entity.h>
#include <lib/ecs/system.h>

class ObstaclesControlSystem : public ISystem {
 private:
  const Engine& engine;

 protected:
  void OnUpdate() override;

 public:
  ObstaclesControlSystem(EntityManager *entityManager, SystemManager *systemManager, const Engine &engine);
};

#endif  // ECS_OBSTACLES_CONTROL_SYSTEM_H
