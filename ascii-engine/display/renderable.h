#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <string>

using namespace std;

namespace ascii_engine {
    struct Renderable {
        Renderable(int x, int y) : Renderable(x, y, "") { }
        Renderable(int x, int y, string s) : x(x), y(y), graphic(s) { }

        // setters
        void set_graphic(const string& s) { graphic = s; }

        // getters
        const string& get_graphic() const { return graphic; }
        int get_x() const { return x; }
        int get_y() const { return y; }
    private:
        string graphic;
        int x, y;
    };
}

#endif // RENDERABLE_H
