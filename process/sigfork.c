#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获了信号%d\n" , signo);
}

int main()
{
	if (signal(SIGINT , fa) == SIG_ERR)
	{
		perror("signal 2");
		exit(1);
	}

	pid_t pid = fork();

	if (pid  == 0)
	{
		printf("child %d \n" , getpid());
		while(1);
	}

	printf("parent\n");
	return -1;
}
