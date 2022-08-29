#include "sort.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 100000

int IsRepeat(float* A, int i, float temp) {
    for(int j = 0; j < i; j++) {
        if(*(A + i) == temp) {
            return 1;
        }
    }
    return 0;
}

void MakeRand(float *A, int percent) {
    printf("Starting make random array\n");
    float initial = rand()%(10 * NUM);
    for(int i = 0; i < NUM * percent / 100; i++) {
        *(A + i) = initial;
    }
    for(int i = NUM * percent / 100; i < NUM; i++) {
        float temp= 0;
        do{
            temp = rand()%(10*NUM);
        } while(IsRepeat(A, i, temp) == 1);
        *(A + i) = temp;
    }
    printf("Starting random shuffle array \n");
    for(int i = 0; i < NUM - 1; i++) {
        int position = i + rand() % (NUM - i - 1);
        float temp = A[i];
        A[i] = A[position];
        A[position] = temp;
    }
}

int cmp(float *a, float *b) {
    if(*a ==*b) {
        return 0;
    } else if (*a > *b) {
        return 1;
    } else if(*a < *b) {
        return -1;
    }
}

int main(int argc, char *argv[]) {
    size_t t1, t2;
    int (*compare)(float *a, float *b);
    compare = &cmp;

    if(argc != 2) {
        return -1;
    }
    int percent = atoi(argv[1]);
    float* A = (float *)malloc(sizeof(float) * NUM);
    MakeRand(A, percent);
    printf("Starting quick sort array\n");
    t1 = clock();
    QuickSort(A, 0, NUM - 1, compare);
    t2 = clock();
    printf("QuickSort %d%% percent data in %f seconds\n", percent, (t2 - t1)/((double)CLOCKS_PER_SEC));
    return 0;
}
