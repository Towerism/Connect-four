add_subdirectory(entities)
add_subdirectory(contexts)
add_subdirectory(player)
add_subdirectory(board)

set(project_sources main.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${project_sources})

set(project_libs asciiengine entities contexts player board)
target_link_libraries(${CMAKE_PROJECT_NAME} ${project_libs})

