cmake_minimum_required(VERSION 3.10)
project(Andron C)

set(CMAKE_C_STANDARD 11)

include_directories(Include)

add_executable(Andron main.c Types/dictionary.c Types/dynamic_array.c Types/object.c Types/base_types.c Include/base_types.h Include/object.h Include/dynamic_array.h Include/dictionary.h)