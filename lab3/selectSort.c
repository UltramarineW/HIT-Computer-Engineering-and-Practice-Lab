#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/* #define DEBUG */

void SelectionSort(ElemType *orig, int n, int (*cmp)(ElemType*, ElemType*)){
    int i, j, k;
    for(i = 0; i < n-1; i++) {
#ifdef DEBUG
        if (i % 10000 == 0) {
            printf("SelectionSort processing %d/100\n", i/10000);
        }
#endif
        j = i;
        for(k = i + 1; k < n; k++) {
            if(cmp(orig + j, orig + k) > 0){
                j = k;
            }
        }
        Swap(orig, i, j);
    }
}
