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
    std::map<std::size_t, std::pair<int, std::vector<int>>> test_cases;

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
        int elem, pairs;
        std::vector<int> tmp;
        while (std::getline(fh, line))
        {
            std::stringstream ss(line);
            ss >> pairs;
            while (ss >> elem)
            {
                tmp.push_back(elem);
            }
            test_cases.insert({tmp.size(), {pairs, tmp}});
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
    for (const auto &[size, pairs_vec] : test_cases)
    {
        pairs = solution_1(size, pairs_vec.second);
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