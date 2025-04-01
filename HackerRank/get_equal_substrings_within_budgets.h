/**
 * @file get_equal_substrings_within_budgets.h
 * @author Guangzhuan Mo (gwongzaanmok@gmail.com)
 * @brief
 *      given two strings of same length, s and t, and an integer max_cost
 *
 *      change s_i to t_i, cost = abs(s[i] - t[i]) (the absolute difference between the ASCII values of the characters)
 *
 *      return the max length of substring of s that can be changed to be the same as the corresponding substring of t ,
 *      with the cost less or equal to max-cost.
 *
 *      if there is no substring from s that can be changed to its corresponding  substring from t, return 0
 *
 *      example:
 *          s = abcd, t = bcdf, max_cost = 3
 *          a -> b : 1
 *          b -> c : 1
 *          c -> d : 1
 *          return 3
 *
 *          s = abcd, t = cdef, max_cost = 3
 *          a -> c : 2 < 3
 *          b -> d : 2  ==> 2+2 > 3
 *          return 1
 *
 *      construaints
 *          1 <= s.length <= 10 ^ 5
 *          t.length = l.length
 *          0 <= max_cost <= 10 ^ 5
 *          s, t contains only lowcase letters
 *
 *      ANALYSIS
 *
 *          Modeling the problem:
 *
 *              creating an array of max_cost ?
 *                  TRANSFERing the problem to be finding the longest subarray in this cost array where the sum of elements is <= max_cost
 *
 *              sum of the cost <= max_cost ---> constraint on the max length of the substring
 *
 *
 *          any similar solution pattern ?
 *
 *          using sliding window techniques? any practical senarios in HFT?
 *              sliding window techniques,
 *                  - used to effectively solve problems involving array, strings, or other sequential data structures.
 *                  - involves maintaining a dynamically adjusting "window" ( a sub-string/array/structure) defined by two pointer(left and right)
 *                      the window slide over the data,
 *                  - it optimize the computation by resuing previous results rather than recalculating them from scratch
 *              key concepts:
 *                  - window types
 *                      - fixed-size, the window maintain a constant size while slide. (e.g. finding the maximum sum of subarrays of size K)
 *                      - variable-size, the window expands or contracts based on conditions. (e.g. finding the longest substring  without repeating characters)
 *              how it works:
 *                  - initialize pointer: left and right to define the window boundaries
 *                  - expand the window: move pointer(right pointer, why right not left?) to include new element until a condition  is met or violated.
 *                  - contract the window: ajdust pointer(left pointer, why left not right?) to optimize the solution (e.g. minimize window size or remove invalid elements)
 *                  - Track status: use data structures (e.g. hashmap, sets) to monitor the windows content( e.g. character count or uniqueness)
 *
 *              Time complexity:
 *                  O(N) , each element is processed at most twice
 *
 *              advantages:
 *                  avoid redundant computation, reducing from O(n^2) to O(n)
 *                  flexible for problems requiring  continguous subarrays/substrings with specific properties
 *
 *
 *
 *         the cost are all positive, the sliding window technique works here (how about containing negative? not usable any more?)
 *
 *         adding a new element to the window can only increase the sum,
 *          and when the sum exceeds the max_cost, we can move the left end of the window to the right until the sum is within the limit again.
 *
 *          steps:
 *          compute costs array, std::abs(s[i] - t[i])
 *          use a sliding window on the costs array, and find the maximum length of a subarray with sum <= max_cost
 *
 *          paper run:
 *              s = abcd, t = bcdf, max_cost = 3
 *              costs = [1, 1, 1, 2]
 *
 *
 *
 *
 *
 *
 * @version 0.1.0
 * @date 2025-03-31
 *
 * @copyright Copyright (c) 2025
 *
 */

// TODO think about some variation in HFT scenario?

#include <string>
#include <iostream>
#include <vector>
/**
 * @brief Get the equal substring within budget object
 *
 * @param s
 * @param t
 * @param max_cost
 * @return int
 */
int get_equal_substring_within_budget(std::string s, std::string t, int max_cost);

int solution_1(std::string s, std::string t, int max_cost)
{

    // using size_type = std::size_t;
    using size_type = uint8_t;

    size_type sz = s.size();
    std::vector<int> costs(sz);
    // TODO use int or size_t or uint8? in the scenario of HFT?, why and why not
    // initialize the sliding window
    for (size_type i = 0; i < sz; ++i)
    {
        costs[i] = std::abs(s[i] - t[i]);
    }

    size_type current_sum{0}, max_length{0}, left_ptr{0}, right_ptr{0}, current_length{0};
    for (right_ptr = 0; right_ptr < sz; ++right_ptr)
    {
        current_sum += costs[right_ptr];
        while (current_sum > max_cost)
        {
            current_sum -= costs[left_ptr];
            ++left_ptr;
        }
        current_length = right_ptr - left_ptr + 1;
        if (current_length > max_length)
        {
            max_length = current_length;
        }
    }

    return max_length;
}
// TODO use raw array for better performance, significant difference?
// Necessary optimization ?
int solution2(std::string s, std::string t, int max_cost)
{
    using size_type = std::size_t;
    size_type sz = s.size();
    int costs[sz];
    for (size_type i = 0; i < sz; ++i)
    {
        costs[i] = std::abs(s[i] - t[i]);
    }
    size_type max_length{0}, current_sum{0}, current_length{0}, right_ptr{0}, left_ptr{0};
    for (right_ptr = 0; right_ptr < sz; ++right_ptr)
    {
        current_sum += costs[right_ptr];
        while (current_sum > max_cost)
        {
            ++left_ptr;
        }
        max_length = std::max(max_length, right_ptr - left_ptr + 1);
    }
    return max_length;
}

/**
 * @brief
 *
 * @param s
 * @param t
 * @param max_cost
 * @return int
 */
int solution3(std::string s, std::string t, int max_cost)
{
}