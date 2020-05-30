cmake_minimum_required(VERSION 3.16)
project(kvxlogger)

set(CMAKE_CXX_STANDARD 17)

add_library(logger kvxlogger/logger.cpp kvxlogger/logger.hpp)

add_executable(kvxlogger main.cpp)

target_link_libraries(kvxlogger logger)
include_directories(.)