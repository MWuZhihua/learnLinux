#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//1.字符串的声明和赋值

	char* s1 = "abc";
	char s2[] = "abc";

	char* s3 = s2;

	//s1 = "123";//改地址，此时s1 指向123
	//strcpy(s1 , "123");//段错误 ，修改只读区
	//s2 = "123";//数组是常指针，不能再次改变指向
	//strcpy(s2 , "123");//对，改内容
	//s3 = "123";//对 ，改地址（栈只读）
	//strcpy(s3 , "123");//对，改值

	//2.字符串的长度 strlen() sizeof()取的是大小
	char* s4 = "1234567";
	printf("size = %d ,size2 = %d\n", strlen(s4), sizeof(s4));

	//3.字符串的拼接
	char* file = "hello.c";
	char* path = "/home/tarena";
	//(1)
	char buf[100] = {};
	strcpy(buf , path);
	strcat(buf , "/");
	strcat(buf , file);
	//(2)
	sprintf(buf,"%s/%s", path ,file);
	
	//4.利用指针的操作进行字符串功能 ，比如拆分
	char* s5 = "zhangfei , 25";
	char  name[20] = {};
	char age[10] = {};
	/*int i = 0;
	for (i = 0; i < strlen(s5); i++)
	{
		if (*(s5 + i) == ',')
		{
			memcpy(name , s5 , i);
			strcpy(age , s5 + i + 1);
			break;
		}
	}*/
	sscanf( s5 ,"%s , %s" , name ,age);

	printf("%s,%s\n" , name , age);


	return 0;
}
