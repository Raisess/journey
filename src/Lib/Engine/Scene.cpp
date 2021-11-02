#include "Scene.h"
#include "./Helpers/EntityManager.h"
#include "./Utils/Debugger.h"

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
#define UPDATE_SECONDS 0.05F

Engine::Scene::Scene(int width, int height)
  : width(width), height(height)
{
  this->debugger = new Utils::Debugger("Scene");
  this->entity_manager = new Helpers::EntityManager();

  this->reset();
}

void Engine::Scene::place_entites(void) {
  for (int k = 0; k < this->entities_size; k++) {
    Engine::Entity *entity = this->entity_manager->get(k);
    String draw = entity->get_draw();
    Position pos = entity->get_pos();

    String msg;

    msg.append(entity->get_alias());
    msg.append(": ");
    msg.append("x(");
    msg.append(std::to_string(pos.x));
    msg.append(") ");
    msg.append("y(");
    msg.append(std::to_string(pos.y));
    msg.append(")");

    this->debugger->push_message(msg);

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

void Engine::Scene::attach_entity(String alias, Entity *entity) {
  entity->set_alias(alias);

  this->entity_manager->alloc(entity);
  this->entities_size++;
}

void Engine::Scene::update_entity(Entity *entity, int x, int y) {
  this->entity_manager->update_pos(entity->get_id(), x, y);
}

void Engine::Scene::draw(void) {
  system(CLEAR);
  this->place_entites();
  this->update();
  this->debugger->draw_debug_log();
  this->debugger->clear();
  this->reset();
  sleep(UPDATE_SECONDS * SECOND);
}
