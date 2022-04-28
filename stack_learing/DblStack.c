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
	printf("初始化成功");
}

int ISEmpty(DBST ST) {
	if ((ST->top[0] != -1) || (ST->top[1] != MAXSIZE))
	{
		printf("\n不为是栈空");
		return ERROR;
	}
	else
	{
		printf("]\n是为栈空");
		return OK;
	}
}

int ISFull(DBST ST)
{
	if (ST->top[0] == ST->top[1])
	{
		return OK;
		printf("\n是为栈满");
	}
	else
	{
		return ERROR;
		printf("\n不是栈满");
	}
}

void EnterStack1(DBST ST, int e)
{
	ST->V[ST->top[1]] = e;
	ST->top[1]--;
	printf("\n%d入栈1", e);
}

void EnterStack0(DBST ST, int e)
{
	ST->V[(ST->top[0])] = e;
	ST->top[0]++;
	printf("\n%d入栈0",e);
}

void PopStack1(DBST ST)
{
	if (!(ISEmpty(ST)))
	{
		printf("为队空,无法再出栈");
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
		printf("为队空，无法再出栈");
	}
	else
	{
		int newv;
		newv = ST->V[ST->top[0]];
		(ST->top[0])--;
		free(newv);
	}
}