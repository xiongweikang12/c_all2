#include <stdio.h>
#include <stdlib.h>
#include "array_sort.h"

void main()
{
	Sqlist* L = (Sqlist*)malloc(sizeof(Sqlist));
	Input_key(L);
	Output_key(*L);
	//Insert_Sort(L);
	// Bubbling_Sort(L);
	Choice_Sort(L);
	Output_key(*L);
}