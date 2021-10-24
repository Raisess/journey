#include "entity.h"

Entity::Entity(String draw) {
  this->draw = draw;
  this->pos.x = 0;
  this->pos.y = 0;
}

TEntity *Entity::get(void) {
  return (TEntity *) this;
}

void Entity::update(int x, int y) {
  this->pos.x = x;
  this->pos.y = y;
}
