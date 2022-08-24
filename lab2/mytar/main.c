#include "pack.h"
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 1 && ((strcmp(argv[0], "./mytar") == 0) || (strcmp(argv[0], "mytar") == 0))) {
        show_help();
    }
    if (argc == 3 && strcmp(argv[1], "-l") == 0){
        char* folder_path = argv[2];
        show_file(folder_path);
    }
    if (argc == 4 && (((strcmp(argv[1], "-c") == 0)) || (strcmp(argv[1], "0")))) {
        char* folder_path = argv[2];
        char* package_path = argv[3];
        pack_file(folder_path, package_path);
    }
    if (argc == 4 && (((strcmp(argv[1], "-x") ==0)) || (strcmp(argv[1], "1")))) {
        char* package_path = argv[2];
        char* folder_path = argv[3];
        extract_file(package_path, folder_path);
    }
    return 0;
}
