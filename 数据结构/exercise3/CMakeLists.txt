cmake_minimum_required(VERSION 3.12)
project(exercise3)

set(CMAKE_CXX_STANDARD 14)

#源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src/main dir_srcs)

set(WORK ${dir_srcs})
add_executable(work ${WORK})
