#include "Entity.h"
#include "./Helpers/Entity/EntityManager.h"

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
