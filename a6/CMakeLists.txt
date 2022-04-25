cmake_minimum_required(VERSION 3.21)
project(a6 C)

set(CMAKE_C_STANDARD 99)

add_executable(a6 main.c contact.h contact.c contact_list.h contact_list.c utils.h utils.c)
