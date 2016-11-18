#include <stdio.h>
#include <unistd.h>
int main()
{

	FILE* fp = fopen("sysio.dat", "wb");

	if (!fp)
	{
		error("open");
		return -1;
	}

	unsigned int i;
	for (i = 0; i < 100000; ++i)
	{
		fwrite(&i , sizeof(i) , 1 , fp);
	}

	fclose(fp);

	return 0;
}

