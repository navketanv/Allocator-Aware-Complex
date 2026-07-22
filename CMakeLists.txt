cmake_minimum_required(VERSION 4.3.3)

project(Allocator-Aware-Complex LANGUAGES CXX)

# ==========================================================
# Project Options
# ==========================================================

option(
    ENABLE_ASAN
    "Enable Address Sanitizer"
    ON
)

option(
    ENABLE_UBSAN
    "Enable Undefined Behaviour Sanitizer"
    OFF
)

option(
    ENABLE_WARNINGS_AS_ERRORS
    "Treat Compiler Warnings As Errors"
    OFF
)

# ==========================================================
# Build Configuration
# ==========================================================


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Allocator-Aware-Complex src/Allocator-Aware-Complex.cpp
)

target_include_directories(Allocator-Aware-Complex
    PRIVATE
        include
)

target_link_libraries(Allocator-Aware-Complex
    PRIVATE
)

include(GNUInstallDirs)
install(TARGETS Allocator-Aware-Complex
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_sources(Allocator-Aware-Complex PRIVATE)
