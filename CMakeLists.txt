cmake_minimum_required(VERSION 3.26)
project(final_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
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
