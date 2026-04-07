/**
* @file         : random.h
* @author       : ml
* @create       : 2026-04-07 10:25
* @brief        : TODO
* Created by ml on 2026/4/7.
*/


#ifndef SORT_ALGORITHM_RANDOM_H
#define SORT_ALGORITHM_RANDOM_H

#include <stdint.h>

/**
 * get random value
 * @return random value
 */
long GetRandomValue();

/**
 * get uniform random value
 * @param range_upper range end value
 * @return random value and uniform
 */
uint32_t Arc4RandomUniform(uint32_t range_upper);

#endif //SORT_ALGORITHM_RANDOM_H
