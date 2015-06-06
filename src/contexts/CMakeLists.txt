set(contexts_sources game_context.cpp)
add_library(contexts ${contexts_sources})

set(contexts_libs entities)
target_link_libraries(contexts ${contexts_libs})
