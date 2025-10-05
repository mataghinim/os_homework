
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 3;

    char **ptr_str = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        *(ptr_str + i) = (char *)malloc(51 * sizeof(char));
    }

    printf("Enter 3 strings: ");
    for (int i = 0; i < n; i++) {
        scanf("%50s", *(ptr_str + i));
    }

    n = 5;
    char **tmp = (char **)realloc(ptr_str, n * sizeof(char *));
    ptr_str = tmp;

    for (int i = 3; i < n; i++) {
        *(ptr_str + i) = (char *)malloc(51 * sizeof(char));
    }

    printf("Enter 2 more strings: ");
    for (int i = 3; i < n; i++) {
        scanf("%50s", *(ptr_str + i));
    }

    printf("All strings: ");
    for (int i = 0; i < n; i++){
        printf("%s ", *(ptr_str + i));
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        free(*(ptr_str + i));
    }
    free(ptr_str);
    return 0;
}
