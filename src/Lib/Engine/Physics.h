#pragma once

#include "Utils/Debugger.h"
#include "Entity.h"

namespace Engine {

class Physics {
  private:
    Utils::Debugger *debugger;    
    bool overlapping(int min_a, int max_a, int min_b, int max_b);

  public:
    Physics(Utils::Debugger *debugger);

    bool is_colliding(Entity *left, Entity *right);
};

}
