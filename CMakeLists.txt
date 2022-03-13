project(hw)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
add_executable(random random.cpp)

add_executable(class13
        class13/class13.cpp
        class13/geometry.h class13/geometry.cpp
        cmake-build-debug/input.txt cmake-build-debug/output.txt)

add_executable(hw
        hw13/hw13.cpp
        hw13/polynome.cpp hw13/polynome.h
        cmake-build-debug/input.txt cmake-build-debug/output.txt)