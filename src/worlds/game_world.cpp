#include "game_world.h"

Game_world::Game_world(int x, int y) : ascii_engine::World(x, y) {
    // do initializing things
    //
}

void Game_world::update(double delta_time) {
    // do update stuff
    // call parent function
    ascii_engine::World.update(delta_time);
}
