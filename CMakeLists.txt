cmake_minimum_required(VERSION 3.14)
project(pcg_test)

set(CMAKE_CXX_STANDARD 17)

find_package(GSL REQUIRED)

find_package(pcg REQUIRED)

add_executable(pcg_test main.cpp)