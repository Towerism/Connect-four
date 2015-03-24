cmake_minimum_required(VERSION 3.2.1 FATAL_ERROR)

project(connect-four)

list(APPEND CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")

set(CMAKE_CXX_FLAGS "-Wall -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O4 -DNDEBUG")

# set these curses variables to the correct paths on your system
set(curses_include_dir "C:/pdcurs34/")
set(curses_lib "C:/pdcurs34/win32/pdcurses.a")
set(curses_lib_name pdcurses) # the name of the lib, ncurses on unix
add_library(${curses_lib_name} STATIC IMPORTED)
set_target_properties(${curses_lib_name} PROPERTIES IMPORTED_LOCATION ${curses_lib})


include_directories("include") # public headers
include_directories("src")
include_directories("lib") # library implementation and private headers

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(bin)
