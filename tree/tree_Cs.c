

#include <stdio.h>
#include "tree_Cs.h"


void createCStree(CSTree *T)//�����������ָ��
{
	int data = 0;
	printf("\n����ڵ�����:");
	scanf_s("%d", &data);
	if (data == 0)
	{
		(*T) = NULL;//�ݹ��������
		printf("\n get");
	}
	else
	{
		(*T) = (CSTree)malloc(sizeof(CSNode));//ָ��ָ���ַ
		(*T)->data = data;//�����½ڵ㣬�Խڵ㸳ֵ
		createBitree(&((*T)->firstchild));//�ݹ�������
		//T��һ��ָ��ͷ(����ָ��)��ָ�룬
		//(*T->leftchild)�ǶԶ���ָ��ָ��Ĳ���ָ������(һ���ṹָ�룩����ֽ����
		//&��ʾȡ��ַ����ʾָ��(һ���ṹָ��Ķ���ָ��)
		createBitree(&((*T)->nextsibling));//�ݹ�������
	}
	return;
}

