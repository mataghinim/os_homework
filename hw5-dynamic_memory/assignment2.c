#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n, sum = 0;
    double avg = 0.0;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("You should have typed a positive number\n");
        return 1;
    }

    int *ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL) {
        printf("Memory is not available\n");
        return 1;
    }
    printf("Array after calloc:\n");
    for (i = 0; i < n; i++){
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++){
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    avg = (double) sum/n;
    printf("Updated array:\n");
    for (i = 0; i < n; i++){
        printf("%d ", *(ptr + i));
    }

    printf("\n");
    printf("Average of the array: %f\n", avg);

    free(ptr);
}