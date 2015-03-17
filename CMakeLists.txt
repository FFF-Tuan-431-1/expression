cmake_minimum_required(VERSION 2.8.4)
project(collegetwo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test.cpp)
add_executable(collegetwo ${SOURCE_FILES} src/Util.cpp src/Util.h src/Check.cpp src/Check.h src/Suffix.cpp src/Suffix.h src/Calculate.cpp src/Calculate.h src/Cell.cpp src/Cell.h)