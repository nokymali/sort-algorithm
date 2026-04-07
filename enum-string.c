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
        case ST_COCKTAIL: {
            return "Sort CockTail";
        }
        default: {
            return "Unknown";
        }
    }
}
