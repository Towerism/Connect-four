#include <memory>
#include <ascii_engine.h>
#include "contexts/game_context.h"

using namespace std;

int main() {
  ascii_engine::Engine engine(60);
  engine.set_context(new Game_context());
  engine.game_loop();
}
