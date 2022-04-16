add_executable(hello_test test_test.cpp)
add_executable(index_test TestInvertedIndex.cpp ../InvertedIndex.h ../InvertedIndex.cpp)
add_executable(test_ test.cpp)

target_link_libraries(hello_test PRIVATE
        gtest gtest_main)
target_link_libraries(index_test PRIVATE
        gtest gtest_main)
target_link_libraries(test_ PRIVATE
        gtest gtest_main)



include(GoogleTest)
gtest_discover_tests(hello_test index_test test_)