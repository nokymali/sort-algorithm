/**
* @file         : sort-merg.c
* @author       : ml
* @create       : 2026-04-08 09:11
* @brief        : TODO
* Created by ml on 2026/4/8.
*/


#include "sort-merge.h"
static void Merge(int array[], const int left, const int mid, const int right) {
    const int n1 = mid - left + 1;
    const int n2 = right - mid;
    int leftArray[n1], rightArray[n2];
    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = array[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        array[k++] = (leftArray[i] <= rightArray[j]) ? leftArray[i++] : rightArray[j++];
    }
    while (i < n1) {
        array[k++] = leftArray[i++];
    }
    while (j < n2) {
        array[k++] = rightArray[j++];
    }
}

static void MergeSortSub(int array[], const int left, const int right) {
    if (left < right) {
        const int mid = left + (right - left) / 2;
        MergeSortSub(array, left, mid);
        MergeSortSub(array, mid + 1, right);
        Merge(array, left, mid, right);
    }
}

inline __attribute__((always_inline)) void MergeSort(int array[], const int size) {
    MergeSortSub(array, 0, size - 1);
}