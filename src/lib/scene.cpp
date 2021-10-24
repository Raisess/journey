#include "scene.h"

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

Scene::Scene(int width, int height) {
  this->width = width;
  this->height = height;

  this->reset();
}

void Scene::place_entites(void) {
  for (int k = 0; k < this->entities_size; k++) {
    const TEntity *entity = this->entities[k]->get();

    if (entity->pos.x >= 0 && entity->pos.y >= 0) {
      this->scene[entity->pos.y][entity->pos.x] = entity->draw;
    }
  }
}

void Scene::draw(void) {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      std::cout << this->scene[i][j];
    }

    std::cout << "\n";
  }
}

void Scene::reset(void) {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      this->scene[i][j] = " ";
    }
  }
}

void Scene::attach_entity(Entity *entity) {
  this->entities[this->entities_size] = entity;
  this->entities_size++;
}

void Scene::update(void) {
  system(CLEAR);
  this->place_entites();
  this->draw();
  this->reset();
  sleep(UPDATE_SECONDS * SECOND);
}
