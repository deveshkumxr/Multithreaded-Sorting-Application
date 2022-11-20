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
void init_array() {
    printf("Please enter the number of elements:");
    scanf("%ld", &array_size);
    for(size_t i = 0; i != array_size; i++) {
        scanf("%d", &array[i]);
    }
}

void merge_array(int *result) {
    size_t low1 = 0, high1 = array_size / 2;
    size_t low2 = array_size / 2, high2 = array_size;
    size_t i = 0;
    while(low1 < high1 && low2 < high2) {
        if(array[low1] < array[low2]) {
            result[i++] = array[low1++];
        } else {
            result[i++] = array[low2++];
        }
    }
    if(low2 < high2) {
        low1 = low2, high1 = high2;
    }
    while(low1 < high1) {
        result[i++] = array[low1++];
    }
}

void print_array(int *arr, size_t size) {
    for(size_t i = 0; i != size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

