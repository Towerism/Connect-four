#include <memory>
#include <ascii_engine.h>
#include "worlds/game_world.h"

using namespace std;

int main() {
  ascii_engine::Engine engine(60);
  engine.set_world(shared_ptr<ascii_engine::World>(new Game_world(25, 15)));
  engine.game_loop();
}
