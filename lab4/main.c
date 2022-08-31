#include "sort.h"
#include "fileop.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "struct.h"

#define MAX_STUDENT_NUM 45

int main(int argc, char *argv[]){
    int input = 0;
    int num = 0;
    STU *students_record = (STU*) malloc(sizeof(STU) * MAX_STUDENT_NUM);
    memset(students_record, 0, sizeof(STU) * MAX_STUDENT_NUM);
    
    while(1) {
        menu();
        scanf("%d", &input);
        switch(input) {
        default:
            printf("[Error] Please input correct function number\n");
            continue;
        
        case 0:
            printf("GoodBye\n");
            exit(0);

        case 1:
            AppendRecord(students_record, &num);
            break;

        case 2:
            SearchByName(students_record, num);
            break;

        case 3:
            SearchByID(students_record, num);
            break;

        case 4:
            ModifyByID(students_record, num);
            break;

        case 5:
            DeleteByID(students_record, &num);
            break;

        case 6:
            CalcStudents(students_record, num);
            break;

        case 7:
            CalcCourse(students_record, num);
            break;

        case 8:
            SortCourseScore(students_record, num);
            break;

        case 9:
            StatisticAnalysis(students_record, num);
            break;

        case 10:
            SaveRecord(students_record, num);
            break;

        case 11:
            LoadRecord(students_record, &num);
            break;
        }
        
        printf("\n\n");
    }
    
    free(students_record);
    return 0;
}
