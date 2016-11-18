#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid = vfork();

	if (pid == 0)
	{
		printf("child pid = %d\n" , getpid());

		execl("./pid" , "pid" , NULL);
		exit(0);
	}

	waitpid(pid , NULL , 0);
	return -1;
}
