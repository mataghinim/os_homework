#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    int ret = fork();

    if (ret == 0) {                 // child
        printf("Child ret=%d\n", getpid());
        _exit(0);
    }
    
    printf("Parent ret=%d (not waiting)\n", getpid());
    return 0;                       // parent exits without wait()

    // MODIFIED VERSION WOULD BE
    // int status;
    // waitpid(ret, &status, 0);       // no zombie
    // printf("Parent proccess is here, after child %d, exit=%d\n", (int)ret, WEXITSTATUS(status));
}
