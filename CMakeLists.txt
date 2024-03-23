cmake_minimum_required(VERSION 3.15)
project(libevrte VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/libevrte)

if (BUILD_EXAMPLES)
    add_subdirectory(examples/component_example)
endif()