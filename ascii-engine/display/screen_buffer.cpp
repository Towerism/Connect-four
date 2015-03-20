#include <iostream>
#include "screen_buffer.h"

namespace ae = ascii_engine;
using namespace std;

ae::Screen_buffer::Screen_buffer(int width, int height, char val) :
    width(width), height(height) {
    // initialize the container
    for (int i = 0; i < height; ++i) {
        vector<char> row(width, val);
        buffer.push_back(row);
    }
}

void ae::Screen_buffer::set_char(int x, int y, char val) {
    buffer[y][x] = val;
}

ostream& ae::operator<<(ostream& os, const ae::Screen_buffer& buf) {
    ae::buffer_t buffer = buf.get_buffer();
    for (const auto& vec : buffer) {
        for (char c : vec) {
            os << c;
        }
        os << '\n';
    }
}
