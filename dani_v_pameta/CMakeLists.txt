cmake_minimum_required(VERSION 3.26)
project(dani_v_pameta C)

set(CMAKE_C_STANDARD 11)

add_executable(dani_v_pameta main.c
        safeint.h
        safeint.c
        safeadd.c
        safusubtruct.c
        safemultiply.c
        safedivide.c)
