#include <stdio.h>
#define MAXSIZE 1000

int top = 0;
double stack_val[MAXSIZE];

void pushstack(double f)//��ջ
{
	if (top < MAXSIZE)
	{
		stack_val[top++] = f;
	}
	else
	{
		printf("ջ���޷�����");
	}
}

double popstack(void) //ջ����ջ
{
	if (top > 0)
	{
		top--;
		return stack_val[top];
	}
	else
	{
		printf("ջ���޷�����");
	}
	return 0.0;
}