cmake_minimum_required(VERSION 2.8)
project(wesh C CXX)
set(WESH_VERSION 0.1)
set(CMAKE_CXX_COMPILER "g++")

# directories variables
set(SRC_DIR src/)
set(OUT_DIR out/)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

# sources dirs
add_subdirectory(${SRC_DIR})
