
#define MaxSize 20
typedef int KeyType;

typedef struct {
	KeyType key;
	int otherinfo;
}redtype;

typedef struct {
	redtype r[MaxSize + 1];
	int length;
}Sqlist;

void Output_key(Sqlist);
void Input_key(Sqlist*);
void Insert_Sort(Sqlist*);
void BanInsert_Sort(Sqlist*);
void Bubbling_Sort(Sqlist*);
void Choice_Sort(Sqlist*);


