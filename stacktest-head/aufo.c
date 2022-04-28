#include <ctype.h>

double aufo(char s[])
{
	double val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++);//不是空格时循环，i++,
	//不是空格时候跳出循环
	sign = (s[i] == '-') ? -1 : 1;//正负号
	if (s[i] == '+' || s[i] == '-')//非数值符号
	{
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++)//遇到数值
	{
		val = val * 10 + (s[i] - '0');
	}
	if (s[i] == '.')//从上步循环退出，表示遇到.号
		//如果没有遇到.号就是一个整数，像150这样
	{
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++)//表示遇到.后的数字
	{
		val = val * 10 + (s[i] - '0');
		power *= 10;
		//表示除数，如12.10=1210/100
	}
	return (sign * val) / power;

}