#include <stdio.h>

int main(int argc, char** argv) {
    int i = 0;
    long long int a = 1, b = 1, c = 1; 

    printf("%lld\n", a);
    printf("%lld\n", b);
    
    for (i = 2; i < 90; i++){
        c = a + b;
        a = b;
        b = c;

        printf("%lld\n", c);
    }
    return 0;
}
