#include "pack.h"
#include <dirent.h>
#include <string.h>

void show_help(){
    printf("\nUsage: mytar [OPTION...] [FILE]...\n");
    printf("mytar collect all the files in the specified package\n");
    printf("\nExamples:");
    printf("\n\tmytar -c ./test-folder ./package.pkg");
    printf("\n\tmytar -x ./package.pkg ./result-folder");
    printf("\n\nMain operation mode:\n");
    printf("\n\t-c\t\tcreate a new package\n");
    printf("\t-x\t\textract files from package\n");
    printf("\t-l\t\tlist all files of target folder\n");
    return;
}

int pack_file(char* folder_path, char* package_path){
    printf("Packing file start!\n");
}

int extract_file(char* package_path, char* folder_path){

}

int show_file(char* folder_path){
    DIR* dir;
    char path_name[512];

    if ((dir = opendir(folder_path)) == 0) {
        printf("[Error] Open folder %s fail!\n", folder_path);
        return -1;
    }

    struct dirent *stdir;
    while((stdir = readdir(dir)) != NULL) {
        if(stdir->d_type == 8) {        //如果是文件
            printf("%s/%s\n", folder_path, stdir->d_name);
        }
        else  {     //如果是文件夹
            if (strcmp(stdir->d_name, "..") == 0 || strcmp(stdir->d_name, ".") == 0) {
                continue;
            }
            sprintf(path_name, "%s/%s", folder_path, stdir->d_name);
            show_file(path_name);
        }
    }

    closedir(dir);
    
    return 0;
}



