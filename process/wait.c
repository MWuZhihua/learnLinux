#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("pid = %d\n" , getpid());
	pid_t pid = fork();

	if (pid == 0)
	{
		printf("child pid = %d\n" , getpid());
		sleep(1);
		printf("child over\n");
		exit(10);
	}

	int status;

	pid_t wpid = wait(&status);

	printf("father go on\n");
	printf("over child pid = %d\n" , wpid);

	if (WIFEXITED(status))
	{
		printf("是正常结束 , status code = %d\n" , WEXITSTATUS(status));
	}
	return -1;
}
