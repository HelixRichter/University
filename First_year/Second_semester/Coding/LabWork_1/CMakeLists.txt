cmake_minimum_required(VERSION 3.21)
project(Ultra_Modified_LabWork_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(alexk_hlp/lab1/code)
include_directories(alexk_hlp/lab1/lab1_no_CLI)
include_directories(alexk_hlp/lab1/res)

add_executable(Ultra_Modified_LabWork_1
        alexk_hlp/lab1/code/dict.c
        alexk_hlp/lab1/code/dict.h
        alexk_hlp/lab1/code/main.c
        alexk_hlp/lab1/lab1_no_CLI/dict.c
        alexk_hlp/lab1/lab1_no_CLI/dict.h
        alexk_hlp/lab1/lab1_no_CLI/main.c
        alexk_hlp/lab1/res/core.c
        alexk_hlp/lab1/res/dict.c
        alexk_hlp/lab1/res/dict.h)
