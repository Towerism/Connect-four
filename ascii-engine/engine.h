#include <memory>
#include "world.h"

using namespace std;

namespace ascii_engine {
    struct Engine {
        Engine(int fps) : target_fps(fps) { }
        void game_loop();
        void terminate_loop() { exit_loop = in_loop; }

        // setters
        void set_world(shared_ptr<World> w) { world = w; }
    private:
        shared_ptr<World> world;
        int target_fps;
        bool in_loop = false;
        bool exit_loop = false;
    };
}
