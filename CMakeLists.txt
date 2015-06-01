cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(connect-four)

list(APPEND CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")

set(CMAKE_CXX_FLAGS "-Wall -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O4 -DNDEBUG")

include_directories("src")
include_directories("lib") # library implementation and private headers
include_directories("lib/ascii-engine/include/") # ascii-engine public headers

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

set(project_sources main.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${project_sources})

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)

set(project_libs asciiengine entities worlds player board)
target_link_libraries(${CMAKE_PROJECT_NAME} ${project_libs})

