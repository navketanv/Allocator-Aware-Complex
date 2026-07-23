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
    ON
)

# ==========================================================
# Build Configuration
# ==========================================================

include(cmake/CompilerWarnings.cmake)
include(cmake/CompilerOptions.cmake)
include(cmake/Sanitizers.cmake)

add_executable(Allocator-Aware-Complex
    src/Allocator-Aware-Complex.cpp

    include/Allocator/Allocator.h
)

target_include_directories(Allocator-Aware-Complex
    PRIVATE
        include
)

target_link_libraries(Allocator-Aware-Complex
    PRIVATE
)

# ==========================================================
# enable public interfaces
# ==========================================================

enable_warnings(Allocator-Aware-Complex)
enable_project_options(Allocator-Aware-Complex)
enable_sanitizers(Allocator-Aware-Complex)

include(GNUInstallDirs)
install(TARGETS Allocator-Aware-Complex
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_sources(Allocator-Aware-Complex PRIVATE
src/Allocator-Aware-Complex.cpp
)
