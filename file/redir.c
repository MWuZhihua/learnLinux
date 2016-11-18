#include <stdio.h>

int main()
{
	int i;
	fscanf(stdin , "%d" , &i);
	fprintf(stdout , "标准输出：%d\n", i);
	fprintf(stderr , "标准出错：%d\n", i);
	return 0;
}
