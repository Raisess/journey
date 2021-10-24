#include "scene.h"
#include <unistd.h>

#ifdef WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define SECOND 1000000
#define UPDATE_SECONDS 0.1

Scene::Scene(int width, int height) {
  this->width = width;
  this->height = height;

  this->reset();
}

void Scene::attach_entity(Entity *entity) {
  this->entities[this->entities_size] = entity;
  this->entities_size++;
}

void Scene::draw(void) {
  for (int k = 0; k < this->entities_size; k++) {
    const TEntity *entity = this->entities[k]->get();

    if (entity->pos.x >= 0 && entity->pos.y >= 0) {
      this->scene[entity->pos.y][entity->pos.x] = entity->draw;
    }
  }

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

void Scene::update(void) {
  system(CLEAR);
  this->draw();
  this->reset();
  usleep(UPDATE_SECONDS * SECOND);
}
