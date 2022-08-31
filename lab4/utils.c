#include "utils.h"

void menu(){
    printf("1. Append record\n");
    printf("2. Search by name\n");
    printf("3. Search by ID\n");
    printf("4. Modify by ID\n");
    printf("5. Delete by ID\n");
    printf("6. Caculate total and average score of every student\n");
    printf("7. Caculate average score of every course\n");
    printf("8. Sort in descending order by course score\n");
    printf("9. Statistic analysis for every course\n");
    printf("10.Save record\n");
    printf("11.Load record\n");
    printf("0. Exit\n");
    printf("Please enter your choice:");
}

void AppendRecord(STU* student_record, int* num){
    printf("[INFO] Starting Append student record\n");
    if (*num >= 44){
        printf("[ERROR] The number of students has reached maximum\n");
        return;
    }
    printf("Please input name: ");
    scanf("%s", (student_record + *num)-> stu_name );
    printf("Please input id: ");
    scanf("%lu", &(student_record + *num) -> stu_id);
    printf("Please input ics score: ");
    scanf("%f", &(student_record + *num)->score.ics);
    printf("Please input pdp score: ");
    scanf("%f", &(student_record + *num)->score.pdp);
    printf("Please input ds score: ");
    scanf("%f", &(student_record + *num)->score.ds);
    printf("Please input dl score: ");
    scanf("%f", &(student_record + *num)->score.dl);

    (*num) ++;
    printf("[INFO] Append recored succesfully\n");
    return ;
}

void SearchByName(STU* student_record, int num){
    printf("[INFO] Starting search student by name\n");
    char input_name[32];
    int i = 0;
    printf("Please input name: ");
    scanf("%s", input_name);
    for (i = 0; i < num; i++) {
        if(strcmp(input_name, (student_record + i)->stu_name) == 0) {
            printf("[Success] Find student %s\n", input_name);
            printf("ID             Name        ICS   PDP   DS    DL\n");
            printf("%-14lu %-10s  %-.1f  %-.1f  %-.1f  %-.1f\n", (student_record + i)->stu_id,\
                                                           (student_record + i)->stu_name,\
                                                           (student_record + i)->score.ics,\
                                                           (student_record + i)->score.pdp,\
                                                           (student_record + i)->score.ds,\
                                                           (student_record + i)->score.dl);
            return;
        }
    }
    printf("[INFO] Can't find student %s", input_name);
    return;
}

void SearchByID(STU* student_record, int num){
    printf("[INFO] Starting search student by ID\n");
    unsigned long input_id = 0;
    int i = 0;
    printf("Please input ID: ");
    if(scanf("%lu", &input_id) == 0) {
        printf("[ERROR] Please input correct id");
        setbuf(stdin, NULL);
        return;
    }
    for (i = 0; i < num; i++) {
        if((student_record + i)->stu_id == input_id) {
            printf("[Success] Find student %s\n", (student_record + i) -> stu_name);
            printf("ID             Name        ICS   PDP   DS    DL\n");
            printf("%-14lu %-10s  %-.1f  %-.1f  %-.1f  %-.1f\n", (student_record + i)->stu_id,\
                                                           (student_record + i)->stu_name,\
                                                           (student_record + i)->score.ics,\
                                                           (student_record + i)->score.pdp,\
                                                           (student_record + i)->score.ds,\
                                                           (student_record + i)->score.dl);
            return;
        }
    }
    printf("[INFO] Can't find student %s", (student_record + i)-> stu_name);
    return;

}

void ModifyByID(STU* student_record, int num){
    printf("[INFO] Starting modify student by ID\n");
    unsigned long input_id = 0;
    int i = 0;
    printf("Please input ID: ");
    scanf("%lu", &input_id);
    for (i = 0; i < num; i++) {
        if((student_record + i)->stu_id == input_id) {
            printf("[Success] Find student %s\n", (student_record + i) -> stu_name);
            printf("ID             Name        ICS   PDP   DS    DL\n");
            printf("%-14lu %-10s  %-.1f  %-.1f  %-.1f  %-.1f\n", (student_record + i)->stu_id,\
                                                           (student_record + i)->stu_name,\
                                                           (student_record + i)->score.ics,\
                                                           (student_record + i)->score.pdp,\
                                                           (student_record + i)->score.ds,\
                                                           (student_record + i)->score.dl);
            printf("\nPlease input new student information");
            
            printf("Please input name: ");
            scanf("%s", (student_record + i)-> stu_name );
            printf("Please input id: ");
            scanf("%lu", &(student_record + i) -> stu_id);
            printf("Please input ics score: ");
            scanf("%f", &(student_record + i)->score.ics);
            printf("Please input pdp score: ");
            scanf("%f", &(student_record + i)->score.pdp);
            printf("Please input ds score: ");
            scanf("%f", &(student_record + i)->score.ds);
            printf("Please input dl score: ");
            scanf("%f", &(student_record + i)->score.dl);
            return;
        }
    }
    printf("[INFO] Can't find student %s", (student_record + i)-> stu_name);
    return;

}

