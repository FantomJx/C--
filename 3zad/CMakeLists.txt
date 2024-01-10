cmake_minimum_required(VERSION 3.26)
project(3zad C)

set(CMAKE_C_STANDARD 11)

add_executable(3zad strlength.c
        strcompare.c
        help.c
        strconcat.c)
