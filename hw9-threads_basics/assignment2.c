#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[8] = {3, 7, 2, 9, 5, 4, 8, 6};

typedef struct {
    int start;
    int end;
} Range;

void* sum(void* arg){
    Range* range = (Range*)arg;
    int sum = 0;
    for (int i = range->start; i < range->end+1; i++){
        sum += arr[i];
    }

    printf("Sum from %d to %d = %d\n", range->start, range->end, sum);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    Range r1 = {0, 3};
    Range r2 = {4, 7};

    pthread_create(&t1, NULL, sum, &r1);
    pthread_create(&t2, NULL, sum, &r2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}