#include <iostream>
#include <algorithm>
#include <curses.h>
#include "ascii-engine/display/screen_buffer.h"

namespace ae = ascii_engine;
using namespace std;

ae::Screen_buffer::Screen_buffer(int width, int height, char val) :
    width(width), height(height) {
    // set up console for curses
    initscr();
    //noecho();
    curs_set(0);
    clear();
    // initialize the container
    for (int i = 0; i < height; ++i) {
        vector<char> row(width, val);
        buffer.push_back(row);
    }
}

void ae::Screen_buffer::purge() {
    for (auto& vec : buffer) {
        fill(vec.begin(), vec.end(), ' ');
    }
}

void ae::Screen_buffer::set_char(int x, int y, char val) {
    buffer[y][x] = val;
}

void ae::Screen_buffer::flush() {
    // clear screen before outputting the buffer
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            mvprintw(j, i, "%c", buffer.at(j).at(i));
        }
    }
    purge();
    refresh();
}
