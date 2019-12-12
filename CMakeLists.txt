cmake_minimum_required(VERSION 3.14)
project(example C)

set(CMAKE_C_STANDARD 99)

add_executable(example main.c libinjection_sqli.c)