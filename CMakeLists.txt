cmake_minimum_required(VERSION 3.7)
project(window)

find_package(SDL2 REQUIRED)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})
add_executable(SDL2Test main.cpp Screen.cpp Screen.h Transform.cpp Transform.h LA_Array.cpp LA_Array.h tests/LA_Array/LA_Array_unit_tests.cpp)
target_link_libraries(SDL2Test ${SDL2_LIBRARIES})


