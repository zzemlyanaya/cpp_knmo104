project(hw)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
add_executable(random random.cpp)

add_executable(class
        class14/class14.cpp
        class14/Node.h class14/Node.cpp
        class14/List.h class14/List.cpp
        cmake-build-debug/input.txt cmake-build-debug/output.txt)

add_executable(hw
        hw14/hw14.cpp
        hw14/Node.h hw14/Node.cpp
        hw14/SparsePoly.cpp hw14/SparsePoly.h
        cmake-build-debug/input.txt cmake-build-debug/output.txt)

add_executable(ihw
        ihw1/ihw1.cpp
        ihw1/TPoint.cpp ihw1/TPoint.h
        cmake-build-debug/input.txt cmake-build-debug/output.txt)