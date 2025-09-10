#include <stdio.h>

int main(){
    int x = 444;
    int *ptr = &x;

    printf("Address of x: %p\n", &x);
    printf("Address of x via pointer: %p\n", ptr);

    *ptr = 100;
    printf("New value of x: %d\n", x);
    return 0;

}