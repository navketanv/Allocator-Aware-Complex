cmake_minimum_required(VERSION 4.3.3)

project(Allocator-Aware-Complex LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Allocator-Aware-Complex src/Allocator-Aware-Complex.cpp
    include/AllocationBlock.h include/AllocationBlock.cpp
    include/ObjectStorage.h include/ObjectStorage.cpp
    include/NewHandlerGuard.h include/NewHandlerGuard.cpp)

include(GNUInstallDirs)
install(TARGETS Allocator-Aware-Complex
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_sources(Allocator-Aware-Complex PRIVATE)
