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
			case 1: //���
				add_Info(number_info,com);
				break;
			case 2: //�޸�
				printf("\n�����޸ĵ�����:");
				scanf_s("%d", &index);
				change_info(number_info, index);
				c = getchar();
				break;
			case 3: 
				//ɾ��ĳ��(ͨ�������±�)
				//˳����㷨
				printf("\n����ɾ��������:");
				scanf_s("%d", &index_del);
				delete_info(number_info, index_del, com);
				c = getchar();
				break;
			case 4 : //��Ա�б�
				print_info(number_info, com);
				break;
			case 5 : //�˳�
				loop = 0;
				break;
		default:
			printf("�޲�������������");
			continue;
		}

	} while (loop);
	printf("\n�˳�ϵͳ");
}


