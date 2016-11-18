#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd = open("a.pipe" , O_RDWR);
	if (fd == -1) perror("open") , exit(-1);

	int i;
	for (i = 0; i< 100;i++)
	{
		int x;
		read(fd , &x , sizeof(x));
		printf("%d \n" , x);
	}

	close(fd);
}
