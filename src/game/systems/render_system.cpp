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

      if (e.Contains<DoorComponent>()) {
        auto door = e.Get<DoorComponent>();
        if (current_room_ == ToPos(door->id_room_)) {
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
RenderSystem::RenderSystem(EntityManager *entityManager, SystemManager *systemManager, int currentRoom)
    : ISystem(entityManager, systemManager), current_room_(currentRoom) {}
