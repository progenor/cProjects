cmake_minimum_required(VERSION 3.26)
project(project_06 C)

set(CMAKE_C_STANDARD 23)

add_executable(project_06 main.c
        arrayFunctions.h
        arrayFunctions.c
)
