#ifndef FRAMERATE_LIMITER_H
#define FRAMERATE_LIMITER_H

#include <chrono>
#include <math.h>

#ifdef _WIN32
    #include <windows.h>
    void sleep(unsigned milliseconds) {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>
    void sleep(unsigned milliseconds) {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif

using namespace std;
using namespace chrono;

namespace ascii_engine {
    struct Framerate_limiter {
        Framerate_limiter(int target) : 
            target_fps(target), target_dur(steady_clock::period::den/target) { }
        void frame_start() {
            start = clock.now();
        }
        void frame_end() {
            end = time_point_cast<milliseconds>(clock.now());
            frame_time = end - start;
            if (frame_time.count() < target_dur.count()) {
                milliseconds sleep_length = duration_cast<milliseconds>(target_dur - frame_time);
                sleep(sleep_length.count());
                delta_time = frame_time + sleep_length;
            } else {
                delta_time = frame_time;
            }
        }
        double get_delta_time() { return duration_cast<duration<double>>(delta_time).count(); }
    private:
        steady_clock clock;
        int target_fps;
        steady_clock::duration target_dur, frame_time, delta_time;
        steady_clock::time_point start, end;
    };
}

#endif // FRAMERATE_LIMITER_H
