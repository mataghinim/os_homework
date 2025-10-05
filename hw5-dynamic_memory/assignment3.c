#include <stdio.h>
#include <stdlib.h>

int main(){

    int *ptr = (int *) malloc(10 * sizeof(int));

    printf("Enter 10 integers: ");
    for (int i = 0; i < 10; i++){
        scanf("%d", ptr + i);
    }
    printf("\n");
    printf("Array after resizing: ");
    
    ptr = realloc (ptr, 5 * sizeof (int));
    for (int i = 0; i < 5; i++){
        printf("%d ", *(ptr + i));
    }

    free(ptr);
    return 0;
}