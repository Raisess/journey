#include "Entity.h"

Engine::Entity::Entity(String draw)
  : draw(draw)
{}

void Engine::Entity::update(int x, int y) {
  this->pos.x = x;
  this->pos.y = y;
}
