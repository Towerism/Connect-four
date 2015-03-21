#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "ascii-engine/world.h"

namespace ae = ascii_engine;

struct Game_world : ae::World {
    Game_world(int x, int y);
    override void update(double delta_time);
}

#endif // GAME_WORLD_H
