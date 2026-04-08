/**
* @file         : sort-shell.c
* @author       : ml
* @create       : 2026-04-08 09:12
* @brief        : TODO
* Created by ml on 2026/4/8.
*/


#include "sort-shell.h"
inline __attribute__((always_inline)) void ShellSort(int array[], const int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            const int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}