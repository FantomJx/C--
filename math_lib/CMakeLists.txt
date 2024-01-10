cmake_minimum_required(VERSION 3.26)
project(math_lib C)

set(CMAKE_C_STANDARD 11)

add_executable(math_lib main.c
        maths.c)
