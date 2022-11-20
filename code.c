//CS252-Operating Systems project (assignment)
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100
/* global variables are shared by threads */
int array[MAX_NUM];
size_t array_size = 0;

typedef struct {
    size_t low;
    size_t high;
} parameters;

int cmp(const void  *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

/* The thread will do the sorting */
void *runner(void *param) {
    size_t low, high;
    low = ((parameters *)param)->low;
    high = ((parameters *)param)->high;
    // printf("Low: %lu, high: %lu\n", low, high);
    qsort(array + low, high - low, sizeof(int), cmp);
    pthread_exit(0);
}
