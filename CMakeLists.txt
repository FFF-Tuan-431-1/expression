cmake_minimum_required(VERSION 2.8.4)
project(expression)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test.cpp)
add_executable(expression ${SOURCE_FILES} src/Util.cpp src/Util.h src/Check.cpp src/Check.h src/Suffix.cpp src/Suffix.h src/Calculate.cpp src/Calculate.h src/Cell.cpp src/Cell.h)