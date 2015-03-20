#include "engine.h"

namespace ae = ascii_engine;
using namespace std;

void ae::Engine::game_loop() {
    in_loop = true;
    while (!exit_loop) {
        world->update();
    }
}

int main() {
    ae::Engine engine;
    shared_ptr<ae::World> world(new ae::World(50, 50));
    world->add(make_shared<ae::Entity>(0, 0, "000\n000\n000"));
    world->add(make_shared<ae::Entity>(0, 0, "111\n101\n111"));
    world->add(make_shared<ae::Entity>(1, 1, "2"));
    engine.set_world(world);
    engine.game_loop();
}
