#ifndef TEST_ENTITY_H
#define TEST_ENTITY_H

#include <ascii_engine.h>

struct Test_entity : ascii_engine::Entity {
  Test_entity(int x, int y);
  virtual void update(double delta_time);
};

#endif // TEST_ENTITY_H

