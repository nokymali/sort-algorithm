/**
* @file         : enum-string.h
* @author       : ml
* @create       : 2026-04-07 11:06
* @brief        : TODO
* Created by ml on 2026/4/7.
*/


#ifndef SORT_ALGORITHM_ENUM_STRING_H
#define SORT_ALGORITHM_ENUM_STRING_H

typedef enum  SortType_ {
    ST_BUBBLE,
    ST_COCKTAIL,
    ST_MAX,
} SortType;

char *EnumToString(SortType sort);

#endif //SORT_ALGORITHM_ENUM_STRING_H
