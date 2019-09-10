#ifndef ECS_SAVE_STEP_COMPONENT_H
#define ECS_SAVE_STEP_COMPONENT_H

#include "lib/ecs/component.h"
#include "lib/math/vec2.h"

class SaveStepComponent : public IComponent {
 public:
  Vec2 prev_step_;

  explicit SaveStepComponent(const Vec2& prevStep) : prev_step_(prevStep) {}
};
#endif  // ECS_SAVE_STEP_COMPONENT_H
