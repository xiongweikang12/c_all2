#include <stdio.h>
#include <stdlib.h>
#include "tree_noraml_rail.h"
#include <stack>


void createBitree(Bitree* T)//函数传入二级指针
{
	int data = 0;
	printf("\n输入节点数据:");
	scanf_s("%d", &data);
	if (data == 0)
	{
		(*T) = NULL;//递归结束条件
	}
	else
	{
		(*T) = (Bitree)malloc(sizeof(BitreeNode));//指针指向地址
		(*T)->data = data;//创建新节点，对节点赋值
		createBitree(&((*T)->leftchild));//递归左子树
		//T是一个指向头(操作指针)的指针，
		//(*T->leftchild)是对二级指针指向的操作指针引用(一级结构指针）的左孩纸引用
		//&表示取地址，表示指向(一级结构指针的二级指针)
		createBitree(&((*T)->rightchild));//递归右子树
	}
	return;
}

int depth_of_Bitree(Bitree T)
{
	if (T == NULL)
	{
		return 0;//递归结束
	}
	else
	{
		int m = depth_of_Bitree(T->leftchild) + 1;//表示结点数目
		int n = depth_of_Bitree(T->rightchild) + 1;
		return m >= n ? m : n;
		//用树中子树的最大深度表示树的深度
		//返回子树最大深度
	}
}

void copy_new_tree(Bitree T, Bitree* new)
{
	//像创建一个二叉树一样，通过二级指针对结构指针操作
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
	//得到树中的结点数目
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
		printf("是空树");
		return TRUE;
	}
	else
	{
		printf("不是空树");
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
		printf("\n先序访问结点:%d", T->data);
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
		printf("\n中序访问结点:%d", T->data);
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
		printf("\n后序访问结点 :%d", T->data);
	}
}

