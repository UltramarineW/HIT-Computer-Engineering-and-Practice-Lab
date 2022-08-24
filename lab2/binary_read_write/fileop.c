#include "fileop.h"

int WriteTxtFileFloat(float number_list[], char* output_file){
    printf("Write float text file start\n");
    FILE* ofp = fopen(output_file, "w");
    if(ofp == NULL){
        printf("Can't open output file\n");
        return -1;
    }

    for (int i = 0; i < 100; i++) {
        fprintf(ofp, "%f\t", number_list[i]);
    }

    printf("Write into txt successfully\n");

    fclose(ofp);
    return 0;


}

int WriteTxtFileChar(char char_list[], char* output_file){

    printf("Write char text file start\n");
    FILE* ofp = fopen(output_file, "w");
    if(ofp == NULL){
        printf("Can't open output file\n");
        return -1;
    }

    for (int i = 0; i < 100; i++) {
        fprintf(ofp, "%c\t", char_list[i]);
    }

    printf("Write into txt successfully\n");

    fclose(ofp);
    return 0;

    
}

int WriteBinaryFileFloat(float number_list[], char* output_file){

    printf("Write float binary file start\n");

    FILE* ofp = fopen(output_file, "wb");

    if(ofp == NULL){
        printf("Can't open output file");
        return -1;
    }

    fwrite((char*)number_list, sizeof(float), 100, ofp);
    printf("Write into binary file succeccfully\n");
    
    fclose(ofp);
    return 0;

}

int WriteBinaryFileChar(char char_list[], char* output_file){

    printf("Write char binary file start\n");

    FILE* ofp = fopen(output_file, "wb");

    if(ofp == NULL){
        printf("Can't open output file");
        return -1;
    }

    fwrite((char*)char_list, sizeof(char), 100, ofp);
    printf("Write into binary file succeccfully\n");
    
    fclose(ofp);
    return 0;


}


int ReadBinaryFileFloat(float float_list[], char* input_file){
    FILE* ifp = fopen(input_file, "rb+");
    if (ifp == NULL) {
        printf("Can't open input file");
        return -1;
    }
    
    for (int i = 0; i < 100; i++) {
        fread(&float_list[i], sizeof(float), 1, ifp);
        printf("%f\n", float_list[i]);
    }

    fclose(ifp);
    return 0;
    
    
}
