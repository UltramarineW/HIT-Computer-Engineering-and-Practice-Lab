#include "fileop.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    //validate the arguments
    if(argc != 4) {
        printf("Please input 3 arguments, function, input file address, output file address\n");
        exit(1);
    }

    // arguments
    // argv[1] : function 1: from text file to binary file
    //                    2: from binary file to text file
    // argv[2] : input_file
    // argv[3] : output_file
    
    int function = atoi(argv[1]);
    char* input_file = argv[2];
    char* output_file = argv[3];

    if (function != 1 && function != 2) {
        printf("Please input true function number\n");
        printf("1: from text file to binary file\n");
        printf("2: from binary file to text file\n");
    }
    
    printf("Input file is %s, output file is %s\n", input_file, output_file);
    
    struct myrecord students[10];

    // from binary file to text file
    if (function == 2){
       int ret1 = ReadBinaryFile(students, input_file); 
       if(ret1 < 0) {
           printf("Read binary file error!");
           exit(1);
       }
       int ret2 = WriteTxtFile(students, output_file);
       if(ret2 < 0) {
           printf("Write text file error");
           exit(1);
       }
    } 

    //from text file to binary file
    else if(function == 1) {
        int ret3 = ReadTxtFile(students, input_file);
        if(ret3 < 0) {
            printf("Read text file error!");
            exit(1);
        }
        int ret4 = WriteBinaryFile(students, output_file);
        if(ret4 < 0) {
            printf("Write binary file error!");
            exit(1);
        }
    }

    return 0;
}
