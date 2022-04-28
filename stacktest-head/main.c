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

//文件包含指令（include指令）
//使的处理大量的#define指令以及声明更加方便

//宏替代 #define 名字 替代文本
//宏定义可以带参数，这样可以对不同的宏调用使用不同文本替代
//#define MAX(A,B) ((A)>(B)) ? (A):(B)
//要适当使用括号以保证计算次序的正确性
//#define square(x) x*x 当 square(z+1)这样的可能引起错误

//#define dprintf(expr) printf(#expr "=%g\n",expr)
//在#作为前缀，则结果将被扩展为
//由实际参数替代该参数的带引号的字符串

//条件包含，



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
				pushstack(aufo(s));//表示数据入栈
				//数组进入aufo中转换为double类型后再入栈
				break;
			case ADD_STRING_OP :
				pushstack(popstack() + popstack());//将出栈数值相加其结果入栈
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

			case REPOT_STRING : //换行符表示读取结束
				printf("\t%.8g\n", popstack());
				break;
		default:
			printf("error:unKown command%s\n", s);
			//错误命令
			break;
		}
	}
}