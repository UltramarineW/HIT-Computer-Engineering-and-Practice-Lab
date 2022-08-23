#include "fileop.h"


int ReadTxtFile(struct myrecord students[], char* input_file){
    FILE* ifp = fopen(input_file, "r+");
    if (ifp == NULL) {
        printf("Can't open input file");
        return -1;
    }
    
    for (int i = 0; i < 4; i++) {
        fscanf(ifp, "%ld %s %f %f %f %f", &students[i].id, students[i].name, &students[i].score[0], &students[i].score[1], &students[i].score[2], &students[i].score[3]);
        printf("%ld, %s, %.1f, %.1f, %.1f, %.1f\n", students[i].id, students[i].name, students[i].score[0], students[i].score[1], students[i].score[2], students[i].score[3]);
    }

    fclose(ifp);
    return 0;
}

int ReadBinaryFile(struct myrecord students[],  char* input_file){
    FILE* ifp = fopen(input_file, "rb+");
    if (ifp == NULL) {
        printf("Can't open input file");
        return -1;
    }
    
    for (int i = 0; i < 4; i++) {
        fread(&students[i], sizeof(struct myrecord), 1, ifp);
        printf("%ld, %s, %.1f, %.1f, %.1f, %.1f\n", students[i].id, students[i].name, students[i].score[0], students[i].score[1], students[i].score[2], students[i].score[3]);
    }

    fclose(ifp);
    return 0;
    
}

int WriteTxtFile(struct myrecord students[], char* output_file){
    FILE* ofp = fopen(output_file, "w");
    if(ofp == NULL){
        printf("Can't open output file");
        return -1;
    }

    for (int i = 0; i < 4; i++) {
        fprintf(ofp, "%ld %s %f %f %f %f\n", students[i].id, students[i].name, students[i].score[0], students[i].score[1], students[i].score[2], students[i].score[3]);
    }
    printf("Write into txt successfully\n");

    fclose(ofp);
    return 0;


}

int WriteBinaryFile(struct myrecord students[], char* output_file){
    FILE* ofp = fopen(output_file, "wb");

    if(ofp == NULL){
        printf("Can't open output file");
        return -1;
    }

    fwrite((char*)students, sizeof(struct myrecord), 4, ofp);
    printf("Write into binary file succeccfully\n");
    
    fclose(ofp);
    return 0;
}
