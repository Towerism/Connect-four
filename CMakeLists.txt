cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(connect-four)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O4 -DNDEBUG")

# set these curses variables to the correct paths on your system
if (WIN32)
    set(curses_include_dir "C:/pdcurs34/")
    set(curses_lib "C:/pdcurs34/win32/pdcurses.a")
    set(curses_lib_name pdcurses) # the name of the lib, ncurses on unix
    add_library(${curses_lib_name} STATIC IMPORTED)
elseif (UNIX)
    set(CURSES_NEED_NCURSES TRUE)
    find_package(Curses REQUIRED)
    set(curses_include_dir ${CURSES_INCLUDE_DIR})
    set(curses_lib_name ${CURSES_LIBRARIES})
    set(curses_lib ${CURSES_LIBRARIES})
endif (WIN32)
include_directories(${CURSES_INCLUDE_DIR})

include_directories("src")
include_directories("lib") # library implementation and private headers
include_directories("lib/ascii-engine/include") # ascii-engine public headers

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(bin)
