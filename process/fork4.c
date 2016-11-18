#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>



int main()
{
	pid_t pid = fork();
	int fd = open("a.txt" , O_RDWR | O_CREAT ,0666);
	if (fd == -1) perror("open") , exit(-1);


	if (pid == 0)
	{
		printf("child : fd = %d\n" , fd);
		write(fd , "abc" , 3);
		close(fd);
		exit(0);
	}

	printf("father : fd = %d\n" , fd);
	write(fd , "123" , 3);
	close(fd);
	return -1;
}
