add_library(Cpu Cpu.cpp)

target_include_directories(Cpu PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/Memory"
)

target_link_libraries(Cpu PUBLIC Memory)
