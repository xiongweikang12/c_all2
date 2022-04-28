#include <stdio.h>
#define MAXSIZE 1000

int top = 0;
double stack_val[MAXSIZE];

void pushstack(double f)//入栈
{
	if (top < MAXSIZE)
	{
		stack_val[top++] = f;
	}
	else
	{
		printf("栈满无法操作");
	}
}

double popstack(void) //栈顶出栈
{
	if (top > 0)
	{
		top--;
		return stack_val[top];
	}
	else
	{
		printf("栈空无法操作");
	}
	return 0.0;
}