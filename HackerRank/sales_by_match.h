/**
 * @file sales_by_match.cpp
 * @author Guangzhuan Mo (gwongzaanmok@gmail.com)
 * @brief
 *  - large piles of sock being paired by color
 *  - given an array of integers representing color of each sock
 *  - determine how many pairs of socks with matching color there are
 *
 *  input format:
 *      first line: number of sock
 *      second line: n space-seperated integers
 *
 *  constraints:
 *      1 <=  n <= 100
 *      1 <= a[i] <= 100, where 0 <= i <= n
 *
 *  sample input:
 *
 *      n = 7;
 *
 *      ar = [1, 3, 4, 3, 1, 4, 2]
 *  sample output:
 *
 *      3 pairs, (1,1), (3, 3), (4, 4)
 *
 *
 *  Analysis
 *      - a pair consist of two socks of same color, that is same integer in this problem,
 *      - if (x), then there's zero pair
 *      - if (x, x), then there's one pair
 *      - if (x, x, x) then there's one pair,
 *      - if (x, x, x, x) there's TWO pair,
 *      - if (x, x, x, x, x) there's TWO pair
 *      -
 *      - essentially, it is counting the number of elements that are of the same color, or say same value, for each color/ value,
 *      -
 *      - that is group different elements and count elements in each group.
 *      -
 *      - the core operation would be grouping and counting
 *      -
 *      - there's duplication in the array,
 *      - first thing to consider is how to group elements in the array. if it can counts at the same time while grouping, would be best
 *
 *          sorting to group?
 *
 *              std::sort();
 *
 *          std::multiset to group?
 *
 *              - it can store multiple elements with same value
 *              - it is sorted in increasing order by default
 *              - it provide fast insertion, deletion and search operation
 *
 *          std::map ? no, there duplication in the array,
 *              - associative container, key-value pair,
 *              - no duplication allowed, no good for grouping
 *
 *          std:;unordered_map ? similar to std::map, but allow duplication.
 *              - it can group and count at the same time
 *
 *
 *
 * @version 0.1.0
 * @date 2025-03-25
 *
 * @copyright Copyright (c) 2025
 *
 */

// TODO compare performance and memory usage between solutions
// TODO write google test

#include <vector>
#include <algorithm>

/**
 * @brief
 *
 * @param n  : number of socks in the pile
 * @param ar : colors of each sock
 * @return int : the number of pairs
 */
int sock_merchant(int n, std::vector<int> ar);

/**
 * @brief
 *
 *      it is essentially a
 *
 *      - sort the array in place
 *      - set the first element as the initial anchor
 *      - iterate rest of the sorted array, i in [1, n), and match in pair
 *          if anchor == ar[i], there is a match
 *
 *              increase number of pairs

 *              pop the anchor and the matching element
 *
 *              set a new anchor
 *              set the new current element pointing to the next of the new anchor
 *          otherwise, it is not a match, because the array is sorted,
 *                  that implying there will be no match with the anchor in the rest of the array.
 *
 *              set the new  anchor pointing to the next element,
 *              set the new current element pointing to the next of the new anchor
 *
 *
 *
 * @param n
 * @param ar
 * @return int
 */
int solution_1(int n, std::vector<int> ar)
{
    std::sort(ar.begin(), ar.end(), std::greater<int>());

    int pairs{0};
    int anchor{ar[0]};

    for (int i = 1; i < n; ++i)
    {
        if (anchor == ar[i])
        {
            ++pairs; // using prefix- increments has slightly better performance then post-fix increment
            anchor = ar[++i];
            continue;
        }
        anchor = ar[i];
    }

    return pairs;
}

#include <unordered_map>
/**
 * @brief
 *      using std::unordered_map
 *
 *      iterate the array
 *
 *          for each sock color(group tag/key), increment the corresponding 'key' in the map
 *
 *      iterate the map,
 *          count each group
 *          pairs += (count/2);
 *
 * @param n
 * @param ar
 * @return int
 */
int solution_2(int n, std::vector<int> ar)
{
    int pairs{0};

    std::unordered_map<int, int> groups;

    for (auto e : ar)
    {
        ++groups[e];
    }

    for (const auto &[k, v] : groups)
    {
        pairs += (v / 2);
    }

    return pairs;
}