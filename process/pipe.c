#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd = open("a.pipe" , O_WRONLY);
	if (fd == -1) perror("open") , exit(-1);

	int i;
	for (i = 0; i< 100;i++)
	{
		write(fd , &i , sizeof(i));
		//usleep(100000);
	}

	close(fd);
}
