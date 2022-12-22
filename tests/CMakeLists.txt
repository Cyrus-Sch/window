cmake_minimum_required(VERSION 3.10)
project(MyProject)

# set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add Google Test as a subdirectory
add_subdirectory(googletest)

# add the source files for the project
add_executable(MyProject test.cpp )

# link Google Test to the project
target_link_libraries(MyProject gtest gtest_main)

# enable testing with CTest
enable_testing()

# add a test named "MyTest" that runs the binary created by the "MyProject" target
add_test(NAME MyTest COMMAND MyProject)

