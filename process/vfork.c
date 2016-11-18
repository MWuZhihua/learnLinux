#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

	pid_t pid = vfork();

	if (pid == 0)
	{
		//sleep(1);

		execl("/bin/pwd" , "pwd" , NULL);
		printf("child\n");

		exit(0);
	}

	printf("father\n");

	return 0;
}
