#include <stdio.h>
#include <string.h>

int main()
{

	extern char** environ;
	char** p = environ;
	
	while(*p != NULL)
	{
		printf("%s\n" , *p);
		p++;
	}

	char** l = environ;

	char value[100] = {};
	while(*l)
	{
		if (strncmp("LANG=", *l , 5) == 0)
		{
			strcpy(value , *l + 5);
			break;
		}

		l++;
	}

	printf("%s\n" ,value );
	
	return 0;
}
