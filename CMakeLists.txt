cmake_minimum_required(VERSION 3.10)
project(Andron C)

set(CMAKE_C_STANDARD 11)

include_directories(Include)

add_executable(Andron main.c Types/dictionary.c Types/dynamic_array.c Types/object.c Types/base_types.c Include/types/base_types.h Include/types/object.h Include/types/dynamic_array.h Include/types/dictionary.h Tools/hashing.c Include/tools/hashing.h Tools/bit_operations.c Include/tools/bit_operations.h Types/linked_list.c Include/types/linked_list.h Include/constants.h)