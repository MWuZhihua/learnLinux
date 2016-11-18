#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	printf("新建普通文件，用默认的屏蔽字\n");
	int fd = open("a1.txt" , O_CREAT | O_RDWR , 0666);
	close(fd);
	printf("新建特殊文件，屏蔽两个写权限\n");
	mode_t old = umask(0022);
	fd = open("a2.txt" , O_CREAT | O_RDWR ,0666);
	close(fd);
	printf("新建普通文件，回复默认屏蔽字\n");

	umask(old);
	fd = open("a3.txt" , O_CREAT | O_RDWR , 0666);
	close(fd);
	return -1;
}
