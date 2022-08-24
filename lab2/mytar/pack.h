#ifndef PACK_H
#define PACK_H
#define MAX_NAME_LEN 32

#include <stdio.h>

typedef struct file {
    char name[MAX_NAME_LEN];
    /* _fsize_t size; */
    int bol; // seperating file and folder
} file;

typedef struct folder_info {
    char name[MAX_NAME_LEN];
    int begin;
    int end;
    long int offset;
    struct folder_info *next;

} folder;  // 存储相对于文件开头的偏移量

void show_help();

int pack_file(char* folder_path, char* package_path);

int extract_file(char* package_path, char* folder_path);

int show_file(char* folder_path);

#endif
