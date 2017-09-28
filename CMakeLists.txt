cmake_minimum_required(VERSION 3.9.3)
project(Wordz-Solver)

add_definitions("-std=c++11")

#Bring the headers into the project
include_directories(include)

#List of executables
file(GLOB SOURCES "src/*.cpp")

add_executable(solver ${SOURCES})
