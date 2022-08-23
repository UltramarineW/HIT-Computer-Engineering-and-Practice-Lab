#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
    char name[30];
    char num[30];

    printf("Please enter your name:\n");
    gets(name);
    printf("Please enter your scholar number:\n");
    gets(num);
    
    printf("hello %s - %s\n", name, num);

    return 0;
}
