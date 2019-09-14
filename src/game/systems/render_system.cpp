#include "game/system/render_system.h"
#include <BearLibTerminal.h>
#include <game/components/door_component.h>
#include "game/components/texture_component.h"
#include "game/components/transform_component.h"
#include "game/math-utils.h"
#include "lib/ecs/entity_manager.h"

void RenderSystem::OnPreUpdate() {
  terminal_clear();
}
void RenderSystem::OnUpdate() {
  for (auto &e : GetEntityManager()) {
    if (e.Contains<TransformComponent>() && e.Contains<TextureComponent>()) {
      auto texture = e.Get<TextureComponent>();
      auto transform = e.Get<TransformComponent>();

      terminal_put(ToPos(transform->pos_.x), ToPos(transform->pos_.y), texture->symbol_);
    }
  }
  for (auto &door : GetEntityManager()) {
    if (door.Contains<DoorComponent>() && door.Contains<TextureComponent>()) {
      auto texture = door.Get<TextureComponent>();
      auto dc = door.Get<DoorComponent>();

      if (current_room_ == ToPos(dc->id_room_)) {
        terminal_put(ToPos(dc->pos_.x), ToPos(dc->pos_.y), texture->symbol_);
      }
    }
  }
}
void RenderSystem::OnPostUpdate() {
  terminal_refresh();
}
RenderSystem::RenderSystem(EntityManager *entityManager, SystemManager *systemManager, int currentRoom)
    : ISystem(entityManager, systemManager), current_room_(currentRoom) {}
