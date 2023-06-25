cmake_minimum_required(VERSION 3.17.5)
project(untitled3)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled3 main.cpp)

target_link_libraries(untitled3 pthread)
