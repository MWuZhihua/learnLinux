#include <stdio.h>
#include <dirent.h>

int main()
{
	DIR* dir = opendir("../");

	struct dirent* ent = readdir(dir);
	
	while(ent)
	{
		printf("%d , %s\n" , ent->d_type , ent->d_name);
		ent = readdir(dir);//继续读取下一个子项
	}
	return -1;
}
