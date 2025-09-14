#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int ret = fork();

    if (ret == 0) {                           // child process
        execlp("grep", "grep", "main", "test.txt", (char *)NULL);
        perror("execl grep");                      // only if execlp fails
        
    } else {                                  // parent process
        sleep(5);                           // ensures child finishes
        printf("Parent process done:%d\n", ret);
    }
        
    return 0;
}
