cmake_minimum_required(VERSION 3.8)
project(sort_algorithm C)

set(CMAKE_C_STANDARD 11)

add_executable(sort_algorithm main.c
        sort-cocktail.c
        sort-cocktail.h
        random.c
        random.h
        sort-bubble.c
        sort-bubble.h
        enum-string.c
        enum-string.h)
