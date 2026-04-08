/**
* @file         : sort-radix.c
* @author       : ml
* @create       : 2026-04-08 09:13
* @brief        : TODO
* Created by ml on 2026/4/8.
*/


#include "sort-radix.h"

static inline __attribute__((always_inline)) int GetMax(int array[], const int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

static inline __attribute__((always_inline)) void RadixSortCounting(int array[], const int n, const int exp) {
    int out[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[(array[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        out[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        array[i] = out[i];
    }
}

inline __attribute__((always_inline)) void RadixSort(int array[], const int n) {
    const int max = GetMax(array, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        RadixSortCounting(array, n, exp);
    }
}