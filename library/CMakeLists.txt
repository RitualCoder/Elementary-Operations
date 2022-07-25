#Version Cmake
cmake_minimum_required(VERSION 3.0)

#projet
project("Lightup" C)

include(CTest)
enable_testing()

#variable
set(CMAKE_C_FLAGS "-std=c99 -Wall -pthread -L SDL2")
set(CMAKE_C_FLAGS_DEBUG "-g --coverage -D DEBUG")    # use CMake option: -DCMAKE_BUILD_TYPE=DEBUG
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")   # use CMake option: -DCMAKE_BUILD_TYPE=RELEASE

add_library(op op.c aux.c)

add_executable(operation op_text.c)
add_executable(test_op test.c)

target_link_libraries(operation op m)
target_link_libraries(test_op op)

add_test(test_op_addition ./test_op add)
add_test(test_op_substraction ./test_op sub)
add_test(test_op_multiplication ./test_op mul)
add_test(test_op_division ./test_op div)
add_test(test_op_pow ./test_op pow)


