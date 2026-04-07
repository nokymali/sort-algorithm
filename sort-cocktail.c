/**
* @file         : sort-cocktail.c
* @author       : ml
* @create       : 2026-04-07 10:24
* @brief        : TODO
* Created by ml on 2026/4/7.
*/

#include <stddef.h>
#include "sort-cocktail.h"


inline __attribute__((always_inline)) void CockTailSort(int array[], const int size) {
    int start = 0;
    int end = size - 1;
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        for (size_t i = start; i < end; i++) {
            if (array[i] > array[i + 1]) {
                const int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }
        if (0 == swapped) {
            break;
        }
        swapped = 0;
        end -= 1;
        for (int i = end - 1; i > start - 1; i--) {
            if (array[i] > array[i + 1]) {
                const int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }
        start += 1;
    }
}
