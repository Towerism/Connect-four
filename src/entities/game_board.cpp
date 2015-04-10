#include "game_board.h"

Game_board::Game_board(int x, int y) : ascii_engine::Entity(x, y) {
  set_graphic("|_|_|_|_|_|_|_|\n"
      "|_|_|_|_|_|_|_|\n"
      "|_|_|_|_|_|_|_|\n"
      "|_|_|_|_|_|_|_|\n"
      "|_|_|_|_|_|_|_|\n"
      "|_|_|_|_|_|_|_|\n"
      " 1 2 3 4 5 6 7");
}

void Game_board::update(double delta_time) {
  // do update stuff
  // call parent function
  ascii_engine::Entity::update(delta_time);
}
