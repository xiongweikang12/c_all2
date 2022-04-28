

//孩子兄弟表示法，转换二叉树
typedef struct CSLnode
{
	int data;
	struct CSLnode* firstchild, * nextsibling;
}CSNode,*CSTree;

void createCStree(CSTree*);