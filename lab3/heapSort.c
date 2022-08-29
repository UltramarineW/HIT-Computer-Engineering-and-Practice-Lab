#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void AdjustMaxHeap(ElemType* orig, int n, int i, int (*cmp)(ElemType*, ElemType*)){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left >= n) {
        return;
    }
    int max = i;
    if (cmp(orig + left, orig + i) > 0) {
        max = left;
    }
    if(right < n && cmp(orig + right, orig + i) > 0) {
        max = right;
    }

    if (max == i) {
        return;
    } else{
        Swap(orig, max, i);
        AdjustMaxHeap(orig, n, max, cmp);
    }
}

void BuildMaxHeap(ElemType* orig, int n, int (*cmp)(ElemType*, ElemType*)) {
    for (int i = (n-1)/2; i >= 0; i--) {
        AdjustMaxHeap(orig, n, i, cmp);
    }
}


void HeapSort(ElemType *orig, int n, int (*cmp)(ElemType*, ElemType*)){
    BuildMaxHeap(orig, n, cmp);
    for(int i = n - 1; i > 0; i--) {
        Swap(orig, i, 0);
        AdjustMaxHeap(orig, i, 0, cmp);
    }
}


