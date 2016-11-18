#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	key_t key = ftok("." , 100);

	if (key == -1)
	{
		perror("ftok");
		exit(-1);
	}

	int shmid = shmget(key , 0 , 0);

	if (shmid == -1)
	{
		perror("shmid");
		exit(-1);
	}

	//printf("共享内存创建完毕 \n");

	void* p = shmat(shmid , 0 , 0);

	if (p == (void* )-1)
	{
		perror("shmat");
		exit(-1);
	}

	int* pi = p;
	printf("*pi = %d\n" , *pi);
	shmdt(p);
	shmctl(shmid , IPC_RMID , 0);//删除
}
