#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <inttypes.h>

int main() 
{ 
    int pids[2];
    for (int i = 0; i < 2; i++) {
        int ret = fork();

        if (ret == 0) {      
            if (i == 0){         // child process 1
                printf("Child1 pid: %jd\n", (intmax_t)getpid());    
                _exit(1);    //just a random number inside, to distinguish which child is it             
            }
            else{               // child process 2
                printf("Child2 id: %jd\n", (intmax_t)getpid());
                _exit(2);      //just a random number inside, to distinguish which child is it
            }

        }
        pids[i] = ret;
    }
    int status;
    int pid;

    pid = waitpid(pids[0], &status, 0);
    printf("child with pid %jd exited normally with exit code %d\n", (intmax_t)pid, WEXITSTATUS(status));

    pid = waitpid(pids[1], &status, 0);
    printf("child with pid %jd exited normally with exit code %d\n", (intmax_t)pid, WEXITSTATUS(status));


    return 0;
}
