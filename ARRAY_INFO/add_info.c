#include <stdio.h>
#include "info.h"

void add_Info(info INfo[],int*comnum)
{	
	char c = '\n';
	int num = *comnum;
	INfo[num].id = num;
	*comnum = num + 1;
	printf("\n--------------------添加客户--------------------\n");
	printf("\n姓名:");
	intput(INfo[num].name);
	c=getchar();
	printf("\n性别:");
	scanf_s("%c", &(INfo[num].gender));
	c=getchar();
	printf("\n年龄:");
	scanf_s("%d", &(INfo[num].age));
	c = getchar();
	printf("\n电话:");
	intput(INfo[num].phone);
	c = getchar();
	printf("\n邮箱:");
	intput(INfo[num].mail);
	c = getchar();
}