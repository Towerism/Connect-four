#include "entities/test_entity.h"
#include "ascii-engine/input_handler.h"
#include <curses.h>

Test_entity::Test_entity(int x, int y) : ascii_engine::Entity(x, y) {
    set_graphic("@");
}

void Test_entity::update(double delta_time) {
    ascii_engine::Input_handler& input = ascii_engine::Input_handler::get_instance();
    if (input.check_key('i')) {
        translate(0, -1);
    }
    if (input.check_key('k')) {
        translate(0, 1);
    }
    if (input.check_key('j')) {
        translate(-1, 0);
    }
    if (input.check_key('l')) {
        translate(1, 0);
    }
}
