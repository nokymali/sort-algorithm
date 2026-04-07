#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

#include "enum-string.h"
#include "random.h"
#include "sort-cocktail.h"
#include "sort-bubble.h"

#define MAX_COUNT 10

typedef struct Element_ {
    int *values;
    int count;
} Element;

typedef void (*CBSort)(int array[], const int size);
static CBSort sortFuncs[ST_MAX];
static Element *elMgr = NULL;

void RegisterSortCB();
void ElementCreate(int);
void ElementDestroy();
void ElementUpdate();
void DisplayInfo(const char *);

int main(const int argc, char *argv[]) {
    /**< 1. check command line parameter*/
    if (2 > argc) {
        fprintf(stderr, "Please Set Count\n");
        fprintf(stdout, "%s [count]\n\t count: digit count\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /**< 2. Register Sort Algorithm*/
    RegisterSortCB();

    /**< 3. Create Elements*/
    const int count = (int)strtoul(argv[1], NULL, 10);
    ElementCreate(count);

    /**< 4. Sort */
    int i = 0;
    for (i = 0; i < ST_MAX; i++) {
        ElementUpdate();
        DisplayInfo("Before");
        struct timeval s, e;
        gettimeofday(&s, NULL);
        sortFuncs[i](elMgr->values, elMgr->count);
        gettimeofday(&e, NULL);
        DisplayInfo("End");
        const double diff = (double)(e.tv_sec - s.tv_sec) * 1.0L + (e.tv_usec - s.tv_usec) / 1000000.0L;
        const char *title = EnumToString(i);
        fprintf(stdout, "%s Algorithm, Count %d, Elapsed: %.06f s (seconds)\n\n", title, elMgr->count, diff);
    }

    /**< 5. Destroy*/
    ElementDestroy();
    return 0;
}

void RegisterSortCB() {
    sortFuncs[ST_BUBBLE]    = BubbleSort;
    sortFuncs[ST_COCKTAIL]  = CockTailSort;
    //...
}

void ElementCreate(const int count) {
    elMgr = (Element *)calloc(1, (count * sizeof(Element)));
    if (NULL == elMgr) {
        fprintf(stderr, "Fail to Allocated Element Buffer.\n");
        exit(EXIT_FAILURE);
    }
    if (count < MAX_COUNT) {
        elMgr->count = MAX_COUNT;
    } else {
        elMgr->count = count;
    }
    elMgr->values = (int *)calloc(elMgr->count, sizeof(int));
    if (NULL == elMgr->values) {
        fprintf(stderr, "Fail to Allocated Value Buffer.\n");
        exit(EXIT_FAILURE);
    }
}

void ElementUpdate() {
    if (NULL == elMgr || NULL == elMgr->values) {
        return;
    }
    for (uint32_t i = 0; i < elMgr->count; i++) {
        elMgr->values[i] = (int)Arc4RandomUniform(100);
    }
}

void ElementDestroy() {
    if (elMgr == NULL) {
        return;
    }
    if (elMgr->values) {
        free(elMgr->values);
        elMgr->values = NULL;
    }
    free(elMgr);
    elMgr = NULL;
}




void DisplayInfo(const char *flag) {
    if (elMgr == NULL) {
        return;
    }
    if (elMgr->values == NULL || elMgr->count == 0) {
        return;
    }

    if (elMgr->count > 70) {
        fprintf(stdout, "......\n");
        return;
    }
    fprintf(stdout, "[");
    for (uint32_t i = 0; i < elMgr->count; i++) {
        if ((i + 1) == elMgr->count) {
            fprintf(stdout, "%d", elMgr->values[i]);
        } else {
            fprintf(stdout, "%d, ", elMgr->values[i]);
        }
    }
    fprintf(stdout, "] %s\n", flag);
}

