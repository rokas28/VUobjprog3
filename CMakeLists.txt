cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")

add_executable(untitled headers/main_header.h headers/struct_header.h headers/list_header.h headers/deque_header.h main.cpp functions/functions.cpp functions/iostream_input_functions.cpp functions/list_functions.cpp functions/deque_functions.cpp)