#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* #define DEBUG */

void BubbleSort(ElemType *orig, int n, int (*cmp)(ElemType*, ElemType*)){
    int i, j;
    for(i = 0; i < n - 1; i++) {
#ifdef DEBUG
        if (i % 10000 == 0){
            printf("BubbleSort processing %d/100\n", i / 10000);
        }
#endif
        for(j = 0; j < n - i ; j++){
            if(cmp(orig + j - 1, orig + j) > 0){
                Swap(orig, j - 1, j);
            }
        }
    }

}
