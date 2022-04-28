#include <stdio.h>
#include "info.h"

void delete_info(info INfo[], int index ,int *commun)
//删除索引，对想
{
	int com = *commun;//通过指针引用
	int i = index;
	if (index > com||index <= 0)
	{
		printf("索引错误");
	}
	else if (index==com)
	{
		free(INfo[index]);
		(*commun)--;
	}
	else
	{
		for (i = index; i + 1 < commun; i++)
		{
			INfo[i] = INfo[i + 1];
		}
	}
	//当未添加
}