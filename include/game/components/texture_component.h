#ifndef ECS_TEXTURE_COMPONENT_H
#define ECS_TEXTURE_COMPONENT_H

#include "lib/ecs/component.h"

class TextureComponent : public IComponent {
 public:
  char symbol_;

  explicit TextureComponent(char symbol) : symbol_(symbol) {}
};

#endif  // ECS_TEXTURE_COMPONENT_H
