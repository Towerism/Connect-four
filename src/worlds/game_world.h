#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <memory>
#include "../ascii-engine/world.h"
#include "../entities/game_board.h"
#include "../ascii-engine/entity/entity.h"

namespace ae = ascii_engine;

struct Game_world : ae::World {
    Game_world(int x, int y);
    virtual void update(double delta_time);
private:
    shared_ptr<ascii_engine::Entity> board;
};

#endif // GAME_WORLD_H
