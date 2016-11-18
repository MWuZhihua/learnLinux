#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

//加解读锁
int rlock(int fd , off_t start , off_t len , int wait , int bLock)
{
	struct flock lock;
	lock.l_type = bLock ? F_RDLCK : F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = start;
	lock.l_len = len;
	lock.l_pid = -1;

	return fcntl(fd , wait ? F_SETLKW : F_SETLK , &lock);
}

int main()
{
	int fd = open("lock.txt" , O_RDONLY);

	if (fd == -1)
	{
		perror("open");
		return -1;
	}

	if (rlock(fd , 0 , 0, 1, 1) == -1)
	{
		perror("rlock");
		return -1;
	}

	char buf[1024];
	ssize_t readded;
	while((readded = read(fd , buf , sizeof(buf))) > 0)
	{
		write(STDOUT_FILENO , buf , readded);
		printf("\n");
	}

	if (readded == -1)
	{
		perror("read");
		return -1;
	}

	if (rlock(fd , 0 , 0 , 0 , 0) == -1)
	{
		perror("ulock");
		return -1;
	}
	close(fd);
}
