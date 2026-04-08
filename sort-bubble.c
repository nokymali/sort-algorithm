/**
* @file         : sort-bubble.c
* @author       : ml
* @create       : 2026-04-07 10:36
* @brief        : TODO
* Created by ml on 2026/4/7.
*/
#include "sort-bubble.h"

inline __attribute__((always_inline))  void BubbleSort(int array[], const int size) {
    int i = 0, j = 0, temp = 0;
    for (i = 0; i < size - 1; i++) {
        int swap = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swap = 1;
            }
        }
        if (0 == swap) {
            break;
        }
    }
}