cmake_minimum_required(VERSION 3.10)

project(ShellNU VERSION 0.0.3)

set(SOURCES src/main.cpp src/header/func.hpp src/header/file.h)

if(WIN32)
    set(SOURCES ${SOURCES} res.rc)
endif()

add_executable(ShellNU ${SOURCES})
