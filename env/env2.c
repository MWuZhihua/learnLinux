#include <stdio.h>
#include <stdlib.h>

int main(int argc , int** argv , char** env)
{
	extern char** environ;

	printf("%p , %p \n" , env , environ);

	char* value = getenv("LANG");
	printf("value=%s\n" , value);

	return 0;
}
