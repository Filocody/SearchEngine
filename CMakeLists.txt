cmake_minimum_required(VERSION 3.19)
project(search_engine)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(nlohmann_json)

add_executable(search_engine main.cpp converterJSON.cpp InvertedIndex.cpp InvertedIndex.h)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)