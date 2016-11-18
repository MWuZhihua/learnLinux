#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	void* p = sbrk(0);
	brk(p+4);//分配了4字节
	brk(p+8);//重新分配4字节
	brk(p+4);//回收了4个字节

	int* pi = p;//放入 int/double/char*
	*pi = 100;
	double* pd = sbrk(0);
	brk(pd + 1);
	*pd = 12000.0;
	char* pc = sbrk(0);
	brk(pc + 10);
	// pc = "zhangfei";//堆指向了只读区 ，内存泄露
	strcpy(pc , "zhangfei");
	printf("%d,%.1lf,%s\n",*pi , *pd , pc);
	brk(pc);
	brk(pd);
	brk(pi);
	return 0;
}
