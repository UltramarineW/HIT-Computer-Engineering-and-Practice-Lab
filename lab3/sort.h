#ifndef __SORT_H__
#define __SORT_H__

#define INT 0
#define FLOAT 1
#define DOUBLE 2
#define STUDENT 3

typedef struct Student {
    char id[20];
    char name[20];
    float score[5];
    float total;
} STU;

typedef float ElemType;

void generate_data(ElemType *orig, int size);
void SelectionSort(ElemType *orig, int n, int (*cmp)(ElemType*, ElemType*));
void InsertSort(ElemType *orig, int n, int (*cmp)(ElemType*, ElemType*));
void BubbleSort(ElemType *orig, int n, int (*cmp)(ElemType*, ElemType*));
void MergeSort(ElemType *orig, int start, int end, int (*cmp)(ElemType*, ElemType*));
void QuickSort(ElemType *orig, int start, int end, int (*cmp)(ElemType*, ElemType*));
void HeapSort(ElemType *orig, int n, int (*cmp)(ElemType*, ElemType*));


void Swap(ElemType* data_list, int i, int j);

#endif
