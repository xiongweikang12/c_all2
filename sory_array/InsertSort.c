#include <stdio.h>
#include "array_sort.h"

//插入排序，Insert_Sort

void Insert_Sort(Sqlist* L)
{
	//对顺序表操作，进行插入排序
	for (int i = 2; i < L->length; i++)//从第二个位置开始
	{
		if (L->r[i].key <= L->r[i-1].key)
		{	
			//后者比前者小,关键字作为比较依据
			L->r[0] = L->r[i];
			int j = i - 1;
			while (L->r[j].key > L->r[0].key)//
			{
				L->r[j + 1] = L->r[j];
				//向后移动
				j--;
			}
			//小于时退出,并插入到小于位置后的地方
			L->r[j + 1] = L->r[0];
		}
	}
}

void BanInsert_Sort(Sqlist* L)
{
	for (int i = 2; i < L->length; i++)
	{
		if (L->r[i].key <= L->r[i - 1].key)//小于前者
		{
			L->r[0] = L->r[i]; //保存待插入的数据单元
			int low = 1;
			int high = i - 1;
			while (low<=high) //low>high结束条件
			{
				int mid = (low + high) / 2;
				if (L->r[mid].key > L->r[0].key)
				{
					//插入值小与后一半，插入位置排除后一半
					high = mid - 1;
				}
				else
				{
					//插入值打于前一半，插入位置排除前一半
					low = mid + 1;
				}
				
			}
			for (int j = i - 1; j >=high+1; --j)
			{
				//得到插入位置，循环先后移动
				L->r[j + 1] = L->r[j];
			}
			L->r[high + 1] = L->r[0];
		}
	}
}

void Bubbling_Sort(Sqlist* L)
{
	for (int i = 0; i < L->length-1; i++)
	{
		for (int j = 0; j < (L->length - i-1); j++)
		{
			if (L->r[j + 1].key <= L->r[j].key)
			{
				redtype swap = L->r[j];
				L->r[j] = L->r[j + 1];
				L->r[j + 1] = swap;
			}
			else
			{
				continue;
			}
		}
	}
}

void Choice_Sort(Sqlist* L)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < L->length; i++)
	{
		int min = L->r[i].key;
		for (j = i; j < L->length; j++)
		{
			if (L->r[j].key <= min)
			{
				min = L->r[j].key;
				k = j;
			}
			else
			{
				continue;
			}
		}
		if (k != i)
		{
			redtype swap = L->r[i];
			L->r[i] = L->r[k];
			L->r[k] = swap;
		}
	}
}


