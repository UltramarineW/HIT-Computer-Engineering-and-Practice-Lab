#include <stdio.h>
#include <stdlib.h>
#include "fileop.h"

int main(int argc, char *argv[]) {
    float number_list[100] = {0};
    for (int i = 0; i < 100; i++) {
        number_list[i] = (float) i + 1;
    }
    char char_list[100] = {0};
    for (int i = 0; i < 10; i++) {
        char_list[i * 10 + 0] = 'a';
        char_list[i * 10 + 1] = 'b';
        char_list[i * 10 + 2] = 'c';
        char_list[i * 10 + 3] = 'd';
        char_list[i * 10 + 4] = 'e';
        char_list[i * 10 + 5] = 'f';
        char_list[i * 10 + 6] = 'g';
        char_list[i * 10 + 7] = 'h';
        char_list[i * 10 + 8] = 'i';
        char_list[i * 10 + 9] = 'j';
    }
    
    if (WriteTxtFileFloat(number_list, "float_txt_output.txt") != 0){
        exit(1);
    }
    if(WriteTxtFileChar(char_list, "char_txt_output.txt") != 0){
        exit(1);
    }
    if(WriteBinaryFileFloat(number_list, "float_binary_output.dat") != 0){
        exit(1);
    }
    if(WriteBinaryFileChar(char_list, "char_binary_output.dat") != 0){
        exit(1);
    }
    
    float float_list[100] = {0};
    if(ReadBinaryFileFloat(float_list, "./float_binary_output.dat") != 0) {
        exit(1);
    }

    
    return 0;
}
