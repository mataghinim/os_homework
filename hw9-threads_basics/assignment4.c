#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[5] = {1, 2, 3, 4, 5};

typedef struct {
    int *arr;
    int i;
} Arr_info;

void* square(void* arg) {
    Arr_info* info = (Arr_info*)arg;
    int value = info->arr[info->i];
    printf("Square of %d is %d\n", value, value * value);
    return NULL;
}

int main() {
    pthread_t threads[5];
    Arr_info args[5];

    for (int i = 0; i < 5; i++) {
        args[i].arr = arr;
        args[i].i = i;
        pthread_create(&threads[i], NULL, square, &args[i]);
    }

    for (int i = 0; i < 5; i++)
        pthread_join(threads[i], NULL);

    return 0;
}

//more elegant solution

// int arr[5] = {1, 2, 3, 4, 5};

// void* square(void* arg) {
//     int num = *(int*)arg;
//     printf("Square of %d is %d\n", num, num * num);
//     return NULL;
// }

// int main() {
//     pthread_t threads[5];

//     for (int i = 0; i < 5; i++)
//         pthread_create(&threads[i], NULL, square, &arr[i]);

//     for (int i = 0; i < 5; i++)
//         pthread_join(threads[i], NULL);

//     return 0;
// }

