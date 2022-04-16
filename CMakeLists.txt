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

FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(nlohmann_json)

add_executable(search_engine main.cpp converterJSON.cpp converterJSON.h InvertedIndex.cpp InvertedIndex.h)
add_executable(converter_test TestConverterJSON.cpp converterJSON.h converterJSON.cpp)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(converter_test PRIVATE nlohmann_json::nlohmann_json gtest gtest_main)

add_subdirectory(test)

include(GoogleTest)
gtest_discover_tests(converter_test)

