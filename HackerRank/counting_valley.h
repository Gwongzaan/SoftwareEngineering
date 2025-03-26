/**
 * @file counting_valley.h
 * @author Guangzhuan Mo (gwongzaanmok@gmail.com)
 * @brief
 *
 * DESCRIPTION:  description of the problem
 *
 *      An avid hiker keeps meticulous records of their hikes.
 *      During the last hike that took exactly  steps,
 *      for every step it was noted if it was an uphill, U, or a downhill, D step.
 *      Hikes always start and end at sea level,
 *      and each step up or down represents a  unit change in altitude.
 *
 *      We define the following terms:
 *
 *      A mountain is a sequence of consecutive steps above sea level,
 *      starting with a step up from sea level and ending with a step down to sea level.
 *
 *      A valley is a sequence of consecutive steps below sea level,
 *      starting with a step down from sea level and ending with a step up to sea level.
 *
 *      Given the sequence of up and down steps during a hike,
 *
 *      find and print the number of valleys walked through.
 *
 *
 *  EXPLANATION: demonstrate the problem with examples/scenario
 *
 *  Example and Test Cases
 *
 *  steps = 8, path = [DDUUUUDD], number of valley 1
 *
 *  input format
 *
 *  sample input
 *
 *  sample output
 *
 *  ANALYSIS: understanding the question and model the solution
 *
 *      QUESTION:
 *
 *      - the problem is to count numbers of valley walked through
 *
 *      KNOWN: What is given?
 *
 *      - the hiker takes steps, up(U) or down (D),
 *
 *      - the hike start and end at sea level.
 *
 *      - a valley is a sequence of steps that start with a step down from the sea level,
 *          and then comes back up to the sea level.
 *
 *      - what is constraint?
 *
 *      KEY:
 *          - track the altitude and detect when the hiker enter and exit a valley.
 *
 *      TOUGHT: Modelling
 *
 *      - sea level is the base, 0
 *      - up +1, down -1,
 *      - start and end at sea level (0), therefore,
 *
 *              whenever the current level transit from -1 to 0,
 *              it indicates exiting a valley.
 *
 *
 *      PATTERN: identify if there is a similar question meet before?
 *
 *      SOLUTION: KEY TO the model
 *          - iterate the path one by one
 *          - in each iteration,if  previous-level == -1 and current_level == 0,
 *              that is the current-level is transiting from -1 to  0,
 *              which indicates hiker is exiting a valley.
 *
 *      DATASTRUCTURE: need extra data structure to model? what data structure can help? why and why not?
 *
 *      OPTIMIZATION:
 *
 *      TIMECOMPLEXITY:
 *
 *      SPACECOMPLEXITY:
 *
 *      EXTENTIONS: what kind of real problem similar to this?
 *
 *      SUMMARY: what pattern can be extra?
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