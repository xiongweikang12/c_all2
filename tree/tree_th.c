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
	//����������
	if (T)
	{
		InThreading(T->leftchild);
		if (!(T->leftchild)) //����գ�����ǰ��
		{
			T->leftchild = pre;
			T->THL_tag = 1;
		}
		else
		{
			T->THL_tag = 0;
		}
		if (!(pre->rigthchild))//�ҽ��գ��������
		{
			pre->THR_tag = 1;
			pre->rigthchild = T;
		}
		else
		{
			pre->THR_tag = 0;
		}
		pre = T;//��ǰ���
		InThreading(T->rigthchild);//�˻ص��ϸ���㴦
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
			printf("\n�������� ��%d", p->data);
		}
		while (p->THR_tag == 1&& p!=T)
		{
			p = p->rigthchild; //�������ݣ���˫��
			printf("\n�������� ��%d", p->data);
		}
		p = p->rigthchild; //ת��������
	}
}

