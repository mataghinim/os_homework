#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
   for (int i = 0; i < 2; i++) {
        int ret = fork();

        if (ret == 0) {      
            if (i == 0){         // child process 1
                execl("/bin/ls", "ls", (char *)NULL);
                perror("execl ls");                      
            }
            else{               // child process 2
                execl("/bin/date", "date", (char *)NULL); 
                perror("execl date");
            }

        }
    }

    sleep(5);                           // ensures children finish
    printf("Parent process done \n");        // parent process
    
    return 0;
}
