#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include <vector>
#include "entity/entity.h"
#include "display/renderer.h"

using namespace std;

namespace ascii_engine {
    struct World {
        World(int x, int y) : renderer(x, y) { }
        void add(shared_ptr<Entity> e);
        void remove(shared_ptr<Entity> e) { remove(e.get()); }
        void remove(Entity* e);

        virtual void update();
    private:
        vector<shared_ptr<Entity>> entities;
        Renderer renderer;
    };
}

#endif // WORLD_H
