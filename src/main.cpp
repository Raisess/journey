#include "./lib/scene.h"

int main() {
  Scene *scene = new Scene(60, 20);

  Entity *block_one = new Entity("|+|");
  Entity *block_two = new Entity("O");
  Entity *block_three = new Entity("|-|");

  scene->attach_entity(block_one);
  scene->attach_entity(block_two);
  scene->attach_entity(block_three);

  int c = 0;
  int y1 = 0;
  bool back = false;

  int x = 0;
  int y = 0;

  while (true) {
    block_one->update(0, y1);
    block_two->update(x, y);
    block_three->update(59, y1);
    scene->update();

    if (back) {
      c--;
      y1--;
      if (c == 0) {
        back = !back;
      }
    } else {
      c++;
      y1++;
      if (c == 20) {
        back = !back;
      }
    }
  }

  return 0;
}
