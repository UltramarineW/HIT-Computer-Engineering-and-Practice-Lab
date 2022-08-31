#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct course
{
	float ics;
	float pdp;
	float ds;
	float dl;
}COURSE;

typedef struct student
{
	unsigned long   stu_id;//或char id[32];
	char stu_name[32];
    float total;
    float average;
	COURSE  score;
}STU;

typedef STU ElemType;

#endif
