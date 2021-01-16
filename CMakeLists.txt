# cmake_minimum_required(VERSION <specify CMake version here>)
project(in4200 C)

set(CMAKE_C_STANDARD 99)

add_executable(in4200 main.c e1/verify_limit.c e1/max_min_number_in_array.c)