#include "EntityManager.h"

void Helpers::EntityManager::alloc(Engine::Entity *entity) {
  this->node = (EntityLList *) malloc(sizeof(EntityLList));

  entity->set_id(
    this->head != NULL
    ? this->head->data->get_id() + 1
    : 0
  );

  this->node->data = entity;
  this->node->next = this->head;

  this->head = this->node;
}

Engine::Entity *Helpers::EntityManager::get(int id) {
  EntityLList *temp = this->head;

  while (temp != NULL) {
    if (temp->data->get_id() == id) {
      return temp->data;
    }

    temp = temp->next;
  }

  return NULL;
}

void Helpers::EntityManager::update_pos(int id, int x, int y) {
  Engine::Entity *list_item = this->get(id);

  list_item->update(x, y);
}

void Helpers::EntityManager::destroy(int id) {
  EntityLList *list_item = this->get_list_item(id);

  free(list_item);
}

EntityLList *Helpers::EntityManager::get_list_item(int id) {
  EntityLList *temp = this->head;

  while (temp != NULL) {
    if (temp->data->get_id() == id) {
      return temp;
    }

    temp = temp->next;
  }

  return NULL;
}
