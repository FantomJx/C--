cmake_minimum_required(VERSION 3.26)
project(mystrings C)

set(CMAKE_C_STANDARD 11)

add_executable(mystrings mystrings.c
        mystrings.h
)
