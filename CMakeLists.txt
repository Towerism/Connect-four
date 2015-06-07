cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(connect-four)

list(APPEND CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O4 -DNDEBUG")

include_directories("src")
include_directories("lib/ascii-engine/src/")
include_directories("lib/ascii-engine/include/ascii-engine/")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)

