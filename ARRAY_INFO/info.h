
#define MAX_SIZE 100;

typedef struct array_info {
	int id;
	char name[10];
	int age;
	char gender;
	char phone[20];
	char mail[20];
}info;

void add_Info(info[], int*);
void printf_menu();
void print_info(info[], int*);
void intput(char []);
void printf_choice_menu();
void change_info(info[], int);
void delete_info(info[], int, int*);


