cmake_minimum_required(VERSION 3.10)

project(mos6502 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DCMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(mos6502 main.cpp)
