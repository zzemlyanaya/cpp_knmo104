cmake_minimum_required(VERSION 3.20)
project(hw)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
add_executable(hw hw10.cpp cmake-build-debug/input.txt)
add_executable(random random.cpp)
