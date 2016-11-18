#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

struct emp 
{
	int id;
	char name[20];
	double sal;
};

int main()
{
	int fd = open("em.dat" , O_CREAT |O_RDWR | O_TRUNC ,0666);
	if (fd == -1) perror("open") , exit(-1);

	ftruncate(fd , sizeof(struct emp) * 3);
	void* p = mmap(0,sizeof(struct emp)*3,
			PROT_READ | PROT_WRITE , MAP_SHARED,//MAP_PRIVATE  其他进程看不到数据
			fd , 0);
	if (p == (void*)-1) perror("mmap") , exit(-1);
	struct emp* pe = p;
	pe[0].id = 100;
	strcpy(pe[0].name , "liubei");
	pe[0].sal = 30000.0;
	
	pe[1].id = 200;
	strcpy(pe[1].name , "guangyu");
	pe[1].sal = 24000.0;
	
	pe[2].id = 300;
	strcpy(pe[2].name , "zhangfei");
	pe[2].sal = 40000.0;
	
	int i;
	for(i = 0; i < 3; i++)
	{
		printf("id = %d, name = %s , sal = %g\n" ,
				pe[i].id , pe[i].name , pe[i].sal);
	}
	return -1;
}
