# Integrate GoogleTest.
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# Download and make GoogleTest Avaliable
FetchContent_MakeAvailable(googletest)

set(SRC_FILES 
../HackerRank/sales_by_match.h
../HackerRank/counting_valley.h
)

configure_file(
    test_cases_sales_by_match.txt
    test_cases_sales_by_match.txt
    COPYONLY
)

configure_file(
    test_cases_counting_valley.txt 
    test_cases_counting_valley.txt 
    COPYONLY
)

configure_file(
    test_cases_get_equal_substrings_within_budgets.txt
    test_cases_get_equal_substrings_within_budgets.txt
    COPYONLY
)
# add test executable
add_executable(
    test_hackerrank
    main.cpp
    test_sales_by_match.cpp
    test_counting_valley.cpp
    test_get_equal_substrings_within_budgets.cpp

    ${SRC_FILES}

)

# include Google Test headers explicityly for IntelliSense
target_include_directories( 
    test_hackerrank
    PRIVATE 
        ${googletest_SOURCE_DIR}/googletest/include
        ${SOURCE_DIR}/include
        )


target_link_libraries(
    test_hackerrank
    PRIVATE 
        gtest 
        GTest::gtest_main
)


# Enable google test discovery
include(GoogleTest)
gtest_discover_tests(test_hackerrank)