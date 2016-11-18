#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee
{
	char name[256];
	int age;
	double salary;
}EMP;

//以二进制写Bin.dat文件

void binwrite(void)
{
	char name[256]  = "zhangfei";
	int age = 30;
	double salary = 20000.5;
	EMP emp = {"zhaoyun" , 20 , 10000.5};

	int fd  = open("bin.dat" , O_WRONLY | O_CREAT | O_TRUNC , 0666);
	if (fd == -1)
	{
		perror("open");
		exit(-1);
	}

	if (write(fd , name , sizeof(name)) == -1||
			write(fd , &age , sizeof(age)) == -1 ||
			write(fd , &salary , sizeof(salary)) == -1 ||
			write(fd , &emp , sizeof(emp)) == -1)
	{
		perror("write");
		exit(-1);
	}

	close(fd);

}


// 以二进制方式读bin.dat文件

void binread(void)
{
	char name[256];
	int age;
	double salary;
	EMP emp;


	int fd  = open("bin.dat" , O_RDONLY);

	if ( read(fd , name , sizeof(name)) == -1 ||
			read(fd , &age , sizeof(age)) == -1||
			read(fd , &salary , sizeof(salary)) == -1||
			read(fd , &emp , sizeof(emp)) == -1)
	{
		perror("read");
		exit(-1);
	}
	close(fd);

	printf("%s %d %g\n" , name , age ,salary);
	printf("%s %d %g\n" , emp.name , emp.age , emp.salary);


}

//以纯文本方式写txtx.txt文件
void txtwrite(void)
{
	char name[256] = "zhangfei";
	int age = 30;
	double salary = 20000.5;

	EMP emp = {"zhaoyun" , 30 , 10000.5};

	//
	char text[1024];
	sprintf(text , "%s %d %g\n%s %d %g" , name , age , salary , 
			emp.name , emp.age , emp.salary);

	int fd  = open("txt.txt" , O_WRONLY |
			O_CREAT | O_TRUNC , 0666);

	if (fd == -1)
	{
		perror("open");
		exit(-1);
	}
	
	if (write(fd , text , strlen(text) * sizeof(text[0])) == -1)
	{
		perror("wriet");
		exit(-1);
	}

	close(fd);


}

//以纯文本方式读txt.txt文件
void txtread(void)
{
	char name[256];
	int age;
	double salary;

	EMP emp;

	int fd = open("txt.txt" , O_RDONLY);

	if (fd == -1)
	{
		perror("open");
		exit(-1);
	}

	char text[1024] = {};
	if (read (fd , text , sizeof(text)) == -1)
	{
		perror("read");
		exit(-1);
	}

	sscanf(text , "%s%d%lf%s%d%lf" , name , &age , &salary ,
			emp.name , &emp.age , &emp.salary);
	printf("%s %d %g \n %s %d %g\n" , name , age ,salary , 
			emp.name , emp.age , emp.salary);
	
	close(fd);
}

int main()
{
	binwrite();
	binread();

	txtwrite();
	txtread();
}
