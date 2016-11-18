#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
	key_t key = ftok("." , 200);

	//ipc_execl 不要挂上，因为第二次放入时队列已经存在
	int msgid = msgget(key, 0);
	if (msgid == -1) perror("msgget") , exit(-1);

	//printf("消息队列创建/获取成功\n");
	char buf[50] = {};
	int res = msgrcv(msgid ,buf, sizeof(buf) , 0 , 0);///IPC_NOWAIT非阻塞

	if (res == -1)
	{
		perror("msgsnd");
		exit(-1);
	}
	printf(" %s \n" , buf);
}
