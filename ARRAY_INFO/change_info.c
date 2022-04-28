#include<stdio.h>
#include "info.h"

void change_info(info INfo[], int index)
{
	int loop = 1;
	int key = 10;
	char c = '\n';
	int age = 100;
	do
	{	
		printf_choice_menu();
		printf("\n		输入选项:");
		scanf_s("%d", &key);
		c = getchar();
		switch (key)
		{
		case 1:
			//修改名字
			printf("\n修改名字：");
			intput(INfo[index].name);
			c = getchar();
			break;
		case 2:
			//修改年龄
			printf("修改年龄");
			scanf_s("%d", &age);
			INfo[index].age = age;
			c = getchar();
			break;
		case 3:
			//修改电话号码
			printf("\n修改电话:");
			intput(INfo[index].phone);
			c = getchar();
			break;
		case 4:
			//修改邮箱
			printf("\n修改邮箱:");
			intput(INfo[index].mail);
			c = getchar();
			break;
		case 5:
			//退出
			loop = 0;
			break;
		default:
			printf("\n没有此操作");
			break;
		}

	} while (loop);
	printf("\n退出成功");
}