#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
void fa(int signo)
{
	printf("i am superman!\n");
}

int main()
{
	signal(SIGALRM , fa);

	struct itimerval timer;
	timer.it_interval.tv_sec = 1;//间隔秒数
	timer.it_interval.tv_usec = 100000;//间隔微妙
	timer.it_value.tv_sec = 5;//开始秒数
	timer.it_value.tv_usec = 0;//开始微秒

	setitimer(ITIMER_REAL , &timer , NULL);
	while(1);
}
