cmake_minimum_required(VERSION 3.0)

project(JSON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(my_json_cmake main.cpp src/json.cpp src/parser.cpp)
