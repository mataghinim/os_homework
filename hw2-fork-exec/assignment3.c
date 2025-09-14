#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int ret = fork();

    if (ret == 0) {                           // child process
        execl("/bin/echo", "echo", "Hello from the child process", (char *)NULL);
        perror("execl echo");                      // only if execl fails

    } else {                                  // parent process
        sleep(5);                           // ensures child finishes
        printf("Parent process done:%d\n", ret);
    }
    return 0;
}
