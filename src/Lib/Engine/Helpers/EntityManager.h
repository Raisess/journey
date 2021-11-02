#pragma once

#include <iostream>
#include "../Entity.h"

typedef struct EntityLList {
  Engine::Entity *data;
  struct EntityLList *next;
} EntityLList;

namespace Helpers {

class EntityManager {
  private:
    EntityLList *head = NULL;
    EntityLList *node;

    EntityLList *get_list_item(int id);

  public:
    ~EntityManager() { delete this; }

    void alloc(Engine::Entity *entity);
    void update_pos(int id, int x, int y);
    void destroy(int id);
    Engine::Entity *get(int id);
};

}
