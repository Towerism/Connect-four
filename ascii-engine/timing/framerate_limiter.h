#include <chrono>
#include <thread>

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
            delta_time = end - start;
            if (delta_time.count() < target_dur.count()) {
                unsigned sleep_length = duration_cast<milliseconds>(target_dur - delta_time).count();
                sleep(sleep_length);
            }
        }
        double get_delta_time() { return duration_cast<duration<double>>(delta_time).count(); }
    private:
        steady_clock clock;
        int target_fps;
        steady_clock::duration target_dur, delta_time;
        steady_clock::time_point start, end;
    };
}
