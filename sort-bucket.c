/**
* @file         : sort-bucket.c
* @author       : ml
* @create       : 2026-04-08 09:13
* @brief        : TODO
* Created by ml on 2026/4/8.
*/


#include "sort-bucket.h"

#include <stdlib.h>
// Insert sort pre-bucket
void InnerInsertionSort(int array[], const int size) {
    for (int i = 1; i < size; i++) {
        const int key = array[i];
        int j = i - 1;
        /**< move back larg key*/
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Bucket Sort Main Function
void BucketSort(int array[], const int size) {
    if (size <= 0) {
        return;
    }

    // 1. Lookup max and min value.
    int max_value = array[0];
    float min_value = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }

        if (array[i] < min_value) {
            min_value = array[i];
        }
    }

    // 2. create bucket
    const int bucket_count = size; /**< bucket size is element count*/
    const float bucketInterval = (max_value - min_value) / bucket_count;/**< pre-bucket range size*/

    /**< allocated */
    int **buckets = (int **)malloc(bucket_count * sizeof(int *));
    int *bucketEleCountSizes = (int *)calloc(bucket_count, sizeof(int));

    for (int i = 0; i < bucket_count; i++) {
        buckets[i] = (int *)malloc(size * sizeof(float));
    }

    // 3. assigned bucket
    for (int i = 0; i < size; i++) {
        /**< caculate current bucket index*/
        int index = (array[i] - min_value) / bucketInterval;

        /**< edge case: when the element is largest, index maybe equal bucket count*/
        if (index == bucket_count) index--;

        /**< put element to bueckt*/
        buckets[index][bucketEleCountSizes[index]] = array[i];
        bucketEleCountSizes[index]++;
    }

    // 4.
    int idx = 0;
    for (int i = 0; i < bucket_count; i++) {
        if (bucketEleCountSizes[i] > 0) {
            InnerInsertionSort(buckets[i], bucketEleCountSizes[i]);
            for (int j = 0; j < bucketEleCountSizes[i]; j++) {
                array[idx++] = buckets[i][j];
            }
        }
    }

    // 5. free
    for (int i = 0; i < bucket_count; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketEleCountSizes);
}