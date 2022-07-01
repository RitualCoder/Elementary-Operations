cmake_minimum_required(VERSION 3.10)

# set the project name
project(operation)

set(CMAKE_C_FLAGS "-std=c99 -g -Wall")

add_library(op aux_func/aux.c)

add_executable(operation op.c)

target_link_libraries(operation op m)
