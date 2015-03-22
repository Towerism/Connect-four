#include "ascii-engine/engine.h"
#include "ascii-engine/timing/framerate_limiter.h"
#include "ascii-engine/input/input_handler.h"

namespace ae = ascii_engine;
using namespace std;

void ae::Engine::game_loop() {
    using Input_handler = ae::Input_handler;
    Framerate_limiter fps_limiter(target_fps);
    Input_handler& input = Input_handler::get_instance();
    in_loop = true;
    while (!exit_loop) {
        fps_limiter.frame_start();
        input.poll();
        world->update(fps_limiter.get_delta_time());
        fps_limiter.frame_end();
    }
}
