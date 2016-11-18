#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("%d\n" , stdin->_fileno);
	printf("%d\n" , stdout->_fileno);
	printf("%d\n" , stderr->_fileno);
	FILE* fp = fopen("a.out" ,"r");
	printf("%d\n" , fp->_fileno);
	fclose(fp);
	FILE* fp2 = fopen("a.out" ,"r");
	printf("%d\n" , fp2->_fileno);
	fclose(fp2);
	printf("%ld\n" , sysconf(_SC_OPEN_MAX));
	fclose(stdout);
	printf("hello world\n");

	return 0;
}
