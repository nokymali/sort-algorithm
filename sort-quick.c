/**
* @file         : sort-quick.c
* @author       : ml
* @create       : 2026-04-08 09:12
* @brief        : TODO
* Created by ml on 2026/4/8.
*/


#include "sort-quick.h"
static inline __attribute__((always_inline)) int Partition(int array[], const int low, int const high) {
    const int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            const int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    const int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

static void QuickSortSub(int array[], const int low, const int high) {
    if (low < high) {
        const int pot = Partition(array, low, high);
        QuickSortSub(array, low, pot - 1);
        QuickSortSub(array, pot + 1, high);
    }
}

inline __attribute__((always_inline)) void QuickSort(int array[], const int size) {
    QuickSortSub(array, 0, size - 1);
}