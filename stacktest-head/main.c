#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXTOP 100
#define NUMBER '0'
#define ADD_STRING_OP  '+'
#define MINUS_STRING_OP '-'
#define MULTIPLICATION_STRING_OP '*'
#define DIVISION_STRING_OP  '/'
#define MOD_STRING_OP '%'
#define REPOT_STRING '\n'

//�ļ�����ָ�includeָ�
//ʹ�Ĵ��������#defineָ���Լ��������ӷ���

//����� #define ���� ����ı�
//�궨����Դ��������������ԶԲ�ͬ�ĺ����ʹ�ò�ͬ�ı����
//#define MAX(A,B) ((A)>(B)) ? (A):(B)
//Ҫ�ʵ�ʹ�������Ա�֤����������ȷ��
//#define square(x) x*x �� square(z+1)�����Ŀ����������

//#define dprintf(expr) printf(#expr "=%g\n",expr)
//��#��Ϊǰ׺������������չΪ
//��ʵ�ʲ�������ò����Ĵ����ŵ��ַ���

//����������



void main()
{
	int type;
	char s[MAXTOP];
	double top_laterop;
	double top_frontop;
	while ((type = gettop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER :
				pushstack(aufo(s));//��ʾ������ջ
				//�������aufo��ת��Ϊdouble���ͺ�����ջ
				break;
			case ADD_STRING_OP :
				pushstack(popstack() + popstack());//����ջ��ֵ���������ջ
				break;
			case MULTIPLICATION_STRING_OP :
				pushstack(popstack() * popstack());
				break;
			case MINUS_STRING_OP :
				top_laterop = popstack();
				top_frontop = popstack();
				pushstack(top_frontop - top_laterop);
				break;
			case DIVISION_STRING_OP:
				top_laterop = popstack();
				top_frontop = popstack();
				if (top_frontop == 0.0)
				{
					printf("ERROR DIVISION ZERO");
				}
				else
				{
					pushstack(top_frontop / top_laterop);
				}
				break;

			case REPOT_STRING : //���з���ʾ��ȡ����
				printf("\t%.8g\n", popstack());
				break;
		default:
			printf("error:unKown command%s\n", s);
			//��������
			break;
		}
	}
}