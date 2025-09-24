#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdint.h>

int main() 
{ 
	int ret = fork();
	if (ret == 0)                     // child process
		printf("Child pid: %jd\n", (intmax_t)getpid()); 
	else                              // parent process
		printf("Parent id: %jd\n", (intmax_t)getppid());	

	return 0; 
} 
