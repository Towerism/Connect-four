#include <iostream>
#include <algorithm>
#include "C:/pdcurs34/curses.h"
#include "screen_buffer.h"

namespace ae = ascii_engine;
using namespace std;

ae::Screen_buffer::Screen_buffer(int width, int height, char val) :
    width(width), height(height) {
    // set up console for curses
    noecho();
    curs_set(0);
    // initialize the container
    for (int i = 0; i < height; ++i) {
        vector<char> row(width, val);
        buffer.push_back(row);
    }
}

void ae::Screen_buffer::clear() {
    for (auto& vec : buffer) {
        fill(vec.begin(), vec.end(), ' ');
    }
}

void ae::Screen_buffer::set_char(int x, int y, char val) {
    buffer[y][x] = val;
}

ostream& ae::operator<<(ostream& os, const ae::Screen_buffer& buf) {
    ae::buffer_t buffer = buf.get_buffer();
    // clear screen before outputting the buffer
    clear();
    for (int i = 0; i < buf.get_width(); ++i) {
        for (int j = 0; j < buf.get_height(); ++j) {
            mvprintw(j, i, "%c", buffer.at(j).at(i));
        }
    }
    refresh();
    /*
    for (const auto& vec : buffer) {
        for (char c : vec) {
            os << c;
        }
        os << '\n';
    }*/
    return os;
}
