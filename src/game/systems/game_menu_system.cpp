#include "game/system/game_menu_system.h"
#include <BearLibTerminal.h>
#include <cstring>
#include "game/components/menu_component.h"
#include "lib/ecs/entity_manager.h"

void GameMenuSystem::MainMenu() {
  terminal_clear();
  for (auto &menu : GetEntityManager()) {
    if (menu.Contains<MenuComponent>()) {
      auto mc = menu.Get<MenuComponent>();
      terminal_print(5, 5, "[color=red]Room \n    Escape");
      for (unsigned int i = 0; i < mc->pointMainMenu.size(); i++) {
        if (mc->menuPoint_ == static_cast<int>(i)) {
          terminal_color(color_from_name("green"));
        }
        terminal_printf(5, 8 + i, "%s", mc->pointMainMenu[i]);
        terminal_color(color_from_name("white"));
        if (controls.IsPressed(TK_ENTER)) {
          // новая игра
          if (strcmp(mc->pointMainMenu[mc->menuPoint_], mc->new_game_) == 0) {
            status->setNewGame(true);
            mc->menuPoint_ = 0;
            break;
          }
          // настройки
          if (strcmp(mc->pointMainMenu[mc->menuPoint_], mc->setting_game_) == 0) {
            if (status->isSettingGameOnOff()) {
              mc->setting_game_ = "Тайлы [color=red]OFF";
              mc->pointMainMenu.at(1) = "Тайлы [color=red]OFF";
              status->setSettingGameOnOff(false);
            } else {
              mc->setting_game_ = "Тайлы [color=green]ON";
              mc->pointMainMenu.at(1) = "Тайлы [color=green]ON";
              status->setSettingGameOnOff(true);
            }
            break;
          }
          // выход
          if (strcmp(mc->pointMainMenu[mc->menuPoint_], mc->end_game_) == 0) {
            status->setEndGame(true);
            break;
          }
        }
      }
      if (controls.IsPressed(TK_UP)) {
        mc->menuPoint_ -= 1;
        if (mc->menuPoint_ < 0) mc->menuPoint_ = static_cast<int>(mc->pointMainMenu.size() - 1);
      }
      if (controls.IsPressed(TK_DOWN)) {
        mc->menuPoint_ += 1;
        if (mc->menuPoint_ > static_cast<int>(mc->pointMainMenu.size() - 1)) mc->menuPoint_ = 0;
      }
      terminal_color(color_from_name("white"));
    }
  }
}
void GameMenuSystem::OnUpdate() {
  terminal_refresh();
  MainMenu();
}
GameMenuSystem::GameMenuSystem(EntityManager *entityManager, SystemManager *systemManager, const Controls &controls,
                               Status *status)
    : ISystem(entityManager, systemManager), controls(controls), status(status) {
  status->setSettingGameOnOff(false);
}
