#include <stdio.h>
#define BUFSIZE 100
#include "calc.h"

char buf[BUFSIZE]; //符号缓存区
int bufp = 0;
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
	//bufp为符号缓存区，像* - / +;
	//当出现符号时会调用到bufp存入，此时getch下次返回的为符号
	//其相当于一个状态，当bufp缓存区为空时通过getchar输入字符
	//循环判断是否为数值，不断从getchar读取，为数值插入s数组中，当遇到字符，包括/n
	//跳出判断，buf[bufp++]=c此时c为字符，buf状态非空，
	//return (bufp>0) 返回buf[--bufp]，通过swicth(type)进行对应操作
}
void ungetch(int c)
{
	if ((bufp) >= BUFSIZE)
	{
		printf("ungetch: too many charaters \n");
	}
	else
	{
		buf[bufp++] = c;
	}
}