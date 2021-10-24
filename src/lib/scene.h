#include "entity.h"

class Scene {
  private:
    String scene[100][100];
    int entities_size;
    int height;
    int width;
    Entity *entities[];

    void draw(void);
    void reset(void);

  public:
    Scene(int width, int height);

    void attach_entity(Entity *entity);
    void update(void);
};
