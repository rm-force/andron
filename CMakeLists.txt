cmake_minimum_required(VERSION 3.10)
project(Andron C)

set(CMAKE_C_STANDARD 11)

include_directories(header)
link_directories(header)

add_executable(Andron main.c executable/dictTools.c)