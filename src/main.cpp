#include <memory>
#include "worlds/game_world.h"
#include "ascii-engine/engine.h"

int main() {
    int width = 50, height = 25;
    ascii_engine::Engine engine(width, height);
    engine.set_world(shared_ptr<World>(new Game_world(width, height));
    engine.game_loop();
}
