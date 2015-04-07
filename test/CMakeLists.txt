set(test_sources test_main.cpp)

enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(c4_test_suite ${test_sources})

set(c4_test_suite_libs ${GTEST_LIBRARY} pthread)

target_link_libraries(c4_test_suite ${c4_test_suite_libs})

add_test(all_c4_tests c4_test_suite)
