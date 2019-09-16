#ifndef ECS_MENU_COMPONENT_H
#define ECS_MENU_COMPONENT_H

#include <vector>
#include "lib/ecs/component.h"

class MenuComponent : public IComponent {
 public:
  // пункты основного меню
  const char* continue_game_ = "Продолжить";
  const char* new_game_ = "Новая игра";
  const char* load_game_ = "Загрузить";
  const char* setting_game_ = "Настройки";
  const char* end_game_ = "Выход";

  // пункты меню сохранения/загрузки
  const char* slot1_ = "Слот 1";
  const char* slot2_ = "Слот 2";
  const char* slot3_ = "Слот 3";

  // меню настроек
  const char* tiles_ = "Тайлы [color=green]ON";

  std::vector<const char*> pointMainMenu{new_game_, load_game_, setting_game_, end_game_};
  std::vector<const char*> pointLoadMenu{slot1_};
  std::vector<const char*> pointSettingMenu{tiles_};

  // 0 - основное меню, 1 - меню сохранений, 2 - меню загрузки
  int menu_ = 0;
  int menuPoint_ = 0;
  // слот сохранений
  int slot_;
};

#endif  // ECS_MENU_COMPONENT_H
