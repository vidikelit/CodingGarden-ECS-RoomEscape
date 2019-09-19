#include "game/system/render_symbols_system.h"
#include <BearLibTerminal.h>
#include "game/components/coin_component.h"
#include "game/components/coins_component.h"
#include "game/components/door_component.h"
#include "game/components/enimy_component.h"
#include "game/components/health_component.h"
#include "game/components/player_component.h"
#include "game/components/room_component.h"
#include "game/components/steps_component.h"
#include "game/components/texture_component.h"
#include "game/components/transform_component.h"
#include "game/math-utils.h"
#include "game/status.h"
#include "lib/ecs/entity_manager.h"

void RenderSymbolsSystem::OnPreUpdate() {
  terminal_clear();
  if (status.isSettingGameOnOff() == true) {
    terminal_set("0x40: ../resources/sprites/player.png");
    terminal_set("0x24: ../resources/sprites/coinGold.png");
    terminal_set("0x2A: ../resources/sprites/enemy.png");
    terminal_set("0x3F: ../resources/sprites/health.png");
    terminal_set("0xB7: ../resources/sprites/floor.png");
    terminal_set("0x23: ../resources/sprites/wall.png");

    CheckCurrentRoom();
    terminal_layer(0);
    // отрисовка пола
    for (int i = 1; i < 20; i++) {
      terminal_put(i, 7, 0xB7);
      for (int j = 0; j < 9; j++) {
        terminal_put(i, 7 + j, 0xB7);
      }
    }
    terminal_layer(2);
    for (auto &door : GetEntityManager()) {
      if (door.Contains<DoorComponent>()) {
        if (door.Get<DoorComponent>()->id_room_ == current_room_) {
          auto tc = door.Get<TransformComponent>();
          // верх
          if (ToPos(tc->pos_.x) == 10 && ToPos(tc->pos_.y) == 6) {
            terminal_set("0xE21: ../resources/sprites/door_up.png");
            terminal_put(ToPos(tc->pos_.x), ToPos(tc->pos_.y), 0xE21);
          }
          // низ
          if (ToPos(tc->pos_.x) == 10 && ToPos(tc->pos_.y) == 16) {
            terminal_set("0xE22: ../resources/sprites/door_down.png");
            terminal_put(ToPos(tc->pos_.x), ToPos(tc->pos_.y), 0xE22);
          }
          // лево
          if (ToPos(tc->pos_.x) == 0 && ToPos(tc->pos_.y) == 11) {
            terminal_set("0xE23: ../resources/sprites/door_left.png");
            terminal_put(ToPos(tc->pos_.x), ToPos(tc->pos_.y), 0xE23);
          }
          // право
          if (ToPos(tc->pos_.x) == 20 && ToPos(tc->pos_.y) == 11) {
            terminal_set("0xE24: ../resources/sprites/door_right.png");
            terminal_put(ToPos(tc->pos_.x), ToPos(tc->pos_.y), 0xE24);
          }
        }
      }
    }
  } else {
    terminal_set("0x40: none");
    terminal_set("0x24: none");
    terminal_set("0x2A: none");
    terminal_set("0x3F: none");
    terminal_set("0xB7: none");
    terminal_set("0x23: none");
  }
}
void RenderSymbolsSystem::OnUpdate() {
  for (auto &entity : GetEntityManager()) {
    if (entity.Contains<TransformComponent>() && entity.Contains<TextureComponent>()) {
      CheckCurrentRoom();
      auto texture = entity.Get<TextureComponent>();
      auto transform = entity.Get<TransformComponent>();

      terminal_layer(1);
      // отрисовка объектов
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
      } else if (entity.Contains<EnimyComponent>()) {
        auto enemy = entity.Get<EnimyComponent>();
        if (enemy->id_room_ == current_room_) {
          terminal_put(ToPos(transform->pos_.x), ToPos(transform->pos_.y), texture->symbol_);
        }
      } else {
        terminal_put(ToPos(transform->pos_.x), ToPos(transform->pos_.y), texture->symbol_);
      }
      // отрисовка индикаторов игрока
      if (entity.Contains<PlayerComponent>()) {
        auto health = entity.Get<HealthComponent>();
        auto coins = entity.Get<CoinsComponent>();
        auto steps = entity.Get<StepsComponent>();

        terminal_put(6, 3, 0x40);
        terminal_printf(7, 1, "%d", health->count_);

        terminal_put(6, 2, 0x24);
        terminal_printf(7, 2, "%d", coins->count_);

        terminal_put(6, 1, 0x3F);
        terminal_printf(7, 3, "%d", steps->count_);
      }
    }
  }
}
void RenderSymbolsSystem::OnPostUpdate() {
  terminal_refresh();
}
void RenderSymbolsSystem::CheckCurrentRoom() {
  for (auto &room : GetEntityManager()) {
    if (room.Contains<RoomComponent>()) {
      if (room.Get<RoomComponent>()->current) current_room_ = room.GetId();
    }
  }
}
RenderSymbolsSystem::RenderSymbolsSystem(EntityManager *entityManager, SystemManager *systemManager,
                                         const Status &status)
    : ISystem(entityManager, systemManager), status(status) {}
