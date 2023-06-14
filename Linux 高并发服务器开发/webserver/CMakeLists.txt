cmake_minimum_required(VERSION 3.0)

project(WEBSERVER)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pthread")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(my_cmake main.cpp src/http_conn.cpp)