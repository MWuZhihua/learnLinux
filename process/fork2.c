#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("begin\n");
	pid_t pid = fork();

	if (pid == 0)
	{
		printf("2\n");
		printf("childpid = %d, parentpid = %d\n" , getpid() , getppid());
	}
	else
	{
		printf("1\n");
		printf("childpid = %d , ownpid = %d\n" , pid , getpid());
	}
}
