#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <memory>
#include <ascii_engine.h>

namespace ae = ascii_engine;

struct Game_context : ae::Context {
  Game_context();
  virtual void update(double delta_time);
private:
  std::shared_ptr<ae::Entity> board;
};

#endif // GAME_WORLD_H
