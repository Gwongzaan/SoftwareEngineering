#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    // ::testing::GTEST_FLAG(filter) = "test_sales_by_match*";
    // ::testing::GTEST_FLAG(filter) = "test_counting_valley*";
    ::testing::GTEST_FLAG(filter) = "test_get_equal_substrings_within_budgets*";
    return RUN_ALL_TESTS();
}