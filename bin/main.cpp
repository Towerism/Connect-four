#include <memory>
#include "worlds/game_world.h"
#include "ascii-engine/engine.h"

using namespace std;

int main() {
    ascii_engine::Engine engine(60);
    engine.set_world(shared_ptr<ae::World>(new Game_world(25, 15)));
    engine.game_loop();
}
