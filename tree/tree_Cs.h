

//�����ֵܱ�ʾ����ת��������
typedef struct CSLnode
{
	int data;
	struct CSLnode* firstchild, * nextsibling;
}CSNode,*CSTree;

void createCStree(CSTree*);