#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>


int main(int argc , char* argv[])
{

	if (argc < 3)
	{
		printf("用法：%s <源文件> <目标文件>\n" , argv[0]);

		return -1;
	}

	int src = open(argv[1] , O_RDONLY );

	if (src == -1)
	{
		perror("open");

		return -1;
	}

	struct stat st;
	if (fstat(src , &st) == -1)
	{
		perror("fstat");

		return -1;
	}


	int dst = open(argv[2] , O_WRONLY | O_CREAT | O_EXCL , st.st_mode );
	if(dst == -1)
	{
		if (errno!= EEXIST)
		{
			perror("write");
			return -1;
		}
		printf("文件%s已经存在 , 是否覆盖？(y/n)\n" , argv[2]);
		int ch = getchar();

		if (ch != 'y' && ch != 'Y')
			return 0;

		dst = open(argv[2] , O_WRONLY | O_CREAT | O_TRUNC , st.st_mode);

		if (dst == -1)
		{
			perror("open");
			return -1;
		}
	}

	char buf[1024];
	
	ssize_t bytes;
	while((bytes = read (src , buf , sizeof(buf))) > 0)
	{
		if(write(dst , buf , bytes) == -1)
		{
			perror("write");
			return -1;
		}
	}
	
	if (bytes == -1)
	{
		perror("read");
		return -1;
	}

	close(dst);
	close(src);

	return 0;
}
