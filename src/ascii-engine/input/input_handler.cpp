#include <chrono>
#include <algorithm>
#include <curses.h>
#include "ascii-engine/input/input_handler.h"

namespace ae = ascii_engine;
using namespace std;
using namespace chrono;

ae::Input_handler::Input_handler() {
    raw();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
}

void ae::Input_handler::poll() {
    char c;
    // clear keys unused from last poll
    input_vec.clear();
    while(true) {
        c = getch();
        if (c == ERR) {
            break;
        }
        input_vec.push_back(c);
    }
}

bool ae::Input_handler::check_key(char key) {
    const auto& it = find_if(input_vec.begin(), input_vec.end(),
        [key](const char& c) { return c == key; }
    );
    if (it != input_vec.end()) {
        input_vec.erase(it);
        return true;
    }
    return false;
}
