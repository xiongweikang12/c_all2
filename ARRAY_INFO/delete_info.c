#include <stdio.h>
#include "info.h"

void delete_info(info INfo[], int index ,int *commun)
//ɾ������������
{
	int com = *commun;//ͨ��ָ������
	int i = index;
	if (index > com||index <= 0)
	{
		printf("��������");
	}
	else if (index==com)
	{
		free(INfo[index]);
		(*commun)--;
	}
	else
	{
		for (i = index; i + 1 < commun; i++)
		{
			INfo[i] = INfo[i + 1];
		}
	}
	//��δ���
}