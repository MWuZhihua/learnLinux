#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <signal.h>

struct Msg
{
	long mtype;//消息类型
	char buf[20];//存储数据。什么类型都可以
};


int msgid;
void fa(int signo)
{
	msgctl(msgid , IPC_RMID , 0);
	printf("进程已关闭\n");
	exit(0);
}

int main()
{
	signal(SIGINT , fa);
	key_t key = ftok("." , 100);
	msgid = msgget(key , IPC_CREAT | 0666);
	if (msgid == -1)
	{
		perror("msgget");
		exit(-1);
	}
	
	struct Msg msg1 , msg2;
	msg1.mtype = 1;
	strcpy(msg1.buf , "zhang fei");
	msg2.mtype = 2;
	strcpy(msg2.buf , "guang yu");
	msgsnd(msgid , &msg1 , sizeof(msg1.buf) , 0);
	msgsnd(msgid , &msg2 , sizeof(msg2.buf) , 0);
	
	while(1);//为了回收消息队列的资源（删除）

	return 0;
}
