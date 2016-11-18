#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int fa(int signo)
{
	printf("捕获%d\n" , signo);
}

int main()
{
	signal(SIGALRM , fa);
	alarm(5);
	while(1);
}
