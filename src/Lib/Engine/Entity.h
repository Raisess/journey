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
    String draw;
    Position pos;

  public:
    Entity(String draw);

    void update(int x, int y);
    String getDraw(void) const { return this->draw; }
    Position getPos(void) const { return this->pos; }
};

}
