#include <memory>
#include "renderer.h"
#include "renderable.h"

namespace ae = ascii_engine;

void ae::Renderer::add(shared_ptr<Renderable> r) {
    renderables.push_back(r);
}

void ae::Renderer::render() {
    for (const auto& r : renderables) {
        canvas.draw(r->get_x(), r->get_y(), r->get_graphic());
        cout << canvas;
    }
}
