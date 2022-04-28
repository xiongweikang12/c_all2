#include <stdio.h>
#include <stdlib.h>
#include "tree_noraml_rail.h"
#include <stack>


void createBitree(Bitree* T)//�����������ָ��
{
	int data = 0;
	printf("\n����ڵ�����:");
	scanf_s("%d", &data);
	if (data == 0)
	{
		(*T) = NULL;//�ݹ��������
	}
	else
	{
		(*T) = (Bitree)malloc(sizeof(BitreeNode));//ָ��ָ���ַ
		(*T)->data = data;//�����½ڵ㣬�Խڵ㸳ֵ
		createBitree(&((*T)->leftchild));//�ݹ�������
		//T��һ��ָ��ͷ(����ָ��)��ָ�룬
		//(*T->leftchild)�ǶԶ���ָ��ָ��Ĳ���ָ������(һ���ṹָ�룩����ֽ����
		//&��ʾȡ��ַ����ʾָ��(һ���ṹָ��Ķ���ָ��)
		createBitree(&((*T)->rightchild));//�ݹ�������
	}
	return;
}

int depth_of_Bitree(Bitree T)
{
	if (T == NULL)
	{
		return 0;//�ݹ����
	}
	else
	{
		int m = depth_of_Bitree(T->leftchild) + 1;//��ʾ�����Ŀ
		int n = depth_of_Bitree(T->rightchild) + 1;
		return m >= n ? m : n;
		//�����������������ȱ�ʾ�������
		//��������������
	}
}

void copy_new_tree(Bitree T, Bitree* new)
{
	//�񴴽�һ��������һ����ͨ������ָ��Խṹָ�����
	if (T == NULL)
	{
		(*new) = NULL;
		return;
	}
	else
	{
		(*new) = (Bitree)malloc(sizeof(BitreeNode));
		(*new)->data = T->data;
		copy_new_tree(T->leftchild, &((*new)->leftchild));
		copy_new_tree(T->rightchild, &((*new)->rightchild));

	}

}

int Node_counter(Bitree T)
{
	//�õ����еĽ����Ŀ
	if (T == NULL)
	{
		return 0;
	}
	return Node_counter(T->leftchild) + Node_counter(T->rightchild) + 1;
}

int isEmpty(Bitree T)
{
	if (T == NULL)
	{	
		printf("�ǿ���");
		return TRUE;
	}
	else
	{
		printf("���ǿ���");
		return FALSE;
	}
}

void  visitBitreeNode(Bitree T)
{

	if (T == NULL)
	{
		return ;
	}
	else
	{
		printf("\n������ʽ��:%d", T->data);
		visitBitreeNode(T->leftchild);
		visitBitreeNode(T->rightchild);
	}
	return;
}

void visitBitree_INOrder(Bitree T)
{
	if (T == NULL)
	{
		return;
	}
	else {
		visitBitree_INOrder(T->leftchild);
		printf("\n������ʽ��:%d", T->data);
		visitBitree_INOrder(T->rightchild);
	}
}

void visiBitree_Post(Bitree T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{

		visiBitree_Post(T->leftchild);
		visiBitree_Post(T->rightchild);
		printf("\n������ʽ�� :%d", T->data);
	}
}

