#pragma once

#include "./Helpers/Entity/EntityManager.h"
#include "Entity.h"

namespace Engine {

class Scene {
  private:
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
    ~Scene() { delete this; }

    void attach_entity(Entity *entity);
    void update_entity(Entity *entity, int x, int y);
    void draw(void);
};

}
