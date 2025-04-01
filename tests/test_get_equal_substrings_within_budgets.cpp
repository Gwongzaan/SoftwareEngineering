#include <gtest/gtest.h>
#include "get_equal_substrings_within_budgets.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class test_get_equal_substrings_within_budgets : public ::testing::Test
{
protected:
    /// @brief <case-no, <expected-result, string s, string t, max-cost
    std::map<int, std::tuple<int, std::string, std::string, int>> test_cases;

    /**
     * @brief Set the up test cases object
     *
     *      format of test cases
     *
     *      <expected result> <string s> <string t> <max-cost>
     * @param file
     */
    void setup_test_cases(std::string file = "test_cases_get_equal_substrings_within_budgets.txt")
    {
        std::ifstream fh{file};
        if (!fh.is_open())
        {
            std::cerr << "cannot open file : " << file << std::endl;
            exit(EXIT_FAILURE);
        }
        std::string line;
        int case_no = 0, expected_result, max_cost;
        std::string s, t;
        while (std::getline(fh, line))
        {
            std::stringstream ss{line};
            ss >> expected_result >> s >> t >> max_cost;
            test_cases.insert({++case_no, {expected_result, s, t, max_cost}});
        }
    }

    void SetUp() override
    {
        setup_test_cases();
    }
};

TEST_F(test_get_equal_substrings_within_budgets, solution_1)
{
    int result;
    for (const auto &[case_no, case_tuple] : test_cases)
    {
        std::cout << case_no << ": "
                  << std::get<0>(case_tuple) << " "
                  << std::get<1>(case_tuple) << " "
                  << std::get<2>(case_tuple) << " "
                  << std::get<3>(case_tuple)
                  << std::endl;

        result = solution_1(std::get<1>(case_tuple), std::get<2>(case_tuple), std::get<3>(case_tuple));
        EXPECT_EQ(result, std::get<3>(case_tuple));
    }
}