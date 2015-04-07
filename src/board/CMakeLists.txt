set(board_sources bit_boards.cpp)
add_library(board ${board_sources})

set(board_libs "")
target_link_libraries(board ${board_libs})
