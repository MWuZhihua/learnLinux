#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{

	int fd = open("seek.txt" , O_WRONLY | O_CREAT | O_TRUNC , 0666);

	if (fd == -1)
	{
		perror("open");
		return -1;
	}

	const char* text = "hello, world! ";
	if (write(fd , text , strlen(text) * sizeof(text[0])) == -1)
	{
		perror("wriet");
		return -1;
	}

	if (lseek(fd , -7 , SEEK_CUR) == -1)
	{
		perror("lseek");
		return -1;
	}

	off_t pos = lseek(fd , 0, SEEK_CUR);
	printf("dan qian wei zhi : %ld\n" , pos);

	text = "Linux";

	if (write(fd , text , strlen(text) * sizeof(text[0])) == -1)
	{
		perror("write");
		return -1;
	}

	if (lseek(fd  , 8 , SEEK_END)== -1)
	{
		perror("lseek");
		return -1;
	}

	text  = "这里有个洞！";

	if (write(fd , text , strlen(text) * sizeof(text[0])) == -1)
	{
		perror("write");
		return -1;
	}
	
	off_t size = lseek(fd , 0 , SEEK_END);
	if (size == -1)
	{
		perror("lseek");
		return -1;
	}
	printf("da xiao : %ld\n" , size);

	close(fd);

	return -1;
}
