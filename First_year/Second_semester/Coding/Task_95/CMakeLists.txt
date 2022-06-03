cmake_minimum_required(VERSION 3.22)
project(MyTask_1_95)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MyTask_1_95
        main.cpp
        movebot.cpp
        movebot.h)
