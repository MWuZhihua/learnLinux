#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{

	FILE* file = fopen("/etc/passwd1","r");
	if (file == NULL)
	{
		printf("%s\n", strerror(errno));
		perror("fopen");
		printf("%m\n");
	}

	fclose(file);

	return 0;
}
