#include <iostream>

typedef std::string String;

typedef struct Position {
  int x;
  int y;
} Position;

typedef struct TEntity {
  String draw;
  Position pos;
} TEntity;

class Entity {
  private:
    String draw;
    Position pos;

  public:
    Entity(String draw);

    void update(int x, int y);
    TEntity *get(void);
};
