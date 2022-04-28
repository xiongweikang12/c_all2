#include <stdio.h>
#include "tag_all.h"
#include "tree.child.h"


void Creat_TC(T_C_array TC[])
{
	int index = 0;
	int inpudata = 0;
	int link_data = 0; //孩子索引
	char c_getchar = '\n';
	int choice_child_link = 0;
	do
	{

		printf("输入结点信息:"); //输入结点信息，如果为0输入完成，退出
		scanf_s("%d", &inpudata);
		if (inpudata == FALSE)
		{
			break;
		}
		else
		{
			
			TC[index].data_node = inpudata;
			c_getchar = getchar();
		}
		printf("是否孩子链表空:"); //输入结点孩子链表信息
		scanf_s("%d", &choice_child_link);
		if (choice_child_link == FALSE) //choice为0表示无孩纸，将孩纸链表制空
		{
			TC[index++].child_link = NULL;
			c_getchar = getchar();
			continue; //继续
		}
		else
		{
			//为结点添加链表
			Lnode *demmm = (Lnode*)malloc(sizeof(Lnode));
			TC[index].child_link = demmm;
			Linknode p = demmm;
			do
			{
				Lnode* children = (Lnode*)malloc(sizeof(Lnode));
				printf("\n输入孩子链表结点信息:");
				scanf_s("%d", &link_data);
				if (link_data == -1) //链表为-1表示退出
				{
					break;
				}
				else
				{
					children->data_index = link_data;
					p->next = children;
					p = p->next;
				}
			} while (1);
			p->next = NULL;
		}
		index++;
	} while (1);
	TC[index].data_node = '\0';

}

int* Find_child(T_C_array TC[] ,int parent )
{
	//寻找孩子,根据父母
	//先是寻找表，孩子链表 ，表
	int index_child_link = 0;
	int index = 0;
	for (int index = 0; TC[index].data_node != '0'; index++)
	{
		if (TC[index].data_node != parent && TC[index].child_link == NULL)
		{	
			continue;
		}

		if (TC[index].data_node==parent && TC[index].child_link==NULL)
		{
			// printf("没有孩子树");
			return NO_CHILD;
		}

		if (TC[index].data_node==parent && TC[index].child_link)
		{
			//找到孩子，通过表格找到双亲
			Linknode p = TC[index].child_link->next;
			int* q = (int*)malloc(sizeof(int) * 50);
			int i = 0;
			while (p)
			{
				q[i++] = TC[p->data_index].data_node;
				p = p->next;
			}
			q[i] = '\0';
			return q;
		}

		if (TC[index].data_node != parent && TC[index].child_link)
		{
			Linknode p_find = TC[index].child_link->next;
			while (p_find)
			{
				if (TC[p_find->data_index].data_node == parent)
				{
					if (TC[p_find->data_index].child_link!=NULL)
					{
						//寻找到双亲，通过孩子链表
					//找到孩子,通过链表寻找孩子
						Linknode pp = TC[p_find->data_index].child_link->next;
						int* pq = (int*)malloc(sizeof(int) * 50);
						int i = 0;
						while (pp)
						{
							pq[i++] = TC[pp->data_index].data_node;
							pp = pp->next;
						}
						pq[i] = '\0';
						return pq;
					}
					else
					{
						return NO_CHILD;

					}

				}
				else
				{
					p_find = p_find->next;
				}
			}
		}
	}
} //返回类型数组

void printf_child(int* p)

{	
	if (p == NULL)
	{
		printf("没有树孩子，为叶子结点");
	}
	else
	{
		//打印孩子结点
		int i = 0;
		while (p[i] != '\0')
		{
			printf("\n 孩子结点 :%d", p[i]);
			i++;
		}
	}
}
