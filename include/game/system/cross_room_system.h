#ifndef ECS_CROSS_ROOM_SYSTEM_H
#define ECS_CROSS_ROOM_SYSTEM_H

#include "game/control.h"
#include "lib/ecs/system.h"
#include "lib/math/vec2.h"

class CrossRoomSystem : public ISystem {
 private:
  int current_room_;
  Vec2 current_room_pos;

  const Controls &controls;

  void Scanner();
  void Teleport();
  void SetFalseRoom();
  void CheckCurrentRoom();

 protected:
  void OnUpdate() override;

 public:
  CrossRoomSystem(EntityManager *entityManager, SystemManager *systemManager, const Controls &controls);
};

#endif  // ECS_CROSS_ROOM_SYSTEM_H
