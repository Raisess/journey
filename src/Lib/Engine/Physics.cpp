#include "Physics.h"

Engine::Physics::Physics(Utils::Debugger *debugger) {
  this->debugger = debugger;
}

bool Engine::Physics::is_colliding(Entity *left, Entity *right) {
  Position left_pos = left->get_pos();
  Position right_pos = right->get_pos();

  int a_left = left_pos.x;
  int a_right = left_pos.x + 1;
  int b_left = right_pos.x;
  int b_right = right_pos.x + 1;

  int a_top = left_pos.y;
  int a_bottom = left_pos.y + 1;
  int b_top = right_pos.y;
  int b_bottom = right_pos.y + 1;

  bool is_colliding = 
    this->overlapping(a_left, a_right, b_left, b_right) && 
    this->overlapping(a_top, a_bottom, b_top, b_bottom);

  String msg;

  msg.append(left->get_alias());
  msg.append(" and ");
  msg.append(right->get_alias());
  msg.append(" is colliding: ");
  msg.append(std::to_string(is_colliding));

  this->debugger->push_message(msg);

  return is_colliding;
}

bool Engine::Physics::overlapping(int min_a, int max_a, int min_b, int max_b) {
  return min_b <= max_a && min_a <= max_b;
}