void DeleteByID(STU* student_record, int* num){
    printf("[INFO] Starting delete student by ID\n");
    unsigned long input_id = 0;
    int i = 0;
    printf("Please input ID: ");
    scanf("%lu", &input_id);
    for (i = 0; i < *num; i++) {
        if((student_record + i)->stu_id == input_id) {
            printf("[Success] Find student %s\n", (student_record + i) -> stu_name);
            printf("ID             Name        ICS   PDP   DS    DL\n");
            printf("%-14lu %-10s  %-.1f  %-.1f  %-.1f  %-.1f\n", (student_record + i)->stu_id,\
                                                           (student_record + i)->stu_name,\
                                                           (student_record + i)->score.ics,\
                                                           (student_record + i)->score.pdp,\
                                                           (student_record + i)->score.ds,\
                                                           (student_record + i)->score.dl);
            printf("\nAre you sure to delete?[y/n]: ");
            char judge;
            judge = getchar();
            judge = getchar();
            if (judge == 'y') {
                for(int j = i; j < (*num)-1; j++) {
                    strcpy((student_record + j)->stu_name, (student_record + j + 1)->stu_name);
                    (student_record + j)->stu_id = (student_record + j + 1) -> stu_id;
                    (student_record + j)->score = (student_record + j + 1) -> score;
                }
                (*num) --;
                printf("[INFO] Complete delete");
            } else{
                printf("[INFO] Stop delete");
            }
            return;
        }
    }
    printf("[INFO] Can't find student %s", (student_record + i)-> stu_name);
    return;

    

}

void CalcStudents(STU* student_record, int num){
    printf("[INFO] Starting calculate total and average score of every students\n");
    printf("ID             Name        ICS   PDP   DS    DL    Total  Average\n");
    for(int i = 0; i < num; i++){
        (student_record + i)->total = (student_record + i)->score.ics + \
                                      (student_record + i)->score.pdp + \
                                      (student_record + i)->score.dl + \
                                      (student_record + i)->score.ds;
        (student_record + i)->average = (student_record + i)->total /4;
        printf("%-14lu %-10s  %-.1f  %-.1f  %-.1f  %-.1f  %-.1f  %-.1f\n", (student_record + i)->stu_id,\
                                                       (student_record + i)->stu_name,\
                                                       (student_record + i)->score.ics,\
                                                       (student_record + i)->score.pdp,\
                                                       (student_record + i)->score.ds,\
                                                       (student_record + i)->score.dl,\
                                                       (student_record + i)->total,\
                                                       (student_record + i)->average);
    }
    return;
}

void CalcCourse(STU* student_record, int num){
    printf("[INFO] Starting calculate course average\n");
    float ics_total = 0, pdp_total = 0, ds_total = 0, dl_total = 0;
    float ics_aver, pdp_aver, ds_aver, dl_aver;
    for(int i = 0; i < num; i++) {
        ics_total += (student_record + i)->score.ics;
        pdp_total += (student_record + i)->score.pdp;
        dl_total += (student_record + i)->score.dl;
        ds_total += (student_record + i)->score.ds;
    }
    ics_aver = ics_total / num ;
    pdp_aver = pdp_total / num ;
    ds_aver = ds_total / num;
    dl_aver = dl_total /num;
    printf("ICS average: %f\n", ics_aver);
    printf("PDP average: %f\n", pdp_aver);
    printf("DL average: %f\n", dl_aver);
    printf("DS average: %f\n", ds_aver);
}

void SortCourseScore(STU* student_record, int num){
    if(num == 0 && student_record->total == 0){
        printf("[ERROR] Please run function 6 to compute total and average score of each person\n");
        return;
    }
    int (*compare)(ElemType* a, ElemType* b);
    compare = &cmp;
    /* HeapSort(student_record, num, compare); */
    MergeSort(student_record, 0, num - 1, compare);
    printf("[INFO] Sort complete\n");

}

void SaveRecord(STU* student_record, int num){
    printf("[INFO] Starting saving record to file\n");
    printf("1. text file   2. binary file\n");
    printf("Please choose: ");
    int choose;
    scanf("%d", &choose);
    switch(choose) {
    case 1: 
        WriteTxtFile(student_record, "./student_record.txt", num);
        break;
    case 2:
        WriteBinaryFile(student_record, "./student_record.dat", num);
        break;
    }
    

}

