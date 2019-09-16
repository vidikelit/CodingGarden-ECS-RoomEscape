#include "game/system/cross_room_system.h"
#include "game/components/door_component.h"
#include "game/components/player_control_component.h"
#include "game/components/room_component.h"
#include "game/components/room_size_component.h"
#include "game/components/transform_component.h"

#include "game/math-utils.h"
#include "lib/ecs/entity_manager.h"

void CrossRoomSystem::Scanner() {
  int player_x = 0;
  int player_y = 0;
  CheckCurrentRoom();
  for (auto &player : GetEntityManager()) {
    if (player.Contains<PlayerControlComponent>()) {
      player_x = player.Get<TransformComponent>()->pos_.x;
      player_y = player.Get<TransformComponent>()->pos_.y;
    }
  }
  for (auto &door : GetEntityManager()) {
    if (door.Contains<DoorComponent>()) {
      auto door_dc = door.Get<DoorComponent>();
      auto door_tc = door.Get<TransformComponent>();
      if (door_dc->id_room_ == current_room_) {
        if (sqrt(pow(ToPos(door_tc->pos_.x) - ToPos(player_x), 2) + pow(ToPos(door_tc->pos_.y) - ToPos(player_y), 2)) <=
            1)
          Teleport();
      }
    }
  }
}
void CrossRoomSystem::Teleport() {
  Vec2 move;
  Vec2 player_save_pos;
  // получаем координаты текущей комнаты
  for (auto &room : GetEntityManager()) {
    if (room.Contains<RoomComponent>()) {
      if (room.Get<RoomComponent>()->current) {
        current_room_pos.x = room.Get<RoomComponent>()->pos_.x;
        current_room_pos.y = room.Get<RoomComponent>()->pos_.y;
      }
    }
  }
  // перемещение игрока
  for (auto &player : GetEntityManager()) {
    if (player.Contains<PlayerControlComponent>()) {
      player_save_pos = Vec2(player.Get<TransformComponent>()->pos_.x, player.Get<TransformComponent>()->pos_.y);
      auto player_pos = player.Get<TransformComponent>();
      auto room_size = player.Get<RoomSizeComponent>();
      // перемещение игрока
      // вверх
      if (ToPos(player_pos->pos_.x) == 10 && ToPos(player_pos->pos_.y) == 7) {
        player_save_pos.y += 8;
        move.y -= room_size->size_.y;
      }
      // вниз
      if (ToPos(player_pos->pos_.x) == 10 && ToPos(player_pos->pos_.y) == 15) {
        player_save_pos.y -= 8;
        move.y += room_size->size_.y;
      }
      // влево
      if (ToPos(player_pos->pos_.x) == 1 && ToPos(player_pos->pos_.y) == 11) {
        player_save_pos.x += 18;
        move.x -= room_size->size_.x;
      }
      // вправо
      if (ToPos(player_pos->pos_.x) == 19 && ToPos(player_pos->pos_.y) == 11) {
        player_save_pos.x -= 18;
        move.x += room_size->size_.x;
      }
      player_pos->pos_.x = player_save_pos.x;
      player_pos->pos_.y = player_save_pos.y;
    }
  }
  // передвигаем комнату
  for (auto &entity : GetEntityManager()) {
    if (entity.Contains<RoomComponent>()) {
      if (ToPos(current_room_pos.x + move.x) == ToPos(entity.Get<RoomComponent>()->pos_.x)) {
        if (ToPos(current_room_pos.y + move.y) == ToPos(entity.Get<RoomComponent>()->pos_.y)) {
          auto setTrue = entity.Get<RoomComponent>();
          SetFalseRoom();
          setTrue->current = true;
          break;
        }
      }
    }
  }
}
void CrossRoomSystem::SetFalseRoom() {
  for (auto &room : GetEntityManager()) {
    if (room.Contains<RoomComponent>()) {
      auto setFalse = room.Get<RoomComponent>();
      setFalse->current = false;
    }
  }
}
void CrossRoomSystem::CheckCurrentRoom() {
  for (auto &room : GetEntityManager()) {
    if (room.Contains<RoomComponent>()) {
      if (room.Get<RoomComponent>()->current) current_room_ = room.GetId();
    }
  }
}
void CrossRoomSystem::OnUpdate() {
  for (auto &entity : GetEntityManager()) {
    if (entity.Contains<PlayerControlComponent>()) {
      if (controls.IsPressed(TK_E)) {
        Scanner();
      }
    }
  }
}
CrossRoomSystem::CrossRoomSystem(EntityManager *entityManager, SystemManager *systemManager, const Controls &controls)
    : ISystem(entityManager, systemManager), controls(controls) {}
