#include <stdio.h>
#include "tree_array.h"
#include "tag_all.h"
#include <stdlib.h>



void Creat_array_tree(tree_parent TP[])
{	
	int index = 0;
	int index_TP = 0;
	int inputdata = 0;
	char c_getchar = '\n';
	do
	{
		printf("\n��������Ϣ  :");
		scanf_s("%d", &inputdata);
		if (inputdata ==0)
		{
			break;
		}
		else
		{
			TP[index].data = inputdata;
			c_getchar = getchar();
			printf("\n������˫��ָ�� :");
			scanf_s("%d", &index_TP);
			TP[index].parent = index_TP;
			c_getchar = getchar();
			index += 1;
		}
	} while (1);
	TP[index].data = '\0';

}

int Find_parent(tree_parent TP[],int child)
{	
	//Ѱ�ҽ��child��˫��
	int index = 0;
	while (TP[index].data != '\0')
	{
		if (TP[index].data == child)
		{
			return TP[TP[index].parent].data;
		}
		else
		{
			index += 1;
			continue;
		}
	}
	return FALSE;
}


