#include <sstream>
#include <string>
#include "canvas.h"

namespace ae = ascii_engine;
using namespace std;

void ae::Canvas::draw(int x, int y, const string& s) {
    istringstream iss(s);
    int j = y;
    while (iss.good() && !s.empty() && j < buffer.get_height()) {
        string line;
        getline(iss, line);
        for (int i = x; i < buffer.get_width() && i - x < line.length(); ++i) {
            if (i < 0 || j < 0) {
                continue;
            }
            buffer.set_char(i, j, line[i - x]);
        }
        ++j;
    }
}

ostream& ae::operator<<(ostream& os, const ae::Canvas& canvas) {
    // clear the screen before we write to the output stream
    #ifdef _WIN32
        system("cls");
    #else // Assume POSIX
        system("clear");
    #endif

    return os << canvas.get_buffer();
}

int main() {
    ae::Canvas canvas(5, 5);
    canvas.draw(-2,-2,"hi\nmy name is\nmartin\nfracker");
    cout << canvas;
}
