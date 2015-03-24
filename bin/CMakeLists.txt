set(executable_sources main.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${executable_sources})

set(executable_libs asciiengine entities worlds ${curses_lib_name})
target_link_libraries(${CMAKE_PROJECT_NAME} ${executable_libs})
