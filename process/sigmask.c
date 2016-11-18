#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int fa(int signo)
{
	printf("捕获了信号 %d\n" , signo);
}

int main()
{

	signal(SIGINT ,fa);// 不可靠信号 屏蔽时丢失
	signal(50 , fa);//可靠信号 屏蔽时不丢失
	printf("pid = %d\n" , getpid());
	printf("执行普通程序，不屏蔽信号\n");
	sleep(20);
	printf("执行关键代码 ,开始屏蔽信号\n");
	sigset_t new ,old;
	sigemptyset(&new);
	sigaddset(&new , 2);
	sigaddset(&new , 50);
	sigprocmask(SIG_SETMASK , &new , &old);
	sleep(15);
	printf("关键代码执行完毕，解除屏蔽\n");

	sigset_t pend;
	sigpending(&pend);
	if (sigismember(&pend , SIGINT))
	{
		printf("xinhao 2 laiguo\n");
	}

	sigprocmask(SIG_SETMASK, &old , NULL);


	//return -1;
}
