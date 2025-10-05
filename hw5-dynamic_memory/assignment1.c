#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n, sum = 0;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("You should have typed a positive number\n");
        return 1;
    }

    int *ptr = (int *) malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory is not available\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++){
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum of the array: %d\n", sum);

    free(ptr);
    return 0;
}
