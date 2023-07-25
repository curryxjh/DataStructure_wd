cmake_minimum_required(VERSION 3.26)
project(DS_WD_All_Practise)

set(CMAKE_CXX_STANDARD 17)

add_executable(DS_WD_All_Practise main.cpp
        2_2_3_coding/problem01.cpp
        2_2_3_coding/problem02.cpp
        2_2_3_coding/problem03.cpp
        2_2_3_coding/problem04.cpp
        2_2_3_coding/problem05.cpp
        2_2_3_coding/problem06.cpp)

add_executable(problem01 2_2_3_coding/problem01.cpp)
add_executable(problem02 2_2_3_coding/problem02.cpp)
add_executable(main main.cpp)
add_executable(problem03 2_2_3_coding/problem03.cpp)
add_executable(problem04 2_2_3_coding/problem04.cpp)
add_executable(problem05 2_2_3_coding/problem05.cpp)
add_executable(problem06 2_2_3_coding/problem06.cpp)