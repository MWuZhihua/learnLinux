#include <stdio.h>
#include <unistd.h>

int main()
{
	void* p1 = sbrk(4);
	void* p2 = sbrk(4);
	void* p3 = sbrk(4);
	int* p4 = sbrk(4);

	printf("p1=%p , p2=%p , p3=%p , p4=%p\n" , p1 , p2 , p3 , p4);
	
	*p4 = 100;
	sbrk(-4);
	sbrk(-8);

	void* p5 = sbrk(0);
	printf("p5 = %p\n" , p5);
	
	printf("*p4 = %d\n", *p4);//还能得到100,数据没有被清理

	sbrk(4093);//正好超过一页  立即分配2页
	sbrk(-1);//立即释放内存并解除映射（退页）
	sbrk(-4096);//释放内存解除映射
	printf("pid = %d\n" , getpid());
	while(1);
	return 0;
}
