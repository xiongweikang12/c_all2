#include <ctype.h>
#include <stdio.h>
#include "calc.h"


int gettop(char s[])
{	
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t');
	//�����ո�ͺ����Ʊ��
	//����getch������getchar()���뻺�������ַ�
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
	//��ʾΪ���������
	{
		return c;
	}
	i = 0;
	if (isdigit(c))
	//��λgetchar������Ϊ����
	{
		while (isdigit(s[++i] = c = getch()));
		//���ϴ�getchar��������ȡ��ֵ��������ֵs��
	}
	if (c == '.')
		//��ʾΪС���㣬ͬ�ϲ�����ֵ��
	{
		while (isdigit(s[++i] = c = getch()));
	}
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}