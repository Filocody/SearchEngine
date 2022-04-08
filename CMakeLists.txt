cmake_minimum_required(VERSION 3.19)
project(search_engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(search_engine main.cpp converterJSON.cpp InvertedIndex.cpp InvertedIndex.h)