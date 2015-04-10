#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "ascii-engine/entity.h"

struct Game_board : ascii_engine::Entity {
  Game_board(int x, int y);
  virtual void update(double delta_time) override;
};

#endif // GAME_BOARD_H
