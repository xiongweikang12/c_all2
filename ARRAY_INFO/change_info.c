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
		printf("\n		����ѡ��:");
		scanf_s("%d", &key);
		c = getchar();
		switch (key)
		{
		case 1:
			//�޸�����
			printf("\n�޸����֣�");
			intput(INfo[index].name);
			c = getchar();
			break;
		case 2:
			//�޸�����
			printf("�޸�����");
			scanf_s("%d", &age);
			INfo[index].age = age;
			c = getchar();
			break;
		case 3:
			//�޸ĵ绰����
			printf("\n�޸ĵ绰:");
			intput(INfo[index].phone);
			c = getchar();
			break;
		case 4:
			//�޸�����
			printf("\n�޸�����:");
			intput(INfo[index].mail);
			c = getchar();
			break;
		case 5:
			//�˳�
			loop = 0;
			break;
		default:
			printf("\nû�д˲���");
			break;
		}

	} while (loop);
	printf("\n�˳��ɹ�");
}