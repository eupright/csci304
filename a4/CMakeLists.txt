cmake_minimum_required(VERSION 3.21)
project(calc C)

set(CMAKE_C_STANDARD 99)

add_executable(calc calc.c bin_str.h)
