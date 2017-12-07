# CMake Version

cmake_minimum_required(VERSION 2.8)

project(socketTest)

set(CMAKE_CXX_STANDARD 11)


set(DIR_LIB_SRCS server_socket.cpp)

add_library(rsocket ${DIR_LIB_SRCS})

add_executable(socketTest testfile.cpp)

target_link_libraries(socketTest rsocket)