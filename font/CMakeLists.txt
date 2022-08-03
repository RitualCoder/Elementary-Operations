cmake_minimum_required(VERSION 3.0)

project(Font C)

foreach(file "04B_20__.ttf")
  file(COPY ${file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endforeach(file)