#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid1 = fork();
	pid_t pid2;
	if (pid1 > 0)
	{
		pid2 = fork();
	}
	
	if(pid1 == 0)
	{
		printf("pid1 = %d\n" , getpid());
		sleep(1);
		printf("pid1 over\n");
		exit(10);
	}

	if (pid2 == 0)
	{
		printf("pid2 = %d\n" , getpid());
		sleep(3);
		printf("pid2 over\n");
		exit(20);
	}
	
	int stat;
	pid_t wpid = waitpid( /*-1*/ pid2 , &stat , 0 /*WNOHANG*/);
	printf("father over\n");
	printf("wpid = %d\n" , wpid);
	
	//printf("end\n");
	return -1;
}
