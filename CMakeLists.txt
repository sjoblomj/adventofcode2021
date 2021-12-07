cmake_minimum_required(VERSION 3.21)
project(adventofcode2021)

set(CMAKE_CXX_STANDARD 17)

add_executable(adventofcode2021 main.cpp utils.cpp)
add_executable(tests tests.cpp utils.cpp)

include(CTest)
enable_testing()
add_test(NAME adventofcode2021_tests COMMAND tests)
