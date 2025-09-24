#include <stdio.h>
int main(){
    char str[] = "Hello";
    char *ptr = &str[0];

    int len = 0;

    for (int i = 0; *(ptr + i) != '\0'; i++){
        len++;
    }

    for (int j = 0; j <len ; j++)
        printf("%c", *(ptr + j));
    return 0;
}