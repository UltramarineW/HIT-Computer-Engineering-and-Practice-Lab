#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "sort.h"

/* #define Debug */

int dataType = FLOAT;

int   cmp(ElemType * a, ElemType *b);
void  generateData(ElemType * A, int num);
void  randName(char * name);
void  randID(char * id);
void  output(ElemType A[],int n, char * info);



int main(int argc, char ** argv)
{
    size_t t1, t2;
    int size;
    ElemType *orig, *toSort;
    int (*cmpare)(ElemType * a, ElemType *b);
    cmpare = &cmp;
    char type[10] = {0};

    if(argc<2)
        return 1;
    sscanf(argv[1], "%d", &size);
    if(size<=0){
        printf("Size must be a positive number");
        return 0;
    }

    orig = (ElemType*) malloc(sizeof(ElemType)*size);
    toSort = (ElemType*) malloc(sizeof(ElemType)*size);
    generateData(orig, size);
    
    if(dataType == INT) {
        strcpy(type, "int");
    } else if (dataType == FLOAT) {
        strcpy(type, "float");
    } else if (dataType == STUDENT) {
        strcpy(type, "student");
    } else {
        strcpy(type, "double");
    }

    printf("Successfully generate data: %d %s\n", size, type);

    memcpy(toSort, orig, size*sizeof(ElemType));
#ifdef Debug
    output(toSort, size,"SelectSort: before");
#endif
    t1 = clock();
    SelectionSort(toSort, size, cmpare);
    t2 = clock();
#ifdef Debug
    output(toSort, size, "SelectSort: after");
#endif
    printf("SelectSort runs in %f seconds\n", (t2-t1)/((double)CLOCKS_PER_SEC));



    memcpy(toSort, orig, size*sizeof(ElemType));
#ifdef Debug
    output(toSort, size,"BubbleSort: before");
#endif
    t1 = clock();
    BubbleSort(toSort, size, cmpare);
    t2 = clock();
#ifdef Debug
    output(toSort, size, "BubbleSort: after");
#endif
    printf("BubbleSort runs in %f seconds\n", (t2-t1)/((double)CLOCKS_PER_SEC));


   memcpy(toSort, orig, size*sizeof(ElemType));
#ifdef Debug
    output(toSort, size,"InsertSort: before");
#endif
    t1 = clock();
    InsertSort(toSort, size, cmpare);
    t2 = clock();
#ifdef Debug
    output(toSort, size, "InsertSort: after");
#endif
    printf("InsertSort runs in %f seconds\n", (t2-t1)/((double)CLOCKS_PER_SEC));

    
     memcpy(toSort, orig, size*sizeof(ElemType));
#ifdef Debug
    output(toSort, size,"MergeSort: before");
#endif
    t1 = clock();
    MergeSort(toSort, 0, size - 1, cmpare);
    t2 = clock();
#ifdef Debug
    output(toSort, size, "MergeSort: after");
#endif
    printf("MergeSort runs in %f seconds\n", (t2-t1)/((double)CLOCKS_PER_SEC));



     memcpy(toSort, orig, size*sizeof(ElemType));
#ifdef Debug
    output(toSort, size,"QuickSort: before");
#endif
    t1 = clock();
    QuickSort(toSort, 0, size-1, cmpare);
    t2 = clock();
#ifdef Debug
    output(toSort, size, "QuickSort: after");
#endif
    printf("QuickSort runs in %f seconds\n", (t2-t1)/((double)CLOCKS_PER_SEC));


    memcpy(toSort, orig, size*sizeof(ElemType));
#ifdef Debug
    output(toSort, size,"HeapSort: before");
#endif
    t1 = clock();
    HeapSort(toSort,size, cmpare);
    t2 = clock();
#ifdef Debug
    output(toSort, size, "HeapSort: after");
#endif
    printf("HeapSort runs in %f seconds\n", (t2-t1)/((double)CLOCKS_PER_SEC));

    return 1;
}


int cmp(ElemType * a, ElemType *b)
{
    if(dataType == INT)
    {
        if(*((int*)a) == *((int*)b))
            return 0;
        else if (*((int*)a)> *((int*)b))
            return 1;
        else
            return -1;
    }
    else if(dataType == FLOAT)
    {
        if(*((float*)a) == *((float*)b))
            return 0;
        else if (*((float*)a)> *((float*)b))
            return 1;
        else
            return -1;
    }
    else if(dataType == DOUBLE)
    {
        if(*((double*)a) == *((double*)b))
            return 0;
        else if (*((double*)a)> *((double*)b))
            return 1;
        else
            return -1;
    }
    else
    {
        STU * pa = (STU *)a;
        STU * pb = (STU *)b;
        if(pa->total == pb->total)
            return 0;
        else if (pa->total > pb->total)
            return 1;
        else
            return -1;
    }
}

void  generateData(ElemType * A, int num)
{
    if(dataType == INT)
    {
        for(int i=0; i<num; i++)
        {
            *((int*)(A+i)) = rand()%(10*num);
        }
    }
    else if(dataType == FLOAT)
    {
        for(int i=0; i<num; i++)
        {
            *((float*)(A+i)) = rand()%(10*num);
        }
    }
    else if(dataType == DOUBLE)
    {
        for(int i=0; i<num; i++)
        {
            *((double*)(A+i)) = rand()%(10*num);
        }
    }
    else
    {
        for(int i=0; i<num; i++)
        {
            randID(((STU*)(A+i))->id);
            randName( ((STU*)(A+i))->name);
            ((STU*)(A+i))->total = 0;
            for(int j=0; j<5; j++)
            {
                ((STU*)(A+i))->score[j] = (rand()%10000)/((double) 100);
                ((STU*)(A+i))->total += ((STU*)(A+i))->score[j];
            }
        }
    }
}

void  randName(char * name)
{
    char ALPHA[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alpha[26]="abcdefghijklmnopqrstuvwxyz";
    int len = 1+ rand()%18;
    name[0] = ALPHA[rand()%26];
    for(int i=1; i<len; i++)
    {
        name[i] = alpha[rand()%26];
    }
    name[len] = '\0';

}
void  randID(char * id)
{
    char buf[20] = "2021031";
    char buf1[3];
    char buf2[5];
    int classNo = rand()%100;
    int stuNo = rand()%10000;
    sprintf(buf1, "%02d", classNo);
    buf1[2] = '\0';
    sprintf(buf2,  "%04d", stuNo);
    buf2[4] = '\0';
    strcat(buf, buf1);
    strcat(buf, buf2);
    strcpy(id, buf);
}

void output(ElemType A[],int n, char * info)
{
    printf("%s\n", info);
    switch(dataType)
    {
    case INT:
        for(int i=0; i<n; i++)
        {

            printf("%d ", *((int*)(A+i)));
        }
        printf("\n");
        break;

    case FLOAT:
        for(int i=0; i<n; i++)
        {

            printf("%f ", *((float*)(A+i)));
        }
        printf("\n");
        break;
    case DOUBLE:
        for(int i=0; i<n; i++)
        {

            printf("%f ", *((double*)(A+i)));
        }
        printf("\n");
        break;
    case STUDENT:
        for(int i=0; i<n; i++)
        {

            printf("%s %-20s ", ((STU*)(A+i))->id, ((STU*)(A+i))->name);
            for(int j=0; j<5; j++)
            {
                printf("%f ", ((STU*)(A+i))->score[j]);
            }
            printf("%f \n", ((STU*)(A+i))->total);
        }
        break;
    default:
        break;
    }
}
