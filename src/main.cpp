#include "./Lib/Engine/Scene.h"

int main() {
  Engine::Scene *scene = new Engine::Scene(60, 20);

  Engine::Entity *block_one = new Engine::Entity("|+|");
  Engine::Entity *block_two = new Engine::Entity("|-|");
  Engine::Entity *ball = new Engine::Entity("O");

  scene->attach_entity("block-one", block_one);
  scene->attach_entity("block-two", block_two);
  scene->attach_entity("ball", ball);

  int c = 0;
  int y1 = 0;
  bool back = false;

  int x = 1;
  int y = 0;
  bool ball_back = false;

  while (true) {
    scene->update_entity(block_one, 0, y1);
    scene->update_entity(block_two, 59, y1);
    scene->update_entity(ball, x, y);
    scene->draw();

    if (ball_back) {
      x--;
      if (x == 1) {
        ball_back = !ball_back;
      }
    } else {
      x++;
      if (x == 58) {
        ball_back = !ball_back;
      }
    }

    if (back) {
      c--;
      y--;
      y1--;
      if (c == 0) {
        back = !back;
      }
    } else {
      c++;
      y++;
      y1++;
      if (c == 20) {
        back = !back;
      }
    }
  }

  return 0;
}
