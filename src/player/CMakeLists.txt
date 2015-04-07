set(player_sources player.cpp)
add_library(player ${player_sources})

set(player_libs "")
target_link_libraries(player ${player_libs})