void LoadRecord(STU* student_record, int* num){
    printf("[INFO] Starting loading from file\n");
    printf("1. text file   2. binary file\n");
    printf("Please choose: ");
    int choose;
    scanf("%d", &choose);
    printf("Please input file address: ");
    char address[50];
    scanf("%s", address);
    switch(choose) {
    case 1: 
        (*num) += ReadTxtFile(student_record + (*num), address);
        break;
    case 2:
        (*num) += ReadBinaryFile(student_record + (*num),address);
        break;
    }
    
}

void StatisticAnalysis(STU* student_record, int num){
    printf("[INFO] Starting statistic analysis\n");

    int data[4][5];
    memset(data, 0, sizeof(int) * 5 *4);
    
    printf("             90~100   80~89    70~79    60~69    0~59\n");
    for(int i = 0; i < num; i++) {
        if ((student_record + i)->score.ics >= 90 &&
            (student_record + i)->score.ics <= 100){
            data[0][0] ++;
        }
        else if ((student_record + i)->score.ics >=80 &&
            (student_record + i)->score.ics < 90){
            data[0][1] ++;
        }
        else if ((student_record + i)->score.ics >= 70 &&
            (student_record + i)->score.ics < 80){
            data[0][2] ++;
        }
        else if ((student_record + i)->score.ics >= 60 &&
            (student_record + i)->score.ics < 70){
            data[0][3] ++;
        }
        if ((student_record + i)->score.ics >= 0 &&
            (student_record + i)->score.ics < 60){
            data[0][4] ++;
        }


        if ((student_record + i)->score.pdp >= 90 &&
            (student_record + i)->score.pdp <= 100){
            data[1][0] ++;
        }
        else if ((student_record + i)->score.pdp >=80 &&
            (student_record + i)->score.pdp < 90){
            data[1][1] ++;
        }
        else if ((student_record + i)->score.pdp >= 70 &&
            (student_record + i)->score.pdp < 80){
            data[1][2] ++;
        }
        else if ((student_record + i)->score.pdp >= 60 &&
            (student_record + i)->score.pdp < 70){
            data[1][3] ++;
        }
        if ((student_record + i)->score.pdp >= 0 &&
            (student_record + i)->score.pdp < 60){
            data[1][4] ++;
        }


        if ((student_record + i)->score.dl >= 90 &&
            (student_record + i)->score.dl <= 100){
            data[2][0] ++;
        }
        else if ((student_record + i)->score.dl >=80 &&
            (student_record + i)->score.dl < 90){
            data[2][1] ++;
        }
        else if ((student_record + i)->score.dl >= 70 &&
            (student_record + i)->score.dl < 80){
            data[2][2] ++;
        }
        else if ((student_record + i)->score.dl >= 60 &&
            (student_record + i)->score.dl < 70){
            data[2][3] ++;
        }
        if ((student_record + i)->score.dl >= 0 &&
            (student_record + i)->score.dl < 60){
            data[2][4] ++;
        }


        if ((student_record + i)->score.ds >= 90 &&
            (student_record + i)->score.ds <= 100){
            data[3][0] ++;
        }
        else if ((student_record + i)->score.ds >=80 &&
            (student_record + i)->score.ds < 90){
            data[3][1] ++;
        }
        else if ((student_record + i)->score.ds >= 70 &&
            (student_record + i)->score.ds < 80){
            data[3][2] ++;
        }
        else if ((student_record + i)->score.ds >= 60 &&
            (student_record + i)->score.ds < 70){
            data[3][3] ++;
        }
        if ((student_record + i)->score.ds >= 0 &&
            (student_record + i)->score.ds < 60){
            data[3][4] ++;
        }
    }
    printf("%-12s %-8d %-8d %-8d %-8d %-8d\n", "ICS", data[0][0], data[0][1], data[0][2], data[0][3], data[0][4]);
    printf("%-12s %-8d %-8d %-8d %-8d %-8d\n", "PDP", data[1][0], data[1][1], data[1][2], data[1][3], data[1][4]);
    printf("%-12s %-8d %-8d %-8d %-8d %-8d\n", "DL", data[2][0], data[2][1], data[2][2], data[2][3], data[2][4]);
    printf("%-12s %-8d %-8d %-8d %-8d %-8d\n", "DS", data[3][0], data[3][1], data[3][2], data[2][3], data[3][4]);
    
    
    
    

}

int cmp(ElemType * a, ElemType *b)
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
