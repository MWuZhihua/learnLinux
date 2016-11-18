#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct Msg
{
	long mtype;//消息类型
	char buf[20];//存储数据。什么类型都可以
};

int main()
{
	key_t key = ftok("." , 100);
	int msgid = msgget(key , 0);
	if (msgid == -1)
	{
		perror("msgget");
		exit(-1);
	}
	
	struct Msg msg;
	int res = msgrcv(msgid , &msg , sizeof(msg.buf) , 2 , 0);

	printf("接收了%d字节，内容：%s\n" , res , msg.buf);
	return 0;
}
