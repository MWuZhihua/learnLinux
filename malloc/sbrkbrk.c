#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{

	int* a = sbrk(4);
	double* b = sbrk(8);
	char* c = sbrk(10);

	*a = 10;
	*b = 12000.0;
	strcpy(c , "zhangfei");
	
	printf("%d , %.1lf , %s\n" , *a , *b , c);

	brk(a);
	//brk(b);
	//brk(c);

	return 0;
}
