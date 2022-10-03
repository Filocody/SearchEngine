cmake_minimum_required(VERSION 3.19)
project(search_engine)

set(CMAKE_CXX_STANDARD 14)


include(FetchContent)

FetchContent_Declare(
        googletest
        URL
        https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_disable_pthreads on)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)




enable_testing()

add_subdirectory(nlohmann_json)

add_executable(search_engine main.cpp converterJSON.cpp converterJSON.h InvertedIndex.cpp InvertedIndex.h SearchServer.cpp SearchServer.h)
add_executable(converter_test TestConverterJSON.cpp converterJSON.h converterJSON.cpp)
add_executable(search_test TestSearchServer.cpp SearchServer.cpp SearchServer.h InvertedIndex.cpp InvertedIndex.h)

include_directories(${gtest_SOURCE_DIR}/include)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(converter_test PRIVATE nlohmann_json::nlohmann_json gtest gtest_main )
target_link_libraries(search_test PRIVATE gtest gtest_main)

add_subdirectory(test)

include(GoogleTest)
gtest_discover_tests(converter_test search_test)

