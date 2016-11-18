#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void fa(int signo)
{
	printf("捕获信号%d\n" , signo);
}

int main()
{
	signal(SIGINT , fa);
	printf("begin\n");
	int res = sleep(10);
	printf("res = %d\n" , res);
	printf("end\n");
}
