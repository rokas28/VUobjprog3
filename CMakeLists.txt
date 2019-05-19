cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")

add_executable(untitled main.cpp )

include_directories(code)
add_subdirectory(code)
add_subdirectory(VUobjprog3_test)

target_link_libraries(untitled code)