#ifndef ECS_MENU_COMPONENT_H
#define ECS_MENU_COMPONENT_H

#include <vector>
#include "lib/ecs/component.h"

class MenuComponent : public IComponent {
 public:
  // пункты основного меню
  const char* new_game_ = "Новая игра";
  const char* setting_game_ = "Тайлы [color=red]OFF";
  const char* end_game_ = "Выход";

  std::vector<const char*> pointMainMenu{new_game_, setting_game_, end_game_};
  int menuPoint_ = 0;
};

#endif  // ECS_MENU_COMPONENT_H
