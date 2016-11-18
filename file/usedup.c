#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd  = open("usedup.log" , O_WRONLY | O_CREAT | O_TRUNC , 0666);

	printf("版本 1.0\n");

	//close(STDOUT_FILENO);
	//dup(fd);

	dup2(fd , STDOUT_FILENO);

	printf("内存分配错误\n");
	printf("....错误\n");

	return -1;
}
