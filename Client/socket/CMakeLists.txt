# CMake Version

cmake_minimum_required(VERSION 2.8)

project(socketClient)

set(CMAKE_CXX_STANDARD 11)


set(DIR_LIB_SRCS socket_client.cpp)

add_library(rsocket ${DIR_LIB_SRCS})

add_executable(socketClient testfile.cpp)

target_link_libraries(socketClient rsocket)