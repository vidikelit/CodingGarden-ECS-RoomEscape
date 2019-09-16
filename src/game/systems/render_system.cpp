#include "game/system/render_system.h"
#include <BearLibTerminal.h>
#include "game/components/coin_component.h"
#include "game/components/door_component.h"
#include "game/components/room_component.h"
#include "game/components/texture_component.h"
#include "game/components/transform_component.h"
#include "game/math-utils.h"
#include "lib/ecs/entity_manager.h"

void RenderSystem::OnPreUpdate() {
  terminal_clear();
}
void RenderSystem::OnUpdate() {
  for (auto &entity : GetEntityManager()) {
    if (entity.Contains<TransformComponent>() && entity.Contains<TextureComponent>()) {
      CheckCurrentRoom();
      auto texture = entity.Get<TextureComponent>();
      auto transform = entity.Get<TransformComponent>();

      if (entity.Contains<DoorComponent>()) {
        auto door = entity.Get<DoorComponent>();
        if (door->id_room_ == current_room_) {
          terminal_put(ToPos(transform->pos_.x), ToPos(transform->pos_.y), texture->symbol_);
        }
      } else if (entity.Contains<CoinComponent>()) {
        auto coin = entity.Get<CoinComponent>();
        if (coin->id_room_ == current_room_) {
          terminal_put(ToPos(transform->pos_.x), ToPos(transform->pos_.y), texture->symbol_);
        }
      } else {
        terminal_put(ToPos(transform->pos_.x), ToPos(transform->pos_.y), texture->symbol_);
      }
    }
  }
}
void RenderSystem::OnPostUpdate() {
  terminal_refresh();
}
void RenderSystem::CheckCurrentRoom() {
  for (auto &room : GetEntityManager()) {
    if (room.Contains<RoomComponent>()) {
      if (room.Get<RoomComponent>()->current) current_room_ = room.GetId();
    }
  }
}
RenderSystem::RenderSystem(EntityManager *entityManager, SystemManager *systemManager)
    : ISystem(entityManager, systemManager) {}
