#pragma once

#include <stdio.h>


int WriteTxtFileFloat(float number_list[], char* output_file);

int WriteTxtFileChar(char char_list[], char* output_file);

int WriteBinaryFileFloat(float number_list[], char* output_file);

int WriteBinaryFileChar(char char_list[], char* output_file);

int ReadBinaryFileFloat(float float_list[], char* input_file);
