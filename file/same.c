#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd1 = open("same.txt" , O_RDWR | O_CREAT | O_TRUNC , 0666);

	if (fd1 == -1)
	{
		return -1;
	}

	printf("fd1 = %d \n" , fd1);

	int fd2 = open("same.txt" , O_WRONLY);

	if (fd2 == -1)
	{
		perror("open");
		return -1;
	}

	printf("fd2 = %d\n" ,fd2) ;

	const char* text = "Hello, World !";
	if (write(fd1 , text , strlen(text) * sizeof(text[0])) == -1)
	{
		perror("write");
		return -1;
	}

	if (lseek (fd1 , -7 , SEEK_CUR) == -1)
	{
		perror("lseek");
		return -1;
	}

	text = "Linux";
	if (write(fd2 , text , strlen(text) * sizeof(text[0])) == -1)
	{
		perror("write");
		return -1;
	}

	close(fd1);
	close(fd2);
	


	return -1;
}

