#pragma once

#include <iostream>

typedef std::string String;

typedef struct Position {
  int x;
  int y;
} Position;

namespace Engine {

class Entity {
  private:
    int id;
    String draw;
    Position pos;

  public:
    Entity(String draw);
    ~Entity() { delete this; }

    void update(int x, int y);
    void set_id(int id);
    int get_id(void) const { return this->id; }
    String get_draw(void) const { return this->draw; }
    Position get_pos(void) const { return this->pos; }
};

}
