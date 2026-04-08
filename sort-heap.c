/**
* @file         : sort-heap.c
* @author       : ml
* @create       : 2026-04-08 09:12
* @brief        : TODO
* Created by ml on 2026/4/8.
*/


#include "sort-heap.h"

static void Heapify(int array[], const int size, const int index) {
    int largest = index;
    const int left = 2 * index + 1;
    const int right = 2 * index + 2;
    if (left < size && array[left] > array[largest]) {
        largest = left;
    }

    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != index) {
        const int temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;
        Heapify(array, size, largest);
    }
}

inline __attribute__((always_inline)) void HeapSort(int array[], const int size) {
    /**< create max heap*/
    for (int i = size / 2 - 1; i >= 0; i--) {
        Heapify(array, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        const int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        Heapify(array, i, 0);
    }
}
