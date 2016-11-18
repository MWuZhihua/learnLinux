#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

//pint 递归函数 ，实现打印出所有目录的内容
//包括各层子目录（ent->d_type == 4） 
void print(char* path)
{
	DIR* dir = opendir(path);
	if (dir == NULL) return;
	struct dirent* ent;
	while(ent = readdir(dir))
	{
		if (strcmp("." , ent->d_name) == 0 || 
				strcmp(".." , ent->d_name ) == 0)
		{
			continue;
		}

		if (ent->d_type == 4)
		{
			printf("[%s]\n" , ent->d_name);
			char buf[50] = {};
			sprintf(buf , "%s/%s" , path , ent->d_name);

			print(buf);
		}
		else
		{
			printf("%s\n" , ent->d_name);		
		}
	}

}

int main()
{
	print("../");
	return -1;
}
