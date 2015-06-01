#include "game_world.h"
#include "entities/game_board.h"

using namespace std;

Game_world::Game_world(int x, int y) : 
  ascii_engine::World(x, y), board(new Game_board(1, 1)) {
    add(board);
    // add(shared_ptr<ae::Entity>(new Test_entity(0, 0)));
  }

void Game_world::update(double delta_time) {
  // do update stuff
  // call parent function
  ascii_engine::World::update(delta_time);
}
