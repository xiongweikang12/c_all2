#include <ctype.h>
#include <stdio.h>
#include "calc.h"


int gettop(char s[])
{	
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t');
	//跳过空格和横向制表符
	//进入getch返回首getchar()输入缓存区的字符
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
	//表示为运算符返回
	{
		return c;
	}
	i = 0;
	if (isdigit(c))
	//首位getchar缓存区为数字
	{
		while (isdigit(s[++i] = c = getch()));
		//不断从getchar缓存区获取数值，插入数值s中
	}
	if (c == '.')
		//表示为小数点，同上插入数值中
	{
		while (isdigit(s[++i] = c = getch()));
	}
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}