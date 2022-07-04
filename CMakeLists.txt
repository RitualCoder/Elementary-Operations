cmake_minimum_required(VERSION 3.10)

# set the project name
project(operation)

include(CTest)
enable_testing()

set(CMAKE_C_FLAGS "-std=c99 -g -Wall")

add_library(op op.c aux_func/aux.c)

add_executable(operation op_text.c)
add_executable(test_op test.c)

target_link_libraries(operation op m)
target_link_libraries(test_op op)

