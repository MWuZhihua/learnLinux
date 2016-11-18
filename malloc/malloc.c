#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a , b , c;

	printf("a=%p , b =%p , c =%p\n" , &a ,&b ,&c);
	
	int* p1 = malloc(4);
	int* p2 = malloc(4);
	int* p3 = malloc(4);

	printf("p1 = %p,p2=%p,p3=%p,pid= %d\n", p1,p2,p3,getpid());

	while(1);
	return 0;
}
