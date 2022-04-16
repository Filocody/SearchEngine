add_test( HelloTest.BasicAssertions C:/Users/stigi/CLionProjects/search_engine/cmake-build-debug/test/hello_test.exe [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties( HelloTest.BasicAssertions PROPERTIES WORKING_DIRECTORY C:/Users/stigi/CLionProjects/search_engine/cmake-build-debug/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( hello_test_TESTS HelloTest.BasicAssertions)
