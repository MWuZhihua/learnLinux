#include <stdio.h>
#include <signal.h>

int main()
{
	printf("size = %d\n" , sizeof(sigset_t));

	sigset_t set;
	printf("set %d\n" ,set);
	sigemptyset(&set);
	printf("set %d\n" , set);

	sigaddset(&set, 2);printf("set %d\n" , set);
	sigaddset(&set, 3);printf("set %d\n" , set);
	sigaddset(&set, 7);printf("set %d\n" , set);
	sigdelset(&set, 3);printf("set %d\n" , set);
	sigdelset(&set, 2);printf("set %d\n" , set);
	if (sigismember(&set , 7))
	{
		printf("xinhao zai \n");
	}
}
