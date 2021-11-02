#pragma once

#include "./Utils/Debugger.h"
#include "./Helpers/EntityManager.h"
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

    void place_entites(void);
    void update(void);
    void reset(void);

  public:
    Scene(int width, int height);

    void attach_entity(String alias, Entity *entity);
    void update_entity(Entity *entity, int x, int y);
    void draw(void);
};

}
