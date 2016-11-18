#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{

	int fd1 = open("dup.txt" , O_RDWR | O_CREAT | O_TRUNC, 0666);

	if (fd1 == -1)
	{
		perror("open");
		return -1;
	}

	printf("fd1 = %d\n" , fd1);

	int fd2 = dup(fd1);
	if (fd2 == -1)
	{
		perror("dup");
		return -1;
	}
	printf("fd2 = %d\n" , fd2);

	int fd3 = dup2(fd2 , 100);
	printf("fd3 = %d\n" , fd3);

	const char* text = "hello, world! ";

	if (write(fd1 , text , strlen(text) * sizeof(text[0])) == -1)
	{
		perror("write");
		return -1;
	}

	if (lseek(fd2 , -7 , SEEK_CUR) == -1)
	{
		perror("lseek");
		return -1;
	}

	text = "Linux";

	if (write(fd3 , text , strlen(text) * sizeof(text[0])) == -1)
	{
		perror("write");
		return -1;
	}

	close(fd1);
	close(fd2);
	close(fd3);
	return -1;
}
