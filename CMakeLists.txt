cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")

add_executable(untitled main_header.h struct_header.h list_header.h deque_header.h main.cpp functions.cpp iostream_input_functions.cpp list_functions.cpp deque_functions.cpp)