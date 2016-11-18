#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("begin\n");

	pid_t pid = fork();

	printf("pid = %d\n" , pid);
	printf("end\n");
	return -1;
}
