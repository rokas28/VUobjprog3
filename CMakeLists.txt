cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")

add_executable(untitled headers/main_header.h headers/studentas.h main.cpp functions/functions.cpp functions/studentas.cpp headers/studentas.h)