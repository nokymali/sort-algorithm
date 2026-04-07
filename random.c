/**
* @file         : random.c
* @author       : ml
* @create       : 2026-04-07 10:25
* @brief        : TODO
* Created by ml on 2026/4/7.
*/

#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include "random.h"


inline __attribute__((always_inline)) long GetRandomValue() {
    struct timeval t;
    memset(&t, 0, sizeof(struct timeval));
    gettimeofday(&t, NULL);
    srand(t.tv_sec ^ t.tv_usec);
    return random();
}

inline __attribute__((always_inline)) uint32_t Arc4RandomUniform(uint32_t range_upper) {
    if (range_upper < 2) {
        return 0;
    }
    const uint32_t min = (UINT32_MAX - range_upper + 1) % range_upper;
    uint32_t v = 0;
    do {
        v = arc4random();
    } while (v < min);
    return v % range_upper;
}

