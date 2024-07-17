cmake_minimum_required(VERSION 3.26)
project(final_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(final_project main.cpp
        Person.cpp
        Person.h
        Info.cpp
        Info.h
        Functions.cpp
        Functions.h
        Exception.h)
