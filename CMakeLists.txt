cmake_minimum_required(VERSION 3.15)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c fileinput.h fileinput.c quicksort.c quicksort.h anagrams.c anagrams.h)