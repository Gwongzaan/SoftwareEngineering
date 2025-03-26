/**
 * @file counting_valley.h
 * @author Guangzhuan Mo (gwongzaanmok@gmail.com)
 * @brief
 *
 * Question
 *
 *  An avid hiker keeps meticulous records of their hikes.
 * During the last hike that took exactly  steps,
 * for every step it was noted if it was an uphill, U, or a downhill, D step.
 * Hikes always start and end at sea level,
 * and each step up or down represents a  unit change in altitude.
 *
 * We define the following terms:
 *
 * A mountain is a sequence of consecutive steps above sea level,
 * starting with a step up from sea level and ending with a step down to sea level.
 *
 * A valley is a sequence of consecutive steps below sea level,
 * starting with a step down from sea level and ending with a step up to sea level.
 *
 * Given the sequence of up and down steps during a hike,
 *
 * find and print the number of valleys walked through.
 *
 *  Example
 *
 *  steps = 8, path = [DDUUUUDD]
 *
 *  input format
 *
 *  sample input
 *
 *  sample output
 *
 *
 *  Explanation
 *
 *  Analysis
 *      - only up or down, each time go up a unit, +1, go down a unit -1
 *      - sea level is the base, 0
 *      - what is the characteristic of a vellay?  and how to represent them?
 *              start with a step down from sea level,  does it matter?
 *                  because start at the sea level, and end at the sea level,
 *                  start should not matter, because end is start, start is end,
 *              end with a step up to the sea level
 *                  the current level should be -1,
 *          there should be a flag to mark the current level,
 *
 *      - identifying pattern. is there a similar question meet before?
 *
 *      - steps
 *          iterate the path
 *          track up and down by +1, -1
 *              if prevous_level == -1, current_level == 0, going out of a valley
 *
 *
 * @version 0.1.0
 * @date 2025-03-25
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <string>
/**
 * @brief
 *
 * @param steps
 * @param path
 * @return  int  the number of valley traversed
 */
int counting_valleys(std::size_t steps, std::string path);

int solution_1(std::size_t steps, std::string path)
{
    std::size_t current_level{0};
    std::size_t previous_level{0};
    std::size_t count{0};
    for (auto c : path)
    {
        if ('U' == c)
        {
            previous_level = current_level;
            ++current_level;
            if (previous_level == -1 && current_level == 0)
            {
                ++count;
            }
        }
        else
        {
            --current_level;
        }
    }
    return count;
}