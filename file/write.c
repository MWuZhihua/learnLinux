#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd = open("write.txt" , O_WRONLY | O_CREAT | O_TRUNC,0666 );

	if (fd == -1)
	{
		perror("open");
		return -1;
	}

	const char* text = "hello world";
	printf("写入内容：%s\n", text);
	size_t towrite = strlen(text) * sizeof(text[0]);

	ssize_t written = write(fd , text , towrite);

	if (written == -1)
	{
		perror("write");
		return -1;
	}

	printf("期望写入%d字节，"
			"实际写入%d字节" , towrite , written);
	close(fd);	
}
