set(entities_sources game_board.cpp test_entity.cpp)
add_library(entities ${entities_sources})

set(entities_libs worlds ${curses_lib_name})
target_link_libraries(entities ${entities_libs})
