#pragma once

#include "Utils/Debugger.h"
#include "Helpers/EntityManager.h"
#include "Physics.h"
#include "Entity.h"

namespace Engine {

class Scene {
  private:
    Utils::Debugger *debugger;
    Helpers::EntityManager *entity_manager;
    String scene[100][100];
    int entities_size;
    int height;
    int width;

    void reset(void);
    void update(void);
    void place_entities(void);

  public:
    Engine::Physics *physics;

    Scene(int width, int height);

    void draw(void);
    void update_entity(Entity *entity, int x, int y);
    void attach_entity(String alias, Entity *entity);
};

}
