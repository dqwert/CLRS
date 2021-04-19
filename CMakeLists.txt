cmake_minimum_required(VERSION 3.14)
project(clrs)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_sorting test_sorting.cpp merge_sort.cpp insertion_sort.cpp heapsort.cpp quicksort.cpp)
add_executable(test_dynamic_programming test_dynamic_programming.cpp rod_cutting.cpp)
add_executable(find_maximum_subarray find_maximum_subarray.cpp)
