# cmake_minimum_required(VERSION <specify CMake version here>)
project(in4200 C)

set(CMAKE_C_STANDARD 11)

#add_executable(
#        in4200
#        s1/e1/verify_limit.c
#        s1/e1/max_min_number_in_array.c
#        s1/e1/matrix_loop.c s1/e1/3d_array.c
#        s1/e2/temperatures.c s1/e3/quicksort.c
#        s2/e1/txt_bin_performance.c
#        s2/e2/copy_array.c
#        s2/e3/3d_numerical_calculation.c
#        s2/e2/copy_array_2.c
#        s4/e2/memory_badwidth_strided.c)
add_executable(in4200_s1e1 s1/e1/verify_limit.c)
add_executable(in4200_s4e1 s4/e1/memory_bandwidth.c)
add_executable(in4200_hpc_1_1_integrate HPC_BOOK/chap1/p1/integrate.c)