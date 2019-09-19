#ifndef ECS_COMBAT_CONTROL_SYSTEM_H
#define ECS_COMBAT_CONTROL_SYSTEM_H

#include <lib/ecs/engine.h>
#include <lib/ecs/entity.h>
#include <lib/ecs/system.h>

class CombatControlSystem : public ISystem {
 private:
  int current_room_;
  const Engine &engine;
  void Combat(const Entity &entity);
  void CheckCurrentRoom();

 protected:
  void OnUpdate() override;

 public:
  CombatControlSystem(EntityManager *entityManager, SystemManager *systemManager, const Engine &engine);
};

#endif  // ECS_COMBAT_CONTROL_SYSTEM_H
