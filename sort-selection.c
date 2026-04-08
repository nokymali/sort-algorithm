/**
* @file         : sort-selection.c
* @author       : ml
* @create       : 2026-04-08 09:10
* @brief        : TODO
* Created by ml on 2026/4/8.
*/


#include "sort-selection.h"
inline __attribute__((always_inline)) void SelectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIdx]) {
                minIdx = j;
            }
        }
        const int temp = array[minIdx];
        array[minIdx] = array[i];
        array[i] = temp;
    }
}