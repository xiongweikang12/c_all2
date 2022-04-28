#include "tag_all.h"

typedef struct bitree {
	int data;
	struct bitree* leftchild, * rightchild;
}BitreeNode, * Bitree;


void createBitree(Bitree*);//通过二级指针创建树

void visitBitreeNode(Bitree);//先序遍历树

void visitBitree_INOrder(Bitree); //中序遍历树

void visiBitree_Post(Bitree); //后序遍历树

int depth_of_Bitree(Bitree); //s树的深度

void copy_new_tree(Bitree, Bitree* ); //复制一个新树

int Node_counter(Bitree); //树中结点数目

int isEmpty(Bitree); //判断是否为空树