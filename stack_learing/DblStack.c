#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ERROR 0
#define OK 1

typedef struct dlstack {
	int top[2], bot[2];
	int V[MAXSIZE];
}Dblsatck;

typedef Dblsatck* DBST;
void intiStack(DBST ST);
int ISEmpty(DBST ST);
int ISFull(DBST ST);
void EnterStack1(DBST ST, int e);
void EnterStack0(DBST ST, int e);
void PopStack1(DBST ST);
void PopStack0(DBST ST);

void main()
{	
	int choice = 0;
	Dblsatck* ST;
	ST = (Dblsatck*)malloc(sizeof(Dblsatck));
	intiStack(ST);
	choice = ISEmpty(ST);
	EnterStack0(ST, 6);
	choice = ISEmpty(ST);

}

void intiStack(DBST ST)
{
	ST->top[0] = -1;
	ST->top[1] = MAXSIZE;
	printf("��ʼ���ɹ�");
}

int ISEmpty(DBST ST) {
	if ((ST->top[0] != -1) || (ST->top[1] != MAXSIZE))
	{
		printf("\n��Ϊ��ջ��");
		return ERROR;
	}
	else
	{
		printf("]\n��Ϊջ��");
		return OK;
	}
}

int ISFull(DBST ST)
{
	if (ST->top[0] == ST->top[1])
	{
		return OK;
		printf("\n��Ϊջ��");
	}
	else
	{
		return ERROR;
		printf("\n����ջ��");
	}
}

void EnterStack1(DBST ST, int e)
{
	ST->V[ST->top[1]] = e;
	ST->top[1]--;
	printf("\n%d��ջ1", e);
}

void EnterStack0(DBST ST, int e)
{
	ST->V[(ST->top[0])] = e;
	ST->top[0]++;
	printf("\n%d��ջ0",e);
}

void PopStack1(DBST ST)
{
	if (!(ISEmpty(ST)))
	{
		printf("Ϊ�ӿ�,�޷��ٳ�ջ");
	}
	else
	{	
		int newv;
		newv = ST->V[ST->top[1]];
		(ST->top[1])++;
		free(newv);
	}
}

void PopStack0(DBST ST)
{	
	if (!(ISEmpty(ST)))
	{
		printf("Ϊ�ӿգ��޷��ٳ�ջ");
	}
	else
	{
		int newv;
		newv = ST->V[ST->top[0]];
		(ST->top[0])--;
		free(newv);
	}
}