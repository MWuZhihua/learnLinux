#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	struct stat st;
	int res = stat("./stat.c" , &st);
	if (res == -1) perror("stat") , exit(-1);

	printf("size = %d\n" , st.st_size);
	printf("inode = %d\n" , st.st_ino);
	printf("links = %d\n" , st.st_nlink);
	printf("mode = %o\n" , st.st_mode);
	printf("%s\n" , ctime(&st.st_mtime));
	if (S_ISDIR(st.st_mode)) printf("是目录\n");
	if (S_ISREG(st.st_mode)) printf("是文件\n");
	printf("权限：%o\n" , st.st_mode&07777);
	return -1;
}
