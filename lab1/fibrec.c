#include <stdio.h>

long long int fiblist[100];

long long int fib(int index) {
    if(fiblist[index] != 0) {
        return fiblist[index];
    }
    if (index == 1 || index == 2) {
        fiblist[index] = 1;
        return 1;
    }
    else{
        fiblist[index] =  fib(index - 1) + fib(index - 2);
        return fiblist[index];
    }
}

int main(int argc, char** argv) {
    for(int i = 0; i < 100; i++) {
        fiblist[i] = 0;
    }
    for(int i = 0; i < 90; i++) {
        printf("%lld\n", fib(i + 1));
    }
    return 0;
}
