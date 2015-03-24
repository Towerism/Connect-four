set(entities_sources game_board.cpp test_entity.cpp)
add_library(entities ${entities_sources})

target_include_directories(entities PUBLIC ${curses_include_dir})

set(entities_libs worlds ${curses_lib_name})
target_link_libraries(entities ${entities_libs})