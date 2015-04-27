set(test_sources test_main.cpp)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/lib/googletest/include)

add_executable(c4_test_suite ${test_sources})

set(c4_test_suite_libs gtest)

target_link_libraries(c4_test_suite ${c4_test_suite_libs})

add_test(all_c4_tests c4_test_suite)
