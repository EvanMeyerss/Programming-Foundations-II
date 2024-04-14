cmake_minimum_required(VERSION 3.26)
project(project_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(project_2 main.cpp
        table.cpp
        table.h
        BestSellerNode.cpp
        BestSellerNode.h
        BestSellerList.cpp
        BestSellerList.h)
