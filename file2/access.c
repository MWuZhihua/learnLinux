#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
	if (!access("stat.c" , R_OK)) printf("can read\n");

	if (!access("stat.c" , W_OK)) printf("can write\n");

	if (!access("stat.c" , X_OK)) printf("can execute\n");

	if (!access("stat.c" , F_OK)) printf("文件存在\n");

	chmod("a.txt" , 0666);
	truncate("a.txt" , 100);
	return -1;
}
