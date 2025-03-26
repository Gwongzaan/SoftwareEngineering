#include <gtest/gtest.h>
#include "sales_by_match.h"
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class test_sales_by_match : public ::testing::Test
{
protected:
    /// @brief <case_no, <pairs, array>>
    std::map<int, std::pair<int, std::vector<int>>> test_cases;

    /**
     * @brief Set the up test cases object
     *
     *  format of test cases
     *
     *  <pairs> <vector containing integer>
     *
     * @param file
     */
    void setup_test_cases(std::string file = "test_cases_sales_by_match.txt")
    {

        std::ifstream fh{file};

        if (!fh.is_open())
        {
            std::cerr << "Cannot open " << file << std::endl;
            exit(EXIT_FAILURE);
        }

        std::string line;
        int elem = 0, pairs = 0, no = 0;
        std::vector<int> tmp;
        while (std::getline(fh, line))
        {
            std::stringstream ss(line);
            ss >> pairs;
            while (ss >> elem)
            {
                tmp.push_back(elem);
            }
            test_cases.insert({++no, {pairs, tmp}});
            tmp.clear();
        }
    }

    void SetUp() override
    {
        setup_test_cases();
    }
};

TEST_F(test_sales_by_match, solution_1)
{
    int pairs;
    for (const auto &[case_no, pairs_vec] : test_cases)
    {
        std::cout << "test case " << case_no << " : " << std::endl;
        std::copy(pairs_vec.second.begin(), pairs_vec.second.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        pairs = solution_1(pairs_vec.second.size(), pairs_vec.second);

        EXPECT_EQ(pairs, pairs_vec.first);
    }
}

TEST_F(test_sales_by_match, solution_2)
{
    int pairs;
    for (const auto &[size, pairs_vec] : test_cases)
    {
        pairs = solution_2(size, pairs_vec.second);
        EXPECT_EQ(pairs, pairs_vec.first);
    }
}