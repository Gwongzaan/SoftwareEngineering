#include <gtest/gtest.h>
#include "counting_valley.h"
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class test_counting_valley : public ::testing ::Test
{
protected:
    std::map<int, std::pair<int, std::string>> test_cases;
    void setup_test_cases(std::string file = "test_cases_counting_valley.txt")
    {
        std::ifstream fh{file};
        if (!fh.is_open())
        {
            std::cerr << "Can not open file : " << file << std::endl;
        }
        std::size_t res;
        std::string line;
        std::string path;
        int cnt = 0;
        while (std::getline(fh, line))
        {

            std::stringstream ss(line);
            ss >> res >> path;
            test_cases.insert({++cnt, {res, path}});
        }
    }

    void SetUp() override
    {
        setup_test_cases();
    }
};

TEST_F(test_counting_valley, solution_1)
{
    int res;
    for (const auto &[case_no, res_path] : test_cases)
    {
        std::cout << "test case " << case_no << std::endl
                  << res_path.second << std::endl;
        res = solution_1(res_path.second.size(), res_path.second);
        EXPECT_EQ(res, res_path.first);
    }
}