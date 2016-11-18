#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{

	int fd1 = open("dup1.txt" , O_WRONLY | O_CREAT | O_TRUNC , 0666);
	if (fd1 == -1)
	{
		perror("open");
		return -1;
	}

	printf("fd1 = %d \n" , fd1);
	int fd2 = open("dup2.txt" , O_WRONLY | O_CREAT | O_TRUNC ,0666);
	if (fd2 == -1)
	{
		perror("open");
		return -1;
	}

	printf("fd2 = %d \n ", fd2);
	
	/*int fd3 = dup2(fd1 , fd2);
	if (fd3 == -1)
	{
		perror("dup2");
		return -1;
	}*/

	int fd3 = fcntl(fd1 , F_DUPFD , fd2);
	if (fd3 == -1)
	{
		perror("fcntl");
		return -1;
	}

	printf("fd3 = %d\n" , fd3);
	const char* text = "123";
	if (write( fd1 , text , strlen(text) * sizeof(text[0])) == -1)
	{
		perror("write");
		return -1;
	}

	text = "456";

	if (write(fd2 , text , strlen(text) * sizeof(text[0])) == -1)
	{
		perror("write");
		return -1;
	}

	text = "789";

	if (write(fd3 , text , strlen(text)* sizeof(text[0])) == -1)
	{
		perror("write");
		return -1;
	}

	close(fd3);
	close(fd2);
	close(fd1);



	return -1;
}
