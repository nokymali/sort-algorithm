/**
* @file         : sort-insertion.c
* @author       : ml
* @create       : 2026-04-08 09:11
* @brief        : TODO
* Created by ml on 2026/4/8.
*/


#include "sort-insertion.h"
inline __attribute__((always_inline)) void InsertionSort(int array[], const int size) {
    for (int i = 1; i < size; i++) {
        const int value = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > value) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = value;
    }
}