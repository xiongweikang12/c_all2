#include <stdio.h>
#include "info.h"

//��ʾ������,��ʾ�����û�����Ϣ
void print_info(info INfo[],int *com)
{
	int length = *com;
	int i;
	printf("\n----------------------------------------�ͻ��б�----------------------------------------");
	printf("\n���\t����\t�Ա�\t����\t�绰\t\t����");
	for (i = 0; i < length; i++)
	{
		printf("\n%d\t%s\t%c\t%d\t%s\t\t%s",
			INfo[i].id, INfo[i].name, INfo[i].gender,
			INfo[i].age, INfo[i].phone, INfo[i].mail);
	}
	printf("\n----------------------------------------�ͻ��б�----------------------------------------\n");

}