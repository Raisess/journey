#include "Scene.h"

#ifdef WIN32
#include <Windows.h>
#define CLEAR "cls"
#define sleep Sleep
#else
#include <unistd.h>
#define CLEAR "clear"
#define sleep usleep
#endif

#define SECOND 1000000
#define UPDATE_SECONDS 0.1

Engine::Scene::Scene(int width, int height)
  : width(width), height(height)
{
  this->reset();
}

void Engine::Scene::place_entites(void) {
  for (int k = 0; k < this->entities_size; k++) {
    const Entity *entity = this->entities[k];
    const String draw = entity->getDraw();
    const Position pos = entity->getPos();

    if (pos.x >= 0 && pos.y >= 0) {
      this->scene[pos.y][pos.x] = draw;
    }
  }
}

void Engine::Scene::update(void) {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      std::cout << this->scene[i][j];
    }

    std::cout << "\n";
  }
}

void Engine::Scene::reset(void) {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      this->scene[i][j] = " ";
    }
  }
}

void Engine::Scene::attach_entity(Entity *entity) {
  this->entities[this->entities_size] = entity;
  this->entities_size++;
}

void Engine::Scene::draw(void) {
  system(CLEAR);
  this->place_entites();
  this->update();
  this->reset();
  sleep(UPDATE_SECONDS * SECOND);
}
