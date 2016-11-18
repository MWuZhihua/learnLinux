#include <stdio.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获了信号%d\n" , signo);
}

int main()
{
	signal(SIGINT , fa);
	signal(SIGQUIT , SIG_IGN);
	signal(SIGKILL , fa);
	printf("pid = %d \n" , getpid());

	while(1);
	return -1;
}
