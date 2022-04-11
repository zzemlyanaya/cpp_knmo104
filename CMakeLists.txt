project(hw)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
add_executable(random random.cpp)

add_executable(class
        class15/class15.cpp
        class15/Node.h class15/Node.cpp
        class15/Dict.h class15/Dict.cpp
        cmake-build-debug/input.txt cmake-build-debug/output.txt)

add_executable(hw
        hw14/hw14.cpp
        hw14/Node.h hw14/Node.cpp
        hw14/SparsePoly.cpp hw14/SparsePoly.h
        cmake-build-debug/input.txt cmake-build-debug/output.txt)

add_executable(ihw
        ihw2/ihw2.cpp
        cmake-build-debug/input.txt cmake-build-debug/output.txt)