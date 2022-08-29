#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


void QuickSort(ElemType *orig, int start, int end, int (*cmp)(ElemType*, ElemType*)){
    if (start > end) {
        return;
    }
    ElemType temp = orig[start];
    int left = start;
    int right = end;
    while (left < right) {
        while(cmp(orig + right, &temp) >= 0 && right > left) {
            right --;
        }
        while(cmp(orig + left, &temp) <= 0 && right > left) {
            left ++;
        }
        if(left < right) {
            Swap(orig, left, right);
        }
    }

    orig[start] = orig[left];
    orig[left] = temp;
    
    QuickSort(orig, start, left - 1, cmp);
    QuickSort(orig, right + 1, end, cmp);
}
