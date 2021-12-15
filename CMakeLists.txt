cmake_minimum_required(VERSION 3.20)
project(hw)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
add_executable(hw hw11.cpp cmake-build-debug/input.txt cmake-build-debug/output.txt)
add_executable(random random.cpp)
