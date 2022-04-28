#include<stdio.h>
#include <stdlib.h>
#include "tree_noraml_rail.h"
#include "tree_array.h"
#include "tree.child.h"
#include "tree_Cs.h"




int main()
{
	//int dept = 0;
	//int node_count = 0;
	// Bitree *T =(Bitree)malloc(sizeof(Bitree));
	// Bitree *newT =(Bitree)malloc(sizeof(Bitree));
	//二级指针,对于通过递归建立的二叉树，建立成功没有办法将头指针传出;
	//同过二级指针，地址访问的方法,解决;
	//createBitree(T);
	//copy_new_tree((*T), newT);
	//visitBitreeNode((*T));
	//visitBitreeNode((*newT));
	//visitBitree_INOrder((*newT));
	//printf("\n此二叉树的最大深度为:%d", depth_of_Bitree(*T));
	//printf("\n此二叉树的结点个数为:%d", Node_counter((*T)));
	//tree_parent* TP = (tree_parent*)malloc(sizeof(tree_parent) * 1000);
	//Creat_array_tree(TP);
	//printf("%d", Find_parent(TP, 11));
	//T_C_array* TC = (T_C_array*)malloc(sizeof(T_C_array) * 100);
	//Creat_TC(TC);
	//printf_child(Find_child(TC, 3));
	CSTree *T = (CSTree)malloc(sizeof(CSNode));
	createCStree(T);
	return 0;
}


