cmake_minimum_required(VERSION 3.12)
project(BiTree)
include_directories(src/include)

aux_source_directory(src/main dir_srcs)

set(CMAKE_CXX_STANDARD 14)

set(BiTree ${dir_srcs} src/include/main.h)

add_executable(BiTree ${BiTree})