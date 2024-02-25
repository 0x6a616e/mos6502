cmake_minimum_required(VERSION 3.10)

project(mos6502 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(mos6502 main.cpp)

add_subdirectory(Memory)
target_link_libraries(mos6502 PUBLIC Memory)

add_subdirectory(Cpu)
target_link_libraries(mos6502 PUBLIC Cpu)

target_include_directories(mos6502 PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/Memory"
    "${PROJECT_SOURCE_DIR}/Cpu"
)
