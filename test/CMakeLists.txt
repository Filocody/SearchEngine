add_executable(hello_test test_test.cpp)
add_executable(index_test TestInvertedIndex.cpp ../InvertedIndex.h ../InvertedIndex.cpp)
add_executable(converter_test TestConverterJSON.cpp ../converterJSON.h ../converterJSON.cpp)
add_executable(search_test TestSearchServer.cpp ../SearchServer.h ../SearchServer.cpp ../InvertedIndex.h ../InvertedIndex.cpp)
add_executable(test_ test.cpp)

target_link_libraries(hello_test PRIVATE
        gtest gtest_main)
target_link_libraries(index_test PRIVATE
        gtest gtest_main)
target_link_libraries(test_ PRIVATE
        gtest gtest_main)
target_link_libraries(converter_test PRIVATE
        gtest gtest_main nlohmann_json::nlohmann_json)
target_link_libraries(search_test PRIVATE
        gtest gtest_main nlohmann_json::nlohmann_json)



include(GoogleTest)
gtest_discover_tests(hello_test index_test test_ converter_test search_test)