#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <memory>
#include "renderable.h"
#include "canvas.h"

using namespace std;

namespace ascii_engine {
    struct Renderer {
        Renderer(int width, int height) : canvas(width, height) { };
        void add(shared_ptr<Renderable> r);
        void render();
    private:
        vector<shared_ptr<Renderable>> renderables;
        Canvas canvas;
    };
}

#endif // RENDERER_H
