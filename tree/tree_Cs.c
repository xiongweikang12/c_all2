

#include <stdio.h>
#include "tree_Cs.h"


void createCStree(CSTree *T)//函数传入二级指针
{
	int data = 0;
	printf("\n输入节点数据:");
	scanf_s("%d", &data);
	if (data == 0)
	{
		(*T) = NULL;//递归结束条件
		printf("\n get");
	}
	else
	{
		(*T) = (CSTree)malloc(sizeof(CSNode));//指针指向地址
		(*T)->data = data;//创建新节点，对节点赋值
		createBitree(&((*T)->firstchild));//递归左子树
		//T是一个指向头(操作指针)的指针，
		//(*T->leftchild)是对二级指针指向的操作指针引用(一级结构指针）的左孩纸引用
		//&表示取地址，表示指向(一级结构指针的二级指针)
		createBitree(&((*T)->nextsibling));//递归右子树
	}
	return;
}

