
#include <stdio.h>
#include <math.h>
//#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#pragma warning(disable : 4996)
typedef struct _wrkr{
	char name[20];
	char dep[20];
	unsigned int salary;
}wrkr;



unsigned int loadfromfile(wrkr* str) {
	FILE* f;
	char* buffer = malloc(21);
	errno_t	error = fopen_s(&f, "text.txt", "r+");
	int i = 0;
	while (!feof(f)) {
		fscanf(f, "%s%s%d\n", (str+i)->name, (str + i)->dep, &((str + i)->salary));
		i++;
	}
	//prinft_s("%s %s %d",str->name,str->dep,str->salary);*/
	/*int j;
	for (int i = 0; *(buffer+i) != '\0'; i++) {
		if (*(buffer+i) == ' ') {
			j = i;
		};
	};*/
	//while (!feof(f)) {
	//	fgets((str + i)->name, 40, f);
	//	fgets((str + i)->dep, 40, f);
	//	fgets(buffer, 40, f);
	//	(str + i)->salary = atof(buffer);
	//	i++;
	//}
	fclose(f);
	return i;
};

void additem(wrkr* str) {
	int i;
	for ( i = 0; (str + i)->name[0] != 0; i++) {		
	}	
	scanf("%s %s %d", (str + i)->name, (str + i)->dep, &((str + i)->salary));
};

void displaylst(wrkr* str) {
	for (int i = 0; (str + i)->name[0] != 0; i++) {
		printf_s(" % s % s % d \n", (str + i)->name, (str + i)->dep, ((str + i)->salary));
	}
};

void deleteitem(wrkr* str) {
	unsigned int num = 0;
	scanf("%d", &num);
	int i;
	for (i = 0; (str + i)->name[0] != 0; i++) {
	}
	*(str + num - 1) = *(str + i - 1);
	(str + i-1)->name[0] = 0;
	(str + i-1)->dep[0] = 0;
	(str + i-1)->salary = 0;
	
};

void edititem(wrkr* str) {
	wrkr* tempstr = malloc(sizeof(wrkr));
	unsigned int num;
	printf_s("Enter num");
	scanf_s("%d", &num);
	printf_s("Enter struct (name dep salary)");
	scanf("%s %s %d", (tempstr)->name, (tempstr)->dep, &((tempstr)->salary));
	printf_s("Save? [1]/[0]");
	unsigned int choice;
	scanf_s("%d", &choice);
	if (choice) {
		*(str + num-1) = *tempstr;
	}

}
void extra(wrkr* str) {
	char depname[20];
	printf_s("Enter depname \n");
	scanf("%s", depname);
	int amount = 0;
	int sum = 0;
	for (int i = 0; (str + i)->name[0] != 0; i++) {
		if (!strcmp((str + i)->dep, depname)) {
			amount++;
			sum += (str + i)->salary;
		}
	}
	printf_s(" total payment: %d \n", sum);
	sum = sum / amount;
	printf_s(" Avegare salary %d \n", sum);
	system("pause");
};

void savefile(wrkr* str) {
	FILE* f;
	errno_t	error = fopen_s(&f, "text.txt", "w+");
	for (int i = 0; (str + i)->dep[0] != 0; i++) {
		fprintf_s(f, "%s %s %d \n", (str + i)->name, (str + i)->dep, (str + i)->salary);
	}
	fclose(f);
};

unsigned int option(wrkr* str) {
	printf_s("[0] Add [1] Delete [2] Edit [3] Extra [4]Exit [5]LoadFromFile [6]SaveToFile\n");
	unsigned choice;
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 0:additem(str); break;
	case 1:deleteitem(str); break;
	case 2:edititem(str); break;
	case 3:extra(str); break;
	case 4:return 0;
	case 5:loadfromfile(str); break;
	case 6:savefile(str); break;
	default:break;
	}
	system("cls");
	displaylst(str);
	return 1;
};



int main()
{
	system("chcp 1251");
	system("cls");
	wrkr* str= malloc(sizeof(wrkr)* SIZE);
	for (int i = 0; i < SIZE; i++) {
		(str + i)->name[0] = 0;
		(str + i)->dep[0] = 0;
		(str + i)->salary = 0;

	};
	unsigned int amount = loadfromfile(str);
	displaylst(str);
	while(option(str));

	return 0;
}
