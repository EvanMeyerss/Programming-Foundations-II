cmake_minimum_required(VERSION 3.25)
project(Project_1)

set(CMAKE_CXX_STANDARD 17)

set(Headers BestSeller.h table.h)

add_executable(Project_1 main.cpp
        BestSeller.cpp
        table.h
        table.cpp)
