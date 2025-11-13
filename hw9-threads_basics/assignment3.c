#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// A struct to hold the arguments for the thread
typedef struct {
    int thread_id;
} thread_data_t;

void* print_thread_info(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    printf("Thread ID: %d\n",data->thread_id);
    for(int i = 0; i<5; i++){
        printf("%d ", i+1);
    }
    printf("\n");
    return NULL;
}


int main() {

    pthread_t thread1, thread2;
    thread_data_t thread1_data, thread2_data;

    thread1_data.thread_id = 1;
    thread2_data.thread_id = 2;



    if (pthread_create(&thread1, NULL, print_thread_info, (void*)&thread1_data) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    if (pthread_create(&thread2, NULL, print_thread_info, (void*)&thread2_data) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // wait for 2 threads to finish
    if (pthread_join(thread1, NULL) != 0) {
        perror("Failed to join thread 1");
        return 1;
    }

    if (pthread_join(thread2, NULL) != 0) {
        perror("Failed to join thread 2");
        return 1;
    }

}