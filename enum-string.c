/**
* @file         : enum-string.c
* @author       : ml
* @create       : 2026-04-07 11:06
* @brief        : TODO
* Created by ml on 2026/4/7.
*/


#include "enum-string.h"

inline __attribute__((always_inline)) char *EnumToString(SortType type) {
    switch (type) {
        case ST_BUBBLE: {
            return "Sort Bubble";
        }
        case ST_SELECTION: {
            return "Sort Selection";
        }
        case ST_INSERTION: {
            return "Sort Insertion";
        }
        case ST_MERGE: {
            return "Sort Merge";
        }
        case ST_QUICK: {
            return "Sort Quick";
        }
        case ST_HEAP: {
            return "Sort Heap";
        }
        case ST_SHELL: {
            return "Sort Shell";
        }
        case ST_COUNTING: {
            return "Sort Counting";
        }
        case ST_BUCKET: {
            return "Sort Bucket";
        }
        case ST_RADIX: {
            return "Sort Radix";
        }
        case ST_COCKTAIL: {
            return "Sort CockTail";
        }
        default: {
            return "Unknown";
        }
    }
}
