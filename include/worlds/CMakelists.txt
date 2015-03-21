set(worlds_sources game_world.cpp)
add_library(worlds ${worlds_sources})

set(worlds_libs entities)
target_link_libraries(worlds ${worlds_libs})
