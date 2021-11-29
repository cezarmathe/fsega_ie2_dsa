# CMakeLists.txt

cmake_minimum_required(VERSION 3.0)

project(fsega_ie2_dsa
        VERSION 0.1.0
        DESCRIPTION "FSEGA IE2 - Algorithms and data structures."
        LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out")

add_executable(
    "lab1_1"
    "src/lab1/lab1_1_main.c" "src/lab1/lab1_1.c"
    "src/lab1/lab1_1.h")
add_executable(
    "lab1_2"
    "src/lab1/lab1_2_main.c" "src/lab1/lab1_2.c"
    "src/lab1/lab1_2.h")
add_executable(
    "lab1_3"
    "src/lab1/lab1_3_main.c" "src/lab1/lab1_3.c"
    "src/lab1/lab1_3.h")

add_executable("lab2_1"
    "src/lab2/lab2_1_main.c"
    "src/lab2/lab2_1.c"
    "src/lab2/lab2_1.h")
