#include "fileop.h"


int ReadTxtFile(STU students[], char* input_file){
    FILE* ifp = fopen(input_file, "r+");
    if (ifp == NULL) {
        printf("Can't open input file");
        return -1;
    }
    int i = 0;
    
    while(fscanf(ifp, "%ld %s %f %f %f %f", &students[i].stu_id,
                                          students[i].stu_name,
                                          &students[i].score.ics,
                                          &students[i].score.pdp,
                                          &students[i].score.ds,
                                          &students[i].score.dl) != EOF) {
        printf("%ld, %s, %.1f, %.1f, %.1f, %.1f\n", students[i].stu_id, 
                                                      students[i].stu_name, 
                                                      students[i].score.ics, 
                                                      students[i].score.pdp, 
                                                      students[i].score.ds,
                                                      students[i].score.dl);
        i++;
    }

    fclose(ifp);
    return i;
}

int ReadBinaryFile(STU students[],  char* input_file){
    FILE* ifp = fopen(input_file, "rb+");
    if (ifp == NULL) {
        printf("Can't open input file");
        return -1;
    }
    
    int i = 0;
    while(fread(&students[i], sizeof(STU), 1, ifp) != 0){
        printf("%ld, %s, %.1f, %.1f, %.1f, %.1f\n", students[i].stu_id, 
                                                      students[i].stu_name, 
                                                      students[i].score.ics, 
                                                      students[i].score.pdp, 
                                                      students[i].score.ds,
                                                      students[i].score.dl);
        i++;
    }

    fclose(ifp);
    return i;
    
}

int WriteTxtFile(STU students[], char* output_file, int num){
    FILE* ofp = fopen(output_file, "w");
    if(ofp == NULL){
        printf("Can't open output file");
        return -1;
    }

    for (int i = 0; i < num; i++) {
        fprintf(ofp, "%ld %s %f %f %f %f\n", students[i].stu_id,
                                             students[i].stu_name,
                                             students[i].score.ics,
                                             students[i].score.pdp,
                                             students[i].score.ds,
                                             students[i].score.dl);
    }
    printf("Write into txt successfully\n");

    fclose(ofp);
    return 0;


}

int WriteBinaryFile(STU students[], char* output_file, int num){
    FILE* ofp = fopen(output_file, "wb");

    if(ofp == NULL){
        printf("Can't open output file");
        return -1;
    }

    fwrite((char*)students, sizeof(STU), num, ofp);
    printf("Write into binary file succeccfully\n");
    
    fclose(ofp);
    return 0;
}
