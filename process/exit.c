#include <stdio.h>
#include <stdlib.h>

void fa()
{
	printf("fa is called\n");
}

int main()
{
	atexit(fa);
	printf("begin\n");
	//exit(0);
	//_Exit(0);
	printf("end\n");

	return -1;
}
