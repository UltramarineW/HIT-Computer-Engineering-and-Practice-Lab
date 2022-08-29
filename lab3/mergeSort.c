#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"



void MergeSort(ElemType *orig, int start, int end, int (*cmp)(ElemType*, ElemType*)){
    int middle = (start + end) / 2;
    if(start >= end) {
        return;
    }
    MergeSort(orig, start, middle, cmp);
    MergeSort(orig, middle + 1, end, cmp);
    
    ElemType* temp = (ElemType *)malloc(sizeof(ElemType) * (end - start + 1));
    
    int p1 = start, p2 = middle + 1, p3 = 0;
    while(p1 <= middle && p2 <= end) {
        if(cmp(orig + p1, orig + p2) < 0){
            temp[p3] = orig[p1];
            p1++;
            p3++;
        }
        else{
            temp[p3] = orig[p2];
            p2++;
            p3++;
        }
    }
    if(p1 <= middle) {
        memcpy(temp + p3, orig + p1, (middle - p1 + 1) * sizeof(ElemType));
    }
    if(p2 <= end) {
        memcpy(temp + p3, orig + p2, (end - p2 + 1) * sizeof(ElemType));
    }
    memcpy(orig + start, temp, sizeof(ElemType) * (end - start + 1));
    free(temp);

}
