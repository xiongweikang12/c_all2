
typedef struct Londe {
	int data_index;
	struct Londe *next;
}Lnode, * Linknode;

typedef struct tree_child {
	int data_node;
	Linknode child_link;
}T_C_array;

void Creat_TC(T_C_array[]);

int* Find_child(T_C_array[], int);

void printf_child(int*);

#define NO_CHILD NULL