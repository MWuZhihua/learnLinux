#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo)
{
	printf("pid = %d 捕获信号 %d\n" , getpid() , signo);
}

int main()
{
	pid_t pid = fork();

	if (pid == 0)
	{
		signal(SIGINT , fa);
		while(1);
	}

	printf("pid %d 给子进程发信号\n" , getpid());
	kill(pid , SIGINT);
	//return -1;
}
