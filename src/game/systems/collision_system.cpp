#include "game/system/collision_system.h"
#include "game/components/collider_component.h"
#include "game/components/transform_component.h"
#include "game/math-utils.h"
#include "lib/ecs/entity.h"
#include "lib/ecs/entity_manager.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<ColliderComponent>() && entity.Contains<TransformComponent>();
}

static void Collide(Entity* entity_1, Entity* entity_2) {
  if (entity_1->GetId() == entity_2->GetId()) return;

  auto cc2 = entity_2->Get<ColliderComponent>();
  auto tc1 = entity_1->Get<TransformComponent>();
  auto tc2 = entity_2->Get<TransformComponent>();

  if (ToPos(tc1->pos_.x) == ToPos(tc2->pos_.x) && ToPos(tc1->pos_.y) == ToPos(tc2->pos_.y)) {
    cc2->Collide(entity_1);
  }
}
void CollisionSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<ColliderComponent>()) {
      entity.Get<ColliderComponent>()->Clear();
    }
  }

  for (auto& entity_1 : GetEntityManager()) {
    if (Filter(entity_1)) {
      for (auto& entity_2 : GetEntityManager()) {
        if (Filter(entity_2)) {
          Collide(&entity_1, &entity_2);
        }
      }
    }
  }
}
CollisionSystem::CollisionSystem(EntityManager* entityManager, SystemManager* systemManager)
    : ISystem(entityManager, systemManager) {}
