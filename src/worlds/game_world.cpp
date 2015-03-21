#include "game_world.h"

Game_world::Game_world(int x, int y) : 
    ascii_engine::World(x, y), board(new Game_board(1, 1)) {
    add(board);
}

void Game_world::update(double delta_time) {
    // do update stuff
    // call parent function
    ascii_engine::World::update(delta_time);
}
