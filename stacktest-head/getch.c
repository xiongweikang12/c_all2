#include <stdio.h>
#define BUFSIZE 100
#include "calc.h"

char buf[BUFSIZE]; //���Ż�����
int bufp = 0;
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
	//bufpΪ���Ż���������* - / +;
	//�����ַ���ʱ����õ�bufp���룬��ʱgetch�´η��ص�Ϊ����
	//���൱��һ��״̬����bufp������Ϊ��ʱͨ��getchar�����ַ�
	//ѭ���ж��Ƿ�Ϊ��ֵ�����ϴ�getchar��ȡ��Ϊ��ֵ����s�����У��������ַ�������/n
	//�����жϣ�buf[bufp++]=c��ʱcΪ�ַ���buf״̬�ǿգ�
	//return (bufp>0) ����buf[--bufp]��ͨ��swicth(type)���ж�Ӧ����
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