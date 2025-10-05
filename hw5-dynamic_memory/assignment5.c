#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n;

    printf("Enter the number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("You should have typed a positive number\n");
        return 1;
    }

    int *ptr = (int *) malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory is not available\n");
        return 1;
    }

    printf("Enter the grades: ");
    int highest = 0, lowest = 0;
    for (i = 0; i < n; i++){
        scanf("%d", ptr + i);
        if (i == 0) {
            highest = lowest = *(ptr + i);
        } else {
            if (*(ptr + i) > highest) highest = *(ptr + i);
            if (*(ptr + i) < lowest)  lowest  = *(ptr + i);
        }
    }

    printf("Highest grade: %d\n", highest);
    printf("Lowest grade: %d\n", lowest);

    free(ptr);
    return 0;
}
