#Version Cmake
cmake_minimum_required(VERSION 3.0)

#projet
project("Lightup" C)

include(CTest)
enable_testing()

#on cherche SDL2
find_package(SDL2 REQUIRED)

set(SDL2_ALL_INC ${SDL2_INCLUDE_DIRS})
set(SDL2_ALL_LIBS ${SDL2_LIBRARIES} -lSDL2_ttf -lSDL2_image) # add extra SDL2 libraries

message(STATUS "SDL2 include dir: ${SDL2_ALL_INC}")
message(STATUS "SDL2 all libraries: ${SDL2_ALL_LIBS}")

include_directories(${SDL2_ALL_INC})

#variable
set(CMAKE_C_FLAGS "-std=c99 -Wall -pthread -L SDL2")
set(CMAKE_C_FLAGS_DEBUG "-g --coverage -D DEBUG")    # use CMake option: -DCMAKE_BUILD_TYPE=DEBUG
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")   # use CMake option: -DCMAKE_BUILD_TYPE=RELEASE

add_library(op library/op.c library/aux.c)

add_executable(operation op_text.c)
add_executable(sdl main.c)
add_executable(test_op test.c)

target_link_libraries(operation op m)
target_link_libraries(sdl op ${SDL2_ALL_LIBS})
target_link_libraries(test_op op)
