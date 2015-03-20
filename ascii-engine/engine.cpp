#include "engine.h"
#include "timing/framerate_limiter.h"

namespace ae = ascii_engine;
using namespace std;

void ae::Engine::game_loop() {
    in_loop = true;
    Framerate_limiter fps_limiter(target_fps);
    while (!exit_loop) {
        fps_limiter.frame_start();
        world->update();
        fps_limiter.frame_end();
    }
}
