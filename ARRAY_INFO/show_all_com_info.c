#include <stdio.h>
#include "info.h"

//显示各数据,显示所有用户的信息
void print_info(info INfo[],int *com)
{
	int length = *com;
	int i;
	printf("\n----------------------------------------客户列表----------------------------------------");
	printf("\n编号\t姓名\t性别\t年龄\t电话\t\t邮箱");
	for (i = 0; i < length; i++)
	{
		printf("\n%d\t%s\t%c\t%d\t%s\t\t%s",
			INfo[i].id, INfo[i].name, INfo[i].gender,
			INfo[i].age, INfo[i].phone, INfo[i].mail);
	}
	printf("\n----------------------------------------客户列表----------------------------------------\n");

}