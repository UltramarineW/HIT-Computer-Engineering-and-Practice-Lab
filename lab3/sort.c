#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/* #define DEBUG */

void Swap(ElemType *data_list, int i, int j){
    ElemType temp;
    temp = *(data_list + i);
    *(data_list + i) = *(data_list + j);
    *(data_list + j) = temp;
}


void SelectionSort(ElemType *orig, int n, int (*cmp)(ElemType *, ElemType *))
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
#ifdef DEBUG
        if (i % 10000 == 0)
        {
            printf("SelectionSort processing %d/100\n", i / 10000);
        }
#endif
        j = i;
        for (k = i + 1; k < n; k++)
        {
            if (cmp(orig + j, orig + k) > 0)
            {
                j = k;
            }
        }
        Swap(orig, i, j);
    }
}

void BubbleSort(ElemType *orig, int n, int (*cmp)(ElemType *, ElemType *))
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
#ifdef DEBUG
        if (i % 10000 == 0)
        {
            printf("BubbleSort processing %d/100\n", i / 10000);
        }
#endif
        for (j = 0; j < n - i; j++)
        {
            if (cmp(orig + j - 1, orig + j) > 0)
            {
                Swap(orig, j - 1, j);
            }
        }
    }
}

void InsertSort(ElemType *orig, int n, int (*cmp)(ElemType *, ElemType *))
{
    int i, j, k;
    for (i = 1; i < n; i++)
    {
#ifdef DEBUG
        if (i % 10000 == 0)
        {
            printf("InsertSort processing %d/100\n", i / 10000);
        }
#endif
        ElemType temp = orig[i];
        j = i - 1;
        while (j >= 0 && cmp(orig + j, &temp) > 0)
        {
            orig[j + 1] = orig[j];
            j--;
        }
        orig[j + 1] = temp;
    }
}

void MergeSort(ElemType *orig, int start, int end, int (*cmp)(ElemType *, ElemType *))
{
    int middle = (start + end) / 2;
    if (start >= end)
    {
        return;
    }
    MergeSort(orig, start, middle, cmp);
    MergeSort(orig, middle + 1, end, cmp);

    ElemType *temp = (ElemType *)malloc(sizeof(ElemType) * (end - start + 1));

    int p1 = start, p2 = middle + 1, p3 = 0;
    while (p1 <= middle && p2 <= end)
    {
        if (cmp(orig + p1, orig + p2) < 0)
        {
            temp[p3] = orig[p1];
            p1++;
            p3++;
        }
        else
        {
            temp[p3] = orig[p2];
            p2++;
            p3++;
        }
    }
    if (p1 <= middle)
    {
        memcpy(temp + p3, orig + p1, (middle - p1 + 1) * sizeof(ElemType));
    }
    if (p2 <= end)
    {
        memcpy(temp + p3, orig + p2, (end - p2 + 1) * sizeof(ElemType));
    }
    memcpy(orig + start, temp, sizeof(ElemType) * (end - start + 1));
    free(temp);
}

void QuickSort(ElemType *orig, int start, int end, int (*cmp)(ElemType *, ElemType *))
{
    if (start > end)
    {
        return;
    }
    ElemType temp = orig[start];
    int left = start;
    int right = end;
    while (left < right)
    {
        while (cmp(orig + right, &temp) >= 0 && right > left)
        {
            right--;
        }
        while (cmp(orig + left, &temp) <= 0 && right > left)
        {
            left++;
        }
        if (left < right)
        {
            Swap(orig, left, right);
        }
    }

    orig[start] = orig[left];
    orig[left] = temp;

    QuickSort(orig, start, left - 1, cmp);
    QuickSort(orig, right + 1, end, cmp);
}

void AdjustMaxHeap(ElemType *orig, int n, int i, int (*cmp)(ElemType *, ElemType *))
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left >= n)
    {
        return;
    }
    int max = i;
    if (cmp(orig + left, orig + i) > 0)
    {
        max = left;
    }
    if (right < n && cmp(orig + right, orig + i) > 0)
    {
        max = right;
    }

    if (max == i)
    {
        return;
    }
    else
    {
        Swap(orig, max, i);
        AdjustMaxHeap(orig, n, max, cmp);
    }
}

void BuildMaxHeap(ElemType *orig, int n, int (*cmp)(ElemType *, ElemType *))
{
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        AdjustMaxHeap(orig, n, i, cmp);
    }
}

void HeapSort(ElemType *orig, int n, int (*cmp)(ElemType *, ElemType *))
{
    BuildMaxHeap(orig, n, cmp);
    for (int i = n - 1; i > 0; i--)
    {
        Swap(orig, i, 0);
        AdjustMaxHeap(orig, i, 0, cmp);
    }
}

