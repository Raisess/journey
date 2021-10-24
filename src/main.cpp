#include "./lib/scene.h"

int main() {
  Scene *scene = new Scene(60, 20);

  Entity *block_one = new Entity("|+|");
  Entity *block_two = new Entity("|-|");
  Entity *ball = new Entity("O");

  scene->attach_entity(block_one);
  scene->attach_entity(block_two);
  scene->attach_entity(ball);

  int c = 0;
  int y1 = 0;
  bool back = false;

  int x = 1;
  int y = 0;
  bool ball_back = false;

  while (true) {
    block_one->update(0, y1);
    block_two->update(59, y1);
    ball->update(x, y);
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
