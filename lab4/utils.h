#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <string.h>
#include "struct.h"
#include "fileop.h"



void menu();

void AppendRecord(STU* student_record, int* num);

void SearchByName(STU* student_record, int num);

void SearchByID(STU* student_record, int num);

void ModifyByID(STU* student_record, int num);

void DeleteByID(STU* student_record, int* num);

void CalcStudents(STU* student_record, int num);

void CalcCourse(STU* student_record, int num);

void SortCourseScore(STU* student_record, int num);

void SaveRecord(STU* student_record, int num);

void LoadRecord(STU* student_record, int* num);

void StatisticAnalysis(STU* student_record, int num);

int cmp(ElemType* a, ElemType *b);

#endif
