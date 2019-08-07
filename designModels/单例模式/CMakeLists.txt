cmake_minimum_required(VERSION 3.14)
project(CodeCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(singleton_11 C++11.cpp)
add_executable(singleton_lazy lazy.cpp)
add_executable(singleton_labor labor.cpp)