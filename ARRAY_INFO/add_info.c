#include <stdio.h>
#include "info.h"

void add_Info(info INfo[],int*comnum)
{	
	char c = '\n';
	int num = *comnum;
	INfo[num].id = num;
	*comnum = num + 1;
	printf("\n--------------------��ӿͻ�--------------------\n");
	printf("\n����:");
	intput(INfo[num].name);
	c=getchar();
	printf("\n�Ա�:");
	scanf_s("%c", &(INfo[num].gender));
	c=getchar();
	printf("\n����:");
	scanf_s("%d", &(INfo[num].age));
	c = getchar();
	printf("\n�绰:");
	intput(INfo[num].phone);
	c = getchar();
	printf("\n����:");
	intput(INfo[num].mail);
	c = getchar();
}