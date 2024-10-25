cmake_minimum_required(VERSION 3.26)
project(final_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(final_project main.cpp
        Person.cpp
        Person.h
        User.cpp
        User.h
        Functions.cpp
        Functions.h
        WrongChoice.h
        Admin.cpp
        Admin.h
        Report.cpp
        Report.h
        Banned.h
        Instructions.h)
