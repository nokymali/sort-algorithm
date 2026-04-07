/**
* @file         : sort-bubble.c
* @author       : ml
* @create       : 2026-04-07 10:36
* @brief        : TODO
* Created by ml on 2026/4/7.
*/
#include "sort-bubble.h"

inline __attribute__((always_inline))  void BubbleSort(int array[], const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                const int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}