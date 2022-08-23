#pragma once

#include <stdio.h>


struct myrecord{
    unsigned long id;
    char name[32];
    float score[4];
};

int ReadTxtFile(struct myrecord students[], char* input_file);

int ReadBinaryFile(struct myrecord students[], char* input_file);

int WriteTxtFile(struct myrecord students[], char* output_file);

int WriteBinaryFile(struct myrecord students[], char* output_file);


