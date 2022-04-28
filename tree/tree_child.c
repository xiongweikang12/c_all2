#include <stdio.h>
#include "tag_all.h"
#include "tree.child.h"


void Creat_TC(T_C_array TC[])
{
	int index = 0;
	int inpudata = 0;
	int link_data = 0; //��������
	char c_getchar = '\n';
	int choice_child_link = 0;
	do
	{

		printf("��������Ϣ:"); //��������Ϣ�����Ϊ0������ɣ��˳�
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
		printf("�Ƿ��������:"); //�����㺢��������Ϣ
		scanf_s("%d", &choice_child_link);
		if (choice_child_link == FALSE) //choiceΪ0��ʾ�޺�ֽ������ֽ�����ƿ�
		{
			TC[index++].child_link = NULL;
			c_getchar = getchar();
			continue; //����
		}
		else
		{
			//Ϊ����������
			Lnode *demmm = (Lnode*)malloc(sizeof(Lnode));
			TC[index].child_link = demmm;
			Linknode p = demmm;
			do
			{
				Lnode* children = (Lnode*)malloc(sizeof(Lnode));
				printf("\n���뺢����������Ϣ:");
				scanf_s("%d", &link_data);
				if (link_data == -1) //����Ϊ-1��ʾ�˳�
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
	//Ѱ�Һ���,���ݸ�ĸ
	//����Ѱ�ұ��������� ����
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
			// printf("û�к�����");
			return NO_CHILD;
		}

		if (TC[index].data_node==parent && TC[index].child_link)
		{
			//�ҵ����ӣ�ͨ������ҵ�˫��
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
						//Ѱ�ҵ�˫�ף�ͨ����������
					//�ҵ�����,ͨ������Ѱ�Һ���
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
} //������������

void printf_child(int* p)

{	
	if (p == NULL)
	{
		printf("û�������ӣ�ΪҶ�ӽ��");
	}
	else
	{
		//��ӡ���ӽ��
		int i = 0;
		while (p[i] != '\0')
		{
			printf("\n ���ӽ�� :%d", p[i]);
			i++;
		}
	}
}
