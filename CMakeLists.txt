# cmake_minimum_required(VERSION <specify CMake version here>)
project(in4200 C)

set(CMAKE_C_STANDARD 99)

add_executable(in4200 main.c s1/e1/verify_limit.c s1/e1/max_min_number_in_array.c s1/e1/matrix_loop.c s1/e1/3d_array.c s1/e2/temperatures.c s1/e3/quicksort.c s2/e1/txt_bin_performance.c)