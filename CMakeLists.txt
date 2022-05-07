project(hw)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
add_executable(random random.cpp)

add_executable(class
        class19/class19.cpp
        class18/SimpleNode.cpp class18/SimpleNode.h
        class18/SimpleList.cpp class18/SimpleList.h
        class18/ListNode.cpp class18/ListNode.h
        class18/ListList.cpp class18/ListList.h
        cmake-build-debug/input.txt cmake-build-debug/output.txt)

add_executable(hw
        hw14/hw14.cpp
        hw14/Node.h hw14/Node.cpp
        hw14/SparsePoly.cpp hw14/SparsePoly.h
        cmake-build-debug/input.txt cmake-build-debug/output.txt)

add_executable(ihw
        ihw3/ihw3.cpp
        cmake-build-debug/input.txt cmake-build-debug/output.txt)