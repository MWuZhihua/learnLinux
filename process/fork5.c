#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("%d\n" , getpid());
	pid_t pid = fork();

	if (pid == 0)
	{
		printf("parent: pid = %d\n" , getppid());
		sleep(2);
		printf("parent: pid = %d\n" , getppid());
		exit(0);
	}

	sleep(1);
	return -1;
}
