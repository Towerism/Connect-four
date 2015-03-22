#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <vector>

namespace ascii_engine {
    struct Input_handler {
        static Input_handler& get_instance() {
            static Input_handler instance;
            return instance;
        }
        Input_handler();
        void poll();
        bool check_key(char key_code);
    private:
        std::vector<char> input_vec;

        Input_handler(const Input_handler&) = delete;
        void operator=(const Input_handler&) = delete;
    };
}

#endif // INPUT_HANDLER_H
