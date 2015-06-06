#include "game_context.h"
#include "entities/test_entity.h"
#include "entities/game_board.h"

using namespace std;

Game_context::Game_context() : Context(15, 25), board(new Game_board(1, 1)) {
  //add(board);
  add(new Test_entity(0, 0));
}

void Game_context::update(double delta_time) {
  ascii_engine::Context::update(delta_time);
}
