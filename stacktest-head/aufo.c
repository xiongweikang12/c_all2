#include <ctype.h>

double aufo(char s[])
{
	double val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++);//���ǿո�ʱѭ����i++,
	//���ǿո�ʱ������ѭ��
	sign = (s[i] == '-') ? -1 : 1;//������
	if (s[i] == '+' || s[i] == '-')//����ֵ����
	{
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++)//������ֵ
	{
		val = val * 10 + (s[i] - '0');
	}
	if (s[i] == '.')//���ϲ�ѭ���˳�����ʾ����.��
		//���û������.�ž���һ����������150����
	{
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++)//��ʾ����.�������
	{
		val = val * 10 + (s[i] - '0');
		power *= 10;
		//��ʾ��������12.10=1210/100
	}
	return (sign * val) / power;

}