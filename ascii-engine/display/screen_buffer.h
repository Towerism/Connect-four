#ifndef SCREEN_BUFFER_H
#define SCREEN_BUFFER_H

#include <vector>
#include <iostream>

using namespace std;

namespace ascii_engine {
    typedef vector<vector<char>> buffer_t;
    struct Screen_buffer {

        Screen_buffer(int width, int height, char val = ' ');
        
        void clear();

        // setters
        void set_char(int x, int y, char val);

        // getters
        int get_width() const { return width; }
        int get_height() const { return height; }
        const buffer_t& get_buffer() const { return buffer; }

    private:
        int width, height;
        buffer_t buffer;
    };

    ostream& operator<<(ostream& os, const Screen_buffer& buf);
}

#endif // SCREEN_BUFFER_H
