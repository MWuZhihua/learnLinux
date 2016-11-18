#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

//加写锁 解锁
int wlock(int fd , off_t start , off_t len ,int wait , int bLock)
{
	struct flock lock;
	lock.l_type = bLock ? F_WRLCK : F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = start;
	lock.l_len = len;
	lock.l_pid = -1;

	return fcntl(fd , wait ? F_SETLKW : F_SETLK , &lock);
}

int main( int argc , char* argv[])
{
	if (argc < 2)
	{
		printf("用法：%s<字符串>\n" , argv[0]);
		return -1;
	}
	
	int fd  = open("lock.txt" , O_WRONLY | O_CREAT | O_APPEND , 0666);
	if (fd == -1)
	{
		perror("open");
		return -1;
	}
	
	if (wlock(fd , 0 , 0 , 1 , 1) == -1)
	{
		perror("wlock");
		return -1;
	}

	size_t i , len = strlen(argv[1]);
	for(i = 0; i < len; i++)
	{
		if (write(fd , &argv[1][i] , sizeof(argv[1][i])) == -1)
		{
			perror("write");
			return -1;
		}

		printf("%#x\n" , argv[1][i]);
		sleep(1);
	}

	if(wlock(fd , 0 , 0 ,0 , 0) == -1)
	{
		perror("wlock");
		return -1;
	}

	close(fd);
	
	return -1;
}
