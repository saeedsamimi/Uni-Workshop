cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 23)

project(main)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "ON")

if(MSYS)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()

add_subdirectory(Workshop01)
add_subdirectory(Workshop02)
add_subdirectory(Workshop03)
add_subdirectory(Workshop04)
add_subdirectory(Workshop05)
add_subdirectory(SinglyLinkedListImplementation)
add_subdirectory(Competition01)
add_subdirectory(Practice01)