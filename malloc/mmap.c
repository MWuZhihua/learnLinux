#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

int main()
{

	void* p = mmap(0,//首地址由内核指定
			4,//映射内存的大小，不足一页会补足一页
			PROT_READ|PROT_WRITE,//权限，一般读写
			MAP_ANONYMOUS | //映射物理内存必须用
			MAP_PRIVATE,//MAP_SHARED 用于文件映射，
			//MAP_PRIVATE 物理内存映射和文件映射都可以
			0,0);//最后两个参数用于文件映射
	if(p == MAP_FAILED)
	{
		perror("mmap");
		return -1;
	}

	int* pi = p;
	*pi = 100;
	
	munmap(p , 4);
	
	return 0;
}
