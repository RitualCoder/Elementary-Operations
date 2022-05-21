cmake_minimum_required(VERSION 3.10)

# set the project name
project(operation)

add_executable(operation op.c)

target_link_libraries(operation PRIVATE m)