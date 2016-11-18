#include <stdio.h>
#include <stdlib.h>

int i1 = 10;//全局
static int i2 = 20;//全局
int i3;//bbs段
const int i4 = 40;//只读常量区

void fa(int i5 )/*区*/
{
	int i6;//栈区
	static int i7 = 70;//全局
	const int i8 = 80;//栈区
	int* pi = malloc(4);//堆区
	char* s1 = "abc";//只读常量区
	char s2[] = "abc";//栈（数据只读区复制）
	printf("i5 = %p\n",&i5);
	printf("i6 = %p\n",&i6);
	printf("i7 = %p\n",&i7);
	printf("i8 = %p\n",&i8);
	printf("pi = %p\n",&pi);
	printf("s1 = %p\n",&s1);
	printf("s2 = %p\n",&s2);

}

int main()
{

	printf("pid = %d\n", getpid());
	printf("i1 = %p\n",&i1);
	printf("i2 = %p\n",&i2);
	printf("i3 = %p\n",&i3);
	printf("i4 = %p\n",&i4);
	
	printf("fa = %p\n",fa);
	fa(5);

	return 0;
}
