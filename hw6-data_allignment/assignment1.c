#include<stdio.h>
int main(){
        int a;
        char b;
        double c;
        short d;

//sizes
        printf("size of int: %zu\n", sizeof a);
        printf("size of char: %zu\n", sizeof b);
        printf("size of double: %zu\n", sizeof c);
        printf("size of short: %zu\n", sizeof d);
//addresses
        printf("addr of int:    %p\n", &a);
        printf("addr of char:   %p\n", &b);
        printf("addr of double: %p\n", &c);
        printf("addr of short:  %p\n", &d);

        return 0;
}