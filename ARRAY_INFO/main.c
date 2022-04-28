#include <stdio.h>
#include<stdlib.h>
#include "info.h"

int key;
int loop=1;



void main()
{	
	int comnum = 0;
	int* com = &comnum;
	info number_info[100];
	int index = 0;
	int index_del = 0;
	char c = '\n';


	do
	{
		printf_menu();
		scanf_s("%d", &key);
		c=getchar();
		switch (key)
		{
			case 1: //添加
				add_Info(number_info,com);
				break;
			case 2: //修改
				printf("\n输入修改的索引:");
				scanf_s("%d", &index);
				change_info(number_info, index);
				c = getchar();
				break;
			case 3: 
				//删除某个(通过索引下标)
				//顺序表算法
				printf("\n输入删除的索引:");
				scanf_s("%d", &index_del);
				delete_info(number_info, index_del, com);
				c = getchar();
				break;
			case 4 : //成员列表
				print_info(number_info, com);
				break;
			case 5 : //退出
				loop = 0;
				break;
		default:
			printf("无操作，重新输入");
			continue;
		}

	} while (loop);
	printf("\n退出系统");
}


