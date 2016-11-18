#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
	printf("begin\n");
	int res = execl("/bin/ls","ls","-l" , NULL);
	printf("end\n");
	return -1;
}
