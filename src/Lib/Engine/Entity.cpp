#include "Entity.h"
#include "./Helpers/EntityManager.h"

Engine::Entity::Entity(String draw)
  : draw(draw)
{}

void Engine::Entity::update(int x, int y) {
  this->pos.x = x;
  this->pos.y = y;
}

void Engine::Entity::set_id(int id) {
  this->id = id;
}

void Engine::Entity::set_alias(String alias) {
  this->alias = alias;
}
