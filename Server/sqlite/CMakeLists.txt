# CMake Version

cmake_minimum_required(VERSION 2.8)

project(sqliteTest)

set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/include)
find_library(SQLITELIB sqlite3 /usr/lib)

set(DIR_LIB_SRCS sqlite.cpp)

add_library(rsqlite ${DIR_LIB_SRCS})

add_executable(sqliteTest testfile.cpp)

target_link_libraries(sqliteTest rsqlite ${SQLITELIB})

