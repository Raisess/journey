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

void Engine::Scene::draw(void) {
  system(CLEAR);
  this->place_entities();
  this->update();
  this->debugger->draw_debug_log();
  this->debugger->clear();
  this->reset();
  sleep(UPDATE_SECONDS * SECOND);
}

void Engine::Scene::update_entity(Entity *entity, int x, int y) {
  this->entity_manager->update_pos(entity->get_id(), x, y);
}

void Engine::Scene::attach_entity(String alias, Entity *entity) {
  entity->set_alias(alias);

  this->entity_manager->alloc(entity);
  this->entities_size++;
}

void Engine::Scene::reset(void) {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      this->scene[i][j] = " ";
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

void Engine::Scene::place_entities(void) {
  for (int i = 0; i < this->entities_size; i++) {
    Engine::Entity *entity = this->entity_manager->get(i);
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

bool Engine::Scene::is_colliding(Entity *left, Entity *right) {
  Position left_pos = left->get_pos();
  Position right_pos = right->get_pos();

  bool is_colliding_top = false;
  bool is_colliding_side = false;

  if (left_pos.y > right_pos.y) {
    is_colliding_top = left_pos.y - right_pos.y == 1 ? true : false;
  } else {
    is_colliding_top = right_pos.y - left_pos.y == 1 ? true : false;
  }

  if (left_pos.x > right_pos.x) {
    is_colliding_side = left_pos.x - right_pos.x == 1 ? true : false;
  } else {
    is_colliding_side = right_pos.x - left_pos.x == 1 ? true : false;
  }

  bool is_colliding = is_colliding_top || is_colliding_side;

  String msg;

  msg.append(left->get_alias());
  msg.append(" and ");
  msg.append(right->get_alias());
  msg.append(" is colliding: ");
  msg.append(std::to_string(is_colliding));

  this->debugger->push_message(msg);

  return is_colliding;
}
