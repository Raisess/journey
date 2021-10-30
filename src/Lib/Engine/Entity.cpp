#include "Entity.h"
#include "./Helpers/Entity/EntityManager.h"

Engine::Entity::Entity(int id, String draw)
  : id(id), draw(draw)
{}

void Engine::Entity::update(int x, int y) {
  this->pos.x = x;
  this->pos.y = y;
}
