#include "sort.h"

void Swap(ElemType *data_list, int i, int j){
    ElemType temp;
    temp = *(data_list + i);
    *(data_list + i) = *(data_list + j);
    *(data_list + j) = temp;
}

