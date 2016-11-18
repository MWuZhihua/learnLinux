#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

	int fd = open("sysio.dat" , O_WRONLY | O_CREAT | O_TRUNC ,
			0666);

	if (fd  == -1)
	{
		perror("open");
		return -1;
	}

	unsigned int i;
	for (i = 0; i < 100000; ++i)
	{
		write(fd , &i , sizeof(i));
	}

	close(fd);

	return 0;
}

