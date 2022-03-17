project(hw)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
add_executable(random random.cpp)

add_executable(class14 class14/class14.cpp
        class14/Node.h class14/Node.cpp
        class14/List.h class14/List.cpp
        cmake-build-debug/input.txt cmake-build-debug/output.txt)

add_executable(hw
        hw13/hw13.cpp
        hw13/polynome.cpp hw13/polynome.h
        cmake-build-debug/input.txt cmake-build-debug/output.txt)

add_executable(ihw
        ihw1/ihw1.cpp
        ihw1/TPoint.cpp ihw1/TPoint.h
        cmake-build-debug/input.txt cmake-build-debug/output.txt)