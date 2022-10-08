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

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(search_engine main.cpp converterJSON.cpp converterJSON.h InvertedIndex.cpp InvertedIndex.h SearchServer.cpp SearchServer.h)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)

include_directories(${gtest_SOURCE_DIR}/include)

add_subdirectory(test)

include(GoogleTest)


