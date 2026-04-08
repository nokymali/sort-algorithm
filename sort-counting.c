/**
* @file         : sort-counting.c
* @author       : ml
* @create       : 2026-04-08 09:12
* @brief        : TODO
* Created by ml on 2026/4/8.
*/


#include "sort-counting.h"

#include <stdlib.h>

inline __attribute__((always_inline)) void CountingSort(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    int *count = calloc(max + 1, sizeof(int));
    int *out  = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }
    for (int i =  1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        out[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (int i = 0; i < size; i++) {
        array[i] = out[i];
    }
    free(count);
    free(out);
}
