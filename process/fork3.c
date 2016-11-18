#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int i1 = 10;

int main()
{
	int i2 = 10;
	char* str = malloc(10);

	strcpy(str , "abcd");

	pid_t pid = fork();

	int i3 = 10;

	if (pid == 0)
	{
		i1 = 20;
		i2 = 20;
		i3 = 20;

		str[0] = '1';
		printf("i1 = %d , i2 = %d , i3 = %d , str = %s\n" ,
				i1 ,i2 , i3 , str);
		printf("i1 = %p , i2 = %p , i3 = %p , str = %p\n",
				&i1 , &i2 , &i3 , str);
		exit(0);	
	}

	sleep(1);
	printf("i1 = %d , i2 = %d , i3 = %d , str = %s\n " ,
			i2 , i2, i3 , str);
	printf("i1 = %p , i2 = %p , i3 = %p , str = %p\n",
			&i1 , &i2 , &i3 , str);

	return -1;
}
