#include "tag_all.h"

typedef struct bitree {
	int data;
	struct bitree* leftchild, * rightchild;
}BitreeNode, * Bitree;


void createBitree(Bitree*);//ͨ������ָ�봴����

void visitBitreeNode(Bitree);//���������

void visitBitree_INOrder(Bitree); //���������

void visiBitree_Post(Bitree); //���������

int depth_of_Bitree(Bitree); //s�������

void copy_new_tree(Bitree, Bitree* ); //����һ������

int Node_counter(Bitree); //���н����Ŀ

int isEmpty(Bitree); //�ж��Ƿ�Ϊ����