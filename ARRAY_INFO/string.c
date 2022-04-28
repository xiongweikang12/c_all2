#include <stdio.h>

void intput(char s[])
{
	int i = 0;
	do
	{
		scanf_s("%c", &s[i]);
		if (s[i] == '#')
		{	
			s[i] = '\0';
			break;
		}
		else
		{	
			i++;
			continue;
		}

	} while (1);

}
