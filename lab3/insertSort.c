#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* #define DEBUG */

void InsertSort(ElemType *orig, int n, int(*cmp)(ElemType*, ElemType*)){
    int i, j, k;
    for(i = 1; i < n; i++) {
#ifdef DEBUG
        if (i %10000 == 0) {
            printf("InsertSort processing %d/100\n" , i /10000);
        } 
#endif
        ElemType temp = orig[i];
        j = i - 1;
        while(j >= 0 && cmp(orig + j, &temp) > 0) {
            orig[j + 1] = orig[j];
            j--;
        }
        orig[j + 1] = temp;
    }
}
