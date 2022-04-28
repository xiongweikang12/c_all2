#include <stdio.h>
#include <stdlib.h>

typedef struct Bitnode_TH {

	int data;
	struct Bitnode *leftchild;
	struct Bitnode *rigthchild;
	int THL_tag;
	int THR_tag;

} BiThrNode, *BiThrTree;

static BiThrTree pre=NULL;

void InThreading(BiThrTree T)
{	
	//中序线索化
	if (T)
	{
		InThreading(T->leftchild);
		if (!(T->leftchild)) //左结点空，线索前驱
		{
			T->leftchild = pre;
			T->THL_tag = 1;
		}
		else
		{
			T->THL_tag = 0;
		}
		if (!(pre->rigthchild))//右结点空，线索后继
		{
			pre->THR_tag = 1;
			pre->rigthchild = T;
		}
		else
		{
			pre->THR_tag = 0;
		}
		pre = T;//当前结点
		InThreading(T->rigthchild);//退回到上个结点处
	}

}

void InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p = T->leftchild;
	while (p!=T)
	{
		while (p->THL_tag == 0)
		{
			p = p->leftchild;
			printf("\n线索访问 ：%d", p->data);
		}
		while (p->THR_tag == 1&& p!=T)
		{
			p = p->rigthchild; //线索回溯，到双亲
			printf("\n线索访问 ：%d", p->data);
		}
		p = p->rigthchild; //转到右子树
	}
}

